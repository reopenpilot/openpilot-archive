// Link-time configuration for jemalloc heap profiling.
//
// Setting the global `malloc_conf` symbol is how jemalloc reads its startup
// config without requiring the user to set MALLOC_CONF in the environment.
// The values here enable heap profiling with sparse sampling:
//   prof:true              — compile-time profiling is already on; enable at runtime
//   prof_active:true       — start sampling immediately (not lazily on first hint)
//   lg_prof_sample:21      — 1 sample per 2 MB of cumulative allocation.
//                            At this rate any allocator consuming >few MB is
//                            attributable, but the bookkeeping cost is <1 % CPU.
//   prof_prefix            — where prof.dump writes the .heap file
//   prof_silent:true       — don't print to stderr when a dump runs
//
// See https://jemalloc.net/jemalloc.3.html#opt.prof

#ifdef ENABLE_JEMALLOC_PROFILING
extern "C" const char *malloc_conf =
  "prof:true,prof_active:true,lg_prof_sample:21,"
  "prof_prefix:/data/error_logs/jeprof";
#endif
