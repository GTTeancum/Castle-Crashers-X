DEFINE_REX_FUNC(sub_8212F690) {
	REX_FUNC_PROLOGUE();
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x8212f630
	sub_8212F630(ctx, base);
	return;
}
