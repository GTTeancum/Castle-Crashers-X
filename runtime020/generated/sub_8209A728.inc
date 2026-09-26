DEFINE_REX_FUNC(sub_8209A728) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f0
	ctx.lr = 0x8209A730;
	__savegprlr_18(ctx, base);
	// stwu r1,-2000(r1)
	ea = -2000 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// addi r30,r11,-16888
	ctx.r30.s64 = ctx.r11.s64 + -16888;
	// beq cr6,0x8209a844
	if (ctx.cr6.eq) goto loc_8209A844;
	// li r18,0
	ctx.r18.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// addi r8,r30,72
	ctx.r8.s64 = ctx.r30.s64 + 72;
	// li r7,68
	ctx.r7.s64 = 68;
loc_8209A75C:
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8209A764:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r4,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r4.u64;
	// beq cr6,0x8209a788
	if (ctx.cr6.eq) goto loc_8209A788;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8209a764
	if (ctx.cr6.eq) goto loc_8209A764;
loc_8209A788:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8209a7ac
	if (ctx.cr6.eq) goto loc_8209A7AC;
	// addi r7,r7,68
	ctx.r7.s64 = ctx.r7.s64 + 68;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,68
	ctx.r8.s64 = ctx.r8.s64 + 68;
	// cmplwi cr6,r7,17408
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 17408, ctx.xer);
	// blt cr6,0x8209a75c
	if (ctx.cr6.lt) goto loc_8209A75C;
	// lhz r20,96(r1)
	ctx.r20.u64 = REX_LOAD_U16(ctx.r1.u32 + 96);
	// b 0x8209a7b4
	goto loc_8209A7B4;
loc_8209A7AC:
	// clrlwi r20,r6,16
	ctx.r20.u64 = ctx.r6.u32 & 0xFFFF;
	// li r5,1
	ctx.r5.s64 = 1;
loc_8209A7B4:
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209a85c
	if (!ctx.cr6.eq) goto loc_8209A85C;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,68
	ctx.r10.s64 = 68;
	// addi r9,r30,68
	ctx.r9.s64 = ctx.r30.s64 + 68;
loc_8209A7CC:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x8209a7f8
	if (!ctx.cr6.eq) goto loc_8209A7F8;
	// addi r10,r10,68
	ctx.r10.s64 = ctx.r10.s64 + 68;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r9,68
	ctx.r9.s64 = ctx.r9.s64 + 68;
	// cmplwi cr6,r10,17408
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 17408, ctx.xer);
	// blt cr6,0x8209a7cc
	if (ctx.cr6.lt) goto loc_8209A7CC;
	// b 0x8209a85c
	goto loc_8209A85C;
loc_8209A7F8:
	// mulli r10,r11,68
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(68));
	// clrlwi r20,r11,16
	ctx.r20.u64 = ctx.r11.u32 & 0xFFFF;
	// add r31,r10,r30
	ctx.r31.u64 = ctx.r10.u64 + ctx.r30.u64;
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
loc_8209A808:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209a808
	if (!ctx.cr6.eq) goto loc_8209A808;
	// subf r11,r19,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r19.u64;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r5,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// bl 0x82129a70
	ctx.lr = 0x8209A834;
	sub_82129A70(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// add r10,r31,r11
	ctx.r10.u64 = ctx.r31.u64 + ctx.r11.u64;
	// stb r18,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, ctx.r18.u8);
	// b 0x8209a85c
	goto loc_8209A85C;
loc_8209A844:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r10,-644
	ctx.r4.s64 = ctx.r10.s64 + -644;
	// bl 0x82053a00
	ctx.lr = 0x8209A854;
	sub_82053A00(ctx, base);
	// li r18,0
	ctx.r18.s64 = 0;
	// mr r20,r18
	ctx.r20.u64 = ctx.r18.u64;
loc_8209A85C:
	// rlwinm r9,r20,2,14,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r11,r20,16
	ctx.r11.u64 = ctx.r20.u32 & 0xFFFF;
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r10,r10,-22008
	ctx.r10.s64 = ctx.r10.s64 + -22008;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,12
	ctx.r8.s64 = ctx.r10.s64 + 12;
	// lwzx r7,r9,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8209ae94
	if (!ctx.cr6.eq) goto loc_8209AE94;
	// mulli r8,r11,68
	ctx.r8.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(68));
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
	// add r31,r9,r10
	ctx.r31.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r21,r8,r11
	ctx.r21.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// addi r3,r11,-636
	ctx.r3.s64 = ctx.r11.s64 + -636;
	// sth r20,4(r31)
	REX_STORE_U16(ctx.r31.u32 + 4, ctx.r20.u16);
	// bl 0x8208c5d8
	ctx.lr = 0x8209A8A8;
	sub_8208C5D8(ctx, base);
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// beq cr6,0x8209ae84
	if (ctx.cr6.eq) goto loc_8209AE84;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r22,r11,26304
	ctx.r22.s64 = ctx.r11.s64 + 26304;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8214a434
	ctx.lr = 0x8209A8C0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// addi r4,r11,-8160
	ctx.r4.s64 = ctx.r11.s64 + -8160;
	// bl 0x821287b0
	ctx.lr = 0x8209A8D0;
	sub_821287B0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209a8e4
	if (ctx.cr6.eq) goto loc_8209A8E4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r11,-612
	ctx.r4.s64 = ctx.r11.s64 + -612;
	// b 0x8209a934
	goto loc_8209A934;
