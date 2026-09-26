// SPDX-License-Identifier: MIT
#include "selftest.h"
#include <cstring>
namespace cc::tree {
struct TestSink {
  Case *c;
  uint32_t texture{}, used{};
  bool reject_bind{}, reject_submit{};
};
static bool bind(void *ptr, uint32_t d, const uint32_t *) {
  auto &s = *static_cast<TestSink *>(ptr);
  s.texture = d;
  return !s.reject_bind;
}
static bool submit(void *ptr, const Draw &d) {
  auto &s = *static_cast<TestSink *>(ptr);
  if (s.reject_submit || s.used >= s.c->draws)
    return false;
  const auto *e = s.c->expected + s.used * draw_bytes;
  if (s.texture != little32(e) || d.count != 4 || d.stride != 24 ||
      d.primitive != 13 || d.blend != little32(e + 8) ||
      std::memcmp(d.vertices, e + 80, 96))
    return false;
  for (unsigned i = 0; i < 16; ++i)
    if (d.projection[i] != little32(e + 16 + 4 * i))
      return false;
  ++s.used;
  return true;
}
uint32_t self_test(const Fixtures &f, Workspace &w) noexcept {
  uint32_t mask = 0;
  Case c;
  auto restore_first = [&]() {
    return restore(f, 0, w, c) == FixtureError::ok && c.entry == 0x8208a7a0;
  };
  for (uint32_t test = 0; test < 9; ++test) {
    if (!restore_first())
      return mask;
    TestSink sink{&c, c.initial_texture};
    uint32_t entry = c.entry, budget = 50000;
    uint64_t vt = 0, head = 0;
    w.memory.load_be(c.initial.r3.u32, 4, vt);
    w.memory.load_be(c.initial.r3.u32 + 104, 4, head);
    if (test == 1)
      entry = 0xdeadbeef;
    if (test == 2)
      budget = 1;
    if (test == 3 && w.memory.store_be(uint32_t(vt) + 48, 4, 0xdeadbeef) !=
                         cc::xbox::MemoryError::ok)
      return mask;
    if (test == 4)
      sink.reject_bind = true;
    if (test == 5)
      sink.reject_submit = true;
    if (test == 6 && w.memory.store_be(uint32_t(head) + 88, 4, head) !=
                         cc::xbox::MemoryError::ok)
      return mask;
    if (test == 7)
      w.memory = AddressSpace{};
    if (test == 8 && w.memory.store_be(uint32_t(head) + 88, 4, 0xfeedbeef) !=
                         cc::xbox::MemoryError::ok)
      return mask;
    auto r = invoke(entry, w.ctx, w.memory, {&sink, bind, submit}, budget);
    bool good = false;
    switch (test) {
    case 0:
      good = r.error == Error::ok && sink.used == c.draws &&
             check_stores(c, w) && callee_saved(c, w.ctx);
      break;
    case 1:
      good = r.error == Error::entry;
      break;
    case 2:
      good = r.error == Error::capacity;
      break;
    case 6:
      good = r.error == Error::cycle;
      break;
    case 3:
      good = r.error == Error::dispatch && r.address == 0xdeadbeef;
      break;
    case 4:
      good = r.error == Error::texture;
      break;
    case 5:
      good = r.error == Error::quad &&
             r.quad_error == uint32_t(cc::quad::Error::sink);
      break;
    case 7:
    case 8:
      good = r.error == Error::memory;
      break;
    }
    if (good)
      mask |= 1u << test;
  }
  return mask;
}
} // namespace cc::tree
