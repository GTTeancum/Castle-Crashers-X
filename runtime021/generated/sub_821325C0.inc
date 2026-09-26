DEFINE_REX_FUNC(sub_821325C0) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,2956(r10)
	REX_STORE_U32(ctx.r10.u32 + 2956, ctx.r11.u32);
	// blr 
	return;
}
