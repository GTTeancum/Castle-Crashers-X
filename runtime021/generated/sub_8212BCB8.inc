DEFINE_REX_FUNC(sub_8212BCB8) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// and r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 & ctx.r4.u64;
	// lwz r3,31268(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 31268);
	// andc r9,r3,r4
	ctx.r9.u64 = ctx.r3.u64 & ~ctx.r4.u64;
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
	// stw r11,31268(r10)
	REX_STORE_U32(ctx.r10.u32 + 31268, ctx.r11.u32);
	// blr 
	return;
}
