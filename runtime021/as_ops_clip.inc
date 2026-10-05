// MovieClip member and property access, timeline tag reading and the
// signed bit-field reader (included by as_ops_more.inc). Helper
// replacements only; the recompiled bodies stay as sub_X_exact.

// Clip property ids the native getter sub_82089C00 answers (78..82,
// 84..88, 91, 98, 102: it returns 1 for them); for any other id it returns
// 0 having written nothing but its stack frame. The setter sub_82089F70
// acts on 78..81, 84, 85, 87, 88, 91 and 97; any other id returns 0 the
// same way.
static CC_AS_INL bool cc_clip_get_prop(uint32_t k) {
  const uint32_t d = k - 78u;
  return d < 25u && ((0x11027DFu >> d) & 1u) != 0u;
}
static CC_AS_INL bool cc_clip_set_prop(uint32_t k) {
  const uint32_t d = k - 78u;
  return d < 20u && ((0x826CFu >> d) & 1u) != 0u;
}

// Clip GetMember (exact sub_8208B438: clip r3, id r4, out value r5).
// The clip's slot 112 (property getter, r4 id u16, r5 out) answers
// first; then the member read sub_8208C140(clip, id, out); then a child
// of that name in the display list at clip+104 (sub_82085078) as a typed
// reference (sub_8206F918(out, child)); then the map at clip+204, whose
// object gives out = {type (slot 40), object}. Found: 1; otherwise out =
// undefined and 0. When slot 112 is the native getter sub_82089C00, a
// property id calls it directly and any other id skips it (it would
// answer 0 and write nothing). GetVariable and GetMember (0x4E, 0xA2) call
// this directly for objects whose slot 12 is sub_8208B438.
static CC_HOT_FN uint32_t cc_clip_get_member(Context& ctx, Machine& base, uint32_t clip, uint64_t id, uint64_t out) {
  CcFrame frame(ctx, base, 112u);
  const uint32_t k = uint32_t(id) & 0xFFFFu;
  if (REX_LOAD_U32(REX_LOAD_U32(clip) + 112u) == 0x82089C00u) {
    if (cc_clip_get_prop(k)) {
      ctx.r3.u64 = clip; ctx.r4.u64 = k; ctx.r5.u64 = out; ctx.lr = 0x8208B464u;
      sub_82089C00(ctx, base);
      return 1u;
    }
  } else {
    ctx.r4.u64 = k;
    ctx.r5.u64 = out;
    if ((cc_vcall(ctx, base, clip, 112u, 0x8208B464u) & 0xFFu) != 0u) return 1u;
  }
  ctx.r3.u64 = clip; ctx.r4.u64 = id; ctx.r5.u64 = out; ctx.lr = 0x8208B480u;
  sub_8208C140(ctx, base);
  if ((ctx.r3.u32 & 0xFFu) != 0u) return 1u;
  ctx.r3.u64 = clip + 104u; ctx.r4.u64 = id; ctx.lr = 0x8208B498u;
  sub_82085078(ctx, base);
  const uint32_t child = ctx.r3.u32;
  if (child != 0u) {
    ctx.r3.u64 = out; ctx.r4.u64 = child; ctx.lr = 0x8208B4ACu;
    sub_8206F918(ctx, base);
    return 1u;
  }
  const uint32_t o = uint32_t(out);
  const uint32_t obj = cc_asmap_find(base, clip + 204u, uint32_t(id) & 0xFFFFu);
  if (obj != 0u) {
    const uint32_t t = cc_vcall(ctx, base, obj, 40u, 0x8208B4E0u);
    REX_STORE_U32(o + 0u, t);
    REX_STORE_U32(o + 4u, obj);
    return 1u;
  }
  REX_STORE_U32(o + 0u, kAsUndef);
  REX_STORE_U32(o + 4u, 0u);
  return 0u;
}
static CC_HOT_FN void sub_8208B438(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8208B438);
  CC_FPROF_SCOPE(sub_8208B438_native);
  ctx.r3.u64 = cc_clip_get_member(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64);
}

