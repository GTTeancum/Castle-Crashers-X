DEFINE_REX_FUNC(sub_820B6B80) {
	REX_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8214a384
	__imp__XamInputGetState(ctx, base);
	return;
}
