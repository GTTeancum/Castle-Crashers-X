DEFINE_REX_FUNC(sub_82126298) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298ec
	ctx.lr = 0x821262A0;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r22,r4
	ctx.r22.u64 = ctx.r4.u64;
	// mr r20,r7
	ctx.r20.u64 = ctx.r7.u64;
	// li r19,0
	ctx.r19.s64 = 0;
	// lwz r11,52(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 52);
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x821262d0
	if (ctx.cr0.eq) goto loc_821262D0;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x821264bc
	if (!ctx.cr6.eq) goto loc_821264BC;
	// mr r17,r19
	ctx.r17.u64 = ctx.r19.u64;
	// b 0x821262d4
	goto loc_821262D4;
loc_821262D0:
	// li r17,1
	ctx.r17.s64 = 1;
loc_821262D4:
	// lwz r18,20(r27)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r27.u32 + 20);
	// rlwinm. r25,r11,31,31,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// lwz r11,152(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 152);
	// li r26,1
	ctx.r26.s64 = 1;
	// lwz r24,68(r27)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r27.u32 + 68);
	// mr r21,r19
	ctx.r21.u64 = ctx.r19.u64;
	// clrlwi r23,r11,8
	ctx.r23.u64 = ctx.r11.u32 & 0xFFFFFF;
	// bne 0x821262fc
	if (!ctx.cr0.eq) goto loc_821262FC;
	// cmpwi cr6,r24,3
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 3, ctx.xer);
	// bne cr6,0x82126378
	if (!ctx.cr6.eq) goto loc_82126378;
loc_821262FC:
	// rlwinm r11,r6,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// subf r10,r11,r20
	ctx.r10.u64 = ctx.r20.u64 - ctx.r11.u64;
	// li r8,-1
	ctx.r8.s64 = -1;
	// blt cr6,0x82126368
	if (ctx.cr6.lt) goto loc_82126368;
	// li r8,1
	ctx.r8.s64 = 1;
	// b 0x82126368
	goto loc_82126368;
loc_82126318:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,20(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 20);
	// cmplw cr6,r11,r18
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r18.u32, ctx.xer);
	// bne cr6,0x82126360
	if (!ctx.cr6.eq) goto loc_82126360;
	// lwz r11,52(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 52);
	// rlwinm. r7,r11,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x82126340
	if (!ctx.cr0.eq) goto loc_82126340;
	// lhz r7,72(r9)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r9.u32 + 72);
	// rlwinm. r7,r7,0,22,22
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x82126360
	if (ctx.cr0.eq) goto loc_82126360;
loc_82126340:
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r25,r19
	ctx.r25.u64 = ctx.r19.u64;
	// mr r26,r19
	ctx.r26.u64 = ctx.r19.u64;
	// bne 0x82126374
	if (!ctx.cr0.eq) goto loc_82126374;
	// lhz r11,72(r9)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r9.u32 + 72);
	// rlwinm. r11,r11,0,22,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82126374
	if (!ctx.cr0.eq) goto loc_82126374;
	// li r21,1
	ctx.r21.s64 = 1;
loc_82126360:
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_82126368:
	// cmplw cr6,r10,r20
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r20.u32, ctx.xer);
	// bne cr6,0x82126318
	if (!ctx.cr6.eq) goto loc_82126318;
	// b 0x82126378
	goto loc_82126378;
loc_82126374:
	// mr r21,r19
	ctx.r21.u64 = ctx.r19.u64;
loc_82126378:
	// lwz r11,60(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 60);
	// cmpwi cr6,r24,3
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 3, ctx.xer);
	// lwz r31,64(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 64);
	// subf r30,r31,r11
	ctx.r30.u64 = ctx.r11.u64 - ctx.r31.u64;
	// bne cr6,0x82126490
	if (!ctx.cr6.eq) goto loc_82126490;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// blt cr6,0x821263a0
	if (ctx.cr6.lt) goto loc_821263A0;
	// cmplw cr6,r5,r6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// mr r28,r19
	ctx.r28.u64 = ctx.r19.u64;
	// bgt cr6,0x821263a4
	if (ctx.cr6.gt) goto loc_821263A4;
loc_821263A0:
	// li r28,1
	ctx.r28.s64 = 1;
loc_821263A4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// beq cr6,0x821263b4
	if (ctx.cr6.eq) goto loc_821263B4;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
