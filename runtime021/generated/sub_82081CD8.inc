DEFINE_REX_FUNC(sub_82081CD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82081CE0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,8(r5)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// addi r3,r11,10372
	ctx.r3.s64 = ctx.r11.s64 + 10372;
	// bl 0x82082488
	ctx.lr = 0x82081D08;
	sub_82082488(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207aa50
	ctx.lr = 0x82081D20;
	sub_8207AA50(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r5,76(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 76);
	// and r6,r7,r12
	ctx.r6.u64 = ctx.r7.u64 & ctx.r12.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lwz r11,156(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 156);
	// addi r30,r11,10372
	ctx.r30.s64 = ctx.r11.s64 + 10372;
	// beq cr6,0x82081d60
	if (ctx.cr6.eq) goto loc_82081D60;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82081d60
	if (ctx.cr6.eq) goto loc_82081D60;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82066ea8
	ctx.lr = 0x82081D60;
	sub_82066EA8(ctx, base);
loc_82081D60:
	// lwz r11,5024(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 5024);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r29,r10,r30
	REX_STORE_U32(ctx.r10.u32 + ctx.r30.u32, ctx.r29.u32);
	// lwz r11,5024(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 5024);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,5024(r30)
	REX_STORE_U32(ctx.r30.u32 + 5024, ctx.r9.u32);
	// bl 0x8207a908
	ctx.lr = 0x82081D88;
	sub_8207A908(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r7,76(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 76);
	// lwz r11,156(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 156);
	// addi r3,r11,10372
	ctx.r3.s64 = ctx.r11.s64 + 10372;
	// bl 0x82082488
	ctx.lr = 0x82081DA0;
	sub_82082488(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x8207af80
	ctx.lr = 0x82081DB0;
	sub_8207AF80(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r3,76(r6)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + 76);
	// and r4,r5,r12
	ctx.r4.u64 = ctx.r5.u64 & ctx.r12.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwz r11,156(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// addi r31,r11,10372
	ctx.r31.s64 = ctx.r11.s64 + 10372;
	// beq cr6,0x82081df0
	if (ctx.cr6.eq) goto loc_82081DF0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82081df0
	if (ctx.cr6.eq) goto loc_82081DF0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82066ea8
	ctx.lr = 0x82081DF0;
	sub_82066EA8(ctx, base);
loc_82081DF0:
	// lwz r11,5024(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r10,r31
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, ctx.r30.u32);
	// lwz r11,5024(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,5024(r31)
	REX_STORE_U32(ctx.r31.u32 + 5024, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
