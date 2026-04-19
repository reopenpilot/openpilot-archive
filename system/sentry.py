"""Install exception handler for process crash."""
import json
import os
import sentry_sdk
import subprocess
import traceback
from datetime import datetime
from enum import Enum
from sentry_sdk.integrations.threading import ThreadingIntegration

from openpilot.common.params import Params
from openpilot.system.hardware import HARDWARE, PC
from openpilot.common.swaglog import cloudlog
from openpilot.system.version import get_build_metadata, get_version

from openpilot.frogpilot.common.frogpilot_variables import ERROR_LOGS_PATH, params

class SentryProject(Enum):
  # python project
  SELFDRIVE = "https://7ba43fba4cfcf1a6c0eff83d40374e43@o4505034923769856.ingest.us.sentry.io/4505034930651136"
  # native project
  SELFDRIVE_NATIVE = "https://7ba43fba4cfcf1a6c0eff83d40374e43@o4505034923769856.ingest.us.sentry.io/4505034930651136"


def report_tombstone(fn: str, message: str, contents: str) -> None:
  cloudlog.error({'tombstone': message})

  with sentry_sdk.configure_scope() as scope:
    scope.set_extra("tombstone_fn", fn)
    scope.set_extra("tombstone", contents)
    sentry_sdk.capture_message(message=message)
    sentry_sdk.flush()


def capture_block():
  with sentry_sdk.push_scope() as scope:
    sentry_sdk.capture_message("Blocked user from using the development branch", level='info')
    sentry_sdk.flush()


def capture_exception(*args, crash_log=True, **kwargs) -> None:
  exc_text = traceback.format_exc()

  phrases_to_check = [
    "already exists. To overwrite it, set 'overwrite' to True",
    "failed after retry",
  ]

  if any(phrase in exc_text for phrase in phrases_to_check):
    return

  save_exception(exc_text, crash_log)
  cloudlog.error("crash", exc_info=kwargs.get('exc_info', 1))

  try:
    sentry_sdk.capture_exception(*args, **kwargs)
    sentry_sdk.flush()  # https://github.com/getsentry/sentry-python/issues/291
  except Exception:
    cloudlog.exception("sentry exception")


def _read_meminfo() -> dict[str, int]:
  meminfo = {}
  with open("/proc/meminfo", "r") as meminfo_file:
    for line in meminfo_file:
      parts = line.split()
      if len(parts) >= 2:
        meminfo[parts[0].rstrip(":")] = int(parts[1]) * 1024
  return meminfo


def _read_text_if_exists(path: str) -> str | None:
  if not os.path.exists(path):
    return None
  with open(path, "r") as file_handle:
    return file_handle.read().strip()


def _read_vmstat(keys: tuple[str, ...]) -> dict[str, int]:
  requested = set(keys)
  values = {}
  if not os.path.exists("/proc/vmstat"):
    return values

  with open("/proc/vmstat", "r") as vmstat_file:
    for line in vmstat_file:
      key, value = line.split()[:2]
      if key in requested:
        values[key] = int(value)
  return values


def _build_ps_snapshot(limit: int = 30) -> list[dict[str, object]]:
  output = subprocess.check_output(["ps", "-eo", "pid,ppid,rss,vsz,%mem,args", "--sort=-rss"], encoding="utf-8")
  rows = []
  for line in output.splitlines()[1:limit + 1]:
    parts = line.split(None, 5)
    if len(parts) < 6:
      continue
    rows.append({
      "pid": int(parts[0]),
      "ppid": int(parts[1]),
      "rss_kb": int(parts[2]),
      "vsz_kb": int(parts[3]),
      "mem_percent": float(parts[4]),
      "args": parts[5],
    })
  return rows


def _read_kv_report(path: str, *, convert_kb: bool = True) -> dict[str, int | str]:
  if not os.path.exists(path):
    return {}

  values: dict[str, int | str] = {}
  with open(path, "r") as report_file:
    for line in report_file:
      if ":" not in line:
        continue
      key, value = line.split(":", 1)
      value = value.strip()
      if convert_kb and value.endswith(" kB"):
        try:
          values[key] = int(value[:-3].strip()) * 1024
          continue
        except ValueError:
          pass
      if value.isdigit():
        values[key] = int(value)
      else:
        values[key] = value
  return values


