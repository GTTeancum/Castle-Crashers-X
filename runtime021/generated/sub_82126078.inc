DEFINE_REX_FUNC(sub_82126078) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lbz r11,75(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 75);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lhz r11,72(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 72);
	// lbz r10,74(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 74);
	// clrlwi r11,r11,17
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFF;
	// lwz r3,20(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// sth r11,72(r4)
	REX_STORE_U16(ctx.r4.u32 + 72, ctx.r11.u16);
	// bne 0x821260a8
	if (!ctx.cr0.eq) goto loc_821260A8;
	// b 0x82122b78
	sub_82122B78(ctx, base);
	return;
loc_821260A8:
	// b 0x82122bd0
	sub_82122BD0(ctx, base);
	return;
}
