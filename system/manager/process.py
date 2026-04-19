import importlib
import os
import signal
import struct
import time
import subprocess
from collections.abc import Callable, ValuesView
from abc import ABC, abstractmethod
from multiprocessing import Process

from setproctitle import setproctitle

from cereal import car, log
import cereal.messaging as messaging
import openpilot.system.sentry as sentry
from openpilot.common.basedir import BASEDIR
from openpilot.common.params import Params
from openpilot.common.swaglog import cloudlog

WATCHDOG_FN = "/dev/shm/wd_"
ENABLE_WATCHDOG = os.getenv("NO_WATCHDOG") is None


def launcher(proc: str, name: str) -> None:
  try:
    # import the process
    mod = importlib.import_module(proc)

    # rename the process
    setproctitle(proc)

    # create new context since we forked
    messaging.context = messaging.Context()

    # add daemon name tag to logs
    cloudlog.bind(daemon=name)
    sentry.set_tag("daemon", name)

    # exec the process
    mod.main()
  except KeyboardInterrupt:
    cloudlog.warning(f"child {proc} got SIGINT")
  except Exception:
    # can't install the crash handler because sys.excepthook doesn't play nice
    # with threads, so catch it here.
    sentry.capture_exception()
    raise


def nativelauncher(pargs: list[str], cwd: str, name: str) -> None:
  os.environ['MANAGER_DAEMON'] = name

  # Enable jemalloc heap profiling for the ui process.
  #   lg_prof_sample:21      — 1 stack sample per 2 MB allocated (<1 % CPU)
  #   lg_prof_interval:28    — auto-dump a heap profile every 256 MB of
  #                            cumulative allocation. Produces steady state
  #                            of ~3-4 .heap files per drive; capture_memory_usage
  #                            attaches the newest one to the Sentry event.
  #                            Qt/wayland eats signals so we can't rely on
  #                            SIGUSR2-triggered dumps.
  # Offline analysis:
  #   jeprof --text /data/openpilot/selfdrive/ui/ui heap.prof | head -20
  if name == "ui":
    os.environ["MALLOC_CONF"] = (
      "prof:true,prof_active:true,lg_prof_sample:21,lg_prof_interval:28,"
      "prof_prefix:/data/error_logs/jeprof"
    )

  # exec the process
  os.chdir(cwd)
  os.execvp(pargs[0], pargs)


def join_process(process: Process, timeout: float) -> None:
  # Process().join(timeout) will hang due to a python 3 bug: https://bugs.python.org/issue28382
  # We have to poll the exitcode instead
  t = time.monotonic()
  while time.monotonic() - t < timeout and process.exitcode is None:
    time.sleep(0.001)


class ManagerProcess(ABC):
  daemon = False
  sigkill = False
  should_run: Callable[[bool, Params, car.CarParams], bool]
  proc: Process | None = None
  enabled = True
  name = ""

  last_watchdog_time = 0
  watchdog_max_dt: int | None = None
  watchdog_seen = False
  shutting_down = False
  # Tracks the last exitcode we already reported to Sentry so we don't spam
  # repeats during shutdown churn. Reset whenever a new process is spawned.
  _reported_exit_pid: int | None = None

  @abstractmethod
  def prepare(self) -> None:
    pass

  @abstractmethod
  def start(self) -> None:
    pass

  def restart(self) -> None:
    self.stop(sig=signal.SIGKILL)
    self.start()

  def check_abnormal_exit(self) -> None:
    """If the managed process has exited with a non-zero or signal status and
    we haven't reported it yet, fire a Sentry 'Process Abnormal Exit' event.
    Called every manager loop so crashes get reported within ~seconds.

    For the ui process specifically, attach the newest ui_crash_*.txt written
    by the in-process fatal-signal handler in selfdrive/ui/main.cc (covers
    both tombstoned-visible crashes and process-level-only exits)."""
    if self.proc is None or self.proc.exitcode is None or self.shutting_down:
      return
    ec = self.proc.exitcode
    if ec == 0:
      return
    pid = self.proc.pid
    if pid == self._reported_exit_pid:
      return
    self._reported_exit_pid = pid

    try:
      from openpilot.system import sentry as _sentry
      import glob
      # exitcode < 0 => killed by -exitcode; > 0 => process returned exitcode.
      signal_num = -ec if ec < 0 else 0
      signame = ""
      if signal_num:
        try:
          signame = signal.Signals(signal_num).name
        except Exception:
          signame = f"sig{signal_num}"

      # Find the newest ui_crash_*.txt for the ui process (matches the epoch
      # suffix we wrote in the signal handler).
      attachments = []
      if self.name == "ui":
        crash_files = sorted(
          glob.glob("/data/error_logs/ui_crash_*.txt"),
          key=os.path.getmtime, reverse=True,
        )
        if crash_files:
          attachments.append((crash_files[0], os.path.basename(crash_files[0])))

      _sentry.report_abnormal_exit(
        proc_name=self.name, pid=pid, exitcode=ec, signal_name=signame,
        attachments=attachments,
      )
    except Exception:
      cloudlog.exception(f"failed to report abnormal exit for {self.name}")

  def check_watchdog(self, started: bool) -> None:
    if self.watchdog_max_dt is None or self.proc is None:
      return

    try:
      fn = WATCHDOG_FN + str(self.proc.pid)
      with open(fn, "rb") as f:
        # TODO: why can't pylint find struct.unpack?
        self.last_watchdog_time = struct.unpack('Q', f.read())[0]
    except Exception:
      pass

    dt = time.monotonic() - self.last_watchdog_time / 1e9

    if dt > self.watchdog_max_dt:
      if self.watchdog_seen and ENABLE_WATCHDOG:
        cloudlog.error(f"Watchdog timeout for {self.name} (exitcode {self.proc.exitcode}) restarting ({started=})")
        self.restart()
    else:
      self.watchdog_seen = True

  def stop(self, retry: bool = True, block: bool = True, sig: signal.Signals = None) -> int | None:
    if self.proc is None:
      return None

    if self.proc.exitcode is None:
      if not self.shutting_down:
        cloudlog.info(f"killing {self.name}")
        if sig is None:
          sig = signal.SIGKILL if self.sigkill else signal.SIGINT
        self.signal(sig)
        self.shutting_down = True

        if not block:
          return None

      join_process(self.proc, 5)

      # If process failed to die send SIGKILL
      if self.proc.exitcode is None and retry:
        cloudlog.info(f"killing {self.name} with SIGKILL")
        self.signal(signal.SIGKILL)
        self.proc.join()

    ret = self.proc.exitcode
    cloudlog.info(f"{self.name} is dead with {ret}")

    if self.proc.exitcode is not None:
      self.shutting_down = False
      self.proc = None

    return ret

  def signal(self, sig: int) -> None:
    if self.proc is None:
      return

    # Don't signal if already exited
    if self.proc.exitcode is not None and self.proc.pid is not None:
      return

    # Can't signal if we don't have a pid
    if self.proc.pid is None:
      return

    cloudlog.info(f"sending signal {sig} to {self.name}")
    os.kill(self.proc.pid, sig)

  def get_process_state_msg(self):
    state = log.ManagerState.ProcessState.new_message()
    state.name = self.name
    if self.proc:
      state.running = self.proc.is_alive()
      state.shouldBeRunning = self.proc is not None and not self.shutting_down
      state.pid = self.proc.pid or 0
      state.exitCode = self.proc.exitcode or 0
    return state


