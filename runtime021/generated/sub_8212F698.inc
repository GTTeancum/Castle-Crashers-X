DEFINE_REX_FUNC(sub_8212F698) {
	REX_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8212f4b8
	sub_8212F4B8(ctx, base);
	return;
}
