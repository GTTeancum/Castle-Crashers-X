DEFINE_REX_FUNC(sub_82125DD0) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,9
	ctx.r3.s64 = 9;
	// stw r5,5(r11)
	REX_STORE_U32(ctx.r11.u32 + 5, ctx.r5.u32);
	// stw r6,1(r11)
	REX_STORE_U32(ctx.r11.u32 + 1, ctx.r6.u32);
	// stb r4,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r4.u8);
	// blr 
	return;
}
