DEFINE_REX_FUNC(sub_820EAF50) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x820e82f8
	sub_820E82F8(ctx, base);
	return;
}
