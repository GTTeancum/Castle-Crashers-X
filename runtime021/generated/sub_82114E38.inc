DEFINE_REX_FUNC(sub_82114E38) {
	REX_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x8214ac64
	__imp__ExFreePool(ctx, base);
	return;
}
