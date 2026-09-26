DEFINE_REX_FUNC(sub_8212E370) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8212E378;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x8212e398
	if (ctx.cr6.eq) goto loc_8212E398;
	// stw r25,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r25.u32);
loc_8212E398:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x8212e3c8
	if (!ctx.cr6.eq) goto loc_8212E3C8;
loc_8212E3A0:
	// bl 0x821294e0
	ctx.lr = 0x8212E3A4;
	sub_821294E0(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212c298
	ctx.lr = 0x8212E3C4;
	sub_8212C298(ctx, base);
	// b 0x8212e654
	goto loc_8212E654;
loc_8212E3C8:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x8212e3e0
	if (ctx.cr6.eq) goto loc_8212E3E0;
	// cmpwi cr6,r28,2
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2, ctx.xer);
	// blt cr6,0x8212e3a0
	if (ctx.cr6.lt) goto loc_8212E3A0;
	// cmpwi cr6,r28,36
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 36, ctx.xer);
	// bgt cr6,0x8212e3a0
	if (ctx.cr6.gt) goto loc_8212E3A0;
loc_8212E3E0:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lbz r31,0(r25)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r29,r25,1
	ctx.r29.s64 = ctx.r25.s64 + 1;
	// addi r30,r11,32376
	ctx.r30.s64 = ctx.r11.s64 + 32376;
	// lwz r10,32376(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32376);
loc_8212E3F8:
	// lwz r11,172(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x8212e41c
	if (!ctx.cr6.gt) goto loc_8212E41C;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// bl 0x8212e338
	ctx.lr = 0x8212E414;
	sub_8212E338(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8212e42c
	goto loc_8212E42C;
loc_8212E41C:
	// lwz r11,200(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 200);
	// rlwinm r9,r31,1,23,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0x1FE;
	// lhzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r11.u32);
	// rlwinm r3,r11,0,28,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
loc_8212E42C:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8212e440
	if (ctx.cr6.eq) goto loc_8212E440;
	// lbz r31,0(r29)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// b 0x8212e3f8
	goto loc_8212E3F8;
loc_8212E440:
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// cmpwi cr6,r11,45
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 45, ctx.xer);
	// bne cr6,0x8212e454
	if (!ctx.cr6.eq) goto loc_8212E454;
	// ori r24,r24,2
	ctx.r24.u64 = ctx.r24.u64 | 2;
	// b 0x8212e45c
	goto loc_8212E45C;
loc_8212E454:
	// cmpwi cr6,r11,43
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 43, ctx.xer);
	// bne cr6,0x8212e464
	if (!ctx.cr6.eq) goto loc_8212E464;
loc_8212E45C:
	// lbz r31,0(r29)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
loc_8212E464:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x8212e648
	if (ctx.cr6.lt) goto loc_8212E648;
	// cmpwi cr6,r28,1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 1, ctx.xer);
	// beq cr6,0x8212e648
	if (ctx.cr6.eq) goto loc_8212E648;
	// cmpwi cr6,r28,36
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 36, ctx.xer);
	// bgt cr6,0x8212e648
	if (ctx.cr6.gt) goto loc_8212E648;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x8212e4c0
	if (!ctx.cr6.eq) goto loc_8212E4C0;
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// beq cr6,0x8212e498
	if (ctx.cr6.eq) goto loc_8212E498;
	// li r28,10
	ctx.r28.s64 = 10;
	// b 0x8212e4f8
	goto loc_8212E4F8;
loc_8212E498:
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,120
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 120, ctx.xer);
	// beq cr6,0x8212e4b8
	if (ctx.cr6.eq) goto loc_8212E4B8;
	// cmpwi cr6,r11,88
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 88, ctx.xer);
	// beq cr6,0x8212e4b8
	if (ctx.cr6.eq) goto loc_8212E4B8;
	// li r28,8
	ctx.r28.s64 = 8;
	// b 0x8212e4f8
	goto loc_8212E4F8;
loc_8212E4B8:
	// li r28,16
	ctx.r28.s64 = 16;
	// b 0x8212e4c8
	goto loc_8212E4C8;
loc_8212E4C0:
	// cmpwi cr6,r28,16
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 16, ctx.xer);
	// bne cr6,0x8212e4f8
	if (!ctx.cr6.eq) goto loc_8212E4F8;
loc_8212E4C8:
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// bne cr6,0x8212e4f8
	if (!ctx.cr6.eq) goto loc_8212E4F8;
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,120
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 120, ctx.xer);
	// beq cr6,0x8212e4ec
	if (ctx.cr6.eq) goto loc_8212E4EC;
	// cmpwi cr6,r11,88
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 88, ctx.xer);
	// bne cr6,0x8212e4f8
	if (!ctx.cr6.eq) goto loc_8212E4F8;
loc_8212E4EC:
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// lbz r31,1(r29)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r29.u32 + 1);
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
loc_8212E4F8:
	// li r27,-1
	ctx.r27.s64 = -1;
	// lwz r8,200(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 200);
	// twllei r28,0
	if (ctx.r28.s32 == 0 || ctx.r28.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r9,r27,r28
	ctx.r9.u64 = uint32_t(ctx.r28.u32 ? ctx.r27.u32 / ctx.r28.u32 : 0);
loc_8212E508:
	// rlwinm r11,r31,1,23,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0x1FE;
	// lhzx r11,r11,r8
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r8.u32);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8212e524
	if (ctx.cr0.eq) goto loc_8212E524;
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// addi r11,r11,-48
	ctx.r11.s64 = ctx.r11.s64 + -48;
	// b 0x8212e54c
	goto loc_8212E54C;
