// Timeline seek (included by bodies.inc after the recompiled body, which
// stays as sub_82087F70_exact).
//
// Exact sub_82087F70: clip r3, frame r4 (u16; gotoAndStop, gotoAndPlay,
// nextFrame and prevFrame end here). Clip fields: +92 the definition's tag
// stream, +104 the child list (linked by +88; a child's depth at +28, the
// frame it was placed in u16 +84, a frame stamp u16 +82, flags +86), +108
// the frame map {n, entries} (frame -> offset of its first tag, looked up
// by sub_82082390), +140 flags, u16 +142 / +144 / +146 the previous,
// pending and current frame, +156 the movie. Tag headers are SWF's
// little-endian u16 (code << 6 | length, length 63: a u32 length follows).
//
// Unless the frame is the current one (slot 160), the seek pushes the clip
// on the movie's update stack (+8248, entries +(n+1998)*4), moves +146 to
// +142 and +144 (or 1) to +146, sets bit 6 of +140, records {clip, slot
// 140, frame} in the player's 255-entry ring (+4924, index +7988, read
// index +7984; sub_820935B0 drains it when full), then builds a list of
// 16-byte entries {type, tag offset, u16 state, u16 frame, depth} at
// 0x8225E6B8:
// - forward (frame > +142): one entry per child (type 0, stamp +82 set to
//   +146), then the tags of frames +142+1 .. frame: PlaceObject2 (26) adds
//   an entry (state 1); RemoveObject (5) / RemoveObject2 (28) removes the
//   child at that depth (sub_82084C78) and marks the entries of that depth
//   state 2; ShowFrame (1) moves to the next frame's offset.
// - backward: children placed after the frame are removed, the others get
//   an entry (frame +84); then the tags of frames 1 .. frame. A
//   PlaceObject2 whose depth one of those entries has updates the child
//   (when the tag's frame is not before the entry's): matrix (sub_82085890
//   into a frame-local record, copied to +36..+72 unless +86 bit 5 is set),
//   colour transform (sub_82083F50 into a frame-local object, sub_820837C0
//   applies it; without one, sub_820838A8 resets it when the tag is the
//   entry's own frame), name (sub_8209D948, slot 76). Its byte cursor
//   carries over between entries of the same depth, as compiled. Other
//   PlaceObject2 tags add an entry; RemoveObject(2) of a depth no entry has
//   removes and marks as above.
// Then every new entry not marked 2 runs its tag handler (table 0x8215A400
// by type; PlaceObject2 is sub_820922B8) with +146 = the entry's frame,
// +146 = frame, children with a zero stamp get +146, and the update-stack
// entry is popped.
//
// The native does the same guest reads and writes in the same order, calls
// the same functions with the same arguments and return addresses from a
// frame of the same size, and writes the frame words the original leaves
// (saved f30/f31, the frame argument at +414, the list pointer +100, the
// entry count +104, the swapped long length +96, the matrix and colour
// records). Tag bytes are read through host pointers, and the entry list
// is scanned in place. Callee-saved registers are not touched (the play
// build's register view keeps them per function, so callees see the
// caller's values either way).
// Switches: CC_SEEK_EXACT=1 (host) / make SEEKEXACT=1 (Xbox,
// CC_SEEK_EXACT_BUILD) run the recompiled body (and the recompiled
// CharToFunc for the timeline builtins, as_ops_call.inc). Host checks:
// CC_ORACLE=1 or CC_SEEK_ORACLE=1 compare every tag-stream and list read
// through a host pointer with the guest read; CC_SEEK_TRACE=1 prints, per
// seek, hashes of the stack below the caller's frame and of the list, to
// compare a CC_SEEK_EXACT=1 run with a native one seek by seek;
// CC_SEEK_STATS=1 prints a census at exit (frames CC_SAMPLE_FROM..
// CC_SAMPLE_TO).

#ifndef CC_XBOX_DRIVER
static const bool g_seek_exact = std::getenv("CC_SEEK_EXACT") != nullptr;
static const bool g_seek_stats = std::getenv("CC_SEEK_STATS") != nullptr;
static const bool g_seek_oracle = std::getenv("CC_ORACLE") != nullptr || std::getenv("CC_SEEK_ORACLE") != nullptr;
#elif defined(CC_SEEK_EXACT_BUILD)
static constexpr bool g_seek_exact = true;
#else
static constexpr bool g_seek_exact = false;
#endif

