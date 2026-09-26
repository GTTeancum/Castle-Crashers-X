// SPDX-License-Identifier: MIT
#include "guest_memory.h"
#include "leaf_bridge.h"
#include <stdio.h>
#include <string.h>
using namespace cc::xbox;
static unsigned assertions;
#define CHECK(x) do { ++assertions; if(!(x)){ fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#x);return 1;} } while(0)
int main() {
  constexpr uint32_t rw=read_access|write_access;uint8_t a[128]{},b[128]{};AddressSpace m;
  CHECK(m.map(0,0,a,rw)==MemoryError::invalid);
  CHECK(m.map(0,1,nullptr,rw)==MemoryError::invalid);
  CHECK(m.map(0,1,a,8)==MemoryError::invalid);
  CHECK(m.map(0xfffffff0u,32,a,rw)==MemoryError::wrap);
  CHECK(m.map(0x82000000u,64,a,rw)==MemoryError::ok);
  CHECK(m.map(0x82000040u,64,b,rw)==MemoryError::ok);
  CHECK(m.map(0x82000000u,1,b,rw)==MemoryError::overlap);
  CHECK(m.map(0x81ffffffu,2,b,rw)==MemoryError::overlap);
  CHECK(m.map(0x8200007fu,2,b,rw)==MemoryError::overlap);
  CHECK(m.map(0xa0000000u,64,a,rw)==MemoryError::ok);
  CHECK(m.map(0xe0000000u,64,a,read_access)==MemoryError::ok);
  CHECK(m.store_be(0x8200003eu,4,0x12345678)==MemoryError::ok);
  CHECK(a[62]==0x12 && a[63]==0x34 && b[0]==0x56 && b[1]==0x78);
  uint64_t v=0;CHECK(m.load_be(0x8200003eu,4,v)==MemoryError::ok && v==0x12345678);
  CHECK(m.store_be(0xa0000000u,8,0x0123456789abcdefull)==MemoryError::ok);
  CHECK(m.load_be(0xe0000000u,8,v)==MemoryError::ok && v==0x0123456789abcdefull);
  CHECK(m.store_be(0xe0000000u,8,0)==MemoryError::readonly && a[1]==0x23);
  CHECK(m.contiguous(0x8200003eu,4,read_access)==nullptr);
  CHECK(m.contiguous(0xa0000000u,8,read_access)==a);
  CHECK(m.contiguous(0xe0000000u,8,write_access)==nullptr);
  CHECK(m.contiguous(0xfffffffcu,8,read_access)==nullptr);
  CHECK(m.read(0,nullptr,0)==MemoryError::ok);
  CHECK(m.write(0,nullptr,1)==MemoryError::invalid);
  uint8_t temp[8]{};memset(b+62,0x99,2);
  CHECK(m.write(0x8200007eu,temp,8)==MemoryError::unmapped);
  CHECK(b[62]==0x99 && b[63]==0x99);
  memset(temp,0x88,8);CHECK(m.read(0x8200007eu,temp,8)==MemoryError::unmapped && temp[0]==0x88);
  CHECK(m.check(0xffffffffu,2,read_access)==MemoryError::wrap);
  CHECK(m.load_be(0x82000000u,3,v)==MemoryError::invalid);
  CHECK(m.map(0xfffffff0u,16,b+64,rw)==MemoryError::ok);
  CHECK(m.store_be(0xfffffff8u,8,0x123456789abcdef0ull)==MemoryError::ok);
  CHECK(m.load_be(0xfffffff8u,8,v)==MemoryError::ok && v==0x123456789abcdef0ull);
  AddressSpace ro;uint8_t r[16]{};
  CHECK(ro.map(0x1000,8,r,rw)==MemoryError::ok);CHECK(ro.map(0x1008,8,r+8,read_access)==MemoryError::ok);
  CHECK(ro.store_be(0x1004,8,~uint64_t(0))==MemoryError::readonly);
  CHECK(r[4]==0 && r[7]==0 && r[8]==0);
  // All capacity slots; insert backwards and test random cross-boundary accesses.
  AddressSpace random;constexpr unsigned slots=AddressSpace::capacity, bytes=slots*8;uint8_t spans[slots][8]{};uint8_t oracle[bytes]{};
  for(unsigned i=slots;i-->0;)CHECK(random.map(0x90000000u+i*8,8,spans[slots-1-i],rw)==MemoryError::ok);
  CHECK(random.map(0x100,1,r,rw)==MemoryError::capacity);
  uint32_t state=0x53465736;
  for(unsigned i=0;i<10000;++i) {
    state^=state<<13;state^=state>>17;state^=state<<5;
    const unsigned width=1u<<((state>>24)&3);const unsigned offset=state%(bytes+1-width);
    const uint64_t value=(uint64_t(state)<<32)|(~state);
    CHECK(random.store_be(0x90000000u+offset,width,value)==MemoryError::ok);
    for(unsigned j=0;j<width;++j)oracle[offset+j]=uint8_t(value>>(8*(width-j-1)));
    uint8_t all[bytes];CHECK(random.read(0x90000000u,all,sizeof(all))==MemoryError::ok);
    CHECK(memcmp(all,oracle,sizeof(all))==0);
    uint64_t expected=0;for(unsigned j=0;j<width;++j)expected=(expected<<8)|oracle[offset+j];
    CHECK(random.load_be(0x90000000u+offset,width,v)==MemoryError::ok && v==expected);
  }
  uint32_t out=0xabcdef01;
  CHECK(run_leaf_820b20c8(m,0x81000000u,0,out)==MemoryError::unmapped && out==0xabcdef01);
  CHECK(run_leaf_820b20c8(m,0xffffffe1u,0,out)==MemoryError::wrap && out==0xabcdef01);
  CHECK(run_leaf_820b20c8(m,0xe0000000u,0,out)==MemoryError::readonly && out==0xabcdef01);
  unsigned cases=0;CHECK(bridge_selftest(&cases) && cases==4096);
  printf("PASS: %u assertions; 10000 memory-model trials; %u original-leaf inputs; sizeof(AddressSpace)=%zu; sizeof(Region)=%zu\n",assertions,cases,sizeof(AddressSpace),sizeof(Region));return 0;
}
