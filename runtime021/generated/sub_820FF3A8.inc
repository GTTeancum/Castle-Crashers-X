DEFINE_REX_FUNC(sub_820FF3A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x820FF3B0;
	__savegprlr_21(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,372(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r22,r7
	ctx.r22.u64 = ctx.r7.u64;
	// mr r23,r8
	ctx.r23.u64 = ctx.r8.u64;
	// rlwinm. r27,r11,0,28,28
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq 0x820ff3fc
	if (ctx.cr0.eq) goto loc_820FF3FC;
	// lwz r8,720(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 720);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// ori r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 | 32;
	// ori r7,r7,65534
	ctx.r7.u64 = ctx.r7.u64 | 65534;
	// stw r8,720(r30)
	REX_STORE_U32(ctx.r30.u32 + 720, ctx.r8.u32);
	// lwz r8,24(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + 24);
	// subf r8,r8,r7
	ctx.r8.u64 = ctx.r7.u64 - ctx.r8.u64;
	// oris r8,r8,65016
	ctx.r8.u64 = ctx.r8.u64 | 4260888576;
	// b 0x820ff410
	goto loc_820FF410;
loc_820FF3FC:
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lwz r7,24(r26)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r26.u32 + 24);
	// ori r8,r8,65534
	ctx.r8.u64 = ctx.r8.u64 | 65534;
	// subf r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	// oris r8,r8,65532
	ctx.r8.u64 = ctx.r8.u64 | 4294705152;
loc_820FF410:
	// stw r8,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// clrlwi r29,r11,30
	ctx.r29.u64 = ctx.r11.u32 & 0x3;
	// lwz r8,720(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 720);
	// rlwinm. r11,r8,0,14,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820ff428
	if (!ctx.cr0.eq) goto loc_820FF428;
	// ori r29,r29,64
	ctx.r29.u64 = ctx.r29.u64 | 64;
loc_820FF428:
	// lbz r11,383(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 383);
	// li r4,15
	ctx.r4.s64 = 15;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// clrlwi. r5,r11,28
	ctx.r5.u64 = ctx.r11.u32 & 0xF;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// stb r11,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r11.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r28,0
	ctx.r28.s64 = 0;
	// clrlwi r7,r11,24
	ctx.r7.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x820ff4a8
	if (ctx.cr6.eq) goto loc_820FF4A8;
	// beq 0x820ff460
	if (ctx.cr0.eq) goto loc_820FF460;
	// cmplwi cr6,r5,2
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 2, ctx.xer);
	// beq cr6,0x820ff460
	if (ctx.cr6.eq) goto loc_820FF460;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// b 0x820ff47c
	goto loc_820FF47C;
loc_820FF460:
	// lwz r11,24(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 24);
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// slw r4,r8,r11
	ctx.r4.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r11.u8 & 0x3F));
	// slw r11,r8,r6
	ctx.r11.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r6.u8 & 0x3F));
	// or r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 | ctx.r7.u64;
	// stb r11,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r11.u8);
loc_820FF47C:
	// lwz r3,100(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 100);
	// addi r21,r1,104
	ctx.r21.s64 = ctx.r1.s64 + 104;
	// lwz r11,396(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 396);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stw r8,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// stw r28,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r28.u32);
	// rlwinm r11,r11,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// stw r21,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r21.u32);
	// stw r3,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// stw r8,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r8.u32);
	// b 0x820ff4d8
	goto loc_820FF4D8;
loc_820FF4A8:
	// beq 0x820ff4bc
	if (ctx.cr0.eq) goto loc_820FF4BC;
	// cmplwi cr6,r5,2
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 2, ctx.xer);
	// beq cr6,0x820ff4bc
	if (ctx.cr6.eq) goto loc_820FF4BC;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// b 0x820ff4c8
	goto loc_820FF4C8;
loc_820FF4BC:
	// ori r11,r7,240
	ctx.r11.u64 = ctx.r7.u64 | 240;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// stb r11,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r11.u8);
loc_820FF4C8:
	// lwz r11,400(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 400);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
loc_820FF4D8:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r8,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r8.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r3,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r3.u32);
	// beq cr6,0x820ff4f8
	if (ctx.cr6.eq) goto loc_820FF4F8;
	// stw r9,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r9.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r10,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