class NativeProcess(ManagerProcess):
  def __init__(self, name, cwd, cmdline, should_run, enabled=True, sigkill=False, watchdog_max_dt=None):
    self.name = name
    self.cwd = cwd
    self.cmdline = cmdline
    self.should_run = should_run
    self.enabled = enabled
    self.sigkill = sigkill
    self.watchdog_max_dt = watchdog_max_dt
    self.launcher = nativelauncher

  def prepare(self) -> None:
    pass

  def start(self) -> None:
    # In case we only tried a non blocking stop we need to stop it before restarting
    if self.shutting_down:
      self.stop()

    if self.proc is not None:
      return

    cwd = os.path.join(BASEDIR, self.cwd)
    cloudlog.info(f"starting process {self.name}")
    self.proc = Process(name=self.name, target=self.launcher, args=(self.cmdline, cwd, self.name))
    self.proc.start()
    self.watchdog_seen = False
    self.shutting_down = False


class PythonProcess(ManagerProcess):
  def __init__(self, name, module, should_run, enabled=True, sigkill=False, watchdog_max_dt=None):
    self.name = name
    self.module = module
    self.should_run = should_run
    self.enabled = enabled
    self.sigkill = sigkill
    self.watchdog_max_dt = watchdog_max_dt
    self.launcher = launcher

  def prepare(self) -> None:
    if self.enabled:
      cloudlog.info(f"preimporting {self.module}")
      importlib.import_module(self.module)

  def start(self) -> None:
    # In case we only tried a non blocking stop we need to stop it before restarting
    if self.shutting_down:
      self.stop()

    if self.proc is not None:
      return

    cloudlog.info(f"starting python {self.module}")
    self.proc = Process(name=self.name, target=self.launcher, args=(self.module, self.name))
    self.proc.start()
    self.watchdog_seen = False
    self.shutting_down = False


class DaemonProcess(ManagerProcess):
  """Python process that has to stay running across manager restart.
  This is used for athena so you don't lose SSH access when restarting manager."""
  def __init__(self, name, module, param_name, enabled=True):
    self.name = name
    self.module = module
    self.param_name = param_name
    self.enabled = enabled
    self.params = None

  @staticmethod
  def should_run(started, params, CP, classic_model, tinygrad_model, frogpilot_toggles):
    return True

  def prepare(self) -> None:
    pass

  def start(self) -> None:
    if self.params is None:
      self.params = Params()

    pid = self.params.get(self.param_name, encoding='utf-8')
    if pid is not None:
      try:
        os.kill(int(pid), 0)
        with open(f'/proc/{pid}/cmdline') as f:
          if self.module in f.read():
            # daemon is running
            return
      except (OSError, FileNotFoundError):
        # process is dead
        pass

    cloudlog.info(f"starting daemon {self.name}")
    proc = subprocess.Popen(['python', '-m', self.module],
                               stdin=open('/dev/null'),
                               stdout=open('/dev/null', 'w'),
                               stderr=open('/dev/null', 'w'),
                               preexec_fn=os.setpgrp)

    self.params.put(self.param_name, str(proc.pid))

  def stop(self, retry=True, block=True, sig=None) -> None:
    pass


def ensure_running(procs: ValuesView[ManagerProcess], started: bool, params=None, CP: car.CarParams=None,
                   not_run: list[str] | None=None, classic_model=False, tinygrad_model=False, frogpilot_toggles=None) -> list[ManagerProcess]:
  if not_run is None:
    not_run = []

  running = []
  for p in procs:
    if p.enabled and p.name not in not_run and p.should_run(started, params, CP, classic_model, tinygrad_model, frogpilot_toggles):
      running.append(p)
    else:
      p.stop(block=False)

    p.check_watchdog(started)
    p.check_abnormal_exit()

  for p in running:
    p.start()

  return running
