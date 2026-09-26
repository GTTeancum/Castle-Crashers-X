// SPDX-License-Identifier: MIT
// Independent all-byte/property test of the original visibility accessor bodies.
#include "../runtime008/bridge.h"
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace cc::tree;
static unsigned checks;
#define CHECK(x) do {++checks;if(!(x)){std::fprintf(stderr,"FAIL %d: %s\n",__LINE__,#x);std::exit(1);}}while(0)
static bool bind(void*,uint32_t,const uint32_t*) {return false;}
static bool draw(void*,const Draw&) {return false;}
int main(){
 std::array<uint8_t,128> object{},reference{};std::array<uint8_t,1024> stack{},before_stack{};
 AddressSpace map;CHECK(map.map(0x40001000,object.size(),object.data(),3)==cc::xbox::MemoryError::ok);
 CHECK(map.map(0x70000000,stack.size(),stack.data(),3)==cc::xbox::MemoryError::ok);
 uint64_t state=0x70ab63876984fe23ull;
 for(unsigned i=0;i<4352;++i){
  state^=state<<13;state^=state>>7;state^=state<<17;
  const uint64_t value=i<256?uint64_t(i):state;
  for(unsigned j=0;j<object.size();++j)object[j]=uint8_t(j*19+i);
  for(unsigned j=0;j<stack.size();++j)stack[j]=uint8_t(j*7+i);
  reference=object;before_stack=stack;reference[24]=uint8_t(value);
  Context c{};c.r1.u64=0x70000200;c.r3.u64=0x40001000;c.r4.u64=value;c.lr=0x12345678;
  Context prior=c;
  auto r=invoke(0x8209ce40,c,map,{nullptr,bind,draw});CHECK(r.error==Error::ok);CHECK(!r.submits&&!r.bind_calls&&!r.dispatches);
  CHECK(object==reference);CHECK(stack==before_stack);CHECK(std::memcmp(&c,&prior,sizeof(c))==0);
  r=invoke(0x8209ce48,c,map,{nullptr,bind,draw});CHECK(r.error==Error::ok);CHECK(c.r3.u64==uint8_t(value));
  prior.r3.u64=uint8_t(value);CHECK(std::memcmp(&c,&prior,sizeof(c))==0);CHECK(object==reference);CHECK(stack==before_stack);
 }
 Context c{};c.r1.u64=0x70000200;c.r3.u64=0xfffffff0;c.r4.u64=1;
 CHECK(invoke(0x8209ce40,c,map,{nullptr,bind,draw}).error==Error::context);
 c.r3.u64=0x50001000;CHECK(invoke(0x8209ce48,c,map,{nullptr,bind,draw}).error==Error::memory);
 AddressSpace ro;CHECK(ro.map(0x40001000,object.size(),object.data(),1)==cc::xbox::MemoryError::ok);CHECK(ro.map(0x70000000,stack.size(),stack.data(),3)==cc::xbox::MemoryError::ok);
 c.r3.u64=0x40001000;reference=object;CHECK(invoke(0x8209ce40,c,ro,{nullptr,bind,draw}).error==Error::memory);CHECK(reference==object);
 std::printf("PASS visibility properties=%u cases=4352 (all 256 bytes plus 4096 deterministic 64-bit inputs); no unrequested state writes\n",checks);
}
