DEFINE_REX_FUNC(sub_820D7F08) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8214aa24
	__imp__NetDll_XNetGetConnectStatus(ctx, base);
	return;
}
