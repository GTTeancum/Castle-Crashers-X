// SPDX-License-Identifier: MIT
// Malformed serialized state is parsed/restored, never executed as game code.
#include "fixtures.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <memory>
#include <vector>
using namespace cc::tree;
static unsigned checks = 0, accepted = 0, rejected = 0;
#define CHECK(x)                                                               \
  do {                                                                         \
    ++checks;                                                                  \
    if (!(x)) {                                                                \
      std::fprintf(stderr, "FAIL %d: %s\n", __LINE__, #x);                     \
      std::exit(1);                                                            \
    }                                                                          \
  } while (0)
static void put(std::vector<uint8_t> &b, size_t p, uint32_t v) {
  CHECK(p + 4 <= b.size());
  for (unsigned i = 0; i < 4; ++i)
    b[p + i] = uint8_t(v >> (i * 8));
}
static std::vector<uint8_t> first_case(const std::vector<uint8_t> &b) {
  Fixtures f;
  Case c;
  CHECK(parse(b.data(), b.size(), f) == FixtureError::ok);
  CHECK(get(f, 0, c) == FixtureError::ok);
  auto n = little32(b.data() + 36);
  std::vector<uint8_t> a(48 + n);
  std::memcpy(a.data(), b.data(), 32);
  std::memcpy(a.data() + 48, c.record, n);
  put(a, 8, a.size());
  put(a, 12, 1);
  put(a, 24, c.bytes);
  put(a, 28, c.draws);
  put(a, 32, 48);
  put(a, 36, n);
  put(a, 40, 0);
  put(a, 44, 0);
  return a;
}
static void bad(std::vector<uint8_t> b, size_t off, uint32_t v) {
  put(b, off, v);
  Fixtures f{b.data(), b.size(), 999, 999, 999};
  CHECK(parse(b.data(), b.size(), f) != FixtureError::ok);
  CHECK(!f.bytes && !f.size && !f.count);
}
int main(int argc, char **argv) {
  CHECK(argc == 3);
  auto w = std::make_unique<Workspace>();
  Fixtures f;
  CHECK(parse(nullptr, 0, f) == FixtureError::size);
  Case empty;
  CHECK(get(f, 0, empty) == FixtureError::count);
  for (int file = 1; file < argc; ++file) {
    std::ifstream s(argv[file], std::ios::binary);
    CHECK(bool(s));
    std::vector<uint8_t> input((std::istreambuf_iterator<char>(s)), {});
    auto a = first_case(input);
    CHECK(parse(a.data(), a.size(), f) == FixtureError::ok);
    Case c;
    CHECK(restore(f, 0, *w, c) == FixtureError::ok);
    CHECK(get(f, 1, c) == FixtureError::count);
    for (auto off : {0u, 8u, 12u, 16u, 20u, 24u, 28u, 32u, 36u, 40u, 44u})
      bad(a, off, 0xffffffffu);
    for (auto off : {0u, 4u, 8u, 12u, 20u, 24u, 28u, 32u, 36u, 40u, 44u})
      bad(a, 48 + off, 0xffffffffu);
    bad(a, 48 + 48 + 8, 0);             // Invalid initial stack.
    bad(a, 48 + 48 + 528, 0x02020202);  // XER/reserved bits.
    bad(a, 48 + 48 + 532, 0xffffffffu); // Condition register encoding.
    bad(a, 48 + fixed_bytes + 4, 0);    // Empty mapped region.
    bad(a, 48 + fixed_bytes + 8, 1);    // Noncontiguous backing offset.
    CHECK(parse(a.data(), a.size(), f) == FixtureError::ok);
    CHECK(get(f, 0, c) == FixtureError::ok);
    auto maskoff = size_t(c.writes - a.data()),
         draw = size_t(c.expected - a.data());
    bad(a, maskoff, 0x02020202);
    bad(a, draw + 4, 512);
    bad(a, draw + 12, 1);
    for (size_t n = 0; n < 64; ++n) {
      CHECK(parse(a.data(), n, f) != FixtureError::ok);
    }
    for (unsigned i = 1; i <= 512; ++i) {
      auto n = (a.size() * i) / 513;
      CHECK(parse(a.data(), n, f) != FixtureError::ok);
    }
    uint32_t state = 0x8ccd1234u;
    auto random = [&]() {
      state ^= state << 13;
      state ^= state >> 17;
      state ^= state << 5;
      return state;
    };
    for (unsigned i = 0; i < 2000; ++i) {
      auto b = a;
      unsigned edits = 1 + random() % 8;
      while (edits--) {
        auto p = random() % b.size();
        b[p] ^= uint8_t(1u << (random() % 8));
      }
      auto e = parse(b.data(), b.size(), f);
      if (e == FixtureError::ok) {
        ++accepted;
        CHECK(restore(f, 0, *w, c) == FixtureError::ok);
        CHECK(c.bytes <= max_scratch && c.regions <= AddressSpace::capacity);
        CHECK(std::memcmp(w->data, c.before, c.bytes) == 0);
      } else {
        ++rejected;
        CHECK(!f.bytes && !f.size && !f.count);
      }
    }
  }
  std::printf(
      "PASS fixture checks=%u mutation_trials=4000 accepted_restore_only=%u "
      "rejected=%u; no mutated game state executed\n",
      checks, accepted, rejected);
}
