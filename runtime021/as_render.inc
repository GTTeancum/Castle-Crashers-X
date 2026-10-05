// Native display-list drawing walk (included by as_native.inc).

// Clip draw walk (exact sub_8208A7A0: clip r3, draw state r4, renderer r5,
// stop-at child r6; returns flags). Renderer methods take a return buffer in
// r3 and the renderer in r4: slot 32 pushes a state (r5 mode), slot 36 pops.
// The clip's slot 48 runs first; a stop-at child equal to the clip itself
// counts as none. A nonzero s32 +152 pushes renderer mode +152 (u16) for the
// whole walk. Children (+104, linked through +88):
//  - a child that answers slot 44 but, with bit 7 of its byte +140, also
//    answers slot 180, or that does not answer slot 44, is drawn when bit 4
//    of its byte +86 is set; any other child equal to the stop-at child
//    ends the walk with flag 2.
//  - drawing: the clip is pushed on the state's update stack (+8248); with
//    bit 7 of +86 the child's matrix (+36; the identity at 0x82290AA0, set up
//    once under bit 0 of 0x82290AC8, when the bit is clear on re-read) is
//    pushed (sub_82086090, r5 = 1); a child with a colour transform (+76)
//    pushes its colour (sub_820836E0, then sub_82084100 into the state's
//    colour stack at +(n+595)*16, the result copied to +(n+596)*16). A child
//    with a nonzero s32 +32 pushes it on the state's clip-depth stack
//    (+10312, entries at +(n+2546)*4) and renderer mode 11; otherwise, while
//    depth entries are open, a child deeper (s32 +28) than the top entry pops
//    a state, pushes mode 0 and replaces the top with 99999999, else pops and
//    pushes mode 10. The child draws through its slot 68 (r4 state, r5
//    renderer, r6 stop-at child); colour and matrix stacks are popped, the
//    update stack popped, the result OR-ed into the flags; flag 2 ends the
//    walk.
// Afterwards the +152 mode and every open depth entry pop a renderer state.
static CC_HOT_FN void sub_8208A7A0(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8208A7A0);
  CC_FPROF_SCOPE(sub_8208A7A0_native);
  const uint32_t clip = ctx.r3.u32, st = ctx.r4.u32, rnd = ctx.r5.u32;
  uint32_t stop = ctx.r6.u32;
  CcFrame frame(ctx, base, 256u);
  const uint32_t r1 = ctx.r1.u32;
  uint32_t r23 = 0, flags = 0, depth = 0;
  cc_vcall(ctx, base, clip, 48u, 0x8208A7DCu);
  if (stop == clip) stop = 0u;
  if (int32_t(REX_LOAD_U32(clip + 152u)) != 0) {
    ctx.r4.u64 = rnd; ctx.r5.u64 = REX_LOAD_U32(clip + 152u) & 0xFFFFu;
    ctx.r3.u64 = r1 + 80u; ctx.lr = 0x8208A814u;
    REX_CALL_INDIRECT_FUNC(REX_LOAD_U32(REX_LOAD_U32(rnd) + 32u));
  }
  for (uint32_t ch = REX_LOAD_U32(clip + 104u); ch != 0u; ch = REX_LOAD_U32(ch + 88u)) {
    bool draw;
    if ((cc_vcall(ctx, base, ch, 44u, 0x8208A858u) & 0xFFu) == 0u) {
      draw = true;
    } else if ((REX_LOAD_U8(ch + 140u) & 0x80u) != 0u && (cc_vcall(ctx, base, ch, 180u, 0x8208A888u) & 0xFFu) != 0u) {
      draw = true;
    } else {
      if (stop == ch) { r23 = 2u; break; }
      continue;
    }
    if (!draw || (REX_LOAD_U8(ch + 86u) & 0x10u) == 0u) continue;
    {
      const uint32_t n = REX_LOAD_U32(st + 8248u) + 1u;
      REX_STORE_U32(st + 8248u, n);
      REX_STORE_U32(st + (n + 1998u) * 4u, clip);
    }
    if ((REX_LOAD_U8(ch + 86u) & 0x80u) != 0u) {
      const uint32_t flag = REX_LOAD_U32(0x82290AC8u);
      if ((flag & 1u) == 0u) {
        const uint32_t id = 0x82290AA0u;
        const uint32_t f100 = REX_LOAD_U32(0x8201473Cu), f0 = REX_LOAD_U32(0x82042540u);
        REX_STORE_U32(id + 0u, f100);
        REX_STORE_U32(id + 4u, f100);
        REX_STORE_U32(id + 8u, f0);
        REX_STORE_U32(id + 16u, f100);
        REX_STORE_U32(id + 20u, f100);
        REX_STORE_U32(0x82290AC8u, flag | 1u);
        REX_STORE_U32(id + 24u, f0);
        REX_STORE_U8(id + 12u, uint8_t(r23));
        REX_STORE_U32(id + 28u, f0);
        REX_STORE_U8(id + 13u, uint8_t(r23));
        REX_STORE_U32(id + 32u, f0);
        REX_STORE_U8(id + 14u, uint8_t(r23));
        REX_STORE_U32(id + 36u, f0);
      }
      ctx.r4.u64 = (REX_LOAD_U8(ch + 86u) & 0x80u) != 0u ? ch + 36u : 0x82290AA0u;
      ctx.r3.u64 = st; ctx.r5.u64 = 1u; ctx.lr = 0x8208A9C0u;
      sub_82086090(ctx, base);
    }
    if (REX_LOAD_U32(ch + 76u) != 0u) {
      ctx.r3.u64 = ch; ctx.lr = 0x8208A9D4u;
      sub_820836E0(ctx, base);
      const uint32_t src = ctx.r3.u32;
      const uint32_t n = REX_LOAD_U32(st + 10048u) + 1u;
      REX_STORE_U32(st + 10048u, n);
      ctx.r3.u64 = r1 + 128u; ctx.r4.u64 = src; ctx.r5.u64 = st + (n + 595u) * 16u; ctx.lr = 0x8208A9F8u;
      sub_82084100(ctx, base);
      const uint32_t res = ctx.r3.u32;
      const uint32_t dst = st + (REX_LOAD_U32(st + 10048u) + 596u) * 16u;
      REX_STORE_U32(dst + 0u, REX_LOAD_U32(res + 0u));
      REX_STORE_U32(dst + 4u, REX_LOAD_U32(res + 4u));
      REX_STORE_U32(dst + 8u, REX_LOAD_U32(res + 8u));
      REX_STORE_U32(dst + 12u, REX_LOAD_U32(res + 12u));
    }
    const uint32_t cd = REX_LOAD_U32(ch + 32u);
    if (int32_t(cd) != 0) {
      const uint32_t n = REX_LOAD_U32(st + 10312u) + 1u;
      REX_STORE_U32(st + 10312u, n);
      REX_STORE_U32(st + (n + 2546u) * 4u, cd);
      ctx.r3.u64 = r1 + 80u; ctx.r4.u64 = rnd; ctx.r5.u64 = 11u; ctx.lr = 0x8208AA68u;
      REX_CALL_INDIRECT_FUNC(REX_LOAD_U32(REX_LOAD_U32(rnd) + 32u));
      ++depth;
    } else if (depth != 0u) {
      const uint32_t top = REX_LOAD_U32(st + (REX_LOAD_U32(st + 10312u) + 2546u) * 4u);
      const uint32_t pop_fn = REX_LOAD_U32(REX_LOAD_U32(rnd) + 36u);
      if (int32_t(REX_LOAD_U32(ch + 28u)) > int32_t(top)) {
        ctx.r3.u64 = r1 + 88u; ctx.r4.u64 = rnd; ctx.lr = 0x8208AAACu;
        REX_CALL_INDIRECT_FUNC(pop_fn);
        ctx.r3.u64 = r1 + 96u; ctx.r4.u64 = rnd; ctx.r5.u64 = 0u; ctx.lr = 0x8208AAC8u;
        REX_CALL_INDIRECT_FUNC(REX_LOAD_U32(REX_LOAD_U32(rnd) + 32u));
        const uint32_t m = REX_LOAD_U32(st + 10312u);
        REX_STORE_U32(st + 10312u, m);
        REX_STORE_U32(st + (m + 2546u) * 4u, 0x05F5E0FFu);
      } else {
        ctx.r3.u64 = r1 + 104u; ctx.r4.u64 = rnd; ctx.lr = 0x8208AAECu;
        REX_CALL_INDIRECT_FUNC(pop_fn);
        ctx.r3.u64 = r1 + 112u; ctx.r4.u64 = rnd; ctx.r5.u64 = 10u; ctx.lr = 0x8208AB08u;
        REX_CALL_INDIRECT_FUNC(REX_LOAD_U32(REX_LOAD_U32(rnd) + 32u));
      }
    }
    ctx.r4.u64 = st; ctx.r5.u64 = rnd; ctx.r6.u64 = stop;
    const uint32_t r = cc_vcall(ctx, base, ch, 68u, 0x8208AB28u);
    if (REX_LOAD_U32(ch + 76u) != 0u) REX_STORE_U32(st + 10048u, REX_LOAD_U32(st + 10048u) - 1u);
    if ((REX_LOAD_U8(ch + 86u) & 0x80u) != 0u) REX_STORE_U32(st + 9532u, REX_LOAD_U32(st + 9532u) - 1u);
    flags |= r;
    REX_STORE_U32(st + (REX_LOAD_U32(st + 8248u) + 1998u) * 4u, r23);
    REX_STORE_U32(st + 8248u, REX_LOAD_U32(st + 8248u) - 1u);
    if ((flags & 2u) != 0u) break;
  }
  if (int32_t(REX_LOAD_U32(clip + 152u)) != 0) {
    ctx.r3.u64 = r1 + 112u; ctx.r4.u64 = rnd; ctx.lr = 0x8208A8C4u;
    REX_CALL_INDIRECT_FUNC(REX_LOAD_U32(REX_LOAD_U32(rnd) + 36u));
  }
  for (uint32_t k = depth; k != 0u; --k) {
    REX_STORE_U32(st + 10312u, REX_LOAD_U32(st + 10312u) - 1u);
    ctx.r3.u64 = r1 + 112u; ctx.r4.u64 = rnd; ctx.lr = 0x8208A8F4u;
    REX_CALL_INDIRECT_FUNC(REX_LOAD_U32(REX_LOAD_U32(rnd) + 36u));
  }
  ctx.r3.u64 = flags | r23;
}

