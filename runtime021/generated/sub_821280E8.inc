DEFINE_REX_FUNC(sub_821280E8) {
	REX_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82128030
	sub_82128030(ctx, base);
	return;
}