loc_821263B4:
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82126120
	ctx.lr = 0x821263C8;
	sub_82126120(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82126404
	if (ctx.cr6.eq) goto loc_82126404;
	// subfc r11,r30,r3
	ctx.xer.ca = ctx.r3.u32 >= ctx.r30.u32;
	ctx.r11.u64 = ctx.r3.u64 - ctx.r30.u64;
	// li r24,128
	ctx.r24.s64 = 128;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi. r29,r11,31
	ctx.r29.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x821263fc
	if (!ctx.cr0.eq) goto loc_821263FC;
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x821263fc
	if (!ctx.cr6.lt) goto loc_821263FC;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x821263fc
	if (ctx.cr6.eq) goto loc_821263FC;
	// mr r28,r19
	ctx.r28.u64 = ctx.r19.u64;
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
loc_821263FC:
	// mr r25,r26
	ctx.r25.u64 = ctx.r26.u64;
	// b 0x82126454
	goto loc_82126454;
loc_82126404:
	// addi r11,r30,-4
	ctx.r11.s64 = ctx.r30.s64 + -4;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bgt cr6,0x82126434
	if (ctx.cr6.gt) goto loc_82126434;
	// addi r10,r31,4
	ctx.r10.s64 = ctx.r31.s64 + 4;
	// li r24,128
	ctx.r24.s64 = 128;
	// stw r10,64(r27)
	REX_STORE_U32(ctx.r27.u32 + 64, ctx.r10.u32);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// mr r29,r19
	ctx.r29.u64 = ctx.r19.u64;
	// bge cr6,0x82126498
	if (!ctx.cr6.lt) goto loc_82126498;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x82126498
	if (ctx.cr6.eq) goto loc_82126498;
	// b 0x82126494
	goto loc_82126494;
loc_82126434:
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// mr r25,r26
	ctx.r25.u64 = ctx.r26.u64;
	// bl 0x82126120
	ctx.lr = 0x82126450;
	sub_82126120(ctx, base);
	// li r29,1
	ctx.r29.s64 = 1;
loc_82126454:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82126498
	if (ctx.cr6.eq) goto loc_82126498;
	// cmplwi cr6,r30,2440
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2440, ctx.xer);
	// bge cr6,0x82126478
	if (!ctx.cr6.lt) goto loc_82126478;
	// subf r11,r3,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r3.u64;
	// cmplwi cr6,r11,1220
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1220, ctx.xer);
	// ble cr6,0x82126480
	if (!ctx.cr6.gt) goto loc_82126480;
	// rlwinm r30,r30,31,1,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82126498
	goto loc_82126498;
loc_82126478:
	// cmplwi cr6,r3,256
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 256, ctx.xer);
	// ble cr6,0x82126488
	if (!ctx.cr6.gt) goto loc_82126488;
loc_82126480:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82126498
	goto loc_82126498;
loc_82126488:
	// li r30,1220
	ctx.r30.s64 = 1220;
	// b 0x82126498
	goto loc_82126498;
loc_82126490:
	// mr r29,r19
	ctx.r29.u64 = ctx.r19.u64;
loc_82126494:
	// mr r28,r19
	ctx.r28.u64 = ctx.r19.u64;
loc_82126498:
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x821260b0
	ctx.lr = 0x821264B0;
	sub_821260B0(ctx, base);
	// add r31,r3,r30
	ctx.r31.u64 = ctx.r3.u64 + ctx.r30.u64;
	// cmplw cr6,r31,r22
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r22.u32, ctx.xer);
	// ble cr6,0x821264d0
	if (!ctx.cr6.gt) goto loc_821264D0;
loc_821264BC:
	// stw r19,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r19.u32);
	// mr r17,r19
	ctx.r17.u64 = ctx.r19.u64;
	// sth r19,4(r20)
	REX_STORE_U16(ctx.r20.u32 + 4, ctx.r19.u16);
	// sth r19,6(r20)
	REX_STORE_U16(ctx.r20.u32 + 6, ctx.r19.u16);
	// b 0x82126524
	goto loc_82126524;
loc_821264D0:
	// lwz r11,64(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 64);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r11,64(r27)
	REX_STORE_U32(ctx.r27.u32 + 64, ctx.r11.u32);
	// beq cr6,0x821264f4
	if (ctx.cr6.eq) goto loc_821264F4;
	// lhz r11,72(r27)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + 72);
	// ori r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 512;
	// sth r11,72(r27)
	REX_STORE_U16(ctx.r27.u32 + 72, ctx.r11.u16);
	// b 0x82126508
	goto loc_82126508;
loc_821264F4:
	// lhz r11,72(r27)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + 72);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// rlwinm r5,r11,21,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 21) & 0x1;
	// bl 0x821233b8
	ctx.lr = 0x82126508;
	sub_821233B8(ctx, base);
loc_82126508:
	// lhz r11,72(r27)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + 72);
	// rlwimi r21,r25,1,30,30
	ctx.r21.u64 = (__builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0x2) | (ctx.r21.u64 & 0xFFFFFFFFFFFFFFFD);
	// rlwimi r11,r21,7,23,24
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 7) & 0x180) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFE7F);
	// sth r11,72(r27)
	REX_STORE_U16(ctx.r27.u32 + 72, ctx.r11.u16);
	// stw r27,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r27.u32);
	// sth r31,4(r20)
	REX_STORE_U16(ctx.r20.u32 + 4, ctx.r31.u16);
	// sth r30,6(r20)
	REX_STORE_U16(ctx.r20.u32 + 6, ctx.r30.u16);
loc_82126524:
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
}
