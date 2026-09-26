// SPDX-License-Identifier: MIT
#include "live_frame.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <limits>
#include <vector>
using namespace cc;
static bool read(void *p, uint32_t off, void *dst, size_t n) {
  auto &b = *static_cast<std::vector<uint8_t> *>(p);
  if (uint64_t(off) + n > b.size())
    return false;
  std::memcpy(dst, b.data() + off, n);
  return true;
}
static void *allocate(void *, size_t n, bool) { return std::malloc(n); }
static void release(void *, void *p, bool) { std::free(p); }
static std::vector<uint8_t> load(const std::string &p) {
  std::ifstream f(p, std::ios::binary);
  if (!f) {
    std::fprintf(stderr, "Cannot open %s\n", p.c_str());
    std::exit(2);
  }
  return {(std::istreambuf_iterator<char>(f)), {}};
}
int main(int argc, char **argv) {
  if (argc != 3) {
    std::fprintf(
        stderr, "usage: cc_live_preview /path/to/menu-stem output-directory\n");
    return 2;
  }
  std::string stem = argv[1];
  auto blob = load(stem + ".ccr"), inputs = load(stem + ".ccp");
  caller::Fixtures f;
  stream::Scene scene;
  caller::Workspace work;
  if (caller::parse(inputs.data(), inputs.size(), f) !=
          caller::FixtureError::ok ||
      stream::load({&blob, uint32_t(blob.size()), read},
                   {nullptr, allocate, release}, scene) != stream::Error::ok)
    return 3;
  std::filesystem::create_directories(argv[2]);
  for (unsigned phase = 0; phase < 3; ++phase) {
    upstream::Controls c;
    if (phase == 1) {
      c.rotation = 0.15f;
    }
    if (phase == 2)
      c.alpha = 128;
    // Poison the entire prior/frozen geometry; a correct image requires every
    // vertex to be regenerated.
    std::memset(scene.writable_vertices(), 0xa5,
                sizeof(replay::GpuVertex) * 6 * scene.draw_count());
    std::memset(scene.writable_commands(), 0xa5,
                sizeof(stream::Command) * scene.draw_count());
    std::vector<replay::Vertex> vertices(f.draws * 4);
    auto r =
        upstream::frame(f, work, scene, c, vertices.data(), vertices.size());
    std::printf(
        "phase=%u calls=%u matches=%u raw_hash=%08x error=%u failed_call=%u "
        "quad_calls=%u culled=%u dispatches=%u binds=%u\n",
        phase, r.calls, r.baseline_matches, r.raw_hash, r.error, r.failed_call,
        r.quad_calls, r.culled, r.dispatches, r.binds);
    if (r.error)
      return 4;
    auto normalized = blob;
    replay::View v;
    if (replay::parse(normalized.data(), normalized.size(), v) !=
        replay::Error::ok)
      return 5;
    for (unsigned i = 0; i < f.draws; ++i) {
      std::memcpy(normalized.data() + v.draw_table + i * 104 + 8,
                  vertices.data() + i * 4, 96);
      const auto cmd = scene.command(i);
      std::memcpy(normalized.data() + v.draw_table + i * 104, &cmd, 8);
    }
    // Baseline transformed vertex bytes must exactly match the independent
    // Python converter.
    if (!phase && normalized != blob) {
      std::fprintf(stderr, "Baseline normalized geometry mismatch\n");
      return 6;
    }
    std::vector<uint8_t> rgba(size_t(v.width) * v.height * 4);
    if (replay::render(v, rgba.data(), rgba.size()) != replay::Error::ok)
      return 7;
    std::string out =
        std::string(argv[2]) + "/phase-" + std::to_string(phase) + ".ppm";
    FILE *img = std::fopen(out.c_str(), "wb");
    if (!img)
      return 8;
    std::fprintf(img, "P6\n%u %u\n255\n", v.width, v.height);
    for (size_t i = 0; i < rgba.size(); i += 4)
      std::fwrite(rgba.data() + i, 1, 3, img);
    std::fclose(img);
  }
  // An output oracle is checked, never used to repair an incorrect generated
  // draw.
  auto bad = inputs;
  uint32_t first_record;
  std::memcpy(&first_record, bad.data() + 32, 4);
  bad[first_record + 592] ^= 1;
  caller::Fixtures bad_view;
  if (caller::parse(bad.data(), bad.size(), bad_view) !=
      caller::FixtureError::ok)
    return 9;
  auto refused = upstream::frame(bad_view, work, scene, {});
  if (refused.error != 21 || refused.failed_call != 0 || refused.calls != 0)
    return 10;
  if (upstream::frame({}, work, scene, {}).error != 1)
    return 11;
  upstream::Controls invalid;
  invalid.rotation = std::numeric_limits<float>::quiet_NaN();
  if (upstream::frame(f, work, scene, invalid).error != 2)
    return 12;
  std::printf("PASS: corrupted output oracle refused without fallback; empty "
              "fixture and invalid controls refused\n");
  std::printf("PASS: original-routine frame regeneration, poisoned-vertex "
              "replacement, exact baseline and three previews\n");
  return 0;
}
