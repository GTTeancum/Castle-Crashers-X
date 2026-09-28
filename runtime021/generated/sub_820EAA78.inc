DEFINE_REX_FUNC(sub_820EAA78) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x820eaba0
	sub_820EABA0(ctx, base);
	return;
}
