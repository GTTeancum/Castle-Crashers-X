DEFINE_REX_FUNC(sub_821163B0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
	// b 0x82115e60
	sub_82115E60(ctx, base);
	return;
}
