DEFINE_REX_FUNC(sub_820B6190) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8214a504
	__imp__MmFreePhysicalMemory(ctx, base);
	return;
}
