#include "generated/__savegprlr_29.inc"
#include "generated/__restgprlr_29.inc"
#include "generated/sub_8208C5D8.inc"
#include "generated/sub_8209CC98.inc"

// ReXGlue's generated PPC trap intrinsic is a non-returning failure path. The
// bounded host runtime reports it as context failure; it never converts a trap
// into success. The single exception is trap code 20, the Xbox kernel debug-
// output service reached through exact sub_820B7BC0 (r3=string, r4=length):
// with no debugger attached the retail kernel resumes the title, so the
// bounded runtime logs the message and continues without touching game state.
static void ppc_trap([[maybe_unused]] Context& ctx, Machine& base, uint32_t code) {
  if (code == 20u) {
    const uint32_t len = ctx.r4.u32 <= 512u ? ctx.r4.u32 : 512u;
    std::fprintf(stderr, "GUEST DBGPRINT: ");
    for (uint32_t i = 0; i < len; ++i) {
      const int chv = int(base.load(ctx.r3.u32 + i, 1));
      if (!chv) break;
      std::fputc(chv, stderr);
    }
    std::fputc('\n', stderr);
    return;
  }
  base.fail(Error::context, code);
}

#include "generated/sub_82097720.inc"
#include "generated/__savegprlr_22.inc"
#include "generated/__restgprlr_22.inc"

#define HARD_BOUNDARY(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { \
    base.fail(Error::unsupported, addr); \
  }
HARD_BOUNDARY(sub_820B0F18, 0x820B0F18u)
HARD_BOUNDARY(sub_82084D18, 0x82084D18u)
HARD_BOUNDARY(sub_82084DB8, 0x82084DB8u)
HARD_BOUNDARY(sub_820A71E8, 0x820A71E8u)
HARD_BOUNDARY(sub_82086010, 0x82086010u)
HARD_BOUNDARY(sub_82084C78, 0x82084C78u)
HARD_BOUNDARY(sub_8207B630, 0x8207B630u)
HARD_BOUNDARY(sub_8207B8B8, 0x8207B8B8u)
HARD_BOUNDARY(sub_8207BAE8, 0x8207BAE8u)
HARD_BOUNDARY(sub_82084EE0, 0x82084EE0u)
HARD_BOUNDARY(sub_82098100, 0x82098100u)
HARD_BOUNDARY(sub_82099730, 0x82099730u)
HARD_BOUNDARY(sub_82099C68, 0x82099C68u)
HARD_BOUNDARY(sub_82099B48, 0x82099B48u)
HARD_BOUNDARY(sub_82099BE8, 0x82099BE8u)
HARD_BOUNDARY(sub_82051868, 0x82051868u)
HARD_BOUNDARY(sub_820518E0, 0x820518E0u)
HARD_BOUNDARY(sub_82053380, 0x82053380u)
HARD_BOUNDARY(sub_82084AC8, 0x82084AC8u)
HARD_BOUNDARY(sub_82127468, 0x82127468u)
HARD_BOUNDARY(sub_82074A58, 0x82074A58u)
HARD_BOUNDARY(sub_82074B00, 0x82074B00u)
HARD_BOUNDARY(sub_82078668, 0x82078668u)
HARD_BOUNDARY(sub_820516F8, 0x820516F8u)
HARD_BOUNDARY(sub_82127588, 0x82127588u)
HARD_BOUNDARY(sub_8209A170, 0x8209A170u)
HARD_BOUNDARY(sub_82053888, 0x82053888u)
HARD_BOUNDARY(sub_82053648, 0x82053648u)
HARD_BOUNDARY(sub_8208B8D0, 0x8208B8D0u)
HARD_BOUNDARY(sub_82086D30, 0x82086D30u)
HARD_BOUNDARY(sub_82066EA8, 0x82066EA8u)
HARD_BOUNDARY(sub_8207A1E0, 0x8207A1E0u)
#undef HARD_BOUNDARY

#include "generated/sub_820B5EB8.inc"
#include "generated/sub_8209BDD8.inc"
#include "generated/sub_8209BF18.inc"
#include "generated/__savegprlr_26.inc"
#include "generated/__restgprlr_26.inc"
#include "generated/sub_82099A80.inc"
#include "generated/sub_82099968.inc"
#include "generated/sub_820986F0.inc"
#include "generated/sub_82097AC8.inc"
#include "generated/sub_82075098.inc"
#include "generated/sub_820744C8.inc"
#include "generated/sub_82099680.inc"
#include "generated/sub_82097650.inc"
#include "generated/sub_820701D0_manager_slice.inc"

// Xbox 360's performance/timebase frequency is 49.875 MHz. Keep the platform
// shim paired with a scaled monotonic timebase so generated mftb code observes
// guest-rate ticks rather than the host CPU TSC frequency.
static void __imp__KeQueryPerformanceFrequency(Context& ctx, [[maybe_unused]] Machine& base) {
  ctx.r3.u64 = Machine::timebase_hz;
}
#define REX_QUERY_TIMEBASE() base.query_timebase()
#include "generated/sub_820B6D10.inc"
#include "generated/sub_820B6D48.inc"
#undef REX_QUERY_TIMEBASE

#include "generated/sub_82082390.inc"
#include "generated/sub_8208BE40.inc"
#include "generated/sub_8208AB98.inc"
#include "generated/sub_820936B0.inc"
#include "generated/sub_82094530.inc"
#include "generated/sub_82094420.inc"
#include "generated/sub_820772B0.inc"
#include "generated/sub_820A1AC0.inc"
#include "generated/sub_82088A08.inc"
#include "generated/sub_8208A228.inc"
#include "generated/sub_8208AE78.inc"
#include "generated/sub_820915F0.inc"
#include "generated/sub_8209DE50.inc"


// Checkpoint 016 startup-prefix closure. Exact bodies are copied byte-for-byte
// from the sealed ReXGlue translation units; the two host shims below are
// intentionally narrow platform/CRT boundaries and are not counted as exact bodies.
#include "generated/__savegprlr_23.inc"
#include "generated/__restgprlr_23.inc"
#include "generated/sub_82053A00.inc"

static void sub_82127778(Context& ctx, Machine& base) {
  // WIP 021 second accepted sprintf shape: the sealed shader-path format
  // "game:\shaders\%s" at 0x82042134 with a single bounded string argument,
  // used by exact sub_820AA488 to build shader resource paths. Any other
  // format/argument shape still fails closed.
  if (ctx.r4.u32 == 0x82042134u) {
    static const char prefix_fmt[] = "game:\\shaders\\%s";
    for (unsigned i = 0; i <= sizeof(prefix_fmt) - 1; ++i)
      if (base.load(ctx.r4.u32 + i, 1) != uint8_t(prefix_fmt[i]))
        base.fail(Error::unsupported, 0x82127778u);
    uint32_t out = ctx.r3.u32;
    unsigned written = 0;
    for (const char* p = "game:\\shaders\\"; *p; ++p) {
      base.store(out++, 1, uint8_t(*p));
      ++written;
    }
    for (unsigned i = 0;; ++i) {
      if (i >= 64u) base.fail(Error::unsupported, 0x82127778u);
      const uint8_t chv = uint8_t(base.load(ctx.r5.u32 + i, 1));
      if (!chv) break;
      base.store(out++, 1, chv);
      ++written;
    }
    base.store(out, 1, 0);
    ctx.r3.u64 = written;
    return;
  }
  // WIP 022 third accepted sprintf shape: the sealed font-path format
  // "game:\Fonts\%s.xpr" at 0x820420CC with a single bounded string argument,
  // used by exact sub_820A9B58 to build font resource paths.
  if (ctx.r4.u32 == 0x820420CCu) {
    static const char font_fmt[] = "game:\\Fonts\\%s.xpr";
    for (unsigned i = 0; i <= sizeof(font_fmt) - 1; ++i)
      if (base.load(ctx.r4.u32 + i, 1) != uint8_t(font_fmt[i]))
        base.fail(Error::unsupported, 0x82127778u);
    uint32_t out = ctx.r3.u32;
    unsigned written = 0;
    for (const char* p = "game:\\Fonts\\"; *p; ++p) {
      base.store(out++, 1, uint8_t(*p));
      ++written;
    }
    for (unsigned i = 0;; ++i) {
      if (i >= 64u) base.fail(Error::unsupported, 0x82127778u);
      const uint8_t chv = uint8_t(base.load(ctx.r5.u32 + i, 1));
      if (!chv) break;
      base.store(out++, 1, chv);
      ++written;
    }
    for (const char* p = ".xpr"; *p; ++p) {
      base.store(out++, 1, uint8_t(*p));
      ++written;
    }
    base.store(out, 1, 0);
    ctx.r3.u64 = written;
    return;
  }
  // The only other accepted checkpoint-016 call shape is sprintf-like "%i"
  // used by sub_8209CA70 to create its monotonically numbered startup label.
  if (ctx.r4.u32 != 0x8203DF98u ||
      base.load(ctx.r4.u32 + 0,1) != uint8_t('%') ||
      base.load(ctx.r4.u32 + 1,1) != uint8_t('i') ||
      base.load(ctx.r4.u32 + 2,1) != 0)
    base.fail(Error::unsupported, 0x82127778u);
  char rev[16]{};
  unsigned used=0;
  const int32_t sv=ctx.r5.s32;
  uint32_t mag = sv < 0 ? uint32_t(-int64_t(sv)) : uint32_t(sv);
  do { rev[used++]=char('0'+(mag%10)); mag/=10; } while(mag && used<sizeof(rev));
  uint32_t out=ctx.r3.u32;
  unsigned written=0;
  if (sv < 0) { base.store(out++,1,uint8_t('-')); ++written; }
  while (used) { base.store(out++,1,uint8_t(rev[--used])); ++written; }
  base.store(out,1,0);
  ctx.r3.u64=written;
}

#include "generated/sub_8209CA70.inc"
#include "generated/sub_820783E8.inc"
#include "generated/sub_8209C7A8.inc"
#include "generated/sub_8209C588.inc"
#include "generated/sub_82073ED0.inc"
#include "generated/sub_820745D8.inc"
#include "generated/sub_82053118.inc"
#include "generated/sub_82052EA8.inc"
#include "generated/sub_82075410.inc"

static void __imp__RtlInitializeCriticalSection(Context& ctx, Machine& base) {
  // Startup-prefix proof is single-threaded. The Xbox import receives a
  // 28-byte object here; initialize the owned bytes deterministically. WIP
  // 021 additionally registers the object so the bounded enter/leave shims
  // accept exactly the critical sections exact code created (the CRT heap's
  // lock is the first). The registry is small and fails closed when full.
  const uint32_t p=ctx.r3.u32;
  if (p > 0xffffffe4u) base.fail(Error::context,p);
  for (unsigned i=0;i<28;++i) base.store(p+i,1,0);
  for (uint32_t slot : g_registered_cs)
    if (slot==p) { ctx.r3.u64=0; return; }
  g_registered_cs.push_back(p);
  g_registered_cs_locked.push_back(false);
  ctx.r3.u64=0;
}

#include "generated/sub_82095C20.inc"
#include "generated/sub_8209C340.inc"
#include "generated/sub_8209CED0.inc"
#include "generated/sub_82084BE8.inc"
#include "generated/sub_82079A00.inc"
#include "generated/sub_8207A0D0.inc"
#include "generated/sub_82079F38.inc"
#include "generated/sub_820867B8.inc"
#include "generated/sub_82086BA8.inc"
#include "generated/sub_820869B0.inc"
#include "generated/sub_82094C30.inc"
#include "generated/sub_82129FA0.inc"
#include "generated/sub_8208CFA0.inc"


// Deterministic console-region/platform shims used only by the startup locale
// constructor. They validate the observed call shapes rather than pretending to
// implement the wider Xbox APIs.
static void __imp__ExGetXConfigSetting(Context& ctx, Machine& base) {
  if (ctx.r3.u32 != 3u || ctx.r6.u32 != 4u)
    base.fail(Error::unsupported, 0x8214A554u);
  if (ctx.r5.u32 > 0xfffffffbu || ctx.r7.u32 > 0xfffffffdU)
    base.fail(Error::context, 0x8214A554u);
  if (ctx.r4.u32 == 9u) {
    base.store(ctx.r5.u32,4,0);
    base.store(ctx.r7.u32,2,4);
    ctx.r3.s64 = -1; // startup region fallback path
    return;
  }
  if (ctx.r4.u32 == 10u) {
    // This value is not consumed before the checkpoint-018 graphics boundary;
    // expose a deterministic zero-valued platform setting and the observed size.
    base.store(ctx.r5.u32,4,0);
    base.store(ctx.r7.u32,2,4);
    ctx.r3.s64 = 0;
    return;
  }
  base.fail(Error::unsupported, 0x8214A554u);
}
static void __imp__XGetGameRegion(Context& ctx, [[maybe_unused]] Machine& base) {
  // 0x101 is the original NTSC-U/US region code used by this deterministic fixture.
  ctx.r3.u64 = 0x101u;
}
static void __imp__XNotifyPositionUI(Context& ctx, Machine& base) {
  if (ctx.r3.u32 != 1u) base.fail(Error::unsupported, 0x8214A1F4u);
  ctx.r3.u64 = 0;
}

#include "generated/sub_820B6998.inc"
#include "generated/sub_8209F9F0.inc"
#include "generated/sub_8209D3D8.inc"
#include "generated/sub_8209D538.inc"
#include "generated/sub_82050170.inc"
#include "generated/sub_82050000.inc"
#include "generated/sub_8209D2D0.inc"
#include "generated/sub_8209F7E8.inc"

