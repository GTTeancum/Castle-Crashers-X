DEFINE_REX_FUNC(sub_8209FF98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8209FFA0;
	__savegprlr_23(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,59648
	ctx.r9.u64 = ctx.r10.u64 | 59648;
	// lwz r31,-6596(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// lwzx r3,r31,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209ffc4
	if (ctx.cr6.eq) goto loc_8209FFC4;
	// bl 0x82050800
	ctx.lr = 0x8209FFC4;
	sub_82050800(ctx, base);
loc_8209FFC4:
	// addis r10,r31,2
	ctx.r10.s64 = ctx.r31.s64 + 131072;
	// li r25,0
	ctx.r25.s64 = 0;
	// addi r10,r10,-5916
	ctx.r10.s64 = ctx.r10.s64 + -5916;
	// li r23,4
	ctx.r23.s64 = 4;
	// li r24,2
	ctx.r24.s64 = 2;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x820a0220
	if (!ctx.cr6.eq) goto loc_820A0220;
	// addis r27,r31,2
	ctx.r27.s64 = ctx.r31.s64 + 131072;
	// addi r27,r27,-5908
	ctx.r27.s64 = ctx.r27.s64 + -5908;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820a0138
	if (ctx.cr6.lt) goto loc_820A0138;
	// bne cr6,0x820a0220
	if (!ctx.cr6.eq) goto loc_820A0220;
	// addis r29,r31,2
	ctx.r29.s64 = ctx.r31.s64 + 131072;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// addi r29,r29,-5900
	ctx.r29.s64 = ctx.r29.s64 + -5900;
	// addi r30,r30,-5896
	ctx.r30.s64 = ctx.r30.s64 + -5896;
	// lwz r5,0(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r6,0(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r5,31268
	ctx.r11.s64 = ctx.r5.s64 + 31268;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// cmplw cr6,r6,r8
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x820a012c
	if (!ctx.cr6.lt) goto loc_820A012C;
	// lis r27,-32215
	ctx.r27.s64 = -2111242240;
	// lwz r11,2700(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 2700);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820a0108
	if (ctx.cr6.lt) goto loc_820A0108;
	// beq cr6,0x820a0068
	if (ctx.cr6.eq) goto loc_820A0068;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x820a0220
	if (!ctx.cr6.lt) goto loc_820A0220;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x820a1560
	ctx.lr = 0x820A0050;
	sub_820A1560(ctx, base);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r11,2700(r27)
	REX_STORE_U32(ctx.r27.u32 + 2700, ctx.r11.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x820a0220
	goto loc_820A0220;
loc_820A0068:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a11b0
	ctx.lr = 0x820A0070;
	sub_820A11B0(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mulli r10,r10,100
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(100));
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r29,210
	ctx.r29.s64 = 210;
	// mulli r11,r9,312
	ctx.r11.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(312));
	// sth r29,96(r1)
	REX_STORE_U16(ctx.r1.u32 + 96, ctx.r29.u16);
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lis r28,-32218
	ctx.r28.s64 = -2111438848;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r30,580(r8)
	REX_STORE_U32(ctx.r8.u32 + 580, ctx.r30.u32);
	// lwz r11,-6624(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x820A00AC;
	sub_82052EA8(ctx, base);
	// sth r29,96(r1)
	REX_STORE_U16(ctx.r1.u32 + 96, ctx.r29.u16);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,-6624(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// lwz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// slw r5,r7,r30
	ctx.r5.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r30.u8 & 0x3F));
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// or r30,r5,r6
	ctx.r30.u64 = ctx.r5.u64 | ctx.r6.u64;
	// bl 0x82052ea8
	ctx.lr = 0x820A00D0;
	sub_82052EA8(ctx, base);
	// clrlwi r28,r30,16
	ctx.r28.u64 = ctx.r30.u32 & 0xFFFF;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// addi r29,r31,20
	ctx.r29.s64 = ctx.r31.s64 + 20;
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
loc_820A00E0:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d5f8
	ctx.lr = 0x820A00F0;
	sub_8209D5F8(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x820a00e0
	if (!ctx.cr0.eq) goto loc_820A00E0;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// stw r11,2700(r27)
	REX_STORE_U32(ctx.r27.u32 + 2700, ctx.r11.u32);
	// b 0x820a0220
	goto loc_820A0220;
loc_820A0108:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x820a13e8
	ctx.lr = 0x820A0114;
	sub_820A13E8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820a0220
	if (!ctx.cr6.eq) goto loc_820A0220;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,2700(r27)
	REX_STORE_U32(ctx.r27.u32 + 2700, ctx.r11.u32);
	// b 0x820a0220
	goto loc_820A0220;
loc_820A012C:
	// stw r24,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r24.u32);
	// stw r24,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r24.u32);
	// b 0x820a0220
	goto loc_820A0220;
loc_820A0138:
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// addi r30,r30,-5944
	ctx.r30.s64 = ctx.r30.s64 + -5944;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x820a0220
	if (ctx.cr6.eq) goto loc_820A0220;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,59624
	ctx.r10.u64 = ctx.r11.u64 | 59624;
	// lwzx r3,r31,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// bl 0x820b6498
	ctx.lr = 0x820A015C;
	sub_820B6498(ctx, base);
	// addis r28,r31,2
	ctx.r28.s64 = ctx.r31.s64 + 131072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r28,r28,-5900
	ctx.r28.s64 = ctx.r28.s64 + -5900;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// addi r9,r11,31268
	ctx.r9.s64 = ctx.r11.s64 + 31268;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x820b6a28
	ctx.lr = 0x820A0180;
	sub_820B6A28(ctx, base);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r11,31268
	ctx.r7.s64 = ctx.r11.s64 + 31268;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// stw r8,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r8.u32);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r26,r6,59632
	ctx.r26.u64 = ctx.r6.u64 | 59632;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// lwzx r4,r5,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r31.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// ble cr6,0x820a01fc
	if (!ctx.cr6.gt) goto loc_820A01FC;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// add r27,r31,r26
	ctx.r27.u64 = ctx.r31.u64 + ctx.r26.u64;
loc_820A01B4:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r5,308
	ctx.r5.s64 = 308;
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mulli r11,r11,100
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(100));
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r4,r29,r10
	ctx.r4.u64 = ctx.r29.u64 + ctx.r10.u64;
	// mulli r11,r9,312
	ctx.r11.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(312));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r3,r11,272
	ctx.r3.s64 = ctx.r11.s64 + 272;
	// bl 0x82129a70
	ctx.lr = 0x820A01DC;
	sub_82129A70(ctx, base);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r8,r11,31268
	ctx.r8.s64 = ctx.r11.s64 + 31268;
	// addi r29,r29,308
	ctx.r29.s64 = ctx.r29.s64 + 308;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r31
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r31.u32);
	// cmplw cr6,r30,r6
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x820a01b4
	if (ctx.cr6.lt) goto loc_820A01B4;
