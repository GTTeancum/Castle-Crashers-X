// SPDX-License-Identifier: MIT
// Link shims for the prebuilt nxdk libc++ static library on this machine,
// which predates the clang in use and lacks a handful of out-of-line
// exception-thrower symbols that current headers reference. Exceptions are
// disabled in this build (-fno-exceptions); reaching any of these is a
// fatal driver error, reported on the debug console.
#include <hal/debug.h>
#include <windows.h>
#include <cstdlib>

// C++14 sized deallocation and C++17 aligned new/delete, absent from the
// prebuilt nxdk C++ runtime. Alignment requests beyond malloc's natural
// 16-byte alignment over-allocate and stash the base pointer.
void* operator new(unsigned int n) {
  void* p = std::malloc(n ? n : 1u);
  if (!p) { debugPrint("FATAL: new OOM (%u)\n", n); for(;;) Sleep(1000); }
  return p;
}
void* operator new[](unsigned int n) { return operator new(n); }
void operator delete(void* p) noexcept { std::free(p); }
void operator delete[](void* p) noexcept { std::free(p); }
void operator delete(void* p, unsigned int) noexcept { std::free(p); }
void operator delete[](void* p, unsigned int) noexcept { std::free(p); }
namespace std { enum class align_val_t : unsigned int {}; }
void* operator new(unsigned int n, std::align_val_t al) {
  const unsigned a = (unsigned)al < sizeof(void*) ? sizeof(void*) : (unsigned)al;
  unsigned char* raw = (unsigned char*)std::malloc(n + a + sizeof(void*));
  if (!raw) { debugPrint("FATAL: aligned new OOM (%u)\n", n); for(;;) Sleep(1000); }
  unsigned char* user = raw + sizeof(void*);
  user += a - ((unsigned)(uintptr_t)user & (a - 1u)) % a;
  ((void**)user)[-1] = raw;
  return user;
}
void operator delete(void* p, unsigned int, std::align_val_t) noexcept {
  if (p) std::free(((void**)p)[-1]);
}
void operator delete(void* p, std::align_val_t) noexcept {
  if (p) std::free(((void**)p)[-1]);
}

namespace {
[[noreturn]] void cc_libcxx_abort(const char* what) {
  debugPrint("FATAL libc++ shim: %s\n", what);
  for (;;) {
    Sleep(1000);
  }
}
}  // namespace

// pdclib's xbox math stubs assert instead of computing. The generated
// corpus maps the PPC vlogefp estimate instruction to log2f (12-bit
// hardware estimate on the 360); a double-precision log falls well inside
// the accepted estimate tolerance. Implemented via bit extraction plus
// atanh-series log on the reduced mantissa — no libm dependencies.
extern "C" float log2f(float x) {
  if (!(x > 0.0f)) {
    // Mirror IEEE conventions the estimate path can observe.
    if (x == 0.0f) return -3.402823466e38f;
    return __builtin_nanf("");
  }
  union { float f; unsigned u; } v; v.f = x;
  int e = int((v.u >> 23) & 0xFF);
  unsigned frac = v.u & 0x7FFFFFu;
  if (e == 0) { // subnormal: normalize
    while (!(frac & 0x800000u)) { frac <<= 1; --e; }
    frac &= 0x7FFFFFu; ++e;
  }
  e -= 127;
  v.u = (127u << 23) | frac; // m in [1,2)
  double m = v.f;
  // log(m) via atanh series on s=(m-1)/(m+1); converges fast on [1,2).
  const double s = (m - 1.0) / (m + 1.0), s2 = s * s;
  double log_m = 2.0 * s * (1.0 + s2 * (1.0/3 + s2 * (1.0/5 + s2 * (1.0/7 + s2 * (1.0/9 + s2/11)))));
  const double inv_ln2 = 1.4426950408889634;
  return float(double(e) + log_m * inv_ln2);
}
extern "C" float exp2f(float x) {
  if (x <= -150.0f) return 0.0f;
  if (x >= 128.0f) return __builtin_huge_valf();
  const int i = int(__builtin_floorf(x));
  const double f = double(x) - double(i);
  // 2^f = e^(f ln2), Taylor to ~1e-10 on [0,1).
  const double t = f * 0.6931471805599453;
  double r = 1.0, term = 1.0;
  for (int k = 1; k <= 12; ++k) { term *= t / k; r += term; }
  union { float fv; unsigned u; } sc;
  sc.u = unsigned(i + 127) << 23;
  return float(r) * sc.fv;
}