#ifndef CC_XBOX_DRIVER
// Host census: seeks (same frame / forward / backward), frames and tags
// walked, PlaceObject2 tags, entries matched and applied, children kept,
// new entries, list scans, and TSC cycles per seek (callees included).
struct CcSeekStats {
  uint64_t calls, same, fwd, back, frames, tags, place, remove, matched, applied, kept, fresh, scans, cycles;
  uint64_t handler_cycles, remove_cycles, frameoff_cycles, loop_cycles, apply_cycles, back_tags, back_cycles, codes[64];
};
static CcSeekStats g_seek_st;
namespace {
struct CcSeekReport {
  ~CcSeekReport() {
    if (!g_seek_stats || !g_seek_st.calls) return;
    const CcSeekStats& s = g_seek_st;
    const double c = double(s.calls);
    std::fprintf(stderr,
                 "SEEK %s calls=%llu same=%llu fwd=%llu back=%llu frames/seek=%.1f tags/seek=%.1f place/seek=%.1f "
                 "remove/seek=%.2f matched/seek=%.1f applied/seek=%.1f kept/seek=%.1f new/seek=%.2f scans/seek=%.1f "
                 "cycles/seek=%.0f\n",
                 g_seek_exact ? "exact" : "native", (unsigned long long)s.calls, (unsigned long long)s.same,
                 (unsigned long long)s.fwd, (unsigned long long)s.back, double(s.frames) / c, double(s.tags) / c,
                 double(s.place) / c, double(s.remove) / c, double(s.matched) / c, double(s.applied) / c,
                 double(s.kept) / c, double(s.fresh) / c, double(s.scans) / c, double(s.cycles) / c);
    std::fprintf(stderr, "SEEK cycles/seek: handlers=%.0f removes=%.0f frame-map=%.0f loops=%.0f applies=%.0f\n",
                 double(s.handler_cycles) / c, double(s.remove_cycles) / c, double(s.frameoff_cycles) / c,
                 double(s.loop_cycles) / c, double(s.apply_cycles) / c);
    const double b = double(s.back ? s.back : 1u);
    std::fprintf(stderr, "SEEK backward: tags/seek=%.1f cycles/seek=%.0f\n", double(s.back_tags) / b, double(s.back_cycles) / b);
    std::fprintf(stderr, "SEEK tags/seek by code:");
    for (int i = 0; i < 64; ++i)
      if (s.codes[i]) std::fprintf(stderr, " %d:%.2f", i, double(s.codes[i]) / c);
    std::fprintf(stderr, "\n");
  }
} g_seek_report;
}  // namespace
static bool g_seek_counting = false;  // census on for the current seek
static bool g_seek_was_back = false;
// CC_SEEK_STATS=2 also times the callees and the tag loops (the timers cost
// a few hundred cycles a seek, so the plain census leaves them out).
static const bool g_seek_timers = [] { const char* e = std::getenv("CC_SEEK_STATS"); return e && e[0] == '2'; }();
#define CC_SEEK_COUNT(field, n) do { if (g_seek_counting) g_seek_st.field += (n); } while (0)
#define CC_SEEK_TIME(field, ...) do { \
    const bool cc_stt = g_seek_counting && g_seek_timers; \
    const uint64_t cc_st0 = cc_stt ? __builtin_ia32_rdtsc() : 0u; \
    __VA_ARGS__; \
    if (cc_stt) g_seek_st.field += __builtin_ia32_rdtsc() - cc_st0; } while (0)
#else
#define CC_SEEK_COUNT(field, n) do { } while (0)
#define CC_SEEK_TIME(field, ...) do { __VA_ARGS__; } while (0)
#endif

// Little-endian u16 / u32 of the tag stream at guest a.
static inline uint32_t cc_seek_guest_le(Machine& base, uint32_t a, uint32_t n) {
  uint32_t v = 0u;
  for (uint32_t i = 0; i < n; ++i) v |= uint32_t(REX_LOAD_U8(a + i)) << (8u * i);
  return v;
}
static CC_HOT_FN inline uint32_t cc_seek_le(Machine& base, uint32_t a, uint32_t n) {
  uint32_t avail;
  const uint8_t* p = cc_host_span(a, avail);
  uint32_t v;
  if (__builtin_expect(avail >= n, 1)) {
    v = uint32_t(p[0]) | uint32_t(p[1]) << 8;
    if (n == 4u) v |= uint32_t(p[2]) << 16 | uint32_t(p[3]) << 24;
  } else {
    v = cc_seek_guest_le(base, a, n);
  }
#ifndef CC_XBOX_DRIVER
  if (g_seek_oracle) {
    const uint32_t g = cc_seek_guest_le(base, a, n);
    if (g != v) cc_oracle_mismatch("sub_82087F70 tag", int(n), g, v);
  }
#endif
  return v;
}
static CC_HOT_FN inline uint32_t cc_seek_le16(Machine& base, uint32_t a) { return cc_seek_le(base, a, 2u); }
static CC_HOT_FN inline uint32_t cc_seek_le32(Machine& base, uint32_t a) { return cc_seek_le(base, a, 4u); }
// The byte of PlaceObject2 flags as the original tests it: bit-reversed
// (HasCharacter 0x40, HasMatrix 0x20, HasColorTransform 0x10, HasRatio
// 0x08, HasName 0x04).
static inline uint32_t cc_seek_rev8(uint32_t b) {
  b = ((b & 0xF0u) >> 4) | ((b & 0x0Fu) << 4);
  b = ((b & 0xCCu) >> 2) | ((b & 0x33u) << 2);
  return ((b & 0xAAu) >> 1) | ((b & 0x55u) << 1);
}
// Float -> double -> float as lfs / stfs move a word (bits unchanged except
// that a signalling NaN comes back quiet).
static inline uint32_t cc_seek_fmove(uint32_t u) {
  float f; __builtin_memcpy(&f, &u, 4);
  const float g = float(double(f));
  uint32_t r; __builtin_memcpy(&r, &g, 4);
  return r;
}

