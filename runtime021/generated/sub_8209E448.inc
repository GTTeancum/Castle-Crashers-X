DEFINE_REX_FUNC(sub_8209E448) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8209E450;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8209e474
	if (ctx.cr6.eq) goto loc_8209E474;
	// bl 0x820b6498
	ctx.lr = 0x8209E46C;
	sub_820B6498(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8209E474:
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820b64e0
	ctx.lr = 0x8209E494;
	sub_820B64E0(ctx, base);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8209e4bc
	if (!ctx.cr6.eq) goto loc_8209E4BC;
	// bl 0x820b6780
	ctx.lr = 0x8209E4A4;
	sub_820B6780(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8209e6c0
	if (!ctx.cr6.gt) goto loc_8209E6C0;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r3,r11,32775
	ctx.r3.u64 = ctx.r11.u64 | 2147942400;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
loc_8209E4BC:
	// lis r11,21065
	ctx.r11.s64 = 1380515840;
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// li r23,0
	ctx.r23.s64 = 0;
	// ori r10,r11,17990
	ctx.r10.u64 = ctx.r11.u64 | 17990;
	// lis r9,26221
	ctx.r9.s64 = 1718419456;
	// stw r23,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r23.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// ori r7,r9,29728
	ctx.r7.u64 = ctx.r9.u64 | 29728;
	// stw r7,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r7.u32);
	// lis r6,25697
	ctx.r6.s64 = 1684078592;
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// lis r5,22337
	ctx.r5.s64 = 1463877632;
	// stw r8,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
	// ori r4,r6,29793
	ctx.r4.u64 = ctx.r6.u64 | 29793;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// ori r24,r5,22085
	ctx.r24.u64 = ctx.r5.u64 | 22085;
	// stw r3,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r3.u32);
	// lis r11,29541
	ctx.r11.s64 = 1935998976;
	// stw r30,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r30.u32);
	// ori r9,r11,25963
	ctx.r9.u64 = ctx.r11.u64 | 25963;
	// stw r4,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r4.u32);
	// lis r10,22605
	ctx.r10.s64 = 1481441280;
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r30,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// ori r7,r10,16690
	ctx.r7.u64 = ctx.r10.u64 | 16690;
	// stw r24,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r24.u32);
	// addi r28,r31,100
	ctx.r28.s64 = ctx.r31.s64 + 100;
	// stw r8,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r8.u32);
	// addi r25,r31,124
	ctx.r25.s64 = ctx.r31.s64 + 124;
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r27,r31,28
	ctx.r27.s64 = ctx.r31.s64 + 28;
	// stw r30,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// addi r26,r31,52
	ctx.r26.s64 = ctx.r31.s64 + 52;
	// stw r9,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r9.u32);
	// stw r6,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r6.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r30,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r30.u32);
	// stw r7,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r7.u32);
	// stw r5,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r5.u32);
	// bl 0x8209e098
	ctx.lr = 0x8209E568;
	sub_8209E098(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x8209e640
	if (ctx.cr6.lt) goto loc_8209E640;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8209e098
	ctx.lr = 0x8209E57C;
	sub_8209E098(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x8209e594
	if (ctx.cr6.lt) goto loc_8209E594;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
	// b 0x8209e5a0
	goto loc_8209E5A0;
loc_8209E594:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8209e098
	ctx.lr = 0x8209E59C;
	sub_8209E098(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_8209E5A0:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x8209e640
	if (ctx.cr6.lt) goto loc_8209E640;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8209e098
	ctx.lr = 0x8209E5B0;
	sub_8209E098(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x8209e640
	if (ctx.cr6.lt) goto loc_8209E640;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8209e098
	ctx.lr = 0x8209E5C4;
	sub_8209E098(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x8209e640
	if (ctx.cr6.lt) goto loc_8209E640;
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8209e618
	if (!ctx.cr6.eq) goto loc_8209E618;
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x820a7390
	ctx.lr = 0x8209E5E4;
	sub_820A7390(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r6,44(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// bl 0x8209e1c0
	ctx.lr = 0x8209E604;
	sub_8209E1C0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x8209e640
	if (ctx.cr6.lt) goto loc_8209E640;
	// lwz r3,156(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// bl 0x8209e890
	ctx.lr = 0x8209E618;
	sub_8209E890(ctx, base);
loc_8209E618:
	// lwz r3,116(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// bl 0x820a7390
	ctx.lr = 0x8209E620;
	sub_820A7390(ctx, base);
	// stw r3,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r3.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,116(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8209e1c0
	ctx.lr = 0x8209E63C;
	sub_8209E1C0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_8209E640:
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8209e67c
	if (ctx.cr6.eq) goto loc_8209E67C;
	// lwz r3,140(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// bl 0x820a7390
	ctx.lr = 0x8209E654;
	sub_820A7390(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r5,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r5.u32);
	// blt cr6,0x8209e67c
	if (ctx.cr6.lt) goto loc_8209E67C;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,140(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8209e1c0
	ctx.lr = 0x8209E678;
	sub_8209E1C0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_8209E67C:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r23,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r23.u32);
	// blt cr6,0x8209e6ac
	if (ctx.cr6.lt) goto loc_8209E6AC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8209e1c0
	ctx.lr = 0x8209E6A0;
	sub_8209E1C0(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// beq cr6,0x8209e6bc
	if (ctx.cr6.eq) goto loc_8209E6BC;
loc_8209E6AC:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,2
	ctx.r3.u64 = ctx.r3.u64 | 2;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
loc_8209E6BC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8209E6C0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
