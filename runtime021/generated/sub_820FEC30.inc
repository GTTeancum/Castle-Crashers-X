DEFINE_REX_FUNC(sub_820FEC30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x820FEC38;
	__savegprlr_14(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// stw r6,348(r1)
	REX_STORE_U32(ctx.r1.u32 + 348, ctx.r6.u32);
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// stw r7,356(r1)
	REX_STORE_U32(ctx.r1.u32 + 356, ctx.r7.u32);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// stw r24,332(r1)
	REX_STORE_U32(ctx.r1.u32 + 332, ctx.r24.u32);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// stw r25,340(r1)
	REX_STORE_U32(ctx.r1.u32 + 340, ctx.r25.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r23,324(r1)
	REX_STORE_U32(ctx.r1.u32 + 324, ctx.r23.u32);
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// stw r8,364(r1)
	REX_STORE_U32(ctx.r1.u32 + 364, ctx.r8.u32);
	// lwz r22,100(r11)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// stw r22,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r22.u32);
	// bl 0x820fd8a8
	ctx.lr = 0x820FEC7C;
	sub_820FD8A8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// blt 0x820fec8c
	if (ctx.cr0.lt) goto loc_820FEC8C;
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_820FEC8C:
	// lwz r11,420(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 420);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820feca0
	if (ctx.cr6.eq) goto loc_820FECA0;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x820feca4
	goto loc_820FECA4;
loc_820FECA0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_820FECA4:
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820feccc
	if (ctx.cr0.eq) goto loc_820FECCC;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820feccc
	if (ctx.cr6.eq) goto loc_820FECCC;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x820fecc4
	if (!ctx.cr6.eq) goto loc_820FECC4;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820feccc
	if (!ctx.cr6.eq) goto loc_820FECCC;
loc_820FECC4:
	// li r11,-1
	ctx.r11.s64 = -1;
	// b 0x820fecd0
	goto loc_820FECD0;
loc_820FECCC:
	// li r11,-97
	ctx.r11.s64 = -97;
loc_820FECD0:
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// li r16,0
	ctx.r16.s64 = 0;
	// li r14,1
	ctx.r14.s64 = 1;
	// mr r26,r16
	ctx.r26.u64 = ctx.r16.u64;
	// std r16,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r16.u64);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// stw r16,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r16.u32);
	// beq cr6,0x820fedc8
	if (ctx.cr6.eq) goto loc_820FEDC8;
	// addi r27,r1,112
	ctx.r27.s64 = ctx.r1.s64 + 112;
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
	// mr r30,r16
	ctx.r30.u64 = ctx.r16.u64;
loc_820FED04:
	// lwz r29,0(r28)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lhz r31,80(r1)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ld r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r29.u32 + 16);
	// std r11,0(r27)
	REX_STORE_U64(ctx.r27.u32 + 0, ctx.r11.u64);
	// bl 0x820fd0f8
	ctx.lr = 0x820FED1C;
	sub_820FD0F8(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// and r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 & ctx.r31.u64;
	// rlwinm. r10,r9,0,25,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x60;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// bne 0x820fed38
	if (!ctx.cr0.eq) goto loc_820FED38;
	// andi. r10,r31,65439
	ctx.r10.u64 = ctx.r31.u64 & 65439;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sth r10,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
loc_820FED38:
	// andi. r11,r11,80
	ctx.r11.u64 = ctx.r11.u64 & 80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x820fed6c
	if (ctx.cr0.eq) goto loc_820FED6C;
	// mr r11,r16
	ctx.r11.u64 = ctx.r16.u64;
	// slw r8,r14,r26
	ctx.r8.u64 = ctx.r26.u8 & 0x20 ? 0 : (ctx.r14.u32 << (ctx.r26.u8 & 0x3F));
loc_820FED4C:
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// or r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 | ctx.r8.u64;
	// stb r7,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// blt cr6,0x820fed4c
	if (ctx.cr6.lt) goto loc_820FED4C;
loc_820FED6C:
	// lwz r11,396(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 396);
	// rlwinm. r10,r11,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820fed88
	if (ctx.cr0.eq) goto loc_820FED88;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lhzx r8,r30,r10
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + ctx.r10.u32);
	// ori r8,r8,1
	ctx.r8.u64 = ctx.r8.u64 | 1;
	// sthx r8,r30,r10
	REX_STORE_U16(ctx.r30.u32 + ctx.r10.u32, ctx.r8.u16);
loc_820FED88:
	// rlwinm. r10,r11,0,13,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820feda0
	if (ctx.cr0.eq) goto loc_820FEDA0;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lhzx r8,r30,r10
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + ctx.r10.u32);
	// ori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 | 2;
	// sthx r8,r30,r10
	REX_STORE_U16(ctx.r30.u32 + ctx.r10.u32, ctx.r8.u16);
loc_820FEDA0:
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// rlwinm r11,r11,0,17,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// stw r11,396(r29)
	REX_STORE_U32(ctx.r29.u32 + 396, ctx.r11.u32);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// addi r27,r27,8
	ctx.r27.s64 = ctx.r27.s64 + 8;
	// sthx r9,r30,r10
	REX_STORE_U16(ctx.r30.u32 + ctx.r10.u32, ctx.r9.u16);
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// cmplw cr6,r26,r25
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x820fed04
	if (ctx.cr6.lt) goto loc_820FED04;
loc_820FEDC8:
	// lwz r11,720(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 720);
	// mr r15,r16
	ctx.r15.u64 = ctx.r16.u64;
	// mr r28,r16
	ctx.r28.u64 = ctx.r16.u64;
	// rlwinm r20,r11,13,27,27
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 13) & 0x10;
	// li r17,-1
	ctx.r17.s64 = -1;
loc_820FEDDC:
	// addi r11,r28,95
	ctx.r11.s64 = ctx.r28.s64 + 95;
	// rlwinm r18,r11,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r18,r23
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + ctx.r23.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ff058
	if (ctx.cr6.eq) goto loc_820FF058;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x820fe9e0
	ctx.lr = 0x820FEDFC;
	sub_820FE9E0(ctx, base);
	// lhz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// and r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ctx.r11.u64;
	// andi. r9,r10,80
	ctx.r9.u64 = ctx.r10.u64 & 80;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrlwi r19,r10,16
	ctx.r19.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x820fee24
	if (ctx.cr0.eq) goto loc_820FEE24;
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// li r9,255
	ctx.r9.s64 = 255;
	// stbx r9,r28,r10
	REX_STORE_U8(ctx.r28.u32 + ctx.r10.u32, ctx.r9.u8);
loc_820FEE24:
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x820ff058
	if (ctx.cr6.eq) goto loc_820FF058;
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// lwz r27,332(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 332);
	// rlwinm r23,r11,0,27,28
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x18;
	// rlwinm r22,r11,0,25,26
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x60;
	// addi r25,r1,104
	ctx.r25.s64 = ctx.r1.s64 + 104;
	// addi r24,r1,112
	ctx.r24.s64 = ctx.r1.s64 + 112;
	// lbzx r21,r28,r10
	ctx.r21.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r10.u32);
