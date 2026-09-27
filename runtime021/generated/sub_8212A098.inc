DEFINE_REX_FUNC(sub_8212A098) {
	REX_FUNC_PROLOGUE();
	// li r3,8
	ctx.r3.s64 = 8;
	// b 0x8212f2f8
	sub_8212F2F8(ctx, base);
	return;
}
