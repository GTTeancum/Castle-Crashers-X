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
  if (ctx.r3.u32 != 3u || ctx.r4.u32 != 9u || ctx.r6.u32 != 4u)
    base.fail(Error::unsupported, 0x8214A554u);
  if (ctx.r5.u32 > 0xfffffffbu || ctx.r7.u32 > 0xfffffffdu)
    base.fail(Error::context, 0x8214A554u);
  base.store(ctx.r5.u32,4,0);
  base.store(ctx.r7.u32,2,4);
  ctx.r3.s64 = -1; // exercise the original region fallback path
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
#include "generated/sub_820701D0_startup_prefix.inc"
