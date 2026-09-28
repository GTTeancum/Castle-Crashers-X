DEFINE_REX_FUNC(sub_821031E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f0
	ctx.lr = 0x821031E8;
	__savegprlr_18(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r4,268(r1)
	REX_STORE_U32(ctx.r1.u32 + 268, ctx.r4.u32);
	// stw r5,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, ctx.r5.u32);
	// mr r18,r6
	ctx.r18.u64 = ctx.r6.u64;
	// cmplwi cr6,r5,37
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 37, ctx.xer);
	// blt cr6,0x82103658
	if (ctx.cr6.lt) goto loc_82103658;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r8,r4,37
	ctx.r8.s64 = ctx.r4.s64 + 37;
	// addi r7,r5,-37
	ctx.r7.s64 = ctx.r5.s64 + -37;
	// lhz r23,28(r4)
	ctx.r23.u64 = REX_LOAD_U16(ctx.r4.u32 + 28);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// lhz r22,30(r4)
	ctx.r22.u64 = REX_LOAD_U16(ctx.r4.u32 + 30);
	// lwz r26,4(r4)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// ld r25,8(r4)
	ctx.r25.u64 = REX_LOAD_U64(ctx.r4.u32 + 8);
	// lwz r19,16(r4)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r24,20(r4)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r21,24(r4)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// lbz r11,32(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 32);
	// lbz r28,33(r4)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r4.u32 + 33);
	// lbz r27,34(r4)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r4.u32 + 34);
	// lbz r10,35(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 35);
	// lbz r9,36(r4)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r4.u32 + 36);
	// stw r8,268(r1)
	REX_STORE_U32(ctx.r1.u32 + 268, ctx.r8.u32);
	// stw r7,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, ctx.r7.u32);
	// beq cr6,0x8210325c
	if (ctx.cr6.eq) goto loc_8210325C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1306
	ctx.r3.u64 = ctx.r3.u64 | 1306;
	// b 0x821037c4
	goto loc_821037C4;
loc_8210325C:
	// lwz r8,28(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// beq cr6,0x82103274
	if (ctx.cr6.eq) goto loc_82103274;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,117
	ctx.r3.u64 = ctx.r3.u64 | 117;
	// b 0x821037c4
	goto loc_821037C4;
loc_82103274:
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r5,r28,24
	ctx.r5.u64 = ctx.r28.u32 & 0xFF;
	// cmplw cr6,r6,r5
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, ctx.xer);
	// bgt cr6,0x82103658
	if (ctx.cr6.gt) goto loc_82103658;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r4,r27,24
	ctx.r4.u64 = ctx.r27.u32 & 0xFF;
	// cmplw cr6,r7,r4
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, ctx.xer);
	// bgt cr6,0x82103658
	if (ctx.cr6.gt) goto loc_82103658;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x821032a4
	if (!ctx.cr6.eq) goto loc_821032A4;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82103658
	if (ctx.cr6.eq) goto loc_82103658;
loc_821032A4:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x821032b4
	if (!ctx.cr6.eq) goto loc_821032B4;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82103658
	if (ctx.cr6.eq) goto loc_82103658;
loc_821032B4:
	// rlwinm. r10,r26,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x821032c4
	if (ctx.cr0.eq) goto loc_821032C4;
	// rlwinm. r11,r26,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82103658
	if (!ctx.cr0.eq) goto loc_82103658;
loc_821032C4:
	// rlwinm. r20,r26,0,27,27
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq 0x821032d4
	if (ctx.cr0.eq) goto loc_821032D4;
	// rlwinm. r11,r26,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82103658
	if (!ctx.cr0.eq) goto loc_82103658;
loc_821032D4:
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// bne cr6,0x821032e4
	if (!ctx.cr6.eq) goto loc_821032E4;
	// rlwinm. r11,r26,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82103658
	if (ctx.cr0.eq) goto loc_82103658;
loc_821032E4:
	// cmplwi cr6,r23,1020
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 1020, ctx.xer);
	// bgt cr6,0x82103658
	if (ctx.cr6.gt) goto loc_82103658;
	// cmplwi cr6,r22,31
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 31, ctx.xer);
	// bgt cr6,0x82103658
	if (ctx.cr6.gt) goto loc_82103658;
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq cr6,0x82103524
	if (ctx.cr6.eq) goto loc_82103524;
	// rlwinm. r11,r26,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// beq 0x8210331c
	if (ctx.cr0.eq) goto loc_8210331C;
	// rlwinm. r9,r11,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82103324
	if (!ctx.cr0.eq) goto loc_82103324;