loc_820A01FC:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lwzx r3,r31,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r26.u32);
	// ori r10,r11,59640
	ctx.r10.u64 = ctx.r11.u64 | 59640;
	// stwx r25,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r25.u32);
	// bl 0x820a7400
	ctx.lr = 0x820A0210;
	sub_820A7400(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stwx r25,r31,r26
	REX_STORE_U32(ctx.r31.u32 + ctx.r26.u32, ctx.r25.u32);
	// stw r11,2700(r9)
	REX_STORE_U32(ctx.r9.u32 + 2700, ctx.r11.u32);
loc_820A0220:
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a0320
	if (ctx.cr6.eq) goto loc_820A0320;
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// addi r3,r31,36
	ctx.r3.s64 = ctx.r31.s64 + 36;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x820a04fc
	if (ctx.cr6.eq) goto loc_820A04FC;
	// li r30,-1
	ctx.r30.s64 = -1;
	// li r29,-1
	ctx.r29.s64 = -1;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// addi r8,r31,64
	ctx.r8.s64 = ctx.r31.s64 + 64;
loc_820A024C:
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// bne cr6,0x820a0294
	if (!ctx.cr6.eq) goto loc_820A0294;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_820A025C:
	// lwz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r7,2
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 2, ctx.xer);
	// beq cr6,0x820a027c
	if (ctx.cr6.eq) goto loc_820A027C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// blt cr6,0x820a025c
	if (ctx.cr6.lt) goto loc_820A025C;
	// b 0x820a0284
	goto loc_820A0284;