// Number result of a clip property method (f1) as the getter stores it:
// payload float(f1), then type 16.
static CC_HOT_FN inline void cc_clip_put_num(Context& ctx, Machine& base, uint32_t out) {
  ctx.fpscr.disableFlushMode();
  PPCRegister temp{};
  temp.f32 = float(ctx.f1.f64);
  REX_STORE_U32(out + 4u, temp.u32);
  REX_STORE_U32(out + 0u, 16u);
}

// Clip property get by id (exact sub_82089C00: clip r3, id r4, out value
// r5; returns 1 when the id is a property, else 0 with out untouched).
// Ids 78..81 slots 188/192/196/200, 86/87 slots 228/232, 88
// sub_82085FA8(clip+36): numbers (f1). 82: slot 160 -> int (low 16 bits).
// 84: int s16 at [clip+76]+40, or 255 without that object. 85: bool, bit 0
// of byte clip+140 (byte store). 91: string id u16 clip+100 (halfword
// store). 98: the clip, 102: [clip+96], both as typed references
// (sub_8206F918).
static CC_HOT_FN void sub_82089C00(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_82089C00);
  CC_FPROF_SCOPE(sub_82089C00_native);
  const uint32_t clip = ctx.r3.u32, out = ctx.r5.u32;
  const uint64_t out64 = ctx.r5.u64;
  CcFrame frame(ctx, base, 96u);
  switch (ctx.r4.u32 - 78u) {
    case 0u: cc_vcall(ctx, base, clip, 188u, 0x82089CB4u); cc_clip_put_num(ctx, base, out); break;
    case 1u: cc_vcall(ctx, base, clip, 192u, 0x82089CECu); cc_clip_put_num(ctx, base, out); break;
    case 2u: cc_vcall(ctx, base, clip, 196u, 0x82089D24u); cc_clip_put_num(ctx, base, out); break;
    case 3u: cc_vcall(ctx, base, clip, 200u, 0x82089D5Cu); cc_clip_put_num(ctx, base, out); break;
    case 4u: {
      const uint32_t v = cc_vcall(ctx, base, clip, 160u, 0x82089D94u) & 0xFFFFu;
      REX_STORE_U32(out + 4u, v);
      REX_STORE_U32(out + 0u, 4u);
      break;
    }
    case 6u: {
      const uint32_t c = REX_LOAD_U32(clip + 76u);
      REX_STORE_U32(out + 0u, 4u);
      REX_STORE_U32(out + 4u, c != 0u ? uint32_t(int32_t(int16_t(REX_LOAD_U16(c + 40u)))) : 255u);
      break;
    }
    case 7u:
      REX_STORE_U32(out + 0u, 2u);
      REX_STORE_U8(out + 4u, REX_LOAD_U8(clip + 140u) & 1u);
      break;
    case 8u: cc_vcall(ctx, base, clip, 228u, 0x82089E5Cu); cc_clip_put_num(ctx, base, out); break;
    case 9u: cc_vcall(ctx, base, clip, 232u, 0x82089E94u); cc_clip_put_num(ctx, base, out); break;
    case 10u:
      ctx.r3.u64 = clip + 36u; ctx.lr = 0x82089EC0u;
      sub_82085FA8(ctx, base);
      cc_clip_put_num(ctx, base, out);
      break;
    case 13u:
      REX_STORE_U32(out + 0u, 8u);
      REX_STORE_U16(out + 4u, REX_LOAD_U16(clip + 100u));
      break;
    case 20u:
      ctx.r4.u64 = clip; ctx.r3.u64 = out64; ctx.lr = 0x82089F3Cu;
      sub_8206F918(ctx, base);
      break;
    case 24u:
      ctx.r3.u64 = out64; ctx.r4.u64 = REX_LOAD_U32(clip + 96u); ctx.lr = 0x82089F18u;
      sub_8206F918(ctx, base);
      break;
    default:
      ctx.r3.u64 = 0u;
      return;
  }
  ctx.r3.u64 = 1u;
}

