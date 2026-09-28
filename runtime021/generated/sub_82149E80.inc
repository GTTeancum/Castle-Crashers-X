DEFINE_REX_FUNC(sub_82149E80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r3,r11,23040
	ctx.r3.s64 = ctx.r11.s64 + 23040;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82129fa0
	sub_82129FA0(ctx, base);
	return;
}
