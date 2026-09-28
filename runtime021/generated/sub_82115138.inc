DEFINE_REX_FUNC(sub_82115138) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r11,r11,-20600
	ctx.r11.s64 = ctx.r11.s64 + -20600;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x82115008
	sub_82115008(ctx, base);
	return;
}
