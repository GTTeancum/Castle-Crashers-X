DEFINE_REX_FUNC(sub_82087F70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x82087F78;
	__savegprlr_14(ctx, base);
	// stfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -168, ctx.f30.u64);
	// stfd f31,-160(r1)
	REX_STORE_U64(ctx.r1.u32 + -160, ctx.f31.u64);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// sth r30,414(r1)
	REX_STORE_U16(ctx.r1.u32 + 414, ctx.r30.u16);
	// clrlwi r29,r30,16
	ctx.r29.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// lwz r10,160(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82087FA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x820889f8
	if (ctx.cr6.eq) goto loc_820889F8;
	// lwz r11,156(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 156);
	// li r16,1
	ctx.r16.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,156(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r11,8248(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8248);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r8,r11,1998
	ctx.r8.s64 = ctx.r11.s64 + 1998;
	// stw r11,8248(r9)
	REX_STORE_U32(ctx.r9.u32 + 8248, ctx.r11.u32);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r22,r7,r9
	REX_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r22.u32);
	// lhz r5,144(r22)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r22.u32 + 144);
	// lhz r6,146(r22)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r22.u32 + 146);
	// sth r6,142(r22)
	REX_STORE_U16(ctx.r22.u32 + 142, ctx.r6.u16);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// sth r5,146(r22)
	REX_STORE_U16(ctx.r22.u32 + 146, ctx.r5.u16);
	// bne cr6,0x82087ff4
	if (!ctx.cr6.eq) goto loc_82087FF4;
	// sth r16,146(r22)
	REX_STORE_U16(ctx.r22.u32 + 146, ctx.r16.u16);
loc_82087FF4:
	// lbz r11,140(r22)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r22.u32 + 140);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// lwz r10,156(r22)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r22.u32 + 156);
	// ori r9,r11,64
	ctx.r9.u64 = ctx.r11.u64 | 64;
	// lwz r8,0(r22)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// stb r9,140(r22)
	REX_STORE_U8(ctx.r22.u32 + 140, ctx.r9.u8);
	// lwz r7,76(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r6,140(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 140);
	// lwz r31,156(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 156);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82088020;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,7988(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7988);
	// li r27,0
	ctx.r27.s64 = 0;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r22,4924(r4)
	REX_STORE_U32(ctx.r4.u32 + 4924, ctx.r22.u32);
	// lwz r11,7988(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7988);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r3,4928(r10)
	REX_STORE_U32(ctx.r10.u32 + 4928, ctx.r3.u32);
	// lwz r11,7988(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7988);
	// addi r11,r11,411
	ctx.r11.s64 = ctx.r11.s64 + 411;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// sthx r30,r8,r31
	REX_STORE_U16(ctx.r8.u32 + ctx.r31.u32, ctx.r30.u16);
	// lwz r11,7988(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7988);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x82088080
	if (!ctx.cr6.eq) goto loc_82088080;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_82088080:
	// lwz r10,7984(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7984);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82088094
	if (!ctx.cr6.eq) goto loc_82088094;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820935b0
	ctx.lr = 0x82088094;
	sub_820935B0(ctx, base);
loc_82088094:
	// lwz r11,7988(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7988);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,7988(r31)
	REX_STORE_U32(ctx.r31.u32 + 7988, ctx.r11.u32);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x820880ac
	if (!ctx.cr6.eq) goto loc_820880AC;
	// stw r27,7988(r31)
	REX_STORE_U32(ctx.r31.u32 + 7988, ctx.r27.u32);
loc_820880AC:
	// lhz r11,142(r22)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r22.u32 + 142);
	// mr r23,r27
	ctx.r23.u64 = ctx.r27.u64;
	// mr r15,r27
	ctx.r15.u64 = ctx.r27.u64;
	// stw r23,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r23.u32);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82088368
	if (!ctx.cr6.gt) goto loc_82088368;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r26,r22,108
	ctx.r26.s64 = ctx.r22.s64 + 108;
	// clrlwi r28,r11,16
	ctx.r28.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82082390
	ctx.lr = 0x820880DC;
	sub_82082390(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r10,r22,104
	ctx.r10.s64 = ctx.r22.s64 + 104;
	// lwz r10,104(r22)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r22.u32 + 104);
	// addi r11,r11,-6472
	ctx.r11.s64 = ctx.r11.s64 + -6472;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82088138
	if (ctx.cr6.eq) goto loc_82088138;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_82088100:
	// lhz r9,146(r22)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r22.u32 + 146);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// sth r9,82(r10)
	REX_STORE_U16(ctx.r10.u32 + 82, ctx.r9.u16);
	// stw r27,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r27.u32);
	// stw r27,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r27.u32);
	// sth r27,4(r11)
	REX_STORE_U16(ctx.r11.u32 + 4, ctx.r27.u16);
	// sth r27,6(r11)
	REX_STORE_U16(ctx.r11.u32 + 6, ctx.r27.u16);
	// lwz r8,28(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// lwz r10,88(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 88);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82088100
	if (!ctx.cr6.eq) goto loc_82088100;
loc_82088138:
	// clrlwi r6,r28,16
	ctx.r6.u64 = ctx.r28.u32 & 0xFFFF;
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820888fc
	if (ctx.cr6.gt) goto loc_820888FC;
	// lwz r20,100(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r10,r15,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 4) & 0xFFFFFFF0;
	// lhz r19,414(r1)
	ctx.r19.u64 = REX_LOAD_U16(ctx.r1.u32 + 414);
	// li r25,26
	ctx.r25.s64 = 26;
	// addi r11,r20,4
	ctx.r11.s64 = ctx.r20.s64 + 4;
	// li r24,2
	ctx.r24.s64 = 2;
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r21,1
	ctx.r21.s64 = 1;
loc_82088168:
	// lwz r11,92(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 92);
	// addi r10,r29,2
	ctx.r10.s64 = ctx.r29.s64 + 2;
	// add r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbzx r8,r11,r29
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r29.u32);
	// lbz r7,1(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// rotlwi r5,r8,8
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// or r4,r7,r5
	ctx.r4.u64 = ctx.r7.u64 | ctx.r5.u64;
	// clrlwi r3,r4,16
	ctx.r3.u64 = ctx.r4.u32 & 0xFFFF;
	// rlwinm r9,r3,24,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFF;
	// rlwimi r9,r3,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// rlwinm r9,r8,26,22,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FF;
	// clrlwi r8,r8,26
	ctx.r8.u64 = ctx.r8.u32 & 0x3F;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x820881c4
	if (!ctx.cr6.eq) goto loc_820881C4;
	// addi r11,r6,1
	ctx.r11.s64 = ctx.r6.s64 + 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// clrlwi r28,r11,16
	ctx.r28.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82082390
	ctx.lr = 0x820881BC;
	sub_82082390(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x82088354
	goto loc_82088354;
loc_820881C4:
	// clrlwi r9,r8,16
	ctx.r9.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplwi cr6,r9,63
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 63, ctx.xer);
	// bne cr6,0x82088250
	if (!ctx.cr6.eq) goto loc_82088250;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbzx r8,r11,r10
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// rotlwi r6,r8,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// lbz r5,1(r9)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r4,2(r9)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + 2);
	// or r3,r5,r6
	ctx.r3.u64 = ctx.r5.u64 | ctx.r6.u64;
	// lbz r9,3(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 3);
	// rlwinm r8,r3,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// or r6,r8,r4
	ctx.r6.u64 = ctx.r8.u64 | ctx.r4.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r9
	ctx.r4.u64 = ctx.r5.u64 | ctx.r9.u64;
	// stw r4,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// lbz r3,98(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + 98);
	// lbz r9,97(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 97);
	// xor r6,r9,r3
	ctx.r6.u64 = ctx.r9.u64 ^ ctx.r3.u64;
	// lbz r5,99(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 99);
	// clrlwi r6,r6,24
	ctx.r6.u64 = ctx.r6.u32 & 0xFF;
	// lbz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// xor r3,r6,r3
	ctx.r3.u64 = ctx.r6.u64 ^ ctx.r3.u64;
	// xor r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// clrlwi r4,r8,24
	ctx.r4.u64 = ctx.r8.u32 & 0xFF;
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// xor r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// stb r8,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r8.u8);
	// clrlwi r9,r5,24
	ctx.r9.u64 = ctx.r5.u32 & 0xFF;
	// xor r5,r9,r4
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r4.u64;
	// stb r9,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r9.u8);
	// xor r4,r8,r6
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r6.u64;
	// stb r5,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r5.u8);
	// stb r4,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r4.u8);
	// lwz r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
loc_82088250:
	// add r29,r9,r10
	ctx.r29.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplwi cr6,r7,26
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 26, ctx.xer);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// bne cr6,0x820882ac
	if (!ctx.cr6.eq) goto loc_820882AC;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rotlwi r7,r9,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// stw r25,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r25.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// or r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 | ctx.r8.u64;
	// sth r21,4(r31)
	REX_STORE_U16(ctx.r31.u32 + 4, ctx.r21.u16);
	// sth r28,6(r31)
	REX_STORE_U16(ctx.r31.u32 + 6, ctx.r28.u16);
	// clrlwi r5,r6,16
	ctx.r5.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwinm r4,r5,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFF;
	// rlwimi r4,r5,8,16,23
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// addi r3,r11,-16384
	ctx.r3.s64 = ctx.r11.s64 + -16384;
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// b 0x82088354
	goto loc_82088354;
