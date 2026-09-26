DEFINE_REX_FUNC(sub_820E0A00) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820e0388
	sub_820E0388(ctx, base);
	return;
}