loc_820A027C:
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_820A0284:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// blt cr6,0x820a024c
	if (ctx.cr6.lt) goto loc_820A024C;
loc_820A0294:
	// stw r25,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x820b6a28
	ctx.lr = 0x820A02A4;
	sub_820B6A28(ctx, base);
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a02e8
	if (!ctx.cr6.eq) goto loc_820A02E8;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820a02e8
	if (!ctx.cr6.eq) goto loc_820A02E8;
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,3
	ctx.r10.s64 = 3;
	// add r9,r30,r11
	ctx.r9.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r8,r11,16
	ctx.r8.s64 = ctx.r11.s64 + 16;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r7,r31
	REX_STORE_U32(ctx.r7.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r3,260(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// bl 0x820b6498
	ctx.lr = 0x820A02E0;
	sub_820B6498(ctx, base);
	// stw r25,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r25.u32);
	// b 0x820a04fc
	goto loc_820A04FC;
loc_820A02E8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2560
	ctx.r3.s64 = ctx.r11.s64 + 2560;
	// bl 0x8208c5d8
	ctx.lr = 0x820A02F4;
	sub_8208C5D8(ctx, base);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r30,r11
	ctx.r10.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r9,r11,16
	ctx.r9.s64 = ctx.r11.s64 + 16;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r23,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r23.u32);
	// lwz r3,260(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// bl 0x820b6498
	ctx.lr = 0x820A0318;
	sub_820B6498(ctx, base);
	// stw r25,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r25.u32);
	// b 0x820a04fc
	goto loc_820A04FC;
loc_820A0320:
	// lwz r11,256(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a04fc
	if (ctx.cr6.eq) goto loc_820A04FC;
	// li r30,-1
	ctx.r30.s64 = -1;
	// li r29,-1
	ctx.r29.s64 = -1;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// addi r8,r31,64
	ctx.r8.s64 = ctx.r31.s64 + 64;
loc_820A033C:
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// bne cr6,0x820a0384
	if (!ctx.cr6.eq) goto loc_820A0384;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_820A034C:
	// lwz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r7,1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 1, ctx.xer);
	// beq cr6,0x820a036c
	if (ctx.cr6.eq) goto loc_820A036C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// blt cr6,0x820a034c
	if (ctx.cr6.lt) goto loc_820A034C;
	// b 0x820a0374
	goto loc_820A0374;
loc_820A036C:
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_820A0374:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// blt cr6,0x820a033c
	if (ctx.cr6.lt) goto loc_820A033C;
loc_820A0384:
	// cmpwi cr6,r29,-1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, -1, ctx.xer);
	// beq cr6,0x820a04fc
	if (ctx.cr6.eq) goto loc_820A04FC;
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x820a04fc
	if (ctx.cr6.eq) goto loc_820A04FC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820b6868
	ctx.lr = 0x820A03A8;
	sub_820B6868(ctx, base);
	// stw r3,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a03e0
	if (!ctx.cr6.eq) goto loc_820A03E0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2612
	ctx.r3.s64 = ctx.r11.s64 + 2612;
	// bl 0x8208c5d8
	ctx.lr = 0x820A03C0;
	sub_8208C5D8(ctx, base);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r30,r11
	ctx.r10.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r9,r11,16
	ctx.r9.s64 = ctx.r11.s64 + 16;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r23,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r23.u32);
	// b 0x820a04f0
	goto loc_820A04F0;
