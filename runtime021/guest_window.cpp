// SPDX-License-Identifier: MIT
// Flat guest window (guest_window.h): reserving the window and backing the
// guest regions, the aliased 360 command ring and, in Xbox LARGEPAGES
// builds, 4 MiB pages for the hottest regions.
#include "guest_window.h"
#ifdef CC_FLAT_WINDOW
#include "cc_log.h"
#include <cstdio>
#include <cstdlib>
#ifdef CC_XBOX_DRIVER
// nxdk-checkpoint022/xbox_perf.cpp: MEM line with the kernel's free memory.
void cc_xbox_mem_line(const char* when);
#else
extern "C" {
__declspec(dllimport) void* __stdcall VirtualAlloc(void*, size_t, unsigned long, unsigned long);
__declspec(dllimport) int __stdcall VirtualFree(void*, size_t, unsigned long);
__declspec(dllimport) void* __stdcall CreateFileMappingA(void*, void*, unsigned long, unsigned long, unsigned long, const char*);
__declspec(dllimport) void* __stdcall MapViewOfFileEx(void*, unsigned long, unsigned long, unsigned long, size_t, void*);
__declspec(dllimport) int __stdcall UnmapViewOfFile(const void*);
__declspec(dllimport) int __stdcall CloseHandle(void*);
__declspec(dllimport) void* __stdcall GetModuleHandleA(const char*);
__declspec(dllimport) unsigned short __stdcall RtlCaptureStackBackTrace(unsigned long, unsigned long, void**, unsigned long*);
}
struct CcExceptionRecord {
  unsigned long code, flags;
  CcExceptionRecord* next;
  void* address;
  unsigned long count;
  uintptr_t info[15];
};
struct CcExceptionPointers { CcExceptionRecord* record; void* context; };
extern "C" __declspec(dllimport) void* __stdcall AddVectoredExceptionHandler(
    unsigned long first, long(__stdcall* handler)(CcExceptionPointers*));
#endif

