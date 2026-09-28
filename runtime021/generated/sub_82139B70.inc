DEFINE_REX_FUNC(sub_82139B70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82139B78;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r31,r30,1272
	ctx.r31.s64 = ctx.r30.s64 + 1272;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a434
	ctx.lr = 0x82139B90;
	__imp__RtlEnterCriticalSection(ctx, base);
	// stw r29,36(r30)
	REX_STORE_U32(ctx.r30.u32 + 36, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a444
	ctx.lr = 0x82139B9C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