loc_8209A8E4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// addi r4,r11,-596
	ctx.r4.s64 = ctx.r11.s64 + -596;
	// bl 0x821287b0
	ctx.lr = 0x8209A8F4;
	sub_821287B0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209a908
	if (ctx.cr6.eq) goto loc_8209A908;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r11,-592
	ctx.r4.s64 = ctx.r11.s64 + -592;
	// b 0x8209a934
	goto loc_8209A934;
loc_8209A908:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// addi r4,r11,-580
	ctx.r4.s64 = ctx.r11.s64 + -580;
	// bl 0x821287b0
	ctx.lr = 0x8209A918;
	sub_821287B0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209a92c
	if (ctx.cr6.eq) goto loc_8209A92C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r11,-572
	ctx.r4.s64 = ctx.r11.s64 + -572;
	// b 0x8209a934
	goto loc_8209A934;
loc_8209A92C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r11,-560
	ctx.r4.s64 = ctx.r11.s64 + -560;
loc_8209A934:
	// mr r5,r19
	ctx.r5.u64 = ctx.r19.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82127778
	ctx.lr = 0x8209A940;
	sub_82127778(ctx, base);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8209A948:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8209a948
	if (!ctx.cr6.eq) goto loc_8209A948;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// bl 0x82129a70
	ctx.lr = 0x8209A974;
	sub_82129A70(ctx, base);
	// lwz r8,112(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addi r10,r1,116
	ctx.r10.s64 = ctx.r1.s64 + 116;
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// mr r30,r18
	ctx.r30.u64 = ctx.r18.u64;
	// stbx r18,r8,r10
	REX_STORE_U8(ctx.r8.u32 + ctx.r10.u32, ctx.r18.u8);
	// lwz r29,112(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stbx r18,r29,r9
	REX_STORE_U8(ctx.r29.u32 + ctx.r9.u32, ctx.r18.u8);
	// beq cr6,0x8209a9d4
	if (ctx.cr6.eq) goto loc_8209A9D4;
	// li r28,92
	ctx.r28.s64 = 92;
loc_8209A99C:
	// addi r11,r1,116
	ctx.r11.s64 = ctx.r1.s64 + 116;
	// lbzx r10,r30,r11
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// extsb r3,r10
	ctx.r3.s64 = ctx.r10.s8;
	// cmpwi cr6,r3,47
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 47, ctx.xer);
	// bne cr6,0x8209a9bc
	if (!ctx.cr6.eq) goto loc_8209A9BC;
	// addi r11,r1,336
	ctx.r11.s64 = ctx.r1.s64 + 336;
	// stbx r28,r30,r11
	REX_STORE_U8(ctx.r30.u32 + ctx.r11.u32, ctx.r28.u8);
	// b 0x8209a9c8
	goto loc_8209A9C8;
loc_8209A9BC:
	// bl 0x82128a60
	ctx.lr = 0x8209A9C0;
	sub_82128A60(ctx, base);
	// addi r11,r1,336
	ctx.r11.s64 = ctx.r1.s64 + 336;
	// stbx r3,r30,r11
	REX_STORE_U8(ctx.r30.u32 + ctx.r11.u32, ctx.r3.u8);
