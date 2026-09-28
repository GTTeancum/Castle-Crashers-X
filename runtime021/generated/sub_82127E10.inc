DEFINE_REX_FUNC(sub_82127E10) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r6,r11,32376
	ctx.r6.s64 = ctx.r11.s64 + 32376;
	// b 0x82127d38
	sub_82127D38(ctx, base);
	return;
}
