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
// The packed colour and the uv extents are pure functions of the four
// colour words and the texture's four size words; the last sprite's are
// kept (consecutive sprites mostly repeat them). With CC_ORACLE=1 the host
// recomputes them on every hit and logs any difference.
static inline uint32_t cc_sprite_packed(const uint32_t cw[4]) {
  auto chan = [](uint32_t w) { return uint32_t(cc_render_fctidz(cc_f32d(w))); };
  const uint32_t c1 = chan(cw[1]), c2 = chan(cw[2]), c3 = chan(cw[3]), c0 = chan(cw[0]);
  const uint32_t p1 = ((c0 << 8) & 0xFFFFFF00u) | c1;
  const uint32_t p2 = ((p1 << 8) & 0xFFFFFF00u) | c2;
  return ((p2 << 8) & 0xFFFFFF00u) | c3;
}
static inline void cc_sprite_uv(const uint32_t tw[4], uint32_t uv[2]) {
  uv[0] = cc_dbits(double(float(double(int64_t(tw[0])))) / double(float(double(int64_t(tw[2])))));
  uv[1] = cc_dbits(double(float(double(int64_t(tw[1])))) / double(float(double(int64_t(tw[3])))));
}
struct CcSpriteMemo { uint32_t cw[4] = {}, packed = 0, tw[4] = {}, uv[2] = {}; bool has_c = false, has_t = false; };
static CcSpriteMemo g_sprite_memo;
static inline bool cc_same4(const uint32_t a[4], const uint32_t b[4]) {
  return ((a[0] ^ b[0]) | (a[1] ^ b[1]) | (a[2] ^ b[2]) | (a[3] ^ b[3])) == 0u;
}
// Renderer slots 40, 92, 108 and 116 of vtable vt are the game's own.
static inline bool cc_sprite_renderer_ok(Machine& base, uint32_t vt) {
  if (const uint8_t* p = cc_obj_host(vt + 40u, 80u))
    return cc_hb32(p) == 0x820A74E0u && cc_hb32(p + 52u) == 0x820A89F8u && cc_hb32(p + 68u) == 0x820A8DD8u &&
           cc_hb32(p + 76u) == 0x820A9308u;
  return REX_LOAD_U32(vt + 40u) == 0x820A74E0u && REX_LOAD_U32(vt + 92u) == 0x820A89F8u &&
         REX_LOAD_U32(vt + 108u) == 0x820A8DD8u && REX_LOAD_U32(vt + 116u) == 0x820A9308u;
}
// Returns false, having done nothing, when the renderer is not the game's
// own; else the leaf's result (1 culled, else 0) in `result`.
static CC_HOT_FN bool cc_sprite_fused(Context& ctx, Machine& base, uint32_t spr, uint32_t st, uint32_t rnd, uint32_t tex,
                                      uint32_t& result) {
  const uint32_t vt = REX_LOAD_U32(rnd);
  if (vt != 0x82042048u || !cc_sprite_renderer_ok(base, vt)) return false;
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
#endif
  REX_STORE_U8(spr + 86u, uint8_t(REX_LOAD_U8(spr + 86u) | 64u));
  CcFrame frame(ctx, base, 288u);
  const uint32_t r1 = ctx.r1.u32;
  // Corners with the state's current matrix (+8252 + 40 * [+9532]).
  // Constants from 0x82042540: zero +0, 0.05 +36, 0.01 +52, 2000 +56 (the
  // corners read kw[9], kw[13], kw[14]) and the viewport edges +104..+112.
  uint32_t sv[4], mv[6], kw[16], edge[3];
  const uint32_t m = st + REX_LOAD_U32(st + 9532u) * 40u + 8252u;
  cc_load_words(base, spr + 96u, 4u, sv);
  cc_load_words(base, m + 16u, 6u, mv);
  if (const uint8_t* p = cc_obj_host(0x82042540u, 116u)) {
    kw[0] = cc_hb32(p); kw[9] = cc_hb32(p + 36u); kw[13] = cc_hb32(p + 52u); kw[14] = cc_hb32(p + 56u);
    edge[0] = cc_hb32(p + 104u); edge[1] = cc_hb32(p + 108u); edge[2] = cc_hb32(p + 112u);
  } else {
    kw[0] = REX_LOAD_U32(0x82042540u); kw[9] = REX_LOAD_U32(0x82042564u); kw[13] = REX_LOAD_U32(0x82042574u);
    kw[14] = REX_LOAD_U32(0x82042578u);
    edge[0] = REX_LOAD_U32(0x820425A8u); edge[1] = REX_LOAD_U32(0x820425ACu); edge[2] = REX_LOAD_U32(0x820425B0u);
  }
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
    const double right = cc_f32d(edge[2]), left = cc_f32d(edge[1]), bottom = cc_f32d(edge[0]);
    auto all_gt = [](const double* v, double k) { return v[0] > k && v[1] > k && v[2] > k && v[3] > k; };
    auto all_lt = [](const double* v, double k) { return v[0] < k && v[1] < k && v[2] < k && v[3] < k; };
    culled = all_gt(x, right) || all_lt(x, left) || all_gt(y, bottom) || all_lt(y, left);
  }
#ifndef CC_XBOX_DRIVER
  if (oracle) cc_sprite_fused_oracle(ctx, base, spr, m, rnd, c, culled);
#endif
  if (culled) { result = 1u; return true; }
  // Colour from the state's current colour (+(+10048 + 596) * 16), uv
  // extents from the texture (+60 / +68, +64 / +72).
  uint32_t cw[4], tw[4];
  cc_load_words(base, st + (REX_LOAD_U32(st + 10048u) + 596u) * 16u, 4u, cw);
  cc_load_words(base, tex + 60u, 4u, tw);
  CcSpriteMemo& mm = g_sprite_memo;
  if (!mm.has_c || !cc_same4(cw, mm.cw)) {
    for (int i = 0; i < 4; ++i) mm.cw[i] = cw[i];
    mm.packed = cc_sprite_packed(cw);
    mm.has_c = true;
  }
