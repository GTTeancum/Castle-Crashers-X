// Native value conversions and arithmetic / compare handlers (included by
// as_ops.inc after its helpers). The conversions replace sub_82082890,
// sub_82082700 and sub_82082BB0; the handlers use their direct forms.

// Float constant at 0x82040000 + off as the handlers load it (9536 is the
// zero constant, 9540 the one constant).
static inline double cc_asconv_k(Machine& base, uint32_t off) {
  PPCRegister x{};
  x.u32 = REX_LOAD_U32(0x82040000u + off);
  return double(x.f32);
}

// fctiwz as the recompiled code computes it (truncation, NaN -> 0x80000000,
// saturating); the low word, as lwz 84 of the stored double reads it.
static inline uint32_t cc_asconv_fctiwz(double f) {
  const int64_t r = std::isnan(f) ? int64_t(0x80000000U)
                    : (f >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f));
  return uint32_t(r);
}

// Text of a string id in the global string table [0x822666DC]: id 0 -> the
// table's +12, else [table+28][id].
static inline uint32_t cc_asconv_text(Machine& base, uint32_t id) {
  const uint32_t tbl = REX_LOAD_U32(0x822666DCu);
  return id ? REX_LOAD_U32(REX_LOAD_U32(tbl + 28u) + id * 4u) : tbl + 12u;
}

