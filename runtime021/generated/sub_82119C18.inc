DEFINE_REX_FUNC(sub_82119C18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82119C20;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r5,254
	ctx.r5.s64 = 254;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x820fc728
	ctx.lr = 0x82119C38;
	sub_820FC728(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// stw r3,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r3.u32);
	// beq cr6,0x82119ca4
	if (ctx.cr6.eq) goto loc_82119CA4;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lhz r10,268(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 268);
	// lwz r9,264(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r28,0
	ctx.r28.s64 = 0;
	// li r8,2
	ctx.r8.s64 = 2;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// std r28,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r28.u64);
	// std r28,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r28.u64);
	// sth r10,98(r1)
	REX_STORE_U16(ctx.r1.u32 + 98, ctx.r10.u16);
	// sth r8,96(r1)
	REX_STORE_U16(ctx.r1.u32 + 96, ctx.r8.u16);
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// bl 0x820fc788
	ctx.lr = 0x82119C78;
	sub_820FC788(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82119ca4
	if (ctx.cr6.eq) goto loc_82119CA4;
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r3,272(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 272);
	// lis r4,-32764
	ctx.r4.s64 = -2147221504;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ori r4,r4,26238
	ctx.r4.u64 = ctx.r4.u64 | 26238;
	// bl 0x820fc750
	ctx.lr = 0x82119C9C;
	sub_820FC750(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82119cb4
	if (ctx.cr0.eq) goto loc_82119CB4;
loc_82119CA4:
	// bl 0x820fc8b0
	ctx.lr = 0x82119CA8;
	sub_820FC8B0(ctx, base);
	// bl 0x8210c710
	ctx.lr = 0x82119CAC;
	sub_8210C710(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x82119cdc
	goto loc_82119CDC;
loc_82119CB4:
	// addi r30,r31,236
	ctx.r30.s64 = ctx.r31.s64 + 236;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x82119CC0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821199d0
	ctx.lr = 0x82119CC8;
	sub_821199D0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a444
	ctx.lr = 0x82119CD4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x82119cf8
	if (!ctx.cr6.lt) goto loc_82119CF8;
loc_82119CDC:
	// lwz r3,272(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 272);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82119cfc
	if (ctx.cr6.eq) goto loc_82119CFC;
	// bl 0x820fc740
	ctx.lr = 0x82119CEC;
	sub_820FC740(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
	// b 0x82119cfc
	goto loc_82119CFC;
loc_82119CF8:
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_82119CFC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
