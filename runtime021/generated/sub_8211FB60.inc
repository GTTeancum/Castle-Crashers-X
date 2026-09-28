DEFINE_REX_FUNC(sub_8211FB60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8211FB68;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32235
	ctx.r29.s64 = -2112552960;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r29,30236
	ctx.r31.s64 = ctx.r29.s64 + 30236;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x8214a434
	ctx.lr = 0x8211FB80;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,30236(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 30236);
	// addi r11,r30,32
	ctx.r11.s64 = ctx.r30.s64 + 32;
	// stw r31,36(r30)
	REX_STORE_U32(ctx.r30.u32 + 36, ctx.r31.u32);
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// stw r10,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r10.u32);
	// lwz r10,30236(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 30236);
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// stw r11,30236(r29)
	REX_STORE_U32(ctx.r29.u32 + 30236, ctx.r11.u32);
	// bl 0x8214a444
	ctx.lr = 0x8211FBA4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
