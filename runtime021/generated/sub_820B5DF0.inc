DEFINE_REX_FUNC(sub_820B5DF0) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,2892(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 2892);
	// stw r11,2892(r10)
	REX_STORE_U32(ctx.r10.u32 + 2892, ctx.r11.u32);
	// blr 
	return;
}
