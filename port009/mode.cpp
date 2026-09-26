// SPDX-License-Identifier: MIT (adapter; generated includes are user-game code)
#include "mode.h"
#include <cstring>
namespace cc::mode009 {
using cc::xbox::MemoryError;
static constexpr uint32_t rw = cc::xbox::read_access | cc::xbox::write_access;
uint32_t query_license(AddressSpace &memory, uint32_t out, uint32_t overlapped) noexcept {
  if (overlapped) return not_supported;
  if (!out || memory.check(out, 4, cc::xbox::write_access) != MemoryError::ok)
    return invalid_parameter;
  return memory.store_be(out, 4, base_game_mask) == MemoryError::ok
      ? success : invalid_parameter;
}
namespace {
struct Machine {
  AddressSpace &memory;
  uint32_t calls{};
  bool bad{};
#ifdef CC_MODE009_TEST_SERVICE
  bool injected{};
  uint32_t test_mask{}, test_result{};
#endif
  uint64_t load(uint32_t a, unsigned n) noexcept {
    uint64_t v = 0;
    if (memory.load_be(a,n,v) != MemoryError::ok) bad = true;
    return v;
  }
  void store(uint32_t a, unsigned n, uint64_t v) noexcept {
    if (memory.store_be(a,n,v) != MemoryError::ok) bad = true;
  }
};
#define DEFINE_REX_FUNC(name) static void name([[maybe_unused]] Context &ctx, [[maybe_unused]] Machine &base)
#define REX_FUNC_PROLOGUE() ((void)0)
#define REX_LOAD_U32(a) uint32_t(base.load(uint32_t(a),4))
#define REX_STORE_U32(a,v) base.store(uint32_t(a),4,v)
#define REX_STORE_U8(a,v) base.store(uint32_t(a),1,v)
DEFINE_REX_FUNC(__imp__XamContentGetLicenseMask) {
  ++base.calls;
#ifdef CC_MODE009_TEST_SERVICE
  if (base.injected) {
    if (base.test_result == success) base.store(ctx.r3.u32,4,base.test_mask);
    ctx.r3.u64 = base.test_result;
    return;
  }
#endif
  ctx.r3.u64 = query_license(base.memory,ctx.r3.u32,ctx.r4.u32);
}
#include "generated/sub_820B6818.inc"
#include "generated/sub_820A0F88.inc"
#undef DEFINE_REX_FUNC
#undef REX_FUNC_PROLOGUE
#undef REX_LOAD_U32
#undef REX_STORE_U32
#undef REX_STORE_U8
Result run(Context &ctx, Machine &m) noexcept {
  const uint32_t sp = ctx.r1.u32;
  if (ctx.r1.u64 > 0xffffffffull || ctx.lr > 0xffffffffull || sp < 96 || (sp & 15u))
    return {Error::context};
  // This exact routine touches only this frame and the cached full-game byte.
  if (m.memory.check(sp-96,96,rw) != MemoryError::ok ||
      m.memory.check(cached_full_game_address,1,rw) != MemoryError::ok)
    return {Error::memory};
  // Require contiguous stack/cache to make the alias contract explicit.
  auto *stack = m.memory.contiguous(sp-96,96,rw);
  auto *cache = m.memory.contiguous(cached_full_game_address,1,rw);
  if (!stack || !cache) return {Error::memory};
  const uintptr_t a = reinterpret_cast<uintptr_t>(stack), b = reinterpret_cast<uintptr_t>(cache);
  if (b >= a && b-a < 96) return {Error::alias};
  sub_820A0F88(ctx,m);
  if (m.bad) return {Error::memory,0,0,m.calls};
  return {Error::ok,ctx.r3.u32,uint32_t(m.load(cached_full_game_address,1)),m.calls};
}
}
Result query_full_game(Context &ctx, AddressSpace &memory) noexcept {
  Machine machine{memory};
  return run(ctx,machine);
}
#ifdef CC_MODE009_TEST_SERVICE
Result test_query(Context &ctx, AddressSpace &memory, uint32_t mask, uint32_t result) noexcept {
  Machine machine{memory}; machine.injected=true; machine.test_mask=mask; machine.test_result=result;
  return run(ctx,machine);
}
#endif
SelfTest self_test() noexcept {
  SelfTest result{};
  alignas(16) uint8_t stack[256]{};
  uint8_t cache=0;
  AddressSpace memory;
  auto check=[&](bool ok) { ++result.checks; if (ok) ++result.passed; };
  check(memory.map(0x70000000u,sizeof(stack),stack,rw)==MemoryError::ok);
  check(memory.map(cached_full_game_address,1,&cache,rw)==MemoryError::ok);
  Context c{};c.r1.u64=0x700000c0u;c.lr=0x12345678u;
  for (unsigned i=0;i<16;++i) {
    cache=0; c.r1.u64=0x700000c0u;c.lr=0x12345678u;
    const Result r=query_full_game(c,memory);
    check(r.error==Error::ok && r.full_game==1 && r.cached_flag==1 && r.service_calls==1);
    check(c.r1.u64==0x700000c0u && c.lr==0x12345678u);
    uint64_t mask=0;check(memory.load_be(0x700000b0u,4,mask)==MemoryError::ok && mask==1);
    result.full_result=r.full_game;result.cached_flag=r.cached_flag;result.service_calls+=r.service_calls;
  }
  uint8_t before[256];std::memcpy(before,stack,sizeof(stack));
  check(query_license(memory,0,0)==invalid_parameter);
  check(query_license(memory,0xfffffffeu,0)==invalid_parameter);
  check(query_license(memory,0x700000b0u,1)==not_supported);
  check(!std::memcmp(before,stack,sizeof(stack)));
  c.r1.u64=32;
  check(query_full_game(c,memory).error==Error::context);
  return result;
}
}
