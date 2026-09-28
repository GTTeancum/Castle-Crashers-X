DEFINE_REX_FUNC(sub_8213E568) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// clrlwi. r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ori r11,r11,87
	ctx.r11.u64 = ctx.r11.u64 | 87;
	// bne 0x8213e584
	if (!ctx.cr0.eq) goto loc_8213E584;
	// lwz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8213E584:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}
