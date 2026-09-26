DEFINE_REX_FUNC(sub_820FBF50) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r3,r11,30092
	ctx.r3.s64 = ctx.r11.s64 + 30092;
	// b 0x820fbec8
	sub_820FBEC8(ctx, base);
	return;
}
