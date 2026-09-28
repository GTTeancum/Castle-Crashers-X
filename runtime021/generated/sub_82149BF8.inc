DEFINE_REX_FUNC(sub_82149BF8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r3,r11,-24760
	ctx.r3.s64 = ctx.r11.s64 + -24760;
	// b 0x82127fb0
	sub_82127FB0(ctx, base);
	return;
}
