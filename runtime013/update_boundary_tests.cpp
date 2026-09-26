// SPDX-License-Identifier: MIT
// Checkpoint 013: bounded acceptance through map-hit lookup and timeline owner entry.
#include "../runtime008/fixtures.h"
#include "selftest.h"
#include <array>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <vector>
using namespace cc::tree;
static uint64_t assertions = 0;
#define CHECK(x) do { ++assertions; if (!(x)) { \
  std::fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#x); std::exit(1); } } while(0)
static bool bind_ok(void*,uint32_t,const uint32_t[20]) { return true; }
static bool draw_ok(void*,const Draw&) { return true; }
static Sink sink() { return {nullptr,bind_ok,draw_ok}; }
static void store(AddressSpace& m,uint32_t a,unsigned n,uint64_t v) {
  CHECK(m.store_be(a,n,v)==cc::xbox::MemoryError::ok);
}
static void synthetic_controls() {
  std::array<uint8_t,4096> stack{};
  std::array<uint8_t,128> root{};
  std::array<uint8_t,256> nodes{};
  std::array<uint8_t,64> vt{};
  AddressSpace m;
  CHECK(m.map(0x10000,stack.size(),stack.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x20000,root.size(),root.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x21000,nodes.size(),nodes.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x22000,vt.size(),vt.data(),3)==cc::xbox::MemoryError::ok);
  Context c{};
  c.r1.u32=0x10800; c.r3.u32=0x20000; c.f1.f64=1.0/60.0;
  c.r31.u64=0x1122334455667788ull; c.f31.u64=0x8877665544332211ull;
  c.lr=0x12345678;
  const auto initial=c;

  // Visibility must gate the head access: the deliberately unmapped head is never read.
  store(m,0x20000+24,1,0);
  store(m,0x20000+12,4,0xdeadbeef);
  auto r=invoke(0x8209CC98,c,m,sink());
  CHECK(r.error==Error::ok && r.dispatches==0 && r.functions==1);
  CHECK(c.r1.u64==initial.r1.u64 && c.r31.u64==initial.r31.u64 &&
        c.f31.u64==initial.f31.u64 && c.lr==initial.lr);

  // A visible container with no children is also a clean no-op.
  c=initial; store(m,0x20000+24,1,1); store(m,0x20000+12,4,0);
  r=invoke(0x8209CC98,c,m,sink());
  CHECK(r.error==Error::ok && r.dispatches==0 && r.functions==1);

  // Two synthetic container children dispatch the same unchanged original update walker.
  // The child containers are hidden, so the recursive calls terminate immediately.
  store(m,0x20000+12,4,0x21000);
  store(m,0x21000+0,4,0x22000); store(m,0x21000+20,4,0x21080); store(m,0x21000+24,1,0);
  store(m,0x21080+0,4,0x22000); store(m,0x21080+20,4,0); store(m,0x21080+24,1,0);
  store(m,0x22000+8,4,0x8209CC98);
  c=initial; r=invoke(0x8209CC98,c,m,sink());
  CHECK(r.error==Error::ok && r.dispatches==2 && r.functions==3 && r.deepest_dispatch==1);
  CHECK(c.r1.u64==initial.r1.u64 && c.r31.u64==initial.r31.u64 &&
        c.f31.u64==initial.f31.u64 && c.lr==initial.lr);

  // Cycles are rejected in preflight before generated code can loop forever.
  store(m,0x21000+20,4,0x21000); c=initial;
  r=invoke(0x8209CC98,c,m,sink());
  CHECK(r.error==Error::cycle && r.address==0x21000);
}
static void map_hit_and_wrapper_controls() {
  // First prove the unchanged 0x82097720 ordered-map lookup can take a genuine
  // hit path without touching any of its allocation/insertion dependencies.
  {
    std::array<uint8_t,4096> stack{};
    std::array<uint8_t,128> map{};
    std::array<uint8_t,64> sentinel{};
    std::array<uint8_t,64> node{};
    std::array<uint8_t,16> key{};
    AddressSpace m;
    CHECK(m.map(0x70000,stack.size(),stack.data(),3)==cc::xbox::MemoryError::ok);
    CHECK(m.map(0x80000,map.size(),map.data(),3)==cc::xbox::MemoryError::ok);
    CHECK(m.map(0x81000,sentinel.size(),sentinel.data(),3)==cc::xbox::MemoryError::ok);
    CHECK(m.map(0x82000,node.size(),node.data(),3)==cc::xbox::MemoryError::ok);
    CHECK(m.map(0x83000,key.size(),key.data(),3)==cc::xbox::MemoryError::ok);
    store(m,0x80000+4,4,0x81000);
    store(m,0x81000+4,4,0x82000); store(m,0x81000+29,1,1);
    store(m,0x82000+0,4,0x81000); store(m,0x82000+4,4,0x81000);
    store(m,0x82000+8,4,0x81000); store(m,0x82000+12,4,0x44440000);
    store(m,0x82000+29,1,0); store(m,0x83000,4,0x44440000);
    Context c{}; c.r1.u32=0x70800; c.r3.u32=0x80000; c.r4.u32=0x83000;
    auto r=invoke(0x82097720,c,m,sink());
    CHECK(r.error==Error::ok && c.r3.u32==0x82010 && r.functions==1);
  }

  std::array<uint8_t,4096> stack{};
  std::array<uint8_t,128> widget{};
  std::array<uint8_t,12288> owner{};
  std::array<uint8_t,512> manager{};
  std::array<uint8_t,64> sentinel{};
  std::array<uint8_t,64> node{};
  std::array<uint8_t,64> movie{};
  std::array<uint8_t,64> movie_vt{};
  std::array<uint8_t,4> manager_global{};
  std::array<uint8_t,4> active_global{};
  AddressSpace m;
  CHECK(m.map(0x30000,stack.size(),stack.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x40000,widget.size(),widget.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x50000,owner.size(),owner.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x60000,manager.size(),manager.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x61000,sentinel.size(),sentinel.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x61100,node.size(),node.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x62000,movie.size(),movie.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x62100,movie_vt.size(),movie_vt.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x8225e62c,4,manager_global.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x822666dc,4,active_global.data(),3)==cc::xbox::MemoryError::ok);
  Context initial{}; initial.r1.u32=0x30800; initial.r3.u32=0x40000;
  initial.f1.f64=1.0/60.0; initial.r29.u64=0x1111222233334444ull;
  initial.r30.u64=0x5555666677778888ull; initial.r31.u64=0x9999aaaabbbbccccull;
  initial.f31.u64=0x123456789abcdef0ull; initial.lr=0x13572468;

  // Hidden update remains a clean original early-out.
  store(m,0x40000+24,1,0); auto c=initial;
  auto r=invoke(0x8209DE50,c,m,sink());
  CHECK(r.error==Error::ok && r.functions==3 && r.dispatches==0);
  CHECK(c.r1.u64==initial.r1.u64 && c.r29.u64==initial.r29.u64 &&
        c.r30.u64==initial.r30.u64 && c.r31.u64==initial.r31.u64 &&
        c.f31.u64==initial.f31.u64 && c.lr==initial.lr);

  // Depth 15 bypasses the owner-map lookup and now enters the real 0x820915F0
  // body. With an uninitialized owner it hard-stops on the next real helper,
  // 0x82094420, rather than stopping at 0x820915F0 itself.
  store(m,0x40000+24,1,1); store(m,0x40000+96,4,0x50000);
  store(m,0x8225e62c,4,0x60000); store(m,0x60000+72,4,15);
  store(m,0x50000+10316,4,0x0badc0de); store(m,0x50000+10345,1,0);
  c=initial; r=invoke(0x8209DE50,c,m,sink());
  CHECK(r.error==Error::unsupported && r.address==0x82094420);
  uint64_t v=0; CHECK(m.load_be(0x822666dc,4,v)==cc::xbox::MemoryError::ok && v==0x0badc0de);
  CHECK(m.load_be(0x50000+10344,1,v)==cc::xbox::MemoryError::ok && v==1);

  // Empty-depth path with a real synthetic RB-tree hit: wrapper -> exact
  // 0x82097720 hit -> exact 0x820915F0 active-timeline body -> the first
  // unknown movie virtual. The unknown virtual is deliberately a hard dispatch
  // failure; no fake success implementation exists.
  store(m,0x60000+72,4,0);
  // manager+76 is the ordered map; +4 within it is manager+80.
  store(m,0x60000+80,4,0x61000);
  store(m,0x61000+4,4,0x61100); store(m,0x61000+29,1,1);
  store(m,0x61100+0,4,0x61000); store(m,0x61100+4,4,0x61000);
  store(m,0x61100+8,4,0x61000); store(m,0x61100+12,4,0x40000);
  store(m,0x61100+29,1,0);
  store(m,0x50000+10345,1,1); store(m,0x50000+10340,4,0x40000000u); // 2.0f
  store(m,0x50000+0,4,0x62000); store(m,0x62000+0,4,0x62100);
  store(m,0x62100+12,4,0xdead1000u);
  store(m,0x822666dc,4,0);
  c=initial; r=invoke(0x8209DE50,c,m,sink());
  CHECK(r.error==Error::dispatch && r.address==0xdead1000u);
  CHECK(m.load_be(0x60000+88,4,v)==cc::xbox::MemoryError::ok && v==0x61110);
  CHECK(m.load_be(0x822666dc,4,v)==cc::xbox::MemoryError::ok && v==0x0badc0de);
  CHECK(m.load_be(0x50000+10340,4,v)==cc::xbox::MemoryError::ok && v!=0x40000000u);
  std::printf("synthetic_chain map_hit=%08x timeline_virtual=%08x timeline_bits=%08x\n",
              0x61110u, r.address, uint32_t(v));
}
static void captured_startup_boundary(const char* path) {
  std::ifstream stream(path,std::ios::binary);
  CHECK(bool(stream));
  std::vector<uint8_t> bytes((std::istreambuf_iterator<char>(stream)),{});
  Fixtures f; CHECK(parse(bytes.data(),bytes.size(),f)==FixtureError::ok); CHECK(f.count>0);
  auto *w=new Workspace; Case c; CHECK(restore(f,0,*w,c)==FixtureError::ok);
  CHECK(c.entry==0x8209CD08);
  uint64_t head=0,vt=0,update=0;
  CHECK(w->memory.load_be(c.initial.r3.u32+24,1,update)==cc::xbox::MemoryError::ok && update==1);
  CHECK(w->memory.load_be(c.initial.r3.u32+12,4,head)==cc::xbox::MemoryError::ok && head);
  CHECK(w->memory.load_be(uint32_t(head),4,vt)==cc::xbox::MemoryError::ok && vt);
  CHECK(w->memory.load_be(uint32_t(vt)+8,4,update)==cc::xbox::MemoryError::ok);
  CHECK(update==0x8209DE50);
  uint64_t owner_stack=0,owner_depth=0;
  const bool have_owner_stack = w->memory.load_be(0x8225e62c,4,owner_stack)==cc::xbox::MemoryError::ok;
  const bool have_owner_depth = have_owner_stack && w->memory.load_be(uint32_t(owner_stack)+72,4,owner_depth)==cc::xbox::MemoryError::ok;
  std::printf("captured_owner_stack mapped=%u ptr=%08x depth=%u\n",unsigned(have_owner_stack&&have_owner_depth),uint32_t(owner_stack),uint32_t(owner_depth));
  // Run the new original walker against the real captured root. The next original
  // virtual target is intentionally not implemented yet, so this must hard-fail
  // at exactly 0x8209DE50 rather than fake a successful update.
  auto ctx=c.initial; ctx.f1.f64=1.0/60.0;
  auto r=invoke(0x8209CC98,ctx,w->memory,sink());
  CHECK(r.error==Error::memory && r.address==0x8225e62c && r.dispatches==1);
  std::printf("captured_startup root=%08x head=%08x vtable=%08x update=%08x boundary=%s@%08x\n",
              c.initial.r3.u32,uint32_t(head),uint32_t(vt),uint32_t(update),name(r.error),r.address);
  delete w;
}
int main(int argc,char** argv) {
  CHECK(argc==2);
  CHECK(cc::update013::synthetic_chain_test()==cc::update013::synthetic_chain_mask);
  synthetic_controls();
  map_hit_and_wrapper_controls();
  captured_startup_boundary(argv[1]);
  std::printf("PASS update_boundary assertions=%llu originals=8209CC98,8209DE50,82097720,820915F0 next_boundaries=82094420,virtual\n",
              (unsigned long long)assertions);
}
