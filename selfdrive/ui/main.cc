#include <execinfo.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <sys/resource.h>
#include <time.h>
#include <unistd.h>

#include <QApplication>
#include <QTranslator>

#include "system/hardware/hw.h"
#include "selfdrive/ui/qt/qt_window.h"
#include "selfdrive/ui/qt/util.h"
#include "selfdrive/ui/qt/window.h"

// jemalloc heap profiling is enabled via MALLOC_CONF in manager.py nativelauncher.
// Profiles are dumped automatically every lg_prof_interval (256 MB cumulative
// allocation) to /data/error_logs/jeprof.<pid>.<seq>.heap. See process.py for
// the full config. capture_memory_usage in system/sentry.py picks up the
// newest file and attaches it to the Sentry Low Memory Report v3 event.
//
// Offline symbolization (debug info preserved in ui binary — see SConstruct:
// -g is global):  jeprof --text /data/openpilot/selfdrive/ui/ui heap.prof

// Fatal-signal handler: writes a minimal async-signal-safe backtrace to
// /data/error_logs/ui_crash_<ts>_<sig>.txt BEFORE the default handler kills
// the process. manager.py reads the newest crash file on ui respawn and
// ships it to Sentry. Complements Android's tombstoned (which catches the
// same signals at kernel level) — our version runs INSIDE the process so
// it can walk the in-process stack, which tombstoned can't.
//
// Strict async-signal safety: no malloc, no stdio, only reentrant syscalls.
// backtrace() is debatable (allocates on some libcs) but is used by Firefox,
// Chromium, and similar — deemed acceptable for crash-path diagnostics.
namespace {

constexpr size_t CRASH_BT_FRAMES = 64;

void write_str(int fd, const char *s) {
  (void)::write(fd, s, strlen(s));
}

void write_int(int fd, long v) {
  char buf[32];
  int n = snprintf(buf, sizeof(buf), "%ld", v);
  if (n > 0) (void)::write(fd, buf, n);
}

void fatal_signal_handler(int sig, siginfo_t *info, void *ucontext) {
  // Build the filename: /data/error_logs/ui_crash_<unix_epoch_sec>_<sig>.txt
  char path[128];
  time_t now = time(nullptr);
  snprintf(path, sizeof(path), "/data/error_logs/ui_crash_%ld_%d.txt", (long)now, sig);

  int fd = ::open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd < 0) {
    // Best-effort: fall back to default handler so the kernel still produces a tombstone.
    signal(sig, SIG_DFL);
    raise(sig);
    return;
  }

  write_str(fd, "ui crash\n");
  write_str(fd, "pid="); write_int(fd, (long)getpid()); write_str(fd, "\n");
  write_str(fd, "signal="); write_int(fd, sig); write_str(fd, "\n");
  write_str(fd, "time="); write_int(fd, (long)now); write_str(fd, "\n");
  if (info) {
    write_str(fd, "si_code="); write_int(fd, info->si_code); write_str(fd, "\n");
    if (sig == SIGSEGV || sig == SIGBUS) {
      write_str(fd, "si_addr=0x");
      char addrbuf[32];
      int n = snprintf(addrbuf, sizeof(addrbuf), "%lx", (unsigned long)info->si_addr);
      if (n > 0) (void)::write(fd, addrbuf, n);
      write_str(fd, "\n");
    }
  }
  write_str(fd, "backtrace:\n");
  void *frames[CRASH_BT_FRAMES];
  int nframes = backtrace(frames, CRASH_BT_FRAMES);
  // backtrace_symbols_fd writes demangled-ish frames directly to fd.
  backtrace_symbols_fd(frames, nframes, fd);

  ::close(fd);

  // Restore default handler and re-raise so tombstoned still runs + core dump.
  signal(sig, SIG_DFL);
  raise(sig);
}

void install_crash_handlers() {
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));
  sa.sa_sigaction = fatal_signal_handler;
  sa.sa_flags = SA_SIGINFO | SA_RESETHAND;
  sigemptyset(&sa.sa_mask);

  for (int sig : {SIGSEGV, SIGBUS, SIGABRT, SIGFPE, SIGILL}) {
    sigaction(sig, &sa, nullptr);
  }
}

}  // namespace

int main(int argc, char *argv[]) {
  setpriority(PRIO_PROCESS, 0, -20);
  install_crash_handlers();

  qInstallMessageHandler(swagLogMessageHandler);
  initApp(argc, argv);

  QTranslator translator;
  QString translation_file = QString::fromStdString(Params().get("LanguageSetting"));
  if (!translator.load(QString(":/%1").arg(translation_file)) && translation_file.length()) {
    qCritical() << "Failed to load translation file:" << translation_file;
  }

  QApplication a(argc, argv);
  a.installTranslator(&translator);

  MainWindow w;
  setMainWindow(&w);
  a.installEventFilter(&w);
  return a.exec();
}
