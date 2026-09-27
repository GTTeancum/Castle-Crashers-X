DEFINE_REX_FUNC(sub_820C1980) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820C1988;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// bl 0x820c14e8
	ctx.lr = 0x820C19A4;
	sub_820C14E8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820c19c0
	if (ctx.cr0.eq) goto loc_820C19C0;
	// mullw r5,r30,r29
	ctx.r5.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r29.s32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82129a70
	ctx.lr = 0x820C19B8;
	sub_82129A70(ctx, base);
	// lwz r11,13444(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13444);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_820C19C0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