loc_820FEE4C:
	// slw r11,r14,r26
	ctx.r11.u64 = ctx.r26.u8 & 0x20 ? 0 : (ctx.r14.u32 << (ctx.r26.u8 & 0x3F));
	// lwz r31,0(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// and. r11,r11,r21
	ctx.r11.u64 = ctx.r11.u64 & ctx.r21.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// beq 0x820fee98
	if (ctx.cr0.eq) goto loc_820FEE98;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820b5a08
	ctx.lr = 0x820FEE7C;
	sub_820B5A08(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x820fee90
	if (!ctx.cr0.eq) goto loc_820FEE90;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820fee98
	if (!ctx.cr6.eq) goto loc_820FEE98;
loc_820FEE90:
	// andi. r29,r29,65519
	ctx.r29.u64 = ctx.r29.u64 & 65519;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// andi. r30,r30,65471
	ctx.r30.u64 = ctx.r30.u64 & 65471;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
loc_820FEE98:
	// cmplwi cr6,r28,255
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 255, ctx.xer);
	// bne cr6,0x820feea8
	if (!ctx.cr6.eq) goto loc_820FEEA8;
	// li r11,15
	ctx.r11.s64 = 15;
	// b 0x820feeb0
	goto loc_820FEEB0;
loc_820FEEA8:
	// slw r11,r14,r28
	ctx.r11.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r14.u32 << (ctx.r28.u8 & 0x3F));
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_820FEEB0:
	// lbz r10,392(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 392);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820feee4
	if (!ctx.cr0.eq) goto loc_820FEEE4;
	// cmplwi cr6,r28,255
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 255, ctx.xer);
	// bne cr6,0x820feed0
	if (!ctx.cr6.eq) goto loc_820FEED0;
	// li r11,15
	ctx.r11.s64 = 15;
	// b 0x820feed8
	goto loc_820FEED8;
