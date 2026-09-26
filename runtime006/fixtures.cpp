// SPDX-License-Identifier: MIT
#include "fixtures.h"
#include <cmath>
#include <cstring>
namespace cc::quad {
static uint32_t u32(const uint8_t *p) {
  uint32_t x;
  std::memcpy(&x, p, 4);
  return x;
}
static uint64_t u64(const uint8_t *p) {
  uint64_t x;
  std::memcpy(&x, p, 8);
  return x;
}
FixtureError parse(const void *ptr, size_t size, Fixtures &out) noexcept {
  out = {};
  if (!ptr || size < 32)
    return FixtureError::header;
  auto *b = static_cast<const uint8_t *>(ptr);
  if (std::memcmp(b, "CCQF006\0", 8) || u32(b + 16) != 32 ||
      u32(b + 20) != 16 || u32(b + 28))
    return FixtureError::header;
  if (size > 16 * 1024 * 1024 || u32(b + 8) != size)
    return FixtureError::size;
  uint32_t n = u32(b + 12), scratch = u32(b + 24);
  if (!n || n > max_calls || !scratch || scratch > max_scratch)
    return FixtureError::count;
  uint64_t cursor = 32 + uint64_t(n) * 16;
  if (cursor > size)
    return FixtureError::range;
  uint32_t observed = 0;
  for (uint32_t i = 0; i < n; ++i) {
    const auto *t = b + 32 + 16 * i;
    uint32_t off = u32(t), len = u32(t + 4);
    if (off != cursor || len < 720 || uint64_t(off) + len > size)
      return FixtureError::range;
    if (u32(t + 8) >= 512 ||
        (u32(t + 12) != 0x07010701 && u32(t + 12) != 0x00010001))
      return FixtureError::context;
    const auto *r = b + off;
    uint32_t nr = u32(r), nb = u32(r + 4);
    if (!nr || nr > 32 || !nb || nb > scratch || u32(r + 12))
      return FixtureError::capacity;
    if (u32(r + 8) != 0 && u32(r + 8) != 5)
      return FixtureError::context;
    if (uint64_t(720) + nr * 12 + nb != len)
      return FixtureError::size;
    observed = observed > nb ? observed : nb;
    for (unsigned k = 0; k < 3; ++k)
      if (r[16 + 528 + k] > 1)
        return FixtureError::context;
    if (r[16 + 531])
      return FixtureError::context;
    for (unsigned k = 0; k < 8; ++k)
      if (r[16 + 532 + k] > 15)
        return FixtureError::context;
    uint64_t end = 0;
    uint32_t data_end = 0;
    for (unsigned j = 0; j < nr; ++j) {
      auto *p = r + 720 + j * 12;
      uint32_t a = u32(p), bytes = u32(p + 4), offset = u32(p + 8);
      if (!bytes || uint64_t(a) < end || uint64_t(a) + bytes > 0x100000000ull ||
          offset != data_end || uint64_t(offset) + bytes > nb)
        return FixtureError::range;
      end = uint64_t(a) + bytes;
      data_end += bytes;
    }
    if (data_end != nb)
      return FixtureError::size;
    cursor += len;
  }
  if (cursor != size || observed != scratch)
    return FixtureError::size;
  out = {b, size, n, scratch};
  return FixtureError::ok;
}
FixtureError restore(const Fixtures &v, uint32_t i, Workspace &w,
                     Case &out) noexcept {
  out = {};
  if (!v.bytes || i >= v.count)
    return FixtureError::range;
  // Views are produced by parse and immutable for the duration of use.
  const auto *t = v.bytes + 32 + i * 16;
  const auto *r = v.bytes + u32(t);
  const auto *c = r + 16;
  w.memory = cc::xbox::AddressSpace{};
  w.ctx = Context{};
  for (unsigned j = 0; j < 32; ++j)
    gpr(w.ctx, j).u64 = u64(c + j * 8);
  for (unsigned j = 0; j < 32; ++j)
    fpr(w.ctx, j).u64 = u64(c + 256 + j * 8);
  w.ctx.lr = u64(c + 512);
  w.ctx.ctr.u64 = u64(c + 520);
  w.ctx.xer = {c[528], c[529], c[530]};
  for (unsigned j = 0; j < 8; ++j)
    cr(w.ctx, j).raw(c[532 + j]);
  w.ctx.fpscr.csr = u32(c + 540);
  const uint32_t nr = u32(r), nb = u32(r + 4);
  const auto *data = r + 720 + nr * 12;
  std::memcpy(w.data, data, nb);
  for (unsigned j = 0; j < nr; ++j) {
    auto *p = r + 720 + j * 12;
    if (w.memory.map(u32(p), u32(p + 4), w.data + u32(p + 8),
                     cc::xbox::read_access | cc::xbox::write_access) !=
        cc::xbox::MemoryError::ok)
      return FixtureError::range;
  }
  out.expected = r + 560;
  out.texture = u32(t + 8);
  out.blend = u32(t + 12);
  out.shader = u32(r + 8);
  for (unsigned j = 0; j < 16; ++j)
    out.projection[j] = u32(r + 656 + j * 4);
  return FixtureError::ok;
}
Error change_inputs(Workspace &w, float dx, float dy, uint8_t alpha) noexcept {
  if (!std::isfinite(dx) || !std::isfinite(dy) || std::fabs(dx) > 256 ||
      std::fabs(dy) > 256)
    return Error::context;
  auto &c = w.ctx;
  auto &m = w.memory;
  auto get = [&](uint32_t a, uint32_t &x) {
    uint64_t q;
    if (m.load_be(a, 4, q) != cc::xbox::MemoryError::ok)
      return false;
    x = uint32_t(q);
    return true;
  };
  uint32_t mode = 0, color = 0;
  if (!get(c.r1.u32 + 100, mode) || !get(c.r1.u32 + 92, color))
    return Error::memory;
  float sx = 1, sy = 1;
  if (mode != 4) {
    uint32_t rt, x_scale, y_scale;
    if (!get(c.r3.u32 + 29124, rt) || rt >= 32 ||
        !get(c.r3.u32 + 28752 + rt * 24, y_scale) ||
        !get(c.r3.u32 + 28748 + rt * 24, x_scale) || !x_scale || !y_scale)
      return Error::context;
    sx = float(x_scale);
    sy = float(y_scale);
  }
  uint32_t points[4];
  float values[4][2];
  for (unsigned i = 0; i < 4; ++i) {
    points[i] = gpr(c, i + 4).u32;
    if (m.check(points[i], 8, cc::xbox::read_access | cc::xbox::write_access) !=
        cc::xbox::MemoryError::ok)
      return Error::memory;
    for (unsigned j = 0; j < 2; ++j) {
      uint32_t u;
      get(points[i] + 4 * j, u);
      std::memcpy(&values[i][j], &u, 4);
      if (!std::isfinite(values[i][j]))
        return Error::nonfinite;
      values[i][j] += (j ? dy / sy : dx / sx);
    }
  }
  if (m.check(c.r1.u32 + 92, 4, cc::xbox::write_access) !=
      cc::xbox::MemoryError::ok)
    return Error::memory;
  for (unsigned i = 0; i < 4; ++i)
    for (unsigned j = 0; j < 2; ++j) {
      uint32_t u;
      std::memcpy(&u, &values[i][j], 4);
      m.store_be(points[i] + 4 * j, 4, u);
    }
  // Original colour is RGBA, with alpha in the low byte; premultiplication
  // stays in the game function.
  m.store_be(c.r1.u32 + 92, 4,
             (color & 0xffffff00u) |
                 ((color & 255) * uint32_t(alpha) + 127) / 255);
  return Error::ok;
}
} // namespace cc::quad