def _read_proc_memory_details(pid: int) -> dict[str, object] | None:
  status = _read_kv_report(f"/proc/{pid}/status")
  smaps_rollup = _read_kv_report(f"/proc/{pid}/smaps_rollup")
  if not status and not smaps_rollup:
    return None

  interesting_status = {
    key: status.get(key)
    for key in (
      "Name",
      "State",
      "Threads",
      "VmPeak",
      "VmSize",
      "VmRSS",
      "VmHWM",
      "VmSwap",
      "RssAnon",
      "RssFile",
      "RssShmem",
      "voluntary_ctxt_switches",
      "nonvoluntary_ctxt_switches",
    )
    if key in status
  }
  interesting_smaps = {
    key: smaps_rollup.get(key)
    for key in (
      "Rss",
      "Pss",
      "Pss_Anon",
      "Pss_File",
      "Pss_Shmem",
      "Shared_Clean",
      "Shared_Dirty",
      "Private_Clean",
      "Private_Dirty",
      "Referenced",
      "Anonymous",
      "LazyFree",
      "AnonHugePages",
      "Swap",
      "SwapPss",
      "Locked",
    )
    if key in smaps_rollup
  }
  return {
    "pid": pid,
    "status": interesting_status,
    "smaps_rollup": interesting_smaps,
  }


def _collect_process_memory_details(report_context: dict[str, object] | None, ps_snapshot: list[dict[str, object]]) -> list[dict[str, object]]:
  candidate_pids: list[int] = []
  pid_metadata: dict[int, dict[str, object]] = {}

  if report_context is not None:
    proc_snapshot = report_context.get("current_proc_snapshot")
    if isinstance(proc_snapshot, dict):
      for proc in list(proc_snapshot.get("top_processes", []))[:5]:
        pid = int(proc.get("pid", 0))
        if pid > 0 and pid not in candidate_pids:
          candidate_pids.append(pid)
          pid_metadata[pid] = proc

      for proc in list(proc_snapshot.get("suspicious_processes", []))[:5]:
        pid = int(proc.get("pid", 0))
        if pid > 0 and pid not in candidate_pids:
          candidate_pids.append(pid)
          pid_metadata[pid] = proc

    for proc in list(report_context.get("manager_processes", []))[:8]:
      pid = int(proc.get("pid", 0))
      if pid > 0 and pid not in candidate_pids:
        candidate_pids.append(pid)
        pid_metadata[pid] = proc

  for proc in ps_snapshot[:5]:
    pid = int(proc["pid"])
    if pid not in candidate_pids:
      candidate_pids.append(pid)
      pid_metadata[pid] = proc

  details = []
  for pid in candidate_pids[:10]:
    memory_detail = _read_proc_memory_details(pid)
    if memory_detail is None:
      continue
    metadata = pid_metadata.get(pid, {})
    if "label" in metadata:
      memory_detail["label"] = metadata["label"]
    elif "args" in metadata:
      memory_detail["label"] = metadata["args"]
    details.append(memory_detail)
  return details


def _write_low_memory_report(report: dict[str, object]) -> str | None:
  try:
    ERROR_LOGS_PATH.mkdir(parents=True, exist_ok=True)
    report_path = ERROR_LOGS_PATH / datetime.now().astimezone().strftime("%Y-%m-%d--%H-%M-%S-low-memory.json")
    report_path.write_text(json.dumps(report, indent=2, sort_keys=True), encoding="utf-8")
    return str(report_path)
  except Exception:
    cloudlog.exception("failed to write low memory report")
    return None


def _capture_proc_attachments(pid: int, label: str, timestamp: str) -> list[tuple[str, str]]:
  """Copy /proc/<pid>/{maps,smaps,status} + pmap output to attachable files.
  Returns list of (path, filename) tuples for Sentry add_attachment()."""
  if pid <= 0:
    return []
  attachments: list[tuple[str, str]] = []
  try:
    ERROR_LOGS_PATH.mkdir(parents=True, exist_ok=True)
  except Exception:
    return attachments

  for proc_file in ("maps", "smaps", "status"):
    src = f"/proc/{pid}/{proc_file}"
    dst = ERROR_LOGS_PATH / f"{timestamp}-{label}-{pid}-{proc_file}.txt"
    try:
      with open(src, "rb") as f:
        data = f.read()
      dst.write_bytes(data)
      attachments.append((str(dst), f"{label}-{pid}-{proc_file}.txt"))
    except OSError:
      pass

  try:
    pmap_result = subprocess.run(
      ["pmap", "-x", str(pid)],
      capture_output=True, text=True, timeout=5, check=False,
    )
    if pmap_result.returncode == 0 and pmap_result.stdout:
      pmap_path = ERROR_LOGS_PATH / f"{timestamp}-{label}-{pid}-pmap.txt"
      pmap_path.write_text(pmap_result.stdout, encoding="utf-8")
      attachments.append((str(pmap_path), f"{label}-{pid}-pmap.txt"))
  except (subprocess.SubprocessError, OSError):
    pass

  return attachments