// Tag stream position after the header at off (r29/r19 in the original):
// code, body offset p, next tag offset. A long length goes through the
// frame word +96 byte-swapped, as compiled.
struct CcSeekTag { uint32_t code, p, next; };
static CC_HOT_FN inline CcSeekTag cc_seek_tag(Machine& base, uint32_t tb, uint32_t off, uint32_t sp) {
  const uint32_t hdr = cc_seek_le16(base, tb + off);
  CcSeekTag t;
  t.code = hdr >> 6;
  t.p = off + 2u;
  uint32_t len = hdr & 0x3Fu;
  if (len == 63u) {
    len = cc_seek_le32(base, tb + t.p);
    REX_STORE_U32(sp + 96u, len);
    t.p += 4u;
  }
  t.next = len + t.p;
  return t;
}

// Frame offset through the frame map (sub_82082390, a leaf).
static CC_HOT_FN inline uint32_t cc_seek_frame_off(Context& ctx, Machine& base, uint32_t clip, uint32_t f, uint32_t lr) {
  ctx.r3.u64 = uint64_t(clip) + 108u;
  ctx.r4.u64 = f;
  ctx.lr = lr;
  CC_SEEK_TIME(frameoff_cycles, sub_82082390(ctx, base));
  return ctx.r3.u32;
}

// Entry list at 0x8225E6B8 (16 bytes: type, tag offset, u16 state, u16
// frame, depth). Host pointer when the run of entries is mapped in one
// piece, else guest accesses.
static constexpr uint32_t kSeekList = 0x8225E6B8u;
struct CcSeekList {
  uint8_t* h;
  uint32_t cap;  // entries reachable through h
  explicit CcSeekList() {
#ifdef CC_FLAT_WINDOW
    h = ::cc_win::ptr(kSeekList);  // the image is committed in one piece
    cap = (0x822D0000u - kSeekList) / 16u;
#else
    uint32_t avail;
    h = const_cast<uint8_t*>(cc_host_span(kSeekList, avail));
    cap = h ? avail / 16u : 0u;
#endif
  }
  uint32_t depth(Machine& base, uint32_t i) const {
    const uint32_t v = i < cap ? cc_hb32(h + 16u * i + 12u) : REX_LOAD_U32(kSeekList + 16u * i + 12u);
#ifndef CC_XBOX_DRIVER
    if (g_seek_oracle && v != REX_LOAD_U32(kSeekList + 16u * i + 12u))
      cc_oracle_mismatch("sub_82087F70 list depth", int(i), REX_LOAD_U32(kSeekList + 16u * i + 12u), v);
#endif
    return v;
  }
  uint32_t frame(Machine& base, uint32_t i) const {
    const uint32_t v = i < cap ? cc_hb16(h + 16u * i + 10u) : REX_LOAD_U16(kSeekList + 16u * i + 10u);
#ifndef CC_XBOX_DRIVER
    if (g_seek_oracle && v != REX_LOAD_U16(kSeekList + 16u * i + 10u))
      cc_oracle_mismatch("sub_82087F70 list frame", int(i), REX_LOAD_U16(kSeekList + 16u * i + 10u), v);
#endif
    return v;
  }
  void put(Machine& base, uint32_t i, uint32_t type, uint32_t off, uint32_t state, uint32_t frame, uint32_t depth) const {
    const uint32_t e = kSeekList + 16u * i;
    REX_STORE_U32(e + 0u, type);
    REX_STORE_U32(e + 4u, off);
    REX_STORE_U16(e + 8u, uint16_t(state));
    REX_STORE_U16(e + 10u, uint16_t(frame));
    REX_STORE_U32(e + 12u, depth);
  }
  // Entries 0..n-1 of depth d get state 2.
  void mark_removed(Machine& base, uint32_t n, uint32_t d) const {
    for (uint32_t i = 0; i < n; ++i)
      if (depth(base, i) == d) REX_STORE_U16(kSeekList + 16u * i + 8u, uint16_t(2u));
  }
  bool has_depth(Machine& base, uint32_t n, uint32_t d) const {
    for (uint32_t i = 0; i < n; ++i)
      if (depth(base, i) == d) return true;
    return false;
  }
};

