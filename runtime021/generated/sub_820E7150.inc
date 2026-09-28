DEFINE_REX_FUNC(sub_820E7150) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// addi r9,r10,-27760
	ctx.r9.s64 = ctx.r10.s64 + -27760;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// b 0x820ebbd8
	sub_820EBBD8(ctx, base);
	return;
}