loc_820A03E0:
	// addi r5,r31,36
	ctx.r5.s64 = ctx.r31.s64 + 36;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// li r10,7
	ctx.r10.s64 = 7;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820A03F4:
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x820a03f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820A03F4;
	// lwz r10,260(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// stw r10,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// bgt cr6,0x820a04bc
	if (ctx.cr6.gt) goto loc_820A04BC;
	// lis r12,-32246
	ctx.r12.s64 = -2113273856;
	// addi r12,r12,1068
	ctx.r12.s64 = ctx.r12.s64 + 1068;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_820A045C;
	case 1:
		goto loc_820A0464;
	case 2:
		goto loc_820A046C;
	case 3:
		goto loc_820A0474;
	case 4:
		goto loc_820A047C;
	case 5:
		goto loc_820A0484;
	case 6:
		goto loc_820A048C;
	case 7:
		goto loc_820A0494;
	case 8:
		goto loc_820A049C;
	case 9:
		goto loc_820A04A4;
	case 10:
		goto loc_820A04AC;
	case 11:
		goto loc_820A04B4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820A045C:
	// li r11,13
	ctx.r11.s64 = 13;
	// b 0x820a04c0
	goto loc_820A04C0;
loc_820A0464:
	// li r11,14
	ctx.r11.s64 = 14;
	// b 0x820a04c0
	goto loc_820A04C0;
loc_820A046C:
	// li r11,15
	ctx.r11.s64 = 15;
	// b 0x820a04c0
	goto loc_820A04C0;
loc_820A0474:
	// li r11,16
	ctx.r11.s64 = 16;
	// b 0x820a04c0
	goto loc_820A04C0;
loc_820A047C:
	// li r11,17
	ctx.r11.s64 = 17;
	// b 0x820a04c0
	goto loc_820A04C0;
loc_820A0484:
	// li r11,18
	ctx.r11.s64 = 18;
	// b 0x820a04c0
	goto loc_820A04C0;
loc_820A048C:
	// li r11,19
	ctx.r11.s64 = 19;
	// b 0x820a04c0
	goto loc_820A04C0;
loc_820A0494:
	// li r11,20
	ctx.r11.s64 = 20;
	// b 0x820a04c0
	goto loc_820A04C0;
loc_820A049C:
	// li r11,21
	ctx.r11.s64 = 21;
	// b 0x820a04c0
	goto loc_820A04C0;
loc_820A04A4:
	// li r11,22
	ctx.r11.s64 = 22;
	// b 0x820a04c0
	goto loc_820A04C0;
loc_820A04AC:
	// li r11,23
	ctx.r11.s64 = 23;
	// b 0x820a04c0
	goto loc_820A04C0;
loc_820A04B4:
	// li r11,24
	ctx.r11.s64 = 24;
	// b 0x820a04c0
	goto loc_820A04C0;
loc_820A04BC:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_820A04C0:
	// stw r11,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r11.u32);
	// addi r4,r31,264
	ctx.r4.s64 = ctx.r31.s64 + 264;
	// stw r30,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x820b5858
	ctx.lr = 0x820A04D4;
	sub_820B5858(ctx, base);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r24,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r24.u32);
loc_820A04F0:
	// lwz r11,256(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r11.u32);
loc_820A04FC:
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// addi r30,r30,-5892
	ctx.r30.s64 = ctx.r30.s64 + -5892;
	// lwz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// blt cr6,0x820a0538
	if (ctx.cr6.lt) goto loc_820A0538;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lbz r10,29(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a0538
	if (!ctx.cr6.eq) goto loc_820A0538;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x820a1288
	ctx.lr = 0x820A0530;
	sub_820A1288(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_820A0538:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