// Child of the clip at depth d (first in list order), or 0.
static CC_HOT_FN inline uint32_t cc_seek_child(Machine& base, uint32_t clip, uint32_t d) {
  for (uint32_t n = REX_LOAD_U32(clip + 104u); n != 0u; n = REX_LOAD_U32(n + 88u))
    if (REX_LOAD_U32(n + 28u) == d) return n;
  return 0u;
}

// Backward seek: a PlaceObject2 of depth d in frame f applied to the child
// of kept entry k (same depth), the tag's fields read from cursor p.
// Returns the cursor after the fields it read.
static CC_HOT_FN uint32_t cc_seek_apply(Context& ctx, Machine& base, const CcSeekList& L, uint32_t k, uint32_t clip,
                                        uint32_t sp, uint32_t f, uint32_t d, uint32_t p, const uint32_t konst[2]) {
  const uint32_t tb = REX_LOAD_U32(clip + 92u);
  const uint32_t fl = cc_seek_rev8(REX_LOAD_U8(tb + p));
  p += 3u;
  const uint32_t node = cc_seek_child(base, clip, d);
  if (fl & 0x40u) p += 2u;  // character id
  if (fl & 0x20u) {         // matrix
    const uint32_t m = sp + 112u, c100 = konst[0], c0 = konst[1];
    REX_STORE_U32(m + 0u, c100);
    REX_STORE_U32(m + 4u, c100);
    REX_STORE_U32(m + 8u, c0);
    REX_STORE_U8(m + 12u, 0u);
    REX_STORE_U32(m + 16u, c100);
    REX_STORE_U8(m + 13u, 0u);
    REX_STORE_U32(m + 20u, c100);
    REX_STORE_U8(m + 14u, 0u);
    REX_STORE_U32(m + 24u, c0);
    REX_STORE_U32(m + 28u, c0);
    REX_STORE_U32(m + 32u, c0);
    REX_STORE_U32(m + 36u, c0);
    ctx.r3.u64 = m;
    ctx.r4.u64 = uint64_t(tb) + p;
    ctx.lr = 0x82088674u;
    sub_82085890(ctx, base);
    p += ctx.r3.u32;
    if ((REX_LOAD_U8(node + 86u) & 0x20u) == 0u) {
      // Copied through the same float registers as the original (they stay
      // set for whatever runs next).
      PPCRegister t{};
      auto lfs = [&](uint32_t a) { t.u32 = REX_LOAD_U32(a); return double(t.f32); };
      auto stfs = [&](uint32_t a, double v) { t.f32 = float(v); REX_STORE_U32(a, t.u32); };
      const uint32_t b12 = REX_LOAD_U8(m + 12u), b13 = REX_LOAD_U8(m + 13u), b14 = REX_LOAD_U8(m + 14u);
      ctx.f13.f64 = lfs(m + 24u);
      ctx.f12.f64 = lfs(m + 28u);
      ctx.f11.f64 = lfs(m + 32u);
      ctx.f10.f64 = lfs(m + 20u);
      ctx.f8.f64 = lfs(m + 0u);
      ctx.f7.f64 = lfs(m + 4u);
      ctx.f6.f64 = lfs(m + 16u);
      ctx.f0.f64 = lfs(m + 8u);
      ctx.f9.f64 = lfs(m + 36u);
      REX_STORE_U8(node + 50u, b14);
      REX_STORE_U8(node + 48u, b12);
      stfs(node + 60u, ctx.f13.f64);
      REX_STORE_U8(node + 49u, b13);
      stfs(node + 64u, ctx.f12.f64);
      stfs(node + 68u, ctx.f11.f64);
      stfs(node + 56u, ctx.f10.f64);
      stfs(node + 36u, ctx.f8.f64);
      stfs(node + 40u, ctx.f7.f64);
      stfs(node + 52u, ctx.f6.f64);
      stfs(node + 44u, ctx.f0.f64);
      stfs(node + 72u, ctx.f9.f64);
      REX_STORE_U8(node + 86u, REX_LOAD_U8(node + 86u) | 0x80u);
    }
  }
  if (fl & 0x10u) {  // colour transform, through a frame-local object
    const uint32_t c = sp + 160u;
    REX_STORE_U32(c + 0u, 0x8203E470u);
    REX_STORE_U32(c + 4u, 0u);
    REX_STORE_U32(c + 16u, 1u);
    REX_STORE_U32(c + 8u, 0u);
    REX_STORE_U32(c + 12u, 0u);
    REX_STORE_U8(c + 20u, 0u);
    REX_STORE_U16(c + 24u, 0u);
    REX_STORE_U16(c + 40u, 255u);
    REX_STORE_U16(c + 32u, 255u);
    REX_STORE_U16(c + 30u, 255u);
    REX_STORE_U16(c + 28u, 255u);
    REX_STORE_U16(c + 42u, 0u);
    REX_STORE_U16(c + 38u, 0u);
    REX_STORE_U16(c + 36u, 0u);
    REX_STORE_U16(c + 34u, 0u);
    REX_STORE_U32(c + 44u, 0u);
    ctx.r3.u64 = c;
    ctx.r4.u64 = uint64_t(REX_LOAD_U32(clip + 92u)) + p;
    ctx.lr = 0x82088754u;
    sub_82083F50(ctx, base);
    p += ctx.r3.u32;
    ctx.r4.u64 = c;
    ctx.r3.u64 = node;
    ctx.lr = 0x82088764u;
    sub_820837C0(ctx, base);
    REX_STORE_U32(c + 0u, 0x8203E4A0u);
    ctx.r3.u64 = c;
    ctx.lr = 0x82088770u;
    sub_82079970(ctx, base);
  } else if (f == L.frame(base, k)) {
    ctx.r3.u64 = node;
    ctx.lr = 0x82088788u;
    sub_820838A8(ctx, base);
  }
  if (fl & 0x08u) p += 2u;  // ratio
  if (fl & 0x04u) {         // name
    ctx.r3.u64 = REX_LOAD_U32(REX_LOAD_U32(clip + 156u) + 10316u);
    ctx.r4.u64 = uint64_t(REX_LOAD_U32(clip + 92u)) + p;
    ctx.lr = 0x820887B8u;
    sub_8209D948(ctx, base);
    ctx.r4.u64 = ctx.r3.u64;
    cc_vcall(ctx, base, node, 76u, 0x820887D0u);
  }
  return p;
}

