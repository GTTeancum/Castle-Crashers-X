#include "generated/__savegprlr_29.inc"
#include "generated/__restgprlr_29.inc"
#include "generated/sub_8208C5D8.inc"
#include "generated/sub_8209CC98.inc"

// ReXGlue's generated PPC trap intrinsic is a non-returning failure path. The
// bounded host runtime reports it as context failure; it never converts a trap
// into success.
static void ppc_trap([[maybe_unused]] Context& ctx, Machine& base, uint32_t code) {
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
  // The only accepted checkpoint-016 call shape is sprintf-like "%i" used by
  // sub_8209CA70 to create its monotonically numbered startup label.
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
  // 28-byte object here; initialize the owned bytes deterministically. Enter/
  // leave semantics are deliberately outside this checkpoint.
  const uint32_t p=ctx.r3.u32;
  if (p > 0xffffffe4u) base.fail(Error::context,p);
  for (unsigned i=0;i<28;++i) base.store(p+i,1,0);
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
  if (!startup && !graphics) base.fail(Error::unsupported, 0x8214A464u);
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

// Failure-only error translation path for the exact wrappers. Successful
// checkpoint-017 calls never enter it; a platform failure remains fail-closed.
static void sub_820B7290([[maybe_unused]] Context& ctx, Machine& base) {
  base.fail(Error::unsupported, 0x820B7290u);
}

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
HARD_BOUNDARY_017(__imp__RtlEnterCriticalSection, 0x8214A3F4u)
HARD_BOUNDARY_017(__imp__RtlLeaveCriticalSection, 0x8214A404u)
HARD_BOUNDARY_017(sub_821287B0, 0x821287B0u)
HARD_BOUNDARY_017(sub_82128A60, 0x82128A60u)
HARD_BOUNDARY_017(sub_820B00D8, 0x820B00D8u)
HARD_BOUNDARY_017(sub_820B0330, 0x820B0330u)
HARD_BOUNDARY_017(sub_820B0D80, 0x820B0D80u)
HARD_BOUNDARY_017(sub_820B6498, 0x820B6498u)
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



// Checkpoint 018: graphics/runtime platform boundary. Game-side device/ring setup
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
  if (base.graphics_alloc_index!=6u || !base.ring_virtual || ctx.r3.u32!=base.ring_virtual)
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

#define HARD_BOUNDARY_018(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { base.fail(Error::unsupported, addr); }
HARD_BOUNDARY_018(sub_820C74D0,0x820C74D0u)
HARD_BOUNDARY_018(sub_820B6068,0x820B6068u)
HARD_BOUNDARY_018(sub_820D6470,0x820D6470u)
HARD_BOUNDARY_018(sub_820C6218,0x820C6218u)
HARD_BOUNDARY_018(sub_820CC318,0x820CC318u)
HARD_BOUNDARY_018(sub_820BECA0,0x820BECA0u)
HARD_BOUNDARY_018(sub_820CBBF0,0x820CBBF0u)
HARD_BOUNDARY_018(sub_820CB988,0x820CB988u)
HARD_BOUNDARY_018(sub_820C7228,0x820C7228u)
HARD_BOUNDARY_018(sub_820CDD68,0x820CDD68u)
HARD_BOUNDARY_018(sub_820D19E8,0x820D19E8u)
HARD_BOUNDARY_018(sub_820BDE48,0x820BDE48u)
HARD_BOUNDARY_018(__imp__VdIsHSIOTrainingSucceeded,0x8214A8B4u)
HARD_BOUNDARY_018(sub_820D1C08,0x820D1C08u)
HARD_BOUNDARY_018(sub_820BE8F8,0x820BE8F8u)
HARD_BOUNDARY_018(sub_820BE9F0,0x820BE9F0u)
HARD_BOUNDARY_018(sub_820BE928,0x820BE928u)
#undef HARD_BOUNDARY_018

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
#include "generated/sub_820CC100.inc"
#include "generated/sub_820BEFD0.inc"