loc_820882AC:
	// cmplwi cr6,r7,5
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 5, ctx.xer);
	// beq cr6,0x820882c4
	if (ctx.cr6.eq) goto loc_820882C4;
	// cmplwi cr6,r7,28
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 28, ctx.xer);
	// bne cr6,0x82088354
	if (!ctx.cr6.eq) goto loc_82088354;
	// cmplwi cr6,r7,5
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 5, ctx.xer);
	// bne cr6,0x820882ec
	if (!ctx.cr6.eq) goto loc_820882EC;
loc_820882C4:
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// lbz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r9,3(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// rotlwi r8,r10,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r9,r6,24,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// rlwimi r9,r6,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// b 0x82088314
	goto loc_82088314;
loc_820882EC:
	// cmplwi cr6,r7,28
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 28, ctx.xer);
	// bne cr6,0x82088314
	if (!ctx.cr6.eq) goto loc_82088314;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// rotlwi r10,r11,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r9,1(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwinm r9,r7,24,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFF;
	// rlwimi r9,r7,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
loc_82088314:
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r3,r22,104
	ctx.r3.s64 = ctx.r22.s64 + 104;
	// addi r30,r11,-16384
	ctx.r30.s64 = ctx.r11.s64 + -16384;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82084c78
	ctx.lr = 0x82088328;
	sub_82084C78(ctx, base);
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// ble cr6,0x82088354
	if (!ctx.cr6.gt) goto loc_82088354;
	// mr r10,r15
	ctx.r10.u64 = ctx.r15.u64;
	// addi r11,r20,8
	ctx.r11.s64 = ctx.r20.s64 + 8;
