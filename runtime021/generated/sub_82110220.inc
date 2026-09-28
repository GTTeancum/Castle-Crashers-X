DEFINE_REX_FUNC(sub_82110220) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82110228;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82129fa0
	ctx.lr = 0x82110248;
	sub_82129FA0(ctx, base);
	// addi r28,r31,104
	ctx.r28.s64 = ctx.r31.s64 + 104;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a434
	ctx.lr = 0x82110254;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8211029c
	if (ctx.cr6.eq) goto loc_8211029C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210e678
	ctx.lr = 0x82110268;
	sub_8210E678(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82110284
	if (ctx.cr0.eq) goto loc_82110284;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8211029c
	if (ctx.cr6.eq) goto loc_8211029C;
	// lwz r3,68(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82110290
	if (!ctx.cr6.eq) goto loc_82110290;
loc_82110284:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4105
	ctx.r31.u64 = ctx.r31.u64 | 4105;
	// b 0x821102ac
	goto loc_821102AC;
loc_82110290:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82115238
	ctx.lr = 0x82110298;
	sub_82115238(ctx, base);
	// b 0x821102a8
	goto loc_821102A8;
loc_8211029C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,164(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// bl 0x82115230
	ctx.lr = 0x821102A8;
	sub_82115230(ctx, base);
loc_821102A8:
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_821102AC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a444
	ctx.lr = 0x821102B4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