// ToString id, the formatting cases (the original's 624-byte frame, string
// {u32 length, text} at +96): int -> sub_820798D8(format 0x8203E45C, value);
// number -> the same with fctiwz of the float when that converts back to
// the same value, else sub_820798D8(format 0x8203E460, the float as a
// double in r4); the result copied to +96 (sub_82053A00). 1024 (clip) ->
// its path: its name (slot 72 id, text copied to +96), then up the parent
// chain (slot 156) each parent with a nonzero name id is prepended: parent
// name + separator 0x8203E458 + path (sub_82075210 twice, results at +416 /
// +496), or just the parent name (at +176) while the path is empty, copied
// back to +100 (sub_82129A70) with length +96 and a zero byte. The text at
// +100 is interned in the global string table (sub_8209D948); r3 as it
// returns.
static uint32_t cc_asconv_tostr_slow(Context& ctx, Machine& base, uint32_t v, uint32_t t) {
  CcFrame frame(ctx, base, 624u);
  const uint32_t r1 = ctx.r1.u32;
  if (t == 1024u) {
    const uint32_t obj = REX_LOAD_U32(v + 4u);
    const uint32_t id = cc_vcall(ctx, base, obj, 72u, 0x820829A0u) & 0xFFFFu;
    ctx.r4.u64 = cc_asconv_text(base, id);
    ctx.r3.u64 = r1 + 96u; ctx.lr = 0x820829D4u;
    sub_82053A00(ctx, base);
    uint32_t node = cc_vcall(ctx, base, obj, 156u, 0x820829E8u);
    while (node != 0u) {
      const uint32_t pid = cc_vcall(ctx, base, node, 72u, 0x82082A10u) & 0xFFFFu;
      if (pid != 0u) {
        uint32_t len, src;
        if (REX_LOAD_U32(r1 + 96u) != 0u) {
          ctx.r3.u64 = r1 + 256u; ctx.r4.u64 = 0x8203E458u; ctx.lr = 0x82082A34u;  // 0x82040000 - 7080
          sub_82053A00(ctx, base);
          ctx.r4.u64 = cc_asconv_text(base, pid);
          ctx.r3.u64 = r1 + 336u; ctx.lr = 0x82082A64u;
          sub_82053A00(ctx, base);
          ctx.r5.u64 = r1 + 256u; ctx.r4.u64 = r1 + 336u; ctx.r3.u64 = r1 + 416u; ctx.lr = 0x82082A78u;
          sub_82075210(ctx, base);
          ctx.r4.u64 = ctx.r3.u64; ctx.r3.u64 = r1 + 496u; ctx.r5.u64 = r1 + 96u; ctx.lr = 0x82082A88u;
          sub_82075210(ctx, base);
          const uint32_t res = ctx.r3.u32;
          src = res + 4u;
          len = REX_LOAD_U32(res);
        } else {
          ctx.r4.u64 = cc_asconv_text(base, pid);
          ctx.r3.u64 = r1 + 176u; ctx.lr = 0x82082AC8u;
          sub_82053A00(ctx, base);
          src = r1 + 180u;
          len = REX_LOAD_U32(r1 + 176u);
        }
        ctx.r5.u64 = len; ctx.r4.u64 = src; ctx.r3.u64 = r1 + 100u; ctx.lr = 0x82082ADCu;
        sub_82129A70(ctx, base);
        REX_STORE_U32(r1 + 96u, len);
        REX_STORE_U8(len + r1 + 100u, 0u);
      }
      node = cc_vcall(ctx, base, node, 156u, 0x82082AFCu);
    }
    ctx.r4.u64 = r1 + 100u; ctx.r3.u64 = REX_LOAD_U32(0x822666DCu); ctx.lr = 0x82082B14u;
    sub_8209D948(ctx, base);
    return ctx.r3.u32;
  }
  uint32_t lr_copy, lr_intern;
  if (t == 4u) {
    ctx.r4.u64 = REX_LOAD_U32(v + 4u);
    REX_STORE_U32(r1 + 96u, 0u);
    REX_STORE_U8(r1 + 100u, 0u);
    ctx.r3.u64 = 0x8203E45Cu; ctx.lr = 0x820828D8u;  // 0x82040000 - 7076
    sub_820798D8(ctx, base);
    lr_copy = 0x820828E4u; lr_intern = 0x820828F4u;
  } else {
    ctx.fpscr.disableFlushMode();
    PPCRegister x{};
    x.u32 = REX_LOAD_U32(v + 4u);
    const double f0 = double(x.f32);
    const uint32_t iv = cc_asconv_fctiwz(f0);
    const double f10 = double(float(double(int64_t(int32_t(iv)))));
    REX_STORE_U32(r1 + 96u, 0u);
    REX_STORE_U8(r1 + 100u, 0u);
    if (f0 == f10) {
      ctx.r3.u64 = 0x8203E45Cu; ctx.r4.u64 = iv; ctx.lr = 0x82082B6Cu;  // 0x82040000 - 7076
      sub_820798D8(ctx, base);
    } else {
      ctx.fpscr.disableFlushMode();
      PPCRegister y{};
      y.u32 = REX_LOAD_U32(v + 4u);
      ctx.f1.f64 = double(y.f32);
      ctx.r4.u64 = ctx.f1.u64;
      ctx.r3.u64 = 0x8203E460u; ctx.lr = 0x82082B88u;  // 0x82040000 - 7072
      sub_820798D8(ctx, base);
    }
    lr_copy = 0x82082B94u; lr_intern = 0x82082BA4u;
  }
  ctx.r4.u64 = ctx.r3.u64; ctx.r3.u64 = r1 + 96u; ctx.lr = lr_copy;
  sub_82053A00(ctx, base);
  ctx.r3.u64 = REX_LOAD_U32(0x822666DCu); ctx.r4.u64 = r1 + 100u; ctx.lr = lr_intern;
  sub_8209D948(ctx, base);
  return ctx.r3.u32;
}

// ToString id (exact sub_82082890: value r3; returns the id in r3): string
// -> its u16 id; bool -> 126 for a byte of 1, else 127; int, number and
// 1024 -> formatted and interned (above); anything else 0. The id is also
// left in r3 as the original leaves it.
static inline uint32_t cc_as_tostr_id(Context& ctx, Machine& base, uint32_t v) {
  const uint32_t t = REX_LOAD_U32(v);
  uint32_t r = 0u;
  if (t == 8u) {
    r = REX_LOAD_U16(v + 4u);
  } else if (t == 2u) {
    r = REX_LOAD_U8(v + 4u) == 1u ? 126u : 127u;
  } else if (t == 4u || t == 16u || t == 1024u) {
    return cc_asconv_tostr_slow(ctx, base, v, t);
  }
  ctx.r3.u64 = r;
  return r;
}
static void sub_82082890(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_82082890);
  CC_FPROF_SCOPE(sub_82082890_native);
  cc_as_tostr_id(ctx, base, ctx.r3.u32);
}

