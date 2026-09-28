DEFINE_REX_FUNC(sub_82122268) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// b 0x8208c5d8
	sub_8208C5D8(ctx, base);
	return;
}
