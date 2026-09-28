DEFINE_REX_FUNC(sub_8210C538) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// b 0x8210c1a8
	sub_8210C1A8(ctx, base);
	return;
}