#ifndef CC_XBOX_DRIVER
  else if (oracle && cc_sprite_packed(cw) != mm.packed) {
    cc_oracle_mismatch("sub_820855D8 colour memo", 0, cc_sprite_packed(cw), mm.packed);
  }
#endif
  if (!mm.has_t || !cc_same4(tw, mm.tw)) {
    for (int i = 0; i < 4; ++i) mm.tw[i] = tw[i];
    cc_sprite_uv(tw, mm.uv);
    mm.has_t = true;
  }
#ifndef CC_XBOX_DRIVER
  else if (oracle) {
    uint32_t e[2];
    cc_sprite_uv(tw, e);
    if (e[0] != mm.uv[0] || e[1] != mm.uv[1]) cc_oracle_mismatch("sub_820855D8 uv memo", 0, e[0] ^ e[1], mm.uv[0] ^ mm.uv[1]);
  }
#endif
  const uint32_t packed = mm.packed, u = mm.uv[0], v = mm.uv[1], zero = kw[0];
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
  const uint32_t material = REX_LOAD_U32(REX_LOAD_U32(rnd + (REX_LOAD_U32(rnd + 30208u) + 7544u) * 4u));
#ifdef CC_XBOX_DRIVER
  g_cc_renderer = rnd;
#endif
  switch (material) {
    case 0: case 1: case 3: case 5: case 7: case 8: case 9: case 12: case 16: break;
    case 2: case 6: case 10: case 11: case 14: case 15: cc_sprite_quad_guest(ctx, base, rnd); return true;
    default: return true;
  }
  const uint32_t z = REX_LOAD_U32(0x8201473Cu), colour = cc_quad_colour(packed);
  const uint32_t q[24] = {c[0][0], c[0][1], z, zero, zero, colour, c[1][0], c[1][1], z, u, zero, colour,
                          c[2][0], c[2][1], z, u, v, colour, c[3][0], c[3][1], z, zero, v, colour};
  REX_STORE_U32(0x82290000u - 22588u, ring + 4u);
#if defined(CC_XBOX_DRIVER) && !defined(CC_SPRITE_RING_BUILD)
  ::cc_xr_set_material(material);
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