// Checkpoint 017 thread/platform boundary. The five startup workers are created
// suspended by the original code, assigned priority/affinity, then resumed.
// The host proof records that lifecycle as bounded scheduler state but does not
// execute the worker entry: sub_820B0E80 is an intentional infinite work loop.
static void __imp__ExCreateThread(Context& ctx, Machine& base) {
  const uint32_t out_handle=ctx.r3.u32;
  if (ctx.r7.u32 == 0x820D99B0u || ctx.r7.u32 == 0x820D9A78u) {
    // WIP 022: the exact audio-driver init creates two suspended workers
    // (start routines 0x820D99B0 and 0x820D9A78, no thunk, flags
    // 0x10000001). The bounded scheduler records them exactly like the
    // earlier workers; the asynchronous worker routines are never executed.
    // Observed creation flags pin each worker to its own hardware thread
    // (0x10000001 and 0x20000001) and create it suspended.
    if (ctx.r4.u32!=0u || ctx.r5.u32!=0u || ctx.r6.u32!=0u ||
        ctx.r8.u32!=0u ||
        (ctx.r9.u32!=0x10000001u && ctx.r9.u32!=0x20000001u) ||
        base.thread_count>=base.threads.size())
      base.fail(Error::unsupported,0x8214A5E4u);
    auto &t=base.threads[base.thread_count];
    t.allocated=true; t.suspended=true; t.runnable=false;
    t.handle=0xF1000001u+base.thread_count; t.object=0xF2000001u+base.thread_count;
    t.startup_thunk=0u; t.start_routine=ctx.r7.u32; t.parameter=0u;
    t.priority=0; t.affinity=0x3fu; ++base.thread_count;
    base.store(out_handle,4,t.handle); ctx.r3.s64=0; return;
  }
  if (ctx.r7.u32 == 0x82070828u && ctx.r6.u32 == 0x820B79B8u) {
    // WIP 022: creation of the game's main-loop thread (start routine
    // 0x82070828 through the standard thunk). Recorded suspended like every
    // other worker; the asynchronous routine itself is not run by the
    // diagnostic.
    if (ctx.r4.u32!=0u || ctx.r8.u32!=0u || ctx.r9.u32!=1u ||
        base.thread_count>=base.threads.size())
      base.fail(Error::unsupported,0x8214A5E4u);
    auto &t=base.threads[base.thread_count];
    t.allocated=true; t.suspended=true; t.runnable=false;
    t.handle=0xF1000001u+base.thread_count; t.object=0xF2000001u+base.thread_count;
    t.startup_thunk=ctx.r6.u32; t.start_routine=ctx.r7.u32; t.parameter=ctx.r8.u32;
    t.priority=0; t.affinity=0x3fu; ++base.thread_count;
    base.store(out_handle,4,t.handle); ctx.r3.s64=0; return;
  }
  if (ctx.r6.u32 != 0x820B79B8u)
    base.fail(Error::unsupported, 0x8214A5E4u);
  if (ctx.r7.u32 == 0x820B0E80u) {
    if (ctx.r4.u32 != 0u || ctx.r5.u32 != 0u || ctx.r8.u32 >= 5u || ctx.r9.u32 != 1u ||
        base.thread_count != ctx.r8.u32 || base.thread_count >= 5u)
      base.fail(Error::unsupported, 0x8214A5E4u);
    auto &t=base.threads[base.thread_count];
    t.allocated=true; t.suspended=true; t.runnable=false;
    t.handle=0xF1000001u+base.thread_count; t.object=0xF2000001u+base.thread_count;
    t.startup_thunk=ctx.r6.u32; t.start_routine=ctx.r7.u32; t.parameter=ctx.r8.u32;
    t.priority=0; t.affinity=0x3fu; ++base.thread_count;
    base.store(out_handle,4,t.handle); ctx.r3.s64=0; return;
  }
  if (ctx.r7.u32 == 0x820D7578u) {
    static constexpr uint32_t records[2]={0x02002D5Cu,0x02002DACu};
    if (base.thread_count>=2u || ctx.r4.u32!=0x10000u || ctx.r9.u32!=0u ||
        ctx.r8.u32!=records[base.thread_count] || ctx.r5.u32!=ctx.r8.u32+52u)
      base.fail(Error::unsupported,0x8214A5E4u);
    auto &t=base.threads[base.thread_count];
    t.allocated=true; t.suspended=false; t.runnable=true;
    t.handle=0xF1000001u+base.thread_count; t.object=0xF2000001u+base.thread_count;
    t.startup_thunk=ctx.r6.u32; t.start_routine=ctx.r7.u32; t.parameter=ctx.r8.u32;
    t.priority=0; t.affinity=0x3fu; ++base.thread_count;
    base.store(out_handle,4,t.handle); ctx.r3.s64=0; return;
  }
  base.fail(Error::unsupported,0x8214A5E4u);
}
static void __imp__ObReferenceObjectByHandle(Context& ctx, Machine& base) {
  auto *t=base.by_handle(ctx.r3.u32);
  if (!t || ctx.r4.u32 != 0x0001001Bu || ctx.r5.u32 > 0xfffffffbu)
    base.fail(Error::unsupported, 0x8214A474u);
  base.store(ctx.r5.u32,4,t->object);
  ctx.r3.s64=0;
}
static void __imp__KeSetBasePriorityThread(Context& ctx, Machine& base) {
  auto *t=base.by_object(ctx.r3.u32);
  const bool startup=t && t->start_routine==0x820B0E80u && ctx.r4.s32==-1;
  const bool graphics=t && t->start_routine==0x820D7578u && ctx.r4.s32==17;
  // WIP 022: the exact audio workers are raised to base priority 15, and the
  // main-loop thread to base priority 1.
  const bool audio=t && (t->start_routine==0x820D99B0u ||
                         t->start_routine==0x820D9A78u) && ctx.r4.s32==15;
  const bool mainloop=t && t->start_routine==0x82070828u && ctx.r4.s32==1;
  if (!startup && !graphics && !audio && !mainloop)
    base.fail(Error::unsupported, 0x8214A464u);
  const int32_t old=t->priority; t->priority=ctx.r4.s32; ctx.r3.s64=old;
}
static void __imp__ObDereferenceObject(Context& ctx, Machine& base) {
  if (!base.by_object(ctx.r3.u32))
    base.fail(Error::unsupported, 0x8214A454u);
  ctx.r3.u64=0;
}
static void __imp__KeSetAffinityThread(Context& ctx, Machine& base) {
  auto *t=base.by_object(ctx.r3.u32);
  const uint32_t expected=t ? (1u << (t->parameter+1u)) : 0u;
  if (!t || ctx.r4.u32 != expected || ctx.r5.u32 > 0xfffffffbu)
    base.fail(Error::unsupported, 0x8214A484u);
  base.store(ctx.r5.u32,4,t->affinity);
  t->affinity=ctx.r4.u32;
  ctx.r3.s64=0;
}
static void __imp__NtResumeThread(Context& ctx, Machine& base) {
  auto *t=base.by_handle(ctx.r3.u32);
  if (!t || !t->suspended || ctx.r4.u32 > 0xfffffffbu)
    base.fail(Error::unsupported, 0x8214A4C4u);
  base.store(ctx.r4.u32,4,1u);
  t->suspended=false;
  t->runnable=true;
  ctx.r3.s64=0;
}

// WIP 021: the shader loader's SobelEdge.xpu miss legitimately reaches the
// exact error-translation wrapper, so it is now executed byte-exact. The
// trusted RtlNtStatusToDosError contract accepts only the observed
// STATUS_OBJECT_NAME_NOT_FOUND and maps it to ERROR_FILE_NOT_FOUND.
static void __imp__RtlNtStatusToDosError(Context& ctx, Machine& base) {
  if (ctx.r3.u32 != 0xC0000034u)
    base.fail(Error::unsupported, 0x8214A4E4u);
  ctx.r3.u64 = 2u;
}
#include "generated/sub_820B7290.inc"

#include "generated/sub_820B7350.inc"
#include "generated/sub_820B73C0.inc"
#include "generated/sub_820B5D60.inc"
#include "generated/sub_820B5D70.inc"
#include "generated/sub_820B5E08.inc"
#include "generated/sub_820B6028.inc"
#include "generated/sub_8209D688.inc"
#include "generated/sub_820701D0_startup_full.inc"

// Checkpoint 017 caller-prefix closure. The original caller reaches this code
// only after the complete sub_820701D0 startup initializer. Unused branches in
// sub_8209A728 remain hard boundaries; the observed r3=0 path does not enter them.
#include "generated/__savegprlr_18.inc"
#include "generated/__restgprlr_18.inc"

#define HARD_BOUNDARY_017(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { \
    base.fail(Error::unsupported, addr); \
  }
static void __imp__RtlEnterCriticalSection(Context& ctx, Machine& base) {
  // Critical sections created by exact code through the bounded
  // RtlInitializeCriticalSection contract: single-thread diagnostic, so a
  // registered CS may simply toggle. Recursion is not observed and fails.
  for (unsigned i=0;i<unsigned(g_registered_cs.size());++i) {
    if (g_registered_cs[i]==ctx.r3.u32 && ctx.r3.u32) {
      if (g_registered_cs_locked[i]) base.fail(Error::unsupported,0x8214A434u);
      g_registered_cs_locked[i]=true; ctx.r3.u64=0; return;
    }
  }
  if (base.tile_allocator && ctx.r3.u32 == base.tile_allocator) {
    if (base.tile_cs_locked) base.fail(Error::unsupported,0x8214A434u);
    base.tile_cs_locked=true; ctx.r3.u64=0; return;
  }
  const uint32_t hsio_slot=uint32_t(base.load(0x82000594u,4));
  if (!hsio_slot || ctx.r3.u32!=hsio_slot || base.hsio_cs_locked || base.critical_region_depth!=1u)
    base.fail(Error::unsupported,0x8214A434u);
  base.hsio_cs_locked=true; ctx.r3.u64=0;
}
static void __imp__RtlLeaveCriticalSection(Context& ctx, Machine& base) {
  for (unsigned i=0;i<unsigned(g_registered_cs.size());++i) {
    if (g_registered_cs[i]==ctx.r3.u32 && ctx.r3.u32) {
      if (!g_registered_cs_locked[i]) base.fail(Error::unsupported,0x8214A444u);
      g_registered_cs_locked[i]=false; ctx.r3.u64=0; return;
    }
  }
  if (base.tile_allocator && ctx.r3.u32 == base.tile_allocator) {
    if (!base.tile_cs_locked) base.fail(Error::unsupported,0x8214A444u);
    base.tile_cs_locked=false; ctx.r3.u64=0; return;
  }
  const uint32_t hsio_slot=uint32_t(base.load(0x82000594u,4));
  if (!hsio_slot || ctx.r3.u32!=hsio_slot || !base.hsio_cs_locked || base.critical_region_depth!=1u)
    base.fail(Error::unsupported,0x8214A444u);
  base.hsio_cs_locked=false; ctx.r3.u64=0;
}
HARD_BOUNDARY_017(sub_821287B0, 0x821287B0u)
HARD_BOUNDARY_017(sub_82128A60, 0x82128A60u)
HARD_BOUNDARY_017(sub_820B00D8, 0x820B00D8u)
HARD_BOUNDARY_017(sub_820B0330, 0x820B0330u)
HARD_BOUNDARY_017(sub_820B0D80, 0x820B0D80u)
#include "generated/sub_820B6498.inc"
HARD_BOUNDARY_017(sub_820B02B0, 0x820B02B0u)
HARD_BOUNDARY_017(sub_820A7400, 0x820A7400u)
HARD_BOUNDARY_017(sub_820B0750, 0x820B0750u)
#undef HARD_BOUNDARY_017

#include "generated/sub_8209A728.inc"
#include "generated/sub_8209B458.inc"
#include "generated/sub_820A7668.inc"

// Adapter used by the diagnostic caller slice. The body it invokes is the exact
// original startup initializer already provenance-checked above.
static void sub_820701D0(Context& ctx, Machine& base) {
  sub_820701D0_startup_full(ctx, base);
}
#include "generated/sub_82070AC8_renderer_prefix.inc"

// PlatformRenderer::Init entry. The shim returns one deterministic standard
// 640x480/60-Hz mode descriptor; the exact original code consumes it and builds
// its presentation parameters. The prefix then stops immediately before the
// first graphics-device helper (sub_820BEFD0).
static void __imp__XGetVideoMode(Context& ctx, Machine& base) {
  const uint32_t p=ctx.r3.u32;
  if (p > 0xffffffd0u) base.fail(Error::context,0x8214A214u);
  for (unsigned i=0;i<48;++i) base.store(p+i,1,0);
  base.store(p+0,4,640u);
  base.store(p+4,4,480u);
  base.store(p+20,4,0x42700000u); // 60.0f
  base.store(p+24,4,1u);          // deterministic non-PAL standard token
  ctx.r3.u64=0;
}
#include "generated/sub_820A7990_platform_prefix.inc"
#include "generated/sub_820A7990_platform_post_graphics.inc"
#include "generated/sub_820A85E8.inc"



// Checkpoint 019: graphics/runtime platform boundary. Game-side device/ring setup
// remains exact generated code; only loader/kernel/runtime contracts are modeled.
static void sub_82136670(Context& ctx, Machine& base) {
  ctx.r3.u64=base.graphics_allocate(ctx.r3.u32,ctx.r4.u32);
}
static void sub_82136708(Context& ctx, Machine& base) {
  // Fresh-object ring setup frees four null physical allocations. Non-null free
  // behavior is not observed before this checkpoint boundary.
  if (ctx.r3.u32 != 0u || ctx.r4.u32 != 0xB1800000u)
    base.fail(Error::unsupported,0x82136708u);
  ctx.r3.u64=0;
}
static void __imp__KeGetCurrentProcessType(Context& ctx, [[maybe_unused]] Machine& base) {
  ctx.r3.u64=1u; // normal title process, not the process-type-2 system path
}
static void __imp__VdInitializeEngines(Context& ctx, Machine& base) {
  if (base.graphics_engines_initialized || ctx.r3.u32!=0x1DDD0000u ||
      ctx.r4.u32!=0x820CB900u || ctx.r5.u32!=0u ||
      ctx.r6.u32!=0x82005820u || ctx.r7.u32!=0x82005CA0u)
    base.fail(Error::unsupported,0x8214A8A4u);
  base.graphics_engines_initialized=true; ctx.r3.u64=0;
}
static void __imp__ExRegisterTitleTerminateNotification(Context& ctx, Machine& base) {
  // WIP 022: the exact audio-driver init registers its own static terminate
  // record from the image's data segment; accept exactly that one in
  // addition to the two checkpoint-017 graphics records.
  if (ctx.r3.u32==0x8223595Cu && ctx.r4.u32==1u) { ctx.r3.u64=0; return; }
  const uint32_t want = base.terminate_notifications==0 ? 0x821508E0u : 0x821508F0u;
  if (!base.graphics_engines_initialized || base.terminate_notifications>=2u ||
      ctx.r3.u32!=want || ctx.r4.u32!=1u)
    base.fail(Error::unsupported,0x8214A844u);
  ++base.terminate_notifications; ctx.r3.u64=0;
}
static void __imp__VdSetGraphicsInterruptCallback(Context& ctx, Machine& base) {
  if (!base.graphics_engines_initialized || base.terminate_notifications!=2u ||
      ctx.r3.u32!=0x820C60E0u || ctx.r4.u32<0x02000000u || ctx.r4.u32>=0x02240000u)
    base.fail(Error::unsupported,0x8214A894u);
  base.graphics_interrupt_installed=true; ctx.r3.u64=0;
}
static void __imp__VdSetSystemCommandBufferGpuIdentifierAddress(Context& ctx, Machine& base) {
  if (!base.system_identifier_cleared) {
    if (ctx.r3.u32!=0u) base.fail(Error::unsupported,0x8214A7F4u);
    base.system_identifier_cleared=true; ctx.r3.u64=0; return;
  }
  if (!base.ring_writeback_enabled || base.system_identifier_set ||
      !base.ring_descriptor || ctx.r3.u32!=base.ring_descriptor+8u)
    base.fail(Error::unsupported,0x8214A7F4u);
  base.system_identifier_set=true; ctx.r3.u64=0;
}
static void __imp__MmGetPhysicalAddress(Context& ctx, Machine& base) {
  if (g_graphics_alloc_index!=6u || !base.ring_virtual || ctx.r3.u32!=base.ring_virtual)
    base.fail(Error::unsupported,0x8214A7E4u);
  // The bounded fixture maps its graphics arena in low guest memory, so the
  // physical token is the low 29-bit address used by this original path.
  base.ring_physical=ctx.r3.u32 & 0x1FFFFFFFu;
  ctx.r3.u64=base.ring_physical;
}
static void __imp__VdInitializeRingBuffer(Context& ctx, Machine& base) {
  if (!base.graphics_engines_initialized || !base.ring_physical ||
      ctx.r3.u32!=base.ring_physical || ctx.r4.u32!=12u)
    base.fail(Error::unsupported,0x8214A7D4u);
  base.ring_initialized=true; ctx.r3.u64=0;
}
static void __imp__VdEnableRingBufferRPtrWriteBack(Context& ctx, Machine& base) {
  if (!base.ring_initialized || !base.ring_descriptor)
    base.fail(Error::unsupported,0x8214A7C4u);
  uint32_t q=base.ring_descriptor+60u;
  uint64_t t=__builtin_rotateleft64(uint64_t(q) | (uint64_t(q)<<32),12) & 0xFFFu;
  t=(t+512u) & 0xffffffffu;
  t=__builtin_rotateleft64(uint64_t(uint32_t(t)) | (uint64_t(uint32_t(t))<<32),0) & 0x1000u;
  const uint32_t want=uint32_t(t)+(q & 0x1FFFFFFFu);
  if (ctx.r3.u32!=want) base.fail(Error::unsupported,0x8214A7C4u);
  base.ring_writeback_enabled=true; ctx.r3.u64=0;
}

#define HARD_BOUNDARY_019(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, addr); }
HARD_BOUNDARY_019(sub_820C74D0,0x820C74D0u)
HARD_BOUNDARY_019(sub_820CC318,0x820CC318u)
HARD_BOUNDARY_019(sub_820BECA0,0x820BECA0u)
#include "generated/sub_820C7458.inc"
HARD_BOUNDARY_019(sub_820C7A98,0x820C7A98u)
#undef HARD_BOUNDARY_019

