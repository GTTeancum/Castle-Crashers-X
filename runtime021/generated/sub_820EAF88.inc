DEFINE_REX_FUNC(sub_820EAF88) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820e83c8
	sub_820E83C8(ctx, base);
	return;
}
