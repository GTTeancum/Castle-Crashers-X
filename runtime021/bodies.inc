#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savegprlr_29.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restgprlr_29.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_8208C5D8.inc"
#include "generated/sub_8209CC98.inc"

// ReXGlue's generated PPC trap intrinsic is a non-returning failure path. The
// bounded host runtime reports it as context failure; it never converts a trap
// into success. The single exception is trap code 20, the Xbox kernel debug-
// output service reached through exact sub_820B7BC0 (r3=string, r4=length):
// with no debugger attached the retail kernel resumes the title, so the
// bounded runtime logs the message and continues without touching game state.
static void ppc_trap([[maybe_unused]] Context& ctx, Machine& base, uint32_t code) {
  if (code == 20u) {
    const uint32_t len = ctx.r4.u32 <= 512u ? ctx.r4.u32 : 512u;
    char msg[513]{};
    uint32_t used = 0;
    for (uint32_t i = 0; i < len; ++i) {
      const char chv = char(base.load(ctx.r3.u32 + i, 1));
      if (!chv) break;
      msg[used++] = chv;
    }
    cc_elog("GUEST DBGPRINT: %s\n", msg);
    return;
  }
  base.fail(Error::context, code);
}

#include "generated/sub_82097720.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savegprlr_22.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restgprlr_22.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif

#define HARD_BOUNDARY(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { \
    base.fail(Error::unsupported, addr); \
  }
HARD_BOUNDARY(sub_820A71E8, 0x820A71E8u)
HARD_BOUNDARY(sub_82098100, 0x82098100u)
HARD_BOUNDARY(sub_82099BE8, 0x82099BE8u)
HARD_BOUNDARY(sub_82051868, 0x82051868u)
HARD_BOUNDARY(sub_820518E0, 0x820518E0u)
HARD_BOUNDARY(sub_82127468, 0x82127468u)
HARD_BOUNDARY(sub_82078668, 0x82078668u)
HARD_BOUNDARY(sub_820516F8, 0x820516F8u)
HARD_BOUNDARY(sub_82053648, 0x82053648u)
#undef HARD_BOUNDARY

#include "generated/sub_820B5EB8.inc"
#ifndef CC_XBOX_DRIVER
// Host diagnostic: live game-heap blocks (exact sub_8209BDD8 alloc(heap,
// size) / sub_8209BF18 free(heap, ptr)) with their caller, for
// CC_MEM_REPORT.
static std::map<uint32_t, std::pair<uint32_t, uint32_t>> g_heap_live;  // ptr -> (size, lr)
#endif
#if !defined(CC_XBOX_DRIVER) || defined(CC_FAST)
#define sub_8209BDD8 sub_8209BDD8_exact
#define sub_8209BF18 sub_8209BF18_exact
#endif
#include "generated/sub_8209BDD8.inc"
#include "generated/sub_8209BF18.inc"
#if !defined(CC_XBOX_DRIVER) || defined(CC_FAST)
#undef sub_8209BDD8
#undef sub_8209BF18
#endif
#ifdef CC_FAST
// Game heap index (sub_8209BDD8 alloc(heap, size) / sub_8209BF18
// free(heap, ptr)). A heap keeps alignment A at +32, its range [+8, +12),
// the current tag at +24 and per-tag count/bytes at +1060/+1064 + 12*tag.
// Blocks have a header of H = (A + 15) & ~(A - 1) bytes: physical previous
// +0 and next +4, payload size +8 (signed), and at +12 the tag 1..53 when
// in use or, when free, the link of one address-ordered free list (head at
// heap +16, 0 ends it). Alloc takes the first free block in that order
// whose size is at least the rounded request, splitting off the rest when
// it is at least H; free merges with free physical neighbours or links the
// block in at its place in the order. Both find their block by walking the
// list from the head: 6-15 nodes a call in 4P combat, each a cache miss.
//
// A host mirror of the list - address and size of every free block, in
// address order, in chunks of up to 64 entries with each chunk's largest
// size - answers "first fit" and "free block before b" without touching
// guest memory; all guest reads and writes of the result are the
// original's, in its order of effect. A heap's mirror is built from the
// guest list on first use and after heap init (sub_8209BC98). Before each
// call the list head, and the chosen block's size and link, are checked
// against the mirror; a disagreement rebuilds it from the list (before any
// write of that call). The original's red-zone saves of r30/r31 in alloc
// are written as it writes them (dead stack can be copied into the heap by
// later code). Switches: CC_HEAP_EXACT=1 (host) / CC_HEAP_EXACT_BUILD
// (Xbox) run the original walks; CC_ORACLE=1 or CC_HEAP_ORACLE=1 compare
// every answer with the walk and the whole mirror with the list.
struct CcHeapEnt { uint32_t addr; int32_t size; };
struct CcHeapChunk { uint32_t n; int32_t max; CcHeapEnt e[64]; };
struct CcHeapIdx {
  uint32_t heap = 0;
  bool built = false;
  std::vector<CcHeapChunk*> ch;  // address order, none empty
  std::vector<CcHeapChunk*> spare;
};
struct CcHeapPos { uint32_t c, i; };
static CcHeapIdx g_heap_idx[4];
#ifndef CC_XBOX_DRIVER
static struct { uint64_t allocs, frees, builds, fallbacks; } g_heap_st;
#endif
static void cc_heap_chunk_max(CcHeapChunk* c) {
  int32_t m = INT32_MIN;
  for (uint32_t i = 0; i < c->n; ++i) m = c->e[i].size > m ? c->e[i].size : m;
  c->max = m;
}
static CcHeapChunk* cc_heap_chunk_new(CcHeapIdx& x) {
  if (!x.spare.empty()) { CcHeapChunk* c = x.spare.back(); x.spare.pop_back(); c->n = 0; c->max = INT32_MIN; return c; }
  CcHeapChunk* c = new CcHeapChunk;
  c->n = 0; c->max = INT32_MIN;
  return c;
}
static void cc_heap_clear(CcHeapIdx& x) {
  for (CcHeapChunk* c : x.ch) x.spare.push_back(c);
  x.ch.clear();
  x.built = false;
}
// Mirror of heap h's free list read from guest memory; false (and no
// mirror) when the list is longer than any real heap's or loops.
static bool cc_heap_build(Machine& base, CcHeapIdx& x, uint32_t h) {
  cc_heap_clear(x);
  x.heap = h;
#ifndef CC_XBOX_DRIVER
  ++g_heap_st.builds;
#endif
  uint32_t last = 0u, count = 0u;
  for (uint32_t b = REX_LOAD_U32(h + 16u); b != 0u; b = REX_LOAD_U32(b + 12u)) {
    if (++count > 1000000u || (count > 1u && b <= last)) { cc_heap_clear(x); return false; }
    if (x.ch.empty() || x.ch.back()->n == 48u) x.ch.push_back(cc_heap_chunk_new(x));
    CcHeapChunk* c = x.ch.back();
    c->e[c->n++] = {b, int32_t(REX_LOAD_U32(b + 8u))};
    if (c->e[c->n - 1u].size > c->max) c->max = c->e[c->n - 1u].size;
    last = b;
  }
  x.built = true;
  return true;
}
static inline uint32_t cc_heap_first_addr(const CcHeapIdx& x) { return x.ch.empty() ? 0u : x.ch[0]->e[0].addr; }
static inline const CcHeapEnt& cc_heap_at(const CcHeapIdx& x, CcHeapPos p) { return x.ch[p.c]->e[p.i]; }
// Address of the entry after / before p, 0 at the ends.
static inline uint32_t cc_heap_next_addr(const CcHeapIdx& x, CcHeapPos p) {
  if (p.i + 1u < x.ch[p.c]->n) return x.ch[p.c]->e[p.i + 1u].addr;
  return p.c + 1u < x.ch.size() ? x.ch[p.c + 1u]->e[0].addr : 0u;
}
static inline uint32_t cc_heap_prev_addr(const CcHeapIdx& x, CcHeapPos p) {
  if (p.i > 0u) return x.ch[p.c]->e[p.i - 1u].addr;
  return p.c > 0u ? x.ch[p.c - 1u]->e[x.ch[p.c - 1u]->n - 1u].addr : 0u;
}
// First entry in address order with size >= need (signed), as the walk.
static bool cc_heap_first_fit(const CcHeapIdx& x, int32_t need, CcHeapPos& out) {
  for (uint32_t c = 0; c < x.ch.size(); ++c) {
    const CcHeapChunk* k = x.ch[c];
    if (k->max < need) continue;
    for (uint32_t i = 0; i < k->n; ++i)
      if (k->e[i].size >= need) { out = {c, i}; return true; }
  }
  return false;
}
// Last entry whose address is below a; false when there is none.
static bool cc_heap_before(const CcHeapIdx& x, uint32_t a, CcHeapPos& out) {
  uint32_t lo = 0, hi = uint32_t(x.ch.size());  // chunks with e[0].addr < a: [0, lo)
  while (lo < hi) {
    const uint32_t mid = (lo + hi) / 2u;
    if (x.ch[mid]->e[0].addr < a) lo = mid + 1u; else hi = mid;
  }
  if (lo == 0u) return false;
  const CcHeapChunk* k = x.ch[lo - 1u];
  uint32_t l = 1u, r = k->n;  // e[0] < a; entries below a: [0, l)
  while (l < r) {
    const uint32_t mid = (l + r) / 2u;
    if (k->e[mid].addr < a) l = mid + 1u; else r = mid;
  }
  out = {lo - 1u, l - 1u};
  return true;
}
// Entry with address a exactly.
static bool cc_heap_find(const CcHeapIdx& x, uint32_t a, CcHeapPos& out) {
  return cc_heap_before(x, a + 1u, out) && cc_heap_at(x, out).addr == a;
}
static void cc_heap_remove(CcHeapIdx& x, CcHeapPos p) {
  CcHeapChunk* k = x.ch[p.c];
  const int32_t old = k->e[p.i].size;
  __builtin_memmove(&k->e[p.i], &k->e[p.i + 1u], (k->n - p.i - 1u) * sizeof(CcHeapEnt));
  if (--k->n == 0u) {
    x.spare.push_back(k);
    x.ch.erase(x.ch.begin() + p.c);
  } else if (old == k->max) {
    cc_heap_chunk_max(k);
  }
}
static void cc_heap_set(CcHeapIdx& x, CcHeapPos p, uint32_t addr, int32_t size) {
  CcHeapChunk* k = x.ch[p.c];
  const int32_t old = k->e[p.i].size;
  k->e[p.i] = {addr, size};
  if (size > k->max) k->max = size;
  else if (old == k->max && size < old) cc_heap_chunk_max(k);
}
static void cc_heap_insert(CcHeapIdx& x, uint32_t addr, int32_t size) {
  CcHeapPos p;
  uint32_t c, i;
  if (cc_heap_before(x, addr, p)) { c = p.c; i = p.i + 1u; }
  else {
    if (x.ch.empty()) x.ch.push_back(cc_heap_chunk_new(x));
    c = 0u; i = 0u;
  }
  CcHeapChunk* k = x.ch[c];
  if (k->n == 64u) {  // split: the upper half moves to a new chunk
    CcHeapChunk* u = cc_heap_chunk_new(x);
    u->n = 32u;
    __builtin_memcpy(u->e, &k->e[32], 32u * sizeof(CcHeapEnt));
    k->n = 32u;
    cc_heap_chunk_max(k);
    cc_heap_chunk_max(u);
    x.ch.insert(x.ch.begin() + c + 1u, u);
    if (i > 32u) { k = u; i -= 32u; }
  }
  __builtin_memmove(&k->e[i + 1u], &k->e[i], (k->n - i) * sizeof(CcHeapEnt));
  k->e[i] = {addr, size};
  ++k->n;
  if (size > k->max) k->max = size;
}
static CcHeapIdx* cc_heap_idx(Machine& base, uint32_t h) {
  for (CcHeapIdx& x : g_heap_idx)
    if (x.heap == h) {
      if (!x.built && !cc_heap_build(base, x, h)) return nullptr;
      return &x;
    }
  for (CcHeapIdx& x : g_heap_idx)
    if (x.heap == 0u) return cc_heap_build(base, x, h) ? &x : nullptr;
  return nullptr;
}
static void cc_heap_forget(uint32_t h) {
  for (CcHeapIdx& x : g_heap_idx)
    if (x.heap == h) cc_heap_clear(x);
}
#ifndef CC_XBOX_DRIVER
// Host oracle: the mirror against the guest list, entry by entry.
static void cc_heap_check(Machine& base, const CcHeapIdx& x, uint32_t h, const char* when) {
  uint32_t b = REX_LOAD_U32(h + 16u);
  uint32_t k = 0;
  for (uint32_t c = 0; c < x.ch.size(); ++c)
    for (uint32_t i = 0; i < x.ch[c]->n; ++i, ++k) {
      const CcHeapEnt& e = x.ch[c]->e[i];
      if (b != e.addr || REX_LOAD_U32(b + 8u) != uint32_t(e.size)) {
        cc_oracle_mismatch(when, int(k), b, e.addr);
        return;
      }
      b = REX_LOAD_U32(b + 12u);
    }
  if (b != 0u) cc_oracle_mismatch(when, int(k), b, 0u);
}
#endif
// Alloc as sub_8209BDD8; false when the mirror cannot answer (the caller
// then runs the original).
static bool cc_heap_alloc(Context& ctx, Machine& base) {
  const uint32_t h = ctx.r3.u32;
  CcHeapIdx* x = cc_heap_idx(base, h);
  if (!x) return false;
  uint32_t size = ctx.r4.u32;
  if (size == 0u) size = 1u;
  const uint32_t A = REX_LOAD_U32(h + 32u);
  const uint32_t need = (size + A - 1u) & ~(A - 1u);
  const uint32_t H = (A + 15u) & ~(A - 1u);
  CcHeapPos p{};
  bool found = false;
  uint32_t r10 = 0u, link = 0u;
  int32_t sz = 0;
  for (int attempt = 0;; ++attempt) {
    found = cc_heap_first_fit(*x, int32_t(need), p);
    bool agree = REX_LOAD_U32(h + 16u) == cc_heap_first_addr(*x);
    if (agree && found) {
      r10 = cc_heap_at(*x, p).addr;
      sz = int32_t(REX_LOAD_U32(r10 + 8u));
      link = REX_LOAD_U32(r10 + 12u);
      agree = sz == cc_heap_at(*x, p).size && link == cc_heap_next_addr(*x, p);
    }
    if (agree) break;
    if (attempt == 1 || !cc_heap_build(base, *x, h)) { cc_heap_clear(*x); return false; }
  }
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr || std::getenv("CC_HEAP_ORACLE") != nullptr;
  if (oracle) {
    cc_heap_check(base, *x, h, "sub_8209BDD8 mirror");
    uint32_t w = REX_LOAD_U32(h + 16u);
    while (w != 0u && int32_t(need) > int32_t(REX_LOAD_U32(w + 8u))) w = REX_LOAD_U32(w + 12u);
    if (w != (found ? r10 : 0u)) cc_oracle_mismatch("sub_8209BDD8 first fit", 0, w, found ? r10 : 0u);
  }
  ++g_heap_st.allocs;
#endif
  const int32_t rem = int32_t(uint32_t(sz) - H - need);
  if (found && rem == -1) return false;  // the original would take the block twice; leave it to it
  REX_STORE_U64(ctx.r1.u32 - 16u, ctx.r30.u64);  // the original's red-zone saves
  REX_STORE_U64(ctx.r1.u32 - 8u, ctx.r31.u64);
  if (!found) { ctx.r3.u64 = 0u; return true; }
  const uint32_t prev = cc_heap_prev_addr(*x, p);
  uint32_t r6;
  if (rem < int32_t(H)) {
    r6 = link;
    cc_heap_remove(*x, p);
  } else {
    r6 = r10 + H + need;
    REX_STORE_U32(r6 + 0u, r10);
    REX_STORE_U32(r6 + 8u, uint32_t(rem));
    const uint32_t r9 = REX_LOAD_U32(r10 + 4u);
    REX_STORE_U32(r6 + 4u, r9);
    if (r9 != 0u) REX_STORE_U32(r9 + 0u, r6);
    REX_STORE_U32(r6 + 12u, REX_LOAD_U32(r10 + 12u));
    REX_STORE_U32(r10 + 4u, r6);
    REX_STORE_U32(r10 + 8u, need);
    cc_heap_set(*x, p, r6, rem);
  }
  const uint32_t cnt = h + REX_LOAD_U32(h + 24u) * 12u + 1060u;
  REX_STORE_U32(cnt, REX_LOAD_U32(cnt) + 1u);
  const uint32_t bytes = REX_LOAD_U32(r10 + 8u);
  const uint32_t tot = h + REX_LOAD_U32(h + 24u) * 12u + 1064u;
  REX_STORE_U32(tot, bytes + REX_LOAD_U32(tot));
  REX_STORE_U32(r10 + 12u, REX_LOAD_U32(h + 24u));
  if (prev != 0u) REX_STORE_U32(prev + 12u, r6);
  else REX_STORE_U32(h + 16u, r6);
  ctx.r3.u64 = uint64_t(H) + r10;
  return true;
}
// Free as sub_8209BF18; false when the mirror cannot answer.
static bool cc_heap_free(Context& ctx, Machine& base) {
  const uint32_t h = ctx.r3.u32, ptr = ctx.r4.u32;
  if (ptr <= REX_LOAD_U32(h + 8u) || ptr >= REX_LOAD_U32(h + 12u)) return true;
  const uint32_t H = (REX_LOAD_U32(h + 32u) + 15u) & ~(REX_LOAD_U32(h + 32u) - 1u);
  const uint32_t b = ptr - H;
  const uint32_t tag = REX_LOAD_U32(b + 12u), prev = REX_LOAD_U32(b + 0u), next = REX_LOAD_U32(b + 4u);
  if (tag < 1u || tag > 53u) return true;
  CcHeapIdx* x = cc_heap_idx(base, h);
  if (!x) return false;
  auto is_free = [&](uint32_t blk) { const uint32_t t = REX_LOAD_U32(blk + 12u); return t == 0u || t > 53u; };
  const bool merge_prev = prev != 0u && is_free(prev);
  const bool merge_next = next != 0u && is_free(next);
  // Mirror positions, checked against the guest list before any write.
  CcHeapPos pp{}, pn{};
  uint32_t head = 0u, before = 0u, after = 0u;
  for (int attempt = 0;; ++attempt) {
    head = REX_LOAD_U32(h + 16u);
    bool agree = head == cc_heap_first_addr(*x);
    if (agree && merge_prev) agree = cc_heap_find(*x, prev, pp);
    if (agree && !merge_prev && head != 0u && b > head) {
      agree = cc_heap_before(*x, b, pp);
      if (agree) {
        before = cc_heap_at(*x, pp).addr;
        after = cc_heap_next_addr(*x, pp);
        agree = REX_LOAD_U32(before + 12u) == after;
      }
    }
    if (agree && merge_next) agree = cc_heap_find(*x, next, pn);
    if (agree) break;
    if (attempt == 1 || !cc_heap_build(base, *x, h)) { cc_heap_clear(*x); return false; }
  }
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr || std::getenv("CC_HEAP_ORACLE") != nullptr;
  if (oracle) {
    cc_heap_check(base, *x, h, "sub_8209BF18 mirror");
    if (!merge_prev && head != 0u && b > head) {
      uint32_t r9 = head, r10 = head;
      while (r10 != 0u && r10 < b) { r9 = r10; r10 = REX_LOAD_U32(r10 + 12u); }
      if (r9 != before || r10 != after) cc_oracle_mismatch("sub_8209BF18 place", 0, r9, before);
    }
  }
  ++g_heap_st.frees;
#endif
  const uint32_t cnt = h + tag * 12u + 1060u;
  REX_STORE_U32(cnt, REX_LOAD_U32(cnt) - 1u);
  REX_STORE_U32(cnt + 4u, REX_LOAD_U32(cnt + 4u) - REX_LOAD_U32(b + 8u));
  uint32_t r11;
  if (merge_prev) {
    REX_STORE_U32(prev + 8u, H + REX_LOAD_U32(prev + 8u) + REX_LOAD_U32(b + 8u));
    REX_STORE_U32(prev + 4u, REX_LOAD_U32(b + 4u));
    if (next != 0u) REX_STORE_U32(next + 0u, prev);
    r11 = prev;
    cc_heap_set(*x, pp, prev, int32_t(REX_LOAD_U32(prev + 8u)));
  } else {
    if (head == 0u || b <= head) {
      REX_STORE_U32(b + 12u, head);
      REX_STORE_U32(h + 16u, b);
    } else {
      REX_STORE_U32(before + 12u, b);
      REX_STORE_U32(b + 12u, after);
    }
    r11 = b;
    cc_heap_insert(*x, b, int32_t(REX_LOAD_U32(b + 8u)));
  }
  if (merge_next) {
    REX_STORE_U32(r11 + 8u, H + REX_LOAD_U32(next + 8u) + REX_LOAD_U32(r11 + 8u));
    const uint32_t nn = REX_LOAD_U32(next + 4u);
    if (nn != 0u) REX_STORE_U32(nn + 0u, r11);
    REX_STORE_U32(r11 + 4u, REX_LOAD_U32(next + 4u));
    REX_STORE_U32(r11 + 12u, REX_LOAD_U32(next + 12u));
    CcHeapPos q;
    cc_heap_find(*x, next, q);
    cc_heap_remove(*x, q);
    cc_heap_find(*x, r11, q);
    cc_heap_set(*x, q, r11, int32_t(REX_LOAD_U32(r11 + 8u)));
  }
  return true;
}
#endif
#if !defined(CC_XBOX_DRIVER) || defined(CC_FAST)
#ifdef CC_FAST
static inline bool cc_heap_exact() {
#ifndef CC_XBOX_DRIVER
  static const bool exact = std::getenv("CC_HEAP_EXACT") != nullptr;
  return exact;
#elif defined(CC_HEAP_EXACT_BUILD)
  return true;
#else
  return false;
#endif
}
// The original or the mirror; after the original runs in place of the
// mirror, the mirror is rebuilt on the next call.
static inline void cc_heap_alloc_any(Context& ctx, Machine& base) {
  const uint32_t h = ctx.r3.u32;
#ifndef CC_XBOX_DRIVER
  if (std::getenv("CC_HEAP_BIG") && ctx.r4.u32 >= 0x40000u)
    std::fprintf(stderr, "HEAPBIG size=%u lr=%08x\n", ctx.r4.u32, uint32_t(ctx.lr));
#endif
  if (cc_heap_exact() || !cc_heap_alloc(ctx, base)) {
#ifndef CC_XBOX_DRIVER
    if (!cc_heap_exact()) ++g_heap_st.fallbacks;
#endif
    sub_8209BDD8_exact(ctx, base);
    cc_heap_forget(h);
  }
}
static inline void cc_heap_free_any(Context& ctx, Machine& base) {
  const uint32_t h = ctx.r3.u32;
  if (cc_heap_exact() || !cc_heap_free(ctx, base)) {
#ifndef CC_XBOX_DRIVER
    if (!cc_heap_exact()) ++g_heap_st.fallbacks;
#endif
    sub_8209BF18_exact(ctx, base);
    cc_heap_forget(h);
  }
}
#endif
#ifndef CC_XBOX_DRIVER
// Host census (CC_HEAP_WALK=1): free-list nodes before the chosen block
// (alloc) / the insertion point (free), averaged per 2000 calls.
static uint64_t g_hw_alloc_calls, g_hw_alloc_nodes, g_hw_free_calls, g_hw_free_nodes;
static void cc_heap_walk_census(Machine& base, uint32_t heap, uint32_t stop_addr, bool is_free, uint32_t need) {
  static const bool on = std::getenv("CC_HEAP_WALK") != nullptr;
  if (!on) return;
  uint64_t n = 0;
  uint64_t v = 0; base.memory.load_be(heap + 16u, 4, v);
  for (uint32_t b = uint32_t(v); b && n < 100000; ++n) {
    if (is_free) { if (b >= stop_addr) break; }
    else { uint64_t sz = 0; base.memory.load_be(b + 8u, 4, sz); if (int32_t(uint32_t(sz)) >= int32_t(need)) break; }
    uint64_t nx = 0; base.memory.load_be(b + 12u, 4, nx); b = uint32_t(nx);
  }
  if (is_free) { ++g_hw_free_calls; g_hw_free_nodes += n; } else { ++g_hw_alloc_calls; g_hw_alloc_nodes += n; }
  if ((g_hw_alloc_calls + g_hw_free_calls) % 200000u == 0u)
    std::fprintf(stderr, "HEAPWALK calls=%llu alloc_avg=%.1f free_avg=%.1f\n", (unsigned long long)(g_hw_alloc_calls + g_hw_free_calls),
                 double(g_hw_alloc_nodes) / double(g_hw_alloc_calls ? g_hw_alloc_calls : 1),
                 double(g_hw_free_nodes) / double(g_hw_free_calls ? g_hw_free_calls : 1));
}
#endif
#ifdef CC_XBOX_DRIVER
// Console SLOW lines: per-frame counts of script ops, custom function calls,
// clip frame updates and game-heap allocations.
static uint32_t g_fc[4];
#endif
static void sub_8209BDD8(Context& ctx, Machine& base) {
#ifdef CC_XBOX_DRIVER
  ++g_fc[3];
#endif
#ifndef CC_XBOX_DRIVER
  const uint32_t size = ctx.r4.u32, lr = uint32_t(ctx.lr);
  cc_heap_walk_census(base, ctx.r3.u32, 0u, false, size + 16u);
#endif
#ifdef CC_FAST
  cc_heap_alloc_any(ctx, base);
#else
  sub_8209BDD8_exact(ctx, base);
#endif
#ifndef CC_XBOX_DRIVER
  if (ctx.r3.u32) g_heap_live[ctx.r3.u32] = {size, lr};
  // Host oracle aid (CC_HEAP_ZERO=1): new blocks are zeroed, so stale bytes
  // (the padding of copied script values, which the game fills from
  // uninitialised stack temporaries) cannot carry into later allocations
  // and differ between two otherwise identical runs.
  static const bool zero = std::getenv("CC_HEAP_ZERO") != nullptr;
  if (zero && ctx.r3.u32) {
    uint32_t k = 0;
    for (; k + 4u <= size; k += 4u) base.store(ctx.r3.u32 + k, 4, 0u);
    for (; k < size; ++k) base.store(ctx.r3.u32 + k, 1, 0u);
  }
#endif
}
static void sub_8209BF18(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  cc_heap_walk_census(base, ctx.r3.u32, ctx.r4.u32, true, 0u);
  // CC_HEAP_ZERO=1 also clears a block before it is freed.
  static const bool zero = std::getenv("CC_HEAP_ZERO") != nullptr;
  const auto it = g_heap_live.find(ctx.r4.u32);
  if (zero && it != g_heap_live.end()) {
    const uint32_t p = ctx.r4.u32, size = it->second.first;
    uint32_t k = 0;
    for (; k + 4u <= size; k += 4u) base.store(p + k, 4, 0u);
    for (; k < size; ++k) base.store(p + k, 1, 0u);
  }
  if (it != g_heap_live.end()) g_heap_live.erase(it);
#endif
#ifdef CC_FAST
  cc_heap_free_any(ctx, base);
#else
  sub_8209BF18_exact(ctx, base);
#endif
}
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savegprlr_26.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restgprlr_26.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_82099A80.inc"
#include "generated/sub_82099968.inc"
#include "generated/sub_820986F0.inc"
#include "generated/sub_82097AC8.inc"
#include "generated/sub_82075098.inc"
#include "generated/sub_820744C8.inc"
#include "generated/sub_82099680.inc"
#include "generated/sub_82097650.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/sub_820701D0_manager_slice.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif

// Xbox 360's performance/timebase frequency is 49.875 MHz. Keep the platform
// shim paired with a scaled monotonic timebase so generated mftb code observes
// guest-rate ticks rather than the host CPU TSC frequency.
static void __imp__KeQueryPerformanceFrequency(Context& ctx, [[maybe_unused]] Machine& base) {
  ctx.r3.u64 = Machine::timebase_hz;
}
// Hardware-register (MMIO) and timebase helpers used by the generated
// bodies, defined once for the whole file. The MMIO policy functions are
// defined further down with the fixture hardware models.
static uint32_t checkpoint020_mm_load_u32(Machine& base, uint32_t a);
static void checkpoint020_mm_store_u32(Machine& base, uint32_t a, uint32_t v);
static uint16_t cc_mm_load_u16(Machine& base, uint32_t a);
#define REX_MM_LOAD_U32(a) checkpoint020_mm_load_u32(base,uint32_t(a))
#define REX_MM_STORE_U32(a,v) checkpoint020_mm_store_u32(base,uint32_t(a),uint32_t(v))
#define REX_MM_LOAD_U16(a) cc_mm_load_u16(base,uint32_t(a))

// Shared first-fit allocator over the physical cursor arena (used by
// MmAllocatePhysicalMemoryEx/MmFreePhysicalMemory and the kernel pool).
static uint32_t cc_phys_alloc(Machine& base, uint32_t bytes, uint32_t align);
static bool cc_phys_free(Machine& base, uint32_t addr);
static void cc_phys_shrink(Machine& base, uint32_t addr, uint32_t new_size);
static uint64_t g_tex_cache_bytes = 0;
static bool cc_texzone_free(uint32_t a);
static uint32_t cc_texzone_alloc(Machine& base, uint32_t bytes, uint32_t keep);
static uint32_t g_tex_alloc_keep = 0;
static std::vector<std::pair<int64_t, uint32_t>> g_tex_swap_free_early;
static uint32_t g_tex_replays = 0, g_tex_replay_mismatches = 0, g_tex_evictions = 0;
#ifndef CC_XBOX_DRIVER
static double g_raster_seconds = 0.0;
static uint32_t g_raster_count = 0;
static double g_update_seconds, g_render_seconds;
#else
static uint32_t g_frame_update_us, g_frame_render_us;
// Console FRAME line (nxdk-checkpoint022/xbox_perf.cpp, once a second):
// frame-to-frame time and its parts outside the game's update and render,
// in microseconds: {frame, audio mix, frame end (overlay, GPU wait,
// present), frame-pacing sleep, worker jobs, update, render}; frames, and
// baked-texture reads and bytes; the pack's disk reads, seeks, bytes, total
// and longest read time in microseconds (cc_bake_disk). Summed until read by
// cc_xbox_frame_stats (bridge.cpp).
static uint64_t g_fs_us[7];
// One frame's parts for the SLOW lines (microseconds): hook entry and the
// previous hook exit, audio, update, render and frame end.
static struct { uint64_t in, out; uint32_t aud, upd, ren, end; } g_slow;
static uint32_t g_fs_frames, g_fs_bake_reads, g_fs_bake_bytes;
static uint32_t g_fs_disk_reads, g_fs_disk_seeks, g_fs_disk_bytes, g_fs_disk_us, g_fs_disk_max_us;
#endif
static uint32_t g_tex_swap_ins = 0, g_tex_swap_outs = 0;
static uint32_t g_bake_hits = 0, g_bake_misses = 0;
#ifndef CC_XBOX_DRIVER
static long g_quadlog_left = -1;  // host quad probe (CC_QUADLOG), see sub_820A9308
static bool g_quadlog_left_draw = false;  // a logged native quad is being drawn
static bool g_quadlog_from_ok();
#endif
static bool cc_audio_set_volume(uint32_t voice, float vol);
static bool cc_audio_stop(uint32_t voice);
static void cc_audio_frame();
static uint32_t cc_audio_loaded_bytes();
static uint32_t cc_audio_active_voices();
static uint32_t cc_audio_mixed_frames();
#ifndef CC_XBOX_DRIVER
static void cc_mem_report(uint32_t frame);
static cc::xbox::AddressSpace* g_mem_report_space = nullptr;
static std::set<uint32_t> g_committed_pages;
#endif
#define REX_QUERY_TIMEBASE() base.query_timebase()
#include "generated/sub_820B6D10.inc"
#include "generated/sub_820B6D48.inc"

#ifdef CC_FAST
// Display-list child-by-name cache (sub_82085078). The answer for (list,
// id) depends only on the list's links (the head word and each node's
// +88), each node's class (vtable word +0) and, for the three named
// classes, the name: clips 0x8203E878 / 0x8203F510 keep it as u16 +100,
// text fields 0x8203F680 as u16 +150 (slots 52/72 of those vtables read
// exactly that; slots 76/80 write it). Results, "not found" included, sit
// in a direct-mapped table stamped with the version clock at fill time.
// An entry is valid while neither its list's version nor its id's version
// has moved past the stamp:
//  - list versions are bumped by every list primitive (insert, remove,
//    remove by depth, clear, sort) and by the clip constructor and reset
//    for the object's own list at +104 (a recycled address starts fresh);
//  - id versions are bumped for the old and the new name by every name
//    setter; the _name property setter, which stores the name itself,
//    flushes the table.
// Version slots are indexed by hash; a shared slot only costs misses.
// While a list primitive runs (it calls guest code with the list
// half-changed) the table is neither read nor filled. A walk that meets a
// node of any other class whose slot 52/72 answer is not a constant calls
// the methods as the original does and is not cached.
struct CcDlEnt { uint32_t list, id, stamp, result; };
static CcDlEnt g_dl_cache[2048];
static uint32_t g_dl_lver[2048], g_dl_iver[2048];
static uint32_t g_dl_tick = 1u, g_dl_busy = 0u;
#ifndef CC_XBOX_DRIVER
// Host census (CC_DLCACHE_STATS=1), printed every 300 frames.
static struct { uint64_t calls, hits, fills, uncached, busy, nodes, list_bumps, name_bumps, flushes; } g_dl_st;
#define CC_DL_STAT(f) (++g_dl_st.f)
#else
#define CC_DL_STAT(f) ((void)0)
#endif
static inline uint32_t& cc_dl_lv(uint32_t list) { return g_dl_lver[((list >> 3) ^ (list >> 14)) & 2047u]; }
static inline uint32_t& cc_dl_iv(uint32_t id) { return g_dl_iver[id & 2047u]; }
static __attribute__((noinline)) void cc_dl_flush() {
  CC_DL_STAT(flushes);
  __builtin_memset(g_dl_cache, 0, sizeof(g_dl_cache));
}
static inline uint32_t cc_dl_new_version() {
  if (__builtin_expect(++g_dl_tick == 0u, 0)) {  // clock wrapped: start over
    cc_dl_flush();
    __builtin_memset(g_dl_lver, 0, sizeof(g_dl_lver));
    __builtin_memset(g_dl_iver, 0, sizeof(g_dl_iver));
    g_dl_tick = 1u;
  }
  return g_dl_tick;
}
static inline void cc_dl_list_changed(uint32_t list) { CC_DL_STAT(list_bumps); cc_dl_lv(list) = cc_dl_new_version(); }
static inline void cc_dl_name_changed(uint32_t id) { CC_DL_STAT(name_bumps); cc_dl_iv(id & 0xFFFFu) = cc_dl_new_version(); }
// A list primitive in progress on one list.
struct CcDlMutate {
  uint32_t list;
  explicit CcDlMutate(uint32_t l) : list(l) { ++g_dl_busy; cc_dl_list_changed(l); }
  ~CcDlMutate() { cc_dl_list_changed(list); --g_dl_busy; }
};

// Display-list refresh from a candidate table (replaces the per-frame walk
// of sub_8208AE78). The walk sorts the child list (+104, linked by +88) of
// every node it reaches whose bit 5 of byte +140 is set, clearing the bit;
// it reaches the root and, below a reached node, each child whose slot 44
// answers nonzero. Bit 5 is set only by the depth setters sub_820878E0 /
// sub_820879A0, on the node's parent (slot 156 = [node+96]); a new clip can
// also carry it in from the heap, since its constructor (sub_820869B0)
// keeps that bit of the byte. The candidates are therefore the parents the
// depth setters name and the nodes inserted with the bit set. Each refresh
// handles the candidates that still have the bit and are reached (walking
// up through [n+96] finds n in each parent's list, and every node below
// the root answers slot 44) and drops those without the bit or whose class
// never answers slot 44; any other candidate (active but not reached now)
// switches the refresh to the walk from then on. Sorting one list
// does not change any other list or bit, so the order of the sorts does
// not matter. Should a class with a slot 44 that is not a constant leaf be
// inserted, a depth setter run on a class whose slot 156 is not
// "lwz r3,96(r3)", or the table fill up, the walk is used from then on.
static uint32_t g_dl_dirty[1024];
static uint32_t g_dl_ndirty = 0u;
static bool g_dl_walk_always = false;
#ifndef CC_XBOX_DRIVER
static struct { uint64_t refreshes, checked, kept_max, sorts, sorts_changed, sort_nodes, sort_moves, sort_moves_max, sort_nodes_max, sort_merges; } g_dl_rst;
#endif
static void cc_dl_mark(uint32_t node) {
  for (uint32_t i = 0; i < g_dl_ndirty; ++i)
    if (g_dl_dirty[i] == node) return;
  if (g_dl_ndirty == 1024u) { g_dl_walk_always = true; return; }
  g_dl_dirty[g_dl_ndirty++] = node;
}
#endif

#ifdef CC_FAST
#define sub_82082390 sub_82082390_exact
#endif
#include "generated/sub_82082390.inc"
#ifdef CC_FAST
#undef sub_82082390
// ActionScript member map lookup (exact sub_82082390: map r3 = {u32 n,
// entry* e}, id r4 u16; entries are 8 bytes {u16 id, u32 value}; returns
// the value or 0). Fewer than 4 entries: linear scan; otherwise the
// original's binary search, probe for probe (unsigned index arithmetic
// kept as compiled, so even a malformed map reads the same entries).
//
// Maps of 16 to 32767 entries also keep the answer of the last lookup per
// (map, id) in a small host table: the entry index when the id was found,
// or the position it would sort into when it was not. On the 4P level-13
// run (frames 6600-9000) about 47% of lookups go to such maps, and most
// repeat a recent (map, id) with the map unchanged. A cached answer is
// used only while the map's count and entry array are the ones it was
// found with and, for a found id, the entry still holds the id between
// strictly smaller and larger neighbours, or, for an absent id, the
// neighbours around its position are strictly smaller and larger than it.
// Maps are kept sorted by sub_820936B0 (every insert changes the count),
// and on a sorted map the search can only give that same answer (the host
// census CC_ASMAP_STAT=1 also checks every such map it sees is sorted).
// CC_ORACLE=1 re-runs the search on every cached answer and reports a
// difference; CC_ASMAP_NOCACHE=1 (host) or the Xbox build define
// CC_ASMAP_NOCACHE_BUILD turns the table off.
struct CcAsMapHit { uint32_t map, n, e, ki; };  // ki: id | index << 16 | absent << 31
static CcAsMapHit g_asmap_hit[2048];
#ifndef CC_XBOX_DRIVER
static const bool g_asmap_cache = std::getenv("CC_ASMAP_NOCACHE") == nullptr;
static const bool g_asmap_oracle = std::getenv("CC_ORACLE") != nullptr;
#elif defined(CC_ASMAP_NOCACHE_BUILD)
static constexpr bool g_asmap_cache = false;
#else
static constexpr bool g_asmap_cache = true;
#endif
#ifndef CC_XBOX_DRIVER
// Host census (CC_ASMAP_STAT=1, frames CC_SAMPLE_FROM..CC_SAMPLE_TO),
// printed at exit: lookups of maps under 4 entries, of 4..15 entries (or
// past the table's range), and of table-sized maps answered by the table
// (found / absent) or by a search (found / absent); unsorted counts the
// table-sized maps seen with ids not strictly increasing.
static const bool g_asmap_stat = std::getenv("CC_ASMAP_STAT") != nullptr;
static uint64_t g_asmap_count[7];
namespace {
struct CcAsMapReport {
  ~CcAsMapReport() {
    if (g_asmap_stat)
      std::fprintf(stderr, "ASMAP small=%llu mid=%llu hit_found=%llu hit_absent=%llu search_found=%llu search_absent=%llu unsorted=%llu\n",
                   (unsigned long long)g_asmap_count[0], (unsigned long long)g_asmap_count[1], (unsigned long long)g_asmap_count[2],
                   (unsigned long long)g_asmap_count[3], (unsigned long long)g_asmap_count[4], (unsigned long long)g_asmap_count[5],
                   (unsigned long long)g_asmap_count[6]);
  }
} g_asmap_report;
}  // namespace
#define CC_ASMAP_COUNT(k) do { if (g_asmap_stat && g_sample_on.load(std::memory_order_relaxed)) ++g_asmap_count[k]; } while (0)
static __attribute__((noinline, cold)) void cc_asmap_sortcheck(Machine& base, uint32_t n, uint32_t e) {
  if (!g_sample_on.load(std::memory_order_relaxed)) return;
  for (uint32_t k = 0; k + 1u < n; ++k)
    if (REX_LOAD_U16(e + k * 8u) >= REX_LOAD_U16(e + k * 8u + 8u)) { ++g_asmap_count[6]; return; }
}
#else
#define CC_ASMAP_COUNT(k) do { } while (0)
#endif
// Binary search of a map with n >= 4 entries: index of the id, or n when
// absent (the original's probes and final checks); lo/hi: the final window
// of an absent id.
static CC_HOT_FN inline uint32_t cc_asmap_search(Machine& base, uint32_t n, uint32_t e, uint32_t key, uint32_t& lo, uint32_t& hi) {
  hi = n - 1u; lo = 0u;
  uint32_t mid = hi >> 1;
  uint32_t v = REX_LOAD_U16(e + mid * 8u);
  while (v != key) {
    if (v > key) hi = mid - 1u; else lo = mid + 1u;
    const uint32_t d = hi - lo;
    if (d < 2u) {
      if (REX_LOAD_U16(e + lo * 8u) == key) return lo;
      if (REX_LOAD_U16(e + hi * 8u) == key) return hi;
      return n;
    }
    mid = (d >> 1) + lo;
    v = REX_LOAD_U16(e + mid * 8u);
  }
  return mid;
}
static CC_HOT_FN inline uint32_t cc_asmap_search(Machine& base, uint32_t n, uint32_t e, uint32_t key) {
  uint32_t lo, hi;
  return cc_asmap_search(base, n, e, key, lo, hi);
}
static CC_HOT_FN uint32_t cc_asmap_find(Machine& base, uint32_t map, uint32_t key) {
  const uint32_t n = REX_LOAD_U32(map + 0u), e = REX_LOAD_U32(map + 4u);
  if (n < 4u) {
    CC_ASMAP_COUNT(0);
    for (uint32_t i = 0; i < n; ++i)
      if (REX_LOAD_U16(e + i * 8u) == key) return REX_LOAD_U32(e + i * 8u + 4u);
    return 0u;
  }
  if (n < 16u || n > 0x7FFFu || !g_asmap_cache) {
    CC_ASMAP_COUNT(1);
    const uint32_t i = cc_asmap_search(base, n, e, key);
    return i != n ? REX_LOAD_U32(e + i * 8u + 4u) : 0u;
  }
#ifndef CC_XBOX_DRIVER
  if (g_asmap_stat) cc_asmap_sortcheck(base, n, e);
#endif
  CcAsMapHit& h = g_asmap_hit[((map >> 3) ^ (map >> 12) ^ (key * 0x9E3779B1u >> 7)) & 2047u];
  if (h.map == map && h.n == n && h.e == e && (h.ki & 0xFFFFu) == key) {
    const uint32_t i = (h.ki >> 16) & 0x7FFFu;
    const uint32_t a = e + i * 8u;
    if (int32_t(h.ki) >= 0) {
      if (REX_LOAD_U16(a) == key && (i == 0u || REX_LOAD_U16(a - 8u) < key) && (i + 1u >= n || REX_LOAD_U16(a + 8u) > key)) {
#ifndef CC_XBOX_DRIVER
        if (g_asmap_oracle) {
          const uint32_t j = cc_asmap_search(base, n, e, key);
          if (j != i) cc_oracle_mismatch("cc_asmap_find_cache", int(key), j, i);
        }
#endif
        CC_ASMAP_COUNT(2);
        return REX_LOAD_U32(a + 4u);
      }
    } else if ((i == 0u || REX_LOAD_U16(a - 8u) < key) && (i >= n || REX_LOAD_U16(a) > key)) {
#ifndef CC_XBOX_DRIVER
      if (g_asmap_oracle) {
        const uint32_t j = cc_asmap_search(base, n, e, key);
        if (j != n) cc_oracle_mismatch("cc_asmap_find_absent", int(key), j, n);
      }
#endif
      CC_ASMAP_COUNT(3);
      return 0u;
    }
  }
  uint32_t lo, hi;
  const uint32_t i = cc_asmap_search(base, n, e, key, lo, hi);
  h.map = map; h.n = n; h.e = e;
  if (i == n) {
    // position the id would sort into (entries before lo are smaller and
    // after hi larger in a sorted map; lo and hi themselves were compared)
    const uint32_t p = lo + (REX_LOAD_U16(e + lo * 8u) < key ? 1u : 0u) + (hi != lo && REX_LOAD_U16(e + hi * 8u) < key ? 1u : 0u);
    h.ki = key | (p << 16) | 0x80000000u;
    CC_ASMAP_COUNT(5);
    return 0u;
  }
  h.ki = key | (i << 16);
  CC_ASMAP_COUNT(4);
  return REX_LOAD_U32(e + i * 8u + 4u);
}
// ActionScript Var read (shared by the locals and member lookups): Var
// {+0 object, +4 type, +8 payload} -> out value {type, payload}; object type
// 1 goes through sub_8206F918(out, object); unknown types leave out alone.
static CC_HOT_FN void cc_as_var_read(Context& ctx, Machine& base, uint32_t var, uint32_t out, uint32_t lr) {
  const uint32_t type = REX_LOAD_U32(var + 4u);
  switch (type) {
    case 0x80000000u: REX_STORE_U32(out + 0u, 0x80000000u); REX_STORE_U32(out + 4u, 0u); break;
    case 1u: {
      CcFrame frame(ctx, base, 96u);
      ctx.r3.u64 = out; ctx.r4.u64 = REX_LOAD_U32(var + 0u); ctx.lr = lr;
      sub_8206F918(ctx, base);
      break;
    }
    case 2u: REX_STORE_U32(out + 0u, 2u); REX_STORE_U8(out + 4u, REX_LOAD_U8(var + 8u)); break;
    case 4u: REX_STORE_U32(out + 0u, 4u); REX_STORE_U32(out + 4u, REX_LOAD_U32(var + 8u)); break;
    case 8u: REX_STORE_U32(out + 0u, 8u); REX_STORE_U16(out + 4u, REX_LOAD_U16(var + 8u)); break;
    case 16u: {  // through f0 as the original (float -> double -> float)
      ctx.fpscr.disableFlushMode();
      PPCRegister temp{};
      temp.u32 = REX_LOAD_U32(var + 8u);
      ctx.f0.f64 = double(temp.f32);
      REX_STORE_U32(out + 0u, 16u);
      temp.f32 = float(ctx.f0.f64);
      REX_STORE_U32(out + 4u, temp.u32);
      break;
    }
    default: break;
  }
}
static CC_HOT_FN void sub_82082390(Context& ctx, Machine& base) {
  const uint32_t r = cc_asmap_find(base, ctx.r3.u32, ctx.r4.u32 & 0xFFFFu);
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
  if (oracle) {
    sub_82082390_exact(ctx, base);
    if (ctx.r3.u32 != r) cc_oracle_mismatch("sub_82082390", 0, ctx.r3.u32, r);
    return;
  }
#else
  static_cast<void>(&sub_82082390_exact);
#endif
  ctx.r3.u64 = r;
}
#endif
#include "generated/sub_8208BE40.inc"
#ifdef CC_FAST
#define sub_8208AB98 sub_8208AB98_exact
#endif
#include "generated/sub_8208AB98.inc"
#ifdef CC_FAST
#undef sub_8208AB98
#endif
#ifdef CC_FAST
#define sub_820936B0 sub_820936B0_exact
#endif
#include "generated/sub_820936B0.inc"
#ifdef CC_FAST
#undef sub_820936B0
#endif
#include "generated/sub_82094530.inc"
#include "generated/sub_82094420.inc"
#include "generated/sub_820772B0.inc"
#include "generated/sub_820A1AC0.inc"
#ifdef CC_FAST
// Display-node classes the advance and frame-update walkers answer without
// a method call (vtables live in the image's read-only data): the clip
// class 0x8203E878 is active (slot 44 = li 1); the second clip class
// 0x8203F510 and the text field 0x8203F680 are not (li 0). Both clip
// classes share slot 84 (advance sub_82088A08), 88 (frame update
// sub_8208A228), 92 (sub_8208ADE8), 124 (bit 2 of byte +140) and 148
// (setParent, stw r4,96(r3)). Checked once against the mapped image; any
// difference leaves every call to cc_vcall. Host switch CC_WALK_VCALL=1,
// Xbox build CC_WALK_VCALL_BUILD: always the method calls.
enum : uint32_t { kVtClip = 0x8203E878u, kVtClip2 = 0x8203F510u, kVtText = 0x8203F680u };
static bool cc_walk_classes_check(Machine& base) {
#ifndef CC_XBOX_DRIVER
  if (std::getenv("CC_WALK_VCALL") != nullptr) return false;
#elif defined(CC_WALK_VCALL_BUILD)
  return false;
#endif
  auto slot = [&](uint32_t vt, uint32_t s) { uint64_t v = 0; base.memory.load_be(vt + s, 4, v); return uint32_t(v); };
  for (const uint32_t vt : {kVtClip, kVtClip2}) {
    if (slot(vt, 84u) != 0x82088A08u || slot(vt, 88u) != 0x8208A228u || slot(vt, 92u) != 0x8208ADE8u ||
        slot(vt, 124u) != 0x82086818u || slot(vt, 148u) != 0x820868C8u)
      return false;
  }
  return slot(kVtClip, 44u) == 0x820619E8u && slot(kVtClip2, 44u) == 0x82053A98u && slot(kVtText, 44u) == 0x82053A98u &&
         slot(0x820619E8u, 0u) == 0x38600001u && slot(0x82053A98u, 0u) == 0x38600000u && slot(0x820868C8u, 0u) == 0x90830060u &&
         slot(0x82086818u, 0u) == 0x8963008Cu && slot(0x82086818u, 4u) == 0x5563F7FEu &&
         slot(0x82086818u, 8u) == 0x4E800020u;
}
static inline bool cc_walk_classes_ok(Machine& base) {
  static const bool ok = cc_walk_classes_check(base);
  return ok;
}
// Slot 44 ("active") of child ch whose vtable word is vt: 1 / 0 for the
// classes above (r3 as the leaf leaves it), else the method call at return
// address lr.
#define cc_walk_active(CTX, BASE, CH, VT, OK, LR) ([&]() __attribute__((always_inline)) -> uint32_t { \
    if ((OK) && (VT) == kVtClip) { (CTX).r3.u64 = 1u; return 1u; } \
    if ((OK) && ((VT) == kVtClip2 || (VT) == kVtText)) { (CTX).r3.u64 = 0u; return 0u; } \
    return cc_vcall(CTX, BASE, CH, 44u, LR) & 0xFFu; }())
// The manager of node n's movie, [[[n+156]+76]+156] (its update stack:
// count +8248, entries at +(count+1998)*4).
static inline __attribute__((always_inline)) uint32_t cc_walk_mgr(Machine& base, uint32_t n) {
  return REX_LOAD_U32(REX_LOAD_U32(REX_LOAD_U32(n + 156u) + 76u) + 156u);
}
#define sub_82088A08 sub_82088A08_exact
#endif
#include "generated/sub_82088A08.inc"
#ifdef CC_FAST
#undef sub_82088A08
// Display-list advance (exact sub_82088A08: node r3), run per frame for
// every playing clip. Only for nodes with bit 7 of byte +140 set: the node
// is pushed on the manager's update stack ([[[node+156]+76]+156], count
// +8248, entries at +(count+1998)*4); if the node is playing (slot 124) its
// frame counter u16 +146 advances, wrapping to 1 past u16 +148 (on a wrap
// the children whose u16 +84 is not 1 are removed via sub_82084D18, the
// others take the node's u16 +144 into +82), +144 takes the new frame and
// slot 92 (r4 = 1) applies it. Then each child: after a wrap, a child whose
// +82 differs from the node's +144 is released via sub_82084C78(list,
// [child+28]); otherwise its +82 is cleared and, if active (slot 44), it
// advances (slot 148, r4 = node) and updates (slot 84). The stack entry is
// popped at the end. The known classes skip the method calls
// (cc_walk_classes_ok); the next sibling's lines are prefetched while the
// current child is visited.
static CC_HOT_FN void sub_82088A08(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  static const bool walk_exact = std::getenv("CC_WALK_EXACT") != nullptr;  // host A/B switch
  if (walk_exact) { sub_82088A08_exact(ctx, base); return; }
#else
  #ifdef CC_WALK_EXACT_BUILD
  sub_82088A08_exact(ctx, base); return;  // Xbox bisect build
#endif
  static_cast<void>(&sub_82088A08_exact);
#endif
  const uint32_t node = ctx.r3.u32;
  if ((REX_LOAD_U8(node + 140u) & 0x80u) == 0u) return;
  CcFrame frame(ctx, base, 128u);
  if (const uint32_t first = REX_LOAD_U32(node + 104u)) cc_prefetch_node(first);
  const bool ok = cc_walk_classes_ok(base);
  const uint32_t nvt = REX_LOAD_U32(node);
  const bool nclip = ok && (nvt == kVtClip || nvt == kVtClip2);
  {
    const uint32_t mgr = cc_walk_mgr(base, node);
    const uint32_t cnt = REX_LOAD_U32(mgr + 8248u) + 1u;
    REX_STORE_U32(mgr + 8248u, cnt);
    REX_STORE_U32(mgr + (cnt + 1998u) * 4u, node);
  }
  bool wrapped = false;
  uint32_t playing;
  if (nclip) {
    playing = (REX_LOAD_U8(node + 140u) >> 2) & 1u;
    ctx.r3.u64 = playing;
  } else {
    playing = cc_vcall(ctx, base, node, 124u, 0x82088A64u) & 0xFFu;
  }
  if (playing != 0u) {
    const uint32_t f = (REX_LOAD_U16(node + 146u) + 1u) & 0xFFFFu;
    REX_STORE_U16(node + 146u, uint16_t(f));
    if (f > REX_LOAD_U16(node + 148u)) {
      wrapped = true;
      REX_STORE_U16(node + 146u, 1u);
      uint32_t ch = REX_LOAD_U32(node + 104u);
      while (ch) {
        if (REX_LOAD_U16(ch + 84u) == 1u) {
          REX_STORE_U16(ch + 82u, REX_LOAD_U16(node + 144u));
          ch = REX_LOAD_U32(ch + 88u);
        } else {
          const uint32_t next = REX_LOAD_U32(ch + 88u);
          ctx.r3.u64 = node + 104u; ctx.r4.u64 = ch; ctx.lr = 0x82088ABCu;
          sub_82084D18(ctx, base);
          ch = next;
        }
      }
    }
    REX_STORE_U16(node + 144u, REX_LOAD_U16(node + 146u));
    ctx.r4.u64 = 1u;
    if (nclip) {
      ctx.r3.u64 = node; ctx.lr = 0x82088AF8u;
      sub_8208ADE8(ctx, base);
    } else {
      cc_vcall(ctx, base, node, 92u, 0x82088AF8u);
    }
  }
  for (uint32_t ch = REX_LOAD_U32(node + 104u); ch; ch = REX_LOAD_U32(ch + 88u)) {
    if (const uint32_t next = REX_LOAD_U32(ch + 88u)) cc_prefetch_node(next);
    if (wrapped && REX_LOAD_U16(node + 144u) != REX_LOAD_U16(ch + 82u)) {
      ctx.r3.u64 = node + 104u; ctx.r4.u64 = REX_LOAD_U32(ch + 28u); ctx.lr = 0x82088B30u;
      sub_82084C78(ctx, base);
      continue;
    }
    REX_STORE_U16(ch + 82u, 0u);
    const uint32_t vt = REX_LOAD_U32(ch);
    if (cc_walk_active(ctx, base, ch, vt, ok, 0x82088B4Cu) != 0u) {
      ctx.r4.u64 = node;
      if (ok && vt == kVtClip) {
        REX_STORE_U32(ch + 96u, node);  // setParent
        ctx.r3.u64 = ch; ctx.lr = 0x82088B84u;
        sub_82088A08(ctx, base);
      } else {
        cc_vcall(ctx, base, ch, 148u, 0x82088B70u);
        cc_vcall(ctx, base, ch, 84u, 0x82088B84u);
      }
    }
  }
  {
    const uint32_t mgr = cc_walk_mgr(base, node);
    const uint32_t idx = REX_LOAD_U32(mgr + 8248u);
    REX_STORE_U32(mgr + (idx + 1998u) * 4u, 0u);
    REX_STORE_U32(mgr + 8248u, idx - 1u);
  }
}
#endif
#ifdef CC_FAST
#define sub_8208A228 sub_8208A228_exact
#endif
#include "generated/sub_8208A228.inc"
#ifdef CC_FAST
#undef sub_8208A228
// Display-list frame update (exact sub_8208A228: node r3, frame r4 u16).
// Sets bit 4 of byte +86; nodes without bit 7 of byte +140 return 0. A
// nonzero frame is stored in u16 +144 with bit 6 of +140 set; +144 and +146
// are at least 1. The node is pushed on the manager's update stack; its
// transform block at +160 is rebuilt (sub_8207BAE8 when bit 3 of +140 is
// set, else sub_8207B8B8 and bit 3 set); a playing node (slot 124) applies
// its frame (slot 92, r4 = 2) and refreshes the block (sub_8207B630). Bit 2
// of +140 is cleared when bit 1 is set or the clip has one frame. Each
// child that is active (slot 44) and, while bit 6 is set, on the node's
// frame (u16 +82 == +144) is drawn (slot 88, r4 = 0) and its result OR-ed
// into the return value; active children while bit 6 is set, and inactive
// children with bit 4 of their +86, set bit 0. Without bit 0 the node's
// bit 4 of +86 is cleared; bit 6 of +140 is cleared and the stack popped.
// As in the advance walk, the known classes skip the method calls and the
// next sibling's lines are prefetched.
#ifndef CC_XBOX_DRIVER
static uint32_t g_clip_ticks = 0;  // host CC_TICK_STATS: clip frame updates per frame
#endif
static CC_HOT_FN void sub_8208A228(Context& ctx, Machine& base) {
#ifdef CC_XBOX_DRIVER
  ++g_fc[2];
#endif
#ifndef CC_XBOX_DRIVER
  static const bool walk_exact = std::getenv("CC_WALK_EXACT") != nullptr;  // host A/B switch
  ++g_clip_ticks;
  if (walk_exact) { sub_8208A228_exact(ctx, base); return; }
#else
  #ifdef CC_WALK_EXACT_BUILD
  sub_8208A228_exact(ctx, base); return;  // Xbox bisect build
#endif
  static_cast<void>(&sub_8208A228_exact);
#endif
  const uint32_t node = ctx.r3.u32;
  REX_STORE_U8(node + 86u, uint8_t(REX_LOAD_U8(node + 86u) | 16u));
  if ((REX_LOAD_U8(node + 140u) & 0x80u) == 0u) { ctx.r3.u64 = 0u; return; }
  CcFrame frame(ctx, base, 112u);
  const uint32_t fr = ctx.r4.u32 & 0xFFFFu;
  if (fr) {
    REX_STORE_U16(node + 144u, uint16_t(fr));
    REX_STORE_U8(node + 140u, uint8_t(REX_LOAD_U8(node + 140u) | 64u));
  }
  if (REX_LOAD_U16(node + 144u) == 0u) REX_STORE_U16(node + 144u, 1u);
  if (REX_LOAD_U16(node + 146u) == 0u) REX_STORE_U16(node + 146u, 1u);
  if (const uint32_t first = REX_LOAD_U32(node + 104u)) cc_prefetch_node(first);
  const bool ok = cc_walk_classes_ok(base);
  {
    const uint32_t mgr = cc_walk_mgr(base, node);
    const uint32_t cnt = REX_LOAD_U32(mgr + 8248u) + 1u;
    REX_STORE_U32(mgr + 8248u, cnt);
    REX_STORE_U32(mgr + (cnt + 1998u) * 4u, node);
  }
  ctx.r3.u64 = node + 160u;
  if (REX_LOAD_U8(node + 140u) & 0x08u) {
    ctx.lr = 0x8208A2E4u;
    sub_8207BAE8(ctx, base);
  } else {
    ctx.lr = 0x8208A2ECu;
    sub_8207B8B8(ctx, base);
    REX_STORE_U8(node + 140u, uint8_t(REX_LOAD_U8(node + 140u) | 8u));
  }
  const uint32_t nvt = REX_LOAD_U32(node);
  const bool nclip = ok && (nvt == kVtClip || nvt == kVtClip2);
  uint32_t playing;
  if (nclip) {
    playing = (REX_LOAD_U8(node + 140u) >> 2) & 1u;
    ctx.r3.u64 = playing;
  } else {
    playing = cc_vcall(ctx, base, node, 124u, 0x8208A30Cu) & 0xFFu;
  }
  if (playing != 0u) {
    ctx.r4.u64 = 2u;
    if (nclip) {
      ctx.r3.u64 = node; ctx.lr = 0x8208A330u;
      sub_8208ADE8(ctx, base);
    } else {
      cc_vcall(ctx, base, node, 92u, 0x8208A330u);
    }
    ctx.r3.u64 = node + 160u;
    ctx.lr = 0x8208A338u;
    sub_8207B630(ctx, base);
  }
  {
    const uint32_t f = REX_LOAD_U8(node + 140u);
    if ((f & 2u) || REX_LOAD_U16(node + 148u) == 1u) REX_STORE_U8(node + 140u, uint8_t(f & ~4u));
  }
  uint64_t acc = 0u;
  for (uint32_t ch = REX_LOAD_U32(node + 104u); ch; ch = REX_LOAD_U32(ch + 88u)) {
    if (const uint32_t next = REX_LOAD_U32(ch + 88u)) cc_prefetch_node(next);
    uint32_t bit;
    const uint32_t vt = REX_LOAD_U32(ch);
    if (cc_walk_active(ctx, base, ch, vt, ok, 0x8208A380u) != 0u) {
      if ((REX_LOAD_U8(node + 140u) & 0x40u) == 0u || REX_LOAD_U16(ch + 82u) == REX_LOAD_U16(node + 144u)) {
        ctx.r4.u64 = 0u;
        if (ok && vt == kVtClip) {
          ctx.r3.u64 = ch; ctx.lr = 0x8208A3C4u;
          sub_8208A228(ctx, base);
        } else {
          cc_vcall(ctx, base, ch, 88u, 0x8208A3C4u);
        }
        acc |= ctx.r3.u64;
      }
      bit = REX_LOAD_U8(node + 140u) & 0x40u;
    } else {
      bit = REX_LOAD_U8(ch + 86u) & 0x10u;
    }
    if (bit) acc |= 1u;
  }
  if ((acc & 1u) == 0u) REX_STORE_U8(node + 86u, uint8_t(REX_LOAD_U8(node + 86u) & ~16u));
  REX_STORE_U8(node + 140u, uint8_t(REX_LOAD_U8(node + 140u) & ~64u));
  {
    const uint32_t mgr = cc_walk_mgr(base, node);
    const uint32_t idx = REX_LOAD_U32(mgr + 8248u);
    REX_STORE_U32(mgr + (idx + 1998u) * 4u, 0u);
    REX_STORE_U32(mgr + 8248u, idx - 1u);
  }
  ctx.r3.u64 = acc;
}
#endif
#ifdef CC_FAST
#define sub_8208AE78 sub_8208AE78_exact
#endif
#include "generated/sub_8208AE78.inc"
#ifdef CC_FAST
#undef sub_8208AE78
// Display-list refresh (exact sub_8208AE78: node r3). If bit 5 of byte +140
// is set it is cleared and sub_82084EE0(node + 104) runs; then every child
// in the list at +104 (linked through +88) that answers slot 44 is refreshed
// the same way, depth first. The play build visits only the candidates
// (g_dl_dirty, see there); cc_dl_refresh_walk is the walk itself.
static CC_HOT_FN void cc_dl_refresh_walk(Context& ctx, Machine& base) {
  const uint32_t node = ctx.r3.u32;
  CcFrame frame(ctx, base, 96u);
  const uint32_t flags = REX_LOAD_U8(node + 140u);
  if (flags & 0x20u) {
    REX_STORE_U8(node + 140u, uint8_t(flags & ~0x20u));
    ctx.r3.u64 = node + 104u;
    ctx.lr = 0x8208AEB0u;
    sub_82084EE0(ctx, base);
  }
  for (uint32_t ch = REX_LOAD_U32(node + 104u); ch; ch = REX_LOAD_U32(ch + 88u)) {
    if ((cc_vcall(ctx, base, ch, 44u, 0x8208AED0u) & 0xFFu) != 0u) {
      ctx.r3.u64 = ch;
      ctx.lr = 0x8208AEE4u;
      cc_dl_refresh_walk(ctx, base);
    }
  }
}
// Slot 44 ("active") of a display node's class as a constant: the clip
// class answers 1, the second clip class and text fields 0, other classes
// their "li" leaf; known = false for anything else.
static CC_HOT_FN inline uint32_t cc_dl_active(Machine& base, uint32_t node, bool& known) {
  const uint32_t vt = REX_LOAD_U32(node);
  if (vt == 0x8203E878u) return 1u;
  if (vt == 0x8203F510u || vt == 0x8203F680u) return 0u;
  const CcLeaf& m = cc_leaf_info(base, REX_LOAD_U32(vt + 44u));
  if (m.kind != 2) { known = false; return 0u; }
  return uint32_t(m.imm) & 0xFFu;
}
// Whether the walk from root reaches n (see g_dl_dirty).
static bool cc_dl_reached(Machine& base, uint32_t n, uint32_t root, bool& known) {
  for (uint32_t depth = 0; n != root; ++depth) {
    if (depth == 4096u || cc_dl_active(base, n, known) == 0u) return false;
    const uint32_t p = REX_LOAD_U32(n + 96u);
    if (p == 0u) return false;
    uint32_t c = REX_LOAD_U32(p + 104u);
    while (c != 0u && c != n) c = REX_LOAD_U32(c + 88u);
    if (c == 0u) return false;
    n = p;
  }
  return true;
}
#ifndef CC_XBOX_DRIVER
// Host oracle: the nodes the walk from n would sort, in walk order.
static void cc_dl_refresh_expect(Context& ctx, Machine& base, uint32_t n, std::vector<uint32_t>& out) {
  if (REX_LOAD_U8(n + 140u) & 0x20u) out.push_back(n);
  for (uint32_t ch = REX_LOAD_U32(n + 104u); ch; ch = REX_LOAD_U32(ch + 88u)) {
    bool known = true;
    const uint32_t a = cc_dl_active(base, ch, known);
    if (!known) { cc_oracle_mismatch("sub_8208AE78 class", 0, ch, REX_LOAD_U32(ch)); continue; }
    if (a) cc_dl_refresh_expect(ctx, base, ch, out);
  }
}
#endif
static CC_HOT_FN void sub_8208AE78(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  static const bool walk_exact = std::getenv("CC_WALK_EXACT") != nullptr;  // host A/B switch
  if (walk_exact) { sub_8208AE78_exact(ctx, base); return; }
  static const bool walk = std::getenv("CC_REFRESH_WALK") != nullptr;  // host A/B switch
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr || std::getenv("CC_REFRESH_ORACLE") != nullptr;
#else
  #ifdef CC_WALK_EXACT_BUILD
  sub_8208AE78_exact(ctx, base); return;  // Xbox bisect build
#endif
  static_cast<void>(&sub_8208AE78_exact);
#ifdef CC_REFRESH_WALK_BUILD
  constexpr bool walk = true;  // Xbox bisect build
#else
  constexpr bool walk = false;
#endif
#endif
  if (walk || g_dl_walk_always) { cc_dl_refresh_walk(ctx, base); return; }
  const uint32_t root = ctx.r3.u32;
#ifndef CC_XBOX_DRIVER
  ++g_dl_rst.refreshes;
  std::vector<uint32_t> expect, done;
  if (oracle) cc_dl_refresh_expect(ctx, base, root, expect);
#endif
  CcFrame frame(ctx, base, 96u);
  auto sort_children = [&](uint32_t n, uint32_t flags) {
#ifndef CC_XBOX_DRIVER
    if (oracle) done.push_back(n);
#endif
    REX_STORE_U8(n + 140u, uint8_t(flags & ~0x20u));
    ctx.r3.u64 = n + 104u;
    ctx.lr = 0x8208AEB0u;
    sub_82084EE0(ctx, base);
  };
  {
    const uint32_t flags = REX_LOAD_U8(root + 140u);
    if (flags & 0x20u) sort_children(root, flags);
  }
  uint32_t kept = 0u;
  for (uint32_t i = 0; i < g_dl_ndirty; ++i) {
    const uint32_t d = g_dl_dirty[i];
    const uint32_t flags = REX_LOAD_U8(d + 140u);
    if (d == root || (flags & 0x20u) == 0u) continue;
#ifndef CC_XBOX_DRIVER
    ++g_dl_rst.checked;
#endif
    bool known = true;
    if (cc_dl_active(base, d, known) == 0u && known) continue;
    if (cc_dl_reached(base, d, root, known)) { sort_children(d, flags); continue; }
    // A class the table cannot judge, or an active node the walk does not
    // reach now (detached, or inserted before the advance walk set its +96):
    // walk instead, from then on. Keeping such a node for later could read
    // it after its memory is reused, or sort a list a frame late.
    {
      g_dl_walk_always = true;
      for (uint32_t k = i; k < g_dl_ndirty; ++k) g_dl_dirty[kept++] = g_dl_dirty[k];
      g_dl_ndirty = kept;
      ctx.r3.u64 = root;
      cc_dl_refresh_walk(ctx, base);
      return;
    }
  }
  g_dl_ndirty = kept;
#ifndef CC_XBOX_DRIVER
  if (kept > g_dl_rst.kept_max) g_dl_rst.kept_max = kept;
  if (oracle) {
    std::vector<uint32_t> a = expect, b = done;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    if (a != b) {
      cc_oracle_mismatch("sub_8208AE78", int(a.size()), a.empty() ? 0u : a[0], b.empty() ? 0u : b[0]);
      for (uint32_t x : a) if (!std::binary_search(b.begin(), b.end(), x)) cc_log("ORACLE sub_8208AE78 missed %08x parent=%08x\n", x, REX_LOAD_U32(x + 96u));
      for (uint32_t x : b) if (!std::binary_search(a.begin(), a.end(), x)) cc_log("ORACLE sub_8208AE78 extra %08x\n", x);
    }
  }
#endif
}
#endif
#include "generated/sub_820915F0.inc"
#include "generated/sub_8209DE50.inc"


// Checkpoint 016 startup-prefix closure. Exact bodies are copied byte-for-byte
// from the sealed ReXGlue translation units; the two host shims below are
// intentionally narrow platform/CRT boundaries and are not counted as exact bodies.
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savegprlr_23.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restgprlr_23.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_82053A00.inc"

static void sub_82127778(Context& ctx, Machine& base) {
  // WIP 021 second accepted sprintf shape: the sealed shader-path format
  // "game:\shaders\%s" at 0x82042134 with a single bounded string argument,
  // used by exact sub_820AA488 to build shader resource paths. Any other
  // format/argument shape still fails closed.
  if (ctx.r4.u32 == 0x82042134u) {
    static const char prefix_fmt[] = "game:\\shaders\\%s";
    for (unsigned i = 0; i <= sizeof(prefix_fmt) - 1; ++i)
      if (base.load(ctx.r4.u32 + i, 1) != uint8_t(prefix_fmt[i]))
        base.fail(Error::unsupported, 0x82127778u);
    uint32_t out = ctx.r3.u32;
    unsigned written = 0;
    for (const char* p = "game:\\shaders\\"; *p; ++p) {
      base.store(out++, 1, uint8_t(*p));
      ++written;
    }
    for (unsigned i = 0;; ++i) {
      if (i >= 64u) base.fail(Error::unsupported, 0x82127778u);
      const uint8_t chv = uint8_t(base.load(ctx.r5.u32 + i, 1));
      if (!chv) break;
      base.store(out++, 1, chv);
      ++written;
    }
    base.store(out, 1, 0);
    ctx.r3.u64 = written;
    return;
  }
  // WIP 022 third accepted sprintf shape: the sealed font-path format
  // "game:\Fonts\%s.xpr" at 0x820420CC with a single bounded string argument,
  // used by exact sub_820A9B58 to build font resource paths.
  if (ctx.r4.u32 == 0x820420CCu) {
    static const char font_fmt[] = "game:\\Fonts\\%s.xpr";
    for (unsigned i = 0; i <= sizeof(font_fmt) - 1; ++i)
      if (base.load(ctx.r4.u32 + i, 1) != uint8_t(font_fmt[i]))
        base.fail(Error::unsupported, 0x82127778u);
    uint32_t out = ctx.r3.u32;
    unsigned written = 0;
    for (const char* p = "game:\\Fonts\\"; *p; ++p) {
      base.store(out++, 1, uint8_t(*p));
      ++written;
    }
    for (unsigned i = 0;; ++i) {
      if (i >= 64u) base.fail(Error::unsupported, 0x82127778u);
      const uint8_t chv = uint8_t(base.load(ctx.r5.u32 + i, 1));
      if (!chv) break;
      base.store(out++, 1, chv);
      ++written;
    }
    for (const char* p = ".xpr"; *p; ++p) {
      base.store(out++, 1, uint8_t(*p));
      ++written;
    }
    base.store(out, 1, 0);
    ctx.r3.u64 = written;
    return;
  }
  // WIP 023 fourth accepted sprintf shape: the sealed pak-path format
  // "game\%s.pak" at 0x8203FDD0 with a single bounded string argument,
  // used by the frame loop's asset loader (first observed building
  // "game\logo.pak" for the intro logo screen).
  if (ctx.r4.u32 == 0x8203FDD0u) {
    static const char pak_fmt[] = "game\\%s.pak";
    for (unsigned i = 0; i <= sizeof(pak_fmt) - 1; ++i)
      if (base.load(ctx.r4.u32 + i, 1) != uint8_t(pak_fmt[i]))
        base.fail(Error::unsupported, 0x82127778u);
    uint32_t out = ctx.r3.u32;
    unsigned written = 0;
    for (const char* p = "game\\"; *p; ++p) {
      base.store(out++, 1, uint8_t(*p));
      ++written;
    }
    for (unsigned i = 0;; ++i) {
      if (i >= 64u) base.fail(Error::unsupported, 0x82127778u);
      const uint8_t chv = uint8_t(base.load(ctx.r5.u32 + i, 1));
      if (!chv) break;
      base.store(out++, 1, chv);
      ++written;
    }
    for (const char* p = ".pak"; *p; ++p) {
      base.store(out++, 1, uint8_t(*p));
      ++written;
    }
    base.store(out, 1, 0);
    ctx.r3.u64 = written;
    return;
  }
  // WIP 023 fifth accepted sprintf shape: the sealed device-path format
  // "game:\%s" at 0x82040BF4 with a single bounded string argument, used by
  // the frame loop's asset loader to prefix the pak-relative path (first
  // observed building "game:\game\logo.pak").
  if (ctx.r4.u32 == 0x82040BF4u) {
    static const char dev_fmt[] = "game:\\%s";
    for (unsigned i = 0; i <= sizeof(dev_fmt) - 1; ++i)
      if (base.load(ctx.r4.u32 + i, 1) != uint8_t(dev_fmt[i]))
        base.fail(Error::unsupported, 0x82127778u);
    uint32_t out = ctx.r3.u32;
    unsigned written = 0;
    for (const char* p = "game:\\"; *p; ++p) {
      base.store(out++, 1, uint8_t(*p));
      ++written;
    }
    for (unsigned i = 0;; ++i) {
      if (i >= 128u) base.fail(Error::unsupported, 0x82127778u);
      const uint8_t chv = uint8_t(base.load(ctx.r5.u32 + i, 1));
      if (!chv) break;
      base.store(out++, 1, chv);
      ++written;
    }
    base.store(out, 1, 0);
    ctx.r3.u64 = written;
    return;
  }
  // WIP 023 seventh accepted sprintf shape: the sealed sound-path format
  // "game:\sounds\%s" at 0x82040594 with a single bounded string
  // argument, used by the intro screen's audio loader.
  if (ctx.r4.u32 == 0x82040594u) {
    static const char snd_fmt[] = "game:\\sounds\\%s";
    for (unsigned i = 0; i <= sizeof(snd_fmt) - 1; ++i)
      if (base.load(ctx.r4.u32 + i, 1) != uint8_t(snd_fmt[i]))
        base.fail(Error::unsupported, 0x82127778u);
    uint32_t out = ctx.r3.u32;
    unsigned written = 0;
    for (const char* p = "game:\\sounds\\"; *p; ++p) {
      base.store(out++, 1, uint8_t(*p));
      ++written;
    }
    for (unsigned i = 0;; ++i) {
      if (i >= 128u) base.fail(Error::unsupported, 0x82127778u);
      const uint8_t chv = uint8_t(base.load(ctx.r5.u32 + i, 1));
      if (!chv) break;
      base.store(out++, 1, chv);
      ++written;
    }
    base.store(out, 1, 0);
    ctx.r3.u64 = written;
    return;
  }
  // WIP 023 sixth accepted sprintf shape: the sealed plain "%s" format at
  // 0x8203E464 with a single bounded string argument - a straight copy used
  // by the frame loop's asset loader while resolving the logo pak path.
  if (ctx.r4.u32 == 0x8203E464u) {
    if (base.load(ctx.r4.u32 + 0, 1) != uint8_t('%') ||
        base.load(ctx.r4.u32 + 1, 1) != uint8_t('s') ||
        base.load(ctx.r4.u32 + 2, 1) != 0u)
      base.fail(Error::unsupported, 0x82127778u);
    uint32_t out = ctx.r3.u32;
    unsigned written = 0;
    for (unsigned i = 0;; ++i) {
      if (i >= 128u) base.fail(Error::unsupported, 0x82127778u);
      const uint8_t chv = uint8_t(base.load(ctx.r5.u32 + i, 1));
      if (!chv) break;
      base.store(out++, 1, chv);
      ++written;
    }
    base.store(out, 1, 0);
    ctx.r3.u64 = written;
    return;
  }
  // WIP 023 ninth accepted sprintf shape: any sealed format of the exact
  // structural form "game:\<letters>\%s" (observed so far: shaders, Fonts,
  // game, sounds, music) is a verbatim prefix plus one bounded string.
  {
    char pre[32]; unsigned n = 0; bool shaped = false;
    const char head[] = "game:\\";
    bool okh = true;
    for (unsigned i = 0; i < 6u; ++i) {
      pre[i] = char(base.load(ctx.r4.u32 + i, 1));
      if (pre[i] != head[i]) { okh = false; break; }
    }
    if (okh) {
      n = 6;
      for (;; ++n) {
        if (n >= 30u) break;
        const char chv = char(base.load(ctx.r4.u32 + n, 1));
        if ((chv>='A'&&chv<='Z')||(chv>='a'&&chv<='z')) { pre[n]=chv; continue; }
        if (chv=='\\' && n>6u &&
            char(base.load(ctx.r4.u32+n+1,1))=='%' &&
            char(base.load(ctx.r4.u32+n+2,1))=='s' &&
            char(base.load(ctx.r4.u32+n+3,1))==0) {
          pre[n]='\\'; ++n; shaped = true;
        }
        break;
      }
    }
    if (shaped) {
      uint32_t out = ctx.r3.u32;
      unsigned written = 0;
      for (unsigned i = 0; i < n; ++i) { base.store(out++,1,uint8_t(pre[i])); ++written; }
      for (unsigned i = 0;; ++i) {
        if (i >= 128u) base.fail(Error::unsupported, 0x82127778u);
        const uint8_t chv = uint8_t(base.load(ctx.r5.u32 + i, 1));
        if (!chv) break;
        base.store(out++, 1, chv);
        ++written;
      }
      base.store(out, 1, 0);
      ctx.r3.u64 = written;
      return;
    }
  }
  // WIP 023 eighth accepted sprintf shape: a literal format containing no
  // conversion specifier at all (first observed: ".xma" appended to a
  // sound path at 0x820405A4) is a bounded verbatim copy.
  {
    char lit[64]; unsigned n = 0; bool plain = true;
    for (;; ++n) {
      if (n >= sizeof(lit)) { plain = false; break; }
      const uint8_t chv = uint8_t(base.load(ctx.r4.u32 + n, 1));
      lit[n] = char(chv);
      if (!chv) break;
      if (chv == uint8_t('%')) { plain = false; break; }
    }
    if (plain) {
      uint32_t out = ctx.r3.u32;
      for (unsigned i = 0; i < n; ++i) base.store(out + i, 1, uint8_t(lit[i]));
      base.store(out + n, 1, 0);
      ctx.r3.u64 = n;
      return;
    }
  }
  // WIP 023: general bounded formatter for every other format string (the
  // game has hundreds). sprintf(char* out, const char* fmt, ...): varargs
  // follow the Xbox 360 convention - r5..r10, then 8-byte stack slots from
  // r1+0x50 - with doubles passed as their 64-bit bit pattern in the same
  // slots. Standard conversions %d %i %u %x %X %o %c %s %S %p %e %f %g %%
  // with flags, width, precision (numeric or *) and h/l/ll/I64 lengths.
  // Output and each string argument are bounded; any other conversion
  // character fails closed.
  {
    unsigned argi = 0;
    auto next_arg = [&]() -> uint64_t {
      const unsigned i = argi++;
      if (i < 6u) {
        switch (i) {
          case 0: return ctx.r5.u64; case 1: return ctx.r6.u64;
          case 2: return ctx.r7.u64; case 3: return ctx.r8.u64;
          case 4: return ctx.r9.u64; default: return ctx.r10.u64;
        }
      }
      return base.load(ctx.r1.u32 + 0x50u + (i - 6u) * 8u, 8);
    };
    static char outb[4608];
    size_t on = 0;
    auto put = [&](const char* s) {
      for (; *s; ++s) {
        if (on >= 4096u) base.fail(Error::unsupported, 0x82127778u);
        outb[on++] = *s;
      }
    };
    uint32_t f = ctx.r4.u32;
    for (unsigned guard = 0;; ++guard) {
      if (guard > 4096u) base.fail(Error::unsupported, 0x82127778u);
      const char c = char(base.load(f++, 1));
      if (!c) break;
      if (c != '%') { const char one[2] = {c, 0}; put(one); continue; }
      char spec[48] = "%";
      size_t sn = 1;
      auto spec_push = [&](char d) { if (sn < 40u) { spec[sn++] = d; spec[sn] = 0; } };
      char conv = 0;
      bool is64 = false, is_short = false, wide = false;
      for (unsigned k = 0; k < 16u; ++k) {
        const char d = char(base.load(f++, 1));
        if (d == '*') {
          char num[16]; std::snprintf(num, sizeof(num), "%d", int32_t(uint32_t(next_arg())));
          for (const char* q = num; *q; ++q) spec_push(*q);
          continue;
        }
        if (d == 'l') { if (char(base.load(f, 1)) == 'l') { ++f; is64 = true; } else wide = true; continue; }
        if (d == 'h') { is_short = true; continue; }
        if (d == 'I' && char(base.load(f,1)) == '6' && char(base.load(f+1,1)) == '4') { f += 2; is64 = true; continue; }
        if (d && std::strchr("-+ #0123456789.", d)) { spec_push(d); continue; }
        conv = d; break;
      }
      char fmt[64], buf[512];
      switch (conv) {
        case '%': put("%"); break;
        case 'd': case 'i': {
          const uint64_t v = next_arg();
          const long long sv = is64 ? (long long)(int64_t)v
                             : is_short ? (long long)(int16_t)v : (long long)(int32_t)(uint32_t)v;
          std::snprintf(fmt, sizeof(fmt), "%slld", spec);
          std::snprintf(buf, sizeof(buf), fmt, sv); put(buf); break;
        }
        case 'u': case 'x': case 'X': case 'o': {
          const uint64_t v = next_arg();
          const unsigned long long uv = is64 ? v : is_short ? (v & 0xFFFFu) : (v & 0xFFFFFFFFu);
          std::snprintf(fmt, sizeof(fmt), "%sll%c", spec, conv);
          std::snprintf(buf, sizeof(buf), fmt, uv); put(buf); break;
        }
        case 'p': std::snprintf(buf, sizeof(buf), "%08X", uint32_t(next_arg())); put(buf); break;
        case 'c': { const char one[2] = {char(uint32_t(next_arg()) & 0xFFu), 0}; put(one); break; }
        case 'e': case 'E': case 'f': case 'g': case 'G': {
          uint64_t bits = next_arg(); double dv; std::memcpy(&dv, &bits, 8);
          std::snprintf(fmt, sizeof(fmt), "%s%c", spec, conv);
          std::snprintf(buf, sizeof(buf), fmt, dv); put(buf); break;
        }
        case 's': case 'S': {
          const uint32_t sp = uint32_t(next_arg());
          const bool w = (conv == 'S') != wide;  // %S / %ls = UTF-16BE
          static char sv[1100];
          size_t n = 0;
          if (!sp) { std::snprintf(sv, sizeof(sv), "(null)"); }
          else {
            for (uint32_t k = 0; k < 1024u; ++k) {
              const uint32_t ch = w ? uint32_t(base.load(sp + k * 2u, 2)) : uint32_t(base.load(sp + k, 1));
              if (!ch) break;
              sv[n++] = ch < 0x80u ? char(ch) : '?';
            }
            sv[n] = 0;
          }
          std::snprintf(fmt, sizeof(fmt), "%ss", spec);
          std::snprintf(buf, sizeof(buf), fmt, sv); put(buf); break;
        }
        default:
          cc_elog("SPRINTF unsupported conversion '%c' fmt=%08x\n", conv ? conv : '?', ctx.r4.u32);
          base.fail(Error::unsupported, 0x82127778u);
      }
    }
    uint32_t out = ctx.r3.u32;
    for (size_t i = 0; i < on; ++i) base.store(out++, 1, uint8_t(outb[i]));
    base.store(out, 1, 0);
    ctx.r3.u64 = on;
  }
}

#include "generated/sub_8209CA70.inc"
#include "generated/sub_820783E8.inc"
#include "generated/sub_8209C7A8.inc"
#include "generated/sub_8209C588.inc"
#include "generated/sub_82073ED0.inc"
#include "generated/sub_820745D8.inc"
#include "generated/sub_82053118.inc"
#include "generated/sub_82052EA8.inc"
#include "generated/sub_82075410.inc"

static void __imp__RtlInitializeCriticalSection(Context& ctx, Machine& base) {
  // Startup-prefix proof is single-threaded. The Xbox import receives a
  // 28-byte object here; initialize the owned bytes deterministically. WIP
  // 021 additionally registers the object so the bounded enter/leave shims
  // accept exactly the critical sections exact code created (the CRT heap's
  // lock is the first). The registry is small and fails closed when full.
  const uint32_t p=ctx.r3.u32;
  if (p > 0xffffffe4u) base.fail(Error::context,p);
  for (unsigned i=0;i<28;++i) base.store(p+i,1,0);
  for (uint32_t i=0;i<g_registered_cs_count;++i)
    if (g_registered_cs[i]==p) { ctx.r3.u64=0; return; }
  if (g_registered_cs_count>=64u) base.fail(Error::unsupported,0x8214A854u);
  g_registered_cs[g_registered_cs_count]=p;
  g_registered_cs_locked[g_registered_cs_count]=false;
  ++g_registered_cs_count;
  ctx.r3.u64=0;
}

#include "generated/sub_82095C20.inc"
#include "generated/sub_8209C340.inc"
#include "generated/sub_8209CED0.inc"
#ifdef CC_FAST
#define sub_82084BE8 sub_82084BE8_exact
#endif
#include "generated/sub_82084BE8.inc"
#ifdef CC_FAST
#undef sub_82084BE8
// Display-list clear (exact sub_82084BE8: list r3), seen by the name cache.
static void sub_82084BE8(Context& ctx, Machine& base) {
  const CcDlMutate m(ctx.r3.u32);
  sub_82084BE8_exact(ctx, base);
}
#endif
#ifdef CC_FAST
#define sub_82079A00 sub_82079A00_exact
#endif
#include "generated/sub_82079A00.inc"
#ifdef CC_FAST
#undef sub_82079A00
#endif
#include "generated/sub_8207A0D0.inc"
#include "generated/sub_82079F38.inc"
#ifdef CC_FAST
#define sub_820867B8 sub_820867B8_exact
#endif
#include "generated/sub_820867B8.inc"
#ifdef CC_FAST
#undef sub_820867B8
#define sub_82086BA8 sub_82086BA8_exact
#endif
#include "generated/sub_82086BA8.inc"
#ifdef CC_FAST
#undef sub_82086BA8
#define sub_820869B0 sub_820869B0_exact
#endif
#include "generated/sub_820869B0.inc"
#ifdef CC_FAST
#undef sub_820869B0
// Clip name clear (exact sub_820867B8: clip r3; u16 +100 = 0), clip reset
// (exact sub_82086BA8, the clip vtable's slot 4: clears the clip's own
// list at +104, then its depth, link +88, name and parent) and clip
// constructor (exact sub_820869B0: list head +104 = 0), seen by the name
// cache. The reset also counts as a change of the list it may still be
// linked into (its parent's, [clip+96]+104).
static void sub_820867B8(Context& ctx, Machine& base) {
  const uint32_t old = REX_LOAD_U16(ctx.r3.u32 + 100u);
  sub_820867B8_exact(ctx, base);
  cc_dl_name_changed(old);
}
static void sub_82086BA8(Context& ctx, Machine& base) {
  const uint32_t clip = ctx.r3.u32, parent = REX_LOAD_U32(clip + 96u);
  const CcDlMutate own(clip + 104u);
  if (parent) cc_dl_list_changed(parent + 104u);
  sub_82086BA8_exact(ctx, base);
  if (parent) cc_dl_list_changed(parent + 104u);
}
static void sub_820869B0(Context& ctx, Machine& base) {
  const CcDlMutate own(ctx.r3.u32 + 104u);
  sub_820869B0_exact(ctx, base);
}
#endif
#include "generated/sub_82094C30.inc"
#include "generated/sub_82129FA0.inc"
#include "generated/sub_8208CFA0.inc"


// Deterministic console-region/platform shims used only by the startup locale
// constructor. They validate the observed call shapes rather than pretending to
// implement the wider Xbox APIs.
static void __imp__ExGetXConfigSetting(Context& ctx, Machine& base) {
  if (ctx.r3.u32 != 3u || ctx.r6.u32 != 4u)
    base.fail(Error::unsupported, 0x8214A554u);
  if (ctx.r5.u32 > 0xfffffffbu || ctx.r7.u32 > 0xfffffffdU)
    base.fail(Error::context, 0x8214A554u);
  if (ctx.r4.u32 == 9u) {
    // XCONFIG_USER_LANGUAGE: the port ships English (XC_LANGUAGE_ENGLISH).
    base.store(ctx.r5.u32,4,1);
    base.store(ctx.r7.u32,2,4);
    ctx.r3.s64 = 0;
    return;
  }
  if (ctx.r4.u32 >= 1u && ctx.r4.u32 <= 16u && ctx.r4.u32 != 9u &&
      ctx.r4.u32 != 10u) {
    // WIP 023: the title screen reads the user-settings block (category 3:
    // time-zone bias/names/dates, language, video/retail flags). The
    // deterministic fixture console is UTC with every 4-byte setting zero;
    // settings 9 and 10 keep their earlier observed startup semantics.
    base.store(ctx.r5.u32,4,0);
    if (ctx.r7.u32) base.store(ctx.r7.u32,2,4);
    ctx.r3.s64 = 0;
    return;
  }
  if (ctx.r4.u32 == 10u) {
    // This value is not consumed before the checkpoint-018 graphics boundary;
    // expose a deterministic zero-valued platform setting and the observed size.
    base.store(ctx.r5.u32,4,0);
    base.store(ctx.r7.u32,2,4);
    ctx.r3.s64 = 0;
    return;
  }
  cc_elog("XCONFIG reject cat=%u setting=%u buf=%08x size=%u lr=%08x\n",
          ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, uint32_t(ctx.lr));
  base.fail(Error::unsupported, 0x8214A554u);
}
static void __imp__XGetGameRegion(Context& ctx, [[maybe_unused]] Machine& base) {
  // XGAME_REGION_NA_ALL (0x0101 is the Japan region and selects Japanese text).
  ctx.r3.u64 = 0x00FFu;
}
static void __imp__XNotifyPositionUI(Context& ctx, Machine& base) {
  if (ctx.r3.u32 != 1u) base.fail(Error::unsupported, 0x8214A1F4u);
  ctx.r3.u64 = 0;
}

#include "generated/sub_820B6998.inc"
#include "generated/sub_8209F9F0.inc"
#include "generated/sub_8209D3D8.inc"
#include "generated/sub_8209D538.inc"
#include "generated/sub_82050170.inc"
#include "generated/sub_82050000.inc"
#include "generated/sub_8209D2D0.inc"
#include "generated/sub_8209F7E8.inc"

// Checkpoint 017 thread/platform boundary. The five startup workers are created
// suspended by the original code, assigned priority/affinity, then resumed.
// The host proof records that lifecycle as bounded scheduler state but does not
// execute the worker entry: sub_820B0E80 is an intentional infinite work loop.
// WIP 023 thread model: a newly started system thread runs immediately, on
// its own scratch stack, until it first blocks (a wait nothing can satisfy,
// or a sleep); the harness then returns to the creator and abandons it.
// Everything the thread does before blocking - creating timers, signalling
// its creator's "ready" event - really happens. The standard thread thunk
// is skipped because it would overwrite the main thread's CRT per-thread
// data (one global TLS table in this harness). Real failures inside the
// thread still stop the whole run.
static std::jmp_buf g_thread_escape;
static bool g_in_thread_run = false;
static void cc_thread_block_point() {
  if (g_in_thread_run) std::longjmp(g_thread_escape, 1);
}
static void cc_run_thread_body(Machine& base, uint32_t start, uint32_t param, uint32_t r13) {
  Context tc{};
  tc.r1.u32 = 0x00039000u;   // scratch stack (main thread above, workers at 0x34000)
  tc.r13.u32 = r13;
  tc.r3.u32 = param;
  tc.lr = 0x820B79B8u;
  dispatch(start, tc, base);
}
static void cc_run_thread_until_block(Machine& base, uint32_t start, uint32_t param, uint32_t r13) {
  if (g_in_thread_run) base.fail(Error::unsupported, start);  // no nesting
  const uint32_t saved_depth = base.depth;
  g_in_thread_run = true;
  if (setjmp(g_thread_escape) == 0) {
    cc_run_thread_body(base, start, param, r13);
    cc_log("thread %08x returned without blocking\n", start);
  } else {
    cc_log("thread %08x ran until it blocked\n", start);
  }
  g_in_thread_run = false;
  base.depth = saved_depth;
}
static void __imp__ExCreateThread(Context& ctx, Machine& base) {
  const uint32_t out_handle=ctx.r3.u32;
  if (ctx.r7.u32 == 0x820D99B0u || ctx.r7.u32 == 0x820D9A78u) {
    // WIP 022: the exact audio-driver init creates two suspended workers
    // (start routines 0x820D99B0 and 0x820D9A78, no thunk, flags
    // 0x10000001). The bounded scheduler records them exactly like the
    // earlier workers; the asynchronous worker routines are never executed.
    // Observed creation flags pin each worker to its own hardware thread
    // (0x10000001 and 0x20000001) and create it suspended.
    if (ctx.r4.u32!=0u || ctx.r5.u32!=0u || ctx.r6.u32!=0u ||
        ctx.r8.u32!=0u ||
        (ctx.r9.u32!=0x10000001u && ctx.r9.u32!=0x20000001u) ||
        base.thread_count>=base.threads.size())
      base.fail(Error::unsupported,0x8214A5E4u);
    auto &t=base.threads[base.thread_count];
    t.allocated=true; t.suspended=true; t.runnable=false;
    t.handle=0xF1000001u+base.thread_count; t.object=0xF2000001u+base.thread_count;
    t.startup_thunk=0u; t.start_routine=ctx.r7.u32; t.parameter=0u;
    t.priority=0; t.affinity=0x3fu; ++base.thread_count;
    base.store(out_handle,4,t.handle); ctx.r3.s64=0; return;
  }
  if (ctx.r7.u32 == 0x82070828u && ctx.r6.u32 == 0x820B79B8u) {
    // WIP 022: creation of the game's main-loop thread (start routine
    // 0x82070828 through the standard thunk). Recorded suspended like every
    // other worker; the asynchronous routine itself is not run by the
    // diagnostic.
    if (ctx.r4.u32!=0u || ctx.r8.u32!=0u || ctx.r9.u32!=1u ||
        base.thread_count>=base.threads.size())
      base.fail(Error::unsupported,0x8214A5E4u);
    auto &t=base.threads[base.thread_count];
    t.allocated=true; t.suspended=true; t.runnable=false;
    t.handle=0xF1000001u+base.thread_count; t.object=0xF2000001u+base.thread_count;
    t.startup_thunk=ctx.r6.u32; t.start_routine=ctx.r7.u32; t.parameter=ctx.r8.u32;
    t.priority=0; t.affinity=0x3fu; ++base.thread_count;
    base.store(out_handle,4,t.handle); ctx.r3.s64=0; return;
  }
  if (ctx.r6.u32 != 0x820B79B8u)
    base.fail(Error::unsupported, 0x8214A5E4u);
  if (ctx.r7.u32 == 0x820B0E80u) {
    if (ctx.r4.u32 != 0u || ctx.r5.u32 != 0u || ctx.r8.u32 >= 5u || ctx.r9.u32 != 1u ||
        base.thread_count != ctx.r8.u32 || base.thread_count >= 5u)
      base.fail(Error::unsupported, 0x8214A5E4u);
    auto &t=base.threads[base.thread_count];
    t.allocated=true; t.suspended=true; t.runnable=false;
    t.handle=0xF1000001u+base.thread_count; t.object=0xF2000001u+base.thread_count;
    t.startup_thunk=ctx.r6.u32; t.start_routine=ctx.r7.u32; t.parameter=ctx.r8.u32;
    t.priority=0; t.affinity=0x3fu; ++base.thread_count;
    base.store(out_handle,4,t.handle); ctx.r3.s64=0; return;
  }
  if (ctx.r7.u32 == 0x820D7578u) {
    static constexpr uint32_t records[2]={0x02002D5Cu,0x02002DACu};
    if (base.thread_count>=2u || ctx.r4.u32!=0x10000u || ctx.r9.u32!=0u ||
        ctx.r8.u32!=records[base.thread_count] || ctx.r5.u32!=ctx.r8.u32+52u)
      base.fail(Error::unsupported,0x8214A5E4u);
    auto &t=base.threads[base.thread_count];
    t.allocated=true; t.suspended=false; t.runnable=true;
    t.handle=0xF1000001u+base.thread_count; t.object=0xF2000001u+base.thread_count;
    t.startup_thunk=ctx.r6.u32; t.start_routine=ctx.r7.u32; t.parameter=ctx.r8.u32;
    t.priority=0; t.affinity=0x3fu; ++base.thread_count;
    base.store(out_handle,4,t.handle); ctx.r3.s64=0; return;
  }
  // WIP 023: any other thread started through the title's standard thread
  // thunk (0x820B79B8) - the system notification poller, voice and Live
  // workers - is recorded with its creation flags and never run: this
  // single-threaded diagnostic services only the game threads modelled
  // above, and these threads would never be woken (offline, nobody signs
  // in). Creation flag bit 0 = create suspended.
  if (ctx.r6.u32 == 0x820B79B8u && ctx.r7.u32 >= 0x82000000u && ctx.r7.u32 < 0x82150000u &&
      base.thread_count < base.threads.size()) {
    auto &t=base.threads[base.thread_count];
    t.allocated=true; t.suspended=(ctx.r9.u32 & 1u)!=0u; t.runnable=!t.suspended;
    t.handle=0xF1000001u+base.thread_count; t.object=0xF2000001u+base.thread_count;
    t.startup_thunk=ctx.r6.u32; t.start_routine=ctx.r7.u32; t.parameter=ctx.r8.u32;
    t.priority=0; t.affinity=0x3fu; ++base.thread_count;
    cc_log("thread created start=%08x param=%08x flags=%08x\n",
           ctx.r7.u32, ctx.r8.u32, ctx.r9.u32);
    base.store(out_handle,4,t.handle);
    if (!t.suspended) cc_run_thread_until_block(base, ctx.r7.u32, ctx.r8.u32, ctx.r13.u32);
    ctx.r3.s64=0; return;
  }
  base.fail(Error::unsupported,0x8214A5E4u);
}
static void __imp__ObReferenceObjectByHandle(Context& ctx, Machine& base) {
  auto *t=base.by_handle(ctx.r3.u32);
  if (!t || ctx.r4.u32 != 0x0001001Bu || ctx.r5.u32 > 0xfffffffbu)
    base.fail(Error::unsupported, 0x8214A474u);
  base.store(ctx.r5.u32,4,t->object);
  ctx.r3.s64=0;
}
static void __imp__KeSetBasePriorityThread(Context& ctx, Machine& base) {
  auto *t=base.by_object(ctx.r3.u32);
  const bool startup=t && t->start_routine==0x820B0E80u && ctx.r4.s32==-1;
  const bool graphics=t && t->start_routine==0x820D7578u && ctx.r4.s32==17;
  // WIP 022: the exact audio workers are raised to base priority 15, and the
  // main-loop thread to base priority 1.
  const bool audio=t && (t->start_routine==0x820D99B0u ||
                         t->start_routine==0x820D9A78u) && ctx.r4.s32==15;
  const bool mainloop=t && t->start_routine==0x82070828u && ctx.r4.s32==1;
  const bool generic=t && t->start_routine!=0x820B0E80u && t->start_routine!=0x820D7578u &&
                     t->start_routine!=0x820D99B0u && t->start_routine!=0x820D9A78u &&
                     t->start_routine!=0x82070828u && ctx.r4.s32>=-16 && ctx.r4.s32<=31;
  if (!startup && !graphics && !audio && !mainloop && !generic)
    base.fail(Error::unsupported, 0x8214A464u);
  const int32_t old=t->priority; t->priority=ctx.r4.s32; ctx.r3.s64=old;
}
static void __imp__ObDereferenceObject(Context& ctx, Machine& base) {
  if (!base.by_object(ctx.r3.u32))
    base.fail(Error::unsupported, 0x8214A454u);
  ctx.r3.u64=0;
}
static void __imp__KeSetAffinityThread(Context& ctx, Machine& base) {
  auto *t=base.by_object(ctx.r3.u32);
  const bool known=t && t->start_routine==0x820B0E80u;
  const uint32_t expected=t ? (1u << (t->parameter+1u)) : 0u;
  if (!t || (known && ctx.r4.u32 != expected) || ctx.r4.u32 == 0u || ctx.r4.u32 > 0x3Fu ||
      ctx.r5.u32 > 0xfffffffbu)
    base.fail(Error::unsupported, 0x8214A484u);
  base.store(ctx.r5.u32,4,t->affinity);
  t->affinity=ctx.r4.u32;
  ctx.r3.s64=0;
}
static void __imp__NtResumeThread(Context& ctx, Machine& base) {
  auto *t=base.by_handle(ctx.r3.u32);
  if (!t || !t->suspended || ctx.r4.u32 > 0xfffffffbu)
    base.fail(Error::unsupported, 0x8214A4C4u);
  base.store(ctx.r4.u32,4,1u);
  t->suspended=false;
  t->runnable=true;
  ctx.r3.s64=0;
}

// WIP 021: the shader loader's SobelEdge.xpu miss legitimately reaches the
// exact error-translation wrapper, so it is now executed byte-exact. The
// trusted RtlNtStatusToDosError contract accepts only the observed
// STATUS_OBJECT_NAME_NOT_FOUND and maps it to ERROR_FILE_NOT_FOUND.
static void __imp__RtlNtStatusToDosError(Context& ctx, Machine& base) {
  if (ctx.r3.u32 != 0xC0000034u)
    base.fail(Error::unsupported, 0x8214A4E4u);
  ctx.r3.u64 = 2u;
}
#include "generated/sub_820B7290.inc"

#include "generated/sub_820B7350.inc"
#include "generated/sub_820B73C0.inc"
#include "generated/sub_820B5D60.inc"
#include "generated/sub_820B5D70.inc"
#include "generated/sub_820B5E08.inc"
#include "generated/sub_820B6028.inc"
#include "generated/sub_8209D688.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/sub_820701D0_startup_full.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif

// Checkpoint 017 caller-prefix closure. The original caller reaches this code
// only after the complete sub_820701D0 startup initializer. Unused branches in
// sub_8209A728 remain hard boundaries; the observed r3=0 path does not enter them.
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savegprlr_18.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restgprlr_18.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif

#define HARD_BOUNDARY_017(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { \
    base.fail(Error::unsupported, addr); \
  }
static void __imp__RtlEnterCriticalSection(Context& ctx, Machine& base) {
  // Critical sections created by exact code through the bounded
  // RtlInitializeCriticalSection contract: single-thread diagnostic, so a
  // registered CS may simply toggle. Recursion is not observed and fails.
  for (unsigned i=0;i<g_registered_cs_count;++i) {
    if (g_registered_cs[i]==ctx.r3.u32 && ctx.r3.u32) {
      if (g_registered_cs_locked[i]) base.fail(Error::unsupported,0x8214A434u);
      g_registered_cs_locked[i]=true; ctx.r3.u64=0; return;
    }
  }
  if (base.tile_allocator && ctx.r3.u32 == base.tile_allocator) {
    if (base.tile_cs_locked) base.fail(Error::unsupported,0x8214A434u);
    base.tile_cs_locked=true; ctx.r3.u64=0; return;
  }
  // WIP 023: the CRT's static lock table lives in image .data at
  // 0x821500C0.. (same page as the two pre-seeded CRT locks); these
  // critical sections are image-initialized and never pass through
  // RtlInitializeCriticalSection. First entry registers them with the
  // same single-threaded toggle semantics; anything outside that page
  // still requires an observed initialization.
  if (ctx.r3.u32>=0x82150000u && ctx.r3.u32<0x82152000u &&
      g_registered_cs_count<64u) {
    const unsigned i=g_registered_cs_count++;
    g_registered_cs[i]=ctx.r3.u32;
    g_registered_cs_locked[i]=true;
    ctx.r3.u64=0; return;
  }
  const uint32_t hsio_slot=uint32_t(base.load(0x82000594u,4));
  if (!hsio_slot || ctx.r3.u32!=hsio_slot || base.hsio_cs_locked || base.critical_region_depth!=1u)
    base.fail(Error::unsupported,0x8214A434u);
  base.hsio_cs_locked=true; ctx.r3.u64=0;
}
static void __imp__RtlLeaveCriticalSection(Context& ctx, Machine& base) {
  for (unsigned i=0;i<g_registered_cs_count;++i) {
    if (g_registered_cs[i]==ctx.r3.u32 && ctx.r3.u32) {
      if (!g_registered_cs_locked[i]) base.fail(Error::unsupported,0x8214A444u);
      g_registered_cs_locked[i]=false; ctx.r3.u64=0; return;
    }
  }
  if (base.tile_allocator && ctx.r3.u32 == base.tile_allocator) {
    if (!base.tile_cs_locked) base.fail(Error::unsupported,0x8214A444u);
    base.tile_cs_locked=false; ctx.r3.u64=0; return;
  }
  const uint32_t hsio_slot=uint32_t(base.load(0x82000594u,4));
  if (!hsio_slot || ctx.r3.u32!=hsio_slot || !base.hsio_cs_locked || base.critical_region_depth!=1u)
    base.fail(Error::unsupported,0x8214A444u);
  base.hsio_cs_locked=false; ctx.r3.u64=0;
}
#include "generated/sub_820B6498.inc"
#undef HARD_BOUNDARY_017

#if defined(CC_FAST)
#define sub_8209A728 sub_8209A728_exact
#endif
#include "generated/sub_8209A728.inc"
#if defined(CC_FAST)
#undef sub_8209A728
// Direct level load (diagnostic; Xbox: make LEVEL=<n>, host: CC_LEVEL=<n>):
// see the sub_82076758 wrapper.
static uint32_t cc_direct_level() {
#if defined(CC_DIRECT_LEVEL)
  return uint32_t(CC_DIRECT_LEVEL);
#elif !defined(CC_XBOX_DRIVER)
  static const uint32_t n = [] { const char* e = std::getenv("CC_LEVEL"); return e ? uint32_t(std::strtoul(e, nullptr, 10)) : 0u; }();
  return n;
#else
  return 0u;
#endif
}
static void sub_8209A728(Context& ctx, Machine& base) {
  // Direct level load: the BSP of the first level ("bsp2") is requested by
  // name like the level itself; it becomes "bsp<n>" (scratch copy).
  if (const uint32_t lvl = cc_direct_level(); lvl && ctx.r3.u32) {
    char name[16] = {};
    for (uint32_t k = 0; k < 15u; ++k) { name[k] = char(base.load(ctx.r3.u32 + k, 1)); if (!name[k]) break; }
    if (std::strcmp(name, "bsp2") == 0) {
      char repl[16] = {};
      std::snprintf(repl, sizeof(repl), "bsp%u", lvl);
      constexpr uint32_t scratch = 0x02500440u;
      for (uint32_t k = 0; k < 16u; ++k) base.store(scratch + k, 1, uint8_t(repl[k]));
      cc_log("direct_level %s -> %s\n", name, repl);
      ctx.r3.u64 = scratch;
    }
  }
  sub_8209A728_exact(ctx, base);
}
#else
static uint32_t cc_direct_level() { return 0u; }
#endif
// The play build skips the "Sign In To Xbox LIVE" notice after the game-mode
// book (see the sub_82053BC8 wrapper); host CC_LIVE_NOTICE=1 keeps it.
[[maybe_unused]] static bool cc_skip_live_notice() {
#if !defined(CC_FAST)
  return false;
#elif !defined(CC_XBOX_DRIVER)
  static const bool keep = std::getenv("CC_LIVE_NOTICE") != nullptr;
  return !keep;
#else
  return true;
#endif
}
#include "generated/sub_8209B458.inc"
#include "generated/sub_820A7668.inc"

// Adapter used by the diagnostic caller slice. The body it invokes is the exact
// original startup initializer already provenance-checked above.
static void sub_820701D0(Context& ctx, Machine& base) {
  sub_820701D0_startup_full(ctx, base);
}
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/sub_82070AC8_renderer_prefix.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif

// PlatformRenderer::Init entry. The shim returns one deterministic standard
// 640x480/60-Hz mode descriptor; the exact original code consumes it and builds
// its presentation parameters. The prefix then stops immediately before the
// first graphics-device helper (sub_820BEFD0).
static void __imp__XGetVideoMode(Context& ctx, Machine& base) {
  const uint32_t p=ctx.r3.u32;
  if (p > 0xffffffd0u) base.fail(Error::context,0x8214A214u);
  for (unsigned i=0;i<48;++i) base.store(p+i,1,0);
  base.store(p+0,4,640u);
  base.store(p+4,4,480u);
  base.store(p+20,4,0x42700000u); // 60.0f
  base.store(p+24,4,1u);          // deterministic non-PAL standard token
  ctx.r3.u64=0;
}
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/sub_820A7990_platform_prefix.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/sub_820A7990_platform_post_graphics.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_820A85E8.inc"



// Checkpoint 019: graphics/runtime platform boundary. Game-side device/ring setup
// remains exact generated code; only loader/kernel/runtime contracts are modeled.
static void sub_82136670(Context& ctx, Machine& base) {
  const uint32_t p=base.graphics_allocate(ctx.r3.u32,ctx.r4.u32);
  if (p != 0xFFFFFFFFu) { ctx.r3.u64=p; return; }
  // General allocation (see graphics_allocate): zero-filled, 16-byte aligned,
  // page-aligned from 4 KiB up, bounded to 16 MiB per call.
  const uint32_t size=ctx.r3.u32;
  if (size == 0u || size > 0x01000000u) base.fail(Error::unsupported,0x82136670u);
  g_phys_tag=uint32_t(ctx.lr);
  const uint32_t q=cc_phys_alloc(base,size,size>=0x1000u?0x1000u:16u);
  for (uint32_t i=0;i<((size+3u)&~3u);i+=4u) base.memory.store_be(q+i,4,0u);
  ctx.r3.u64=q;
}
static void sub_82136708(Context& ctx, Machine& base) {
  // Graphics/audio allocator free (pair of sub_82136670). Startup frees
  // null pointers; from the level load on, the audio code frees blocks it
  // allocated. The fixture allocator is a bump cursor, so a free of a block
  // it handed out is accepted without reuse; anything else fails closed.
  if (ctx.r3.u32 == 0u) { ctx.r3.u64 = 0; return; }
  if (ctx.r3.u32 >= 0x12000000u && ctx.r3.u32 < 0x20000000u) {
    if (!cc_phys_free(base, ctx.r3.u32)) base.fail(Error::unsupported,0x82136708u);
    ctx.r3.u64 = 0; return;
  }
  if (ctx.r3.u32 < 0x02000000u || ctx.r3.u32 >= g_graphics_alloc_cursor)
    base.fail(Error::unsupported,0x82136708u);
  ctx.r3.u64=0;
}
static void __imp__KeGetCurrentProcessType(Context& ctx, [[maybe_unused]] Machine& base) {
  ctx.r3.u64=1u; // normal title process, not the process-type-2 system path
}
static void __imp__VdInitializeEngines(Context& ctx, Machine& base) {
  if (base.graphics_engines_initialized || ctx.r3.u32!=0x1DDD0000u ||
      ctx.r4.u32!=0x820CB900u || ctx.r5.u32!=0u ||
      ctx.r6.u32!=0x82005820u || ctx.r7.u32!=0x82005CA0u)
    base.fail(Error::unsupported,0x8214A8A4u);
  base.graphics_engines_initialized=true; ctx.r3.u64=0;
}
static void __imp__ExRegisterTitleTerminateNotification(Context& ctx, Machine& base) {
  // WIP 022: the exact audio-driver init registers its own static terminate
  // record from the image's data segment; accept exactly that one in
  // addition to the two checkpoint-017 graphics records.
  if (ctx.r3.u32==0x8223595Cu && ctx.r4.u32==1u) { ctx.r3.u64=0; return; }
  const uint32_t want = base.terminate_notifications==0 ? 0x821508E0u : 0x821508F0u;
  if (!base.graphics_engines_initialized || base.terminate_notifications>=2u ||
      ctx.r3.u32!=want || ctx.r4.u32!=1u)
    base.fail(Error::unsupported,0x8214A844u);
  ++base.terminate_notifications; ctx.r3.u64=0;
}
static void __imp__VdSetGraphicsInterruptCallback(Context& ctx, Machine& base) {
  if (!base.graphics_engines_initialized || base.terminate_notifications!=2u ||
      ctx.r3.u32!=0x820C60E0u || ctx.r4.u32<0x02000000u || ctx.r4.u32>=0x02240000u)
    base.fail(Error::unsupported,0x8214A894u);
  base.graphics_interrupt_installed=true; ctx.r3.u64=0;
}
static void __imp__VdSetSystemCommandBufferGpuIdentifierAddress(Context& ctx, Machine& base) {
  if (!base.system_identifier_cleared) {
    if (ctx.r3.u32!=0u) base.fail(Error::unsupported,0x8214A7F4u);
    base.system_identifier_cleared=true; ctx.r3.u64=0; return;
  }
  if (!base.ring_writeback_enabled || base.system_identifier_set ||
      !base.ring_descriptor || ctx.r3.u32!=base.ring_descriptor+8u)
    base.fail(Error::unsupported,0x8214A7F4u);
  base.system_identifier_set=true; ctx.r3.u64=0;
}
// WIP 023: the music streamer creates one XMA hardware-decoder context
// (lr=0x820DAE18). The fixture hands out a zeroed 64-byte context block
// from the graphics cursor arena and reports success; decode progress
// stays fail-closed until the exact code is observed polling it. The
// original-Xbox port will replace XMA with pre-converted audio.
static std::vector<uint32_t> g_xma_contexts;
static void __imp__XMACreateContext(Context& ctx, Machine& base) {
  const uint32_t out = ctx.r3.u32;
  if (!out) base.fail(Error::unsupported, 0x8214AC54u);
  const uint32_t p = (g_graphics_alloc_cursor + 15u) & ~15u;
  if (base.memory.check(p, 64u, 3) != cc::xbox::MemoryError::ok)
    base.fail(Error::memory, p);
  g_graphics_alloc_cursor = p + 64u;
  for (uint32_t i = 0; i < 64u; i += 4u) base.store(p + i, 4, 0u);
  base.store(out, 4, p);
  g_xma_contexts.push_back(p);
  ctx.r3.u64 = 0u;
}
// Audio is stubbed by port policy: releasing a fixture decoder context only
// forgets it. A pointer this fixture never handed out stays fail-closed.
static void __imp__XMAReleaseContext(Context& ctx, Machine& base) {
  for (size_t i = 0; i < g_xma_contexts.size(); ++i)
    if (g_xma_contexts[i] == ctx.r3.u32) {
      g_xma_contexts.erase(g_xma_contexts.begin() + i);
      ctx.r3.u64 = 0u;
      return;
    }
  base.fail(Error::unsupported, 0x8214AC44u);
}
static void __imp__MmGetPhysicalAddress(Context& ctx, Machine& base) {
  if (g_graphics_alloc_index==6u && base.ring_virtual && ctx.r3.u32==base.ring_virtual) {
    // The bounded fixture maps its graphics arena in low guest memory, so the
    // physical token is the low 29-bit address used by this original path.
    base.ring_physical=ctx.r3.u32 & 0x1FFFFFFFu;
    ctx.r3.u64=base.ring_physical;
    return;
  }
  // WIP 023: the XMA/music driver translates its graphics-arena work
  // buffers for DMA (lr=0x820DA350). The whole fixture arena is an
  // identity-style low mapping, so the same 29-bit contract applies to
  // any address inside the mapped graphics/physical arenas.
  if ((ctx.r3.u32>=0x02000000u && ctx.r3.u32<0x02400000u+0x00400000u) ||
      (ctx.r3.u32>=0x12000000u && ctx.r3.u32<0x20000000u)) {
    ctx.r3.u64 = ctx.r3.u32 & 0x1FFFFFFFu;
    return;
  }
  base.fail(Error::unsupported,0x8214A7E4u);
}
static void __imp__VdInitializeRingBuffer(Context& ctx, Machine& base) {
  if (!base.graphics_engines_initialized || !base.ring_physical ||
      ctx.r3.u32!=base.ring_physical || ctx.r4.u32!=12u)
    base.fail(Error::unsupported,0x8214A7D4u);
  base.ring_initialized=true; ctx.r3.u64=0;
}
static void __imp__VdEnableRingBufferRPtrWriteBack(Context& ctx, Machine& base) {
  if (!base.ring_initialized || !base.ring_descriptor)
    base.fail(Error::unsupported,0x8214A7C4u);
  uint32_t q=base.ring_descriptor+60u;
  uint64_t t=__builtin_rotateleft64(uint64_t(q) | (uint64_t(q)<<32),12) & 0xFFFu;
  t=(t+512u) & 0xffffffffu;
  t=__builtin_rotateleft64(uint64_t(uint32_t(t)) | (uint64_t(uint32_t(t))<<32),0) & 0x1000u;
  const uint32_t want=uint32_t(t)+(q & 0x1FFFFFFFu);
  if (ctx.r3.u32!=want) base.fail(Error::unsupported,0x8214A7C4u);
  base.ring_writeback_enabled=true; ctx.r3.u64=0;
}

#define HARD_BOUNDARY_019(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, addr); }
HARD_BOUNDARY_019(sub_820CC318,0x820CC318u)
HARD_BOUNDARY_019(sub_820BECA0,0x820BECA0u)
#include "generated/sub_820C7458.inc"
HARD_BOUNDARY_019(sub_820C7A98,0x820C7A98u)
#undef HARD_BOUNDARY_019

// Checkpoint 020: exact late device-finalization path. The game-side EDRAM
// routine is byte-exact generated code. Only the kernel/platform exports are
// modeled here, and only for the observed sub_820CC100 call shape. Xenia's
// Xbox 360 kernel model reports VdRetrainEDRAMWorker/VdRetrainEDRAM as zero
// and VdIsHSIOTrainingSucceeded as one; unexpected ordering/arguments fail.
static void __imp__KeEnterCriticalRegion(Context& ctx, Machine& base) {
  if (base.critical_region_depth!=0u || base.hsio_cs_locked || base.edram_retrain_calls!=0u)
    base.fail(Error::unsupported,0x8214A924u);
  base.critical_region_depth=1u; ctx.r3.u64=0;
}
static void __imp__KeLeaveCriticalRegion(Context& ctx, Machine& base) {
  const bool checkpoint020_complete =
      !base.edram_suffix021_shape && base.edram_worker_calls==1u &&
      base.edram_retrain_calls==1u;
  const bool suffix021_complete =
      base.edram_suffix021_shape && base.edram_worker_calls==0u &&
      base.edram_retrain_calls==1u;
  const bool frame022_complete =
      base.edram_frame022_shape && base.edram_worker_calls==0u &&
      base.edram_retrain_calls==1u;
  if (base.critical_region_depth!=1u || base.hsio_cs_locked ||
      (!checkpoint020_complete && !suffix021_complete && !frame022_complete))
    base.fail(Error::unsupported,0x8214A8F4u);
  // WIP 023: the present path runs Enter -> VdRetrainEDRAM -> Leave once per
  // frame from the same sub_820D19E8 call sites. A completed frame/suffix
  // shape re-arms the sequence for the next frame; the Checkpoint 020
  // worker-assisted init sequence stays one-shot.
  if (suffix021_complete || frame022_complete) {
    base.edram_retrain_calls=0u;
    base.edram_suffix021_shape=false;
    base.edram_frame022_shape=false;
  }
  base.critical_region_depth=0u; ctx.r3.u64=0;
}
static void __imp__VdRetrainEDRAMWorker(Context& ctx, Machine& base) {
  if (ctx.r3.u32!=0u || base.critical_region_depth!=1u || !base.hsio_cs_locked ||
      base.edram_worker_calls!=0u || base.edram_retrain_calls!=0u ||
      base.edram_suffix021_shape)
    base.fail(Error::unsupported,0x8214A914u);
  ++base.edram_worker_calls; ctx.r3.u64=0u;
}
static void __imp__VdRetrainEDRAM(Context& ctx, Machine& base) {
  const uint32_t sp=ctx.r1.u32;
  const bool checkpoint020_shape =
      ctx.r3.u32==1u && ctx.r4.u32==sp+80u && ctx.r5.u32==4096u &&
      ctx.r6.u32==sp+84u && ctx.r7.u32==sp+96u && ctx.r8.u32==2048u &&
      base.edram_worker_calls==1u && !base.edram_suffix021_shape;
  // WIP 021: bind the later PlatformRenderer::Init suffix invocation separately
  // rather than broadening the sealed Checkpoint 020 contract. This exact call
  // skips VdRetrainEDRAMWorker because sub_820C0DA8 passes r5=0 to sub_820D19E8.
  const bool suffix021_shape =
      sp==0x0003E210u && uint32_t(ctx.lr)==0x820D1A48u &&
      ctx.r3.u32==0u && ctx.r4.u32==0x0003E260u && ctx.r5.u32==4096u &&
      ctx.r6.u32==0x0003E264u && ctx.r7.u32==0x0003E270u && ctx.r8.u32==2048u &&
      ctx.r9.u32==0x02012320u && ctx.r10.u32==0x0201231Cu &&
      ctx.r11.u32==0u && ctx.r12.u32==0x820C1318u &&
      base.edram_worker_calls==0u && !base.edram_suffix021_shape;
  // WIP 022: the post-Init frame's present path re-enters sub_820D19E8 on its
  // own stack (again with r5=0 skipping the worker), issuing the same
  // r1-relative retrain shape as the WIP 021 suffix from the same call site.
  const bool frame022_shape =
      uint32_t(ctx.lr)==0x820D1A48u &&
      ctx.r3.u32==0u && ctx.r4.u32==sp+80u && ctx.r5.u32==4096u &&
      ctx.r6.u32==sp+84u && ctx.r7.u32==sp+96u && ctx.r8.u32==2048u &&
      base.edram_worker_calls==0u && !base.edram_suffix021_shape;
  if (base.critical_region_depth!=1u || !base.hsio_cs_locked ||
      base.edram_retrain_calls!=0u ||
      (!checkpoint020_shape && !suffix021_shape && !frame022_shape) ||
      uint32_t(base.load(ctx.r4.u32,4))!=0u || uint32_t(base.load(ctx.r6.u32,4))!=0u)
    base.fail(Error::unsupported,0x8214A904u);
  // The Xbox 360 kernel model returns zero and leaves the caller-owned output
  // words/workspace untouched. Zero selects the exact original success branch.
  base.edram_suffix021_shape=suffix021_shape;
  base.edram_frame022_shape=frame022_shape;
  ++base.edram_retrain_calls; ctx.r3.u64=0u;
}
#include "generated/sub_820D19E8.inc"
#include "generated/sub_820BDE48.inc"
static void __imp__VdIsHSIOTrainingSucceeded(Context& ctx, Machine& base) {
  if (base.critical_region_depth!=0u || base.hsio_cs_locked ||
      base.edram_worker_calls!=1u || base.edram_retrain_calls!=1u ||
      base.hsio_status_calls!=0u)
    base.fail(Error::unsupported,0x8214A8B4u);
  ++base.hsio_status_calls; ctx.r3.u64=1u;
}
#include "generated/sub_820D1C08.inc"


// Checkpoint 019: deterministic VdQueryVideoMode contract for the exact
// 640x480/60 host platform fixture already consumed by PlatformRenderer::Init.
// The X_VIDEO_MODE layout is 48 bytes; only fields consumed on this path are
// populated. Unknown mode shapes remain fail-closed.
static void __imp__VdQueryVideoMode(Context& ctx, Machine& base) {
  const bool contiguous = !base.video_mode_queried && ctx.r3.u32 == 0x0003e5a0u;
  bool resumed = false;
  if (!contiguous && !base.video_mode_queried && base.video_flags_queried && base.system_command_buffer_queried &&
      base.vd_swap_called && base.display_mode_set && base.display_info_queried &&
      ctx.r1.u32==0x0003dec0u && ctx.lr==0x820D129Cu &&
      ctx.r3.u32==ctx.r1.u32+112u && ctx.r3.u32==0x0003df30u &&
      ctx.r28.u32==0x02000080u && ctx.r31.u32==0u &&
      ctx.r29.u32==0x028001e0u && ctx.r27.u32==0u &&
      ctx.r26.u32==0x050002d0u && ctx.r20.u32==0x028001e0u &&
      ctx.r15.u32==0x0003e084u && ctx.r14.u32==0x0003e0acu) {
    const uint32_t dev=ctx.r28.u32;
    resumed = uint32_t(base.load(dev+21544u,4))==1280u &&
              uint32_t(base.load(dev+21548u,4))==720u &&
              uint32_t(base.load(dev+21552u,4))==1280u;
  }
  // Exact later refresh performed by sub_820CF728. This is a second video-mode
  // query, so it is keyed to the complete observed suffix state rather than the
  // one-shot initialization form above.
  bool cf728_refresh = false;
  if (!contiguous && !resumed && base.video_mode_queried && base.video_flags_queried &&
      base.system_command_buffer_queried && base.vd_swap_called && base.display_mode_set &&
      base.display_info_queried && base.scaler_command_buffer_initialized &&
      ctx.r1.u32==0x0003e9e0u && ctx.lr==0x820CF77Cu &&
      ctx.r3.u32==0x02005548u && ctx.r31.u32==0x02000080u &&
      ctx.r24.u32==0u && ctx.r30.u32==0x02211000u &&
      ctx.r29.u32==0x28280106u && ctx.r28.u32==640u &&
      ctx.r27.u32==480u && ctx.r26.u32==0x0200361cu && ctx.r25.u32==0x02003b1cu) {
    const uint32_t dev=ctx.r31.u32;
    cf728_refresh = uint32_t(base.load(dev+21544u,4))==1280u &&
                    uint32_t(base.load(dev+21548u,4))==720u &&
                    uint32_t(base.load(dev+21552u,4))==1280u &&
                    uint32_t(base.load(dev+48u,4))==0x020122dcu;
  }
  if (!contiguous && !resumed && !cf728_refresh)
    base.fail(Error::unsupported,0x8214A7A4u);
  for (uint32_t i=0;i<48u;i+=4u) base.store(ctx.r3.u32+i,4,0u);
  base.store(ctx.r3.u32+0u,4,640u);
  base.store(ctx.r3.u32+4u,4,480u);
  base.store(ctx.r3.u32+20u,4,0x42700000u); // 60.0f
  if (resumed || cf728_refresh) base.store(ctx.r3.u32+28u,4,0x0000004au);
  base.video_mode_queried=true;
}


static void __imp__VdGetCurrentDisplayGamma(Context& ctx, Machine& base) {
  if (base.display_gamma_queried || ctx.r3.u32>0xfffffffbu || ctx.r4.u32>0xfffffffbu)
    base.fail(Error::unsupported,0x8214A814u);
  // Xbox contract: type 1 = sRGB. Power is ignored by this type, but the
  // deterministic platform fixture reports Xenia's documented default.
  base.store(ctx.r3.u32,4,1u);
  base.store(ctx.r4.u32,4,0x400e38e4u);
  base.display_gamma_queried=true;
  ctx.r3.u64=0u;
}

static void __imp__VdQueryVideoFlags(Context& ctx, Machine& base) {
  // The API query itself is valid independently of XGetVideoMode. Most earlier
  // device-init use runs in one Machine invocation and therefore carries the
  // video_mode_queried marker. WIP 021 resumes the still-live original caller
  // through a fresh host Machine while preserving guest memory, so accept only
  // that one exact resumed call shape as the equivalent durable state.
  if (base.video_flags_queried)
    base.fail(Error::unsupported,0x8214A8C4u);
  const bool contiguous = base.video_mode_queried;
  bool resumed = false;
  if (!contiguous && ctx.r1.u32==0x0003DF70u && ctx.lr==0x820CFD30u &&
      ctx.r26.u32==0x02000080u && ctx.r31.u32==0x0200361Cu &&
      ctx.r4.u32==640u && ctx.r5.u32==480u) {
    const uint32_t dev=ctx.r26.u32;
    resumed = uint32_t(base.load(dev+21544u,4))==1280u &&
              uint32_t(base.load(dev+21548u,4))==720u &&
              uint32_t(base.load(dev+21552u,4))==1280u;
  }
  if (!contiguous && !resumed)
    base.fail(Error::unsupported,0x8214A8C4u);
  base.video_flags_queried=true;
  // Exact observed path consumes only bit 0; the trusted standard-mode fixture
  // reports no special flag.
  ctx.r3.u64=0u;
}
static void __imp__VdCallGraphicsNotificationRoutines(Context& ctx, Machine& base) {
  const uint32_t p=ctx.r4.u32;
  if (base.graphics_notification_sent || ctx.r3.u32!=1u || p>0xffffffc0u)
    base.fail(Error::unsupported,0x8214A8D4u);
  const uint16_t w=uint16_t(base.load(p+0u,2)), h=uint16_t(base.load(p+2u,2));
  const uint16_t dw=uint16_t(base.load(p+4u,2)), dh=uint16_t(base.load(p+6u,2));
  if (w!=640u || h!=480u || dw!=640u || dh!=480u)
    base.fail(Error::unsupported,0x8214A8D4u);
  base.graphics_notification_sent=true;
  ctx.r3.u64=0u;
}

// sub_820D62F8 contains PPC atomic/global-lock operations absent from the
// reduced host Context. Model only its exact fresh 6,144-tile allocator
// behavior reached by the sealed presentation path; unexpected requests fail.
static void sub_820D62F8(Context& ctx, Machine& base) {
  const uint32_t request=ctx.r3.u32, out=ctx.r4.u32;
  if (!base.video_mode_queried || request!=240u || out>0xfffffffbu)
    base.fail(Error::unsupported,0x820D62F8u);
  if (!base.tile_allocator) {
    const uint32_t p=base.graphics_allocate(804u,0x64800000u);
    base.tile_allocator=p;
    for (uint32_t i=0;i<804u;++i) base.store(p+i,1,0u);
    base.store(p+28u,4,6144u);
    base.store(p+800u,4,0x55555555u);
    base.store(0x8223191cu,4,p);
  }
  if (base.tile_next>6144u-request) base.fail(Error::unsupported,0x820D62F8u);
  const uint32_t start=base.tile_next;
  for (uint32_t i=0;i<request;++i) {
    const uint32_t tile=start+i, a=base.tile_allocator+32u+(tile/32u)*4u;
    uint32_t w=uint32_t(base.load(a,4));
    w |= 0x80000000u >> (tile%32u);
    base.store(a,4,w);
  }
  base.tile_next+=request;
  base.store(base.tile_allocator+28u,4,6144u-base.tile_next);
  base.store(out,4,start);
  ctx.r3.u64=1u;
}

#define HARD_RESOURCE_BOUNDARY_019(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, addr); }
HARD_RESOURCE_BOUNDARY_019(sub_820D62A8,0x820D62A8u)
// (sub_82136390 XMemCpy is now included exact, in the WIP 021 section)
HARD_RESOURCE_BOUNDARY_019(sub_820C90E0,0x820C90E0u)
HARD_RESOURCE_BOUNDARY_019(sub_820BDD78,0x820BDD78u)
#undef HARD_RESOURCE_BOUNDARY_019

static void __imp__KiApcNormalRoutineNop(Context& ctx, Machine& base) {
  if (ctx.r4.u32!=19u || ctx.r3.u32>0xffffffb3u)
    base.fail(Error::unsupported,0x8214A7B4u);
  static constexpr uint32_t fixed[] = {
    0xC0114800u,1023u,0u,0u
  };
  for (unsigned i=0;i<4;++i)
    if (uint32_t(base.load(ctx.r3.u32+i*4,4))!=fixed[i])
      base.fail(Error::unsupported,0x8214A7B4u);
  // Words 4..11 are copied verbatim by original code from sealed image
  // 0x8200176C; validate the copy instead of inventing their meaning.
  for (unsigned i=0;i<8;++i) {
    uint32_t a=uint32_t(base.load(0x8200176Cu+i*4,4));
    uint32_t b=uint32_t(base.load(ctx.r3.u32+(4u+i)*4,4));
    if (a!=b) base.fail(Error::unsupported,0x8214A7B4u);
  }
  if (uint32_t(base.load(ctx.r3.u32+48,4))!=0x00010800u ||
      uint32_t(base.load(ctx.r3.u32+52,4))!=7u)
    base.fail(Error::unsupported,0x8214A7B4u);
  for (unsigned i=14;i<19;++i)
    if (base.load(ctx.r3.u32+i*4,4)!=0) base.fail(Error::unsupported,0x8214A7B4u);
  // Xbox kernel export 479 is named KiApcNormalRoutineNop in the generated
  // import table. The bounded contract is therefore no observable mutation.
}

#include "generated/sub_82136728.inc"
#include "generated/sub_820BEF28.inc"
#include "generated/sub_820BEF80.inc"
#include "generated/sub_820CC088.inc"
#include "generated/sub_820CBFF0.inc"
#if defined(CC_XBOX_DRIVER) && defined(CC_FAST) && !defined(CC_XBOX_PROFILE)
#define sub_820C5EE8 sub_820C5EE8_exact
#endif
#include "generated/sub_820C5EE8.inc"
#if defined(CC_XBOX_DRIVER) && defined(CC_FAST) && !defined(CC_XBOX_PROFILE)
#undef sub_820C5EE8
// Xbox play build: the generated prologue is empty, so the hook this
// function needs (Machine::hooked_fast) runs here.
static void sub_820C5EE8(Context& ctx, Machine& base) { base.hooked_fast(4, ctx); sub_820C5EE8_exact(ctx, base); }
#endif
#include "generated/sub_820C5F98.inc"
#include "generated/sub_820C73F0.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/sub_820C7548.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_820BEAC8.inc"
#include "generated/sub_820D7708.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savegprlr_17.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restgprlr_17.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_820BF5E0.inc"
#include "generated/sub_820BF8D0.inc"
#include "generated/sub_820BF930.inc"
#include "generated/sub_820D7920.inc"

#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savegprlr_14.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restgprlr_14.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savegprlr_16.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restgprlr_16.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_820C2EF8.inc"
#include "generated/sub_820C2F80.inc"
#include "generated/sub_820C2E60.inc"
#include "generated/sub_820C30A0.inc"
#include "generated/sub_820C2DF0.inc"
#include "generated/sub_820C3EF8.inc"
#include "generated/sub_820C4210.inc"
#include "generated/sub_820C44A0.inc"
#include "generated/sub_820C45C0.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_26.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_26.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_820BB3B8.inc"
#include "generated/sub_820BD978.inc"
#include "generated/sub_820BDF40.inc"
#include "generated/sub_820BE1A8.inc"
#include "generated/sub_820BE248.inc"
#include "generated/sub_820BE2D8.inc"
#include "generated/sub_820BE620.inc"
#include "generated/sub_820CFD98.inc"
#include "generated/sub_820CFC70.inc"
#include "generated/sub_820CFE10.inc"
#include "generated/sub_820D1938.inc"
#include "generated/sub_820D19B8.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_28.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_28.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_8212AA90.inc"
#include "generated/sub_82130550.inc"
#include "generated/sub_8212DEE8.inc"
#include "generated/sub_8212DE48.inc"
#include "generated/sub_8212B1A8.inc"
#include "generated/sub_8212DE20.inc"
#include "generated/sub_8212AB00.inc"
#include "generated/sub_8212AC88.inc"
#include "generated/sub_820C8A90.inc"
#include "generated/sub_820C8B40.inc"
#include "generated/sub_820C8BF0.inc"
#include "generated/sub_820C8D78.inc"
#include "generated/sub_820C9090.inc"
#include "generated/sub_820BDCA8.inc"
#include "generated/sub_820CBBF0.inc"
#include "generated/sub_820CC100.inc"
#include "generated/sub_820BEFD0.inc"

// Checkpoint 020 exact GPU-state setter fanout and adjacent helpers.
#include "generated/sub_820BB6A8.inc"
#include "generated/sub_820BB6D8.inc"
#include "generated/sub_820BB708.inc"
#include "generated/sub_820BB740.inc"
#include "generated/sub_820BB7D0.inc"
#include "generated/sub_820BB860.inc"
#include "generated/sub_820BB8F0.inc"
#include "generated/sub_820BB980.inc"
#include "generated/sub_820BB9F0.inc"
#include "generated/sub_820BBA60.inc"
#include "generated/sub_820BBAD0.inc"
#include "generated/sub_820BBB68.inc"
#include "generated/sub_820BBBC8.inc"
#include "generated/sub_820BBBF8.inc"
#include "generated/sub_820BBCF8.inc"
#include "generated/sub_820BBD30.inc"
#include "generated/sub_820BBDA0.inc"
#include "generated/sub_820BBDD0.inc"
#include "generated/sub_820BBE10.inc"
#include "generated/sub_820BBE40.inc"
#include "generated/sub_820BBE78.inc"
#include "generated/sub_820BBEB8.inc"
#include "generated/sub_820BBEF0.inc"
#include "generated/sub_820BBF20.inc"
#include "generated/sub_820BBF58.inc"
#include "generated/sub_820BBF90.inc"
#include "generated/sub_820BBFC0.inc"
#include "generated/sub_820BBFF0.inc"
#include "generated/sub_820BC028.inc"
#include "generated/sub_820BC060.inc"
#include "generated/sub_820BC090.inc"
#include "generated/sub_820BC0B0.inc"
#include "generated/sub_820BC0D0.inc"
#include "generated/sub_820BC0F0.inc"
#include "generated/sub_820BC110.inc"
#include "generated/sub_820BC130.inc"
#include "generated/sub_820BC150.inc"
#include "generated/sub_820BC1A8.inc"
#include "generated/sub_820BC270.inc"
#include "generated/sub_820BC318.inc"
#include "generated/sub_820BC348.inc"
#include "generated/sub_820BC368.inc"
#include "generated/sub_820BC3A8.inc"
#include "generated/sub_820BC3E8.inc"
#include "generated/sub_820BC428.inc"
#include "generated/sub_820BC468.inc"
#include "generated/sub_820BC478.inc"
#include "generated/sub_820BC4D0.inc"
#include "generated/sub_820BC520.inc"
#include "generated/sub_820BC570.inc"
#include "generated/sub_820BC590.inc"
#include "generated/sub_820BC5B8.inc"
#include "generated/sub_820BC5E0.inc"
#include "generated/sub_820BC608.inc"
#include "generated/sub_820BC630.inc"
#include "generated/sub_820BC658.inc"
#include "generated/sub_820BC680.inc"
#include "generated/sub_820BC6A0.inc"
#include "generated/sub_820BC6C0.inc"
#include "generated/sub_820BC6E8.inc"
#include "generated/sub_820BC710.inc"
#include "generated/sub_820BC738.inc"
#include "generated/sub_820BC760.inc"
#include "generated/sub_820BC788.inc"
#include "generated/sub_820BC7B0.inc"
#include "generated/sub_820BC8D0.inc"
#include "generated/sub_820BC920.inc"
#include "generated/sub_820BC9B8.inc"
#include "generated/sub_820BCA50.inc"
#include "generated/sub_820BCAE8.inc"
#include "generated/sub_820BCB80.inc"
#include "generated/sub_820BCBB8.inc"
#include "generated/sub_820BCBF0.inc"
#include "generated/sub_820BCC28.inc"
#include "generated/sub_820BCC60.inc"
#include "generated/sub_820BCC90.inc"
#include "generated/sub_820BCCB8.inc"
#include "generated/sub_820BCCE8.inc"
#include "generated/sub_820BCD20.inc"
#include "generated/sub_820BCD50.inc"
#include "generated/sub_820BCD80.inc"
#include "generated/sub_820BCDA8.inc"
#include "generated/sub_820BCDD8.inc"
#include "generated/sub_820BCE08.inc"
#include "generated/sub_820BCE70.inc"
#include "generated/sub_820BCEA0.inc"
#include "generated/sub_820BCED0.inc"
#include "generated/sub_820BCF00.inc"
#include "generated/sub_820BCF20.inc"
#include "generated/sub_820BCF30.inc"
#include "generated/sub_820BCF50.inc"
#include "generated/sub_820BD050.inc"
#include "generated/sub_820BD0F8.inc"
#include "generated/sub_820BD1F8.inc"
#include "generated/sub_820BD298.inc"
#include "generated/sub_820BD2F0.inc"
#include "generated/sub_820BD398.inc"
#include "generated/sub_820BD410.inc"
#include "generated/sub_820BD4B8.inc"
#include "generated/sub_820BD558.inc"
#include "generated/sub_820BD5D8.inc"
#include "generated/sub_820BD658.inc"
#include "generated/sub_820BD6C8.inc"
#include "generated/sub_820BD718.inc"
#include "generated/sub_820BD768.inc"
#include "generated/sub_820BD7B8.inc"
#include "generated/sub_820BD810.inc"
#include "generated/sub_820BD868.inc"
#include "generated/sub_820BD8C0.inc"
#include "generated/sub_820BD918.inc"
#include "generated/sub_820BE198.inc"
#include "generated/sub_820CB988.inc"
#include "generated/sub_820C46F8.inc"
#include "generated/sub_820C9150.inc"
#include "generated/sub_820C0530.inc"
#include "generated/sub_820C0248.inc"
#include "generated/sub_820BF0A8.inc"
#include "generated/sub_820BF7B8.inc"

// Checkpoint 020 reduced-host implementation of exact sub_820C6088 semantics.
// The generated body uses PPC ldarx/stdcx plus MSR/global-lock helpers that the
// reduced Context intentionally does not model. On this single-threaded host
// fixture its observable contract is an atomic 64-bit exchange with
// 0x00000000FFFFFFFF, returning the old low/high words through r4/r5.
static void sub_820C6088(Context& ctx, Machine& base) {
  base.prologue(__func__,ctx);
  const uint32_t src=ctx.r3.u32, lo=ctx.r4.u32, hi=ctx.r5.u32;
  if (src>0xfffffff7u || lo>0xfffffffbu || hi>0xfffffffbu)
    base.fail(Error::context,0x820C6088u);
  const uint64_t old=base.load(src,8);
  base.store(src,8,0x00000000FFFFFFFFull);
  base.store(lo,4,uint32_t(old));
  base.store(hi,4,uint32_t(old>>32));
  ctx.r9.u64=old;
  ctx.r10.u64=old;
  ctx.r11.u64=uint32_t(old>>32);
}

// Compile-time fail-closed imports used only by deeper branches of this exact
// command-buffer family. A branch reaching one must establish its observed
// platform/CRT contract before execution can proceed.
static void cc_drain_workers(Machine& base, uint32_t r13) {
  {
    uint32_t jobs_run = 0;
    for (;;) {
      const uint32_t job = uint32_t(base.load(0x8228A770u, 4));
      if (!job) break;
      if (++jobs_run > 4096u) base.fail(Error::capacity, 0x8228A770u);
      base.store(0x8228A770u, 4, uint32_t(base.load(job, 4)));  // pop
      Context wctx{};
      wctx.r1.u32 = 0x00034000u;      // scratch worker stack top
      wctx.r13.u32 = r13;     // shared bounded thread block
      wctx.r3.u32 = job;
      wctx.lr = 0x820B0F08u;          // worker loop return site
      sub_820B1478(wctx, base);
      const uint32_t done = uint32_t(base.load(0x8228A764u, 4));
      base.store(job, 4, done);       // push onto completed list
      base.store(0x8228A764u, 4, job);
    }
  }
  // WIP 023 bounded loader-thread model: the suspended thread routine
  // sub_82070828 services the pak-mount request ring at [pool+0]/[pool+4]
  // (pool published at 0x8225E600): pop a key, exact sub_82096530(pool,
  // key) resolves/creates the record, and when its data pointer [rec+24]
  // is still null, exact sub_820960A8(pool, rec) performs the mount.
  // The same exact code runs here synchronously once per frame; only the
  // ring-head advance (done under the ring CS by the original loop) is
  // applied by the model, exactly as loc_820708B0 computes it.
  {
    const uint32_t pool = uint32_t(base.load(0x8225E600u, 4));
    if (pool) {
      uint32_t served = 0;
      for (;;) {
        const uint32_t tail = uint32_t(base.load(pool + 0u, 4));
        const uint32_t head = uint32_t(base.load(pool + 4u, 4));
        if (tail == head) break;
        if (++served > 64u) base.fail(Error::capacity, pool);
        const uint32_t key = uint32_t(base.load(pool + ((head + 2u) << 2), 4));
        Context wctx{};
        wctx.r1.u32 = 0x00034000u;
        wctx.r13.u32 = r13;
        wctx.r3.u32 = pool;
        wctx.r4.u32 = key;
        wctx.lr = 0x82070884u;        // loader loop return site
        sub_82096530(wctx, base);
        const uint32_t rec = wctx.r3.u32;
        if (rec && uint32_t(base.load(rec + 24u, 4)) == 0u) {
          Context mctx{};
          mctx.r1.u32 = 0x00034000u;
          mctx.r13.u32 = r13;
          mctx.r3.u32 = pool;
          mctx.r4.u32 = rec;
          mctx.lr = 0x820708A4u;
          sub_820960A8(mctx, base);
        }
        base.store(pool + 4u, 4, (head + 1u) % 32u);  // ring-head advance
      }
    }
  }
}
[[maybe_unused]] static const bool g_drain_workers_registered =
    (g_drain_workers = &cc_drain_workers, true);

// WIP 023 frame boundary. The main game loop paces itself with
// KeDelayExecutionThread(WaitMode=1, Alertable=0, Interval=&stack qword)
// from the exact Sleep wrapper sub_820B6068 (lr=0x820B7504). Each accepted
// call is one completed frame (update sub_82075C88 + render sub_820759A8 +
// VdSwap present + EDRAM retrain). The diagnostic runs a bounded number of
// frames, then stops fail-closed at this exact boundary with Error::capacity
// so the harness measures whole frames and never fakes an exit path.
static uint32_t g_frame_delay_calls = 0;
#if defined(CC_XBOX_DRIVER) && defined(CC_FAST) && !defined(CC_BENCH)
static bool g_main_loop_sleep = false;  // inside the main loop's Sleep (sub_820B6068 wrapper)
#endif
static constexpr uint32_t k_frame_budget_default = 10000;
// Host-only probe override: CC_FRAME_BUDGET=<n> stops the diagnostic after
// n frames. The Xbox build and the sealed test always use the default.
static uint32_t frame_budget() {
#ifndef CC_XBOX_DRIVER
  static uint32_t v = [] {
    const char* e = std::getenv("CC_FRAME_BUDGET");
    const unsigned long n = e ? std::strtoul(e, nullptr, 10) : 0ul;
    return n ? uint32_t(n) : k_frame_budget_default;
  }();
  return v;
#elif defined(CC_FAST)
  return 0xFFFFFFFFu;  // play build: the game runs until switched off
#else
  return k_frame_budget_default;
#endif
}
#ifdef CC_FAST
// Play build: the main menu's last item reads "Quit" (it leaves for the
// dashboard; see __imp__XamLoaderLaunchTitle). The English string of
// localized record 216, "Return to Arcade" (UTF-16 BE in the image at
// 0x8201545C), is overwritten in place once; the other languages keep
// their text. Not applied to the verification build.
static void cc_menu_text_patch(Machine& base) {
  static bool done = false;
  if (done) return;
  done = true;
  static const uint16_t quit[] = {'Q', 'u', 'i', 't', 0};
  for (unsigned i = 0; i < 5; ++i) base.memory.store_be(0x8201545Cu + 2u * i, 2, quit[i]);
}
#endif
static void __imp__KeDelayExecutionThread(Context& ctx, Machine& base) {
  cc_thread_block_point();  // a started system thread sleeping = blocked
  if (ctx.r3.u32 != 1u || ctx.r4.u32 != 0u || ctx.r5.u32 == 0u ||
      uint32_t(ctx.lr) != 0x820B7504u)
    base.fail(Error::unsupported, 0x8214A614u);
  const uint64_t interval_hi = base.load(ctx.r5.u32, 4);
  if ((interval_hi & 0x80000000u) == 0u)  // relative (negative) time only
    base.fail(Error::unsupported, 0x8214A614u);
  {
    // Advance KeTimeStampBundle (0x02500100) from the virtual timebase:
    // InterruptTime/SystemTime in 100 ns units, TickCount in milliseconds.
    const uint64_t t100ns = (base.timebase_virtual_ticks * 80ull) / 399ull;
    base.memory.store_be(0x02500100u, 8, t100ns);
    base.memory.store_be(0x02500108u, 8, 0x01C9000000000000ull + t100ns);
    base.memory.store_be(0x02500110u, 4, uint32_t(t100ns / 10000ull));
  }
#ifdef CC_XBOX_DRIVER
  const uint64_t fs_t0 = ::cc_xbox_clock(1000000u);
  g_slow.in = fs_t0;
  {
    static uint64_t last = 0;
    if (last) { g_fs_us[0] += fs_t0 - last; ++g_fs_frames; }
    last = fs_t0;
  }
#endif
  cc_audio_frame();
#ifdef CC_XBOX_DRIVER
  g_slow.aud = uint32_t(::cc_xbox_clock(1000000u) - fs_t0);
  g_fs_us[1] += g_slow.aud;
#endif
#ifdef CC_FAST
  cc_menu_text_patch(base);
#endif
#ifdef CC_XBOX_DRIVER
#ifdef CC_XBOX_PROFILE
  {
    static const cc::xbox::AddressSpace* mem = nullptr;
    mem = &base.memory;
    ::cc_xprof_frame([](uint32_t a, uint32_t* v) {
      uint64_t x = 0;
      if (!mem || mem->load_be(a, 4, x) != cc::xbox::MemoryError::ok) return false;
      *v = uint32_t(x); return true;
    });
  }
#endif
#ifdef CC_BENCH
  // Benchmark build: average frame, update and render time over fixed frame
  // windows of the scripted run (menu, level start, tavern, tavern later),
  // shown on screen once each window completes.
  {
    // With a direct level (make LEVEL=<n>, usually with FOURP=1) the windows
    // sit in the level's fights instead.
    static const unsigned lo_run[4] = {1800u, 5800u, 7300u, 8800u};
    static const unsigned lo_level[4] = {6600u, 7400u, 8200u, 9000u};
    const unsigned* const lo = cc_direct_level() ? lo_level : lo_run;
    static uint64_t last = 0, sum_f[4], sum_u[4], sum_r[4];
    static unsigned n[4];
    const uint64_t now = ::cc_xbox_clock(1000000u);
    const unsigned f = g_frame_delay_calls;
    for (unsigned w = 0; w < 4; ++w)
      if (f >= lo[w] && f < lo[w] + 400u && last) {
        sum_f[w] += now - last; sum_u[w] += g_frame_update_us; sum_r[w] += g_frame_render_us; ++n[w];
        if (n[w] == 400u) ::cc_xr_bench(w, n[w], unsigned(sum_f[w] / n[w]), unsigned(sum_u[w] / n[w]), unsigned(sum_r[w] / n[w]));
      }
    last = now;
  }
#endif
  g_fs_us[5] += g_frame_update_us; g_fs_us[6] += g_frame_render_us;
  {
    const uint64_t t = ::cc_xbox_clock(1000000u);
    ::cc_xr_frame_end(g_frame_update_us, g_frame_render_us);
    g_slow.end = uint32_t(::cc_xbox_clock(1000000u) - t);
    g_fs_us[2] += g_slow.end;
  }
  g_slow.upd = g_frame_update_us; g_slow.ren = g_frame_render_us;
  g_frame_update_us = g_frame_render_us = 0;
#if defined(CC_FAST) && !defined(CC_BENCH)
  // Game clock = real frame time. The main loop (sub_82070AC8) takes the
  // next update's step from f31 = this frame's update + render time,
  // clamped to 1/60..1/10 s afterwards; on the 360 its own sleep filled the
  // rest of a 1/60 s frame, so that matched the real frame. Here the
  // present above holds frames to two vblanks outside that measurement: a
  // 33 ms frame was stepped as 1/60 s, so the 30 fps movies advanced every
  // other frame and the game ran at half speed in light scenes (one frame
  // with the whole movie tick, the next with nothing). When the loop's own
  // Sleep led here (sub_820B6068, sub_820B74B0 and this hook leave f31
  // alone), f31 is replaced by the time since the previous present, rounded
  // to single precision as the loop's frsp does. CC_GAME_STEP builds keep
  // the old step.
  {
    static uint64_t last_present = 0;
    const uint64_t now = ::cc_xbox_clock(1000000u);
#ifndef CC_GAME_STEP
    // The scripted four-player benchmark (make FOURP=1) drives menus and
    // character select by frame numbers tuned on the old 1/60 s step, so it
    // keeps that step until its fight starts (cc_combat_loop holds each
    // fight action for two frames from then on).
#ifdef CC_SCRIPT_4P
    const bool real_step = g_frame_delay_calls >= (cc_direct_level() ? 6500u : 9400u);
#else
    const bool real_step = true;
#endif
    if (last_present && g_main_loop_sleep && real_step) ctx.f31.f64 = double(float(double(now - last_present) * 1e-6));
#endif
    last_present = now;
  }
#endif
#if defined(CC_FAST) && !defined(CC_BENCH)
  // Play build: the game's own frame pacing (it asks to sleep the rest of a
  // 1/60 s frame when it finished early; a late frame still asks for its
  // 2 ms minimum, which was always skipped).
  {
    // The Xbox renderer's present already holds frames to two vblanks (30
    // FPS); the game computed this sleep for a 1/60 s frame before that
    // wait, so honouring it as well stretched light frames to ~45 ms. Only
    // CC_GAME_SLEEP builds still sleep.
    const uint64_t interval = uint64_t(0) - base.load(ctx.r5.u32, 8);
#ifdef CC_GAME_SLEEP
    if (interval > 20000u) {
#else
    if (false) {
#endif
      const uint64_t t = ::cc_xbox_clock(1000000u);
      ::cc_xbox_sleep_100ns(interval);
      g_fs_us[3] += ::cc_xbox_clock(1000000u) - t;
    }
  }
  {
    // Frames well over the 30 FPS budget, one debug line each with their
    // parts in 0.1 ms: update, render, the rest of the game's main loop
    // between the previous frame boundary and this one (loop), audio, frame
    // end (overlay, GPU wait, present), what the game asked to sleep, and
    // the frame's script ops, custom calls, clip updates and heap allocs.
    static uint64_t last = 0;
    static uint32_t frame_no = 0;
    const uint64_t now = ::cc_xbox_clock(1000000u);
    const uint64_t asked = uint64_t(0) - base.load(ctx.r5.u32, 8);
    ++frame_no;
    const uint64_t outside = g_slow.out ? g_slow.in - g_slow.out : 0u;
    const uint32_t loop = outside > uint64_t(g_slow.upd) + g_slow.ren ? uint32_t(outside - g_slow.upd - g_slow.ren) : 0u;
    if (last && now - last > 45000u)
      ::DbgPrint("SLOW f=%u ms=%u upd=%u ren=%u loop=%u aud=%u end=%u ask=%u ops=%u calls=%u clips=%u allocs=%u\n", frame_no,
                 unsigned((now - last) / 100u), g_slow.upd / 100u, g_slow.ren / 100u, loop / 100u, g_slow.aud / 100u,
                 g_slow.end / 100u, unsigned(asked / 1000u), g_fc[0], g_fc[1], g_fc[2], g_fc[3]);
    // A plain frame once a second, for comparison.
    else if (frame_no % 30u == 0u)
      ::DbgPrint("NORM f=%u ms=%u upd=%u ren=%u loop=%u ops=%u calls=%u clips=%u allocs=%u\n", frame_no, unsigned((now - last) / 100u),
                 g_slow.upd / 100u, g_slow.ren / 100u, loop / 100u, g_fc[0], g_fc[1], g_fc[2], g_fc[3]);
    __builtin_memset(g_fc, 0, sizeof g_fc);
    last = now;
    g_slow.out = ::cc_xbox_clock(1000000u);
  }
#endif
#endif
  cc_capture_end_frame(base.memory, g_frame_delay_calls + 1u);
#if defined(CC_XBOX_DRIVER) && defined(CC_SLOW_STATS)
  if ((g_frame_delay_calls + 1u) % 300u == 0u) cc_slow_dbg();
#endif
#if defined(CC_XBOX_DRIVER) && defined(CC_OP_STATS)
  { void cc_op_dbg(); if ((g_frame_delay_calls + 1u) % 300u == 0u) cc_op_dbg(); }
#endif
#ifndef CC_XBOX_DRIVER
  {
    static long from = -1, to = -1;
    if (from < 0) {
      const char* a = std::getenv("CC_SAMPLE_FROM"); const char* b = std::getenv("CC_SAMPLE_TO");
      from = a ? std::strtol(a, nullptr, 10) : 0; to = b ? std::strtol(b, nullptr, 10) : 0x7FFFFFFF;
    }
    const long f = long(g_frame_delay_calls + 1u);
    g_sample_on.store(f >= from && f < to, std::memory_order_relaxed);
#ifdef CC_FAST
    g_fprof_live = g_fprof_on && f >= from && f < to;
#endif
  }
  // Host state check (CC_STATE_HASH=<n>): every n frames, a hash of each
  // writable guest region except the one holding the current stack, so two
  // runs (native vs exact code paths) can be compared region by region.
  {
    static const long every = [] { const char* e = std::getenv("CC_STATE_HASH"); return e ? std::strtol(e, nullptr, 10) : 0L; }();
    const uint32_t f = g_frame_delay_calls + 1u;
    if (every > 0 && f % uint32_t(every) == 0u) {
      const cc::xbox::Region* rg = base.memory.regions();
      uint64_t all = 0;
      for (size_t i = 0; i < base.memory.region_count(); ++i) {
        if (!(rg[i].access & 2u) || !rg[i].host) continue;
        if (ctx.r1.u32 >= rg[i].guest && ctx.r1.u32 - rg[i].guest < rg[i].bytes) continue;
#ifdef CC_FLAT_WINDOW
        // Flat guest window: while its whole pages share one 256 KiB block
        // (cc_win::ring_shared), the 360 command ring (0x0200F140, 2 MiB) is
        // not the page-table build's 256 KiB block repeated byte for byte,
        // so its bytes differ from the aliased layout and are skipped;
        // nothing reads them. With the sharing off (CC_RING_ALIAS=0) the
        // ring is hashed and matches the page-table build run with
        // CC_GFX_ALIAS=none. The surfaces' uncommitted interiors read as
        // zero (they were zero throughout in the aliased layout too).
        if (cc_win::ring_shared() && rg[i].guest - 0x0200F140u < 0x200000u) continue;
        const uint32_t g0 = rg[i].guest;
        bool holes = false;
        for (const cc_win::Range& hr : cc_win::kHoles) holes |= hr.lo < g0 + rg[i].bytes && g0 < hr.hi;
#endif
        // Script values {u32 type, u32 payload, u8 in-use, 3 padding bytes}
        // are copied as three words, so their padding carries whatever stale
        // stack bytes the source temporary had; a word whose word 8 bytes
        // earlier looks like a value type keeps only its in-use byte.
        uint64_t h = 0x9E3779B97F4A7C15ull ^ rg[i].bytes;
        const uint8_t* p = rg[i].host;
        size_t n = rg[i].bytes, k = 0;
#ifdef CC_FLAT_WINDOW
        auto byte = [p, g0, holes](size_t at) -> uint32_t { return holes && cc_win::in_hole(g0 + uint32_t(at)) ? 0u : p[at]; };
        auto be32 = [byte](size_t at) { return (byte(at) << 24) | (byte(at + 1) << 16) | (byte(at + 2) << 8) | byte(at + 3); };
#else
        auto be32 = [p](size_t at) { return (uint32_t(p[at]) << 24) | (uint32_t(p[at + 1]) << 16) | (uint32_t(p[at + 2]) << 8) | p[at + 3]; };
#endif
        auto is_type = [](uint32_t t) { return t == 0x80000000u || (t != 0u && t <= 0x40000u && (t & (t - 1u)) == 0u); };
        for (; k + 4u <= n; k += 4u) {
          uint32_t w = be32(k);
          if (k >= 8u && is_type(be32(k - 8u))) w &= 0xFF000000u;
          h = (h ^ w) * 0x100000001B3ull; h ^= h >> 29;
        }
#ifdef CC_FLAT_WINDOW
        for (; k < n; ++k) h = (h ^ byte(k)) * 0x100000001B3ull;
#else
        for (; k < n; ++k) h = (h ^ p[k]) * 0x100000001B3ull;
#endif
        all = (all ^ h) * 0x9E3779B97F4A7C15ull;
        cc_log("STATE frame=%u guest=%08x bytes=%08x hash=%016llx%c", f, rg[i].guest, rg[i].bytes, (unsigned long long)h, 10);
#ifdef CC_FLAT_WINDOW
        if (holes) continue;  // no dump of a region with uncommitted pages
#endif
        // CC_STATE_DUMP=<dir>: the region's bytes to <dir>/<frame>_<guest>.bin
        if (const char* dir = std::getenv("CC_STATE_DUMP")) {
          char path[512];
          std::snprintf(path, sizeof(path), "%s/%u_%08x.bin", dir, f, rg[i].guest);
          if (FILE* fp = std::fopen(path, "wb")) { std::fwrite(p, 1, n, fp); std::fclose(fp); }
        }
      }
      cc_log("STATEALL frame=%u hash=%016llx%c", f, (unsigned long long)all, 10);
    }
  }
#ifdef CC_FAST
  if (std::getenv("CC_TICK_STATS")) {
    static uint64_t t_last = 0;
    cc_log("TICKS frame=%u clips=%u ms=%.2f%c", g_frame_delay_calls + 1u, g_clip_ticks,
           double(base.timebase_virtual_ticks - t_last) * 1000.0 / double(Machine::timebase_hz), 10);
    t_last = base.timebase_virtual_ticks;
    g_clip_ticks = 0;
  }
  static const bool dl_stats = std::getenv("CC_DLCACHE_STATS") != nullptr;
  if (dl_stats && (g_frame_delay_calls + 1u) % 300u == 0u) {
    cc_log("DLCACHE frame=%u calls=%llu hits=%llu fills=%llu uncached=%llu busy=%llu nodes=%llu list_bumps=%llu name_bumps=%llu flushes=%llu\n",
           g_frame_delay_calls + 1u, (unsigned long long)g_dl_st.calls, (unsigned long long)g_dl_st.hits,
           (unsigned long long)g_dl_st.fills, (unsigned long long)g_dl_st.uncached, (unsigned long long)g_dl_st.busy,
           (unsigned long long)g_dl_st.nodes, (unsigned long long)g_dl_st.list_bumps, (unsigned long long)g_dl_st.name_bumps,
           (unsigned long long)g_dl_st.flushes);
    cc_log("DLREFRESH frame=%u refreshes=%llu candidates_checked=%llu kept_max=%llu sorts=%llu reordered=%llu sorted_nodes=%llu walk=%d\n",
           g_frame_delay_calls + 1u, (unsigned long long)g_dl_rst.refreshes, (unsigned long long)g_dl_rst.checked,
           (unsigned long long)g_dl_rst.kept_max, (unsigned long long)g_dl_rst.sorts, (unsigned long long)g_dl_rst.sorts_changed,
           (unsigned long long)g_dl_rst.sort_nodes, int(g_dl_walk_always));
    cc_log("DLSORT frame=%u sorts=%llu reordered=%llu nodes=%llu nodes_max=%llu moves=%llu moves_max=%llu merges=%llu\n",
           g_frame_delay_calls + 1u, (unsigned long long)g_dl_rst.sorts, (unsigned long long)g_dl_rst.sorts_changed,
           (unsigned long long)g_dl_rst.sort_nodes, (unsigned long long)g_dl_rst.sort_nodes_max,
           (unsigned long long)g_dl_rst.sort_moves, (unsigned long long)g_dl_rst.sort_moves_max,
           (unsigned long long)g_dl_rst.sort_merges);
    g_dl_st = {};
    g_dl_rst = {};
  }
  static const bool heap_stats = std::getenv("CC_HEAP_STATS") != nullptr;  // heap index census
  if (heap_stats && (g_frame_delay_calls + 1u) % 300u == 0u) {
    size_t entries = 0, chunks = 0;
    for (const CcHeapIdx& x : g_heap_idx) {
      chunks += x.ch.size();
      for (const CcHeapChunk* c : x.ch) entries += c->n;
    }
    cc_log("HEAPIDX frame=%u allocs=%llu frees=%llu builds=%llu fallbacks=%llu free_blocks=%zu chunks=%zu\n",
           g_frame_delay_calls + 1u, (unsigned long long)g_heap_st.allocs, (unsigned long long)g_heap_st.frees,
           (unsigned long long)g_heap_st.builds, (unsigned long long)g_heap_st.fallbacks, entries, chunks);
    g_heap_st = {};
  }
#endif
  // Host CC_POOL_HWM=1: highest nonzero 4 KiB page of the main pool at
  // 0x10000000 (the arena starts zeroed), every 500 frames.
  if (std::getenv("CC_POOL_HWM") && (g_frame_delay_calls + 1u) % 500u == 0u) {
    uint32_t top = 0;
    for (uint32_t pg = 0; pg < (16u << 20) / 4096u; ++pg) {
      uint64_t v = 0;
      bool nz = false;
      for (uint32_t o = 0; o < 4096u && !nz; o += 8u)
        if (base.memory.load_be(0x10000000u + pg * 4096u + o, 8, v) == cc::xbox::MemoryError::ok && v) nz = true;
      if (nz) top = pg + 1u;
    }
    // Game heap (0x71000 up, 24 MiB probe builds): the same scan.
    uint32_t htop = 0;
    for (uint32_t pg = 0; pg < (24u << 20) / 4096u; ++pg) {
      uint64_t v = 0;
      bool nz = false;
      for (uint32_t o = 0; o < 4096u && !nz; o += 8u)
        if (base.memory.load_be(0x71000u + pg * 4096u + o, 8, v) == cc::xbox::MemoryError::ok && v) nz = true;
      if (nz) htop = pg + 1u;
    }
    cc_log("POOLHWM frame=%u top=%uK heap=%uK%c", g_frame_delay_calls + 1u, top * 4u, htop * 4u, 10);
  }
  if (std::getenv("CC_WORKSET") && (g_frame_delay_calls + 1u) % 1000u == 0u)
    cc_log("RASTER frame=%u count=%u seconds=%.3f update=%.3f render=%.3f%c", g_frame_delay_calls + 1u, g_raster_count, g_raster_seconds, g_update_seconds, g_render_seconds, 10);
  if (std::getenv("CC_WORKSET") && (g_frame_delay_calls + 1u) % 250u == 0u)
    cc_log("TEXSTREAM frame=%u cache=%lluK replays=%u mismatches=%u evictions=%u swap_out=%u swap_in=%u baked=%u unbaked=%u%c",
           g_frame_delay_calls + 1u, (unsigned long long)(g_tex_cache_bytes >> 10),
           g_tex_replays, g_tex_replay_mismatches, g_tex_evictions, g_tex_swap_outs, g_tex_swap_ins,
           g_bake_hits, g_bake_misses, 10);
  g_mem_report_space = &base.memory;
  cc_mem_report(g_frame_delay_calls + 1u);
#endif
  if (++g_frame_delay_calls >= frame_budget())
    base.fail(Error::capacity, 0x8214A614u);
  // WIP 023 bounded worker-thread model: the five startup workers run the
  // exact loop sub_820B0E80 - pop a job from the pending list at
  // 0x8228A750, execute exact sub_820B1478(job), then push the job onto
  // the completed list at 0x8228A74C. This diagnostic is single-threaded,
  // so the same exact code runs synchronously at each frame boundary
  // (jobs enqueued during the frame complete "during" the frame) on a
  // dedicated scratch stack below the main thread's, exactly as the
  // worker's own stack would be. Nothing here is synthesized: only the
  // scheduling point is modeled.
#ifdef CC_XBOX_DRIVER
  {
    const uint64_t t = ::cc_xbox_clock(1000000u);
    cc_drain_workers(base, ctx.r13.u32);
    g_fs_us[4] += ::cc_xbox_clock(1000000u) - t;
  }
#else
  cc_drain_workers(base, ctx.r13.u32);
#endif
  base.trace_one_frame = false;
#ifndef CC_FAST
  // Diagnostics only: on the Xbox cc_log scrolls the framebuffer text,
  // a visible hitch every 500 frames.
  base.frame_probe_log = (g_frame_delay_calls % 500u == 0u);
  if (g_frame_delay_calls % 500u == 0u) {
    // Frame-state probe: the main loop's quit check reads the object at
    // [0x8225E620]; log its leading words so state transitions are visible.
    uint64_t obj=0; base.memory.load_be(0x8225E620u,4,obj);
    uint64_t w0=0,w1=0,w2=0,w3=0;
    if (obj) { base.memory.load_be(uint32_t(obj),4,w0); base.memory.load_be(uint32_t(obj)+4,4,w1);
               base.memory.load_be(uint32_t(obj)+8,4,w2); base.memory.load_be(uint32_t(obj)+12,4,w3); }
    uint64_t q0=0,q1=0,q2=0,q3=0;
    base.memory.load_be(0x00530C28u,4,q0); base.memory.load_be(0x00530C2Cu,4,q1);
    base.memory.load_be(0x00530C40u,4,q2); base.memory.load_be(0x00530C44u,4,q3);
    cc_log("frame %u state_obj=%08x w=[%08x %08x %08x %08x] q=[%08x %08x %08x %08x] file_open=%u pos=%u phys_live=%lluK phys_peak=%lluK cursor=%08x\n",
           g_frame_delay_calls,uint32_t(obj),uint32_t(w0),uint32_t(w1),uint32_t(w2),uint32_t(w3),
           uint32_t(q0),uint32_t(q1),uint32_t(q2),uint32_t(q3),
           base.open_files(),base.files[0].pos,
           (unsigned long long)(g_phys_live_bytes/1024u),(unsigned long long)(g_phys_peak_bytes/1024u),
           g_phys_cursor);
#ifdef CC_XBOX_DRIVER
    {
      unsigned st = 0, sub = 0, cb = 0, ur = 0, dr = 0;
      ::cc_xbox_audio_stats(&st, &sub, &cb, &ur, &dr);
      cc_log("AUDIO voices=%u mixed=%u ac97=%u fed=%u callbacks=%u underruns=%u dropped=%u\n",
             cc_audio_active_voices(), cc_audio_mixed_frames(), st, sub, cb, ur, dr);
    }
#endif
  }
#endif
  ctx.r3.u64 = 0u;  // STATUS_SUCCESS
}
static void __imp__KfReleaseSpinLock([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A744u); }
static void __imp__KfAcquireSpinLock([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A754u); }
static void __imp___vsnprintf([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A834u); }
static void __imp__DbgPrint([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A5A4u); }
static void __imp__sprintf([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A804u); }

static uint32_t checkpoint020_mm_load_u32(Machine& base, uint32_t a) {
  if (a>=0x7F000000u && a<0x80000000u) {
    // WIP 022: exact sub_820DA1E8 snapshots the APU's XMA context-array
    // register at power-on before any audio setup; the observed hardware
    // reset value is zero. All other MMIO reads stay fail-closed.
    if (a==0x7FEA1800u) return 0u;
    // WIP 023: the music streamer polls the APU's XMA context-control
    // window. The fixture audio hardware is silent: every register in the
    // window reads zero (no decode progress is faked; the exact code's
    // "still decoding" paths remain observable).
    if (a>=0x7FEA0000u && a<0x7FEB0000u) return 0u;
    base.fail(Error::unsupported,a);
  }
  return uint32_t(base.load(a,4));
}
// 16-bit MMIO reads follow the same policy as 32-bit ones: the silent APU
// window reads zero, ordinary memory reads through, anything else fails.
static uint16_t cc_mm_load_u16(Machine& base, uint32_t a) {
  if (a>=0x7F000000u && a<0x80000000u) {
    if (a>=0x7FEA0000u && a<0x7FEB0000u) return 0u;
    base.fail(Error::unsupported,a);
  }
  return uint16_t(base.load(a,2));
}
static void checkpoint020_mm_store_u32(Machine& base, uint32_t a, uint32_t v) {
  if (a>=0x7F000000u && a<0x80000000u) {
    // Observed CP_RB_WPTR write: Xenos MMIO base 0x7FC80000 + register 0x714.
    // The current ring has 8192 dwords, so reject any unobserved/out-of-ring value.
    // WIP 023: XMA context kick/lock writes into the APU window are
    // accepted and ignored by the silent fixture hardware.
    if (a>=0x7FEA0000u && a<0x7FEB0000u) return;
    if (a!=0x7FC80714u || v>=8192u) base.fail(Error::unsupported,a);
    base.cp_rb_wptr=v; ++base.cp_rb_wptr_writes;
    // WIP 022: the fixture Xenos consumes every submitted command
    // synchronously at the doorbell. The exact ring-space wait
    // (sub_820C6B18 -> sub_820BE9F0) compares the descriptor's read-index
    // writeback word against the device's submission phase; publish the
    // caught-up value exactly as the hardware writeback would.
    {
      const uint32_t dev=0x02000080u;
      const uint32_t desc=uint32_t(base.load(dev+10896u,4));
      const uint32_t phase=uint32_t(base.load(dev+10908u,4));
      if (desc) base.store(desc,4,phase);
    }
    return;
  }
  base.store(a,4,v);
}
#define REX_MM_LOAD_U32(a) checkpoint020_mm_load_u32(base,uint32_t(a))
#define REX_MM_STORE_U32(a,v) checkpoint020_mm_store_u32(base,uint32_t(a),uint32_t(v))
#define REX_QUERY_TIMEBASE() base.query_timebase()
// Checkpoint 020 exact command-buffer / flush family from sub_820C7228.
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restgprlr_19.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savegprlr_19.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#if defined(CC_XBOX_DRIVER) && defined(CC_FAST) && !defined(CC_BENCH)
#define sub_820B6068 sub_820B6068_exact
#include "generated/sub_820B6068.inc"
#undef sub_820B6068
// Sleep (tail call to SleepEx sub_820B74B0). The main loop's call, return
// address 0x82070EB8, is the frame boundary whose f31 the
// KeDelayExecutionThread hook replaces with the real frame time.
static void sub_820B6068(Context& ctx, Machine& base) {
  g_main_loop_sleep = uint32_t(ctx.lr) == 0x82070EB8u;
  sub_820B6068_exact(ctx, base);
  g_main_loop_sleep = false;
}
#else
#include "generated/sub_820B6068.inc"
#endif
#include "generated/sub_820B74B0.inc"
#include "generated/sub_820BE8F8.inc"
#include "generated/sub_820BE928.inc"
#if defined(CC_XBOX_DRIVER) && defined(CC_FAST) && !defined(CC_XBOX_PROFILE)
#define sub_820BE9F0 sub_820BE9F0_exact
#endif
#include "generated/sub_820BE9F0.inc"
#if defined(CC_XBOX_DRIVER) && defined(CC_FAST) && !defined(CC_XBOX_PROFILE)
#undef sub_820BE9F0
// Xbox play build: the generated prologue is empty, so the hook this
// function needs (Machine::hooked_fast) runs here.
static void sub_820BE9F0(Context& ctx, Machine& base) { base.hooked_fast(2, ctx); sub_820BE9F0_exact(ctx, base); }
#endif
#if defined(CC_XBOX_DRIVER) && defined(CC_FAST) && !defined(CC_XBOX_PROFILE)
#define sub_820C5E50 sub_820C5E50_exact
#endif
#include "generated/sub_820C5E50.inc"
#if defined(CC_XBOX_DRIVER) && defined(CC_FAST) && !defined(CC_XBOX_PROFILE)
#undef sub_820C5E50
// Xbox play build: the generated prologue is empty, so the hook this
// function needs (Machine::hooked_fast) runs here.
static void sub_820C5E50(Context& ctx, Machine& base) { base.hooked_fast(3, ctx); sub_820C5E50_exact(ctx, base); }
#endif
#include "generated/sub_820C6178.inc"
#include "generated/sub_820C6218.inc"
#include "generated/sub_820C6290.inc"
#include "generated/sub_820C64C0.inc"
#include "generated/sub_820C65A8.inc"
#include "generated/sub_820C6790.inc"
#include "generated/sub_820C6950.inc"
#include "generated/sub_820C6A40.inc"
#include "generated/sub_820C6B18.inc"
#include "generated/sub_820C6E68.inc"
#include "generated/sub_820C6F68.inc"
#include "generated/sub_820C70A0.inc"
#include "generated/sub_820C7228.inc"
#include "generated/sub_820C7988.inc"
#include "generated/sub_820C7B48.inc"
#include "generated/sub_820C7BF8.inc"
#include "generated/sub_820CB088.inc"
#include "generated/sub_820CB108.inc"
#include "generated/sub_820CB370.inc"
#include "generated/sub_820CB468.inc"
#include "generated/sub_820CB7F8.inc"
#include "generated/sub_820CCB40.inc"
#include "generated/sub_820D6470.inc"
#include "generated/sub_82128830.inc"


// Checkpoint 020 late device finalization exact bodies.
#include "generated/sub_820CDD68.inc"

// Checkpoint 021 focused PlatformRenderer::Init suffix probe. Specialized
// adjacent helpers remain fail-closed until the observed sub_820C1F58 branch
// proves they are needed.
static void sub_8212A8B8([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8212A8B8u); }
static void sub_820C48C8([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C48C8u); }
#include "generated/sub_820C4AF8.inc"
#include "generated/sub_820C19C8.inc"
#include "generated/sub_820C1CB8.inc"
#include "generated/sub_820D4298.inc"
#include "generated/sub_820C1F58.inc"
#include "generated/sub_820D3FE8.inc"
#include "generated/sub_820D4630.inc"
#include "generated/sub_820C24C0.inc"
#include "generated/sub_820C2B70.inc"
#include "generated/sub_820C2C98.inc"

// WIP 021: exact next PlatformRenderer::Init suffix body and the first
// adjacent command-state chain actually reached from it. Later direct callees
// remain fail-closed until execution proves they are required.
#include "generated/sub_820CDFB0.inc"
#include "generated/sub_820CC568.inc"
#include "generated/sub_820C6BE8.inc"
#include "generated/sub_820C08B8.inc"
static void sub_820C3A30([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C3A30u); }
#include "generated/sub_820C4878.inc"
static void sub_820C49D8([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C49D8u); }
static void sub_820C4F20([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C4F20u); }
#include "generated/sub_820C4FF8.inc"
#include "generated/sub_820BE228.inc"
// WIP 021: exact opening of the presentation/swap path.  All adjacent
// helpers/platform imports not yet proven on the observed path stay fail-closed.
static void sub_820D3B88([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D3B88u); }
static void sub_820D2E58([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D2E58u); }
static void sub_820D3280([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D3280u); }
#include "generated/sub_820D3EF8.inc"

#include "generated/sub_820CDF20.inc"
// WIP 021: exact post-swap display-mode/display-info helper. Platform imports
// remain fail-closed until this exact observed call shape reaches them.
static void __imp__VdSetDisplayMode(Context& ctx, Machine& base) {
  if (!base.vd_swap_called || base.display_mode_set || ctx.r3.u32 != 0x40000000u)
    base.fail(Error::unsupported, 0x8214A884u);
  base.display_mode_set = true;
  ctx.r3.u64 = 0u;
}
// WIP 021: one-shot observed VdGetCurrentDisplayInformation contract. The
// exact post-swap caller provides a stack-local 0x58-byte X_DISPLAY_INFO.
// Trusted kernel-model evidence zeroes the block and reports its current
// 1280x720 mode. Only the three fields consumed by exact sub_820CBF48 are
// populated here; every other call order/pointer remains fail-closed.
static void __imp__VdGetCurrentDisplayInformation(Context& ctx, Machine& base) {
  if (!base.vd_swap_called || !base.display_mode_set || base.display_info_queried ||
      ctx.r1.u32 != 0x0003E9E0u || ctx.r3.u32 != ctx.r1.u32 + 80u ||
      ctx.r3.u32 != 0x0003EA30u)
    base.fail(Error::unsupported, 0x8214A874u);
  const uint32_t p = ctx.r3.u32;
  if (p > 0xFFFFFFA7u)
    base.fail(Error::context, 0x8214A874u);
  for (uint32_t i = 0; i < 0x58u; i += 4u)
    base.store(p + i, 4, 0u);
  // X_DISPLAY_INFO offsets consumed by exact sub_820CBF48.
  base.store(p + 0x48u, 2, 1280u);  // display_width
  base.store(p + 0x4Au, 2, 720u);   // display_height
  base.store(p + 0x56u, 2, 1280u);  // actual_display_width
  base.display_info_queried = true;
  ctx.r3.u64 = 0u;
}
#include "generated/sub_820CBF48.inc"
#include "generated/sub_820C0BC0.inc"
// WIP 021: exact sub_820D1788; adjacent unobserved edges remain fail-closed.
#include "generated/sub_820D0008.inc"
static void sub_820D0238([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D0238u); }
static void sub_820D0720([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D0720u); }
static void sub_820D0898([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D0898u); }
static void sub_820D08F0([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D08F0u); }
#include "generated/sub_820D09F8.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_22.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_22.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_820D0B00.inc"
#include "generated/sub_82129EF8.inc"
#include "generated/sub_820D02C0.inc"
#include "generated/sub_820D0F80.inc"
#include "generated/sub_820D1260.inc"
// WIP 021: exact observed Xbox kernel RtlFillMemoryUlong contract reached by
// exact sub_820D1788. Xbox/Xenia RTL semantics fill Length>>2 ULONGs with the
// supplied guest-endian pattern. This diagnostic shim accepts only the single
// observed aligned stack-local call and rejects every other shape.
static void __imp__RtlFillMemoryUlong(Context& ctx, Machine& base) {
  constexpr uint32_t kDestination = 0x0003E0D0u;
  constexpr uint32_t kLength = 800u;
  constexpr uint32_t kPattern = 0x80000000u;
  if (ctx.r1.u32 != 0x0003E010u || ctx.r3.u32 != kDestination ||
      ctx.r3.u32 != ctx.r1.u32 + 192u || ctx.r4.u32 != kLength ||
      ctx.r5.u32 != kPattern || (ctx.r3.u32 & 3u) || (ctx.r4.u32 & 3u))
    base.fail(Error::unsupported, 0x8214A6C4u);
  if (base.memory.check(kDestination, kLength, cc::xbox::write_access) !=
      cc::xbox::MemoryError::ok)
    base.fail(Error::memory, kDestination);
  for (uint32_t i = 0; i < kLength; i += 4u)
    base.store(kDestination + i, 4, kPattern);
}
// WIP 021: one-shot observed VdInitializeScalerCommandBuffer contract reached
// by exact sub_820D1788. Xenia's Xbox 360 kernel model exposes the same
// 12-argument ABI and, for this import, fills dest_count words at dest_ptr with
// type-2 GPU NOP 0x80000000 and returns dest_count. Model only the exact Castle
// Crashers call shape observed here; every other stack/register/order shape is
// fail-closed.
static void __imp__VdInitializeScalerCommandBuffer(Context& ctx, Machine& base) {
  constexpr uint32_t kStack = 0x0003E010u;
  constexpr uint32_t kVerticalParams = kStack + 156u;
  constexpr uint32_t kHorizontalParams = kStack + 172u;
  constexpr uint32_t kUnknownBlock = kStack + 992u;
  constexpr uint32_t kDestination = kStack + 192u;
  constexpr uint32_t kCount = 200u;
  if (!base.vd_swap_called || !base.display_mode_set || !base.display_info_queried ||
      base.scaler_command_buffer_initialized || ctx.r1.u32 != kStack ||
      ctx.r3.u32 != 0x00000000u || ctx.r4.u32 != 0x028001E0u ||
      ctx.r5.u32 != 0x00000000u || ctx.r6.u32 != 0x050002D0u ||
      ctx.r7.u32 != 0x028001E0u || ctx.r8.u32 != 1u ||
      ctx.r9.u32 != kVerticalParams || ctx.r10.u32 != 1u ||
      base.load(kStack + 84u,4) != kHorizontalParams ||
      base.load(kStack + 92u,4) != kUnknownBlock ||
      base.load(kStack + 100u,4) != kDestination ||
      base.load(kStack + 108u,4) != kCount)
    base.fail(Error::unsupported, 0x8214A8E4u);
  if (base.memory.check(kDestination, kCount * 4u, cc::xbox::write_access) !=
      cc::xbox::MemoryError::ok)
    base.fail(Error::memory, kDestination);
  for (uint32_t i=0; i<kCount; ++i)
    base.store(kDestination + i*4u, 4, 0x80000000u);
  base.scaler_command_buffer_initialized = true;
  ctx.r3.u64 = kCount;
}
#include "generated/sub_820D1788.inc"
#include "generated/sub_820C0A98.inc"
#include "generated/sub_820C8E98.inc"
static void sub_820C8F90([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C8F90u); }
#include "generated/sub_820C0580.inc"
#include "generated/sub_820C0B40.inc"
static void sub_820CF038([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820CF038u); }
#include "generated/sub_820CF728.inc"
// WIP 021: exact sub_820CF9D0 recovered byte-for-byte. Adjacent direct
// callees remain hard boundaries until the exact observed branch reaches them.
static void sub_820CE088([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820CE088u); }
static void sub_820C91C0([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C91C0u); }
static void sub_820C9348([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C9348u); }
static void sub_820C9968([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C9968u); }
// WIP 021: exact sub_820CF858 and its observed first direct callee
// sub_821368C0 are both recovered byte-for-byte. The observed loader state makes
// sub_821368C0 return zero, so CF858 skips sub_820CD258; keep that later
// conditional callee fail-closed until an exact path actually reaches it.
#include "generated/sub_821368C0.inc"
static void sub_820CD258([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820CD258u); }
#include "generated/sub_820CF858.inc"
#define REX_QUERY_TIMEBASE() base.query_timebase()
#include "generated/sub_820CF9D0.inc"
// WIP 021: one-shot observed VdGetSystemCommandBuffer contract. The exact
// caller supplies two stack output locations. Trusted Xbox 360 kernel-model
// evidence used by this project reports a 0x94-byte system-command block whose
// first dword is 0xBEEF0000 plus companion dword 0xBEEF0001. Model only this
// exact call shape and fail closed on every other invocation.
static void __imp__VdGetSystemCommandBuffer(Context& ctx, Machine& base) {
  // WIP 022 second observed query: the post-Init frame path (exact
  // sub_820D3EF8 at lr=0x820C0FB0) re-reads the system command buffer with
  // the same output layout on its own frame.
  if (uint32_t(ctx.lr)==0x820C0FB0u &&
      ctx.r3.u32==ctx.r1.u32+208u && ctx.r4.u32==ctx.r1.u32+116u) {
    const uint32_t p0=ctx.r3.u32, p1=ctx.r4.u32;
    if (p0>0xffffff6bu || p1>0xfffffffbu)
      base.fail(Error::context,0x8214A784u);
    for (uint32_t i=0;i<0x94u;i+=4u) base.store(p0+i,4,0u);
    base.store(p0,4,0xBEEF0000u);
    base.store(p1,4,0xBEEF0001u);
    base.system_command_buffer_queried=true;
    ctx.r3.u64=0u;
    return;
  }
  if (base.system_command_buffer_queried || ctx.r1.u32!=0x0003EAA0u ||
      ctx.r3.u32!=ctx.r1.u32+208u || ctx.r4.u32!=ctx.r1.u32+116u)
    base.fail(Error::unsupported,0x8214A784u);
  const uint32_t p0=ctx.r3.u32, p1=ctx.r4.u32;
  if (p0>0xffffff6bu || p1>0xfffffffbu)
    base.fail(Error::context,0x8214A784u);
  for (uint32_t i=0;i<0x94u;i+=4u) base.store(p0+i,4,0u);
  base.store(p0,4,0xBEEF0000u);
  base.store(p1,4,0xBEEF0001u);
  base.system_command_buffer_queried=true;
  ctx.r3.u64=0u;
}
// WIP 021: one-shot observed VdSwap contract. Xenia's Xbox 360 kernel model
// validates the D3D texture-header fetch, front-buffer metadata and 640x480
// dimensions, then writes a 64-dword swap command block. This host fixture has
// no kernel MMU/physical mapper, so only the observed low-memory identity map
// (frontbuffer virtual == deterministic fixture physical) is accepted.
static void __imp__VdSwap(Context& ctx, Machine& base) {
  // WIP 022: the observed swap call shape is frame-relative ??? the exact
  // caller (sub_820C7458 at lr=0x820C1014) always passes the fetch block at
  // r1+0x80, sysbuf tokens at r1+0xD0/r1+0x74, and metadata pointers at
  // r1+0x6C/0x70/0x68. Checkpoint 020's one-shot swap targeted the scaler
  // command region (0x0200F950); the post-Init frame writes its swap block
  // through the ring write-pointer window instead. Both are accepted under
  // the same content validation below; everything else fails closed.
  // WIP 023: each game-loop frame advances the guest's own command write
  // cursor, so successive swap blocks walk the graphics command arena
  // (frame 1 at 0x0202FBB0, frame 8 at 0x0203FCE0, ...). Accept any
  // 4-byte-aligned target inside the command arena below the descriptor
  // heap at 0x0220F140; the 64-dword content contract below is unchanged
  // and still rejects anything that is not the exact observed swap block.
  // After enough frames the guest's command cursor wraps, so swap blocks
  // appear anywhere in the secondary/command arena from its 0x0200F140
  // base upward (observed 0x0200F820 post-wrap).
  const bool ring_target = ctx.r3.u32 >= 0x0200F140u &&
                           ctx.r3.u32 < 0x0220F000u &&
                           (ctx.r3.u32 & 3u) == 0u;
  if (!base.system_command_buffer_queried ||
      (base.vd_swap_called && !ring_target) ||
      (ctx.r3.u32 != 0x0200F950u && !ring_target) ||
      ctx.r4.u32 != ctx.r1.u32 + 0x80u || ctx.r5.u32 != 0x0220F148u ||
      ctx.r6.u32 != ctx.r1.u32 + 0xD0u || ctx.r7.u32 != 0xBEEF0001u ||
      ctx.r8.u32 != ctx.r1.u32 + 0x6Cu || ctx.r9.u32 != ctx.r1.u32 + 0x70u ||
      ctx.r10.u32 != ctx.r1.u32 + 0x68u)
    base.fail(Error::unsupported, 0x8214A774u);

  const uint32_t width_ptr = uint32_t(base.load(ctx.r1.u32 + 84u, 4));
  const uint32_t height_ptr = uint32_t(base.load(ctx.r1.u32 + 92u, 4));
  if (width_ptr != ctx.r1.u32 + 96u || height_ptr != ctx.r1.u32 + 100u)
    base.fail(Error::unsupported, 0x8214A774u);

  uint32_t fetch[6]{};
  for (uint32_t i = 0; i < 6u; ++i)
    fetch[i] = uint32_t(base.load(ctx.r4.u32 + i * 4u, 4));

  const uint32_t frontbuffer = uint32_t(base.load(ctx.r8.u32, 4));
  const uint32_t texture_format = uint32_t(base.load(ctx.r9.u32, 4));
  const uint32_t color_space = uint32_t(base.load(ctx.r10.u32, 4));
  const uint32_t width = uint32_t(base.load(width_ptr, 4));
  const uint32_t height = uint32_t(base.load(height_ptr, 4));
  const uint32_t sys0 = uint32_t(base.load(ctx.r6.u32, 4));
  const uint32_t sys1 = uint32_t(base.load(ctx.r1.u32 + 116u, 4));

  const uint32_t fetch_frontbuffer = ((fetch[1] >> 12) & 0xFFFFFu) << 12;
  const uint32_t fetch_width = (fetch[2] & 0x1FFFu) + 1u;
  const uint32_t fetch_height = ((fetch[2] >> 13) & 0x1FFFu) + 1u;
  if (fetch[0] != 0x85000002u || fetch[1] != 0x02211006u ||
      fetch[2] != 0x003BE27Fu || fetch[3] != 0x00001414u ||
      fetch[4] != 0u || fetch[5] != 0x00000200u ||
      fetch_frontbuffer != 0x02211000u || frontbuffer != fetch_frontbuffer ||
      texture_format != 6u || (fetch[1] & 0x3Fu) != texture_format ||
      color_space != 0u || width != 640u || height != 480u ||
      width != fetch_width || height != fetch_height ||
      sys0 != 0xBEEF0000u || sys1 != 0xBEEF0001u)
    base.fail(Error::unsupported, 0x8214A774u);

  // Final 64-dword block matching the trusted kernel model for this exact
  // observed call. The fixture's deterministic low address is used unchanged
  // as the platform physical address; this is not a general Xbox MMU model.
  const uint32_t buffer = ctx.r3.u32;
  base.store(buffer + 0u * 4u, 4, 0x00054800u);  // type0 FETCH_00_0, 6 dwords
  for (uint32_t i = 0; i < 6u; ++i)
    base.store(buffer + (1u + i) * 4u, 4, fetch[i]);
  base.store(buffer + 7u * 4u, 4, 0xC0036400u);  // type3 XE_SWAP, 4 dwords
  base.store(buffer + 8u * 4u, 4, 0x53574150u);  // 'SWAP'
  base.store(buffer + 9u * 4u, 4, frontbuffer);  // identity only for this fixture
  base.store(buffer + 10u * 4u, 4, width);
  base.store(buffer + 11u * 4u, 4, height);
  for (uint32_t i = 12u; i < 64u; ++i)
    base.store(buffer + i * 4u, 4, 0x80000000u);  // type2 NOP

  base.vd_swap_called = true;
}
static void __imp__VdPersistDisplay(Context& ctx, Machine& base) {
  // Xenia's xboxkrnl model for this Xbox 360 export returns TRUE and writes a
  // 64-byte, 32-byte-aligned no-access allocation through its second argument;
  // the exact Castle Crashers caller immediately passes that token to
  // MmFreePhysicalMemory(1, token). Bind only the single observed call shape.
  if (base.persist_display_called || !base.vd_swap_called ||
      ctx.r1.u32 != 0x0003EAA0u || uint32_t(ctx.lr) != 0x820C12E4u ||
      ctx.r3.u32 != 0x0003EB58u || ctx.r4.u32 != 0x0003EB40u ||
      ctx.r5.u32 != 0u || ctx.r6.u32 != 0x02211000u ||
      ctx.r7.u32 != 0x020122ECu || ctx.r8.u32 != 0x0003EB58u ||
      ctx.r9.u32 != 0xFFFFFFFEu || ctx.r10.u32 != 0x00001E4Eu)
    base.fail(Error::unsupported,0x8214A764u);

  // Exact caller code cleared this 12-byte input block before the import.
  if (base.load(ctx.r3.u32 + 0u, 4) != 0u ||
      base.load(ctx.r3.u32 + 4u, 4) != 0u ||
      base.load(ctx.r3.u32 + 8u, 4) != 0u)
    base.fail(Error::unsupported,0x8214A764u);

  // The platform allocation is deliberately represented as an opaque,
  // deterministic no-access token in the diagnostic fixture. The address is
  // 32-byte aligned and is not mapped as guest-readable/writable memory.
  constexpr uint32_t token = 0x02600000u;
  base.persist_display_called = true;
  base.persist_display_allocation = token;
  base.store(ctx.r4.u32, 4, token);
  ctx.r3.u64 = 1u;
}
// Two zones keep the retail-sized arena from fragmenting: small blocks
// (<= 4 KiB with at most 16-byte alignment; thousands of them in a level)
// come from their own zone at 0x1E000000, so they never split the space
// the large texture and pak blocks need at 0x12000000.
struct CcPhysZone { std::vector<PhysRange>* free; uint32_t* cursor; };
static std::vector<PhysRange> g_phys_small_free, g_phys_stub_free;
static uint32_t g_phys_small_cursor = 0x1E000000u, g_phys_stub_cursor = 0x1D000000u;
static uint32_t g_phys_zone_hint = 0;  // 2: texture stub zone
static uint32_t g_zone_hw[3] = {0x12000000u, 0x1E000000u, 0x1D000000u};  // cursor high-water
static CcPhysZone cc_phys_zone_for(uint32_t addr) {
  if (addr >= 0x1E000000u) return {&g_phys_small_free, &g_phys_small_cursor};
  if (addr >= 0x1D000000u) return {&g_phys_stub_free, &g_phys_stub_cursor};
  return {&g_phys_free_ranges, &g_phys_cursor};
}
static uint32_t cc_phys_alloc(Machine& base, uint32_t bytes, uint32_t align) {
  const uint32_t size=(bytes+15u)&~15u;
  // Texture stubs only need to be distinct: the pixels live in the texture
  // cache, so the page alignment the loader asks for is not kept.
  if (g_phys_zone_hint == 2u) align = 16u;
  const bool small = size <= 4096u && align <= 16u;
  CcPhysZone z = g_phys_zone_hint == 2u ? CcPhysZone{&g_phys_stub_free, &g_phys_stub_cursor}
               : small ? CcPhysZone{&g_phys_small_free, &g_phys_small_cursor}
                       : CcPhysZone{&g_phys_free_ranges, &g_phys_cursor};
  std::vector<PhysRange>& fl = *z.free;
    uint32_t p=0;
    for (size_t i=0;i<fl.size();++i) {
      const PhysRange fr=fl[i];
      const uint32_t a=(fr.addr+align-1u)&~(align-1u);
      if (a<fr.addr || a-fr.addr>fr.size || fr.size-(a-fr.addr)<size) continue;
      p=a;
      const uint32_t lead=a-fr.addr, tail=fr.size-lead-size;
      fl.erase(fl.begin()+i);
      if (tail) fl.insert(fl.begin()+i, PhysRange{a+size, tail});
      if (lead) fl.insert(fl.begin()+i, PhysRange{fr.addr, lead});
      break;
    }
    if (!p) {
      p=(*z.cursor+align-1u)&~(align-1u);
      if (p+size<p || base.memory.check(p,size,3)!=cc::xbox::MemoryError::ok) {
        cc_elog("PHYS exhausted zone=%s request=%u live=%llu peak=%llu blocks=%u free_ranges=%u\n",
                g_phys_zone_hint == 2u ? "texture-stub" : small ? "small" : "large",
                size,(unsigned long long)g_phys_live_bytes,(unsigned long long)g_phys_peak_bytes,
                unsigned(g_phys_live_blocks.size()),unsigned(fl.size()));
        base.fail(Error::memory,p);
      }
      *z.cursor=p+size;
      if (z.cursor == &g_phys_cursor && g_phys_cursor > g_zone_hw[0]) g_zone_hw[0] = g_phys_cursor;
      if (z.cursor == &g_phys_small_cursor && g_phys_small_cursor > g_zone_hw[1]) g_zone_hw[1] = g_phys_small_cursor;
      if (z.cursor == &g_phys_stub_cursor && g_phys_stub_cursor > g_zone_hw[2]) g_zone_hw[2] = g_phys_stub_cursor;
    }
    g_phys_live_blocks.push_back(PhysRange{p,size});
#ifndef CC_XBOX_DRIVER
    g_phys_owner[p]=g_phys_tag;
    g_phys_owner2[p]=(uint64_t(g_phys_tag2)<<32)|g_phys_tag3;
    g_phys_tag2=g_phys_tag3=0;
#endif
    g_phys_tag=0;
    g_phys_live_bytes+=size;
    if (g_phys_live_bytes>g_phys_peak_bytes) g_phys_peak_bytes=g_phys_live_bytes;
    return p;
}
#ifndef CC_XBOX_DRIVER
// Host diagnostic: CC_MEM_REPORT=<frame> logs every live physical block
// grouped by the guest code that allocated it, and how much of it holds
// textures the game has bound for drawing.
static void cc_mem_report(uint32_t frame) {
  const char* e = std::getenv("CC_MEM_REPORT");
  if (!e || std::strtoul(e, nullptr, 10) != frame) return;
  struct Group { uint32_t blocks = 0; uint64_t bytes = 0, tex_bytes = 0; uint32_t largest = 0; };
  std::map<uint32_t, Group> groups;
  uint64_t total = 0, tex_total = 0;
  for (const PhysRange& b : g_phys_live_blocks) {
    const auto it = g_phys_owner.find(b.addr);
    Group& g = groups[it == g_phys_owner.end() ? 0u : it->second];
    ++g.blocks; g.bytes += b.size; total += b.size;
    if (b.size > g.largest) g.largest = b.size;
    const auto t = g_bound_textures.lower_bound(b.addr);
    if (t != g_bound_textures.end() && t->first < b.addr + b.size) {
      g.tex_bytes += b.size; tex_total += b.size;
    }
  }
  {
    std::map<uint64_t, std::pair<uint32_t,uint64_t>> chains;
    for (const PhysRange& b : g_phys_live_blocks) {
      const auto it = g_phys_owner2.find(b.addr);
      auto& c = chains[it == g_phys_owner2.end() ? 0u : it->second];
      ++c.first; c.second += b.size;
    }
    for (const auto& [k, c] : chains)
      if (c.second >= 256u * 1024u)
        cc_log("MEMREPORT chain=%08x<-%08x blocks=%u bytes=%lluK\n", unsigned(k >> 32),
               unsigned(k & 0xFFFFFFFFu), c.first, (unsigned long long)(c.second >> 10));
  }
  {
    // Content signature (first 4 guest bytes) and size spread of live blocks.
    std::map<uint32_t, std::pair<uint32_t,uint64_t>> sig;
    for (const PhysRange& b : g_phys_live_blocks) {
      uint64_t w0=0; g_mem_report_space->load_be(b.addr,4,w0);
      auto& c = sig[uint32_t(w0)]; ++c.first; c.second += b.size;
    }
    uint32_t filled = 0, empty = 0; uint64_t filled_b = 0, empty_b = 0;
    for (const PhysRange& b : g_phys_live_blocks) {
      bool nz = false;
      for (uint32_t o = 0; o < b.size && !nz; o += 64u) {
        uint64_t w = 0; g_mem_report_space->load_be(b.addr + o, 4, w); nz = w != 0;
      }
      if (nz) { ++filled; filled_b += b.size; } else { ++empty; empty_b += b.size; }
    }
    cc_log("MEMREPORT filled_blocks=%u (%lluK) empty_blocks=%u (%lluK)%c", filled,
           (unsigned long long)(filled_b >> 10), empty, (unsigned long long)(empty_b >> 10), 10);
    for (const auto& [k, c] : sig)
      if (c.second >= 512u * 1024u)
        cc_log("MEMREPORT first_word=%08x blocks=%u bytes=%lluK%c", k, c.first,
               (unsigned long long)(c.second >> 10), 10);
  }
  {
    uint32_t pool_touched=0;
    for (uint32_t pg=0x10000000u; pg<0x11000000u; pg+=0x1000u)
      for (uint32_t o=0; o<0x1000u; o+=64u) {
        uint64_t w=0; g_mem_report_space->load_be(pg+o,4,w);
        if (w) { ++pool_touched; break; }
      }
    uint32_t heap_touched=0;
    for (uint32_t pg=0x04000000u; pg<g_valloc_cursor; pg+=0x1000u)
      for (uint32_t o=0; o<0x1000u; o+=64u) {
        uint64_t w=0; g_mem_report_space->load_be(pg+o,4,w);
        if (w) { ++heap_touched; break; }
      }
    auto touched = [](uint32_t lo, uint32_t hi) {
      uint32_t n = 0, last = lo;
      for (uint32_t pg = lo; pg < hi; pg += 0x1000u)
        for (uint32_t o = 0; o < 0x1000u; o += 64u) {
          uint64_t w = 0;
          if (g_mem_report_space->load_be(pg + o, 4, w) != cc::xbox::MemoryError::ok) break;
          if (w) { ++n; last = pg + 0x1000u; break; }
        }
      return std::pair<uint32_t, uint32_t>(n * 4u, (last - lo) >> 10);
    };
    const auto gh = touched(0x00071000u, 0x01071000u), gx = touched(0x02000000u, 0x02500000u);
    const auto mp = touched(0x10000000u, 0x11000000u);
    cc_log("MEMREPORT main_pool_highwater=%uK port_audio_loaded=%uK%c", mp.second, cc_audio_loaded_bytes() >> 10, 10);
    cc_log("MEMREPORT zones_highwater large=%uK small=%uK stub=%uK%c",
           (g_zone_hw[0] - 0x12000000u) >> 10, (g_zone_hw[1] - 0x1E000000u) >> 10,
           (g_zone_hw[2] - 0x1D000000u) >> 10, 10);
    cc_log("MEMREPORT game_heap_touched=%uK highwater=%uK gpu_arena_touched=%uK highwater=%uK%c",
           gh.first, gh.second, gx.first, gx.second, 10);
    {
      std::map<uint32_t, std::pair<uint32_t, uint64_t>> by;
      uint64_t tot = 0;
      for (const auto& [a, e] : g_heap_live) { auto& b = by[e.second]; ++b.first; b.second += e.first; tot += e.first; }
      cc_log("MEMREPORT game_heap_live=%lluK blocks=%u%c", (unsigned long long)(tot >> 10), unsigned(g_heap_live.size()), 10);
      for (const auto& [lr, b] : by)
        if (b.second >= 64u * 1024u)
          cc_log("MEMREPORT heap_owner lr=%08x blocks=%u bytes=%lluK%c", lr, b.first, (unsigned long long)(b.second >> 10), 10);
    }
    cc_log("MEMREPORT crt_heap_committed=%uK crt_heap_touched=%uK reserved=%uK main_pool_touched=%uK (of 16384K)%c",
           unsigned(g_committed_pages.size()*4u), heap_touched*4u,
           unsigned((g_valloc_cursor-0x04000000u)>>10), pool_touched*4u, 10);
  }
  cc_log("MEMREPORT frame=%u live=%lluK blocks=%u drawn_texture_blocks=%lluK\n", frame,
         (unsigned long long)(total >> 10), unsigned(g_phys_live_blocks.size()),
         (unsigned long long)(tex_total >> 10));
  for (const auto& [lr, g] : groups)
    cc_log("MEMREPORT owner_lr=%08x blocks=%u bytes=%lluK textures=%lluK largest=%uK\n", lr,
           g.blocks, (unsigned long long)(g.bytes >> 10),
           (unsigned long long)(g.tex_bytes >> 10), g.largest >> 10);
}
#endif
static bool cc_phys_free([[maybe_unused]] Machine& base, uint32_t addr) {
    // A freed texture takes its streaming-cache copy with it. Done before
    // this block is looked up: the nested free reorders the live list.
    if (CcDxtTexture* tx = cc_dxt_lookup(addr)) {
      const uint32_t cache = tx->cache;
      if (cache) g_tex_cache_bytes -= uint64_t(tx->w) * tx->h;
      if (tx->swap_off >= 0)
        g_tex_swap_free_early.push_back({tx->swap_off, tx->w * tx->h});
      cc_dxt_erase(addr);
      if (cache) cc_texzone_free(cache);
    }
    size_t li = 0;
    while (li < g_phys_live_blocks.size() && g_phys_live_blocks[li].addr != addr) ++li;
    if (li == g_phys_live_blocks.size()) return false;
    for (size_t k = 0; k < g_pending_textures.size(); ++k)
      if (g_pending_textures[k].data == addr) { g_pending_textures.erase(g_pending_textures.begin() + long(k)); break; }
    PhysRange r = g_phys_live_blocks[li];
    g_phys_live_blocks[li] = g_phys_live_blocks.back();
    g_phys_live_blocks.pop_back();
    g_phys_live_bytes -= r.size;
    CcPhysZone z = cc_phys_zone_for(r.addr);
    std::vector<PhysRange>& fl = *z.free;
    // Insert sorted, then merge with the neighbours on either side.
    size_t pos = 0;
    while (pos < fl.size() && fl[pos].addr < r.addr) ++pos;
    fl.insert(fl.begin() + pos, r);
    if (pos + 1 < fl.size() && fl[pos].addr + fl[pos].size == fl[pos+1].addr) {
      fl[pos].size += fl[pos+1].size;
      fl.erase(fl.begin() + pos + 1);
    }
    if (pos > 0 && fl[pos-1].addr + fl[pos-1].size == fl[pos].addr) {
      fl[pos-1].size += fl[pos].size;
      fl.erase(fl.begin() + pos);
    }
    // A free range ending at the cursor returns its space to the cursor.
    if (!fl.empty() && fl.back().addr + fl.back().size == *z.cursor) {
      *z.cursor = fl.back().addr;
      fl.pop_back();
    }
  return true;
}
// Kernel pool (used by the game's Live-layer allocator sub_82114E20):
// ExAllocatePoolTypeWithTag(size, tag, type) and ExFreePool(ptr), served
// from the same arena. Size 0 or exhaustion fails closed.
static void __imp__ExAllocatePoolTypeWithTag(Context& ctx, Machine& base) {
  if (ctx.r3.u32 == 0u || ctx.r3.u32 > 0x01000000u)
    base.fail(Error::unsupported, 0x8214ACA4u);
  g_phys_tag=uint32_t(ctx.lr);
  ctx.r3.u64 = cc_phys_alloc(base, ctx.r3.u32, 16u);
}
[[maybe_unused]] static void __imp__ExFreePool(Context& ctx, Machine& base) {
  if (!cc_phys_free(base, ctx.r3.u32))
    base.fail(Error::unsupported, 0x8214AC64u);
}
static void __imp__MmFreePhysicalMemory(Context& ctx, Machine& base) {
  // WIP 023: the pak-mount path frees cursor-arena blocks through the exact
  // wrapper sub_820B6190 (type 0); the shared allocator reuses the space.
  // An address this fixture never handed out fails closed.
  if (ctx.r3.u32 == 0u && ((ctx.r4.u32 >= 0x12000000u && ctx.r4.u32 < g_phys_cursor) ||
                           (ctx.r4.u32 >= 0x1E000000u && ctx.r4.u32 < g_phys_small_cursor) ||
                           (ctx.r4.u32 >= 0x1D000000u && ctx.r4.u32 < g_phys_stub_cursor))) {
    if (!cc_phys_free(base, ctx.r4.u32))
      base.fail(Error::unsupported, 0x8214A504u);  // not a block we handed out
    ctx.r3.u64 = 0u;
    return;
  }
  // Bind only the physical allocation created by the immediately preceding
  // observed VdPersistDisplay call. The trusted xboxkrnl contract requires a
  // 32-byte-aligned address and releases that allocation; this diagnostic
  // fixture represents it as an opaque no-access token rather than mapped
  // guest memory.
  if (!base.persist_display_called || base.persist_display_freed ||
      base.persist_display_allocation != 0x02600000u ||
      ctx.r1.u32 != 0x0003EAA0u || uint32_t(ctx.lr) != 0x820C12F8u ||
      ctx.r3.u32 != 1u || ctx.r4.u32 != base.persist_display_allocation ||
      ctx.r5.u32 != 0u || ctx.r6.u32 != 0x02211000u ||
      ctx.r7.u32 != 0x020122ECu || ctx.r8.u32 != 0x0003EB58u ||
      ctx.r9.u32 != 0xFFFFFFFEu || ctx.r10.u32 != 0x00001E4Eu ||
      (ctx.r4.u32 & 0x1Fu) != 0u ||
      base.memory.check(ctx.r4.u32, 64u, 1u) == cc::xbox::MemoryError::ok)
    base.fail(Error::unsupported,0x8214A504u);

  base.persist_display_freed = true;
  base.persist_display_allocation = 0u;
}

#include "generated/sub_820C0DA8.inc"
#include "generated/sub_820C13B8.inc"

// WIP 021 sub_820A7990-suffix boundaries: descriptor/resource helpers called
// by exact sub_820AA5B8 that are not yet recovered. Each hard-fails rather
// than simulating success.
#define HARD_BOUNDARY_021(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { \
    base.fail(Error::unsupported, addr); \
  }
// (sub_820C0440 is now included exact, below)
// (sub_820C0330 is now included exact, below)
#undef HARD_BOUNDARY_021

#include "generated/sub_820AA5B8.inc"

// Descriptor-parse helpers reached by exact sub_820AA488; unrecovered callees
// stay fail-closed.
#define HARD_BOUNDARY_021B(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { \
    base.fail(Error::unsupported, addr); \
  }
#undef HARD_BOUNDARY_021B

// The bounded NtReadFile contract completes synchronously; the semaphore
// wait contract for this import is defined later with the semaphore fixture.
#include "generated/sub_820B6310.inc"
#include "generated/sub_82138200.inc"
#include "generated/sub_82136390.inc"
#include "generated/sub_820BFDF0.inc"
#include "generated/sub_820C0440.inc"
#include "generated/sub_820C0330.inc"
#include "generated/sub_820C00D0.inc"
#include "generated/sub_820C01C0.inc"
#include "generated/sub_820A8190.inc"
#include "generated/sub_820BFEE8.inc"
#include "generated/sub_820BFC30.inc"
#include "generated/sub_820C00B8.inc"

// WIP 022: sub_82070AC8 caller continuation after the completed
// PlatformRenderer::Init. Exact sub_8209BC98 -> sub_820B6108 request the
// title's main physical pool through MmAllocatePhysicalMemoryEx; the bounded
// contract below serves it from the dedicated fixture arena and fails closed
// outside the observed shape.
// Keep the first new_size bytes of a live block and release the rest.
static void cc_phys_shrink(Machine& base, uint32_t addr, uint32_t new_size) {
  new_size = (new_size + 15u) & ~15u;
  for (auto& b : g_phys_live_blocks) {
    if (b.addr != addr) continue;
    if (new_size >= b.size) return;
    const PhysRange tail{addr + new_size, b.size - new_size};
    b.size = new_size;
    g_phys_live_blocks.push_back(tail);
    cc_phys_free(base, tail.addr);
    return;
  }
}
static void __imp__MmAllocatePhysicalMemoryEx(Context& ctx, Machine& base) {
  // Bounded physical-memory contract. Two observed request families:
  //  - the single 16 MiB title main pool (flags 0, size 0x01000FFF,
  //    PAGE_READWRITE, no bounds, 4 KiB alignment), served once at
  //    0x10000000;
  //  - font/texture blocks (flags 0, PAGE_READWRITE or write-combined
  //    0x404, no bounds, <=4 MiB), served from the cursor arena at
  //    0x12000000.
  if (ctx.r3.u32!=0u || ctx.r6.u32!=0u || ctx.r7.u32!=0xFFFFFFFFu)
    base.fail(Error::unsupported, 0x8214A4F4u);
  if (ctx.r4.u32==0x01000FFFu && ctx.r5.u32==4u && ctx.r8.u32==0x1000u &&
      !g_main_pool_allocated) {
    const uint32_t p=0x10000000u;
    // Only the retail budget's share of the pool is backed (see the test's
    // main_pool_arena); accesses past it fail closed.
    if (base.memory.check(p,0x1000u,3)!=cc::xbox::MemoryError::ok)
      base.fail(Error::memory,p);
    g_main_pool_allocated=true;
    ctx.r3.u64=p;
    return;
  }
  // WIP 023 third family: the pak-mount path allocates 1 MiB streaming
  // blocks with protect 0x20000004 (PAGE_READWRITE plus the observed
  // large-page hint) and default alignment (r8=0), from the same cursor
  // arena (lr=0x820B6164).
  // WIP 023: the sound loader also takes sub-page blocks (observed 0x800);
  // every allocation is page-rounded into the same cursor arena.
  if ((ctx.r5.u32==4u || ctx.r5.u32==0x404u || ctx.r5.u32==0x20000004u) &&
      ctx.r4.u32>=0x100u && ctx.r4.u32<=0x400000u) {
    const uint32_t align = ctx.r8.u32 ? ctx.r8.u32 : 0x1000u;
    if (align & (align-1u))
      base.fail(Error::unsupported, 0x8214A4F4u);
    const uint32_t size=(ctx.r4.u32+0xFFFu)&~0xFFFu;
    g_phys_tag=uint32_t(ctx.lr);
    // The shared allocation wrapper's callers: saved LRs two and three
    // frames up the guest back chain (raw, uncounted reads).
    uint64_t f1=0,l1=0,f2=0,l2=0;
    base.memory.load_be(ctx.r1.u32,4,f1);
    base.memory.load_be(uint32_t(f1)-8u,4,l1);
    base.memory.load_be(uint32_t(f1),4,f2);
    base.memory.load_be(uint32_t(f2)-8u,4,l2);
#ifndef CC_XBOX_DRIVER
    g_phys_tag2=uint32_t(l1); g_phys_tag3=uint32_t(l2);
#endif
    // Texture pixel blocks (allocated by exact sub_820B1078 at lr
    // 0x820B1340, then cut to a 16-byte stub by the port) come from their
    // own zone so the stubs pack together instead of fragmenting the
    // large-block arena.
    g_phys_zone_hint = uint32_t(l1) == 0x820B1340u ? 2u : 0u;
    ctx.r3.u64=cc_phys_alloc(base,size,align);
    g_phys_zone_hint = 0u;
    return;
  }
  cc_elog(
    "MMALLOCPHYSEX unsupported r3=%08x r4=%08x r5=%08x r6=%08x r7=%08x r8=%08x lr=%08x\n",
    ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32, ctx.r8.u32,
    uint32_t(ctx.lr));
  base.fail(Error::unsupported, 0x8214A4F4u);
}
#include "generated/sub_820B6108.inc"
#ifdef CC_FAST
#define sub_8209BC98 sub_8209BC98_exact
#endif
#include "generated/sub_8209BC98.inc"
#ifdef CC_FAST
#undef sub_8209BC98
// Heap init (exact sub_8209BC98: heap r3): one free block; the heap's
// free-list mirror (cc_heap_idx) starts over.
static void sub_8209BC98(Context& ctx, Machine& base) {
  const uint32_t h = ctx.r3.u32;
  sub_8209BC98_exact(ctx, base);
  cc_heap_forget(h);
}
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savegprlr_15.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restgprlr_15.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_820C2D58.inc"
#include "generated/sub_820C3568.inc"
#include "generated/sub_820C7D48.inc"
#include "generated/sub_820C3930.inc"
#include "generated/sub_820C4488.inc"
#include "generated/sub_820C4498.inc"
#include "generated/sub_820D7D70.inc"
#include "generated/sub_820A7390.inc"
#include "generated/sub_820A9B58.inc"
#include "generated/sub_820BFB50.inc"
#include "generated/sub_820A7E80.inc"
#include "generated/sub_820A8030.inc"
#include "generated/sub_820A8010.inc"

// WIP 022 caller-tail closures: worker notification (exact sub_82096828),
// manager registration (exact sub_820756E0), and the semaphore-backed event
// wrapper (exact sub_820B5F50 family). NtCreateSemaphore is observed-shape
// bound below.
static void __imp__NtCreateSemaphore(Context& ctx, Machine& base) {
  // Bounded event/semaphore fixture: the exact sub_820B5F50 wrapper creates
  // one semaphore (initial 0, limit 1) through the OBJECT_ATTRIBUTES block
  // built by exact sub_820B73D0. Handles are opaque tokens; waits on them
  // remain fail-closed.
  if (ctx.r5.u32>ctx.r6.u32 || ctx.r6.u32==0u || ctx.r6.u32>0x7FFFFFFFu ||
      g_semaphore_count>=8u)
    base.fail(Error::unsupported, 0x8214A4A4u);
  base.store(ctx.r3.u32,4,0x0F5E0001u+g_semaphore_count);
  g_semaphore_value[g_semaphore_count]=ctx.r5.u32;
  g_semaphore_limit[g_semaphore_count]=ctx.r6.u32;
  ++g_semaphore_count;
  ctx.r3.u64=0u;
}
// WIP 023: the frame loop signals a fixture semaphore through the exact
// sub_820B5F50 wrapper (lr=0x820B5FF8). Release is modeled against the
// recorded initial/limit values; exceeding a limit or an unknown handle
// stays fail-closed. Waits remain fail-closed until observed.
// WIP 023: the frame loop waits on the same fixture semaphores through the
// exact wrapper sub_820B6020 (WaitMode 1, non-alertable, NULL = infinite
// timeout). A signaled semaphore satisfies the wait immediately; a wait
// that would block forever in this single-threaded diagnostic stays
// fail-closed so a genuine lost-wakeup is observable, never spun through.
// Kernel event objects: handles 0x0EE00001.., type 0 = notification
// (stays signalled), 1 = synchronization (a satisfied wait clears it).
struct CcEvent { bool sync; bool signalled; };
static std::vector<CcEvent> g_events;
static CcEvent* cc_event(uint32_t h) {
  const uint32_t ix = h - 0x0EE00001u;
  return ix < g_events.size() ? &g_events[ix] : nullptr;
}
static void __imp__NtCreateEvent(Context& ctx, Machine& base) {
  if (!ctx.r3.u32 || ctx.r5.u32 > 1u || g_events.size() >= 64u)
    base.fail(Error::unsupported, 0x8214A544u);
  g_events.push_back(CcEvent{ctx.r5.u32 == 1u, (ctx.r6.u32 & 0xFFu) != 0u});
  base.store(ctx.r3.u32, 4, 0x0EE00001u + uint32_t(g_events.size() - 1u));
  ctx.r3.u64 = 0u;
}
[[maybe_unused]] static void __imp__NtSetEvent(Context& ctx, Machine& base) {
  CcEvent* e = cc_event(ctx.r3.u32);
  if (!e) base.fail(Error::unsupported, 0x8214ADE4u);
  if (ctx.r4.u32) base.store(ctx.r4.u32, 4, e->signalled ? 1u : 0u);
  e->signalled = true;
  ctx.r3.u64 = 0u;
}
[[maybe_unused]] static void __imp__NtClearEvent(Context& ctx, Machine& base) {
  CcEvent* e = cc_event(ctx.r3.u32);
  if (!e) base.fail(Error::unsupported, 0x8214AD24u);
  e->signalled = false;
  ctx.r3.u64 = 0u;
}
static void __imp__NtWaitForSingleObjectEx(Context& ctx, Machine& base) {
  // Timeout pointer r6: NULL = infinite. A zero timeout on an unsignalled
  // object reports STATUS_TIMEOUT (0x102); any wait that would really block
  // fails closed (single-threaded diagnostic: nothing could wake it).
  const bool zero_timeout = ctx.r6.u32 != 0u && base.load(ctx.r6.u32, 8) == 0u;
  const uint32_t ix = ctx.r3.u32 - 0x0F5E0001u;
  if (ix < g_semaphore_count && ctx.r4.u32 == 1u && ctx.r5.u32 == 0u) {
    if (g_semaphore_value[ix] > 0u) {
      --g_semaphore_value[ix];
      ctx.r3.u64 = 0u;  // WAIT_OBJECT_0
      return;
    }
    if (zero_timeout) { ctx.r3.u64 = 0x102u; return; }
  }
  if (CcEvent* e = cc_event(ctx.r3.u32)) {
    if (e->signalled) {
      if (e->sync) e->signalled = false;
      ctx.r3.u64 = 0u;
      return;
    }
    if (zero_timeout) { ctx.r3.u64 = 0x102u; return; }
  }
#ifdef CC_FAST
  // Play build, main thread only: a wait on any other object (the main
  // menu's Quit path waits for its threads and I/O on the way out) returns
  // at once as signalled; nothing could wake it on this single-threaded
  // port. A newly started system thread must still park here (the block
  // point below abandons it), or its wait loop would run forever.
  if (!g_in_thread_run) { ctx.r3.u64 = 0u; return; }
#endif
  cc_thread_block_point();
  cc_elog("WAIT would block handle=%08x mode=%u alertable=%u timeout_ptr=%08x lr=%08x\n",
          ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, uint32_t(ctx.lr));
  base.fail(Error::unsupported, 0x8214A514u);
}
static void __imp__NtReleaseSemaphore(Context& ctx, Machine& base) {
  const uint32_t ix = ctx.r3.u32 - 0x0F5E0001u;
  if (ix >= g_semaphore_count || ctx.r4.u32 == 0u ||
      g_semaphore_value[ix] + ctx.r4.u32 > g_semaphore_limit[ix])
    base.fail(Error::unsupported, 0x8214A4B4u);
  if (ctx.r5.u32 != 0u)
    base.store(ctx.r5.u32, 4, g_semaphore_value[ix]);
  g_semaphore_value[ix] += ctx.r4.u32;
  ctx.r3.u64 = 0u;  // STATUS_SUCCESS
}
// WIP 022 notification-listener service creation (exact sub_820D7FD0 family).
// KeInitializeSemaphore models the trusted kernel object initialization; the
// other kernel entries observed on this path are bound elsewhere or fail
// closed until observed.
// Single-threaded diagnostic models of the raised-IRQL spinlock family used
// by the exact audio-driver init. IRQL raise/lower and lock acquire/release
// are balance-checked; contention cannot occur with one thread.
static void __imp__KeRaiseIrqlToDpcLevel(Context& ctx, [[maybe_unused]] Machine& base) {
  // Nested raises are legal; return the previous level and go to DISPATCH.
  ctx.r3.u64=g_irql_level;
  g_irql_level=2u;
}
static void __imp__KfLowerIrql(Context& ctx, Machine& base) {
  if (ctx.r3.u32>2u) base.fail(Error::unsupported, 0x8214A80Cu);
  g_irql_level=ctx.r3.u32;
}
static void __imp__KeAcquireSpinLockAtRaisedIrql(Context& ctx, Machine& base) {
  if (g_irql_level==0u || uint32_t(base.load(ctx.r3.u32,4))!=0u)
    base.fail(Error::unsupported, 0x8214A81Cu);
  base.store(ctx.r3.u32,4,1u);
}
static void __imp__KeReleaseSpinLockFromRaisedIrql(Context& ctx, Machine& base) {
  if (g_irql_level==0u || uint32_t(base.load(ctx.r3.u32,4))!=1u)
    base.fail(Error::unsupported, 0x8214A794u);
  base.store(ctx.r3.u32,4,0u);
}
// Trusted kernel contract: set the dispatcher event's SignalState and return
// the previous state. No waiter dispatch occurs in the single-threaded
// diagnostic; the exact worker threads are recorded but never run.
static void __imp__KeSetEvent(Context& ctx, Machine& base) {
  const uint32_t old=uint32_t(base.load(ctx.r3.u32+4,4));
  base.store(ctx.r3.u32+4,4,1u);
  ctx.r3.u64=old;
}
// Kernel XAudio render-driver boundary. Registration is observed-shape
// bound; frame submission and unregistration stay fail-closed until the
// diagnostic actually reaches them.
static void __imp__XAudioRegisterRenderDriverClient(Context& ctx, Machine& base) {
  // Bound to the single observed registration: callback 0x820E2B30 with the
  // exact driver-object context. The fixture kernel never pumps the render
  // callback (no audio hardware), matching the never-run worker model. The
  // returned client token is opaque to the exact code.
  if (uint32_t(base.load(ctx.r3.u32,4))!=0x820E2B30u || ctx.r4.u32==0u ||
      g_xaudio_client_registered)
    base.fail(Error::unsupported, 0x8214ABE4u);
  g_xaudio_client_registered=true;
  base.store(ctx.r4.u32,4,0x0A0D1001u);
  ctx.r3.u64=0u;
}
static void __imp__XAudioSubmitRenderDriverFrame([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214AA24u);
}
static void __imp__XAudioUnregisterRenderDriverClient([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214AA34u);
}
static void __imp__KeInitializeSemaphore(Context& ctx, Machine& base) {
  base.store(ctx.r3.u32+0,1,5u);            // SemaphoreObject type
  base.store(ctx.r3.u32+1,1,0u);
  base.store(ctx.r3.u32+2,2,20u/4u);        // size in dwords
  base.store(ctx.r3.u32+4,4,ctx.r4.u32);    // SignalState = initial count
  base.store(ctx.r3.u32+8,4,ctx.r3.u32+8);  // wait list head -> self
  base.store(ctx.r3.u32+12,4,ctx.r3.u32+8);
  base.store(ctx.r3.u32+16,4,ctx.r5.u32);   // Limit
}
static void __imp__KeResumeThread(Context& ctx, Machine& base) {
  auto *t=base.by_object(ctx.r3.u32);
  if (!t || !t->suspended)
    base.fail(Error::unsupported, 0x8214A954u);
  t->suspended=false;
  t->runnable=true;
  ctx.r3.u64=1u;
}
#define REX_MM_LOAD_U32(a) checkpoint020_mm_load_u32(base,uint32_t(a))
#define REX_MM_STORE_U32(a,v) checkpoint020_mm_store_u32(base,uint32_t(a),uint32_t(v))
// Generated mfmsr/mtmsrd interrupt-mask sequences: the single-threaded host
// has no interrupts to mask, so the global lock is a no-op and the check
// returns the context's MSR mirror (preserving the exact data flow).
#define REX_CHECK_GLOBAL_LOCK() (ctx.msr)
#define REX_ENTER_GLOBAL_LOCK() do {} while (0)
#define REX_LEAVE_GLOBAL_LOCK() do {} while (0)
#include "generated/sub_820D7FD0.inc"
#include "generated/sub_820DA1E8.inc"
#include "generated/sub_820DA0E8.inc"
#include "generated/sub_820D9D48.inc"
#include "generated/sub_820D9C40.inc"
#include "generated/sub_820D8FA8.inc"
#include "generated/sub_820E35E8.inc"
#include "generated/sub_820E29D0.inc"
#include "generated/sub_820E3040.inc"
#include "generated/sub_820DB8B8.inc"
#include "generated/sub_820D87C0.inc"
#include "generated/sub_820DB880.inc"
#include "generated/sub_820E2978.inc"
#include "generated/sub_820E3548.inc"
#include "generated/sub_820E3498.inc"
#include "generated/sub_820E2700.inc"
#include "generated/sub_820E2BF0.inc"
#include "generated/sub_820E2EB8.inc"
#include "generated/sub_820E4410.inc"
#include "generated/sub_820DB6F8.inc"
#include "generated/sub_820DB698.inc"
#include "generated/sub_820DC848.inc"
#include "generated/sub_820E0A48.inc"
#include "generated/sub_820E4C88.inc"
#include "generated/sub_820E40C0.inc"
#include "generated/sub_820E4510.inc"
#include "generated/sub_820E2688.inc"
#include "generated/sub_820DB278.inc"
#include "generated/sub_820E4278.inc"
#include "generated/sub_820DB298.inc"
#include "generated/sub_820E31D8.inc"
#include "generated/sub_8209B790.inc"
#include "generated/sub_8209B7A8.inc"
#include "generated/sub_820A1640.inc"
#include "generated/sub_82053888.inc"
#include "generated/sub_820A7470.inc"
#include "generated/sub_82074A58.inc"
#include "generated/sub_82074B00.inc"
#include "generated/xstart.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savegprlr_30.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savegprlr_31.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restgprlr_30.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restgprlr_31.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_15.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_16.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_17.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_18.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_21.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_23.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_29.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_30.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_31.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_15.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_16.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_17.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_18.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_21.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_23.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_29.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_30.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_31.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_82051758.inc"
#include "generated/sub_82051848.inc"
#include "generated/sub_82051960.inc"
#include "generated/sub_82051A20.inc"
#include "generated/sub_82051CE0.inc"
#include "generated/sub_82051E68.inc"
#include "generated/sub_82051FA8.inc"
#include "generated/sub_820520F0.inc"
#include "generated/sub_82052E00.inc"
#include "generated/sub_82052E50.inc"
#include "generated/sub_82054C38.inc"
#include "generated/sub_82054DD8.inc"
#include "generated/sub_82055120.inc"
#include "generated/sub_82055130.inc"
#include "generated/sub_82055198.inc"
#include "generated/sub_82055218.inc"
#include "generated/sub_820556E8.inc"
#include "generated/sub_82055740.inc"
#include "generated/sub_820569F0.inc"
#include "generated/sub_82056B28.inc"
#include "generated/sub_82057D78.inc"
#include "generated/sub_820580F8.inc"
#include "generated/sub_82058138.inc"
#include "generated/sub_82058208.inc"
#include "generated/sub_82058320.inc"
#include "generated/sub_82058440.inc"
#include "generated/sub_8205A248.inc"
#include "generated/sub_8205A2B0.inc"
#include "generated/sub_8205A318.inc"
#include "generated/sub_8205B618.inc"
#include "generated/sub_8205B688.inc"
#include "generated/sub_8205B6F0.inc"
#include "generated/sub_8205C400.inc"
#include "generated/sub_8205C520.inc"
#include "generated/sub_8205C750.inc"
#include "generated/sub_8205C988.inc"
#include "generated/sub_8205CA10.inc"
#include "generated/sub_8205CAF0.inc"
#include "generated/sub_8205CDF0.inc"
#include "generated/sub_8205D2D8.inc"
#include "generated/sub_8205D3E0.inc"
#include "generated/sub_8205D448.inc"
#include "generated/sub_82060508.inc"
#include "generated/sub_820606D8.inc"
#include "generated/sub_820607B8.inc"
#include "generated/sub_82061460.inc"
#include "generated/sub_82061518.inc"
#include "generated/sub_820615D8.inc"
#include "generated/sub_82061760.inc"
#include "generated/sub_820618E8.inc"
#include "generated/sub_82061DB0.inc"
#include "generated/sub_82062388.inc"
#include "generated/sub_82063754.inc"
#include "generated/sub_82064100.inc"
#include "generated/sub_820641D8.inc"
#include "generated/sub_820643E0.inc"
#include "generated/sub_82064B80.inc"
#include "generated/sub_82064D08.inc"
#include "generated/sub_82064D98.inc"
#include "generated/sub_82065008.inc"
#include "generated/sub_820650C8.inc"
#include "generated/sub_82065190.inc"
#include "generated/sub_82065388.inc"
#include "generated/sub_82065418.inc"
#include "generated/sub_820664F0.inc"
#include "generated/sub_82066548.inc"
#include "generated/sub_82066570.inc"
#include "generated/sub_82066598.inc"
#include "generated/sub_820665C0.inc"
#include "generated/sub_820665E8.inc"
#include "generated/sub_82066B78.inc"
#include "generated/sub_82066E60.inc"
#include "generated/sub_820670F8.inc"
#include "generated/sub_820673B8.inc"
#include "generated/sub_820678C8.inc"
#include "generated/sub_82069578.inc"
#include "generated/sub_820696A8.inc"
#include "generated/sub_82069768.inc"
#include "generated/sub_82069F40.inc"
#include "generated/sub_8206A5A0.inc"
#include "generated/sub_8206A840.inc"
#include "generated/sub_8206AA08.inc"
#include "generated/sub_8206AAD0.inc"
#include "generated/sub_8206AB50.inc"
#include "generated/sub_8206B5D0.inc"
#include "generated/sub_8206BAB0.inc"
#include "generated/sub_8206BB60.inc"
#include "generated/sub_8206BBD8.inc"
#include "generated/sub_8206BC78.inc"
#include "generated/sub_8206BD08.inc"
#include "generated/sub_8206BD90.inc"
#include "generated/sub_8206BF88.inc"
#include "generated/sub_8206D068.inc"
#include "generated/sub_8206D0D8.inc"
#include "generated/sub_8206D0F8.inc"
#include "generated/sub_8206D200.inc"
#include "generated/sub_8206D220.inc"
#include "generated/sub_8206D278.inc"
#include "generated/sub_8206D298.inc"
#include "generated/sub_8206D338.inc"
#include "generated/sub_8206D3B8.inc"
#include "generated/sub_8206D440.inc"
#include "generated/sub_8206D6C8.inc"
#include "generated/sub_8206D850.inc"
#include "generated/sub_8206D980.inc"
#include "generated/sub_8206DBC0.inc"
#include "generated/sub_8206DEE8.inc"
#include "generated/sub_8206E230.inc"
#include "generated/sub_8206E818.inc"
#include "generated/sub_8206EDA0.inc"
#include "generated/sub_8206EDC0.inc"
#include "generated/sub_82070828.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/sub_82070AC8.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_82072678.inc"
#include "generated/sub_82072680.inc"
#include "generated/sub_82072B68.inc"
#include "generated/sub_82072C70.inc"
#include "generated/sub_82073CF8.inc"
#include "generated/sub_82074FA8.inc"
#include "generated/sub_82075020.inc"
#include "generated/sub_82075380.inc"
#include "generated/sub_82078CB0.inc"
#include "generated/sub_82078CE8.inc"
#include "generated/sub_8207A740.inc"
#include "generated/sub_8207A748.inc"
#include "generated/sub_8207BDE0.inc"
#include "generated/sub_8207BED0.inc"
#include "generated/sub_8207C018.inc"
#include "generated/sub_8207CA40.inc"
#include "generated/sub_8207D498.inc"
#include "generated/sub_8207D6D0.inc"
#include "generated/sub_8207D808.inc"
#include "generated/sub_8207DA68.inc"
#include "generated/sub_8207DC08.inc"
#include "generated/sub_8207DDB8.inc"
#include "generated/sub_8207F350.inc"
#include "generated/sub_82080368.inc"
#include "generated/sub_82080840.inc"
#include "generated/sub_82080C40.inc"
#include "generated/sub_82081250.inc"
#include "generated/sub_82083438.inc"
#include "generated/sub_82083A08.inc"
#include "generated/sub_82085858.inc"
#include "generated/sub_82086290.inc"
#include "generated/sub_820862A0.inc"
#include "generated/sub_820862A8.inc"
#include "generated/sub_82086338.inc"
#include "generated/sub_82086468.inc"
#include "generated/sub_82088BC0.inc"
#include "generated/sub_82088C10.inc"
#include "generated/sub_82088C90.inc"
#include "generated/sub_82088CE8.inc"
#include "generated/sub_8208B088.inc"
#include "generated/sub_8208C110.inc"
#include "generated/sub_8208C378.inc"
#include "generated/sub_8208C6D0.inc"
#include "generated/sub_8208E4F0.inc"
#include "generated/sub_8208E580.inc"
#include "generated/sub_8208E788.inc"
#include "generated/sub_8208E930.inc"
#include "generated/sub_8208EA50.inc"
#include "generated/sub_8208EC10.inc"
#include "generated/sub_8208ED20.inc"
#include "generated/sub_8208EE60.inc"
#include "generated/sub_8208EFD0.inc"
#include "generated/sub_8208F178.inc"
#include "generated/sub_8208F348.inc"
#include "generated/sub_8208FF58.inc"
#include "generated/sub_82092230.inc"
#include "generated/sub_820929E0.inc"
#include "generated/sub_82092CF8.inc"
#include "generated/sub_82092EC8.inc"
#include "generated/sub_82092FA0.inc"
#include "generated/sub_82093918.inc"
#include "generated/sub_82094688.inc"
#ifdef CC_FAST
#define sub_82094730 sub_82094730_exact
#endif
#include "generated/sub_82094730.inc"
#ifdef CC_FAST
#undef sub_82094730
// Text-field name clear (exact sub_82094730: field r3; u16 +150 = 0), seen
// by the name cache.
static void sub_82094730(Context& ctx, Machine& base) {
  const uint32_t old = REX_LOAD_U16(ctx.r3.u32 + 150u);
  sub_82094730_exact(ctx, base);
  cc_dl_name_changed(old);
}
#endif
#include "generated/sub_820956B0.inc"
#include "generated/sub_82095B60.inc"
#include "generated/sub_82095B98.inc"
#include "generated/sub_82099DB8.inc"
#include "generated/sub_82099F18.inc"
#include "generated/sub_8209A288.inc"
#include "generated/sub_8209B368.inc"
#include "generated/sub_8209B3F8.inc"
#include "generated/sub_8209B9B0.inc"
#include "generated/sub_8209C550.inc"
#include "generated/sub_8209C678.inc"
#include "generated/sub_8209C8B8.inc"
#include "generated/sub_8209C970.inc"
#include "generated/sub_8209CB10.inc"
#include "generated/sub_8209CD98.inc"
#include "generated/sub_8209CE08.inc"
#include "generated/sub_8209CE50.inc"
#include "generated/sub_8209CE88.inc"
#include "generated/sub_8209DB88.inc"
#include "generated/sub_820A2C90.inc"
#include "generated/sub_820A2ED8.inc"
#include "generated/sub_820A3050.inc"
#include "generated/sub_820A3448.inc"
#include "generated/sub_820A3AE8.inc"
#include "generated/sub_820A3B88.inc"
#include "generated/sub_820A3C28.inc"
#include "generated/sub_820A3CC8.inc"
#include "generated/sub_820A3D60.inc"
#include "generated/sub_820A40E8.inc"
#include "generated/sub_820A4328.inc"
#include "generated/sub_820A4C60.inc"
#include "generated/sub_820A4E08.inc"
#include "generated/sub_820A4F88.inc"
#include "generated/sub_820A5230.inc"
#include "generated/sub_820A5540.inc"
#include "generated/sub_820A5620.inc"
#include "generated/sub_820A59E8.inc"
#include "generated/sub_820A5D80.inc"
#include "generated/sub_820A5FC0.inc"
#include "generated/sub_820A61E8.inc"
#include "generated/sub_820A6260.inc"
#include "generated/sub_820A66B8.inc"
#include "generated/sub_820A6728.inc"
#include "generated/sub_820A6730.inc"
#include "generated/sub_820A6758.inc"
#include "generated/sub_820A67D0.inc"
#include "generated/sub_820A6990.inc"
#include "generated/sub_820A69F0.inc"
#include "generated/sub_820A6A18.inc"
#include "generated/sub_820A6B60.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/sub_820A7990.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_820A86A8.inc"
#include "generated/sub_820A8960.inc"
#include "generated/sub_820A8CE0.inc"
#include "generated/sub_820AAA78.inc"
#include "generated/sub_820AABF8.inc"
#include "generated/sub_820AACB8.inc"
#include "generated/sub_820AAEB0.inc"
#include "generated/sub_820AB0C0.inc"
#include "generated/sub_820AB290.inc"
#include "generated/sub_820AB6A8.inc"
#include "generated/sub_820AE450.inc"
#include "generated/sub_820AE540.inc"
#include "generated/sub_820AE790.inc"
#include "generated/sub_820AEA68.inc"
#include "generated/sub_820AEB90.inc"
#include "generated/sub_820AF120.inc"
#include "generated/sub_820AF220.inc"
#include "generated/sub_820AF4C0.inc"
#include "generated/sub_820AF600.inc"
#include "generated/sub_820AF900.inc"
#include "generated/sub_820AFD58.inc"
#include "generated/sub_820B0E10.inc"
#include "generated/sub_820B0E68.inc"
#include "generated/sub_820B0E80.inc"
#include "generated/sub_820B17A8.inc"
#include "generated/sub_820B27A8.inc"
#include "generated/sub_820B5D38.inc"
#include "generated/sub_820B5D48.inc"
#include "generated/sub_820B5DF0.inc"
#include "generated/sub_820B5EC0.inc"
#include "generated/sub_820B6B40.inc"
#include "generated/sub_820B6D68.inc"
#include "generated/sub_820B6E20.inc"
#include "generated/sub_820B6EA8.inc"
#include "generated/sub_820B7254.inc"
#include "generated/sub_820B7640.inc"
#include "generated/sub_820B7958.inc"
#include "generated/sub_820B79B8.inc"
#include "generated/sub_820B7A14.inc"
#include "generated/sub_820B9944.inc"
#include "generated/sub_820BA1AC.inc"
#include "generated/sub_820BA4A0.inc"
#include "generated/sub_820BAD60.inc"
#include "generated/sub_820BADC4.inc"
#include "generated/sub_820BADEC.inc"
#include "generated/sub_820BB6C8.inc"
#include "generated/sub_820BB6F8.inc"
#include "generated/sub_820BB730.inc"
#include "generated/sub_820BB7C0.inc"
#include "generated/sub_820BB850.inc"
#include "generated/sub_820BB8E0.inc"
#include "generated/sub_820BB970.inc"
#include "generated/sub_820BB9E0.inc"
#include "generated/sub_820BBA50.inc"
#include "generated/sub_820BBAC0.inc"
#include "generated/sub_820BBB58.inc"
#include "generated/sub_820BBBA0.inc"
#include "generated/sub_820BBBE8.inc"
#include "generated/sub_820BBC88.inc"
#include "generated/sub_820BBD20.inc"
#include "generated/sub_820BBD70.inc"
#include "generated/sub_820BBDC0.inc"
#include "generated/sub_820BBE08.inc"
#include "generated/sub_820BBE30.inc"
#include "generated/sub_820BBE68.inc"
#include "generated/sub_820BBEB0.inc"
#include "generated/sub_820BBEE0.inc"
#include "generated/sub_820BBF10.inc"
#include "generated/sub_820BBF48.inc"
#include "generated/sub_820BBF80.inc"
#include "generated/sub_820BBFB0.inc"
#include "generated/sub_820BBFE0.inc"
#include "generated/sub_820BC018.inc"
#include "generated/sub_820BC050.inc"
#include "generated/sub_820BC080.inc"
#include "generated/sub_820BC0A8.inc"
#include "generated/sub_820BC0C8.inc"
#include "generated/sub_820BC0E8.inc"
#include "generated/sub_820BC108.inc"
#include "generated/sub_820BC128.inc"
#include "generated/sub_820BC148.inc"
#include "generated/sub_820BC190.inc"
#include "generated/sub_820BC1A0.inc"
#include "generated/sub_820BC250.inc"
#include "generated/sub_820BC308.inc"
#include "generated/sub_820BC338.inc"
#include "generated/sub_820BC360.inc"
#include "generated/sub_820BC3A0.inc"
#include "generated/sub_820BC3E0.inc"
#include "generated/sub_820BC420.inc"
#include "generated/sub_820BC460.inc"
#include "generated/sub_820BC470.inc"
#include "generated/sub_820BC4C0.inc"
#include "generated/sub_820BC510.inc"
#include "generated/sub_820BC560.inc"
#include "generated/sub_820BC7D0.inc"
#include "generated/sub_820BC7E0.inc"
#include "generated/sub_820BC7F0.inc"
#include "generated/sub_820BC800.inc"
#include "generated/sub_820BC810.inc"
#include "generated/sub_820BC820.inc"
#include "generated/sub_820BC830.inc"
#include "generated/sub_820BC840.inc"
#include "generated/sub_820BC850.inc"
#include "generated/sub_820BC860.inc"
#include "generated/sub_820BC870.inc"
#include "generated/sub_820BC880.inc"
#include "generated/sub_820BC890.inc"
#include "generated/sub_820BC8A0.inc"
#include "generated/sub_820BC8B0.inc"
#include "generated/sub_820BC8C0.inc"
#include "generated/sub_820BC910.inc"
#include "generated/sub_820BC9B0.inc"
#include "generated/sub_820BCA48.inc"
#include "generated/sub_820BCAE0.inc"
#include "generated/sub_820BCB78.inc"
#include "generated/sub_820BCBA8.inc"
#include "generated/sub_820BCBE0.inc"
#include "generated/sub_820BCC18.inc"
#include "generated/sub_820BCC50.inc"
#include "generated/sub_820BCC80.inc"
#include "generated/sub_820BCCB0.inc"
#include "generated/sub_820BCCD8.inc"
#include "generated/sub_820BCD08.inc"
#include "generated/sub_820BCD48.inc"
#include "generated/sub_820BCD78.inc"
#include "generated/sub_820BCDA0.inc"
#include "generated/sub_820BCDD0.inc"
#include "generated/sub_820BCDF8.inc"
#include "generated/sub_820BCE60.inc"
#include "generated/sub_820BCE90.inc"
#include "generated/sub_820BCEC0.inc"
#include "generated/sub_820BCEF0.inc"
#include "generated/sub_820BCF18.inc"
#include "generated/sub_820BCF28.inc"
#include "generated/sub_820BCF40.inc"
#include "generated/sub_820BD018.inc"
#include "generated/sub_820BD0E8.inc"
#include "generated/sub_820BD1C0.inc"
#include "generated/sub_820BD288.inc"
#include "generated/sub_820BD2D8.inc"
#include "generated/sub_820BD388.inc"
#include "generated/sub_820BD400.inc"
#include "generated/sub_820BD470.inc"
#include "generated/sub_820BD518.inc"
#include "generated/sub_820BD5C8.inc"
#include "generated/sub_820BD648.inc"
#include "generated/sub_820BD6A8.inc"
#include "generated/sub_820BD700.inc"
#include "generated/sub_820BD750.inc"
#include "generated/sub_820BD7A0.inc"
#include "generated/sub_820BD7F8.inc"
#include "generated/sub_820BD850.inc"
#include "generated/sub_820BD8A8.inc"
#include "generated/sub_820BD900.inc"
#include "generated/sub_820BD960.inc"
#include "generated/sub_820BDA70.inc"
#include "generated/sub_820BDB90.inc"
#include "generated/sub_820BDC20.inc"
#include "generated/sub_820BDC68.inc"
#include "generated/sub_820BEC50.inc"
#include "generated/sub_820BEE18.inc"
#include "generated/sub_820BFA60.inc"
#include "generated/sub_820C05F0.inc"
#include "generated/sub_820C0708.inc"
#include "generated/sub_820C0DA0.inc"
#include "generated/sub_820C3410.inc"
#include "generated/sub_820C4970.inc"
#include "generated/sub_820C60E0.inc"
#include "generated/sub_820C6E08.inc"
#include "generated/sub_820C7328.inc"
#include "generated/sub_820C7360.inc"
#include "generated/sub_820C7A38.inc"
#include "generated/sub_820C7A94.inc"
#include "generated/sub_820C7C78.inc"
#include "generated/sub_820C7CF0.inc"
#include "generated/sub_820C7DD8.inc"
#include "generated/sub_820C7FE8.inc"
#include "generated/sub_820C8040.inc"
#include "generated/sub_820C8100.inc"
#include "generated/sub_820C8178.inc"
#include "generated/sub_820C81F8.inc"
#include "generated/sub_820C8350.inc"
#include "generated/sub_820C86D8.inc"
#include "generated/sub_820C87E0.inc"
#include "generated/sub_820C8A40.inc"
#include "generated/sub_820C8E10.inc"
#include "generated/sub_820C90DC.inc"
#include "generated/sub_820C9148.inc"
#include "generated/sub_820C92A8.inc"
#include "generated/sub_820C9950.inc"
#include "generated/sub_820CAFF0.inc"
#include "generated/sub_820CB060.inc"
#include "generated/sub_820CB070.inc"
#include "generated/sub_820CB8B8.inc"
#include "generated/sub_820CB900.inc"
#include "generated/sub_820CB920.inc"
#include "generated/sub_820CB960.inc"
#include "generated/sub_820CBE40.inc"
#include "generated/sub_820CBEF0.inc"
#include "generated/sub_820CC368.inc"
#include "generated/sub_820CC3E8.inc"
#include "generated/sub_820CC6D8.inc"
#include "generated/sub_820CC748.inc"
#include "generated/sub_820CC7A0.inc"
#include "generated/sub_820CC828.inc"
#include "generated/sub_820CC888.inc"
#include "generated/sub_820CC9B0.inc"
#include "generated/sub_820CC9C0.inc"
#include "generated/sub_820CCA30.inc"
#include "generated/sub_820CCA98.inc"
#include "generated/sub_820CCBD8.inc"
#include "generated/sub_820CCC30.inc"
#include "generated/sub_820CCCA8.inc"
#include "generated/sub_820CCD80.inc"
#include "generated/sub_820CCE48.inc"
#include "generated/sub_820CCEB0.inc"
#include "generated/sub_820CCF08.inc"
#include "generated/sub_820CCF50.inc"
#include "generated/sub_820CD0A8.inc"
#include "generated/sub_820CD148.inc"
#include "generated/sub_820CD6A8.inc"
#include "generated/sub_820CDB88.inc"
#include "generated/sub_820CDB90.inc"
#include "generated/sub_820CDE68.inc"
#include "generated/sub_820CE128.inc"
#include "generated/sub_820CE890.inc"
#include "generated/sub_820CED10.inc"
#include "generated/sub_820CFE70.inc"
#include "generated/sub_820CFF10.inc"
#include "generated/sub_820D1AD0.inc"
#include "generated/sub_820D1AE8.inc"
#include "generated/sub_820D1B00.inc"
#include "generated/sub_820D1B38.inc"
#include "generated/sub_820D1B90.inc"
#include "generated/sub_820D1BD8.inc"
#include "generated/sub_820D1BF0.inc"
#include "generated/sub_820D1C30.inc"
#include "generated/sub_820D1EF0.inc"
#include "generated/sub_820D1F70.inc"
#include "generated/sub_820D2080.inc"
#include "generated/sub_820D2DA0.inc"
#include "generated/sub_820D3B58.inc"
#include "generated/sub_820D6080.inc"
#include "generated/sub_820D6160.inc"
#include "generated/sub_820D6518.inc"
#include "generated/sub_820D6590.inc"
#include "generated/sub_820D6648.inc"
#include "generated/sub_820D66B0.inc"
#include "generated/sub_820D67B8.inc"
#include "generated/sub_820D6818.inc"
#include "generated/sub_820D69B8.inc"
#include "generated/sub_820D6A40.inc"
#include "generated/sub_820D6AE0.inc"
#include "generated/sub_820D6BA8.inc"
#include "generated/sub_820D6CE0.inc"
#include "generated/sub_820D6DD8.inc"
#include "generated/sub_820D7118.inc"
#include "generated/sub_820D7260.inc"
#include "generated/sub_820D7578.inc"
#include "generated/sub_820D7888.inc"
#include "generated/sub_820D80F0.inc"
#include "generated/sub_820D83C8.inc"
#include "generated/sub_820D8768.inc"
#include "generated/sub_820D88D0.inc"
#include "generated/sub_820D89D8.inc"
#include "generated/sub_820D8AF0.inc"
#include "generated/sub_820D8DB0.inc"
#include "generated/sub_820D8EE8.inc"
#include "generated/sub_820D9090.inc"
#include "generated/sub_820D9248.inc"
#include "generated/sub_820D9330.inc"
#include "generated/sub_820D99B0.inc"
#include "generated/sub_820D9A78.inc"
#include "generated/sub_820D9B28.inc"
#include "generated/sub_820DA538.inc"
#include "generated/sub_820DA610.inc"
#include "generated/sub_820DA690.inc"
#include "generated/sub_820DA6F8.inc"
#include "generated/sub_820DA758.inc"
#include "generated/sub_820DA7E8.inc"
#include "generated/sub_820DA9A0.inc"
#include "generated/sub_820DAA48.inc"
#include "generated/sub_820DAC00.inc"
#include "generated/sub_820DAC78.inc"
#include "generated/sub_820DACC0.inc"
#include "generated/sub_820DACE0.inc"
#include "generated/sub_820DAD68.inc"
#include "generated/sub_820DADA0.inc"
#include "generated/sub_820DB138.inc"
#include "generated/sub_820DB420.inc"
#include "generated/sub_820DB620.inc"
#include "generated/sub_820DB810.inc"
#include "generated/sub_820DBA80.inc"
#include "generated/sub_820DBAA0.inc"
#include "generated/sub_820DBF20.inc"
#include "generated/sub_820DC868.inc"
#include "generated/sub_820DC958.inc"
#include "generated/sub_820DC9D0.inc"
#include "generated/sub_820DCC80.inc"
#include "generated/sub_820DCDC0.inc"
#include "generated/sub_820DCDF8.inc"
#include "generated/sub_820DCEB8.inc"
#include "generated/sub_820DCED0.inc"
#include "generated/sub_820DCEE0.inc"
#include "generated/sub_820DD0F0.inc"
#include "generated/sub_820DD4A8.inc"
#include "generated/sub_820DDAF8.inc"
#include "generated/sub_820DDC08.inc"
#include "generated/sub_820DDCD0.inc"
#include "generated/sub_820DDF78.inc"
#include "generated/sub_820DE040.inc"
#include "generated/sub_820DE1B8.inc"
#include "generated/sub_820DE330.inc"
#include "generated/sub_820DE4A8.inc"
#include "generated/sub_820DE550.inc"
#include "generated/sub_820DEA38.inc"
#include "generated/sub_820DEA50.inc"
#include "generated/sub_820E01C8.inc"
#include "generated/sub_820E0308.inc"
#include "generated/sub_820E0380.inc"
#include "generated/sub_820E03D0.inc"
#include "generated/sub_820E0538.inc"
#include "generated/sub_820E05B0.inc"
#include "generated/sub_820E0660.inc"
#include "generated/sub_820E06B8.inc"
#include "generated/sub_820E08B8.inc"
#include "generated/sub_820E0958.inc"
#include "generated/sub_820E0A08.inc"
#include "generated/sub_820E0A18.inc"
#include "generated/sub_820E0A90.inc"
#include "generated/sub_820E0D20.inc"
#include "generated/sub_820E0D40.inc"
#include "generated/sub_820E0E20.inc"
#include "generated/sub_820E11E0.inc"
#include "generated/sub_820E1310.inc"
#include "generated/sub_820E14F0.inc"
#include "generated/sub_820E1618.inc"
#include "generated/sub_820E1AE8.inc"
#include "generated/sub_820E1BE0.inc"
#include "generated/sub_820E1D90.inc"
#include "generated/sub_820E1D98.inc"
#include "generated/sub_820E1DA8.inc"
#include "generated/sub_820E1DB0.inc"
#include "generated/sub_820E1E00.inc"
#include "generated/sub_820E1E50.inc"
#include "generated/sub_820E1EA0.inc"
#include "generated/sub_820E1F00.inc"
#include "generated/sub_820E1F10.inc"
#include "generated/sub_820E1F20.inc"
#include "generated/sub_820E1F68.inc"
#include "generated/sub_820E1FB0.inc"
#include "generated/sub_820E1FC0.inc"
#include "generated/sub_820E2070.inc"
#include "generated/sub_820E2280.inc"
#include "generated/sub_820E2378.inc"
#include "generated/sub_820E24B0.inc"
#include "generated/sub_820E25A0.inc"
#include "generated/sub_820E26A8.inc"
#include "generated/sub_820E2AD0.inc"
#include "generated/sub_820E2B30.inc"
#include "generated/sub_820E2DD8.inc"
#include "generated/sub_820E32C8.inc"
#include "generated/sub_820E3370.inc"
#include "generated/sub_820E36D8.inc"
#include "generated/sub_820E3A18.inc"
#include "generated/sub_820E3C18.inc"
#include "generated/sub_820E3DF0.inc"
#include "generated/sub_820E40A8.inc"
#include "generated/sub_820E437C.inc"
#include "generated/sub_820E43BC.inc"
#include "generated/sub_820E44B0.inc"
#include "generated/sub_820E4580.inc"
#include "generated/sub_820E4DC0.inc"
#include "generated/sub_820E4E28.inc"
#include "generated/sub_820E4EB0.inc"
#include "generated/sub_820E5018.inc"
#include "generated/sub_820E5078.inc"
#include "generated/sub_820E50D8.inc"
#include "generated/sub_820E5138.inc"
#include "generated/sub_820E5198.inc"
#include "generated/sub_820E51F8.inc"
#include "generated/sub_820E5258.inc"
#include "generated/sub_820E52B8.inc"
#include "generated/sub_820E52C0.inc"
#include "generated/sub_820E52D8.inc"
#include "generated/sub_820E6070.inc"
#include "generated/sub_820E6C50.inc"
#include "generated/sub_820E6EE0.inc"
#include "generated/sub_820E7038.inc"
#include "generated/sub_820E7278.inc"
#include "generated/sub_820E7660.inc"
#include "generated/sub_820E7700.inc"
#include "generated/sub_820E7DE8.inc"
#include "generated/sub_820E7EB0.inc"
#include "generated/sub_820E7FE8.inc"
#include "generated/sub_820E81E8.inc"
#include "generated/sub_820E81F8.inc"
#include "generated/sub_820E8200.inc"
#include "generated/sub_820E8218.inc"
#include "generated/sub_820E8228.inc"
#include "generated/sub_820E8270.inc"
#include "generated/sub_820E8280.inc"
#include "generated/sub_820E82F8.inc"
#include "generated/sub_820E8350.inc"
#include "generated/sub_820E8360.inc"
#include "generated/sub_820E83C8.inc"
#include "generated/sub_820E8400.inc"
#include "generated/sub_820E8540.inc"
#include "generated/sub_820E8698.inc"
#include "generated/sub_820E8AC0.inc"
#include "generated/sub_820E8C10.inc"
#include "generated/sub_820E8CE8.inc"
#include "generated/sub_820E8CF8.inc"
#include "generated/sub_820E8D08.inc"
#include "generated/sub_820E8D10.inc"
#include "generated/sub_820E8D18.inc"
#include "generated/sub_820E8D20.inc"
#include "generated/sub_820E8D40.inc"
#include "generated/sub_820E8D48.inc"
#include "generated/sub_820E8D50.inc"
#include "generated/sub_820E8E68.inc"
#include "generated/sub_820E9750.inc"
#include "generated/sub_820E9D78.inc"
#include "generated/sub_820E9D80.inc"
#include "generated/sub_820E9D88.inc"
#include "generated/sub_820E9F00.inc"
#include "generated/sub_820EAA78.inc"
#include "generated/sub_820EAA80.inc"
#include "generated/sub_820EAAB8.inc"
#include "generated/sub_820EAAC0.inc"
#include "generated/sub_820EAAC8.inc"
#include "generated/sub_820EAAD0.inc"
#include "generated/sub_820EAAF0.inc"
#include "generated/sub_820EAB48.inc"
#include "generated/sub_820EAB98.inc"
#include "generated/sub_820EABA0.inc"
#include "generated/sub_820EABF8.inc"
#include "generated/sub_820EAC58.inc"
#include "generated/sub_820EAD20.inc"
#include "generated/sub_820EAE38.inc"
#include "generated/sub_820EAF40.inc"
#include "generated/sub_820EAF50.inc"
#include "generated/sub_820EAF58.inc"
#include "generated/sub_820EAF78.inc"
#include "generated/sub_820EAF80.inc"
#include "generated/sub_820EAF88.inc"
#include "generated/sub_820EAFA0.inc"
#include "generated/sub_820EAFA8.inc"
#include "generated/sub_820EB078.inc"
#include "generated/sub_820EB170.inc"
#include "generated/sub_820EB2C0.inc"
#include "generated/sub_820EB2C8.inc"
#include "generated/sub_820EB3E0.inc"
#include "generated/sub_820EBB60.inc"
#include "generated/sub_820EBCF8.inc"
#include "generated/sub_820EBF60.inc"
#include "generated/sub_820EC230.inc"
#include "generated/sub_820EC5D0.inc"
#include "generated/sub_820ECA70.inc"
#include "generated/sub_820ECC30.inc"
#include "generated/sub_820ECE30.inc"
#include "generated/sub_820ED060.inc"
#include "generated/sub_820ED2F8.inc"
#include "generated/sub_820ED608.inc"
#include "generated/sub_820ED920.inc"
#include "generated/sub_820EDD10.inc"
#include "generated/sub_820EE300.inc"
#include "generated/sub_820EEB50.inc"
#include "generated/sub_820EEDD8.inc"
#include "generated/sub_820EF0C0.inc"
#include "generated/sub_820EF480.inc"
#include "generated/sub_820EF940.inc"
#include "generated/sub_820EFCB0.inc"
#include "generated/sub_820EFF90.inc"
#include "generated/sub_820F02B8.inc"
#include "generated/sub_820F06B0.inc"
#include "generated/sub_820F0BB0.inc"
#include "generated/sub_820F0F58.inc"
#include "generated/sub_820F1270.inc"
#include "generated/sub_820F1608.inc"
#include "generated/sub_820F1AD0.inc"
#include "generated/sub_820F20F8.inc"
#include "generated/sub_820F24A0.inc"
#include "generated/sub_820F27D8.inc"
#include "generated/sub_820F2BB0.inc"
#include "generated/sub_820F30D0.inc"
#include "generated/sub_820F3760.inc"
#include "generated/sub_820F3B28.inc"
#include "generated/sub_820F3E58.inc"
#include "generated/sub_820F4218.inc"
#include "generated/sub_820F4730.inc"
#include "generated/sub_820F4DC0.inc"
#include "generated/sub_820F4ED8.inc"
#include "generated/sub_820F4FF8.inc"
#include "generated/sub_820F5120.inc"
#include "generated/sub_820F5260.inc"
#include "generated/sub_820F53C0.inc"
#include "generated/sub_820F54F8.inc"
#include "generated/sub_820F5638.inc"
#include "generated/sub_820F5798.inc"
#include "generated/sub_820F5940.inc"
#include "generated/sub_820F5B38.inc"
#include "generated/sub_820F5C68.inc"
#include "generated/sub_820F5DA0.inc"
#include "generated/sub_820F5F00.inc"
#include "generated/sub_820F60A0.inc"
#include "generated/sub_820F6288.inc"
#include "generated/sub_820F63D8.inc"
#include "generated/sub_820F6520.inc"
#include "generated/sub_820F6690.inc"
#include "generated/sub_820F6858.inc"
#include "generated/sub_820F6A80.inc"
#include "generated/sub_820F6C10.inc"
#include "generated/sub_820F6D58.inc"
#include "generated/sub_820F6EF0.inc"
#include "generated/sub_820F70D0.inc"
#include "generated/sub_820F7300.inc"
#include "generated/sub_820F7510.inc"
#include "generated/sub_820F76D0.inc"
#include "generated/sub_820F7908.inc"
#include "generated/sub_820F7BB8.inc"
#include "generated/sub_820F7EE8.inc"
#include "generated/sub_820F8100.inc"
#include "generated/sub_820F82C0.inc"
#include "generated/sub_820F8500.inc"
#include "generated/sub_820F87B0.inc"
#include "generated/sub_820F8AE0.inc"
#include "generated/sub_820F8D10.inc"
#include "generated/sub_820F8EF8.inc"
#include "generated/sub_820F9158.inc"
#include "generated/sub_820F9440.inc"
#include "generated/sub_820F97B8.inc"
#include "generated/sub_820F9890.inc"
#include "generated/sub_820F9968.inc"
#include "generated/sub_820F9A40.inc"
#include "generated/sub_820F9B18.inc"
#include "generated/sub_820F9BF0.inc"
#include "generated/sub_820F9CC8.inc"
#include "generated/sub_820F9DA0.inc"
#include "generated/sub_820F9E78.inc"
#include "generated/sub_820F9F48.inc"
#include "generated/sub_820FA018.inc"
#include "generated/sub_820FA0E8.inc"
#include "generated/sub_820FA1B8.inc"
#include "generated/sub_820FA290.inc"
#include "generated/sub_820FA368.inc"
#include "generated/sub_820FA440.inc"
#include "generated/sub_820FA518.inc"
#include "generated/sub_820FA6D8.inc"
#include "generated/sub_820FA8E8.inc"
#include "generated/sub_820FAC28.inc"
#include "generated/sub_820FAE30.inc"
#include "generated/sub_820FB040.inc"
#include "generated/sub_820FB390.inc"
#include "generated/sub_820FB638.inc"
#include "generated/sub_820FB870.inc"
#include "generated/sub_820FBAD8.inc"
#include "generated/sub_820FBE60.inc"
#include "generated/sub_820FBEB8.inc"
#include "generated/sub_820FC2B8.inc"
#include "generated/sub_820FC750.inc"
#include "generated/sub_820FC7C0.inc"
#include "generated/sub_820FC800.inc"
#include "generated/sub_820FC9C8.inc"
#include "generated/sub_820FC9D8.inc"
#include "generated/sub_820FC9E0.inc"
#include "generated/sub_820FCA58.inc"
#include "generated/sub_820FCA98.inc"
#include "generated/sub_820FCBE8.inc"
#include "generated/sub_820FCCE0.inc"
#include "generated/sub_820FD330.inc"
#include "generated/sub_820FD380.inc"
#include "generated/sub_820FD3D0.inc"
#include "generated/sub_820FD400.inc"
#include "generated/sub_820FD448.inc"
#include "generated/sub_820FD7C8.inc"
#include "generated/sub_820FDA18.inc"
#include "generated/sub_820FDAD8.inc"
#include "generated/sub_820FDB18.inc"
#include "generated/sub_820FDDC8.inc"
#include "generated/sub_820FE340.inc"
#include "generated/sub_820FE5F8.inc"
#include "generated/sub_820FEBB0.inc"
#include "generated/sub_820FF698.inc"
#include "generated/sub_820FF7D0.inc"
#include "generated/sub_820FF8D8.inc"
#include "generated/sub_820FF9C8.inc"
#include "generated/sub_820FFBD8.inc"
#include "generated/sub_821009F8.inc"
#include "generated/sub_82100E68.inc"
#include "generated/sub_82101498.inc"
#include "generated/sub_82101730.inc"
#include "generated/sub_82101B18.inc"
#include "generated/sub_821020F0.inc"
#include "generated/sub_82102420.inc"
#include "generated/sub_821026C8.inc"
#include "generated/sub_821038F8.inc"
#include "generated/sub_82103E58.inc"
#include "generated/sub_82103EA0.inc"
#include "generated/sub_82104130.inc"
#include "generated/sub_82104228.inc"
#include "generated/sub_82104FE0.inc"
#include "generated/sub_82105BB0.inc"
#include "generated/sub_82106110.inc"
#include "generated/sub_82106C68.inc"
#include "generated/sub_82106E60.inc"
#include "generated/sub_82107BF8.inc"
#include "generated/sub_82107C70.inc"
#include "generated/sub_82107D28.inc"
#include "generated/sub_82108138.inc"
#include "generated/sub_82108468.inc"
#include "generated/sub_82108D50.inc"
#include "generated/sub_82108DB0.inc"
#include "generated/sub_82108EF8.inc"
#include "generated/sub_82108F20.inc"
#include "generated/sub_82108FD8.inc"
#include "generated/sub_821091F8.inc"
#include "generated/sub_82109470.inc"
#include "generated/sub_82109570.inc"
#include "generated/sub_821095A0.inc"
#include "generated/sub_821095C0.inc"
#include "generated/sub_82109608.inc"
#include "generated/sub_82109668.inc"
#include "generated/sub_821096C8.inc"
#include "generated/sub_82109798.inc"
#include "generated/sub_82109820.inc"
#include "generated/sub_82109970.inc"
#include "generated/sub_82109AF0.inc"
#include "generated/sub_82109F48.inc"
#include "generated/sub_82109F58.inc"
#include "generated/sub_8210A250.inc"
#include "generated/sub_8210A298.inc"
#include "generated/sub_8210A300.inc"
#include "generated/sub_8210A320.inc"
#include "generated/sub_8210A338.inc"
#include "generated/sub_8210A498.inc"
#include "generated/sub_8210A520.inc"
#include "generated/sub_8210A5C8.inc"
#include "generated/sub_8210A680.inc"
#include "generated/sub_8210A6E8.inc"
#include "generated/sub_8210A7A0.inc"
#include "generated/sub_8210AF48.inc"
#include "generated/sub_8210AFD8.inc"
#include "generated/sub_8210B0E8.inc"
#include "generated/sub_8210B140.inc"
#include "generated/sub_8210B1A8.inc"
#include "generated/sub_8210B1B8.inc"
#include "generated/sub_8210B1C8.inc"
#include "generated/sub_8210B1D0.inc"
#include "generated/sub_8210B1D8.inc"
#include "generated/sub_8210B1E0.inc"
#include "generated/sub_8210B230.inc"
#include "generated/sub_8210B248.inc"
#include "generated/sub_8210B268.inc"
#include "generated/sub_8210B348.inc"
#include "generated/sub_8210B350.inc"
#include "generated/sub_8210B358.inc"
#include "generated/sub_8210B3B8.inc"
#include "generated/sub_8210B418.inc"
#include "generated/sub_8210B428.inc"
#include "generated/sub_8210B458.inc"
#include "generated/sub_8210B488.inc"
#include "generated/sub_8210B4B8.inc"
#include "generated/sub_8210B4E8.inc"
#include "generated/sub_8210B588.inc"
#include "generated/sub_8210B5B8.inc"
#include "generated/sub_8210B610.inc"
#include "generated/sub_8210B660.inc"
#include "generated/sub_8210B690.inc"
#include "generated/sub_8210B6C8.inc"
#include "generated/sub_8210B6F0.inc"
#include "generated/sub_8210B760.inc"
#include "generated/sub_8210B7A8.inc"
#include "generated/sub_8210B870.inc"
#include "generated/sub_8210B8E8.inc"
#include "generated/sub_8210B948.inc"
#include "generated/sub_8210B958.inc"
#include "generated/sub_8210BC40.inc"
#include "generated/sub_8210BC5C.inc"
#include "generated/sub_8210BD30.inc"
#include "generated/sub_8210BD90.inc"
#include "generated/sub_8210C660.inc"
#include "generated/sub_8210C978.inc"
#include "generated/sub_8210CA60.inc"
#include "generated/sub_8210CB1C.inc"
#include "generated/sub_8210D270.inc"
#include "generated/sub_8210D278.inc"
#include "generated/sub_8210D3B8.inc"
#include "generated/sub_8210D540.inc"
#include "generated/sub_8210D668.inc"
#include "generated/sub_8210D758.inc"
#include "generated/sub_8210D830.inc"
#include "generated/sub_8210D918.inc"
#include "generated/sub_8210D974.inc"
#include "generated/sub_8210D978.inc"
#include "generated/sub_8210D9B0.inc"
#include "generated/sub_8210E290.inc"
#include "generated/sub_8210F720.inc"
#include "generated/sub_8210F888.inc"
#include "generated/sub_8210FA50.inc"
#include "generated/sub_8210FAF8.inc"
#include "generated/sub_8210FC10.inc"
#include "generated/sub_8210FD48.inc"
#include "generated/sub_8210FDF0.inc"
#include "generated/sub_8210FEB8.inc"
#include "generated/sub_8210FF60.inc"
#include "generated/sub_82110EA8.inc"
#include "generated/sub_821110E8.inc"
#include "generated/sub_821126B8.inc"
#include "generated/sub_821127D0.inc"
#include "generated/sub_82112B68.inc"
#include "generated/sub_82112FA0.inc"
#include "generated/sub_82112FF0.inc"
#include "generated/sub_82113920.inc"
#include "generated/sub_821139E0.inc"
#include "generated/sub_82113B00.inc"
#include "generated/sub_82114820.inc"
#include "generated/sub_82114870.inc"
#include "generated/sub_82114E38.inc"
#include "generated/sub_82115138.inc"
#include "generated/sub_82115148.inc"
#include "generated/sub_82115330.inc"
#include "generated/sub_821153F8.inc"
#include "generated/sub_82115474.inc"
#include "generated/sub_821156E0.inc"
#include "generated/sub_82115E58.inc"
#include "generated/sub_82116318.inc"
#include "generated/sub_82117510.inc"
#include "generated/sub_82117BF8.inc"
#include "generated/sub_82117C50.inc"
#include "generated/sub_821181D0.inc"
#include "generated/sub_82118338.inc"
#include "generated/sub_82118550.inc"
#include "generated/sub_821185F0.inc"
#include "generated/sub_82118638.inc"
#include "generated/sub_821187C8.inc"
#include "generated/sub_82118A10.inc"
#include "generated/sub_82118CB8.inc"
#include "generated/sub_82118D48.inc"
#include "generated/sub_82119180.inc"
#include "generated/sub_821191D0.inc"
#include "generated/sub_82119840.inc"
#include "generated/sub_821199D0.inc"
#include "generated/sub_82119B40.inc"
#include "generated/sub_82119BC0.inc"
#include "generated/sub_82119C18.inc"
#include "generated/sub_82119D08.inc"
#include "generated/sub_82119E48.inc"
#include "generated/sub_82119E58.inc"
#include "generated/sub_82119E70.inc"
#include "generated/sub_82119EC8.inc"
#include "generated/sub_82119F20.inc"
#include "generated/sub_8211A240.inc"
#include "generated/sub_8211A318.inc"
#include "generated/sub_8211A598.inc"
#include "generated/sub_8211AFF8.inc"
#include "generated/sub_8211B0B0.inc"
#include "generated/sub_8211B100.inc"
#include "generated/sub_8211B2A0.inc"
#include "generated/sub_8211B488.inc"
#include "generated/sub_8211B690.inc"
#include "generated/sub_8211BCC0.inc"
#include "generated/sub_8211C470.inc"
#include "generated/sub_8211C9A0.inc"
#include "generated/sub_8211CA20.inc"
#include "generated/sub_8211CBC0.inc"
#include "generated/sub_8211CC70.inc"
#include "generated/sub_8211CE50.inc"
#include "generated/sub_8211CF88.inc"
#include "generated/sub_8211D1F8.inc"
#include "generated/sub_8211D278.inc"
#include "generated/sub_8211D320.inc"
#include "generated/sub_8211E308.inc"
#include "generated/sub_8211E990.inc"
#include "generated/sub_8211EA80.inc"
#include "generated/sub_8211ED58.inc"
#include "generated/sub_8211EE88.inc"
#include "generated/sub_8211F548.inc"
#include "generated/sub_8211F840.inc"
#include "generated/sub_8211FA68.inc"
#include "generated/sub_8211FB60.inc"
#include "generated/sub_8211FBB0.inc"
#include "generated/sub_8211FCD8.inc"
#include "generated/sub_821200B8.inc"
#include "generated/sub_821207A8.inc"
#include "generated/sub_82120830.inc"
#include "generated/sub_821209A0.inc"
#include "generated/sub_82120D18.inc"
#include "generated/sub_821210D8.inc"
#include "generated/sub_821210E0.inc"
#include "generated/sub_821210E8.inc"
#include "generated/sub_82121180.inc"
#include "generated/sub_821212C0.inc"
#include "generated/sub_82121A18.inc"
#include "generated/sub_82121A98.inc"
#include "generated/sub_82121C30.inc"
#include "generated/sub_82121C48.inc"
#include "generated/sub_82122020.inc"
#include "generated/sub_821221B0.inc"
#include "generated/sub_82122268.inc"
#include "generated/sub_82122370.inc"
#include "generated/sub_82122CE0.inc"
#include "generated/sub_82122D00.inc"
#include "generated/sub_82122D08.inc"
#include "generated/sub_82122D28.inc"
#include "generated/sub_82122F44.inc"
#include "generated/sub_82122F48.inc"
#include "generated/sub_82122FC0.inc"
#include "generated/sub_82123600.inc"
#include "generated/sub_821236CC.inc"
#include "generated/sub_82123808.inc"
#include "generated/sub_82123A50.inc"
#include "generated/sub_82123AA0.inc"
#include "generated/sub_82123CD0.inc"
#include "generated/sub_82123D50.inc"
#include "generated/sub_82123DB0.inc"
#include "generated/sub_82123E18.inc"
#include "generated/sub_82123EE8.inc"
#include "generated/sub_82123FA0.inc"
#include "generated/sub_821242C8.inc"
#include "generated/sub_821245D8.inc"
#include "generated/sub_82124CE0.inc"
#include "generated/sub_82124E98.inc"
#include "generated/sub_82125130.inc"
#include "generated/sub_82125430.inc"
#include "generated/sub_82125690.inc"
#include "generated/sub_82125828.inc"
#include "generated/sub_82125998.inc"
#include "generated/sub_82125DE8.inc"
#include "generated/sub_82125F28.inc"
#include "generated/sub_82125FB0.inc"
#include "generated/sub_82125FF4.inc"
#include "generated/sub_82125FF8.inc"
#include "generated/sub_82126034.inc"
#include "generated/sub_82126038.inc"
#include "generated/sub_82126074.inc"
#include "generated/sub_821260AC.inc"
#include "generated/sub_821270E0.inc"
#include "generated/sub_82127100.inc"
#include "generated/sub_82127108.inc"
#include "generated/sub_82127120.inc"
#include "generated/sub_82127188.inc"
#include "generated/sub_8212727C.inc"
#include "generated/sub_821272B0.inc"
#include "generated/sub_821272F4.inc"
#include "generated/sub_82127320.inc"
#include "generated/sub_821273B4.inc"
#include "generated/sub_821273E0.inc"
#include "generated/sub_82127648.inc"
#include "generated/sub_82127728.inc"
#include "generated/sub_82127BE8.inc"
#include "generated/sub_82127CE0.inc"
#include "generated/sub_82127D38.inc"
#include "generated/sub_82127E10.inc"
#include "generated/sub_821285B8.inc"
#include "generated/sub_82128890.inc"
#include "generated/sub_82128948.inc"
#include "generated/sub_82128A08.inc"
#include "generated/sub_82128A28.inc"
#include "generated/sub_82129078.inc"
#include "generated/sub_82129110.inc"
#include "generated/sub_82129190.inc"
#include "generated/sub_821292B4.inc"
#include "generated/sub_821292D8.inc"
#include "generated/sub_82129304.inc"
#include "generated/sub_82129370.inc"
#include "generated/sub_8212940C.inc"
#include "generated/sub_8212942C.inc"
#include "generated/sub_82129468.inc"
#include "generated/sub_82129618.inc"
#include "generated/sub_82129984.inc"
#include "generated/sub_82129990.inc"
#include "generated/sub_8212A0A0.inc"
#include "generated/sub_8212A100.inc"
#include "generated/sub_8212A200.inc"
#include "generated/sub_8212A220.inc"
#include "generated/sub_8212A260.inc"
#include "generated/sub_8212A270.inc"
#include "generated/sub_8212A4E8.inc"
#include "generated/sub_8212A598.inc"
#include "generated/sub_8212B338.inc"
#include "generated/sub_8212B370.inc"
#include "generated/sub_8212B540.inc"
#include "generated/sub_8212B598.inc"
#include "generated/sub_8212B5C8.inc"
#include "generated/sub_8212B5F0.inc"
#include "generated/sub_8212B610.inc"
#include "generated/sub_8212B618.inc"
#include "generated/sub_8212B6B0.inc"
#include "generated/sub_8212B778.inc"
#include "generated/sub_8212B7B0.inc"
#include "generated/sub_8212B830.inc"
#include "generated/sub_8212B8A8.inc"
#include "generated/sub_8212B8F0.inc"
#include "generated/sub_8212BA48.inc"
#include "generated/sub_8212BB00.inc"
#include "generated/sub_8212BB58.inc"
#include "generated/sub_8212BC08.inc"
#include "generated/sub_8212BCB8.inc"
#include "generated/sub_8212BCE0.inc"
#include "generated/sub_8212BEB0.inc"
#include "generated/sub_8212BED0.inc"
#include "generated/sub_8212C038.inc"
#include "generated/sub_8212C078.inc"
#include "generated/sub_8212C0E8.inc"
#include "generated/sub_8212C138.inc"
#include "generated/sub_8212C178.inc"
#include "generated/sub_8212C2E0.inc"
#include "generated/sub_8212C3AC.inc"
#include "generated/sub_8212DE60.inc"
#include "generated/sub_8212E680.inc"
#include "generated/sub_8212E6A8.inc"
#include "generated/sub_8212E780.inc"
#include "generated/sub_8212E8B0.inc"
#include "generated/sub_8212E968.inc"
#include "generated/sub_8212EA48.inc"
#include "generated/sub_8212EB60.inc"
#include "generated/sub_8212EB80.inc"
#include "generated/sub_8212EBB8.inc"
#include "generated/sub_8212EC20.inc"
#include "generated/sub_8212F024.inc"
#include "generated/sub_8212F088.inc"
#include "generated/sub_8212F1B0.inc"
#include "generated/sub_8212F1D0.inc"
#include "generated/sub_8212F40C.inc"
#include "generated/sub_8212F4B8.inc"
#include "generated/sub_8212F558.inc"
#include "generated/sub_8212F610.inc"
#include "generated/sub_8212F630.inc"
#include "generated/sub_8212F690.inc"
#include "generated/sub_8212F698.inc"
#include "generated/sub_8212F6A0.inc"
#include "generated/sub_8212F6A8.inc"
#include "generated/sub_8212F920.inc"
#include "generated/sub_8212FA38.inc"
#include "generated/sub_8212FE80.inc"
#include "generated/sub_82130048.inc"
#include "generated/sub_82130130.inc"
#include "generated/sub_82130280.inc"
#include "generated/sub_821302D0.inc"
#include "generated/sub_82130330.inc"
#include "generated/sub_8213037C.inc"
#include "generated/sub_82130390.inc"
#include "generated/sub_821303D4.inc"
#include "generated/sub_821304C4.inc"
#include "generated/sub_821304E8.inc"
#include "generated/sub_82130588.inc"
#include "generated/sub_82130990.inc"
#include "generated/sub_82130BE8.inc"
#include "generated/sub_82130C30.inc"
#include "generated/sub_82130C78.inc"
#include "generated/sub_82130D80.inc"
#include "generated/sub_82130E00.inc"
#include "generated/sub_82130EF0.inc"
#include "generated/sub_82130F20.inc"
#include "generated/sub_82130F30.inc"
#include "generated/sub_82130F54.inc"
#include "generated/sub_82130F74.inc"
#include "generated/sub_82130F84.inc"
#include "generated/sub_82130FA0.inc"
#include "generated/sub_82131048.inc"
#include "generated/sub_82131070.inc"
#include "generated/sub_82131128.inc"
#include "generated/sub_82131168.inc"
#include "generated/sub_82131188.inc"
#include "generated/sub_82131238.inc"
#include "generated/sub_821312C0.inc"
#include "generated/sub_82131438.inc"
#include "generated/sub_82131478.inc"
#include "generated/sub_821314A0.inc"
#include "generated/sub_821314E8.inc"
#include "generated/sub_82131570.inc"
#include "generated/sub_82131598.inc"
#include "generated/sub_82131668.inc"
#include "generated/sub_821318E4.inc"
#include "generated/sub_821318F8.inc"
#include "generated/sub_82131A18.inc"
#include "generated/sub_82131A28.inc"
#include "generated/sub_82131B70.inc"
#include "generated/sub_82131CE0.inc"
#include "generated/sub_82131FA0.inc"
#include "generated/sub_821321A8.inc"
#include "generated/sub_821321B8.inc"
#include "generated/sub_821321D0.inc"
#include "generated/sub_82132470.inc"
#include "generated/sub_82132490.inc"
#include "generated/sub_821324D8.inc"
#include "generated/sub_82132598.inc"
#include "generated/sub_821327D8.inc"
#include "generated/sub_821336C0.inc"
#include "generated/sub_82134740.inc"
#include "generated/sub_821349D0.inc"
#include "generated/sub_82134A28.inc"
#include "generated/sub_82134A40.inc"
#include "generated/sub_82134AE8.inc"
#include "generated/sub_82134B90.inc"
#include "generated/sub_82134D18.inc"
#include "generated/sub_82134DF8.inc"
#include "generated/sub_82134E98.inc"
#include "generated/sub_82134EA0.inc"
#include "generated/sub_82134F20.inc"
#include "generated/sub_82134F50.inc"
#if defined(CC_FLAT_WINDOW) && !defined(CC_WINDOW_NOMASK)
// Context restore: besides the stack's back chain (bridge.cpp REX_LOAD_U32)
// the one place r1 is loaded from memory. Flat window stack accesses skip
// the offset mask, so r1 is kept below 0x20000000 here too (a valid stack
// pointer is unchanged).
#define sub_82134FAC sub_82134FAC_exact
#include "generated/sub_82134FAC.inc"
#undef sub_82134FAC
static void sub_82134FAC(Context& ctx, Machine& base) {
  sub_82134FAC_exact(ctx, base);
  ctx.r1.u32 &= ::cc_win::kLowMask;
}
#else
#include "generated/sub_82134FAC.inc"
#endif
#include "generated/sub_82135070.inc"
#include "generated/sub_82135090.inc"
#include "generated/sub_82135134.inc"
#include "generated/sub_8213513C.inc"
#include "generated/sub_82135160.inc"
#include "generated/sub_82135608.inc"
#include "generated/sub_82136280.inc"
#include "generated/sub_82136720.inc"
#include "generated/sub_82136738.inc"
#if defined(CC_FLAT_WINDOW) && !defined(CC_WINDOW_NOMASK)
// stwux r1,r1,r12 moves r1 by a register amount in this function, so its
// stack accesses take the masked path (a bad amount must not carry r1 out of
// the window, see CC_R1_CHAIN in bridge.cpp).
#pragma push_macro("CC_R1_ADDR")
#undef CC_R1_ADDR
#define CC_R1_ADDR(a) false
#endif
#include "generated/sub_821367A0.inc"
#if defined(CC_FLAT_WINDOW) && !defined(CC_WINDOW_NOMASK)
#pragma pop_macro("CC_R1_ADDR")
#endif
#include "generated/sub_821368F0.inc"
#include "generated/sub_82136A00.inc"
#include "generated/sub_82136BD0.inc"
#include "generated/sub_82137160.inc"
#include "generated/sub_82137484.inc"
#include "generated/sub_82137950.inc"
#include "generated/sub_82137CE0.inc"
#include "generated/sub_821382C0.inc"
#include "generated/sub_82138308.inc"
#include "generated/sub_82138678.inc"
#include "generated/sub_82138E50.inc"
#include "generated/sub_82138F38.inc"
#include "generated/sub_82139010.inc"
#include "generated/sub_82139310.inc"
#include "generated/sub_82139768.inc"
#include "generated/sub_82139790.inc"
#include "generated/sub_82139818.inc"
#include "generated/sub_82139888.inc"
#include "generated/sub_821398F8.inc"
#include "generated/sub_82139920.inc"
#include "generated/sub_821399D8.inc"
#include "generated/sub_82139A60.inc"
#include "generated/sub_82139AB8.inc"
#include "generated/sub_82139AE8.inc"
#include "generated/sub_82139AF0.inc"
#include "generated/sub_82139BA8.inc"
#include "generated/sub_8213A3B0.inc"
#include "generated/sub_8213A420.inc"
#include "generated/sub_8213A490.inc"
#include "generated/sub_8213A598.inc"
#include "generated/sub_8213A5F8.inc"
#include "generated/sub_8213A6B8.inc"
#include "generated/sub_8213A710.inc"
#include "generated/sub_8213A778.inc"
#include "generated/sub_8213A800.inc"
#include "generated/sub_8213A870.inc"
#include "generated/sub_8213B0A8.inc"
#include "generated/sub_8213B160.inc"
#include "generated/sub_8213B320.inc"
#include "generated/sub_8213B510.inc"
#include "generated/sub_8213B528.inc"
#include "generated/sub_8213B728.inc"
#include "generated/sub_8213B9A0.inc"
#include "generated/sub_8213BA40.inc"
#include "generated/sub_8213BBA0.inc"
#include "generated/sub_8213BBB8.inc"
#include "generated/sub_8213BF98.inc"
#include "generated/sub_8213C228.inc"
#include "generated/sub_8213C348.inc"
#include "generated/sub_8213C3C0.inc"
#include "generated/sub_8213C748.inc"
#include "generated/sub_8213C948.inc"
#include "generated/sub_8213CDC8.inc"
#include "generated/sub_8213CDF8.inc"
#include "generated/sub_8213CE20.inc"
#include "generated/sub_8213CE48.inc"
#include "generated/sub_8213CF40.inc"
#include "generated/sub_8213D1B8.inc"
#include "generated/sub_8213D458.inc"
#include "generated/sub_8213D658.inc"
#include "generated/sub_8213D760.inc"
#include "generated/sub_8213D790.inc"
#include "generated/sub_8213DE78.inc"
#include "generated/sub_8213DEF0.inc"
#include "generated/sub_8213DF68.inc"
#include "generated/sub_8213E008.inc"
#include "generated/sub_8213E090.inc"
#include "generated/sub_8213E108.inc"
#include "generated/sub_8213E130.inc"
#include "generated/sub_8213E520.inc"
#include "generated/sub_8213E568.inc"
#include "generated/sub_8213E590.inc"
#include "generated/sub_8213E620.inc"
#include "generated/sub_8213E780.inc"
#include "generated/sub_8213E7A8.inc"
#include "generated/sub_8213E7D0.inc"
#include "generated/sub_8213F040.inc"
#include "generated/sub_8213F098.inc"
#include "generated/sub_8213F108.inc"
#include "generated/sub_8213F230.inc"
#include "generated/sub_8213F300.inc"
#include "generated/sub_8213F3D0.inc"
#include "generated/sub_8213F608.inc"
#include "generated/sub_8213F718.inc"
#include "generated/sub_8213F990.inc"
#include "generated/sub_8213FB58.inc"
#include "generated/sub_82141448.inc"
#include "generated/sub_82141B40.inc"
#include "generated/sub_82141CF8.inc"
#include "generated/sub_82141E18.inc"
#include "generated/sub_821420D0.inc"
#include "generated/sub_82142228.inc"
#include "generated/sub_821422C0.inc"
#include "generated/sub_82142578.inc"
#include "generated/sub_821426F8.inc"
#include "generated/sub_82142768.inc"
#include "generated/sub_821429C0.inc"
#include "generated/sub_82142AA8.inc"
#include "generated/sub_82142C60.inc"
#include "generated/sub_82142EE0.inc"
#include "generated/sub_821430F0.inc"
#include "generated/sub_821432E0.inc"
#include "generated/sub_82143798.inc"
#include "generated/sub_82143AE0.inc"
#include "generated/sub_82143BD8.inc"
#include "generated/sub_82143BF0.inc"
#include "generated/sub_82143C68.inc"
#include "generated/sub_82143EF0.inc"
#include "generated/sub_82144188.inc"
#include "generated/sub_821441E0.inc"
#include "generated/sub_82144280.inc"
#include "generated/sub_821442D0.inc"
#include "generated/sub_82144350.inc"
#include "generated/sub_821443A8.inc"
#include "generated/sub_82144778.inc"
#include "generated/sub_82144800.inc"
#include "generated/sub_821449E0.inc"
#include "generated/sub_82144B48.inc"
#include "generated/sub_82144CF0.inc"
#include "generated/sub_82144F08.inc"
#include "generated/sub_821450A8.inc"
#include "generated/sub_821451C8.inc"
#include "generated/sub_821452A8.inc"
#include "generated/sub_821452E8.inc"
#include "generated/sub_82145328.inc"
#include "generated/sub_82145480.inc"
#include "generated/sub_821454B0.inc"
#include "generated/sub_821454E8.inc"
#include "generated/sub_82145510.inc"
#include "generated/sub_82145718.inc"
#include "generated/sub_82145928.inc"
#include "generated/sub_821459D0.inc"
#include "generated/sub_82145A30.inc"
#include "generated/sub_82145B18.inc"
#include "generated/sub_82145BE8.inc"
#include "generated/sub_82145ED8.inc"
#include "generated/sub_82145F80.inc"
#include "generated/sub_82146158.inc"
#include "generated/sub_821461A0.inc"
#include "generated/sub_82146340.inc"
#include "generated/sub_82146480.inc"
#include "generated/sub_82146608.inc"
#include "generated/sub_821467A0.inc"
#include "generated/sub_82146810.inc"
#include "generated/sub_82146860.inc"
#include "generated/sub_821469B0.inc"
#include "generated/sub_821469E8.inc"
#include "generated/sub_82146B70.inc"
#include "generated/sub_82146CD0.inc"
#include "generated/sub_82146E58.inc"
#include "generated/sub_821470D8.inc"
#include "generated/sub_82147180.inc"
#include "generated/sub_821475F0.inc"
#include "generated/sub_82147760.inc"
#include "generated/sub_82147808.inc"
#include "generated/sub_82147C28.inc"
#include "generated/sub_82147E10.inc"
#include "generated/sub_82147E50.inc"
#include "generated/sub_82147F78.inc"
#include "generated/sub_821480B8.inc"
#include "generated/sub_82148488.inc"
#include "generated/sub_821485A8.inc"
#include "generated/sub_821486D0.inc"
#include "generated/sub_821489C0.inc"
#include "generated/sub_82148C18.inc"
#include "generated/sub_82148C88.inc"
#include "generated/sub_82148DC8.inc"
#include "generated/sub_82148ED8.inc"
#include "generated/sub_82148EE0.inc"
#include "generated/sub_82148F38.inc"
#include "generated/sub_82148FA8.inc"
#include "generated/sub_82149030.inc"
#include "generated/sub_821491F0.inc"
#include "generated/sub_821492C0.inc"
#include "generated/sub_82149300.inc"
#include "generated/sub_821494C0.inc"
#include "generated/sub_82149628.inc"
#include "generated/sub_82149780.inc"
#include "generated/sub_82149828.inc"
#include "generated/sub_82149910.inc"
#include "generated/sub_82149F48.inc"
#include "generated/sub_82149FC0.inc"
#include "generated/sub_8214A028.inc"
#include "generated/sub_8214A040.inc"
#include "generated/sub_8214A0A8.inc"
#include "generated/sub_8214A110.inc"
#include "generated/sub_8214A178.inc"
#include "generated/sub_8214A188.inc"
#include "generated/sub_8214A1A0.inc"
#include "generated/sub_8214A1B8.inc"
#include "generated/sub_8214A1D0.inc"
#include "generated/sub_820864D0.inc"
#include "generated/sub_8208CD68.inc"
#include "generated/sub_8208CEA8.inc"
#include "generated/sub_8208CD38.inc"
#include "generated/sub_82094678.inc"
#ifdef CC_FAST
#define sub_82084EE0 sub_82084EE0_exact
#endif
#include "generated/sub_82084EE0.inc"
#ifdef CC_FAST
#undef sub_82084EE0
// Display-list sort by depth (exact sub_82084EE0: list r3, linked through
// +88): a bottom-up merge sort on the signed depth +28 that takes the left
// node on ties, i.e. a stable sort, rewriting the head word and every
// link. Here the nodes are read once; an already sorted list is left as it
// is (the original writes the same links back), otherwise a stable
// insertion sort runs and only the links that change are written. The
// name cache sees a change of order only. Lists longer than the buffer
// take the exact body.
// The insertion sort is quadratic at worst: past 4 element moves per node
// (4P level 13 fight: ~0.4 sorts a frame of ~560 nodes, ~150 moves a sort,
// at most 1,824 seen) the rest is done by merging the ascending runs. A
// stable sort's result is unique, and the partly sorted prefix followed by
// the untouched suffix keeps every tie in list order, so the merge ends in
// the same order. Host CC_SORT_MERGE=1 merges every reordered list and
// CC_SORT_BUDGET=<moves per node> changes the limit (to check those paths
// against the hashes and the CC_ORACLE comparison).
struct CcDlSortEnt { uint32_t node; int32_t depth; uint32_t next; };
static CcDlSortEnt g_dl_sort_buf[2048];
static CcDlSortEnt g_dl_sort_tmp[2048];
// Stable merge sort of a[0..n) by depth over its ascending runs (a tie
// takes the left run's entry first), pass by pass until one run is left.
static void cc_dl_merge_runs(CcDlSortEnt* a, uint32_t n) {
  CcDlSortEnt* src = a;
  CcDlSortEnt* dst = g_dl_sort_tmp;
  for (;;) {
    uint32_t m = 1u;
    while (m < n && src[m - 1u].depth <= src[m].depth) ++m;
    if (m >= n) break;
    for (uint32_t i = 0; i < n;) {
      m = i + 1u;
      while (m < n && src[m - 1u].depth <= src[m].depth) ++m;
      uint32_t e = m;
      if (e < n) {
        ++e;
        while (e < n && src[e - 1u].depth <= src[e].depth) ++e;
      }
      uint32_t l = i, r = m, o = i;
      while (l < m && r < e) dst[o++] = src[r].depth < src[l].depth ? src[r++] : src[l++];
      while (l < m) dst[o++] = src[l++];
      while (r < e) dst[o++] = src[r++];
      i = e;
    }
    CcDlSortEnt* const t = src;
    src = dst;
    dst = t;
  }
  if (src != a)
    for (uint32_t i = 0; i < n; ++i) a[i] = src[i];
}
static CC_HOT_FN void sub_82084EE0(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  static const bool exact = std::getenv("CC_SORT_EXACT") != nullptr;  // host A/B switch
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr || std::getenv("CC_REFRESH_ORACLE") != nullptr;
  static const bool merge_always = std::getenv("CC_SORT_MERGE") != nullptr;
  static const uint32_t per_node = [] { const char* e = std::getenv("CC_SORT_BUDGET"); return e ? uint32_t(std::atoi(e)) : 4u; }();
#elif defined(CC_SORT_EXACT_BUILD)
  constexpr bool exact = true;  // Xbox bisect build
  constexpr bool merge_always = false;
  constexpr uint32_t per_node = 4u;
#else
  constexpr bool exact = false;
  constexpr bool merge_always = false;
  constexpr uint32_t per_node = 4u;
#endif
  const uint32_t list = ctx.r3.u32;
  if (exact) { sub_82084EE0_exact(ctx, base); cc_dl_list_changed(list); return; }
  CcDlSortEnt* const a = g_dl_sort_buf;
  uint32_t cnt = 0u;
  bool sorted = true;
  int32_t prev = INT32_MIN;
  for (uint32_t n = REX_LOAD_U32(list); n;) {
    if (cnt == 2048u) { sub_82084EE0_exact(ctx, base); cc_dl_list_changed(list); return; }
    const uint32_t next = REX_LOAD_U32(n + 88u);
    if (next) { cc_prefetch(next + 28u); cc_prefetch(next + 88u); }
    const int32_t d = int32_t(REX_LOAD_U32(n + 28u));
    if (d < prev) sorted = false;
    prev = d;
    a[cnt++] = {n, d, next};
    n = next;
  }
#ifndef CC_XBOX_DRIVER
  ++g_dl_rst.sorts;
  g_dl_rst.sort_nodes += cnt;
#endif
  if (sorted) {
#ifndef CC_XBOX_DRIVER
    if (oracle) {  // the exact body must leave the same order
      sub_82084EE0_exact(ctx, base);
      uint32_t k = 0;
      for (uint32_t n = REX_LOAD_U32(list); n; n = REX_LOAD_U32(n + 88u), ++k)
        if (k >= cnt || a[k].node != n) { cc_oracle_mismatch("sub_82084EE0 sorted", int(k), n, k < cnt ? a[k].node : 0u); break; }
    }
#endif
    return;
  }
  uint32_t moves = 0u;
  bool merged = merge_always;
  if (merged) {
    cc_dl_merge_runs(a, cnt);
  } else {
    const uint32_t budget = per_node * cnt;
    for (uint32_t i = 1; i < cnt; ++i) {
      const CcDlSortEnt x = a[i];
      uint32_t j = i;
      for (; j > 0u && a[j - 1u].depth > x.depth; --j) a[j] = a[j - 1u];
      a[j] = x;
      moves += i - j;
      if (moves > budget) {
        cc_dl_merge_runs(a, cnt);
        merged = true;
        break;
      }
    }
  }
  static_cast<void>(merged);
#ifndef CC_XBOX_DRIVER
  if (merged) ++g_dl_rst.sort_merges;
  g_dl_rst.sort_moves += moves;
  if (moves > g_dl_rst.sort_moves_max) g_dl_rst.sort_moves_max = moves;
  if (cnt > g_dl_rst.sort_nodes_max) g_dl_rst.sort_nodes_max = cnt;
  ++g_dl_rst.sorts_changed;
  if (oracle) {
    sub_82084EE0_exact(ctx, base);
    uint32_t k = 0;
    for (uint32_t n = REX_LOAD_U32(list); n; n = REX_LOAD_U32(n + 88u), ++k)
      if (k >= cnt || a[k].node != n) { cc_oracle_mismatch("sub_82084EE0", int(k), n, k < cnt ? a[k].node : 0u); break; }
    cc_dl_list_changed(list);
    return;
  }
#endif
  if (REX_LOAD_U32(list) != a[0].node) REX_STORE_U32(list, a[0].node);
  for (uint32_t i = 0; i < cnt; ++i) {
    const uint32_t next = i + 1u < cnt ? a[i + 1u].node : 0u;
    if (a[i].next != next) REX_STORE_U32(a[i].node + 88u, next);
  }
  cc_dl_list_changed(list);
}
#endif
#include "generated/sub_82086748.inc"
#include "generated/sub_820866A0.inc"
#include "generated/sub_820868B0.inc"
#include "generated/sub_82077F20.inc"
#include "generated/sub_820FC9B8.inc"
#include "generated/sub_82080640.inc"
#include "generated/sub_82080A40.inc"
#include "generated/sub_8207F440.inc"
#include "generated/sub_82135188.inc"
#include "generated/sub_82132E10.inc"
#include "generated/sub_82132B28.inc"
#include "generated/sub_82132F50.inc"
#include "generated/sub_82132F40.inc"
#include "generated/sub_821370C8.inc"
#include "generated/sub_8212D268.inc"
#include "generated/sub_8212D2D0.inc"
#include "generated/sub_82080440.inc"
#include "generated/sub_820FC9D0.inc"
#include "generated/sub_82139B70.inc"
#include "generated/sub_821091C8.inc"
#include "generated/sub_82109020.inc"
#include "generated/sub_82104320.inc"
#include "generated/sub_82107A68.inc"
#include "generated/sub_82106120.inc"
#include "generated/sub_8210C538.inc"
#include "generated/sub_82105878.inc"
#include "generated/sub_8210A030.inc"
#include "generated/sub_8210A890.inc"
#include "generated/sub_82100C60.inc"
#include "generated/sub_82107888.inc"
#include "generated/sub_82105F28.inc"
#include "generated/sub_820FFB38.inc"
#include "generated/sub_82100240.inc"
#include "generated/sub_8210C1A8.inc"
#include "generated/sub_8210BCD8.inc"
#include "generated/sub_8210BC60.inc"
#include "generated/sub_82101348.inc"
#include "generated/sub_82138DA0.inc"
#include "generated/sub_821052E8.inc"
#include "generated/sub_82109C68.inc"
#include "generated/sub_820D7F38.inc"
#include "generated/sub_820FD808.inc"
#include "generated/sub_820FD9A8.inc"
#include "generated/sub_821005E8.inc"
#include "generated/sub_82108E20.inc"
#include "generated/sub_82108E38.inc"
#include "generated/sub_82106FF0.inc"
#include "generated/sub_82107290.inc"
#include "generated/sub_821031E0.inc"
#include "generated/sub_82105460.inc"
#include "generated/sub_82103D80.inc"
#include "generated/sub_82106368.inc"
#include "generated/sub_82103C48.inc"
#include "generated/sub_82108E30.inc"
#include "generated/sub_82105C40.inc"
#include "generated/sub_820FEC30.inc"
#include "generated/sub_820FFF08.inc"
#include "generated/sub_820FC7E0.inc"
#include "generated/sub_8210BED0.inc"
#include "generated/sub_820D7FA8.inc"
#include "generated/sub_820FC7A0.inc"
#include "generated/sub_821390B0.inc"
#include "generated/sub_820FCDE0.inc"
#include "generated/sub_821061D0.inc"
#include "generated/sub_821012A0.inc"
#include "generated/sub_821015D0.inc"
#include "generated/sub_82105118.inc"
#include "generated/sub_82136F70.inc"
#include "generated/sub_82107F30.inc"
#include "generated/sub_821089A8.inc"
#include "generated/sub_820FFE78.inc"
#include "generated/sub_82108E58.inc"
#include "generated/sub_8210DF08.inc"
#include "generated/sub_82113430.inc"
#include "generated/sub_82138B88.inc"
#include "generated/sub_82106C70.inc"
#include "generated/sub_82104D68.inc"
#include "generated/sub_82102A60.inc"
#include "generated/sub_82102940.inc"
#include "generated/sub_82109378.inc"
#include "generated/sub_82108E88.inc"
#include "generated/sub_821071F8.inc"
#include "generated/sub_82108E60.inc"
#include "generated/sub_82109038.inc"
#include "generated/sub_821087B0.inc"
#include "generated/sub_821094F0.inc"
#include "generated/sub_82108800.inc"
#include "generated/sub_82107E28.inc"
#include "generated/sub_82138990.inc"
#include "generated/sub_82107E78.inc"
#include "generated/sub_821002A8.inc"
#include "generated/sub_820FCEA0.inc"
#include "generated/sub_82108F18.inc"
#include "generated/sub_82104C20.inc"
#include "generated/sub_82105A18.inc"
#include "generated/sub_8210AE50.inc"
#include "generated/sub_821037D0.inc"
#include "generated/sub_82108E68.inc"
#include "generated/sub_82114C78.inc"
#include "generated/sub_820FD0F8.inc"
#include "generated/sub_82108E98.inc"
#include "generated/sub_820FE9E0.inc"
#include "generated/sub_82139170.inc"
#include "generated/sub_82108DF0.inc"
#include "generated/sub_82101D80.inc"
#include "generated/sub_821391B8.inc"
#include "generated/sub_82100F28.inc"
#include "generated/sub_820FCAA8.inc"
#include "generated/sub_82104DD8.inc"
#include "generated/sub_82138828.inc"
#include "generated/sub_82138480.inc"
#include "generated/sub_8210B2D0.inc"
#include "generated/sub_821102C0.inc"
#include "generated/sub_82115190.inc"
#include "generated/sub_82109548.inc"
#include "generated/sub_82108E78.inc"
#include "generated/sub_820FC9E8.inc"
#include "generated/sub_820FE6C8.inc"
#include "generated/sub_82138A38.inc"
#include "generated/sub_8210BB48.inc"
#include "generated/sub_82109098.inc"
#include "generated/sub_8210B288.inc"
#include "generated/sub_820FCD60.inc"
#include "generated/sub_82108E48.inc"
#include "generated/sub_820FF170.inc"
#include "generated/sub_8210C058.inc"
#include "generated/sub_82110820.inc"
#include "generated/sub_8210E078.inc"
#include "generated/sub_82108068.inc"
#include "generated/sub_82108EA0.inc"
#include "generated/sub_8210E1B8.inc"
#include "generated/sub_82138C30.inc"
#include "generated/sub_82138D08.inc"
#include "generated/sub_82106008.inc"
#include "generated/sub_821104D0.inc"
#include "generated/sub_8210CFC8.inc"
#include "generated/sub_8210CE28.inc"
#include "generated/sub_82115198.inc"
#include "generated/sub_8210CF10.inc"
#include "generated/sub_821141E8.inc"
#include "generated/sub_82114BC0.inc"
#include "generated/sub_8210C7E8.inc"
#include "generated/sub_821113A8.inc"
#include "generated/sub_821148C0.inc"
#include "generated/sub_821108F8.inc"
#include "generated/sub_8210DC20.inc"
#include "generated/sub_8210C5B0.inc"
#include "generated/sub_821392B0.inc"
#include "generated/sub_8210E160.inc"
#include "generated/sub_8210F620.inc"
#include "generated/sub_8211DBA0.inc"
#include "generated/sub_82110620.inc"
#include "generated/sub_82108E50.inc"
#include "generated/sub_820D7ED0.inc"
#include "generated/sub_8210B960.inc"
#include "generated/sub_82108ED8.inc"
#include "generated/sub_82110070.inc"
#include "generated/sub_821094A8.inc"
#include "generated/sub_82107EE0.inc"
#include "generated/sub_82108868.inc"
#include "generated/sub_8210BF70.inc"
#include "generated/sub_820B59F0.inc"
#include "generated/sub_82110AE0.inc"
#include "generated/sub_82110960.inc"
#include "generated/sub_8211FC20.inc"
#include "generated/sub_82115160.inc"
#include "generated/sub_821155F0.inc"
#include "generated/sub_82115178.inc"
#include "generated/sub_8210CCC0.inc"
#include "generated/sub_82115420.inc"
#include "generated/sub_821145B0.inc"
#include "generated/sub_821150A0.inc"
#include "generated/sub_8210E3F8.inc"
#include "generated/sub_8210E8B0.inc"
#include "generated/sub_8210EC50.inc"
#include "generated/sub_8210F1B0.inc"
#include "generated/sub_82116EE8.inc"
#include "generated/sub_8210F0B8.inc"
#include "generated/sub_82116AD0.inc"
#include "generated/sub_8210CDB0.inc"
#include "generated/sub_8210EE60.inc"
#include "generated/sub_82113CD8.inc"
#include "generated/sub_82111848.inc"
#include "generated/sub_8210C0B8.inc"
#include "generated/sub_8210C548.inc"
#include "generated/sub_82122D88.inc"
#include "generated/sub_82110220.inc"
#include "generated/sub_8210DB60.inc"
#include "generated/sub_82110B68.inc"
#include "generated/sub_820B5960.inc"
#include "generated/sub_82115258.inc"
#include "generated/sub_82119560.inc"
#include "generated/sub_82115478.inc"
#include "generated/sub_82119718.inc"
#include "generated/sub_8210F2A0.inc"
#include "generated/sub_821179C0.inc"
#include "generated/sub_8210CC60.inc"
#include "generated/sub_82115E60.inc"
#include "generated/sub_82115878.inc"
#include "generated/sub_82116E20.inc"
#include "generated/sub_82116898.inc"
#include "generated/sub_82115850.inc"
#include "generated/sub_82115158.inc"
#include "generated/sub_8210CD28.inc"
#include "generated/sub_82115150.inc"
#include "generated/sub_8210E490.inc"
#include "generated/sub_820FC768.inc"
#include "generated/sub_820FC728.inc"
#include "generated/sub_820FC788.inc"
#include "generated/sub_8210C440.inc"
#include "generated/sub_82126860.inc"
#include "generated/sub_82115230.inc"
#include "generated/sub_8211A4A8.inc"
#include "generated/sub_8211A410.inc"
#include "generated/sub_82118928.inc"
#include "generated/sub_8211CD00.inc"
#include "generated/sub_82117FD0.inc"
#include "generated/sub_8211F3E0.inc"
#include "generated/sub_821153D8.inc"
#include "generated/sub_82121538.inc"
#include "generated/sub_821212C8.inc"
#include "generated/sub_82120960.inc"
#include "generated/sub_821163B0.inc"
#include "generated/sub_82119398.inc"
#include "generated/sub_820D7EB8.inc"
#include "generated/sub_82118870.inc"
#include "generated/sub_82117BC0.inc"
#include "generated/sub_82122D30.inc"
#include "generated/sub_821184E8.inc"
#include "generated/sub_8211F0C0.inc"
#include "generated/sub_821220F8.inc"
#include "generated/sub_8211BBF0.inc"
#include "generated/sub_8211B3B8.inc"
#include "generated/sub_82121220.inc"
#include "generated/sub_8211DFA0.inc"
#include "generated/sub_82121210.inc"
#include "generated/sub_8211E358.inc"
#include "generated/sub_82121D28.inc"
#include "generated/sub_82120BE0.inc"
#include "generated/sub_82118030.inc"
#include "generated/sub_82122068.inc"
#include "generated/sub_82121D50.inc"
#include "generated/sub_82123858.inc"
#include "generated/sub_82122118.inc"
#include "generated/sub_82124570.inc"
#include "generated/sub_82121FF0.inc"
#include "generated/sub_82121BF8.inc"
#include "generated/sub_82122200.inc"
#include "generated/sub_82124F10.inc"
#include "generated/sub_8211C420.inc"
#include "generated/sub_82123D30.inc"
#include "generated/sub_8211B620.inc"
#include "generated/sub_821241D0.inc"
#include "generated/sub_821214A8.inc"
#include "generated/sub_82121428.inc"
#include "generated/sub_820D7EF8.inc"
#include "generated/sub_82121C50.inc"
#include "generated/sub_82126B08.inc"
#include "generated/sub_821236D0.inc"
#include "generated/sub_82124228.inc"
#include "generated/sub_82122568.inc"
#include "generated/sub_82120A28.inc"
#include "generated/sub_821208B8.inc"
#include "generated/sub_82125DD0.inc"
#include "generated/sub_82109540.inc"
#include "generated/sub_8213A8E0.inc"
#include "generated/sub_8213A238.inc"
#include "generated/sub_821499D8.inc"
#include "generated/sub_82137138.inc"
#include "generated/sub_82149958.inc"
#include "generated/sub_82149998.inc"
#include "generated/sub_82149A48.inc"
#include "generated/sub_82139C00.inc"
#include "generated/sub_8213DDC8.inc"
#include "generated/sub_8213C438.inc"
#include "generated/sub_820D8268.inc"
#include "generated/sub_820B77A8.inc"
#include "generated/sub_8213E1F0.inc"
#include "generated/sub_821395D8.inc"
#include "generated/sub_8213C7A0.inc"
#include "generated/sub_8213E888.inc"
#include "generated/sub_8213A008.inc"
#include "generated/sub_8213FDC8.inc"
#include "generated/sub_82141508.inc"
#include "generated/sub_8213BC30.inc"
#include "generated/sub_8213EC70.inc"
#include "generated/sub_821412F8.inc"
#include "generated/sub_82141110.inc"
#include "generated/sub_821413C8.inc"
#include "generated/sub_8213DA80.inc"
#include "generated/sub_82139F10.inc"
#include "generated/sub_8213BBB0.inc"
#include "generated/sub_8213B858.inc"
#include "generated/sub_820D8160.inc"
#include "generated/sub_8213D140.inc"
#include "generated/sub_82142390.inc"
#include "generated/sub_821424E0.inc"
#include "generated/sub_821422D8.inc"
#include "generated/sub_82142398.inc"
#include "generated/sub_821436A8.inc"
#include "generated/sub_821434D8.inc"
#include "generated/sub_821476E0.inc"
#include "generated/sub_8213B5C0.inc"
#include "generated/sub_8213FC10.inc"
#include "generated/sub_8213B0C0.inc"
#include "generated/sub_8213E860.inc"
#include "generated/sub_8213ED10.inc"
#include "generated/sub_8213CD98.inc"
#include "generated/sub_8213CD80.inc"
#include "generated/sub_8213CEC0.inc"
#include "generated/sub_821420A0.inc"
#include "generated/sub_82141F80.inc"
#include "generated/sub_8213CE58.inc"
#include "generated/sub_82141F88.inc"
#include "generated/sub_82141EC0.inc"
#include "generated/sub_82142500.inc"
#include "generated/sub_82142560.inc"
#include "generated/sub_82142530.inc"
#include "generated/sub_82142518.inc"
#include "generated/sub_821424E8.inc"
#include "generated/sub_82142548.inc"
#include "generated/sub_82142800.inc"
#include "generated/sub_82142930.inc"
#include "generated/sub_82144F20.inc"
#include "generated/sub_82144FE8.inc"
#include "generated/sub_821445B0.inc"
#include "generated/sub_82144660.inc"
#include "generated/sub_82144708.inc"
#include "generated/sub_82145058.inc"
#include "generated/sub_82144F98.inc"
#include "generated/sub_8213B078.inc"
#include "generated/sub_8213BB88.inc"
#include "generated/sub_8213BAB0.inc"
#include "generated/sub_8213B690.inc"
#include "generated/sub_8213F6A0.inc"
#include "generated/sub_820DCB00.inc"
#include "generated/sub_8213E548.inc"
#include "generated/sub_8213E5A8.inc"
#include "generated/sub_8213E508.inc"
#include "generated/sub_82114E20.inc"
#include "generated/sub_82053380.inc"
#include "generated/sub_82129A68.inc"
#include "generated/sub_821299D0.inc"
#include "generated/sub_820B7730.inc"
#include "generated/sub_820B7650.inc"
#include "generated/sub_8212E7E8.inc"
#include "generated/sub_8212BF18.inc"
#include "generated/sub_82132F98.inc"
#include "generated/sub_82149DD8.inc"
#include "generated/sub_82149E10.inc"
#include "generated/sub_82149E48.inc"
#include "generated/sub_82149E80.inc"
#include "generated/sub_82149E98.inc"
#include "generated/sub_82149EB0.inc"
#include "generated/sub_82149F10.inc"
#include "generated/sub_82149B18.inc"
#include "generated/sub_82149B88.inc"
#include "generated/sub_82149BF8.inc"
#include "generated/sub_82149C08.inc"
#include "generated/sub_82149C60.inc"
#include "generated/sub_82149CB8.inc"
#include "generated/sub_82149D10.inc"
#include "generated/sub_82149D68.inc"
#include "generated/sub_82149D78.inc"
#include "generated/sub_82149DB0.inc"
#include "generated/sub_82114E40.inc"
#include "generated/sub_82075298.inc"
#include "generated/sub_820E3308.inc"
#include "generated/sub_820EBBD8.inc"
#include "generated/sub_820E7150.inc"
#include "generated/sub_820E2018.inc"
#include "generated/sub_820E7F70.inc"
#include "generated/sub_820E83D0.inc"
#include "generated/sub_820E81F0.inc"
#include "generated/sub_820E7C20.inc"
#include "generated/sub_820E2628.inc"
#include "generated/sub_820DAB80.inc"
#include "generated/sub_820DABC0.inc"
#include "generated/sub_820E8138.inc"
#include "generated/sub_820DAFE8.inc"
#include "generated/sub_820DAE88.inc"
#include "generated/sub_820DAAD0.inc"
#include "generated/sub_820E71D0.inc"
#include "generated/sub_820DAF20.inc"
#include "generated/sub_820DA528.inc"
#include "generated/sub_820E89C0.inc"
#include "generated/sub_820E3AB0.inc"
#include "generated/sub_820DBD88.inc"
#include "generated/sub_820DC398.inc"
#include "generated/sub_820E3CA8.inc"
#include "generated/sub_820E9B98.inc"
#include "generated/sub_820DC5F8.inc"
#include "generated/sub_82081378.inc"
#include "generated/sub_8207EB68.inc"
#include "generated/sub_8209C388.inc"
#include "generated/sub_8207D918.inc"
#include "generated/sub_8207E3C8.inc"
#include "generated/sub_82086710.inc"
#include "generated/sub_82078058.inc"
#include "generated/sub_8207D0C8.inc"
#include "generated/sub_8207B598.inc"
#include "generated/sub_8207D2A0.inc"
#ifdef CC_FAST
#define sub_82077BC0 sub_82077BC0_exact
#endif
#include "generated/sub_82077BC0.inc"
#ifdef CC_FAST
#undef sub_82077BC0
// GameManager::QueueMovie (exact sub_82077BC0: manager r3, name r4 =
// {u32 length, chars}, r5). Host CC_MOVIE_LOG=1 logs each request.
static void sub_82077BC0(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  if (std::getenv("CC_MOVIE_LOG") && ctx.r4.u32) {
    const uint32_t len = uint32_t(base.load(ctx.r4.u32, 4));
    char nm[24] = {};
    for (uint32_t k = 0; k < len && k < 23u; ++k) nm[k] = char(base.load(ctx.r4.u32 + 4u + k, 1));
    cc_log("queue '%s' r3=%08x r5=%08x lr=%08x\n", nm, ctx.r3.u32, ctx.r5.u32, uint32_t(ctx.lr));
  }
#endif
  // Direct level load (make LEVEL=<n> / CC_LEVEL=<n>): a request for the
  // first level, "level2" (the castle interior), queues "level<n>" instead,
  // from a copy in the platform-globals page.
  if (const uint32_t lvl = cc_direct_level(); lvl && ctx.r4.u32) {
    const uint32_t len = uint32_t(base.load(ctx.r4.u32, 4));
    char name[16] = {};
    for (uint32_t k = 0; k < len && k < 15u; ++k) name[k] = char(base.load(ctx.r4.u32 + 4u + k, 1));
    if (len == 6u && std::strcmp(name, "level2") == 0) {
      char repl[16] = {};
      const int n = std::snprintf(repl, sizeof(repl), "level%u", lvl);
      constexpr uint32_t obj = 0x02500400u;
      base.store(obj, 4, uint32_t(n));
      for (int k = 0; k <= n; ++k) base.store(obj + 4u + uint32_t(k), 1, uint8_t(repl[k]));
      cc_log("direct_level %s -> %s\n", name, repl);
      ctx.r4.u64 = obj;
      // The level that normally leads into level 13 also queues the movies
      // level 13 uses (its horses, chickens and sky); queue them here too.
      const uint32_t r3 = ctx.r3.u32, r5 = ctx.r5.u32;
      sub_82077BC0_exact(ctx, base);
      const uint32_t ret = ctx.r3.u32;
      static const char* const extra[] = {"horse", "chicken", "sky1"};
      for (const char* e : extra) {
        const uint32_t eo = 0x02500480u;
        const uint32_t el = uint32_t(std::strlen(e));
        base.store(eo, 4, el);
        for (uint32_t k = 0; k <= el; ++k) base.store(eo + 4u + k, 1, uint8_t(e[k]));
        ctx.r3.u64 = r3; ctx.r4.u64 = eo; ctx.r5.u64 = r5;
        sub_82077BC0_exact(ctx, base);
      }
      ctx.r3.u64 = ret;
      return;
    }
  }
  sub_82077BC0_exact(ctx, base);
}
#endif
#include "generated/sub_82087CF8.inc"
#include "generated/sub_820815C0.inc"
#include "generated/sub_820822D8.inc"
#include "generated/sub_8208CF90.inc"
#include "generated/sub_8207DB80.inc"
#include "generated/sub_820B2C28.inc"
#include "generated/sub_82081160.inc"
#include "generated/sub_82063730.inc"
#include "generated/sub_8209B730.inc"
#include "generated/sub_8209B6C0.inc"
#include "generated/sub_820A43E8.inc"
#include "generated/sub_820A3540.inc"
#include "generated/sub_820A2B00.inc"
#include "generated/sub_82063C00.inc"
#include "generated/sub_82063F18.inc"
#include "generated/sub_82063DC8.inc"
#include "generated/sub_82063758.inc"
#include "generated/sub_82054490.inc"
#include "generated/sub_82064048.inc"
#include "generated/sub_82067AF0.inc"
#include "generated/sub_82066820.inc"
#include "generated/sub_82063648.inc"
#include "generated/sub_820669E8.inc"
#ifdef CC_FAST
#define sub_82062990 sub_82062990_exact
#endif
#include "generated/sub_82062990.inc"
#ifdef CC_FAST
#undef sub_82062990
// Main menu: refresh the Download Content / Unlock Full Game item, which
// the exact code addresses as menu slot 6 ([[screen+48]+44]). The play
// build drops that item (see the trim), so the slot is empty: nothing to do.
static void sub_82062990(Context& ctx, Machine& base) {
  const uint32_t menu = uint32_t(base.load(ctx.r3.u32 + 48u, 4));
  if (!menu || base.load(menu + 44u, 4) == 0u) return;
  sub_82062990_exact(ctx, base);
}
#endif
#include "generated/sub_82065DF0.inc"
#include "generated/sub_820657B0.inc"
#include "generated/sub_820655E0.inc"
#include "generated/sub_82065D08.inc"
#include "generated/sub_820656C8.inc"
#include "generated/sub_82065B38.inc"
#include "generated/sub_82065898.inc"
#include "generated/sub_820659E8.inc"
#include "generated/sub_82065C20.inc"
#include "generated/sub_820654F8.inc"
#include "generated/sub_82066BA0.inc"
#include "generated/sub_82066270.inc"
#include "generated/sub_82066CD0.inc"
#include "generated/sub_820667B0.inc"
#include "generated/sub_82053EF0.inc"
#include "generated/sub_82061E48.inc"
#include "generated/sub_82053A90.inc"
#include "generated/sub_82067670.inc"
#include "generated/sub_82065ED8.inc"
#include "generated/sub_82065380.inc"
#include "generated/sub_82053AA8.inc"
#include "generated/sub_82094728.inc"
#include "generated/sub_82088C60.inc"
#include "generated/sub_8207BF88.inc"
#include "generated/sub_82087F30.inc"
#include "generated/sub_8207FCA8.inc"
#include "generated/sub_821284C0.inc"
#include "generated/sub_82128390.inc"
#include "generated/sub_82128680.inc"
#include "generated/sub_8209C4D0.inc"
#include "generated/sub_82093B00.inc"
#include "generated/sub_82093F98.inc"
#include "generated/sub_82083B70.inc"
#include "generated/sub_82083E58.inc"
#include "generated/sub_8207E308.inc"
#include "generated/sub_82080E08.inc"
#include "generated/sub_8207C3A8.inc"
#include "generated/sub_8208B8D0.inc"
#include "generated/sub_8207FB40.inc"
#include "generated/sub_8207F260.inc"
#include "generated/sub_8207C1F8.inc"
#include "generated/sub_8207EEC8.inc"
#include "generated/sub_8207DEB8.inc"
#include "generated/sub_82086808.inc"
#include "generated/sub_82081A08.inc"
#include "generated/sub_82082F18.inc"
#include "generated/sub_8207ECC0.inc"
#include "generated/sub_82088C98.inc"
#include "generated/sub_8207C5A8.inc"
#include "generated/sub_8208C5E0.inc"
#include "generated/sub_82079D50.inc"
#include "generated/sub_820817B8.inc"
#include "generated/sub_8207C778.inc"
#include "generated/sub_82078910.inc"
#include "generated/sub_820789E0.inc"
#include "generated/sub_82078C30.inc"
#include "generated/sub_82078978.inc"
#include "generated/sub_82078AB0.inc"
#include "generated/sub_82078B30.inc"
#include "generated/sub_82078A48.inc"
#include "generated/sub_82078BB0.inc"
#include "generated/sub_820790E8.inc"
#include "generated/sub_82075408.inc"
#include "generated/sub_820939B8.inc"
#include "generated/sub_82093A60.inc"
#include "generated/sub_8207AE58.inc"
#include "generated/sub_8207CF70.inc"
#include "generated/sub_8207BFE8.inc"
#ifdef CC_FAST
#define sub_82084D18 sub_82084D18_exact
#endif
#include "generated/sub_82084D18.inc"
#ifdef CC_FAST
#undef sub_82084D18
#endif
#include "generated/sub_82086828.inc"
#include "generated/sub_8207F4D8.inc"
#ifdef CC_FAST
#define sub_82084C78 sub_82084C78_exact
#endif
#include "generated/sub_82084C78.inc"
#ifdef CC_FAST
#undef sub_82084C78
// Display-list remove (exact sub_82084D18: list r3, node r4) and remove by
// depth (exact sub_82084C78: list r3, depth r4), seen by the name cache.
static void sub_82084D18(Context& ctx, Machine& base) {
  const CcDlMutate m(ctx.r3.u32);
  sub_82084D18_exact(ctx, base);
}
static void sub_82084C78(Context& ctx, Machine& base) {
  const CcDlMutate m(ctx.r3.u32);
  sub_82084C78_exact(ctx, base);
}
#endif
#include "generated/sub_82127E48.inc"
#include "generated/sub_820B8678.inc"
#include "generated/sub_820BAD80.inc"
#include "generated/sub_8212A098.inc"
#include "generated/sub_820B8BF8.inc"
#include "generated/sub_820BA518.inc"
#include "generated/sub_82127F8C.inc"
#include "generated/sub_8212E0D0.inc"
#include "generated/sub_8212A090.inc"
#include "generated/sub_8212DFE0.inc"
#include "generated/sub_82127EA8.inc"
#include "generated/sub_82127FB0.inc"
#include "generated/sub_8207C048.inc"
#include "generated/sub_82086668.inc"
#include "generated/sub_82081598.inc"
#include "generated/sub_82058508.inc"
#include "generated/sub_82094B48.inc"
#include "generated/sub_820954A0.inc"
#include "generated/sub_82094740.inc"
#include "generated/sub_82094748.inc"
#include "generated/sub_82080FA0.inc"
#include "generated/sub_820E8208.inc"
#include "generated/sub_820DB998.inc"
#include "generated/sub_820E3E50.inc"
#include "generated/sub_820E99E0.inc"
#include "generated/sub_820E8448.inc"
#include "generated/sub_820DBB90.inc"
#include "generated/sub_820E21B0.inc"
#include "generated/sub_820E72E8.inc"
#include "generated/sub_820E79B8.inc"
#include "generated/sub_820E8078.inc"
#include "generated/sub_820EAA88.inc"
#include "generated/sub_820DA4B0.inc"
#include "generated/sub_82136298.inc"
#include "generated/sub_820DADC0.inc"
#include "generated/sub_820DA400.inc"
#include "generated/sub_820DA458.inc"
#include "generated/sub_8212B374.inc"
#include "generated/sub_820DA200.inc"
#if defined(CC_FLAT_WINDOW) && !defined(CC_WINDOW_NOMASK)
// stwux r1,r1,r12 moves r1 by a register amount in this function, so its
// stack accesses take the masked path (a bad amount must not carry r1 out of
// the window, see CC_R1_CHAIN in bridge.cpp).
#pragma push_macro("CC_R1_ADDR")
#undef CC_R1_ADDR
#define CC_R1_ADDR(a) false
#endif
#include "generated/sub_820E87E0.inc"
#if defined(CC_FLAT_WINDOW) && !defined(CC_WINDOW_NOMASK)
#pragma pop_macro("CC_R1_ADDR")
#endif
#include "generated/sub_820EBC10.inc"
#include "generated/sub_820EBCD0.inc"
#include "generated/sub_820E7168.inc"
#include "generated/sub_820E7110.inc"
#include "generated/sub_820E1AB8.inc"
#include "generated/sub_820E1D28.inc"
#include "generated/sub_820EB2D0.inc"
#include "generated/sub_820E9D98.inc"
#include "generated/sub_820EBAF0.inc"
#include "generated/sub_820EA9C8.inc"
#include "generated/sub_820E1D00.inc"
#include "generated/sub_820E39B8.inc"
#include "generated/sub_820E38F8.inc"
#include "generated/sub_820E3B50.inc"
#include "generated/sub_820E0D30.inc"
#include "generated/sub_820E0F78.inc"
#include "generated/sub_820E0D58.inc"
#include "generated/sub_820E19E0.inc"
#include "generated/sub_820DB398.inc"
#include "generated/sub_820E8E40.inc"
#include "generated/sub_820EB2A8.inc"
#include "generated/sub_820E1CD8.inc"
#include "generated/sub_820E1998.inc"
#include "generated/sub_820DB310.inc"
#include "generated/sub_82099060.inc"
#include "generated/sub_82098B88.inc"
#include "generated/sub_82097DF8.inc"
#include "generated/sub_82096C80.inc"
#include "generated/sub_8208C790.inc"
#include "generated/sub_8208C868.inc"
#include "generated/sub_820868A0.inc"
#include "generated/sub_8207A4C0.inc"
#include "generated/sub_8207A5D8.inc"
#include "generated/sub_8207FE10.inc"
#include "generated/sub_8207A3F0.inc"
#include "generated/sub_82081E18.inc"
#include "generated/sub_8207CE60.inc"
#include "generated/sub_8207F870.inc"
#include "generated/sub_8208CB80.inc"
#include "generated/sub_8208CB88.inc"
#include "generated/sub_8208FC30.inc"
#include "generated/sub_8208FAB8.inc"
#include "generated/sub_82082520.inc"
#include "generated/sub_8207E5C8.inc"
#include "generated/sub_82081CD8.inc"
#include "generated/sub_82099C68.inc"
#ifdef CC_FAST
#define sub_82094D28 sub_82094D28_exact
#define sub_820834D0 sub_820834D0_exact
#endif
#include "generated/sub_82094D28.inc"
#include "generated/sub_820834D0.inc"
#ifdef CC_FAST
#undef sub_82094D28
#undef sub_820834D0
// Slot 4 (reset) of the text field (sub_82094D28) and of the base and
// shape classes (sub_820834D0, sub_8208C6E0, sub_8208C5E8) clears link +88:
// a node reset while still linked cuts its list short, and its +96 does not
// always name that list (text fields answer slot 156 with 0), so the name
// cache is flushed rather than one list bumped. The list primitives reset
// nodes while they hold the list (g_dl_busy), which bumps it anyway.
static void sub_82094D28(Context& ctx, Machine& base) {
  sub_82094D28_exact(ctx, base);
  if (g_dl_busy == 0u) cc_dl_flush();
}
static void sub_820834D0(Context& ctx, Machine& base) {
  sub_820834D0_exact(ctx, base);
  if (g_dl_busy == 0u) cc_dl_flush();
}
#endif
#include "generated/sub_8208C4A8.inc"
#include "generated/sub_8208C590.inc"
#include "generated/sub_8208CCA8.inc"
#include "generated/sub_82096E50.inc"
#ifdef CC_FAST
#define sub_8208C6E0 sub_8208C6E0_exact
#endif
#include "generated/sub_8208C6E0.inc"
#ifdef CC_FAST
#undef sub_8208C6E0
static void sub_8208C6E0(Context& ctx, Machine& base) {  // reset, see sub_82094D28
  sub_8208C6E0_exact(ctx, base);
  if (g_dl_busy == 0u) cc_dl_flush();
}
#endif
#include "generated/sub_82096778.inc"
#include "generated/sub_82099730.inc"
#include "generated/sub_8207A1E0.inc"
#include "generated/sub_82086D30.inc"
#include "generated/sub_82093A68.inc"
#include "generated/sub_82093FA0.inc"
#include "generated/sub_820861E0.inc"
#include "generated/sub_8207A7E0.inc"
#include "generated/sub_82086B00.inc"
#include "generated/sub_820941B0.inc"
#include "generated/sub_820998F0.inc"
#include "generated/sub_82099878.inc"
#include "generated/sub_820997D8.inc"
#include "generated/sub_82098240.inc"
#include "generated/sub_82097CE8.inc"
#include "generated/sub_82084650.inc"
#include "generated/sub_82097840.inc"
#include "generated/sub_820842F0.inc"
#include "generated/sub_820845C0.inc"
#include "generated/sub_8209CBA8.inc"
#include "generated/sub_82096A30.inc"
#include "generated/sub_82090448.inc"
#include "generated/sub_8209DD78.inc"
#include "generated/sub_8209DCE8.inc"
#include "generated/sub_8209A3A0.inc"
#include "generated/sub_8209A170.inc"
#include "generated/sub_82066F78.inc"
#include "generated/sub_82066F68.inc"
#include "generated/sub_82053A88.inc"
#include "generated/sub_82066F60.inc"
#include "generated/sub_82053AA0.inc"
#include "generated/sub_820863D8.inc"
#include "generated/sub_820865D8.inc"
#include "generated/sub_82086728.inc"
#include "generated/sub_820868B8.inc"
#include "generated/sub_82066F38.inc"
#include "generated/sub_82099B48.inc"
#include "generated/sub_820B2608.inc"
#include "generated/sub_82092BD0.inc"
#include "generated/sub_8208A458.inc"
#include "generated/sub_8208B948.inc"
#include "generated/sub_8208BAE0.inc"
#include "generated/sub_82087E50.inc"
#include "generated/sub_82092238.inc"
#ifdef CC_FAST
#define sub_82094760 sub_82094760_exact
#endif
#include "generated/sub_82094760.inc"
#ifdef CC_FAST
#undef sub_82094760
#define sub_82094EF0 sub_82094EF0_exact
#endif
#include "generated/sub_82094EF0.inc"
#ifdef CC_FAST
#undef sub_82094EF0
// Text-field name set (exact sub_82094760: field r3, id r4; u16 +150) and
// text-field copy (exact sub_82094EF0: from r3, to r4; copies the name
// among other fields), seen by the name cache.
static void sub_82094760(Context& ctx, Machine& base) {
  const uint32_t old = REX_LOAD_U16(ctx.r3.u32 + 150u), id = ctx.r4.u32;
  sub_82094760_exact(ctx, base);
  cc_dl_name_changed(old);
  cc_dl_name_changed(id);
}
static void sub_82094EF0(Context& ctx, Machine& base) {
  const uint32_t to = ctx.r4.u32, old = REX_LOAD_U16(to + 150u);
  sub_82094EF0_exact(ctx, base);
  cc_dl_name_changed(old);
  cc_dl_name_changed(REX_LOAD_U16(to + 150u));
}
#endif
#include "generated/sub_82094E88.inc"
#include "generated/sub_82083428.inc"
#include "generated/sub_82094720.inc"
#include "generated/sub_82094680.inc"
#include "generated/sub_82094768.inc"
#include "generated/sub_8208FD90.inc"
#include "generated/sub_82084570.inc"
#include "generated/sub_820953C0.inc"
#include "generated/sub_82093250.inc"
#include "generated/sub_8208CF98.inc"
#include "generated/sub_8208FCE8.inc"
#include "generated/sub_82092DC8.inc"
#include "generated/sub_82092AA8.inc"
#include "generated/sub_82091D78.inc"
#include "generated/sub_82091D00.inc"
#ifdef CC_FAST
#define sub_8207BAE8 sub_8207BAE8_exact
#endif
#include "generated/sub_8207BAE8.inc"
#ifdef CC_FAST
#undef sub_8207BAE8
#endif
#include "generated/sub_820D5130.inc"
#include "generated/sub_820D5200.inc"
#include "generated/sub_820D52B8.inc"
#include "generated/sub_820D4B20.inc"
#include "generated/sub_820D56B0.inc"
#include "generated/sub_820D40A0.inc"
#include "generated/sub_820D5408.inc"
#include "generated/sub_820D5568.inc"
#include "generated/sub_820D49C8.inc"
#include "generated/sub_820D4870.inc"
#include "generated/sub_820D57F0.inc"
#include "generated/sub_820D46F0.inc"
#include "generated/sub_820C14E8.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_20.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#define sub_820C1980 sub_820C1980_exact
#include "generated/sub_820C1980.inc"
#undef sub_820C1980
#ifdef CC_WRAP_82129A70
// Guest memcpy (exact sub_82129A70: dst r3, src r4, count r5; saves r3 at
// r1-8 and returns it). Play build: non-overlapping copies within one
// region each are done natively (guest bytes are stored in guest order, so
// a byte copy is exact); anything else runs the exact body.
static void sub_82129A70(Context& ctx, Machine& base) {
  const uint32_t d = ctx.r3.u32, sr = ctx.r4.u32, n = ctx.r5.u32;
  if (n && (uint64_t(d) + n <= sr || uint64_t(sr) + n <= d)) {
    uint8_t* dp = base.memory.contiguous(d, n, 2);
    const uint8_t* sp = base.memory.contiguous(sr, n, 1);
    if (dp && sp) {
      base.store(ctx.r1.u32 - 8u, 8, ctx.r3.u64);
      uint32_t i = 0;
      for (; i + 4u <= n; i += 4u) { uint32_t w; __builtin_memcpy(&w, sp + i, 4); __builtin_memcpy(dp + i, &w, 4); }
      for (; i < n; ++i) dp[i] = sp[i];
      return;
    }
  }
  sub_82129A70_exact(ctx, base);
}
#endif
static void sub_820C1980(Context& ctx, Machine& base) {
  // The game's final draw call (r3 device, r4 primitive, r5 vertex count,
  // r6 vertices, r7 stride): the Xbox renderer draws it from here.
#ifdef CC_XBOX_DRIVER
  // Vertices and the device's blend word through the page table (the
  // checked lookups are the fallback for spans that cross a 64 KiB page).
  const uint32_t count = ctx.r5.u32, stride = ctx.r7.u32;
  if (count && stride && count <= 65536u / stride) {
    const uint8_t* v = cc_obj_host(ctx.r6.u32, count * stride);
    if (!v) v = base.memory.contiguous(ctx.r6.u32, size_t(count) * stride, 1);
    uint32_t blend = 0;
    if (const uint8_t* d = cc_obj_host(ctx.r3.u32 + 10552u, 4u)) blend = cc_hb32(d);
    else { uint64_t b = 0; base.memory.load_be(ctx.r3.u32 + 10552u, 4, b); blend = uint32_t(b); }
    if (v) ::cc_xr_draw(ctx.r4.u32, count, v, stride, blend);
  }
#endif
#ifndef CC_XBOX_DRIVER
  if (g_quadlog_left > 0 && (g_quadlog_left_draw || g_quadlog_from_ok())) {
    --g_quadlog_left;
    const uint32_t count = ctx.r5.u32, stride = ctx.r7.u32;
    cc_log("QUADOUT prim=%u count=%u stride=%u", ctx.r4.u32, count, stride);
    for (uint32_t i = 0; i < count && i < 8u; ++i) {
      const uint32_t v = ctx.r6.u32 + i * stride;
      auto f32 = [&](uint32_t a) { uint32_t b = uint32_t(base.load(a, 4)); float f; std::memcpy(&f, &b, 4); return f; };
      cc_log(" v%u=(%g,%g,%g,%g,%g,%08x)", i, f32(v), f32(v + 4u), f32(v + 8u), f32(v + 12u), f32(v + 16u), uint32_t(base.load(v + 20u, 4)));
    }
    cc_log("\n");
  }
#endif
  // The exact body only builds the Xbox 360 GPU's command packets (state
  // flush into the ring, then a copy of the vertices); nothing reads them
  // back. The play build skips it (a quarter of a menu frame); the host can
  // do the same with CC_SKIP_360_DRAW=1 to check the game is unaffected.
#if defined(CC_XBOX_DRIVER) && defined(CC_FAST)
  return;
#else
  static const bool skip = std::getenv("CC_SKIP_360_DRAW") != nullptr;
  if (skip) { cc_capture_on_function("sub_820C1980", ctx, base.memory); return; }
  sub_820C1980_exact(ctx, base);
#endif
}
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_20.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#if !defined(CC_XBOX_DRIVER) || defined(CC_FAST)
#define sub_820A9308 sub_820A9308_exact
#endif
#include "generated/sub_820A9308.inc"
#if !defined(CC_XBOX_DRIVER) || defined(CC_FAST)
#undef sub_820A9308
#endif
#ifdef CC_FAST
// Native quad emitter (play build), derived from the exact sub_820A9308
// (renderer r3, points r4..r7 {x,y,z}, uv pointers r8..r10 and [r1+84],
// colour [r1+92] as bytes [R G B A], count [r1+100]). The exact body does
// nothing when the renderer's draw flag (+28715) is clear or the vertex
// ring (count at 0x8228A7C4) holds 6000; for count != 4 it maps each point
// to screen pixels, x' = w * (x + 0.5), y' = h * (y + 0.5), with w and h
// the integer viewport size at [renderer + 24*idx + 28748 / 28752],
// idx = [renderer + 29124], and 0.5 the constant at 0x82014748; it reads
// the blend mode 0..16 of the current material
// ([[renderer + ([renderer+30208] + 7544) * 4]]) and, on the common modes,
// writes four 24-byte vertices {x, y, z = 100.0 (0x8201473C), u, v,
// premultiplied ARGB colour} at 0x822673D8 + 24*count, adds 4 to the count
// and calls sub_820C1980(device [renderer+4], 13, 4, vertices, 24).
// Modes 4, 13 and > 16 draw nothing; modes 2, 6, 10, 11, 14 and 15 (other
// vertex layouts) keep the exact body. Float steps repeat the exact body's
// operations, so the vertices are bit-identical (host: CC_QUAD_EXACT=1
// runs the exact body instead).
static uint32_t cc_quad_colour(uint32_t c) {
  const uint32_t a = c & 255u, r = c >> 24, g = (c >> 16) & 255u, b = (c >> 8) & 255u;
  return (a << 24) | ((r * a >> 8) << 16) | ((g * a >> 8) << 8) | (b * a >> 8);
}
static bool cc_quad_native(Context& ctx, Machine& base) {
  const uint32_t renderer = ctx.r3.u32;
  if (REX_LOAD_U8(renderer + 28715u) == 0u) return true;
  const uint32_t ring = REX_LOAD_U32(0x82290000u - 22588u);  // vertex ring count (0x8228A7C4)
  if (int32_t(ring) >= 6000) return true;
  const uint32_t slot = REX_LOAD_U32(renderer + (REX_LOAD_U32(renderer + 30208u) + 7544u) * 4u);
  switch (REX_LOAD_U32(slot)) {
    case 0: case 1: case 3: case 5: case 7: case 8: case 9: case 12: case 16: break;
    case 2: case 6: case 10: case 11: case 14: case 15: return false;
    default: return true;
  }
  const uint32_t pts[4] = {ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32};
  const uint32_t uvs[4] = {ctx.r8.u32, ctx.r9.u32, ctx.r10.u32, REX_LOAD_U32(ctx.r1.u32 + 84)};
  const uint32_t colour = cc_quad_colour(REX_LOAD_U32(ctx.r1.u32 + 92));
  const uint32_t count = REX_LOAD_U32(ctx.r1.u32 + 100);
  uint32_t xy[4][2];
  for (uint32_t i = 0; i < 4; ++i) { xy[i][0] = REX_LOAD_U32(pts[i] + 0u); xy[i][1] = REX_LOAD_U32(pts[i] + 4u); }
  if (count != 4u) {
    ctx.fpscr.disableFlushMode();
    auto f32 = [](uint32_t b) { float f; __builtin_memcpy(&f, &b, 4); return f; };
    auto bits = [](float f) { uint32_t b; __builtin_memcpy(&b, &f, 4); return b; };
    const uint32_t idx = REX_LOAD_U32(renderer + 29124u);
    const double c = f32(REX_LOAD_U32(0x82014748u));
    const double w = double(float(double(int64_t(uint64_t(REX_LOAD_U32(renderer + idx * 24u + 28748u))))));
    const double h = double(float(double(int64_t(uint64_t(REX_LOAD_U32(renderer + idx * 24u + 28752u))))));
    for (uint32_t i = 0; i < 4; ++i) {
      xy[i][0] = bits(float(w * double(float(double(f32(xy[i][0])) + c))));
      xy[i][1] = bits(float(h * double(float(double(f32(xy[i][1])) + c))));
    }
  }
  const uint32_t z = REX_LOAD_U32(0x8201473Cu);
#if defined(CC_XBOX_DRIVER) && !defined(CC_SPRITE_RING_BUILD)
  // Xbox: the quad goes to the renderer's quad batch instead of the guest
  // vertex ring and sub_820C1980, whose hand-off is the ring's only reader
  // there (see cc_sprite_fused in as_render.inc; make SPRITERING=1 keeps
  // the ring).
  {
    uint32_t q[24];
    for (uint32_t i = 0; i < 4; ++i) {
      q[i * 6 + 0] = xy[i][0]; q[i * 6 + 1] = xy[i][1]; q[i * 6 + 2] = z;
      q[i * 6 + 3] = REX_LOAD_U32(uvs[i] + 0u); q[i * 6 + 4] = REX_LOAD_U32(uvs[i] + 4u); q[i * 6 + 5] = colour;
    }
    REX_STORE_U32(0x82290000u - 22588u, ring + 4u);
    ::cc_xr_quad(q, REX_LOAD_U32(REX_LOAD_U32(renderer + 4u) + 10552u));  // device blend word
  }
#else
  const uint32_t verts = 0x822673D8u + ring * 24u;
  for (uint32_t i = 0; i < 4; ++i) {
    const uint32_t v = verts + i * 24u;
    REX_STORE_U32(v + 0u, xy[i][0]);
    REX_STORE_U32(v + 4u, xy[i][1]);
    REX_STORE_U32(v + 8u, z);
    REX_STORE_U32(v + 12u, REX_LOAD_U32(uvs[i] + 0u));
    REX_STORE_U32(v + 16u, REX_LOAD_U32(uvs[i] + 4u));
    REX_STORE_U32(v + 20u, colour);
  }
  REX_STORE_U32(0x82290000u - 22588u, ring + 4u);
  const auto lr = ctx.lr;
  ctx.r3.u64 = REX_LOAD_U32(renderer + 4u);
  ctx.r4.u64 = 13; ctx.r5.u64 = 4; ctx.r6.u64 = verts; ctx.r7.u64 = 24;
  ctx.lr = 0x820A9AD0u;
  sub_820C1980(ctx, base);
  ctx.lr = lr;
#endif
  return true;
}
#endif
#ifndef CC_XBOX_DRIVER
static bool g_quadlog_from_ok() {
  static long from = -1;
  if (from < 0) { const char* e = std::getenv("CC_QUADLOG_FROM"); from = e ? std::strtol(e, nullptr, 10) : 0; }
  return long(g_frame_delay_calls) >= from;
}
// Host probe (CC_QUADLOG=<count>): log the quad emitter's inputs (renderer
// r3, points r4..r7, uv pointers r8..r10 and [r1+84], colour [r1+92], count
// [r1+100]) before the exact body runs; sub_820C1980's wrapper logs the
// vertices it produced. Together they define the native emitter.
static void sub_820A9308(Context& ctx, Machine& base) {
  // CC_QUADLOG=<n> logs n quads, starting at frame CC_QUADLOG_FROM (default 0).
  static long from = -1;
  if (from < 0) { const char* e = std::getenv("CC_QUADLOG_FROM"); from = e ? std::strtol(e, nullptr, 10) : 0; }
  if (g_quadlog_left < 0) { const char* e = std::getenv("CC_QUADLOG"); g_quadlog_left = e ? std::strtol(e, nullptr, 10) : 0; }
  const bool logging = g_quadlog_left > 0 && long(g_frame_delay_calls) >= from;
#ifdef CC_FAST
  static const bool native = std::getenv("CC_QUAD_EXACT") == nullptr;
  if (native) {
    if (logging) {
      // Log the inputs even on the native path so both paths can be diffed.
      auto f32 = [&](uint32_t a) { uint32_t b = uint32_t(base.load(a, 4)); float f; std::memcpy(&f, &b, 4); return f; };
      const uint32_t p[4] = {ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32};
      cc_log("QUADIN frame=%u count=%u colour=%08x", g_frame_delay_calls, uint32_t(base.load(ctx.r1.u32 + 100u, 4)), uint32_t(base.load(ctx.r1.u32 + 92u, 4)));
      for (int i = 0; i < 4; ++i) cc_log(" p%d=(%g,%g,%g)", i, f32(p[i]), f32(p[i] + 4u), f32(p[i] + 8u));
      cc_log(" ring=%u\n", uint32_t(base.load(0x82290000u - 22588u, 4)));
      cc_log("QUADNAT idx=%u w=%08x h=%08x c=%08x z=%08x\n", uint32_t(base.load(ctx.r3.u32 + 29124u, 4)), uint32_t(base.load(ctx.r3.u32 + uint32_t(base.load(ctx.r3.u32 + 29124u, 4)) * 24u + 28748u, 4)), uint32_t(base.load(ctx.r3.u32 + uint32_t(base.load(ctx.r3.u32 + 29124u, 4)) * 24u + 28752u, 4)), uint32_t(base.load(0x82014748u, 4)), uint32_t(base.load(0x8201473Cu, 4)));
      g_quadlog_left_draw = true;
    }
    if (cc_quad_native(ctx, base)) { g_quadlog_left_draw = false; return; }
    g_quadlog_left_draw = false;
  }
#endif
  if (logging) {
    auto f32 = [&](uint32_t a) { uint32_t b = uint32_t(base.load(a, 4)); float f; std::memcpy(&f, &b, 4); return f; };
    const uint32_t p[4] = {ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32};
    const uint32_t uv[4] = {ctx.r8.u32, ctx.r9.u32, ctx.r10.u32, uint32_t(base.load(ctx.r1.u32 + 84u, 4))};
    cc_log("QUADIN frame=%u count=%u colour=%08x", g_frame_delay_calls, uint32_t(base.load(ctx.r1.u32 + 100u, 4)), uint32_t(base.load(ctx.r1.u32 + 92u, 4)));
    for (int i = 0; i < 4; ++i) cc_log(" p%d=(%g,%g,%g)", i, f32(p[i]), f32(p[i] + 4u), f32(p[i] + 8u));
    for (int i = 0; i < 4; ++i) cc_log(" uv%d=(%g,%g)", i, f32(uv[i]), f32(uv[i] + 4u));
    cc_log(" ring=%u\n", uint32_t(base.load(0x82290000u - 22588u, 4)));
  }
  sub_820A9308_exact(ctx, base);
}
#else
#ifdef CC_FAST
static void sub_820A9308(Context& ctx, Machine& base) {
  if (cc_quad_native(ctx, base)) return;
  sub_820A9308_exact(ctx, base);
}
#endif
#endif
// Fields of the game's texture record read at a bind: the pixel pointer +36
// (the texture's identity), width +16, height +20 and format code +24. False
// when the record is null or +36 is unreadable (the bind then does nothing);
// the other fields read as 0 when unreadable.
struct CcTexRec { uint32_t data, w, h, fmt; };
static inline bool cc_tex_record(Machine& base, uint32_t record, CcTexRec& r) {
  if (!record) return false;
  if (const uint8_t* p = cc_obj_host(record + 16u, 24u)) {
    r.w = cc_hb32(p); r.h = cc_hb32(p + 4u); r.fmt = cc_hb32(p + 8u); r.data = cc_hb32(p + 20u);
    return true;
  }
  uint64_t d = 0, w = 0, h = 0, f = 0;
  if (base.memory.load_be(record + 36u, 4, d) != cc::xbox::MemoryError::ok) return false;
  base.memory.load_be(record + 16u, 4, w);
  base.memory.load_be(record + 20u, 4, h);
  base.memory.load_be(record + 24u, 4, f);
  r = CcTexRec{uint32_t(d), uint32_t(w), uint32_t(h), uint32_t(f)};
  return true;
}
static const CcDxtTexture* cc_tex_stream_on_bind(Context& ctx, Machine& base, uint32_t data, bool& ran);
#define sub_820A89F8 sub_820A89F8_exact
#include "generated/sub_820A89F8.inc"
#undef sub_820A89F8
static void cc_xr_on_bind(Machine& base, const CcTexRec& rec, const CcDxtTexture* t);
static void sub_820A89F8(Context& ctx, Machine& base) {
  // Texture bind (r4 = the game's texture record): make sure a streamed
  // texture's pixels are resident before the exact bind runs, then hand it
  // to the Xbox renderer.
  CcTexRec rec;
  if (cc_tex_record(base, ctx.r4.u32, rec)) {
    bool ran = false;
    const CcDxtTexture* t = cc_tex_stream_on_bind(ctx, base, rec.data, ran);
    bool ok = true;
    if (ran) {
      ok = cc_tex_record(base, ctx.r4.u32, rec);
      t = ok ? cc_dxt_lookup(rec.data) : nullptr;
    }
    if (ok) cc_xr_on_bind(base, rec, t);
  }
  // The exact bind programs the Xbox 360's device per sprite (vertex and
  // pixel shader, vertex declaration, render states, sampler registers)
  // for a draw path the play build no longer runs (sub_820C1980's body is
  // skipped there); the Xbox renderer binds from cc_xr_on_bind instead.
#if !defined(CC_FAST) || defined(CC_BIND_EXACT_BUILD)
  sub_820A89F8_exact(ctx, base);
#elif defined(CC_XBOX_DRIVER)
  static_cast<void>(&sub_820A89F8_exact);
#else
  static const bool exact_bind = std::getenv("CC_BIND_EXACT") != nullptr;  // host A/B switch
  if (exact_bind) sub_820A89F8_exact(ctx, base);
  else cc_capture_on_function("sub_820A89F8", ctx, base.memory);  // frame capture reads the texture record here
#endif
}
#include "generated/sub_82086680.inc"
#include "generated/sub_82086778.inc"
#include "generated/sub_820866D0.inc"
#ifdef CC_FAST
#define sub_82089F70 sub_82089F70_exact
#endif
#include "generated/sub_82089F70.inc"
#ifdef CC_FAST
#undef sub_82089F70
#endif
#ifdef CC_FAST
#define sub_8208C2A0 sub_8208C2A0_exact
#endif
#include "generated/sub_8208C2A0.inc"
#ifdef CC_FAST
#undef sub_8208C2A0
#endif
#ifdef CC_FAST
#define sub_8208B520 sub_8208B520_exact
#endif
#include "generated/sub_8208B520.inc"
#ifdef CC_FAST
#undef sub_8208B520
#endif
#include "generated/sub_8207A290.inc"
#include "generated/sub_8207A358.inc"
#include "generated/sub_820820D8.inc"
#include "generated/sub_820867C8.inc"
#include "generated/sub_820867D0.inc"
#include "generated/sub_82085FA8.inc"
#ifdef CC_FAST
#define sub_82089C00 sub_82089C00_exact
#endif
#include "generated/sub_82089C00.inc"
#ifdef CC_FAST
#undef sub_82089C00
#endif
#ifdef CC_FAST
#define sub_82085078 sub_82085078_exact
#endif
#include "generated/sub_82085078.inc"
#ifdef CC_FAST
#undef sub_82085078
// Display-list lookup (exact sub_82085078: list r3, id r4): the first node
// in the list at [r3] (linked through +88) that answers slot 52 and whose
// slot 72 value matches id in the low 16 bits; 0 when none does. Answered
// from the name cache (see CcDlEnt) while its versions hold.
//
// The walk answers the three named classes from their name field (their
// slot 52 is "name != 0", slot 72 the name) and classes whose two methods
// are constant leaves from the constants; from the first node of any
// other class on, it calls the methods as the original does and the
// result is not cached. The next node's lines are prefetched as soon as
// its address is known.
static __attribute__((noinline)) uint32_t cc_dl_walk_calls(Context& ctx, Machine& base, uint32_t n, uint32_t id) {
  CcFrame frame(ctx, base, 112u);
  for (; n; n = REX_LOAD_U32(n + 88u)) {
    if ((cc_vcall(ctx, base, n, 52u, 0x820850B0u) & 0xFFu) != 0u &&
        (cc_vcall(ctx, base, n, 72u, 0x820850D0u) & 0xFFFFu) == id)
      return n;
  }
  return 0u;
}
static CC_HOT_FN uint32_t cc_dl_walk(Context& ctx, Machine& base, uint32_t list, uint32_t id, bool& cacheable) {
  uint32_t n = REX_LOAD_U32(list);
  while (n) {
    cc_prefetch(n + 88u);
    cc_prefetch(n + 100u);
    const uint32_t vt = REX_LOAD_U32(n);
    CC_DL_STAT(nodes);
    if (vt == 0x8203E878u || vt == 0x8203F510u || vt == 0x8203F680u) {
      const uint32_t name = REX_LOAD_U16(n + (vt == 0x8203F680u ? 150u : 100u));
      if (name != 0u && name == id) return n;
    } else {
      const CcLeaf& m52 = cc_leaf_info(base, REX_LOAD_U32(vt + 52u));
      if (m52.kind != 2) { cacheable = false; return cc_dl_walk_calls(ctx, base, n, id); }
      if ((uint32_t(m52.imm) & 0xFFu) != 0u) {
        const CcLeaf& m72 = cc_leaf_info(base, REX_LOAD_U32(vt + 72u));
        if (m72.kind != 2) { cacheable = false; return cc_dl_walk_calls(ctx, base, n, id); }
        if ((uint32_t(m72.imm) & 0xFFFFu) == id) return n;
      }
    }
    n = REX_LOAD_U32(n + 88u);
    if (n) cc_prefetch(n);
  }
  return 0u;
}
static CC_HOT_FN void sub_82085078(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  static const bool walk_exact = std::getenv("CC_WALK_EXACT") != nullptr;  // host A/B switch
  if (walk_exact) { sub_82085078_exact(ctx, base); return; }
  static const bool use_cache = std::getenv("CC_DLCACHE_OFF") == nullptr;  // host A/B switch
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr || std::getenv("CC_DLCACHE_ORACLE") != nullptr;
#else
  #ifdef CC_WALK_EXACT_BUILD
  sub_82085078_exact(ctx, base); return;  // Xbox bisect build
#endif
  static_cast<void>(&sub_82085078_exact);
#ifdef CC_DLCACHE_OFF_BUILD
  constexpr bool use_cache = false;  // Xbox bisect build
#else
  constexpr bool use_cache = true;
#endif
#endif
  const uint32_t list = ctx.r3.u32, id = ctx.r4.u32 & 0xFFFFu;
  CC_DL_STAT(calls);
  CcDlEnt& e = g_dl_cache[((list >> 3) * 0x9E3779B1u ^ id * 0x85EBCA6Bu) >> 21];
  const bool usable = use_cache && g_dl_busy == 0u;
  if (usable && e.list == list && e.id == id && cc_dl_lv(list) <= e.stamp && cc_dl_iv(id) <= e.stamp) {
    CC_DL_STAT(hits);
#ifndef CC_XBOX_DRIVER
    if (oracle) {  // the uncached walk on every hit; its answer stays in effect
      bool c = true;
      const uint32_t r = cc_dl_walk(ctx, base, list, id, c);
      if (r != e.result || !c) cc_oracle_mismatch("sub_82085078", int(id), r, e.result);
      ctx.r3.u64 = r;
      return;
    }
#endif
    ctx.r3.u64 = e.result;
    return;
  }
  bool cacheable = true;
  const uint32_t r = cc_dl_walk(ctx, base, list, id, cacheable);
  if (usable && cacheable && g_dl_busy == 0u) {
    CC_DL_STAT(fills);
    e.list = list; e.id = id; e.stamp = g_dl_tick; e.result = r;
  } else if (!usable) {
    CC_DL_STAT(busy);
  } else {
    CC_DL_STAT(uncached);
  }
  ctx.r3.u64 = r;
}
#endif
#ifdef CC_FAST
#define sub_8208B438 sub_8208B438_exact
#endif
#include "generated/sub_8208B438.inc"
#ifdef CC_FAST
#undef sub_8208B438
#endif
#ifdef CC_FAST
#define sub_8207A908 sub_8207A908_exact
#endif
#include "generated/sub_8207A908.inc"
#ifdef CC_FAST
#undef sub_8207A908
#endif
#include "generated/sub_82081C08.inc"
#include "generated/sub_82081920.inc"
#include "generated/sub_8207C948.inc"
#include "generated/sub_82082CD0.inc"
#include "generated/sub_8207F088.inc"
#include "generated/sub_8207CDA0.inc"
#include "generated/sub_82138350.inc"
#include "generated/sub_82135370.inc"
#include "generated/sub_82136E98.inc"
#include "generated/sub_820BB330.inc"
#include "generated/sub_820BB290.inc"
#include "generated/sub_820DC3C8.inc"
#include "generated/sub_820DC010.inc"
#include "generated/sub_82133DB8.inc"
#include "generated/sub_82132FC8.inc"
#include "generated/sub_82052430.inc"
#include "generated/sub_82052318.inc"
#include "generated/sub_820523A0.inc"
#include "generated/sub_8206F0F8.inc"
#include "generated/sub_8208BEC0.inc"
#include "generated/sub_82128A78.inc"
#include "generated/sub_820BB050.inc"
#include "generated/sub_820BADF8.inc"
#include "generated/sub_820DC7A8.inc"
#include "generated/sub_8209E868.inc"
#include "generated/sub_8212E280.inc"
#include "generated/sub_820524D8.inc"
#include "generated/sub_82127860.inc"
#include "generated/sub_82067BC0.inc"
#include "generated/sub_8206F1C8.inc"
#include "generated/sub_8208B608.inc"
#include "generated/sub_8208B6F8.inc"
#include "generated/sub_8208B570.inc"
#include "generated/sub_82128D48.inc"
#include "generated/sub_820B7A38.inc"
#include "generated/sub_82099D30.inc"
#include "generated/sub_820D82C8.inc"
#include "generated/sub_820D8328.inc"
#include "generated/sub_820D8648.inc"
#include "generated/sub_8209E740.inc"
#include "generated/sub_821280F8.inc"
#include "generated/sub_820A5730.inc"
#include "generated/sub_821279C0.inc"
#include "generated/sub_8209BC08.inc"
#include "generated/sub_820631B0.inc"
// ---- Main menu trim (play build) -------------------------------------------
// The user's main menu is Local Game, Player Statistics, Help & Options and
// Quit. The exact constructor sub_820623C0(screen r3, menu r4) builds eight
// items: each is created by sub_82067020(obj, parent, handler, string id,
// 0) and appended by sub_82065F78(menu, item, scale, scale), which also
// re-lays the list out, vertically centred, 30 px apart. The play build
// drops the Xbox LIVE Game (387), Leaderboards (597), Achievements (598),
// Unlock Full Game (601, trial only) and Download Content (600) items at
// the append, and afterwards moves the remaining four up 10 px, which
// centres the block between the logo's bottom (y 134) and the top of the
// "A Select" prompt (y 413), as measured on the console (user, 2026-10-03).
// The verification build runs the exact code unchanged.
#ifdef CC_FAST
static bool g_menu_trim_active = false;
static struct { uint32_t obj, id; } g_text_ids[64];
static unsigned g_text_ids_next = 0;
static uint32_t cc_text_id_of(uint32_t obj) {
  for (const auto& e : g_text_ids) if (e.obj == obj) return e.id;
  return 0xFFFFFFFFu;
}
static bool cc_menu_item_dropped(uint32_t id) {
  return id == 387u || id == 597u || id == 598u || id == 600u || id == 601u;
}
#define sub_820623C0 sub_820623C0_exact
#endif
#include "generated/sub_820623C0.inc"
#ifdef CC_FAST
#undef sub_820623C0
static void sub_820623C0(Context& ctx, Machine& base) {
  const uint32_t menu = ctx.r4.u32;
  g_menu_trim_active = true;
  sub_820623C0_exact(ctx, base);
  g_menu_trim_active = false;
  // Items: count u16 at +4, pointers from +20 (slot i at (i+5)*4); each
  // item's y is the float at +8 (screen pixels, down positive).
  const uint32_t count = uint32_t(base.load(menu + 4u, 2));
  for (uint32_t i = 0; i < count && i < 16u; ++i) {
    const uint32_t item = uint32_t(base.load(menu + (i + 5u) * 4u, 4));
    if (!item) continue;
    uint32_t bits = uint32_t(base.load(item + 8u, 4));
    float y; std::memcpy(&y, &bits, 4);
    y -= 10.0f;
    std::memcpy(&bits, &y, 4);
    base.store(item + 8u, 4, bits);
  }
}
#endif
#include "generated/sub_8206D728.inc"
#include "generated/sub_82057398.inc"
#include "generated/sub_82056718.inc"
#include "generated/sub_82055810.inc"
#include "generated/sub_82055C20.inc"
#include "generated/sub_82061FC8.inc"
#include "generated/sub_820684C0.inc"
#include "generated/sub_820563A0.inc"
#include "generated/sub_82068D60.inc"
#include "generated/sub_82057028.inc"
#include "generated/sub_82056CB8.inc"
#include "generated/sub_8206ABD0.inc"
#include "generated/sub_82062E80.inc"
#include "generated/sub_8206B2B0.inc"
#include "generated/sub_82062A50.inc"
#include "generated/sub_8206B000.inc"
#include "generated/sub_82057670.inc"
#include "generated/sub_82056030.inc"
#include "generated/sub_820B5D40.inc"
#include "generated/sub_8206EA70.inc"
#include "generated/sub_8206DF58.inc"
#include "generated/sub_8206F390.inc"
#include "generated/sub_8206F498.inc"
#include "generated/sub_8206EDD0.inc"
#include "generated/sub_8206F620.inc"
#include "generated/sub_820B59F8.inc"
#include "generated/sub_82128E90.inc"
#include "generated/sub_82128E88.inc"
#include "generated/sub_820B7540.inc"
#ifdef CC_FAST
#define sub_8208C140 sub_8208C140_exact
#endif
#include "generated/sub_8208C140.inc"
#ifdef CC_FAST
#undef sub_8208C140
// ActionScript object member read (exact sub_8208C140: object r3, id r4
// u16, out r5): the member map at object+4; found -> Var read, returns 1;
// not found -> 0.
static CC_HOT_FN void sub_8208C140(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  static const bool walk_exact = std::getenv("CC_WALK_EXACT") != nullptr;
  if (walk_exact) { sub_8208C140_exact(ctx, base); return; }
#else
  #ifdef CC_WALK_EXACT_BUILD
  sub_8208C140_exact(ctx, base); return;  // Xbox bisect build
#endif
  static_cast<void>(&sub_8208C140_exact);
#endif
  const uint32_t var = cc_asmap_find(base, ctx.r3.u32 + 4u, ctx.r4.u32 & 0xFFFFu);
  if (!var) { ctx.r3.u64 = 0u; return; }
  cc_as_var_read(ctx, base, var, ctx.r5.u32, 0x8208C1C4u);
  ctx.r3.u64 = 1u;
}
#endif
#ifdef CC_FAST
#define sub_82079BE0 sub_82079BE0_exact
#endif
#include "generated/sub_82079BE0.inc"
#ifdef CC_FAST
#undef sub_82079BE0
// ActionScript local variable read (exact sub_82079BE0: activation r3,
// id r4 u16, out value r5). Locals are {u16 id at +44+8i, Var* at +48+8i},
// ended by a null Var*. A Var is {+0 object, +4 type, +8 payload}. Found:
// out = {type, payload} by type (undefined 0x80000000 -> {tag, 0}; object
// type 1 -> sub_8206F918(out, object); bool 2 byte; int 4 word; string 8
// u16 id; number 16 float), other types leave out alone; returns 1.
// Not found: 0.
static CC_HOT_FN void sub_82079BE0(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  static const bool walk_exact = std::getenv("CC_WALK_EXACT") != nullptr;
  if (walk_exact) { sub_82079BE0_exact(ctx, base); return; }
#else
  #ifdef CC_WALK_EXACT_BUILD
  sub_82079BE0_exact(ctx, base); return;  // Xbox bisect build
#endif
  static_cast<void>(&sub_82079BE0_exact);
#endif
  const uint32_t act = ctx.r3.u32, id = ctx.r4.u32 & 0xFFFFu, out = ctx.r5.u32;
  uint32_t i = 0;
  bool found = false;
  for (uint32_t p = act + 48u; REX_LOAD_U32(p) != 0u; p += 8u, ++i)
    if (REX_LOAD_U16(p - 4u) == id) { found = true; break; }
  if (!found) { ctx.r3.u64 = 0u; return; }
  cc_as_var_read(ctx, base, REX_LOAD_U32(act + (i + 6u) * 8u), out, 0x82079CA0u);
  ctx.r3.u64 = 1u;
}
#endif
#include "generated/sub_82085400.inc"
#include "generated/sub_82128290.inc"
#include "generated/sub_820935B0.inc"
#include "generated/sub_820838A8.inc"
#include "generated/sub_820A58C8.inc"
#include "generated/sub_82094A98.inc"
#include "generated/sub_82070F20.inc"
#include "generated/sub_82094858.inc"
#include "generated/sub_8209BBA0.inc"
#include "generated/sub_820A0E98.inc"
#include "generated/sub_820B5D50.inc"
#include "generated/sub_820A4238.inc"
#include "generated/sub_820A32C0.inc"
#include "generated/sub_820619F0.inc"
#include "generated/sub_820A4038.inc"
#include "generated/sub_820A31A0.inc"
#include "generated/sub_8206DDC8.inc"
#include "generated/sub_8206F988.inc"
#include "generated/sub_820A3DF8.inc"
#include "generated/sub_820B6070.inc"
#ifdef CC_FAST
#define sub_8208BF38 sub_8208BF38_exact
#endif
#include "generated/sub_8208BF38.inc"
#ifdef CC_FAST
#undef sub_8208BF38
#endif
#ifdef CC_FAST
#define sub_8207AF80 sub_8207AF80_exact
#endif
#include "generated/sub_8207AF80.inc"
#ifdef CC_FAST
#undef sub_8207AF80
#endif
#include "generated/sub_8208FB88.inc"
#include "generated/sub_820875B0.inc"
#include "generated/sub_820975D8.inc"
#include "generated/sub_82096FC8.inc"
#ifdef CC_FAST
#define sub_820878E0 sub_820878E0_exact
#endif
#include "generated/sub_820878E0.inc"
#ifdef CC_FAST
#undef sub_820878E0
// Depth setters (exact sub_820878E0: node r3, depth r4; exact sub_820879A0:
// node r3, target r5): both set bit 5 of the parent's byte +140 (parent =
// slot 156), which makes the next refresh sort the parent's list. The
// parent becomes a refresh candidate (see g_dl_dirty); a class whose slot
// 156 is not the parent field [node+96] sends the refresh back to the walk.
static void cc_dl_mark_parent(Machine& base, uint32_t node) {
  const CcLeaf& m = cc_leaf_info(base, REX_LOAD_U32(REX_LOAD_U32(node) + 156u));
  if (m.kind != 3 || m.imm != 96) { g_dl_walk_always = true; return; }
  const uint32_t p = REX_LOAD_U32(node + 96u);
  if (p != 0u && (REX_LOAD_U8(p + 140u) & 0x20u) != 0u) cc_dl_mark(p);
}
// Depth set (exact sub_820878E0, f_Depth's last step): a depth below 0 or
// the node's own depth +28 does nothing; else the parent (slot 156; none:
// the log call sub_8208C5D8) and its child list (slot 100, the clip
// classes' "addi r3,r3,104" taken inline) are found, the first child at
// that depth gets the node's old depth, the node gets the new one and the
// parent's +140 bit 5 is set. The list walk (up to ~560 children in the
// 4P fight) is the cost; native, with the original's frame, return
// addresses and the volatile registers it leaves. Switches: CC_DEPTH_EXACT
// =1 (host) / make DEPTHEXACT=1 (Xbox, CC_DEPTH_EXACT_BUILD) run the
// original; CC_ORACLE=1 or CC_DEPTH_ORACLE=1 run the original and compare
// it with the native's answer (found child and the three stores).
static CC_HOT_FN void cc_depth_set(Context& ctx, Machine& base) {
  const uint32_t node = ctx.r3.u32, d = ctx.r4.u32;
  ctx.r12.u64 = ctx.lr;
  ctx.lr = 0x820878E8u;  // the register-save call
  CcFrame frame(ctx, base, 128u);
  const uint32_t old = REX_LOAD_U32(node + 28u);
  if (int32_t(d) < 0 || d == old) return;
  const uint32_t parent = cc_vcall(ctx, base, node, 156u, 0x82087918u);
  if (parent == 0u) {
    ctx.r11.u64 = 0xFFFFFFFF82040000ull;
    ctx.r3.u64 = 0xFFFFFFFF8203E600ull;
    ctx.lr = 0x82087994u;
    sub_8208C5D8(ctx, base);
    return;
  }
  uint32_t list;
  {
    const uint32_t vt = REX_LOAD_U32(parent + 0u), fn = REX_LOAD_U32(vt + 100u);
    if (fn == 0x82086810u) {
      list = parent + 104u;
      ctx.r3.u64 = list;
      ctx.r11.u64 = vt;
      ctx.r10.u64 = fn;
      ctx.ctr.u64 = fn;
      ctx.lr = 0x82087930u;
    } else {
      list = cc_vcall(ctx, base, parent, 100u, 0x82087930u);
    }
  }
  for (uint32_t n = REX_LOAD_U32(list + 0u); n != 0u; n = REX_LOAD_U32(n + 88u))
    if (REX_LOAD_U32(n + 28u) == d) {
      REX_STORE_U32(n + 28u, old);
      break;
    }
  const uint32_t vt = REX_LOAD_U32(node + 0u);
  REX_STORE_U32(node + 28u, d);
  const uint32_t p = cc_vcall(ctx, base, node, 156u, 0x82087974u);
  const uint32_t b = REX_LOAD_U8(p + 140u);
  REX_STORE_U8(p + 140u, uint8_t(b | 0x20u));
  ctx.r11.u64 = vt;
  ctx.r10.u64 = REX_LOAD_U32(vt + 156u);
  ctx.ctr.u64 = ctx.r10.u64;
  ctx.r9.u64 = b;
  ctx.r8.u64 = b | 0x20u;
}
static void sub_820878E0(Context& ctx, Machine& base) {
  CC_FPROF_SCOPE(sub_820878E0_native);
  const uint32_t node = ctx.r3.u32;
#ifndef CC_XBOX_DRIVER
  static const bool exact = std::getenv("CC_DEPTH_EXACT") != nullptr;
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr || std::getenv("CC_DEPTH_ORACLE") != nullptr;
  if (oracle && !exact) {
    // The native's answer, read before the original runs: the child it
    // would swap with and the stores it would make.
    const uint32_t d = ctx.r4.u32, old = REX_LOAD_U32(node + 28u);
    const bool acts = int32_t(d) >= 0 && d != old && REX_LOAD_U32(node + 96u) != 0u;
    uint32_t hit = 0u;
    if (acts)
      for (uint32_t n = REX_LOAD_U32(REX_LOAD_U32(node + 96u) + 104u); n != 0u; n = REX_LOAD_U32(n + 88u))
        if (REX_LOAD_U32(n + 28u) == d) { hit = n; break; }
    const CcLeaf& up = cc_leaf_info(base, REX_LOAD_U32(REX_LOAD_U32(node) + 156u));
    const uint32_t par = REX_LOAD_U32(node + 96u);
    const bool known = up.kind == 3 && up.imm == 96 && par != 0u && REX_LOAD_U32(REX_LOAD_U32(par) + 100u) == 0x82086810u;
    sub_820878E0_exact(ctx, base);
    if (acts && known) {
      if (REX_LOAD_U32(node + 28u) != d) cc_oracle_mismatch("sub_820878E0 depth", 0, REX_LOAD_U32(node + 28u), d);
      if (hit != 0u && REX_LOAD_U32(hit + 28u) != old) cc_oracle_mismatch("sub_820878E0 swap", 1, REX_LOAD_U32(hit + 28u), old);
      if ((REX_LOAD_U8(REX_LOAD_U32(node + 96u) + 140u) & 0x20u) == 0u) cc_oracle_mismatch("sub_820878E0 mark", 2, 0u, 0x20u);
    }
    cc_dl_mark_parent(base, node);
    return;
  }
#elif defined(CC_DEPTH_EXACT_BUILD)
  constexpr bool exact = true;
#else
  constexpr bool exact = false;
#endif
  if (exact) sub_820878E0_exact(ctx, base);
  else cc_depth_set(ctx, base);
  cc_dl_mark_parent(base, node);
}
#endif
#ifdef CC_FAST
#define sub_82082700 sub_82082700_exact
#endif
#include "generated/sub_82082700.inc"
#ifdef CC_FAST
#undef sub_82082700
#endif
#include "generated/sub_82087358.inc"
#ifdef CC_FAST
#define sub_82087F70 sub_82087F70_exact
#endif
#include "generated/sub_82087F70.inc"
#ifdef CC_FAST
#undef sub_82087F70
#include "seek.inc"
#endif
#include "generated/sub_82071280.inc"
#include "generated/sub_82086FF0.inc"
#ifdef CC_FAST
#define sub_8207B150 sub_8207B150_exact
#endif
#include "generated/sub_8207B150.inc"
#ifdef CC_FAST
#undef sub_8207B150
#endif
#include "generated/sub_82089778.inc"
#ifdef CC_FAST
#define sub_8206F918 sub_8206F918_exact
#endif
#include "generated/sub_8206F918.inc"
#ifdef CC_FAST
#undef sub_8206F918
// Typed reference (exact sub_8206F918: out r3, object r4): out = {type
// (slot 40), object}, or {0x80000000, 0} for no object.
static CC_HOT_FN void sub_8206F918(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  static const bool walk_exact = std::getenv("CC_WALK_EXACT") != nullptr;  // host A/B switch
  if (walk_exact) { sub_8206F918_exact(ctx, base); return; }
#else
  #ifdef CC_WALK_EXACT_BUILD
  sub_8206F918_exact(ctx, base); return;  // Xbox bisect build
#endif
  static_cast<void>(&sub_8206F918_exact);
#endif
  const uint32_t out = ctx.r3.u32, obj = ctx.r4.u32;
  if (!obj) {
    REX_STORE_U32(out + 0u, 0x80000000u);
    REX_STORE_U32(out + 4u, 0u);
    return;
  }
  CcFrame frame(ctx, base, 112u);
  const uint32_t t = cc_vcall(ctx, base, obj, 40u, 0x8206F950u);
  REX_STORE_U32(out + 0u, t);
  REX_STORE_U32(out + 4u, obj);
}
#endif
#include "generated/sub_82089AB8.inc"
#include "generated/sub_820899D0.inc"
#include "generated/sub_82082848.inc"
#include "generated/sub_82087AD8.inc"
#include "generated/sub_82097560.inc"
#ifdef CC_FAST
#define sub_82082670 sub_82082670_exact
#endif
#include "generated/sub_82082670.inc"
#ifdef CC_FAST
#undef sub_82082670
#endif
#include "generated/sub_8208AFC8.inc"
#include "generated/sub_820868D8.inc"
#ifdef CC_FAST
#define sub_820879A0 sub_820879A0_exact
#endif
#include "generated/sub_820879A0.inc"
#ifdef CC_FAST
#undef sub_820879A0
static void sub_820879A0(Context& ctx, Machine& base) {
  const uint32_t node = ctx.r3.u32;
  sub_820879A0_exact(ctx, base);
  cc_dl_mark_parent(base, node);
}
#endif
#include "generated/sub_820970D0.inc"
#include "generated/sub_82087160.inc"
#include "generated/sub_8208B7F8.inc"
#include "generated/sub_820877A0.inc"
#include "generated/sub_82089668.inc"
#ifdef CC_FAST
#define sub_82088CF0 sub_82088CF0_exact  // native CharToFunc: runtime021/as_ops_call.inc
#endif
#include "generated/sub_82088CF0.inc"
#ifdef CC_FAST
#undef sub_82088CF0
#endif
#ifdef CC_FAST
#define sub_82082890 sub_82082890_exact
#endif
#include "generated/sub_82082890.inc"
#ifdef CC_FAST
#undef sub_82082890
#endif
#ifdef CC_FAST
#define sub_82082BB0 sub_82082BB0_exact
#endif
#include "generated/sub_82082BB0.inc"
#ifdef CC_FAST
#undef sub_82082BB0
#endif
#include "generated/sub_8207E048.inc"
#ifdef CC_FAST
#define sub_82082488 sub_82082488_exact
#endif
#include "generated/sub_82082488.inc"
#ifdef CC_FAST
#undef sub_82082488
// ActionScript value-pool allocation (exact sub_82082488: pool r3). 1256
// slots of 12 bytes at +5028, in-use byte at slot+8, rover at +20100: the
// first free slot from the rover on (wrapping), marked used and made the
// new rover; 0 when all are in use.
static CC_HOT_FN void sub_82082488(Context& ctx, Machine& base) {
  const uint32_t pool = ctx.r3.u32;
  const uint32_t start = REX_LOAD_U32(pool + 20100u);
  uint32_t i = start;
  if (REX_LOAD_U8(pool + i * 12u + 5036u) != 0u) {
    for (;;) {
      i = (int32_t(i + 1u) < 1256) ? i + 1u : 0u;
      if (i == start) {
#ifndef CC_XBOX_DRIVER
        static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
        if (oracle) { sub_82082488_exact(ctx, base); if (ctx.r3.u32) cc_oracle_mismatch("sub_82082488", 1, ctx.r3.u32, 0u); return; }
#endif
        ctx.r3.u64 = 0u; return;
      }
      if (REX_LOAD_U8(pool + i * 12u + 5036u) == 0u) break;
    }
  }
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
  if (oracle) {
    sub_82082488_exact(ctx, base);
    if (ctx.r3.u32 != pool + i * 12u + 5028u) cc_oracle_mismatch("sub_82082488", 0, ctx.r3.u32, pool + i * 12u + 5028u);
    return;
  }
#else
  static_cast<void>(&sub_82082488_exact);
#endif
  REX_STORE_U8(pool + i * 12u + 5036u, 1u);
  REX_STORE_U32(pool + 20100u, i);
  ctx.r3.u64 = pool + i * 12u + 5028u;
}
#endif
#ifdef CC_FAST
#define sub_8207AA50 sub_8207AA50_exact
#endif
#include "generated/sub_8207AA50.inc"
#ifdef CC_FAST
#undef sub_8207AA50
// The native Push item decode cc_as_decode and sub_8207AA50 are in
// runtime021/as_ops.inc (they take the interpreter loop state).
#endif
#include "generated/sub_820814A0.inc"
#include "generated/sub_82083900.inc"
#include "generated/sub_820813F8.inc"
#ifdef CC_FAST
#define sub_8207B630 sub_8207B630_exact
#endif
#include "generated/sub_8207B630.inc"
#ifdef CC_FAST
#undef sub_8207B630
#endif
#include "generated/sub_82079B48.inc"
#ifdef CC_FAST
#define sub_8207B8B8 sub_8207B8B8_exact
#endif
#include "generated/sub_8207B8B8.inc"
#ifdef CC_FAST
#undef sub_8207B8B8
#endif
#include "generated/sub_8208C670.inc"
#include "generated/sub_82086818.inc"
#include "generated/sub_820B02B0.inc"
#ifdef CC_FAST
#define sub_8208C5E8 sub_8208C5E8_exact
#endif
#include "generated/sub_8208C5E8.inc"
#ifdef CC_FAST
#undef sub_8208C5E8
static void sub_8208C5E8(Context& ctx, Machine& base) {  // reset, see sub_82094D28
  sub_8208C5E8_exact(ctx, base);
  if (g_dl_busy == 0u) cc_dl_flush();
}
#endif
#include "generated/sub_820B20F0.inc"
#include "generated/sub_820B2180.inc"
#include "generated/sub_820B20C8.inc"
#if defined(CC_XBOX_DRIVER) && defined(CC_FAST) && !defined(CC_XBOX_PROFILE)
#define sub_820B0F18 sub_820B0F18_exact
#endif
#include "generated/sub_820B0F18.inc"
#if defined(CC_XBOX_DRIVER) && defined(CC_FAST) && !defined(CC_XBOX_PROFILE)
#undef sub_820B0F18
// Xbox play build: the generated prologue is empty, so the hook this
// function needs (Machine::hooked_fast) runs here.
static void sub_820B0F18(Context& ctx, Machine& base) { base.hooked_fast(1, ctx); sub_820B0F18_exact(ctx, base); }
#endif
#include "generated/sub_820868C8.inc"
#ifdef CC_FAST
#define sub_820867E8 sub_820867E8_exact
#endif
#include "generated/sub_820867E8.inc"
#ifdef CC_FAST
#undef sub_820867E8
#endif
#include "generated/sub_8208BBB0.inc"
#include "generated/sub_8208BCF8.inc"
#include "generated/sub_8207BD00.inc"
#include "generated/sub_82086DE8.inc"
#include "generated/sub_82086F78.inc"
#ifdef CC_FAST
#define sub_82084DB8 sub_82084DB8_exact
#endif
#include "generated/sub_82084DB8.inc"
#ifdef CC_FAST
#undef sub_82084DB8
// Clip name set (exact sub_820867E8: clip r3, id r4; u16 +100) and
// display-list insert by depth (exact sub_82084DB8: list r3, node r4,
// replace flag r5), seen by the name cache.
static void sub_820867E8(Context& ctx, Machine& base) {
  const uint32_t old = REX_LOAD_U16(ctx.r3.u32 + 100u), id = ctx.r4.u32;
  sub_820867E8_exact(ctx, base);
  cc_dl_name_changed(old);
  cc_dl_name_changed(id);
}
static void sub_82084DB8(Context& ctx, Machine& base) {
  const uint32_t node = ctx.r4.u32;
  {
    const CcDlMutate m(ctx.r3.u32);
    sub_82084DB8_exact(ctx, base);
  }
  // Refresh candidates (see g_dl_dirty): a node arriving with bit 5 set,
  // and a class whose slot 44 the table cannot judge.
  bool known = true;
  cc_dl_active(base, node, known);
  if (!known) g_dl_walk_always = true;
  if (REX_LOAD_U8(node + 140u) & 0x20u) cc_dl_mark(node);
}
#endif
#include "generated/sub_82083550.inc"
#include "generated/sub_82085540.inc"
#include "generated/sub_820867F0.inc"
#include "generated/sub_8208F9E8.inc"
#ifdef CC_FAST
#define sub_82085890 sub_82085890_exact
#endif
#include "generated/sub_82085890.inc"
#ifdef CC_FAST
#undef sub_82085890
// MSB-first bit cursor over a SWF record as the game's readers keep it
// (sub_82095700 unsigned, sub_82095788 signed, and the inline single-bit
// reads): byte position pos from p, bits left in the current byte (8..1);
// a byte is read when its first bit is. The readers test bits through the
// mask table at 0x820146B0, which holds 1 << i for i = 0..31 (checked once
// by cc_swf_mask_ok). A signed field of n bits takes bit n-1 as its sign;
// n = 0 reads 0 and moves nothing.
struct CcSwfBits {
  uint32_t p, pos, bits;
  // Host bytes of the record (to the end of its page); the cursor reads a
  // byte only when it takes a bit from it, as the readers do, and takes
  // all the bits it needs from a byte at once.
  uint32_t avail = 0u;
  const uint8_t* hp;
  CcSwfBits(uint32_t rec, uint32_t start_bits) : p(rec), pos(0u), bits(start_bits), hp(cc_host_span(rec, avail)) {}
  uint32_t byte(Machine& base) const { return pos < avail ? hp[pos] : REX_LOAD_U8(p + pos); }
  uint32_t bit(Machine& base) {
    const uint32_t b = (byte(base) >> (bits - 1u)) & 1u;
    if (--bits == 0u) { bits = 8u; ++pos; }
    return b;
  }
  // n <= 32 bits, most significant first. When 8 bytes from the current
  // one are host-mapped, one big-endian load covers the field (the bytes
  // past it are host reads only, never guest accesses).
  uint32_t ubits(Machine& base, uint32_t n) {
    if (n == 0u) return 0u;
    if (pos + 8u <= avail) {
      uint64_t w;
      __builtin_memcpy(&w, hp + pos, 8);
      w = __builtin_bswap64(w);
      const uint32_t v = uint32_t((w << (8u - bits)) >> (64u - n));
      const uint32_t used = 8u - bits + n;  // from the start of byte pos
      pos += used >> 3;
      bits = 8u - (used & 7u);
      return v;
    }
    uint32_t v = 0u;
    while (n != 0u) {
      const uint32_t take = n < bits ? n : bits;
      const uint32_t chunk = (byte(base) >> (bits - take)) & ((1u << take) - 1u);
      v = take < 32u ? (v << take) | chunk : chunk;
      bits -= take;
      n -= take;
      if (bits == 0u) { bits = 8u; ++pos; }
    }
    return v;
  }
  int32_t sbits(Machine& base, uint32_t n) {
    if (n == 0u) return 0;
    const uint32_t v = ubits(base, n);
    return int32_t(((v >> (n - 1u)) & 1u) && n < 32u ? v | (~0u << n) : v);
  }
};
static bool cc_swf_mask_check(Machine& base) {
  for (uint32_t i = 0; i < 32u; ++i)
    if (REX_LOAD_U32(0x820146B0u + 4u * i) != (1u << i)) return false;
  return true;
}
static inline bool cc_swf_mask_ok(Machine& base) {
  static const bool ok = cc_swf_mask_check(base);
  return ok;
}
// SWF MATRIX record reader (exact sub_82085890: matrix r3, record r4; r3 =
// bytes read, a partly read last byte included). HasScale is bit 7 of byte
// 0, tested in place; the cursor then starts at bit 6. With it, a 5-bit
// count n and two signed n-bit fields, each converted to float and
// multiplied by the float at 0x820425E0, go to +16 / +20. One bit
// HasRotate: the same with the float at 0x820425DC into +24 / +28. Then a
// count n and, only when n is nonzero, two fields as plain floats into
// +32 / +36. Bytes +12..+14 are cleared; fields not present keep their
// values. Conversions as compiled: int -> double -> float, the product in
// double rounded to float. Switches: CC_PLACE_EXACT=1 (host) /
// CC_PLACE_EXACT_BUILD (Xbox) run the exact body; CC_ORACLE=1 or
// CC_PLACE_ORACLE=1 run it after the native decode and compare.
static CC_HOT_FN void sub_82085890(Context& ctx, Machine& base) {
  CC_FPROF_SCOPE(sub_82085890_native);
#ifndef CC_XBOX_DRIVER
  static const bool exact = std::getenv("CC_PLACE_EXACT") != nullptr;
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr || std::getenv("CC_PLACE_ORACLE") != nullptr;
#elif defined(CC_PLACE_EXACT_BUILD)
  constexpr bool exact = true;
#else
  constexpr bool exact = false;
#endif
  if (exact || !cc_swf_mask_ok(base)) { sub_82085890_exact(ctx, base); return; }
  const uint32_t m = ctx.r3.u32, rec = ctx.r4.u32;
  ctx.fpscr.disableFlushMode();
  auto f32 = [](uint32_t b) { float f; __builtin_memcpy(&f, &b, 4); return f; };
  auto bits = [](float f) { uint32_t b; __builtin_memcpy(&b, &f, 4); return b; };
  auto scaled = [](int32_t v, float c) { const float f = float(double(int64_t(v))); return float(double(f) * double(c)); };
  CcSwfBits b(rec, 7u);
  uint32_t out[6] = {};
  bool have[3] = {false, false, false};  // scale, rotate, translate
  int32_t last = 0;  // the last field converted
  bool converted = false;
  auto field = [&](uint32_t n) { last = b.sbits(base, n); converted = true; return last; };
  if (REX_LOAD_U8(rec) & 0x80u) {
    const float c = f32(REX_LOAD_U32(0x820425E0u));
    const uint32_t n = b.ubits(base, 5u);
    out[0] = bits(scaled(field(n), c));
    out[1] = bits(scaled(field(n), c));
    have[0] = true;
  }
  if (b.bit(base)) {
    const float c = f32(REX_LOAD_U32(0x820425DCu));
    const uint32_t n = b.ubits(base, 5u);
    out[2] = bits(scaled(field(n), c));
    out[3] = bits(scaled(field(n), c));
    have[1] = true;
  }
  if (const uint32_t n = b.ubits(base, 5u)) {
    out[4] = bits(float(double(int64_t(field(n)))));
    out[5] = bits(float(double(int64_t(field(n)))));
    have[2] = true;
  }
  const uint32_t used = b.bits < 8u ? b.pos + 1u : b.pos;
  // The original's stack frame as it leaves it (frame F = r1 - 144: back
  // chain, bits left +80, position +84, the last converted field as int64
  // at +88; the unsigned reader's save of r31 at F - 8). The game later
  // copies uninitialised stack words into heap objects (the 8-byte keys of
  // the tree nodes sub_82099B48 builds carry 2 padding bytes), so these
  // dead bytes are written as the original writes them.
  auto stack_frame = [&]() {
    const uint32_t r1 = ctx.r1.u32, f = r1 - 144u;
    REX_STORE_U64(f - 8u, ctx.r31.u64);
    REX_STORE_U32(f, r1);
    REX_STORE_U32(f + 80u, b.bits);
    REX_STORE_U32(f + 84u, b.pos);
    if (converted) REX_STORE_U64(f + 88u, uint64_t(int64_t(last)));
  };
#ifndef CC_XBOX_DRIVER
  if (oracle) {
    uint32_t before[6];
    for (int k = 0; k < 6; ++k) before[k] = REX_LOAD_U32(m + 16u + 4u * uint32_t(k));
    sub_82085890_exact(ctx, base);
    for (int k = 0; k < 6; ++k) {
      const uint32_t want = have[k / 2] ? out[k] : before[k];
      const uint32_t got = REX_LOAD_U32(m + 16u + 4u * uint32_t(k));
      if (got != want) cc_oracle_mismatch("sub_82085890", k, got, want);
    }
    if (ctx.r3.u32 != used) cc_oracle_mismatch("sub_82085890", 6, ctx.r3.u32, used);
    for (uint32_t k = 12u; k < 15u; ++k)
      if (REX_LOAD_U8(m + k) != 0u) cc_oracle_mismatch("sub_82085890", int(k), REX_LOAD_U8(m + k), 0u);
    const uint32_t f = ctx.r1.u32 - 144u;
    if (REX_LOAD_U32(f + 80u) != b.bits) cc_oracle_mismatch("sub_82085890 stack", 80, REX_LOAD_U32(f + 80u), b.bits);
    if (REX_LOAD_U32(f + 84u) != b.pos) cc_oracle_mismatch("sub_82085890 stack", 84, REX_LOAD_U32(f + 84u), b.pos);
    if (converted && REX_LOAD_U64(f + 88u) != uint64_t(int64_t(last)))
      cc_oracle_mismatch("sub_82085890 stack", 88, uint32_t(REX_LOAD_U64(f + 88u)), uint32_t(last));
    if (REX_LOAD_U32(f) != ctx.r1.u32) cc_oracle_mismatch("sub_82085890 stack", 0, REX_LOAD_U32(f), ctx.r1.u32);
    if (REX_LOAD_U64(f - 8u) != ctx.r31.u64) cc_oracle_mismatch("sub_82085890 stack", -8, uint32_t(REX_LOAD_U64(f - 8u)), ctx.r31.u32);
    return;
  }
#endif
  stack_frame();
  for (int k = 0; k < 6; ++k)
    if (have[k / 2]) REX_STORE_U32(m + 16u + 4u * uint32_t(k), out[k]);
  REX_STORE_U8(m + 12u, 0u); REX_STORE_U8(m + 13u, 0u); REX_STORE_U8(m + 14u, 0u);
  ctx.r3.u64 = used;
}
#endif
#include "generated/sub_82079970.inc"
#ifdef CC_FAST
#define sub_82083F50 sub_82083F50_exact
#endif
#include "generated/sub_82083F50.inc"
#ifdef CC_FAST
#undef sub_82083F50
// SWF CXFORMWITHALPHA record reader (exact sub_82083F50: colour transform
// r3, record r4; r3 = bytes read, a partly read last byte included).
// HasAddTerms is bit 7 and HasMultTerms bit 6 of byte 0, tested in place;
// the cursor then starts at bit 5 with a 4-bit count n (the unsigned
// reader sub_82095700). Multiply terms, n signed bits each (sub_82095788),
// go to +28 / +30 / +32 / +40 (red, green, blue, alpha) as 16 bits, a
// negative one stored as 0; add terms to +34 / +36 / +38 / +42 as read.
// Terms not present keep their values. When +44 is set, sub_820837C0(+44,
// transform) passes the terms on. The original's frame words are written
// as it leaves them (frame F = r1 - 176: back chain, byte position +80,
// bits left +84; the unsigned reader's save of r31 at F - 8), and lr and
// r12 as its calls leave them. Switches: CC_CXFORM_EXACT=1 (host) /
// CC_CXFORM_EXACT_BUILD (Xbox) run the original; CC_ORACLE=1 or
// CC_CXFORM_ORACLE=1 run it instead and compare the terms, the result and
// the frame words with the native's.
static CC_HOT_FN void sub_82083F50(Context& ctx, Machine& base) {
  CC_FPROF_SCOPE(sub_82083F50_native);
#ifndef CC_XBOX_DRIVER
  static const bool exact = std::getenv("CC_CXFORM_EXACT") != nullptr;
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr || std::getenv("CC_CXFORM_ORACLE") != nullptr;
#elif defined(CC_CXFORM_EXACT_BUILD)
  constexpr bool exact = true;
#else
  constexpr bool exact = false;
#endif
  if (exact || !cc_swf_mask_ok(base)) { sub_82083F50_exact(ctx, base); return; }
  const uint32_t t = ctx.r3.u32, rec = ctx.r4.u32, r1 = ctx.r1.u32, f = r1 - 176u;
  const uint32_t b0 = REX_LOAD_U8(rec);
  const bool has_mul = (b0 & 0x40u) != 0u, has_add = (b0 & 0x80u) != 0u;
  CcSwfBits b(rec, 6u);
  const uint32_t n = b.ubits(base, 4u);
  uint16_t mul[4] = {}, add[4] = {};
  if (has_mul)
    for (int k = 0; k < 4; ++k) {
      const int16_t v = int16_t(b.sbits(base, n));
      mul[k] = v < 0 ? uint16_t(0u) : uint16_t(v);
    }
  if (has_add)
    for (int k = 0; k < 4; ++k) add[k] = uint16_t(b.sbits(base, n));
  const uint32_t used = b.bits < 8u ? b.pos + 1u : b.pos;
  static constexpr uint32_t kMulOff[4] = {28u, 30u, 32u, 40u}, kAddOff[4] = {34u, 36u, 38u, 42u};
#ifndef CC_XBOX_DRIVER
  if (oracle) {
    uint16_t before[8];
    for (int k = 0; k < 4; ++k) { before[k] = REX_LOAD_U16(t + kMulOff[k]); before[4 + k] = REX_LOAD_U16(t + kAddOff[k]); }
    sub_82083F50_exact(ctx, base);
    for (int k = 0; k < 4; ++k) {
      const uint32_t wm = has_mul ? mul[k] : before[k], wa = has_add ? add[k] : before[4 + k];
      if (REX_LOAD_U16(t + kMulOff[k]) != wm) cc_oracle_mismatch("sub_82083F50 mul", k, REX_LOAD_U16(t + kMulOff[k]), wm);
      if (REX_LOAD_U16(t + kAddOff[k]) != wa) cc_oracle_mismatch("sub_82083F50 add", k, REX_LOAD_U16(t + kAddOff[k]), wa);
    }
    if (ctx.r3.u32 != used) cc_oracle_mismatch("sub_82083F50", 8, ctx.r3.u32, used);
    if (REX_LOAD_U32(f) != r1) cc_oracle_mismatch("sub_82083F50 stack", 0, REX_LOAD_U32(f), r1);
    if (REX_LOAD_U32(f + 80u) != b.pos) cc_oracle_mismatch("sub_82083F50 stack", 80, REX_LOAD_U32(f + 80u), b.pos);
    if (REX_LOAD_U32(f + 84u) != b.bits) cc_oracle_mismatch("sub_82083F50 stack", 84, REX_LOAD_U32(f + 84u), b.bits);
    if (REX_LOAD_U64(f - 8u) != ctx.r31.u64) cc_oracle_mismatch("sub_82083F50 stack", -8, uint32_t(REX_LOAD_U64(f - 8u)), ctx.r31.u32);
    return;
  }
#endif
  REX_STORE_U64(f - 8u, ctx.r31.u64);
  REX_STORE_U32(f, r1);
  REX_STORE_U32(f + 80u, b.pos);
  REX_STORE_U32(f + 84u, b.bits);
  if (has_mul)
    for (int k = 0; k < 4; ++k) REX_STORE_U16(t + kMulOff[k], mul[k]);
  if (has_add)
    for (int k = 0; k < 4; ++k) REX_STORE_U16(t + kAddOff[k], add[k]);
  ctx.r12.u64 = ctx.lr;
  ctx.lr = has_add ? 0x820840BCu : has_mul ? 0x8208400Cu : 0x82083F94u;
  if (const uint32_t next = REX_LOAD_U32(t + 44u)) {
    CcFrame frame(ctx, base, 176u);
    ctx.r3.u64 = next; ctx.r4.u64 = t; ctx.lr = 0x820840F0u;
    sub_820837C0(ctx, base);
  }
  ctx.r3.u64 = used;
}
#endif
#include "generated/sub_820837C0.inc"
#include "generated/sub_820922B8.inc"
#ifdef CC_FAST
#define sub_8208ADE8 sub_8208ADE8_exact
#endif
#include "generated/sub_8208ADE8.inc"
#ifdef CC_FAST
#undef sub_8208ADE8
#endif
#include "generated/sub_8208AFB8.inc"
#include "generated/sub_820868A8.inc"
#include "generated/sub_8208A688.inc"
#include "generated/sub_8208F828.inc"
#include "generated/sub_820920D0.inc"
#include "generated/sub_82084AC8.inc"
#include "generated/sub_82127588.inc"
#include "generated/sub_82094038.inc"
#include "generated/sub_82091DF0.inc"
#include "generated/sub_82086270.inc"
#include "generated/sub_8208C6D8.inc"
#include "generated/sub_820A9AE0.inc"
#include "generated/sub_82137048.inc"
#include "generated/sub_82053950.inc"
#include "generated/sub_8212B4B8.inc"
#include "generated/sub_82052D98.inc"
#include "generated/sub_820517E0.inc"
#include "generated/sub_82053798.inc"
#include "generated/sub_82127230.inc"
#include "generated/sub_82053098.inc"
#include "generated/sub_820534A8.inc"
#include "generated/sub_82127368.inc"
#include "generated/sub_821274B0.inc"
#include "generated/sub_82053568.inc"
#include "generated/sub_82052FA0.inc"
#include "generated/sub_82084B38.inc"
#include "generated/sub_82098F50.inc"
#include "generated/sub_82084800.inc"
#include "generated/sub_82084678.inc"
#include "generated/sub_82084720.inc"
#include "generated/sub_820B1008.inc"
#include "generated/sub_82084448.inc"
// ---- Port policy: sprite textures are stored DXT5-compressed ------------
// Castle Crashers renders its vector art into 32-bit A8R8G8B8 textures at
// load time (exact sub_820B1078 parses the shape and rasterizes it; the
// caller sub_82091AC0 then builds the texture record: w +16, h +20,
// format +24, pixels +36). A level holds ~158 MB of them; a retail 64 MB
// original Xbox cannot. The port therefore compresses each finished
// texture in place to DXT5 (4:1, read natively by the NV2A) and returns
// the unused three quarters of its block to the allocator. The pixel
// bytes are only ever consumed by the GPU path, which knows the format from
// g_dxt_textures.
static bool cc_texture_dxt5_enabled() {
#ifndef CC_XBOX_DRIVER
  static int on = -1;
  // Port default; CC_TEXTURE_DXT5=0 keeps the original 32-bit textures.
  if (on < 0) { const char* e = std::getenv("CC_TEXTURE_DXT5"); on = !(e && e[0] == '0'); }
  return on == 1;
#else
  return true;
#endif
}
// Encode one 4x4 block of RGBA pixels (r,g,b,a bytes) as standard DXT5
// (little-endian block layout as the NV2A and DDS files store it).
static void cc_dxt5_block(const uint8_t px[16][4], uint8_t out[16]) {
  // Alpha: endpoints are the block min/max, eight-value mode (a0 > a1).
  uint8_t amin = 255, amax = 0;
  for (int i = 0; i < 16; ++i) { if (px[i][3] < amin) amin = px[i][3]; if (px[i][3] > amax) amax = px[i][3]; }
  out[0] = amax; out[1] = amin;
  uint64_t abits = 0;
  if (amax != amin) {
    int pal[8] = {amax, amin};
    for (int j = 1; j <= 6; ++j) pal[1 + j] = ((7 - j) * amax + j * amin) / 7;
    for (int i = 0; i < 16; ++i) {
      int best = 0, be = 1 << 30;
      for (int k = 0; k < 8; ++k) { const int e = std::abs(pal[k] - px[i][3]); if (e < be) { be = e; best = k; } }
      abits |= uint64_t(best) << (3 * i);
    }
  }
  for (int k = 0; k < 6; ++k) out[2 + k] = uint8_t(abits >> (8 * k));
  // Colour: bounding-box endpoints inset by 1/16 of the range.
  int lo[3] = {255, 255, 255}, hi[3] = {0, 0, 0};
  for (int i = 0; i < 16; ++i)
    for (int c = 0; c < 3; ++c) { if (px[i][c] < lo[c]) lo[c] = px[i][c]; if (px[i][c] > hi[c]) hi[c] = px[i][c]; }
  for (int c = 0; c < 3; ++c) { const int in = (hi[c] - lo[c]) >> 4; lo[c] += in; hi[c] -= in; }
  auto pack = [](const int v[3]) {
    return uint16_t(((v[0] * 31 + 127) / 255) << 11 | ((v[1] * 63 + 127) / 255) << 5 | ((v[2] * 31 + 127) / 255));
  };
  uint16_t c0 = pack(hi), c1 = pack(lo);
  if (c0 < c1) { const uint16_t t = c0; c0 = c1; c1 = t; }
  auto unpack = [](uint16_t c, int v[3]) {
    v[0] = ((c >> 11) & 31) * 255 / 31; v[1] = ((c >> 5) & 63) * 255 / 63; v[2] = (c & 31) * 255 / 31;
  };
  int pal[4][3];
  unpack(c0, pal[0]); unpack(c1, pal[1]);
  for (int c = 0; c < 3; ++c) { pal[2][c] = (2 * pal[0][c] + pal[1][c]) / 3; pal[3][c] = (pal[0][c] + 2 * pal[1][c]) / 3; }
  uint32_t cbits = 0;
  if (c0 != c1)
    for (int i = 0; i < 16; ++i) {
      int best = 0, be = 1 << 30;
      for (int k = 0; k < 4; ++k) {
        int e = 0;
        for (int c = 0; c < 3; ++c) { const int d = pal[k][c] - px[i][c]; e += d * d; }
        if (e < be) { be = e; best = k; }
      }
      cbits |= uint32_t(best) << (2 * i);
    }
  out[8] = uint8_t(c0); out[9] = uint8_t(c0 >> 8); out[10] = uint8_t(c1); out[11] = uint8_t(c1 >> 8);
  for (int k = 0; k < 4; ++k) out[12 + k] = uint8_t(cbits >> (8 * k));
}
// Compress a w x h A8R8G8B8 image (big-endian guest pixels, pitch w*4) at
// src into DXT5 blocks at dst (w*h bytes). dst may equal src.
static bool cc_compress_texture_dxt5(Machine& base, uint32_t src, uint32_t dst, uint32_t w, uint32_t h) {
  if (w < 4u || h < 4u || (w & 3u) || (h & 3u) || w > 4096u || h > 4096u) return false;
  const uint8_t* p = base.memory.contiguous(src, size_t(w) * h * 4u, 3);
  uint8_t* q = base.memory.contiguous(dst, size_t(w) * h, 3);
  if (!p || !q) return false;
  static uint8_t rows[4 * 4096 * 4];
  for (uint32_t by = 0; by < h / 4u; ++by) {
    std::memcpy(rows, p + size_t(by) * 16u * w, size_t(w) * 16u);
    for (uint32_t bx = 0; bx < w / 4u; ++bx) {
      uint8_t px[16][4];
      for (int y = 0; y < 4; ++y)
        for (int x = 0; x < 4; ++x) {
          const uint8_t* s = rows + (size_t(y) * w + bx * 4u + x) * 4u;  // A R G B
          px[y * 4 + x][0] = s[1]; px[y * 4 + x][1] = s[2]; px[y * 4 + x][2] = s[3]; px[y * 4 + x][3] = s[0];
        }
      cc_dxt5_block(px, q + (size_t(by) * (w / 4u) + bx) * 16u);
    }
  }
  return true;
}
// The loader (exact sub_820B1078) allocates a w*h*4 texture block and
// parses the shape; the pixels are written later by the rasterizer (exact
// sub_820B1478: renders into a float buffer, then converts w*h pixels to
// the texture at [obj+564], pitch w*4). Between the two the game never
// touches the pixels, so the port cuts the game's block to 16 bytes at
// once (the pointer stays the texture's identity), lets the rasterizer
// write into a transient 32-bit scratch block, and compresses into the
// texture streaming cache (below). Only one full-size image exists at a
// time.
#define sub_820B1078 sub_820B1078_exact
#include "generated/sub_820B1078.inc"
#undef sub_820B1078
static void sub_820B1078(Context& ctx, Machine& base) {
  // Out parameters (as passed by sub_82091AC0): r5 -> pixels, r6 -> width,
  // r7 -> height.
  const uint32_t out_data = ctx.r5.u32, out_w = ctx.r6.u32, out_h = ctx.r7.u32;
  sub_820B1078_exact(ctx, base);
  if (!cc_texture_dxt5_enabled()) return;
  uint64_t data = 0, w = 0, h = 0;
  if (base.memory.load_be(out_data, 4, data) != cc::xbox::MemoryError::ok ||
      base.memory.load_be(out_w, 4, w) != cc::xbox::MemoryError::ok ||
      base.memory.load_be(out_h, 4, h) != cc::xbox::MemoryError::ok || !data) return;
  if (w < 4u || h < 4u || (w & 3u) || (h & 3u) || w > 4096u || h > 4096u) return;
  cc_phys_shrink(base, uint32_t(data), 16u);
  CcDxtTexture t; t.data = uint32_t(data); t.w = uint32_t(w); t.h = uint32_t(h);
  g_pending_textures.push_back(t);
}
// ---- Texture streaming ------------------------------------------------------
static void sub_820B1478_exact(Context& ctx, Machine& base);
// Compressed pixels live in a cache bounded by cc_tex_cache_limit(). Every
// texture keeps a snapshot of its 596-byte rasterizer job (the job's inputs
// are its own bytes plus the shape tag bytes in the loaded movie, which stay
// resident), so an evicted texture is regenerated on its next bind by
// replaying the exact rasterizer. Each replay is checked against the hash of
// the first compression.
static uint64_t cc_tex_cache_limit() {
#ifndef CC_XBOX_DRIVER
  static uint64_t lim = 0;
  if (!lim) { const char* e = std::getenv("CC_TEX_CACHE_KB"); lim = uint64_t(e ? std::strtoul(e, nullptr, 10) : 6144u) << 10; }
  return lim;
#else
  // Retail 64 MB budget: the 6 MiB texture zone (menus draw ~4.5 MB per
  // frame, level 1 <3 MB per 10 s; overflow goes through the Z: swap).
  return uint64_t(6144u) << 10;
#endif
}
// Host verification mode CC_TEX_EAGER=1 rasterizes every texture at load,
// as the original game does; the port default rasterizes on first bind.
static bool cc_tex_eager() {
#ifndef CC_XBOX_DRIVER
  static int on = -1;
  if (on < 0) { const char* e = std::getenv("CC_TEX_EAGER"); on = e && e[0] == '1'; }
  return on == 1;
#else
  return false;
#endif
}
static uint32_t cc_hash_bytes(const uint8_t* p, size_t n) {
  uint32_t h = 2166136261u;
  for (size_t i = 0; i < n; ++i) { h ^= p[i]; h *= 16777619u; }
  return h;
}
// ---- Texture cache zone: buddy allocator --------------------------------
// Compressed textures are power-of-two sized (w*h bytes for power-of-two
// w, h), so a buddy allocator over a dedicated 4 MiB zone at 0x1C000000
// never fragments beyond what freeing re-merges. The zone is 6 MiB: one
// 4 MiB and one 2 MiB top-level block (the menus draw ~4.5 MB of art per
// frame, so the cache must hold that even without the scratch swap). When
// no block of the needed order is free, least recently drawn textures are
// evicted (to the swap) until one is.
constexpr uint32_t kTexZoneBase = 0x1C000000u, kTexZoneOrder = 22u, kTexMinOrder = 8u;
constexpr uint32_t kTexZoneBytes = 0x600000u;
static std::vector<uint32_t> g_texzone_free[kTexZoneOrder + 1];
static std::vector<uint8_t> g_texzone_alloc_order;  // per min block: order+1 if allocated here
static std::vector<uint8_t> g_texzone_free_order;   // per min block: order+1 if free block here
static uint32_t cc_texzone_index(uint32_t a);
static void cc_texzone_init() {
  if (!g_texzone_alloc_order.empty()) return;
  const size_t n = size_t(kTexZoneBytes >> kTexMinOrder);
  g_texzone_alloc_order.assign(n, 0);
  g_texzone_free_order.assign(n, 0);
  g_texzone_free[kTexZoneOrder].push_back(kTexZoneBase);
  g_texzone_free_order[0] = uint8_t(kTexZoneOrder + 1);
  const uint32_t second = kTexZoneBase + (1u << kTexZoneOrder);
  g_texzone_free[kTexZoneOrder - 1].push_back(second);
  g_texzone_free_order[cc_texzone_index(second)] = uint8_t(kTexZoneOrder);
}
static uint32_t cc_texzone_index(uint32_t a) { return (a - kTexZoneBase) >> kTexMinOrder; }
static void cc_texzone_take(uint32_t order, uint32_t a) {
  auto& fl = g_texzone_free[order];
  for (size_t i = 0; i < fl.size(); ++i) if (fl[i] == a) { fl[i] = fl.back(); fl.pop_back(); break; }
  g_texzone_free_order[cc_texzone_index(a)] = 0;
}
static void cc_texzone_put(uint32_t order, uint32_t a) {
  g_texzone_free[order].push_back(a);
  g_texzone_free_order[cc_texzone_index(a)] = uint8_t(order + 1);
}
static uint32_t cc_texzone_try_alloc(uint32_t bytes) {
  cc_texzone_init();
  uint32_t order = kTexMinOrder;
  while ((1u << order) < bytes) ++order;
  if (order > kTexZoneOrder) return 0;
  uint32_t k = order;
  while (k <= kTexZoneOrder && g_texzone_free[k].empty()) ++k;
  if (k > kTexZoneOrder) return 0;
  const uint32_t a = g_texzone_free[k].back();
  cc_texzone_take(k, a);
  while (k > order) { --k; cc_texzone_put(k, a + (1u << k)); }
  g_texzone_alloc_order[cc_texzone_index(a)] = uint8_t(order + 1);
  return a;
}
static bool cc_texzone_free(uint32_t a) {
  if (a < kTexZoneBase || a >= kTexZoneBase + kTexZoneBytes || g_texzone_alloc_order.empty()) return false;
  const uint32_t ix = cc_texzone_index(a);
  if (!g_texzone_alloc_order[ix]) return false;
  uint32_t order = g_texzone_alloc_order[ix] - 1u;
  g_texzone_alloc_order[ix] = 0;
  while (order < kTexZoneOrder) {
    const uint32_t buddy = kTexZoneBase + (((a - kTexZoneBase) ^ (1u << order)));
    if (buddy + (1u << order) > kTexZoneBase + kTexZoneBytes) break;  // top of the 2 MiB block
    if (g_texzone_free_order[cc_texzone_index(buddy)] != uint8_t(order + 1)) break;
    cc_texzone_take(order, buddy);
    a = a < buddy ? a : buddy;
    ++order;
  }
  cc_texzone_put(order, a);
  return true;
}
// Scratch swap for evicted textures (the retail install runs from the hard
// drive; Z: is the title's scratch drive, which the dashboard may wipe, so
// the swap is only ever a cache: a missing or wrong copy is re-rasterized).
// Regions are reused by exact size when textures are freed.
static std::FILE* g_tex_swap = nullptr;
static bool g_tex_swap_tried = false;
static int64_t g_tex_swap_end = 0;
static std::vector<std::pair<int64_t, uint32_t>>& g_tex_swap_free = g_tex_swap_free_early;
static std::FILE* cc_tex_swap() {
  if (g_tex_swap_tried) return g_tex_swap;
  g_tex_swap_tried = true;
#ifdef CC_XBOX_DRIVER
  const bool was_mounted = nxIsDriveMounted('Z');
  const bool mounted = was_mounted || nxMountDrive('Z', "\\Device\\Harddisk0\\Partition5\\");
  g_tex_swap = std::fopen("Z:\\cctexswap.bin", "w+b");
  cc_log("TEXSWAP Z: was_mounted=%d mounted=%d open=%d\n", int(was_mounted), int(mounted),
         int(g_tex_swap != nullptr));
#else
  const char* dir = std::getenv("CC_SCRATCH_DIR");
  char path[400];
  if (dir) std::snprintf(path, sizeof(path), "%s/cctexswap.bin", dir);
  else {
    std::snprintf(path, sizeof(path), "%s", g_game_root);
    const size_t n = std::strlen(path);
    if (n >= 9 && !std::strcmp(path + n - 9, "extracted"))
      std::snprintf(path + n - 9, sizeof(path) - (n - 9), "converted/cctexswap.bin");
    else path[0] = 0;
  }
  if (path[0] && !(dir && !std::strcmp(dir, "none"))) g_tex_swap = std::fopen(path, "w+b");
#endif
  if (!g_tex_swap) cc_log("TEXSWAP unavailable; evicted textures are re-rasterized%c", 10);
  return g_tex_swap;
}
static void cc_tex_swap_release(CcDxtTexture& t) {
  if (t.swap_off >= 0) g_tex_swap_free.push_back({t.swap_off, t.w * t.h});
  t.swap_off = -1;
}
// Write an evicted texture's pixels to the swap (once; they never change).
static void cc_tex_swap_out(Machine& base, CcDxtTexture& t) {
  if (t.swap_off >= 0 || !t.hashed || t.bake >= 0) return;
  std::FILE* f = cc_tex_swap();
  const uint8_t* q = base.memory.contiguous(t.cache, size_t(t.w) * t.h, 1);
  if (!f || !q) return;
  const uint32_t bytes = t.w * t.h;
  int64_t off = -1;
  for (size_t i = 0; i < g_tex_swap_free.size(); ++i)
    if (g_tex_swap_free[i].second == bytes) {
      off = g_tex_swap_free[i].first;
      g_tex_swap_free.erase(g_tex_swap_free.begin() + long(i));
      break;
    }
  if (off < 0) { off = g_tex_swap_end; g_tex_swap_end += bytes; }
  if (std::fseek(f, long(off), SEEK_SET) != 0 || std::fwrite(q, 1, bytes, f) != bytes) {
    g_tex_swap_free.push_back({off, bytes});
    return;
  }
  t.swap_off = off;
  ++g_tex_swap_outs;
}
// Read a texture back from the swap into a new cache block; 0 on failure.
static uint32_t cc_tex_swap_in(Machine& base, CcDxtTexture& t) {
  std::FILE* f = g_tex_swap;
  if (t.swap_off < 0 || !f) return 0;
  const uint32_t bytes = t.w * t.h;
  const uint32_t cache = cc_texzone_alloc(base, bytes, t.data);
  uint8_t* q = base.memory.contiguous(cache, bytes, 3);
  if (!q || std::fseek(f, long(t.swap_off), SEEK_SET) != 0 || std::fread(q, 1, bytes, f) != bytes
#ifndef CC_XBOX_DRIVER
      || cc_hash_bytes(q, bytes) != t.hash  // diagnostic; the Xbox skips the GPU-memory read-back
#endif
      ) {
    cc_texzone_free(cache);
    cc_tex_swap_release(t);
    return 0;
  }
  g_tex_cache_bytes += bytes;
  ++g_tex_swap_ins;
  return cache;
}
// Evict least recently bound textures until the cache fits (never `keep`).
// Least recently bound resident texture other than `keep`. On the Xbox a
// texture bound this frame is still referenced by queued draws (the GPU
// samples the zone directly), so those are evicted only when nothing else
// is resident, and then only after the GPU has finished the queued work.
static CcDxtTexture* cc_tex_pick_victim(uint32_t keep) {
  CcDxtTexture* victim = nullptr;
#ifdef CC_XBOX_DRIVER
  for (auto& t : g_dxt_textures)
    if (t.cache && t.data != keep && t.last_use != g_frame_delay_calls &&
        (!victim || t.last_use < victim->last_use)) victim = &t;
  if (victim) return victim;
  for (auto& t : g_dxt_textures)
    if (t.cache && t.data != keep && (!victim || t.last_use < victim->last_use)) victim = &t;
  if (victim) ::cc_xr_gpu_idle();
#else
  for (auto& t : g_dxt_textures)
    if (t.cache && t.data != keep && (!victim || t.last_use < victim->last_use)) victim = &t;
#endif
  return victim;
}
static void cc_tex_cache_trim(Machine& base, uint32_t keep) {
  while (g_tex_cache_bytes > cc_tex_cache_limit()) {
    CcDxtTexture* victim = cc_tex_pick_victim(keep);
    if (!victim) return;
    cc_tex_swap_out(base, *victim);
    const uint32_t cache = victim->cache;
    victim->cache = 0;
    g_tex_cache_bytes -= uint64_t(victim->w) * victim->h;
    ++g_tex_evictions;
    cc_texzone_free(cache);
  }
}
// A cache block for a w*h texture, evicting least recently drawn textures
// (never `keep`) until the zone has a free block of the right order.
static uint32_t cc_texzone_alloc(Machine& base, uint32_t bytes, uint32_t keep) {
  for (;;) {
    if (const uint32_t a = cc_texzone_try_alloc(bytes)) return a;
    CcDxtTexture* victim = cc_tex_pick_victim(keep);
    if (!victim) base.fail(Error::memory, kTexZoneBase);
    cc_tex_swap_out(base, *victim);
    const uint32_t cache = victim->cache;
    victim->cache = 0;
    g_tex_cache_bytes -= uint64_t(victim->w) * victim->h;
    ++g_tex_evictions;
    cc_texzone_free(cache);
  }
}
// Run the exact rasterizer on `job` with its output redirected to a scratch
// block, then compress into a fresh cache block. Returns the cache address
// (0 on failure) and the hash of the compressed pixels.
static uint32_t cc_tex_rasterize_impl(Context& ctx, Machine& base, uint32_t job,
                                      uint32_t w, uint32_t h, uint32_t& hash);
static uint32_t cc_tex_rasterize(Context& ctx, Machine& base, uint32_t job,
                                 uint32_t w, uint32_t h, uint32_t& hash) {
#ifndef CC_XBOX_DRIVER
  const auto t0 = std::chrono::steady_clock::now();
  const uint32_t r = cc_tex_rasterize_impl(ctx, base, job, w, h, hash);
  g_raster_seconds += std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
  ++g_raster_count;
  return r;
#else
  // A texture rasterized on the console is missing from the bake pack (the
  // rasterizer's 4.8 MiB of game-heap work blocks then come mid-level).
  ::DbgPrint("TEXBAKE miss: job %08x %ux%u rasterized live (not in the pack)\n", unsigned(job), unsigned(w), unsigned(h));
  return cc_tex_rasterize_impl(ctx, base, job, w, h, hash);
#endif
}
static uint32_t cc_tex_rasterize_impl(Context& ctx, Machine& base, uint32_t job,
                                      uint32_t w, uint32_t h, uint32_t& hash) {
  const uint32_t scratch = cc_phys_alloc(base, w * h * 4u, 0x1000u);
#ifndef CC_XBOX_DRIVER
  if (std::getenv("CC_RASTER_LOG"))
    std::fprintf(stderr, "RASTERIZE frame=%u job=%08x w=%u h=%u scratch=%08x\n", g_frame_delay_calls, job, w, h, scratch);
#endif
  base.memory.store_be(job + 564u, 4, scratch);
  Context c = ctx;
  c.r3.u64 = job;
  sub_820B1478_exact(c, base);
  const uint32_t cache = cc_texzone_alloc(base, w * h, g_tex_alloc_keep);
  const bool ok = cc_compress_texture_dxt5(base, scratch, cache, w, h);
  cc_phys_free(base, scratch);
  if (!ok) { cc_texzone_free(cache); return 0; }
  const uint8_t* q = base.memory.contiguous(cache, size_t(w) * h, 1);
  hash = q ? cc_hash_bytes(q, size_t(w) * h) : 0u;
  g_tex_cache_bytes += uint64_t(w) * h;
  return cache;
}
// Hand the bound texture to the Xbox renderer: streamed DXT5 textures from
// the texture cache zone, other formats (the A4R4G4B4 font atlas) from the
// game's own block. t: the record's streamed texture (cc_dxt_lookup of
// rec.data, as returned by cc_tex_stream_on_bind), or nullptr. The host
// address of the last pixel span is kept: guest regions are mapped once and
// never move, and consecutive binds mostly repeat the texture.
static void cc_xr_on_bind([[maybe_unused]] Machine& base, [[maybe_unused]] const CcTexRec& rec,
                          [[maybe_unused]] const CcDxtTexture* t) {
#ifdef CC_XBOX_DRIVER
  static uint32_t last_a = 0, last_n = 0;
  static const uint8_t* last_q = nullptr;
  auto span = [&](uint32_t a, size_t n) -> const uint8_t* {
    if (a == last_a && n == last_n && last_q) return last_q;
    const uint8_t* q = base.memory.contiguous(a, n, 1);
    if (q) { last_a = a; last_n = uint32_t(n); last_q = q; }
    return q;
  };
  if (t) {
    const uint8_t* q = t->cache ? span(t->cache, size_t(t->w) * t->h) : nullptr;
    ::cc_xr_bind(rec.data, q, t->w, t->h, 100);
    return;
  }
  const uint32_t bpp = rec.fmt == 1u ? 4u : (rec.fmt == 5u ? 2u : 0u);
  const uint8_t* q = bpp ? span(rec.data, size_t(rec.w) * rec.h * bpp) : nullptr;
  ::cc_xr_bind(rec.data, q, rec.w, rec.h, int(rec.fmt));
#endif
}
// ---- Baked texture pack ----------------------------------------------------
// A texture's pixels depend only on its rasterizer job's inputs (flags at
// +540/+541, size and pixel count at +552..+563, transform at +572..+595)
// and the shape bytes its stream pointer (+20) walks. The host harness
// (CC_TEX_BAKE=<file>) records every first rasterization as DXT5 keyed by a
// fingerprint of those inputs; the port then loads a texture from the pack
// (CC_TEX_PACK=<file> on the host, <game root>\texbake.pak on the Xbox)
// instead of rasterizing it, which removes the first-appearance stalls.
// Keys: key0 over the job inputs and the first 64 shape bytes (lookup),
// full over the job inputs and all `len` shape bytes the rasterizer read
// (confirmation). A texture not in the pack is rasterized as before.
struct CcBakeEntry { uint32_t key0, full, len, w, h, offset; };
static std::vector<CcBakeEntry> g_bake_index;   // sorted by key0
static bool g_bake_loaded = false, g_bake_ready = false;
#ifdef CC_XBOX_DRIVER
// The Xbox reads the pack with NtReadFile at each entry's offset, straight
// into the texture's cache block or the read-ahead buffer (nxdk's fread
// copies through its buffer byte by byte, unoptimised).
static HANDLE g_bake_handle = INVALID_HANDLE_VALUE;
#else
static std::FILE* g_bake_file = nullptr;
#endif
static bool cc_bake_pixels(uint8_t* q, uint32_t offset, uint32_t bytes) {
#ifdef CC_XBOX_DRIVER
  IO_STATUS_BLOCK io{};
  LARGE_INTEGER at;
  at.QuadPart = offset;
  NTSTATUS st = NtReadFile(g_bake_handle, nullptr, nullptr, nullptr, &io, q, bytes, &at);
  if (st == STATUS_PENDING) {
    st = NtWaitForSingleObject(g_bake_handle, FALSE, nullptr);
    if (NT_SUCCESS(st)) st = io.Status;
  }
  return NT_SUCCESS(st) && io.Information == bytes;
#else
  return std::fseek(g_bake_file, long(offset), SEEK_SET) == 0 && std::fread(q, 1, bytes, g_bake_file) == bytes;
#endif
}
// Read-ahead. On the console a pack read in key order is a disk seek each
// (36 reads of 1.5 MB took one 370 ms frame when new enemies appeared).
// With the pack laid out in first-use order (tools/texbake_order.py) the
// textures needed next follow the one being read, so a first read that
// misses the buffer reads that texture and the whole entries stored after
// it, up to the buffer size, in one disk read, and the next first uses are
// copied from memory. A fill that served nothing stops further fills until
// a read continues where the previous disk read ended (a pack in key order
// gains nothing from reading ahead); re-reads of evicted textures go
// straight to their cache block. Bytes are the pack's either way. Size:
// host CC_BAKE_READAHEAD_KB=<KiB> (0: off), Xbox make BAKERA=<KiB> (0: off);
// default 512 KiB (MEM shows ~7.5 MB free in a 4P fight). Larger buffers
// mean fewer disk reads but more bytes read during the frame that misses.
#ifndef CC_BAKE_READAHEAD_KB
#define CC_BAKE_READAHEAD_KB 512
#endif
constexpr uint32_t kBakeNone = 0xFFFFFFFFu;
static std::vector<uint32_t> g_bake_next;  // entry -> the entry stored after it
static std::vector<uint8_t> g_bake_seen;   // entry read before
static uint8_t* g_bake_buf = nullptr;
static uint32_t g_bake_buf_size = 0, g_bake_buf_lo = 0, g_bake_buf_hi = 0, g_bake_buf_hits = 0;
static uint32_t g_bake_disk_end = kBakeNone;  // pack offset where the last disk read ended
static bool g_bake_filled = false;
static uint32_t g_bake_disk_reads = 0, g_bake_disk_seeks = 0, g_bake_from_buf = 0;
static uint64_t g_bake_disk_bytes = 0;
// One disk read of the pack, counted (reads, seeks: reads not starting where
// the previous one ended, bytes; on the Xbox also its time for FRAME).
static bool cc_bake_disk(uint8_t* q, uint32_t offset, uint32_t bytes) {
  const bool seek = offset != g_bake_disk_end;
  ++g_bake_disk_reads; g_bake_disk_seeks += seek; g_bake_disk_bytes += bytes;
#ifdef CC_XBOX_DRIVER
  const unsigned long long t0 = cc_monotonic_ns();
  const bool ok = cc_bake_pixels(q, offset, bytes);
  const uint32_t us = uint32_t((cc_monotonic_ns() - t0) / 1000u);
  ++g_fs_disk_reads; g_fs_disk_seeks += seek; g_fs_disk_bytes += bytes;
  g_fs_disk_us += us;
  if (us > g_fs_disk_max_us) g_fs_disk_max_us = us;
#else
  const bool ok = cc_bake_pixels(q, offset, bytes);
#endif
  g_bake_disk_end = ok ? offset + bytes : kBakeNone;
  return ok;
}
// Oracle (host, CC_ORACLE=1): pixels copied from the read-ahead buffer are
// checked against a direct read of the pack.
static void cc_bake_oracle([[maybe_unused]] size_t i, [[maybe_unused]] const uint8_t* q,
                           [[maybe_unused]] uint32_t bytes) {
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
  if (!oracle) return;
  std::vector<uint8_t> direct(bytes);
  if (!cc_bake_pixels(direct.data(), g_bake_index[i].offset, bytes) || std::memcmp(direct.data(), q, bytes) != 0)
    cc_oracle_mismatch("cc_bake_fetch", int(i), cc_hash_bytes(direct.data(), bytes), cc_hash_bytes(q, bytes));
#endif
}
// Copy pack entry i's pixels (bytes) to q: from the read-ahead buffer, by
// filling it, or straight from the disk. first: the entry's first read;
// buffered: served from memory.
static bool cc_bake_fetch(size_t i, uint8_t* q, uint32_t bytes, bool& first, bool& buffered) {
  const uint32_t o = g_bake_index[i].offset;
  first = !g_bake_seen[i];
  g_bake_seen[i] = 1;
  buffered = false;
  if (g_bake_buf && o >= g_bake_buf_lo && o <= g_bake_buf_hi && g_bake_buf_hi - o >= bytes) {
    std::memcpy(q, g_bake_buf + (o - g_bake_buf_lo), bytes);
    ++g_bake_buf_hits; ++g_bake_from_buf;
    buffered = true;
    cc_bake_oracle(i, q, bytes);
    return true;
  }
  if (g_bake_buf && first && bytes <= g_bake_buf_size &&
      (!g_bake_filled || g_bake_buf_hits || o == g_bake_disk_end)) {
    uint32_t end = o + bytes;
    for (uint32_t k = g_bake_next[i]; k != kBakeNone; k = g_bake_next[k]) {
      const CcBakeEntry& n = g_bake_index[k];
      const uint32_t ne = n.offset + n.w * n.h;
      if (ne - o > g_bake_buf_size) break;
      if (ne > end) end = ne;  // a pack sharing blocks must not shrink the fill
    }
    g_bake_filled = true;
    g_bake_buf_hits = 0;
    g_bake_buf_lo = g_bake_buf_hi = 0;
    if (cc_bake_disk(g_bake_buf, o, end - o)) {
      g_bake_buf_lo = o;
      g_bake_buf_hi = end;
      std::memcpy(q, g_bake_buf, bytes);
      cc_bake_oracle(i, q, bytes);
      return true;
    }
    // A fill cut short (damaged pack): read just the entry.
  }
  return cc_bake_disk(q, o, bytes);
}
#ifndef CC_XBOX_DRIVER
// Host recorder CC_TEX_ORDER=<file>: one line per baked-texture read, the
// input of tools/texbake_order.py (pack layout in first-use order).
static void cc_bake_note_read(size_t i, bool first, bool buffered) {
  static std::FILE* f = [] { const char* p = std::getenv("CC_TEX_ORDER"); return p ? std::fopen(p, "w") : nullptr; }();
  if (!f) return;
  const CcBakeEntry& e = g_bake_index[i];
  std::fprintf(f, "TEXREAD frame=%u entry=%u key0=%08x full=%08x bytes=%u first=%d from=%s%c", g_frame_delay_calls + 1u,
               unsigned(i), e.key0, e.full, e.w * e.h, int(first), buffered ? "buffer" : "disk", 10);
  std::fflush(f);
}
// Pack reading totals at exit (host runs; the Xbox shows them per second in
// FRAME).
static struct CcBakeTotals {
  ~CcBakeTotals() {
    if (!g_bake_ready) return;
    cc_log("TEXBAKE totals reads=%u from_buffer=%u disk_reads=%u seeks=%u disk_kb=%llu readahead=%uK%c",
           g_bake_hits, g_bake_from_buf, g_bake_disk_reads, g_bake_disk_seeks,
           (unsigned long long)(g_bake_disk_bytes >> 10), unsigned(g_bake_buf_size >> 10), 10);
  }
} g_bake_totals;
#endif
static uint32_t cc_fnv(uint32_t h, const uint8_t* p, size_t n) {
  for (size_t i = 0; i < n; ++i) { h ^= p[i]; h *= 16777619u; }
  return h;
}
static uint32_t cc_bake_fields(const uint8_t* job) {
  uint32_t h = 2166136261u;
  h = cc_fnv(h, job + 540, 2);
  h = cc_fnv(h, job + 552, 12);
  h = cc_fnv(h, job + 572, 24);
  return h;
}
static uint32_t cc_bake_stream_ptr(const uint8_t* job) {
  return uint32_t(job[20]) << 24 | uint32_t(job[21]) << 16 | uint32_t(job[22]) << 8 | job[23];
}
// The pack's open result goes to the debug channel on the Xbox (cc_log is
// silent in the play build): without the pack every texture is rasterized
// on first use, which shows as a slowdown, not as an error.
#ifdef CC_XBOX_DRIVER
#define CC_BAKE_NOTE DbgPrint
#define CC_BAKE_FAIL DbgPrint
#else
#define CC_BAKE_NOTE cc_log
#define CC_BAKE_FAIL cc_elog
#endif
static void cc_bake_load() {
  if (g_bake_loaded) return;
  g_bake_loaded = true;
  char path[400] = {};
#ifdef CC_XBOX_DRIVER
  std::snprintf(path, sizeof(path), "%s\\texbake.pak", g_game_root);
#else
  const char* e = std::getenv("CC_TEX_PACK");
  if (!e) return;
  std::snprintf(path, sizeof(path), "%s", e);
#endif
  std::FILE* f = std::fopen(path, "rb");
  if (!f) {
    CC_BAKE_FAIL("TEXBAKE pack %s: cannot open; textures are rasterized on first use%c", path, 10);
    return;
  }
  uint8_t head[8];
  if (std::fread(head, 1, 8, f) != 8 || std::memcmp(head, "TXB1", 4)) {
    CC_BAKE_FAIL("TEXBAKE pack %s: not a texture pack; textures are rasterized on first use%c", path, 10);
    std::fclose(f);
    return;
  }
  const uint32_t count = uint32_t(head[4]) | uint32_t(head[5]) << 8 | uint32_t(head[6]) << 16 | uint32_t(head[7]) << 24;
  g_bake_index.resize(count);
  if (std::fread(g_bake_index.data(), sizeof(CcBakeEntry), count, f) != count) {
    CC_BAKE_FAIL("TEXBAKE pack %s: index of %u entries cut short; textures are rasterized on first use%c", path,
                 count, 10);
    g_bake_index.clear(); std::fclose(f); return;
  }
#ifdef CC_XBOX_DRIVER
  std::fclose(f);
  g_bake_handle = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING,
                              FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS, nullptr);
  if (g_bake_handle == INVALID_HANDLE_VALUE) {
    CC_BAKE_FAIL("TEXBAKE pack %s: CreateFileA failed (error %u); textures are rasterized on first use%c", path,
                 unsigned(GetLastError()), 10);
    g_bake_index.clear();
    return;
  }
#else
  g_bake_file = f;
#endif
  g_bake_ready = true;
  // Storage order for the read-ahead: each entry's successor in the file.
  {
    std::vector<uint32_t> order(count);
    for (uint32_t i = 0; i < count; ++i) order[i] = i;
    std::sort(order.begin(), order.end(),
              [](uint32_t a, uint32_t b) { return g_bake_index[a].offset < g_bake_index[b].offset; });
    g_bake_next.assign(count, kBakeNone);
    for (uint32_t k = 0; k + 1u < count; ++k) g_bake_next[order[k]] = order[k + 1u];
    g_bake_seen.assign(count, 0);
  }
#ifdef CC_XBOX_DRIVER
  const uint32_t ra_kb = CC_BAKE_READAHEAD_KB;
  if (ra_kb) {
    PVOID b = nullptr;
    SIZE_T s = SIZE_T(ra_kb) << 10;
    if (NT_SUCCESS(NtAllocateVirtualMemory(&b, 0, &s, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE))) {
      g_bake_buf = static_cast<uint8_t*>(b);
      g_bake_buf_size = ra_kb << 10;
    }
  }
#else
  const char* ra_env = std::getenv("CC_BAKE_READAHEAD_KB");
  const uint32_t ra_kb = ra_env ? uint32_t(std::strtoul(ra_env, nullptr, 10)) : uint32_t(CC_BAKE_READAHEAD_KB);
  if (ra_kb) {
    static std::vector<uint8_t> storage;
    storage.assign(size_t(ra_kb) << 10, 0);
    g_bake_buf = storage.data();
    g_bake_buf_size = ra_kb << 10;
  }
#endif
  CC_BAKE_NOTE("TEXBAKE pack %s: %u textures, read-ahead %uK%s%c", path, count, unsigned(g_bake_buf_size >> 10),
               ra_kb && !g_bake_buf ? " (allocation failed: off)" : "", 10);
}
// Look the job up in the pack (the shape stream must be resident, so this
// is done when the texture is registered): the entry index, or -1.
static int32_t cc_bake_find(Machine& base, const uint8_t* job, uint32_t w, uint32_t h) {
  cc_bake_load();
  if (!g_bake_ready || g_bake_index.empty()) return -1;
  const uint32_t sp = cc_bake_stream_ptr(job);
  const uint8_t* s64 = base.memory.contiguous(sp, 64u, 1);
  if (!s64) return -1;
  const uint32_t fields = cc_bake_fields(job);
  const uint32_t key0 = cc_fnv(fields, s64, 64);
  size_t lo = 0, hi = g_bake_index.size();
  while (lo < hi) { const size_t mid = (lo + hi) / 2; if (g_bake_index[mid].key0 < key0) lo = mid + 1; else hi = mid; }
  for (size_t i = lo; i < g_bake_index.size() && g_bake_index[i].key0 == key0; ++i) {
    const CcBakeEntry& e = g_bake_index[i];
    if (e.w != w || e.h != h) continue;
    const uint8_t* s = base.memory.contiguous(sp, e.len, 1);
    if (!s || cc_fnv(fields, s, e.len) != e.full) continue;
    return int32_t(i);
  }
  return -1;
}
// Read a pack entry's DXT5 pixels into a new cache block (0 on failure).
static uint32_t cc_bake_read(Machine& base, int32_t entry, uint32_t w, uint32_t h, uint32_t keep) {
  if (entry < 0 || size_t(entry) >= g_bake_index.size() || !g_bake_ready) { ++g_bake_misses; return 0; }
  const uint32_t cache = cc_texzone_alloc(base, w * h, keep);
  uint8_t* q = base.memory.contiguous(cache, size_t(w) * h, 3);
  bool first = false, buffered = false;
  if (!q || !cc_bake_fetch(size_t(entry), q, w * h, first, buffered)) {
    cc_texzone_free(cache);
    ++g_bake_misses;
    return 0;
  }
#ifndef CC_XBOX_DRIVER
  cc_bake_note_read(size_t(entry), first, buffered);
#endif
  g_tex_cache_bytes += uint64_t(w) * h;
  ++g_bake_hits;
#ifdef CC_XBOX_DRIVER
  ++g_fs_bake_reads; g_fs_bake_bytes += w * h;
#endif
  return cache;
}
// Resolve a texture's pack entry; a packed texture drops its job. At
// registration a miss is not final (text shapes are written after their
// texture is registered), so the first bind looks again.
static void cc_bake_resolve(Machine& base, CcDxtTexture& t, bool final_lookup) {
  if (t.bake != -2) return;
  const int32_t e = t.job.size() == 596u ? cc_bake_find(base, t.job.data(), t.w, t.h) : -1;
  if (e >= 0) { t.bake = e; std::vector<uint8_t>().swap(t.job); }
  else if (final_lookup) t.bake = -1;
}
#ifndef CC_XBOX_DRIVER
// Bake mode: remember each first rasterization; written at exit.
struct CcBakeRecord { CcBakeEntry e; std::vector<uint8_t> pixels; };
struct CcBakeWriter {
  std::vector<CcBakeRecord> records;
  ~CcBakeWriter() {
    const char* path = std::getenv("CC_TEX_BAKE");
    if (!path || records.empty()) return;
    std::sort(records.begin(), records.end(), [](const CcBakeRecord& a, const CcBakeRecord& b) {
      return a.e.key0 < b.e.key0;
    });
    std::FILE* f = std::fopen(path, "wb");
    if (!f) return;
    const uint32_t count = uint32_t(records.size());
    uint32_t offset = 8u + count * uint32_t(sizeof(CcBakeEntry));
    for (auto& r : records) { r.e.offset = offset; offset += uint32_t(r.pixels.size()); }
    std::fwrite("TXB1", 1, 4, f);
    std::fwrite(&count, 4, 1, f);
    for (const auto& r : records) std::fwrite(&r.e, sizeof(CcBakeEntry), 1, f);
    for (const auto& r : records) std::fwrite(r.pixels.data(), 1, r.pixels.size(), f);
    std::fclose(f);
    std::fprintf(stderr, "TEXBAKE wrote %u textures to %s\n", count, path);
  }
};
static CcBakeWriter g_bake_writer;
static void cc_bake_record(Machine& base, const uint8_t* snapshot, uint32_t job_after, uint32_t cache, uint32_t w, uint32_t h) {
  if (!std::getenv("CC_TEX_BAKE") || !cache) return;
  uint64_t end_ptr = 0;
  base.memory.load_be(job_after + 20u, 4, end_ptr);
  const uint32_t sp = cc_bake_stream_ptr(snapshot);
  const uint32_t len = uint32_t(end_ptr) - sp;
  if (uint32_t(end_ptr) < sp || len > 0x400000u) return;
  const uint8_t* s = base.memory.contiguous(sp, len > 64u ? len : 64u, 1);
  const uint8_t* q = base.memory.contiguous(cache, size_t(w) * h, 1);
  if (!s || !q) return;
  const uint32_t fields = cc_bake_fields(snapshot);
  CcBakeRecord r;
  r.e = CcBakeEntry{cc_fnv(fields, s, 64), cc_fnv(fields, s, len), len, w, h, 0};
  for (const auto& o : g_bake_writer.records) if (o.e.full == r.e.full && o.e.key0 == r.e.key0) return;
  r.pixels.assign(q, q + size_t(w) * h);
  g_bake_writer.records.push_back(std::move(r));
}
#endif
// Make a streamed texture (pixel pointer `data`) resident at its bind.
// Returns its entry, or nullptr; `ran` is set when the pixels had to be
// produced (swap, pack or rasterizer, which runs guest code), after which
// the caller looks the record and the entry up again.
static void cc_tex_stream_fill(Context& ctx, Machine& base, CcDxtTexture& tr);
static const CcDxtTexture* cc_tex_stream_on_bind(Context& ctx, Machine& base, uint32_t data, bool& ran) {
  ran = false;
  CcDxtTexture* t = cc_dxt_lookup(data);
  if (!t) return nullptr;
  t->last_use = g_frame_delay_calls;
  if (t->cache) return t;
  cc_tex_stream_fill(ctx, base, *t);
  ran = true;
  return nullptr;
}
static void cc_tex_stream_fill(Context& ctx, Machine& base, CcDxtTexture& tr) {
  CcDxtTexture* t = &tr;
  if (const uint32_t swapped = cc_tex_swap_in(base, *t)) {
    t->cache = swapped;
    cc_tex_cache_trim(base, t->data);
    return;
  }
  // A baked copy replaces the rasterization when the pack has it.
  cc_bake_resolve(base, *t, true);
  if (t->bake >= 0) {
    const uint32_t baked = cc_bake_read(base, t->bake, t->w, t->h, t->data);
    if (!baked) return;  // pack read failed: draw untextured rather than stop
#ifndef CC_XBOX_DRIVER
    const uint8_t* q = base.memory.contiguous(baked, size_t(t->w) * t->h, 1);
    const uint32_t hash = q ? cc_hash_bytes(q, size_t(t->w) * t->h) : 0u;
    if (!t->hashed) { t->hash = hash; t->hashed = true; }
    else if (hash != t->hash) {
      ++g_tex_replay_mismatches;
      cc_elog("TEXBAKE mismatch data=%08x %ux%u\n", t->data, t->w, t->h);
    }
#else
    t->hashed = true;
#endif
    t->cache = baked;
    cc_tex_cache_trim(base, t->data);
    return;
  }
  if (t->job.size() != 596u) return;  // nothing to regenerate from
  // Regenerate from the snapshot in a guest job block.
  const uint32_t job = cc_phys_alloc(base, 596u, 16u);
  uint8_t* jp = base.memory.contiguous(job, 596u, 3);
  if (!jp) base.fail(Error::memory, job);
  std::memcpy(jp, t->job.data(), 596u);
  const uint32_t want = t->hash, data_key = t->data, w = t->w, h = t->h;
  uint32_t hash = 0;
  g_tex_alloc_keep = data_key;
  const uint32_t cache = cc_tex_rasterize(ctx, base, job, w, h, hash);
#ifndef CC_XBOX_DRIVER
  if (!t->hashed) cc_bake_record(base, t->job.data(), job, cache, w, h);
#endif
  cc_phys_free(base, job);
  if (CcDxtTexture* e = cc_dxt_lookup(data_key)) e->cache = cache;
  bool first = false;
  if (CcDxtTexture* e = cc_dxt_lookup(data_key)) {
    first = !e->hashed;
    if (first) { e->hash = hash; e->hashed = true; }
  }
  if (first) { cc_tex_cache_trim(base, data_key); return; }
  ++g_tex_replays;
  if (hash != want) {
    ++g_tex_replay_mismatches;
    cc_elog("TEXSTREAM replay mismatch data=%08x %ux%u\n", data_key, w, h);
  }
  cc_tex_cache_trim(base, data_key);
}
#define sub_820B1478 sub_820B1478_exact
#include "generated/sub_820B1478.inc"
#undef sub_820B1478
static void sub_820B1478(Context& ctx, Machine& base) {
  const uint32_t obj = ctx.r3.u32;
  uint64_t target = 0;
  base.memory.load_be(obj + 564u, 4, target);
  size_t pending = g_pending_textures.size();
  for (size_t i = 0; i < g_pending_textures.size(); ++i)
    if (g_pending_textures[i].data == uint32_t(target)) { pending = i; break; }
  if (pending == g_pending_textures.size()) {
    if (cc_texture_dxt5_enabled() && cc_find_dxt_texture(uint32_t(target))) {
      // The game's block for a known texture is only 16 bytes: stop rather
      // than let a second rasterization write past it.
      cc_elog("DXT5 texture %08x rasterized again\n", uint32_t(target));
      base.fail(Error::unsupported, 0x820B1478u);
    }
    sub_820B1478_exact(ctx, base);
    return;
  }
  CcDxtTexture t = g_pending_textures[pending];
  g_pending_textures.erase(g_pending_textures.begin() + long(pending));
  // Snapshot the job before the rasterizer advances its stream pointer.
  t.job.resize(596u);
  if (base.memory.read(obj, t.job.data(), 596u) != cc::xbox::MemoryError::ok)
    base.fail(Error::memory, obj);
  const uint32_t key = t.data;
  if (!cc_tex_eager()) {
    // Lazy: the pixels are produced on first bind. The exact rasterizer
    // only allocates and frees its own temporaries, so skipping it here
    // leaves no game-visible state behind. Packed textures are identified
    // now, while the shape stream is in memory, and keep no job snapshot.
    cc_bake_resolve(base, t, false);
    cc_dxt_add(std::move(t));
    return;
  }
  g_tex_alloc_keep = t.data;
  t.cache = cc_tex_rasterize(ctx, base, obj, t.w, t.h, t.hash);
#ifndef CC_XBOX_DRIVER
  cc_bake_record(base, t.job.data(), obj, t.cache, t.w, t.h);
#endif
  t.hashed = t.cache != 0;
  base.memory.store_be(obj + 564u, 4, t.data);
  t.last_use = g_frame_delay_calls;
  if (t.cache) cc_dxt_add(std::move(t));
  cc_tex_cache_trim(base, key);
}
#include "generated/sub_8208F930.inc"
#include "generated/sub_82091AC0.inc"
#include "generated/sub_82091C88.inc"
#include "generated/sub_8208FE50.inc"
#include "generated/sub_820921C8.inc"
#include "generated/sub_82092B78.inc"
#include "generated/sub_82086010.inc"
#include "generated/sub_8206FDB8.inc"
#include "generated/sub_82070F68.inc"
#include "generated/sub_82075400.inc"
#include "generated/sub_820753F8.inc"
#include "generated/sub_82094040.inc"
#ifdef CC_FAST
#define sub_82066EA8 sub_82066EA8_exact
#endif
#include "generated/sub_82066EA8.inc"
#ifdef CC_FAST
#undef sub_82066EA8
// Reference count step (exact sub_82066EA8: object r3, up r4 byte): for an
// object whose type (slot 40) has any of the bits 0x7C6C1, the u16 at +24
// is incremented (up) or decremented and 1 is returned; else 0.
static CC_HOT_FN void sub_82066EA8(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  static const bool walk_exact = std::getenv("CC_WALK_EXACT") != nullptr;  // host A/B switch
  if (walk_exact) { sub_82066EA8_exact(ctx, base); return; }
#else
  #ifdef CC_WALK_EXACT_BUILD
  sub_82066EA8_exact(ctx, base); return;  // Xbox bisect build
#endif
  static_cast<void>(&sub_82066EA8_exact);
#endif
  const uint32_t obj = ctx.r3.u32;
  const bool up = (ctx.r4.u32 & 0xFFu) != 0u;
  CcFrame frame(ctx, base, 112u);
  const uint32_t t = cc_vcall(ctx, base, obj, 40u, 0x82066ED4u);
  if ((t & 0x7C6C1u) == 0u) { ctx.r3.u64 = 0u; return; }
  const uint32_t v = REX_LOAD_U16(obj + 24u);
  REX_STORE_U16(obj + 24u, uint16_t(up ? v + 1u : v + 0xFFFFu));
  ctx.r3.u64 = 1u;
}
#endif
#include "generated/sub_820B6190.inc"
#include "generated/sub_820B0D80.inc"
#include "generated/sub_820B1CA8.inc"
#include "generated/sub_820B1D80.inc"
#include "generated/sub_820B1AE8.inc"
#include "generated/sub_820B1FB0.inc"
#include "generated/sub_820B5788.inc"
#include "generated/sub_820B1A08.inc"
#include "generated/sub_820B5698.inc"
#include "generated/sub_820B1618.inc"
#include "generated/sub_820B4370.inc"
#include "generated/sub_820B4AC8.inc"
#include "generated/sub_820B4B20.inc"
#include "generated/sub_820B4580.inc"
#include "generated/sub_820B4BA8.inc"
#include "generated/sub_820B46A8.inc"
#include "generated/sub_820B54E8.inc"
#include "generated/sub_820B4DC8.inc"
#include "generated/sub_820B42C0.inc"
#include "generated/sub_820B3AE8.inc"
#include "generated/sub_820B4498.inc"
#include "generated/sub_820B3E08.inc"
#include "generated/sub_820B4920.inc"
#include "generated/sub_820B3710.inc"
#include "generated/sub_820B31D0.inc"
#include "generated/sub_820B1960.inc"
#include "generated/sub_820B1838.inc"
#include "generated/sub_82130408.inc"
#include "generated/sub_8212A2E0.inc"
#include "generated/sub_8212F288.inc"
#include "generated/sub_8212C3E0.inc"
#include "generated/sub_821303E0.inc"
#include "generated/sub_8212C288.inc"
#include "generated/sub_8212EC40.inc"
#include "generated/sub_821303F8.inc"
#include "generated/sub_8212F208.inc"
#include "generated/sub_8212A340.inc"
#include "generated/sub_8212A280.inc"
#include "generated/sub_820B7810.inc"
#include "generated/sub_8212A630.inc"
#include "generated/sub_820B0750.inc"
#include "generated/sub_820B0330.inc"
#include "generated/sub_820A7400.inc"
#include "generated/sub_820AFF40.inc"
#include "generated/sub_820B06C0.inc"
#include "generated/sub_820B00D8.inc"
#include "generated/sub_82128A60.inc"
#include "generated/sub_821287B0.inc"
#include "generated/sub_820C74D0.inc"
#include "generated/sub_820A75E0.inc"
#include "generated/sub_820A7DE0.inc"
#include "generated/sub_820A7E30.inc"
#include "generated/sub_820A8650.inc"
#include "generated/sub_820A86D0.inc"
#include "generated/sub_820A8750.inc"
#include "generated/sub_820A8810.inc"
#include "generated/sub_820A8840.inc"
#include "generated/sub_820A7550.inc"
#include "generated/sub_820BECF8.inc"
#include "generated/sub_820BED90.inc"
#include "generated/sub_820BFA70.inc"
#include "generated/sub_820D7D00.inc"
#include "generated/sub_820D7AF0.inc"
#include "generated/sub_820A1718.inc"
#include "generated/sub_820A1720.inc"
#include "generated/sub_820A1940.inc"
#include "generated/sub_8209B9D0.inc"
#include "generated/sub_820B6B80.inc"
#include "generated/sub_8209B830.inc"
#ifdef CC_FAST
#define sub_820798D8 sub_820798D8_exact
#endif
#include "generated/sub_820798D8.inc"
#ifdef CC_FAST
#undef sub_820798D8
// Rotating-buffer sprintf (exact sub_820798D8: format r3, arguments from
// r4): the CRT's vsprintf (sub_821280E8 -> _output sub_8212C6F0) into the
// next of four 512-byte buffers at 0x82290288, picked by the signed index
// byte at 0x82290A88 (read again afterwards, then advanced mod 4); returns
// that buffer. The formats "%d" (the low word of r4 as int) and "%s" (the
// string at r4, copied up to its zero byte) are written here; any other
// format, and "%s" of a null pointer, run the original. The two outer
// stack frames are left as the original leaves them (return addresses,
// saved r30/r31, the argument save area, back chains, the string FILE
// block); _output's own frame is not reproduced.
// Switches: CC_FORMAT_EXACT=1 (host) / CC_FORMAT_EXACT_BUILD (Xbox) run
// the original; CC_ORACLE=1 or CC_FORMAT_ORACLE=1 run it after the native
// text is made and compare buffer, length and result.
static CC_HOT_FN void sub_820798D8(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  static const bool exact = std::getenv("CC_FORMAT_EXACT") != nullptr;
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr || std::getenv("CC_FORMAT_ORACLE") != nullptr;
#elif defined(CC_FORMAT_EXACT_BUILD)
  constexpr bool exact = true;
#else
  constexpr bool exact = false;
#endif
  const uint32_t fmt = ctx.r3.u32;
  const uint32_t c1 = REX_LOAD_U8(fmt + 1u);
  if (exact || REX_LOAD_U8(fmt) != 0x25u || (c1 != 0x64u && c1 != 0x73u) || REX_LOAD_U8(fmt + 2u) != 0u ||
      (c1 == 0x73u && ctx.r4.u32 == 0u)) {
    sub_820798D8_exact(ctx, base);
    return;
  }
  // The text: digits of the int, or the string's length (copied below).
  char num[12];
  uint32_t len = 0u;
  if (c1 == 0x64u) {
    const int32_t v = int32_t(ctx.r4.u32);
    uint32_t u = v < 0 ? 0u - uint32_t(v) : uint32_t(v);
    char tmp[10];
    uint32_t n = 0u;
    do { tmp[n++] = char(0x30u + u % 10u); u /= 10u; } while (u != 0u);
    if (v < 0) num[len++] = 0x2D;
    while (n != 0u) num[len++] = tmp[--n];
  } else {
    while (REX_LOAD_U8(ctx.r4.u32 + len) != 0u) ++len;
  }
#ifndef CC_XBOX_DRIVER
  std::vector<uint8_t> want;
  if (oracle) {
    want.resize(len);
    for (uint32_t i = 0; i < len; ++i) want[i] = c1 == 0x64u ? uint8_t(num[i]) : REX_LOAD_U8(ctx.r4.u32 + i);
    const uint32_t buf0 = (uint32_t(int32_t(int8_t(REX_LOAD_U8(0x82290A88u)))) << 9) + 0x82290288u;
    sub_820798D8_exact(ctx, base);
    if (ctx.r3.u32 != buf0) cc_oracle_mismatch("sub_820798D8 buffer", 0, ctx.r3.u32, buf0);
    for (uint32_t i = 0; i <= len; ++i) {
      const uint32_t got = REX_LOAD_U8(buf0 + i), w = i < len ? want[i] : 0u;
      if (got != w) { cc_oracle_mismatch("sub_820798D8 text", int(i), got, w); break; }
    }
    return;
  }
#endif
  // Stack as the original leaves it: its frame F0 = r1 - 112 below the
  // saved return address, r30, r31 and the argument save area, the
  // va_list at F0 + 80; vsprintf's frame F1 = F0 - 128 with its return
  // address, saved r31 and the FILE block {ptr, count, base, flags 66} at
  // F1 + 80 as _output leaves it.
  const uint32_t r1 = ctx.r1.u32, f0 = r1 - 112u, f1 = f0 - 128u;
  REX_STORE_U32(r1 - 8u, uint32_t(ctx.lr));
  REX_STORE_U64(r1 - 24u, ctx.r30.u64);
  REX_STORE_U64(r1 - 16u, ctx.r31.u64);
  REX_STORE_U64(r1 + 24u, ctx.r4.u64); REX_STORE_U64(r1 + 32u, ctx.r5.u64);
  REX_STORE_U64(r1 + 40u, ctx.r6.u64); REX_STORE_U64(r1 + 48u, ctx.r7.u64);
  REX_STORE_U64(r1 + 56u, ctx.r8.u64); REX_STORE_U64(r1 + 64u, ctx.r9.u64);
  REX_STORE_U64(r1 + 72u, ctx.r10.u64);
  REX_STORE_U32(f0, r1);
  REX_STORE_U32(f0 + 80u, r1 + 24u);
  const uint32_t idx = uint32_t(int32_t(int8_t(REX_LOAD_U8(0x82290A88u))));
  const uint32_t buf = (idx << 9) + 0x82290288u;
  REX_STORE_U32(f0 - 8u, 0x8207993Cu);
  REX_STORE_U64(f0 - 16u, ctx.r31.u64);
  REX_STORE_U32(f1, f0);
  // The text, byte by byte in order (a source inside the buffers reads as
  // the original's copy does), then the zero byte.
  if (c1 == 0x64u) {
    for (uint32_t i = 0; i < len; ++i) REX_STORE_U8(buf + i, uint8_t(num[i]));
  } else {
    const uint32_t src = ctx.r4.u32;
    for (uint32_t i = 0; i < len; ++i) REX_STORE_U8(buf + i, REX_LOAD_U8(src + i));
  }
  REX_STORE_U8(buf + len, 0u);
  REX_STORE_U32(f1 + 80u, buf + len);
  REX_STORE_U32(f1 + 84u, 0x7FFFFFFFu - len - 1u);
  REX_STORE_U32(f1 + 88u, buf);
  REX_STORE_U32(f1 + 92u, 66u);
  const int32_t now = int32_t(int8_t(REX_LOAD_U8(0x82290A88u)));
  REX_STORE_U8(0x82290A88u, uint8_t((now + 1) & 3));
  ctx.r3.u64 = uint32_t(uint32_t(now) << 9) + 0x82290288u;
}
#endif
#include "generated/sub_820B6B90.inc"
#include "generated/sub_8209BA50.inc"
#include "generated/sub_821280E8.inc"
#include "generated/sub_8209B8D8.inc"
#include "generated/sub_82128030.inc"
#include "generated/sub_8212C6F0.inc"
#include "generated/sub_8212C3F0.inc"
#include "generated/sub_8212BF08.inc"
#include "generated/sub_82132B08.inc"
#include "generated/sub_8212C5C0.inc"
#include "generated/sub_8212E910.inc"
#include "generated/sub_821329B8.inc"
#include "generated/sub_82132B00.inc"
#include "generated/sub_8212C658.inc"
#include "generated/sub_821329A8.inc"
#include "generated/sub_8212EEF0.inc"
#include "generated/sub_821326A0.inc"
#include "generated/sub_82132830.inc"
#include "generated/sub_821329E0.inc"
#include "generated/sub_821328B8.inc"
#include "generated/sub_821348A8.inc"
#include "generated/sub_8212F044.inc"
#include "generated/sub_8212EC98.inc"
#include "generated/sub_82129518.inc"
#include "generated/sub_821325D0.inc"
#include "generated/sub_821327F8.inc"
#include "generated/sub_82130438.inc"
#include "generated/sub_8212F458.inc"
#include "generated/sub_82134968.inc"
#include "generated/sub_821349A0.inc"
#include "generated/sub_82129550.inc"
#include "generated/sub_82136AA8.inc"
#include "generated/sub_821347D8.inc"
#include "generated/sub_8212F318.inc"
#include "generated/sub_8212F2F8.inc"
#include "generated/sub_8212F428.inc"
#include "generated/sub_820A7480.inc"
#include "generated/sub_820DBF00.inc"
#include "generated/sub_820DCAF8.inc"
#include "generated/sub_820E2D18.inc"
#include "generated/sub_820E2D70.inc"
#include "generated/sub_820E2F50.inc"
#include "generated/sub_820E2960.inc"
#include "generated/sub_820E3FD8.inc"
#include "generated/sub_820E46A0.inc"
#include "generated/sub_820E2B40.inc"
#include "generated/sub_820E2838.inc"
#include "generated/sub_820E0770.inc"
#include "generated/sub_820E0790.inc"
#include "generated/sub_820E07F8.inc"
#include "generated/sub_820E0960.inc"
#include "generated/sub_820E0988.inc"
#include "generated/sub_820E0998.inc"
#include "generated/sub_820E09A0.inc"
#include "generated/sub_820E0B70.inc"
#include "generated/sub_820E0C70.inc"
#include "generated/sub_820E0D00.inc"
#include "generated/sub_820E0D08.inc"
#include "generated/sub_820E15E0.inc"
#include "generated/sub_820EAAA8.inc"
#include "generated/sub_820E26D0.inc"
#include "generated/sub_820E15E8.inc"
#include "generated/sub_820DBEE0.inc"
#include "generated/sub_820DBEF0.inc"
#include "generated/sub_820DCAE8.inc"
#include "generated/sub_820E0978.inc"
#include "generated/sub_820E2820.inc"
#include "generated/sub_820E2A50.inc"
#include "generated/sub_820E2BC0.inc"
#include "generated/sub_820E4310.inc"
#include "generated/sub_820E43D8.inc"
#include "generated/sub_820E2A60.inc"
#include "generated/sub_820E48C8.inc"
#include "generated/sub_820E41A8.inc"
#include "generated/sub_820D8C70.inc"

#include "generated/sub_820E32D0.inc"
#include "generated/sub_820E0388.inc"
#include "generated/sub_820E3148.inc"
#include "generated/sub_820E3160.inc"
#include "generated/sub_820E32E8.inc"
#include "generated/sub_820E32F8.inc"
#include "generated/sub_820E8D30.inc"
#include "generated/sub_820E0A00.inc"
#include "generated/sub_820D8A48.inc"
#include "generated/sub_820516F0.inc"
#include "generated/sub_820E3300.inc"
#include "generated/sub_820D8DF8.inc"
#include "generated/sub_820E2808.inc"
#include "generated/sub_820DB2B8.inc"
#include "generated/sub_820D8E50.inc"
#include "generated/sub_820D8A68.inc"
#include "generated/sub_820D9D18.inc"
#include "generated/sub_820E33D0.inc"
#include "generated/sub_820E3448.inc"
#include "generated/sub_820DC858.inc"
#include "generated/sub_820D94F8.inc"
#include "generated/sub_820E3248.inc"
#include "generated/sub_820E1FD0.inc"
#include "generated/sub_820B6020.inc"
#include "generated/sub_820DB258.inc"
#include "generated/sub_820D9470.inc"
#include "generated/sub_820B7448.inc"
#include "generated/sub_820B7428.inc"

#include "generated/sub_8213ACB0.inc"
#include "generated/sub_8213AEE0.inc"
#include "generated/sub_820D84A8.inc"
#include "generated/sub_820D8580.inc"
#include "generated/sub_820B73D0.inc"
#include "generated/sub_820B5F50.inc"
#include "generated/sub_820756E0.inc"
#include "generated/sub_82096828.inc"
// WIP 022: fail-closed XAM/Live kernel imports referenced by the family
// below; each is bound to its observed shape only when the diagnostic
// actually reaches it.

static void __imp__XamLoaderTerminateTitle([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A404u); }
static void __imp__HalReturnToFirmware([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A694u); }
static void __imp__KeLockL2([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A964u); }
static void __imp__KeReleaseSemaphore([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214ABE4u); }
static void __imp__KeResetEvent([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A984u); }
static void __imp__KeUnlockL2([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A974u); }
static void __imp__KeWaitForMultipleObjects([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AC14u); }
static void __imp__KeWaitForSingleObject([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A994u); }
static void __imp__NetDll_WSAGetOverlappedResult([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB54u); }
static void __imp__NetDll_WSARecvFrom([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB74u); }
static void __imp__NetDll_ioctlsocket([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB14u); }
// NtClose(handle r3) called directly (the indirect form is the dispatch
// case): an open game file handle is closed; the main menu's Quit path
// closes other handles (events) on its way out, which the play build
// accepts; the verification build stays fail-closed for those.
static void __imp__NtClose(Context& ctx, Machine& base) {
  if (auto* f = base.find_file(ctx.r3.u32)) {
    if (f->fp) { std::fclose(f->fp); f->fp = nullptr; }
    f->open = false; f->handle = 0; f->pos = 0; f->size = 0;
    ctx.r3.u64 = 0u;  // STATUS_SUCCESS
    return;
  }
#ifdef CC_FAST
  ctx.r3.u64 = 0u;
#else
  base.fail(Error::unsupported, 0x8214A584u);
#endif
}
static void __imp__NtFlushBuffersFile([[maybe_unused]] Context& ctx, Machine& base) {
#ifdef CC_FAST
  if (ctx.r4.u32) { base.store(ctx.r4.u32, 4, 0u); base.store(ctx.r4.u32 + 4u, 4, 0u); }
  ctx.r3.u64 = 0u;  // nothing buffered
#else
  base.fail(Error::unsupported, 0x8214A564u);
#endif
}
static void __imp__NtOpenFile([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A524u); }
static void __imp__NtQueryInformationFile([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A624u); }
static void __imp__NtQueryVolumeInformationFile([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A634u); }
static void __imp__NtSetInformationFile([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A5F4u); }
static void __imp__RtlCaptureContext([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AD04u); }
static void __imp__RtlTryEnterCriticalSection([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214ABB4u); }
static void __imp__RtlUnwind([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214ACF4u); }
static void __imp__VdShutdownEngines([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A854u); }
static void __imp__XAudioGetVoiceCategoryVolume([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214ABF4u); }
static void __imp__XAudioGetVoiceCategoryVolumeChangeMask([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AC04u); }
static void __imp__XGetAVPack([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A3F4u); }
static void __imp__XGetLanguage([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A3E4u); }
static void __imp__XamSessionCreateHandle([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AD84u); }
static void __imp__XamShowAchievementsUI([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A2F4u); }
static void __imp__XamShowFriendsUI([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A2D4u); }
static void __imp__XamShowMessageBoxUIEx([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A3D4u); }
static void __imp__XamVoiceCreate([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214ADC4u); }
static void __imp__XexCheckExecutablePrivilege([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A594u); }
static void __imp__RtlFreeAnsiString([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AD44u); }
static void __imp__RtlInitUnicodeString([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AD64u); }
static void __imp__RtlUnicodeStringToAnsiString([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AD54u); }
static void __imp__NetDll_XNetConnect([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA14u); }
static void __imp__NetDll_XNetGetTitleXnAddr([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA64u); }
static void __imp__NetDll_XNetInAddrToXnAddr([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A9F4u); }
static void __imp__NetDll_XNetQosLookup([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA44u); }
static void __imp__NetDll_XNetXnAddrToInAddr([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A9E4u); }
static void __imp__NetDll_bind([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB34u); }
static void __imp__NetDll_recvfrom([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB64u); }
static void __imp__NetDll_select([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB44u); }
static void __imp__NetDll_setsockopt([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB24u); }
static void __imp__NetDll_socket([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AAF4u); }
static void __imp__RtlMultiByteToUnicodeN([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AD34u); }
static void __imp__ExTerminateThread([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A6A4u); }
// Kernel timers (the system notification thread's 10 ms poll timer):
// handles 0x07100001... Waiting on a timer is a block point (a started
// thread stops there; on the main thread it fails closed), so no timer ever
// needs to fire in this diagnostic.
static uint32_t g_timer_count = 0;
static void __imp__NtCancelTimer(Context& ctx, Machine& base) {
  if (ctx.r3.u32 < 0x07100001u || ctx.r3.u32 >= 0x07100001u + g_timer_count)
    base.fail(Error::unsupported, 0x8214ADD4u);
  if (ctx.r4.u32) base.store(ctx.r4.u32, 4, 0u);  // previous state: not signalled
  ctx.r3.u64 = 0u;
}
static void __imp__NtCreateTimer(Context& ctx, Machine& base) {
  if (!ctx.r3.u32 || ctx.r5.u32 > 1u || g_timer_count >= 16u)
    base.fail(Error::unsupported, 0x8214AE04u);
  base.store(ctx.r3.u32, 4, 0x07100001u + g_timer_count++);
  ctx.r3.u64 = 0u;
}
static void __imp__NtSetTimerEx(Context& ctx, Machine& base) {
  if (ctx.r3.u32 < 0x07100001u || ctx.r3.u32 >= 0x07100001u + g_timer_count || !ctx.r4.u32)
    base.fail(Error::unsupported, 0x8214ADF4u);
  ctx.r3.u64 = 0u;  // armed; see NtCancelTimer note
}
// PORT POLICY: voice chat belongs to the stubbed Xbox Live layer. No
// headset is ever present, so the voice engine never captures or submits.
static void __imp__XamVoiceHeadsetPresent(Context& ctx, [[maybe_unused]] Machine& base) {
  ctx.r3.u64 = 0u;
}
static void __imp__XamVoiceSubmitPacket([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214ADB4u); }
// WIP 023: trusted xboxkrnl RtlTimeToTimeFields contract - split a 64-bit
// FILETIME (100 ns since 1601) into the eight big-endian u16 TIME_FIELDS
// (year, month, day, hour, minute, second, millisecond, weekday).
static void __imp__RtlTimeToTimeFields(Context& ctx, Machine& base) {
  if (!ctx.r3.u32 || !ctx.r4.u32) base.fail(Error::unsupported, 0x8214A4D4u);
  const uint64_t t = base.load(ctx.r3.u32, 8);
  const uint64_t ms_total = t / 10000ull;
  const uint32_t msec = uint32_t(ms_total % 1000ull);
  uint64_t secs = ms_total / 1000ull;
  const uint32_t sec = uint32_t(secs % 60ull); secs /= 60ull;
  const uint32_t min = uint32_t(secs % 60ull); secs /= 60ull;
  const uint32_t hour = uint32_t(secs % 24ull);
  uint64_t days = secs / 24ull;
  const uint32_t weekday = uint32_t((days + 1ull) % 7ull);  // 1601-01-01 was a Monday
  uint32_t year = 1601;
  for (;;) {
    const bool leap = (year%4==0 && year%100!=0) || year%400==0;
    const uint32_t ydays = leap ? 366u : 365u;
    if (days < ydays) break;
    days -= ydays; ++year;
  }
  static const uint32_t mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  const bool leap = (year%4==0 && year%100!=0) || year%400==0;
  uint32_t month = 1;
  for (; month <= 12u; ++month) {
    uint32_t md = mdays[month-1] + ((month==2u && leap) ? 1u : 0u);
    if (days < md) break;
    days -= md;
  }
  const uint32_t out = ctx.r4.u32;
  base.store(out+0,2,year); base.store(out+2,2,month);
  base.store(out+4,2,uint32_t(days)+1u); base.store(out+6,2,hour);
  base.store(out+8,2,min); base.store(out+10,2,sec);
  base.store(out+12,2,msec); base.store(out+14,2,weekday);
}
// WIP 023: the title/attract screen queries wall-clock time (exact wrapper
// sub_820B6070, lr=0x820B608C). The fixture derives a deterministic
// FILETIME from the same virtual timebase every other clock uses: a fixed
// epoch plus the elapsed guest ticks converted to 100 ns units, so host
// and Xbox measurements stay identical.
static void __imp__KeQuerySystemTime(Context& ctx, Machine& base) {
  if (ctx.r3.u32 == 0u) base.fail(Error::unsupported, 0x8214A4E4u);
  const uint64_t ticks = base.timebase_virtual_ticks;
  const uint64_t filetime = 0x01C9000000000000ull + (ticks * 80ull) / 399ull;
  base.store(ctx.r3.u32, 8, filetime);
}
static void __imp__RtlTimeFieldsToTime([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A734u); }
static void __imp__RtlUnicodeToMultiByteN([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A604u); }
static void __imp__XamShowGamerCardUIForXUID([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A2E4u); }
static void __imp__XamShowMarketplaceUI([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A304u); }
// PORT POLICY (nobody signs in): every controller slot reports "not
// signed in" (ERROR_NOT_LOGGED_ON 0x4DD) with an empty name / zero XUID,
// exactly as a real console answers for an empty slot.
static bool cc_four_players();
static void __imp__XamUserGetName(Context& ctx, Machine& base) {
  if (ctx.r4.u32 == 0u && ctx.r5.u32 != 0u)
    base.fail(Error::unsupported, 0x8214A234u);
  if (ctx.r4.u32 && ctx.r5.u32) base.store(ctx.r4.u32, 1, 0u);
  // An index past the four slots (the world map after level 3 asks for
  // 0xFFFFFFFF in a four-player game) is no signed-in user either.
  if (ctx.r3.u32 > 3u) { ctx.r3.u64 = 0x4DDu; return; }
  if (cc_four_players() && ctx.r3.u32 >= 1u && ctx.r3.u32 <= 3u && ctx.r4.u32 && ctx.r5.u32 >= 9u) {
    const char name[] = "Player ";
    for (uint32_t k = 0; k < 7u; ++k) base.store(ctx.r4.u32 + k, 1, uint8_t(name[k]));
    base.store(ctx.r4.u32 + 7, 1, uint8_t('1' + ctx.r3.u32));
    base.store(ctx.r4.u32 + 8, 1, 0u);
    ctx.r3.u64 = 0u;
    return;
  }
  ctx.r3.u64 = 0x4DDu;
}
// NtWriteFile(handle r3, event r4, apc r5, ctx r6, iosb r7, buffer r8, length
// r9, offset r10). The port opens no writable files; the play build reports
// an invalid handle so the game's own error path runs (saves are TODO).
static void __imp__NtWriteFile([[maybe_unused]] Context& ctx, Machine& base) {
#ifdef CC_FAST
  if (ctx.r7.u32) { base.store(ctx.r7.u32, 4, 0xC0000008u); base.store(ctx.r7.u32 + 4u, 4, 0u); }
  ctx.r3.u64 = 0xC0000008u;  // STATUS_INVALID_HANDLE
#else
  base.fail(Error::unsupported, 0x8214AD14u);
#endif
}
// WIP 023 input fixture: exactly one standard gamepad on port 0, idle
// (no buttons, centered sticks, released triggers). Ports 1-3 report
// ERROR_DEVICE_NOT_CONNECTED (0x48F), matching a console with one pad.
// The original-Xbox driver maps real pads through this same boundary.
static uint32_t g_input_packet_number = 0;
// Four-player diagnostic (Xbox: make FOURP=1, host: CC_4P=1): ports 1-3 are
// connected too and follow their own scripts - join at character select,
// pick a knight - and from the first fight on all four players walk and
// attack in a loop, so a run measures combat with four players on screen.
static bool cc_four_players() {
#if defined(CC_SCRIPT_4P)
  return true;
#elif !defined(CC_XBOX_DRIVER)
  static const bool on = std::getenv("CC_4P") != nullptr;
  return on;
#else
  return false;
#endif
}
// Combat loop for player `user` (0-3) from frame `start`: walk, light
// attacks, walk back, heavy and light attacks; offsets keep the players apart.
static void cc_combat_loop(uint32_t user, uint32_t frame, uint32_t start, uint32_t& buttons, uint32_t& thumbs) {
  if (frame < start) return;
#if defined(CC_XBOX_DRIVER) && defined(CC_FAST) && !defined(CC_BENCH) && !defined(CC_GAME_STEP)
  // The play build steps the game by the real frame (1/30 s), twice the
  // game time per frame of the host harness the loop was tuned on (1/60 s);
  // each action is held for twice as many frames, so the fight plays out
  // the same in game time instead of marching through the level at double
  // pace.
  frame = start + (frame - start) / 2u;
#endif
  // Net movement is to the right (the camera only scrolls when the whole
  // party moves on, and the enemies are ahead), attacking all the way.
  const uint32_t t = (frame - start + user * 23u) % 400u;
  const uint32_t cycle = (frame - start + user * 23u) / 400u;
  int16_t lx = 0, ly = 0;
  // Zigzag up and down while walking so nobody stays stuck behind a table.
  const int16_t lane = int16_t(((cycle + user) & 1u) ? 17000 : -17000);
  if (t < 150u) { lx = 26000; ly = t < 60u ? lane : int16_t(0); }                     // walk right (zigzag, then level)
  else if (t < 210u) { if ((t % 14u) < 4u) buttons |= 0x4000u; }                     // X combo
  else if (t < 230u) { lx = -14000; ly = int16_t(-lane); }                           // step back
  else if (t < 290u) { if ((t % 28u) < 5u) buttons |= 0x8000u;                       // Y heavy
                       else if ((t % 28u) >= 14u && (t % 28u) < 18u) buttons |= 0x4000u; }
  else if (t < 380u) { lx = 26000; if (t >= 320u + user * 2u && t < 324u + user * 2u) buttons |= 0x1000u; }  // walk right, jump
  else { if ((t % 8u) < 3u) buttons |= 0x4000u; }
  if (lx || ly) thumbs = (uint32_t(uint16_t(lx)) << 16) | uint16_t(ly);
}
// Scripted pads 1-3: A to join at character select (on screen from about
// frame 5200 until player 1's START at 6000), A again to take a knight.
static void cc_extra_pad(uint32_t user, uint32_t frame, uint32_t& buttons, uint32_t& thumbs) {
  uint32_t join = 5640u + user * 40u, pick = 5800u + user * 40u, hold = 12u;
#ifndef CC_XBOX_DRIVER
  if (const char* e = std::getenv("CC_4P_JOIN")) join = uint32_t(std::strtoul(e, nullptr, 10)) + user * 40u;
  if (const char* e = std::getenv("CC_4P_PICK")) pick = uint32_t(std::strtoul(e, nullptr, 10)) + user * 40u;
#endif
  if (frame >= join && frame < join + hold) buttons |= 0x1000u;
  if (frame >= pick && frame < pick + hold) buttons |= 0x1000u;
  cc_combat_loop(user, frame, cc_direct_level() ? 6500u : 9400u, buttons, thumbs);
}
static void __imp__XamInputGetCapabilities(Context& ctx, Machine& base) {
  const uint32_t user = ctx.r3.u32, caps = ctx.r5.u32;
  if (user != 0u && !(user <= 3u && cc_four_players())) { ctx.r3.u64 = 0x48Fu; return; }
  base.store(caps + 0, 1, 0x01u);      // Type    = XINPUT_DEVTYPE_GAMEPAD
  base.store(caps + 1, 1, 0x01u);      // SubType = XINPUT_DEVSUBTYPE_GAMEPAD
  base.store(caps + 2, 2, 0u);         // Flags
  base.store(caps + 4, 2, 0xF3FFu);    // Gamepad.wButtons supported mask
  base.store(caps + 6, 1, 0xFFu);      // Gamepad.bLeftTrigger range
  base.store(caps + 7, 1, 0xFFu);      // Gamepad.bRightTrigger range
  base.store(caps + 8, 2, 0xFFC0u);    // Gamepad.sThumbLX resolution
  base.store(caps + 10, 2, 0xFFC0u);   // Gamepad.sThumbLY
  base.store(caps + 12, 2, 0xFFC0u);   // Gamepad.sThumbRX
  base.store(caps + 14, 2, 0xFFC0u);   // Gamepad.sThumbRY
  base.store(caps + 16, 2, 0xFFu);     // Vibration.wLeftMotorSpeed range
  base.store(caps + 18, 2, 0xFFu);     // Vibration.wRightMotorSpeed range
  ctx.r3.u64 = 0u;                     // ERROR_SUCCESS
}
static void __imp__XamInputGetState(Context& ctx, Machine& base) {
  const uint32_t user = ctx.r3.u32, state = ctx.r5.u32;
  if (user != 0u) {
    if (!(user <= 3u && cc_four_players())) { ctx.r3.u64 = 0x48Fu; return; }
    static uint32_t packets[4];
#ifndef CC_XBOX_DRIVER
    if (std::getenv("CC_4P_LOG") && (packets[user] < 3u || (g_frame_delay_calls >= 5300u && g_frame_delay_calls < 5320u)))
      cc_log("pad%u frame=%u lr=%08x flags=%08x\n", user, g_frame_delay_calls, uint32_t(ctx.lr), ctx.r4.u32);
#endif
    uint32_t b = 0u, th = 0u;
    cc_extra_pad(user, g_frame_delay_calls, b, th);
    base.store(state + 0, 4, ++packets[user]);
    base.store(state + 4, 4, b << 16);
    base.store(state + 8, 4, th);
    base.store(state + 12, 4, 0u);
    ctx.r3.u64 = 0u;
    return;
  }
  ++g_input_packet_number;
  // WIP 023 labeled diagnostic input script, keyed to the frame counter
  // (g_frame_delay_calls). This is injected input for the diagnostic, never faked game state; the
  // original code reads it through the same boundary a real pad would use.
  // Script rows: first/last frame (inclusive), buttons, left stick X/Y.
  // Boot -> title (START) -> menu (A) -> story book (A) -> Live notice (A;
  // dropped where the play build skips the notice) -> character select -> level: walk right,
  // four light attacks (X), jump (A), walk down-left, heavy attack (Y),
  // walk up-right, three light attacks, walk right to the next room.
  struct InputRow { uint32_t first, last, buttons; int16_t lx, ly; };
  static constexpr InputRow k_script[] = {
    {300,311,0x0010,0,0},{1200,1211,0x0010,0,0},
#ifdef CC_SCRIPT_QUIT
    // Xbox check of the trimmed menu's Quit: DOWN three times, then A.
    {2800,2805,0x0002,0,0},{2850,2855,0x0002,0,0},{2900,2905,0x0002,0,0},
#endif
    {3000,3011,0x1000,0,0},
    {4000,4011,0x1000,0,0},{4500,4511,0x0002,0,0},{5000,5011,0x1000,0,0},
    {6000,6011,0x0010,0,0},{7000,7011,0x1000,0,0},{7600,7899,0,30000,0},
    {8000,8011,0x1000,0,0},{8100,8104,0x4000,0,0},{8130,8134,0x4000,0,0},
    {8160,8164,0x4000,0,0},{8190,8194,0x4000,0,0},{8300,8305,0x1000,0,0},
    {8400,8699,0,-30000,-20000},{8800,8805,0x8000,0,0},
    {8900,9199,0,30000,20000},{9300,9304,0x4000,0,0},{9330,9334,0x4000,0,0},
    {9360,9364,0x4000,0,0},{9400,9899,0,30000,0},
  };
  uint32_t buttons = 0u;
  uint32_t thumbs = 0u;
  for (const InputRow &row : k_script) {
    if (g_frame_delay_calls < row.first || g_frame_delay_calls > row.last) continue;
    if (cc_direct_level() && row.first >= 6500u) continue;  // level-1 walk-through rows
    // The DOWN and A that landed on the notice (no effect there; on the
    // character select they would change player 1's knight and confirm it).
    if ((row.first == 4500u || row.first == 5000u) && cc_skip_live_notice()) continue;
    buttons |= row.buttons;
    if (row.lx || row.ly)
      thumbs = (uint32_t(uint16_t(row.lx)) << 16) | uint16_t(row.ly);
  }
  if (cc_four_players() || cc_direct_level())
    cc_combat_loop(0u, g_frame_delay_calls, cc_direct_level() ? 6500u : 9900u, buttons, thumbs);
#ifndef CC_XBOX_DRIVER
  // Host diagnostic override: CC_INPUT_SCRIPT="first-last:buttons[:lx,ly];..."
  // (hex buttons, signed decimal stick) replaces the built-in script above.
  if (const char *script = std::getenv("CC_INPUT_SCRIPT")) {
    buttons = 0u;
    thumbs = 0u;
    const char *p = script;
    while (*p) {
      unsigned first = 0, last = 0, b = 0;
      int lx = 0, ly = 0, used = 0;
      if (std::sscanf(p, "%u-%u:%x%n", &first, &last, &b, &used) < 3) break;
      p += used;
      if (*p == ':') {
        int used2 = 0;
        if (std::sscanf(p, ":%d,%d%n", &lx, &ly, &used2) >= 2) p += used2;
      }
      if (g_frame_delay_calls >= first && g_frame_delay_calls <= last) {
        buttons |= b;
        thumbs = (uint32_t(uint16_t(int16_t(lx))) << 16) | uint16_t(int16_t(ly));
      }
      while (*p && *p != ';') ++p;
      if (*p == ';') ++p;
    }
  }
#endif
  {
    static uint32_t last_buttons = 0;
    if (buttons != last_buttons) {
      cc_log("input frame=%u buttons=%04x\n", g_frame_delay_calls, buttons);
      last_buttons = buttons;
    }
  }
  uint32_t triggers = 0u, rthumbs = 0u;
#ifdef CC_XBOX_DRIVER
  // A real pad takes over from the script at its first press (or a stick
  // or trigger pushed well past centre) and keeps control from then on.
  {
    static bool pad_live = false;
    uint32_t pb = 0; int16_t lx = 0, ly = 0, rx = 0, ry = 0; uint8_t lt = 0, rt = 0;
    if (::cc_xbox_pad(&pb, &lx, &ly, &rx, &ry, &lt, &rt)) {
      auto pushed = [](int16_t v) { return v > 16000 || v < -16000; };
      if (pb || pushed(lx) || pushed(ly) || pushed(rx) || pushed(ry) || lt > 64 || rt > 64) pad_live = true;
      if (pad_live) {
        buttons = pb;
        thumbs = (uint32_t(uint16_t(lx)) << 16) | uint16_t(ly);
        rthumbs = (uint32_t(uint16_t(rx)) << 16) | uint16_t(ry);
        triggers = (uint32_t(lt) << 8) | rt;
      }
    }
  }
#endif
  base.store(state + 0, 4, g_input_packet_number); // dwPacketNumber
  base.store(state + 4, 4, buttons << 16 | triggers);  // wButtons | triggers
  base.store(state + 8, 4, thumbs);                // sThumbLX | sThumbLY
  base.store(state + 12, 4, rthumbs);              // sThumbRX | sThumbRY
  ctx.r3.u64 = 0u;                                 // ERROR_SUCCESS
}
static void __imp__XamInputSetState(Context& ctx, [[maybe_unused]] Machine& base) {
  // Rumble on the fixture pad: accepted and ignored.
  ctx.r3.u64 = (ctx.r3.u32 == 0u) ? 0u : 0x48Fu;
}
// WIP 023 observed shape (lr=820FBE24): app 0xFA (XMP system music
// player), message 0x00070009 (get playback state), r5 = out status
// pointer, r6 = 0. The original Xbox has no system music player, so the
// port reports "idle / no user music" (state 0) and success. Any other
// app/message stays fail-closed until observed.
static void __imp__XMsgInProcessCall(Context& ctx, Machine& base) {
  if (ctx.r3.u32 == 0xFAu && ctx.r4.u32 == 0x00070009u &&
      ctx.r5.u32 != 0u && ctx.r6.u32 == 0u) {
    base.store(ctx.r5.u32, 4, 0u);  // XMP state = idle
    ctx.r3.u64 = 0u;                // ERROR_SUCCESS
    return;
  }
  base.fail(Error::unsupported, 0x8214AA84u);
}
// PORT POLICY (user directive 2026-09-27): the original Xbox has no
// profile / sign-in system, so no user is ever signed in. The sign-in
// state reports eXUserSigninState_NotSignedIn for every pad and the notify
// poll never reports a sign-in change. The Xbox 360 sign-in blade behaves
// exactly as on a real console when the player backs out of it: the call
// succeeds and nothing changes. Menu scripts (sub_82071280) request it
// unconditionally; the menu's profile gate (sub_82053C70 wrapper) drops its
// requirement separately.
static void __imp__XamShowSigninUI(Context& ctx, Machine& base) {
  if (ctx.r3.u32 == 0u || ctx.r3.u32 > 4u)
    base.fail(Error::unsupported, 0x8214A2C4u);
  static uint32_t logged = 0;
  if (logged < 8u) {
    ++logged;
    cc_log("signin_ui dismissed panes=%u flags=%08x lr=%08x frame=%u\n",
           ctx.r3.u32, ctx.r4.u32, uint32_t(ctx.lr), g_frame_delay_calls);
  }
  ctx.r3.u64 = 0u;  // ERROR_SUCCESS; the blade closes with nobody signed in
}
static bool cc_four_players();
static void __imp__XamUserGetSigninState(Context& ctx, [[maybe_unused]] Machine& base) {
  // Four-player diagnostic: the game asks extra players to sign in before
  // they can join; pads 1-3 report a local profile so they join directly.
  if (cc_four_players() && ctx.r3.u32 >= 1u && ctx.r3.u32 <= 3u) { ctx.r3.u64 = 1u; return; }
  ctx.r3.u64 = 0u;  // eXUserSigninState_NotSignedIn
}
static void __imp__XNotifyGetNext(Context& ctx, Machine& base) {
  const uint32_t id_out = ctx.r5.u32, param_out = ctx.r6.u32;
  if (ctx.r3.u32 < 0x0F110001u || ctx.r3.u32 >= 0x0F110001u + g_xam_listener_count)
    base.fail(Error::unsupported, 0x8214A204u);  // not a listener we issued
  if (id_out) base.store(id_out, 4, 0u);
  if (param_out) base.store(param_out, 4, 0u);
  ctx.r3.u64 = 0u;  // nothing pending
}
static void __imp__XamAlloc([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AAA4u); }
static void __imp__XamContentClose([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A324u); }
static void __imp__XamContentCreateEx([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A314u); }
static void __imp__XamFree([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA94u); }
// XamLoaderLaunchTitle(path r3, flags r4): every caller is the game's
// XLaunchNewImage with the XLNI_DASH_ARCADE path, which sub_820B6908 maps to
// a null title + flag 0x100 ("back to the dashboard"). The main menu's Quit
// ends here: the Xbox returns to the dashboard; the host stays fail-closed.
static void __imp__XamLoaderLaunchTitle([[maybe_unused]] Context& ctx, Machine& base) {
#ifdef CC_XBOX_DRIVER
  if (ctx.r3.u32 == 0u) ::cc_xbox_return_to_dashboard();
#endif
  base.fail(Error::unsupported, 0x8214A354u);
}
static void __imp__XamUserCreateStatsEnumerator([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A284u); }
static void __imp__NetDll_WSACleanup(Context& ctx, [[maybe_unused]] Machine& base) {
  // Teardown mirror of the accepted title-caller WSAStartup.
  ctx.r3.u64=0u;
}
static void __imp__NetDll_WSAGetLastError([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB94u); }
static void __imp__NetDll_WSASendTo([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB84u); }
static void __imp__NetDll_WSAStartup(Context& ctx, Machine& base) {
  // Title-caller startup succeeds; the WSADATA output is zero-filled and
  // versioned 2.2. Every later socket operation remains fail-closed.
  if (ctx.r3.u32!=1u) base.fail(Error::unsupported, 0x8214AAD4u);
  for (uint32_t i=0;i<0x190u;i+=4u) base.store(ctx.r5.u32+i,4,0u);
  base.store(ctx.r5.u32,2,0x0202u);
  base.store(ctx.r5.u32+2,2,0x0202u);
  ctx.r3.u64=0u;
}
static void __imp__NetDll_XNetCleanup(Context& ctx, [[maybe_unused]] Machine& base) {
  // Teardown mirror of the accepted title-caller XNetStartup.
  ctx.r3.u64=0u;
}
static void __imp__NetDll_XNetGetConnectStatus([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA24u); }
static void __imp__NetDll_XNetGetOpt([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA74u); }
static void __imp__NetDll_XNetQosListen([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA34u); }
static void __imp__NetDll_XNetQosRelease([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA54u); }
// WIP 023: the game seeds its RNG through the exact wrapper sub_820D7EA8
// (NetDll_XNetRandom(1, pb, cb)). The original-Xbox port has no XNet, so
// the fixture fills the buffer with a fixed deterministic byte sequence -"
// keeping every measurement reproducible on host and target -" and returns
// success. Unobserved shapes fail closed.
static void __imp__NetDll_XNetRandom(Context& ctx, Machine& base) {
  const uint32_t pb = ctx.r4.u32, cb = ctx.r5.u32;
  if (ctx.r3.u32 != 1u || pb == 0u || cb == 0u || cb > 0x1000u) {
    cc_elog("XNETRANDOM reject r3=%08x pb=%08x cb=%08x\n",
            ctx.r3.u32, pb, cb);
    base.fail(Error::unsupported, 0x8214A9D4u);
  }
  uint32_t s = 0x43435821u;  // 'CCX!' fixture seed
  for (uint32_t i = 0; i < cb; ++i) {
    s = s * 1664525u + 1013904223u;
    base.store(pb + i, 1, (s >> 24) & 0xFFu);
  }
  ctx.r3.u64 = 0u;
}
static void __imp__NetDll_XNetStartup(Context& ctx, Machine& base) {
  // Title-caller startup succeeds; every later XNet operation remains
  // fail-closed. The parameter block is read-only input.
  if (ctx.r3.u32!=1u) base.fail(Error::unsupported, 0x8214A9B4u);
  ctx.r3.u64=0u;
}
static void __imp__NetDll_XNetUnregisterInAddr([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA04u); }
static void __imp__NetDll_closesocket([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB04u); }
static void __imp__NtDuplicateObject([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A674u); }
static void __imp__XMsgCancelIORequest([[maybe_unused]] Context& ctx, [[maybe_unused]] Machine& base) {
#ifdef CC_FAST
  ctx.r3.u64 = 0u;  // no request is ever pending (XMsgStartIORequest completes at once)
#else
  base.fail(Error::unsupported, 0x8214A3C4u);
#endif
}
// PORT POLICY (Live stubbed at the network layer, nobody signs in): every
// Xbox Live user/session/stats request - app 0xFB, message area 0x000B
// (XUserSetContext, achievements, stats, sessions...) - fails at once with
// HRESULT_FROM_WIN32(ERROR_NOT_LOGGED_ON), exactly as a console answers for
// an empty controller slot. When the caller supplied an XOVERLAPPED it is
// marked complete with the same error. Any other app/message fails closed.
static void __imp__XMsgStartIORequest(Context& ctx, Machine& base) {
  if (ctx.r3.u32 != 0xFBu || (ctx.r4.u32 & 0xFFFF0000u) != 0x000B0000u)
    base.fail(Error::unsupported, 0x8214A224u);
  if (const uint32_t ov = ctx.r5.u32) {
    base.store(ov + 0, 4, 0x4DDu);   // InternalLow: result
    base.store(ov + 4, 4, 0u);       // InternalHigh: bytes
    base.store(ov + 24, 4, 0x4DDu);  // dwExtendedError
  }
  ctx.r3.u64 = 0x800704DDu;
}
// Four-player diagnostic: the local profiles of pads 1-3 have no saved
// content. The enumerator is a handle that XamEnumerate answers with
// "no more items" (synchronously, or as an already-completed overlapped
// request); NtClose accepts it like any other handle in the play build.
static void __imp__XamContentCreateEnumerator(Context& ctx, Machine& base) {
  const uint32_t pcb = ctx.r8.u32, phenum = ctx.r9.u32;
  if (!cc_four_players() || !phenum) base.fail(Error::unsupported, 0x8214A344u);
  if (pcb) base.store(pcb, 4, (ctx.r7.u32 ? ctx.r7.u32 : 1u) * 0x134u);  // XCONTENT_DATA per item
  base.store(phenum, 4, 0x0E000001u);
  ctx.r3.u64 = 0u;
}
// WIP 023 PORT POLICY: no marketplace exists on the original Xbox. The
// menu's DLC gate reads a zero license mask (base game only, synchronous
// success); DLC stays hidden exactly as on an offline retail console.
static void __imp__XamContentGetLicenseMask(Context& ctx, Machine& base) {
  if (ctx.r3.u32 == 0u || ctx.r4.u32 != 0u)
    base.fail(Error::unsupported, 0x8214A334u);
  // The original Xbox port is the full game: every license bit is set
  // (callers test bit 0; clear means the Arcade trial).
  base.store(ctx.r3.u32, 4, 0xFFFFFFFFu);
  ctx.r3.u64 = 0u;  // ERROR_SUCCESS
}
static void __imp__XamEnumerate(Context& ctx, Machine& base) {
  if (!cc_four_players() || (ctx.r3.u32 != 0x0E000001u && ctx.r3.u32 != 0x0E000002u)) base.fail(Error::unsupported, 0x8214A364u);
  if (ctx.r7.u32) base.store(ctx.r7.u32, 4, 0u);
  if (const uint32_t ov = ctx.r8.u32) {   // XOVERLAPPED: completed, no items
    base.store(ov + 0, 4, 0x12u);          // InternalLow = ERROR_NO_MORE_FILES
    base.store(ov + 4, 4, 0u);             // InternalHigh = 0 items
    base.store(ov + 24, 4, 0x12u);         // dwExtendedError
    ctx.r3.u64 = 997u;                     // ERROR_IO_PENDING
    return;
  }
  ctx.r3.u64 = 0x12u;                      // ERROR_NO_MORE_FILES
}
// The XEX execution ID from the disc's own header (media 1DF2F0B2, version
// 0x00000103, title 584108B7), published in the platform-globals page.
static void __imp__XamGetExecutionId(Context& ctx, Machine& base) {
  if (!ctx.r3.u32) base.fail(Error::unsupported, 0x8214A414u);
  constexpr uint32_t id = 0x02500200u;
  base.store(id + 0, 4, 0x1DF2F0B2u);   // MediaID
  base.store(id + 4, 4, 0x00000103u);   // Version
  base.store(id + 8, 4, 0x00000103u);   // BaseVersion
  base.store(id + 12, 4, 0x584108B7u);  // TitleID
  base.store(id + 16, 4, 0u);           // Platform, ExecutableType, DiscNum, DiscsInSet
  base.store(id + 20, 4, 0u);           // SaveGameID
  base.store(ctx.r3.u32, 4, id);
  ctx.r3.u64 = 0u;
}
static void __imp__XamGetSystemVersion(Context& ctx, [[maybe_unused]] Machine& base) {
  // Trusted XAM contract: returns the packed system version. The retained
  // Checkpoint 011 kit's dashboard lineage is 2.0.17559.0; the exact caller
  // only compares major/minor fields.
  ctx.r3.u64 = (2u<<28) | (0u<<24) | (17559u<<8);
}
static void __imp__XamNotifyCreateListener(Context& ctx, Machine& base) {
  // Opaque listener handles 0x0F110001.. for any non-empty area mask (the
  // profile system, the audio driver and the Live layer each create one).
  // No listener is ever signalled: nobody signs in and the console is
  // offline. At most eight; more fails closed.
  if (ctx.r3.u32==0u || ctx.r3.u32>0xFFu || g_xam_listener_count>=8u)
    base.fail(Error::unsupported, 0x8214A3B4u);
  g_xam_listener_created=true;
  ctx.r3.u64=0x0F110001u + g_xam_listener_count++;
}
static void __imp__XamSessionRefObjByHandle([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AD74u); }
static void __imp__XamUserAreUsersFriends([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A254u); }
static void __imp__XamUserCheckPrivilege([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A264u); }
// Four-player diagnostic: the local profiles have no achievements either;
// the enumerator is answered by XamEnumerate with "no more items".
static void __imp__XamUserCreateAchievementEnumerator(Context& ctx, Machine& base) {
  const uint32_t pcb = ctx.r9.u32, phenum = ctx.r10.u32;
  if (!cc_four_players() || !phenum) base.fail(Error::unsupported, 0x8214A2A4u);
  if (pcb) base.store(pcb, 4, (ctx.r8.u32 ? ctx.r8.u32 : 1u) * 0x24u);  // XACHIEVEMENT_DETAILS per item
  base.store(phenum, 4, 0x0E000002u);
  ctx.r3.u64 = 0u;
}
// Four-player diagnostic: pads 1-3 report a local (offline) profile named
// "Player 2".."Player 4" with an offline XUID; everyone else stays signed out.
static bool cc_local_profile(uint32_t user) { return cc_four_players() && user >= 1u && user <= 3u; }
static void __imp__XamUserGetSigninInfo(Context& ctx, Machine& base) {
  // XUSER_SIGNIN_INFO: xuid u64, dwInfoFlags, UserSigninState, dwGuestNumber,
  // dwSponsorUserIndex, szUserName[16] (40 bytes).
  const uint32_t user = ctx.r3.u32, info = ctx.r5.u32;
  if (user > 3u || !info) base.fail(Error::unsupported, 0x8214A3A4u);
  for (uint32_t k = 0; k < 40u; k += 4u) base.store(info + k, 4, 0u);
  if (!cc_local_profile(user)) { ctx.r3.u64 = 0x525u; return; }  // ERROR_NO_SUCH_USER
  base.store(info + 0, 8, 0xE000000000000000ull | (user + 1u));
  base.store(info + 12, 4, 1u);                                    // signed in locally
  const char name[] = "Player ";
  for (uint32_t k = 0; k < 7u; ++k) base.store(info + 24 + k, 1, uint8_t(name[k]));
  base.store(info + 31, 1, uint8_t('1' + user));
  ctx.r3.u64 = 0u;
}
static void __imp__XamUserGetXUID(Context& ctx, Machine& base) {
  if (ctx.r3.u32 > 3u) base.fail(Error::unsupported, 0x8214A2B4u);
  if (ctx.r5.u32) base.store(ctx.r5.u32, 8, 0u);
  if (cc_four_players() && ctx.r3.u32 >= 1u && ctx.r3.u32 <= 3u) {
    if (ctx.r5.u32) base.store(ctx.r5.u32, 8, 0xE000000000000000ull | (ctx.r3.u32 + 1u));
    ctx.r3.u64 = 0u;
    return;
  }
  ctx.r3.u64 = 0x800704DDu;  // HRESULT_FROM_WIN32(ERROR_NOT_LOGGED_ON)
}
// Profile settings with no signed-in profile (port policy: nobody signs in):
// the console answers every requested setting with its default. Standard
// two-step protocol: without a big enough buffer, report the size needed
// and return ERROR_INSUFFICIENT_BUFFER (122); then fill
// XUSER_READ_PROFILE_SETTING_RESULT {count, pSettings} followed by one
// 40-byte XUSER_PROFILE_SETTING per id (source XSOURCE_DEFAULT, data type
// taken from bits 28-31 of the setting id, value zero). Reads naming
// specific XUIDs, or asynchronous (overlapped) reads, fail closed until
// observed.
static void __imp__XamUserReadProfileSettings(Context& ctx, Machine& base) {
  const uint32_t n = ctx.r7.u32, ids = ctx.r8.u32, pcb = ctx.r9.u32, out = ctx.r10.u32;
  const uint32_t overlapped = uint32_t(base.load(ctx.r1.u32 + 0x54u, 4));
  if (ctx.r5.u32 != 0u || ctx.r6.u32 != 0u || n == 0u || n > 64u || !ids || !pcb ||
      overlapped != 0u) {
    cc_elog("PROFILEREAD reject title=%08x user=%u numFor=%u n=%u ovl=%08x\n",
            ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, n, overlapped);
    base.fail(Error::unsupported, 0x8214AAB4u);
  }
  const uint32_t need = 8u + n * 40u;
  if (out == 0u || uint32_t(base.load(pcb, 4)) < need) {
    base.store(pcb, 4, need);
    ctx.r3.u64 = 122u;  // ERROR_INSUFFICIENT_BUFFER
    return;
  }
  base.store(out + 0, 4, n);
  base.store(out + 4, 4, out + 8u);
  for (uint32_t i = 0; i < n; ++i) {
    const uint32_t e = out + 8u + i * 40u;
    const uint32_t id = uint32_t(base.load(ids + i * 4u, 4));
    for (uint32_t k = 0; k < 40u; k += 4u) base.store(e + k, 4, 0u);
    base.store(e + 0, 4, 1u);                 // XSOURCE_DEFAULT
    base.store(e + 8, 4, ctx.r4.u32);          // user index
    base.store(e + 16, 4, id);                 // dwSettingId
    base.store(e + 24, 1, (id >> 28) & 0xFu);  // XUSER_DATA.type
  }
  base.store(pcb, 4, need);
  ctx.r3.u64 = 0u;
}
static void __imp__XamUserWriteProfileSettings(Context& ctx, Machine& base) {
  // Four-player diagnostic: settings written for the local profiles of pads
  // 1-3 are accepted and dropped (completed at once when overlapped).
  if (!cc_four_players() || ctx.r4.u32 < 1u || ctx.r4.u32 > 3u) base.fail(Error::unsupported, 0x8214AAC4u);
  if (const uint32_t ov = ctx.r7.u32) {
    base.store(ov + 0, 4, 0u);   // InternalLow = ERROR_SUCCESS
    base.store(ov + 4, 4, 0u);
    base.store(ov + 24, 4, 0u);
    ctx.r3.u64 = 997u;           // ERROR_IO_PENDING (already complete)
    return;
  }
  ctx.r3.u64 = 0u;
}
static void __imp__XamVoiceClose([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214ADA4u); }
static void __imp__XamWriteGamerTile(Context& ctx, Machine& base) {
  // Four-player diagnostic: gamer-picture awards for the local profiles are
  // accepted and dropped (the original Xbox has no gamer pictures).
  if (!cc_four_players()) base.fail(Error::unsupported, 0x8214A294u);
  ctx.r3.u64 = 0u;
}
static void __imp__XexGetModuleHandle(Context& ctx, Machine& base) {
  // Only the observed "xam.xex" lookup is accepted; the fixture hands back
  // an opaque module token.
  if (uint32_t(base.load(ctx.r3.u32,4))!=0x78616d2eu) // "xam."
    base.fail(Error::unsupported, 0x8214ABA4u);
  base.store(ctx.r4.u32,4,0x0D0D0001u);
  ctx.r3.u64=0u;
}
static void __imp__XexGetProcedureAddress(Context& ctx, Machine& base) {
  // The exact caller probes optional XAM ordinals on the fixture module
  // token; the 2008-era dashboard lineage does not export them, so the
  // documented not-found status selects the original fallback path.
  if (ctx.r3.u32!=0x0D0D0001u)
    base.fail(Error::unsupported, 0x8214A5D4u);
  base.store(ctx.r5.u32,4,0u);
  ctx.r3.u64=0xC0000225u; // STATUS_NOT_FOUND
}


// WIP 022: XAM/Live profile-manager family (exact bodies; executed only where observed)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#include "generated/sub_820A1BF8.inc"
#include "generated/sub_820D7E90.inc"
#include "generated/sub_820D7EA0.inc"
#include "generated/sub_820FBF50.inc"
#include "generated/sub_820A1E50.inc"
#include "generated/sub_820FBF60.inc"
#include "generated/sub_82104FD0.inc"
#include "generated/sub_820B6CA0.inc"
#include "generated/sub_820757C8.inc"
#include "generated/sub_820782F0.inc"
#include "generated/sub_820D7DD8.inc"
#include "generated/sub_820FBEC8.inc"
#include "generated/sub_820A0540.inc"
#include "generated/sub_820A39F0.inc"
#include "generated/sub_820A37B8.inc"
#include "generated/sub_820A3900.inc"
#include "generated/sub_820B5CE0.inc"
#include "generated/sub_820B5A10.inc"
#include "generated/sub_820B6C58.inc"
#include "generated/sub_820B5A00.inc"
#include "generated/sub_82077A98.inc"
#include "generated/sub_820A6490.inc"
#include "generated/sub_820FC720.inc"
#include "generated/sub_82104B10.inc"
#include "generated/sub_820FC710.inc"
#include "generated/sub_820FC5A0.inc"
#include "generated/sub_820A1288.inc"
#include "generated/sub_820FC1D8.inc"
#include "generated/sub_820A0C38.inc"
#include "generated/sub_820B5C40.inc"
#include "generated/sub_820A0AF8.inc"
#include "generated/sub_820B6818.inc"
#include "generated/sub_820A0988.inc"
#include "generated/sub_820A08C0.inc"
#include "generated/sub_820A3F38.inc"
#include "generated/sub_820A36D8.inc"
#ifdef CC_FAST
#define sub_8209D948 sub_8209D948_exact
#endif
#include "generated/sub_8209D948.inc"
#ifdef CC_FAST
#undef sub_8209D948
// String table lookup (exact sub_8209D948: table r3, string r4; returns the
// string's id, inserting it through sub_8209DAB0 when absent; a null or
// empty string is id 0). Hash: the sum of (119 + i) * byte i, 32-bit. The
// u16 slot array [table+36] has [table+32] entries (a power of two); probing
// is linear from hash & (size - 1) until an empty slot, a slot's id
// indexing the string pointers at [table+28]. The first probed slot is
// stored at +44 and the slot after the last probed one at +40; a miss
// passes the first slot to the insert. The string bytes are read through
// host pointers where the page allows. The original's frame words (return
// address, saved r31, back chain) are written as it writes them.
// Switches: CC_INTERN_EXACT=1 (host) / CC_INTERN_EXACT_BUILD (Xbox) run the
// original; CC_ORACLE=1 or CC_INTERN_ORACLE=1 run it instead and compare
// the id (the new id on a miss) and +40/+44 with the native's.
static CC_HOT_FN void sub_8209D948(Context& ctx, Machine& base) {
  CC_FPROF_SCOPE(sub_8209D948_native);
#ifndef CC_XBOX_DRIVER
  static const bool exact = std::getenv("CC_INTERN_EXACT") != nullptr;
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr || std::getenv("CC_INTERN_ORACLE") != nullptr;
#elif defined(CC_INTERN_EXACT_BUILD)
  constexpr bool exact = true;
#else
  constexpr bool exact = false;
#endif
  if (exact) { sub_8209D948_exact(ctx, base); return; }
  const uint32_t t = ctx.r3.u32, str = ctx.r4.u32, r1 = ctx.r1.u32;
  REX_STORE_U32(r1 - 8u, uint32_t(ctx.lr));
  REX_STORE_U64(r1 - 16u, ctx.r31.u64);
  REX_STORE_U32(r1 - 96u, r1);
  if (str == 0u || REX_LOAD_U8(str) == 0u) { ctx.r3.u64 = 0u; return; }
  uint32_t avail = 0u;
  const uint8_t* hp = cc_host_span(str, avail);
  uint32_t h = 0u, len = 0u;
  while (len < avail && hp[len] != 0u) { h += (119u + len) * hp[len]; ++len; }
  if (len == avail)  // no host bytes, or the string runs past its page
    for (uint32_t c; (c = REX_LOAD_U8(str + len)) != 0u; ++len) h += (119u + len) * c;
  const bool host_str = len < avail;
  const uint32_t mask = REX_LOAD_U32(t + 32u) - 1u, slots = REX_LOAD_U32(t + 36u), strings = REX_LOAD_U32(t + 28u);
  const uint32_t first = h & mask;
  uint32_t pos = first;
  uint32_t id = REX_LOAD_U16(slots + pos * 2u);
  pos = (pos + 1u) & mask;
  while (id != 0u) {
    // strcmp(str, string of id): equal when they agree up to str's zero byte
    const uint32_t s2 = REX_LOAD_U32(strings + id * 4u);
    uint32_t avail2 = 0u;
    const uint8_t* hq = cc_host_span(s2, avail2);
    uint32_t i = 0u;
    if (host_str && len < avail2) {
      while (i < len && hp[i] == hq[i]) ++i;
      if (i == len && hq[len] == 0u) break;
    } else {
      for (; i <= len; ++i) {
        const uint32_t q = i < avail2 ? hq[i] : REX_LOAD_U8(s2 + i);
        if (q != (i < len ? REX_LOAD_U8(str + i) : 0u)) break;
      }
      if (i > len) break;
    }
    id = REX_LOAD_U16(slots + pos * 2u);
    pos = (pos + 1u) & mask;
  }
#ifndef CC_XBOX_DRIVER
  if (oracle) {
    const uint32_t count = REX_LOAD_U32(t + 20u);
    sub_8209D948_exact(ctx, base);
    const uint32_t want = id != 0u ? id : (count & 0xFFFFu);
    if (ctx.r3.u32 != want) cc_oracle_mismatch(id != 0u ? "sub_8209D948 id" : "sub_8209D948 insert", 0, ctx.r3.u32, want);
    if (REX_LOAD_U32(t + 40u) != pos) cc_oracle_mismatch("sub_8209D948 +40", 0, REX_LOAD_U32(t + 40u), pos);
    if (REX_LOAD_U32(t + 44u) != first) cc_oracle_mismatch("sub_8209D948 +44", 0, REX_LOAD_U32(t + 44u), first);
    return;
  }
#endif
  REX_STORE_U32(t + 44u, first);
  REX_STORE_U32(t + 40u, pos);
  if (id != 0u) { ctx.r3.u64 = id; return; }
  CcFrame frame(ctx, base, 96u);
  ctx.r3.u64 = t; ctx.r4.u64 = first; ctx.r5.u64 = str; ctx.lr = 0x8209DA80u;
  sub_8209DAB0(ctx, base);
}
#endif
#include "generated/sub_82097298.inc"
#include "generated/sub_82077310.inc"
#include "generated/sub_820778D0.inc"
#include "generated/sub_820B5A08.inc"
#include "generated/sub_8210C908.inc"
#include "generated/sub_820FF968.inc"
#include "generated/sub_82109190.inc"
#include "generated/sub_821028D8.inc"
#include "generated/sub_8210C788.inc"
#include "generated/sub_820FC668.inc"
#include "generated/sub_820B6820.inc"
#include "generated/sub_820B6AC0.inc"
#include "generated/sub_820B72E8.inc"
#define sub_820D8430 sub_820D8430_exact
#include "generated/sub_820D8430.inc"
#undef sub_820D8430
static void sub_820D8430(Context& ctx, Machine& base) {
  // Port voices (music/effect volume set directly by the audio manager).
  if (cc_audio_set_volume(ctx.r3.u32, float(ctx.f1.f64))) { ctx.r3.u64 = 0; return; }
  sub_820D8430_exact(ctx, base);
}
#include "generated/sub_8209D488.inc"
#include "generated/sub_82058478.inc"
#include "generated/sub_820FC240.inc"
#include "generated/sub_820A0FF0.inc"
#include "generated/sub_8209D5F8.inc"
#include "generated/sub_8209DAB0.inc"
#define sub_820D8370 sub_820D8370_exact
#include "generated/sub_820D8370.inc"
#undef sub_820D8370
static void sub_820D8370(Context& ctx, Machine& base) {
  // Port voices (stop issued directly by the audio manager).
  if (cc_audio_stop(ctx.r3.u32)) { ctx.r3.u64 = 0; return; }
  sub_820D8370_exact(ctx, base);
}
#include "generated/sub_820A1138.inc"
#include "generated/sub_82097198.inc"
#include "generated/sub_82097420.inc"
#include "generated/sub_8206C1D0.inc"
#include "generated/sub_82078FE8.inc"
#include "generated/sub_8206DD58.inc"
#ifdef CC_FAST
#define sub_82053BC8 sub_82053BC8_exact
#endif
#include "generated/sub_82053BC8.inc"
#ifdef CC_FAST
#undef sub_82053BC8
// Front-end SetMenu (exact sub_82053BC8: menu system r3, menu index r4;
// the current index is the u16 at +52). The game-mode book's handler
// sub_82063758 stores the chosen mode in the u16 at +12 (0, 1 or 3) and
// then starts it right away for a player signed in to Xbox LIVE (bit
// player in [[0x8225E61C]+104]) through sub_82063C00 / sub_82063F18 /
// sub_82063DC8, or otherwise opens menu 18, "Sign In To Xbox LIVE to post
// your score to the leaderboards". The original Xbox has no leaderboards,
// so the play build takes the signed-in path for everyone (user,
// 2026-10-03). Host CC_LIVE_NOTICE=1 keeps the notice (the scripted host
// run's inputs and reference frames were recorded with it).
static void sub_82053BC8(Context& ctx, Machine& base) {
  if (cc_skip_live_notice() && ctx.r4.u32 == 18u && uint32_t(ctx.lr) == 0x82063BF4u) {
    switch (base.load(ctx.r3.u32 + 12u, 2)) {
      case 0u: ctx.lr = 0x82063BE4u; sub_82063C00(ctx, base); return;
      case 1u: ctx.lr = 0x82063940u; sub_82063F18(ctx, base); return;
      case 3u: ctx.lr = 0x82063AC8u; sub_82063DC8(ctx, base); return;
      default: break;
    }
  }
  sub_82053BC8_exact(ctx, base);
}
#endif
// PORT POLICY, revised 2026-09-27: Xbox Live stays stubbed, but at the
// network layer ("this console is offline") instead of at the Live
// singleton. The game's local-player bookkeeping (profile manager, player
// join) is built on this singleton; refusing it disabled the whole local
// profile system, so nobody could join a game. The exact constructor now
// runs, and every network-facing import below it answers as an offline
// console. Achievements and leaderboards remain stubbed at their imports.
#include "generated/sub_8210C860.inc"
#include "generated/sub_820FE418.inc"
#include "generated/sub_82108F48.inc"
#include "generated/sub_821090C8.inc"
#include "generated/sub_82101528.inc"
#include "generated/sub_82108F60.inc"
#include "generated/sub_82115008.inc"
#include "generated/sub_82078D90.inc"
#include "generated/sub_820B5C58.inc"
#include "generated/sub_82050468.inc"
#include "generated/sub_82050900.inc"
#include "generated/sub_820A0F88.inc"
#include "generated/sub_82068470.inc"
#ifdef CC_FAST
#define sub_82067230 sub_82067230_exact
#endif
#include "generated/sub_82067230.inc"
#ifdef CC_FAST
#undef sub_82067230
// Set a text object's string by id. With main-menu items dropped (see the
// trim above), later code that addresses menu slots by index can hand this
// a null object (the Download Content slot); setting text on a missing
// item is a no-op in the play build.
static void sub_82067230(Context& ctx, Machine& base) {
  if (ctx.r3.u32 == 0u) return;
  sub_82067230_exact(ctx, base);
}
#endif
#include "generated/sub_82066610.inc"
// PORT POLICY (user directive 2026-09-27): the original Xbox has no
// profiles, so nobody is ever signed in. Exact sub_82053C70 is the menu
// action gate; its fifth argument (r7) says "this action requires a
// signed-in profile", and when set with an empty profile mask the sealed
// code opens the Xbox 360 sign-in blade and blocks the action. The port
// runs the sealed body unchanged with only that requirement argument
// cleared, so every other check it performs (player index range, the
// other capability masks, the action dispatch) is the original code.
#define sub_82053C70 sub_82053C70_exact
#include "generated/sub_82053C70.inc"
#undef sub_82053C70
static void sub_82053C70(Context& ctx, Machine& base) {
  static uint32_t logged = 0;
  if (logged < 4u && (ctx.r7.u32 & 0xFFu) != 0u) {
    ++logged;
    cc_log("profile_gate dropped player=%d flags r6=%u r8=%u r9=%u r10=%u frame=%u\n",
           int(int16_t(ctx.r4.u16)), ctx.r6.u32 & 0xFFu, ctx.r8.u32 & 0xFFu,
           ctx.r9.u32 & 0xFFu, ctx.r10.u32 & 0xFFu, g_frame_delay_calls);
  }
  ctx.r7.u64 = 0u;
  sub_82053C70_exact(ctx, base);
}
#include "generated/sub_82114EA0.inc"
#include "generated/sub_82136F58.inc"
#include "generated/sub_8210C710.inc"
#include "generated/sub_82109340.inc"
#include "generated/sub_82107C10.inc"
#include "generated/sub_821080C8.inc"
#include "generated/sub_82108F78.inc"
#include "generated/sub_8213B068.inc"
#include "generated/sub_82100FD8.inc"
#include "generated/sub_82136F68.inc"
#include "generated/sub_82108860.inc"
#include "generated/sub_82108F88.inc"
#include "generated/sub_82107ED8.inc"
#include "generated/sub_82072EB0.inc"
#include "generated/sub_820B5958.inc"
#include "generated/sub_82050A50.inc"
#include "generated/sub_820D81B8.inc"
#include "generated/sub_82127BC8.inc"
#include "generated/sub_82127E20.inc"
#include "generated/sub_820B5D30.inc"
#include "generated/sub_82054D38.inc"
#include "generated/sub_8213AFE8.inc"
#include "generated/sub_820D7F18.inc"
#include "generated/sub_82109A50.inc"
#include "generated/sub_820FCFB0.inc"
#include "generated/sub_821388E0.inc"
#include "generated/sub_82107C20.inc"
#include "generated/sub_821080E0.inc"
#include "generated/sub_82108E28.inc"
#include "generated/sub_820FFCB0.inc"
#include "generated/sub_8210C510.inc"
#include "generated/sub_8210BE88.inc"
#include "generated/sub_82100718.inc"
#include "generated/sub_820B6CA8.inc"
#include "generated/sub_8210BC48.inc"
#include "generated/sub_82073FA0.inc"
#include "generated/sub_820B58D0.inc"
#include "generated/sub_820510F8.inc"
#include "generated/sub_820515C8.inc"
#include "generated/sub_8213AAB0.inc"
#include "generated/sub_82136C88.inc"
#include "generated/sub_820D7F98.inc"
#include "generated/sub_820FD938.inc"
#include "generated/sub_820D7FB8.inc"
#include "generated/sub_82113480.inc"
#include "generated/sub_82138AE0.inc"
#include "generated/sub_82109430.inc"
#include "generated/sub_8210B298.inc"
#include "generated/sub_8210BC10.inc"
#include "generated/sub_82109068.inc"
#include "generated/sub_82136E38.inc"
#include "generated/sub_820FE778.inc"
#include "generated/sub_8210C060.inc"
#include "generated/sub_82108E90.inc"
#include "generated/sub_82108DE8.inc"
#include "generated/sub_82108E70.inc"
#include "generated/sub_8210AA68.inc"
#include "generated/sub_82100538.inc"
#include "generated/sub_82074080.inc"
#include "generated/sub_82050F90.inc"
#include "generated/sub_8213E2A0.inc"
#include "generated/sub_820B6868.inc"
#include "generated/sub_82139320.inc"
#include "generated/sub_8213A990.inc"
#include "generated/sub_8213CA00.inc"
#include "generated/sub_82149AD0.inc"
#include "generated/sub_8213A1E0.inc"
#include "generated/sub_82109FC8.inc"
#include "generated/sub_82112BC0.inc"
#include "generated/sub_82115C28.inc"
#include "generated/sub_82115208.inc"
#include "generated/sub_82117908.inc"
#include "generated/sub_82115638.inc"
#include "generated/sub_82112570.inc"
#include "generated/sub_8210E528.inc"
#include "generated/sub_8210BBC8.inc"
#include "generated/sub_820FD240.inc"
#include "generated/sub_820FD148.inc"
#include "generated/sub_8210C008.inc"
#include "generated/sub_82110888.inc"
#include "generated/sub_8210FFF0.inc"
#include "generated/sub_8210E0B8.inc"
#include "generated/sub_820FD8A8.inc"
#include "generated/sub_820FF3A8.inc"
#include "generated/sub_82074388.inc"
#include "generated/sub_8213EB88.inc"
#include "generated/sub_8213D808.inc"
#include "generated/sub_8213DCE0.inc"
#include "generated/sub_820D8588.inc"
#include "generated/sub_820D85E8.inc"
#include "generated/sub_82141BD0.inc"
#include "generated/sub_8213EF58.inc"
#include "generated/sub_8213C850.inc"
#include "generated/sub_8213A070.inc"
#include "generated/sub_82109BA0.inc"
#include "generated/sub_821151C8.inc"
#include "generated/sub_82112D10.inc"
#include "generated/sub_8210DA60.inc"
#include "generated/sub_82120688.inc"
#include "generated/sub_82115FA8.inc"
#include "generated/sub_82115CD0.inc"
#include "generated/sub_821157C8.inc"
#include "generated/sub_82115530.inc"
#include "generated/sub_82112238.inc"
#include "generated/sub_82115670.inc"
#include "generated/sub_821117E0.inc"
#include "generated/sub_8210CA68.inc"
#include "generated/sub_821156C0.inc"
#include "generated/sub_82116398.inc"
#include "generated/sub_820FC740.inc"
#include "generated/sub_8210E678.inc"
#include "generated/sub_8210F320.inc"
#include "generated/sub_82108E80.inc"
#include "generated/sub_82108DF8.inc"
#include "generated/sub_8213EE98.inc"
#include "generated/sub_8213EAE0.inc"
#include "generated/sub_820D8020.inc"
#include "generated/sub_820D8088.inc"
#include "generated/sub_820DC6A8.inc"
#include "generated/sub_820DCCB0.inc"
#include "generated/sub_82140F28.inc"
#include "generated/sub_82141A40.inc"
#include "generated/sub_8213EE10.inc"
#include "generated/sub_82136E60.inc"
#include "generated/sub_82118268.inc"
#include "generated/sub_8211E870.inc"
#include "generated/sub_82116FB8.inc"
#include "generated/sub_8210F488.inc"
#include "generated/sub_82116728.inc"
#include "generated/sub_82111FB0.inc"
#include "generated/sub_8210D130.inc"
#include "generated/sub_8210DAB8.inc"
#include "generated/sub_821158D8.inc"
#include "generated/sub_82115998.inc"
#include "generated/sub_82120620.inc"
#include "generated/sub_821156E8.inc"
#include "generated/sub_820D7F08.inc"
#include "generated/sub_82115238.inc"
#include "generated/sub_821153D0.inc"
#include "generated/sub_82111D58.inc"
#include "generated/sub_82111C50.inc"
#include "generated/sub_820D7EE8.inc"
#include "generated/sub_8210CA38.inc"
#include "generated/sub_8210E848.inc"
#include "generated/sub_82115188.inc"
#include "generated/sub_821138A0.inc"
#include "generated/sub_821106E0.inc"
#include "generated/sub_8210DC98.inc"
#include "generated/sub_8213EDB0.inc"
#include "generated/sub_8213E9B0.inc"
#include "generated/sub_820DBF30.inc"
#include "generated/sub_820DC2A0.inc"
#include "generated/sub_820DBCA8.inc"
#include "generated/sub_820DC8D8.inc"
#include "generated/sub_820E3728.inc"
#include "generated/sub_820DCB70.inc"
#include "generated/sub_820DCB08.inc"
#include "generated/sub_821180D8.inc"
#include "generated/sub_8211DAB8.inc"
#include "generated/sub_821229D0.inc"
#include "generated/sub_82124C40.inc"
#include "generated/sub_8211C068.inc"
#include "generated/sub_8211C7F8.inc"
#include "generated/sub_82116088.inc"
#include "generated/sub_820D7EA8.inc"
#include "generated/sub_82115930.inc"
#include "generated/sub_821163C0.inc"
#include "generated/sub_82117520.inc"
#include "generated/sub_82117820.inc"
#include "generated/sub_82115E00.inc"
#include "generated/sub_8210E7D8.inc"
#include "generated/sub_8210E730.inc"
#include "generated/sub_82111A58.inc"
#include "generated/sub_821159F0.inc"
#include "generated/sub_82114E60.inc"
#include "generated/sub_8211A990.inc"
#include "generated/sub_82116D78.inc"
#include "generated/sub_82116BA8.inc"
#include "generated/sub_8211DA00.inc"
#include "generated/sub_8210D208.inc"
#include "generated/sub_82115180.inc"
#include "generated/sub_82113668.inc"
#include "generated/sub_8210CB20.inc"
#include "generated/sub_8213EC90.inc"
#include "generated/sub_820DBBE0.inc"
#include "generated/sub_820E37E0.inc"
#include "generated/sub_820E3698.inc"
#include "generated/sub_8211AAB0.inc"
#include "generated/sub_82124438.inc"
#include "generated/sub_82126078.inc"
#include "generated/sub_821210B0.inc"
#include "generated/sub_82124880.inc"
#include "generated/sub_82123930.inc"
#include "generated/sub_82121E68.inc"
#include "generated/sub_821254C8.inc"
#include "generated/sub_82122270.inc"
#include "generated/sub_82119950.inc"
#include "generated/sub_8211AD88.inc"
#include "generated/sub_82118160.inc"
#include "generated/sub_821206C0.inc"
#include "generated/sub_82117100.inc"
#include "generated/sub_82115AA0.inc"
#include "generated/sub_8210D078.inc"
#include "generated/sub_82121EF0.inc"
#include "generated/sub_82121F40.inc"
#include "generated/sub_82122DB8.inc"
#include "generated/sub_82122900.inc"
#include "generated/sub_82115290.inc"
#include "generated/sub_8211E468.inc"
#include "generated/sub_820DB930.inc"
#include "generated/sub_82125908.inc"
#include "generated/sub_82122BD0.inc"
#include "generated/sub_82122B78.inc"
#include "generated/sub_8211BD50.inc"
#include "generated/sub_82124718.inc"
#include "generated/sub_82122708.inc"
#include "generated/sub_82122840.inc"
#include "generated/sub_821233B8.inc"
#include "generated/sub_82126288.inc"
#include "generated/sub_82118BC8.inc"
#include "generated/sub_8211E560.inc"
#include "generated/sub_8211C550.inc"
#include "generated/sub_82120548.inc"
#include "generated/sub_821227D0.inc"
#include "generated/sub_82126E20.inc"
#include "generated/sub_82126948.inc"
#include "generated/sub_8211DC88.inc"
#include "generated/sub_8211FD38.inc"
#include "generated/sub_82118E38.inc"
#include "generated/sub_8211C0E8.inc"
#include "generated/sub_8211C158.inc"
#include "generated/sub_8211A3B8.inc"
#include "generated/sub_821243D0.inc"
#include "generated/sub_8211AA40.inc"
#include "generated/sub_82122310.inc"
#include "generated/sub_82122EF8.inc"
#include "generated/sub_82122768.inc"
#include "generated/sub_82122640.inc"
#include "generated/sub_820FC858.inc"
#include "generated/sub_82118AF0.inc"
#include "generated/sub_82121038.inc"
#include "generated/sub_820FC8B0.inc"
#include "generated/sub_821182E0.inc"
#include "generated/sub_8211D390.inc"
#include "generated/sub_8211B798.inc"
#include "generated/sub_8211A058.inc"
#include "generated/sub_8211B800.inc"
#include "generated/sub_8211B728.inc"
#include "generated/sub_8211B970.inc"
#include "generated/sub_8211D5B0.inc"
#include "generated/sub_82125088.inc"
#include "generated/sub_8211C3B0.inc"
#include "generated/sub_82123078.inc"
#include "generated/sub_82124958.inc"
#include "generated/sub_82119FE8.inc"
#include "generated/sub_8211AB48.inc"
#include "generated/sub_82126898.inc"
#include "generated/sub_821231F0.inc"
#include "generated/sub_82126198.inc"
#include "generated/sub_82125E28.inc"
#include "generated/sub_82124E80.inc"
#include "generated/sub_82124E68.inc"
#include "generated/sub_82124FE8.inc"
#include "generated/sub_82125038.inc"
#include "generated/sub_82124E50.inc"
#include "generated/sub_82121B80.inc"
#include "generated/sub_82122FC8.inc"
#include "generated/sub_82121B08.inc"
#include "generated/sub_82124CD0.inc"
#include "generated/sub_82125E08.inc"
#include "generated/sub_821224C8.inc"
#include "generated/sub_8211E770.inc"
#include "generated/sub_82125390.inc"
#include "generated/sub_82119F88.inc"
#include "generated/sub_8211A158.inc"
#include "generated/sub_8211A1E0.inc"
#include "generated/sub_821217D0.inc"
#include "generated/sub_82121610.inc"
#include "generated/sub_821217C0.inc"
#include "generated/sub_821217C8.inc"
#include "generated/sub_821216D0.inc"
#include "generated/sub_821215B0.inc"
#include "generated/sub_82121670.inc"
#include "generated/sub_82126530.inc"
#include "generated/sub_8211AF80.inc"
#include "generated/sub_82121370.inc"
#include "generated/sub_8211B8F8.inc"
#include "generated/sub_82122AC0.inc"
#include "generated/sub_82121738.inc"
#include "generated/sub_82122680.inc"
#include "generated/sub_82122C78.inc"
#include "generated/sub_82122438.inc"
#include "generated/sub_82126FE0.inc"
#include "generated/sub_82125E38.inc"
#include "generated/sub_82125628.inc"
#include "generated/sub_82124820.inc"
#include "generated/sub_82124500.inc"
#include "generated/sub_821244A8.inc"
#include "generated/sub_82120AF0.inc"
#include "generated/sub_82120B30.inc"
#include "generated/sub_82122608.inc"
#include "generated/sub_82122C20.inc"
#include "generated/sub_82125E68.inc"
#include "generated/sub_821225D0.inc"
#include "generated/sub_82125EA0.inc"
#include "generated/sub_8211BB58.inc"
#include "generated/sub_8211BA00.inc"
#include "generated/sub_8211A0F0.inc"
#include "generated/sub_8211BA60.inc"
#include "generated/sub_82120778.inc"
#include "generated/sub_82125C10.inc"
#include "generated/sub_82125A88.inc"
#include "generated/sub_82120F60.inc"
#include "generated/sub_82120C00.inc"
#include "generated/sub_82120958.inc"
#include "generated/sub_82120AE0.inc"
#include "generated/sub_82120EA8.inc"
#include "generated/sub_82120BB8.inc"
#include "generated/sub_82120E08.inc"
#include "generated/sub_821235B0.inc"
#include "generated/sub_82121230.inc"
#include "generated/sub_8211AE00.inc"
#include "generated/sub_82126298.inc"
#include "generated/sub_82120C20.inc"
#include "generated/sub_8212B180.inc"
#include "generated/sub_82126C48.inc"
#include "generated/sub_82126D40.inc"
#include "generated/sub_82125558.inc"
#include "generated/sub_8211AED8.inc"
#include "generated/sub_8211A288.inc"
#include "generated/sub_82125BA8.inc"
#include "generated/sub_82123C00.inc"
#include "generated/sub_821260B0.inc"
#include "generated/sub_82126120.inc"
#include "generated/sub_821240F0.inc"
#pragma clang diagnostic pop

// WIP 022: remaining sub_82070AC8 tail (sub_82075C88 game-manager, sub_820759A8, sub_82070908)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
// Timing split of the game's per-frame update and render: host CC_WORKSET
// report, and the Xbox on-screen counters.
#define sub_82075C88 sub_82075C88_exact
#define sub_820759A8 sub_820759A8_exact
#include "generated/sub_82075C88.inc"
#include "generated/sub_820759A8.inc"
#undef sub_82075C88
#undef sub_820759A8
#ifdef CC_XBOX_DRIVER
static void sub_82075C88(Context& ctx, Machine& base) {
  const uint64_t t0 = ::cc_xbox_clock(1000000u);
  sub_82075C88_exact(ctx, base);
  g_frame_update_us += uint32_t(::cc_xbox_clock(1000000u) - t0);
}
static void sub_820759A8(Context& ctx, Machine& base) {
  const uint64_t t0 = ::cc_xbox_clock(1000000u);
  sub_820759A8_exact(ctx, base);
  g_frame_render_us += uint32_t(::cc_xbox_clock(1000000u) - t0);
}
#else
static void sub_82075C88(Context& ctx, Machine& base) {
  const auto t0 = std::chrono::steady_clock::now();
  sub_82075C88_exact(ctx, base);
  g_update_seconds += std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
}
static void sub_820759A8(Context& ctx, Machine& base) {
  const auto t0 = std::chrono::steady_clock::now();
  sub_820759A8_exact(ctx, base);
  g_render_seconds += std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
}
#endif
#include "generated/sub_82070908.inc"
#include "generated/sub_8209B648.inc"
#include "generated/sub_82076CE0.inc"
#include "generated/sub_8209FF98.inc"
#include "generated/sub_82076F08.inc"
#include "generated/sub_82096950.inc"
#include "generated/sub_82099FA0.inc"
#include "generated/sub_820A2150.inc"
#include "generated/sub_820762D0.inc"
#include "generated/sub_82076AD8.inc"
#include "generated/sub_82076758.inc"
#include "generated/sub_820776D8.inc"
#include "generated/sub_82078280.inc"
#include "generated/sub_82078F38.inc"
#include "generated/sub_820A4AD8.inc"
#include "generated/sub_82076DC8.inc"
#include "generated/sub_8209B5D0.inc"
#include "generated/sub_8209C128.inc"
#include "generated/sub_820B6908.inc"
#include "generated/sub_820A1D20.inc"
#include "generated/sub_82077808.inc"
#include "generated/sub_820758E8.inc"
#include "generated/sub_82050800.inc"
#include "generated/sub_820B5858.inc"
#include "generated/sub_820A11B0.inc"
#include "generated/sub_820A13E8.inc"
#include "generated/sub_820B6A28.inc"
#include "generated/sub_820A1560.inc"
#include "generated/sub_82067518.inc"
#include "generated/sub_820A5390.inc"
#include "generated/sub_82051B60.inc"
#include "generated/sub_820A49E0.inc"
#include "generated/sub_820A47E8.inc"
#include "generated/sub_820A6CD8.inc"
#include "generated/sub_820A70B0.inc"
#include "generated/sub_820A3EB8.inc"
#include "generated/sub_820FC418.inc"
#include "generated/sub_82078E38.inc"
#include "generated/sub_8209C718.inc"
#include "generated/sub_820780D8.inc"
#ifdef CC_FAST
#define sub_82077CE0 sub_82077CE0_exact
#endif
#include "generated/sub_82077CE0.inc"
#ifdef CC_FAST
#undef sub_82077CE0
// Movie change (exact sub_82077CE0: manager r3, name r4 = {u32 length,
// chars}, r5). Levels arrive here by name; the first one after character
// select is "level2" (the castle interior). With a direct level set
// (make LEVEL=<n> / CC_LEVEL=<n>), that request names "level<n>" instead,
// from a copy in the platform-globals page, so the game loads and starts
// that level itself: pak, movie, BSP, music and scripts.
static void sub_82077CE0(Context& ctx, Machine& base) {
  const uint32_t lvl = cc_direct_level();
#ifndef CC_XBOX_DRIVER
  if (std::getenv("CC_MOVIE_LOG") && ctx.r4.u32) {
    const uint32_t len = uint32_t(base.load(ctx.r4.u32, 4));
    char nm[24] = {};
    for (uint32_t k = 0; k < len && k < 23u; ++k) nm[k] = char(base.load(ctx.r4.u32 + 4u + k, 1));
    cc_log("movie '%s' r3=%08x r5=%08x lr=%08x phase640=%08x\n", nm, ctx.r3.u32, ctx.r5.u32, uint32_t(ctx.lr), uint32_t(base.load(0x82290280u, 4)));
  }
#endif
  if (false && lvl && ctx.r4.u32) {  // superseded by the queue-time rename (sub_82077BC0)
    const uint32_t len = uint32_t(base.load(ctx.r4.u32, 4));
    char name[16] = {};
    for (uint32_t k = 0; k < len && k < 15u; ++k) name[k] = char(base.load(ctx.r4.u32 + 4u + k, 1));
    if (len == 6u && std::strcmp(name, "level2") == 0) {  // every request for it
      // r4 is the manager's own movie slot name (76-byte slots), so the
      // rename is made in place and every later step sees the new level.
      char repl[16] = {};
      const int n = std::snprintf(repl, sizeof(repl), "level%u", lvl);
      base.store(ctx.r4.u32, 4, uint32_t(n));
      for (int k = 0; k <= n; ++k) base.store(ctx.r4.u32 + 4u + uint32_t(k), 1, uint8_t(repl[k]));
      cc_log("direct_level %s -> %s\n", name, repl);
    }
  }
  sub_82077CE0_exact(ctx, base);
}
#endif
#include "generated/sub_8206BE30.inc"
#include "generated/sub_820B5FE8.inc"
#include "generated/sub_820788B8.inc"
#include "generated/sub_8209AED8.inc"
#include "generated/sub_82095FF0.inc"
#include "generated/sub_82095DA8.inc"
#include "generated/sub_8209DBC0.inc"
#include "generated/sub_82075130.inc"
#include "generated/sub_82095F18.inc"
#include "generated/sub_820727D8.inc"
#include "generated/sub_8209BB30.inc"
#include "generated/sub_820A5478.inc"
#include "generated/sub_8209DFE8.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_27.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_27.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_820A1DD8.inc"
#include "generated/sub_82078170.inc"
#include "generated/sub_82095F78.inc"
#include "generated/sub_8208F5F0.inc"
#include "generated/sub_820966A0.inc"
#include "generated/sub_82128298.inc"
#include "generated/sub_820A15C0.inc"
#include "generated/sub_820B6828.inc"
#include "generated/sub_820B6810.inc"
#include "generated/sub_820D8210.inc"
#include "generated/sub_820FBEA8.inc"
#include "generated/sub_820FBF88.inc"
#include "generated/sub_820A6E08.inc"
#include "generated/sub_820FC0F8.inc"
#include "generated/sub_820FC058.inc"
#include "generated/sub_820FC288.inc"
#include "generated/sub_820FBFD0.inc"
#include "generated/sub_82072D00.inc"
#include "generated/sub_82078810.inc"
#include "generated/sub_82078778.inc"
#ifdef CC_FAST
#define sub_82077FD8 sub_82077FD8_exact
#endif
#include "generated/sub_82077FD8.inc"
#ifdef CC_FAST
#undef sub_82077FD8
// GameManager movie lookup by name (exact sub_82077FD8: manager r3, name r4
// = {u32 length, chars}; returns the slot index or -1). With a direct level
// set, lookups of "level2" find the replacement level, so the scripts that
// wait for the first level see it load.
static void sub_82077FD8(Context& ctx, Machine& base) {
  if (const uint32_t lvl = cc_direct_level(); lvl && ctx.r4.u32 && base.load(ctx.r4.u32, 4) == 6u) {
    char name[8] = {};
    for (uint32_t k = 0; k < 6u; ++k) name[k] = char(base.load(ctx.r4.u32 + 4u + k, 1));
    if (std::strcmp(name, "level2") == 0) {
      char repl[16] = {};
      const int n = std::snprintf(repl, sizeof(repl), "level%u", lvl);
      constexpr uint32_t obj = 0x025004C0u;
      base.store(obj, 4, uint32_t(n));
      for (int k = 0; k <= n; ++k) base.store(obj + 4u + uint32_t(k), 1, uint8_t(repl[k]));
      ctx.r4.u64 = obj;
    }
  }
  sub_82077FD8_exact(ctx, base);
}
#endif
#include "generated/sub_82075210.inc"
#include "generated/sub_82096530.inc"
#include "generated/sub_820967B0.inc"
#include "generated/sub_8206CC40.inc"
#include "generated/sub_8206C510.inc"
#include "generated/sub_8206CA60.inc"
#include "generated/sub_82053AC0.inc"
#include "generated/sub_820552B8.inc"
#include "generated/sub_82066680.inc"
#include "generated/sub_82128688.inc"
#include "generated/sub_8209B030.inc"
#include "generated/sub_8209B0E0.inc"
#include "generated/sub_82096250.inc"
#include "generated/sub_820960A8.inc"
#include "generated/sub_820901A8.inc"
#include "generated/sub_82127FE0.inc"
#include "generated/sub_820A1A20.inc"
#include "generated/sub_820A6A40.inc"
#include "generated/sub_8212E660.inc"
#include "generated/sub_820B6788.inc"
#include "generated/sub_820FBDF8.inc"
#include "generated/sub_820B5BE0.inc"
#include "generated/sub_820B5AA0.inc"
#include "generated/sub_820B5B80.inc"
#include "generated/sub_820521F8.inc"
#include "generated/sub_820FC8B8.inc"
#include "generated/sub_820FC548.inc"
#include "generated/sub_8212B398.inc"
#include "generated/sub_82072708.inc"
#include "generated/sub_82073B00.inc"
#include "generated/sub_820735B0.inc"
#include "generated/sub_82066F80.inc"
#include "generated/sub_82067778.inc"
#ifdef CC_FAST
#define sub_82067020 sub_82067020_exact
#define sub_82065F78 sub_82065F78_exact
#endif
#include "generated/sub_82067020.inc"
#include "generated/sub_82065F78.inc"
#ifdef CC_FAST
#undef sub_82067020
#undef sub_82065F78
// Text object constructor: remember each object's string id (see the main
// menu trim above).
static void sub_82067020(Context& ctx, Machine& base) {
  g_text_ids[g_text_ids_next % 64u] = {ctx.r3.u32, ctx.r6.u32};
  ++g_text_ids_next;
#ifndef CC_XBOX_DRIVER
  if (std::getenv("CC_TEXT_LOG"))  // host: which screen builds which text item
    cc_elog("TEXT frame=%u id=%u obj=%08x parent=%08x lr=%08x\n", g_frame_delay_calls, ctx.r6.u32, ctx.r3.u32, ctx.r4.u32, uint32_t(ctx.lr));
#endif
  sub_82067020_exact(ctx, base);
}
// Menu append: while the main menu is being built, dropped items are not
// appended (the exact code's later stores do not depend on the result).
static void sub_82065F78(Context& ctx, Machine& base) {
  if (g_menu_trim_active && cc_menu_item_dropped(cc_text_id_of(ctx.r4.u32))) return;
  sub_82065F78_exact(ctx, base);
}
#endif
#include "generated/sub_82067E00.inc"
#include "generated/sub_8205F6E0.inc"
#include "generated/sub_8205D8E0.inc"
#include "generated/sub_82054528.inc"
#include "generated/sub_8205D5A8.inc"
#include "generated/sub_8205E7E0.inc"
#include "generated/sub_82058F88.inc"
#include "generated/sub_82059210.inc"
#include "generated/sub_820585A8.inc"
#include "generated/sub_82059600.inc"
#include "generated/sub_82054858.inc"
#include "generated/sub_820589F0.inc"
#include "generated/sub_82054170.inc"
#include "generated/sub_82059EE8.inc"
#include "generated/sub_82096B48.inc"
#include "generated/sub_8212A4A8.inc"
#include "generated/sub_8212C230.inc"
#include "generated/sub_8209C0D0.inc"
#include "generated/sub_82095A08.inc"
#include "generated/sub_82096358.inc"
#include "generated/sub_820906A8.inc"
#include "generated/sub_82094048.inc"
#include "generated/sub_82094290.inc"
#include "generated/sub_8212E370.inc"
#include "generated/sub_820FC998.inc"
#include "generated/sub_82073E20.inc"
#include "generated/sub_82073D80.inc"
#include "generated/sub_82072AB8.inc"
#include "generated/sub_82067C40.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__restfpr_24.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/__savefpr_24.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif
#include "generated/sub_820679E8.inc"
#include "generated/sub_82067828.inc"
#include "generated/sub_82097A28.inc"
#include "generated/sub_82097948.inc"
#include "audio.inc"
#include "generated/sub_8212A048.inc"
#include "generated/sub_82095840.inc"
#include "generated/sub_8209B258.inc"
#include "generated/sub_8209B1E0.inc"
#include "generated/sub_8209D840.inc"
#include "generated/sub_8209D758.inc"
#include "generated/sub_82085E18.inc"
#include "generated/sub_82093848.inc"
#include "generated/sub_82085D70.inc"
#include "generated/sub_8212E338.inc"
#include "generated/sub_820742A0.inc"
#include "generated/sub_82068378.inc"
#include "generated/sub_82127CF0.inc"
#include "generated/sub_82097EE0.inc"
#include "generated/sub_8209E448.inc"
#include "generated/sub_8209ECB0.inc"
#include "generated/sub_8209E270.inc"
#include "generated/sub_8209E6C8.inc"
#include "generated/sub_820958F8.inc"
#include "generated/sub_820B0A38.inc"
#include "generated/sub_8209A628.inc"
#include "generated/sub_820B0BA8.inc"
#include "generated/sub_821282A8.inc"
#include "generated/sub_82085EC0.inc"
#ifdef CC_FAST
#define sub_82095788 sub_82095788_exact
#endif
#include "generated/sub_82095788.inc"
#ifdef CC_FAST
#undef sub_82095788
#endif
#include "generated/sub_82095700.inc"
#include "generated/sub_82099258.inc"
#include "generated/sub_82099118.inc"
#include "generated/sub_8209E098.inc"
#include "generated/sub_8209E890.inc"
#include "generated/sub_8209E1C0.inc"
#include "generated/sub_8209E328.inc"
#include "generated/sub_8212C1A0.inc"
#include "generated/sub_820AD440.inc"
#include "generated/sub_820B0830.inc"
#include "generated/sub_820AD568.inc"
#include "generated/sub_820B61A0.inc"
#include "generated/sub_820B66D8.inc"
#include "generated/sub_820AD2F0.inc"
#include "generated/sub_820AD370.inc"
#include "generated/sub_820ABCA8.inc"
#include "generated/sub_820AFDE0.inc"
#include "generated/sub_820AFE78.inc"
#include "generated/sub_820ABDB0.inc"
#include "generated/sub_820ABBD8.inc"
#include "generated/sub_821295C0.inc"
#include "generated/sub_820AE2F0.inc"
#include "generated/sub_820AE118.inc"
#include "generated/sub_820AE030.inc"
#include "generated/sub_820AC7D8.inc"
#include "generated/sub_820ADB18.inc"
#include "generated/sub_820ACEB8.inc"
#pragma clang diagnostic pop
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_PLAIN
#endif
#include "generated/sub_82070AC8_post_init.inc"
#ifdef CC_VIEW_ACTIVE
#undef DEFINE_REX_FUNC
#define DEFINE_REX_FUNC DEFINE_REX_FUNC_SELECT
#endif

// KeBugCheck is a terminal kernel failure; reaching it is never success.
static void __imp__KeBugCheck([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214A9F4u);
}

// WIP 021: the exact statically linked game heap (RtlHeap-family) reached by
// the shader loader's sub_82128F70 allocation. Game-side heap code is executed
// byte-exact; only the kernel TLS/virtual-memory/critical-section contracts
// below are modeled, each fail-closed outside its observed shape.
static void __imp__KeBugCheckEx([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214AA04u);
}
// WIP 023: KeTlsAlloc/KeTlsFree back the exact CRT _mtinit (sub_8212A630),
// run as a bounded harness pre-step exactly as the sealed XEX entry would
// have. Slots come from the same 64-entry fixture table the get/set shims
// already use; exhaustion fails closed rather than returning TLS_OUT_OF_INDEXES.
static void __imp__KeTlsAlloc(Context& ctx, Machine& base) {
  for (uint32_t i = 0; i < 64u; ++i)
    if (!(g_tls_allocated >> i & 1u)) {
      g_tls_allocated |= 1ull << i;
      g_tls_slots[i] = 0u;
      ctx.r3.u64 = i;
      return;
    }
  base.fail(Error::unsupported, 0x8214ACB4u);
}
static void __imp__KeTlsFree(Context& ctx, Machine& base) {
  const uint32_t ix = ctx.r3.u32;
  if (ix >= 64u || !(g_tls_allocated >> ix & 1u))
    base.fail(Error::unsupported, 0x8214ACE4u);
  g_tls_allocated &= ~(1ull << ix);
  g_tls_slots[ix] = 0u;
  ctx.r3.u64 = 1u;
}
static void __imp__KeTlsGetValue(Context& ctx, Machine& base) {
  if (ctx.r3.u32 >= 64u) base.fail(Error::unsupported, 0x8214ACC4u);
  ctx.r3.u64 = g_tls_slots[ctx.r3.u32];
}
static void __imp__KeTlsSetValue(Context& ctx, Machine& base) {
  if (ctx.r3.u32 >= 64u) base.fail(Error::unsupported, 0x8214ACD4u);
  g_tls_slots[ctx.r3.u32] = ctx.r4.u32;
  ctx.r3.u64 = 1u;
}
static void __imp__RtlCompareMemoryUlong(Context& ctx, Machine& base) {
  // Trusted xboxkrnl contract: count leading bytes of the ULONG-aligned block
  // at r3 (length r4) equal to pattern r5, in whole-ULONG steps.
  const uint32_t src=ctx.r3.u32, len=ctx.r4.u32 & ~3u, pat=ctx.r5.u32;
  uint32_t matched=0;
  while (matched<len && uint32_t(base.load(src+matched,4))==pat) matched+=4u;
  ctx.r3.u64=matched;
}
static void __imp__NtAllocateVirtualMemory(Context& ctx, Machine& base) {
  // Bounded virtual-memory contract for the exact CRT heap: reservations and
  // commits are served from the dedicated fixture arena at 0x04000000. Only
  // the observed shapes are accepted; anything else fails closed.
  const uint32_t base_ptr=ctx.r3.u32, size_ptr=ctx.r4.u32,
                 alloc_type=ctx.r5.u32, protect=ctx.r6.u32;
  const uint32_t want_base=uint32_t(base.load(base_ptr,4));
  const uint32_t want_size=uint32_t(base.load(size_ptr,4));
  if (ctx.r7.u32!=0u || protect!=4u || want_size==0u || want_size>0x400000u)
    base.fail(Error::unsupported, 0x8214A6B4u);
  if (alloc_type==0x60002000u && want_base==0u) {
    // Top-down reserve of a fresh region: round to 64 KiB.
    const uint32_t size=(want_size+0xFFFFu)&~0xFFFFu;
    const uint32_t p=(g_valloc_cursor+0xFFFFu)&~0xFFFFu;
    if (p+size<p || base.memory.check(p,size,3)!=cc::xbox::MemoryError::ok)
      base.fail(Error::memory,p);
    g_valloc_cursor=p+size;
    base.store(base_ptr,4,p);
    base.store(size_ptr,4,size);
    ctx.r3.u64=0;
    return;
  }
  if ((alloc_type==0x1000u||alloc_type==0x2000u||alloc_type==0x60001000u) &&
      want_base>=0x04000000u && want_base<g_valloc_cursor) {
    // Commit inside an existing fixture reservation: round to 4 KiB.
    const uint32_t start=want_base&~0xFFFu;
    const uint32_t size=((want_base-start)+want_size+0xFFFu)&~0xFFFu;
    if (base.memory.check(start,size,3)!=cc::xbox::MemoryError::ok)
      base.fail(Error::memory,start);
#ifndef CC_XBOX_DRIVER
    for (uint32_t pg=start;pg<start+size;pg+=0x1000u) g_committed_pages.insert(pg);
#endif
    base.store(base_ptr,4,start);
    base.store(size_ptr,4,size);
    ctx.r3.u64=0;
    return;
  }
  cc_elog(
    "NTALLOCVM unsupported r3=%08x r4=%08x r5=%08x r6=%08x r7=%08x [r3]=%08x [r4]=%08x lr=%08x\n",
    ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32,
    want_base, want_size, uint32_t(ctx.lr));
  base.fail(Error::unsupported, 0x8214A6B4u);
}
static void __imp__NtFreeVirtualMemory([[maybe_unused]] Context& ctx, [[maybe_unused]] Machine& base) {
#ifdef CC_FAST
  ctx.r3.u64 = 0u;  // play build: releases on the way out are accepted (nothing reuses the range)
#else
  base.fail(Error::unsupported, 0x8214A9B4u);
#endif
}

// RtlRaiseException is a terminal failure path for the exact heap; reaching
// it is never promoted to success.
static void __imp__RtlRaiseException([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214A9C4u);
}
#include "generated/sub_820B6780.inc"
#include "generated/sub_820B72C8.inc"
#include "generated/sub_820B7BC8.inc"
#include "generated/sub_820B7D88.inc"
#include "generated/sub_820B7EA8.inc"
#include "generated/sub_820B8138.inc"
#include "generated/sub_820B8540.inc"
#include "generated/sub_820B8CA0.inc"
#include "generated/sub_820B8E08.inc"
#include "generated/sub_820B9048.inc"
#include "generated/sub_820BA1D4.inc"
#include "generated/sub_820BA228.inc"
#include "generated/sub_820BA4C8.inc"
#include "generated/sub_82129470.inc"
#include "generated/sub_82129880.inc"
#include "generated/sub_8212A2E8.inc"
#include "generated/sub_8212A3B8.inc"
#include "generated/sub_8212C298.inc"
#include "generated/sub_8212E140.inc"
#include "generated/sub_8212E218.inc"
#include "generated/sub_821325C0.inc"
#include "generated/sub_820B9958.inc"
#include "generated/sub_820BB280.inc"
#include "generated/sub_8212EC50.inc"
#include "generated/sub_821294E0.inc"
#include "generated/sub_820B7BC0.inc"
#include "generated/sub_820B7630.inc"

// Exact CRT heap creation (sub_820B7880 -> RtlCreateHeap-family
// sub_820B93B0), executed as observed original startup behavior. The
// XexExecutableModuleHandle loader variable is fixture-resolved to a null
// module so the default 1 MiB reserve path is taken, exactly as a title with
// no XEX default-heap-size field.
static void __imp__RtlImageXexHeaderField([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214A684u);
}
static void __imp__NtQueryVirtualMemory(Context& ctx, Machine& base) {
  cc_elog(
    "NTQUERYVM r3=%08x r4=%08x r5=%08x r6=%08x r7=%08x r1=%08x lr=%08x\n",
    ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32,
    ctx.r1.u32, uint32_t(ctx.lr));
  base.fail(Error::unsupported, 0x8214A994u);
}
#include "generated/sub_8212A760.inc"
#include "generated/sub_820B93B0.inc"
#include "generated/sub_820B7880.inc"
#include "generated/sub_820B6CD0.inc"
#include "generated/sub_8212C368.inc"
#include "generated/sub_8212C3B0.inc"
#include "generated/sub_8212A040.inc"
#include "generated/sub_82128F70.inc"

#include "generated/sub_820B75C0.inc"
#include "generated/sub_820B6AD8.inc"

// Trusted xboxkrnl contract: initialize the ANSI_STRING at r3 (USHORT Length,
// USHORT MaximumLength, ULONG Buffer, big-endian) from the NUL-terminated
// guest buffer at r4. The observed shader-path call always passes a valid
// bounded string; unbounded scans fail closed.
static void __imp__RtlInitAnsiString(Context& ctx, Machine& base) {
  uint32_t len = 0;
  if (ctx.r4.u32) {
    while (base.load(ctx.r4.u32 + len, 1) != 0)
      if (++len >= 1024u) base.fail(Error::unsupported, 0x8214A494u);
  }
  base.store(ctx.r3.u32 + 0, 2, len);
  base.store(ctx.r3.u32 + 2, 2, ctx.r4.u32 ? len + 1 : 0);
  base.store(ctx.r3.u32 + 4, 4, ctx.r4.u32);
}

#include "generated/sub_820B7278.inc"
#include "generated/sub_820B73C8.inc"
#include "generated/sub_820B64E0.inc"
#include "generated/sub_820AA488.inc"
#if defined(CC_XBOX_DRIVER) && defined(CC_OP_STATS)
void cc_op_dbg();
#endif
#ifdef CC_FAST
// Native ActionScript interpreter (play build): runtime021/as_native.inc.
// Its clip property setter (as_ops_clip.inc) is wrapped below.
#define sub_82089F70 sub_82089F70_as
#include "as_native.inc"
#undef sub_82089F70
// Clip property set (sub_82089F70, native in as_ops_clip.inc): id 91,
// _name, stores the clip's name u16 +100 itself (no name setter), so the
// display-list name cache is flushed once it has run.
static void sub_82089F70(Context& ctx, Machine& base) {
  if (ctx.r4.u32 != 91u) { sub_82089F70_as(ctx, base); return; }
  sub_82089F70_as(ctx, base);
  cc_dl_flush();
}
#endif
