// SPDX-License-Identifier: MIT
// Checkpoint 012: bounded acceptance for original update-list walker 0x8209CC98.
#include "../runtime008/fixtures.h"
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
static void wrapper_controls() {
  std::array<uint8_t,4096> stack{};
  std::array<uint8_t,128> widget{};
  std::array<uint8_t,12288> owner{};
  std::array<uint8_t,256> manager{};
  std::array<uint8_t,4> manager_global{};
  std::array<uint8_t,4> active_global{};
  AddressSpace m;
  CHECK(m.map(0x30000,stack.size(),stack.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x40000,widget.size(),widget.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x50000,owner.size(),owner.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x60000,manager.size(),manager.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x8225e62c,4,manager_global.data(),3)==cc::xbox::MemoryError::ok);
  CHECK(m.map(0x822666dc,4,active_global.data(),3)==cc::xbox::MemoryError::ok);
  Context initial{}; initial.r1.u32=0x30800; initial.r3.u32=0x40000;
  initial.f1.f64=1.0/60.0; initial.r29.u64=0x1111222233334444ull;
  initial.r30.u64=0x5555666677778888ull; initial.r31.u64=0x9999aaaabbbbccccull;
  initial.f31.u64=0x123456789abcdef0ull; initial.lr=0x13572468;

  // Hidden update takes the unchanged original early-out and restores ABI state.
  store(m,0x40000+24,1,0); auto c=initial;
  auto r=invoke(0x8209DE50,c,m,sink());
  CHECK(r.error==Error::ok && r.functions==3 && r.dispatches==0);
  CHECK(c.r1.u64==initial.r1.u64 && c.r29.u64==initial.r29.u64 &&
        c.r30.u64==initial.r30.u64 && c.r31.u64==initial.r31.u64 &&
        c.f31.u64==initial.f31.u64 && c.lr==initial.lr);

  // Visible object, empty owner-stack path: exact wrapper mutates the real stack
  // manager state then stops at the explicit owner-lookup boundary.
  store(m,0x40000+24,1,1); store(m,0x40000+96,4,0x50000);
  store(m,0x8225e62c,4,0x60000); store(m,0x60000+72,4,0);
  c=initial; r=invoke(0x8209DE50,c,m,sink());
  CHECK(r.error==Error::unsupported && r.address==0x82097720);
  uint64_t v=0; CHECK(m.load_be(0x60000+72,4,v)==cc::xbox::MemoryError::ok && v==1);
  CHECK(m.load_be(0x60000+12,4,v)==cc::xbox::MemoryError::ok && v==0x40000);

  // Depth 15 follows the original guard/no-op helper path, sets the active owner
  // timeline pointer, then hard-stops at the large sub_820915F0 boundary.
  store(m,0x60000+72,4,15); store(m,0x50000+10316,4,0x0badc0de);
  store(m,0x822666dc,4,0); c=initial;
  r=invoke(0x8209DE50,c,m,sink());
  CHECK(r.error==Error::unsupported && r.address==0x820915F0);
  CHECK(m.load_be(0x822666dc,4,v)==cc::xbox::MemoryError::ok && v==0x0badc0de);
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
  synthetic_controls();
  wrapper_controls();
  captured_startup_boundary(argv[1]);
  std::printf("PASS update_boundary assertions=%llu originals=8209CC98,8209DE50 hard_boundaries=82097720,820915F0\n",
              (unsigned long long)assertions);
}
