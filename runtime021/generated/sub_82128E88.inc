DEFINE_REX_FUNC(sub_82128E88) {
	REX_FUNC_PROLOGUE();
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x82128d48
	sub_82128D48(ctx, base);
	return;
}