// fctidz / fcfid as the recompiled code computes them.
static CC_HOT_FN inline int64_t cc_render_fctidz(double f) {
  return std::isnan(f) ? int64_t(0x8000000000000000ULL) : (f > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f));
}

// Sprite draw (exact sub_820855D8: sprite r3, draw state r4, renderer r5,
// stop-at node r6; returns 1 when culled, 2 when the sprite is the stop-at
// node, else 0). A stop-at node other than this sprite returns 0 at once.
// With a texture (+92): bit 6 of byte +86 set; renderer slot 40; the four
// corners (sub_82085110 with the state's current matrix at
// +8252 + 40 * [+9532], into four zeroed frame triples); renderer slot 108
// culls them (r8 = 4). Otherwise the texture is bound (renderer slot 92) and
// the quad emitted (slot 116) with uv extents u = tex+60 / tex+68 and
// v = tex+64 / tex+72 (u32 -> float, divided as floats), the colour packed
// from the state's current colour (+(+10048 + 596) * 16, floats truncated:
// ((((a << 8) | r) << 8 | g) << 8) | b with a at +0) and 4 points; the
// ninth and later arguments sit at the frame's +84 / +92 / +100.
static CC_HOT_FN void sub_820855D8(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_820855D8);
  CC_FPROF_SCOPE(sub_820855D8_native);
  const uint32_t spr = ctx.r3.u32, st = ctx.r4.u32, rnd = ctx.r5.u32, stop = ctx.r6.u32;
  if (stop != 0u && stop != spr) { ctx.r3.u64 = 0u; return; }
  if (REX_LOAD_U32(spr + 92u) != 0u) {
    CcFrame frame(ctx, base, 288u);
    const uint32_t r1 = ctx.r1.u32;
    REX_STORE_U8(spr + 86u, uint8_t(REX_LOAD_U8(spr + 86u) | 64u));
    cc_vcall(ctx, base, rnd, 40u, 0x82085650u);
    const uint32_t zero = REX_LOAD_U32(0x82042540u);
    const uint32_t m = st + REX_LOAD_U32(st + 9532u) * 40u + 8252u;
    for (uint32_t off : {216u, 220u, 224u, 200u, 204u, 208u, 184u, 188u, 192u, 168u, 172u, 176u})
      REX_STORE_U32(r1 + off, zero);
    ctx.r3.u64 = spr; ctx.r4.u64 = m; ctx.r5.u64 = r1 + 216u; ctx.r6.u64 = r1 + 200u; ctx.r7.u64 = r1 + 184u;
    ctx.r8.u64 = r1 + 168u; ctx.lr = 0x820856BCu;
    sub_82085110(ctx, base);
    ctx.r4.u64 = r1 + 216u; ctx.r5.u64 = r1 + 200u; ctx.r6.u64 = r1 + 184u; ctx.r7.u64 = r1 + 168u; ctx.r8.u64 = 4u;
    if ((cc_vcall(ctx, base, rnd, 108u, 0x820856E4u) & 0xFFu) != 0u) { ctx.r3.u64 = 1u; return; }
    const uint32_t tex = REX_LOAD_U32(spr + 92u);
    const uint32_t col = st + (REX_LOAD_U32(st + 10048u) + 596u) * 16u;
    const uint32_t t60 = REX_LOAD_U32(tex + 60u), t68 = REX_LOAD_U32(tex + 68u);
    const uint32_t t64 = REX_LOAD_U32(tex + 64u), t72 = REX_LOAD_U32(tex + 72u);
    const uint32_t bind = REX_LOAD_U32(REX_LOAD_U32(rnd) + 92u);
    ctx.fpscr.disableFlushMode();
    auto chan = [&](uint32_t off) {
      PPCRegister x{};
      x.u32 = REX_LOAD_U32(col + off);
      return uint32_t(cc_render_fctidz(double(x.f32)));
    };
    const uint32_t c1 = chan(4u), c2 = chan(8u), c3 = chan(12u), c0 = chan(0u);
    const uint32_t p1 = ((c0 << 8) & 0xFFFFFF00u) | c1;
    const uint32_t p2 = ((p1 << 8) & 0xFFFFFF00u) | c2;
    const uint32_t packed = ((p2 << 8) & 0xFFFFFF00u) | c3;
    REX_STORE_U32(r1 + 136u, zero);
    REX_STORE_U32(r1 + 140u, zero);
    REX_STORE_U32(r1 + 132u, zero);
    REX_STORE_U32(r1 + 112u, zero);
    const double fu = double(float(double(int64_t(t60)))) / double(float(double(int64_t(t68))));
    const double fv = double(float(double(int64_t(t64)))) / double(float(double(int64_t(t72))));
    PPCRegister u{}, v{};
    u.f32 = float(fu);
    v.f32 = float(fv);
    REX_STORE_U32(r1 + 128u, u.u32);
    REX_STORE_U32(r1 + 120u, u.u32);
    REX_STORE_U32(r1 + 124u, v.u32);
    REX_STORE_U32(r1 + 116u, v.u32);
    ctx.r3.u64 = rnd; ctx.r4.u64 = tex; ctx.lr = 0x820857F4u;
    REX_CALL_INDIRECT_FUNC(bind);
    REX_STORE_U32(r1 + 92u, packed);
    REX_STORE_U32(r1 + 100u, 4u);
    REX_STORE_U32(r1 + 84u, r1 + 112u);
    ctx.r3.u64 = rnd; ctx.r4.u64 = r1 + 216u; ctx.r5.u64 = r1 + 200u; ctx.r6.u64 = r1 + 184u; ctx.r7.u64 = r1 + 168u;
    ctx.r8.u64 = r1 + 136u; ctx.r9.u64 = r1 + 128u; ctx.r10.u64 = r1 + 120u;
    cc_vcall(ctx, base, rnd, 116u, 0x82085838u);
  }
  ctx.r3.u64 = (stop == spr) ? 2u : 0u;
}
