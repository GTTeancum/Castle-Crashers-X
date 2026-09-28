DEFINE_REX_FUNC(sub_8214A178) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// addi r3,r11,-22032
	ctx.r3.s64 = ctx.r11.s64 + -22032;
	// b 0x8209a288
	sub_8209A288(ctx, base);
	return;
}
