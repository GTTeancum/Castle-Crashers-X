DEFINE_REX_FUNC(sub_820D7EF8) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8214aa14
	__imp__NetDll_XNetConnect(ctx, base);
	return;
}
