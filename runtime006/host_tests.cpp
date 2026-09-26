// SPDX-License-Identifier: MIT
#include "fixtures.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <vector>
using namespace cc::quad;
static uint64_t assertions;
#define CHECK(x)                                                               \
  do {                                                                         \
    ++assertions;                                                              \
    if (!(x)) {                                                                \
      std::fprintf(stderr, "FAIL %s:%d %s\n", __FILE__, __LINE__, #x);         \
      return 1;                                                                \
    }                                                                          \
  } while (0)
struct Observed {
  Draw draw;
  unsigned count{};
};
static bool receive(void *p, const Draw &d) {
  auto &o = *static_cast<Observed *>(p);
  o.draw = d;
  ++o.count;
  return true;
}
static bool reject(void *, const Draw &) { return false; }
static uint32_t be32(const uint8_t *b) {
  return uint32_t(b[0]) << 24 | uint32_t(b[1]) << 16 | uint32_t(b[2]) << 8 |
         b[3];
}
static float bef(const uint8_t *b) {
  uint32_t u = be32(b);
  float f;
  std::memcpy(&f, &u, 4);
  return f;
}
int main(int argc, char **argv) {
  CHECK(argc > 1);
  uint64_t calls = 0, mutations = 0;
  for (int file = 1; file < argc; ++file) {
    std::ifstream f(argv[file], std::ios::binary);
    CHECK(f.good());
    std::vector<uint8_t> b((std::istreambuf_iterator<char>(f)), {});
    Fixtures view;
    CHECK(parse(b.data(), b.size(), view) == FixtureError::ok);
    Workspace w;
    Case v;
    std::printf("Testing %s: %u captured calls\n", argv[file], view.count);
    for (unsigned i = 0; i < view.count; ++i) {
      CHECK(restore(view, i, w, v) == FixtureError::ok);
      Context before = w.ctx;
      uint64_t original_count = 0;
      CHECK(w.memory.load_be(0x8228a7c4, 4, original_count) ==
            cc::xbox::MemoryError::ok);
      Observed got{};
      unsigned n = 0;
      auto err = invoke(0x820a9308, w.ctx, w.memory, {&got, receive}, &n);
      if (err != Error::ok) {
        std::fprintf(stderr, "call %u rejected: %s sp=%08x obj=%08x\n", i,
                     name(err), w.ctx.r1.u32, w.ctx.r3.u32);
        return 1;
      }
      CHECK(n == 1 && got.count == 1);
      CHECK(got.draw.count == 4 && got.draw.primitive == 13 &&
            got.draw.stride == 24);
      if (std::memcmp(got.draw.vertices, v.expected, 96)) {
        for (unsigned k = 0; k < 96; k += 4)
          std::fprintf(stderr, "%u: actual=%08x expected=%08x\n", k,
                       be32(got.draw.vertices + k), be32(v.expected + k));
        CHECK(false);
      }
      ++assertions;
      uint64_t updated_count = 0;
      CHECK(w.memory.load_be(0x8228a7c4, 4, updated_count) ==
            cc::xbox::MemoryError::ok);
      CHECK(updated_count == original_count + 4);
      CHECK(std::memcmp(got.draw.projection, v.projection, 64) == 0);
      CHECK(got.draw.blend == v.blend);
      CHECK(w.ctx.r1.u64 == before.r1.u64 &&
            w.ctx.lr == (before.lr & 0xffffffffu));
      for (unsigned r = 21; r < 32; ++r)
        CHECK(gpr(w.ctx, r).u64 == gpr(before, r).u64);
      for (unsigned r = 20; r < 32; ++r)
        CHECK(fpr(w.ctx, r).u64 == fpr(before, r).u64);
      // Caller-controlled motion goes through the generated coordinate path,
      // not post-render translation.
      for (unsigned pass = 0; pass < 3; ++pass) {
        CHECK(restore(view, i, w, v) == FixtureError::ok);
        float dx = pass == 0   ? 32.f
                   : pass == 1 ? -16.f
                               : 0.f,
              dy = pass == 0   ? -12.f
                   : pass == 1 ? 24.f
                               : 0.f;
        uint8_t alpha = pass == 2 ? 128 : 255;
        CHECK(change_inputs(w, dx, dy, alpha) == Error::ok);
        uint64_t color = 0;
        CHECK(w.memory.load_be(w.ctx.r1.u32 + 92, 4, color) ==
              cc::xbox::MemoryError::ok);
        uint32_t a = uint32_t(color) & 255;
        uint32_t color_oracle =
            (a << 24) | ((uint32_t(color >> 24) * a >> 8) << 16) |
            ((((uint32_t(color) >> 16) & 255) * a >> 8) << 8) |
            (((uint32_t(color) >> 8) & 255) * a >> 8);
        got = {};
        CHECK(invoke(0x820a9308, w.ctx, w.memory, {&got, receive}, &n) ==
                  Error::ok &&
              n == 1);
        for (unsigned k = 0; k < 4; ++k) {
          CHECK(std::fabs(bef(got.draw.vertices + 24 * k) -
                          (bef(v.expected + 24 * k) + dx)) < .001f);
          CHECK(std::fabs(bef(got.draw.vertices + 24 * k + 4) -
                          (bef(v.expected + 24 * k + 4) + dy)) < .001f);
          CHECK(std::memcmp(got.draw.vertices + 24 * k + 8,
                            v.expected + 24 * k + 8, 12) == 0);
          CHECK(be32(got.draw.vertices + 24 * k + 20) == color_oracle);
        }
        if (pass < 2)
          for (unsigned k = 0; k < 4; ++k)
            CHECK(be32(got.draw.vertices + 24 * k + 20) ==
                  be32(v.expected + 24 * k + 20));
        else
          for (unsigned k = 0; k < 4; ++k)
            CHECK((be32(got.draw.vertices + 24 * k + 20) >> 24) <=
                  (be32(v.expected + 24 * k + 20) >> 24));
      }
      ++calls;
    }
    CHECK(restore(view, 0, w, v) == FixtureError::ok);
    std::vector<uint8_t> before(w.data, w.data + view.scratch);
    Observed got{};
    CHECK(invoke(0x1234, w.ctx, w.memory, {&got, receive}) == Error::entry);
    CHECK(std::memcmp(before.data(), w.data, view.scratch) == 0);
    CHECK(invoke(0x820a9308, w.ctx, w.memory, {&got, nullptr}) ==
          Error::context);
    CHECK(got.count == 0);
    w.ctx.r1.u64 = 0;
    CHECK(invoke(0x820a9308, w.ctx, w.memory, {&got, receive}) ==
          Error::context);
    CHECK(restore(view, 0, w, v) == FixtureError::ok);
    w.ctx.r4.u64 = 0x12345678;
    CHECK(invoke(0x820a9308, w.ctx, w.memory, {&got, receive}) ==
          Error::memory);
    CHECK(restore(view, 0, w, v) == FixtureError::ok);
    CHECK(invoke(0x820a9308, w.ctx, w.memory, {nullptr, reject}) ==
          Error::sink);
    CHECK(restore(view, 0, w, v) == FixtureError::ok);
    w.memory.store_be(w.ctx.r3.u32 + 28715, 1, 0);
    unsigned n = 99;
    CHECK(invoke(0x820a9308, w.ctx, w.memory, {&got, receive}, &n) ==
              Error::ok &&
          n == 0);
    CHECK(restore(view, 0, w, v) == FixtureError::ok);
    w.memory.store_be(0x8228a7c4u, 4, 6000);
    CHECK(invoke(0x820a9308, w.ctx, w.memory, {&got, receive}, &n) ==
              Error::ok &&
          n == 0);
    // Rejection before guest writes for explicit unsupported states.
    CHECK(restore(view, 0, w, v) == FixtureError::ok);
    w.memory.store_be(0x8228a7c4u, 4, 0xffffffffu);
    before.assign(w.data, w.data + view.scratch);
    CHECK(invoke(0x820a9308, w.ctx, w.memory, {&got, receive}) ==
          Error::capacity);
    CHECK(std::memcmp(before.data(), w.data, view.scratch) == 0);
    CHECK(restore(view, 0, w, v) == FixtureError::ok);
    uint64_t slot = 0, ptr = 0;
    CHECK(w.memory.load_be(w.ctx.r3.u32 + 30208, 4, slot) ==
          cc::xbox::MemoryError::ok);
    CHECK(w.memory.load_be(w.ctx.r3.u32 + 30176 + uint32_t(slot) * 4, 4, ptr) ==
          cc::xbox::MemoryError::ok);
    w.memory.store_be(uint32_t(ptr), 4, 11);
    before.assign(w.data, w.data + view.scratch);
    CHECK(invoke(0x820a9308, w.ctx, w.memory, {&got, receive}) ==
          Error::shader);
    CHECK(std::memcmp(before.data(), w.data, view.scratch) == 0);
    CHECK(restore(view, 0, w, v) == FixtureError::ok);
    w.memory.store_be(w.ctx.r4.u32, 4, 0x7fc00000);
    before.assign(w.data, w.data + view.scratch);
    CHECK(invoke(0x820a9308, w.ctx, w.memory, {&got, receive}) ==
          Error::nonfinite);
    CHECK(std::memcmp(before.data(), w.data, view.scratch) == 0);
    CHECK(restore(view, 0, w, v) == FixtureError::ok);
    w.ctx.r4.u64 = w.ctx.r1.u64 - 100;
    CHECK(invoke(0x820a9308, w.ctx, w.memory, {&got, receive}) == Error::alias);
    CHECK(restore(view, 0, w, v) == FixtureError::ok);
    w.ctx.fpscr.csr |= 0x2000;
    CHECK(invoke(0x820a9308, w.ctx, w.memory, {&got, receive}) ==
          Error::context);
    CHECK(restore(view, 0, w, v) == FixtureError::ok);
    CHECK(change_inputs(w, NAN, 0, 255) == Error::context);
    CHECK(change_inputs(w, 257, 0, 255) == Error::context);
    // Caller FP environment is restored even when the bridge selects its own
    // nearest mode.
    uint32_t saved_mx, observed_mx;
    uint16_t saved_cw, observed_cw;
    asm volatile("stmxcsr %0" : "=m"(saved_mx));
    asm volatile("fnstcw %0" : "=m"(saved_cw));
    uint32_t changed_mx = (saved_mx | 0x2000 | 0x8000);
    uint16_t changed_cw = uint16_t((saved_cw & ~0xc00) | 0x800);
    asm volatile("ldmxcsr %0" ::"m"(changed_mx));
    asm volatile("fldcw %0" ::"m"(changed_cw));
    got = {};
    auto fp_result = invoke(0x820a9308, w.ctx, w.memory, {&got, receive});
    asm volatile("stmxcsr %0" : "=m"(observed_mx));
    asm volatile("fnstcw %0" : "=m"(observed_cw));
    asm volatile("ldmxcsr %0" ::"m"(saved_mx));
    asm volatile("fldcw %0" ::"m"(saved_cw));
    CHECK(fp_result == Error::ok);
    CHECK(observed_mx == changed_mx && observed_cw == changed_cw);
    CHECK(std::memcmp(got.draw.vertices, v.expected, 96) == 0);
    uint32_t seed = 0x006ca571;
    // Format fuzz: accepted mutations are revalidated/restored but never sent
    // unchecked into generated code.
    for (unsigned trial = 0; trial < 2000; ++trial) {
      auto m = b;
      seed ^= seed << 13;
      seed ^= seed >> 17;
      seed ^= seed << 5;
      size_t pos = seed % m.size();
      m[pos] ^= uint8_t((seed >> 16) | 1);
      Fixtures z;
      auto e = parse(m.data(), m.size(), z);
      if (e == FixtureError::ok) {
        CHECK(z.count <= 4096 && z.scratch <= 16384);
        CHECK(restore(z, 0, w, v) == FixtureError::ok);
      }
      ++mutations;
    }
    for (size_t len : {size_t(0), size_t(7), size_t(31), b.size() - 1})
      CHECK(parse(b.data(), len, view) != FixtureError::ok);
  }
  std::printf("PASS: %llu assertions, %llu real input/output matches, %llu "
              "malformed fixture mutations; Context=%zu Workspace=%zu\n",
              (unsigned long long)assertions, (unsigned long long)calls,
              (unsigned long long)mutations, sizeof(Context),
              sizeof(Workspace));
  return 0;
}