namespace cc_win {
uint32_t guest_of(uintptr_t window_offset) {
  if (window_offset >= kWindowBytes) return uint32_t(window_offset);  // guard below the window
  return window_offset >= kHalf ? uint32_t(window_offset) + (kImageGuest - kImageOffset) : uint32_t(window_offset);
}
uint32_t used_top(uint32_t lo, uint32_t hi, uint32_t* peak) {
  for (uint32_t pg = hi; pg > lo + *peak; pg -= 4096u) {
    const uint32_t* w = reinterpret_cast<const uint32_t*>(ptr(pg - 4096u));
    uint32_t any = 0;
    for (uint32_t i = 0; i < 1024u; ++i) any |= w[i];
    if (any) { *peak = pg - lo; break; }
  }
  return *peak;
}
#ifndef CC_XBOX_DRIVER
uint8_t* g_base = nullptr;
// Host: a guest access outside the committed window faults; report the
// guest address (like a harness memory stop) instead of a bare crash.
static long __stdcall fault_report(CcExceptionPointers* ep) {
  const CcExceptionRecord* r = ep->record;
  if (r->code != 0xC0000005ul || r->count < 2) return 0;  // EXCEPTION_CONTINUE_SEARCH
  const uintptr_t off = r->info[1] - uintptr_t(g_base);
  if (!fault_in_window(off)) return 0;
  cc_elog("FAIL flat window: guest %08x not mapped (%s, %s)\n", guest_of(off), r->info[0] ? "write" : "read",
          fault_note(guest_of(off)));
  if (std::getenv("CC_FAULT_TRACE")) {
    // Host code addresses (offsets from the exe's base) of the faulting
    // instruction and the stack, for llvm-symbolizer on a -g build.
    const uintptr_t mod = uintptr_t(GetModuleHandleA(nullptr));
    cc_elog("FAULTPC %llx\n", (unsigned long long)(uintptr_t(r->address) - mod));
    void* frames[24];
    const unsigned short n = RtlCaptureStackBackTrace(0, 24, frames, nullptr);
    for (unsigned short i = 0; i < n; ++i) cc_elog("FAULTSTACK %llx\n", (unsigned long long)(uintptr_t(frames[i]) - mod));
  }
  std::fflush(nullptr);
  std::exit(1);
}
#endif

namespace {
constexpr uint32_t kPage = 0x1000u, kChunk = 0x400000u;  // 4 KiB and 4 MiB pages
constexpr uint32_t kNone = 0xFFFFFFFFu;
constexpr unsigned kMaxGroups = 12;

// Sorted list of window-offset ranges.
struct List {
  Range r[32];
  unsigned n = 0;
  bool add(uint32_t lo, uint32_t hi) {
    if (hi <= lo) return true;
    if (n == 32u) return false;
    unsigned k = n++;
    while (k && r[k - 1].lo > lo) { r[k] = r[k - 1]; --k; }
    r[k] = Range{lo, hi};
    return true;
  }
  void merge() {
    unsigned m = 0;
    for (unsigned i = 0; i < n; ++i) {
      if (m && r[i].lo <= r[m - 1].hi) {
        if (r[i].hi > r[m - 1].hi) r[m - 1].hi = r[i].hi;
      } else {
        r[m++] = r[i];
      }
    }
    n = m;
  }
};

// A run of 4 MiB chunks (window offsets c0 * 4 MiB ..) to back with large pages.
struct Group {
  uint32_t c0, n;
  void* block;  // contiguous memory (Xbox), the kernel's own mapping of it
  uint32_t phys;
  bool on;
  const char* why;  // why not, when off
};

uint32_t g_committed = 0;  // bytes committed as 4 KiB pages
bool g_ring_shared = false;

#ifdef CC_XBOX_DRIVER
// Retail consoles have 64 MiB: keep the contiguous blocks below it so a
// development console (128 MiB) measures the retail layout.
constexpr ULONG_PTR kRetailTop = 0x03FFFFFFu;

// Committed pages come back zero-filled (NtAllocateVirtualMemory's contract,
// as for VirtualAlloc), so they are not cleared again.
bool commit(uint32_t lo, uint32_t hi) {
  PVOID b = reinterpret_cast<PVOID>(kBase + lo);
  SIZE_T s = hi - lo;
  const NTSTATUS st = NtAllocateVirtualMemory(&b, 0, &s, MEM_COMMIT, PAGE_READWRITE);
  if (!NT_SUCCESS(st)) {
    DbgPrint("MEM flat window: commit %08x+%08x failed status=%08x\n", unsigned(kBase + lo), unsigned(hi - lo),
             unsigned(st));
    return false;
  }
  g_committed += hi - lo;
  return true;
}

// The kernel keeps the page tables mapped at 0xC0000000: the entry for
// virtual address v at 0xC0000000 + (v >> 12) * 4, the page directory at
// 0xC0300000 (its entry 0x300 points at the directory itself). pte_template
// checks that layout before anything relies on it.
inline volatile uint32_t* pte_of(uintptr_t va) {
  return reinterpret_cast<volatile uint32_t*>(0xC0000000u + ((va >> 12) << 2));
}
inline volatile uint32_t* pde_of(uintptr_t va) {
  return reinterpret_cast<volatile uint32_t*>(0xC0300000u + ((va >> 22) << 2));
}
inline uint32_t read_cr3() { uint32_t v; __asm__ volatile("mov %%cr3, %0" : "=r"(v)); return v; }
inline uint32_t read_cr4() { uint32_t v; __asm__ volatile("mov %%cr4, %0" : "=r"(v)); return v; }
// Reloading CR3 drops every non-global TLB entry (window entries are never
// global). The entries written here replace not-present ones, which the
// TLB never holds; the flush is belt and braces.
inline void flush_tlb() { __asm__ volatile("mov %%cr3, %%eax\n\tmov %%eax, %%cr3" : : : "eax", "memory"); }
inline uint32_t irq_off() {
  uint32_t f;
  __asm__ volatile("pushfl\n\tpopl %0\n\tcli" : "=r"(f) : : "memory");
  return f;
}
inline void irq_restore(uint32_t f) { __asm__ volatile("pushl %0\n\tpopfl" : : "r"(f) : "memory", "cc"); }

// Hardware bits (present, writable, user, write-through, cache-disable) of
// the kernel's page-table entry for a committed 4 KiB window page, or 0 if
// the page tables are not laid out as expected (then nothing is written).
uint32_t pte_template(uintptr_t va, const char** why) {
  if (read_cr4() & 0x20u) { *why = "PAE paging"; return 0; }
  if (!MmIsAddressValid(reinterpret_cast<PVOID>(0xC0300C00u))) { *why = "no page-table map"; return 0; }
  const uint32_t self = *pde_of(0xC0000000u);
  if (!(self & 1u) || ((self ^ read_cr3()) & 0xFFFFF000u)) { *why = "page directory not self-mapped"; return 0; }
  const uint32_t pde = *pde_of(va);
  if ((pde & 0x81u) != 0x01u) { *why = "template page table"; return 0; }
  const uint32_t pte = *pte_of(va);
  const uint32_t phys = uint32_t(MmGetPhysicalAddress(reinterpret_cast<PVOID>(va)));
  if ((pte & 3u) != 3u || ((pte ^ phys) & 0xFFFFF000u)) { *why = "template entry"; return 0; }
  return pte & 0x1Fu;
}

// Point the page-directory entries of the group's chunks at its contiguous
// block as 4 MiB pages. Why this cannot disturb the kernel's own mappings:
// - only entries for the window's own reservation change (directory entries
//   0x100..0x103 and 0x188, all below 0x80000000; the kernel's are above),
//   and only ones that are not present: no page table exists there because
//   nothing was committed in those chunks, and the reservation keeps the
//   kernel from placing anything else there;
// - the memory is the kernel's contiguous memory, which it never moves (its
//   own mapping is fixed at 0x80000000 + physical) and which nothing else
//   owns; both mappings are write-back, so the caches stay consistent;
// - nothing in the window is ever decommitted or freed, so the kernel never
//   walks these entries (a quick reboot re-initialises memory management;
//   only memory marked persistent survives it);
// - nothing hands these addresses to kernel I/O: never read a file
//   (NtReadFile) or DMA straight into a 4 MiB-page region. The kernel would
//   look up the buffer's 4 KiB page-table entries at 0xC0000000 + (va >>
//   12) * 4, which under a 4 MiB page is the page's own memory (game data).
//   File data reaches the window through copies (fread's buffer).
// 4 MiB pages must be enabled (CR4.PSE, checked). CR3 is reloaded after the
// writes.
bool map_large(Group& g, uint32_t tmpl) {
  if (!(read_cr4() & 0x10u)) { g.why = "no 4 MiB pages (CR4.PSE)"; return false; }
  const uintptr_t va = kBase + uintptr_t(g.c0) * kChunk;
  uint32_t saved[8];
  if (g.n > 8u) { g.why = "too many chunks"; return false; }
  for (uint32_t i = 0; i < g.n; ++i) {
    saved[i] = *pde_of(va + i * kChunk);
    if (saved[i] & 1u) { g.why = "page table present"; return false; }
  }
  __builtin_memset(g.block, 0, size_t(g.n) * kChunk);  // through the kernel's mapping
  // present, writable, user as the template; accessed, dirty, 4 MiB page;
  // write-back caching like the kernel's own mapping of the block.
  const uint32_t flags = (tmpl & 0x07u) | 0x60u | 0x80u;
  const uint32_t f = irq_off();
  for (uint32_t i = 0; i < g.n; ++i) *pde_of(va + i * kChunk) = (g.phys + i * kChunk) | flags;
  flush_tlb();
  irq_restore(f);
  // A word written through the window must read back through the kernel's
  // mapping of the block.
  bool ok = true;
  for (uint32_t i = 0; i < g.n; ++i) {
    volatile uint32_t* w = reinterpret_cast<volatile uint32_t*>(va + i * kChunk + 0x1230u);
    volatile uint32_t* k = reinterpret_cast<volatile uint32_t*>(static_cast<uint8_t*>(g.block) + i * kChunk + 0x1230u);
    *w = 0x5AA5C33Cu ^ i;
    ok = ok && *k == (0x5AA5C33Cu ^ i);
    *w = 0;
  }
  if (!ok) {
    const uint32_t f2 = irq_off();
    for (uint32_t i = 0; i < g.n; ++i) *pde_of(va + i * kChunk) = saved[i];
    flush_tlb();
    irq_restore(f2);
    g.why = "read-back mismatch";
    return false;
  }
  return true;
}

// Point the page-table entries of window pages [lo, hi) at the contiguous
// block, page p at block byte (p - lo) % period. Only entries that are not
// present are written (reserved, never committed pages); the page table
// itself exists because neighbouring pages of the same 4 MiB were committed,
// and it stays because nothing in the window is ever decommitted.
bool alias_pages(uint32_t lo, uint32_t hi, uint32_t period, void* block, uint32_t phys, uint32_t tmpl,
                 const char** why) {
  static uint32_t saved[0x200];
  if ((hi - lo) / kPage > 0x200u) { *why = "range too long"; return false; }
  const uintptr_t a = kBase + lo, b = kBase + hi;
  for (uintptr_t v = a & ~uintptr_t(kChunk - 1u); v < b; v += kChunk) {
    if ((*pde_of(v) & 0x81u) != 0x01u) { *why = "no page table"; return false; }
  }
  for (uintptr_t v = a; v < b; v += kPage) {
    if (*pte_of(v) & 1u) { *why = "page already committed"; return false; }
  }
  __builtin_memset(block, 0, period);  // through the kernel's mapping
  const uint32_t flags = (tmpl & 0x1Fu) | 0x60u;  // as the template; accessed, dirty
  const uint32_t f = irq_off();
  for (uintptr_t v = a; v < b; v += kPage) {
    saved[(v - a) / kPage] = *pte_of(v);
    *pte_of(v) = (phys + uint32_t(v - a) % period) | flags;
  }
  flush_tlb();
  irq_restore(f);
  // Each repeat's first word must land in the block's first word.
  bool ok = true;
  volatile uint32_t* k = reinterpret_cast<volatile uint32_t*>(static_cast<uint8_t*>(block) + 0x120u);
  for (uintptr_t v = a; v < b; v += period) {
    volatile uint32_t* w = reinterpret_cast<volatile uint32_t*>(v + 0x120u);
    *w = 0xC33C5AA5u ^ uint32_t(v);
    ok = ok && *k == (0xC33C5AA5u ^ uint32_t(v));
  }
  *k = 0;
  if (!ok) {
    const uint32_t f2 = irq_off();
    for (uintptr_t v = a; v < b; v += kPage) *pte_of(v) = saved[(v - a) / kPage];
    flush_tlb();
    irq_restore(f2);
    *why = "read-back mismatch";
    return false;
  }
  return true;
}
#else
bool commit(uint32_t lo, uint32_t hi) {
  if (!VirtualAlloc(g_base + lo, hi - lo, 0x1000u /*MEM_COMMIT*/, 0x04u /*PAGE_READWRITE*/)) return false;
  g_committed += hi - lo;
  return true;
}

// Host: reserve the window with pages [lo, hi) (64 KiB-aligned) as views of
// one file mapping of `period` bytes, the layout the Xbox builds with its
// page tables. A failed step undoes the others.
bool reserve_aliased(uint32_t lo, uint32_t hi, uint32_t period) {
  constexpr unsigned long kReserve = 0x2000u, kRelease = 0x8000u, kNoAccess = 0x01u;
  uint8_t* b = static_cast<uint8_t*>(VirtualAlloc(nullptr, kWindowBytes, kReserve, kNoAccess));
  if (!b) return false;
  VirtualFree(b, 0, kRelease);  // keep the address, place the pieces there
  void* h = CreateFileMappingA(reinterpret_cast<void*>(intptr_t(-1)), nullptr, 0x04u /*PAGE_READWRITE*/, 0, period,
                               nullptr);
  const bool below = h && VirtualAlloc(b, lo, kReserve, kNoAccess) == b;
  const bool above = below && VirtualAlloc(b + hi, kWindowBytes - hi, kReserve, kNoAccess) == b + hi;
  void* views[16];
  unsigned nv = 0;
  bool ok = above && (hi - lo) / period < 16u;
  for (uint32_t a = lo; ok && a < hi; a += period) {
    void* v = MapViewOfFileEx(h, 0xF001Fu /*FILE_MAP_ALL_ACCESS*/, 0, 0, hi - a < period ? hi - a : period, b + a);
    if (v) views[nv++] = v;
    ok = v == b + a;
  }
  if (h) CloseHandle(h);  // the views keep the mapping
  if (ok) {
    g_base = b;
    return true;
  }
  for (unsigned i = 0; i < nv; ++i) UnmapViewOfFile(views[i]);
  if (above) VirtualFree(b + hi, 0, kRelease);
  if (below) VirtualFree(b, 0, kRelease);
  return false;
}
#endif

// Commit the parts of the page list inside [clip_lo, clip_hi) that no
// excluded range covers (excl sorted, merged).
bool commit_pages(const List& pages, uint32_t clip_lo, uint32_t clip_hi, const List& excl) {
  for (unsigned i = 0; i < pages.n; ++i) {
    uint32_t cur = pages.r[i].lo > clip_lo ? pages.r[i].lo : clip_lo;
    const uint32_t end = pages.r[i].hi < clip_hi ? pages.r[i].hi : clip_hi;
    for (unsigned j = 0; j < excl.n && cur < end; ++j) {
      const Range& e = excl.r[j];
      if (e.hi <= cur || e.lo >= end) continue;
      if (e.lo > cur && !commit(cur, e.lo)) return false;
      cur = e.hi;
    }
    if (cur < end && !commit(cur, end)) return false;
  }
  return true;
}

// First page of the list that commit_pages(pages, all, excl) commits.
[[maybe_unused]] uint32_t first_committed(const List& pages, const List& excl) {
  for (unsigned i = 0; i < pages.n; ++i) {
    uint32_t cur = pages.r[i].lo;
    for (unsigned j = 0; j < excl.n; ++j)
      if (excl.r[j].lo <= cur && cur < excl.r[j].hi) cur = excl.r[j].hi;
    if (cur < pages.r[i].hi) return cur;
  }
  return kNone;
}
}  // namespace

bool open(const Layout& L) {
  // Window offsets of the commit ranges, page-rounded, sorted and merged.
  List pages;
  for (unsigned i = 0; i < L.commit_count; ++i) {
    const Range& g = L.commit[i];
    if (g.hi <= g.lo) continue;
    if (!pages.add(uint32_t(offset(g.lo)) & ~(kPage - 1u), (uint32_t(offset(g.hi - 1u)) + kPage) & ~(kPage - 1u)))
      return false;
  }
  pages.merge();
  // Aliased interior: 64 KiB-aligned (the host maps views there).
  uint32_t alo = 0, ahi = 0;
  const uint32_t period = L.alias_period;
  if (period && L.alias.hi > L.alias.lo) {
    alo = (uint32_t(offset(L.alias.lo)) + 0xFFFFu) & ~0xFFFFu;
    ahi = uint32_t(offset(L.alias.hi - 1u) + 1u) & ~0xFFFFu;
    if (ahi < alo + 2u * period) alo = ahi = 0;
  }
  Group groups[kMaxGroups];
  unsigned ng = 0;
  for (unsigned i = 0; i < L.large_count && ng < 4u; ++i) {
    const Range& g = L.large[i];
    if (g.hi <= g.lo) continue;
    const uint32_t c0 = uint32_t(offset(g.lo)) >> 22, c1 = uint32_t(offset(g.hi - 1u)) >> 22;
    groups[ng++] = Group{c0, c1 - c0 + 1u, nullptr, 0, false, "not tried"};
  }
  uint32_t large_bytes = 0, ring_bytes = 0, reserved = 0;
  bool ring_on = false, guard = false;
  const char* ring_why = alo < ahi ? "not tried" : "off";
  List excl;
#ifdef CC_XBOX_DRIVER
  // Reserve the whole 1 GiB the offset mask reaches (0x40000000..0x7FFFFFFF)
  // or as much of it as the kernel lets a title reserve: its highest
  // reservable address is just below 0x7FFE0000, and nothing is mapped above
  // that in user space, so a stray there faults as well. Last resort (if
  // something already sat in the upper window): the span the layout uses,
  // with a warning; the mask still keeps strays below the kernel.
  {
    static const uint32_t sizes[] = {kWindowBytes, kWindowBytes - 0x10000u, kWindowBytes - 0x20000u, kSpan};
    NTSTATUS st = 0;
    for (const uint32_t s : sizes) {
      PVOID base = reinterpret_cast<PVOID>(kBase);
      SIZE_T size = s;
      st = NtAllocateVirtualMemory(&base, 0, &size, MEM_RESERVE, PAGE_READWRITE);
      if (NT_SUCCESS(st) && base == reinterpret_cast<PVOID>(kBase)) { reserved = s; break; }
    }
    if (!reserved) {
      DbgPrint("MEM flat window: reserve %08x+%08x failed status=%08x\n", unsigned(kBase), unsigned(kSpan), unsigned(st));
      return false;
    }
    if (reserved == kSpan)
      DbgPrint("MEM flat window: WARNING only %08x bytes reserved, a stray may hit title memory\n", unsigned(kSpan));
    PVOID gb = reinterpret_cast<PVOID>(kBase - kGuardBelow);
    SIZE_T gs = kGuardBelow;
    guard = NT_SUCCESS(NtAllocateVirtualMemory(&gb, 0, &gs, MEM_RESERVE, PAGE_READWRITE)) &&
            gb == reinterpret_cast<PVOID>(kBase - kGuardBelow);
  }
  // 4 MiB chunks may end past a short reservation (the image's): reserve up
  // to the last.
  uint32_t tail = reserved;
  for (unsigned i = 0; i < ng; ++i)
    if ((groups[i].c0 + groups[i].n) * kChunk > tail) tail = (groups[i].c0 + groups[i].n) * kChunk;
  bool tail_ok = tail == reserved;
  if (!tail_ok) {
    PVOID tb = reinterpret_cast<PVOID>(kBase + reserved);
    SIZE_T ts = tail - reserved;
    tail_ok = NT_SUCCESS(NtAllocateVirtualMemory(&tb, 0, &ts, MEM_RESERVE, PAGE_READWRITE)) &&
              tb == reinterpret_cast<PVOID>(kBase + reserved);
  }
  // Contiguous memory first, before the 4 KiB commits scatter free memory:
  // one block per group (compact), else one per chunk.
  for (unsigned i = 0; i < ng; ++i) {
    Group& g = groups[i];
    if ((g.c0 + g.n) * kChunk > reserved && !tail_ok) { g.why = "past the window"; continue; }
    g.block = MmAllocateContiguousMemoryEx(size_t(g.n) * kChunk, 0, kRetailTop, kChunk, PAGE_READWRITE);
    if (!g.block && g.n > 1u && ng + g.n - 1u <= kMaxGroups) {
      for (uint32_t k = 1; k < g.n; ++k) groups[ng++] = Group{g.c0 + k, 1u, nullptr, 0, false, "not tried"};
      g.n = 1u;
      g.block = MmAllocateContiguousMemoryEx(kChunk, 0, kRetailTop, kChunk, PAGE_READWRITE);
    }
    if (!g.block) { g.why = "no contiguous memory"; continue; }
    g.phys = uint32_t(MmGetPhysicalAddress(g.block));
    if (g.phys & (kChunk - 1u)) {
      MmFreeContiguousMemory(g.block);
      g.block = nullptr;
      g.why = "unaligned block";
      continue;
    }
    excl.add(g.c0 * kChunk, (g.c0 + g.n) * kChunk);
  }
  void* ring_block = nullptr;
  uint32_t ring_phys = 0;
  if (alo < ahi) {
    ring_block = MmAllocateContiguousMemoryEx(period, 0, kRetailTop, 0, PAGE_READWRITE);
    if (ring_block) {
      ring_phys = uint32_t(MmGetPhysicalAddress(ring_block));
      excl.add(alo, ahi);
    } else {
      ring_why = "no contiguous memory";
    }
  }
  excl.merge();
  if (!commit_pages(pages, 0, kNone, excl)) return false;
  // The kernel's entry for a committed page: the bits the new entries copy.
  const char* pt_why = "no committed page";
  const uint32_t t = first_committed(pages, excl);
  const uint32_t tmpl = t == kNone ? 0u : pte_template(kBase + t, &pt_why);
  const List none{};
  for (unsigned i = 0; i < ng; ++i) {
    Group& g = groups[i];
    if (!g.block) continue;
    if (!tmpl) g.why = pt_why;
    if (tmpl && map_large(g, tmpl)) {
      g.on = true;
      large_bytes += g.n * kChunk;
      continue;
    }
    MmFreeContiguousMemory(g.block);
    g.block = nullptr;
    if (!commit_pages(pages, g.c0 * kChunk, (g.c0 + g.n) * kChunk, none)) return false;
  }
  if (ring_block) {
    if (!tmpl) ring_why = pt_why;
    if (tmpl && alias_pages(alo, ahi, period, ring_block, ring_phys, tmpl, &ring_why)) {
      ring_on = true;
      ring_bytes = period;
    } else {
      MmFreeContiguousMemory(ring_block);
      if (!commit_pages(pages, alo, ahi, none)) return false;
    }
  }
#else
  if (alo < ahi) {
    ring_on = reserve_aliased(alo, ahi, period);
    if (ring_on) {
      ring_bytes = period;
      excl.add(alo, ahi);
    } else {
      ring_why = "views not placed";
    }
  }
  if (!ring_on) {
    g_base = static_cast<uint8_t*>(VirtualAlloc(nullptr, kWindowBytes, 0x2000u /*MEM_RESERVE*/, 0x01u /*PAGE_NOACCESS*/));
    if (!g_base) return false;
  }
  reserved = kWindowBytes;
  guard = VirtualAlloc(g_base - kGuardBelow, kGuardBelow, 0x2000u, 0x01u) == g_base - kGuardBelow;
  AddVectoredExceptionHandler(1, fault_report);
  // 4 MiB chunks: committed whole, the layout the Xbox maps with large pages.
  for (unsigned i = 0; i < ng; ++i) {
    Group& g = groups[i];
    const uint32_t lo = g.c0 * kChunk, hi = (g.c0 + g.n) * kChunk;
    if (!VirtualAlloc(g_base + lo, hi - lo, 0x1000u, 0x04u)) {
      g.why = "commit failed";
      continue;
    }
    g.on = true;
    large_bytes += hi - lo;
    excl.add(lo, hi);
  }
  excl.merge();
  if (!commit_pages(pages, 0, kNone, excl)) return false;
#endif
  g_ring_shared = ring_on;
  const unsigned total_k = unsigned((g_committed + large_bytes + ring_bytes) >> 10);
#ifdef CC_XBOX_DRIVER
#define CC_WIN_LOG DbgPrint
#else
#define CC_WIN_LOG cc_log
#endif
  for (unsigned i = 0; i < ng; ++i) {
    const Group& g = groups[i];
    CC_WIN_LOG("MEM large pages window %08x+%08x: %s phys=%08x\n", unsigned(g.c0 * kChunk), unsigned(g.n * kChunk),
               g.on ? "on" : g.why, unsigned(g.phys));
  }
  if (alo < ahi) {
    CC_WIN_LOG("MEM ring alias window %08x..%08x on one %uK block: %s\n", unsigned(alo), unsigned(ahi),
               unsigned(period >> 10), ring_on ? "on" : ring_why);
  }
  // (The kernel's DbgPrint has no 64-bit conversions: %llx shifts the
  // arguments after it, and the next %s then reads a number as a string,
  // which faulted at boot. The base goes out as two 32-bit halves.)
  CC_WIN_LOG("MEM flat window base=%08x%08x span=%08x reserved=%08x guard=%s committed=%uK (4K pages %uK, 4M pages %uK, ring block %uK) ranges=%u\n",
             unsigned(uint64_t(CC_WINDOW_BASE) >> 32), unsigned(CC_WINDOW_BASE), unsigned(kSpan), unsigned(reserved), guard ? "on" : "off", total_k,
             unsigned(g_committed >> 10),
             unsigned(large_bytes >> 10), unsigned(ring_bytes >> 10), pages.n);
#undef CC_WIN_LOG
#ifdef CC_XBOX_DRIVER
  cc_xbox_mem_line("startup");
#endif
  return true;
}
bool ring_shared() { return g_ring_shared; }
}  // namespace cc_win
#endif
