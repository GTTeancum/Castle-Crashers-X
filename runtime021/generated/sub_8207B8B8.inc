DEFINE_REX_FUNC(sub_8207B8B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x8207B8C0;
	__savegprlr_22(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207bae0
	if (ctx.cr6.eq) goto loc_8207BAE0;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
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
	// lwzx r27,r7,r9
	ctx.r27.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r6,0(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r5,52(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 52);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8207B904;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// stw r26,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r26.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// sth r26,108(r1)
	REX_STORE_U16(ctx.r1.u32 + 108, ctx.r26.u16);
	// lis r9,-32234
	ctx.r9.s64 = -2112487424;
	// stb r8,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r8.u8);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// stw r26,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r26.u32);
	// stw r4,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r4.u32);
	// addi r24,r11,-7608
	ctx.r24.s64 = ctx.r11.s64 + -7608;
	// addi r22,r10,-7700
	ctx.r22.s64 = ctx.r10.s64 + -7700;
	// addi r25,r9,-23272
	ctx.r25.s64 = ctx.r9.s64 + -23272;
	// lwz r23,16(r30)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
loc_8207B944:
	// stw r26,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r26.u32);
	// add r11,r29,r23
	ctx.r11.u64 = ctx.r29.u64 + ctx.r23.u64;
	// stb r26,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r26.u8);
	// li r28,1
	ctx.r28.s64 = 1;
	// lbzx r10,r29,r23
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + ctx.r23.u32);
	// cmpwi cr6,r10,128
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 128, ctx.xer);
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// blt cr6,0x8207b9a0
	if (ctx.cr6.lt) goto loc_8207B9A0;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// li r28,3
	ctx.r28.s64 = 3;
	// lbz r7,2(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rotlwi r6,r9,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// clrlwi r4,r5,16
	ctx.r4.u64 = ctx.r5.u32 & 0xFFFF;
	// rlwinm r3,r4,24,24,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF;
	// rlwimi r3,r4,8,16,23
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFF00) | (ctx.r3.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r3,108(r1)
	REX_STORE_U16(ctx.r1.u32 + 108, ctx.r3.u16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8207b9a0
	if (ctx.cr6.eq) goto loc_8207B9A0;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// addi r28,r9,3
	ctx.r28.s64 = ctx.r9.s64 + 3;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
loc_8207B9A0:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8207ba8c
	if (ctx.cr6.eq) goto loc_8207BA8C;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r25
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8207ba54
	if (!ctx.cr6.eq) goto loc_8207BA54;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207B9CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8207ba20
	if (ctx.cr6.eq) goto loc_8207BA20;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
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
	ctx.lr = 0x8207B9FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207ba10
	if (!ctx.cr6.eq) goto loc_8207BA10;
	// addi r31,r31,12
	ctx.r31.s64 = ctx.r31.s64 + 12;
	// b 0x8207ba24
	goto loc_8207BA24;
loc_8207BA10:
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// b 0x8207ba24
	goto loc_8207BA24;
loc_8207BA20:
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
loc_8207BA24:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207BA38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// bl 0x820798d8
	ctx.lr = 0x8207BA4C;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x8207BA50;
	sub_8208C5D8(ctx, base);
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_8207BA54:
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r10,r11,r25
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207BA78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// add r11,r3,r28
	ctx.r11.u64 = ctx.r3.u64 + ctx.r28.u64;
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8207b944
	if (ctx.cr6.eq) goto loc_8207B944;
loc_8207BA8C:
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207bac0
	if (ctx.cr6.eq) goto loc_8207BAC0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207a0d0
	ctx.lr = 0x8207BAA0;
	sub_8207A0D0(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// addi r3,r11,10372
	ctx.r3.s64 = ctx.r11.s64 + 10372;
	// bl 0x82079b48
	ctx.lr = 0x8207BAB4;
	sub_82079B48(ctx, base);
	// stw r26,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r26.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8207BAC0:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207badc
	if (ctx.cr6.eq) goto loc_8207BADC;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8207badc
	if (!ctx.cr6.eq) goto loc_8207BADC;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
loc_8207BADC:
	// stw r26,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r26.u32);
loc_8207BAE0:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
