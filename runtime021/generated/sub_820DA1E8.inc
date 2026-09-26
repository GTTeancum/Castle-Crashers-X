DEFINE_REX_FUNC(sub_820DA1E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,32746
	ctx.r11.s64 = 2146041856;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// ori r9,r11,6144
	ctx.r9.u64 = ctx.r11.u64 | 6144;
	// lwbrx r11,0,r9
	ctx.r11.u64 = __builtin_bswap32(REX_MM_LOAD_U32(ctx.r9.u32));
	// stw r11,22964(r10)
	REX_STORE_U32(ctx.r10.u32 + 22964, ctx.r11.u32);
	// blr 
	return;
}