loc_8212E524:
	// andi. r11,r11,259
	ctx.r11.u64 = ctx.r11.u64 & 259;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212e58c
	if (ctx.cr0.eq) goto loc_8212E58C;
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// cmpwi cr6,r11,97
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 97, ctx.xer);
	// blt cr6,0x8212e548
	if (ctx.cr6.lt) goto loc_8212E548;
	// cmpwi cr6,r11,122
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 122, ctx.xer);
	// bgt cr6,0x8212e548
	if (ctx.cr6.gt) goto loc_8212E548;
	// addi r11,r11,-32
	ctx.r11.s64 = ctx.r11.s64 + -32;
loc_8212E548:
	// addi r11,r11,-55
	ctx.r11.s64 = ctx.r11.s64 + -55;
loc_8212E54C:
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bge cr6,0x8212e58c
	if (!ctx.cr6.lt) goto loc_8212E58C;
	// ori r24,r24,8
	ctx.r24.u64 = ctx.r24.u64 | 8;
	// cmplw cr6,r26,r9
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8212e5ac
	if (ctx.cr6.lt) goto loc_8212E5AC;
	// bne cr6,0x8212e580
	if (!ctx.cr6.eq) goto loc_8212E580;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// twllei r28,0
	if (ctx.r28.s32 == 0 || ctx.r28.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r7,r10,r28
	ctx.r7.u64 = uint32_t(ctx.r28.u32 ? ctx.r10.u32 / ctx.r28.u32 : 0);
	// mullw r7,r7,r28
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r28.s32);
	// subf r10,r7,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r7.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8212e5ac
	if (!ctx.cr6.gt) goto loc_8212E5AC;
loc_8212E580:
	// ori r24,r24,4
	ctx.r24.u64 = ctx.r24.u64 | 4;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// bne cr6,0x8212e5b4
	if (!ctx.cr6.eq) goto loc_8212E5B4;
loc_8212E58C:
	// rlwinm. r11,r24,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r29,r29,-1
	ctx.r29.s64 = ctx.r29.s64 + -1;
	// bne 0x8212e5c0
	if (!ctx.cr0.eq) goto loc_8212E5C0;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x8212e5a4
	if (ctx.cr6.eq) goto loc_8212E5A4;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
loc_8212E5A4:
	// li r26,0
	ctx.r26.s64 = 0;
	// b 0x8212e628
	goto loc_8212E628;
loc_8212E5AC:
	// mullw r10,r26,r28
	ctx.r10.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8212E5B4:
	// lbz r31,0(r29)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// b 0x8212e508
	goto loc_8212E508;
loc_8212E5C0:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// rlwinm. r11,r24,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r31,r10,65535
	ctx.r31.u64 = ctx.r10.u64 | 65535;
	// bne 0x8212e5fc
	if (!ctx.cr0.eq) goto loc_8212E5FC;
	// clrlwi. r11,r24,31
	ctx.r11.u64 = ctx.r24.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8212e628
	if (!ctx.cr0.eq) goto loc_8212E628;
	// rlwinm. r11,r24,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212e5ec
	if (ctx.cr0.eq) goto loc_8212E5EC;
	// cmplw cr6,r26,r30
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r30.u32, ctx.xer);
	// bgt cr6,0x8212e5fc
	if (ctx.cr6.gt) goto loc_8212E5FC;
loc_8212E5EC:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8212e628
	if (!ctx.cr6.eq) goto loc_8212E628;
	// cmplw cr6,r26,r31
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x8212e628
	if (!ctx.cr6.gt) goto loc_8212E628;
loc_8212E5FC:
	// bl 0x821294e0
	ctx.lr = 0x8212E600;
	sub_821294E0(ctx, base);
	// li r11,34
	ctx.r11.s64 = 34;
	// clrlwi. r10,r24,31
	ctx.r10.u64 = ctx.r24.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq 0x8212e618
	if (ctx.cr0.eq) goto loc_8212E618;
	// mr r26,r27
	ctx.r26.u64 = ctx.r27.u64;
	// b 0x8212e628
	goto loc_8212E628;
loc_8212E618:
	// rlwinm. r11,r24,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
	// bne 0x8212e628
	if (!ctx.cr0.eq) goto loc_8212E628;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
loc_8212E628:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x8212e634
	if (ctx.cr6.eq) goto loc_8212E634;
	// stw r29,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r29.u32);
loc_8212E634:
	// rlwinm. r11,r24,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8212e640
	if (ctx.cr0.eq) goto loc_8212E640;
	// neg r26,r26
	ctx.r26.s64 = static_cast<int64_t>(-ctx.r26.u64);
loc_8212E640:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// b 0x8212e658
	goto loc_8212E658;
loc_8212E648:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x8212e654
	if (ctx.cr6.eq) goto loc_8212E654;
	// stw r25,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r25.u32);
loc_8212E654:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8212E658:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