// Clip SetMember (exact sub_8208B520: clip r3, id r4, value r5). The
// clip's slot 116 (property setter, r4 id u16, r5 value) first; when it
// returns 0 in its low byte, sub_8208C2A0(clip, id, value) sets the
// member. r3 is the last call's result. When slot 116 is the native
// setter sub_82089F70, non-property ids skip it.
static CC_HOT_FN void sub_8208B520(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8208B520);
  CC_FPROF_SCOPE(sub_8208B520_native);
  const uint32_t clip = ctx.r3.u32;
  const uint64_t id = ctx.r4.u64, val = ctx.r5.u64;
  CcFrame frame(ctx, base, 112u);
  // the native setter sub_82089F70 answers 0 untouched for non-property ids
  if (REX_LOAD_U32(REX_LOAD_U32(clip) + 116u) != 0x82089F70u || cc_clip_set_prop(uint32_t(id) & 0xFFFFu)) {
    ctx.r4.u64 = id & 0xFFFFu;
    ctx.r5.u64 = val;
    if ((cc_vcall(ctx, base, clip, 116u, 0x8208B54Cu) & 0xFFu) != 0u) return;
  }
  ctx.r3.u64 = clip; ctx.r4.u64 = id; ctx.r5.u64 = val; ctx.lr = 0x8208B568u;
  sub_8208C2A0(ctx, base);
}