loc_82088338:
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r9,r30
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r30.s32, ctx.xer);
	// bne cr6,0x82088348
	if (!ctx.cr6.eq) goto loc_82088348;
	// sth r24,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r24.u16);
loc_82088348:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bne 0x82088338
	if (!ctx.cr0.eq) goto loc_82088338;
loc_82088354:
	// clrlwi r6,r28,16
	ctx.r6.u64 = ctx.r28.u32 & 0xFFFF;
	// clrlwi r11,r19,16
	ctx.r11.u64 = ctx.r19.u32 & 0xFFFF;
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82088168
	if (!ctx.cr6.gt) goto loc_82088168;
	// b 0x820888fc
	goto loc_820888FC;
loc_82088368:
	// addi r14,r22,108
	ctx.r14.s64 = ctx.r22.s64 + 108;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// bl 0x82082390
	ctx.lr = 0x82088378;
	sub_82082390(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r31,104(r22)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r22.u32 + 104);
	// addi r10,r22,104
	ctx.r10.s64 = ctx.r22.s64 + 104;
	// addi r11,r11,-6472
	ctx.r11.s64 = ctx.r11.s64 + -6472;
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820883fc
	if (ctx.cr6.eq) goto loc_820883FC;
	// addi r30,r11,4
	ctx.r30.s64 = ctx.r11.s64 + 4;