loc_8209A9C8:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x8209a99c
	if (ctx.cr6.lt) goto loc_8209A99C;
loc_8209A9D4:
	// lbz r10,340(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 340);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// addi r30,r11,-7068
	ctx.r30.s64 = ctx.r11.s64 + -7068;
	// cmplwi cr6,r10,58
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 58, ctx.xer);
	// addi r3,r1,848
	ctx.r3.s64 = ctx.r1.s64 + 848;
	// bne cr6,0x8209a9f8
	if (!ctx.cr6.eq) goto loc_8209A9F8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// b 0x8209aa00
	goto loc_8209AA00;
loc_8209A9F8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r11,3060
	ctx.r4.s64 = ctx.r11.s64 + 3060;
loc_8209AA00:
	// bl 0x82127778
	ctx.lr = 0x8209AA04;
	sub_82127778(ctx, base);
	// addi r11,r1,848
	ctx.r11.s64 = ctx.r1.s64 + 848;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8209AA0C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8209aa0c
	if (!ctx.cr6.eq) goto loc_8209AA0C;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r4,r1,848
	ctx.r4.s64 = ctx.r1.s64 + 848;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,260
	ctx.r3.s64 = ctx.r1.s64 + 260;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r5,256(r1)
	REX_STORE_U32(ctx.r1.u32 + 256, ctx.r5.u32);
	// bl 0x82129a70
	ctx.lr = 0x8209AA38;
	sub_82129A70(ctx, base);
	// lwz r9,256(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 256);
	// addi r10,r1,260
	ctx.r10.s64 = ctx.r1.s64 + 260;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r1,260
	ctx.r5.s64 = ctx.r1.s64 + 260;
	// addi r3,r1,1104
	ctx.r3.s64 = ctx.r1.s64 + 1104;
	// stbx r18,r9,r10
	REX_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r18.u8);
	// bl 0x82127778
	ctx.lr = 0x8209AA54;
	sub_82127778(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8209aa88
	if (!ctx.cr6.eq) goto loc_8209AA88;
	// addi r3,r1,1104
	ctx.r3.s64 = ctx.r1.s64 + 1104;
	// bl 0x820b00d8
	ctx.lr = 0x8209AA68;
	sub_820B00D8(ctx, base);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8209aa88
	if (!ctx.cr6.eq) goto loc_8209AA88;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8214a444
	ctx.lr = 0x8209AA7C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,2000
	ctx.r1.s64 = ctx.r1.s64 + 2000;
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
loc_8209AA88:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209aa9c
	if (ctx.cr6.eq) goto loc_8209AA9C;
	// ld r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 4);
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
loc_8209AA9C:
	// lwz r27,104(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lis r25,-32215
	ctx.r25.s64 = -2111242240;
	// addi r26,r11,29632
	ctx.r26.s64 = ctx.r11.s64 + 29632;
	// addi r23,r10,-1768
	ctx.r23.s64 = ctx.r10.s64 + -1768;
	// stw r27,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r27.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8209ab44
	if (!ctx.cr6.eq) goto loc_8209AB44;
	// lis r11,468
	ctx.r11.s64 = 30670848;
	// mulli r30,r27,140
	ctx.r30.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(140));
	// ori r10,r11,7489
	ctx.r10.u64 = ctx.r11.u64 | 7489;
	// cmplw cr6,r27,r10
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8209aadc
	if (!ctx.cr6.gt) goto loc_8209AADC;
	// li r30,-1
	ctx.r30.s64 = -1;
loc_8209AADC:
	// lbz r11,-22601(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209aafc
	if (!ctx.cr6.eq) goto loc_8209AAFC;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209AAFC;
	sub_820A71E8(ctx, base);
loc_8209AAFC:
	// bl 0x820b5eb8
	ctx.lr = 0x8209AB00;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8209AB10;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209ab3c
	if (ctx.cr6.eq) goto loc_8209AB3C;
	// addic. r11,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r11.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt 0x8209ab34
	if (ctx.cr0.lt) goto loc_8209AB34;
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
loc_8209AB24:
	// stw r18,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r18.u32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,140
	ctx.r10.s64 = ctx.r10.s64 + 140;
	// bge 0x8209ab24
	if (!ctx.cr0.lt) goto loc_8209AB24;
