// SPDX-License-Identifier: MIT
#include "fixtures.h"
#include "selftest.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <vector>
using namespace cc::tree;
static uint64_t assertions = 0;
#define CHECK(x)                                                               \
  do {                                                                         \
    ++assertions;                                                              \
    if (!(x)) {                                                                \
      std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #x);                \
      std::exit(1);                                                            \
    }                                                                          \
  } while (0)
struct Output {
  Case *c{};
  uint32_t used{}, texture{};
  bool bad{};
};
static bool bind(void *p, uint32_t d, const uint32_t w[20]) {
  auto &o = *static_cast<Output *>(p);
  o.texture = d;
  return w[4] && w[5];
}
static bool submit(void *p, const Draw &d) {
  auto &o = *static_cast<Output *>(p);
  if (o.used >= o.c->draws) {
    o.bad = true;
    return false;
  }
  auto e = o.c->expected + o.used * draw_bytes;
  if (o.texture != little32(e) || d.blend != little32(e + 8) || d.count != 4 ||
      d.stride != 24 || d.primitive != 13 ||
      std::memcmp(d.vertices, e + 80, 96)) {
    std::fprintf(stderr, "draw mismatch #%u tex=%x want=%x blend=%x want=%x\n",
                 o.used, o.texture, little32(e), d.blend, little32(e + 8));
    for (unsigned i = 0; i < 96; ++i)
      if (d.vertices[i] != e[80 + i]) {
        std::fprintf(stderr, "first byte %u: %u != %u\n", i, d.vertices[i],
                     e[80 + i]);
        break;
      }
    o.bad = true;
    return false;
  }
  for (unsigned i = 0; i < 16; ++i)
    if (d.projection[i] != little32(e + 16 + 4 * i)) {
      o.bad = true;
      return false;
    }
  ++o.used;
  return true;
}
int main(int argc, char **argv) {
  CHECK(argc >= 2);
  auto *work = new Workspace;
  uint64_t calls = 0, draws = 0, visits = 0, stores = 0;
  for (int file = 1; file < argc; ++file) {
    std::ifstream stream(argv[file], std::ios::binary);
    std::vector<uint8_t> data((std::istreambuf_iterator<char>(stream)), {});
    Fixtures f;
    CHECK(parse(data.data(), data.size(), f) == FixtureError::ok);
    for (uint32_t i = 0; i < f.count; ++i) {
      Case c;
      CHECK(restore(f, i, *work, c) == FixtureError::ok);
      Output o{&c, 0, c.initial_texture, false};
      auto r = invoke(c.entry, work->ctx, work->memory, {&o, bind, submit});
      if (r.error != Error::ok || o.bad) {
        std::fprintf(stderr,
                     "root %u entry %08x failed %s address=%08x quad=%u after "
                     "%u draws ops=%u dispatch=%u\n",
                     i, c.entry, name(r.error), r.address, r.quad_error, o.used,
                     r.memory_ops, r.dispatches);
        return 2;
      }
      CHECK(o.used == c.draws);
      CHECK(callee_saved(c, work->ctx));
      CHECK(r.tree_visits == c.tree_visits);
      CHECK(r.dispatches == c.dispatches);
      CHECK(r.bind_calls == c.binds);
      if (c.entry == 0x8208a7a0)
        CHECK(work->ctx.r3.u64 == c.post.r3.u64);
      uint64_t count;
      CHECK(work->memory.load_be(0x8228a7c4, 4, count) ==
            cc::xbox::MemoryError::ok);
      CHECK(count == c.counter_after);
      uint32_t address = 0;
      if (!check_stores(c, *work, &address)) {
        uint64_t actual = 0;
        work->memory.load_be(address, 1, actual);
        std::fprintf(stderr, "root %u state mismatch %08x actual=%02x\n", i,
                     address, unsigned(actual));
        return 3;
      }
      for (uint32_t j = 0; j < c.bytes; ++j)
        stores += c.writes[j];
      ++calls;
      draws += o.used;
      visits += r.tree_visits;
    }
    uint32_t controls = self_test(f, *work);
    std::printf("control_mask=%u\n", controls);
    CHECK(controls == 511);
    std::printf("PASS %s roots=%u draws=%u scratch=%u\n", argv[file], f.count,
                f.draws, f.scratch);
  }
  delete work;
  std::printf("PASS assertions=%llu roots=%llu draws=%llu tree_visits=%llu "
              "checked_store_bytes=%llu\n",
              (unsigned long long)assertions, (unsigned long long)calls,
              (unsigned long long)draws, (unsigned long long)visits,
              (unsigned long long)stores);
}
