DEFINE_REX_FUNC(sub_820EAF80) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x820ead20
	sub_820EAD20(ctx, base);
	return;
}
