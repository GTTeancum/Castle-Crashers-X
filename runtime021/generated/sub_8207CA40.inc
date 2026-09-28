DEFINE_REX_FUNC(sub_8207CA40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x8207CA48;
	__savegprlr_25(ctx, base);
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// addi r31,r11,10372
	ctx.r31.s64 = ctx.r11.s64 + 10372;
	// lwz r11,15396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 15396);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,5024(r31)
	REX_STORE_U32(ctx.r31.u32 + 5024, ctx.r11.u32);
	// lwzx r30,r9,r31
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// and r7,r8,r12
	ctx.r7.u64 = ctx.r8.u64 & ctx.r12.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8207cac4
	if (ctx.cr6.eq) goto loc_8207CAC4;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207cac4
	if (ctx.cr6.eq) goto loc_8207CAC4;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207cab8
	if (!ctx.cr6.eq) goto loc_8207CAB8;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207CAB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207CAB8:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x8207CAC4;
	sub_82066EA8(ctx, base);
loc_8207CAC4:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r10,5024(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,76(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwzx r25,r9,r31
	ctx.r25.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// lwz r11,156(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 156);
	// addi r31,r11,10372
	ctx.r31.s64 = ctx.r11.s64 + 10372;
	// lwz r11,15396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 15396);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,5024(r31)
	REX_STORE_U32(ctx.r31.u32 + 5024, ctx.r11.u32);
	// lwzx r30,r7,r31
	ctx.r30.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r31.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// and r5,r6,r12
	ctx.r5.u64 = ctx.r6.u64 & ctx.r12.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x8207cb44
	if (ctx.cr6.eq) goto loc_8207CB44;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207cb44
	if (ctx.cr6.eq) goto loc_8207CB44;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207cb38
	if (!ctx.cr6.eq) goto loc_8207CB38;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207CB38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207CB38:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x8207CB44;
	sub_82066EA8(ctx, base);
loc_8207CB44:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r10,5024(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,76(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwzx r26,r9,r31
	ctx.r26.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// lwz r11,156(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 156);
	// addi r30,r11,10372
	ctx.r30.s64 = ctx.r11.s64 + 10372;
	// lwz r11,15396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 15396);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,5024(r30)
	REX_STORE_U32(ctx.r30.u32 + 5024, ctx.r11.u32);
	// lwzx r31,r7,r30
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r30.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// and r5,r6,r12
	ctx.r5.u64 = ctx.r6.u64 & ctx.r12.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x8207cbc4
	if (ctx.cr6.eq) goto loc_8207CBC4;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207cbc4
	if (ctx.cr6.eq) goto loc_8207CBC4;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207cbb8
	if (!ctx.cr6.eq) goto loc_8207CBB8;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207CBB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207CBB8:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x8207CBC4;
	sub_82066EA8(ctx, base);
loc_8207CBC4:
	// lwz r11,5024(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 5024);
	// li r31,0
	ctx.r31.s64 = 0;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r31,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r31.u32);
	// stb r31,212(r1)
	REX_STORE_U8(ctx.r1.u32 + 212, ctx.r31.u8);
	// lwzx r29,r9,r30
	ctx.r29.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r30.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x8207cd28
	if (ctx.cr6.eq) goto loc_8207CD28;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x8207cd28
	if (!ctx.cr6.eq) goto loc_8207CD28;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x8207cd28
	if (!ctx.cr6.eq) goto loc_8207CD28;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82082bb0
	ctx.lr = 0x8207CC0C;
	sub_82082BB0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82082bb0
	ctx.lr = 0x8207CC18;
	sub_82082BB0(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r31,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r31,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stw r31,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// stb r31,116(r1)
	REX_STORE_U8(ctx.r1.u32 + 116, ctx.r31.u8);
	// sth r31,120(r1)
	REX_STORE_U16(ctx.r1.u32 + 120, ctx.r31.u16);
	// bl 0x82082890
	ctx.lr = 0x8207CC40;
	sub_82082890(ctx, base);
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// stb r31,132(r1)
	REX_STORE_U8(ctx.r1.u32 + 132, ctx.r31.u8);
	// sth r3,124(r1)
	REX_STORE_U16(ctx.r1.u32 + 124, ctx.r3.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r9,76(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,156(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r10,10316(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 10316);
	// bne cr6,0x8207cc6c
	if (!ctx.cr6.eq) goto loc_8207CC6C;
	// addi r4,r10,12
	ctx.r4.s64 = ctx.r10.s64 + 12;
	// b 0x8207cc78
	goto loc_8207CC78;
loc_8207CC6C:
	// lwz r10,28(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_8207CC78:
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x82053a00
	ctx.lr = 0x8207CC80;
	sub_82053A00(ctx, base);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x8207cc90
	if (!ctx.cr6.lt) goto loc_8207CC90;
	// lwz r30,288(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 288);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
loc_8207CC90:
	// ble cr6,0x8207cca8
	if (!ctx.cr6.gt) goto loc_8207CCA8;
	// addi r11,r1,291
	ctx.r11.s64 = ctx.r1.s64 + 291;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// add r4,r11,r27
	ctx.r4.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// bl 0x82129ef8
	ctx.lr = 0x8207CCA8;
	sub_82129EF8(ctx, base);
loc_8207CCA8:
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// addi r11,r1,368
	ctx.r11.s64 = ctx.r1.s64 + 368;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stbx r31,r30,r9
	REX_STORE_U8(ctx.r30.u32 + ctx.r9.u32, ctx.r31.u8);
loc_8207CCB8:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8207ccb8
	if (!ctx.cr6.eq) goto loc_8207CCB8;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,132
	ctx.r3.s64 = ctx.r1.s64 + 132;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r5,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r5.u32);
	// bl 0x82129a70
	ctx.lr = 0x8207CCE4;
	sub_82129A70(ctx, base);
	// lwz r9,128(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// addi r10,r1,132
	ctx.r10.s64 = ctx.r1.s64 + 132;
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// addi r3,r1,212
	ctx.r3.s64 = ctx.r1.s64 + 212;
	// stbx r31,r9,r10
	REX_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r31.u8);
	// lwz r30,128(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x82129a70
	ctx.lr = 0x8207CD04;
	sub_82129A70(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r7,r1,212
	ctx.r7.s64 = ctx.r1.s64 + 212;
	// stw r30,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r30.u32);
	// addi r6,r8,-7140
	ctx.r6.s64 = ctx.r8.s64 + -7140;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r6,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// stbx r31,r30,r7
	REX_STORE_U8(ctx.r30.u32 + ctx.r7.u32, ctx.r31.u8);
	// bl 0x82079970
	ctx.lr = 0x8207CD24;
	sub_82079970(ctx, base);
	// b 0x8207cd38
	goto loc_8207CD38;
loc_8207CD28:
	// stb r31,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r31.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82053a00
	ctx.lr = 0x8207CD38;
	sub_82053A00(ctx, base);
loc_8207CD38:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// addi r4,r1,212
	ctx.r4.s64 = ctx.r1.s64 + 212;
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,156(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r3,10316(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x8207CD50;
	sub_8209D948(ctx, base);
	// li r8,8
	ctx.r8.s64 = 8;
	// sth r3,4(r29)
	REX_STORE_U16(ctx.r29.u32 + 4, ctx.r3.u16);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r8,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r8.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r6,76(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 76);
	// lwz r11,156(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 156);
	// addi r11,r11,10372
	ctx.r11.s64 = ctx.r11.s64 + 10372;
	// lwz r5,5024(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 5024);
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r4,r11
	REX_STORE_U32(ctx.r4.u32 + ctx.r11.u32, ctx.r29.u32);
	// lwz r10,5024(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 5024);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,5024(r11)
	REX_STORE_U32(ctx.r11.u32 + 5024, ctx.r10.u32);
	// stb r31,8(r25)
	REX_STORE_U8(ctx.r25.u32 + 8, ctx.r31.u8);
	// stw r31,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r31.u32);
	// stb r31,8(r26)
	REX_STORE_U8(ctx.r26.u32 + 8, ctx.r31.u8);
	// stw r31,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r31.u32);
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