loc_8208839C:
	// lhz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 84);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x820883bc
	if (!ctx.cr6.gt) goto loc_820883BC;
	// addi r3,r22,104
	ctx.r3.s64 = ctx.r22.s64 + 104;
	// lwz r4,28(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r31,88(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x82084c78
	ctx.lr = 0x820883B8;
	sub_82084C78(ctx, base);
	// b 0x820883f0
	goto loc_820883F0;
loc_820883BC:
	// lhz r11,146(r22)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r22.u32 + 146);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// sth r11,82(r31)
	REX_STORE_U16(ctx.r31.u32 + 82, ctx.r11.u16);
	// stw r27,-4(r30)
	REX_STORE_U32(ctx.r30.u32 + -4, ctx.r27.u32);
	// stw r27,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r27.u32);
	// sth r27,4(r30)
	REX_STORE_U16(ctx.r30.u32 + 4, ctx.r27.u16);
	// lhz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 84);
	// sth r10,6(r30)
	REX_STORE_U16(ctx.r30.u32 + 6, ctx.r10.u16);
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// stw r9,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r9.u32);
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// lwz r31,88(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
loc_820883F0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8208839c
	if (!ctx.cr6.eq) goto loc_8208839C;
	// stw r23,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r23.u32);
loc_820883FC:
	// cmplwi cr6,r29,1
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 1, ctx.xer);
	// blt cr6,0x820888fc
	if (ctx.cr6.lt) goto loc_820888FC;
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r10,r15,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 4) & 0xFFFFFFF0;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// add r20,r10,r11
	ctx.r20.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f30,18236(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18236);
	ctx.f30.f64 = double(temp.f32);
	// li r21,255
	ctx.r21.s64 = 255;
	// lfs f31,9536(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// addi r18,r11,-7008
	ctx.r18.s64 = ctx.r11.s64 + -7008;
	// addi r17,r10,-7056
	ctx.r17.s64 = ctx.r10.s64 + -7056;
loc_82088438:
	// lwz r11,92(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 92);
	// li r30,2
	ctx.r30.s64 = 2;
	// lwz r29,100(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r31,r19,2
	ctx.r31.s64 = ctx.r19.s64 + 2;
	// add r10,r11,r19
	ctx.r10.u64 = ctx.r11.u64 + ctx.r19.u64;
	// lbzx r9,r11,r19
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r19.u32);
	// lbz r8,1(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// rotlwi r7,r9,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// or r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 | ctx.r8.u64;
	// clrlwi r5,r6,16
	ctx.r5.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwinm r4,r5,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFF;
	// rlwimi r4,r5,8,16,23
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwinm r10,r4,26,22,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 26) & 0x3FF;
	// clrlwi r9,r4,26
	ctx.r9.u64 = ctx.r4.u32 & 0x3F;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x8208849c
	if (!ctx.cr6.eq) goto loc_8208849C;
	// clrlwi r11,r16,16
	ctx.r11.u64 = ctx.r16.u32 & 0xFFFF;
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r16,r11,16
	ctx.r16.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// bl 0x82082390
	ctx.lr = 0x82088494;
	sub_82082390(ctx, base);
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// b 0x820888e8
	goto loc_820888E8;
