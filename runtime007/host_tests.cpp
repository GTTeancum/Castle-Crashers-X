// SPDX-License-Identifier: MIT
#include "fixtures.h"
#include "selftest.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <vector>
using namespace cc::caller;
static unsigned checks = 0;
#define CHECK(x)                                                               \
  do {                                                                         \
    ++checks;                                                                  \
    if (!(x)) {                                                                \
      std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #x);                \
      std::exit(1);                                                            \
    }                                                                          \
  } while (0)
static uint64_t get(AddressSpace &m, uint32_t a, unsigned n = 4) {
  uint64_t v = 0;
  CHECK(m.load_be(a, n, v) == cc::xbox::MemoryError::ok);
  return v;
}
static void put(AddressSpace &m, uint32_t a, uint64_t v, unsigned n = 4) {
  CHECK(m.store_be(a, n, v) == cc::xbox::MemoryError::ok);
}
struct Observation {
  Case c;
  unsigned emitted{}, bound{};
  bool reject_bind{}, reject_draw{};
};
static bool bind(void *p, uint32_t d, const uint32_t words[20]) {
  auto &o = *static_cast<Observation *>(p);
  ++o.bound;
  CHECK(d == o.c.descriptor);
  CHECK(words[4] && words[5]);
  return !o.reject_bind;
}
static bool submit(void *p, const Draw &d) {
  auto &o = *static_cast<Observation *>(p);
  ++o.emitted;
  CHECK(d.count == 4 && d.stride == 24 && d.primitive == 13);
  CHECK(o.c.emissions == 1);
  CHECK(d.blend == o.c.blend);
  CHECK(std::memcmp(d.projection, o.c.projection, 64) == 0);
  if (std::memcmp(d.vertices, o.c.expected, 96)) {
    for (unsigned i = 0; i < 96; ++i)
      if (d.vertices[i] != o.c.expected[i])
        std::fprintf(stderr, "byte %u got %02x wanted %02x\n", i, d.vertices[i],
                     o.c.expected[i]);
    CHECK(false);
  }
  return !o.reject_draw;
}
int main(int argc, char **argv) {
  CHECK(argc >= 2);
  unsigned total = 0, draws = 0, nodraws = 0, bindings = 0, dispatches = 0;
  for (int f = 1; f < argc; ++f) {
    std::ifstream in(argv[f], std::ios::binary);
    CHECK(in.good());
    std::vector<uint8_t> bytes((std::istreambuf_iterator<char>(in)), {});
    Fixtures fixtures;
    CHECK(parse(bytes.data(), bytes.size(), fixtures) == FixtureError::ok);
    CHECK(fixtures.draws > 0);
    Workspace w;
    for (uint32_t i = 0; i < fixtures.count; ++i) {
      Case c;
      CHECK(restore(fixtures, i, w, c) == FixtureError::ok);
      auto old = w.ctx;
      const uint32_t sprite = old.r3.u32;
      Observation obs{c};
      auto r = invoke(c.entry, w.ctx, w.memory, {&obs, bind, submit});
      if (r.error != Error::ok) {
        std::fprintf(
            stderr,
            "CASE %s/%u entry=%08x error=%s address=%08x qerr=%u dispatch=%u\n",
            argv[f], i, c.entry, name(r.error), r.address, r.quad_error,
            r.dispatches);
        return 2;
      }
      CHECK(r.submits == c.emissions);
      CHECK(obs.emitted == c.emissions);
      CHECK(r.quad_calls == c.emissions);
      CHECK(w.ctx.r1.u64 == old.r1.u64);
      CHECK(w.ctx.lr == old.lr);
      for (unsigned reg = 14; reg < 32; ++reg) {
        CHECK(cc::quad::gpr(w.ctx, reg).u64 == cc::quad::gpr(old, reg).u64);
        CHECK(cc::quad::fpr(w.ctx, reg).u64 == cc::quad::fpr(old, reg).u64);
      }
      CHECK(get(w.memory, 0x8228a7c4) == c.post_counter);
      if (c.entry == 0x820855d8) {
        CHECK(w.ctx.r3.u64 == c.returned);
        CHECK(get(w.memory, sprite + 86, 1) == c.flags);
      }
      draws += r.submits;
      nodraws += !r.submits;
      bindings += r.bind_calls;
      dispatches += r.dispatches;
      ++total;
      // Bounded-memory failures and unknown function pointers must not succeed.
      CHECK(restore(fixtures, i, w, c) == FixtureError::ok);
      auto e = invoke(0, w.ctx, w.memory, {&obs, bind, submit});
      CHECK(e.error == Error::entry);
      if (c.entry == 0x820855d8) {
        w.ctx.r6.u32 = sprite + 1;
        obs = {c};
        e = invoke(c.entry, w.ctx, w.memory, {&obs, bind, submit});
        CHECK(e.error == Error::ok);
        CHECK(e.submits == 0);
        CHECK(w.ctx.r3.u64 == 0);
      }
      if (c.emissions) {
        CHECK(restore(fixtures, i, w, c) == FixtureError::ok);
        uint32_t obj = c.entry == 0x820a9068 ? w.ctx.r3.u32 : w.ctx.r5.u32;
        uint32_t vt = uint32_t(get(w.memory, obj));
        put(w.memory, vt + 116, 0x12345678);
        obs = {c};
        e = invoke(c.entry, w.ctx, w.memory, {&obs, bind, submit});
        CHECK(e.error == Error::dispatch);
        CHECK(e.address == 0x12345678);
        CHECK(!e.submits);
        CHECK(restore(fixtures, i, w, c) == FixtureError::ok);
        obs = {c};
        obs.reject_draw = true;
        e = invoke(c.entry, w.ctx, w.memory, {&obs, bind, submit});
        CHECK(e.error == Error::quad);
        CHECK(e.quad_error == uint32_t(cc::quad::Error::sink));
        if (c.entry == 0x820855d8) {
          CHECK(restore(fixtures, i, w, c) == FixtureError::ok);
          obs = {c};
          obs.reject_bind = true;
          e = invoke(c.entry, w.ctx, w.memory, {&obs, bind, submit});
          CHECK(e.error == Error::texture);
          CHECK(!e.submits);
        }
        // Invalid root pointer triggers checked memory failure, not raw host
        // access.
        CHECK(restore(fixtures, i, w, c) == FixtureError::ok);
        w.ctx.r3.u64 = 0x40000000;
        obs = {c};
        e = invoke(c.entry, w.ctx, w.memory, {&obs, bind, submit});
        CHECK(e.error == Error::memory);
        CHECK(!e.submits);
      }
    }
    CHECK(self_test(fixtures, w) == 255);
    // Parser mutation tests never execute arbitrary corrupted caller machine
    // state.
    uint32_t state = 0x13377331;
    unsigned rejected = 0, accepted = 0;
    for (unsigned trial = 0; trial < 2000; ++trial) {
      auto bad = bytes;
      state ^= state << 13;
      state ^= state >> 17;
      state ^= state << 5;
      size_t at = state % bad.size();
      bad[at] ^= uint8_t(1u << (trial % 8));
      Fixtures v;
      auto e = parse(bad.data(), bad.size(), v);
      if (e == FixtureError::ok) {
        ++accepted;
        Case c;
        CHECK(restore(v, trial % v.count, w, c) == FixtureError::ok);
      } else
        ++rejected;
    }
    std::printf(
        "fixture %s: calls=%u draws=%u mutations accepted=%u rejected=%u\n",
        argv[f], fixtures.count, fixtures.draws, accepted, rejected);
  }
  std::printf(
      "PASS assertions=%u original_caller_cases=%u exact_draws=%u "
      "original_no_draws=%u texture_bindings=%u indirect_dispatches=%u\n",
      checks, total, draws, nodraws, bindings, dispatches);
}
