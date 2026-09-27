DEFINE_REX_FUNC(sub_820922B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e4
	ctx.lr = 0x820922C0;
	__savegprlr_15(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// lbz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// lbz r9,1(r27)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r27.u32 + 1);
	// lfs f13,18236(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 18236);
	ctx.f13.f64 = double(temp.f32);
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// lbz r6,2(r27)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r27.u32 + 2);
	// rotlwi r5,r9,8
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lfs f0,9536(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lbz r4,10344(r24)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r24.u32 + 10344);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// rlwimi r3,r11,2,22,29
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x3FC) | (ctx.r3.u64 & 0xFFFFFFFFFFFFFC03);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// rlwimi r7,r11,30,26,31
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3F) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFC0);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// or r8,r6,r5
	ctx.r8.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// rlwimi r9,r3,2,20,28
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFF8) | (ctx.r9.u64 & 0xFFFFFFFFFFFFF007);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// rlwimi r10,r7,30,27,31
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x1F) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFE0);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// stw r30,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// rlwinm r10,r10,30,28,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0xF;
	// stw r30,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r30.u32);
	// rlwinm r8,r3,2,18,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FF0;
	// stw r30,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r30.u32);
	// rlwinm r5,r11,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// stb r30,164(r1)
	REX_STORE_U8(ctx.r1.u32 + 164, ctx.r30.u8);
	// rlwinm r6,r7,24,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFF;
	// stb r30,108(r1)
	REX_STORE_U8(ctx.r1.u32 + 108, ctx.r30.u8);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// sth r30,168(r1)
	REX_STORE_U16(ctx.r1.u32 + 168, ctx.r30.u16);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// stb r30,109(r1)
	REX_STORE_U8(ctx.r1.u32 + 109, ctx.r30.u8);
	// or r9,r8,r5
	ctx.r9.u64 = ctx.r8.u64 | ctx.r5.u64;
	// stb r30,110(r1)
	REX_STORE_U8(ctx.r1.u32 + 110, ctx.r30.u8);
	// rlwimi r6,r7,8,16,23
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFF00) | (ctx.r6.u64 & 0xFFFFFFFFFFFF00FF);
	// sth r30,186(r1)
	REX_STORE_U16(ctx.r1.u32 + 186, ctx.r30.u16);
	// addi r7,r3,-7056
	ctx.r7.s64 = ctx.r3.s64 + -7056;
	// sth r30,182(r1)
	REX_STORE_U16(ctx.r1.u32 + 182, ctx.r30.u16);
	// rlwinm r5,r10,31,25,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7F;
	// sth r30,180(r1)
	REX_STORE_U16(ctx.r1.u32 + 180, ctx.r30.u16);
	// li r11,255
	ctx.r11.s64 = 255;
	// stw r7,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// sth r30,178(r1)
	REX_STORE_U16(ctx.r1.u32 + 178, ctx.r30.u16);
	// rlwinm r3,r9,1,24,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFE;
	// sth r11,184(r1)
	REX_STORE_U16(ctx.r1.u32 + 184, ctx.r11.u16);
	// clrlwi r10,r6,16
	ctx.r10.u64 = ctx.r6.u32 & 0xFFFF;
	// stw r8,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r8.u32);
	// mr r23,r30
	ctx.r23.u64 = ctx.r30.u64;
	// sth r11,176(r1)
	REX_STORE_U16(ctx.r1.u32 + 176, ctx.r11.u16);
	// or r31,r5,r3
	ctx.r31.u64 = ctx.r5.u64 | ctx.r3.u64;
	// sth r11,174(r1)
	REX_STORE_U16(ctx.r1.u32 + 174, ctx.r11.u16);
	// addi r16,r10,-16384
	ctx.r16.s64 = ctx.r10.s64 + -16384;
	// sth r11,172(r1)
	REX_STORE_U16(ctx.r1.u32 + 172, ctx.r11.u16);
	// li r28,3
	ctx.r28.s64 = 3;
	// stw r30,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r30.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8209241c
	if (ctx.cr6.eq) goto loc_8209241C;
	// lwz r11,76(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 76);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// lwz r11,8248(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8248);
	// addi r9,r11,1998
	ctx.r9.s64 = ctx.r11.s64 + 1998;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,160(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 160);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82092410;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r5,r3,16
	ctx.r5.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r5,1
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1, ctx.xer);
	// bgt cr6,0x820929bc
	if (ctx.cr6.gt) goto loc_820929BC;