// Checkpoint 020: exact late device-finalization path. The game-side EDRAM
// routine is byte-exact generated code. Only the kernel/platform exports are
// modeled here, and only for the observed sub_820CC100 call shape. Xenia's
// Xbox 360 kernel model reports VdRetrainEDRAMWorker/VdRetrainEDRAM as zero
// and VdIsHSIOTrainingSucceeded as one; unexpected ordering/arguments fail.
static void __imp__KeEnterCriticalRegion(Context& ctx, Machine& base) {
  if (base.critical_region_depth!=0u || base.hsio_cs_locked || base.edram_retrain_calls!=0u)
    base.fail(Error::unsupported,0x8214A924u);
  base.critical_region_depth=1u; ctx.r3.u64=0;
}
static void __imp__KeLeaveCriticalRegion(Context& ctx, Machine& base) {
  const bool checkpoint020_complete =
      !base.edram_suffix021_shape && base.edram_worker_calls==1u &&
      base.edram_retrain_calls==1u;
  const bool suffix021_complete =
      base.edram_suffix021_shape && base.edram_worker_calls==0u &&
      base.edram_retrain_calls==1u;
  const bool frame022_complete =
      base.edram_frame022_shape && base.edram_worker_calls==0u &&
      base.edram_retrain_calls==1u;
  if (base.critical_region_depth!=1u || base.hsio_cs_locked ||
      (!checkpoint020_complete && !suffix021_complete && !frame022_complete))
    base.fail(Error::unsupported,0x8214A8F4u);
  base.critical_region_depth=0u; ctx.r3.u64=0;
}
static void __imp__VdRetrainEDRAMWorker(Context& ctx, Machine& base) {
  if (ctx.r3.u32!=0u || base.critical_region_depth!=1u || !base.hsio_cs_locked ||
      base.edram_worker_calls!=0u || base.edram_retrain_calls!=0u ||
      base.edram_suffix021_shape)
    base.fail(Error::unsupported,0x8214A914u);
  ++base.edram_worker_calls; ctx.r3.u64=0u;
}
static void __imp__VdRetrainEDRAM(Context& ctx, Machine& base) {
  const uint32_t sp=ctx.r1.u32;
  const bool checkpoint020_shape =
      ctx.r3.u32==1u && ctx.r4.u32==sp+80u && ctx.r5.u32==4096u &&
      ctx.r6.u32==sp+84u && ctx.r7.u32==sp+96u && ctx.r8.u32==2048u &&
      base.edram_worker_calls==1u && !base.edram_suffix021_shape;
  // WIP 021: bind the later PlatformRenderer::Init suffix invocation separately
  // rather than broadening the sealed Checkpoint 020 contract. This exact call
  // skips VdRetrainEDRAMWorker because sub_820C0DA8 passes r5=0 to sub_820D19E8.
  const bool suffix021_shape =
      sp==0x0003E210u && uint32_t(ctx.lr)==0x820D1A48u &&
      ctx.r3.u32==0u && ctx.r4.u32==0x0003E260u && ctx.r5.u32==4096u &&
      ctx.r6.u32==0x0003E264u && ctx.r7.u32==0x0003E270u && ctx.r8.u32==2048u &&
      ctx.r9.u32==0x02012320u && ctx.r10.u32==0x0201231Cu &&
      ctx.r11.u32==0u && ctx.r12.u32==0x820C1318u &&
      base.edram_worker_calls==0u && !base.edram_suffix021_shape;
  // WIP 022: the post-Init frame's present path re-enters sub_820D19E8 on its
  // own stack (again with r5=0 skipping the worker), issuing the same
  // r1-relative retrain shape as the WIP 021 suffix from the same call site.
  const bool frame022_shape =
      uint32_t(ctx.lr)==0x820D1A48u &&
      ctx.r3.u32==0u && ctx.r4.u32==sp+80u && ctx.r5.u32==4096u &&
      ctx.r6.u32==sp+84u && ctx.r7.u32==sp+96u && ctx.r8.u32==2048u &&
      base.edram_worker_calls==0u && !base.edram_suffix021_shape;
  if (base.critical_region_depth!=1u || !base.hsio_cs_locked ||
      base.edram_retrain_calls!=0u ||
      (!checkpoint020_shape && !suffix021_shape && !frame022_shape) ||
      uint32_t(base.load(ctx.r4.u32,4))!=0u || uint32_t(base.load(ctx.r6.u32,4))!=0u)
    base.fail(Error::unsupported,0x8214A904u);
  // The Xbox 360 kernel model returns zero and leaves the caller-owned output
  // words/workspace untouched. Zero selects the exact original success branch.
  base.edram_suffix021_shape=suffix021_shape;
  base.edram_frame022_shape=frame022_shape;
  ++base.edram_retrain_calls; ctx.r3.u64=0u;
}
#include "generated/sub_820D19E8.inc"
#include "generated/sub_820BDE48.inc"
static void __imp__VdIsHSIOTrainingSucceeded(Context& ctx, Machine& base) {
  if (base.critical_region_depth!=0u || base.hsio_cs_locked ||
      base.edram_worker_calls!=1u || base.edram_retrain_calls!=1u ||
      base.hsio_status_calls!=0u)
    base.fail(Error::unsupported,0x8214A8B4u);
  ++base.hsio_status_calls; ctx.r3.u64=1u;
}
#include "generated/sub_820D1C08.inc"


// Checkpoint 019: deterministic VdQueryVideoMode contract for the exact
// 640x480/60 host platform fixture already consumed by PlatformRenderer::Init.
// The X_VIDEO_MODE layout is 48 bytes; only fields consumed on this path are
// populated. Unknown mode shapes remain fail-closed.
static void __imp__VdQueryVideoMode(Context& ctx, Machine& base) {
  const bool contiguous = !base.video_mode_queried && ctx.r3.u32 == 0x0003e5a0u;
  bool resumed = false;
  if (!contiguous && !base.video_mode_queried && base.video_flags_queried && base.system_command_buffer_queried &&
      base.vd_swap_called && base.display_mode_set && base.display_info_queried &&
      ctx.r1.u32==0x0003dec0u && ctx.lr==0x820D129Cu &&
      ctx.r3.u32==ctx.r1.u32+112u && ctx.r3.u32==0x0003df30u &&
      ctx.r28.u32==0x02000080u && ctx.r31.u32==0u &&
      ctx.r29.u32==0x028001e0u && ctx.r27.u32==0u &&
      ctx.r26.u32==0x050002d0u && ctx.r20.u32==0x028001e0u &&
      ctx.r15.u32==0x0003e084u && ctx.r14.u32==0x0003e0acu) {
    const uint32_t dev=ctx.r28.u32;
    resumed = uint32_t(base.load(dev+21544u,4))==1280u &&
              uint32_t(base.load(dev+21548u,4))==720u &&
              uint32_t(base.load(dev+21552u,4))==1280u;
  }
  // Exact later refresh performed by sub_820CF728. This is a second video-mode
  // query, so it is keyed to the complete observed suffix state rather than the
  // one-shot initialization form above.
  bool cf728_refresh = false;
  if (!contiguous && !resumed && base.video_mode_queried && base.video_flags_queried &&
      base.system_command_buffer_queried && base.vd_swap_called && base.display_mode_set &&
      base.display_info_queried && base.scaler_command_buffer_initialized &&
      ctx.r1.u32==0x0003e9e0u && ctx.lr==0x820CF77Cu &&
      ctx.r3.u32==0x02005548u && ctx.r31.u32==0x02000080u &&
      ctx.r24.u32==0u && ctx.r30.u32==0x02211000u &&
      ctx.r29.u32==0x28280106u && ctx.r28.u32==640u &&
      ctx.r27.u32==480u && ctx.r26.u32==0x0200361cu && ctx.r25.u32==0x02003b1cu) {
    const uint32_t dev=ctx.r31.u32;
    cf728_refresh = uint32_t(base.load(dev+21544u,4))==1280u &&
                    uint32_t(base.load(dev+21548u,4))==720u &&
                    uint32_t(base.load(dev+21552u,4))==1280u &&
                    uint32_t(base.load(dev+48u,4))==0x020122dcu;
  }
  if (!contiguous && !resumed && !cf728_refresh)
    base.fail(Error::unsupported,0x8214A7A4u);
  for (uint32_t i=0;i<48u;i+=4u) base.store(ctx.r3.u32+i,4,0u);
  base.store(ctx.r3.u32+0u,4,640u);
  base.store(ctx.r3.u32+4u,4,480u);
  base.store(ctx.r3.u32+20u,4,0x42700000u); // 60.0f
  if (resumed || cf728_refresh) base.store(ctx.r3.u32+28u,4,0x0000004au);
  base.video_mode_queried=true;
}


static void __imp__VdGetCurrentDisplayGamma(Context& ctx, Machine& base) {
  if (base.display_gamma_queried || ctx.r3.u32>0xfffffffbu || ctx.r4.u32>0xfffffffbu)
    base.fail(Error::unsupported,0x8214A814u);
  // Xbox contract: type 1 = sRGB. Power is ignored by this type, but the
  // deterministic platform fixture reports Xenia's documented default.
  base.store(ctx.r3.u32,4,1u);
  base.store(ctx.r4.u32,4,0x400e38e4u);
  base.display_gamma_queried=true;
  ctx.r3.u64=0u;
}

static void __imp__VdQueryVideoFlags(Context& ctx, Machine& base) {
  // The API query itself is valid independently of XGetVideoMode. Most earlier
  // device-init use runs in one Machine invocation and therefore carries the
  // video_mode_queried marker. WIP 021 resumes the still-live original caller
  // through a fresh host Machine while preserving guest memory, so accept only
  // that one exact resumed call shape as the equivalent durable state.
  if (base.video_flags_queried)
    base.fail(Error::unsupported,0x8214A8C4u);
  const bool contiguous = base.video_mode_queried;
  bool resumed = false;
  if (!contiguous && ctx.r1.u32==0x0003DF70u && ctx.lr==0x820CFD30u &&
      ctx.r26.u32==0x02000080u && ctx.r31.u32==0x0200361Cu &&
      ctx.r4.u32==640u && ctx.r5.u32==480u) {
    const uint32_t dev=ctx.r26.u32;
    resumed = uint32_t(base.load(dev+21544u,4))==1280u &&
              uint32_t(base.load(dev+21548u,4))==720u &&
              uint32_t(base.load(dev+21552u,4))==1280u;
  }
  if (!contiguous && !resumed)
    base.fail(Error::unsupported,0x8214A8C4u);
  base.video_flags_queried=true;
  // Exact observed path consumes only bit 0; the trusted standard-mode fixture
  // reports no special flag.
  ctx.r3.u64=0u;
}
static void __imp__VdCallGraphicsNotificationRoutines(Context& ctx, Machine& base) {
  const uint32_t p=ctx.r4.u32;
  if (base.graphics_notification_sent || ctx.r3.u32!=1u || p>0xffffffc0u)
    base.fail(Error::unsupported,0x8214A8D4u);
  const uint16_t w=uint16_t(base.load(p+0u,2)), h=uint16_t(base.load(p+2u,2));
  const uint16_t dw=uint16_t(base.load(p+4u,2)), dh=uint16_t(base.load(p+6u,2));
  if (w!=640u || h!=480u || dw!=640u || dh!=480u)
    base.fail(Error::unsupported,0x8214A8D4u);
  base.graphics_notification_sent=true;
  ctx.r3.u64=0u;
}

// sub_820D62F8 contains PPC atomic/global-lock operations absent from the
// reduced host Context. Model only its exact fresh 6,144-tile allocator
// behavior reached by the sealed presentation path; unexpected requests fail.
static void sub_820D62F8(Context& ctx, Machine& base) {
  const uint32_t request=ctx.r3.u32, out=ctx.r4.u32;
  if (!base.video_mode_queried || request!=240u || out>0xfffffffbu)
    base.fail(Error::unsupported,0x820D62F8u);
  if (!base.tile_allocator) {
    const uint32_t p=base.graphics_allocate(804u,0x64800000u);
    base.tile_allocator=p;
    for (uint32_t i=0;i<804u;++i) base.store(p+i,1,0u);
    base.store(p+28u,4,6144u);
    base.store(p+800u,4,0x55555555u);
    base.store(0x8223191cu,4,p);
  }
  if (base.tile_next>6144u-request) base.fail(Error::unsupported,0x820D62F8u);
  const uint32_t start=base.tile_next;
  for (uint32_t i=0;i<request;++i) {
    const uint32_t tile=start+i, a=base.tile_allocator+32u+(tile/32u)*4u;
    uint32_t w=uint32_t(base.load(a,4));
    w |= 0x80000000u >> (tile%32u);
    base.store(a,4,w);
  }
  base.tile_next+=request;
  base.store(base.tile_allocator+28u,4,6144u-base.tile_next);
  base.store(out,4,start);
  ctx.r3.u64=1u;
}

#define HARD_RESOURCE_BOUNDARY_019(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, addr); }
HARD_RESOURCE_BOUNDARY_019(sub_820D62A8,0x820D62A8u)
// (sub_82136390 XMemCpy is now included exact, in the WIP 021 section)
HARD_RESOURCE_BOUNDARY_019(sub_820C90E0,0x820C90E0u)
HARD_RESOURCE_BOUNDARY_019(sub_820BDD78,0x820BDD78u)
#undef HARD_RESOURCE_BOUNDARY_019

static void __imp__KiApcNormalRoutineNop(Context& ctx, Machine& base) {
  if (ctx.r4.u32!=19u || ctx.r3.u32>0xffffffb3u)
    base.fail(Error::unsupported,0x8214A7B4u);
  static constexpr uint32_t fixed[] = {
    0xC0114800u,1023u,0u,0u
  };
  for (unsigned i=0;i<4;++i)
    if (uint32_t(base.load(ctx.r3.u32+i*4,4))!=fixed[i])
      base.fail(Error::unsupported,0x8214A7B4u);
  // Words 4..11 are copied verbatim by original code from sealed image
  // 0x8200176C; validate the copy instead of inventing their meaning.
  for (unsigned i=0;i<8;++i) {
    uint32_t a=uint32_t(base.load(0x8200176Cu+i*4,4));
    uint32_t b=uint32_t(base.load(ctx.r3.u32+(4u+i)*4,4));
    if (a!=b) base.fail(Error::unsupported,0x8214A7B4u);
  }
  if (uint32_t(base.load(ctx.r3.u32+48,4))!=0x00010800u ||
      uint32_t(base.load(ctx.r3.u32+52,4))!=7u)
    base.fail(Error::unsupported,0x8214A7B4u);
  for (unsigned i=14;i<19;++i)
    if (base.load(ctx.r3.u32+i*4,4)!=0) base.fail(Error::unsupported,0x8214A7B4u);
  // Xbox kernel export 479 is named KiApcNormalRoutineNop in the generated
  // import table. The bounded contract is therefore no observable mutation.
}

#include "generated/sub_82136728.inc"
#include "generated/sub_820BEF28.inc"
#include "generated/sub_820BEF80.inc"
#include "generated/sub_820CC088.inc"
#include "generated/sub_820CBFF0.inc"
#include "generated/sub_820C5EE8.inc"
#include "generated/sub_820C5F98.inc"
#include "generated/sub_820C73F0.inc"
#include "generated/sub_820C7548.inc"
#include "generated/sub_820BEAC8.inc"
#include "generated/sub_820D7708.inc"
#include "generated/__savegprlr_17.inc"
#include "generated/__restgprlr_17.inc"
#include "generated/sub_820BF5E0.inc"
#include "generated/sub_820BF8D0.inc"
#include "generated/sub_820BF930.inc"
#include "generated/sub_820D7920.inc"

#include "generated/__savegprlr_14.inc"
#include "generated/__restgprlr_14.inc"
#include "generated/__savegprlr_16.inc"
#include "generated/__restgprlr_16.inc"
#include "generated/sub_820C2EF8.inc"
#include "generated/sub_820C2F80.inc"
#include "generated/sub_820C2E60.inc"
#include "generated/sub_820C30A0.inc"
#include "generated/sub_820C2DF0.inc"
#include "generated/sub_820C3EF8.inc"
#include "generated/sub_820C4210.inc"
#include "generated/sub_820C44A0.inc"
#include "generated/sub_820C45C0.inc"
#include "generated/__savefpr_26.inc"
#include "generated/__restfpr_26.inc"
#include "generated/sub_820BB3B8.inc"
#include "generated/sub_820BD978.inc"
#include "generated/sub_820BDF40.inc"
#include "generated/sub_820BE1A8.inc"
#include "generated/sub_820BE248.inc"
#include "generated/sub_820BE2D8.inc"
#include "generated/sub_820BE620.inc"
#include "generated/sub_820CFD98.inc"
#include "generated/sub_820CFC70.inc"
#include "generated/sub_820CFE10.inc"
#include "generated/sub_820D1938.inc"
#include "generated/sub_820D19B8.inc"
#include "generated/__savefpr_28.inc"
#include "generated/__restfpr_28.inc"
#include "generated/sub_8212AA90.inc"
#include "generated/sub_82130550.inc"
#include "generated/sub_8212DEE8.inc"
#include "generated/sub_8212DE48.inc"
#include "generated/sub_8212B1A8.inc"
#include "generated/sub_8212DE20.inc"
#include "generated/sub_8212AB00.inc"
#include "generated/sub_8212AC88.inc"
#include "generated/sub_820C8A90.inc"
#include "generated/sub_820C8B40.inc"
#include "generated/sub_820C8BF0.inc"
#include "generated/sub_820C8D78.inc"
#include "generated/sub_820C9090.inc"
#include "generated/sub_820BDCA8.inc"
#include "generated/sub_820CBBF0.inc"
#include "generated/sub_820CC100.inc"
#include "generated/sub_820BEFD0.inc"

