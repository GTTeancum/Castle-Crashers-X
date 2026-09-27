DEFINE_REX_FUNC(sub_82128290) {
	REX_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x821280f8
	sub_821280F8(ctx, base);
	return;
}
