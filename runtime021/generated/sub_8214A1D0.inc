DEFINE_REX_FUNC(sub_8214A1D0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r11,r11,23132
	ctx.r11.s64 = ctx.r11.s64 + 23132;
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// b 0x82115138
	sub_82115138(ctx, base);
	return;
}
