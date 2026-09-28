DEFINE_REX_FUNC(sub_82102A60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x82102A68;
	__savegprlr_14(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r7,388(r1)
	REX_STORE_U32(ctx.r1.u32 + 388, ctx.r7.u32);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r21,r28
	ctx.r21.u64 = ctx.r28.u64;
	// stw r28,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r26,364(r1)
	REX_STORE_U32(ctx.r1.u32 + 364, ctx.r26.u32);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// stw r21,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// mr r19,r6
	ctx.r19.u64 = ctx.r6.u64;
	// mr r15,r8
	ctx.r15.u64 = ctx.r8.u64;
	// mr r14,r9
	ctx.r14.u64 = ctx.r9.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// mr r17,r28
	ctx.r17.u64 = ctx.r28.u64;
	// mr r18,r28
	ctx.r18.u64 = ctx.r28.u64;
	// mr r16,r28
	ctx.r16.u64 = ctx.r28.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82102ae8
	if (ctx.cr6.eq) goto loc_82102AE8;
	// addi r26,r1,112
	ctx.r26.s64 = ctx.r1.s64 + 112;
loc_82102ABC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// bl 0x82109548
	ctx.lr = 0x82102AC8;
	sub_82109548(ctx, base);
	// stw r30,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r30.u32);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// lwz r30,88(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82102abc
	if (!ctx.cr6.eq) goto loc_82102ABC;
	// stw r21,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// b 0x82102b48
	goto loc_82102B48;
loc_82102AE8:
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// lwz r6,532(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 532);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820fcd60
	ctx.lr = 0x82102B00;
	sub_820FCD60(ctx, base);
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,536(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 536);
	// li r4,19
	ctx.r4.s64 = 19;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820fcd60
	ctx.lr = 0x82102B18;
	sub_820FCD60(ctx, base);
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r6,540(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 540);
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820fcd60
	ctx.lr = 0x82102B30;
	sub_820FCD60(ctx, base);
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r6,544(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 544);
	// li r4,19
	ctx.r4.s64 = 19;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820fcd60
	ctx.lr = 0x82102B48;
	sub_820FCD60(ctx, base);
loc_82102B48:
	// rlwinm r10,r21,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// li r20,0
	ctx.r20.s64 = 0;
	// add r22,r10,r11
	ctx.r22.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r24,r1,128
	ctx.r24.s64 = ctx.r1.s64 + 128;
	// stw r22,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r22.u32);
	// addi r23,r1,144
	ctx.r23.s64 = ctx.r1.s64 + 144;
	// addi r25,r19,27
	ctx.r25.s64 = ctx.r19.s64 + 27;
loc_82102B68:
	// ld r4,0(r27)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r27.u32 + 0);
	// cmpldi cr6,r4,0
	ctx.cr6.compare<uint64_t>(ctx.r4.u64, 0, ctx.xer);
	// beq cr6,0x82102e60
	if (ctx.cr6.eq) goto loc_82102E60;
	// lhz r11,-3(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + -3);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// stw r10,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
	// beq 0x82102bb4
	if (ctx.cr0.eq) goto loc_82102BB4;
	// lbz r11,171(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 171);
	// lbz r10,169(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 169);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82102bc4
	if (ctx.cr6.lt) goto loc_82102BC4;
	// lbz r11,170(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 170);
	// lbz r10,168(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 168);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82102e88
	if (!ctx.cr6.lt) goto loc_82102E88;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// b 0x82102bc4
	goto loc_82102BC4;
loc_82102BB4:
	// lbz r11,170(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 170);
	// lbz r10,168(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 168);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82102e88
	if (!ctx.cr6.lt) goto loc_82102E88;
loc_82102BC4:
	// rlwinm. r21,r30,31,31,31
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// beq 0x82102bd8
	if (ctx.cr0.eq) goto loc_82102BD8;
	// lwz r11,396(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 396);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82102e94
	if (!ctx.cr6.eq) goto loc_82102E94;
loc_82102BD8:
	// rlwinm r11,r30,0,27,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x18;
	// cmplwi cr6,r11,24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 24, ctx.xer);
	// beq cr6,0x82102e94
	if (ctx.cr6.eq) goto loc_82102E94;
	// rlwinm r11,r30,0,25,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x60;
	// cmplwi cr6,r11,96
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 96, ctx.xer);
	// beq cr6,0x82102e94
	if (ctx.cr6.eq) goto loc_82102E94;
	// lwz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// rlwinm r10,r30,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x100;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// lwz r9,0(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
	// std r4,0(r23)
	REX_STORE_U64(ctx.r23.u32 + 0, ctx.r4.u64);
	// li r7,0
	ctx.r7.s64 = 0;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x8210bb48
	ctx.lr = 0x82102C28;
	sub_8210BB48(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82102f20
	if (ctx.cr0.eq) goto loc_82102F20;
	// lwz r11,-19(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -19);
	// rlwinm r5,r30,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x80;
	// stw r31,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r31.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// lwz r8,396(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// rlwimi r8,r30,23,6,6
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 23) & 0x2000000) | (ctx.r8.u64 & 0xFFFFFFFFFDFFFFFF);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// lwz r11,-15(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -15);
	// rlwinm r7,r30,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x20;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// cntlzw r11,r5
	ctx.r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r6,r30,0,25,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x40;
	// lwz r30,364(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 364);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// lwz r4,-11(r25)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r25.u32 + -11);
	// stw r4,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r4.u32);
	// rlwinm r3,r8,0,12,6
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFE0FFFFF;
	// xori r5,r11,1
	ctx.r5.u64 = ctx.r11.u64 ^ 1;
	// lwz r11,-7(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -7);
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r8,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r8.u32);
	// stw r30,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// lbz r11,168(r19)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r19.u32 + 168);
	// rlwinm r11,r11,28,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0x1;
	// rlwimi r10,r11,4,27,27
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0x10) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFEF);
	// rlwimi r9,r10,2,25,26
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x60) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFF9F);
	// rlwinm r11,r9,2,23,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x1C0;
	// or r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 | ctx.r7.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 | ctx.r6.u64;
	// rlwinm r11,r11,14,0,17
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 14) & 0xFFFFC000;
	// or r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 | ctx.r3.u64;
	// rlwinm r10,r11,18,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 18) & 0x1;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// beq cr6,0x82102cec
	if (ctx.cr6.eq) goto loc_82102CEC;
	// rlwimi r11,r5,14,17,17
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 14) & 0x4000) | (ctx.r11.u64 & 0xFFFFFFFFFFFFBFFF);
	// rlwinm. r10,r11,0,4,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// beq 0x82102cec
	if (ctx.cr0.eq) goto loc_82102CEC;
	// lwz r3,12(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82102CEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82102CEC:
	// addi r5,r31,44
	ctx.r5.s64 = ctx.r31.s64 + 44;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820fc9e8
	ctx.lr = 0x82102CFC;
	sub_820FC9E8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82103058
	if (ctx.cr0.lt) goto loc_82103058;
	// lwz r3,424(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 424);
	// addi r26,r29,424
	ctx.r26.s64 = ctx.r29.s64 + 424;
	// ld r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82102d3c
	if (ctx.cr6.eq) goto loc_82102D3C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82102D34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82102d40
	goto loc_82102D40;