static CC_HOT_FN void cc_seek_native(Context& ctx, Machine& base) {
  const uint32_t clip = ctx.r3.u32;
  const uint32_t arg = ctx.r4.u32, want = arg & 0xFFFFu;
  ctx.r12.u64 = ctx.lr;
  ctx.fpscr.disableFlushMode();
  const uint32_t r1 = ctx.r1.u32, sp = r1 - 384u;
  REX_STORE_U64(r1 - 168u, ctx.f30.u64);
  REX_STORE_U64(r1 - 160u, ctx.f31.u64);
  CcFrame frame(ctx, base, 384u);
  REX_STORE_U16(sp + 414u, uint16_t(arg));
  CC_SEEK_COUNT(calls, 1);
  // Current frame (slot 160; the clip classes' sub_820867F0, u16 +146 or 1
  // when 0, is answered inline).
  const uint32_t vt0 = REX_LOAD_U32(clip + 0u), get = REX_LOAD_U32(vt0 + 160u);
  uint32_t now;
  if (get == 0x820867F0u) {
    now = REX_LOAD_U16(clip + 146u);
    if (now == 0u) now = 1u;
    ctx.r3.u64 = now;
    ctx.lr = 0x82087FA4u;
    ctx.ctr.u64 = get;
  } else {
    now = cc_vcall(ctx, base, clip, 160u, 0x82087FA4u) & 0xFFFFu;
  }
  if (want == now) {
    // Volatile registers as the original leaves them (a later variadic
    // call can spill them into stack words that later reach the heap).
    ctx.r9.u64 = now;
    ctx.r11.u64 = vt0;
    ctx.r10.u64 = get;
    CC_SEEK_COUNT(same, 1);
    return;
  }
  {  // update stack push
    const uint32_t m = REX_LOAD_U32(REX_LOAD_U32(REX_LOAD_U32(clip + 156u) + 76u) + 156u);
    const uint32_t n = REX_LOAD_U32(m + 8248u) + 1u;
    REX_STORE_U32(m + 8248u, n);
    REX_STORE_U32(m + (n + 1998u) * 4u, clip);
  }
  {
    const uint32_t pending = REX_LOAD_U16(clip + 144u), cur = REX_LOAD_U16(clip + 146u);
    REX_STORE_U16(clip + 142u, uint16_t(cur));
    REX_STORE_U16(clip + 146u, uint16_t(pending != 0u ? pending : 1u));
  }
  REX_STORE_U8(clip + 140u, uint8_t(REX_LOAD_U8(clip + 140u) | 0x40u));
  {  // the player's ring of {clip, slot 140, frame}
    const uint32_t pl = REX_LOAD_U32(REX_LOAD_U32(REX_LOAD_U32(clip + 156u) + 76u) + 156u);
    const uint32_t v = cc_vcall(ctx, base, clip, 140u, 0x82088020u);
    REX_STORE_U32(pl + REX_LOAD_U32(pl + 7988u) * 12u + 4924u, clip);
    REX_STORE_U32(pl + REX_LOAD_U32(pl + 7988u) * 12u + 4928u, v);
    REX_STORE_U16(pl + (REX_LOAD_U32(pl + 7988u) + 411u) * 12u, uint16_t(arg));
    uint32_t nx = REX_LOAD_U32(pl + 7988u) + 1u;
    if (nx == 255u) nx = 0u;
    if (nx == REX_LOAD_U32(pl + 7984u)) {
      ctx.r3.u64 = pl;
      ctx.lr = 0x82088094u;
      sub_820935B0(ctx, base);
    }
    const uint32_t i = REX_LOAD_U32(pl + 7988u) + 1u;
    REX_STORE_U32(pl + 7988u, i);
    if (i == 255u) REX_STORE_U32(pl + 7988u, 0u);
  }
  const uint32_t prev = REX_LOAD_U16(clip + 142u);
  REX_STORE_U32(sp + 104u, 0u);
  const CcSeekList L;
  uint32_t n = 0u;      // entries written (r15)
  uint32_t kept = 0u;   // entries for children (r23)
  if (want > prev) {
    CC_SEEK_COUNT(fwd, 1);
    uint32_t f = (prev + 1u) & 0xFFFFu;
    uint32_t off = cc_seek_frame_off(ctx, base, clip, f, 0x820880DCu);
    REX_STORE_U32(sp + 100u, kSeekList);
    for (uint32_t c = REX_LOAD_U32(clip + 104u); c != 0u; c = REX_LOAD_U32(c + 88u)) {
      REX_STORE_U16(c + 82u, REX_LOAD_U16(clip + 146u));
      L.put(base, n, 0u, 0u, 0u, 0u, REX_LOAD_U32(c + 28u));
      ++n; ++kept;
    }
    CC_SEEK_COUNT(kept, kept);
    if (f <= want) {
#ifndef CC_XBOX_DRIVER
      const uint64_t cc_lt0 = g_seek_counting && g_seek_timers ? __builtin_ia32_rdtsc() : 0u;
#endif
      do {
        const uint32_t tb = REX_LOAD_U32(clip + 92u);
        const CcSeekTag t = cc_seek_tag(base, tb, off, sp);
        CC_SEEK_COUNT(tags, 1);
        CC_SEEK_COUNT(codes[t.code & 63u], 1);
        if (t.code == 1u) {
          f = (f + 1u) & 0xFFFFu;
          off = cc_seek_frame_off(ctx, base, clip, f, 0x820881BCu);
          CC_SEEK_COUNT(frames, 1);
          continue;
        }
        off = t.next;
        if (t.code == 26u) {
          CC_SEEK_COUNT(place, 1);
          L.put(base, n++, 26u, t.p, 1u, f, cc_seek_le16(base, tb + t.p + 1u) - 16384u);
        } else if (t.code == 5u || t.code == 28u) {
          CC_SEEK_COUNT(remove, 1);
          const uint32_t d16 = cc_seek_le16(base, tb + t.p + (t.code == 5u ? 2u : 0u));
          ctx.r3.u64 = uint64_t(clip) + 104u;
          ctx.r4.s64 = int64_t(d16) - 16384;
          ctx.lr = 0x82088328u;
          CC_SEEK_TIME(remove_cycles, sub_82084C78(ctx, base));
          L.mark_removed(base, n, d16 - 16384u);
          CC_SEEK_COUNT(scans, 1);
        }
      } while (f <= want);
#ifndef CC_XBOX_DRIVER
      if (g_seek_counting && g_seek_timers) g_seek_st.loop_cycles += __builtin_ia32_rdtsc() - cc_lt0;
#endif
    }
  } else {
    CC_SEEK_COUNT(back, 1);
#ifndef CC_XBOX_DRIVER
    g_seek_was_back = true;
#endif
    uint32_t off = cc_seek_frame_off(ctx, base, clip, 1u, 0x82088378u);
    REX_STORE_U32(sp + 100u, kSeekList);
    uint32_t c = REX_LOAD_U32(clip + 104u);
    if (c != 0u) {
      while (c != 0u) {
        if (REX_LOAD_U16(c + 84u) > want) {
          const uint32_t d = REX_LOAD_U32(c + 28u);
          c = REX_LOAD_U32(c + 88u);
          ctx.r3.u64 = uint64_t(clip) + 104u;
          ctx.r4.u64 = d;
          ctx.lr = 0x820883B8u;
          CC_SEEK_TIME(remove_cycles, sub_82084C78(ctx, base));
        } else {
          REX_STORE_U16(c + 82u, REX_LOAD_U16(clip + 146u));
          L.put(base, n, 0u, 0u, 0u, REX_LOAD_U16(c + 84u), REX_LOAD_U32(c + 28u));
          ++n; ++kept;
          c = REX_LOAD_U32(c + 88u);
        }
      }
      REX_STORE_U32(sp + 104u, kept);
    }
    CC_SEEK_COUNT(kept, kept);
    if (want >= 1u) {
      const uint32_t konst[2] = {cc_seek_fmove(REX_LOAD_U32(0x8201473Cu)), cc_seek_fmove(REX_LOAD_U32(0x82042540u))};
      uint32_t f = 1u;
#ifndef CC_XBOX_DRIVER
      const uint64_t cc_lt0 = g_seek_counting && g_seek_timers ? __builtin_ia32_rdtsc() : 0u;
#endif
      do {
        const uint32_t tb = REX_LOAD_U32(clip + 92u);
        const CcSeekTag t = cc_seek_tag(base, tb, off, sp);
        CC_SEEK_COUNT(tags, 1); CC_SEEK_COUNT(back_tags, 1);
        CC_SEEK_COUNT(codes[t.code & 63u], 1);
        if (t.code == 1u) {
          f = (f + 1u) & 0xFFFFu;
          off = cc_seek_frame_off(ctx, base, clip, f, 0x82088494u);
          CC_SEEK_COUNT(frames, 1);
          continue;
        }
        off = t.next;
        if (t.code == 26u) {
          CC_SEEK_COUNT(place, 1);
          const uint32_t d = cc_seek_le16(base, tb + t.p + 1u) - 16384u;
          bool any = false;
          uint32_t p = t.p;
          CC_SEEK_COUNT(scans, kept != 0u ? 1 : 0);
          for (uint32_t k = 0; k < kept; ++k) {
            if (L.depth(base, k) != d) continue;
            any = true;
            CC_SEEK_COUNT(matched, 1);
            const uint32_t ef = L.frame(base, k);
            if (f < ef) continue;
            CC_SEEK_COUNT(applied, 1);
            CC_SEEK_TIME(apply_cycles, p = cc_seek_apply(ctx, base, L, k, clip, sp, f, d, p, konst));
          }
          if (!any) {
            L.put(base, n++, 26u, p, 1u, f, d);
            CC_SEEK_COUNT(fresh, 1);
          }
        } else if (t.code == 5u || t.code == 28u) {
          CC_SEEK_COUNT(remove, 1);
          const uint32_t d16 = cc_seek_le16(base, tb + t.p + (t.code == 5u ? 2u : 0u));
          const uint32_t d = d16 - 16384u;
          CC_SEEK_COUNT(scans, 1);
          if (!L.has_depth(base, kept, d)) {
            ctx.r3.u64 = uint64_t(clip) + 104u;
            ctx.r4.s64 = int64_t(d16) - 16384;
            ctx.lr = 0x820888BCu;
            CC_SEEK_TIME(remove_cycles, sub_82084C78(ctx, base));
            L.mark_removed(base, n, d);
          }
        }
      } while (f <= want);
#ifndef CC_XBOX_DRIVER
      if (g_seek_counting && g_seek_timers) g_seek_st.loop_cycles += __builtin_ia32_rdtsc() - cc_lt0;
#endif
    }
  }
  // New entries: tag handlers (entries re-read from the list: a handler may
  // run a nested seek, which reuses it).
  for (uint32_t k = kept; int32_t(k) < int32_t(n); ++k) {
    const uint32_t e = kSeekList + 16u * k;
    if (REX_LOAD_U16(e + 8u) == 2u) continue;
    REX_STORE_U16(clip + 146u, REX_LOAD_U16(e + 10u));
    const uint32_t type = REX_LOAD_U32(e + 0u);
    if (type == 255u) continue;
    const uint32_t fn = REX_LOAD_U32(0x8215A400u + (type << 2));
    ctx.r11.u64 = fn;
    if (fn != 0u) {
      ctx.r9.u64 = REX_LOAD_U32(e + 4u);
      ctx.r10.u64 = REX_LOAD_U32(clip + 92u);
      ctx.r3.u64 = REX_LOAD_U32(clip + 156u);
      ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
      ctx.r5.u64 = 0u;
      ctx.lr = 0x82088974u;
      ctx.ctr.u64 = fn;
      CC_SEEK_TIME(handler_cycles, if (fn == 0x820922B8u) sub_820922B8(ctx, base); else REX_CALL_INDIRECT_FUNC(fn));
    } else if (type != 45u) {
      // Unknown tag type (never seen: only PlaceObject2 entries are new).
      ctx.r3.u64 = 0xFFFFFFFF8203E5C4ull;
      ctx.r4.u64 = type;
      ctx.lr = 0x82088988u;
      sub_820798D8(ctx, base);
      ctx.lr = 0x8208898Cu;
      sub_8208C5D8(ctx, base);
    }
  }
  REX_STORE_U16(clip + 146u, REX_LOAD_U16(sp + 414u));
  for (uint32_t c = REX_LOAD_U32(clip + 104u); c != 0u; c = REX_LOAD_U32(c + 88u))
    if (REX_LOAD_U16(c + 82u) == 0u) REX_STORE_U16(c + 82u, REX_LOAD_U16(clip + 146u));
  {  // update stack pop, leaving r6-r11 as the original does
    const uint32_t r10 = REX_LOAD_U32(REX_LOAD_U32(clip + 156u) + 76u);
    const uint32_t m = REX_LOAD_U32(r10 + 156u);
    const uint64_t r8 = uint64_t(REX_LOAD_U32(m + 8248u)) + 1998u;
    const uint32_t r7 = uint32_t(r8) << 2;
    REX_STORE_U32(r7 + m, 0u);
    const uint32_t r11 = REX_LOAD_U32(m + 8248u);
    const uint64_t r6 = uint64_t(r11) - 1u;
    REX_STORE_U32(m + 8248u, uint32_t(r6));
    ctx.r6.u64 = r6;
    ctx.r7.u64 = r7;
    ctx.r8.u64 = r8;
    ctx.r9.u64 = m;
    ctx.r10.u64 = r10;
    ctx.r11.u64 = r11;
  }
}

