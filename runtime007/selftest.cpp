// SPDX-License-Identifier: MIT
#include "selftest.h"
#include <cstring>
namespace cc::caller {
struct Checks {
  const Case *c;
  bool fail_bind{}, fail_draw{};
  uint32_t draws{}, binds{};
};
static bool bind(void *p, uint32_t d, const uint32_t words[20]) {
  auto &o = *static_cast<Checks *>(p);
  ++o.binds;
  return !o.fail_bind && d == o.c->descriptor && words[4] && words[5];
}
static bool submit(void *p, const Draw &d) {
  auto &o = *static_cast<Checks *>(p);
  ++o.draws;
  return !o.fail_draw && !std::memcmp(d.vertices, o.c->expected, 96);
}
uint32_t self_test(const Fixtures &f, Workspace &w) noexcept {
  Case c;
  uint32_t index = 0;
  for (; index < f.count; ++index) {
    if (restore(f, index, w, c) != FixtureError::ok)
      return 0;
    if (c.entry == 0x820855d8 && c.emissions)
      break;
  }
  if (index == f.count)
    return 0;
  uint32_t mask = 0;
  for (uint32_t test = 0; test < 8; ++test) {
    if (restore(f, index, w, c) != FixtureError::ok)
      return mask;
    Checks checks{&c};
    uint32_t entry = c.entry;
    auto &ctx = w.ctx;
    auto &m = w.memory;
    switch (test) {
    case 0:
      entry = 0;
      break;
    case 1:
      ctx.r6.u64 = ctx.r3.u32 + 1;
      break;
    case 2:
      ctx.r6.u64 = ctx.r3.u64;
      break;
    case 3: {
      uint64_t vt = 0;
      if (m.load_be(ctx.r5.u32, 4, vt) != cc::xbox::MemoryError::ok)
        return mask;
      if (m.store_be(uint32_t(vt) + 116, 4, 0x12345678) !=
          cc::xbox::MemoryError::ok)
        return mask;
      break;
    }
    case 4:
      checks.fail_bind = true;
      break;
    case 5:
      checks.fail_draw = true;
      break;
    case 6:
      ctx.r3.u64 = 0x40000000;
      break;
    case 7: {
      uint64_t mi = 0;
      if (m.load_be(ctx.r4.u32 + 9532, 4, mi) != cc::xbox::MemoryError::ok ||
          mi >= 32)
        return mask;
      // Translate the sprite wholly outside the actual culling rectangle.
      const float far = 1000000.0f;
      uint32_t bits;
      std::memcpy(&bits, &far, 4);
      if (m.store_be(ctx.r4.u32 + 8252 + uint32_t(mi) * 40 + 32, 4, bits) !=
          cc::xbox::MemoryError::ok)
        return mask;
      break;
    }
    }
    const auto r = invoke(entry, ctx, m, {&checks, bind, submit});
    bool passed = false;
    switch (test) {
    case 0:
      passed = r.error == Error::entry && !r.submits;
      break;
    case 1:
      passed = r.error == Error::ok && !r.submits && ctx.r3.u64 == 0;
      break;
    case 2:
      passed = r.error == Error::ok && r.submits == 1 && ctx.r3.u64 == 2;
      break;
    case 3:
      passed =
          r.error == Error::dispatch && r.address == 0x12345678 && !r.submits;
      break;
    case 4:
      passed = r.error == Error::texture && !r.submits;
      break;
    case 5:
      passed = r.error == Error::quad &&
               r.quad_error == uint32_t(cc::quad::Error::sink) && !r.submits;
      break;
    case 6:
      passed = r.error == Error::memory && !r.submits;
      break;
    case 7:
      passed = r.error == Error::ok && !r.submits && ctx.r3.u64 == 1;
      break;
    }
    if (passed)
      mask |= 1u << test;
  }
  return mask;
}
} // namespace cc::caller