loc_82102D3C:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82102D40:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82103058
	if (ctx.cr6.lt) goto loc_82103058;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// ld r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// li r17,1
	ctx.r17.s64 = 1;
	// bl 0x82109098
	ctx.lr = 0x82102D58;
	sub_82109098(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82103058
	if (ctx.cr0.lt) goto loc_82103058;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lbz r5,-1(r25)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r25.u32 + -1);
	// addi r3,r29,256
	ctx.r3.s64 = ctx.r29.s64 + 256;
	// bl 0x82109378
	ctx.lr = 0x82102D70;
	sub_82109378(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82103058
	if (ctx.cr0.lt) goto loc_82103058;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r18,1
	ctx.r18.s64 = 1;
	// bl 0x820fff08
	ctx.lr = 0x82102D8C;
	sub_820FFF08(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82103058
	if (ctx.cr0.lt) goto loc_82103058;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82102db0
	if (ctx.cr6.eq) goto loc_82102DB0;
	// lbz r11,171(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 171);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,171(r29)
	REX_STORE_U8(ctx.r29.u32 + 171, ctx.r11.u8);
	// b 0x82102dbc
	goto loc_82102DBC;
loc_82102DB0:
	// lbz r11,170(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 170);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,170(r29)
	REX_STORE_U8(ctx.r29.u32 + 170, ctx.r11.u8);
loc_82102DBC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82109548
	ctx.lr = 0x82102DC4;
	sub_82109548(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82102de0
	if (!ctx.cr6.eq) goto loc_82102DE0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r3,400(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 400);
	// lwz r4,364(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 364);
	// bl 0x82108e88
	ctx.lr = 0x82102DDC;
	sub_82108E88(ctx, base);
	// b 0x82102e10
	goto loc_82102E10;
loc_82102DE0:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8210b288
	ctx.lr = 0x82102DEC;
	sub_8210B288(ctx, base);
	// addi r11,r31,376
	ctx.r11.s64 = ctx.r31.s64 + 376;
	// lwz r11,376(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 376);
	// stw r11,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r11.u32);
	// lwz r11,380(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 380);
	// stw r11,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r11.u32);
	// lwz r11,384(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 384);
	// stw r11,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// lwz r11,388(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 388);
	// stw r11,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r11.u32);
loc_82102E10:
	// mr r28,r31
	ctx.r28.u64 = ctx.r31.u64;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// beq cr6,0x82102e34
	if (ctx.cr6.eq) goto loc_82102E34;
	// lwz r11,396(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 396);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82102e34
	if (!ctx.cr6.eq) goto loc_82102E34;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82109548
	ctx.lr = 0x82102E30;
	sub_82109548(ctx, base);
	// stw r31,396(r29)
	REX_STORE_U32(ctx.r29.u32 + 396, ctx.r31.u32);
loc_82102E34:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820fe6c8
	ctx.lr = 0x82102E40;
	sub_820FE6C8(ctx, base);
	// lwz r21,96(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r17,0
	ctx.r17.s64 = 0;
	// li r18,0
	ctx.r18.s64 = 0;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// addi r23,r23,8
	ctx.r23.s64 = ctx.r23.s64 + 8;
	// addi r22,r22,4
	ctx.r22.s64 = ctx.r22.s64 + 4;
	// addi r24,r24,4
	ctx.r24.s64 = ctx.r24.s64 + 4;
loc_82102E60:
	// addi r20,r20,1
	ctx.r20.s64 = ctx.r20.s64 + 1;
	// addi r25,r25,42
	ctx.r25.s64 = ctx.r25.s64 + 42;
	// addi r27,r27,8
	ctx.r27.s64 = ctx.r27.s64 + 8;
	// cmplwi cr6,r20,4
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 4, ctx.xer);
	// blt cr6,0x82102b68
	if (ctx.cr6.lt) goto loc_82102B68;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82102f2c
	if (!ctx.cr6.eq) goto loc_82102F2C;
	// lis r30,-32747
	ctx.r30.s64 = -2146107392;
	// ori r30,r30,10
	ctx.r30.u64 = ctx.r30.u64 | 10;
	// b 0x82102ea0
	goto loc_82102EA0;
loc_82102E88:
	// lis r30,-32747
	ctx.r30.s64 = -2146107392;
	// ori r30,r30,20994
	ctx.r30.u64 = ctx.r30.u64 | 20994;
	// b 0x82102ea0
	goto loc_82102EA0;
loc_82102E94:
	// lis r30,-32747
	ctx.r30.s64 = -2146107392;
	// ori r30,r30,10
	ctx.r30.u64 = ctx.r30.u64 | 10;
loc_82102E9C:
	// lwz r21,96(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
loc_82102EA0:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x82103134
	if (ctx.cr6.eq) goto loc_82103134;
	// addi r28,r29,256
	ctx.r28.s64 = ctx.r29.s64 + 256;
loc_82102EAC:
	// addi r16,r16,-1
	ctx.r16.s64 = ctx.r16.s64 + -1;
	// lwz r11,388(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 388);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// add r9,r16,r21
	ctx.r9.u64 = ctx.r16.u64 + ctx.r21.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r10
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bne cr6,0x82102ee4
	if (!ctx.cr6.eq) goto loc_82102EE4;
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// bne cr6,0x82102ee4
	if (!ctx.cr6.eq) goto loc_82102EE4;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,400(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 400);
	// lwz r4,364(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 364);
	// bl 0x82108e88
	ctx.lr = 0x82102EE4;
	sub_82108E88(ctx, base);
loc_82102EE4:
	// lwz r3,424(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 424);
	// ld r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82102f04
	if (ctx.cr6.eq) goto loc_82102F04;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82102F04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82102F04:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821030e4
	if (ctx.cr0.eq) goto loc_821030E4;
	// lbz r11,171(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 171);
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// stb r11,171(r29)
	REX_STORE_U8(ctx.r29.u32 + 171, ctx.r11.u8);
	// b 0x821030f0
	goto loc_821030F0;
loc_82102F20:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x82103058
	goto loc_82103058;
loc_82102F2C:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// bne cr6,0x82102f88
	if (!ctx.cr6.eq) goto loc_82102F88;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r14
	ctx.r7.u64 = ctx.r14.u64;
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820fec30
	ctx.lr = 0x82102F50;
	sub_820FEC30(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82103134
	if (ctx.cr0.lt) goto loc_82103134;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x821031cc
	if (ctx.cr6.eq) goto loc_821031CC;
	// addi r31,r1,112
	ctx.r31.s64 = ctx.r1.s64 + 112;
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
loc_82102F68:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8210bc10
	ctx.lr = 0x82102F70;
	sub_8210BC10(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x82102f68
	if (!ctx.cr0.eq) goto loc_82102F68;
	// b 0x821031cc
	goto loc_821031CC;
loc_82102F88:
	// lwz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82102fc8
	if (ctx.cr6.eq) goto loc_82102FC8;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82102fc8
	if (ctx.cr6.eq) goto loc_82102FC8;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x82102fb0
	if (ctx.cr6.eq) goto loc_82102FB0;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,1609
	ctx.r30.u64 = ctx.r30.u64 | 1609;
	// b 0x82102ea0
	goto loc_82102EA0;
loc_82102FB0:
	// lwz r11,720(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 720);
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82102fc8
	if (!ctx.cr0.eq) goto loc_82102FC8;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,4320
	ctx.r30.u64 = ctx.r30.u64 | 4320;
	// b 0x82102ea0
	goto loc_82102EA0;
loc_82102FC8:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,32(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// bl 0x82138a38
	ctx.lr = 0x82102FE0;
	sub_82138A38(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82103004
	if (ctx.cr0.eq) goto loc_82103004;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82136e38
	ctx.lr = 0x82102FF0;
	sub_82136E38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82102ea0
	if (ctx.cr0.lt) goto loc_82102EA0;
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r30,r30,16389
	ctx.r30.u64 = ctx.r30.u64 | 16389;
	// b 0x82102ea0
	goto loc_82102EA0;
loc_82103004:
	// add r28,r16,r21
	ctx.r28.u64 = ctx.r16.u64 + ctx.r21.u64;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r14
	ctx.r7.u64 = ctx.r14.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820fec30
	ctx.lr = 0x8210302C;
	sub_820FEC30(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x821030bc
	if (ctx.cr0.lt) goto loc_821030BC;
	// lwz r11,720(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 720);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82103160
	if (ctx.cr0.eq) goto loc_82103160;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82102940
	ctx.lr = 0x82103050;
	sub_82102940(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x8210315c
	if (!ctx.cr0.lt) goto loc_8210315C;
loc_82103058:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821030ac
	if (ctx.cr6.eq) goto loc_821030AC;
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq cr6,0x82103074
	if (ctx.cr6.eq) goto loc_82103074;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r29,256
	ctx.r3.s64 = ctx.r29.s64 + 256;
	// bl 0x82109430
	ctx.lr = 0x82103074;
	sub_82109430(ctx, base);
loc_82103074:
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x8210309c
	if (ctx.cr6.eq) goto loc_8210309C;
	// lwz r3,424(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 424);
	// ld r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210309c
	if (ctx.cr6.eq) goto loc_8210309C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210309C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210309C:
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// bl 0x8210bc10
	ctx.lr = 0x821030AC;
	sub_8210BC10(ctx, base);
loc_821030AC:
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82102e9c
	if (ctx.cr6.eq) goto loc_82102E9C;
	// lwz r21,96(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
loc_821030BC:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,32(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// bl 0x82138b88
	ctx.lr = 0x821030D0;
	sub_82138B88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82102ea0
	if (ctx.cr0.eq) goto loc_82102EA0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82136e38
	ctx.lr = 0x821030E0;
	sub_82136E38(ctx, base);
	// b 0x82102ea0
	goto loc_82102EA0;
loc_821030E4:
	// lbz r11,170(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 170);
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// stb r11,170(r29)
	REX_STORE_U8(ctx.r29.u32 + 170, ctx.r11.u8);
loc_821030F0:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82109430
	ctx.lr = 0x821030FC;
	sub_82109430(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820fe778
	ctx.lr = 0x8210310C;
	sub_820FE778(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210b298
	ctx.lr = 0x82103114;
	sub_8210B298(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// bl 0x8210bc10
	ctx.lr = 0x82103124;
	sub_8210BC10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210bc10
	ctx.lr = 0x8210312C;
	sub_8210BC10(ctx, base);
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// bne cr6,0x82102eac
	if (!ctx.cr6.eq) goto loc_82102EAC;
loc_82103134:
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x821031d0
	if (ctx.cr6.eq) goto loc_821031D0;
	// lwz r31,104(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_82103140:
	// addi r31,r31,-4
	ctx.r31.s64 = ctx.r31.s64 + -4;
	// addi r21,r21,-1
	ctx.r21.s64 = ctx.r21.s64 + -1;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8210bc10
	ctx.lr = 0x82103150;
	sub_8210BC10(ctx, base);
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// bne cr6,0x82103140
	if (!ctx.cr6.eq) goto loc_82103140;
	// b 0x821031d0
	goto loc_821031D0;
loc_8210315C:
	// lwz r21,96(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
loc_82103160:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x821031cc
	if (ctx.cr6.eq) goto loc_821031CC;
	// addi r31,r1,112
	ctx.r31.s64 = ctx.r1.s64 + 112;
loc_82103170:
	// cmplw cr6,r30,r21
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r21.u32, ctx.xer);
	// blt cr6,0x821031ac
	if (ctx.cr6.lt) goto loc_821031AC;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// lwz r3,12(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r11,180(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 180);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,180(r29)
	REX_STORE_U32(ctx.r29.u32 + 180, ctx.r11.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821031AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821031AC:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8210bc10
	ctx.lr = 0x821031B4;
	sub_8210BC10(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x82103170
	if (ctx.cr6.lt) goto loc_82103170;
loc_821031CC:
	// li r30,0
	ctx.r30.s64 = 0;
loc_821031D0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