loc_8209AB34:
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x8209ab40
	goto loc_8209AB40;
loc_8209AB3C:
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
loc_8209AB40:
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_8209AB44:
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r18,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r18.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8209ab9c
	if (ctx.cr6.eq) goto loc_8209AB9C;
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r18,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r18.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r18,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r18.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r30,120
	ctx.r5.s64 = ctx.r30.s64 + 120;
	// stw r11,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// addi r4,r30,40
	ctx.r4.s64 = ctx.r30.s64 + 40;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820b0330
	ctx.lr = 0x8209AB88;
	sub_820B0330(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r9,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r9.u32);
	// beq cr6,0x8209abf0
	if (ctx.cr6.eq) goto loc_8209ABF0;
loc_8209AB9C:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8214a444
	ctx.lr = 0x8209ABA4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8209abe0
	if (ctx.cr6.eq) goto loc_8209ABE0;
	// lwz r11,124(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 124);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209abc4
	if (ctx.cr6.eq) goto loc_8209ABC4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820b0d80
	ctx.lr = 0x8209ABC4;
	sub_820B0D80(ctx, base);
loc_8209ABC4:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x820b6498
	ctx.lr = 0x8209ABCC;
	sub_820B6498(ctx, base);
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,-28288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -28288);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8209ABE0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8209ABE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r18,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r18.u32);
	// addi r1,r1,2000
	ctx.r1.s64 = ctx.r1.s64 + 2000;
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
loc_8209ABF0:
	// li r24,256
	ctx.r24.s64 = 256;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r1,1360
	ctx.r10.s64 = ctx.r1.s64 + 1360;
	// li r9,256
	ctx.r9.s64 = 256;
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// addi r8,r1,1616
	ctx.r8.s64 = ctx.r1.s64 + 1616;
	// li r7,256
	ctx.r7.s64 = 256;
	// addi r6,r1,592
	ctx.r6.s64 = ctx.r1.s64 + 592;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x820b0330
	ctx.lr = 0x8209AC1C;
	sub_820B0330(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8209ac44
	if (ctx.cr6.eq) goto loc_8209AC44;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8214a444
	ctx.lr = 0x8209AC2C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x820b02b0
	ctx.lr = 0x8209AC34;
	sub_820B02B0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r18,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r18.u32);
	// addi r1,r1,2000
	ctx.r1.s64 = ctx.r1.s64 + 2000;
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
loc_8209AC44:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209ac58
	if (ctx.cr6.eq) goto loc_8209AC58;
	// bl 0x820a7400
	ctx.lr = 0x8209AC58;
	sub_820A7400(ctx, base);
loc_8209AC58:
	// addi r11,r1,592
	ctx.r11.s64 = ctx.r1.s64 + 592;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_8209AC60:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209ac60
	if (!ctx.cr6.eq) goto loc_8209AC60;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// lbz r10,-22601(r25)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r25.u32 + -22601);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// rotlwi r30,r9,0
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// bne cr6,0x8209ac9c
	if (!ctx.cr6.eq) goto loc_8209AC9C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209AC9C;
	sub_820A71E8(ctx, base);