// ToNumber (exact sub_82082700: value r3; returns f1): number -> its
// float; int (signed) and bool -> converted and rounded to float; string ->
// strtod sub_82128290(text, 0) rounded to float; 1024 and 16384 -> the one
// constant when the payload is nonzero; anything else the zero constant.
static inline double cc_as_tonum(Context& ctx, Machine& base, uint32_t v) {
  const uint32_t t = REX_LOAD_U32(v);
  switch (t) {
    case 16u: {
      ctx.fpscr.disableFlushMode();
      PPCRegister x{};
      x.u32 = REX_LOAD_U32(v + 4u);
      return double(x.f32);
    }
    case 4u:
      ctx.fpscr.disableFlushMode();
      return double(float(double(int64_t(int32_t(REX_LOAD_U32(v + 4u))))));
    case 2u:
      ctx.fpscr.disableFlushMode();
      return double(float(double(int64_t(REX_LOAD_U8(v + 4u)))));
    case 8u: {
      const uint32_t id = REX_LOAD_U16(v + 4u);
      ctx.r3.u64 = cc_asconv_text(base, id);
      ctx.r4.u64 = 0u;
      ctx.lr = id ? 0x82082784u : 0x82082754u;
      sub_82128290(ctx, base);
      ctx.fpscr.disableFlushMode();
      return double(float(ctx.f1.f64));
    }
    case 1024u: case 16384u:
      if (REX_LOAD_U32(v + 4u) != 0u) {
        ctx.fpscr.disableFlushMode();
        return cc_asconv_k(base, 9540u);
      }
      break;
    default: break;
  }
  ctx.fpscr.disableFlushMode();
  return cc_asconv_k(base, 9536u);
}
static void sub_82082700(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_82082700);
  CC_FPROF_SCOPE(sub_82082700_native);
  ctx.f1.f64 = cc_as_tonum(ctx, base, ctx.r3.u32);
}

// ToInt (exact sub_82082BB0: value r3; returns r3): bool -> its byte; int
// -> payload; number -> fctiwz of the float; string -> strtol base 10
// sub_82128298(text) (r3 as it returns); anything else 0. The result is
// also left in r3.
static inline uint32_t cc_as_toint(Context& ctx, Machine& base, uint32_t v) {
  const uint32_t t = REX_LOAD_U32(v);
  uint32_t r = 0u;
  switch (t) {
    case 2u: r = REX_LOAD_U8(v + 4u); break;
    case 4u: r = REX_LOAD_U32(v + 4u); break;
    case 16u: {
      ctx.fpscr.disableFlushMode();
      PPCRegister x{};
      x.u32 = REX_LOAD_U32(v + 4u);
      r = cc_asconv_fctiwz(double(x.f32));
      break;
    }
    case 8u: {
      const uint32_t id = REX_LOAD_U16(v + 4u);
      ctx.r3.u64 = cc_asconv_text(base, id);
      ctx.lr = id ? 0x82082CACu : 0x82082C84u;
      sub_82128298(ctx, base);
      return ctx.r3.u32;
    }
    default: break;
  }
  ctx.r3.u64 = r;
  return r;
}
static void sub_82082BB0(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_82082BB0);
  CC_FPROF_SCOPE(sub_82082BB0_native);
  cc_as_toint(ctx, base, ctx.r3.u32);
}

