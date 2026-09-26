DEFINE_REX_FUNC(sub_8212C288) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// stw r3,3232(r11)
	REX_STORE_U32(ctx.r11.u32 + 3232, ctx.r3.u32);
	// blr 
	return;
}
