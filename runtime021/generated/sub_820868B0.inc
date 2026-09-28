DEFINE_REX_FUNC(sub_820868B0) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,104
	ctx.r3.s64 = ctx.r3.s64 + 104;
	// b 0x82085078
	sub_82085078(ctx, base);
	return;
}
