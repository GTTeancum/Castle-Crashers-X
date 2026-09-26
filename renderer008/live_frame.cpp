// SPDX-License-Identifier: MIT
#include "live_frame.h"
#include <cmath>
#include <cstring>
namespace cc::scene008 {
static uint32_t be32(const uint8_t *p) {
  return uint32_t(p[0]) << 24 | uint32_t(p[1]) << 16 | uint32_t(p[2]) << 8 |
         p[3];
}
static float number(uint32_t u) {
  float f;
  std::memcpy(&f, &u, 4);
  return f;
}
struct Registry {
  uint32_t descriptors[512]{}, ids[512]{}, count{};
  bool add(uint32_t d, uint32_t id) {
    for (uint32_t i = 0; i < count; ++i)
      if (descriptors[i] == d)
        return ids[i] == id;
    if (count == 512)
      return false;
    descriptors[count] = d;
    ids[count++] = id;
    return true;
  }
  uint32_t lookup(uint32_t d) const {
    for (uint32_t i = 0; i < count; ++i)
      if (descriptors[i] == d)
        return ids[i];
    return 0xffffffffu;
  }
};
struct Submission {
  cc::stream::Scene *scene;
  uint32_t index;
  cc::tree::Case original;
  Result *result;
  bool baseline;
  cc::replay::Vertex *norm;
  const Registry *registry;
  uint32_t active_texture;
  uint32_t within = 0;
};
static bool submit(void *ptr, const cc::quad::Draw &d) {
  auto &s = *static_cast<Submission *>(ptr);
  auto &r = *s.result;
  if (s.within >= s.original.draws || s.index >= s.scene->draw_count()) {
    r.error = 20;
    return false;
  }
  const auto *e = s.original.expected + s.within * cc::tree::draw_bytes;
  const auto tex = cc::tree::little32(e + 4), blend = cc::tree::little32(e + 8);
  if (d.primitive != 13 || d.count != 4 || d.stride != 24 || d.blend != blend) {
    r.error = 20;
    return false;
  }
  for (unsigned i = 0; i < 16; ++i)
    if (d.projection[i] != cc::tree::little32(e + 16 + i * 4)) {
      r.error = 20;
      return false;
    }
  if (s.baseline) {
    if (std::memcmp(d.vertices, e + 80, 96)) {
      r.error = 21;
      return false;
    }
    ++r.matches;
  }
  for (auto b : d.vertices)
    r.raw_hash = (r.raw_hash ^ b) * 16777619u;
  if (s.active_texture >= s.scene->texture_count() || s.active_texture != tex) {
    r.error = 26;
    return false;
  }
  s.scene->writable_commands()[s.index] = {s.active_texture, d.blend};
  const auto &t = s.scene->texture(s.active_texture);
  cc::replay::Vertex v[4];
  for (unsigned i = 0; i < 4; ++i) {
    const auto *b = d.vertices + i * 24;
    double p[4] = {number(be32(b)), number(be32(b + 4)), number(be32(b + 8)),
                   1},
           q[4]{};
    for (unsigned j = 0; j < 4; ++j)
      for (unsigned k = 0; k < 4; ++k)
        q[j] += p[k] * number(d.projection[k * 4 + j]);
    float u = number(be32(b + 12)), vv = number(be32(b + 16));
    if (!std::isfinite(q[0]) || !std::isfinite(q[1]) || !std::isfinite(q[2]) ||
        !std::isfinite(q[3]) || std::fabs(q[3] - 1) > 1e-6 ||
        !std::isfinite(u) || !std::isfinite(vv) || std::fabs(u) > 32 ||
        std::fabs(vv) > 32) {
      r.error = 22;
      return false;
    }
    v[i] = {float((q[0] + 1) * s.scene->width() * .5),
            float((1 - q[1]) * s.scene->height() * .5),
            float(q[2]),
            u,
            vv,
            be32(b + 20)};
    if (std::fabs(v[i].x) > 1e6 || std::fabs(v[i].y) > 1e6) {
      r.error = 23;
      return false;
    }
  }
  cc::replay::GpuVertex gpu[6];
  constexpr unsigned ix[6] = {0, 1, 2, 0, 2, 3};
  for (unsigned i = 0; i < 6; ++i) {
    const auto &a = v[ix[i]];
    auto &o = gpu[i];
    o.position[0] = a.x;
    o.position[1] = a.y;
    o.position[2] = 0;
    o.position[3] = 1;
    o.color[0] = float((a.argb >> 16) & 255) / 255.f;
    o.color[1] = float((a.argb >> 8) & 255) / 255.f;
    o.color[2] = float(a.argb & 255) / 255.f;
    o.color[3] = float(a.argb >> 24) / 255.f;
    o.uv[0] = a.u * t.width;
    o.uv[1] = a.v * t.height;
  }
  // One-way cached-to-write-combined write; never sample the old/frozen vertex
  // buffer.
  std::memcpy(s.scene->writable_vertices() + 6 * s.index, gpu, sizeof(gpu));
  if (s.norm)
    std::memcpy(s.norm + 4 * s.index, v, sizeof(v));
  ++s.index;
  ++s.within;
  return true;
}

static bool bind_texture(void *ptr, uint32_t descriptor,
                         const uint32_t words[20]) {
  auto &s = *static_cast<Submission *>(ptr);
  s.active_texture = s.registry->lookup(descriptor);
  if (s.active_texture >= s.scene->texture_count()) {
    s.result->error = 24;
    return false;
  }
  // The descriptor is resolved to a pre-uploaded native resource. Reject wrong
  // dimensions; no 360 GPU header or texture-cache operation is emulated here.
  uint32_t width = 1, height = 1;
  while (width < words[4])
    width *= 2;
  while (height < words[5])
    height *= 2;
  const auto &tex = s.scene->texture(s.active_texture);
  if (tex.width != width || tex.height != height) {
    s.result->error = 25;
    return false;
  }
  return true;
}
Result frame(const cc::tree::Fixtures &f, cc::tree::Workspace &scratch,
             cc::stream::Scene &scene, Resident &resident, bool hide,
             cc::replay::Vertex *norm, size_t norm_count) noexcept {
  Result result;
  if (!f.bytes || f.draws != scene.draw_count() || !scene.writable_vertices() ||
      (norm && norm_count != size_t(f.draws) * 4) || (!norm && norm_count)) {
    result.error = 1;
    return result;
  }
  Registry registry;
  for (uint32_t i = 0; i < f.count; ++i) {
    cc::tree::Case c;
    if (cc::tree::get(f, i, c) != cc::tree::FixtureError::ok) {
      result.error = 3;
      return result;
    }
    for (uint32_t j = 0; j < c.draws; ++j) {
      auto e = c.expected + j * cc::tree::draw_bytes;
      auto id = cc::tree::little32(e + 4);
      if (id >= scene.texture_count() ||
          !registry.add(cc::tree::little32(e), id)) {
        result.error = 5;
        return result;
      }
    }
  }
  if (!resident.ready) {
    if (cc::tree::restore(f, 0, resident.work, resident.root) !=
            cc::tree::FixtureError::ok ||
        resident.root.entry != 0x8208a7a0) {
      result.error = 6;
      return result;
    }
    uint64_t v = 0;
    if (resident.work.memory.load_be(resident.root.initial.r3.u32 + 104, 4,
                                     v) != cc::xbox::MemoryError::ok ||
        !v) {
      result.error = 7;
      return result;
    }
    resident.child_head = uint32_t(v);
    resident.ready = true;
    resident.fixture_source = f.bytes;
    resident.fixture_size = f.size;
    ++resident.restores;
  }
  if (resident.fixture_source != f.bytes || resident.fixture_size != f.size) {
    result.error = 8;
    return result;
  }
  if (hide != resident.hidden) {
    if (resident.work.memory.store_be(resident.root.initial.r3.u32 + 104, 4,
                                      hide ? 0 : resident.child_head) !=
        cc::xbox::MemoryError::ok) {
      result.error = 9;
      return result;
    }
    resident.hidden = hide;
  }
  for (uint32_t i = 0; i < f.count; ++i) {
    result.failed_root = i;
    cc::tree::Case c;
    auto *w = &scratch;
    if (i == 0) {
      w = &resident.work;
      c = resident.root;
      w->ctx = c.initial;
      if (w->memory.store_be(0x8228a7c4, 4, c.counter_before) !=
          cc::xbox::MemoryError::ok) {
        result.error = 10;
        return result;
      }
      if (hide)
        c.draws = 0;
    } else if (cc::tree::restore(f, i, *w, c) != cc::tree::FixtureError::ok) {
      result.error = 3;
      return result;
    }
    Submission sink{
        &scene, result.draws, c,         &result,
        true,   norm,         &registry, registry.lookup(c.initial_texture)};
    auto r = cc::tree::invoke(c.entry, w->ctx, w->memory,
                              {&sink, bind_texture, submit});
    if (r.error != cc::tree::Error::ok || r.submits != c.draws ||
        sink.within != c.draws) {
      if (!result.error)
        result.error = 200 + uint32_t(r.error);
      result.address = r.address;
      result.quad_error = r.quad_error;
      return result;
    }
    if (!cc::tree::callee_saved(c, w->ctx)) {
      result.error = 30;
      return result;
    }
    uint64_t counter = 0;
    if (w->memory.load_be(0x8228a7c4, 4, counter) !=
            cc::xbox::MemoryError::ok ||
        counter != c.counter_before + 4 * c.draws) {
      result.error = 31;
      return result;
    }
    if (!(i == 0 && hide)) {
      if (!cc::tree::check_stores(c, *w, &result.address)) {
        result.error = 32;
        return result;
      }
      for (uint32_t j = 0; j < c.bytes; ++j)
        result.checked_writes += c.writes[j];
    } else if (r.tree_visits != 1) {
      result.error = 33;
      return result;
    }
    ++result.roots;
    result.draws += r.submits;
    result.visits += r.tree_visits;
    result.dispatches += r.dispatches;
    result.binds += r.bind_calls;
  }
  if (result.draws != f.draws - (hide ? resident.root.draws : 0)) {
    result.error = 34;
    return result;
  }
  ++resident.frames;
  result.resident_frames = resident.frames;
  result.resident_restores = resident.restores;
  result.failed_root = 0xffffffffu;
  return result;
}
} // namespace cc::scene008