loc_8209AC9C:
	// bl 0x820b5eb8
	ctx.lr = 0x8209ACA0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r30,1
	ctx.r4.s64 = ctx.r30.s64 + 1;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8209ACB0;
	sub_8209BDD8(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r1,592
	ctx.r11.s64 = ctx.r1.s64 + 592;
	// stw r3,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
loc_8209ACC4:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x8209acc4
	if (!ctx.cr6.eq) goto loc_8209ACC4;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r10,140(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r11,12
	ctx.r30.s64 = ctx.r11.s64 + 12;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82129a70
	ctx.lr = 0x8209AD00;
	sub_82129A70(ctx, base);
	// addi r4,r30,40
	ctx.r4.s64 = ctx.r30.s64 + 40;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r5,80
	ctx.r5.s64 = 80;
	// bl 0x82129a70
	ctx.lr = 0x8209AD10;
	sub_82129A70(ctx, base);
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r27,1
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 1, ctx.xer);
	// ble cr6,0x8209ae78
	if (!ctx.cr6.gt) goto loc_8209AE78;
	// li r30,140
	ctx.r30.s64 = 140;
loc_8209AD20:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x820b0750
	ctx.lr = 0x8209AD28;
	sub_820B0750(ctx, base);
	// cmpwi cr6,r3,-100
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -100, ctx.xer);
	// beq cr6,0x8209aea8
	if (ctx.cr6.eq) goto loc_8209AEA8;
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// addi r10,r1,1360
	ctx.r10.s64 = ctx.r1.s64 + 1360;
	// li r9,256
	ctx.r9.s64 = 256;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r8,r1,1616
	ctx.r8.s64 = ctx.r1.s64 + 1616;
	// li r7,256
	ctx.r7.s64 = 256;
	// addi r6,r1,592
	ctx.r6.s64 = ctx.r1.s64 + 592;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x820b0330
	ctx.lr = 0x8209AD58;
	sub_820B0330(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r29,4(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8209ada0
	if (ctx.cr6.eq) goto loc_8209ADA0;
	// lbz r11,-22601(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209ad8c
	if (!ctx.cr6.eq) goto loc_8209AD8C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209AD8C;
	sub_820A71E8(ctx, base);
loc_8209AD8C:
	// bl 0x820b5eb8
	ctx.lr = 0x8209AD90;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bf18
	ctx.lr = 0x8209ADA0;
	sub_8209BF18(ctx, base);
loc_8209ADA0:
	// addi r11,r1,592
	ctx.r11.s64 = ctx.r1.s64 + 592;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_8209ADA8:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209ada8
	if (!ctx.cr6.eq) goto loc_8209ADA8;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// lbz r10,-22601(r25)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r25.u32 + -22601);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// rotlwi r29,r9,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// bne cr6,0x8209ade4
	if (!ctx.cr6.eq) goto loc_8209ADE4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209ADE4;
	sub_820A71E8(ctx, base);
loc_8209ADE4:
	// bl 0x820b5eb8
	ctx.lr = 0x8209ADE8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r29,1
	ctx.r4.s64 = ctx.r29.s64 + 1;
	// lwzx r3,r11,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8209ADF8;
	sub_8209BDD8(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r1,592
	ctx.r11.s64 = ctx.r1.s64 + 592;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// stw r3,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + ctx.r30.u64;
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
loc_8209AE14:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x8209ae14
	if (!ctx.cr6.eq) goto loc_8209AE14;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r10,140(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r29,r11,12
	ctx.r29.s64 = ctx.r11.s64 + 12;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82129a70
	ctx.lr = 0x8209AE58;
	sub_82129A70(ctx, base);
	// addi r4,r29,40
	ctx.r4.s64 = ctx.r29.s64 + 40;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r5,80
	ctx.r5.s64 = 80;
	// bl 0x82129a70
	ctx.lr = 0x8209AE68;
	sub_82129A70(ctx, base);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r30,r30,140
	ctx.r30.s64 = ctx.r30.s64 + 140;
	// cmplw cr6,r28,r27
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x8209ad20
	if (ctx.cr6.lt) goto loc_8209AD20;
loc_8209AE78:
	// stw r28,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8214a444
	ctx.lr = 0x8209AE84;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8209AE84:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// addi r3,r11,-488
	ctx.r3.s64 = ctx.r11.s64 + -488;
	// bl 0x8208c5d8
	ctx.lr = 0x8209AE94;
	sub_8208C5D8(ctx, base);
loc_8209AE94:
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r20,-22602(r10)
	REX_STORE_U8(ctx.r10.u32 + -22602, ctx.r20.u8);
	// addi r1,r1,2000
	ctx.r1.s64 = ctx.r1.s64 + 2000;
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
loc_8209AEA8:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8214a444
	ctx.lr = 0x8209AEB0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// addi r3,r11,-548
	ctx.r3.s64 = ctx.r11.s64 + -548;
	// bl 0x8208c5d8
	ctx.lr = 0x8209AEC0;
	sub_8208C5D8(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x820b02b0
	ctx.lr = 0x8209AEC8;
	sub_820B02B0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r18,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r18.u32);
	// addi r1,r1,2000
	ctx.r1.s64 = ctx.r1.s64 + 2000;
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
}