loc_82103310:
	// lis r3,-32747
	ctx.r3.s64 = -2146107392;
	// ori r3,r3,21001
	ctx.r3.u64 = ctx.r3.u64 | 21001;
	// b 0x821037c4
	goto loc_821037C4;
loc_8210331C:
	// rlwinm. r9,r11,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8210342c
	if (!ctx.cr0.eq) goto loc_8210342C;
loc_82103324:
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// bne cr6,0x82103384
	if (!ctx.cr6.eq) goto loc_82103384;
	// clrlwi. r9,r26,31
	ctx.r9.u64 = ctx.r26.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82103340
	if (ctx.cr0.eq) goto loc_82103340;
	// rlwinm. r9,r11,0,2,2
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82103348
	if (!ctx.cr0.eq) goto loc_82103348;
	// b 0x821033c4
	goto loc_821033C4;
loc_82103340:
	// rlwinm. r9,r11,0,2,2
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x821033c4
	if (!ctx.cr0.eq) goto loc_821033C4;
loc_82103348:
	// rlwinm. r9,r26,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8210335c
	if (ctx.cr0.eq) goto loc_8210335C;
	// rlwinm. r9,r11,0,3,3
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82103364
	if (!ctx.cr0.eq) goto loc_82103364;
	// b 0x821033c4
	goto loc_821033C4;
loc_8210335C:
	// rlwinm. r9,r11,0,3,3
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x821033c4
	if (!ctx.cr0.eq) goto loc_821033C4;
loc_82103364:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82103374
	if (ctx.cr6.eq) goto loc_82103374;
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// b 0x82103380
	goto loc_82103380;
loc_82103374:
	// rlwinm. r10,r26,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x821033b4
	if (ctx.cr0.eq) goto loc_821033B4;
	// rlwinm. r11,r11,0,5,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
loc_82103380:
	// beq 0x821033c4
	if (ctx.cr0.eq) goto loc_821033C4;
loc_82103384:
	// addi r29,r31,380
	ctx.r29.s64 = ctx.r31.s64 + 380;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82103390:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821033d8
	if (ctx.cr6.eq) goto loc_821033D8;
	// lwz r9,396(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 396);
	// rlwinm. r8,r26,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x821033d0
	if (ctx.cr0.eq) goto loc_821033D0;
	// rlwinm. r9,r9,0,3,3
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82103310
	if (ctx.cr0.eq) goto loc_82103310;
	// b 0x821033d8
	goto loc_821033D8;
loc_821033B4:
	// rlwinm. r10,r11,0,4,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x821033c4
	if (!ctx.cr0.eq) goto loc_821033C4;
	// rlwinm. r11,r11,0,5,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82103384
	if (ctx.cr0.eq) goto loc_82103384;
loc_821033C4:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1610
	ctx.r3.u64 = ctx.r3.u64 | 1610;
	// b 0x821037c4
	goto loc_821037C4;
loc_821033D0:
	// rlwinm. r9,r9,0,3,3
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8210342c
	if (!ctx.cr0.eq) goto loc_8210342C;
loc_821033D8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// blt cr6,0x82103390
	if (ctx.cr6.lt) goto loc_82103390;
	// lbz r9,170(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 170);
	// subf r11,r6,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r6.u64;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x82103420
	if (ctx.cr6.lt) goto loc_82103420;
	// lbz r11,171(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 171);
	// subf r7,r7,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r7.u64;
	// cmpw cr6,r7,r11
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x821035b0
	if (!ctx.cr6.lt) goto loc_821035B0;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// subf r10,r6,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r6.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x82103438
	if (!ctx.cr6.lt) goto loc_82103438;
loc_82103420:
	// lis r3,-32747
	ctx.r3.s64 = -2146107392;
	// ori r3,r3,20994
	ctx.r3.u64 = ctx.r3.u64 | 20994;
	// b 0x821037c4
	goto loc_821037C4;
loc_8210342C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1365
	ctx.r3.u64 = ctx.r3.u64 | 1365;
	// b 0x821037c4
	goto loc_821037C4;
