// SPDX-License-Identifier: MIT
#include "stream_loader.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <unordered_map>
#include <vector>
static size_t checks = 0;
#define CHECK(x)                                                               \
  do {                                                                         \
    ++checks;                                                                  \
    if (!(x)) {                                                                \
      std::fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #x);        \
      std::abort();                                                            \
    }                                                                          \
  } while (0)
namespace {
using namespace cc::stream;
struct Tracked {
  std::unordered_map<void *, std::pair<size_t, bool>> live;
  size_t bytes = 0, peak = 0, calls = 0, fail_at = 0;
  static void *allocate(void *ctx, size_t n, bool gpu) {
    auto &m = *static_cast<Tracked *>(ctx);
    if (++m.calls == m.fail_at)
      return nullptr;
    void *p = std::malloc(n);
    CHECK(p);
    m.live[p] = {n, gpu};
    m.bytes += n;
    m.peak = std::max(m.peak, m.bytes);
    std::memset(p, 0xa5, n);
    return p;
  }
  static void release(void *ctx, void *p, bool gpu) {
    auto &m = *static_cast<Tracked *>(ctx);
    auto i = m.live.find(p);
    CHECK(i != m.live.end());
    CHECK(i->second.second == gpu);
    m.bytes -= i->second.first;
    std::free(p);
    m.live.erase(i);
  }
  Memory api() { return {this, allocate, release}; }
  ~Tracked() { CHECK(live.empty()); }
};
struct Input {
  const std::vector<uint8_t> &b;
  size_t reads = 0, fail_at = 0;
  static bool read(void *ctx, uint32_t off, void *out, size_t n) {
    auto &r = *static_cast<Input *>(ctx);
    CHECK(uint64_t(off) + n <= r.b.size());
    if (++r.reads == r.fail_at)
      return false;
    std::memcpy(out, r.b.data() + off, n);
    return true;
  }
  Source api() { return {this, uint32_t(b.size()), read}; }
};
void u32(std::vector<uint8_t> &b, size_t p, uint32_t x) {
  for (int i = 0; i < 4; ++i)
    b[p + size_t(i)] = uint8_t(x >> (i * 8));
}
void f32(std::vector<uint8_t> &b, size_t p, float x) {
  uint32_t t;
  std::memcpy(&t, &x, 4);
  u32(b, p, t);
}
std::vector<uint8_t> fixture() {
  const uint32_t nt = 2, nd = 3, dt = 36 + nt * 16, start = dt + nd * 104;
  std::vector<uint8_t> b(start + 4 * 2 * 4 + 8 * 4 * 4, 0);
  std::memcpy(b.data(), "CCRP004\0", 8);
  u32(b, 8, 32);
  u32(b, 12, 32);
  u32(b, 16, nt);
  u32(b, 20, nd);
  u32(b, 24, 36);
  u32(b, 28, dt);
  u32(b, 32, uint32_t(b.size()));
  u32(b, 36, 4);
  u32(b, 40, 2);
  u32(b, 44, start);
  u32(b, 48, 32);
  u32(b, 52, 8);
  u32(b, 56, 4);
  u32(b, 60, start + 32);
  u32(b, 64, 128);
  for (uint32_t i = 0; i < nd; ++i) {
    auto p = dt + i * 104;
    u32(b, p, i % 2);
    u32(b, p + 4, i % 2 ? 0x00010001 : 0x07010701);
    p += 8;
    for (uint32_t j = 0; j < 4; ++j) {
      f32(b, p, float((j == 1 || j == 2) ? 24 : 4));
      f32(b, p + 4, float(j >= 2 ? 24 : 4));
      f32(b, p + 8, .3f);
      f32(b, p + 12, float(j == 1 || j == 2));
      f32(b, p + 16, float(j >= 2));
      u32(b, p + 20, 0xCC1155AAu + i + j);
      p += 24;
    }
  }
  for (size_t i = start; i < b.size(); ++i)
    b[i] = uint8_t(i * 37u);
  return b;
}
void equivalent(const std::vector<uint8_t> &b) {
  cc::replay::View v;
  CHECK(cc::replay::parse(b.data(), b.size(), v) == cc::replay::Error::ok);
  Tracked m;
  Input in{b};
  Scene scene;
  CHECK(load(in.api(), m.api(), scene) == Error::ok);
  CHECK(scene.width() == v.width);
  CHECK(scene.height() == v.height);
  CHECK(scene.texture_count() == v.textures);
  CHECK(scene.draw_count() == v.draws);
  for (uint32_t i = 0; i < v.textures; ++i) {
    auto t = cc::replay::texture(v, i);
    const auto &g = scene.texture(i);
    CHECK(g.width == t.width && g.height == t.height);
    CHECK(g.pitch == cc::replay::gpu_pitch(t));
    std::vector<uint8_t> expected(size_t(g.pitch) * g.height);
    CHECK(cc::replay::bgra_texture(t, expected.data(), expected.size()));
    CHECK(!std::memcmp(g.data, expected.data(), expected.size()));
  }
  for (uint32_t i = 0; i < v.draws; ++i) {
    const auto d = cc::replay::draw(v, i);
    const auto &c = scene.command(i);
    CHECK(c.texture == d.texture && c.blend == d.blend);
    cc::replay::GpuVertex expected[6];
    CHECK(cc::replay::gpu_vertices(v, i, expected, 6));
    CHECK(!std::memcmp(scene.vertices() + 6 * i, expected, sizeof expected));
  }
  CHECK(m.peak == size_t(scene.gpu_bytes()) + scene.command_bytes());
  CHECK(load(in.api(), m.api(), scene) == Error::busy);
  CHECK(scene.draw_count() == v.draws);
  std::printf(
      "EQUIVALENT %ux%u draws=%u textures=%u final_gpu_bytes=%u "
      "command_bytes=%u peak_requested=%zu source_bytes=%zu reads=%zu\n",
      v.width, v.height, v.draws, v.textures, scene.gpu_bytes(),
      scene.command_bytes(), m.peak, b.size(), in.reads);
  scene.reset();
  CHECK(m.bytes == 0 && m.live.empty());
  scene.reset();
  CHECK(m.bytes == 0);
}
void unit() {
  auto b = fixture();
  equivalent(b);
  size_t reads = 0, allocations = 0;
  {
    Tracked m;
    Input in{b};
    Scene s;
    CHECK(load(in.api(), m.api(), s) == Error::ok);
    reads = in.reads;
    allocations = m.calls;
  }
  for (size_t i = 1; i <= reads; ++i) {
    Tracked m;
    Input in{b, 0, i};
    Scene s;
    CHECK(load(in.api(), m.api(), s) == Error::read);
    CHECK(!s.draw_count() && !s.vertices());
    CHECK(m.live.empty() && m.bytes == 0);
  }
  for (size_t i = 1; i <= allocations; ++i) {
    Tracked m;
    m.fail_at = i;
    Input in{b};
    Scene s;
    CHECK(load(in.api(), m.api(), s) == Error::allocation);
    CHECK(!s.draw_count() && !s.vertices());
    CHECK(m.live.empty() && m.bytes == 0);
  }
  {
    Tracked m;
    Input in{b};
    Scene s;
    CHECK(load(in.api(), m.api(), s, 1) == Error::budget);
    CHECK(m.calls == 0);
    CHECK(load(in.api(), Memory{}, s) == Error::allocator);
    CHECK(load(Source{}, m.api(), s) == Error::header);
  }
  for (size_t n = 0; n < b.size(); ++n) {
    std::vector<uint8_t> q(b.begin(), b.begin() + n);
    Tracked m;
    Input in{q};
    Scene s;
    CHECK(load(in.api(), m.api(), s) != Error::ok);
    CHECK(m.calls == 0);
  }
  uint32_t rng = 0x005CA57u;
  size_t accepted = 0;
  for (unsigned i = 0; i < 2000; ++i) {
    auto q = b;
    rng = rng * 1664525 + 1013904223;
    size_t pos = rng % q.size();
    rng = rng * 1664525 + 1013904223;
    q[pos] ^= uint8_t((rng >> 24) | 1);
    cc::replay::View v;
    auto ref = cc::replay::parse(q.data(), q.size(), v);
    Tracked m;
    Input in{q};
    Scene s;
    auto e = load(in.api(), m.api(), s);
    CHECK((e == Error::ok) == (ref == cc::replay::Error::ok));
    if (e == Error::ok)
      ++accepted;
  }
  std::printf("Failure injection: %zu read sites, %zu allocation sites; 2000 "
              "mutations (%zu valid).\n",
              reads, allocations, accepted);
}
} // namespace
int main(int argc, char **argv) {
  unit();
  for (int i = 1; i < argc; ++i) {
    std::ifstream f(argv[i], std::ios::binary);
    CHECK(bool(f));
    std::vector<uint8_t> b((std::istreambuf_iterator<char>(f)), {});
    CHECK(!b.empty());
    equivalent(b);
  }
  std::printf("PASS: %zu assertions. Host validation, not target execution.\n",
              checks);
}