// Checkpoint 020 exact GPU-state setter fanout and adjacent helpers.
#include "generated/sub_820BB6A8.inc"
#include "generated/sub_820BB6D8.inc"
#include "generated/sub_820BB708.inc"
#include "generated/sub_820BB740.inc"
#include "generated/sub_820BB7D0.inc"
#include "generated/sub_820BB860.inc"
#include "generated/sub_820BB8F0.inc"
#include "generated/sub_820BB980.inc"
#include "generated/sub_820BB9F0.inc"
#include "generated/sub_820BBA60.inc"
#include "generated/sub_820BBAD0.inc"
#include "generated/sub_820BBB68.inc"
#include "generated/sub_820BBBC8.inc"
#include "generated/sub_820BBBF8.inc"
#include "generated/sub_820BBCF8.inc"
#include "generated/sub_820BBD30.inc"
#include "generated/sub_820BBDA0.inc"
#include "generated/sub_820BBDD0.inc"
#include "generated/sub_820BBE10.inc"
#include "generated/sub_820BBE40.inc"
#include "generated/sub_820BBE78.inc"
#include "generated/sub_820BBEB8.inc"
#include "generated/sub_820BBEF0.inc"
#include "generated/sub_820BBF20.inc"
#include "generated/sub_820BBF58.inc"
#include "generated/sub_820BBF90.inc"
#include "generated/sub_820BBFC0.inc"
#include "generated/sub_820BBFF0.inc"
#include "generated/sub_820BC028.inc"
#include "generated/sub_820BC060.inc"
#include "generated/sub_820BC090.inc"
#include "generated/sub_820BC0B0.inc"
#include "generated/sub_820BC0D0.inc"
#include "generated/sub_820BC0F0.inc"
#include "generated/sub_820BC110.inc"
#include "generated/sub_820BC130.inc"
#include "generated/sub_820BC150.inc"
#include "generated/sub_820BC1A8.inc"
#include "generated/sub_820BC270.inc"
#include "generated/sub_820BC318.inc"
#include "generated/sub_820BC348.inc"
#include "generated/sub_820BC368.inc"
#include "generated/sub_820BC3A8.inc"
#include "generated/sub_820BC3E8.inc"
#include "generated/sub_820BC428.inc"
#include "generated/sub_820BC468.inc"
#include "generated/sub_820BC478.inc"
#include "generated/sub_820BC4D0.inc"
#include "generated/sub_820BC520.inc"
#include "generated/sub_820BC570.inc"
#include "generated/sub_820BC590.inc"
#include "generated/sub_820BC5B8.inc"
#include "generated/sub_820BC5E0.inc"
#include "generated/sub_820BC608.inc"
#include "generated/sub_820BC630.inc"
#include "generated/sub_820BC658.inc"
#include "generated/sub_820BC680.inc"
#include "generated/sub_820BC6A0.inc"
#include "generated/sub_820BC6C0.inc"
#include "generated/sub_820BC6E8.inc"
#include "generated/sub_820BC710.inc"
#include "generated/sub_820BC738.inc"
#include "generated/sub_820BC760.inc"
#include "generated/sub_820BC788.inc"
#include "generated/sub_820BC7B0.inc"
#include "generated/sub_820BC8D0.inc"
#include "generated/sub_820BC920.inc"
#include "generated/sub_820BC9B8.inc"
#include "generated/sub_820BCA50.inc"
#include "generated/sub_820BCAE8.inc"
#include "generated/sub_820BCB80.inc"
#include "generated/sub_820BCBB8.inc"
#include "generated/sub_820BCBF0.inc"
#include "generated/sub_820BCC28.inc"
#include "generated/sub_820BCC60.inc"
#include "generated/sub_820BCC90.inc"
#include "generated/sub_820BCCB8.inc"
#include "generated/sub_820BCCE8.inc"
#include "generated/sub_820BCD20.inc"
#include "generated/sub_820BCD50.inc"
#include "generated/sub_820BCD80.inc"
#include "generated/sub_820BCDA8.inc"
#include "generated/sub_820BCDD8.inc"
#include "generated/sub_820BCE08.inc"
#include "generated/sub_820BCE70.inc"
#include "generated/sub_820BCEA0.inc"
#include "generated/sub_820BCED0.inc"
#include "generated/sub_820BCF00.inc"
#include "generated/sub_820BCF20.inc"
#include "generated/sub_820BCF30.inc"
#include "generated/sub_820BCF50.inc"
#include "generated/sub_820BD050.inc"
#include "generated/sub_820BD0F8.inc"
#include "generated/sub_820BD1F8.inc"
#include "generated/sub_820BD298.inc"
#include "generated/sub_820BD2F0.inc"
#include "generated/sub_820BD398.inc"
#include "generated/sub_820BD410.inc"
#include "generated/sub_820BD4B8.inc"
#include "generated/sub_820BD558.inc"
#include "generated/sub_820BD5D8.inc"
#include "generated/sub_820BD658.inc"
#include "generated/sub_820BD6C8.inc"
#include "generated/sub_820BD718.inc"
#include "generated/sub_820BD768.inc"
#include "generated/sub_820BD7B8.inc"
#include "generated/sub_820BD810.inc"
#include "generated/sub_820BD868.inc"
#include "generated/sub_820BD8C0.inc"
#include "generated/sub_820BD918.inc"
#include "generated/sub_820BE198.inc"
#include "generated/sub_820CB988.inc"
#include "generated/sub_820C46F8.inc"
#include "generated/sub_820C9150.inc"
#include "generated/sub_820C0530.inc"
#include "generated/sub_820C0248.inc"
#include "generated/sub_820BF0A8.inc"
#include "generated/sub_820BF7B8.inc"

// Checkpoint 020 reduced-host implementation of exact sub_820C6088 semantics.
// The generated body uses PPC ldarx/stdcx plus MSR/global-lock helpers that the
// reduced Context intentionally does not model. On this single-threaded host
// fixture its observable contract is an atomic 64-bit exchange with
// 0x00000000FFFFFFFF, returning the old low/high words through r4/r5.
static void sub_820C6088(Context& ctx, Machine& base) {
  base.prologue(__func__,ctx);
  const uint32_t src=ctx.r3.u32, lo=ctx.r4.u32, hi=ctx.r5.u32;
  if (src>0xfffffff7u || lo>0xfffffffbu || hi>0xfffffffbu)
    base.fail(Error::context,0x820C6088u);
  const uint64_t old=base.load(src,8);
  base.store(src,8,0x00000000FFFFFFFFull);
  base.store(lo,4,uint32_t(old));
  base.store(hi,4,uint32_t(old>>32));
  ctx.r9.u64=old;
  ctx.r10.u64=old;
  ctx.r11.u64=uint32_t(old>>32);
}

// Compile-time fail-closed imports used only by deeper branches of this exact
// command-buffer family. A branch reaching one must establish its observed
// platform/CRT contract before execution can proceed.
static void __imp__KeDelayExecutionThread([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A614u); }
static void __imp__KfReleaseSpinLock([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A744u); }
static void __imp__KfAcquireSpinLock([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A754u); }
static void __imp___vsnprintf([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A834u); }
static void __imp__DbgPrint([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A5A4u); }
static void __imp__sprintf([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8214A804u); }

static uint32_t checkpoint020_mm_load_u32(Machine& base, uint32_t a) {
  if (a>=0x7F000000u && a<0x80000000u) {
    // WIP 022: exact sub_820DA1E8 snapshots the APU's XMA context-array
    // register at power-on before any audio setup; the observed hardware
    // reset value is zero. All other MMIO reads stay fail-closed.
    if (a==0x7FEA1800u) return 0u;
    base.fail(Error::unsupported,a);
  }
  return uint32_t(base.load(a,4));
}
static void checkpoint020_mm_store_u32(Machine& base, uint32_t a, uint32_t v) {
  if (a>=0x7F000000u && a<0x80000000u) {
    // Observed CP_RB_WPTR write: Xenos MMIO base 0x7FC80000 + register 0x714.
    // The current ring has 8192 dwords, so reject any unobserved/out-of-ring value.
    if (a!=0x7FC80714u || v>=8192u) base.fail(Error::unsupported,a);
    base.cp_rb_wptr=v; ++base.cp_rb_wptr_writes;
    // WIP 022: the fixture Xenos consumes every submitted command
    // synchronously at the doorbell. The exact ring-space wait
    // (sub_820C6B18 -> sub_820BE9F0) compares the descriptor's read-index
    // writeback word against the device's submission phase; publish the
    // caught-up value exactly as the hardware writeback would.
    {
      const uint32_t dev=0x02000080u;
      const uint32_t desc=uint32_t(base.load(dev+10896u,4));
      const uint32_t phase=uint32_t(base.load(dev+10908u,4));
      if (desc) base.store(desc,4,phase);
    }
    return;
  }
  base.store(a,4,v);
}
#define REX_MM_LOAD_U32(a) checkpoint020_mm_load_u32(base,uint32_t(a))
#define REX_MM_STORE_U32(a,v) checkpoint020_mm_store_u32(base,uint32_t(a),uint32_t(v))
#define REX_QUERY_TIMEBASE() base.query_timebase()
// Checkpoint 020 exact command-buffer / flush family from sub_820C7228.
#include "generated/__restgprlr_19.inc"
#include "generated/__savegprlr_19.inc"
#include "generated/sub_820B6068.inc"
#include "generated/sub_820B74B0.inc"
#include "generated/sub_820BE8F8.inc"
#include "generated/sub_820BE928.inc"
#include "generated/sub_820BE9F0.inc"
#include "generated/sub_820C5E50.inc"
#include "generated/sub_820C6178.inc"
#include "generated/sub_820C6218.inc"
#include "generated/sub_820C6290.inc"
#include "generated/sub_820C64C0.inc"
#include "generated/sub_820C65A8.inc"
#include "generated/sub_820C6790.inc"
#include "generated/sub_820C6950.inc"
#include "generated/sub_820C6A40.inc"
#include "generated/sub_820C6B18.inc"
#include "generated/sub_820C6E68.inc"
#include "generated/sub_820C6F68.inc"
#include "generated/sub_820C70A0.inc"
#include "generated/sub_820C7228.inc"
#include "generated/sub_820C7988.inc"
#include "generated/sub_820C7B48.inc"
#include "generated/sub_820C7BF8.inc"
#include "generated/sub_820CB088.inc"
#include "generated/sub_820CB108.inc"
#include "generated/sub_820CB370.inc"
#include "generated/sub_820CB468.inc"
#include "generated/sub_820CB7F8.inc"
#include "generated/sub_820CCB40.inc"
#include "generated/sub_820D6470.inc"
#include "generated/sub_82128830.inc"

#undef REX_QUERY_TIMEBASE // checkpoint020-c7228
#undef REX_MM_STORE_U32
#undef REX_MM_LOAD_U32

// Checkpoint 020 late device finalization exact bodies.
#include "generated/sub_820CDD68.inc"

// Checkpoint 021 focused PlatformRenderer::Init suffix probe. Specialized
// adjacent helpers remain fail-closed until the observed sub_820C1F58 branch
// proves they are needed.
static void sub_8212A8B8([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x8212A8B8u); }
static void sub_820C48C8([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C48C8u); }
#include "generated/sub_820C4AF8.inc"
#include "generated/sub_820C19C8.inc"
#include "generated/sub_820C1CB8.inc"
#include "generated/sub_820D4298.inc"
#include "generated/sub_820C1F58.inc"
#include "generated/sub_820D3FE8.inc"
#include "generated/sub_820D4630.inc"
#include "generated/sub_820C24C0.inc"
#include "generated/sub_820C2B70.inc"
#include "generated/sub_820C2C98.inc"

// WIP 021: exact next PlatformRenderer::Init suffix body and the first
// adjacent command-state chain actually reached from it. Later direct callees
// remain fail-closed until execution proves they are required.
#include "generated/sub_820CDFB0.inc"
#include "generated/sub_820CC568.inc"
#include "generated/sub_820C6BE8.inc"
#include "generated/sub_820C08B8.inc"
static void sub_820C3A30([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C3A30u); }
#include "generated/sub_820C4878.inc"
static void sub_820C49D8([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C49D8u); }
static void sub_820C4F20([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C4F20u); }
#include "generated/sub_820C4FF8.inc"
#include "generated/sub_820BE228.inc"
// WIP 021: exact opening of the presentation/swap path.  All adjacent
// helpers/platform imports not yet proven on the observed path stay fail-closed.
static void sub_820D3B88([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D3B88u); }
static void sub_820D2E58([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D2E58u); }
static void sub_820D3280([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D3280u); }
#include "generated/sub_820D3EF8.inc"

