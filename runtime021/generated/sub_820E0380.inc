DEFINE_REX_FUNC(sub_820E0380) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820e0660
	sub_820E0660(ctx, base);
	return;
}
