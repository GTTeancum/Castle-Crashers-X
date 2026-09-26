// SPDX-License-Identifier: MIT
#include "mode.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <initializer_list>
using namespace cc::mode009;
using cc::xbox::MemoryError;
static unsigned checks=0;
#define CHECK(x) do {++checks;if(!(x)){std::fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#x);std::exit(1);}}while(0)
int main() {
  const auto self=self_test();CHECK(self.checks==self.passed);CHECK(self.full_result==1);CHECK(self.service_calls==16);
  alignas(16) uint8_t stack[256]{}; uint8_t cache=0;
  AddressSpace mem;CHECK(mem.map(0x70000000,sizeof(stack),stack,3)==MemoryError::ok);
  CHECK(mem.map(cached_full_game_address,1,&cache,3)==MemoryError::ok);
  Context ctx{};ctx.r1.u64=0x700000c0;ctx.lr=0x12345678;
  for (uint32_t mask : {0u,1u,2u,3u,0xffffffffu,0x80000000u}) {
    for (uint32_t status : {success,invalid_parameter,not_supported}) {
      cache=0;ctx.r3.u64=0;const auto r=test_query(ctx,mem,mask,status);
      const uint32_t expected=status==success ? mask&1u : 0u;
      CHECK(r.error==Error::ok);CHECK(r.full_game==expected);CHECK(r.cached_flag==expected);
      CHECK(ctx.r1.u64==0x700000c0);CHECK(ctx.lr==0x12345678);
    }
  }
  uint32_t seed=0x6a09e667;
  for(unsigned i=0;i<4096;++i) {
    seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;
    cache=0;auto ref=test_query(ctx,mem,seed,success);
    CHECK(ref.full_game==(seed&1));CHECK(cache==(seed&1));
    cache=0;auto prod=query_full_game(ctx,mem);
    CHECK(prod.error==Error::ok && prod.full_game==1 && prod.cached_flag==1);
    CHECK(prod.service_calls==1);
  }
  // Invalid pointer, readonly and async requests never partially modify memory.
  auto all=stack; uint8_t snapshot[256];std::memcpy(snapshot,all,256);
  for(uint32_t p : {0u,0x700000ffu,0xfffffffeu,0x70000100u}) CHECK(query_license(mem,p,0)==invalid_parameter);
  CHECK(!std::memcmp(snapshot,stack,256));
  CHECK(query_license(mem,0x700000b0u,1)==not_supported);CHECK(!std::memcmp(snapshot,stack,256));
  AddressSpace ro;CHECK(ro.map(0x1000,256,stack,1)==MemoryError::ok);
  CHECK(query_license(ro,0x1000,0)==invalid_parameter);CHECK(!std::memcmp(snapshot,stack,256));
  // Original check rejects bad guest stack before any generated write.
  for(uint64_t sp : {0ull,32ull,0x700000c1ull,0x1700000c0ull,0x600000c0ull}) {
    ctx.r1.u64=sp;Context old=ctx;
    CHECK(query_full_game(ctx,mem).error!=Error::ok);CHECK(!std::memcmp(&ctx,&old,sizeof(ctx)));
  }
  AddressSpace alias;CHECK(alias.map(0x70000000,256,stack,3)==MemoryError::ok);
  CHECK(alias.map(cached_full_game_address,1,stack+160,3)==MemoryError::ok);
  ctx.r1.u64=0x700000c0;CHECK(query_full_game(ctx,alias).error==Error::alias);
  std::printf("PASS: %u assertions; 4096 mask controls; shared target self-test %u/%u; production mask=%u.\n",checks,self.passed,self.checks,base_game_mask);
}
