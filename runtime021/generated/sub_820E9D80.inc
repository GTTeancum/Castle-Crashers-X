DEFINE_REX_FUNC(sub_820E9D80) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x820e99e0
	sub_820E99E0(ctx, base);
	return;
}
