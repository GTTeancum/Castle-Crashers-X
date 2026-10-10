// SPDX-License-Identifier: MIT
// Flat guest window (play build): every guest region the game uses is
// committed at one fixed place in host memory, so a guest access is the
// window base plus the guest address, with no table and no branch.
//
// Window offset = the guest address's low 29 bits, plus 0x20000000 when bit
// 31 is set (a sign-mask select): guest 0..0x1FFFFFFF at offsets 0.., the
// guest image at 0x82000000 at offset 0x22000000 (a plain mask would fold
// it onto the graphics arena at 0x02000000). Every guest address therefore
// lands in the window's 1 GiB, all of it reserved (Xbox 0x40000000..
// 0x7FFFFFFF, below the kernel's 0x80000000+): a stray address faults on an
// uncommitted page or aliases guest memory, but never reaches kernel memory
// (the title runs in ring 0). The mask costs one AND per access over the
// plain select, plus one add where the guest address has a displacement
// (x86 can no longer fold it into the addressing mode); stack accesses keep
// the unmasked form (see low_ptr). Window layout (offsets): stack 0x30000, TLS/heap block
// 0x60000..0xE71000, graphics arena and platform globals 0x02000000..
// 0x02502000, CRT heap 0x04000000, main pool 0x10000000, physical zones
// 0x12000000 / 0x1D000000 / 0x1E000000, image 0x22000000..0x222D0000.
// Not in the window: the texture cache zone 0x1C000000 (the NV2A samples it,
// so it stays physically contiguous memory; only port natives reach it,
// through AddressSpace::contiguous) and the two 640x480 surfaces of the 360
// device, which nothing reads or writes (their interior pages stay
// uncommitted, see kHoles).
//
// The 360 command ring (2 MiB at 0x0200F140) is written by the game and read
// by nothing, so its whole 64 KiB-aligned pages 0x02010000..0x02200000 share
// one 256 KiB block, repeated (the page-table build's aliasing, moved to page
// granularity): Xbox page-table entries pointed at one contiguous block, host
// views of one file mapping. That saves ~1.7 MiB on the Xbox. Off: host
// CC_RING_ALIAS=0, Xbox make NORINGALIAS=1 (the ring is committed in full).
//
// Xbox make LARGEPAGES=1: the guest stack, TLS and game heap (window
// 0..16 MiB) and the game data image are backed by 4 MiB pages (page
// directory entries written in ring 0 over physically contiguous memory), so
// the Pentium III's data TLB covers them with 5 entries instead of thousands
// of 4 KiB entries; ~3 MiB more memory (the chunks' unused tails). Any failed
// step falls back to 4 KiB pages for that region. LARGEPAGES=heap or =image
// for one of them. Host CC_LARGE_PAGES=<mask> lays the window out the same
// way (whole 4 MiB chunks committed) to test that path. Mask: 1 stack/TLS/
// heap, 2 image.
// - The gaps the 4 KiB layout leaves unmapped inside those chunks (guest
//   0..0x30000, 0x40000..0x60000, 0xE71000..0x1000000, the image chunk's
//   tail) are ordinary zeroed memory there: a stray access reads zeros
//   instead of stopping, and a game heap outgrowing its 14 MiB runs on to
//   16 MiB. Builds can therefore differ only on paths that are broken anyway.
// - No direct kernel I/O (NtReadFile into a window buffer, DMA, anything
//   that locks or translates its pages) may target a region on 4 MiB pages:
//   the kernel finds a buffer's 4 KiB page-table entries through its
//   self-map, which for a 4 MiB page is the page's own memory (game data).
//   Data reaches the window through copies today (fread's buffer).
//
// Build switch: CC_PAGE_TABLE keeps the 64 KiB page-table path of earlier
// play builds (verification build; make PAGETABLE=1 on the Xbox).
#pragma once
#include <stdint.h>
// Backed game heap at 0x71000 (runtime021/update_boundary_tests.cpp; the
// game's allocator is told CC_GAME_HEAP_LIMIT there). Host bake runs raise it.
#ifndef CC_GAME_HEAP_BYTES
#define CC_GAME_HEAP_BYTES 0xE00000
#endif
#ifndef CC_GAME_HEAP_LIMIT
#define CC_GAME_HEAP_LIMIT 0x1000000
#endif
// Main pool backing at 0x10000000 (the game reserves 16 MiB): 7.5 MiB.
// Four-player runs of all 58 levels (host CC_POOL_HWM, console HWM lines,
// the same numbers) peak at 3.6-6.3 MiB, except level 35: 6.9 MiB, reached
// as the level loads. 4.5 MiB stopped level 11 after level 13.
#ifndef CC_MAIN_POOL_BYTES
#define CC_MAIN_POOL_BYTES 0x780000
#endif
#if defined(CC_FAST) && !defined(CC_PAGE_TABLE)
#define CC_FLAT_WINDOW 1
#elif defined(CC_FAST)
#define CC_PAGE_TABLE_FAST 1
#endif
namespace cc_win {
constexpr uint32_t kImageGuest = 0x82000000u;
constexpr uint32_t kImageOffset = 0x22000000u;
constexpr uint32_t kSpan = 0x22300000u;  // bytes the layout uses (image end, rounded up)
// Offsets of addresses with bit 31 set start at kHalf; the reservation
// covers both halves.
constexpr uint32_t kHalf = 0x20000000u, kLowMask = kHalf - 1u, kWindowBytes = 2u * kHalf;
static_assert((kImageGuest & kLowMask) + kHalf == kImageOffset, "image offset");
// Reserved below the window too: a stack access (r1 plus a constant, see
// low_ptr) may reach up to 32 KiB below it.
constexpr uint32_t kGuardBelow = 0x10000u;
// A host fault at this window offset is a guest access (offsets below the
// window wrap to the top of the address range).
inline bool fault_in_window(uintptr_t off) {
  return off < uintptr_t(kWindowBytes) || off >= uintptr_t(0) - uintptr_t(kGuardBelow);
}
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
// The 360 device's command ring (graphics arena piece) and the block its
// whole pages share when aliased.
constexpr uint32_t kRingLo = 0x0200F140u, kRingBytes = 0x200000u, kRingBlock = 0x40000u;
// What open() lays out:
//   commit: guest ranges to back (page-rounded and merged);
//   alias:  a guest range inside them whose 64 KiB-aligned interior shares
//           one block of alias_period bytes, repeated (memory nothing reads
//           back); alias_period 0 commits it like the rest;
//   large:  guest ranges to back with 4 MiB pages where possible (the 4 MiB
//           chunks they touch; Xbox LARGEPAGES builds, host emulation).
struct Layout {
  const Range* commit;
  unsigned commit_count;
  Range alias;
  uint32_t alias_period;
  const Range* large;
  unsigned large_count;
};
#ifdef CC_XBOX_DRIVER
// Fixed base in the title's user address space, the upper half of it
// (nothing else is mapped there: the XBE and its heap sit near the bottom,
// the kernel at 0x80000000 and above).
constexpr uintptr_t kBase = 0x40000000u;
#define CC_WINDOW_BASE (::cc_win::kBase)
#else
extern uint8_t* g_base;  // host: wherever the reservation landed
#define CC_WINDOW_BASE (uintptr_t(::cc_win::g_base))
#endif
// The select without the mask (the window's earlier form): a stray guest
// address can reach kernel memory through it.
__attribute__((always_inline)) inline uintptr_t select_offset(uint32_t a) {
  return uintptr_t(a) + (uintptr_t(intptr_t(int32_t(a) >> 31)) &
                         uintptr_t(intptr_t(int32_t(kImageOffset - kImageGuest))));
}
// Build switches for timing the mask (4P fight, host count: ~470K guest
// loads and ~150K stores per frame go through it):
//   CC_WINDOW_NOMASK (Xbox make NOWINDOWMASK=1): no mask anywhere;
//   CC_WINDOW_MASK_STORES (make WINDOWMASK=stores): generated code's loads
//     skip it (load_ptr), so no stray write can reach kernel memory, but a
//     stray read may read it or stop the kernel instead of the failure bar.
__attribute__((always_inline)) inline uintptr_t offset(uint32_t a) {
#ifndef CC_WINDOW_NOMASK
  return uintptr_t(a & kLowMask) + uintptr_t(uint32_t(int32_t(a) >> 31) & kHalf);
#else
  return select_offset(a);
#endif
}
__attribute__((always_inline)) inline uint8_t* ptr(uint32_t a) {
  return reinterpret_cast<uint8_t*>(CC_WINDOW_BASE + offset(a));
}
__attribute__((always_inline)) inline const uint8_t* load_ptr(uint32_t a) {
#ifdef CC_WINDOW_MASK_STORES
  return reinterpret_cast<const uint8_t*>(CC_WINDOW_BASE + select_offset(a));
#else
  return ptr(a);
#endif
}
// r1 plus a constant (stack accesses): the guest stacks are low memory, so
// no select and no mask (masking would cost two instructions on every stack
// access). r1 is kept below 0x20000000 where it is loaded from memory (the
// stack's back chain and the context restore; bridge.cpp REX_LOAD_U32), and
// compiled code otherwise moves it only by constants, so these accesses
// stay within 32 KiB of the window.
__attribute__((always_inline)) inline uint8_t* low_ptr(uint32_t a) {
  return reinterpret_cast<uint8_t*>(CC_WINDOW_BASE + uintptr_t(a));
}
// What a faulting guest address is, for the stop report: the failure bar
// shows code 4 (instead of 3) for a game-heap block past the backed heap.
inline bool past_backed_heap(uint32_t a) {
  return a >= 0x71000u + CC_GAME_HEAP_BYTES && a < 0x71000u + CC_GAME_HEAP_LIMIT;
}
inline const char* fault_note(uint32_t a) {
  if (a < 0x10000u) return "null pointer";
  if (past_backed_heap(a)) return "game heap block past the backed heap";
  return "unmapped";
}
inline bool in_window(const void* p) {
  return uintptr_t(p) - CC_WINDOW_BASE < uintptr_t(kWindowBytes);
}
// Reserve the window and back it as the layout says (guest_window.cpp).
// Returns false if the window cannot be placed or committed; says on the
// debug channel which memory paths are active and how much is committed. The
// host also reports a fault inside the window with its guest address.
bool open(const Layout& layout);
// Whether open() shares one block between the command ring's pages (then
// the ring's bytes differ from a layout that keeps them all).
bool ring_shared();
// Guest address of a window offset: the inverse of offset() for guest
// addresses below 0x20000000 or from 0x80000000 to 0x9FFFFFFF (for a stray
// elsewhere, the one of those it folded onto); an offset in the guard below
// the window gives the r1-relative address below zero.
uint32_t guest_of(uintptr_t window_offset);
// High-water mark of guest memory [lo, hi): the end of the highest 4 KiB
// page holding a nonzero byte, in bytes above lo (committed pages start
// zeroed and nothing returns them to zero, so it only climbs). *peak carries
// the previous answer between calls; pages under it are not scanned again.
uint32_t used_top(uint32_t lo, uint32_t hi, uint32_t* peak);
}  // namespace cc_win
