DEFINE_REX_FUNC(sub_820B5C40) {
	REX_FUNC_PROLOGUE();
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// oris r6,r4,1
	ctx.r6.u64 = ctx.r4.u64 | 65536;
	// oris r5,r4,2
	ctx.r5.u64 = ctx.r4.u64 | 131072;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8214a294
	__imp__XamWriteGamerTile(ctx, base);
	return;
}
