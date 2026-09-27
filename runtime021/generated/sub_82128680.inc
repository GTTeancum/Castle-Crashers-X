DEFINE_REX_FUNC(sub_82128680) {
	REX_FUNC_PROLOGUE();
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x821284c0
	sub_821284C0(ctx, base);
	return;
}
