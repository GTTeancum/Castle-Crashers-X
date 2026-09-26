DEFINE_REX_FUNC(sub_820D7EA0) {
	REX_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8214a9c4
	__imp__NetDll_XNetCleanup(ctx, base);
	return;
}