// Rotated textured rectangle (renderer slot 112: exact sub_820A8FF8 and the
// sub_820A9068 it calls; the glyph loop sub_820A9E98 draws every glyph with
// it, angle 0). r3 renderer, r4 / r5 two opposite corners {x, y, z}, r10
// colour, f1..f4 u0 v0 u1 v1, f5 the angle; the caller's frame holds the
// vertex count at +100 and an aspect flag byte at +95.
// sub_820A8FF8 saves lr at r1-8 and r31 at r1-16, opens a 160-byte frame
// and writes the uv pairs (u0 v0) (u1 v0) (u1 v1) (u0 v1) at +112..+140 of
// it, the count at +100 and the flag at +95. sub_820A9068 opens a 352-byte
// frame below; when the renderer's draw flag (+28715) is set it rotates the
// rectangle about its centre c = (a + b) * 0.5 (0x82014748): with
// s = sin(angle), k = cos(angle) (sub_82127A08 / sub_82127AE8, rounded to
// float) and d a corner's offset from c, x = c.x + (d.x*k - d.y*s) and
// y = c.y + (d.y*k + d.x*s), each product and sum rounded to float and the
// second product fused as compiled; z = (a.z + b.z) * 0.5. Each y is then
// multiplied by the renderer's viewport aspect (slot 60: w / h of viewport
// [+29124]) when the flag is set, else by 1.0 (0x82042544). The corners go
// to +160 / +144 / +128 / +112 of the frame, the colour to +92, the count
// to +100 and the fourth uv pointer to +84, and slot 116 (the quad) draws
// them with the other uv pointers in r8..r10.
// Native: the same stores (both frames' words, slot 60's stack word) and
// calls (sin, cos, slot 116; slot 60 inline when it is sub_820A7488) from
// host values. Non-finite corners or angle take the exact body.
// Switches: host CC_GLYPH_EXACT=1, Xbox make GLYPHEXACT=1.
static inline bool cc_glyph_native_on() {
#if defined(CC_GLYPH_EXACT_BUILD)
  return false;
#elif defined(CC_XBOX_DRIVER)
  return true;
#else
  static const bool on = !std::getenv("CC_GLYPH_EXACT");
  return on;
#endif
}
// Corners (dx0, dy0), (dx1, dy0), (dx1, dy1), (dx0, dy1) rotated by (k, s),
// offsets from the centre.
template <bool Plain>
static inline __attribute__((always_inline)) void cc_glyph_rotate(const double dx[2], const double dy[2], double s, double k,
                                                                  double out[4][2]) {
  const double sy0 = cc_rf(dy[0] * s), sx0 = cc_rf(dx[0] * s), sx1 = cc_rf(dx[1] * s), sy1 = cc_rf(dy[1] * s);
  out[0][0] = cc_rf(cc_fmaf<Plain>(dx[0], k, -sy0)); out[0][1] = cc_rf(cc_fmaf<Plain>(dy[0], k, sx0));
  out[1][0] = cc_rf(cc_fmaf<Plain>(dx[1], k, -sy0)); out[1][1] = cc_rf(cc_fmaf<Plain>(dy[0], k, sx1));
  out[2][0] = cc_rf(cc_fmaf<Plain>(dx[1], k, -sy1)); out[2][1] = cc_rf(cc_fmaf<Plain>(dy[1], k, sx1));
  out[3][0] = cc_rf(cc_fmaf<Plain>(dx[0], k, -sy1)); out[3][1] = cc_rf(cc_fmaf<Plain>(dy[1], k, sx0));
}
#ifndef CC_XBOX_DRIVER
// Glyph-loop oracle (CC_ORACLE=1, see sub_820A9E98 below): the inputs of
// each glyph rectangle call, as the native loop computed them and as the
// exact loop passes them: r1, r3, r4, r5, r10, lr, r14..r31, f1..f5,
// f14..f31 and the frame words +100, +128..+152 and byte +95.
namespace cc_text_oracle {
struct Call { uint64_t g[24]; uint64_t f[23]; uint32_t w[9]; };
static_assert(offsetof(Context, r31) == offsetof(Context, r0) + 31u * sizeof(Register), "register layout");
static_assert(offsetof(Context, f31) == offsetof(Context, f0) + 31u * sizeof(Register), "register layout");
std::vector<Call> g_expect;
size_t g_seen = 0;
bool g_check = false;
inline void capture(Context& ctx, Machine& base, Call& c) {
  const Register* r = &ctx.r0;
  const Register* f = &ctx.f0;
  c.g[0] = ctx.r1.u64; c.g[1] = ctx.r3.u64; c.g[2] = ctx.r4.u64; c.g[3] = ctx.r5.u64; c.g[4] = ctx.r10.u64; c.g[5] = ctx.lr;
  for (int i = 14; i < 32; ++i) c.g[6 + i - 14] = r[i].u64;
  for (int i = 1; i < 6; ++i) c.f[i - 1] = f[i].u64;
  for (int i = 14; i < 32; ++i) c.f[5 + i - 14] = f[i].u64;
  const uint32_t r1 = ctx.r1.u32;
  c.w[0] = REX_LOAD_U32(r1 + 100u);
  for (uint32_t k = 0; k < 7u; ++k) c.w[1 + k] = REX_LOAD_U32(r1 + 128u + 4u * k);
  c.w[8] = REX_LOAD_U8(r1 + 95u);
}
// Called at the glyph rectangle's entry while the exact loop runs.
__attribute__((noinline)) void check(Context& ctx, Machine& base) {
  Call c;
  capture(ctx, base, c);
  const size_t k = g_seen++;
  if (k >= g_expect.size()) { cc_oracle_mismatch("sub_820A9E98 extra glyph call", int(k), 0u, uint32_t(g_expect.size())); return; }
  const Call& e = g_expect[k];
  for (int i = 0; i < 24; ++i)
    if (c.g[i] != e.g[i]) { cc_oracle_mismatch("sub_820A9E98 glyph call gpr", i, uint32_t(c.g[i]), uint32_t(e.g[i])); return; }
  for (int i = 0; i < 23; ++i)
    if (c.f[i] != e.f[i]) { cc_oracle_mismatch("sub_820A9E98 glyph call fpr", i, uint32_t(c.f[i] >> 32), uint32_t(e.f[i] >> 32)); return; }
  for (int i = 0; i < 9; ++i)
    if (c.w[i] != e.w[i]) { cc_oracle_mismatch("sub_820A9E98 glyph call frame", i, c.w[i], e.w[i]); return; }
}
}  // namespace cc_text_oracle
#endif
static CC_HOT_FN void sub_820A8FF8(Context& ctx, Machine& base) {
#ifndef CC_XBOX_DRIVER
  if (cc_text_oracle::g_check) cc_text_oracle::check(ctx, base);
#endif
  CC_AS_SWITCH(sub_820A8FF8);
  uint32_t aw[3], bw[3];
  cc_load_words(base, ctx.r4.u32, 3u, aw);
  cc_load_words(base, ctx.r5.u32, 3u, bw);
  const double angle = ctx.f5.f64;
  const bool finite = std::isfinite(angle) && cc_finite_bits(aw[0]) && cc_finite_bits(aw[1]) && cc_finite_bits(aw[2]) &&
                      cc_finite_bits(bw[0]) && cc_finite_bits(bw[1]) && cc_finite_bits(bw[2]);
  if (!cc_glyph_native_on() || !finite) {
    sub_820A8FF8_exact(ctx, base);
    return;
  }
  ctx.fpscr.disableFlushMode();
  const uint32_t rnd = ctx.r3.u32, colour = ctx.r10.u32, r0 = ctx.r1.u32;
  const uint32_t lr0 = uint32_t(ctx.lr);
  // sub_820A8FF8's frame.
  REX_STORE_U32(r0 - 8u, lr0);
  REX_STORE_U64(r0 - 16u, ctx.r31.u64);
  const uint32_t r1 = r0 - 160u;
  REX_STORE_U32(r1, r0);
  const uint32_t count = REX_LOAD_U32(r1 + 260u);
  const uint8_t flag = REX_LOAD_U8(r1 + 255u);
  {
    const uint32_t u0 = cc_dbits(ctx.f1.f64), v0 = cc_dbits(ctx.f2.f64), u1 = cc_dbits(ctx.f3.f64), v1 = cc_dbits(ctx.f4.f64);
    const uint32_t uv[8] = {u0, v0, u1, v0, u1, v1, u0, v1};
    cc_store_words(base, r1 + 112u, 8u, uv);
    REX_STORE_U32(r1 + 100u, count);
    REX_STORE_U8(r1 + 95u, flag);
  }
  // sub_820A9068's frame.
  const uint32_t r2 = r1 - 352u;
  REX_STORE_U32(r2, r1);
  if (REX_LOAD_U8(rnd + 28715u) != 0u) {
    const double half = cc_f32d(REX_LOAD_U32(0x82014748u));
    const double ax = cc_f32d(aw[0]), ay = cc_f32d(aw[1]), az = cc_f32d(aw[2]);
    const double bx = cc_f32d(bw[0]), by = cc_f32d(bw[1]), bz = cc_f32d(bw[2]);
    const double cx = cc_rf(cc_rf(bx + ax) * half), cy = cc_rf(cc_rf(by + ay) * half);
    const uint32_t z = cc_dbits(cc_rf(cc_rf(az + bz) * half));
    const double dx[2] = {cc_rf(ax - cx), cc_rf(bx - cx)}, dy[2] = {cc_rf(ay - cy), cc_rf(by - cy)};
    ctx.r1.u64 = r2;
    ctx.f1.f64 = angle; ctx.lr = 0x820A9148u;
    sub_82127A08(ctx, base);
    const double s = cc_rf(ctx.f1.f64);
    ctx.f1.f64 = angle; ctx.lr = 0x820A9154u;
    sub_82127AE8(ctx, base);
    const double k = cc_rf(ctx.f1.f64);
    ctx.fpscr.disableFlushMode();
    double rot[4][2];
    if (cc_plain_fma()) {
      cc_glyph_rotate<true>(dx, dy, s, k, rot);
      bool fin = true;
      for (int i = 0; i < 4; ++i) fin = fin && std::isfinite(rot[i][0]) && std::isfinite(rot[i][1]);
      if (!fin) cc_glyph_rotate<false>(dx, dy, s, k, rot);
    } else {
      cc_glyph_rotate<false>(dx, dy, s, k, rot);
    }
    // Corner i at +160 - 16 i: {x, y, z}.
    uint32_t pt[4][3];
    double y[4];
    for (int i = 0; i < 4; ++i) {
      pt[i][0] = cc_dbits(rot[i][0] + cx);
      y[i] = cc_rf(rot[i][1] + cy);
      pt[i][1] = cc_dbits(y[i]);
      pt[i][2] = z;
    }
    auto put_corners = [&]() {
      for (uint32_t i = 0; i < 4u; ++i) cc_store_words(base, r2 + 160u - 16u * i, 3u, pt[i]);
    };
    // Aspect: slot 60 once per y, in corner order.
    const double one = cc_f32d(REX_LOAD_U32(0x82042544u));
    for (uint32_t i = 0; i < 4u; ++i) {
      double ratio = one;
      if (flag != 0u) {
        const uint32_t fn = REX_LOAD_U32(REX_LOAD_U32(rnd) + 60u);
        if (fn == 0x820A7488u) {
          const uint32_t idx = REX_LOAD_U32(rnd + 29124u);
          const uint32_t w = REX_LOAD_U32(rnd + idx * 24u + 28748u), h = REX_LOAD_U32(rnd + idx * 24u + 28752u);
          REX_STORE_U64(r2 - 16u, uint64_t(h));  // sub_820A7488's conversion word (its last store)
          ratio = cc_rf(cc_rf(double(int64_t(w))) / cc_rf(double(int64_t(h))));
        } else {
          put_corners();  // the frame as the exact body has it at this call
          ctx.r3.u64 = rnd; ctx.lr = 0x820A9210u + 0x30u * i;
          REX_CALL_INDIRECT_FUNC(fn);
          ratio = ctx.f1.f64;
        }
      }
      y[i] = cc_rf(ratio * y[i]);
      pt[i][1] = cc_dbits(y[i]);
    }
    put_corners();
    REX_STORE_U32(r2 + 92u, colour);
    REX_STORE_U32(r2 + 84u, r1 + 136u);
    REX_STORE_U32(r2 + 100u, count);
    ctx.r3.u64 = rnd; ctx.r4.u64 = r2 + 160u; ctx.r5.u64 = r2 + 144u; ctx.r6.u64 = r2 + 128u; ctx.r7.u64 = r2 + 112u;
    ctx.r8.u64 = r1 + 112u; ctx.r9.u64 = r1 + 120u; ctx.r10.u64 = r1 + 128u; ctx.lr = 0x820A92F4u;
    const uint32_t quad = REX_LOAD_U32(REX_LOAD_U32(rnd) + 116u);
    if (quad == 0x820A9308u) sub_820A9308(ctx, base);
    else REX_CALL_INDIRECT_FUNC(quad);
  }
  ctx.r1.u64 = r0;
  ctx.r12.u64 = lr0;
  ctx.lr = lr0;
}

