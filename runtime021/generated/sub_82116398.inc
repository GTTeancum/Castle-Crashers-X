DEFINE_REX_FUNC(sub_82116398) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r3,r11,48
	ctx.r3.s64 = ctx.r11.s64 + 48;
	// addi r10,r10,-20592
	ctx.r10.s64 = ctx.r10.s64 + -20592;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8208c5d8
	sub_8208C5D8(ctx, base);
	return;
}
