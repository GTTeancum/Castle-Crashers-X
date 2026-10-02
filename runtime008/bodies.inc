static void __restfpr_14(Context&, Machine&);
static void __restfpr_19(Context&, Machine&);
static void __restfpr_25(Context&, Machine&);
static void __restgprlr_20(Context&, Machine&);
static void __restgprlr_21(Context&, Machine&);
static void __restgprlr_25(Context&, Machine&);
static void __restgprlr_27(Context&, Machine&);
static void __restgprlr_28(Context&, Machine&);
static void __savefpr_14(Context&, Machine&);
static void __savefpr_19(Context&, Machine&);
static void __savefpr_25(Context&, Machine&);
static void __savegprlr_20(Context&, Machine&);
static void __savegprlr_21(Context&, Machine&);
static void __savegprlr_25(Context&, Machine&);
static void __savegprlr_27(Context&, Machine&);
static void __savegprlr_28(Context&, Machine&);
static void sub_82053A98(Context&, Machine&);
static void sub_820619E8(Context&, Machine&);
static void sub_820836E0(Context&, Machine&);
static void sub_82084100(Context&, Machine&);
static void sub_82085110(Context&, Machine&);
static void sub_820855D8(Context&, Machine&);
static void sub_82085AD8(Context&, Machine&);
static void sub_82085C70(Context&, Machine&);
static void sub_82086090(Context&, Machine&);
static void sub_82086278(Context&, Machine&);
static void sub_820868D0(Context&, Machine&);
static void sub_8208A7A0(Context&, Machine&);
static void sub_8208AF08(Context&, Machine&);
static void sub_8208C5D8(Context&, Machine&);
static void sub_82094FE8(Context&, Machine&);
static void sub_8209D028(Context&, Machine&);
static void sub_8209D118(Context&, Machine&);
static void sub_8209D1C8(Context&, Machine&);
static void sub_820A7488(Context&, Machine&);
static void sub_820A74E0(Context&, Machine&);
static void sub_820A74F8(Context&, Machine&);
static void sub_820A7508(Context&, Machine&);
static void sub_820A75C8(Context&, Machine&);
static void sub_820A8038(Context&, Machine&);
static void sub_820A8100(Context&, Machine&);
static void sub_820A86B0(Context&, Machine&);
static void sub_820A8DD8(Context&, Machine&);
static void sub_820A8FF8(Context&, Machine&);
static void sub_820A9068(Context&, Machine&);
static void sub_820A9D78(Context&, Machine&);
static void sub_820A9E98(Context&, Machine&);
static void sub_82127A08(Context&, Machine&);
static void sub_82127AE8(Context&, Machine&);
static void sub_82127FB0(Context&, Machine&);
static void sub_82129038(Context&, Machine&);
static void sub_82129A70(Context&, Machine&);
#include "generated/__restfpr_14.inc"
#include "generated/__restfpr_19.inc"
#include "generated/__restfpr_25.inc"
#include "generated/__restgprlr_20.inc"
#include "generated/__restgprlr_21.inc"
#include "generated/__restgprlr_25.inc"
#include "generated/__restgprlr_27.inc"
#include "generated/__restgprlr_28.inc"
#include "generated/__savefpr_14.inc"
#include "generated/__savefpr_19.inc"
#include "generated/__savefpr_25.inc"
#include "generated/__savegprlr_20.inc"
#include "generated/__savegprlr_21.inc"
#include "generated/__savegprlr_25.inc"
#include "generated/__savegprlr_27.inc"
#include "generated/__savegprlr_28.inc"
#include "generated/sub_82053A98.inc"
#include "generated/sub_820619E8.inc"
#include "generated/sub_820836E0.inc"
#include "generated/sub_82084100.inc"
#include "generated/sub_82085110.inc"
#include "generated/sub_820855D8.inc"
#include "generated/sub_82085AD8.inc"
#include "generated/sub_82086090.inc"
#include "generated/sub_82086278.inc"
#include "generated/sub_820868D0.inc"
#include "generated/sub_8208A7A0.inc"
#include "generated/sub_8208AF08.inc"
#include "generated/sub_82094FE8.inc"
#include "generated/sub_8209D028.inc"
#include "generated/sub_8209D118.inc"
#include "generated/sub_8209D1C8.inc"
#include "generated/sub_820A7488.inc"
#include "generated/sub_820A74E0.inc"
#include "generated/sub_820A74F8.inc"
#include "generated/sub_820A7508.inc"
#include "generated/sub_820A75C8.inc"
#include "generated/sub_820A8038.inc"
#include "generated/sub_820A8100.inc"
#include "generated/sub_820A86B0.inc"
#ifdef CC_FAST
#define sub_820A8DD8 sub_820A8DD8_exact
#endif
#include "generated/sub_820A8DD8.inc"
#ifdef CC_FAST
#undef sub_820A8DD8
// Sprite cull test (renderer r3, four points r4..r7 as {x, y, z} floats,
// mode r8). Mode 4 means the points are already in screen space; the exact
// code then returns 1 (skip) when all four x are beyond one side or all four
// y beyond one side of the viewport constants at 0x82042598.. (rx 9648,
// lx 9644, by 9640, ty 9644 again, read as the exact code does). Other
// modes transform first and stay exact. Comparisons mirror the PPC fcmpu:
// a NaN fails every test, so the sprite is drawn.
static void sub_820A8DD8(Context& ctx, Machine& base) {
#ifdef CC_CULL_EXACT_BUILD
  if (true) { sub_820A8DD8_exact(ctx, base); return; }
#endif
  if (ctx.r8.u32 != 4u) { sub_820A8DD8_exact(ctx, base); return; }
  const uint32_t pts[4] = {ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32};
  auto f32 = [&](uint32_t a) { uint32_t b = uint32_t(base.load(a, 4)); float f; std::memcpy(&f, &b, 4); return double(f); };
  double x[4], y[4];
  for (int i = 0; i < 4; ++i) { x[i] = f32(pts[i]); y[i] = f32(pts[i] + 4u); }
  const double right = f32(0x82040000u + 9648u), left = f32(0x82040000u + 9644u), bottom = f32(0x82040000u + 9640u);
  auto all_gt = [](const double* v, double c) { return v[0] > c && v[1] > c && v[2] > c && v[3] > c; };
  auto all_lt = [](const double* v, double c) { return v[0] < c && v[1] < c && v[2] < c && v[3] < c; };
  const bool out = all_gt(x, right) || all_lt(x, left) || all_gt(y, bottom) || all_lt(y, left);
  ctx.r3.u64 = out ? 1u : 0u;
}
#endif
#include "generated/sub_820A8FF8.inc"
#include "generated/sub_820A9068.inc"
#include "generated/sub_820A9D78.inc"
#include "generated/sub_820A9E98.inc"
#include "generated/sub_82127A08.inc"
#include "generated/sub_82127AE8.inc"
#include "generated/sub_82129038.inc"
// runtime021 play build wraps the guest memcpy (see runtime021/bodies.inc).
#ifdef CC_WRAP_82129A70
#define sub_82129A70 sub_82129A70_exact
#endif
#include "generated/sub_82129A70.inc"
#ifdef CC_WRAP_82129A70
#undef sub_82129A70
#endif
static void sub_82085C70(Context&, Machine& base) { base.fail(Error::unsupported, 0x82085C70u); }
static void sub_8208C5D8(Context&, Machine& base) { base.fail(Error::unsupported, 0x8208C5D8u); }
// WIP 023: sub_82127FB0 is now the exact generated body (runtime021).
