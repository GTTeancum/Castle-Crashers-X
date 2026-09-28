DEFINE_REX_FUNC(sub_82134E98) {
	REX_FUNC_PROLOGUE();
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8212a048
	sub_8212A048(ctx, base);
	return;
}