// Clip property set by id (exact sub_82089F70: clip r3, id r4, value r5;
// returns 1 when the id is a settable property, 0 for others and for a
// null or undefined value). Ids 78..81 and 88: ToNumber (sub_82082700)
// passed in f1 to slots 208/212/216/220/224 (the vtable pointer read
// before the conversion, the method after, as the original). 84: ToInt
// (sub_82082BB0) as s16 times the float at 0x82042600, truncated, stored
// u16 at +40 of the object at clip+76 (created first by
// sub_8208F9E8([0x8225E608], 0) and referenced with sub_82066EA8(obj, 1)
// when missing), then sub_820837C0([obj+44], obj) if [obj+44] is set. 85:
// ToBoolean to slot 236 (r4). 87: ToNumber / slot 232's f1, times the
// float at 0x82014740, to slot 220. 91: ToString id (sub_82082890) stored
// u16 at clip+100. 97: nothing, returns 1.
static CC_HOT_FN void sub_82089F70(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_82089F70);
  CC_FPROF_SCOPE(sub_82089F70_native);
  const uint32_t clip = ctx.r3.u32, val = ctx.r5.u32;
  const uint32_t k = ctx.r4.u32 - 78u;
  CcFrame frame(ctx, base, 128u);
  if (val == 0u || REX_LOAD_U32(val) == kAsUndef) { ctx.r3.u64 = 0u; return; }
  switch (k) {
    case 0u: {
      const uint32_t vt = REX_LOAD_U32(clip);
      ctx.r3.u64 = val; ctx.lr = 0x8208A020u;
      sub_82082700(ctx, base);
      ctx.r3.u64 = clip; ctx.lr = 0x8208A030u;
      REX_CALL_INDIRECT_FUNC(REX_LOAD_U32(vt + 208u));
      break;
    }
    case 1u: {
      const uint32_t vt = REX_LOAD_U32(clip);
      ctx.r3.u64 = val; ctx.lr = 0x8208A04Cu;
      sub_82082700(ctx, base);
      ctx.r3.u64 = clip; ctx.lr = 0x8208A05Cu;
      REX_CALL_INDIRECT_FUNC(REX_LOAD_U32(vt + 212u));
      break;
    }
    case 2u: {
      const uint32_t vt = REX_LOAD_U32(clip);
      ctx.r3.u64 = val; ctx.lr = 0x8208A078u;
      sub_82082700(ctx, base);
      ctx.r3.u64 = clip; ctx.lr = 0x8208A088u;
      REX_CALL_INDIRECT_FUNC(REX_LOAD_U32(vt + 216u));
      break;
    }
    case 3u: {
      const uint32_t vt = REX_LOAD_U32(clip);
      ctx.r3.u64 = val; ctx.lr = 0x8208A0A4u;
      sub_82082700(ctx, base);
      ctx.r3.u64 = clip; ctx.lr = 0x8208A0B4u;
      REX_CALL_INDIRECT_FUNC(REX_LOAD_U32(vt + 220u));
      break;
    }
    case 6u: {
      ctx.r3.u64 = val; ctx.lr = 0x8208A0CCu;
      sub_82082BB0(ctx, base);
      const int64_t a = ctx.r3.s16;
      if (REX_LOAD_U32(clip + 76u) == 0u) {
        ctx.r3.u64 = REX_LOAD_U32(0x8225E608u); ctx.r4.u64 = 0u; ctx.lr = 0x8208A0ECu;
        sub_8208F9E8(ctx, base);
        REX_STORE_U32(clip + 76u, ctx.r3.u32);
        ctx.r4.u64 = 1u; ctx.lr = 0x8208A0F8u;
        sub_82066EA8(ctx, base);
      }
      const uint32_t obj = REX_LOAD_U32(clip + 76u);
      ctx.fpscr.disableFlushMode();
      const double f12 = double(float(double(a)));
      PPCRegister c{};
      c.u32 = REX_LOAD_U32(0x82040000u + 9728u);
      const uint32_t sub = REX_LOAD_U32(obj + 44u);
      double f11 = double(float(f12 * double(c.f32)));
      const int64_t f10 = std::isnan(f11) ? int64_t(0x80000000U) : (f11 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f11));
      REX_STORE_U16(obj + 40u, uint16_t(uint64_t(f10)));
      if (sub != 0u) {
        ctx.r3.u64 = sub; ctx.r4.u64 = obj; ctx.lr = 0x8208A13Cu;
        sub_820837C0(ctx, base);
      }
      break;
    }
    case 7u:
      ctx.r4.u64 = cc_as_tobool(ctx, base, val);
      cc_vcall(ctx, base, clip, 236u, 0x8208A16Cu);
      break;
    case 9u: {
      cc_vcall(ctx, base, clip, 232u, 0x8208A190u);
      ctx.fpscr.disableFlushMode();
      const double cur = ctx.f1.f64;
      ctx.r3.u64 = val; ctx.lr = 0x8208A19Cu;
      sub_82082700(ctx, base);
      ctx.fpscr.disableFlushMode();
      ctx.f13.f64 = double(float(ctx.f1.f64 / cur));
      PPCRegister c{};
      c.u32 = REX_LOAD_U32(0x82010000u + 18236u);
      ctx.f0.f64 = double(c.f32);
      ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
      cc_vcall(ctx, base, clip, 220u, 0x8208A1C0u);
      break;
    }
    case 10u: {
      const uint32_t vt = REX_LOAD_U32(clip);
      ctx.r3.u64 = val; ctx.lr = 0x8208A1DCu;
      sub_82082700(ctx, base);
      ctx.r3.u64 = clip; ctx.lr = 0x8208A1ECu;
      REX_CALL_INDIRECT_FUNC(REX_LOAD_U32(vt + 224u));
      break;
    }
    case 13u:
      ctx.r3.u64 = val; ctx.lr = 0x8208A204u;
      sub_82082890(ctx, base);
      REX_STORE_U16(clip + 100u, ctx.r3.u16);
      break;
    case 19u:
      break;
    default:
      ctx.r3.u64 = 0u;
      return;
  }
  ctx.r3.u64 = 1u;
}

