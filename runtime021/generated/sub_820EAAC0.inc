DEFINE_REX_FUNC(sub_820EAAC0) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x820e79b8
	sub_820E79B8(ctx, base);
	return;
}