#include "generated/sub_820CDF20.inc"
// WIP 021: exact post-swap display-mode/display-info helper. Platform imports
// remain fail-closed until this exact observed call shape reaches them.
static void __imp__VdSetDisplayMode(Context& ctx, Machine& base) {
  if (!base.vd_swap_called || base.display_mode_set || ctx.r3.u32 != 0x40000000u)
    base.fail(Error::unsupported, 0x8214A884u);
  base.display_mode_set = true;
  ctx.r3.u64 = 0u;
}
// WIP 021: one-shot observed VdGetCurrentDisplayInformation contract. The
// exact post-swap caller provides a stack-local 0x58-byte X_DISPLAY_INFO.
// Trusted kernel-model evidence zeroes the block and reports its current
// 1280x720 mode. Only the three fields consumed by exact sub_820CBF48 are
// populated here; every other call order/pointer remains fail-closed.
static void __imp__VdGetCurrentDisplayInformation(Context& ctx, Machine& base) {
  if (!base.vd_swap_called || !base.display_mode_set || base.display_info_queried ||
      ctx.r1.u32 != 0x0003E9E0u || ctx.r3.u32 != ctx.r1.u32 + 80u ||
      ctx.r3.u32 != 0x0003EA30u)
    base.fail(Error::unsupported, 0x8214A874u);
  const uint32_t p = ctx.r3.u32;
  if (p > 0xFFFFFFA7u)
    base.fail(Error::context, 0x8214A874u);
  for (uint32_t i = 0; i < 0x58u; i += 4u)
    base.store(p + i, 4, 0u);
  // X_DISPLAY_INFO offsets consumed by exact sub_820CBF48.
  base.store(p + 0x48u, 2, 1280u);  // display_width
  base.store(p + 0x4Au, 2, 720u);   // display_height
  base.store(p + 0x56u, 2, 1280u);  // actual_display_width
  base.display_info_queried = true;
  ctx.r3.u64 = 0u;
}
#include "generated/sub_820CBF48.inc"
#include "generated/sub_820C0BC0.inc"
// WIP 021: exact sub_820D1788; adjacent unobserved edges remain fail-closed.
#include "generated/sub_820D0008.inc"
static void sub_820D0238([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D0238u); }
static void sub_820D0720([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D0720u); }
static void sub_820D0898([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D0898u); }
static void sub_820D08F0([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820D08F0u); }
#include "generated/sub_820D09F8.inc"
#include "generated/__savefpr_22.inc"
#include "generated/__restfpr_22.inc"
#include "generated/sub_820D0B00.inc"
#include "generated/sub_82129EF8.inc"
#include "generated/sub_820D02C0.inc"
#include "generated/sub_820D0F80.inc"
#include "generated/sub_820D1260.inc"
// WIP 021: exact observed Xbox kernel RtlFillMemoryUlong contract reached by
// exact sub_820D1788. Xbox/Xenia RTL semantics fill Length>>2 ULONGs with the
// supplied guest-endian pattern. This diagnostic shim accepts only the single
// observed aligned stack-local call and rejects every other shape.
static void __imp__RtlFillMemoryUlong(Context& ctx, Machine& base) {
  constexpr uint32_t kDestination = 0x0003E0D0u;
  constexpr uint32_t kLength = 800u;
  constexpr uint32_t kPattern = 0x80000000u;
  if (ctx.r1.u32 != 0x0003E010u || ctx.r3.u32 != kDestination ||
      ctx.r3.u32 != ctx.r1.u32 + 192u || ctx.r4.u32 != kLength ||
      ctx.r5.u32 != kPattern || (ctx.r3.u32 & 3u) || (ctx.r4.u32 & 3u))
    base.fail(Error::unsupported, 0x8214A6C4u);
  if (base.memory.check(kDestination, kLength, cc::xbox::write_access) !=
      cc::xbox::MemoryError::ok)
    base.fail(Error::memory, kDestination);
  for (uint32_t i = 0; i < kLength; i += 4u)
    base.store(kDestination + i, 4, kPattern);
}
// WIP 021: one-shot observed VdInitializeScalerCommandBuffer contract reached
// by exact sub_820D1788. Xenia's Xbox 360 kernel model exposes the same
// 12-argument ABI and, for this import, fills dest_count words at dest_ptr with
// type-2 GPU NOP 0x80000000 and returns dest_count. Model only the exact Castle
// Crashers call shape observed here; every other stack/register/order shape is
// fail-closed.
static void __imp__VdInitializeScalerCommandBuffer(Context& ctx, Machine& base) {
  constexpr uint32_t kStack = 0x0003E010u;
  constexpr uint32_t kVerticalParams = kStack + 156u;
  constexpr uint32_t kHorizontalParams = kStack + 172u;
  constexpr uint32_t kUnknownBlock = kStack + 992u;
  constexpr uint32_t kDestination = kStack + 192u;
  constexpr uint32_t kCount = 200u;
  if (!base.vd_swap_called || !base.display_mode_set || !base.display_info_queried ||
      base.scaler_command_buffer_initialized || ctx.r1.u32 != kStack ||
      ctx.r3.u32 != 0x00000000u || ctx.r4.u32 != 0x028001E0u ||
      ctx.r5.u32 != 0x00000000u || ctx.r6.u32 != 0x050002D0u ||
      ctx.r7.u32 != 0x028001E0u || ctx.r8.u32 != 1u ||
      ctx.r9.u32 != kVerticalParams || ctx.r10.u32 != 1u ||
      base.load(kStack + 84u,4) != kHorizontalParams ||
      base.load(kStack + 92u,4) != kUnknownBlock ||
      base.load(kStack + 100u,4) != kDestination ||
      base.load(kStack + 108u,4) != kCount)
    base.fail(Error::unsupported, 0x8214A8E4u);
  if (base.memory.check(kDestination, kCount * 4u, cc::xbox::write_access) !=
      cc::xbox::MemoryError::ok)
    base.fail(Error::memory, kDestination);
  for (uint32_t i=0; i<kCount; ++i)
    base.store(kDestination + i*4u, 4, 0x80000000u);
  base.scaler_command_buffer_initialized = true;
  ctx.r3.u64 = kCount;
}
#include "generated/sub_820D1788.inc"
#include "generated/sub_820C0A98.inc"
#include "generated/sub_820C8E98.inc"
static void sub_820C8F90([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C8F90u); }
#include "generated/sub_820C0580.inc"
#include "generated/sub_820C0B40.inc"
static void sub_820CF038([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820CF038u); }
#include "generated/sub_820CF728.inc"
// WIP 021: exact sub_820CF9D0 recovered byte-for-byte. Adjacent direct
// callees remain hard boundaries until the exact observed branch reaches them.
static void sub_820CE088([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820CE088u); }
static void sub_820C91C0([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C91C0u); }
static void sub_820C9348([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C9348u); }
static void sub_820C9968([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820C9968u); }
// WIP 021: exact sub_820CF858 and its observed first direct callee
// sub_821368C0 are both recovered byte-for-byte. The observed loader state makes
// sub_821368C0 return zero, so CF858 skips sub_820CD258; keep that later
// conditional callee fail-closed until an exact path actually reaches it.
#include "generated/sub_821368C0.inc"
static void sub_820CD258([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported,0x820CD258u); }
#include "generated/sub_820CF858.inc"
#define REX_QUERY_TIMEBASE() base.query_timebase()
#include "generated/sub_820CF9D0.inc"
#undef REX_QUERY_TIMEBASE
// WIP 021: one-shot observed VdGetSystemCommandBuffer contract. The exact
// caller supplies two stack output locations. Trusted Xbox 360 kernel-model
// evidence used by this project reports a 0x94-byte system-command block whose
// first dword is 0xBEEF0000 plus companion dword 0xBEEF0001. Model only this
// exact call shape and fail closed on every other invocation.
static void __imp__VdGetSystemCommandBuffer(Context& ctx, Machine& base) {
  // WIP 022 second observed query: the post-Init frame path (exact
  // sub_820D3EF8 at lr=0x820C0FB0) re-reads the system command buffer with
  // the same output layout on its own frame.
  if (uint32_t(ctx.lr)==0x820C0FB0u &&
      ctx.r3.u32==ctx.r1.u32+208u && ctx.r4.u32==ctx.r1.u32+116u) {
    const uint32_t p0=ctx.r3.u32, p1=ctx.r4.u32;
    if (p0>0xffffff6bu || p1>0xfffffffbu)
      base.fail(Error::context,0x8214A784u);
    for (uint32_t i=0;i<0x94u;i+=4u) base.store(p0+i,4,0u);
    base.store(p0,4,0xBEEF0000u);
    base.store(p1,4,0xBEEF0001u);
    base.system_command_buffer_queried=true;
    ctx.r3.u64=0u;
    return;
  }
  if (base.system_command_buffer_queried || ctx.r1.u32!=0x0003EAA0u ||
      ctx.r3.u32!=ctx.r1.u32+208u || ctx.r4.u32!=ctx.r1.u32+116u)
    base.fail(Error::unsupported,0x8214A784u);
  const uint32_t p0=ctx.r3.u32, p1=ctx.r4.u32;
  if (p0>0xffffff6bu || p1>0xfffffffbu)
    base.fail(Error::context,0x8214A784u);
  for (uint32_t i=0;i<0x94u;i+=4u) base.store(p0+i,4,0u);
  base.store(p0,4,0xBEEF0000u);
  base.store(p1,4,0xBEEF0001u);
  base.system_command_buffer_queried=true;
  ctx.r3.u64=0u;
}
// WIP 021: one-shot observed VdSwap contract. Xenia's Xbox 360 kernel model
// validates the D3D texture-header fetch, front-buffer metadata and 640x480
// dimensions, then writes a 64-dword swap command block. This host fixture has
// no kernel MMU/physical mapper, so only the observed low-memory identity map
// (frontbuffer virtual == deterministic fixture physical) is accepted.
static void __imp__VdSwap(Context& ctx, Machine& base) {
  // WIP 022: the observed swap call shape is frame-relative ??? the exact
  // caller (sub_820C7458 at lr=0x820C1014) always passes the fetch block at
  // r1+0x80, sysbuf tokens at r1+0xD0/r1+0x74, and metadata pointers at
  // r1+0x6C/0x70/0x68. Checkpoint 020's one-shot swap targeted the scaler
  // command region (0x0200F950); the post-Init frame writes its swap block
  // through the ring write-pointer window instead. Both are accepted under
  // the same content validation below; everything else fails closed.
  const bool ring_target = ctx.r3.u32 >= 0x0201F000u && ctx.r3.u32 <= 0x0202F000u;
  if (!base.system_command_buffer_queried ||
      (base.vd_swap_called && !ring_target) ||
      (ctx.r3.u32 != 0x0200F950u && !ring_target) ||
      ctx.r4.u32 != ctx.r1.u32 + 0x80u || ctx.r5.u32 != 0x0220F148u ||
      ctx.r6.u32 != ctx.r1.u32 + 0xD0u || ctx.r7.u32 != 0xBEEF0001u ||
      ctx.r8.u32 != ctx.r1.u32 + 0x6Cu || ctx.r9.u32 != ctx.r1.u32 + 0x70u ||
      ctx.r10.u32 != ctx.r1.u32 + 0x68u)
    base.fail(Error::unsupported, 0x8214A774u);

  const uint32_t width_ptr = uint32_t(base.load(ctx.r1.u32 + 84u, 4));
  const uint32_t height_ptr = uint32_t(base.load(ctx.r1.u32 + 92u, 4));
  if (width_ptr != ctx.r1.u32 + 96u || height_ptr != ctx.r1.u32 + 100u)
    base.fail(Error::unsupported, 0x8214A774u);

  uint32_t fetch[6]{};
  for (uint32_t i = 0; i < 6u; ++i)
    fetch[i] = uint32_t(base.load(ctx.r4.u32 + i * 4u, 4));

  const uint32_t frontbuffer = uint32_t(base.load(ctx.r8.u32, 4));
  const uint32_t texture_format = uint32_t(base.load(ctx.r9.u32, 4));
  const uint32_t color_space = uint32_t(base.load(ctx.r10.u32, 4));
  const uint32_t width = uint32_t(base.load(width_ptr, 4));
  const uint32_t height = uint32_t(base.load(height_ptr, 4));
  const uint32_t sys0 = uint32_t(base.load(ctx.r6.u32, 4));
  const uint32_t sys1 = uint32_t(base.load(ctx.r1.u32 + 116u, 4));

  const uint32_t fetch_frontbuffer = ((fetch[1] >> 12) & 0xFFFFFu) << 12;
  const uint32_t fetch_width = (fetch[2] & 0x1FFFu) + 1u;
  const uint32_t fetch_height = ((fetch[2] >> 13) & 0x1FFFu) + 1u;
  if (fetch[0] != 0x85000002u || fetch[1] != 0x02211006u ||
      fetch[2] != 0x003BE27Fu || fetch[3] != 0x00001414u ||
      fetch[4] != 0u || fetch[5] != 0x00000200u ||
      fetch_frontbuffer != 0x02211000u || frontbuffer != fetch_frontbuffer ||
      texture_format != 6u || (fetch[1] & 0x3Fu) != texture_format ||
      color_space != 0u || width != 640u || height != 480u ||
      width != fetch_width || height != fetch_height ||
      sys0 != 0xBEEF0000u || sys1 != 0xBEEF0001u)
    base.fail(Error::unsupported, 0x8214A774u);

  // Final 64-dword block matching the trusted kernel model for this exact
  // observed call. The fixture's deterministic low address is used unchanged
  // as the platform physical address; this is not a general Xbox MMU model.
  const uint32_t buffer = ctx.r3.u32;
  base.store(buffer + 0u * 4u, 4, 0x00054800u);  // type0 FETCH_00_0, 6 dwords
  for (uint32_t i = 0; i < 6u; ++i)
    base.store(buffer + (1u + i) * 4u, 4, fetch[i]);
  base.store(buffer + 7u * 4u, 4, 0xC0036400u);  // type3 XE_SWAP, 4 dwords
  base.store(buffer + 8u * 4u, 4, 0x53574150u);  // 'SWAP'
  base.store(buffer + 9u * 4u, 4, frontbuffer);  // identity only for this fixture
  base.store(buffer + 10u * 4u, 4, width);
  base.store(buffer + 11u * 4u, 4, height);
  for (uint32_t i = 12u; i < 64u; ++i)
    base.store(buffer + i * 4u, 4, 0x80000000u);  // type2 NOP

  base.vd_swap_called = true;
}
static void __imp__VdPersistDisplay(Context& ctx, Machine& base) {
  // Xenia's xboxkrnl model for this Xbox 360 export returns TRUE and writes a
  // 64-byte, 32-byte-aligned no-access allocation through its second argument;
  // the exact Castle Crashers caller immediately passes that token to
  // MmFreePhysicalMemory(1, token). Bind only the single observed call shape.
  if (base.persist_display_called || !base.vd_swap_called ||
      ctx.r1.u32 != 0x0003EAA0u || uint32_t(ctx.lr) != 0x820C12E4u ||
      ctx.r3.u32 != 0x0003EB58u || ctx.r4.u32 != 0x0003EB40u ||
      ctx.r5.u32 != 0u || ctx.r6.u32 != 0x02211000u ||
      ctx.r7.u32 != 0x020122ECu || ctx.r8.u32 != 0x0003EB58u ||
      ctx.r9.u32 != 0xFFFFFFFEu || ctx.r10.u32 != 0x00001E4Eu)
    base.fail(Error::unsupported,0x8214A764u);

  // Exact caller code cleared this 12-byte input block before the import.
  if (base.load(ctx.r3.u32 + 0u, 4) != 0u ||
      base.load(ctx.r3.u32 + 4u, 4) != 0u ||
      base.load(ctx.r3.u32 + 8u, 4) != 0u)
    base.fail(Error::unsupported,0x8214A764u);

  // The platform allocation is deliberately represented as an opaque,
  // deterministic no-access token in the diagnostic fixture. The address is
  // 32-byte aligned and is not mapped as guest-readable/writable memory.
  constexpr uint32_t token = 0x02600000u;
  base.persist_display_called = true;
  base.persist_display_allocation = token;
  base.store(ctx.r4.u32, 4, token);
  ctx.r3.u64 = 1u;
}
static void __imp__MmFreePhysicalMemory(Context& ctx, Machine& base) {
  // Bind only the physical allocation created by the immediately preceding
  // observed VdPersistDisplay call. The trusted xboxkrnl contract requires a
  // 32-byte-aligned address and releases that allocation; this diagnostic
  // fixture represents it as an opaque no-access token rather than mapped
  // guest memory.
  if (!base.persist_display_called || base.persist_display_freed ||
      base.persist_display_allocation != 0x02600000u ||
      ctx.r1.u32 != 0x0003EAA0u || uint32_t(ctx.lr) != 0x820C12F8u ||
      ctx.r3.u32 != 1u || ctx.r4.u32 != base.persist_display_allocation ||
      ctx.r5.u32 != 0u || ctx.r6.u32 != 0x02211000u ||
      ctx.r7.u32 != 0x020122ECu || ctx.r8.u32 != 0x0003EB58u ||
      ctx.r9.u32 != 0xFFFFFFFEu || ctx.r10.u32 != 0x00001E4Eu ||
      (ctx.r4.u32 & 0x1Fu) != 0u ||
      base.memory.check(ctx.r4.u32, 64u, 1u) == cc::xbox::MemoryError::ok)
    base.fail(Error::unsupported,0x8214A504u);

  base.persist_display_freed = true;
  base.persist_display_allocation = 0u;
}

#include "generated/sub_820C0DA8.inc"
#include "generated/sub_820C13B8.inc"

// WIP 021 sub_820A7990-suffix boundaries: descriptor/resource helpers called
// by exact sub_820AA5B8 that are not yet recovered. Each hard-fails rather
// than simulating success.
#define HARD_BOUNDARY_021(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { \
    base.fail(Error::unsupported, addr); \
  }
// (sub_820C0440 is now included exact, below)
// (sub_820C0330 is now included exact, below)
#undef HARD_BOUNDARY_021

#include "generated/sub_820AA5B8.inc"

// Descriptor-parse helpers reached by exact sub_820AA488; unrecovered callees
// stay fail-closed.
#define HARD_BOUNDARY_021B(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { \
    base.fail(Error::unsupported, addr); \
  }
HARD_BOUNDARY_021B(sub_820B6190, 0x820B6190u)
#undef HARD_BOUNDARY_021B

// The bounded NtReadFile contract completes synchronously, so the exact read
// wrapper's pending-wait branch is never reached; it stays fail-closed.
static void __imp__NtWaitForSingleObjectEx([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214A514u);
}
#include "generated/sub_820B6310.inc"
#include "generated/sub_82138200.inc"
#include "generated/sub_82136390.inc"
#include "generated/sub_820BFDF0.inc"
#include "generated/sub_820C0440.inc"
#include "generated/sub_820C0330.inc"
#include "generated/sub_820C00D0.inc"
#include "generated/sub_820C01C0.inc"
#include "generated/sub_820A8190.inc"
#include "generated/sub_820BFEE8.inc"
#include "generated/sub_820BFC30.inc"
#include "generated/sub_820C00B8.inc"

// WIP 022: sub_82070AC8 caller continuation after the completed
// PlatformRenderer::Init. Exact sub_8209BC98 -> sub_820B6108 request the
// title's main physical pool through MmAllocatePhysicalMemoryEx; the bounded
// contract below serves it from the dedicated fixture arena and fails closed
// outside the observed shape.
static void __imp__MmAllocatePhysicalMemoryEx(Context& ctx, Machine& base) {
  // Bounded physical-memory contract. Two observed request families:
  //  - the single 16 MiB title main pool (flags 0, size 0x01000FFF,
  //    PAGE_READWRITE, no bounds, 4 KiB alignment), served once at
  //    0x10000000;
  //  - font/texture blocks (flags 0, PAGE_READWRITE or write-combined
  //    0x404, no bounds, <=4 MiB), served from the cursor arena at
  //    0x12000000.
  if (ctx.r3.u32!=0u || ctx.r6.u32!=0u || ctx.r7.u32!=0xFFFFFFFFu)
    base.fail(Error::unsupported, 0x8214A4F4u);
  if (ctx.r4.u32==0x01000FFFu && ctx.r5.u32==4u && ctx.r8.u32==0x1000u &&
      !g_main_pool_allocated) {
    const uint32_t p=0x10000000u;
    if (base.memory.check(p,0x01001000u,3)!=cc::xbox::MemoryError::ok)
      base.fail(Error::memory,p);
    g_main_pool_allocated=true;
    ctx.r3.u64=p;
    return;
  }
  if ((ctx.r5.u32==4u || ctx.r5.u32==0x404u) && ctx.r4.u32>=0x1000u &&
      ctx.r4.u32<=0x400000u) {
    const uint32_t align = ctx.r8.u32 ? ctx.r8.u32 : 0x1000u;
    if (align & (align-1u))
      base.fail(Error::unsupported, 0x8214A4F4u);
    const uint32_t size=(ctx.r4.u32+0xFFFu)&~0xFFFu;
    const uint32_t p=(g_phys_cursor+align-1u)&~(align-1u);
    if (p+size<p || base.memory.check(p,size,3)!=cc::xbox::MemoryError::ok)
      base.fail(Error::memory,p);
    g_phys_cursor=p+size;
    ctx.r3.u64=p;
    return;
  }
  std::fprintf(stderr,
    "MMALLOCPHYSEX unsupported r3=%08x r4=%08x r5=%08x r6=%08x r7=%08x r8=%08x lr=%08x\n",
    ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32, ctx.r8.u32,
    uint32_t(ctx.lr));
  base.fail(Error::unsupported, 0x8214A4F4u);
}
#include "generated/sub_820B6108.inc"
#include "generated/sub_8209BC98.inc"
#include "generated/__savegprlr_15.inc"
#include "generated/__restgprlr_15.inc"
#include "generated/sub_820C2D58.inc"
#include "generated/sub_820C3568.inc"
#include "generated/sub_820C7D48.inc"
#include "generated/sub_820C3930.inc"
#include "generated/sub_820C4488.inc"
#include "generated/sub_820C4498.inc"
#include "generated/sub_820D7D70.inc"
#include "generated/sub_820A7390.inc"
#include "generated/sub_820A9B58.inc"
#include "generated/sub_820BFB50.inc"
#include "generated/sub_820A7E80.inc"
#include "generated/sub_820A8030.inc"
#include "generated/sub_820A8010.inc"

