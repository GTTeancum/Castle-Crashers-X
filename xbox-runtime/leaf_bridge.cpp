// SPDX-License-Identifier: MIT (adapter only; generated include is user-game-derived)
#include "leaf_bridge.h"
#include <stdlib.h>
namespace cc::xbox {
static_assert(__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__, "Adapter targets little-endian x86 only");
union Reg { uint64_t u64; uint32_t u32; Reg():u64(0){} };
struct LeafContext { Reg r1,r3,r4,r8,r9,r10,r11; };
static uint8_t read8(AddressSpace& memory,uint32_t a) {
  uint64_t v=0;if(memory.load_be(a,1,v)!=MemoryError::ok) abort();return uint8_t(v);
}
static void store64(AddressSpace& memory,uint32_t a,uint64_t v) {
  if(memory.store_be(a,8,v)!=MemoryError::ok) abort();
}
#define DEFINE_REX_FUNC(name) static void name(LeafContext& ctx,AddressSpace& base)
#define REX_FUNC_PROLOGUE() ((void)0)
#define REX_STORE_U64(a,v) store64(base,a,v)
#define REX_LOAD_U8(a) read8(base,a)
#include "leaf_820b20c8.generated.inc"
#undef DEFINE_REX_FUNC
#undef REX_FUNC_PROLOGUE
#undef REX_STORE_U64
#undef REX_LOAD_U8
MemoryError run_leaf_820b20c8(AddressSpace& memory,uint32_t stack,uint64_t r4,uint32_t& result) {
  if(stack>0xffffffe0u)return MemoryError::wrap;
  const auto e=memory.check(stack+24,8,read_access|write_access);if(e!=MemoryError::ok)return e;
  LeafContext ctx;ctx.r1.u64=stack;ctx.r4.u64=r4;sub_820B20C8(ctx,memory);result=ctx.r3.u32;
  return MemoryError::ok;
}
bool bridge_selftest(unsigned* cases) {
  uint8_t stack[64]{};AddressSpace memory;
  if(memory.map(0x70000000u,sizeof(stack),stack,read_access|write_access)!=MemoryError::ok)return false;
  uint32_t state=0x43c0ffee;unsigned passed=0;
  for(unsigned i=0;i<4096;++i) {
    state^=state<<13;state^=state>>17;state^=state<<5;
    const uint32_t color=state;const uint64_t r4=(uint64_t(color)<<32)|(~color);
    uint32_t out=0;if(run_leaf_820b20c8(memory,0x70000000u,r4,out)!=MemoryError::ok)return false;
    if(out!=((color>>8)|(color<<24)))return false;
    uint64_t stored=0;if(memory.load_be(0x70000018u,8,stored)!=MemoryError::ok || stored!=r4)return false;
    ++passed;
  }
  if(cases)*cases=passed;return true;
}
} // namespace cc::xbox