// Operands of the numeric binary handlers: a (top) then b popped and
// released; ToNumber of a, then of b (the zero constant z for undefined).
struct CcAsConvNum2 {
  uint32_t a, b;
  double fa, fb, z;
};
static inline CcAsConvNum2 cc_asconv_num2(Context& ctx, Machine& base, uint32_t s, uint32_t lr_a1, uint32_t lr_a2,
                                          uint32_t lr_b1, uint32_t lr_b2) {
  CcAsConvNum2 n;
  n.a = cc_as_pop_release(ctx, base, s, lr_a1, lr_a2);
  n.b = cc_as_pop_release(ctx, base, s, lr_b1, lr_b2);
  ctx.fpscr.disableFlushMode();
  n.z = cc_asconv_k(base, 9536u);
  n.fa = REX_LOAD_U32(n.a) != kAsUndef ? cc_as_tonum(ctx, base, n.a) : n.z;
  n.fb = REX_LOAD_U32(n.b) != kAsUndef ? cc_as_tonum(ctx, base, n.b) : n.z;
  return n;
}
// Boolean result of a binary handler: b = {2, r} (byte), pushed (pool
// re-read from S), then a's slot freed.
static inline void cc_asconv_put_bool(Machine& base, uint32_t s, uint32_t a, uint32_t b, uint32_t r) {
  REX_STORE_U8(b + 4u, uint8_t(r));
  REX_STORE_U32(b + 0u, 2u);
  cc_as_push(base, cc_as_pool(base, s), b);
  cc_as_free(base, a);
}
// Number result of a binary handler: b = {16, r}, pushed, a's slot freed.
static inline void cc_asconv_put_num(Machine& base, uint32_t s, uint32_t a, uint32_t b, float r) {
  PPCRegister x{};
  x.f32 = r;
  REX_STORE_U32(b + 4u, x.u32);
  REX_STORE_U32(b + 0u, 16u);
  cc_as_push(base, cc_as_pool(base, s), b);
  cc_as_free(base, a);
}

// Subtract (exact sub_8207C048, op 0x0B): b - a (ToNumber, single
// precision) into b.
static uint32_t cc_as_op_0B(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_0B);
  const CcAsConvNum2 n = cc_asconv_num2(ctx, base, o.s, 0x8207C0C8u, 0x8207C0D4u, 0x8207C148u, 0x8207C154u);
  cc_asconv_put_num(base, o.s, n.a, n.b, float(n.fb - n.fa));
  return 0u;
}

// Multiply (exact sub_8207C1F8, op 0x0C): b * a into b.
static uint32_t cc_as_op_0C(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_0C);
  const CcAsConvNum2 n = cc_asconv_num2(ctx, base, o.s, 0x8207C278u, 0x8207C284u, 0x8207C2F8u, 0x8207C304u);
  cc_asconv_put_num(base, o.s, n.a, n.b, float(n.fb * n.fa));
  return 0u;
}

// Divide (exact sub_8207C3A8, op 0x0D): a equal to the zero constant ->
// b = {undefined, 0}, else b = {16, b / a}; b referenced and pushed, a's
// slot freed.
static uint32_t cc_as_op_0D(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_0D);
  const CcAsConvNum2 n = cc_asconv_num2(ctx, base, o.s, 0x8207C42Cu, 0x8207C438u, 0x8207C4ACu, 0x8207C4B8u);
  if (n.fa == n.z) {
    REX_STORE_U32(n.b + 0u, kAsUndef);
    REX_STORE_U32(n.b + 4u, 0u);
  } else {
    PPCRegister x{};
    x.f32 = float(n.fb / n.fa);
    REX_STORE_U32(n.b + 4u, x.u32);
    REX_STORE_U32(n.b + 0u, 16u);
  }
  const uint32_t p = cc_as_pool(base, o.s);
  cc_as_ref(ctx, base, n.b, 0x8207C570u);
  cc_as_push(base, p, n.b);
  cc_as_free(base, n.a);
  return 0u;
}

// And (exact sub_8207C5A8, op 0x10): false when either ToNumber equals the
// zero constant.
static uint32_t cc_as_op_10(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_10);
  const CcAsConvNum2 n = cc_asconv_num2(ctx, base, o.s, 0x8207C62Cu, 0x8207C638u, 0x8207C6ACu, 0x8207C6B8u);
  cc_asconv_put_bool(base, o.s, n.a, n.b, (n.fa == n.z || n.fb == n.z) ? 0u : 1u);
  return 0u;
}