// WIP 022 caller-tail closures: worker notification (exact sub_82096828),
// manager registration (exact sub_820756E0), and the semaphore-backed event
// wrapper (exact sub_820B5F50 family). NtCreateSemaphore is observed-shape
// bound below.
static void __imp__NtCreateSemaphore(Context& ctx, Machine& base) {
  // Bounded event/semaphore fixture: the exact sub_820B5F50 wrapper creates
  // one semaphore (initial 0, limit 1) through the OBJECT_ATTRIBUTES block
  // built by exact sub_820B73D0. Handles are opaque tokens; waits on them
  // remain fail-closed.
  if (ctx.r5.u32>ctx.r6.u32 || ctx.r6.u32==0u || ctx.r6.u32>0x7FFFFFFFu ||
      g_semaphore_count>=8u)
    base.fail(Error::unsupported, 0x8214A4A4u);
  base.store(ctx.r3.u32,4,0x0F5E0001u+g_semaphore_count);
  ++g_semaphore_count;
  ctx.r3.u64=0u;
}
// WIP 022 notification-listener service creation (exact sub_820D7FD0 family).
// KeInitializeSemaphore models the trusted kernel object initialization; the
// other kernel entries observed on this path are bound elsewhere or fail
// closed until observed.
// Single-threaded diagnostic models of the raised-IRQL spinlock family used
// by the exact audio-driver init. IRQL raise/lower and lock acquire/release
// are balance-checked; contention cannot occur with one thread.
static void __imp__KeRaiseIrqlToDpcLevel(Context& ctx, [[maybe_unused]] Machine& base) {
  // Nested raises are legal; return the previous level and go to DISPATCH.
  ctx.r3.u64=g_irql_level;
  g_irql_level=2u;
}
static void __imp__KfLowerIrql(Context& ctx, Machine& base) {
  if (ctx.r3.u32>2u) base.fail(Error::unsupported, 0x8214A80Cu);
  g_irql_level=ctx.r3.u32;
}
static void __imp__KeAcquireSpinLockAtRaisedIrql(Context& ctx, Machine& base) {
  if (g_irql_level==0u || uint32_t(base.load(ctx.r3.u32,4))!=0u)
    base.fail(Error::unsupported, 0x8214A81Cu);
  base.store(ctx.r3.u32,4,1u);
}
static void __imp__KeReleaseSpinLockFromRaisedIrql(Context& ctx, Machine& base) {
  if (g_irql_level==0u || uint32_t(base.load(ctx.r3.u32,4))!=1u)
    base.fail(Error::unsupported, 0x8214A794u);
  base.store(ctx.r3.u32,4,0u);
}
// Trusted kernel contract: set the dispatcher event's SignalState and return
// the previous state. No waiter dispatch occurs in the single-threaded
// diagnostic; the exact worker threads are recorded but never run.
static void __imp__KeSetEvent(Context& ctx, Machine& base) {
  const uint32_t old=uint32_t(base.load(ctx.r3.u32+4,4));
  base.store(ctx.r3.u32+4,4,1u);
  ctx.r3.u64=old;
}
// Kernel XAudio render-driver boundary. Registration is observed-shape
// bound; frame submission and unregistration stay fail-closed until the
// diagnostic actually reaches them.
static void __imp__XAudioRegisterRenderDriverClient(Context& ctx, Machine& base) {
  // Bound to the single observed registration: callback 0x820E2B30 with the
  // exact driver-object context. The fixture kernel never pumps the render
  // callback (no audio hardware), matching the never-run worker model. The
  // returned client token is opaque to the exact code.
  if (uint32_t(base.load(ctx.r3.u32,4))!=0x820E2B30u || ctx.r4.u32==0u ||
      g_xaudio_client_registered)
    base.fail(Error::unsupported, 0x8214ABE4u);
  g_xaudio_client_registered=true;
  base.store(ctx.r4.u32,4,0x0A0D1001u);
  ctx.r3.u64=0u;
}
static void __imp__XAudioSubmitRenderDriverFrame([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214AA24u);
}
static void __imp__XAudioUnregisterRenderDriverClient([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214AA34u);
}
static void __imp__KeInitializeSemaphore(Context& ctx, Machine& base) {
  base.store(ctx.r3.u32+0,1,5u);            // SemaphoreObject type
  base.store(ctx.r3.u32+1,1,0u);
  base.store(ctx.r3.u32+2,2,20u/4u);        // size in dwords
  base.store(ctx.r3.u32+4,4,ctx.r4.u32);    // SignalState = initial count
  base.store(ctx.r3.u32+8,4,ctx.r3.u32+8);  // wait list head -> self
  base.store(ctx.r3.u32+12,4,ctx.r3.u32+8);
  base.store(ctx.r3.u32+16,4,ctx.r5.u32);   // Limit
}
static void __imp__KeResumeThread(Context& ctx, Machine& base) {
  auto *t=base.by_object(ctx.r3.u32);
  if (!t || !t->suspended)
    base.fail(Error::unsupported, 0x8214A954u);
  t->suspended=false;
  t->runnable=true;
  ctx.r3.u64=1u;
}
#define REX_MM_LOAD_U32(a) checkpoint020_mm_load_u32(base,uint32_t(a))
#define REX_MM_STORE_U32(a,v) checkpoint020_mm_store_u32(base,uint32_t(a),uint32_t(v))
// Generated mfmsr/mtmsrd interrupt-mask sequences: the single-threaded host
// has no interrupts to mask, so the global lock is a no-op and the check
// returns the context's MSR mirror (preserving the exact data flow).
#define REX_CHECK_GLOBAL_LOCK() (ctx.msr)
#define REX_ENTER_GLOBAL_LOCK() do {} while (0)
#define REX_LEAVE_GLOBAL_LOCK() do {} while (0)
#include "generated/sub_820D7FD0.inc"
#include "generated/sub_820DA1E8.inc"
#include "generated/sub_820DA0E8.inc"
#include "generated/sub_820D9D48.inc"
#include "generated/sub_820D9C40.inc"
#include "generated/sub_820D8FA8.inc"
#include "generated/sub_820E35E8.inc"
#include "generated/sub_820E29D0.inc"
#include "generated/sub_820E3040.inc"
#include "generated/sub_820DB8B8.inc"
#include "generated/sub_820D87C0.inc"
#include "generated/sub_820DB880.inc"
#include "generated/sub_820E2978.inc"
#include "generated/sub_820E3548.inc"
#include "generated/sub_820E3498.inc"
#include "generated/sub_820E2700.inc"
#include "generated/sub_820E2BF0.inc"
#include "generated/sub_820E2EB8.inc"
#include "generated/sub_820E4410.inc"
#include "generated/sub_820DB6F8.inc"
#include "generated/sub_820DB698.inc"
#include "generated/sub_820DC848.inc"
#include "generated/sub_820E0A48.inc"
#include "generated/sub_820E4C88.inc"
#include "generated/sub_820E40C0.inc"
#include "generated/sub_820E4510.inc"
#include "generated/sub_820E2688.inc"
#include "generated/sub_820DB278.inc"
#include "generated/sub_820E4278.inc"
#include "generated/sub_820DB298.inc"
#include "generated/sub_820E31D8.inc"
#include "generated/sub_820A7480.inc"
#include "generated/sub_820DBF00.inc"
#include "generated/sub_820DCAF8.inc"
#include "generated/sub_820E2D18.inc"
#include "generated/sub_820E2D70.inc"
#include "generated/sub_820E2F50.inc"
#include "generated/sub_820E2960.inc"
#include "generated/sub_820E3FD8.inc"
#include "generated/sub_820E46A0.inc"
#include "generated/sub_820E2B40.inc"
#include "generated/sub_820E2838.inc"
#include "generated/sub_820E0770.inc"
#include "generated/sub_820E0790.inc"
#include "generated/sub_820E07F8.inc"
#include "generated/sub_820E0960.inc"
#include "generated/sub_820E0988.inc"
#include "generated/sub_820E0998.inc"
#include "generated/sub_820E09A0.inc"
#include "generated/sub_820E0B70.inc"
#include "generated/sub_820E0C70.inc"
#include "generated/sub_820E0D00.inc"
#include "generated/sub_820E0D08.inc"
#include "generated/sub_820E15E0.inc"
#include "generated/sub_820EAAA8.inc"
#include "generated/sub_820E26D0.inc"
#include "generated/sub_820E15E8.inc"
#include "generated/sub_820DBEE0.inc"
#include "generated/sub_820DBEF0.inc"
#include "generated/sub_820DCAE8.inc"
#include "generated/sub_820E0978.inc"
#include "generated/sub_820E2820.inc"
#include "generated/sub_820E2A50.inc"
#include "generated/sub_820E2BC0.inc"
#include "generated/sub_820E4310.inc"
#include "generated/sub_820E43D8.inc"
#include "generated/sub_820E2A60.inc"
#include "generated/sub_820E48C8.inc"
#include "generated/sub_820E41A8.inc"
#include "generated/sub_820D8C70.inc"

#include "generated/sub_820E32D0.inc"
#include "generated/sub_820E0388.inc"
#include "generated/sub_820E3148.inc"
#include "generated/sub_820E3160.inc"
#include "generated/sub_820E32E8.inc"
#include "generated/sub_820E32F8.inc"
#include "generated/sub_820E8D30.inc"
#include "generated/sub_820E0A00.inc"
#include "generated/sub_820D8A48.inc"
#include "generated/sub_820516F0.inc"
#include "generated/sub_820E3300.inc"
#include "generated/sub_820D8DF8.inc"
#include "generated/sub_820E2808.inc"
#include "generated/sub_820DB2B8.inc"
#include "generated/sub_820D8E50.inc"
#include "generated/sub_820D8A68.inc"
#include "generated/sub_820D9D18.inc"
#include "generated/sub_820E33D0.inc"
#include "generated/sub_820E3448.inc"
#include "generated/sub_820DC858.inc"
#include "generated/sub_820D94F8.inc"
#include "generated/sub_820E3248.inc"
#include "generated/sub_820E1FD0.inc"
#include "generated/sub_820B6020.inc"
#include "generated/sub_820DB258.inc"
#include "generated/sub_820D9470.inc"
#include "generated/sub_820B7448.inc"
#include "generated/sub_820B7428.inc"
#undef REX_MM_STORE_U32
#undef REX_MM_LOAD_U32

#include "generated/sub_8213ACB0.inc"
#include "generated/sub_8213AEE0.inc"
#include "generated/sub_820D84A8.inc"
#include "generated/sub_820D8580.inc"
#include "generated/sub_820B73D0.inc"
#include "generated/sub_820B5F50.inc"
#include "generated/sub_820756E0.inc"
#include "generated/sub_82096828.inc"
// WIP 022: fail-closed XAM/Live kernel imports referenced by the family
// below; each is bound to its observed shape only when the diagnostic
// actually reaches it.
static void __imp__NtReleaseSemaphore([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A4B4u); }
static void __imp__XMsgInProcessCall([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA84u); }
static void __imp__XNotifyGetNext([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A204u); }
static void __imp__XamAlloc([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AAA4u); }
static void __imp__XamContentClose([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A324u); }
static void __imp__XamContentCreateEx([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A314u); }
static void __imp__XamFree([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA94u); }
static void __imp__XamLoaderLaunchTitle([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A354u); }
static void __imp__XamUserCreateStatsEnumerator([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A284u); }
static void __imp__NetDll_WSACleanup([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AAE4u); }
static void __imp__NetDll_WSAGetLastError([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB94u); }
static void __imp__NetDll_WSASendTo([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB84u); }
static void __imp__NetDll_WSAStartup(Context& ctx, Machine& base) {
  // Title-caller startup succeeds; the WSADATA output is zero-filled and
  // versioned 2.2. Every later socket operation remains fail-closed.
  if (ctx.r3.u32!=1u) base.fail(Error::unsupported, 0x8214AAD4u);
  for (uint32_t i=0;i<0x190u;i+=4u) base.store(ctx.r5.u32+i,4,0u);
  base.store(ctx.r5.u32,2,0x0202u);
  base.store(ctx.r5.u32+2,2,0x0202u);
  ctx.r3.u64=0u;
}
static void __imp__NetDll_XNetCleanup([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A9C4u); }
static void __imp__NetDll_XNetGetConnectStatus([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA24u); }
static void __imp__NetDll_XNetGetOpt([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA74u); }
static void __imp__NetDll_XNetQosListen([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA34u); }
static void __imp__NetDll_XNetQosRelease([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA54u); }
static void __imp__NetDll_XNetRandom([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A9D4u); }
static void __imp__NetDll_XNetStartup(Context& ctx, Machine& base) {
  // Title-caller startup succeeds; every later XNet operation remains
  // fail-closed. The parameter block is read-only input.
  if (ctx.r3.u32!=1u) base.fail(Error::unsupported, 0x8214A9B4u);
  ctx.r3.u64=0u;
}
static void __imp__NetDll_XNetUnregisterInAddr([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AA04u); }
static void __imp__NetDll_closesocket([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AB04u); }
static void __imp__NtClearEvent([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AD24u); }
static void __imp__NtCreateEvent([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A544u); }
static void __imp__NtDuplicateObject([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A674u); }
static void __imp__XMsgCancelIORequest([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A3C4u); }
static void __imp__XMsgStartIORequest([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A224u); }
static void __imp__XamContentCreateEnumerator([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A344u); }
static void __imp__XamContentGetLicenseMask([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A334u); }
static void __imp__XamEnumerate([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A364u); }
static void __imp__XamGetExecutionId([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A414u); }
static void __imp__XamGetSystemVersion(Context& ctx, [[maybe_unused]] Machine& base) {
  // Trusted XAM contract: returns the packed system version. The retained
  // Checkpoint 011 kit's dashboard lineage is 2.0.17559.0; the exact caller
  // only compares major/minor fields.
  ctx.r3.u64 = (2u<<28) | (0u<<24) | (17559u<<8);
}
static void __imp__XamNotifyCreateListener(Context& ctx, Machine& base) {
  // One observed listener over notification areas mask 3. The fixture hands
  // back an opaque handle; the listener is never signaled, and polls of it
  // are bound where observed.
  if (ctx.r3.u32!=3u || g_xam_listener_created)
    base.fail(Error::unsupported, 0x8214A3B4u);
  g_xam_listener_created=true;
  ctx.r3.u64=0x0F110001u;
}
static void __imp__XamSessionRefObjByHandle([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AD74u); }
static void __imp__XamShowSigninUI([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A2C4u); }
static void __imp__XamUserAreUsersFriends([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A254u); }
static void __imp__XamUserCheckPrivilege([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A264u); }
static void __imp__XamUserCreateAchievementEnumerator([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A2A4u); }
static void __imp__XamUserGetSigninInfo([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A3A4u); }
static void __imp__XamUserGetSigninState([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A244u); }
static void __imp__XamUserGetXUID([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A2B4u); }
static void __imp__XamUserReadProfileSettings([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AAB4u); }
static void __imp__XamUserWriteProfileSettings([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214AAC4u); }
static void __imp__XamVoiceClose([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214ADA4u); }
static void __imp__XamWriteGamerTile([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, 0x8214A294u); }
static void __imp__XexGetModuleHandle(Context& ctx, Machine& base) {
  // Only the observed "xam.xex" lookup is accepted; the fixture hands back
  // an opaque module token.
  if (uint32_t(base.load(ctx.r3.u32,4))!=0x78616d2eu) // "xam."
    base.fail(Error::unsupported, 0x8214ABA4u);
  base.store(ctx.r4.u32,4,0x0D0D0001u);
  ctx.r3.u64=0u;
}
static void __imp__XexGetProcedureAddress(Context& ctx, Machine& base) {
  // The exact caller probes optional XAM ordinals on the fixture module
  // token; the 2008-era dashboard lineage does not export them, so the
  // documented not-found status selects the original fallback path.
  if (ctx.r3.u32!=0x0D0D0001u)
    base.fail(Error::unsupported, 0x8214A5D4u);
  base.store(ctx.r5.u32,4,0u);
  ctx.r3.u64=0xC0000225u; // STATUS_NOT_FOUND
}


