DEFINE_REX_FUNC(sub_8207B150) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f8
	ctx.lr = 0x8207B158;
	__savegprlr_20(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r22,r4
	ctx.r22.u64 = ctx.r4.u64;
	// addi r3,r24,44
	ctx.r3.s64 = ctx.r24.s64 + 44;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r20,r7
	ctx.r20.u64 = ctx.r7.u64;
	// mr r21,r8
	ctx.r21.u64 = ctx.r8.u64;
	// bl 0x82082390
	ctx.lr = 0x8207B17C;
	sub_82082390(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// li r23,0
	ctx.r23.s64 = 0;
	// lis r27,-32768
	ctx.r27.s64 = -2147483648;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x8207b260
	if (!ctx.cr6.eq) goto loc_8207B260;
	// stw r23,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r23.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stb r23,152(r1)
	REX_STORE_U8(ctx.r1.u32 + 152, ctx.r23.u8);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8207af80
	ctx.lr = 0x8207B1A8;
	sub_8207AF80(ctx, base);
	// lwz r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x8207b204
	if (ctx.cr6.eq) goto loc_8207B204;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r10,r11,r12
	ctx.r10.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8207b1d0
	if (ctx.cr6.eq) goto loc_8207B1D0;
	// lwz r11,148(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// b 0x8207b1f8
	goto loc_8207B1F8;
loc_8207B1D0:
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8207b1f4
	if (ctx.cr6.eq) goto loc_8207B1F4;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x8207b1ec
	if (ctx.cr6.eq) goto loc_8207B1EC;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x8207b1f4
	if (!ctx.cr6.eq) goto loc_8207B1F4;
loc_8207B1EC:
	// lwz r11,148(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// b 0x8207b1f8
	goto loc_8207B1F8;
loc_8207B1F4:
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_8207B1F8:
	// mr r26,r11
	ctx.r26.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207b260
	if (!ctx.cr6.eq) goto loc_8207B260;
loc_8207B204:
	// lwz r10,0(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// clrlwi r11,r22,16
	ctx.r11.u64 = ctx.r22.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r9,76(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,156(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r10,10316(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 10316);
	// bne cr6,0x8207b23c
	if (!ctx.cr6.eq) goto loc_8207B23C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r10,12
	ctx.r4.s64 = ctx.r10.s64 + 12;
	// addi r3,r11,-7816
	ctx.r3.s64 = ctx.r11.s64 + -7816;
	// bl 0x820798d8
	ctx.lr = 0x8207B230;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x8207B234;
	sub_8208C5D8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
loc_8207B23C:
	// lwz r10,28(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-7816
	ctx.r3.s64 = ctx.r11.s64 + -7816;
	// lwzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x820798d8
	ctx.lr = 0x8207B254;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x8207B258;
	sub_8208C5D8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
loc_8207B260:
	// lhz r11,32(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 32);
	// mr r28,r23
	ctx.r28.u64 = ctx.r23.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207b2e8
	if (ctx.cr6.eq) goto loc_8207B2E8;
	// addi r30,r26,48
	ctx.r30.s64 = ctx.r26.s64 + 48;
loc_8207B274:
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8207b2cc
	if (ctx.cr6.eq) goto loc_8207B2CC;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r10,r11,r12
	ctx.r10.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8207b2cc
	if (ctx.cr6.eq) goto loc_8207B2CC;
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207b2cc
	if (ctx.cr6.eq) goto loc_8207B2CC;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207b2c0
	if (!ctx.cr6.eq) goto loc_8207B2C0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207B2C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207B2C0:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82066ea8
	ctx.lr = 0x8207B2CC;
	sub_82066EA8(ctx, base);
loc_8207B2CC:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// stw r23,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r23.u32);
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// lhz r11,32(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 32);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8207b274
	if (ctx.cr6.lt) goto loc_8207B274;
loc_8207B2E8:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x8207b318
	if (!ctx.cr6.gt) goto loc_8207B318;
	// addi r30,r26,48
	ctx.r30.s64 = ctx.r26.s64 + 48;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
loc_8207B2F8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r5,0(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8208bf38
	ctx.lr = 0x8207B308;
	sub_8208BF38(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x8207b2f8
	if (!ctx.cr0.eq) goto loc_8207B2F8;
loc_8207B318:
	// lwz r27,36(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 36);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8207b590
	if (ctx.cr6.eq) goto loc_8207B590;
	// lbz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 0);
	// mr r31,r23
	ctx.r31.u64 = ctx.r23.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207b344
	if (!ctx.cr6.eq) goto loc_8207B344;
loc_8207B334:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// lbzx r11,r31,r27
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r27.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207b334
	if (ctx.cr6.eq) goto loc_8207B334;
loc_8207B344:
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,156(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r11,10180(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 10180);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r8,r11,2513
	ctx.r8.s64 = ctx.r11.s64 + 2513;
	// stw r11,10180(r9)
	REX_STORE_U32(ctx.r9.u32 + 10180, ctx.r11.u32);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r26,r7,r9
	REX_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r26.u32);
	// lwz r6,0(r24)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r5,40(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 40);
	// lwz r4,76(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 76);
	// lwz r3,156(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 156);
	// lwz r11,8248(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8248);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r11,1998
	ctx.r10.s64 = ctx.r11.s64 + 1998;
	// stw r11,8248(r3)
	REX_STORE_U32(ctx.r3.u32 + 8248, ctx.r11.u32);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r5,r9,r3
	REX_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r5.u32);
	// stw r23,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r23.u32);
	// sth r23,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r23.u16);
	// stw r23,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r23.u32);
	// lhz r8,30(r26)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r26.u32 + 30);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// cmpw cr6,r31,r7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x8207b4c0
	if (!ctx.cr6.lt) goto loc_8207B4C0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32234
	ctx.r10.s64 = -2112487424;
	// addi r28,r11,-7756
	ctx.r28.s64 = ctx.r11.s64 + -7756;
	// addi r29,r10,-23272
	ctx.r29.s64 = ctx.r10.s64 + -23272;
loc_8207B3BC:
	// lbz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r21.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207b4c0
	if (!ctx.cr6.eq) goto loc_8207B4C0;
	// lbzx r10,r31,r27
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r27.u32);
	// add r11,r31,r27
	ctx.r11.u64 = ctx.r31.u64 + ctx.r27.u64;
	// li r30,1
	ctx.r30.s64 = 1;
	// cmpwi cr6,r10,128
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 128, ctx.xer);
	// stw r10,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// blt cr6,0x8207b41c
	if (ctx.cr6.lt) goto loc_8207B41C;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// li r30,3
	ctx.r30.s64 = 3;
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
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
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// sth r4,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r4.u16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8207b41c
	if (ctx.cr6.eq) goto loc_8207B41C;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// addi r30,r9,3
	ctx.r30.s64 = ctx.r9.s64 + 3;
	// stw r11,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
loc_8207B41C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8207b4c0
	if (ctx.cr6.eq) goto loc_8207B4C0;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r29
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8207b478
	if (!ctx.cr6.eq) goto loc_8207B478;
	// lwz r10,0(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// clrlwi r11,r22,16
	ctx.r11.u64 = ctx.r22.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r9,76(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,156(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r10,10316(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 10316);
	// bne cr6,0x8207b458
	if (!ctx.cr6.eq) goto loc_8207B458;
	// addi r4,r10,12
	ctx.r4.s64 = ctx.r10.s64 + 12;
	// b 0x8207b464
	goto loc_8207B464;
loc_8207B458:
	// lwz r10,28(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_8207B464:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x820798d8
	ctx.lr = 0x8207B470;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x8207B474;
	sub_8208C5D8(ctx, base);
	// lwz r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
loc_8207B478:
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwzx r10,r11,r29
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207B49C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,128(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// cmpwi cr6,r9,62
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 62, ctx.xer);
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// beq cr6,0x8207b4c0
	if (ctx.cr6.eq) goto loc_8207B4C0;
	// lhz r11,30(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 30);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpw cr6,r31,r10
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8207b3bc
	if (ctx.cr6.lt) goto loc_8207B3BC;
loc_8207B4C0:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82079a00
	ctx.lr = 0x8207B4C8;
	sub_82079A00(ctx, base);
	// addi r30,r26,48
	ctx.r30.s64 = ctx.r26.s64 + 48;
	// li r29,12
	ctx.r29.s64 = 12;
loc_8207B4D0:
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8207b544
	if (ctx.cr6.eq) goto loc_8207B544;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207b544
	if (ctx.cr6.eq) goto loc_8207B544;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8207b53c
	if (ctx.cr6.eq) goto loc_8207B53C;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r10,r11,r12
	ctx.r10.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8207b53c
	if (ctx.cr6.eq) goto loc_8207B53C;
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207b53c
	if (ctx.cr6.eq) goto loc_8207B53C;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207b530
	if (!ctx.cr6.eq) goto loc_8207B530;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207B530;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207B530:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82066ea8
	ctx.lr = 0x8207B53C;
	sub_82066EA8(ctx, base);
loc_8207B53C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r23,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r23.u32);
loc_8207B544:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// bne 0x8207b4d0
	if (!ctx.cr0.eq) goto loc_8207B4D0;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
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
	// stwx r23,r7,r9
	REX_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r23.u32);
	// lwz r11,8248(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8248);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// stw r6,8248(r9)
	REX_STORE_U32(ctx.r9.u32 + 8248, ctx.r6.u32);
	// lwz r5,0(r24)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r4,76(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 76);
	// lwz r3,156(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 156);
	// lwz r11,10180(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10180);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,10180(r3)
	REX_STORE_U32(ctx.r3.u32 + 10180, ctx.r11.u32);
loc_8207B590:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
}
