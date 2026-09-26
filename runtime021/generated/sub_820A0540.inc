DEFINE_REX_FUNC(sub_820A0540) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820A0548;
	__savegprlr_25(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32218
	ctx.r27.s64 = -2111438848;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// li r25,1
	ctx.r25.s64 = 1;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// slw r9,r25,r31
	ctx.r9.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r25.u32 << (ctx.r31.u8 & 0x3F));
	// lwz r11,-6628(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -6628);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r29,-6596(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + -6596);
	// lwz r8,36(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x820a0590
	if (!ctx.cr6.eq) goto loc_820A0590;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r25,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A0590:
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// li r28,0
	ctx.r28.s64 = 0;
	// lbz r10,2704(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + 2704);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a05ac
	if (ctx.cr6.eq) goto loc_820A05AC;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// b 0x820a05e8
	goto loc_820A05E8;
loc_820A05AC:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820b6818
	ctx.lr = 0x820A05B8;
	sub_820B6818(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a05e0
	if (!ctx.cr6.eq) goto loc_820A05E0;
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a05e0
	if (ctx.cr6.eq) goto loc_820A05E0;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// stb r9,2704(r26)
	REX_STORE_U8(ctx.r26.u32 + 2704, ctx.r9.u8);
	// b 0x820a05e4
	goto loc_820A05E4;
loc_820A05E0:
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
loc_820A05E4:
	// lwz r11,-6628(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -6628);
loc_820A05E8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a06bc
	if (ctx.cr6.eq) goto loc_820A06BC;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820a061c
	if (ctx.cr6.eq) goto loc_820A061C;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a061c
	if (ctx.cr6.eq) goto loc_820A061C;
	// lbz r11,1185(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// bne cr6,0x820a0620
	if (!ctx.cr6.eq) goto loc_820A0620;
loc_820A061C:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_820A0620:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a08ac
	if (!ctx.cr6.eq) goto loc_820A08AC;
	// lis r27,-32221
	ctx.r27.s64 = -2111635456;
	// lbz r11,840(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 840);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a0674
	if (ctx.cr6.eq) goto loc_820A0674;
	// li r11,210
	ctx.r11.s64 = 210;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// sth r11,112(r1)
	REX_STORE_U16(ctx.r1.u32 + 112, ctx.r11.u16);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,-6624(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x820A0658;
	sub_82052EA8(ctx, base);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stb r11,840(r27)
	REX_STORE_U8(ctx.r27.u32 + 840, ctx.r11.u8);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a1288
	ctx.lr = 0x820A0674;
	sub_820A1288(ctx, base);
loc_820A0674:
	// lis r11,25576
	ctx.r11.s64 = 1676148736;
	// stw r28,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r10,r11,16383
	ctx.r10.u64 = ctx.r11.u64 | 16383;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// addi r7,r1,116
	ctx.r7.s64 = ctx.r1.s64 + 116;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820fc1d8
	ctx.lr = 0x820A06A4;
	sub_820FC1D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,122
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 122, ctx.xer);
	// beq cr6,0x820a06d0
	if (ctx.cr6.eq) goto loc_820A06D0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2656
	ctx.r3.s64 = ctx.r11.s64 + 2656;
	// bl 0x8208c5d8
	ctx.lr = 0x820A06BC;
	sub_8208C5D8(ctx, base);
loc_820A06BC:
	// stw r25,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r28,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r28.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A06D0:
	// lwz r3,116(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x820a7390
	ctx.lr = 0x820A06D8;
	sub_820A7390(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// bl 0x82129fa0
	ctx.lr = 0x820A06E8;
	sub_82129FA0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// addi r7,r1,116
	ctx.r7.s64 = ctx.r1.s64 + 116;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820fc1d8
	ctx.lr = 0x820A0708;
	sub_820FC1D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820a076c
	if (ctx.cr6.eq) goto loc_820A076C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2656
	ctx.r3.s64 = ctx.r11.s64 + 2656;
	// bl 0x8208c5d8
	ctx.lr = 0x820A0720;
	sub_8208C5D8(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820a7400
	ctx.lr = 0x820A0728;
	sub_820A7400(ctx, base);
	// addi r10,r31,5
	ctx.r10.s64 = ctx.r31.s64 + 5;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r29
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r29.u32);
	// bl 0x8209d2d0
	ctx.lr = 0x820A073C;
	sub_8209D2D0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a0c38
	ctx.lr = 0x820A074C;
	sub_820A0C38(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820a08c0
	ctx.lr = 0x820A0758;
	sub_820A08C0(ctx, base);
	// stw r25,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
	// stw r28,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r28.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A076C:
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r11,32(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a0800
	if (!ctx.cr6.eq) goto loc_820A0800;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820a7400
	ctx.lr = 0x820A0784;
	sub_820A7400(ctx, base);
	// addi r11,r31,5
	ctx.r11.s64 = ctx.r31.s64 + 5;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r29
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// bl 0x8209d2d0
	ctx.lr = 0x820A0798;
	sub_8209D2D0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a0af8
	ctx.lr = 0x820A07A8;
	sub_820A0AF8(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a0c38
	ctx.lr = 0x820A07B8;
	sub_820A0C38(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5c40
	ctx.lr = 0x820A07CC;
	sub_820B5C40(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5c40
	ctx.lr = 0x820A07E0;
	sub_820B5C40(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820a08c0
	ctx.lr = 0x820A07EC;
	sub_820A08C0(ctx, base);
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// stw r28,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r28.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A0800:
	// addi r9,r31,5
	ctx.r9.s64 = ctx.r31.s64 + 5;
	// rlwinm r26,r9,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r26,r29
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + ctx.r29.u32);
	// lwz r5,8(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r3,4(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820a0880
	if (ctx.cr6.eq) goto loc_820A0880;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820a7400
	ctx.lr = 0x820A0824;
	sub_820A7400(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwzx r4,r26,r29
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + ctx.r29.u32);
	// bl 0x8209d2d0
	ctx.lr = 0x820A0830;
	sub_8209D2D0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a0af8
	ctx.lr = 0x820A0840;
	sub_820A0AF8(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a0c38
	ctx.lr = 0x820A0850;
	sub_820A0C38(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820a08c0
	ctx.lr = 0x820A085C;
	sub_820A08C0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a0988
	ctx.lr = 0x820A086C;
	sub_820A0988(ctx, base);
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// stw r28,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r28.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A0880:
	// lwz r4,36(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// bl 0x82129a70
	ctx.lr = 0x820A0888;
	sub_82129A70(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a0c38
	ctx.lr = 0x820A0898;
	sub_820A0C38(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820a08c0
	ctx.lr = 0x820A08A4;
	sub_820A08C0(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820a7400
	ctx.lr = 0x820A08AC;
	sub_820A7400(ctx, base);
loc_820A08AC:
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r28,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r28.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
