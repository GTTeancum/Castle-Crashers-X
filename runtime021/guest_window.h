// SPDX-License-Identifier: MIT
// Flat guest window (play build): every guest region the game uses is
// committed at one fixed place in host memory, so a guest access is the
// window base plus the guest address, with no table and no branch.
//
// The guest image sits at 0x82000000, which a plain mask would fold onto the
// graphics arena at 0x02000000, so addresses with bit 31 set move down by
// 0x60000000 (a sign-mask select): window offset = a, or a - 0x60000000 for
// a >= 0x80000000. Window layout (offsets): stack 0x30000, TLS/heap block
// 0x60000..0xE71000, graphics arena and platform globals 0x02000000..
// 0x02502000, CRT heap 0x04000000, main pool 0x10000000, physical zones
// 0x12000000 / 0x1D000000 / 0x1E000000, image 0x22000000..0x222D0000.
// Not in the window: the texture cache zone 0x1C000000 (the NV2A samples it,
// so it stays physically contiguous memory; only port natives reach it,
// through AddressSpace::contiguous) and the two 640x480 surfaces of the 360
// device, which nothing reads or writes (their interior pages stay
// uncommitted, see kHoles).
//
// Build switch: CC_PAGE_TABLE keeps the 64 KiB page-table path of earlier
// play builds (verification build; make PAGETABLE=1 on the Xbox).
#pragma once
#include <stdint.h>
#if defined(CC_FAST) && !defined(CC_PAGE_TABLE)
#define CC_FLAT_WINDOW 1
#elif defined(CC_FAST)
#define CC_PAGE_TABLE_FAST 1
#endif
namespace cc_win {
constexpr uint32_t kImageGuest = 0x82000000u;
constexpr uint32_t kImageOffset = 0x22000000u;
constexpr uint32_t kSpan = 0x22300000u;  // reserved bytes (image end, rounded up)
// The 360 device's two 640x480x32 surfaces (graphics arena pieces); their
// interior pages are never committed.
constexpr uint32_t kSurfaceA = 0x02211770u, kSurfaceB = 0x02344FA0u, kSurfaceBytes = 0x12C000u;
struct Range { uint32_t lo, hi; };
constexpr Range kHoles[] = {
  {(kSurfaceA + 0xFFFu) & ~0xFFFu, (kSurfaceA + kSurfaceBytes) & ~0xFFFu},
  {(kSurfaceB + 0xFFFu) & ~0xFFFu, (kSurfaceB + kSurfaceBytes) & ~0xFFFu},
};
inline bool in_hole(uint32_t a) {
  for (const Range& h : kHoles) if (a - h.lo < h.hi - h.lo) return true;
  return false;
}
#ifdef CC_XBOX_DRIVER
// Fixed base in the title's user address space (nothing else is mapped
// there: the XBE and its heap sit near the bottom, the kernel above
// 0x80000000).
constexpr uintptr_t kBase = 0x40000000u;
#define CC_WINDOW_BASE (::cc_win::kBase)
#else
extern uint8_t* g_base;  // host: wherever the reservation landed
#define CC_WINDOW_BASE (uintptr_t(::cc_win::g_base))
#endif
__attribute__((always_inline)) inline uintptr_t offset(uint32_t a) {
  return uintptr_t(a) + (uintptr_t(intptr_t(int32_t(a) >> 31)) &
                         uintptr_t(intptr_t(int32_t(kImageOffset - kImageGuest))));
}
__attribute__((always_inline)) inline uint8_t* ptr(uint32_t a) {
  return reinterpret_cast<uint8_t*>(CC_WINDOW_BASE + offset(a));
}
// r1-relative accesses: the guest stacks are low memory, so no select.
__attribute__((always_inline)) inline uint8_t* low_ptr(uint32_t a) {
  return reinterpret_cast<uint8_t*>(CC_WINDOW_BASE + uintptr_t(a));
}
inline bool in_window(const void* p) {
  return uintptr_t(p) - CC_WINDOW_BASE < uintptr_t(kSpan);
}
// Reserve the window and commit the given guest ranges (page-rounded and
// merged). Returns false if the window cannot be placed; says on the debug
// channel which memory path is active and how much is committed. The host
// also reports a fault inside the window with its guest address.
bool open(const Range* ranges, unsigned count);
// Guest address of a window offset (the inverse of offset()).
uint32_t guest_of(uintptr_t window_offset);
}  // namespace cc_win
