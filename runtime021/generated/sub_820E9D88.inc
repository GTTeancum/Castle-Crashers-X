DEFINE_REX_FUNC(sub_820E9D88) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x820e8d48
	sub_820E8D48(ctx, base);
	return;
}
