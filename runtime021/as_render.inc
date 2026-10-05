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
//
// Play build: the methods the walk calls are read from the node's vtable
// and, when they are the display-list classes' own (addresses below; the
// image's code is fixed), answered or called directly instead of through
// cc_vcall: slot 48 (clear bit 6 of +86), slot 44 (constant 1 or 0), slot
// 180 (the visibility query sub_8208AF08, or constant 1) and slot 68 (this
// walk or the sprite leaf). Any other method is called as before.
// The query for a child C walks C's parents (slot 156, +96 for clips) and
// returns 0 at the first one that answers slot 44 with bit 0 of byte +140
// clear, else C's own bit 0 of +140. For every child whose parent is this
// clip the walk over the parents is the same, so it is done once per clip
// (the clip's "chain": 1 every node from the clip up passes, 2 one fails)
// and such a child's answer is (chain 1 ? bit 0 of its +140 : 0). The chain
// of a clip child follows from this clip's and is handed to its walk. The
// query's one guest-visible effect, its frame word at r1 - 112, is still
// written. Chains are formed only from the recognised leaves (slot 44
// constant, slot 156 +96 or constant 0); otherwise the query runs. Nothing
// the draw walk runs writes +96 or +140; with CC_ORACLE=1 the host runs the
// query for every child answered from a chain and logs any difference.
// The next sibling's node is prefetched while a child is drawn.
// Switches: host CC_WALK_VCALL=1 (every method through cc_vcall, no chains:
// the previous walk), CC_WALK_NOINHERIT=1 (the query for every child),
// CC_WALK_NOPREFETCH=1; Xbox make WALKVCALL=1 / WALKNOINHERIT=1 /
// WALKNOPREFETCH=1. CC_WALK_EXACT (the exact query) also turns chains off.
namespace cc_walk {
constexpr uint32_t kLi1 = 0x820619E8u;     // li r3,1
constexpr uint32_t kLi0 = 0x82053A98u;     // li r3,0
constexpr uint32_t kParent = 0x820868D0u;  // lwz r3,96(r3)
constexpr uint32_t kClear6 = 0x82086278u;  // byte +86 &= ~0x40
constexpr uint32_t kQuery = 0x8208AF08u;   // sub_8208AF08
constexpr uint32_t kWalk = 0x8208A7A0u;    // sub_8208A7A0
constexpr uint32_t kSprite = 0x820855D8u;  // sub_820855D8
#if defined(CC_WALK_VCALL_BUILD)
constexpr bool kDirect = false;
#else
constexpr bool kDirect = true;
#endif
#if defined(CC_WALK_VCALL_BUILD) || defined(CC_WALK_NOINHERIT_BUILD) || defined(CC_WALK_EXACT_BUILD)
constexpr bool kInherit = false;
#else
constexpr bool kInherit = true;
#endif
#if defined(CC_WALK_NOPREFETCH_BUILD)
constexpr bool kPrefetch = false;
#else
constexpr bool kPrefetch = true;
#endif
#ifdef CC_XBOX_DRIVER
inline bool direct() { return kDirect; }
inline bool inherit() { return kInherit; }
inline bool prefetch() { return kPrefetch; }
#else
inline bool direct() {
  static const bool on = kDirect && !std::getenv("CC_WALK_VCALL");
  return on;
}
inline bool inherit() {
  static const bool on = kInherit && direct() && !std::getenv("CC_WALK_NOINHERIT") && !std::getenv("CC_WALK_EXACT");
  return on;
}
inline bool prefetch() {
  static const bool on = kPrefetch && !std::getenv("CC_WALK_NOPREFETCH");
  return on;
}
#endif
// Chain handed by a walk to the walk of the clip child it calls next
// (taken and cleared at that walk's entry).
uint32_t g_chain_node = 0;
uint8_t g_chain = 0;
// A node's methods in slots 44, 68, 156 and 180.
struct Slots { uint32_t s44, s68, s156, s180; };
inline __attribute__((always_inline)) void slots(Machine& base, uint32_t vt, Slots& s) {
  if (const uint8_t* p = cc_obj_host(vt + 44u, 140u)) {
    s.s44 = cc_hb32(p); s.s68 = cc_hb32(p + 24u); s.s156 = cc_hb32(p + 112u); s.s180 = cc_hb32(p + 136u);
  } else {
    s.s44 = REX_LOAD_U32(vt + 44u); s.s68 = REX_LOAD_U32(vt + 68u);
    s.s156 = REX_LOAD_U32(vt + 156u); s.s180 = REX_LOAD_U32(vt + 180u);
  }
}
// Chain of node a as the query walks it: 1 pass, 2 fail, 3 a method on the
// way is not a recognised leaf (the query then runs for each child).
__attribute__((noinline)) uint8_t chain_of(Machine& base, uint32_t a) {
  for (uint32_t n = 0; a != 0u; ++n) {
    if (n >= 4096u) return 3u;  // a parent loop: the query itself runs (and loops)
    const uint32_t vt = REX_LOAD_U32(a);
    const uint32_t s44 = REX_LOAD_U32(vt + 44u), s156 = REX_LOAD_U32(vt + 156u);
    if (s44 == kLi1) {
      if ((REX_LOAD_U8(a + 140u) & 1u) == 0u) return 2u;
    } else if (s44 != kLi0) {
      return 3u;
    }
    if (s156 == kParent) a = REX_LOAD_U32(a + 96u);
    else if (s156 == kLi0) a = 0u;
    else return 3u;
  }
  return 1u;
}
// Prefetch of the node at guest a (the fields the walk and the sprite leaf
// read lie in its first 160 bytes).
inline __attribute__((always_inline)) void prefetch_node(uint32_t a) {
  if (const uint8_t* p = cc_obj_host(a, 160u)) {
    __builtin_prefetch(p, 0, 3); __builtin_prefetch(p + 32, 0, 3); __builtin_prefetch(p + 64, 0, 3);
    __builtin_prefetch(p + 96, 0, 3); __builtin_prefetch(p + 128, 0, 3);
  }
}
#ifndef CC_XBOX_DRIVER
// Oracle (CC_ORACLE=1): the query itself for a child answered from the
// clip's chain (it writes the same frame word).
__attribute__((noinline)) void oracle_query(Context& ctx, Machine& base, uint32_t ch, uint32_t answer) {
  ctx.r3.u64 = ch; ctx.lr = 0x8208A888u;
  sub_8208AF08(ctx, base);
  if ((ctx.r3.u32 & 0xFFu) != answer) cc_oracle_mismatch("sub_8208A7A0 chain", 0, ctx.r3.u32 & 0xFFu, answer);
}
#endif
}  // namespace cc_walk
static CC_HOT_FN void sub_8208A7A0(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_8208A7A0);
  CC_FPROF_SCOPE(sub_8208A7A0_native);
  using namespace cc_walk;
  const uint32_t clip = ctx.r3.u32, st = ctx.r4.u32, rnd = ctx.r5.u32;
  uint32_t stop = ctx.r6.u32;
  const bool dir = direct(), inh = inherit(), pf = prefetch();
  // This clip's chain: 0 not yet known, 1 pass, 2 fail, 3 not formed.
  uint8_t chain = g_chain_node == clip ? g_chain : 0u;
  g_chain_node = 0u;
  CcFrame frame(ctx, base, 256u);
  const uint32_t r1 = ctx.r1.u32;
  uint32_t r23 = 0, flags = 0, depth = 0;
  if (dir && REX_LOAD_U32(REX_LOAD_U32(clip) + 48u) == kClear6) REX_STORE_U8(clip + 86u, uint8_t(REX_LOAD_U8(clip + 86u) & 0xBFu));
  else cc_vcall(ctx, base, clip, 48u, 0x8208A7DCu);
  if (stop == clip) stop = 0u;
  if (int32_t(REX_LOAD_U32(clip + 152u)) != 0) {
    ctx.r4.u64 = rnd; ctx.r5.u64 = REX_LOAD_U32(clip + 152u) & 0xFFFFu;
    ctx.r3.u64 = r1 + 80u; ctx.lr = 0x8208A814u;
    REX_CALL_INDIRECT_FUNC(REX_LOAD_U32(REX_LOAD_U32(rnd) + 32u));
  }
  for (uint32_t ch = REX_LOAD_U32(clip + 104u); ch != 0u; ch = REX_LOAD_U32(ch + 88u)) {
    if (pf) prefetch_node(REX_LOAD_U32(ch + 88u));
    Slots s{0u, 0u, 0u, 0u};
    if (dir) slots(base, REX_LOAD_U32(ch), s);
    uint32_t a44;
    if (dir && s.s44 == kLi1) a44 = 1u;
    else if (dir && s.s44 == kLi0) a44 = 0u;
    else a44 = cc_vcall(ctx, base, ch, 44u, 0x8208A858u) & 0xFFu;
    bool draw;
    if (a44 == 0u) {
      draw = true;
    } else if ((REX_LOAD_U8(ch + 140u) & 0x80u) == 0u) {
      draw = false;
    } else if (dir && s.s180 == kQuery) {
      // ch's parents as the query walks them are this clip's chain when
      // ch's slot 156 is +96 and that is this clip.
      const bool mine = inh && s.s156 == kParent && REX_LOAD_U32(ch + 96u) == clip;
      if (mine && chain == 0u) chain = chain_of(base, clip);
      if (mine && (chain == 1u || chain == 2u)) {
        REX_STORE_U32(r1 - 112u, r1);  // the query's frame word
        const uint32_t answer = chain == 1u ? (REX_LOAD_U8(ch + 140u) & 1u) : 0u;
#ifndef CC_XBOX_DRIVER
        static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
        if (oracle) oracle_query(ctx, base, ch, answer);
#endif
        draw = answer != 0u;
      } else {
        ctx.r3.u64 = ch; ctx.lr = 0x8208A888u;
        sub_8208AF08(ctx, base);
        draw = (ctx.r3.u32 & 0xFFu) != 0u;
      }
    } else if (dir && s.s180 == kLi1) {
      draw = true;
    } else {
      draw = (cc_vcall(ctx, base, ch, 180u, 0x8208A888u) & 0xFFu) != 0u;
    }
    if (!draw) {
      if (stop == ch) { r23 = 2u; break; }
      continue;
    }
    if ((REX_LOAD_U8(ch + 86u) & 0x10u) == 0u) continue;
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
    uint32_t r;
    if (dir && s.s68 == kWalk) {
      // The child's chain fails at the child itself when it answers slot 44
      // with bit 0 of +140 clear, else continues with this clip's when the
      // child's parent (slot 156) is this clip.
      uint8_t cc = 0u;
      if (inh) {
        if (s.s44 == kLi1 && (REX_LOAD_U8(ch + 140u) & 1u) == 0u) cc = 2u;
        else if ((s.s44 == kLi1 || s.s44 == kLi0) && s.s156 == kParent && REX_LOAD_U32(ch + 96u) == clip &&
                 (chain == 1u || chain == 2u))
          cc = chain;
      }
      g_chain_node = cc ? ch : 0u; g_chain = cc;
      ctx.r3.u64 = ch; ctx.lr = 0x8208AB28u;
      sub_8208A7A0(ctx, base);
      g_chain_node = 0u;
      r = ctx.r3.u32;
    } else if (dir && s.s68 == kSprite) {
      ctx.r3.u64 = ch; ctx.lr = 0x8208AB28u;
      sub_820855D8(ctx, base);
      r = ctx.r3.u32;
    } else {
      r = cc_vcall(ctx, base, ch, 68u, 0x8208AB28u);
    }
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

// Fused sprite leaf (play build). For a textured sprite drawn by the game's
// 2D renderer (vtable 0x82042048 whose slots 40, 92, 108 and 116 hold its own
// methods 0x820A74E0, 0x820A89F8, 0x820A8DD8 and 0x820A9308), the leaf's work
// is done from host values (its stack frame is still filled, see below):
//  - slot 40 (the current material getter) has no effects and is skipped;
//  - the corners are sub_82085110's arithmetic (cc_corners_words) and the
//    cull is sub_820A8DD8's mode-4 test, on the corner values directly;
//  - the colour and uv extents are computed as in sub_820855D8 below, the
//    bind wrapper sub_820A89F8 runs as before (r3 renderer, r4 texture);
//  - the quad is cc_quad_native's count-4 path: the same draw-flag, ring and
//    material-mode tests, the ring count bumped by 4. Its vertices are
//    written to the guest vertex ring and drawn through sub_820C1980 (host:
//    always, so the 360 draw, the state hash and the frame capture see what
//    they saw before; Xbox: with make SPRITERING=1) or handed straight to the
//    Xbox renderer's quad batch (cc_xr_quad; the ring's only reader on the
//    Xbox is sub_820C1980's hand-off, which then has nothing to read).
//    Modes with other vertex layouts (2, 6, 10, 11, 14, 15) call
//    sub_820A9308 on the leaf's frame as the general path does.
// Guest-visible effects, including the leaf's stack frame below r1, are
// those of the general path in its order: later guest code copies stale
// stack words into heap objects, so the state hash differs when the frame
// is not filled or the bind and quad run at another depth.
// Switches: host CC_SPRITE_UNFUSED=1 (also off with CC_QUAD_EXACT or
// CC_QUADLOG, whose probes sit on the general path); Xbox make
// SPRITEUNFUSED=1. With CC_ORACLE=1 the host also runs the exact corners and
// cull on scratch stack points and logs any difference.
#if defined(CC_SPRITE_EXACT_BUILD) || defined(CC_CULL_EXACT_BUILD) || defined(CC_SPRITE_UNFUSED_BUILD)
static constexpr bool kCcSpriteFused = false;
#else
static constexpr bool kCcSpriteFused = true;
#endif
static inline bool cc_sprite_fused_on() {
#ifdef CC_XBOX_DRIVER
  return kCcSpriteFused;
#else
  static const bool on = kCcSpriteFused && !std::getenv("CC_SPRITE_UNFUSED") && !std::getenv("CC_QUAD_EXACT") &&
                         !std::getenv("CC_QUADLOG");
  return on;
#endif
}
// Words of the leaf's frame (open at r1) as the general path stores them:
// the four points {x, y, z} at +216 / +200 / +184 / +168; the uv pairs at
// +136, +128, +120 and +112, the colour at +92, the count (4) at +100 and
// the pointer r1 + 112 at +84. Later guest code reads stale stack words
// (some are copied into heap objects), so the frame holds what it held.
static inline __attribute__((always_inline)) void cc_frame_put(Machine& base, uint8_t* fp, uint32_t r1, uint32_t off, uint32_t v) {
  if (fp) cc_hput32(fp + (off - 84u), v);
  else REX_STORE_U32(r1 + off, v);
}
static inline __attribute__((always_inline)) void cc_sprite_frame_points(Machine& base, uint32_t r1, const uint32_t c[4][3]) {
  uint8_t* fp = cc_obj_host(r1 + 84u, 144u);
  static const uint32_t at[4] = {216u, 200u, 184u, 168u};
  for (int i = 0; i < 4; ++i)
    for (uint32_t k = 0; k < 3; ++k) cc_frame_put(base, fp, r1, at[i] + 4u * k, c[i][k]);
}
static inline __attribute__((always_inline)) void cc_sprite_frame_quad(Machine& base, uint32_t r1, uint32_t zero, uint32_t u, uint32_t v,
                                                                       uint32_t packed) {
  uint8_t* fp = cc_obj_host(r1 + 84u, 144u);
  cc_frame_put(base, fp, r1, 136u, zero); cc_frame_put(base, fp, r1, 140u, zero);
  cc_frame_put(base, fp, r1, 132u, zero); cc_frame_put(base, fp, r1, 112u, zero);
  cc_frame_put(base, fp, r1, 128u, u); cc_frame_put(base, fp, r1, 120u, u);
  cc_frame_put(base, fp, r1, 124u, v); cc_frame_put(base, fp, r1, 116u, v);
  cc_frame_put(base, fp, r1, 92u, packed);
  cc_frame_put(base, fp, r1, 100u, 4u);
  cc_frame_put(base, fp, r1, 84u, r1 + 112u);
}
// Slot 116 on the filled frame (modes with other vertex layouts).
static __attribute__((noinline)) void cc_sprite_quad_guest(Context& ctx, Machine& base, uint32_t rnd) {
  const uint32_t r1 = ctx.r1.u32;
  ctx.r3.u64 = rnd; ctx.r4.u64 = r1 + 216u; ctx.r5.u64 = r1 + 200u; ctx.r6.u64 = r1 + 184u; ctx.r7.u64 = r1 + 168u;
  ctx.r8.u64 = r1 + 136u; ctx.r9.u64 = r1 + 128u; ctx.r10.u64 = r1 + 120u; ctx.lr = 0x82085838u;
  sub_820A9308(ctx, base);
}
#ifndef CC_XBOX_DRIVER
// Oracle (CC_ORACLE=1): the exact corners (sub_82085110_exact) and mode-4
// cull (sub_820A8DD8_exact) on scratch points in a frame below r1, compared
// with the fused values. Only the stack is written.
static __attribute__((noinline)) void cc_sprite_fused_oracle(Context& ctx, Machine& base, uint32_t spr, uint32_t m, uint32_t rnd,
                                                             const uint32_t c[4][3], bool culled) {
  CcFrame frame(ctx, base, 288u);
  const uint32_t r1 = ctx.r1.u32;
  const uint32_t pts[4] = {r1 + 216u, r1 + 200u, r1 + 184u, r1 + 168u};
  for (uint32_t p : pts)
    for (uint32_t k = 0; k < 3; ++k) REX_STORE_U32(p + 4u * k, 0u);
  ctx.r3.u64 = spr; ctx.r4.u64 = m; ctx.r5.u64 = pts[0]; ctx.r6.u64 = pts[1]; ctx.r7.u64 = pts[2]; ctx.r8.u64 = pts[3];
  ctx.lr = 0x820856BCu;
  sub_82085110_exact(ctx, base);
  for (int i = 0; i < 4; ++i)
    for (uint32_t k = 0; k < 3; ++k) {
      const uint32_t e = REX_LOAD_U32(pts[i] + 4u * k);
      if (e != c[i][k]) cc_oracle_mismatch("sub_820855D8 fused corners", i * 3 + int(k), e, c[i][k]);
    }
  ctx.r3.u64 = rnd; ctx.r4.u64 = pts[0]; ctx.r5.u64 = pts[1]; ctx.r6.u64 = pts[2]; ctx.r7.u64 = pts[3]; ctx.r8.u64 = 4u;
  ctx.lr = 0x820856E4u;
  sub_820A8DD8_exact(ctx, base);
  const bool e = (ctx.r3.u32 & 0xFFu) != 0u;
  if (e != culled) cc_oracle_mismatch("sub_820855D8 fused cull", 0, e, culled);
}
#endif
// Returns false, having done nothing, when the renderer is not the game's
// own; else the leaf's result (1 culled, else 0) in `result`.
static CC_HOT_FN bool cc_sprite_fused(Context& ctx, Machine& base, uint32_t spr, uint32_t st, uint32_t rnd, uint32_t tex,
                                      uint32_t& result) {
  const uint32_t vt = REX_LOAD_U32(rnd);
  if (vt != 0x82042048u) return false;
  {
    uint32_t s[20];
    cc_load_words(base, vt + 40u, 20u, s);  // slots 40 .. 116
    if (s[0] != 0x820A74E0u || s[13] != 0x820A89F8u || s[17] != 0x820A8DD8u || s[19] != 0x820A9308u) return false;
  }
  REX_STORE_U8(spr + 86u, uint8_t(REX_LOAD_U8(spr + 86u) | 64u));
  CcFrame frame(ctx, base, 288u);
  const uint32_t r1 = ctx.r1.u32;
  // Corners with the state's current matrix (+8252 + 40 * [+9532]).
  uint32_t sv[4], mv[6], kw[29];
  const uint32_t m = st + REX_LOAD_U32(st + 9532u) * 40u + 8252u;
  cc_load_words(base, spr + 96u, 4u, sv);
  cc_load_words(base, m + 16u, 6u, mv);
  cc_load_words(base, 0x82042540u, 29u, kw);  // through the viewport words at 0x820425A8..B0
  ctx.fpscr.disableFlushMode();
  uint32_t c[4][3];
  cc_corners_words(sv, mv, kw, c);
  cc_sprite_frame_points(base, r1, c);
  // Mode-4 cull: all four x beyond the right (9648) or left (9644) edge, or
  // all four y below the bottom (9640) or above the top (9644 again).
  bool culled;
  {
    double x[4], y[4];
    for (int i = 0; i < 4; ++i) { x[i] = cc_f32d(c[i][0]); y[i] = cc_f32d(c[i][1]); }
    const double right = cc_f32d(kw[28]), left = cc_f32d(kw[27]), bottom = cc_f32d(kw[26]);
    auto all_gt = [](const double* v, double k) { return v[0] > k && v[1] > k && v[2] > k && v[3] > k; };
    auto all_lt = [](const double* v, double k) { return v[0] < k && v[1] < k && v[2] < k && v[3] < k; };
    culled = all_gt(x, right) || all_lt(x, left) || all_gt(y, bottom) || all_lt(y, left);
  }
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
  if (oracle) cc_sprite_fused_oracle(ctx, base, spr, m, rnd, c, culled);
#endif
  if (culled) { result = 1u; return true; }
  // Colour from the state's current colour (+(+10048 + 596) * 16), uv
  // extents from the texture (+60 / +68, +64 / +72).
  uint32_t cw[4], tw[4];
  cc_load_words(base, st + (REX_LOAD_U32(st + 10048u) + 596u) * 16u, 4u, cw);
  cc_load_words(base, tex + 60u, 4u, tw);
  auto chan = [](uint32_t w) { return uint32_t(cc_render_fctidz(cc_f32d(w))); };
  const uint32_t c1 = chan(cw[1]), c2 = chan(cw[2]), c3 = chan(cw[3]), c0 = chan(cw[0]);
  const uint32_t p1 = ((c0 << 8) & 0xFFFFFF00u) | c1;
  const uint32_t p2 = ((p1 << 8) & 0xFFFFFF00u) | c2;
  const uint32_t packed = ((p2 << 8) & 0xFFFFFF00u) | c3;
  const double fu = double(float(double(int64_t(tw[0])))) / double(float(double(int64_t(tw[2]))));
  const double fv = double(float(double(int64_t(tw[1])))) / double(float(double(int64_t(tw[3]))));
  const uint32_t u = cc_dbits(fu), v = cc_dbits(fv), zero = kw[0];
  cc_sprite_frame_quad(base, r1, zero, u, v, packed);
  // The bind and the quad run in the leaf's frame, as in the general path,
  // so their callees (the rasterizer of a texture's first bind, the 360 draw
  // on the host) build their frames at the same depth.
  ctx.r3.u64 = rnd; ctx.r4.u64 = tex; ctx.lr = 0x820857F4u;
  sub_820A89F8(ctx, base);
  result = 0u;
  // The quad (cc_quad_native with count 4: points already in screen space).
  if (REX_LOAD_U8(rnd + 28715u) == 0u) return true;
  const uint32_t ring = REX_LOAD_U32(0x82290000u - 22588u);  // vertex ring count (0x8228A7C4)
  if (int32_t(ring) >= 6000) return true;
  switch (REX_LOAD_U32(REX_LOAD_U32(rnd + (REX_LOAD_U32(rnd + 30208u) + 7544u) * 4u))) {
    case 0: case 1: case 3: case 5: case 7: case 8: case 9: case 12: case 16: break;
    case 2: case 6: case 10: case 11: case 14: case 15: cc_sprite_quad_guest(ctx, base, rnd); return true;
    default: return true;
  }
  const uint32_t z = REX_LOAD_U32(0x8201473Cu), colour = cc_quad_colour(packed);
  const uint32_t q[24] = {c[0][0], c[0][1], z, zero, zero, colour, c[1][0], c[1][1], z, u, zero, colour,
                          c[2][0], c[2][1], z, u, v, colour, c[3][0], c[3][1], z, zero, v, colour};
  REX_STORE_U32(0x82290000u - 22588u, ring + 4u);
#if defined(CC_XBOX_DRIVER) && !defined(CC_SPRITE_RING_BUILD)
  ::cc_xr_quad(q, REX_LOAD_U32(REX_LOAD_U32(rnd + 4u) + 10552u));  // device blend word
#else
  const uint32_t verts = 0x822673D8u + ring * 24u;
  cc_store_words(base, verts, 24u, q);
  ctx.r3.u64 = REX_LOAD_U32(rnd + 4u);
  ctx.r4.u64 = 13; ctx.r5.u64 = 4; ctx.r6.u64 = verts; ctx.r7.u64 = 24;
  ctx.lr = 0x820A9AD0u;
  sub_820C1980(ctx, base);
#endif
  return true;
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
  const uint32_t tex0 = REX_LOAD_U32(spr + 92u);
  uint32_t fused = 0u;
  if (tex0 != 0u && cc_sprite_fused_on() && cc_sprite_fused(ctx, base, spr, st, rnd, tex0, fused)) {
    if (fused == 1u) { ctx.r3.u64 = 1u; return; }
  } else if (tex0 != 0u) {
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
