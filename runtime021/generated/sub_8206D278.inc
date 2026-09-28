DEFINE_REX_FUNC(sub_8206D278) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r11,-11624
	ctx.r7.s64 = ctx.r11.s64 + -11624;
	// li r6,15
	ctx.r6.s64 = 15;
	// li r5,539
	ctx.r5.s64 = 539;
	// li r4,538
	ctx.r4.s64 = 538;
	// b 0x82054c38
	sub_82054C38(ctx, base);
	return;
}
