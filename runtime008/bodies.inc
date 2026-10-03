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
#ifdef CC_FAST
#define sub_82084100 sub_82084100_exact
#endif
#include "generated/sub_82084100.inc"
#ifdef CC_FAST
#undef sub_82084100
static void cc_oracle_mismatch(const char* fn, int slot, uint32_t exact, uint32_t native);
// Sprite colour (exact sub_82084100: out r3 = 4 floats, record r4 with
// int16 multipliers at +28, +30, +32, +40 and offsets at +34, +36, +38,
// +42, input r5 = 4 floats). out[i] = mul[i]/255 * in[i] + off[i], then
// clamped to [0, 255] (a NaN becomes 255). Rounding as compiled: the
// multiplier scaled by 1/255 (0x8204257C) is rounded to float, the
// multiply-add is fused, the result rounded to float.
static void cc_colour_native(Machine& base, Context& ctx, uint32_t out[4]) {
  ctx.fpscr.disableFlushMode();
  auto f32 = [](uint32_t b) { float f; __builtin_memcpy(&f, &b, 4); return double(f); };
  auto bits = [](double v) { const float f = float(v); uint32_t b; __builtin_memcpy(&b, &f, 4); return b; };
  auto r = [](double v) { return double(float(v)); };
  const uint32_t rec = ctx.r4.u32, in = ctx.r5.u32;
  const double inv = f32(REX_LOAD_U32(0x8204257Cu)), top = f32(REX_LOAD_U32(0x82042548u)), zero = f32(REX_LOAD_U32(0x82042540u));
  auto h = [&](uint32_t a) { return double(float(double(int16_t(REX_LOAD_U16(a))))); };
  const uint32_t mo[4] = {28u, 30u, 32u, 40u}, oo[4] = {34u, 36u, 38u, 42u};
  for (int i = 0; i < 4; ++i) {
    double v = r(std::fma(r(h(rec + mo[i]) * inv), f32(REX_LOAD_U32(in + 4u * uint32_t(i))), h(rec + oo[i])));
    v = (v < top) ? v : top;
    v = (v > zero) ? v : zero;
    out[i] = bits(v);
  }
}
static void sub_82084100(Context& ctx, Machine& base) {
#ifdef CC_SPRITE_EXACT_BUILD
  if (true) { sub_82084100_exact(ctx, base); return; }  // Xbox bisect build
#endif
  uint32_t out[4];
  cc_colour_native(base, ctx, out);
  const uint32_t o = ctx.r3.u32;
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
  if (oracle) {
    sub_82084100_exact(ctx, base);
    for (int k = 0; k < 4; ++k) {
      const uint32_t e = REX_LOAD_U32(o + 4u * uint32_t(k));
      if (e != out[k]) cc_oracle_mismatch("sub_82084100", k, e, out[k]);
    }
    return;
  }
#else
  static_cast<void>(&sub_82084100_exact);
#endif
  for (int k = 0; k < 4; ++k) REX_STORE_U32(o + 4u * uint32_t(k), out[k]);
}
// Oracle checks (host play build, CC_ORACLE=1): a native routine runs first,
// then the exact body; any difference in the outputs is logged. The exact
// result stays in effect, so an oracle run is also a normal run.
#ifndef CC_XBOX_DRIVER
static uint32_t g_oracle_mismatches = 0;
static void cc_oracle_mismatch(const char* fn, int slot, uint32_t exact, uint32_t native) {
  ++g_oracle_mismatches;
  if (g_oracle_mismatches <= 20u || (g_oracle_mismatches % 1000u) == 0u)
    cc_log("ORACLE %s slot=%d exact=%08x native=%08x total=%u\n", fn, slot, exact, native, g_oracle_mismatches);
}
#endif
#define sub_82085110 sub_82085110_exact
#endif
#include "generated/sub_82085110.inc"
#ifdef CC_FAST
#undef sub_82085110
// Sprite corners (exact sub_82085110: sprite r3 with its rectangle as int32
// left +96, right +100, top +104, bottom +108 in 1/20 pixel; matrix r4 with
// floats a +16, b +20, c +24, d +28, tx +32, ty +36; out points r5..r8 as
// {x, y, z}). Each corner of the rectangle scaled by 0.05 is mapped with
// the matrix entries pre-scaled by 0.01 (a, b) and 0.05 (c, d, tx, ty);
// z = 2000. The compiled original rounds the two products in a different
// order per corner; the same order is kept here so the results are
// bit-identical (constants 0x82042564 = 0.05, 0x82042574 = 0.01,
// 0x82042578 = 2000).
static void cc_corners_native(Context& ctx, Machine& base, uint32_t out[4][3]) {
  ctx.fpscr.disableFlushMode();
  auto f32 = [](uint32_t b) { float f; __builtin_memcpy(&f, &b, 4); return double(f); };
  auto bits = [](double v) { const float f = float(v); uint32_t b; __builtin_memcpy(&b, &f, 4); return b; };
  auto r = [](double v) { return double(float(v)); };
  const uint32_t s = ctx.r3.u32, m = ctx.r4.u32;
  const double c05 = f32(REX_LOAD_U32(0x82042564u)), c01 = f32(REX_LOAD_U32(0x82042574u));
  const uint32_t zb = REX_LOAD_U32(0x82042578u);
  auto cv = [&](uint32_t a) { return double(float(double(int32_t(REX_LOAD_U32(a))))); };
  const double x0 = r(cv(s + 96u) * c05), x1 = r(cv(s + 100u) * c05);
  const double y0 = r(cv(s + 104u) * c05), y1 = r(cv(s + 108u) * c05);
  const double a = f32(REX_LOAD_U32(m + 16u)), b = f32(REX_LOAD_U32(m + 20u)), c = f32(REX_LOAD_U32(m + 24u)),
               d = f32(REX_LOAD_U32(m + 28u)), tx = f32(REX_LOAD_U32(m + 32u)), ty = f32(REX_LOAD_U32(m + 36u));
  const double a01 = r(a * c01), b01 = r(b * c01), c05x = r(c * c05), d05 = r(d * c05);
  out[0][0] = bits(std::fma(tx, c05, r(std::fma(d05, y0, r(a01 * x0)))));   // p0 (x0, y0)
  out[0][1] = bits(std::fma(ty, c05, r(std::fma(c05x, x0, r(b01 * y0)))));
  out[1][0] = bits(std::fma(tx, c05, r(std::fma(a01, x1, r(d05 * y0)))));   // p1 (x1, y0)
  out[1][1] = bits(std::fma(ty, c05, r(std::fma(c05x, x1, r(b01 * y0)))));
  out[2][0] = bits(std::fma(tx, c05, r(std::fma(a01, x1, r(d05 * y1)))));   // p2 (x1, y1)
  out[2][1] = bits(std::fma(ty, c05, r(std::fma(c05x, x1, r(b01 * y1)))));
  out[3][0] = bits(std::fma(tx, c05, r(std::fma(a01, x0, r(d05 * y1)))));   // p3 (x0, y1)
  out[3][1] = bits(std::fma(ty, c05, r(std::fma(c05x, x0, r(b01 * y1)))));
  for (int i = 0; i < 4; ++i) out[i][2] = zb;
}
static void sub_82085110(Context& ctx, Machine& base) {
#ifdef CC_SPRITE_EXACT_BUILD
  if (true) { sub_82085110_exact(ctx, base); return; }  // Xbox bisect build
#endif
  uint32_t out[4][3];
  cc_corners_native(ctx, base, out);
  const uint32_t dst[4] = {ctx.r5.u32, ctx.r6.u32, ctx.r7.u32, ctx.r8.u32};
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
  if (oracle) {
    sub_82085110_exact(ctx, base);
    for (int i = 0; i < 4; ++i)
      for (int k = 0; k < 3; ++k) {
        const uint32_t e = REX_LOAD_U32(dst[i] + 4u * uint32_t(k));
        if (e != out[i][k]) cc_oracle_mismatch("sub_82085110", i * 3 + k, e, out[i][k]);
      }
    return;
  }
#else
  static_cast<void>(&sub_82085110_exact);
#endif
  for (int i = 0; i < 4; ++i)
    for (int k = 0; k < 3; ++k) REX_STORE_U32(dst[i] + 4u * uint32_t(k), out[i][k]);
}
#endif
#include "generated/sub_820855D8.inc"
#ifdef CC_FAST
#define sub_82085AD8 sub_82085AD8_exact
#endif
#include "generated/sub_82085AD8.inc"
#ifdef CC_FAST
#undef sub_82085AD8
// Sprite matrix multiply (exact sub_82085AD8: out r3, A r4, B r5; matrices
// hold floats a +16, b +20, c +24, d +28, tx +32, ty +36 in the game's
// fixed scales). out = {100, 100, 0, bytes 12..14 = 0, then
//   a' = 100 * (b24*0.05 * a28*0.05 + b16*0.01 * a16*0.01)
//   b' = 100 * (b28*0.05 * a24*0.05 + b20*0.01 * a20*0.01)
//   c' =  20 * (b16*0.01 * a24*0.05 + b24*0.05 * a20*0.01)
//   d' =  20 * (b20*0.01 * a28*0.05 + b28*0.05 * a16*0.01)
//   tx' = 20 * (a32*0.05 + a28*0.05 * b36*0.05 + a16*0.01 * b32*0.05)
//   ty' = 20 * (a36*0.05 + a24*0.05 * b32*0.05 + a20*0.01 * b36*0.05)}
// with the compiled original's rounding (each scaled entry rounded to
// float, the second product fused, the sum rounded). The byte at
// 0x8228A7B4 selects an extra fix-up call (sub_82085C70) that the harness
// never runs; that path keeps the exact body. Returns out in r3.
static void cc_matmul_native(Machine& base, Context& ctx, uint32_t A, uint32_t B, uint32_t out[6]) {
  ctx.fpscr.disableFlushMode();
  auto f32 = [](uint32_t b) { float f; __builtin_memcpy(&f, &b, 4); return double(f); };
  auto bits = [](double v) { const float f = float(v); uint32_t b; __builtin_memcpy(&b, &f, 4); return b; };
  auto r = [](double v) { return double(float(v)); };
  const double c05 = f32(REX_LOAD_U32(0x82042564u)), c01 = f32(REX_LOAD_U32(0x82042574u));
  const double k20 = f32(REX_LOAD_U32(0x82042568u)), k100 = f32(REX_LOAD_U32(0x8201473Cu));
  auto ld = [&](uint32_t a) { return f32(REX_LOAD_U32(a)); };
  const double a16c = r(ld(A + 16u) * c01), a20c = r(ld(A + 20u) * c01), a24c = r(ld(A + 24u) * c05), a28c = r(ld(A + 28u) * c05);
  const double a32 = ld(A + 32u), a36 = ld(A + 36u);
  const double b16c = r(ld(B + 16u) * c01), b20c = r(ld(B + 20u) * c01), b24c = r(ld(B + 24u) * c05), b28c = r(ld(B + 28u) * c05);
  const double b32c = r(ld(B + 32u) * c05), b36c = r(ld(B + 36u) * c05);
  const double f6 = r(std::fma(a28c, b36c, r(a16c * b32c)));
  const double f4 = r(std::fma(a24c, b32c, r(a20c * b36c)));
  const double f2 = r(std::fma(b24c, a28c, r(b16c * a16c)));
  const double f12 = r(std::fma(b28c, a24c, r(b20c * a20c)));
  const double f11 = r(std::fma(b16c, a24c, r(b24c * a20c)));
  const double f10 = r(std::fma(b20c, a28c, r(b28c * a16c)));
  const double f9 = r(std::fma(a32, c05, f6));
  const double f8 = r(std::fma(a36, c05, f4));
  out[0] = bits(f2 * k100); out[1] = bits(f12 * k100);
  out[2] = bits(f11 * k20); out[3] = bits(f10 * k20);
  out[4] = bits(f9 * k20); out[5] = bits(f8 * k20);
}
static void sub_82085AD8(Context& ctx, Machine& base) {
#ifdef CC_SPRITE_EXACT_BUILD
  if (true) { sub_82085AD8_exact(ctx, base); return; }  // Xbox bisect build
#endif
  if (REX_LOAD_U8(0x8228A7B4u) != 0u) { sub_82085AD8_exact(ctx, base); return; }
  uint32_t out[6];
  cc_matmul_native(base, ctx, ctx.r4.u32, ctx.r5.u32, out);
  const uint32_t o = ctx.r3.u32;
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
  if (oracle) {
    sub_82085AD8_exact(ctx, base);
    for (int k = 0; k < 6; ++k) {
      const uint32_t e = REX_LOAD_U32(o + 16u + 4u * uint32_t(k));
      if (e != out[k]) cc_oracle_mismatch("sub_82085AD8", k, e, out[k]);
    }
    return;
  }
#endif
  const uint32_t k100 = REX_LOAD_U32(0x8201473Cu);
  REX_STORE_U32(o + 0u, k100); REX_STORE_U32(o + 4u, k100); REX_STORE_U32(o + 8u, 0u);
  REX_STORE_U8(o + 12u, 0u); REX_STORE_U8(o + 13u, 0u); REX_STORE_U8(o + 14u, 0u);
  for (int k = 0; k < 6; ++k) REX_STORE_U32(o + 16u + 4u * uint32_t(k), out[k]);
}
#endif
#ifdef CC_FAST
#define sub_82086090 sub_82086090_exact
#endif
#include "generated/sub_82086090.inc"
#ifdef CC_FAST
#undef sub_82086090
// Matrix stack push (exact sub_82086090: stack r3, matrix r4, combine flag
// r5 byte). depth = ++[r3+9532]; the 40-byte entry at r3 + 8252 + 40*depth
// becomes (flag ? previous entry x matrix : matrix): floats +0, +4, +8,
// bytes +12..14, floats +16..36 (byte 15 untouched). The combined form is
// sub_82085AD8's result ({100, 100, 0}, zero bytes, product).
static void sub_82086090(Context& ctx, Machine& base) {
#ifdef CC_SPRITE_EXACT_BUILD
  if (true) { sub_82086090_exact(ctx, base); return; }  // Xbox bisect build
#endif
  const uint32_t st = ctx.r3.u32, m = ctx.r4.u32;
  const bool combine = (ctx.r5.u32 & 0xFFu) != 0u;
  if (combine && REX_LOAD_U8(0x8228A7B4u) != 0u) { sub_82086090_exact(ctx, base); return; }
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
#else
  constexpr bool oracle = false;
  static_cast<void>(&sub_82086090_exact);
#endif
  const uint32_t depth = REX_LOAD_U32(st + 9532u) + 1u;
  const uint32_t e = st + 8252u + depth * 40u;
  uint32_t v[10]; uint8_t by[3];
  if (combine) {
    // Operands passed directly: a whole-Context copy (2.6 KB, a byte-loop
    // memcpy under nxdk) here cost ~7 ms of render per level frame on Xbox.
    uint32_t prod[6];
    cc_matmul_native(base, ctx, e - 40u, m, prod);
    const uint32_t k100 = REX_LOAD_U32(0x8201473Cu);
    v[0] = k100; v[1] = k100; v[2] = 0u; by[0] = by[1] = by[2] = 0u;
    for (int k = 0; k < 6; ++k) v[4 + k] = prod[k];
  } else {
    v[0] = REX_LOAD_U32(m + 0u); v[1] = REX_LOAD_U32(m + 4u); v[2] = REX_LOAD_U32(m + 8u);
    by[0] = REX_LOAD_U8(m + 12u); by[1] = REX_LOAD_U8(m + 13u); by[2] = REX_LOAD_U8(m + 14u);
    for (int k = 0; k < 6; ++k) v[4 + k] = REX_LOAD_U32(m + 16u + 4u * uint32_t(k));
  }
#ifndef CC_XBOX_DRIVER
  if (oracle) {
    sub_82086090_exact(ctx, base);
    const int slots[9] = {0, 1, 2, 4, 5, 6, 7, 8, 9};
    for (int k : slots) {
      const uint32_t x = REX_LOAD_U32(e + 4u * uint32_t(k));
      if (x != v[k]) cc_oracle_mismatch("sub_82086090", k, x, v[k]);
    }
    for (int k = 0; k < 3; ++k) {
      const uint32_t x = REX_LOAD_U8(e + 12u + uint32_t(k));
      if (x != by[k]) cc_oracle_mismatch("sub_82086090", 10 + k, x, by[k]);
    }
    if (REX_LOAD_U32(st + 9532u) != depth) cc_oracle_mismatch("sub_82086090", 20, REX_LOAD_U32(st + 9532u), depth);
    return;
  }
#endif
  REX_STORE_U32(st + 9532u, depth);
  REX_STORE_U32(e + 0u, v[0]); REX_STORE_U32(e + 4u, v[1]); REX_STORE_U32(e + 8u, v[2]);
  REX_STORE_U8(e + 12u, by[0]); REX_STORE_U8(e + 13u, by[1]); REX_STORE_U8(e + 14u, by[2]);
  for (int k = 0; k < 6; ++k) REX_STORE_U32(e + 16u + 4u * uint32_t(k), v[4 + k]);
}
#endif
#include "generated/sub_82086278.inc"
#include "generated/sub_820868D0.inc"
#include "generated/sub_8208A7A0.inc"
#ifdef CC_FAST
// Native virtual call for the display-list walkers. The Flash display-list
// classes answer most per-node questions with one-instruction methods; the
// walkers call them millions of times per minute. A method known to be one
// of those leaves is answered directly (same result, and the leaves only
// write r3 and volatile scratch registers); anything else goes through the
// normal indirect call with r3 = object and the original return address.
// Two-instruction methods "li r3,K / lwz|lhz|lha|lbz r3,D(r3)" + blr are
// recognised from the original code (read once per method address from the
// mapped image, cached); no hand-written wrapper is such a method.
struct CcLeaf { uint32_t fn; uint8_t kind; int32_t imm; };  // kind 0 unknown, 1 not a leaf, 2.. leaf
static CcLeaf g_leaf_cache[1024];
static inline const CcLeaf& cc_leaf_info(Machine& base, uint32_t fn) {
  CcLeaf& e = g_leaf_cache[(fn >> 2) & 1023u];
  if (e.fn == fn && e.kind) return e;
  e.fn = fn; e.kind = 1; e.imm = 0;
  if (fn >= 0x82000000u && fn < 0x822D0000u) {
    uint64_t i0 = 0, i1 = 0;
    base.memory.load_be(fn, 4, i0);
    base.memory.load_be(fn + 4u, 4, i1);
    if (uint32_t(i1) == 0x4E800020u) {
      const uint32_t op = uint32_t(i0) >> 16;
      e.imm = int32_t(int16_t(uint16_t(i0)));
      if (op == 0x3860u) e.kind = 2;        // li r3,K
      else if (op == 0x8063u) e.kind = 3;   // lwz r3,D(r3)
      else if (op == 0xA063u) e.kind = 4;   // lhz r3,D(r3)
      else if (op == 0xA863u) e.kind = 5;   // lha r3,D(r3)
      else if (op == 0x8863u) e.kind = 6;   // lbz r3,D(r3)
    }
  }
  return e;
}
static inline bool cc_leaf_method(Machine& base, uint32_t fn, uint32_t obj, uint64_t& r3) {
  switch (fn) {
    case 0x820867D0u: r3 = REX_LOAD_U16(obj + 100u) != 0u ? 1u : 0u; return true;  // u16 +100 != 0
    case 0x82086818u: r3 = (REX_LOAD_U8(obj + 140u) >> 2) & 1u; return true;    // bit 2 of byte +140
    default: break;
  }
  const CcLeaf& e = cc_leaf_info(base, fn);
  const uint32_t a = obj + uint32_t(e.imm);
  switch (e.kind) {
    case 2: r3 = uint64_t(int64_t(e.imm)); return true;             // sign-extended like li
    case 3: r3 = REX_LOAD_U32(a); return true;
    case 4: r3 = REX_LOAD_U16(a); return true;
    case 5: r3 = uint64_t(int64_t(int16_t(REX_LOAD_U16(a)))); return true;
    case 6: r3 = REX_LOAD_U8(a); return true;
    default: return false;
  }
}
static inline uint32_t cc_vcall_ic(Context& ctx, Machine& base, uint32_t obj, uint32_t slot, uint32_t lr,
                                   uint32_t& ic_key, CcGenFn& ic_fn) {
  const uint32_t fn = REX_LOAD_U32(REX_LOAD_U32(obj) + slot);
  uint64_t r3 = 0;
  if (cc_leaf_method(base, fn, obj, r3)) { ctx.r3.u64 = r3; return uint32_t(r3); }
  ctx.r3.u64 = obj;
  ctx.lr = lr;
  if (fn == ic_key) ic_fn(ctx, base);
  else cc_dispatch_cached(fn, ctx, base, ic_key, ic_fn);
  return ctx.r3.u32;
}
// One inline cache per call site, like the generated code's indirect calls
// (a shared cache would miss on every alternation of targets).
#define cc_vcall(CTX, BASE, OBJ, SLOT, LR) ([&]() -> uint32_t { \
    static uint32_t cc_vic_key = 0; static CcGenFn cc_vic_fn = nullptr; \
    return cc_vcall_ic(CTX, BASE, OBJ, SLOT, LR, cc_vic_key, cc_vic_fn); }())