def _latest_heap_profile_for_pid(pid: int) -> tuple[str, str] | None:
  """Return (path, filename) of the newest jemalloc heap profile for the given
  pid. Profiles are produced automatically via MALLOC_CONF lg_prof_interval.
  Returns None if no profile file exists yet."""
  if pid <= 0:
    return None
  try:
    candidates = sorted(
      ERROR_LOGS_PATH.glob(f"jeprof.{pid}.*.heap"),
      key=lambda p: p.stat().st_mtime,
      reverse=True,
    )
  except Exception:
    return None
  if not candidates:
    return None
  p = candidates[0]
  return (str(p), p.name)


def _capture_self_malloc_info(timestamp: str) -> tuple[str, str] | None:
  """Dump glibc malloc_info() for the calling process (controlsd). Not the UI —
  that needs a separate hook from C++ (Layer 2 jemalloc prof.dump)."""
  try:
    import ctypes
    libc = ctypes.CDLL("libc.so.6")
    if not hasattr(libc, "malloc_info"):
      return None

    # Use libc.fopen directly so we hold the only FILE* — avoids the double-free
    # that results from Python's open() + fdopen() on the same fd.
    libc.fopen.restype = ctypes.c_void_p
    libc.fopen.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
    libc.fclose.argtypes = [ctypes.c_void_p]
    libc.malloc_info.argtypes = [ctypes.c_int, ctypes.c_void_p]

    path = ERROR_LOGS_PATH / f"{timestamp}-controlsd-malloc_info.xml"
    fp = libc.fopen(str(path).encode("utf-8"), b"w")
    if not fp:
      return None
    try:
      libc.malloc_info(0, fp)
    finally:
      libc.fclose(fp)
    return (str(path), "controlsd-malloc_info.xml")
  except Exception:
    cloudlog.exception("malloc_info capture failed")
    return None


def report_abnormal_exit(proc_name: str, pid: int, exitcode: int,
                          signal_name: str = "",
                          attachments: list[tuple[str, str]] | None = None) -> None:
  """Fire a Sentry event for a managed process that died with a non-zero /
  signal exit status. Called from system/manager/process.py:check_abnormal_exit.

  The event groups by proc_name + signal so related crashes cluster. For the
  ui, we also attach the /data/error_logs/ui_crash_*.txt written by the
  in-process signal handler (gives a Qt-thread backtrace that tombstoned
  can't see)."""
  try:
    with sentry_sdk.push_scope() as scope:
      scope.set_tag("proc_name", proc_name)
      scope.set_tag("exit_signal", signal_name or "none")
      scope.set_extra("pid", pid)
      scope.set_extra("exitcode", exitcode)
      if attachments:
        _attach_files_to_scope(scope, attachments)
      title = f"Process Abnormal Exit: {proc_name}"
      if signal_name:
        title += f" ({signal_name})"
      else:
        title += f" (code {exitcode})"
      sentry_sdk.capture_message(title, level="error")
      sentry_sdk.flush()
  except Exception:
    cloudlog.exception("failed to report abnormal exit")


def memory_breadcrumb(message: str, data: dict | None = None) -> None:
  """Add a breadcrumb that'll surface inside the Low Memory Report v3 event's
  recent-action trail. Use for significant lifecycle events that might precede
  memory pressure (theme changes, model downloads, asset fetches, widget load)."""
  try:
    sentry_sdk.add_breadcrumb(
      category="memory",
      message=message,
      level="info",
      data=data or {},
    )
  except Exception:
    pass


def _attach_files_to_scope(scope, attachments: list[tuple[str, str]]) -> None:
  """Attach the given files to the current Sentry scope.
  Skips files > 19 MB (Sentry's per-attachment limit is 20 MB)."""
  MAX_BYTES = 19 * 1024 * 1024
  for path, filename in attachments:
    try:
      if os.path.getsize(path) > MAX_BYTES:
        cloudlog.warning(f"skipping oversized attachment {filename}")
        continue
      scope.add_attachment(path=path, filename=filename)
    except Exception:
      cloudlog.exception(f"failed to attach {filename}")