loc_8209241C:
	// rlwinm r29,r31,26,31,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 26) & 0x1;
	// clrlwi r18,r31,24
	ctx.r18.u64 = ctx.r31.u32 & 0xFF;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8209244c
	if (ctx.cr6.eq) goto loc_8209244C;
	// lbz r11,3(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 3);
	// li r28,5
	ctx.r28.s64 = 5;
	// lbz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + 4);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwinm r23,r7,24,24,31
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFF;
	// rlwimi r23,r7,8,16,23
	ctx.r23.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFF00) | (ctx.r23.u64 & 0xFFFFFFFFFFFF00FF);
loc_8209244C:
	// rlwinm r25,r18,27,31,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 27) & 0x1;
	// rlwinm r26,r18,0,26,26
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x8209246c
	if (ctx.cr6.eq) goto loc_8209246C;
	// add r4,r28,r27
	ctx.r4.u64 = ctx.r28.u64 + ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82085890
	ctx.lr = 0x82092468;
	sub_82085890(ctx, base);
	// add r28,r3,r28
	ctx.r28.u64 = ctx.r3.u64 + ctx.r28.u64;
loc_8209246C:
	// rlwinm r15,r18,28,31,31
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 28) & 0x1;
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x82092488
	if (ctx.cr6.eq) goto loc_82092488;
	// add r4,r28,r27
	ctx.r4.u64 = ctx.r28.u64 + ctx.r27.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82083f50
	ctx.lr = 0x82092484;
	sub_82083F50(ctx, base);
	// add r28,r3,r28
	ctx.r28.u64 = ctx.r3.u64 + ctx.r28.u64;
loc_82092488:
	// rlwinm r11,r18,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82092498
	if (ctx.cr6.eq) goto loc_82092498;
	// addi r28,r28,2
	ctx.r28.s64 = ctx.r28.s64 + 2;
loc_82092498:
	// rlwinm r17,r18,30,31,31
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// beq cr6,0x820924ec
	if (ctx.cr6.eq) goto loc_820924EC;
	// lwz r11,76(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 76);
	// add r31,r28,r27
	ctx.r31.u64 = ctx.r28.u64 + ctx.r27.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// lwz r3,10316(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x820924BC;
	sub_8209D948(ctx, base);
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_820924C4:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820924c4
	if (!ctx.cr6.eq) goto loc_820924C4;
	// subf r11,r31,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r31.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 1;
	// b 0x820924f0
	goto loc_820924F0;
loc_820924EC:
	// lhz r19,80(r1)
	ctx.r19.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
loc_820924F0:
	// rlwinm r21,r18,31,31,31
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x8209252c
	if (ctx.cr6.eq) goto loc_8209252C;
	// add r11,r28,r27
	ctx.r11.u64 = ctx.r28.u64 + ctx.r27.u64;
	// lbzx r10,r28,r27
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r27.u32);
	// addi r28,r28,2
	ctx.r28.s64 = ctx.r28.s64 + 2;
	// rotlwi r9,r10,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r8,1(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r5,r6,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// rlwimi r5,r6,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r11,r5,16
	ctx.r11.u64 = ctx.r5.u32 & 0xFFFF;
	// addi r22,r11,-16384
	ctx.r22.s64 = ctx.r11.s64 + -16384;
	// b 0x82092530
	goto loc_82092530;
loc_8209252C:
	// lwz r22,80(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_82092530:
	// lwz r11,76(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 76);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// lwz r11,8248(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8248);
	// addi r9,r11,1998
	ctx.r9.s64 = ctx.r11.s64 + 1998;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// beq cr6,0x820928e4
	if (ctx.cr6.eq) goto loc_820928E4;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// rlwinm r26,r26,27,29,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 27) & 0x7;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82092568;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8209258c
	if (ctx.cr6.eq) goto loc_8209258C;
loc_82092574:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpw cr6,r11,r16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r16.s32, ctx.xer);
	// beq cr6,0x82092768
	if (ctx.cr6.eq) goto loc_82092768;
	// lwz r31,88(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82092574
	if (!ctx.cr6.eq) goto loc_82092574;
loc_8209258C:
	// lwz r11,96(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 96);
	// clrlwi r25,r23,16
	ctx.r25.u64 = ctx.r23.u32 & 0xFFFF;
	// cmplw cr6,r25,r11
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820929bc
	if (ctx.cr6.gt) goto loc_820929BC;
	// lwz r11,84(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// addi r10,r25,-1
	ctx.r10.s64 = ctx.r25.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820925c0
	if (ctx.cr6.eq) goto loc_820925C0;
	// lwz r9,88(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 88);
	// subf r8,r11,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r11.u64;
	// srawi r9,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x820925c4
	if (ctx.cr6.lt) goto loc_820925C4;