// Timeline tag step (exact sub_8208AB98: clip r3, mode r4 u16, no-call
// flag r5 byte). Stream at clip+92 (none: 0), position clip+128. The tag
// header is a little-endian u16 {code << 6 | length}; length 63 means a
// little-endian u32 length follows (the sub_8208BE40 read). In mode 0 a
// definition tag (10, 11, 13, 33, 37, 39, 48, 62, 142, 148) gets its
// header rewritten to code 255 with the same length (it is still handled
// this time). Position passes the header (code 0 or 128: returns 0), the
// length goes to clip+132, position passes the data. Code 255: -1. Unless
// the flag is set, sub_82086010(display list [clip+156], kind, data, f)
// handles it: mode 0 always, mode 2 except codes 5/26/28 (kind = code,
// 148 -> 65, 142 -> 66; f = 0), mode 1 only codes 5/26/28 (kind = code, f
// = current frame u16 clip+144). Returns 1 for ShowFrame (code 1), 66 for
// code 142, else -1.
static CC_HOT_FN int32_t cc_clip_tag_step(Context& ctx, Machine& base, uint32_t clip, uint32_t mode, uint32_t flag) {
  const uint32_t stream = REX_LOAD_U32(clip + 92u);
  if (stream == 0u) return 0;
  const uint32_t hdr = stream + REX_LOAD_U32(clip + 128u);
  const uint32_t le = REX_LOAD_U8(hdr + 0u) | (REX_LOAD_U8(hdr + 1u) << 8);
  const uint32_t code = (le >> 6) & 0x3FFu;
  const uint32_t len = le & 0x3Fu;
  if (mode == 0u) {
    switch (code) {
      case 10u: case 11u: case 13u: case 33u: case 37u: case 39u: case 48u: case 62u: case 142u: case 148u:
        REX_STORE_U8(hdr + 1u, 0x3Fu);
        REX_STORE_U8(hdr + 0u, 0xC0u | len);
        break;
      default: break;
    }
  }
  const uint32_t pos = REX_LOAD_U32(clip + 128u) + 2u;
  REX_STORE_U32(clip + 128u, pos);
  if (code == 0u || code == 128u) return 0;
  if (len == 63u) {
    const uint32_t p = pos + REX_LOAD_U32(clip + 92u);
    const uint32_t n = REX_LOAD_U8(p + 0u) | (REX_LOAD_U8(p + 1u) << 8) | (REX_LOAD_U8(p + 2u) << 16) |
                       (REX_LOAD_U8(p + 3u) << 24);
    const uint32_t q = REX_LOAD_U32(clip + 128u);
    REX_STORE_U32(clip + 132u, n);
    REX_STORE_U32(clip + 128u, q + 4u);
  } else {
    REX_STORE_U32(clip + 132u, len);
  }
  const uint32_t data = REX_LOAD_U32(clip + 128u);
  REX_STORE_U32(clip + 128u, data + REX_LOAD_U32(clip + 132u));
  uint32_t kind = code;
  if (code == 148u) kind = 65u;
  else if (code == 142u) kind = 66u;
  else if (code == 255u) return -1;
  if ((flag & 0xFFu) == 0u) {
    const bool place = code == 5u || code == 26u || code == 28u;
    bool call = false;
    uint32_t r4 = 0u, r6 = 0u;
    if (mode == 0u || (mode == 2u && !place)) {
      call = true; r4 = kind & 0xFFFFu; r6 = 0u;
    } else if (mode == 1u && place) {
      call = true; r4 = code; r6 = REX_LOAD_U16(clip + 144u);
    }
    if (call) {
      CcFrame frame(ctx, base, 176u);
      ctx.r3.u64 = REX_LOAD_U32(clip + 156u);
      ctx.r4.u64 = r4;
      ctx.r5.u64 = data + REX_LOAD_U32(clip + 92u);
      ctx.r6.u64 = r6;
      ctx.lr = 0x8208ADACu;
      sub_82086010(ctx, base);
    }
  }
  if (code == 1u) return 1;
  if ((kind & 0xFFFFu) == 66u) return 66;
  return -1;
}
static CC_HOT_FN void sub_8208AB98(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8208AB98);
  CC_FPROF_SCOPE(sub_8208AB98_native);
  const int32_t r = cc_clip_tag_step(ctx, base, ctx.r3.u32, ctx.r4.u32 & 0xFFFFu, ctx.r5.u32 & 0xFFu);
  ctx.r3.s64 = r;
}