namespace std {
inline namespace __1 {
// MSVC-style mangling encodes member access; the real declarations are
// protected, so these must be too for the symbols to match.
template <bool>
struct __vector_base_common {
 protected:
  [[noreturn]] void __throw_length_error() const;
  [[noreturn]] void __throw_out_of_range() const;
};
template <>
void __vector_base_common<true>::__throw_length_error() const {
  cc_libcxx_abort("vector length_error");
}
template <>
void __vector_base_common<true>::__throw_out_of_range() const {
  cc_libcxx_abort("vector out_of_range");
}
template <bool>
struct __basic_string_common {
 protected:
  [[noreturn]] void __throw_length_error() const;
  [[noreturn]] void __throw_out_of_range() const;
};
template <>
void __basic_string_common<true>::__throw_length_error() const {
  cc_libcxx_abort("string length_error");
}
template <>
void __basic_string_common<true>::__throw_out_of_range() const {
  cc_libcxx_abort("string out_of_range");
}
}  // namespace __1
}  // namespace std

// Main menu "Quit": hand control back to the dashboard. A null path asks
// the kernel to launch the dashboard (the port mounts no C: drive, so a
// path would not resolve); if that returns, reboot to it.
#include <hal/xbox.h>
#include <xboxkrnl/xboxkrnl.h>
// Back to the dashboard (main menu Quit, in-game reset): a dashboard launch
// page as nxdk's XLaunchXBEEx(NULL) writes it, then written back from the
// CPU cache before the quick reboot (real hardware can otherwise enter the
// firmware with stale cache lines of the page and crash; found by Perfect
// Dark X). Without a page, a full reboot.
[[noreturn]] void cc_xbox_return_to_dashboard() {
  const ULONG size = 0x1000;
  if (!LaunchDataPage) LaunchDataPage = static_cast<PLAUNCH_DATA_PAGE>(MmAllocateContiguousMemory(size));
  if (!LaunchDataPage) HalReturnToFirmware(HalRebootRoutine);
  MmPersistContiguousMemory(LaunchDataPage, size, TRUE);
  __builtin_memset(LaunchDataPage, 0, size);
  LaunchDataPage->Header.dwLaunchDataType = LDT_LAUNCH_DASHBOARD;
  LaunchDataPage->Header.dwTitleId = CURRENT_XBE_HEADER->CertificateHeader->TitleID;
  LaunchDataPage->Header.dwFlags = 0;
  __asm__ __volatile__("sfence" ::: "memory");
  __asm__ __volatile__("wbinvd" ::: "memory");
  HalReturnToFirmware(HalQuickRebootRoutine);
  for (;;) Sleep(1000);
}

// Fast memcpy/memmove/memset. nxdk builds its PDCLib without optimisation,
// so its versions are byte loops with every variable on the stack (12-17
// instructions per byte); a 2.6 KB register-file copy per matrix push once
// cost ~7 ms per frame. These definitions take precedence over the library
// archive members (one function per object there). Inline asm keeps clang
// from turning the loops back into calls to themselves; DF is clear per the
// calling convention.
extern "C" void* memcpy(void* dst, const void* src, unsigned int n) {
  void* d = dst; const void* s = src; unsigned int q = n >> 2, r = n & 3u;
  __asm__ volatile("rep movsl" : "+D"(d), "+S"(s), "+c"(q) : : "memory");
  __asm__ volatile("rep movsb" : "+D"(d), "+S"(s), "+c"(r) : : "memory");
  return dst;
}
extern "C" void* memmove(void* dst, const void* src, unsigned int n) {
  unsigned char* d = (unsigned char*)dst; const unsigned char* s = (const unsigned char*)src;
  if (d <= s || d >= s + n) return memcpy(dst, src, n);
  // Overlapping with dst above src: copy backwards.
  void* de = d + n - 1; const void* se = s + n - 1; unsigned int c = n;
  __asm__ volatile("std\n\trep movsb\n\tcld" : "+D"(de), "+S"(se), "+c"(c) : : "memory", "cc");
  return dst;
}
extern "C" void* memset(void* dst, int v, unsigned int n) {
  const unsigned int b = (unsigned char)v, w = b * 0x01010101u;
  void* d = dst; unsigned int q = n >> 2, r = n & 3u;
  __asm__ volatile("rep stosl" : "+D"(d), "+c"(q) : "a"(w) : "memory");
  __asm__ volatile("rep stosb" : "+D"(d), "+c"(r) : "a"(w) : "memory");
  return dst;
}