loc_820925C0:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_820925C4:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820929bc
	if (ctx.cr6.eq) goto loc_820929BC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820925E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,1
	ctx.r29.s64 = 1;
loc_820925EC:
	// clrlwi r29,r29,24
	ctx.r29.u64 = ctx.r29.u32 & 0xFF;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82092624
	if (ctx.cr6.eq) goto loc_82092624;
	// lwz r11,76(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 76);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// lwz r11,8248(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8248);
	// addi r9,r11,1998
	ctx.r9.s64 = ctx.r11.s64 + 1998;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,160(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 160);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82092620;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// sth r3,84(r31)
	REX_STORE_U16(ctx.r31.u32 + 84, ctx.r3.u16);
loc_82092624:
	// clrlwi r11,r20,16
	ctx.r11.u64 = ctx.r20.u32 & 0xFFFF;
	// sth r23,80(r31)
	REX_STORE_U16(ctx.r31.u32 + 80, ctx.r23.u16);
	// stw r16,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r16.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209263c
	if (ctx.cr6.eq) goto loc_8209263C;
	// sth r20,82(r31)
	REX_STORE_U16(ctx.r31.u32 + 82, ctx.r20.u16);
loc_8209263C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82092650;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82092688
	if (ctx.cr6.eq) goto loc_82092688;
	// lwz r11,76(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 76);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,156(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// lwz r8,148(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 148);
	// lwz r11,8248(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8248);
	// addi r7,r11,1998
	ctx.r7.s64 = ctx.r11.s64 + 1998;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r6,r9
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82092688;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82092688:
	// clrlwi r11,r26,24
	ctx.r11.u64 = ctx.r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82092700
	if (ctx.cr6.eq) goto loc_82092700;
	// lbz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 108);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lbz r10,109(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 109);
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lbz r9,110(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 110);
	// lfs f12,104(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,120(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// stb r11,48(r31)
	REX_STORE_U8(ctx.r31.u32 + 48, ctx.r11.u8);
	// lfs f8,124(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f8.f64 = double(temp.f32);
	// stb r10,49(r31)
	REX_STORE_U8(ctx.r31.u32 + 49, ctx.r10.u8);
	// lfs f7,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f7.f64 = double(temp.f32);
	// stb r9,50(r31)
	REX_STORE_U8(ctx.r31.u32 + 50, ctx.r9.u8);
	// lfs f6,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f6.f64 = double(temp.f32);
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// stfs f12,44(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// stfs f11,52(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// stfs f10,56(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// stfs f9,60(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 60, temp.u32);
	// stfs f8,64(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// stfs f7,68(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stfs f6,72(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lbz r8,86(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// ori r7,r8,128
	ctx.r7.u64 = ctx.r8.u64 | 128;
	// stb r7,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r7.u8);
loc_82092700:
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x82092714
	if (ctx.cr6.eq) goto loc_82092714;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820837c0
	ctx.lr = 0x82092714;
	sub_820837C0(ctx, base);
loc_82092714:
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// beq cr6,0x82092734
	if (ctx.cr6.eq) goto loc_82092734;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82092734;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82092734:
	// clrlwi r11,r18,31
	ctx.r11.u64 = ctx.r18.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82092758
	if (ctx.cr6.eq) goto loc_82092758;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// add r4,r28,r27
	ctx.r4.u64 = ctx.r28.u64 + ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82092758;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82092758:
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x82092840
	if (ctx.cr6.eq) goto loc_82092840;
	// stw r22,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r22.u32);
	// b 0x82092844
	goto loc_82092844;