loc_8208849C:
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplwi cr6,r10,63
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 63, ctx.xer);
	// bne cr6,0x82088528
	if (!ctx.cr6.eq) goto loc_82088528;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbzx r9,r11,r31
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// rotlwi r7,r9,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r6,1(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r5,2(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// or r4,r7,r6
	ctx.r4.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lbz r3,3(r10)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r10,r5
	ctx.r9.u64 = ctx.r10.u64 | ctx.r5.u64;
	// rlwinm r7,r9,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r6,r7,r3
	ctx.r6.u64 = ctx.r7.u64 | ctx.r3.u64;
	// stw r6,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// lbz r6,99(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 99);
	// lbz r10,98(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 98);
	// lbz r7,97(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 97);
	// lbz r5,96(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// xor r4,r7,r10
	ctx.r4.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// xor r3,r5,r6
	ctx.r3.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// clrlwi r7,r4,24
	ctx.r7.u64 = ctx.r4.u32 & 0xFF;
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// xor r4,r7,r10
	ctx.r4.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// xor r3,r5,r6
	ctx.r3.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// clrlwi r9,r4,24
	ctx.r9.u64 = ctx.r4.u32 & 0xFF;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// xor r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r7.u64;
	// stb r9,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r9.u8);
	// xor r6,r10,r5
	ctx.r6.u64 = ctx.r10.u64 ^ ctx.r5.u64;
	// stb r10,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r10.u8);
	// stb r7,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r7.u8);
	// stb r6,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r6.u8);
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
loc_82088528:
	// add r19,r10,r31
	ctx.r19.u64 = ctx.r10.u64 + ctx.r31.u64;
	// cmplwi cr6,r8,26
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 26, ctx.xer);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// bne cr6,0x82088810
	if (!ctx.cr6.eq) goto loc_82088810;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r24,r27
	ctx.r24.u64 = ctx.r27.u64;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r9,2(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rotlwi r8,r10,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r5,r6,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// rlwimi r5,r6,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r11,r5,16
	ctx.r11.u64 = ctx.r5.u32 & 0xFFFF;
	// addi r25,r11,-16384
	ctx.r25.s64 = ctx.r11.s64 + -16384;
	// ble cr6,0x820887dc
	if (!ctx.cr6.gt) goto loc_820887DC;
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r23,104(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// addi r26,r11,10
	ctx.r26.s64 = ctx.r11.s64 + 10;
loc_8208857C:
	// lwz r11,2(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 2);
	// cmpw cr6,r11,r25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r25.s32, ctx.xer);
	// bne cr6,0x820887d0
	if (!ctx.cr6.eq) goto loc_820887D0;
	// lhz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 0);
	// clrlwi r28,r16,16
	ctx.r28.u64 = ctx.r16.u32 & 0xFFFF;
	// li r24,1
	ctx.r24.s64 = 1;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820887d0
	if (ctx.cr6.lt) goto loc_820887D0;
	// lwz r11,92(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 92);
	// addi r10,r22,104
	ctx.r10.s64 = ctx.r22.s64 + 104;
	// lwz r30,104(r22)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r22.u32 + 104);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lbzx r9,r11,r31
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// addi r31,r31,3
	ctx.r31.s64 = ctx.r31.s64 + 3;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// rlwimi r8,r9,30,26,31
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3F) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFC0);
	// rlwimi r6,r9,2,22,29
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFC03);
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// rlwimi r7,r8,30,27,31
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x1F) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFE0);
	// rlwimi r5,r6,2,20,28
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFF8) | (ctx.r5.u64 & 0xFFFFFFFFFFFFF007);
	// rlwinm r8,r7,30,28,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0xF;
	// rlwinm r6,r5,2,18,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3FF0;
	// rlwinm r7,r9,0,27,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// or r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 | ctx.r7.u64;
	// or r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 | ctx.r5.u64;
	// rlwinm r9,r4,31,25,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7F;
	// rlwinm r8,r3,1,24,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// or r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 | ctx.r8.u64;
	// beq cr6,0x82088614
	if (ctx.cr6.eq) goto loc_82088614;
loc_820885FC:
	// lwz r9,28(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// cmpw cr6,r9,r25
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r25.s32, ctx.xer);
	// beq cr6,0x82088618
	if (ctx.cr6.eq) goto loc_82088618;
	// lwz r30,88(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820885fc
	if (!ctx.cr6.eq) goto loc_820885FC;
