DEFINE_REX_FUNC(sub_8206D440) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8206D448;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8206D458;
	sub_82053BC8(ctx, base);
	// li r23,1
	ctx.r23.s64 = 1;
	// li r31,4
	ctx.r31.s64 = 4;
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
loc_8206D464:
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r10,48(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r29,r9,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// bl 0x82067230
	ctx.lr = 0x8206D484;
	sub_82067230(ctx, base);
	// lwz r8,48(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwzx r7,r8,r29
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r29.u32);
	// stb r23,21(r7)
	REX_STORE_U8(ctx.r7.u32 + 21, ctx.r23.u8);
	// bne 0x8206d464
	if (!ctx.cr0.eq) goto loc_8206D464;
	// lis r25,-32218
	ctx.r25.s64 = -2111438848;
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// lwz r10,-6628(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
	// stw r27,-22656(r29)
	REX_STORE_U32(ctx.r29.u32 + -22656, ctx.r27.u32);
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8206d508
	if (!ctx.cr6.eq) goto loc_8206D508;
	// lwz r10,120(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 120);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206d4d4
	if (ctx.cr6.eq) goto loc_8206D4D4;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_8206D4D4:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206d4e4
	if (ctx.cr6.eq) goto loc_8206D4E4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8206D4E4:
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206d4f4
	if (ctx.cr6.eq) goto loc_8206D4F4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8206D4F4:
	// rlwinm r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206d52c
	if (ctx.cr6.eq) goto loc_8206D52C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x8206d52c
	goto loc_8206D52C;
loc_8206D508:
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206d52c
	if (ctx.cr6.eq) goto loc_8206D52C;
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206D528;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_8206D52C:
	// lis r24,-32215
	ctx.r24.s64 = -2111242240;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,-22660(r24)
	REX_STORE_U32(ctx.r24.u32 + -22660, ctx.r11.u32);
	// beq cr6,0x8206d68c
	if (ctx.cr6.eq) goto loc_8206D68C;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// addi r26,r11,-22652
	ctx.r26.s64 = ctx.r11.s64 + -22652;
loc_8206D548:
	// lwz r31,-6628(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206d5b0
	if (ctx.cr6.eq) goto loc_8206D5B0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206D56C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x8206d5b0
	if (!ctx.cr6.lt) goto loc_8206D5B0;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206D58C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206d5b0
	if (ctx.cr6.eq) goto loc_8206D5B0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206D5A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// bne cr6,0x8206d5b4
	if (!ctx.cr6.eq) goto loc_8206D5B4;
loc_8206D5B0:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8206D5B4:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206d67c
	if (!ctx.cr6.eq) goto loc_8206D67C;
	// lwz r11,-22656(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -22656);
	// lwz r31,-6628(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r10,r26
	REX_STORE_U32(ctx.r10.u32 + ctx.r26.u32, ctx.r30.u32);
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206d630
	if (ctx.cr6.eq) goto loc_8206D630;
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206D5F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x8206d630
	if (!ctx.cr6.lt) goto loc_8206D630;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206D610;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206d630
	if (ctx.cr6.eq) goto loc_8206D630;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206D628;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206d634
	goto loc_8206D634;
loc_8206D630:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
loc_8206D634:
	// lwz r11,-22656(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -22656);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,48(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r7,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// bl 0x82067518
	ctx.lr = 0x8206D658;
	sub_82067518(ctx, base);
	// lwz r11,-22656(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -22656);
	// lwz r4,48(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r11,-22656(r29)
	REX_STORE_U32(ctx.r29.u32 + -22656, ctx.r11.u32);
	// addi r6,r10,5
	ctx.r6.s64 = ctx.r10.s64 + 5;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r4
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r4.u32);
	// stb r27,21(r3)
	REX_STORE_U8(ctx.r3.u32 + 21, ctx.r27.u8);
loc_8206D67C:
	// lwz r11,-22660(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -22660);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8206d548
	if (ctx.cr6.lt) goto loc_8206D548;
loc_8206D68C:
	// lwz r10,48(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// lis r9,30583
	ctx.r9.s64 = 2004287488;
	// lis r8,-1
	ctx.r8.s64 = -65536;
	// ori r7,r9,30719
	ctx.r7.u64 = ctx.r9.u64 | 30719;
	// ori r6,r8,255
	ctx.r6.u64 = ctx.r8.u64 | 255;
	// lhz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// addi r5,r11,5
	ctx.r5.s64 = ctx.r11.s64 + 5;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// stw r7,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// sth r23,8(r10)
	REX_STORE_U16(ctx.r10.u32 + 8, ctx.r23.u16);
	// lwz r11,24(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// stw r6,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r6.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
