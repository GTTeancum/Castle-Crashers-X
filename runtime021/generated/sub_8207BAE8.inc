DEFINE_REX_FUNC(sub_8207BAE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8207BAF0;
	__savegprlr_23(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r24,20(r29)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8207bcf8
	if (ctx.cr6.eq) goto loc_8207BCF8;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r10,12(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r8,156(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// lis r9,-32234
	ctx.r9.s64 = -2112487424;
	// addi r26,r9,-23272
	ctx.r26.s64 = ctx.r9.s64 + -23272;
	// lwz r11,8248(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 8248);
	// addi r5,r11,1998
	ctx.r5.s64 = ctx.r11.s64 + 1998;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r25,r11,-7548
	ctx.r25.s64 = ctx.r11.s64 + -7548;
	// lwzx r28,r4,r8
	ctx.r28.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// stw r10,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r10.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stb r6,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r6.u8);
	// stw r27,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// addi r23,r10,-7700
	ctx.r23.s64 = ctx.r10.s64 + -7700;
	// sth r27,108(r1)
	REX_STORE_U16(ctx.r1.u32 + 108, ctx.r27.u16);
	// stw r27,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r27.u32);
loc_8207BB5C:
	// stw r27,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r27.u32);
	// add r11,r7,r24
	ctx.r11.u64 = ctx.r7.u64 + ctx.r24.u64;
	// stb r27,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r27.u8);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbzx r10,r7,r24
	ctx.r10.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r24.u32);
	// cmpwi cr6,r10,128
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 128, ctx.xer);
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// blt cr6,0x8207bbb8
	if (ctx.cr6.lt) goto loc_8207BBB8;
	// lbz r8,1(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// li r9,3
	ctx.r9.s64 = 3;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rotlwi r4,r8,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// clrlwi r8,r3,16
	ctx.r8.u64 = ctx.r3.u32 & 0xFFFF;
	// rlwinm r5,r8,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF;
	// rlwimi r5,r8,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r8,r5,16
	ctx.r8.u64 = ctx.r5.u32 & 0xFFFF;
	// sth r5,108(r1)
	REX_STORE_U16(ctx.r1.u32 + 108, ctx.r5.u16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8207bbb8
	if (ctx.cr6.eq) goto loc_8207BBB8;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// addi r9,r8,3
	ctx.r9.s64 = ctx.r8.s64 + 3;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
loc_8207BBB8:
	// add r30,r9,r7
	ctx.r30.u64 = ctx.r9.u64 + ctx.r7.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8207bca4
	if (ctx.cr6.eq) goto loc_8207BCA4;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r26
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8207bc70
	if (!ctx.cr6.eq) goto loc_8207BC70;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207BBE8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8207bc3c
	if (ctx.cr6.eq) goto loc_8207BC3C;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r8,72(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 72);
	// lwz r7,156(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r31,10316(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 10316);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8207BC18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207bc2c
	if (!ctx.cr6.eq) goto loc_8207BC2C;
	// addi r31,r31,12
	ctx.r31.s64 = ctx.r31.s64 + 12;
	// b 0x8207bc40
	goto loc_8207BC40;
loc_8207BC2C:
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// b 0x8207bc40
	goto loc_8207BC40;
loc_8207BC3C:
	// mr r31,r23
	ctx.r31.u64 = ctx.r23.u64;
loc_8207BC40:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207BC54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// bl 0x820798d8
	ctx.lr = 0x8207BC68;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x8207BC6C;
	sub_8208C5D8(ctx, base);
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_8207BC70:
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r10,r11,r26
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207BC94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r6,96(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// add r7,r3,r30
	ctx.r7.u64 = ctx.r3.u64 + ctx.r30.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8207bb5c
	if (ctx.cr6.eq) goto loc_8207BB5C;
loc_8207BCA4:
	// clrlwi r11,r6,24
	ctx.r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207bcd8
	if (ctx.cr6.eq) goto loc_8207BCD8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207a0d0
	ctx.lr = 0x8207BCB8;
	sub_8207A0D0(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// addi r3,r11,10372
	ctx.r3.s64 = ctx.r11.s64 + 10372;
	// bl 0x82079b48
	ctx.lr = 0x8207BCCC;
	sub_82079B48(ctx, base);
	// stw r27,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r27.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
loc_8207BCD8:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207bcf4
	if (ctx.cr6.eq) goto loc_8207BCF4;
	// lwz r10,12(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8207bcf4
	if (!ctx.cr6.eq) goto loc_8207BCF4;
	// stw r11,12(r29)
	REX_STORE_U32(ctx.r29.u32 + 12, ctx.r11.u32);
loc_8207BCF4:
	// stw r27,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r27.u32);
loc_8207BCF8:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
