DEFINE_REX_FUNC(sub_820DEA38) {
	REX_FUNC_PROLOGUE();
	// lis r11,4
	ctx.r11.s64 = 262144;
	// li r3,0
	ctx.r3.s64 = 0;
	// ori r11,r11,47792
	ctx.r11.u64 = ctx.r11.u64 | 47792;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}
