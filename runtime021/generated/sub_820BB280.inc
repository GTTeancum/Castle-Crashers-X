DEFINE_REX_FUNC(sub_820BB280) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lwz r3,2876(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2876);
	// blr 
	return;
}
