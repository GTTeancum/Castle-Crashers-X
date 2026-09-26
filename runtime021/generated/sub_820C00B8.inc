DEFINE_REX_FUNC(sub_820C00B8) {
	REX_FUNC_PROLOGUE();
	// stw r4,11820(r3)
	REX_STORE_U32(ctx.r3.u32 + 11820, ctx.r4.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 524288;
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}