// Text switches: host CC_TEXT_EXACT=1 (the recompiled glyph loop and string
// measure; CC_EXACT_FNS=sub_820A9E98 / sub_820A9D78 select one), Xbox make
// TEXTEXACT=1.
static inline bool cc_text_native_on() {
#if defined(CC_TEXT_EXACT_BUILD)
  return false;
#elif defined(CC_XBOX_DRIVER)
  return true;
#else
  static const bool on = !std::getenv("CC_TEXT_EXACT");
  return on;
#endif
}
// a*b + c rounded once, a a float: plain in double when b is a float too
// (b_float) and the result is finite, else the checked fma.
static inline __attribute__((always_inline)) double cc_text_fma(bool b_float, double a, double b, double c) {
  if (b_float) {
    const double v = a * b + c;
    if (__builtin_expect(__builtin_isfinite(v), 1)) return v;
  }
  return std::fma(a, b, c);
}

// String measure (exact sub_820A9D78: font r3, UTF-16 string r4, outputs r5
// and r6 (floats), x scale f1, y scale f2; returns 0 when the font is not
// ready (u8 +0 clear), the string is null or the font has no glyph header
// (+108), else 1). The line height h = [+108]+4 * f2 + 1.0 (0x82042544,
// fused) is the first line's bottom; *r5 and *r6 start at 0.0 (0x82042540).
// For each character before the terminating 0: a newline (10) sets the pen
// back to 0.0 and adds h to the line bottom; a character whose glyph entry
// e = [+116] + 16 * u16 [+112][c] is not null advances the pen by its s16
// widths e.8 and e.12, each times f1 and fused, then raises *r5 to the pen
// and *r6 to the line bottom when they are larger. The widths pass through
// the stack words r1-16 / r1-8 (their last values stay there).
// Native: the same guest reads and stores in the same order (outputs that
// alias the inputs behave the same); a multiply-add is plain when its
// operands are floats and its result finite, else the checked fma.
// With CC_ORACLE=1 the host runs the native measure, puts the four words
// back, runs the exact body and logs any difference.
static CC_HOT_FN void cc_text_measure(Context& ctx, Machine& base) {
  const uint32_t font = ctx.r3.u32, str = ctx.r4.u32, o5 = ctx.r5.u32, o6 = ctx.r6.u32;
  if (REX_LOAD_U8(font + 0u) == 0u || str == 0u) { ctx.r3.u64 = 0u; return; }
  const uint32_t hdr = REX_LOAD_U32(font + 108u);
  if (hdr == 0u) { ctx.r3.u64 = 0u; return; }
  ctx.fpscr.disableFlushMode();
  const double sx = ctx.f1.f64, sy = ctx.f2.f64;
  const bool plain = cc_plain_fma();
  const bool fx = plain && double(float(sx)) == sx, fy = plain && double(float(sy)) == sy;
  const double lh = cc_f32d(REX_LOAD_U32(hdr + 4u));
  const uint32_t c0 = REX_LOAD_U16(str);
  const double h = cc_rf(cc_text_fma(fy, lh, sy, cc_f32d(REX_LOAD_U32(0x82042544u))));
  const double zero = cc_f32d(REX_LOAD_U32(0x82042540u));
  REX_STORE_U32(o5, cc_dbits(zero));
  REX_STORE_U32(o6, cc_dbits(zero));
  uint32_t end = str;
  if (c0 != 0u) do end += 2u; while (REX_LOAD_U16(end) != 0u);
  double pen = zero, bottom = h;
  for (uint32_t p = str; p < end; p += 2u) {
    const uint32_t c = REX_LOAD_U16(p);
    if (c == 10u) { pen = zero; bottom = cc_rf(h + bottom); continue; }
    const uint32_t tbl = REX_LOAD_U32(font + 112u), first = REX_LOAD_U32(font + 116u);
    const uint32_t e = (uint32_t(REX_LOAD_U16(c * 2u + tbl)) << 4) + first;
    if (e == 0u) continue;
    const int64_t w12 = int16_t(REX_LOAD_U16(e + 12u));
    const double cur = cc_f32d(REX_LOAD_U32(o5));
    const int64_t w8 = int16_t(REX_LOAD_U16(e + 8u));
    REX_STORE_U64(ctx.r1.u32 - 16u, uint64_t(w12));
    REX_STORE_U64(ctx.r1.u32 - 8u, uint64_t(w8));
    const double x = cc_rf(cc_text_fma(fx, cc_rf(double(w8)), sx, pen));
    pen = cc_rf(cc_text_fma(fx, cc_rf(double(w12)), sx, x));
    if (pen > cur) REX_STORE_U32(o5, cc_dbits(pen));
    if (bottom > cc_f32d(REX_LOAD_U32(o6))) REX_STORE_U32(o6, cc_dbits(bottom));
  }
  ctx.r3.u64 = 1u;
}
static CC_HOT_FN void sub_820A9D78(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_820A9D78);
  CC_FPROF_SCOPE(sub_820A9D78_native);
  if (!cc_text_native_on()) { sub_820A9D78_exact(ctx, base); return; }
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
  if (oracle && REX_LOAD_U8(ctx.r3.u32) != 0u && ctx.r4.u32 != 0u && REX_LOAD_U32(ctx.r3.u32 + 108u) != 0u) {
    const uint32_t o5 = ctx.r5.u32, o6 = ctx.r6.u32, r1 = ctx.r1.u32;
    auto snap = [&](uint32_t w[6]) {
      w[0] = REX_LOAD_U32(o5); w[1] = REX_LOAD_U32(o6);
      for (uint32_t k = 0; k < 4u; ++k) w[2 + k] = REX_LOAD_U32(r1 - 16u + 4u * k);
    };
    uint32_t before[6], nat[6], ex[6];
    snap(before);
    const Context in = ctx;
    cc_text_measure(ctx, base);
    const uint32_t rn = ctx.r3.u32;
    snap(nat);
    for (uint32_t k = 0; k < 4u; ++k) REX_STORE_U32(r1 - 16u + 4u * k, before[2 + k]);
    REX_STORE_U32(o6, before[1]);
    REX_STORE_U32(o5, before[0]);
    ctx = in;
    sub_820A9D78_exact(ctx, base);
    snap(ex);
    if (ctx.r3.u32 != rn) cc_oracle_mismatch("sub_820A9D78 result", 0, ctx.r3.u32, rn);
    for (int k = 0; k < 6; ++k)
      if (ex[k] != nat[k]) cc_oracle_mismatch("sub_820A9D78", k, ex[k], nat[k]);
    return;
  }
