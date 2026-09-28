DEFINE_REX_FUNC(sub_82115160) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r3,r11,-200
	ctx.r3.s64 = ctx.r11.s64 + -200;
	// addi r7,r11,30
	ctx.r7.s64 = ctx.r11.s64 + 30;
	// b 0x82119560
	sub_82119560(ctx, base);
	return;
}
