DEFINE_REX_FUNC(sub_820A43E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x820A43F0;
	__savegprlr_22(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r11,12(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a47dc
	if (ctx.cr6.eq) goto loc_820A47DC;
	// lis r23,-32218
	ctx.r23.s64 = -2111438848;
	// lwz r3,-6652(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + -6652);
	// bl 0x8209b730
	ctx.lr = 0x820A4410;
	sub_8209B730(ctx, base);
	// lwz r3,12(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A4424;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,5132
	ctx.r3.s64 = ctx.r9.s64 + 5132;
	// bl 0x8208c5d8
	ctx.lr = 0x820A4434;
	sub_8208C5D8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,12(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 12);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,56(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820A444C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,36(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 36);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820A445C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,5152
	ctx.r3.s64 = ctx.r11.s64 + 5152;
	// bl 0x8208c5d8
	ctx.lr = 0x820A446C;
	sub_8208C5D8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r28,257
	ctx.r28.s64 = 257;
	// li r29,17
	ctx.r29.s64 = 17;
loc_820A4478:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820a39f0
	ctx.lr = 0x820A4484;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a4538
	if (ctx.cr6.eq) goto loc_820A4538;
	// lwz r3,12(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A44A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r9,0(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A44BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stb r30,20(r31)
	REX_STORE_U8(ctx.r31.u32 + 20, ctx.r30.u8);
	// lwz r6,0(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r5,40(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 40);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820A44D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-6652(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + -6652);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lbz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// beq cr6,0x820a4514
	if (ctx.cr6.eq) goto loc_820A4514;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a44fc
	if (!ctx.cr6.eq) goto loc_820A44FC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r28,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r28.u32);
	// b 0x820a4538
	goto loc_820A4538;
loc_820A44FC:
	// lbz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 20);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stw r28,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r28.u32);
	// b 0x820a4538
	goto loc_820A4538;
loc_820A4514:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a4524
	if (!ctx.cr6.eq) goto loc_820A4524;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820a4534
	goto loc_820A4534;
loc_820A4524:
	// lbz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 20);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
loc_820A4534:
	// stw r29,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r29.u32);
loc_820A4538:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x820a4478
	if (ctx.cr6.lt) goto loc_820A4478;
	// lwz r3,12(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 12);
	// li r29,0
	ctx.r29.s64 = 0;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A4560;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a4694
	if (ctx.cr6.eq) goto loc_820A4694;
	// li r24,256
	ctx.r24.s64 = 256;
	// li r27,2
	ctx.r27.s64 = 2;
	// li r26,16
	ctx.r26.s64 = 16;
loc_820A4574:
	// lwz r3,12(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 12);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A458C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A45A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820a4674
	if (!ctx.cr6.eq) goto loc_820A4674;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A45BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820a39f0
	ctx.lr = 0x820A45CC;
	sub_820A39F0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a45f4
	if (ctx.cr6.eq) goto loc_820A45F4;
loc_820A45D8:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820a39f0
	ctx.lr = 0x820A45E8;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a45d8
	if (!ctx.cr6.eq) goto loc_820A45D8;
loc_820A45F4:
	// stb r29,20(r30)
	REX_STORE_U8(ctx.r30.u32 + 20, ctx.r29.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820A460C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-6652(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + -6652);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lbz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// beq cr6,0x820a4648
	if (ctx.cr6.eq) goto loc_820A4648;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a4630
	if (!ctx.cr6.eq) goto loc_820A4630;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r24,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r24.u32);
	// b 0x820a466c
	goto loc_820A466C;
loc_820A4630:
	// lbz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 20);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stw r24,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r24.u32);
	// b 0x820a466c
	goto loc_820A466C;
loc_820A4648:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a4658
	if (!ctx.cr6.eq) goto loc_820A4658;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820a4668
	goto loc_820A4668;
loc_820A4658:
	// lbz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 20);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
loc_820A4668:
	// stw r26,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r26.u32);
loc_820A466C:
	// stw r27,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r27.u32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
loc_820A4674:
	// lwz r3,12(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 12);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A468C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r28,r3
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x820a4574
	if (ctx.cr6.lt) goto loc_820A4574;
loc_820A4694:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,5164
	ctx.r3.s64 = ctx.r11.s64 + 5164;
	// bl 0x8208c5d8
	ctx.lr = 0x820A46A0;
	sub_8208C5D8(ctx, base);
	// lwz r3,12(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 12);
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,52(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 52);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820A46B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a47dc
	if (ctx.cr6.eq) goto loc_820A47DC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r28,-32218
	ctx.r28.s64 = -2111438848;
	// li r27,1
	ctx.r27.s64 = 1;
	// addi r26,r11,5200
	ctx.r26.s64 = ctx.r11.s64 + 5200;
loc_820A46D0:
	// lwz r3,12(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A46E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820A46FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820A4714;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,0(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// lbz r22,20(r30)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r30.u32 + 20);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,20(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 20);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x820A4730;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x820A4748;
	sub_8208C5D8(ctx, base);
	// lwz r11,-6652(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + -6652);
	// lbz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a4760
	if (!ctx.cr6.eq) goto loc_820A4760;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x820a4770
	goto loc_820A4770;
loc_820A4760:
	// lbz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 20);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r9,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
loc_820A4770:
	// addi r9,r31,192
	ctx.r9.s64 = ctx.r31.s64 + 192;
	// stb r27,35(r10)
	REX_STORE_U8(ctx.r10.u32 + 35, ctx.r27.u8);
	// lwz r11,-6624(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// sth r9,128(r1)
	REX_STORE_U16(ctx.r1.u32 + 128, ctx.r9.u16);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// lbz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 20);
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// bl 0x82052ea8
	ctx.lr = 0x820A4794;
	sub_82052EA8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r11,-6624(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -6624);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// stw r29,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r29.u32);
	// lbz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 20);
	// addi r6,r11,188
	ctx.r6.s64 = ctx.r11.s64 + 188;
	// sth r6,128(r1)
	REX_STORE_U16(ctx.r1.u32 + 128, ctx.r6.u16);
	// bl 0x82052ea8
	ctx.lr = 0x820A47B8;
	sub_82052EA8(ctx, base);
	// stw r27,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r27.u32);
	// lwz r3,12(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 12);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// lwz r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,52(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820A47D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r31,r3
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x820a46d0
	if (ctx.cr6.lt) goto loc_820A46D0;
loc_820A47DC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