def _compact_report_context(report_context: dict[str, object] | None) -> dict[str, object] | None:
  if report_context is None:
    return None

  compact_context = dict(report_context)
  compact_context["recent_device_history"] = list(report_context.get("recent_device_history", []))[-60:]
  compact_context["recent_proc_history"] = []
  for entry in list(report_context.get("recent_proc_history", []))[-15:]:
    compact_entry = dict(entry)
    compact_entry.pop("rss_by_label", None)
    compact_context["recent_proc_history"].append(compact_entry)

  proc_snapshot = report_context.get("current_proc_snapshot")
  if isinstance(proc_snapshot, dict):
    compact_snapshot = dict(proc_snapshot)
    compact_snapshot["top_processes"] = list(proc_snapshot.get("top_processes", []))[:10]
    compact_snapshot["grouped_rss"] = list(proc_snapshot.get("grouped_rss", []))[:10]
    compact_snapshot["suspicious_processes"] = list(proc_snapshot.get("suspicious_processes", []))[:10]
    compact_snapshot["tree_rollups"] = list(proc_snapshot.get("tree_rollups", []))[:10]
    compact_context["current_proc_snapshot"] = compact_snapshot

  manager_processes = list(report_context.get("manager_processes", []))
  compact_context["manager_processes"] = [
    process for process in manager_processes
    if (not process.get("running", True)) or process.get("name") in {"updated", "controlsd", "ui", "camerad", "modeld", "loggerd"}
  ]
  compact_context["process_growth"] = list(report_context.get("process_growth", []))[:10]

  return compact_context


def capture_memory_usage(report_context: dict[str, object] | None = None) -> None:
  try:
    meminfo = _read_meminfo()
    total_memory = meminfo.get("MemTotal", 0)
    memory_available = meminfo.get("MemAvailable", 0)

    if not total_memory:
      cloudlog.error("Failed to read memory info")
      return

    used_memory = total_memory - memory_available
    total_memory_usage_percent = (used_memory / total_memory) * 100

    ps_snapshot = _build_ps_snapshot()
    formatted_output = "\n".join(
      f"{row['rss_kb']:>9} KB  {row['mem_percent']:>5.1f}%  pid={row['pid']:>6}  ppid={row['ppid']:>6}  {row['args']}"
      for row in ps_snapshot[:20]
    )

    report = {
      "captured_at": datetime.now().astimezone().isoformat(),
      "root_memory_bytes": {
        "total": total_memory,
        "available": memory_available,
        "used": used_memory,
        "free": meminfo.get("MemFree", 0),
        "buffers": meminfo.get("Buffers", 0),
        "cached": meminfo.get("Cached", 0),
        "active": meminfo.get("Active", 0),
        "inactive": meminfo.get("Inactive", 0),
        "shared": meminfo.get("Shmem", 0),
        "slab": meminfo.get("Slab", 0),
        "sreclaimable": meminfo.get("SReclaimable", 0),
        "sunreclaim": meminfo.get("SUnreclaim", 0),
        "kernel_stack": meminfo.get("KernelStack", 0),
        "page_tables": meminfo.get("PageTables", 0),
      },
      "root_memory_percent_used": round(total_memory_usage_percent, 2),
      "memory_pressure": {
        "psi": _read_text_if_exists("/proc/pressure/memory"),
        "vmstat": _read_vmstat((
          "allocstall",
          "allocstall_dma",
          "allocstall_dma32",
          "allocstall_movable",
          "oom_kill",
          "pgmajfault",
          "pswpin",
          "pswpout",
          "workingset_refault_anon",
          "workingset_refault_file",
        )),
      },
      "top_processes": ps_snapshot,
      "process_memory_details": _collect_process_memory_details(report_context, ps_snapshot),
      "context": report_context or {},
    }

    report_path = _write_low_memory_report(report)
    compact_context = _compact_report_context(report_context)

    timestamp = datetime.now().astimezone().strftime("%Y-%m-%d--%H-%M-%S")
    attachments: list[tuple[str, str]] = []

    # Attach /proc dumps for the top 5 RSS processes — covers ui, frogpilot_process,
    # speed_limit_filler, classic_modeld, mapd in typical cases. Each attachment is
    # a few hundred KB max; well under Sentry's 20 MB / attachment limit.
    ui_pid = 0
    for row in ps_snapshot[:5]:
      pid = int(row.get("pid", 0))
      if pid <= 0:
        continue
      args = row.get("args", "").strip()
      # Detect the ui process for heap-profile attachment.
      if args == "./ui" or args.endswith("/ui"):
        ui_pid = pid
      label = args
      # Slugify: keep basename, strip paths/args, clamp to 40 chars.
      label = label.split()[0].split("/")[-1] if label else f"pid{pid}"
      label = "".join(c if c.isalnum() or c in "._-" else "_" for c in label)[:40]
      if not label:
        label = f"pid{pid}"
      attachments.extend(_capture_proc_attachments(pid, label, timestamp))

    # If ui wasn't in the top 5 but is running, still grab its heap profile.
    if ui_pid <= 0:
      try:
        ui_pid_result = subprocess.run(
          ["pgrep", "-x", "ui"], capture_output=True, text=True, timeout=2, check=False,
        )
        if ui_pid_result.returncode == 0 and ui_pid_result.stdout.strip():
          ui_pid = int(ui_pid_result.stdout.strip().split("\n")[0])
      except (subprocess.SubprocessError, ValueError, OSError):
        pass

    # Attach the newest jemalloc heap profile for the ui process.
    # jeprof --text /data/openpilot/selfdrive/ui/ui <file> gives stack-level
    # allocation attribution. The profile is 50-100 KB typically.
    heap = _latest_heap_profile_for_pid(ui_pid) if ui_pid > 0 else None
    if heap is not None:
      attachments.append(heap)

    # glibc malloc_info() for controlsd itself (the process calling us).
    mi = _capture_self_malloc_info(timestamp)
    if mi is not None:
      attachments.append(mi)

    with sentry_sdk.push_scope() as scope:
      scope.set_extra("memory_usage", formatted_output)
      scope.set_extra("total_memory_usage_percent", f"{total_memory_usage_percent:.1f}%")
      scope.set_extra("root_memory_bytes", report["root_memory_bytes"])
      scope.set_extra("memory_pressure", report["memory_pressure"])
      scope.set_extra("top_processes", report["top_processes"][:12])
      scope.set_extra("process_memory_details", report["process_memory_details"][:5])
      if compact_context is not None:
        scope.set_extra("low_memory_context", compact_context)
      if report_path is not None:
        scope.set_extra("low_memory_report_path", report_path)
      scope.set_extra("attachment_filenames", [filename for _, filename in attachments])
      _attach_files_to_scope(scope, attachments)
      sentry_sdk.capture_message("Low Memory Report v3", level="warning")
      sentry_sdk.flush()

  except Exception:
    cloudlog.exception("failed to capture memory usage")