// Or (exact sub_8207C778, op 0x11): false when both ToNumbers equal the
// zero constant.
static uint32_t cc_as_op_11(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_11);
  const CcAsConvNum2 n = cc_asconv_num2(ctx, base, o.s, 0x8207C7FCu, 0x8207C808u, 0x8207C87Cu, 0x8207C888u);
  cc_asconv_put_bool(base, o.s, n.a, n.b, (n.fa == n.z && n.fb == n.z) ? 0u : 1u);
  return 0u;
}

// Not (exact sub_8207C948, op 0x12): pop, release; the slot becomes {2,
// ToBoolean == 0} (undefined: true) and is pushed again.
static uint32_t cc_as_op_12(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_12);
  const uint32_t v = cc_as_pop_release(ctx, base, o.s, 0x8207C9C0u, 0x8207C9CCu);
  uint32_t r = 1u;
  if (REX_LOAD_U32(v) != kAsUndef) r = (cc_as_tobool(ctx, base, v) & 0xFFu) == 0u ? 1u : 0u;
  REX_STORE_U8(v + 4u, uint8_t(r));
  REX_STORE_U32(v + 0u, 2u);
  cc_as_push(base, cc_as_pool(base, o.s), v);
  return 0u;
}

// ToInteger (exact sub_8207F260, ops 0x18 and 0x4A): pop, release; the
// slot becomes {4, ToInt} (undefined: 0) and is pushed again.
static uint32_t cc_as_op_18(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_18);
  const uint32_t v = cc_as_pop_release(ctx, base, o.s, 0x8207F2D8u, 0x8207F2E4u);
  uint32_t r = 0u;
  if (REX_LOAD_U32(v) != kAsUndef) r = cc_as_toint(ctx, base, v);
  REX_STORE_U32(v + 4u, r);
  REX_STORE_U32(v + 0u, 4u);
  cc_as_push(base, cc_as_pool(base, o.s), v);
  return 0u;
}

// Add (exact sub_8207ECC0, op 0x47): pops a (top) and b, both released.
// a undefined: b is the result (b undefined too: b = {4, 0}), a's slot
// freed. b undefined: a is the result, b's slot freed. Otherwise a new pool
// slot (sub_82082488) takes sub_82082F18(new, VM, a, b) and both slots are
// freed. The result is referenced and pushed.
static uint32_t cc_as_op_47(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_47);
  const uint32_t a = cc_as_pop_release(ctx, base, o.s, 0x8207ED38u, 0x8207ED44u);
  const uint32_t b = cc_as_pop_release(ctx, base, o.s, 0x8207EDB8u, 0x8207EDC4u);
  const uint32_t ta = REX_LOAD_U32(a), tb = REX_LOAD_U32(b);
  uint32_t res;
  if (ta == kAsUndef) {
    res = b;
    if (tb == kAsUndef) {
      REX_STORE_U32(b + 4u, 0u);
      REX_STORE_U32(b + 0u, 4u);
    }
    cc_as_free(base, a);
  } else if (tb == kAsUndef) {
    res = a;
    REX_STORE_U32(b + 4u, 0u);
    REX_STORE_U8(b + 8u, 0u);
  } else {
    ctx.r3.u64 = cc_as_pool(base, o.s); ctx.lr = 0x8207EE34u;
    sub_82082488(ctx, base);
    res = ctx.r3.u32;
    ctx.r4.u64 = cc_as_vm(base, o.s); ctx.r5.u64 = a; ctx.r6.u64 = b; ctx.lr = 0x8207EE50u;
    sub_82082F18(ctx, base);
    cc_as_free(base, a);
    REX_STORE_U32(b + 4u, 0u);
    REX_STORE_U8(b + 8u, 0u);
  }
  const uint32_t p = cc_as_pool(base, o.s);
  cc_as_ref(ctx, base, res, 0x8207EEA4u);
  cc_as_push(base, p, res);
  return 0u;
}

