DEFINE_REX_FUNC(sub_82128298) {
	REX_FUNC_PROLOGUE();
	// li r5,10
	ctx.r5.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8212e660
	sub_8212E660(ctx, base);
	return;
}