// Native frame for a walker: the exact walkers open a stack frame before
// their calls; callees then use the stack below it.
struct CcFrame {
  Context& c; uint32_t saved;
  CcFrame(Context& ctx, Machine& base, uint32_t size) : c(ctx), saved(ctx.r1.u32) {
    const uint32_t nr1 = saved - size;
    REX_STORE_U32(nr1, saved);
    ctx.r1.u64 = nr1;
  }
  ~CcFrame() { c.r1.u64 = saved; }
};
#define sub_8208AF08 sub_8208AF08_exact
#endif
#include "generated/sub_8208AF08.inc"
#ifdef CC_FAST
#undef sub_8208AF08
// Display-list query (exact sub_8208AF08: node r3). Walks the children via
// the node's iterator method (slot 156 on the node, then on each child);
// returns 0 as soon as a child that is "active" (slot 44) has bit 0 of byte
// +140 clear, else bit 0 of the node's own byte +140.
static void sub_8208AF08(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  static const bool walk_exact = std::getenv("CC_WALK_EXACT") != nullptr;  // host A/B switch
  if (walk_exact) { sub_8208AF08_exact(ctx, base); return; }
#else
  #ifdef CC_WALK_EXACT_BUILD
  sub_8208AF08_exact(ctx, base); return;  // Xbox bisect build
#endif
  static_cast<void>(&sub_8208AF08_exact);
#endif
  const uint32_t node = ctx.r3.u32;
  CcFrame frame(ctx, base, 112u);
  uint32_t ch = cc_vcall(ctx, base, node, 156u, 0x8208AF30u);
  while (ch) {
    if ((cc_vcall(ctx, base, ch, 44u, 0x8208AF50u) & 0xFFu) != 0u && (REX_LOAD_U8(ch + 140u) & 1u) == 0u) {
      ctx.r3.u64 = 0u;
      return;
    }
    ch = cc_vcall(ctx, base, ch, 156u, 0x8208AF80u);
  }
  ctx.r3.u64 = REX_LOAD_U8(node + 140u) & 1u;
}
#endif
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