// Less (exact sub_8207EEC8, op 0x48): b < a (ToNumber) into b.
static uint32_t cc_as_op_48(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_48);
  const CcAsConvNum2 n = cc_asconv_num2(ctx, base, o.s, 0x8207EF48u, 0x8207EF54u, 0x8207EFC8u, 0x8207EFD4u);
  cc_asconv_put_bool(base, o.s, n.a, n.b, n.fb < n.fa ? 1u : 0u);
  return 0u;
}

// Equals (exact sub_8207F088, op 0x49): pops a and b (released). a
// undefined: b undefined; b undefined: false; same type, or neither type
// reference-counted: the low byte of sub_82082CD0(b, a); else false. Into
// b as {2, byte}, pushed; a's slot freed.
static uint32_t cc_as_op_49(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_49);
  const uint32_t a = cc_as_pop_release(ctx, base, o.s, 0x8207F100u, 0x8207F10Cu);
  const uint32_t b = cc_as_pop_release(ctx, base, o.s, 0x8207F180u, 0x8207F18Cu);
  const uint32_t ta = REX_LOAD_U32(a);
  uint32_t r = 0u;
  if (ta == kAsUndef) {
    r = REX_LOAD_U32(b) == kAsUndef ? 1u : 0u;
  } else {
    const uint32_t tb = REX_LOAD_U32(b);
    if (tb != kAsUndef && (ta == tb || ((ta & kAsRef) == 0u && (tb & kAsRef) == 0u))) {
      ctx.r3.u64 = b; ctx.r4.u64 = a; ctx.lr = 0x8207F200u;
      sub_82082CD0(ctx, base);
      r = ctx.r3.u32;
    }
  }
  cc_asconv_put_bool(base, o.s, a, b, r);
  return 0u;
}

// ToString (exact sub_8207F350, op 0x4B; frame 128): pop, release; the slot
// becomes {8, ToString id} and is pushed again. For undefined the original
// takes the u16 at its frame +80 (never written there), read the same way.
static uint32_t cc_as_op_4B(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_4B);
  CcFrame frame(ctx, base, 128u);
  const uint32_t v = cc_as_pop_release(ctx, base, o.s, 0x8207F3C8u, 0x8207F3D4u);
  uint32_t id;
  if (REX_LOAD_U32(v) != kAsUndef) id = cc_as_tostr_id(ctx, base, v);
  else id = REX_LOAD_U16(ctx.r1.u32 + 80u);
  REX_STORE_U16(v + 4u, uint16_t(id));
  REX_STORE_U32(v + 0u, 8u);
  cc_as_push(base, cc_as_pool(base, o.s), v);
  return 0u;
}

// PushDuplicate (exact sub_8207F440, op 0x4C): the top slot pointer is
// referenced and pushed again (the same slot twice on the stack).
static uint32_t cc_as_op_4C(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_4C);
  const uint32_t p = cc_as_pool(base, o.s);
  const uint32_t v = REX_LOAD_U32(p + REX_LOAD_U32(p + 5024u) * 4u - 4u);
  cc_as_ref(ctx, base, v, 0x8207F4A4u);
  cc_as_push(base, p, v);
  return 0u;
}

// Increment (exact sub_8207FB40, op 0x50): pop, release; undefined ->
// {4, 1}; int -> {4, ToInt + 1}; number -> {16, ToNumber + the one
// constant}; other types unchanged. Referenced and pushed again.
static uint32_t cc_as_op_50(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_50);
  const uint32_t v = cc_as_pop_release(ctx, base, o.s, 0x8207FBB8u, 0x8207FBC4u);
  const uint32_t t = REX_LOAD_U32(v);
  if (t == kAsUndef) {
    REX_STORE_U32(v + 0u, 4u);
    REX_STORE_U32(v + 4u, 1u);
  } else if (t == 4u) {
    const uint32_t n = cc_as_toint(ctx, base, v);
    REX_STORE_U32(v + 4u, n + 1u);
    REX_STORE_U32(v + 0u, 4u);
  } else if (t == 16u) {
    const double x = cc_as_tonum(ctx, base, v);
    REX_STORE_U32(v + 0u, 16u);
    ctx.fpscr.disableFlushMode();
    PPCRegister r{};
    r.f32 = float(x + cc_asconv_k(base, 9540u));
    REX_STORE_U32(v + 4u, r.u32);
  }
  const uint32_t p = cc_as_pool(base, o.s);
  cc_as_ref(ctx, base, v, 0x8207FC80u);
  cc_as_push(base, p, v);
  return 0u;
}

