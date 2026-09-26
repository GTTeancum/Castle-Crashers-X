// SPDX-License-Identifier: MIT
#include "live_frame.h"
#include <cmath>
#include <cstring>
namespace cc::live {
static uint32_t be32(const uint8_t *p) {
  return uint32_t(p[0]) << 24 | uint32_t(p[1]) << 16 | uint32_t(p[2]) << 8 |
         p[3];
}
static float number(uint32_t u) {
  float f;
  std::memcpy(&f, &u, 4);
  return f;
}
struct Submission {
  cc::stream::Scene *scene;
  uint32_t index;
  cc::quad::Case original;
  Result *result;
  bool baseline;
  cc::replay::Vertex *norm;
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
  const auto &t = s.scene->texture(s.original.texture);
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
Result frame(const cc::quad::Fixtures &fixtures, cc::quad::Workspace &work,
             cc::stream::Scene &scene, Controls controls,
             cc::replay::Vertex *norm, size_t norm_count) noexcept {
  Result result;
  if (!fixtures.bytes || fixtures.count != scene.draw_count() ||
      !scene.writable_vertices() ||
      (norm && norm_count != size_t(fixtures.count) * 4) ||
      (!norm && norm_count)) {
    result.error = 1;
    return result;
  }
  if (!std::isfinite(controls.dx) || !std::isfinite(controls.dy) ||
      std::fabs(controls.dx) > 256 || std::fabs(controls.dy) > 256) {
    result.error = 2;
    return result;
  }
  const bool baseline =
      controls.dx == 0 && controls.dy == 0 && controls.alpha == 255;
  for (uint32_t i = 0; i < fixtures.count; ++i) {
    result.failed_call = i;
    cc::quad::Case c;
    if (cc::quad::restore(fixtures, i, work, c) != cc::quad::FixtureError::ok) {
      result.error = 3;
      return result;
    }
    const auto &cmd = scene.command(i);
    if (c.texture >= scene.texture_count() || cmd.texture != c.texture ||
        cmd.blend != c.blend) {
      result.error = 4;
      return result;
    }
    if (!baseline) {
      auto err = cc::quad::change_inputs(work, controls.dx, controls.dy,
                                         controls.alpha);
      if (err != cc::quad::Error::ok) {
        result.error = 100 + uint32_t(err);
        return result;
      }
    }
    Submission sink{&scene, i, c, &result, baseline, norm};
    unsigned emitted = 0;
    auto err = cc::quad::invoke(0x820a9308u, work.ctx, work.memory,
                                {&sink, submit}, &emitted);
    if (err != cc::quad::Error::ok || emitted != 1) {
      if (!result.error)
        result.error = 200 + uint32_t(err);
      return result;
    }
    ++result.calls;
  }
  result.failed_call = 0xffffffffu;
  return result;
}
} // namespace cc::live