def set_tag(key: str, value: str) -> None:
  sentry_sdk.set_tag(key, value)


def save_exception(exc_text: str, crash_log) -> None:
  files = [
    ERROR_LOGS_PATH / datetime.now().astimezone().strftime("%Y-%m-%d--%H-%M-%S.log"),
    ERROR_LOGS_PATH / "error.txt"
  ]

  for file_path in files:
    if file_path.name == "error.txt" and crash_log:
      lines = exc_text.splitlines()[-10:]
      file_path.write_text("\n".join(lines))
    else:
      file_path.write_text(exc_text)


def init(project: SentryProject) -> bool:
  build_metadata = get_build_metadata()
  FrogPilot = "frogai" in build_metadata.openpilot.git_origin.lower()
  if not FrogPilot or PC:
    return False

  short_branch = build_metadata.channel

  if short_branch in ["COMMA", "HEAD"]:
    return False
  elif short_branch == "FrogPilot-Development":
    env = "Development"
  elif build_metadata.release_channel:
    env = "Release"
  elif short_branch == "FrogPilot-Testing":
    env = "Testing"
  elif build_metadata.tested_channel:
    env = "Staging"
  else:
    env = short_branch

  dongle_id = params.get("DongleId", encoding="utf-8")
  installed = params.get("InstallDate", encoding="utf-8")
  updated = params.get("Updated", encoding="utf-8")

  integrations = []
  if project == SentryProject.SELFDRIVE:
    integrations.append(ThreadingIntegration(propagate_hub=True))

  sentry_sdk.init(project.value,
                  default_integrations=False,
                  release=get_version(),
                  integrations=integrations,
                  traces_sample_rate=1.0,
                  max_value_length=8192,
                  environment=env)

  sentry_sdk.set_user({"id": dongle_id})
  sentry_sdk.set_tag("origin", build_metadata.openpilot.git_origin)
  sentry_sdk.set_tag("branch", short_branch)
  sentry_sdk.set_tag("commit", build_metadata.openpilot.git_commit)
  sentry_sdk.set_tag("updated", updated)
  sentry_sdk.set_tag("installed", installed)

  if project == SentryProject.SELFDRIVE:
    sentry_sdk.Hub.current.start_session()

  return True
