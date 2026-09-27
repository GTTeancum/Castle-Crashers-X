DEFINE_REX_FUNC(sub_8207B630) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e4
	ctx.lr = 0x8207B638;
	__savegprlr_15(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r16,1
	ctx.r16.s64 = 1;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
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
	// lwzx r26,r7,r9
	ctx.r26.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lhz r11,144(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 144);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207b670
	if (ctx.cr6.eq) goto loc_8207B670;
	// mr r16,r11
	ctx.r16.u64 = ctx.r11.u64;
loc_8207B670:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// addi r3,r28,64
	ctx.r3.s64 = ctx.r28.s64 + 64;
	// bl 0x82082390
	ctx.lr = 0x8207B67C;
	sub_82082390(ctx, base);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x8207b8ac
	if (ctx.cr6.eq) goto loc_8207B8AC;
	// addi r17,r28,24
	ctx.r17.s64 = ctx.r28.s64 + 24;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// bl 0x82082390
	ctx.lr = 0x8207B698;
	sub_82082390(ctx, base);
	// cntlzw r11,r3
	ctx.r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r3,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// lwz r18,0(r20)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// mr r23,r27
	ctx.r23.u64 = ctx.r27.u64;
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// xori r15,r10,1
	ctx.r15.u64 = ctx.r10.u64 ^ 1;
	// beq cr6,0x8207b884
	if (ctx.cr6.eq) goto loc_8207B884;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32234
	ctx.r9.s64 = -2112487424;
	// mr r21,r27
	ctx.r21.u64 = ctx.r27.u64;
	// addi r22,r11,-7688
	ctx.r22.s64 = ctx.r11.s64 + -7688;
	// addi r19,r10,-7700
	ctx.r19.s64 = ctx.r10.s64 + -7700;
	// addi r24,r9,-23272
	ctx.r24.s64 = ctx.r9.s64 + -23272;
loc_8207B6D8:
	// lwz r11,4(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 4);
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// add r11,r21,r11
	ctx.r11.u64 = ctx.r21.u64 + ctx.r11.u64;
	// lwz r25,4(r11)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stb r8,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r8.u8);
	// stw r27,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// sth r27,108(r1)
	REX_STORE_U16(ctx.r1.u32 + 108, ctx.r27.u16);
	// stw r27,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r27.u32);
loc_8207B6FC:
	// stw r27,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r27.u32);
	// add r11,r30,r25
	ctx.r11.u64 = ctx.r30.u64 + ctx.r25.u64;
	// stb r27,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r27.u8);
	// li r29,1
	ctx.r29.s64 = 1;
	// lbzx r10,r30,r25
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r25.u32);
	// cmpwi cr6,r10,128
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 128, ctx.xer);
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// blt cr6,0x8207b758
	if (ctx.cr6.lt) goto loc_8207B758;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// li r29,3
	ctx.r29.s64 = 3;
	// lbz r7,2(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rotlwi r6,r9,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// or r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 | ctx.r7.u64;
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
	// beq cr6,0x8207b758
	if (ctx.cr6.eq) goto loc_8207B758;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// addi r29,r9,3
	ctx.r29.s64 = ctx.r9.s64 + 3;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
loc_8207B758:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8207b848
	if (ctx.cr6.eq) goto loc_8207B848;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r24
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8207b810
	if (!ctx.cr6.eq) goto loc_8207B810;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207B784;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8207b7d8
	if (ctx.cr6.eq) goto loc_8207B7D8;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
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
	ctx.lr = 0x8207B7B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207b7c8
	if (!ctx.cr6.eq) goto loc_8207B7C8;
	// addi r31,r31,12
	ctx.r31.s64 = ctx.r31.s64 + 12;
	// b 0x8207b7dc
	goto loc_8207B7DC;
loc_8207B7C8:
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// b 0x8207b7dc
	goto loc_8207B7DC;
loc_8207B7D8:
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
loc_8207B7DC:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207B7F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// bl 0x820798d8
	ctx.lr = 0x8207B808;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x8207B80C;
	sub_8208C5D8(ctx, base);
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_8207B810:
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwzx r10,r11,r24
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207B834;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// add r11,r3,r29
	ctx.r11.u64 = ctx.r3.u64 + ctx.r29.u64;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8207b6fc
	if (ctx.cr6.eq) goto loc_8207B6FC;
loc_8207B848:
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207b868
	if (!ctx.cr6.eq) goto loc_8207B868;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// addi r21,r21,8
	ctx.r21.s64 = ctx.r21.s64 + 8;
	// cmplw cr6,r23,r18
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r18.u32, ctx.xer);
	// blt cr6,0x8207b6d8
	if (ctx.cr6.lt) goto loc_8207B6D8;
	// b 0x8207b884
	goto loc_8207B884;
loc_8207B868:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207a0d0
	ctx.lr = 0x8207B870;
	sub_8207A0D0(ctx, base);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// addi r3,r11,10372
	ctx.r3.s64 = ctx.r11.s64 + 10372;
	// bl 0x82079b48
	ctx.lr = 0x8207B884;
	sub_82079B48(ctx, base);
loc_8207B884:
	// lwz r5,4(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8207b8a8
	if (ctx.cr6.eq) goto loc_8207B8A8;
	// clrlwi r11,r15,24
	ctx.r11.u64 = ctx.r15.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207b8a8
	if (!ctx.cr6.eq) goto loc_8207B8A8;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// bl 0x820936b0
	ctx.lr = 0x8207B8A8;
	sub_820936B0(ctx, base);
loc_8207B8A8:
	// stw r27,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r27.u32);
loc_8207B8AC:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
}
