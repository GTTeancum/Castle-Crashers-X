DEFINE_REX_FUNC(sub_820E32C8) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820e3370
	sub_820E3370(ctx, base);
	return;
}
