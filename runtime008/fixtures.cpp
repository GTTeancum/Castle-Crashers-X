// SPDX-License-Identifier: MIT
#include "fixtures.h"
#include <cstring>
namespace cc::tree {
uint32_t little32(const uint8_t *p) noexcept {
  return uint32_t(p[0]) | uint32_t(p[1]) << 8 | uint32_t(p[2]) << 16 |
         uint32_t(p[3]) << 24;
}
static uint64_t little64(const uint8_t *p) {
  return little32(p) | (uint64_t(little32(p + 4)) << 32);
}
static bool context(const uint8_t *p, Context &c) {
  c = {};
  for (unsigned i = 0; i < 32; ++i) {
    cc::quad::gpr(c, i).u64 = little64(p + 8 * i);
    cc::quad::fpr(c, i).u64 = little64(p + 256 + 8 * i);
  }
  c.lr = little64(p + 512);
  c.ctr.u64 = little64(p + 520);
  if (p[528] > 1 || p[529] > 1 || p[530] > 1 || p[531])
    return false;
  c.xer = {p[528], p[529], p[530]};
  for (unsigned i = 0; i < 8; ++i) {
    if (p[532 + i] > 15)
      return false;
    cc::quad::cr(c, i).raw(p[532 + i]);
  }
  c.fpscr.csr = little32(p + 540);
  return c.r1.u64 >= 16384 && c.r1.u64 <= 0xffffff7f;
}
static FixtureError record(const uint8_t *r, size_t n, uint32_t first,
                           Case &c) {
  if (n < fixed_bytes)
    return FixtureError::size;
  c = {};
  c.record = r;
  c.entry = little32(r);
  c.regions = little32(r + 4);
  c.bytes = little32(r + 8);
  c.draws = little32(r + 12);
  c.initial_texture = little32(r + 16);
  c.counter_before = little32(r + 20);
  c.counter_after = little32(r + 24);
  c.tree_visits = little32(r + 28);
  c.dispatches = little32(r + 32);
  c.binds = little32(r + 36);
  c.first_draw = first;
  const uint32_t flags=little32(r+40);
  c.counter_observed=(flags&1u)==0;
  if ((c.entry != 0x8208a7a0 && c.entry != 0x820a8ff8 && c.entry != 0x82091248 && c.entry != 0x8209cd08 && c.entry != 0x8209df48) || (flags & ~1u) ||
      little32(r + 44))
    return FixtureError::header;
  if (!c.counter_observed && ((c.entry!=0x82091248u && c.entry!=0x8209cd08u && c.entry!=0x8209df48u) || c.draws || c.counter_before || c.counter_after)) return FixtureError::count;
  if (!c.regions || c.regions > AddressSpace::capacity || !c.bytes || c.bytes > max_scratch ||
      c.draws > 4096 || c.tree_visits > 10000 || c.dispatches > 10000 ||
      c.binds > 10000)
    return FixtureError::capacity;
  if (c.counter_before > 6000 ||
      c.counter_after != c.counter_before + 4 * c.draws ||
      c.counter_after > 6000)
    return FixtureError::count;
  if (size_t(fixed_bytes) + c.regions * 12 + size_t(c.bytes) * 3 +
          size_t(c.draws) * draw_bytes !=
      n)
    return FixtureError::size;
  if (!context(r + 48, c.initial) || !context(r + 48 + context_bytes, c.post))
    return FixtureError::context;
  uint64_t end = 0;
  uint32_t off = 0;
  for (uint32_t i = 0; i < c.regions; ++i) {
    const uint8_t *q = r + fixed_bytes + 12 * i;
    uint32_t a = little32(q), sz = little32(q + 4), o = little32(q + 8);
    if (!sz || a < end || uint64_t(a) + sz > 0x100000000ull || o != off ||
        sz > c.bytes - off)
      return FixtureError::range;
    end = uint64_t(a) + sz;
    off += sz;
  }
  if (off != c.bytes)
    return FixtureError::size;
  c.before = r + fixed_bytes + 12 * c.regions;
  c.after = c.before + c.bytes;
  c.writes = c.after + c.bytes;
  c.expected = c.writes + c.bytes;
  for (uint32_t i = 0; i < c.bytes; ++i)
    if (c.writes[i] > 1)
      return FixtureError::range;
  for (uint32_t i = 0; i < c.draws; ++i) {
    auto d = c.expected + i * draw_bytes;
    if (little32(d + 4) >= 512 || little32(d + 12))
      return FixtureError::range;
  }
  return FixtureError::ok;
}
FixtureError parse(const void *ptr, size_t n, Fixtures &out) noexcept {
  out = {};
  if (!ptr || n < 32 || n > max_file)
    return FixtureError::size;
  auto p = static_cast<const uint8_t *>(ptr);
  if (std::memcmp(p, "CCST008\0", 8) || little32(p + 8) != n ||
      little32(p + 16) != 32 || little32(p + 20) != 16)
    return FixtureError::header;
  uint32_t count = little32(p + 12), scratch = little32(p + 24),
           draws = little32(p + 28);
  if (!count || count > max_roots || !scratch || scratch > max_scratch ||
      draws > 4096 || 32 + size_t(count) * 16 > n)
    return FixtureError::count;
  uint32_t off = 32 + count * 16, nd = 0, ms = 0;
  for (uint32_t i = 0; i < count; ++i) {
    auto t = p + 32 + i * 16;
    uint32_t a = little32(t), sz = little32(t + 4), ds = little32(t + 8);
    if (a != off || ds != nd || little32(t + 12) != i || sz > n - off)
      return FixtureError::range;
    Case c;
    auto e = record(p + a, sz, ds, c);
    if (e != FixtureError::ok)
      return e;
    off += sz;
    nd += c.draws;
    if (c.bytes > ms)
      ms = c.bytes;
  }
  if (off != n || nd != draws || ms != scratch)
    return FixtureError::size;
  out = {p, n, count, draws, scratch};
  return FixtureError::ok;
}
FixtureError get(const Fixtures &f, uint32_t i, Case &c) noexcept {
  if (!f.bytes || i >= f.count || f.size < 32 + size_t(f.count) * 16)
    return FixtureError::count;
  auto p = f.bytes + 32 + i * 16;
  uint32_t a = little32(p), n = little32(p + 4);
  if (a > f.size || n > f.size - a)
    return FixtureError::range;
  return record(f.bytes + a, n, little32(p + 8), c);
}
FixtureError restore(const Fixtures &f, uint32_t i, Workspace &w,
                     Case &c) noexcept {
  auto e = get(f, i, c);
  if (e != FixtureError::ok)
    return e;
  w.ctx = c.initial;
  w.memory = AddressSpace{};
  std::memcpy(w.data, c.before, c.bytes);
  for (uint32_t j = 0; j < c.regions; ++j) {
    auto p = c.record + fixed_bytes + j * 12;
    auto a = little32(p), n = little32(p + 4), o = little32(p + 8);
    if (w.memory.map(a, n, w.data + o, 3) != cc::xbox::MemoryError::ok)
      return FixtureError::range;
  }
  return FixtureError::ok;
}
bool check_stores(const Case &c, const Workspace &w,
                  uint32_t *failed) noexcept {
  for (uint32_t i = 0; i < c.regions; ++i) {
    auto p = c.record + fixed_bytes + i * 12;
    auto a = little32(p), n = little32(p + 4), off = little32(p + 8);
    for (uint32_t j = 0; j < n; ++j)
      if (c.writes[off + j] && w.data[off + j] != c.after[off + j]) {
        if (failed)
          *failed = a + j;
        return false;
      }
  }
  return true;
}
bool callee_saved(const Case &c, const Context &x) noexcept {
  auto a = x, b = c.initial;
  if (x.r1.u64 != b.r1.u64 || x.lr != b.lr)
    return false;
  for (unsigned i = 14; i < 32; ++i)
    if (cc::quad::gpr(a, i).u64 != cc::quad::gpr(b, i).u64 ||
        cc::quad::fpr(a, i).u64 != cc::quad::fpr(b, i).u64)
      return false;
  return true;
}
} // namespace cc::tree