loc_82088614:
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
loc_82088618:
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// clrlwi r29,r10,24
	ctx.r29.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8208862c
	if (ctx.cr6.eq) goto loc_8208862C;
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
loc_8208862C:
	// rlwinm r10,r29,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820886f4
	if (ctx.cr6.eq) goto loc_820886F4;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stfs f30,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f30,116(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stb r27,124(r1)
	REX_STORE_U8(ctx.r1.u32 + 124, ctx.r27.u8);
	// stfs f30,128(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stb r27,125(r1)
	REX_STORE_U8(ctx.r1.u32 + 125, ctx.r27.u8);
	// stfs f30,132(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stb r27,126(r1)
	REX_STORE_U8(ctx.r1.u32 + 126, ctx.r27.u8);
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f31,144(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,148(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// bl 0x82085890
	ctx.lr = 0x82088674;
	sub_82085890(ctx, base);
	// lbz r11,86(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 86);
	// add r31,r3,r31
	ctx.r31.u64 = ctx.r3.u64 + ctx.r31.u64;
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820886f4
	if (!ctx.cr6.eq) goto loc_820886F4;
	// lbz r11,126(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 126);
	// lfs f13,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// lbz r10,124(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 124);
	// lfs f12,140(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// lbz r9,125(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 125);
	// lfs f10,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f7.f64 = double(temp.f32);
	// stb r11,50(r30)
	REX_STORE_U8(ctx.r30.u32 + 50, ctx.r11.u8);
	// lfs f6,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f6.f64 = double(temp.f32);
	// stb r10,48(r30)
	REX_STORE_U8(ctx.r30.u32 + 48, ctx.r10.u8);
	// stfs f13,60(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 60, temp.u32);
	// stb r9,49(r30)
	REX_STORE_U8(ctx.r30.u32 + 49, ctx.r9.u8);
	// stfs f12,64(r30)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r30.u32 + 64, temp.u32);
	// stfs f11,68(r30)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r30.u32 + 68, temp.u32);
	// stfs f10,56(r30)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r30.u32 + 56, temp.u32);
	// stfs f8,36(r30)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r30.u32 + 36, temp.u32);
	// stfs f7,40(r30)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r30.u32 + 40, temp.u32);
	// stfs f6,52(r30)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r30.u32 + 52, temp.u32);
	// lfs f0,120(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f9,148(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f9.f64 = double(temp.f32);
	// stfs f0,44(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 44, temp.u32);
	// stfs f9,72(r30)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r30.u32 + 72, temp.u32);
	// lbz r8,86(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 86);
	// ori r7,r8,128
	ctx.r7.u64 = ctx.r8.u64 | 128;
	// stb r7,86(r30)
	REX_STORE_U8(ctx.r30.u32 + 86, ctx.r7.u8);
loc_820886F4:
	// rlwinm r11,r29,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82088774
	if (ctx.cr6.eq) goto loc_82088774;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r17,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r17.u32);
	// stw r27,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r27.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stw r11,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r11.u32);
	// stw r27,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r27.u32);
	// stw r27,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r27.u32);
	// stb r27,180(r1)
	REX_STORE_U8(ctx.r1.u32 + 180, ctx.r27.u8);
	// sth r27,184(r1)
	REX_STORE_U16(ctx.r1.u32 + 184, ctx.r27.u16);
	// sth r21,200(r1)
	REX_STORE_U16(ctx.r1.u32 + 200, ctx.r21.u16);
	// sth r21,192(r1)
	REX_STORE_U16(ctx.r1.u32 + 192, ctx.r21.u16);
	// sth r21,190(r1)
	REX_STORE_U16(ctx.r1.u32 + 190, ctx.r21.u16);
	// sth r21,188(r1)
	REX_STORE_U16(ctx.r1.u32 + 188, ctx.r21.u16);
	// sth r27,202(r1)
	REX_STORE_U16(ctx.r1.u32 + 202, ctx.r27.u16);
	// sth r27,198(r1)
	REX_STORE_U16(ctx.r1.u32 + 198, ctx.r27.u16);
	// sth r27,196(r1)
	REX_STORE_U16(ctx.r1.u32 + 196, ctx.r27.u16);
	// sth r27,194(r1)
	REX_STORE_U16(ctx.r1.u32 + 194, ctx.r27.u16);
	// stw r27,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r27.u32);
	// lwz r11,92(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 92);
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x82083f50
	ctx.lr = 0x82088754;
	sub_82083F50(ctx, base);
	// add r31,r3,r31
	ctx.r31.u64 = ctx.r3.u64 + ctx.r31.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820837c0
	ctx.lr = 0x82088764;
	sub_820837C0(ctx, base);
	// stw r18,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r18.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82079970
	ctx.lr = 0x82088770;
	sub_82079970(ctx, base);
	// b 0x82088788
	goto loc_82088788;
loc_82088774:
	// lhz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 0);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82088788
	if (!ctx.cr6.eq) goto loc_82088788;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820838a8
	ctx.lr = 0x82088788;
	sub_820838A8(ctx, base);
loc_82088788:
	// rlwinm r11,r29,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82088798
	if (ctx.cr6.eq) goto loc_82088798;
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
loc_82088798:
	// rlwinm r11,r29,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820887d0
	if (ctx.cr6.eq) goto loc_820887D0;
	// lwz r10,156(r22)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r22.u32 + 156);
	// lwz r11,92(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 92);
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r3,10316(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x820887B8;
	sub_8209D948(ctx, base);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820887D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820887D0:
	// addic. r23,r23,-1
	ctx.xer.ca = ctx.r23.u32 > 0;
	ctx.r23.s64 = ctx.r23.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// addi r26,r26,16
	ctx.r26.s64 = ctx.r26.s64 + 16;
	// bne 0x8208857c
	if (!ctx.cr0.eq) goto loc_8208857C;
loc_820887DC:
	// clrlwi r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820888e8
	if (!ctx.cr6.eq) goto loc_820888E8;
	// li r11,26
	ctx.r11.s64 = 26;
	// stw r31,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r31.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r16,6(r20)
	REX_STORE_U16(ctx.r20.u32 + 6, ctx.r16.u16);
	// stw r11,-4(r20)
	REX_STORE_U32(ctx.r20.u32 + -4, ctx.r11.u32);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// sth r10,4(r20)
	REX_STORE_U16(ctx.r20.u32 + 4, ctx.r10.u16);
	// stw r25,8(r20)
	REX_STORE_U32(ctx.r20.u32 + 8, ctx.r25.u32);
	// addi r20,r20,16
	ctx.r20.s64 = ctx.r20.s64 + 16;
	// b 0x820888e8
	goto loc_820888E8;
loc_82088810:
	// cmplwi cr6,r8,5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 5, ctx.xer);
	// beq cr6,0x82088828
	if (ctx.cr6.eq) goto loc_82088828;
	// cmplwi cr6,r8,28
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 28, ctx.xer);
	// bne cr6,0x820888e8
	if (!ctx.cr6.eq) goto loc_820888E8;
	// cmplwi cr6,r8,5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 5, ctx.xer);
	// bne cr6,0x82088844
	if (!ctx.cr6.eq) goto loc_82088844;
loc_82088828:
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// lbz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r9,3(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// rotlwi r8,r10,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// b 0x82088860
	goto loc_82088860;
loc_82088844:
	// cmplwi cr6,r8,28
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 28, ctx.xer);
	// bne cr6,0x8208886c
	if (!ctx.cr6.eq) goto loc_8208886C;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,1(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
loc_82088860:
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r10,r6,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// rlwimi r10,r6,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
loc_8208886C:
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// addi r31,r11,-16384
	ctx.r31.s64 = ctx.r11.s64 + -16384;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// ble cr6,0x820888a4
	if (!ctx.cr6.gt) goto loc_820888A4;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// addi r11,r29,12
	ctx.r11.s64 = ctx.r29.s64 + 12;
loc_82088888:
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r8,r31
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r31.s32, ctx.xer);
	// bne cr6,0x82088898
	if (!ctx.cr6.eq) goto loc_82088898;
	// li r9,1
	ctx.r9.s64 = 1;
loc_82088898:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bne 0x82088888
	if (!ctx.cr0.eq) goto loc_82088888;
loc_820888A4:
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820888e8
	if (!ctx.cr6.eq) goto loc_820888E8;
	// addi r3,r22,104
	ctx.r3.s64 = ctx.r22.s64 + 104;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82084c78
	ctx.lr = 0x820888BC;
	sub_82084C78(ctx, base);
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// ble cr6,0x820888e8
	if (!ctx.cr6.gt) goto loc_820888E8;
	// mr r10,r15
	ctx.r10.u64 = ctx.r15.u64;
	// addi r11,r29,8
	ctx.r11.s64 = ctx.r29.s64 + 8;
loc_820888CC:
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r9,r31
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r31.s32, ctx.xer);
	// bne cr6,0x820888dc
	if (!ctx.cr6.eq) goto loc_820888DC;
	// sth r30,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r30.u16);