loc_820FEED0:
	// slw r11,r14,r28
	ctx.r11.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r14.u32 << (ctx.r28.u8 & 0x3F));
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_820FEED8:
	// rlwinm r11,r11,4,24,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xF0;
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820feeec
	if (ctx.cr0.eq) goto loc_820FEEEC;
loc_820FEEE4:
	// li r29,0
	ctx.r29.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
loc_820FEEEC:
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// and r10,r11,r19
	ctx.r10.u64 = ctx.r11.u64 & ctx.r19.u64;
	// clrlwi. r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820fef3c
	if (ctx.cr0.eq) goto loc_820FEF3C;
	// lhz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 0);
	// and. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fef3c
	if (ctx.cr0.eq) goto loc_820FEF3C;
	// lwz r10,324(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// lwz r9,40(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lwzx r11,r18,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + ctx.r10.u32);
	// lwz r8,36(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// and. r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fef24
	if (ctx.cr0.eq) goto loc_820FEF24;
	// rlwinm r16,r20,0,27,27
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x10;
loc_820FEF24:
	// lwz r9,36(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// and. r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fef4c
	if (ctx.cr0.eq) goto loc_820FEF4C;
	// rlwinm r15,r20,0,27,27
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x10;
	// b 0x820fef4c
	goto loc_820FEF4C;
loc_820FEF3C:
	// lwz r10,324(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// rlwinm r20,r20,0,28,26
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// li r16,0
	ctx.r16.s64 = 0;
	// li r15,0
	ctx.r15.s64 = 0;
loc_820FEF4C:
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// and r9,r11,r19
	ctx.r9.u64 = ctx.r11.u64 & ctx.r19.u64;
	// clrlwi. r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fefc0
	if (ctx.cr0.eq) goto loc_820FEFC0;
	// lhz r9,0(r25)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + 0);
	// and. r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fefc0
	if (ctx.cr0.eq) goto loc_820FEFC0;
	// lwzx r11,r18,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + ctx.r10.u32);
	// lwz r9,32(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r8,28(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// and. r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 & ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fef84
	if (ctx.cr0.eq) goto loc_820FEF84;
	// slw r9,r14,r28
	ctx.r9.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r14.u32 << (ctx.r28.u8 & 0x3F));
	// or r20,r9,r20
	ctx.r20.u64 = ctx.r9.u64 | ctx.r20.u64;
loc_820FEF84:
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// and. r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fefc0
	if (ctx.cr0.eq) goto loc_820FEFC0;
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// rlwinm. r9,r11,0,6,6
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fefc0
	if (ctx.cr0.eq) goto loc_820FEFC0;
	// lbz r9,393(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 393);
	// slw r8,r14,r28
	ctx.r8.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r14.u32 << (ctx.r28.u8 & 0x3F));
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// ori r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 32768;
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r9,393(r31)
	REX_STORE_U8(ctx.r31.u32 + 393, ctx.r9.u8);
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// b 0x820fefd4
	goto loc_820FEFD4;
loc_820FEFC0:
	// lbz r11,393(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 393);
	// slw r9,r14,r28
	ctx.r9.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r14.u32 << (ctx.r28.u8 & 0x3F));
	// andc r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ~ctx.r9.u64;
	// mr r6,r17
	ctx.r6.u64 = ctx.r17.u64;
	// stb r11,393(r31)
	REX_STORE_U8(ctx.r31.u32 + 393, ctx.r11.u8);