// Decrement (exact sub_8207FCA8, op 0x51): as Increment with -1:
// undefined -> {4, -1}; int -> {4, ToInt - 1}; number -> {16, ToNumber -
// the one constant}.
static uint32_t cc_as_op_51(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_51);
  const uint32_t v = cc_as_pop_release(ctx, base, o.s, 0x8207FD20u, 0x8207FD2Cu);
  const uint32_t t = REX_LOAD_U32(v);
  if (t == kAsUndef) {
    REX_STORE_U32(v + 0u, 4u);
    REX_STORE_U32(v + 4u, 0xFFFFFFFFu);
  } else if (t == 4u) {
    const uint32_t n = cc_as_toint(ctx, base, v);
    REX_STORE_U32(v + 4u, n - 1u);
    REX_STORE_U32(v + 0u, 4u);
  } else if (t == 16u) {
    const double x = cc_as_tonum(ctx, base, v);
    REX_STORE_U32(v + 0u, 16u);
    ctx.fpscr.disableFlushMode();
    PPCRegister r{};
    r.f32 = float(x - cc_asconv_k(base, 9540u));
    REX_STORE_U32(v + 4u, r.u32);
  }
  const uint32_t p = cc_as_pool(base, o.s);
  cc_as_ref(ctx, base, v, 0x8207FDE8u);
  cc_as_push(base, p, v);
  return 0u;
}

// StrictEquals (exact sub_82080E08, op 0x66): pops a and b (released);
// both defined and of the same type: the low byte of sub_82082CD0(a, b),
// else false (undefined too). Into b as {2, byte}, pushed; a's slot freed.
static uint32_t cc_as_op_66(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_66);
  const uint32_t a = cc_as_pop_release(ctx, base, o.s, 0x82080E80u, 0x82080E8Cu);
  const uint32_t b = cc_as_pop_release(ctx, base, o.s, 0x82080F00u, 0x82080F0Cu);
  const uint32_t ta = REX_LOAD_U32(a);
  uint32_t r = 0u;
  if (ta != kAsUndef) {
    const uint32_t tb = REX_LOAD_U32(b);
    if (tb != kAsUndef && ta == tb) {
      ctx.r3.u64 = a; ctx.r4.u64 = b; ctx.lr = 0x82080F4Cu;
      sub_82082CD0(ctx, base);
      r = ctx.r3.u32;
    }
  }
  cc_asconv_put_bool(base, o.s, a, b, r);
  return 0u;
}

// Greater (exact sub_82080FA0, op 0x67): b > a (ToNumber) into b.
static uint32_t cc_as_op_67(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_67);
  const CcAsConvNum2 n = cc_asconv_num2(ctx, base, o.s, 0x82081020u, 0x8208102Cu, 0x820810A0u, 0x820810ACu);
  cc_asconv_put_bool(base, o.s, n.a, n.b, n.fb > n.fa ? 1u : 0u);
  return 0u;
}

// ToBoolean (exact sub_82081160, op 0x70): pop, release; the slot becomes
// {2, ToBoolean} (undefined: false) and is pushed again. Returns 1.
static uint32_t cc_as_op_70(Context& ctx, Machine& base, const CcAsOp& o) {
  CC_FPROF_SCOPE(cc_as_op_70);
  const uint32_t v = cc_as_pop_release(ctx, base, o.s, 0x820811D8u, 0x820811E4u);
  uint32_t r = 0u;
  if (REX_LOAD_U32(v) != kAsUndef) r = cc_as_tobool(ctx, base, v);
  REX_STORE_U8(v + 4u, uint8_t(r));
  REX_STORE_U32(v + 0u, 2u);
  cc_as_push(base, cc_as_pool(base, o.s), v);
  return 1u;
}
