// SPDX-License-Identifier: MIT (adapter only; exact generated includes are
// user-game-derived)
#include "bridge.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
namespace cc::quad {
static_assert(__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__);
static_assert(sizeof(Register) == 8);
[[noreturn]] static void hard_failure() noexcept {
  std::abort();
  __builtin_trap();
}
// FPState::disableFlushMode is inline in bridge.h. Pentium III has FTZ but
// no DAZ; clearing either bit is safe. Never enable DAZ on the Xbox: loading
// MXCSR with an unsupported bit set faults there.
#ifdef CC_XBOX_DRIVER
static constexpr uint32_t kFlushBits = 0x8000u;
#else
static constexpr uint32_t kFlushBits = 0x8040u;
#endif
void FPState::disableFlushModeUnconditional() noexcept {
  uint32_t mx;
  asm volatile("stmxcsr %0" : "=m"(mx));
  mx &= ~uint32_t(0x8040);
  asm volatile("ldmxcsr %0" : : "m"(mx));
  csr = mx;
}
void FPState::enableFlushModeUnconditional() noexcept {
  // Match ReXGlue 0.10.0 x86 flush-mode ownership for vector FP helpers.
  uint32_t mx;
  asm volatile("stmxcsr %0" : "=m"(mx));
  mx |= kFlushBits;
  asm volatile("ldmxcsr %0" ::"m"(mx));
  csr = mx;
}
void FPState::enableFlushMode() noexcept {
  uint32_t mx;
  asm volatile("stmxcsr %0" : "=m"(mx));
  if ((mx & kFlushBits) != kFlushBits) {
    mx |= kFlushBits;
    asm volatile("ldmxcsr %0" ::"m"(mx));
  }
  csr = mx;
}
uint32_t FPState::loadFromHost() noexcept {
  uint32_t mx;
  asm volatile("stmxcsr %0" : "=m"(mx));
  csr = mx;
  static constexpr uint32_t host_to_guest[4] = {0u,3u,2u,1u};
  return host_to_guest[(mx >> 13) & 3u];
}
void FPState::storeFromGuest(uint32_t value) noexcept {
  uint32_t mx;
  asm volatile("stmxcsr %0" : "=m"(mx));
  static constexpr uint32_t guest_to_host[4] = {0u,3u,2u,1u};
  mx = (mx & ~(3u << 13)) | (guest_to_host[value & 3u] << 13);
  asm volatile("ldmxcsr %0" ::"m"(mx));
  csr = mx;
}
struct FloatScope {
  uint32_t mx;
  uint16_t cw;
  FloatScope() {
    asm volatile("stmxcsr %0" : "=m"(mx));
    asm volatile("fnstcw %0" : "=m"(cw));
    uint32_t next = (mx & ~uint32_t(0xe040)) | 0x1f80;
    uint16_t word = uint16_t((cw & ~0x0f00) | 0x023f);
    asm volatile("ldmxcsr %0" ::"m"(next));
    asm volatile("fldcw %0" ::"m"(word));
  }
  ~FloatScope() {
    asm volatile("ldmxcsr %0" ::"m"(mx));
    asm volatile("fldcw %0" ::"m"(cw));
  }
};
Register &gpr(Context &c, unsigned i) noexcept {
  switch (i) {
  case 0:
    return c.r0;
  case 1:
    return c.r1;
  case 2:
    return c.r2;
  case 3:
    return c.r3;
  case 4:
    return c.r4;
  case 5:
    return c.r5;
  case 6:
    return c.r6;
  case 7:
    return c.r7;
  case 8:
    return c.r8;
  case 9:
    return c.r9;
  case 10:
    return c.r10;
  case 11:
    return c.r11;
  case 12:
    return c.r12;
  case 13:
    return c.r13;
  case 14:
    return c.r14;
  case 15:
    return c.r15;
  case 16:
    return c.r16;
  case 17:
    return c.r17;
  case 18:
    return c.r18;
  case 19:
    return c.r19;
  case 20:
    return c.r20;
  case 21:
    return c.r21;
  case 22:
    return c.r22;
  case 23:
    return c.r23;
  case 24:
    return c.r24;
  case 25:
    return c.r25;
  case 26:
    return c.r26;
  case 27:
    return c.r27;
  case 28:
    return c.r28;
  case 29:
    return c.r29;
  case 30:
    return c.r30;
  case 31:
    return c.r31;
  default:
    hard_failure();
  }
}
Register &fpr(Context &c, unsigned i) noexcept {
  switch (i) {
  case 0:
    return c.f0;
  case 1:
    return c.f1;
  case 2:
    return c.f2;
  case 3:
    return c.f3;
  case 4:
    return c.f4;
  case 5:
    return c.f5;
  case 6:
    return c.f6;
  case 7:
    return c.f7;
  case 8:
    return c.f8;
  case 9:
    return c.f9;
  case 10:
    return c.f10;
  case 11:
    return c.f11;
  case 12:
    return c.f12;
  case 13:
    return c.f13;
  case 14:
    return c.f14;
  case 15:
    return c.f15;
  case 16:
    return c.f16;
  case 17:
    return c.f17;
  case 18:
    return c.f18;
  case 19:
    return c.f19;
  case 20:
    return c.f20;
  case 21:
    return c.f21;
  case 22:
    return c.f22;
  case 23:
    return c.f23;
  case 24:
    return c.f24;
  case 25:
    return c.f25;
  case 26:
    return c.f26;
  case 27:
    return c.f27;
  case 28:
    return c.f28;
  case 29:
    return c.f29;
  case 30:
    return c.f30;
  case 31:
    return c.f31;
  default:
    hard_failure();
  }
}
CR &cr(Context &c, unsigned i) noexcept {
  switch (i) {
  case 0:
    return c.cr0;
  case 1:
    return c.cr1;
  case 2:
    return c.cr2;
  case 3:
    return c.cr3;
  case 4:
    return c.cr4;
  case 5:
    return c.cr5;
  case 6:
    return c.cr6;
  case 7:
    return c.cr7;
  default:
    hard_failure();
  }
}
struct Machine {
  cc::xbox::AddressSpace &memory;
  Sink sink;
  Error error{Error::ok};
  unsigned submits{};
  uint64_t load(uint32_t a, unsigned n) {
    uint64_t v = 0;
    if (memory.load_be(a, n, v) != cc::xbox::MemoryError::ok)
      hard_failure();
    return v;
  }
  void store(uint32_t a, unsigned n, uint64_t v) {
    if (memory.store_be(a, n, v) != cc::xbox::MemoryError::ok)
      hard_failure();
  }
};
using PPCRegister = Register;
#define DEFINE_REX_FUNC(name)                                                  \
  static void name([[maybe_unused]] Context &ctx,                              \
                   [[maybe_unused]] Machine &base)
#define REX_FUNC_PROLOGUE() ((void)0)
#define REX_LOAD_U8(a) uint8_t(base.load(uint32_t(a), 1))
#define REX_LOAD_U32(a) uint32_t(base.load(uint32_t(a), 4))
#define REX_LOAD_U64(a) base.load(uint32_t(a), 8)
#define REX_STORE_U32(a, v) base.store(uint32_t(a), 4, v)
#define REX_STORE_U64(a, v) base.store(uint32_t(a), 8, v)
// Genuine replacement submission service, with a copied packet and explicit
// sink failure.
DEFINE_REX_FUNC(sub_820C1980) {
  if (ctx.r4.u32 != 13 || ctx.r5.u32 != 4 || ctx.r7.u32 != 24 || base.submits) {
    base.error = Error::contract;
    return;
  }
  Draw d;
  d.device = ctx.r3.u32;
  d.primitive = ctx.r4.u32;
  d.count = ctx.r5.u32;
  d.stride = ctx.r7.u32;
  d.source = ctx.r6.u32;
  if (base.memory.read(d.source, d.vertices, 96) != cc::xbox::MemoryError::ok) {
    base.error = Error::memory;
    return;
  }
  for (unsigned i = 0; i < 16; ++i)
    d.projection[i] = uint32_t(base.load(d.device + 1920 + 4 * i, 4));
  d.blend = uint32_t(base.load(d.device + 10552, 4));
  if (!base.sink.submit(base.sink.user, d)) {
    base.error = Error::sink;
    return;
  }
  ++base.submits;
}
// This path is not part of the supported shader 0/5 contract. Preflight rejects
// it. Deliberate hard failure rather than a success stub for unported
// shader-constant services.
DEFINE_REX_FUNC(sub_820BFB50) { hard_failure(); }
#include "generated/__restfpr_20.inc"
#include "generated/__restgprlr_21.inc"
#include "generated/__savefpr_20.inc"
#include "generated/__savegprlr_21.inc"
#include "generated/sub_820A9308.inc"
#undef DEFINE_REX_FUNC
#undef REX_FUNC_PROLOGUE
#undef REX_LOAD_U8
#undef REX_LOAD_U32
#undef REX_LOAD_U64
#undef REX_STORE_U32
#undef REX_STORE_U64
static bool overlap(uint32_t a, uint32_t n, uint32_t b, uint32_t m) {
  return uint64_t(a) < uint64_t(b) + m && uint64_t(b) < uint64_t(a) + n;
}
Error invoke(uint32_t entry, Context &c, cc::xbox::AddressSpace &mem, Sink sink,
             unsigned *submitted) noexcept {
  if (submitted)
    *submitted = 0;
  if (entry != 0x820a9308u)
    return Error::entry;
  if (!sink.submit || (c.fpscr.csr & 0x6000))
    return Error::context;
  if (c.r1.u64 < 400 || c.r1.u64 > 0xffffff97u || c.r3.u64 > 0xffff89f3u)
    return Error::context;
  const uint32_t sp = c.r1.u32, obj = c.r3.u32;
  constexpr uint32_t rd = cc::xbox::read_access,
                     rw = rd | cc::xbox::write_access;
  const auto check = [&](uint32_t a, size_t n, uint32_t p) {
    return mem.check(a, n, p) == cc::xbox::MemoryError::ok;
  };
  const auto word = [&](uint32_t a, uint32_t &v) {
    uint64_t q = 0;
    if (mem.load_be(a, 4, q) != cc::xbox::MemoryError::ok)
      return false;
    v = uint32_t(q);
    return true;
  };
  if (!check(sp - 400, 400, rw) || !check(obj + 28715, 1, rd))
    return Error::memory;
  uint64_t enabled = 0;
  mem.load_be(obj + 28715, 1, enabled);
  uint32_t count = 0;
  if (enabled && !word(0x8228a7c4u, count))
    return Error::memory;
  // The original compares count as signed. Negative counters are outside our
  // contract.
  if (enabled && count > 0x7fffffffu)
    return Error::capacity;
  if (enabled && count < 6000) {
    uint32_t shader_index, shader_ptr, shader, device, mode, uv4, rt = 0;
    if (!word(obj + 30208, shader_index))
      return Error::memory;
    if (shader_index >= 8)
      return Error::shader;
    if (!word(obj + 30176 + shader_index * 4, shader_ptr) ||
        !word(shader_ptr, shader))
      return Error::memory;
    if (shader != 0 && shader != 5)
      return Error::shader;
    if (!word(obj + 4, device) || device > 0xffffd6c3u || !word(sp + 84, uv4) ||
        !word(sp + 100, mode) || !check(sp + 92, 4, rd))
      return Error::memory;
    if (!check(0x8201473c, 16, rd) || !check(0x82042544, 4, rd) ||
        !check(0x820a9634 + shader * 4, 4, rd) || !check(0x8228a7c4, 4, rw))
      return Error::memory;
    if (!check(device + 1920, 64, rd) || !check(device + 10552, 4, rd))
      return Error::memory;
    const uint32_t out = 0x822673d8u + count * 24;
    if (!check(out, 96, rw) || overlap(out, 96, sp - 400, 400))
      return Error::memory;
    uint32_t inputs[8];
    for (unsigned i = 0; i < 7; ++i) {
      if (gpr(c, i + 4).u64 > 0xffffffffu)
        return Error::context;
      inputs[i] = gpr(c, i + 4).u32;
    }
    inputs[7] = uv4;
    for (unsigned i = 0; i < 8; ++i) {
      unsigned n = i < 4 ? 12 : 8;
      if (!check(inputs[i], n, rd))
        return Error::memory;
      if (overlap(inputs[i], n, sp - 400, 400) ||
          overlap(inputs[i], n, out, 96))
        return Error::alias;
      for (unsigned j = 0; j < n; j += 4) {
        uint32_t u = 0;
        word(inputs[i] + j, u);
        float f;
        std::memcpy(&f, &u, 4);
        if (!std::isfinite(f))
          return Error::nonfinite;
      }
    }
    if (mode != 4) {
      uint32_t width, height;
      if (!word(obj + 29124, rt) || rt >= 32)
        return Error::context;
      if (!word(obj + 28748 + rt * 24, height) ||
          !word(obj + 28752 + rt * 24, width))
        return Error::memory;
      if (!width || !height || width > 16384 || height > 16384)
        return Error::context;
    }
  }
  Machine machine{mem, sink};
  FloatScope fp;
  sub_820A9308(c, machine);
  if (submitted)
    *submitted = machine.submits;
  return machine.error;
}
const char *name(Error e) noexcept {
  switch (e) {
#define E(x)                                                                   \
  case Error::x:                                                               \
    return #x;
    E(ok)
    E(entry) E(context) E(memory) E(shader) E(capacity) E(nonfinite) E(alias)
        E(sink) E(contract)
#undef E
  }
  return "unknown";
}
} // namespace cc::quad