loc_820FEFD4:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// rlwinm. r9,r11,0,4,4
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820fefec
	if (!ctx.cr0.eq) goto loc_820FEFEC;
	// lwz r9,364(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 364);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820ff02c
	if (ctx.cr6.eq) goto loc_820FF02C;
loc_820FEFEC:
	// rlwinm. r11,r11,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820ff02c
	if (!ctx.cr0.eq) goto loc_820FF02C;
	// lwz r3,424(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 424);
	// ld r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ff020
	if (ctx.cr6.eq) goto loc_820FF020;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820FF018;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x820ff024
	goto loc_820FF024;
loc_820FF020:
	// li r29,0
	ctx.r29.s64 = 0;
loc_820FF024:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x820ff164
	if (ctx.cr6.lt) goto loc_820FF164;
loc_820FF02C:
	// lwz r11,340(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 340);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// addi r24,r24,8
	ctx.r24.s64 = ctx.r24.s64 + 8;
	// addi r25,r25,2
	ctx.r25.s64 = ctx.r25.s64 + 2;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820fee4c
	if (ctx.cr6.lt) goto loc_820FEE4C;
	// lwz r22,92(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// rotlwi r25,r11,0
	ctx.r25.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r24,332(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 332);
	// lwz r23,324(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
loc_820FF058:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplwi cr6,r28,4
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 4, ctx.xer);
	// blt cr6,0x820feddc
	if (ctx.cr6.lt) goto loc_820FEDDC;
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// bne cr6,0x820ff078
	if (!ctx.cr6.eq) goto loc_820FF078;
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// bne cr6,0x820ff078
	if (!ctx.cr6.eq) goto loc_820FF078;
	// rlwinm r20,r20,0,28,26
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_820FF078:
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// lwz r3,400(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 400);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// bl 0x82108e98
	ctx.lr = 0x820FF088;
	sub_82108E98(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x820ff164
	if (!ctx.cr0.eq) goto loc_820FF164;
	// lwz r3,420(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 420);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ff0c4
	if (ctx.cr6.eq) goto loc_820FF0C4;
	// mr r9,r15
	ctx.r9.u64 = ctx.r15.u64;
	// lwz r10,364(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 364);
	// mr r8,r16
	ctx.r8.u64 = ctx.r16.u64;
	// lwz r7,356(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 356);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// lwz r6,348(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 348);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x8210aa68
	ctx.lr = 0x820FF0BC;
	sub_8210AA68(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x820ff164
	if (ctx.cr0.lt) goto loc_820FF164;
loc_820FF0C4:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x820ff164
	if (ctx.cr6.eq) goto loc_820FF164;
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
	// mr r26,r25
	ctx.r26.u64 = ctx.r25.u64;
loc_820FF0D8:
	// lwz r31,0(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820FF0F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820ff100
	if (ctx.cr0.eq) goto loc_820FF100;
	// mr r30,r14
	ctx.r30.u64 = ctx.r14.u64;
loc_820FF100:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// rlwinm. r10,r11,0,13,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820ff114
	if (ctx.cr0.eq) goto loc_820FF114;
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// ori r30,r10,2
	ctx.r30.u64 = ctx.r10.u64 | 2;
loc_820FF114:
	// lhz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r27.u32 + 0);
	// clrlwi r9,r30,16
	ctx.r9.u64 = ctx.r30.u32 & 0xFFFF;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820ff12c
	if (!ctx.cr6.eq) goto loc_820FF12C;
	// rlwinm. r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820ff154
	if (ctx.cr0.eq) goto loc_820FF154;
loc_820FF12C:
	// rlwinm. r10,r11,0,4,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r11,r11,0,21,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF7FF;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// beq 0x820ff154
	if (ctx.cr0.eq) goto loc_820FF154;
	// lwz r3,12(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820FF154;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FF154:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// addi r27,r27,2
	ctx.r27.s64 = ctx.r27.s64 + 2;
	// bne 0x820ff0d8
	if (!ctx.cr0.eq) goto loc_820FF0D8;
loc_820FF164:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