static CC_HOT_FN void sub_82087F70(Context& ctx, Machine& base) {
  CC_FPROF_SCOPE(sub_82087F70_native);
#ifndef CC_XBOX_DRIVER
  const bool timed = g_seek_stats && g_sample_on.load(std::memory_order_relaxed);
  const bool outer = !g_seek_counting;
  if (timed && outer) g_seek_counting = true;
  const uint64_t t0 = timed && outer ? __builtin_ia32_rdtsc() : 0u;
  if (g_seek_exact) {
    if (timed) ++g_seek_st.calls;
    sub_82087F70_exact(ctx, base);
  } else {
    cc_seek_native(ctx, base);
  }
  if (timed && outer) {
    const uint64_t dt = __builtin_ia32_rdtsc() - t0;
    g_seek_st.cycles += dt;
    if (g_seek_was_back) g_seek_st.back_cycles += dt;
    g_seek_was_back = false;
    g_seek_counting = false;
  }
  // CC_SEEK_TRACE=1: per seek, a hash of the 16 KiB of stack below the
  // caller's frame (the seek's frame words and its callees' frames) and of
  // the first 64 list entries, for comparing CC_SEEK_EXACT=1 runs with
  // native runs seek by seek (the state hash skips the stack region).
  static const bool trace = std::getenv("CC_SEEK_TRACE") != nullptr;
  if (trace) {
    static uint32_t seq = 0;
    uint64_t hs = 0xcbf29ce484222325ull, hl = hs;
    for (uint32_t a = ctx.r1.u32 - 16384u; a != ctx.r1.u32; a += 4u) hs = (hs ^ REX_LOAD_U32(a + 0u)) * 0x100000001B3ull;
    for (uint32_t a = kSeekList; a != kSeekList + 1024u; a += 4u) hl = (hl ^ REX_LOAD_U32(a + 0u)) * 0x100000001B3ull;
    std::fprintf(stderr, "SEEKTRACE %u f=%u stack=%016llx list=%016llx\n", seq, g_frame_delay_calls + 1u,
                 (unsigned long long)hs, (unsigned long long)hl);
    static const long at = [] { const char* e = std::getenv("CC_SEEK_TRACE_AT"); return e ? std::strtol(e, nullptr, 10) : -1L; }();
    if (long(seq) == at)
      for (uint32_t a = ctx.r1.u32 - 16384u; a != ctx.r1.u32; a += 4u)
        std::fprintf(stderr, "SEEKWORD %08x %08x\n", a, REX_LOAD_U32(a + 0u));
    ++seq;
  }
#else
  if (g_seek_exact) { sub_82087F70_exact(ctx, base); return; }
  cc_seek_native(ctx, base);
#endif
}