// Run one frame's tags (exact sub_8208ADE8: clip r3, mode r4). Position
// clip+128 = the map clip+108 entry for the current frame u16 clip+144;
// then tag steps sub_8208AB98(clip, mode, 0) until ShowFrame (1, or 255)
// -> 0, or a 0 result (no stream / end tag) -> -1.
static CC_HOT_FN void sub_8208ADE8(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8208ADE8);
  CC_FPROF_SCOPE(sub_8208ADE8_native);
  const uint32_t clip = ctx.r3.u32;
  const uint64_t mode = ctx.r4.u64;
  CcFrame frame(ctx, base, 112u);
  REX_STORE_U32(clip + 128u, cc_asmap_find(base, clip + 108u, REX_LOAD_U16(clip + 144u)));
  ctx.r3.u64 = clip; ctx.r4.u64 = mode; ctx.r5.u64 = 0u; ctx.lr = 0x8208AE24u;
  sub_8208AB98(ctx, base);
  int32_t r = ctx.r3.s32;
  while (r != 0) {
    if (r == 1 || r == 255) { ctx.r3.s64 = 0; return; }
    ctx.r3.u64 = clip; ctx.r4.u64 = mode; ctx.r5.u64 = 0u; ctx.lr = 0x8208AE4Cu;
    sub_8208AB98(ctx, base);
    r = ctx.r3.s32;
  }
  ctx.r3.s64 = -1;
}

// Signed bit-field read (exact sub_82095788: bytes r3, byte position* r4,
// bits left in the current byte* r5, width r6). r6 bits, most significant
// first, through the mask table at 0x820146B0: byte bit tested with entry
// (bits left - 1), result bit ORed from entries r6-1 down to 0; bits left
// reaching 0 restarts at 8 with the next byte. When the result and entry
// r6-1 share a bit, -entry r6 (64-bit, as the original's neg) is ORed in.
// Bits left and position written back; r3 = the result.
static CC_HOT_FN void sub_82095788(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_82095788);
  CC_FPROF_SCOPE(sub_82095788_native);
  constexpr uint32_t tbl = 0x82010000u + 18096u;
  const uint32_t buf = ctx.r3.u32, posp = ctx.r4.u32, bitp = ctx.r5.u32, n = ctx.r6.u32;
  uint32_t bits = REX_LOAD_U32(bitp);
  uint32_t pos = REX_LOAD_U32(posp);
  uint64_t v = 0u;
  if (int32_t(n) > 0) {
    uint32_t m = tbl + n * 4u - 4u;
    for (uint32_t i = n; i != 0u; --i, m -= 4u) {
      const uint32_t byte = REX_LOAD_U8(pos + buf);
      const uint32_t bit = REX_LOAD_U32(tbl + bits * 4u - 4u) & byte;
      bits -= 1u;
      if (int32_t(bits) < 1) { bits = 8u; pos += 1u; }
      if ((bit & 0xFFu) != 0u) v |= REX_LOAD_U32(m);
    }
  }
  const uint32_t top = tbl + n * 4u;
  if ((REX_LOAD_U32(top - 4u) & uint32_t(v)) != 0u) v |= uint64_t(0) - uint64_t(REX_LOAD_U32(top));
  REX_STORE_U32(bitp, bits);
  ctx.r3.u64 = v;
  REX_STORE_U32(posp, pos);
}
