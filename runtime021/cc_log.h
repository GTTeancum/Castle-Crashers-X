// SPDX-License-Identifier: MIT
// Logging seam for the Checkpoint 022 boundary harness so the identical
// driver source runs on the host (console) and on the original Xbox
// (nxdk debug console rendered on screen).
#pragma once

#ifdef CC_XBOX_DRIVER
#include <hal/debug.h>
#include <stdarg.h>
#include <stdio.h>
#include <windows.h>
#include <xboxkrnl/xboxkrnl.h>
// Monotonic nanoseconds without libc++ chrono (whose out-of-line clock
// functions are absent from the prebuilt nxdk libc++ on this machine).
static inline unsigned long long cc_monotonic_ns() {
  LARGE_INTEGER f, c;
  QueryPerformanceFrequency(&f);
  QueryPerformanceCounter(&c);
  const unsigned long long sec = (unsigned long long)(c.QuadPart / f.QuadPart);
  const unsigned long long rem = (unsigned long long)(c.QuadPart % f.QuadPart);
  return sec * 1000000000ull + rem * 1000000000ull / (unsigned long long)f.QuadPart;
}
static inline void cc_vlog(const char* fmt, va_list ap) {
  char buf[512];
  vsnprintf(buf, sizeof(buf), fmt, ap);
  debugPrint("%s", buf);
  DbgPrint("%s", buf);  // debug channel (XBDM debug strings on a development console)
}
#ifdef CC_FAST
// Play build: informational lines are dropped (the debug console sits
// behind the game picture, and each screenful costs a 1.2 MB clear);
// errors still print.
static inline void cc_log(const char*, ...) {}
#else
static inline void cc_log(const char* fmt, ...) {
  va_list ap; va_start(ap, fmt); cc_vlog(fmt, ap); va_end(ap);
}
#endif
static inline void cc_elog(const char* fmt, ...) {
  va_list ap; va_start(ap, fmt); cc_vlog(fmt, ap); va_end(ap);
}
#else
#include <cstdarg>
#include <cstdio>
#include <chrono>
static inline unsigned long long cc_monotonic_ns() {
  using namespace std::chrono;
  return (unsigned long long)duration_cast<nanoseconds>(
      steady_clock::now().time_since_epoch()).count();
}
static inline void cc_log(const char* fmt, ...) {
  va_list ap; va_start(ap, fmt); std::vprintf(fmt, ap); va_end(ap);
}
static inline void cc_elog(const char* fmt, ...) {
  va_list ap; va_start(ap, fmt); std::vfprintf(stderr, fmt, ap); va_end(ap);
}
#endif
