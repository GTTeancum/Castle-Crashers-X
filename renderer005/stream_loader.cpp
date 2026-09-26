// SPDX-License-Identifier: MIT
#include "stream_loader.h"
#include <cmath>
#include <cstring>
namespace cc::stream {
namespace {
uint32_t le32(const uint8_t *p) {
  return uint32_t(p[0]) | (uint32_t(p[1]) << 8) | (uint32_t(p[2]) << 16) |
         (uint32_t(p[3]) << 24);
}
float fl32(const uint8_t *p) {
  auto x = le32(p);
  float f;
  std::memcpy(&f, &x, 4);
  return f;
}
bool read(Source s, uint32_t offset, void *out, size_t n) {
  return s.read && out && uint64_t(offset) + n <= s.length &&
         s.read(s.context, offset, out, n);
}
struct Plan {
  uint32_t width, height, offset, pitch;
};
Error decode(const uint8_t *b, uint32_t textures, cc::replay::Draw &d) {
  d.texture = le32(b);
  d.blend = le32(b + 4);
  if (d.texture >= textures)
    return Error::draw;
  if (d.blend != 0x07010701 && d.blend != 0x00010001)
    return Error::blend;
  b += 8;
  for (auto &v : d.vertices) {
    v = {fl32(b),      fl32(b + 4),  fl32(b + 8),
         fl32(b + 12), fl32(b + 16), le32(b + 20)};
    b += 24;
    if (!std::isfinite(v.x) || !std::isfinite(v.y) || !std::isfinite(v.z) ||
        !std::isfinite(v.u) || !std::isfinite(v.v) || std::fabs(v.x) > 1e6f ||
        std::fabs(v.y) > 1e6f || std::fabs(v.u) > 32 || std::fabs(v.v) > 32)
      return Error::nonfinite;
  }
  return Error::ok;
}
void vertices(const cc::replay::Draw &d, const Plan &t, GpuVertex *out) {
  const unsigned ix[6] = {0, 1, 2, 0, 2, 3};
  for (unsigned i = 0; i < 6; ++i) {
    const auto &p = d.vertices[ix[i]];
    auto &o = out[i];
    o.position[0] = p.x;
    o.position[1] = p.y;
    o.position[2] = 0;
    o.position[3] = 1;
    o.color[0] = float((p.argb >> 16) & 255) / 255.f;
    o.color[1] = float((p.argb >> 8) & 255) / 255.f;
    o.color[2] = float(p.argb & 255) / 255.f;
    o.color[3] = float(p.argb >> 24) / 255.f;
    o.uv[0] = p.u * float(t.width);
    o.uv[1] = p.v * float(t.height);
  }
}
} // namespace
void Scene::reset() noexcept {
  if (memory_.release) {
    if (vertices_)
      memory_.release(memory_.context, vertices_, true);
    if (commands_)
      memory_.release(memory_.context, commands_, false);
    for (uint32_t i = 0; i < nt_; ++i)
      if (textures_[i].data)
        memory_.release(memory_.context, textures_[i].data, true);
  }
  for (uint32_t i = 0; i < nt_; ++i)
    textures_[i] = {};
  memory_ = {};
  vertices_ = nullptr;
  commands_ = nullptr;
  width_ = height_ = nt_ = nd_ = gpu_bytes_ = 0;
}
const char *name(Error e) noexcept {
  switch (e) {
#define E(x)                                                                   \
  case Error::x:                                                               \
    return #x
    E(ok);
    E(busy);
    E(header);
    E(size);
    E(counts);
    E(range);
    E(texture);
    E(draw);
    E(blend);
    E(nonfinite);
    E(read);
    E(allocator);
    E(budget);
    E(allocation);
#undef E
  }
  return "unknown";
}
Error load(Source s, Memory m, Scene &out, uint32_t budget) noexcept {
  if (out.nt_ || out.nd_ || out.vertices_ || out.commands_)
    return Error::busy;
  if (!s.read || s.length < 36)
    return Error::header;
  if (s.length > cc::replay::max_bytes)
    return Error::size;
  if (!m.allocate || !m.release)
    return Error::allocator;
  uint8_t header[36];
  if (!read(s, 0, header, sizeof header))
    return Error::read;
  if (std::memcmp(header, "CCRP004\0", 8))
    return Error::header;
  if (le32(header + 32) != s.length)
    return Error::size;
  const uint32_t w = le32(header + 8), h = le32(header + 12),
                 nt = le32(header + 16), nd = le32(header + 20),
                 tt = le32(header + 24), dt = le32(header + 28);
  if (!w || !h || w > 1920 || h > 1080 || !nt ||
      nt > cc::replay::max_textures || !nd || nd > cc::replay::max_draws)
    return Error::counts;
  uint32_t cursor = 36 + nt * 16 + nd * 104;
  if (tt != 36 || dt != 36 + nt * 16 || cursor > s.length)
    return Error::range;
  Plan plan[cc::replay::max_textures];
  uint64_t gpu = uint64_t(nd) * 6 * sizeof(GpuVertex);
  for (uint32_t i = 0; i < nt; ++i) {
    uint8_t b[16];
    if (!read(s, tt + i * 16, b, 16))
      return Error::read;
    const uint32_t tw = le32(b), th = le32(b + 4), offset = le32(b + 8),
                   n = le32(b + 12);
    if (!tw || !th || tw > 2048 || th > 2048 || (tw & (tw - 1)) ||
        (th & (th - 1)) || n != tw * th * 4)
      return Error::texture;
    if (offset != cursor || uint64_t(offset) + n > s.length)
      return Error::range;
    cursor += n;
    const uint32_t pitch = (tw * 4 + 63) & ~63u;
    gpu += uint64_t(pitch) * th;
    plan[i] = {tw, th, offset, pitch};
  }
  if (cursor != s.length)
    return Error::size;
  if (gpu > budget)
    return Error::budget;
  for (uint32_t i = 0; i < nd; ++i) {
    uint8_t b[104];
    if (!read(s, dt + i * 104, b, 104))
      return Error::read;
    cc::replay::Draw d;
    const auto e = decode(b, nt, d);
    if (e != Error::ok)
      return e;
  }
  out.memory_ = m;
  out.width_ = w;
  out.height_ = h;
  out.nt_ = nt;
  out.nd_ = nd;
  out.gpu_bytes_ = uint32_t(gpu);
  const auto fail = [&](Error e) {
    out.reset();
    return e;
  };
  out.vertices_ = static_cast<GpuVertex *>(
      m.allocate(m.context, size_t(nd) * 6 * sizeof(GpuVertex), true));
  if (!out.vertices_)
    return fail(Error::allocation);
  out.commands_ = static_cast<Command *>(
      m.allocate(m.context, size_t(nd) * sizeof(Command), false));
  if (!out.commands_)
    return fail(Error::allocation);
  uint8_t row[2048 * 4]; // Cached scratch avoids reading back write-combined
                         // GPU memory.
  for (uint32_t i = 0; i < nt; ++i) {
    const auto &t = plan[i];
    auto &g = out.textures_[i];
    g.width = t.width;
    g.height = t.height;
    g.pitch = t.pitch;
    g.data = m.allocate(m.context, size_t(t.pitch) * t.height, true);
    if (!g.data)
      return fail(Error::allocation);
    for (uint32_t y = 0; y < t.height; ++y) {
      if (!read(s, t.offset + y * t.width * 4, row, size_t(t.width) * 4))
        return fail(Error::read);
      for (uint32_t x = 0; x < t.width; ++x) {
        const auto r = row[x * 4];
        row[x * 4] = row[x * 4 + 2];
        row[x * 4 + 2] = r;
      }
      std::memset(row + t.width * 4, 0, t.pitch - t.width * 4);
      std::memcpy(static_cast<uint8_t *>(g.data) + size_t(y) * t.pitch, row,
                  t.pitch);
    }
  }
  for (uint32_t i = 0; i < nd; ++i) {
    uint8_t b[104];
    if (!read(s, dt + i * 104, b, 104))
      return fail(Error::read);
    cc::replay::Draw d;
    const auto e = decode(b, nt, d);
    if (e != Error::ok)
      return fail(e);
    out.commands_[i] = {d.texture, d.blend};
    vertices(d, plan[d.texture], out.vertices_ + i * 6);
  }
  return Error::ok;
}
} // namespace cc::stream