loc_820FF4F8:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x820ff518
	if (ctx.cr6.eq) goto loc_820FF518;
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stwx r22,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r22.u32);
	// stwx r23,r10,r3
	REX_STORE_U32(ctx.r10.u32 + ctx.r3.u32, ctx.r23.u32);
loc_820FF518:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820ff5cc
	if (!ctx.cr6.eq) goto loc_820FF5CC;
	// cmplwi cr6,r5,15
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 15, ctx.xer);
	// beq cr6,0x820ff53c
	if (ctx.cr6.eq) goto loc_820FF53C;
	// li r11,7
	ctx.r11.s64 = 7;
	// oris r10,r4,32768
	ctx.r10.u64 = ctx.r4.u64 | 2147483648;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// stw r10,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// b 0x820ff55c
	goto loc_820FF55C;
loc_820FF53C:
	// rlwinm r11,r7,0,24,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xF0;
	// cmplwi cr6,r11,112
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 112, ctx.xer);
	// beq cr6,0x820ff554
	if (ctx.cr6.eq) goto loc_820FF554;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// b 0x820ff558
	goto loc_820FF558;
loc_820FF554:
	// stw r28,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r28.u32);
loc_820FF558:
	// stw r4,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r4.u32);
loc_820FF55C:
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,400(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 400);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stw r28,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// bl 0x82108df8
	ctx.lr = 0x820FF580;
	sub_82108DF8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x820ff5a4
	if (!ctx.cr0.lt) goto loc_820FF5A4;
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// ori r11,r11,4101
	ctx.r11.u64 = ctx.r11.u64 | 4101;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x820ff68c
	if (!ctx.cr6.eq) goto loc_820FF68C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,4328
	ctx.r3.u64 = ctx.r3.u64 | 4328;
	// b 0x820ff68c
	goto loc_820FF68C;
loc_820FF5A4:
	// lwz r11,720(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 720);
	// rlwinm. r11,r11,0,14,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820ff5cc
	if (!ctx.cr0.eq) goto loc_820FF5CC;
	// lwz r11,396(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 396);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x820ff5c4
	if (ctx.cr6.eq) goto loc_820FF5C4;
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// b 0x820ff5c8
	goto loc_820FF5C8;
loc_820FF5C4:
	// ori r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 8192;
loc_820FF5C8:
	// stw r11,396(r26)
	REX_STORE_U32(ctx.r26.u32 + 396, ctx.r11.u32);
loc_820FF5CC:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x820ff688
	if (ctx.cr6.eq) goto loc_820FF688;
	// lwz r11,396(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 396);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ff688
	if (ctx.cr0.eq) goto loc_820FF688;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r10,r24,280
	ctx.r10.s64 = ctx.r24.s64 + 280;
	// addi r11,r24,136
	ctx.r11.s64 = ctx.r24.s64 + 136;
	// addi r3,r30,380
	ctx.r3.s64 = ctx.r30.s64 + 380;
	// li r4,4
	ctx.r4.s64 = 4;
loc_820FF5F8:
	// lwz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820ff648
	if (ctx.cr6.eq) goto loc_820FF648;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x820ff614
	if (ctx.cr6.eq) goto loc_820FF614;
	// cmplw cr6,r25,r6
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x820ff648
	if (!ctx.cr6.eq) goto loc_820FF648;
loc_820FF614:
	// lwz r8,396(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 396);
	// rlwinm. r8,r8,0,4,4
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x820ff648
	if (ctx.cr0.eq) goto loc_820FF648;
	// ld r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// clrldi r7,r23,32
	ctx.r7.u64 = ctx.r23.u64 & 0xFFFFFFFF;
	// stw r6,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// std r8,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r8.u64);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
loc_820FF648:
	// addic. r4,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x820ff5f8
	if (!ctx.cr0.eq) goto loc_820FF5F8;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820ff688
	if (ctx.cr6.eq) goto loc_820FF688;
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// mr r8,r23
	ctx.r8.u64 = ctx.r23.u64;
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820FF688;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FF688:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_820FF68C:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