loc_82103438:
	// li r30,0
	ctx.r30.s64 = 0;
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r6,r31,392
	ctx.r6.s64 = ctx.r31.s64 + 392;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82103448:
	// lwz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821034ac
	if (ctx.cr6.eq) goto loc_821034AC;
	// lwz r9,396(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 396);
	// rlwinm. r5,r9,0,2,2
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq 0x821034ac
	if (ctx.cr0.eq) goto loc_821034AC;
	// rlwinm r9,r9,0,3,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFDFFFFFFF;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,396(r10)
	REX_STORE_U32(ctx.r10.u32 + 396, ctx.r9.u32);
	// addi r3,r8,-1
	ctx.r3.s64 = ctx.r8.s64 + -1;
	// lbz r9,170(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 170);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lbz r10,171(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 171);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stwx r3,r11,r5
	REX_STORE_U32(ctx.r11.u32 + ctx.r5.u32, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwx r5,r11,r4
	REX_STORE_U32(ctx.r11.u32 + ctx.r4.u32, ctx.r5.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stb r10,171(r31)
	REX_STORE_U8(ctx.r31.u32 + 171, ctx.r10.u8);
	// stb r9,170(r31)
	REX_STORE_U8(ctx.r31.u32 + 170, ctx.r9.u8);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpw cr6,r7,r10
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x821034b8
	if (!ctx.cr6.lt) goto loc_821034B8;
loc_821034AC:
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r6,r6,-4
	ctx.r6.s64 = ctx.r6.s64 + -4;
	// bne 0x82103448
	if (!ctx.cr0.eq) goto loc_82103448;
loc_821034B8:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82138ae0
	ctx.lr = 0x821034CC;
	sub_82138AE0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x821034f4
	if (!ctx.cr0.eq) goto loc_821034F4;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82138990
	ctx.lr = 0x821034EC;
	sub_82138990(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82103510
	if (ctx.cr0.eq) goto loc_82103510;
loc_821034F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82136e38
	ctx.lr = 0x821034FC;
	sub_82136E38(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x821037c4
	if (ctx.cr0.lt) goto loc_821037C4;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x821037c4
	goto loc_821037C4;
loc_82103510:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821005e8
	ctx.lr = 0x82103518;
	sub_821005E8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x821037c4
	if (ctx.cr0.lt) goto loc_821037C4;
	// b 0x821035b0
	goto loc_821035B0;
loc_82103524:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x821037c0
	if (ctx.cr6.eq) goto loc_821037C0;
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// beq cr6,0x821037c0
	if (ctx.cr6.eq) goto loc_821037C0;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r11,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82103550
	if (ctx.cr0.eq) goto loc_82103550;
	// rlwinm. r11,r26,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82103558
	if (!ctx.cr0.eq) goto loc_82103558;
	// b 0x82103658
	goto loc_82103658;
loc_82103550:
	// rlwinm. r11,r26,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82103658
	if (!ctx.cr0.eq) goto loc_82103658;
loc_82103558:
	// addi r29,r31,380
	ctx.r29.s64 = ctx.r31.s64 + 380;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_82103564:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82103584
	if (!ctx.cr6.eq) goto loc_82103584;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82103564
	if (ctx.cr6.lt) goto loc_82103564;
	// b 0x821035b0
	goto loc_821035B0;
loc_82103584:
	// addi r11,r11,95
	ctx.r11.s64 = ctx.r11.s64 + 95;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// lwz r11,396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm. r11,r11,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821035a8
	if (ctx.cr0.eq) goto loc_821035A8;
	// rlwinm. r11,r26,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x821035b0
	if (!ctx.cr0.eq) goto loc_821035B0;
	// b 0x82103658
	goto loc_82103658;
loc_821035A8:
	// rlwinm. r11,r26,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82103658
	if (!ctx.cr0.eq) goto loc_82103658;
loc_821035B0:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// lwz r10,720(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// stb r28,168(r31)
	REX_STORE_U8(ctx.r31.u32 + 168, ctx.r28.u8);
	// rlwimi r11,r26,2,29,29
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0x4) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFFB);
	// std r25,40(r31)
	REX_STORE_U64(ctx.r31.u32 + 40, ctx.r25.u64);
	// rlwinm r8,r26,0,28,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x8;
	// stb r27,169(r31)
	REX_STORE_U8(ctx.r31.u32 + 169, ctx.r27.u8);
	// rlwimi r9,r11,2,27,28
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x18) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFE7);
	// rlwinm r11,r10,0,6,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFC3FFFFFF;
	// rlwinm r9,r9,2,25,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x70;
	// addi r28,r31,228
	ctx.r28.s64 = ctx.r31.s64 + 228;
	// or r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 | ctx.r8.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r7,r8,23,0,8
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 23) & 0xFF800000;
	// li r9,0
	ctx.r9.s64 = 0;
	// or r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 | ctx.r11.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,276
	ctx.r6.s64 = ctx.r1.s64 + 276;
	// addi r5,r1,268
	ctx.r5.s64 = ctx.r1.s64 + 268;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821089a8
	ctx.lr = 0x82103614;
	sub_821089A8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x821037c4
	if (ctx.cr0.lt) goto loc_821037C4;
	// addi r27,r31,240
	ctx.r27.s64 = ctx.r31.s64 + 240;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,276
	ctx.r6.s64 = ctx.r1.s64 + 276;
	// addi r5,r1,268
	ctx.r5.s64 = ctx.r1.s64 + 268;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82107f30
	ctx.lr = 0x82103644;
	sub_82107F30(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x821037c4
	if (ctx.cr0.lt) goto loc_821037C4;
	// lwz r11,276(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82103664
	if (!ctx.cr6.gt) goto loc_82103664;
loc_82103658:
	// lis r3,-32747
	ctx.r3.s64 = -2146107392;
	// ori r3,r3,10
	ctx.r3.u64 = ctx.r3.u64 | 10;
	// b 0x821037c4
	goto loc_821037C4;
loc_82103664:
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// lwz r4,268(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fcfb0
	ctx.lr = 0x82103674;
	sub_820FCFB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x821037c4
	if (ctx.cr0.lt) goto loc_821037C4;
	// lwz r11,268(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// lwz r10,276(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// add r4,r23,r11
	ctx.r4.u64 = ctx.r23.u64 + ctx.r11.u64;
	// subf r11,r23,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r23.u64;
	// stw r4,268(r1)
	REX_STORE_U32(ctx.r1.u32 + 268, ctx.r4.u32);
	// stw r11,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, ctx.r11.u32);
	// beq cr6,0x821036b4
	if (ctx.cr6.eq) goto loc_821036B4;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// addi r3,r31,256
	ctx.r3.s64 = ctx.r31.s64 + 256;
	// bl 0x821094f0
	ctx.lr = 0x821036A8;
	sub_821094F0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x821037c4
	if (ctx.cr0.lt) goto loc_821037C4;
	// lwz r4,268(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
loc_821036B4:
	// lwz r11,276(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// add r10,r22,r4
	ctx.r10.u64 = ctx.r22.u64 + ctx.r4.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// subf r11,r22,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r22.u64;
	// stw r10,268(r1)
	REX_STORE_U32(ctx.r1.u32 + 268, ctx.r10.u32);
	// stw r11,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, ctx.r11.u32);
loc_821036CC:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821036f8
	if (ctx.cr6.eq) goto loc_821036F8;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82108800
	ctx.lr = 0x821036E8;
	sub_82108800(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82107e78
	ctx.lr = 0x821036F8;
	sub_82107E78(ctx, base);
loc_821036F8:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x821036cc
	if (ctx.cr6.lt) goto loc_821036CC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821015d0
	ctx.lr = 0x82103710;
	sub_821015D0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x821037c4
	if (ctx.cr0.lt) goto loc_821037C4;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8210375c
	if (ctx.cr6.lt) goto loc_8210375C;
	// beq cr6,0x82103750
	if (ctx.cr6.eq) goto loc_82103750;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x82103748
	if (!ctx.cr6.eq) goto loc_82103748;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82103748
	if (ctx.cr6.eq) goto loc_82103748;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82103750
	if (!ctx.cr0.eq) goto loc_82103750;
loc_82103748:
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82103754
	goto loc_82103754;
loc_82103750:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82103754:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fcde0
	ctx.lr = 0x8210375C;
	sub_820FCDE0(ctx, base);
loc_8210375C:
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// bne cr6,0x821037c0
	if (!ctx.cr6.eq) goto loc_821037C0;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x82103790
	if (ctx.cr6.eq) goto loc_82103790;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821087b0
	ctx.lr = 0x82103778;
	sub_821087B0(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x821037c0
	if (ctx.cr0.eq) goto loc_821037C0;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// b 0x821037b8
	goto loc_821037B8;
loc_82103790:
	// rlwinm. r11,r26,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821037c0
	if (ctx.cr0.eq) goto loc_821037C0;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82107e28
	ctx.lr = 0x821037A4;
	sub_82107E28(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x821037c0
	if (ctx.cr0.eq) goto loc_821037C0;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
loc_821037B8:
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821037C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821037C0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821037C4:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
}
