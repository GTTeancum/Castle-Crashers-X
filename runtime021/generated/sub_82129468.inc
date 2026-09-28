DEFINE_REX_FUNC(sub_82129468) {
	REX_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82129190
	sub_82129190(ctx, base);
	return;
}