loc_82092768:
	// rlwinm r11,r18,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820927b0
	if (ctx.cr6.eq) goto loc_820927B0;
	// clrlwi r11,r26,24
	ctx.r11.u64 = ctx.r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820927b0
	if (!ctx.cr6.eq) goto loc_820927B0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82083658
	ctx.lr = 0x82092788;
	sub_82083658(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,10
	ctx.r9.s64 = 10;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82092798:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82092798
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82092798;
	// li r26,1
	ctx.r26.s64 = 1;
loc_820927B0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// clrlwi r25,r23,16
	ctx.r25.u64 = ctx.r23.u32 & 0xFFFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820927C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplw cr6,r9,r25
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r25.u32, ctx.xer);
	// bne cr6,0x8209258c
	if (!ctx.cr6.eq) goto loc_8209258C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,132(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820927E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,86(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// rlwinm r8,r9,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820925ec
	if (ctx.cr6.eq) goto loc_820925EC;
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// beq cr6,0x8209282c
	if (ctx.cr6.eq) goto loc_8209282C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82092814;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// clrlwi r8,r19,16
	ctx.r8.u64 = ctx.r19.u32 & 0xFFFF;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8209282c
	if (!ctx.cr6.eq) goto loc_8209282C;
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
	// b 0x820925ec
	goto loc_820925EC;
loc_8209282C:
	// lbz r11,86(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r10,r10,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stb r10,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r10.u8);
	// b 0x820925ec
	goto loc_820925EC;
loc_82092840:
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
loc_82092844:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820928a4
	if (ctx.cr6.eq) goto loc_820928A4;
	// rlwinm r11,r18,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82092860
	if (ctx.cr6.eq) goto loc_82092860;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x820928a4
	if (ctx.cr6.eq) goto loc_820928A4;
loc_82092860:
	// lwz r11,76(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 76);
	// lbz r10,10344(r24)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r24.u32 + 10344);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r8,156(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// rlwinm r30,r9,27,31,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r11,8248(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 8248);
	// addi r7,r11,1998
	ctx.r7.s64 = ctx.r11.s64 + 1998;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r8
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82092894;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x82084db8
	ctx.lr = 0x820928A0;
	sub_82084DB8(ctx, base);
	// b 0x820929bc
	goto loc_820929BC;
loc_820928A4:
	// rlwinm r11,r18,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820929bc
	if (ctx.cr6.eq) goto loc_820929BC;
	// lwz r11,76(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 76);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// lwz r11,8248(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8248);
	// addi r9,r11,1998
	ctx.r9.s64 = ctx.r11.s64 + 1998;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820928D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// bl 0x82084c78
	ctx.lr = 0x820928E0;
	sub_82084C78(ctx, base);
	// b 0x820929bc
	goto loc_820929BC;
loc_820928E4:
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820928EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820929bc
	if (ctx.cr6.eq) goto loc_820929BC;
loc_820928F8:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpw cr6,r11,r16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r16.s32, ctx.xer);
	// beq cr6,0x82092914
	if (ctx.cr6.eq) goto loc_82092914;
	// lwz r31,88(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x820928f8
	if (!ctx.cr6.eq) goto loc_820928F8;
	// b 0x820929bc
	goto loc_820929BC;
loc_82092914:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x82092988
	if (ctx.cr6.eq) goto loc_82092988;
	// lbz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 108);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lbz r10,110(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 110);
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lbz r9,109(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 109);
	// lfs f12,104(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,124(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f9.f64 = double(temp.f32);
	// stb r11,48(r31)
	REX_STORE_U8(ctx.r31.u32 + 48, ctx.r11.u8);
	// lfs f8,120(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// stb r10,50(r31)
	REX_STORE_U8(ctx.r31.u32 + 50, ctx.r10.u8);
	// lfs f7,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f7.f64 = double(temp.f32);
	// stb r9,49(r31)
	REX_STORE_U8(ctx.r31.u32 + 49, ctx.r9.u8);
	// lfs f6,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f6.f64 = double(temp.f32);
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// stfs f12,44(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// stfs f11,52(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// stfs f10,56(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// stfs f9,64(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// stfs f8,60(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 60, temp.u32);
	// stfs f7,68(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stfs f6,72(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lbz r8,86(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 86);
	// ori r7,r8,128
	ctx.r7.u64 = ctx.r8.u64 | 128;
	// stb r7,86(r31)
	REX_STORE_U8(ctx.r31.u32 + 86, ctx.r7.u8);
loc_82092988:
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8209299c
	if (ctx.cr6.eq) goto loc_8209299C;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820837c0
	ctx.lr = 0x8209299C;
	sub_820837C0(ctx, base);
loc_8209299C:
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// beq cr6,0x820929bc
	if (ctx.cr6.eq) goto loc_820929BC;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820929BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820929BC:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r10,r11,-7008
	ctx.r10.s64 = ctx.r11.s64 + -7008;
	// stw r10,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// bl 0x82079970
	ctx.lr = 0x820929D0;
	sub_82079970(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
}
