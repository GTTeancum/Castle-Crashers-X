// SPDX-License-Identifier: MIT
#include "live_frame.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <limits>
#include <memory>
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
  auto blob = load(stem + ".ccr"), inputs = load(stem + ".cct");
  tree::Fixtures f;
  stream::Scene scene;
  auto work = std::make_unique<tree::Workspace>();
  auto resident = std::make_unique<scene008::Resident>();
  if (tree::parse(inputs.data(), inputs.size(), f) != tree::FixtureError::ok ||
      stream::load({&blob, uint32_t(blob.size()), read},
                   {nullptr, allocate, release}, scene) != stream::Error::ok)
    return 3;
  std::filesystem::create_directories(argv[2]);
  for (unsigned phase = 0; phase < 4; ++phase) {
    bool hide = phase == 2;
    // Poison the entire prior/frozen geometry; a correct image requires every
    // vertex to be regenerated.
    std::memset(scene.writable_vertices(), 0xa5,
                sizeof(replay::GpuVertex) * 6 * scene.draw_count());
    std::memset(scene.writable_commands(), 0xa5,
                sizeof(stream::Command) * scene.draw_count());
    std::vector<replay::Vertex> vertices(f.draws * 4);
    auto r = scene008::frame(f, *work, scene, *resident, hide, vertices.data(),
                             vertices.size());
    std::printf(
        "phase=%u roots=%u draws=%u visits=%u matches=%u hash=%08x error=%u "
        "root=%u addr=%08x quad=%u resident_frames=%u restores=%u\n",
        phase, r.roots, r.draws, r.visits, r.matches, r.raw_hash, r.error,
        r.failed_root, r.address, r.quad_error, r.resident_frames,
        r.resident_restores);
    if (r.error)
      return 4;
    auto normalized = blob;
    replay::View v;
    if (replay::parse(normalized.data(), normalized.size(), v) !=
        replay::Error::ok)
      return 5;
    for (unsigned i = 0; i < r.draws; ++i) {
      std::memcpy(normalized.data() + v.draw_table + i * 104 + 8,
                  vertices.data() + i * 4, 96);
      const auto cmd = scene.command(i);
      std::memcpy(normalized.data() + v.draw_table + i * 104, &cmd, 8);
    }
    // Baseline transformed vertex bytes must exactly match the independent
    // Python converter.
    if (!hide && normalized != blob) {
      std::fprintf(stderr, "Baseline normalized geometry mismatch\n");
      return 6;
    }
    v.draws = r.draws; // Bounded prefix of the validated, regenerated command
                       // storage.
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
  if (resident->restores != 1 || resident->frames != 4 || resident->hidden)
    return 9;
  // A resident object must not be silently reused with another input owner.
  auto other = inputs;
  tree::Fixtures other_fixture;
  if (tree::parse(other.data(), other.size(), other_fixture) !=
      tree::FixtureError::ok)
    return 10;
  auto wrong_owner =
      scene008::frame(other_fixture, *work, scene, *resident, false);
  if (wrong_owner.error != 8 || resident->frames != 4)
    return 11;
  auto invalid_capacity =
      scene008::frame(f, *work, scene, *resident, false, nullptr, 1);
  if (invalid_capacity.error != 1 || resident->frames != 4)
    return 12;
  // Corrupt the reference output only, never the original input machine state.
  // The bridge must reject it; there is no route to copy reference vertices.
  tree::Case first;
  if (tree::get(other_fixture, 0, first) != tree::FixtureError::ok ||
      !first.draws)
    return 13;
  other[size_t(first.expected - other.data()) + 80] ^= 1;
  auto bad_resident = std::make_unique<scene008::Resident>();
  std::memset(scene.writable_vertices(), 0xa5,
              sizeof(replay::GpuVertex) * 6 * scene.draw_count());
  auto corrupt_oracle =
      scene008::frame(other_fixture, *work, scene, *bad_resident, false);
  if (corrupt_oracle.error != 21 || corrupt_oracle.draws != 0 ||
      corrupt_oracle.matches != 0)
    return 14;
  std::printf("PASS: wrong fixture ownership, invalid output capacity and "
              "corrupt oracle explicitly rejected.\n");
  std::printf(
      "PASS: poisoned output rebuilt, exact baseline before/after persistent "
      "child-list detach/reattach, one subtree restore for four frames.\n");
  return 0;
}