#endif
  cc_text_measure(ctx, base);
}

// Text glyph loop (exact sub_820A9E98: font r3, renderer r4, colour r7,
// UTF-16 string r8, position f1 f2, scale f3 f4, alignment word [r1+84]:
// 0 ends each line at x, 2 centres it on x, else it starts at x). It opens
// a 560-byte frame and returns 0 when the font has no glyph header (+108),
// the string is null or the font is not ready (u8 +0), else 1.
// With the game's renderer (vtable 0x82042048) the renderer slots it calls
// do this: 32 / 36 push / pop a state (return buffer frame+176, mode 5);
// 92 binds the font's texture (font+12); 72 gives z = [0x8201473C]; 100
// writes the scale s = 1.0 to frame+156 / +160; 44 writes the viewport size
// w, h ([rnd+28720], [rnd+28724]) to frame+196 / +164 when the draw flag
// (+28715) is set (else those words keep what they held); 68 (y up) answers
// 0, 76 (normalised) 1; 80 writes 1/w, 1/h to frame+172 / +168 (its
// conversion word at r1-16); 112 draws a glyph (sub_820A8FF8).
// Layout (each step rounded to float as compiled; 0.5 = [0x82014748],
// 1.0 = [0x82042544]): origin ox = (x*s/w - 0.5) / s, oy = (1 - (h - y*s)/h
// - 0.5) / s; kx = f3 / w, ky = f4 / h. The string is measured
// (sub_820A9D78 into frame+120 width / +112 height) and the first baseline
// is floor(height * [0x820425D0]) (sub_82129038). At a line start the pen
// is ox, or with alignment 0 / 2 floor(ox - width) / floor(ox - width * 0.5)
// (a fresh measure, outputs swapped). A newline moves the baseline by the
// font's line height ([+108]+4) and starts a new line. A character with a
// glyph entry e ([+116] + 16 * u16 [+112][c], not null) has left edge
// l = pen + e.8, moves the pen to l + e.12 and, unless it is a space (32),
// is drawn as the rectangle (l - 0.5, baseline - 0.5) .. (l - 0.5 + e.10 +
// 1, baseline - 0.5 + height - 1), mapped by kx / ky and the origin, with
// uvs (e.0, e.2) .. (e.4, e.6) over the texture size (+28, +32), z, the
// colour, angle 0.0 and frame+100 = 1, +95 = 0. The conversion words of
// each glyph go to frame+176 and +248..+304.
// The play build runs the recompiled body on the register view (bridge.cpp):
// its callee-saved registers are locals, the register save helpers do
// nothing, so callees see the Context's callee-saved registers as they were
// at entry; on return r12 = r1 - 104 and lr is the last return address set.
// Native (game renderer only): the same guest stores and calls, with the
// argument registers the exact body passes and the Context's callee-saved
// registers untouched; slots 44, 68, 72, 76, 80 and 100 are answered
// inline, the others called directly; stores the exact body overwrites
// before anything reads them are made once. Another renderer, or a frame
// across a host page, takes the exact body.
// With CC_ORACLE=1 the host first runs the native loop without its calls
// (push, bind, glyphs, pop), recording each glyph call's registers and
// frame words, then runs the exact body: each glyph call is checked against
// the record, and afterwards the result, r1, r12, lr, the callee-saved
// registers and the frame (except the push / pop return buffer) are
// compared.
namespace cc_text {
// Renderer slots 32..112 the loop calls, and the game's own methods there.
inline bool renderer_ok(Machine& base, uint32_t rnd) {
  const uint32_t vt = REX_LOAD_U32(rnd);
  if (vt != 0x82042048u) return false;
  static const uint32_t want[21] = {
      0x820A8038u, 0x820A8100u, 0u, 0x820A86B0u, 0u, 0u, 0u, 0u, 0u, 0x82053A98u, 0x820A74F8u,  // 32..72
      0x820619E8u, 0x820A7508u, 0u, 0u, 0x820A89F8u, 0u, 0x820A75C8u, 0u, 0u, 0x820A8FF8u};   // 76..112
  const uint8_t* p = cc_obj_host(vt + 32u, 84u);
  for (uint32_t k = 0; k < 21u; ++k) {
    if (want[k] == 0u) continue;
    const uint32_t fn = p ? cc_hb32(p + 4u * k) : REX_LOAD_U32(vt + 32u + 4u * k);
    if (fn != want[k]) return false;
  }
  return true;
}
// The loop's frame: host address of frame+0, valid from -16 to +560.
struct Frame {
  uint8_t* p;
  void put(int32_t off, uint32_t v) const { cc_hput32(p + off, v); }
  void put64(int32_t off, uint64_t v) const { cc_hput32(p + off, uint32_t(v >> 32)); cc_hput32(p + off + 4, uint32_t(v)); }
  uint32_t get(int32_t off) const { return cc_hb32(p + off); }
};
// Returns false, having done nothing, for another renderer or a frame that
// is not in one host page; else runs the loop. Record = true (host oracle)
// skips the push, bind, glyph and pop calls and records each glyph call.
template <bool Record>
static CC_HOT_FN bool glyphs(Context& ctx, Machine& base) {
  const uint32_t R = ctx.r1.u32, F = R - 560u, rnd = ctx.r4.u32;
  uint8_t* hp = cc_obj_host(F - 16u, 576u);
  if (!hp || !renderer_ok(base, rnd)) return false;
  const Frame fr{hp + 16};
  const uint64_t r1_entry = ctx.r1.u64;
  fr.put(0, R);
  ctx.r1.u32 = F;
  ctx.fpscr.disableFlushMode();
  const uint32_t font = ctx.r3.u32;
  const uint64_t font64 = ctx.r3.u64, rnd64 = ctx.r4.u64, colour64 = ctx.r7.u64, str64 = ctx.r8.u64;
  const double x = ctx.f1.f64, y = ctx.f2.f64, sx = ctx.f3.f64, sy = ctx.f4.f64;
  uint32_t result = 0u;
  if (REX_LOAD_U32(font + 108u) != 0u && uint32_t(str64) != 0u && REX_LOAD_U8(font + 0u) != 0u) {
    result = 1u;
    // Slot 32: push a state (mode 5); slot 92: bind the font's texture.
    ctx.r5.s64 = 5; ctx.r3.s64 = ctx.r1.s64 + 176; ctx.lr = 0x820A9F04u;
    if constexpr (!Record) sub_820A8038(ctx, base);
    ctx.r4.u64 = font64 + 12u; ctx.r3.u64 = rnd64; ctx.lr = 0x820A9F1Cu;
    if constexpr (!Record) sub_820A89F8(ctx, base);
    ctx.fpscr.disableFlushMode();
    // Slot 72: z; slot 100: the scale 1.0 twice.
    const double z = cc_f32d(REX_LOAD_U32(0x8201473Cu));
    {
      const uint32_t s = cc_dbits(cc_f32d(REX_LOAD_U32(0x82042544u)));
      fr.put(156, s); fr.put(160, s);
    }
    double ox = cc_rf(cc_f32d(fr.get(156)) * x);
    double ty = cc_rf(cc_f32d(fr.get(160)) * y);
    // Slot 44: the viewport size while the draw flag is set.
    if (REX_LOAD_U8(rnd + 28715u) != 0u) {
      fr.put(196, REX_LOAD_U32(rnd + 28720u));
      fr.put(164, REX_LOAD_U32(rnd + 28724u));
    }
    // Slot 68 answers 0 (y = h - y), slot 76 answers 1 (normalised origin).
    ty = cc_rf(cc_rf(double(int64_t(fr.get(164)))) - ty);
    const double half = cc_f32d(REX_LOAD_U32(0x82014748u)), one = cc_f32d(REX_LOAD_U32(0x82042544u));
    double oy;
    {
      const uint32_t w = fr.get(196), h = fr.get(164);
      const double s0 = cc_f32d(fr.get(156)), s1 = cc_f32d(fr.get(160));
      fr.put64(120, h);  // the last of the three conversion words there
      const double fh = cc_rf(double(int64_t(h))), fw = cc_rf(double(int64_t(w)));
      const double ny = cc_rf(ty / fh), nx = cc_rf(ox / fw);
      const double f4 = cc_rf(one - ny), f3 = cc_rf(nx - half), f2 = cc_rf(f4 - half);
      ox = cc_rf(f3 / s0);
      oy = cc_rf(f2 / s1);
    }
    // Slot 80: 1/w and 1/h (its conversion word at r1-16 ends as h), then
    // times the scale arguments.
    double kx, ky;
    {
      const double k1 = cc_f32d(REX_LOAD_U32(0x82042544u));
      const uint32_t w = REX_LOAD_U32(rnd + 28720u);
      fr.put(172, cc_dbits(k1 / cc_rf(double(int64_t(w)))));
      const uint32_t h = REX_LOAD_U32(rnd + 28724u);
      fr.put64(-16, h);
      fr.put(168, cc_dbits(k1 / cc_rf(double(int64_t(h)))));
      kx = cc_rf(cc_f32d(fr.get(172)) * sx);
      ky = cc_rf(cc_f32d(fr.get(168)) * sy);
      fr.put(172, cc_dbits(kx));
      fr.put(168, cc_dbits(ky));
    }
    const double zero = cc_f32d(REX_LOAD_U32(0x82042540u));
    double pen = zero;
    // Measure (width +120, height +112) and the first baseline.
    ctx.r9.s64 = 0; ctx.f2.f64 = one; ctx.r6.s64 = ctx.r1.s64 + 112; ctx.f1.f64 = one;
    ctx.r5.s64 = ctx.r1.s64 + 120; ctx.r4.u64 = str64; ctx.r3.u64 = font64; ctx.lr = 0x820AA0A0u;
    sub_820A9D78(ctx, base);
    ctx.fpscr.disableFlushMode();
    ctx.f1.f64 = cc_rf(cc_f32d(fr.get(112)) * cc_f32d(REX_LOAD_U32(0x820425D0u)));
    ctx.lr = 0x820AA0B4u;
    sub_82129038(ctx, base);
    ctx.fpscr.disableFlushMode();
    double baseline = cc_rf(ctx.f1.f64);
    uint32_t end = uint32_t(str64);
    if (REX_LOAD_U16(end + 0u) != 0u) do end += 2u; while (REX_LOAD_U16(end + 0u) != 0u);
    if (uint32_t(str64) < end) {
      const uint32_t align = REX_LOAD_U32(ctx.r1.u32 + 644u);  // the caller's frame +84
      bool line_start = true;
      for (uint32_t p = uint32_t(str64); p < end; p += 2u) {
        if (line_start) {
          // Right or centre alignment measures again.
          if (align == 0u || align == 2u) {
            ctx.r9.s64 = 0; ctx.f2.f64 = one; ctx.r6.s64 = ctx.r1.s64 + 120; ctx.f1.f64 = one;
            ctx.r5.s64 = ctx.r1.s64 + 112; ctx.r4.u64 = str64; ctx.r3.u64 = font64; ctx.lr = 0x820AA130u;
            sub_820A9D78(ctx, base);
            ctx.fpscr.disableFlushMode();
            const double wd = cc_f32d(fr.get(112));
            ctx.f1.f64 = align == 0u ? cc_rf(ox - wd) : cc_rf(-std::fma(wd, half, -ox));
            ctx.lr = 0x820AA158u;
            sub_82129038(ctx, base);
            ctx.fpscr.disableFlushMode();
            pen = cc_rf(ctx.f1.f64);
          }
          line_start = false;
        }
        const uint32_t c = REX_LOAD_U16(p + 0u);
        if (c == 10u) {
          // Newline (slot 68 answers 0: the baseline moves down).
          pen = ox;
          baseline = cc_rf(cc_f32d(REX_LOAD_U32(REX_LOAD_U32(font + 108u) + 4u)) + baseline);
          line_start = true;
          continue;
        }
        const uint32_t tbl = REX_LOAD_U32(font + 112u), first = REX_LOAD_U32(font + 116u);
        const uint32_t e = (uint32_t(REX_LOAD_U16((c << 1) + tbl)) << 4) + first;
        if (e == 0u) continue;
        const uint8_t* ep = cc_obj_host(e, 14u);
        auto e16 = [&](uint32_t off) -> uint32_t { return ep ? cc_hb16(ep + off) : REX_LOAD_U16(e + off); };
        const double top = cc_rf(baseline - half);
        const int64_t a10 = int16_t(e16(10u)), a8 = int16_t(e16(8u));
        fr.put64(264, uint64_t(a10));
        fr.put64(280, uint64_t(a8));
        const double left = cc_rf(cc_rf(double(a8)) + pen);
        const double x0 = cc_rf(left - half);
        const double x1 = cc_rf(cc_rf(cc_rf(double(a10)) + one) + x0);
        const double y1 = cc_rf(cc_rf(cc_f32d(REX_LOAD_U32(REX_LOAD_U32(font + 108u) + 4u)) - one) + top);
        const int64_t a12 = int16_t(e16(12u));
        fr.put64(296, uint64_t(a12));
        pen = cc_rf(cc_rf(double(a12)) + left);
        if (c == 32u) continue;
        const uint32_t u1 = e16(4u), v0 = e16(2u), u0 = e16(0u), v1 = e16(6u);
        const uint32_t tw = REX_LOAD_U32(font + 28u), th = REX_LOAD_U32(font + 32u);
        fr.put64(272, u1); fr.put64(248, tw); fr.put64(304, v0); fr.put64(288, th); fr.put64(256, u0); fr.put64(176, v1);
        const double fw = cc_rf(double(int64_t(tw))), fh = cc_rf(double(int64_t(th)));
        // Corners {x, y, z} at +128 and +144 (and their staging words
        // +184..+208) for slot 112.
        const uint32_t zb = cc_dbits(z);
        const uint32_t ay = cc_dbits(cc_rf(ky * top) + oy);
        const uint32_t bx = cc_dbits(cc_rf(kx * x1) + ox);
        const uint32_t ax = cc_dbits(cc_rf(kx * x0) + ox);
        const uint32_t by = cc_dbits(cc_rf(ky * y1) + oy);
        fr.put(184, ax); fr.put(188, ay); fr.put(192, zb); fr.put(200, bx); fr.put(204, by); fr.put(208, zb);
        fr.put(128, ax); fr.put(132, ay); fr.put(136, zb); fr.put(144, bx); fr.put(148, by); fr.put(152, zb);
        fr.put(100, 1u);
        fr.p[95] = 0u;
        ctx.f5.f64 = zero; ctx.r10.u64 = colour64;
        ctx.f4.f64 = cc_rf(cc_rf(double(int64_t(v1))) / fh);
        ctx.f3.f64 = cc_rf(cc_rf(double(int64_t(u1))) / fw);
        ctx.f1.f64 = cc_rf(cc_rf(double(int64_t(u0))) / fw);
        ctx.f2.f64 = cc_rf(cc_rf(double(int64_t(v0))) / fh);
        ctx.r5.s64 = ctx.r1.s64 + 144; ctx.r4.s64 = ctx.r1.s64 + 128; ctx.r3.u64 = rnd64; ctx.lr = 0x820AA43Cu;
        if constexpr (Record) {
#ifndef CC_XBOX_DRIVER
          cc_text_oracle::Call k;
          cc_text_oracle::capture(ctx, base, k);
          cc_text_oracle::g_expect.push_back(k);
#endif
        } else {
          sub_820A8FF8(ctx, base);
          ctx.fpscr.disableFlushMode();
        }
      }
    }
    // Slot 36: pop the state.
    ctx.r4.u64 = rnd64; ctx.r3.s64 = ctx.r1.s64 + 176; ctx.lr = 0x820AA460u;
    if constexpr (!Record) sub_820A8100(ctx, base);
  }
  ctx.r1.u64 = r1_entry;
  ctx.r12.s64 = ctx.r1.s64 - 104;
  ctx.lr = result ? 0x820AA470u : 0x820AA484u;
  ctx.r3.u64 = result;
  return true;
}
#ifndef CC_XBOX_DRIVER
// Oracle run (CC_ORACLE=1): the native loop without its calls, then the
// exact body (whose effects stay), compared as described above.
__attribute__((noinline)) void oracle_run(Context& ctx, Machine& base) {
  using namespace cc_text_oracle;
  const Context in = ctx;
  const uint32_t F = ctx.r1.u32 - 560u;
  g_expect.clear();
  if (!glyphs<true>(ctx, base)) { ctx = in; sub_820A9E98_exact(ctx, base); return; }
  const Context nat = ctx;
  uint32_t fw[140];
  for (uint32_t k = 0; k < 140u; ++k) fw[k] = REX_LOAD_U32(F + 4u * k);
  ctx = in;
  g_seen = 0; g_check = true;
  sub_820A9E98_exact(ctx, base);
  g_check = false;
  if (g_seen != g_expect.size()) cc_oracle_mismatch("sub_820A9E98 glyph calls", 0, uint32_t(g_seen), uint32_t(g_expect.size()));
  if (ctx.r3.u32 != nat.r3.u32) cc_oracle_mismatch("sub_820A9E98 result", 0, ctx.r3.u32, nat.r3.u32);
  if (ctx.r1.u64 != nat.r1.u64) cc_oracle_mismatch("sub_820A9E98 r1", 0, ctx.r1.u32, nat.r1.u32);
  if (ctx.r12.u64 != nat.r12.u64) cc_oracle_mismatch("sub_820A9E98 r12", 0, ctx.r12.u32, nat.r12.u32);
  if (ctx.lr != nat.lr) cc_oracle_mismatch("sub_820A9E98 lr", 0, uint32_t(ctx.lr), uint32_t(nat.lr));
  const Register* er = &ctx.r0; const Register* nr = &nat.r0;
  const Register* ef = &ctx.f0; const Register* nf = &nat.f0;
  for (int i = 14; i < 32; ++i) {
    if (er[i].u64 != nr[i].u64) cc_oracle_mismatch("sub_820A9E98 gpr", i, uint32_t(er[i].u64), uint32_t(nr[i].u64));
    if (ef[i].u64 != nf[i].u64) cc_oracle_mismatch("sub_820A9E98 fpr", i, uint32_t(ef[i].u64 >> 32), uint32_t(nf[i].u64 >> 32));
  }
  for (uint32_t k = 0; k < 140u; ++k) {
    if (k == 44u || k == 45u) continue;  // +176: the push / pop return buffer
    const uint32_t e = REX_LOAD_U32(F + 4u * k);
    if (e != fw[k]) cc_oracle_mismatch("sub_820A9E98 frame", int(4u * k), e, fw[k]);
  }
}
#endif
}  // namespace cc_text
static CC_HOT_FN void sub_820A9E98(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_820A9E98);
  CC_FPROF_SCOPE(sub_820A9E98_native);
  if (!cc_text_native_on()) { sub_820A9E98_exact(ctx, base); return; }
#ifndef CC_XBOX_DRIVER
  static const bool oracle = std::getenv("CC_ORACLE") != nullptr;
  if (oracle) { cc_text::oracle_run(ctx, base); return; }
#endif
  if (!cc_text::glyphs<false>(ctx, base)) sub_820A9E98_exact(ctx, base);
}