loc_820888DC:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bne 0x820888cc
	if (!ctx.cr0.eq) goto loc_820888CC;
loc_820888E8:
	// lhz r11,414(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 414);
	// clrlwi r10,r16,16
	ctx.r10.u64 = ctx.r16.u32 & 0xFFFF;
	// lwz r23,104(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82088438
	if (!ctx.cr6.gt) goto loc_82088438;
loc_820888FC:
	// cmpw cr6,r23,r15
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r15.s32, ctx.xer);
	// bge cr6,0x82088998
	if (!ctx.cr6.lt) goto loc_82088998;
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r10,r23,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r30,r23,r15
	ctx.r30.u64 = ctx.r15.u64 - ctx.r23.u64;
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32234
	ctx.r10.s64 = -2112487424;
	// addi r28,r11,-6716
	ctx.r28.s64 = ctx.r11.s64 + -6716;
	// addi r29,r10,-23552
	ctx.r29.s64 = ctx.r10.s64 + -23552;
loc_82088928:
	// lhz r11,-2(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + -2);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x8208898c
	if (ctx.cr6.eq) goto loc_8208898C;
	// lhz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// sth r11,146(r22)
	REX_STORE_U16(ctx.r22.u32 + 146, ctx.r11.u16);
	// lwz r4,-10(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + -10);
	// cmpwi cr6,r4,255
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 255, ctx.xer);
	// beq cr6,0x8208898c
	if (ctx.cr6.eq) goto loc_8208898C;
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82088978
	if (ctx.cr6.eq) goto loc_82088978;
	// lwz r9,-6(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + -6);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,92(r22)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r22.u32 + 92);
	// lwz r3,156(r22)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + 156);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82088974;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8208898c
	goto loc_8208898C;
