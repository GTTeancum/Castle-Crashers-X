// Native member-map insert (included by as_ops_more.inc after as_ops_var.inc).

// Member map insert (exact sub_820936B0: map r3 = {u32 n, entries* +4, u32
// capacity +8, u32 growth +12}, id r4, value r5). n is incremented; past the
// capacity the array grows by the growth step (bytes = capacity * 8, or
// 0xFFFFFFFF past 0x1FFFFFFF entries) from the game heap, the old entries
// copied (u16 id, u32 value) and the old array freed. Then one insertion
// pass over the n old entries carries (id, value) past every entry with a
// greater id (swapping), and the carried pair lands in entry n. Only the
// u16 id and the value of each 8-byte entry are written.
static CC_HOT_FN void sub_820936B0(Context& ctx, Machine& base) {
  CC_AS_SWITCH(sub_820936B0);
  CC_FPROF_SCOPE(sub_820936B0_native);
  const uint32_t map = ctx.r3.u32;
  uint32_t id = ctx.r4.u32, val = ctx.r5.u32;
  const uint32_t n = REX_LOAD_U32(map + 0u), cap = REX_LOAD_U32(map + 8u);
  REX_STORE_U32(map + 0u, n + 1u);
  if (n + 1u > cap) {
    const uint32_t old = REX_LOAD_U32(map + 4u);
    const uint32_t ncap = REX_LOAD_U32(map + 12u) + cap;
    REX_STORE_U32(map + 8u, ncap);
    const uint32_t bytes = ncap > 0x1FFFFFFFu ? 0xFFFFFFFFu : ((ncap << 3) & 0xFFFFFFF8u);
    ctx.r3.u64 = cc_as_game_heap(ctx, base, 0x82093734u, 0x82093738u);
    ctx.r4.u64 = bytes; ctx.lr = 0x82093754u;
    sub_8209BDD8(ctx, base);
    REX_STORE_U32(map + 4u, ctx.r3.u32);
    if (old != 0u) {
      for (uint32_t k = 0; k < cap; ++k) {
        REX_STORE_U16(REX_LOAD_U32(map + 4u) + k * 8u, REX_LOAD_U16(old + k * 8u));
        REX_STORE_U32(REX_LOAD_U32(map + 4u) + k * 8u + 4u, REX_LOAD_U32(old + k * 8u + 4u));
      }
      const uint32_t heap = cc_as_game_heap(ctx, base, 0x820937B8u, 0x820937BCu);
      ctx.r3.u64 = heap; ctx.r4.u64 = old; ctx.lr = 0x820937CCu;
      sub_8209BF18(ctx, base);
    }
  }
  for (uint32_t k = 0; k < n; ++k) {
    const uint32_t e = REX_LOAD_U32(map + 4u) + k * 8u;
    const uint32_t eid = REX_LOAD_U16(e);
    if (eid > (id & 0xFFFFu)) {
      REX_STORE_U16(e, uint16_t(id));
      const uint32_t e2 = REX_LOAD_U32(map + 4u) + k * 8u;
      const uint32_t ov = REX_LOAD_U32(e2 + 4u);
      REX_STORE_U32(e2 + 4u, val);
      id = eid;
      val = ov;
    }
  }
  REX_STORE_U32(REX_LOAD_U32(map + 4u) + n * 8u + 4u, val);
  REX_STORE_U16(REX_LOAD_U32(map + 4u) + n * 8u, uint16_t(id));
}