// WIP 022: XAM/Live profile-manager family (exact bodies; executed only where observed)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#include "generated/sub_820A1BF8.inc"
#include "generated/sub_820D7E90.inc"
#include "generated/sub_820D7EA0.inc"
#include "generated/sub_820FBF50.inc"
#include "generated/sub_820A1E50.inc"
#include "generated/sub_820FBF60.inc"
#include "generated/sub_82104FD0.inc"
#include "generated/sub_820B6CA0.inc"
#include "generated/sub_820757C8.inc"
#include "generated/sub_820782F0.inc"
#include "generated/sub_820D7DD8.inc"
#include "generated/sub_820FBEC8.inc"
#include "generated/sub_820A0540.inc"
#include "generated/sub_820A39F0.inc"
#include "generated/sub_820A37B8.inc"
#include "generated/sub_820A3900.inc"
#include "generated/sub_820B5CE0.inc"
#include "generated/sub_820B5A10.inc"
#include "generated/sub_820B6C58.inc"
#include "generated/sub_820B5A00.inc"
#include "generated/sub_82077A98.inc"
#include "generated/sub_820A6490.inc"
#include "generated/sub_820FC720.inc"
#include "generated/sub_82104B10.inc"
#include "generated/sub_820FC710.inc"
#include "generated/sub_820FC5A0.inc"
#include "generated/sub_820A1288.inc"
#include "generated/sub_820FC1D8.inc"
#include "generated/sub_820A0C38.inc"
#include "generated/sub_820B5C40.inc"
#include "generated/sub_820A0AF8.inc"
#include "generated/sub_820B6818.inc"
#include "generated/sub_820A0988.inc"
#include "generated/sub_820A08C0.inc"
#include "generated/sub_820A3F38.inc"
#include "generated/sub_820A36D8.inc"
#include "generated/sub_8209D948.inc"
#include "generated/sub_82097298.inc"
#include "generated/sub_82077310.inc"
#include "generated/sub_820778D0.inc"
#include "generated/sub_820B5A08.inc"
#include "generated/sub_8210C908.inc"
#include "generated/sub_820FF968.inc"
#include "generated/sub_82109190.inc"
#include "generated/sub_821028D8.inc"
#include "generated/sub_8210C788.inc"
#include "generated/sub_820FC668.inc"
#include "generated/sub_820B6820.inc"
#include "generated/sub_820B6AC0.inc"
#include "generated/sub_820B72E8.inc"
#include "generated/sub_820D8430.inc"
#include "generated/sub_8209D488.inc"
#include "generated/sub_82058478.inc"
#include "generated/sub_820FC240.inc"
#include "generated/sub_820A0FF0.inc"
#include "generated/sub_8209D5F8.inc"
#include "generated/sub_8209DAB0.inc"
#include "generated/sub_820D8370.inc"
#include "generated/sub_820A1138.inc"
#include "generated/sub_82097198.inc"
#include "generated/sub_82097420.inc"
#include "generated/sub_8206C1D0.inc"
#include "generated/sub_82078FE8.inc"
#include "generated/sub_8206DD58.inc"
#include "generated/sub_82053BC8.inc"
#include "generated/sub_8210C860.inc"
#include "generated/sub_820FE418.inc"
#include "generated/sub_82108F48.inc"
#include "generated/sub_821090C8.inc"
#include "generated/sub_82101528.inc"
#include "generated/sub_82108F60.inc"
#include "generated/sub_82115008.inc"
#include "generated/sub_82078D90.inc"
#include "generated/sub_820B5C58.inc"
#include "generated/sub_82050468.inc"
#include "generated/sub_82050900.inc"
#include "generated/sub_8209F400.inc"
#include "generated/sub_820A0F88.inc"
#include "generated/sub_82068470.inc"
#include "generated/sub_82067230.inc"
#include "generated/sub_82066610.inc"
#include "generated/sub_82053C70.inc"
#include "generated/sub_82114EA0.inc"
#include "generated/sub_82136F58.inc"
#include "generated/sub_8210C710.inc"
#include "generated/sub_82109340.inc"
#include "generated/sub_82107C10.inc"
#include "generated/sub_821080C8.inc"
#include "generated/sub_82108F78.inc"
#include "generated/sub_8213B068.inc"
#include "generated/sub_82100FD8.inc"
#include "generated/sub_82136F68.inc"
#include "generated/sub_82108860.inc"
#include "generated/sub_82108F88.inc"
#include "generated/sub_82107ED8.inc"
#include "generated/sub_82072EB0.inc"
#include "generated/sub_820B5958.inc"
#include "generated/sub_82050A50.inc"
#include "generated/sub_820D81B8.inc"
#include "generated/sub_82127BC8.inc"
#include "generated/sub_82127E20.inc"
#include "generated/sub_820B5D30.inc"
#include "generated/sub_82054D38.inc"
#include "generated/sub_8213AFE8.inc"
#include "generated/sub_820D7F18.inc"
#include "generated/sub_82109A50.inc"
#include "generated/sub_820FCFB0.inc"
#include "generated/sub_821388E0.inc"
#include "generated/sub_82107C20.inc"
#include "generated/sub_821080E0.inc"
#include "generated/sub_82108E28.inc"
#include "generated/sub_820FFCB0.inc"
#include "generated/sub_8210C510.inc"
#include "generated/sub_8210BE88.inc"
#include "generated/sub_82100718.inc"
#include "generated/sub_820B6CA8.inc"
#include "generated/sub_8210BC48.inc"
#include "generated/sub_82073FA0.inc"
#include "generated/sub_820B58D0.inc"
#include "generated/sub_820510F8.inc"
#include "generated/sub_820515C8.inc"
#include "generated/sub_8213AAB0.inc"
#include "generated/sub_82136C88.inc"
#include "generated/sub_820D7F98.inc"
#include "generated/sub_820FD938.inc"
#include "generated/sub_820D7FB8.inc"
#include "generated/sub_82113480.inc"
#include "generated/sub_82138AE0.inc"
#include "generated/sub_82109430.inc"
#include "generated/sub_8210B298.inc"
#include "generated/sub_8210BC10.inc"
#include "generated/sub_82109068.inc"
#include "generated/sub_82136E38.inc"
#include "generated/sub_820FE778.inc"
#include "generated/sub_8210C060.inc"
#include "generated/sub_82108E90.inc"
#include "generated/sub_82108DE8.inc"
#include "generated/sub_82108E70.inc"
#include "generated/sub_8210AA68.inc"
#include "generated/sub_82100538.inc"
#include "generated/sub_82074080.inc"
#include "generated/sub_82050F90.inc"
#include "generated/sub_8213E2A0.inc"
#include "generated/sub_820B6868.inc"
#include "generated/sub_82139320.inc"
#include "generated/sub_8213A990.inc"
#include "generated/sub_8213CA00.inc"
#include "generated/sub_82149AD0.inc"
#include "generated/sub_8213A1E0.inc"
#include "generated/sub_82109FC8.inc"
#include "generated/sub_82112BC0.inc"
#include "generated/sub_82115C28.inc"
#include "generated/sub_82115208.inc"
#include "generated/sub_82117908.inc"
#include "generated/sub_82115638.inc"
#include "generated/sub_82112570.inc"
#include "generated/sub_8210E528.inc"
#include "generated/sub_8210BBC8.inc"
#include "generated/sub_820FD240.inc"
#include "generated/sub_820FD148.inc"
#include "generated/sub_8210C008.inc"
#include "generated/sub_82110888.inc"
#include "generated/sub_8210FFF0.inc"
#include "generated/sub_8210E0B8.inc"
#include "generated/sub_820FD8A8.inc"
#include "generated/sub_820FF3A8.inc"
#include "generated/sub_82074388.inc"
#include "generated/sub_8213EB88.inc"
#include "generated/sub_8213D808.inc"
#include "generated/sub_8213DCE0.inc"
#include "generated/sub_820D8588.inc"
#include "generated/sub_820D85E8.inc"
#include "generated/sub_82141BD0.inc"
#include "generated/sub_8213EF58.inc"
#include "generated/sub_8213C850.inc"
#include "generated/sub_8213A070.inc"
#include "generated/sub_82109BA0.inc"
#include "generated/sub_821151C8.inc"
#include "generated/sub_82112D10.inc"
#include "generated/sub_8210DA60.inc"
#include "generated/sub_82120688.inc"
#include "generated/sub_82115FA8.inc"
#include "generated/sub_82115CD0.inc"
#include "generated/sub_821157C8.inc"
#include "generated/sub_82115530.inc"
#include "generated/sub_82112238.inc"
#include "generated/sub_82115670.inc"
#include "generated/sub_821117E0.inc"
#include "generated/sub_8210CA68.inc"
#include "generated/sub_821156C0.inc"
#include "generated/sub_82116398.inc"
#include "generated/sub_820FC740.inc"
#include "generated/sub_8210E678.inc"
#include "generated/sub_8210F320.inc"
#include "generated/sub_82108E80.inc"
#include "generated/sub_82108DF8.inc"
#include "generated/sub_8213EE98.inc"
#include "generated/sub_8213EAE0.inc"
#include "generated/sub_820D8020.inc"
#include "generated/sub_820D8088.inc"
#include "generated/sub_820DC6A8.inc"
#include "generated/sub_820DCCB0.inc"
#include "generated/sub_82140F28.inc"
#include "generated/sub_82141A40.inc"
#include "generated/sub_8213EE10.inc"
#include "generated/sub_82136E60.inc"
#include "generated/sub_82118268.inc"
#include "generated/sub_8211E870.inc"
#include "generated/sub_82116FB8.inc"
#include "generated/sub_8210F488.inc"
#include "generated/sub_82116728.inc"
#include "generated/sub_82111FB0.inc"
#include "generated/sub_8210D130.inc"
#include "generated/sub_8210DAB8.inc"
#include "generated/sub_821158D8.inc"
#include "generated/sub_82115998.inc"
#include "generated/sub_82120620.inc"
#include "generated/sub_821156E8.inc"
#include "generated/sub_820D7F08.inc"
#include "generated/sub_82115238.inc"
#include "generated/sub_821153D0.inc"
#include "generated/sub_82111D58.inc"
#include "generated/sub_82111C50.inc"
#include "generated/sub_820D7EE8.inc"
#include "generated/sub_8210CA38.inc"
#include "generated/sub_8210E848.inc"
#include "generated/sub_82115188.inc"
#include "generated/sub_821138A0.inc"
#include "generated/sub_821106E0.inc"
#include "generated/sub_8210DC98.inc"
#include "generated/sub_8213EDB0.inc"
#include "generated/sub_8213E9B0.inc"
#include "generated/sub_820DBF30.inc"
#include "generated/sub_820DC2A0.inc"
#include "generated/sub_820DBCA8.inc"
#include "generated/sub_820DC8D8.inc"
#include "generated/sub_820E3728.inc"
#include "generated/sub_820DCB70.inc"
#include "generated/sub_820DCB08.inc"
#include "generated/sub_821180D8.inc"
#include "generated/sub_8211DAB8.inc"
#include "generated/sub_821229D0.inc"
#include "generated/sub_82124C40.inc"
#include "generated/sub_8211C068.inc"
#include "generated/sub_8211C7F8.inc"
#include "generated/sub_82116088.inc"
#include "generated/sub_820D7EA8.inc"
#include "generated/sub_82115930.inc"
#include "generated/sub_821163C0.inc"
#include "generated/sub_82117520.inc"
#include "generated/sub_82117820.inc"
#include "generated/sub_82115E00.inc"
#include "generated/sub_8210E7D8.inc"
#include "generated/sub_8210E730.inc"
#include "generated/sub_82111A58.inc"
#include "generated/sub_821159F0.inc"
#include "generated/sub_82114E60.inc"
#include "generated/sub_8211A990.inc"
#include "generated/sub_82116D78.inc"
#include "generated/sub_82116BA8.inc"
#include "generated/sub_8211DA00.inc"
#include "generated/sub_8210D208.inc"
#include "generated/sub_82115180.inc"
#include "generated/sub_82113668.inc"
#include "generated/sub_8210CB20.inc"
#include "generated/sub_8213EC90.inc"
#include "generated/sub_820DBBE0.inc"
#include "generated/sub_820E37E0.inc"
#include "generated/sub_820E3698.inc"
#include "generated/sub_8211AAB0.inc"
#include "generated/sub_82124438.inc"
#include "generated/sub_82126078.inc"
#include "generated/sub_821210B0.inc"
#include "generated/sub_82124880.inc"
#include "generated/sub_82123930.inc"
#include "generated/sub_82121E68.inc"
#include "generated/sub_821254C8.inc"
#include "generated/sub_82122270.inc"
#include "generated/sub_82119950.inc"
#include "generated/sub_8211AD88.inc"
#include "generated/sub_82118160.inc"
#include "generated/sub_821206C0.inc"
#include "generated/sub_82117100.inc"
#include "generated/sub_82115AA0.inc"
#include "generated/sub_8210D078.inc"
#include "generated/sub_82121EF0.inc"
#include "generated/sub_82121F40.inc"
#include "generated/sub_82122DB8.inc"
#include "generated/sub_82122900.inc"
#include "generated/sub_82115290.inc"
#include "generated/sub_8211E468.inc"
#include "generated/sub_820DB930.inc"
#include "generated/sub_82125908.inc"
#include "generated/sub_82122BD0.inc"
#include "generated/sub_82122B78.inc"
#include "generated/sub_8211BD50.inc"
#include "generated/sub_82124718.inc"
#include "generated/sub_82122708.inc"
#include "generated/sub_82122840.inc"
#include "generated/sub_821233B8.inc"
#include "generated/sub_82126288.inc"
#include "generated/sub_82118BC8.inc"
#include "generated/sub_8211E560.inc"
#include "generated/sub_8211C550.inc"
#include "generated/sub_82120548.inc"
#include "generated/sub_821227D0.inc"
#include "generated/sub_82126E20.inc"
#include "generated/sub_82126948.inc"
#include "generated/sub_8211DC88.inc"
#include "generated/sub_8211FD38.inc"
#include "generated/sub_82118E38.inc"
#include "generated/sub_8211C0E8.inc"
#include "generated/sub_8211C158.inc"
#include "generated/sub_8211A3B8.inc"
#include "generated/sub_821243D0.inc"
#include "generated/sub_8211AA40.inc"
#include "generated/sub_82122310.inc"
#include "generated/sub_82122EF8.inc"
#include "generated/sub_82122768.inc"
#include "generated/sub_82122640.inc"
#include "generated/sub_820FC858.inc"
#include "generated/sub_82118AF0.inc"
#include "generated/sub_82121038.inc"
#include "generated/sub_820FC8B0.inc"
#include "generated/sub_821182E0.inc"
#include "generated/sub_8211D390.inc"
#include "generated/sub_8211B798.inc"
#include "generated/sub_8211A058.inc"
#include "generated/sub_8211B800.inc"
#include "generated/sub_8211B728.inc"
#include "generated/sub_8211B970.inc"
#include "generated/sub_8211D5B0.inc"
#include "generated/sub_82125088.inc"
#include "generated/sub_8211C3B0.inc"
#include "generated/sub_82123078.inc"
#include "generated/sub_82124958.inc"
#include "generated/sub_82119FE8.inc"
#include "generated/sub_8211AB48.inc"
#include "generated/sub_82126898.inc"
#include "generated/sub_821231F0.inc"
#include "generated/sub_82126198.inc"
#include "generated/sub_82125E28.inc"
#include "generated/sub_82124E80.inc"
#include "generated/sub_82124E68.inc"
#include "generated/sub_82124FE8.inc"
#include "generated/sub_82125038.inc"
#include "generated/sub_82124E50.inc"
#include "generated/sub_82121B80.inc"
#include "generated/sub_82122FC8.inc"
#include "generated/sub_82121B08.inc"
#include "generated/sub_82124CD0.inc"
#include "generated/sub_82125E08.inc"
#include "generated/sub_821224C8.inc"
#include "generated/sub_8211E770.inc"
#include "generated/sub_82125390.inc"
#include "generated/sub_82119F88.inc"
#include "generated/sub_8211A158.inc"
#include "generated/sub_8211A1E0.inc"
#include "generated/sub_821217D0.inc"
#include "generated/sub_82121610.inc"
#include "generated/sub_821217C0.inc"
#include "generated/sub_821217C8.inc"
#include "generated/sub_821216D0.inc"
#include "generated/sub_821215B0.inc"
#include "generated/sub_82121670.inc"
#include "generated/sub_82126530.inc"
#include "generated/sub_8211AF80.inc"
#include "generated/sub_82121370.inc"
#include "generated/sub_8211B8F8.inc"
#include "generated/sub_82122AC0.inc"
#include "generated/sub_82121738.inc"
#include "generated/sub_82122680.inc"
#include "generated/sub_82122C78.inc"
#include "generated/sub_82122438.inc"
#include "generated/sub_82126FE0.inc"
#include "generated/sub_82125E38.inc"
#include "generated/sub_82125628.inc"
#include "generated/sub_82124820.inc"
#include "generated/sub_82124500.inc"
#include "generated/sub_821244A8.inc"
#include "generated/sub_82120AF0.inc"
#include "generated/sub_82120B30.inc"
#include "generated/sub_82122608.inc"
#include "generated/sub_82122C20.inc"
#include "generated/sub_82125E68.inc"
#include "generated/sub_821225D0.inc"
#include "generated/sub_82125EA0.inc"
#include "generated/sub_8211BB58.inc"
#include "generated/sub_8211BA00.inc"
#include "generated/sub_8211A0F0.inc"
#include "generated/sub_8211BA60.inc"
#include "generated/sub_82120778.inc"
#include "generated/sub_82125C10.inc"
#include "generated/sub_82125A88.inc"
#include "generated/sub_82120F60.inc"
#include "generated/sub_82120C00.inc"
#include "generated/sub_82120958.inc"
#include "generated/sub_82120AE0.inc"
#include "generated/sub_82120EA8.inc"
#include "generated/sub_82120BB8.inc"
#include "generated/sub_82120E08.inc"
#include "generated/sub_821235B0.inc"
#include "generated/sub_82121230.inc"
#include "generated/sub_8211AE00.inc"
#include "generated/sub_82126298.inc"
#include "generated/sub_82120C20.inc"
#include "generated/sub_8212B180.inc"
#include "generated/sub_82126C48.inc"
#include "generated/sub_82126D40.inc"
#include "generated/sub_82125558.inc"
#include "generated/sub_8211AED8.inc"
#include "generated/sub_8211A288.inc"
#include "generated/sub_82125BA8.inc"
#include "generated/sub_82123C00.inc"
#include "generated/sub_821260B0.inc"
#include "generated/sub_82126120.inc"
#include "generated/sub_821240F0.inc"
#pragma clang diagnostic pop

