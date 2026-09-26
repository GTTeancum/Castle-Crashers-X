DEFINE_REX_FUNC(sub_8213AAB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x8213AAB8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r29,r11,24040
	ctx.r29.s64 = ctx.r11.s64 + 24040;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r30,0(r26)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// bl 0x8213a990
	ctx.lr = 0x8213AAD8;
	sub_8213A990(ctx, base);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// li r3,2240
	ctx.r3.s64 = 2240;
	// ori r4,r4,32780
	ctx.r4.u64 = ctx.r4.u64 | 32780;
	// bl 0x82136670
	ctx.lr = 0x8213AAE8;
	sub_82136670(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8213aafc
	if (!ctx.cr0.eq) goto loc_8213AAFC;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x8213aca0
	goto loc_8213ACA0;
loc_8213AAFC:
	// li r25,1
	ctx.r25.s64 = 1;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// stw r25,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82129a70
	ctx.lr = 0x8213AB18;
	sub_82129A70(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82139320
	ctx.lr = 0x8213AB24;
	sub_82139320(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x8213ac94
	if (ctx.cr0.lt) goto loc_8213AC94;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8213ab70
	if (!ctx.cr6.gt) goto loc_8213AB70;
	// addi r28,r31,1096
	ctx.r28.s64 = ctx.r31.s64 + 1096;
loc_8213AB40:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// lwz r5,12(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x8213ca00
	ctx.lr = 0x8213AB54;
	sub_8213CA00(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x8213ac94
	if (ctx.cr0.lt) goto loc_8213AC94;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8213ab40
	if (ctx.cr6.lt) goto loc_8213AB40;
loc_8213AB70:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8213abbc
	if (!ctx.cr6.gt) goto loc_8213ABBC;
	// addi r28,r31,1128
	ctx.r28.s64 = ctx.r31.s64 + 1128;
loc_8213AB84:
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// lwz r7,40(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,36(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// lwz r5,20(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r4,16(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x8213e2a0
	ctx.lr = 0x8213ABA0;
	sub_8213E2A0(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x8213ac94
	if (ctx.cr0.lt) goto loc_8213AC94;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8213ab84
	if (ctx.cr6.lt) goto loc_8213AB84;
loc_8213ABBC:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820b6868
	ctx.lr = 0x8213ABD0;
	sub_820B6868(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,1304(r31)
	REX_STORE_U32(ctx.r31.u32 + 1304, ctx.r3.u32);
	// bne 0x8213abe8
	if (!ctx.cr0.eq) goto loc_8213ABE8;
loc_8213ABDC:
	// lis r29,-32768
	ctx.r29.s64 = -2147483648;
	// ori r29,r29,16389
	ctx.r29.u64 = ctx.r29.u64 | 16389;
	// b 0x8213ac94
	goto loc_8213AC94;
loc_8213ABE8:
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x8214a3b4
	ctx.lr = 0x8213ABF4;
	__imp__XamNotifyCreateListener(ctx, base);
	// stw r3,1312(r31)
	REX_STORE_U32(ctx.r31.u32 + 1312, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8213abdc
	if (ctx.cr0.eq) goto loc_8213ABDC;
	// stw r25,1316(r31)
	REX_STORE_U32(ctx.r31.u32 + 1316, ctx.r25.u32);
	// addi r3,r31,1272
	ctx.r3.s64 = ctx.r31.s64 + 1272;
	// bl 0x8214a424
	ctx.lr = 0x8213AC0C;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8213ac8c
	if (!ctx.cr6.eq) goto loc_8213AC8C;
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r5,r11,-22304
	ctx.r5.s64 = ctx.r11.s64 + -22304;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820b7350
	ctx.lr = 0x8213AC3C;
	sub_820B7350(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,1264(r31)
	REX_STORE_U32(ctx.r31.u32 + 1264, ctx.r3.u32);
	// beq 0x8213abdc
	if (ctx.cr0.eq) goto loc_8213ABDC;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,1304(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1304);
	// bl 0x820b6020
	ctx.lr = 0x8213AC54;
	sub_820B6020(ctx, base);
	// lwz r6,4(r26)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8213ac8c
	if (ctx.cr6.eq) goto loc_8213AC8C;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,1264(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 1264);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82149ad0
	ctx.lr = 0x8213AC7C;
	sub_82149AD0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8213ac8c
	if (!ctx.cr0.eq) goto loc_8213AC8C;
	// lis r29,-32768
	ctx.r29.s64 = -2147483648;
	// ori r29,r29,16389
	ctx.r29.u64 = ctx.r29.u64 | 16389;
loc_8213AC8C:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x8213aca0
	if (!ctx.cr6.lt) goto loc_8213ACA0;
loc_8213AC94:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8213a1e0
	ctx.lr = 0x8213AC9C;
	sub_8213A1E0(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
loc_8213ACA0:
	// stw r31,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r31.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
