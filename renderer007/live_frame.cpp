// SPDX-License-Identifier: MIT
#include "live_frame.h"
#include <cmath>
#include <cstring>
namespace cc::upstream {
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
  cc::caller::Case original;
  Result *result;
  bool baseline;
  cc::replay::Vertex *norm;
  const Registry *registry;
  uint32_t active_texture;
};
static bool submit(void *ptr, const cc::quad::Draw &d) {
  auto &s = *static_cast<Submission *>(ptr);
  auto &r = *s.result;
  if (d.primitive != 13 || d.count != 4 || d.stride != 24 ||
      d.blend != s.original.blend ||
      std::memcmp(d.projection, s.original.projection, 64)) {
    r.error = 20;
    return false;
  }
  if (s.baseline) {
    if (std::memcmp(d.vertices, s.original.expected, 96)) {
      r.error = 21;
      return false;
    }
    ++r.baseline_matches;
  }
  for (auto b : d.vertices)
    r.raw_hash = (r.raw_hash ^ b) * 16777619u;
  if (s.active_texture >= s.scene->texture_count() ||
      s.active_texture != s.original.texture) {
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
Result frame(const cc::caller::Fixtures &fixtures, cc::caller::Workspace &work,
             cc::stream::Scene &scene, Controls controls,
             cc::replay::Vertex *norm, size_t norm_count) noexcept {
  Result result;
  if (!fixtures.bytes || fixtures.draws != scene.draw_count() ||
      !scene.writable_vertices() ||
      (norm && norm_count != size_t(fixtures.draws) * 4) ||
      (!norm && norm_count)) {
    result.error = 1;
    return result;
  }
  if (!std::isfinite(controls.rotation) ||
      std::fabs(controls.rotation) > 0.5f) {
    result.error = 2;
    return result;
  }
  const bool baseline = controls.rotation == 0 && controls.alpha == 255;
  Registry registry;
  // Build a descriptor -> native resource registry, not a frozen command list.
  // This slice rejects multiple texture versions under one descriptor in a
  // frame.
  for (uint32_t i = 0; i < fixtures.count; ++i) {
    cc::caller::Case c;
    if (cc::caller::restore(fixtures, i, work, c) !=
        cc::caller::FixtureError::ok) {
      result.error = 3;
      return result;
    }
    if (c.emissions && (c.texture >= scene.texture_count() ||
                        !registry.add(c.descriptor, c.texture))) {
      result.error = 5;
      return result;
    }
  }
  uint32_t emitted = 0;
  for (uint32_t i = 0; i < fixtures.count; ++i) {
    result.failed_call = i;
    cc::caller::Case c;
    if (cc::caller::restore(fixtures, i, work, c) !=
        cc::caller::FixtureError::ok) {
      result.error = 3;
      return result;
    }
    const uint32_t sprite = work.ctx.r3.u32;
    if (c.emissions) {
      if (emitted >= scene.draw_count() || c.texture >= scene.texture_count()) {
        result.error = 4;
        return result;
      }
    }
    if (!baseline) {
      auto e =
          cc::caller::change_inputs(work, c, controls.rotation, controls.alpha);
      if (e != cc::caller::Error::ok) {
        result.error = 100 + uint32_t(e);
        return result;
      }
    }
    Submission sink{&scene,
                    emitted,
                    c,
                    &result,
                    baseline,
                    norm,
                    &registry,
                    c.entry == 0x820a9068 ? registry.lookup(c.initial_texture)
                                          : 0xffffffffu};
    const auto r = cc::caller::invoke(c.entry, work.ctx, work.memory,
                                      {&sink, bind_texture, submit});
    if (r.error != cc::caller::Error::ok || r.submits != c.emissions) {
      if (!result.error)
        result.error = 200 + uint32_t(r.error);
      return result;
    }
    uint64_t counter = 0, flag = 0;
    if (work.memory.load_be(0x8228a7c4, 4, counter) !=
            cc::xbox::MemoryError::ok ||
        counter != c.post_counter) {
      result.error = 30;
      return result;
    }
    if (c.entry == 0x820855d8 && (work.ctx.r3.u64 != c.returned ||
                                  work.memory.load_be(sprite + 86, 1, flag) !=
                                      cc::xbox::MemoryError::ok ||
                                  flag != c.flags)) {
      result.error = 31;
      return result;
    }
    emitted += r.submits;
    ++result.calls;
    result.quad_calls += r.quad_calls;
    result.culled += !r.submits;
    result.dispatches += r.dispatches;
    result.binds += r.bind_calls;
  }
  if (emitted != scene.draw_count()) {
    result.error = 32;
    return result;
  }
  result.failed_call = 0xffffffffu;
  return result;
}
} // namespace cc::upstream
