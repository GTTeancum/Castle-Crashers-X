DEFINE_REX_FUNC(sub_82126530) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298ec
	ctx.lr = 0x82126538;
	__savegprlr_17(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r28,0(r10)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r21,r5
	ctx.r21.u64 = ctx.r5.u64;
	// mr r17,r8
	ctx.r17.u64 = ctx.r8.u64;
	// mr r20,r9
	ctx.r20.u64 = ctx.r9.u64;
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r29,52(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// li r23,0
	ctx.r23.s64 = 0;
	// lwz r22,68(r31)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// li r25,0
	ctx.r25.s64 = 0;
	// subf. r19,r28,r11
	ctx.r19.u64 = ctx.r11.u64 - ctx.r28.u64;
	ctx.cr0.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r24,0
	ctx.r24.s64 = 0;
	// beq 0x82126590
	if (ctx.cr0.eq) goto loc_82126590;
	// lhz r9,72(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 72);
	// li r22,128
	ctx.r22.s64 = 128;
	// rlwinm. r9,r9,0,22,22
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82126590
	if (ctx.cr0.eq) goto loc_82126590;
	// ori r29,r29,3
	ctx.r29.u64 = ctx.r29.u64 | 3;
loc_82126590:
	// lwz r9,60(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x821265a8
	if (!ctx.cr6.lt) goto loc_821265A8;
	// rlwinm r11,r29,0,30,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF3;
	// rlwinm r11,r11,0,24,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF8FF;
	// ori r29,r11,3
	ctx.r29.u64 = ctx.r11.u64 | 3;
loc_821265A8:
	// clrlwi. r11,r29,31
	ctx.r11.u64 = ctx.r29.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r18,1
	ctx.r18.s64 = 1;
	// beq 0x821265f8
	if (ctx.cr0.eq) goto loc_821265F8;
	// rlwinm. r11,r29,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r18,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r18.u32);
	// mr r26,r18
	ctx.r26.u64 = ctx.r18.u64;
	// bne 0x821265d4
	if (!ctx.cr0.eq) goto loc_821265D4;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r11,168(r9)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r9.u32 + 168);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,168(r9)
	REX_STORE_U16(ctx.r9.u32 + 168, ctx.r11.u16);
loc_821265D4:
	// rlwinm. r11,r29,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821265e4
	if (ctx.cr0.eq) goto loc_821265E4;
	// li r9,3
	ctx.r9.s64 = 3;
	// b 0x821265fc
	goto loc_821265FC;
loc_821265E4:
	// rlwinm r11,r29,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x8;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// b 0x821265fc
	goto loc_821265FC;
loc_821265F8:
	// li r9,0
	ctx.r9.s64 = 0;
loc_821265FC:
	// rlwinm. r11,r29,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82126638
	if (ctx.cr0.eq) goto loc_82126638;
	// mr r23,r18
	ctx.r23.u64 = ctx.r18.u64;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x82126620
	if (ctx.cr6.eq) goto loc_82126620;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r11,170(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 170);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,170(r10)
	REX_STORE_U16(ctx.r10.u32 + 170, ctx.r11.u16);
loc_82126620:
	// lhz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 72);
	// lwz r8,20(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r6,r11,24,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0x1;
	// rlwinm r10,r11,25,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	// xori r25,r6,1
	ctx.r25.u64 = ctx.r6.u64 ^ 1;
	// lhz r24,170(r8)
	ctx.r24.u64 = REX_LOAD_U16(ctx.r8.u32 + 170);
loc_82126638:
	// rlwinm. r11,r29,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82126644
	if (ctx.cr0.eq) goto loc_82126644;
	// stw r18,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r18.u32);
loc_82126644:
	// lwz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x82126654
	if (!ctx.cr6.gt) goto loc_82126654;
	// stw r9,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r9.u32);
loc_82126654:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = ctx.r11.u64 ^ 1;
	// bl 0x82121230
	ctx.lr = 0x82126678;
	sub_82121230(ctx, base);
	// rlwinm. r11,r29,0,21,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x600;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// beq 0x8212669c
	if (ctx.cr0.eq) goto loc_8212669C;
	// addi r11,r27,9
	ctx.r11.s64 = ctx.r27.s64 + 9;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stwx r31,r11,r30
	REX_STORE_U32(ctx.r11.u32 + ctx.r30.u32, ctx.r31.u32);
	// lhz r11,330(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 330);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,330(r30)
	REX_STORE_U16(ctx.r30.u32 + 330, ctx.r11.u16);
loc_8212669C:
	// rlwinm r11,r27,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r3,36(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// sth r24,86(r1)
	REX_STORE_U16(ctx.r1.u32 + 86, ctx.r24.u16);
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// lwz r10,152(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 152);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// lhz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 76);
	// clrlwi r10,r10,8
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFFFF;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// add r29,r11,r3
	ctx.r29.u64 = ctx.r11.u64 + ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82125a88
	ctx.lr = 0x821266E0;
	sub_82125A88(ctx, base);
	// lwz r10,32(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// add r11,r3,r28
	ctx.r11.u64 = ctx.r3.u64 + ctx.r28.u64;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r26,r3,r29
	ctx.r26.u64 = ctx.r3.u64 + ctx.r29.u64;
	// stw r10,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r10.u32);
	// sth r11,0(r20)
	REX_STORE_U16(ctx.r20.u32 + 0, ctx.r11.u16);
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82126754
	if (!ctx.cr6.eq) goto loc_82126754;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,80(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lhz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 168);
	// sth r11,0(r10)
	REX_STORE_U16(ctx.r10.u32 + 0, ctx.r11.u16);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bne cr6,0x82126728
	if (!ctx.cr6.eq) goto loc_82126728;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82126728:
	// addi r10,r27,9
	ctx.r10.s64 = ctx.r27.s64 + 9;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stwx r11,r10,r30
	REX_STORE_U32(ctx.r10.u32 + ctx.r30.u32, ctx.r11.u32);
	// lhz r11,330(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 330);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,330(r30)
	REX_STORE_U16(ctx.r30.u32 + 330, ctx.r11.u16);
	// stw r18,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r18.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,172(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// oris r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 1073741824;
	// stw r10,172(r11)
	REX_STORE_U32(ctx.r11.u32 + 172, ctx.r10.u32);
loc_82126754:
	// addi r30,r31,80
	ctx.r30.s64 = ctx.r31.s64 + 80;
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// beq cr6,0x82126778
	if (ctx.cr6.eq) goto loc_82126778;
loc_82126760:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplw cr6,r19,r11
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82126778
	if (ctx.cr6.lt) goto loc_82126778;
	// subf. r19,r11,r19
	ctx.r19.u64 = ctx.r19.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// bne 0x82126760
	if (!ctx.cr0.eq) goto loc_82126760;
loc_82126778:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x821267bc
	if (ctx.cr6.eq) goto loc_821267BC;
loc_82126780:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r29,r19,r11
	ctx.r29.u64 = ctx.r11.u64 - ctx.r19.u64;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// ble cr6,0x82126794
	if (!ctx.cr6.gt) goto loc_82126794;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_82126794:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// add r4,r11,r19
	ctx.r4.u64 = ctx.r11.u64 + ctx.r19.u64;
	// bl 0x82129a70
	ctx.lr = 0x821267A8;
	sub_82129A70(ctx, base);
	// subf. r28,r29,r28
	ctx.r28.u64 = ctx.r28.u64 - ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// add r26,r29,r26
	ctx.r26.u64 = ctx.r29.u64 + ctx.r26.u64;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// li r19,0
	ctx.r19.s64 = 0;
	// bne 0x82126780
	if (!ctx.cr0.eq) goto loc_82126780;
loc_821267BC:
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82126858
	if (ctx.cr6.lt) goto loc_82126858;
	// lbz r11,74(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x821267e8
	if (!ctx.cr0.eq) goto loc_821267E8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x82122b78
	ctx.lr = 0x821267E4;
	sub_82122B78(ctx, base);
	// b 0x82126858
	goto loc_82126858;
loc_821267E8:
	// rlwinm. r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82126804
	if (ctx.cr0.eq) goto loc_82126804;
	// lbz r10,75(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 75);
	// clrlwi r11,r11,25
	ctx.r11.u64 = ctx.r11.u32 & 0x7F;
	// ori r10,r10,128
	ctx.r10.u64 = ctx.r10.u64 | 128;
	// stb r11,74(r31)
	REX_STORE_U8(ctx.r31.u32 + 74, ctx.r11.u8);
	// stb r10,75(r31)
	REX_STORE_U8(ctx.r31.u32 + 75, ctx.r10.u8);
loc_82126804:
	// lbz r11,74(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 74);
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82126824
	if (ctx.cr0.eq) goto loc_82126824;
	// lbz r10,75(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 75);
	// andi. r11,r11,239
	ctx.r11.u64 = ctx.r11.u64 & 239;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ori r10,r10,16
	ctx.r10.u64 = ctx.r10.u64 | 16;
	// stb r11,74(r31)
	REX_STORE_U8(ctx.r31.u32 + 74, ctx.r11.u8);
	// stb r10,75(r31)
	REX_STORE_U8(ctx.r31.u32 + 75, ctx.r10.u8);
loc_82126824:
	// lhz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 72);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lbz r10,75(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 75);
	// ori r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 16384;
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// sth r11,72(r31)
	REX_STORE_U16(ctx.r31.u32 + 72, ctx.r11.u16);
	// beq 0x82126854
	if (ctx.cr0.eq) goto loc_82126854;
	// ori r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 32768;
	// sth r11,72(r31)
	REX_STORE_U16(ctx.r31.u32 + 72, ctx.r11.u16);
	// bl 0x821235b0
	ctx.lr = 0x82126850;
	sub_821235B0(ctx, base);
	// b 0x82126858
	goto loc_82126858;
loc_82126854:
	// bl 0x82122bd0
	ctx.lr = 0x82126858;
	sub_82122BD0(ctx, base);
loc_82126858:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
}