// WIP 022: remaining sub_82070AC8 tail (sub_82075C88 game-manager, sub_820759A8, sub_82070908)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#include "generated/sub_82075C88.inc"
#include "generated/sub_820759A8.inc"
#include "generated/sub_82070908.inc"
#include "generated/sub_8209B648.inc"
#include "generated/sub_82076CE0.inc"
#include "generated/sub_8209FF98.inc"
#include "generated/sub_82076F08.inc"
#include "generated/sub_82096950.inc"
#include "generated/sub_82099FA0.inc"
#include "generated/sub_820A2150.inc"
#include "generated/sub_820762D0.inc"
#include "generated/sub_82076AD8.inc"
#include "generated/sub_82076758.inc"
#include "generated/sub_820776D8.inc"
#include "generated/sub_82078280.inc"
#include "generated/sub_82078F38.inc"
#include "generated/sub_820A4AD8.inc"
#include "generated/sub_82076DC8.inc"
#include "generated/sub_8209B5D0.inc"
#include "generated/sub_8209C128.inc"
#include "generated/sub_820B6908.inc"
#include "generated/sub_820A1D20.inc"
#include "generated/sub_82077808.inc"
#include "generated/sub_820758E8.inc"
#include "generated/sub_82050800.inc"
#include "generated/sub_820B5858.inc"
#include "generated/sub_820A11B0.inc"
#include "generated/sub_820A13E8.inc"
#include "generated/sub_820B6A28.inc"
#include "generated/sub_820A1560.inc"
#include "generated/sub_82067518.inc"
#include "generated/sub_8209E928.inc"
#include "generated/sub_820A5390.inc"
#include "generated/sub_82051B60.inc"
#include "generated/sub_820A49E0.inc"
#include "generated/sub_820A47E8.inc"
#include "generated/sub_820A6CD8.inc"
#include "generated/sub_820A70B0.inc"
#include "generated/sub_820A3EB8.inc"
#include "generated/sub_820FC418.inc"
#include "generated/sub_82078E38.inc"
#include "generated/sub_8209C718.inc"
#include "generated/sub_820780D8.inc"
#include "generated/sub_82077CE0.inc"
#include "generated/sub_8206BE30.inc"
#include "generated/sub_820B5FE8.inc"
#include "generated/sub_820788B8.inc"
#include "generated/sub_8209AED8.inc"
#include "generated/sub_82095FF0.inc"
#include "generated/sub_82095DA8.inc"
#include "generated/sub_8209DBC0.inc"
#include "generated/sub_82075130.inc"
#include "generated/sub_82095F18.inc"
#include "generated/sub_820727D8.inc"
#include "generated/sub_8209BB30.inc"
#include "generated/sub_820A5478.inc"
#include "generated/sub_8209DFE8.inc"
#include "generated/__restfpr_27.inc"
#include "generated/__savefpr_27.inc"
#include "generated/sub_820A1DD8.inc"
#include "generated/sub_82078170.inc"
#include "generated/sub_82095F78.inc"
#include "generated/sub_8208F5F0.inc"
#include "generated/sub_820966A0.inc"
#include "generated/sub_82128298.inc"
#include "generated/sub_820A15C0.inc"
#include "generated/sub_820B6828.inc"
#include "generated/sub_820B6810.inc"
#include "generated/sub_820D8210.inc"
#include "generated/sub_820FBEA8.inc"
#include "generated/sub_820FBF88.inc"
#include "generated/sub_820A6E08.inc"
#include "generated/sub_820FC0F8.inc"
#include "generated/sub_820FC058.inc"
#include "generated/sub_820FC288.inc"
#include "generated/sub_820FBFD0.inc"
#include "generated/sub_82072D00.inc"
#include "generated/sub_82078810.inc"
#include "generated/sub_82078778.inc"
#include "generated/sub_82077FD8.inc"
#include "generated/sub_82075210.inc"
#include "generated/sub_82096530.inc"
#include "generated/sub_820967B0.inc"
#include "generated/sub_8206CC40.inc"
#include "generated/sub_8206C510.inc"
#include "generated/sub_8206CA60.inc"
#include "generated/sub_82053AC0.inc"
#include "generated/sub_820552B8.inc"
#include "generated/sub_82066680.inc"
#include "generated/sub_82128688.inc"
#include "generated/sub_8209B030.inc"
#include "generated/sub_8209B0E0.inc"
#include "generated/sub_82096250.inc"
#include "generated/sub_820960A8.inc"
#include "generated/sub_820901A8.inc"
#include "generated/sub_82127FE0.inc"
#include "generated/sub_820A1A20.inc"
#include "generated/sub_820A6A40.inc"
#include "generated/sub_8212E660.inc"
#include "generated/sub_820B6788.inc"
#include "generated/sub_820FBDF8.inc"
#include "generated/sub_820B5BE0.inc"
#include "generated/sub_820B5AA0.inc"
#include "generated/sub_820B5B80.inc"
#include "generated/sub_820521F8.inc"
#include "generated/sub_820FC8B8.inc"
#include "generated/sub_820FC548.inc"
#include "generated/sub_8212B398.inc"
#include "generated/sub_82072708.inc"
#include "generated/sub_82073B00.inc"
#include "generated/sub_820735B0.inc"
#include "generated/sub_82066F80.inc"
#include "generated/sub_82067778.inc"
#include "generated/sub_82067020.inc"
#include "generated/sub_82065F78.inc"
#include "generated/sub_82067E00.inc"
#include "generated/sub_8205F6E0.inc"
#include "generated/sub_8205D8E0.inc"
#include "generated/sub_82054528.inc"
#include "generated/sub_8205D5A8.inc"
#include "generated/sub_8205E7E0.inc"
#include "generated/sub_82058F88.inc"
#include "generated/sub_82059210.inc"
#include "generated/sub_820585A8.inc"
#include "generated/sub_82059600.inc"
#include "generated/sub_82054858.inc"
#include "generated/sub_820589F0.inc"
#include "generated/sub_82054170.inc"
#include "generated/sub_82059EE8.inc"
#include "generated/sub_82096B48.inc"
#include "generated/sub_8212A4A8.inc"
#include "generated/sub_8212C230.inc"
#include "generated/sub_8209C0D0.inc"
#include "generated/sub_82095A08.inc"
#include "generated/sub_82096358.inc"
#include "generated/sub_820906A8.inc"
#include "generated/sub_82094048.inc"
#include "generated/sub_82094290.inc"
#include "generated/sub_8212E370.inc"
#include "generated/sub_820FC998.inc"
#include "generated/sub_82073E20.inc"
#include "generated/sub_82073D80.inc"
#include "generated/sub_82072AB8.inc"
#include "generated/sub_82067C40.inc"
#include "generated/__restfpr_24.inc"
#include "generated/__savefpr_24.inc"
#include "generated/sub_820679E8.inc"
#include "generated/sub_82067828.inc"
#include "generated/sub_82097A28.inc"
#include "generated/sub_82097948.inc"
#include "generated/sub_8209EA18.inc"
#include "generated/sub_8212A048.inc"
#include "generated/sub_82095840.inc"
#include "generated/sub_8209B258.inc"
#include "generated/sub_8209B1E0.inc"
#include "generated/sub_8209D840.inc"
#include "generated/sub_8209D758.inc"
#include "generated/sub_82085E18.inc"
#include "generated/sub_82093848.inc"
#include "generated/sub_82085D70.inc"
#include "generated/sub_8212E338.inc"
#include "generated/sub_820742A0.inc"
#include "generated/sub_82068378.inc"
#include "generated/sub_82127CF0.inc"
#include "generated/sub_82097EE0.inc"
#include "generated/sub_8209E448.inc"
#include "generated/sub_8209ECB0.inc"
#include "generated/sub_8209EFF0.inc"
#include "generated/sub_8209E270.inc"
#include "generated/sub_8209E6C8.inc"
#include "generated/sub_820958F8.inc"
#include "generated/sub_820B0A38.inc"
#include "generated/sub_8209A628.inc"
#include "generated/sub_820B0BA8.inc"
#include "generated/sub_821282A8.inc"
#include "generated/sub_82085EC0.inc"
#include "generated/sub_82095788.inc"
#include "generated/sub_82095700.inc"
#include "generated/sub_82099258.inc"
#include "generated/sub_82099118.inc"
#include "generated/sub_8209E098.inc"
#include "generated/sub_8209E890.inc"
#include "generated/sub_8209E1C0.inc"
#include "generated/sub_8209E328.inc"
#include "generated/sub_8212C1A0.inc"
#include "generated/sub_820AD440.inc"
#include "generated/sub_820B0830.inc"
#include "generated/sub_820AD568.inc"
#include "generated/sub_820B61A0.inc"
#include "generated/sub_820B66D8.inc"
#include "generated/sub_820AD2F0.inc"
#include "generated/sub_820AD370.inc"
#include "generated/sub_820ABCA8.inc"
#include "generated/sub_820AFDE0.inc"
#include "generated/sub_820AFE78.inc"
#include "generated/sub_820ABDB0.inc"
#include "generated/sub_820ABBD8.inc"
#include "generated/sub_821295C0.inc"
#include "generated/sub_820AE2F0.inc"
#include "generated/sub_820AE118.inc"
#include "generated/sub_820AE030.inc"
#include "generated/sub_820AC7D8.inc"
#include "generated/sub_820ADB18.inc"
#include "generated/sub_820ACEB8.inc"
#pragma clang diagnostic pop
#include "generated/sub_82070AC8_post_init.inc"

// KeBugCheck is a terminal kernel failure; reaching it is never success.
static void __imp__KeBugCheck([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214A9F4u);
}

// WIP 021: the exact statically linked game heap (RtlHeap-family) reached by
// the shader loader's sub_82128F70 allocation. Game-side heap code is executed
// byte-exact; only the kernel TLS/virtual-memory/critical-section contracts
// below are modeled, each fail-closed outside its observed shape.
static void __imp__KeBugCheckEx([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214AA04u);
}
static void __imp__KeTlsGetValue(Context& ctx, Machine& base) {
  if (ctx.r3.u32 >= 64u) base.fail(Error::unsupported, 0x8214A9D4u);
  ctx.r3.u64 = g_tls_slots[ctx.r3.u32];
}
static void __imp__KeTlsSetValue(Context& ctx, Machine& base) {
  if (ctx.r3.u32 >= 64u) base.fail(Error::unsupported, 0x8214A9E4u);
  g_tls_slots[ctx.r3.u32] = ctx.r4.u32;
  ctx.r3.u64 = 1u;
}
static void __imp__RtlCompareMemoryUlong(Context& ctx, Machine& base) {
  // Trusted xboxkrnl contract: count leading bytes of the ULONG-aligned block
  // at r3 (length r4) equal to pattern r5, in whole-ULONG steps.
  const uint32_t src=ctx.r3.u32, len=ctx.r4.u32 & ~3u, pat=ctx.r5.u32;
  uint32_t matched=0;
  while (matched<len && uint32_t(base.load(src+matched,4))==pat) matched+=4u;
  ctx.r3.u64=matched;
}
static void __imp__NtAllocateVirtualMemory(Context& ctx, Machine& base) {
  // Bounded virtual-memory contract for the exact CRT heap: reservations and
  // commits are served from the dedicated fixture arena at 0x04000000. Only
  // the observed shapes are accepted; anything else fails closed.
  const uint32_t base_ptr=ctx.r3.u32, size_ptr=ctx.r4.u32,
                 alloc_type=ctx.r5.u32, protect=ctx.r6.u32;
  const uint32_t want_base=uint32_t(base.load(base_ptr,4));
  const uint32_t want_size=uint32_t(base.load(size_ptr,4));
  if (ctx.r7.u32!=0u || protect!=4u || want_size==0u || want_size>0x400000u)
    base.fail(Error::unsupported, 0x8214A6B4u);
  if (alloc_type==0x60002000u && want_base==0u) {
    // Top-down reserve of a fresh region: round to 64 KiB.
    const uint32_t size=(want_size+0xFFFFu)&~0xFFFFu;
    const uint32_t p=(g_valloc_cursor+0xFFFFu)&~0xFFFFu;
    if (p+size<p || base.memory.check(p,size,3)!=cc::xbox::MemoryError::ok)
      base.fail(Error::memory,p);
    g_valloc_cursor=p+size;
    base.store(base_ptr,4,p);
    base.store(size_ptr,4,size);
    ctx.r3.u64=0;
    return;
  }
  if ((alloc_type==0x1000u||alloc_type==0x2000u||alloc_type==0x60001000u) &&
      want_base>=0x04000000u && want_base<g_valloc_cursor) {
    // Commit inside an existing fixture reservation: round to 4 KiB.
    const uint32_t start=want_base&~0xFFFu;
    const uint32_t size=((want_base-start)+want_size+0xFFFu)&~0xFFFu;
    if (base.memory.check(start,size,3)!=cc::xbox::MemoryError::ok)
      base.fail(Error::memory,start);
    base.store(base_ptr,4,start);
    base.store(size_ptr,4,size);
    ctx.r3.u64=0;
    return;
  }
  std::fprintf(stderr,
    "NTALLOCVM unsupported r3=%08x r4=%08x r5=%08x r6=%08x r7=%08x [r3]=%08x [r4]=%08x lr=%08x\n",
    ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32,
    want_base, want_size, uint32_t(ctx.lr));
  base.fail(Error::unsupported, 0x8214A6B4u);
}
static void __imp__NtFreeVirtualMemory([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214A9B4u);
}

// RtlRaiseException is a terminal failure path for the exact heap; reaching
// it is never promoted to success.
static void __imp__RtlRaiseException([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214A9C4u);
}
#include "generated/sub_820B6780.inc"
#include "generated/sub_820B72C8.inc"
#include "generated/sub_820B7BC8.inc"
#include "generated/sub_820B7D88.inc"
#include "generated/sub_820B7EA8.inc"
#include "generated/sub_820B8138.inc"
#include "generated/sub_820B8540.inc"
#include "generated/sub_820B8CA0.inc"
#include "generated/sub_820B8E08.inc"
#include "generated/sub_820B9048.inc"
#include "generated/sub_820BA1D4.inc"
#include "generated/sub_820BA228.inc"
#include "generated/sub_820BA4C8.inc"
#include "generated/sub_82129470.inc"
#include "generated/sub_82129880.inc"
#include "generated/sub_8212A2E8.inc"
#include "generated/sub_8212A3B8.inc"
#include "generated/sub_8212C298.inc"
#include "generated/sub_8212E140.inc"
#include "generated/sub_8212E218.inc"
#include "generated/sub_821325C0.inc"
#include "generated/sub_820B9958.inc"
#include "generated/sub_820BB280.inc"
#include "generated/sub_8212EC50.inc"
#include "generated/sub_821294E0.inc"
#include "generated/sub_820B7BC0.inc"
#include "generated/sub_820B7630.inc"

// Exact CRT heap creation (sub_820B7880 -> RtlCreateHeap-family
// sub_820B93B0), executed as observed original startup behavior. The
// XexExecutableModuleHandle loader variable is fixture-resolved to a null
// module so the default 1 MiB reserve path is taken, exactly as a title with
// no XEX default-heap-size field.
static void __imp__RtlImageXexHeaderField([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x8214A684u);
}
static void __imp__NtQueryVirtualMemory(Context& ctx, Machine& base) {
  std::fprintf(stderr,
    "NTQUERYVM r3=%08x r4=%08x r5=%08x r6=%08x r7=%08x r1=%08x lr=%08x\n",
    ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32,
    ctx.r1.u32, uint32_t(ctx.lr));
  base.fail(Error::unsupported, 0x8214A994u);
}
#include "generated/sub_8212A760.inc"
#include "generated/sub_820B93B0.inc"
#include "generated/sub_820B7880.inc"
#include "generated/sub_820B6CD0.inc"
#include "generated/sub_8212C368.inc"
#include "generated/sub_8212C3B0.inc"
#include "generated/sub_8212A040.inc"
#include "generated/sub_82128F70.inc"

#include "generated/sub_820B75C0.inc"
#include "generated/sub_820B6AD8.inc"

// Trusted xboxkrnl contract: initialize the ANSI_STRING at r3 (USHORT Length,
// USHORT MaximumLength, ULONG Buffer, big-endian) from the NUL-terminated
// guest buffer at r4. The observed shader-path call always passes a valid
// bounded string; unbounded scans fail closed.
static void __imp__RtlInitAnsiString(Context& ctx, Machine& base) {
  uint32_t len = 0;
  if (ctx.r4.u32) {
    while (base.load(ctx.r4.u32 + len, 1) != 0)
      if (++len >= 1024u) base.fail(Error::unsupported, 0x8214A494u);
  }
  base.store(ctx.r3.u32 + 0, 2, len);
  base.store(ctx.r3.u32 + 2, 2, ctx.r4.u32 ? len + 1 : 0);
  base.store(ctx.r3.u32 + 4, 4, ctx.r4.u32);
}

#include "generated/sub_820B7278.inc"
#include "generated/sub_820B73C8.inc"
#include "generated/sub_820B64E0.inc"
#include "generated/sub_820AA488.inc"