loc_82088978:
	// cmpwi cr6,r4,45
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 45, ctx.xer);
	// beq cr6,0x8208898c
	if (ctx.cr6.eq) goto loc_8208898C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820798d8
	ctx.lr = 0x82088988;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x8208898C;
	sub_8208C5D8(ctx, base);
loc_8208898C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// bne 0x82088928
	if (!ctx.cr0.eq) goto loc_82088928;
loc_82088998:
	// lhz r10,414(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 414);
	// addi r11,r22,104
	ctx.r11.s64 = ctx.r22.s64 + 104;
	// lwz r11,104(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// sth r10,146(r22)
	REX_STORE_U16(ctx.r22.u32 + 146, ctx.r10.u16);
	// beq cr6,0x820889d0
	if (ctx.cr6.eq) goto loc_820889D0;
loc_820889B0:
	// lhz r10,82(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 82);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820889c4
	if (!ctx.cr6.eq) goto loc_820889C4;
	// lhz r10,146(r22)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r22.u32 + 146);
	// sth r10,82(r11)
	REX_STORE_U16(ctx.r11.u32 + 82, ctx.r10.u16);
loc_820889C4:
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820889b0
	if (!ctx.cr6.eq) goto loc_820889B0;
loc_820889D0:
	// lwz r11,156(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 156);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,156(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r11,8248(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8248);
	// addi r8,r11,1998
	ctx.r8.s64 = ctx.r11.s64 + 1998;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r27,r7,r9
	REX_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r27.u32);
	// lwz r11,8248(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8248);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// stw r6,8248(r9)
	REX_STORE_U32(ctx.r9.u32 + 8248, ctx.r6.u32);
loc_820889F8:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
