// SPDX-License-Identifier: MIT
#include "fixtures.h"
#include <cmath>
#include <cstring>
namespace cc::caller {
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
  if (std::memcmp(b, "CCPF007\0", 8) || u32(b + 16) != 32 ||
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
  uint32_t observed = 0, draws = 0;
  for (uint32_t i = 0; i < n; ++i) {
    const auto *t = b + 32 + 16 * i;
    uint32_t off = u32(t), len = u32(t + 4);
    if (off != cursor || len < 752 || uint64_t(off) + len > size)
      return FixtureError::range;
    if (u32(t + 8) >= 512 ||
        (u32(t + 12) != 0x07010701 && u32(t + 12) != 0x00010001))
      return FixtureError::context;
    const auto *r = b + off;
    uint32_t nr = u32(r), nb = u32(r + 4);
    if (!nr || nr > 32 || !nb || nb > scratch)
      return FixtureError::capacity;
    if ((u32(r + 12) != 0x820a9068 && u32(r + 12) != 0x820855d8) ||
        u32(r + 16) > 1 || u32(r + 36) > 255 || u32(r + 44))
      return FixtureError::context;
    if (u32(r + 8) != 0 && u32(r + 8) != 5)
      return FixtureError::context;
    if (uint64_t(752) + nr * 12 + nb != len)
      return FixtureError::size;
    observed = observed > nb ? observed : nb;
    for (unsigned k = 0; k < 3; ++k)
      if (r[48 + 528 + k] > 1)
        return FixtureError::context;
    if (r[48 + 531])
      return FixtureError::context;
    for (unsigned k = 0; k < 8; ++k)
      if (r[48 + 532 + k] > 15)
        return FixtureError::context;
    uint64_t end = 0;
    uint32_t data_end = 0;
    for (unsigned j = 0; j < nr; ++j) {
      auto *p = r + 752 + j * 12;
      uint32_t a = u32(p), bytes = u32(p + 4), offset = u32(p + 8);
      if (!bytes || uint64_t(a) < end || uint64_t(a) + bytes > 0x100000000ull ||
          offset != data_end || uint64_t(offset) + bytes > nb)
        return FixtureError::range;
      end = uint64_t(a) + bytes;
      data_end += bytes;
    }
    if (data_end != nb)
      return FixtureError::size;
    draws += u32(r + 16);
    cursor += len;
  }
  if (cursor != size || observed != scratch)
    return FixtureError::size;
  out = {b, size, n, scratch, draws};
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
  const auto *c = r + 48;
  w.memory = cc::xbox::AddressSpace{};
  w.ctx = Context{};
  for (unsigned j = 0; j < 32; ++j)
    cc::quad::gpr(w.ctx, j).u64 = u64(c + j * 8);
  for (unsigned j = 0; j < 32; ++j)
    cc::quad::fpr(w.ctx, j).u64 = u64(c + 256 + j * 8);
  w.ctx.lr = u64(c + 512);
  w.ctx.ctr.u64 = u64(c + 520);
  w.ctx.xer = {c[528], c[529], c[530]};
  for (unsigned j = 0; j < 8; ++j)
    cc::quad::cr(w.ctx, j).raw(c[532 + j]);
  w.ctx.fpscr.csr = u32(c + 540);
  const uint32_t nr = u32(r), nb = u32(r + 4);
  const auto *data = r + 752 + nr * 12;
  std::memcpy(w.data, data, nb);
  for (unsigned j = 0; j < nr; ++j) {
    auto *p = r + 752 + j * 12;
    if (w.memory.map(u32(p), u32(p + 4), w.data + u32(p + 8),
                     cc::xbox::read_access | cc::xbox::write_access) !=
        cc::xbox::MemoryError::ok)
      return FixtureError::range;
  }
  out.expected = r + 592;
  out.entry = u32(r + 12);
  out.emissions = u32(r + 16);
  out.descriptor = u32(r + 20);
  out.initial_texture = u32(r + 24);
  out.returned = u64(r + 28);
  out.flags = u32(r + 36);
  out.post_counter = u32(r + 40);
  out.texture = u32(t + 8);
  out.blend = u32(t + 12);
  out.shader = u32(r + 8);
  for (unsigned j = 0; j < 16; ++j)
    out.projection[j] = u32(r + 688 + j * 4);
  return FixtureError::ok;
}

Error change_inputs(Workspace &w, const Case &c, float rotation,
                    uint8_t alpha) noexcept {
  if (!std::isfinite(rotation) || std::fabs(rotation) > 0.5f)
    return Error::context;
  if (c.entry == 0x820a9068) {
    if (!std::isfinite(w.ctx.f1.f64) || std::fabs(w.ctx.f1.f64) > 10000)
      return Error::context;
    w.ctx.f1.f64 += rotation;
    uint32_t color = w.ctx.r10.u32;
    w.ctx.r10.u32 =
        (color & 0xffffff00u) | (((color & 255) * uint32_t(alpha) + 127) / 255);
    return Error::ok;
  }
  // Colour transform entry alpha, before the original float-to-integer packer.
  if (c.entry != 0x820855d8)
    return Error::entry;
  const uint32_t state = w.ctx.r4.u32;
  uint64_t ci = 0, bits = 0;
  if (w.memory.load_be(state + 10048, 4, ci) != cc::xbox::MemoryError::ok ||
      ci >= 32)
    return Error::memory;
  const uint32_t addr = state + (uint32_t(ci) + 596) * 16 + 12;
  if (w.memory.load_be(addr, 4, bits) != cc::xbox::MemoryError::ok)
    return Error::memory;
  uint32_t u = uint32_t(bits);
  float f;
  std::memcpy(&f, &u, 4);
  if (!std::isfinite(f) || f < 0 || f > 255)
    return Error::context;
  f = float((uint32_t(f) * uint32_t(alpha) + 127) / 255);
  std::memcpy(&u, &f, 4);
  if (w.memory.store_be(addr, 4, u) != cc::xbox::MemoryError::ok)
    return Error::memory;
  return Error::ok;
}
} // namespace cc::caller
