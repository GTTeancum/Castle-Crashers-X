DEFINE_REX_FUNC(sub_8207FE10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f8
	ctx.lr = 0x8207FE18;
	__savegprlr_20(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// mr r20,r7
	ctx.r20.u64 = ctx.r7.u64;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
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
	// beq cr6,0x8207fe98
	if (ctx.cr6.eq) goto loc_8207FE98;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207fe98
	if (ctx.cr6.eq) goto loc_8207FE98;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207fe8c
	if (!ctx.cr6.eq) goto loc_8207FE8C;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207FE8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207FE8C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x8207FE98;
	sub_82066EA8(ctx, base);
loc_8207FE98:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
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
	// lwzx r21,r9,r31
	ctx.r21.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
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
	// beq cr6,0x8207ff18
	if (ctx.cr6.eq) goto loc_8207FF18;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207ff18
	if (ctx.cr6.eq) goto loc_8207FF18;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207ff0c
	if (!ctx.cr6.eq) goto loc_8207FF0C;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207FF0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207FF0C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x8207FF18;
	sub_82066EA8(ctx, base);
loc_8207FF18:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
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
	// lwzx r22,r9,r31
	ctx.r22.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
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
	// beq cr6,0x8207ff98
	if (ctx.cr6.eq) goto loc_8207FF98;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207ff98
	if (ctx.cr6.eq) goto loc_8207FF98;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8207ff8c
	if (!ctx.cr6.eq) goto loc_8207FF8C;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8207FF8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207FF8C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x8207FF98;
	sub_82066EA8(ctx, base);
loc_8207FF98:
	// lwz r11,5024(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// lis r25,-32768
	ctx.r25.s64 = -2147483648;
	// li r24,0
	ctx.r24.s64 = 0;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r23,r24
	ctx.r23.u64 = ctx.r24.u64;
	// lwzx r26,r10,r31
	ctx.r26.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// lwz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmpw cr6,r9,r25
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r25.s32, ctx.xer);
	// beq cr6,0x82080070
	if (ctx.cr6.eq) goto loc_82080070;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82082bb0
	ctx.lr = 0x8207FFC4;
	sub_82082BB0(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// ble cr6,0x82080068
	if (!ctx.cr6.gt) goto loc_82080068;
	// addi r27,r1,112
	ctx.r27.s64 = ctx.r1.s64 + 112;
	// mr r28,r23
	ctx.r28.u64 = ctx.r23.u64;
loc_8207FFD8:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
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
	// beq cr6,0x8208004c
	if (ctx.cr6.eq) goto loc_8208004C;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208004c
	if (ctx.cr6.eq) goto loc_8208004C;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82080040
	if (!ctx.cr6.eq) goto loc_82080040;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82080040;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82080040:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82066ea8
	ctx.lr = 0x8208004C;
	sub_82066EA8(ctx, base);
loc_8208004C:
	// lwz r11,5024(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// stw r9,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r9.u32);
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// bne 0x8207ffd8
	if (!ctx.cr0.eq) goto loc_8207FFD8;
loc_82080068:
	// stw r25,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r25.u32);
	// stw r24,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r24.u32);
loc_82080070:
	// lwz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// cmpw cr6,r11,r25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r25.s32, ctx.xer);
	// beq cr6,0x820802c0
	if (ctx.cr6.eq) goto loc_820802C0;
	// lwz r10,0(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// cmpw cr6,r10,r25
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r25.s32, ctx.xer);
	// beq cr6,0x820802c0
	if (ctx.cr6.eq) goto loc_820802C0;
	// cmpwi cr6,r11,1024
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1024, ctx.xer);
	// bgt cr6,0x82080168
	if (ctx.cr6.gt) goto loc_82080168;
	// beq cr6,0x82080180
	if (ctx.cr6.eq) goto loc_82080180;
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// bgt cr6,0x8208015c
	if (ctx.cr6.gt) goto loc_8208015C;
	// beq cr6,0x82080180
	if (ctx.cr6.eq) goto loc_82080180;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x820800b4
	if (ctx.cr6.eq) goto loc_820800B4;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// beq cr6,0x82080180
	if (ctx.cr6.eq) goto loc_82080180;
	// b 0x820802c0
	goto loc_820802C0;
loc_820800B4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r24,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r24.u32);
	// addi r31,r11,-7140
	ctx.r31.s64 = ctx.r11.s64 + -7140;
	// stw r24,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r24.u32);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// stb r24,100(r1)
	REX_STORE_U8(ctx.r1.u32 + 100, ctx.r24.u8);
	// sth r24,104(r1)
	REX_STORE_U16(ctx.r1.u32 + 104, ctx.r24.u16);
	// bl 0x82082890
	ctx.lr = 0x820800E4;
	sub_82082890(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// sth r3,108(r1)
	REX_STORE_U16(ctx.r1.u32 + 108, ctx.r3.u16);
	// lwz r8,76(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r7,156(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 156);
	// lwz r11,8248(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 8248);
	// addi r6,r11,1998
	ctx.r6.s64 = ctx.r11.s64 + 1998;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r7
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// lwz r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82080114;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
	// lwz r9,76(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r28,156(r9)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// bl 0x82082890
	ctx.lr = 0x8208012C;
	sub_82082890(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r9,r20
	ctx.r9.u64 = ctx.r20.u64;
	// bl 0x8207a5d8
	ctx.lr = 0x8208014C;
	sub_8207A5D8(ctx, base);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82079970
	ctx.lr = 0x82080158;
	sub_82079970(ctx, base);
	// b 0x820802c0
	goto loc_820802C0;
loc_8208015C:
	// cmpwi cr6,r11,512
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 512, ctx.xer);
	// beq cr6,0x82080180
	if (ctx.cr6.eq) goto loc_82080180;
	// b 0x820802c0
	goto loc_820802C0;
loc_82080168:
	// cmpwi cr6,r11,4096
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4096, ctx.xer);
	// beq cr6,0x82080180
	if (ctx.cr6.eq) goto loc_82080180;
	// cmpwi cr6,r11,8192
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8192, ctx.xer);
	// beq cr6,0x82080180
	if (ctx.cr6.eq) goto loc_82080180;
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// bne cr6,0x820802c0
	if (!ctx.cr6.eq) goto loc_820802C0;
loc_82080180:
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r10,r11,r12
	ctx.r10.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820801b0
	if (!ctx.cr6.eq) goto loc_820801B0;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820802c0
	if (ctx.cr6.eq) goto loc_820802C0;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x820801b0
	if (ctx.cr6.eq) goto loc_820801B0;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x820802c0
	if (!ctx.cr6.eq) goto loc_820802C0;
loc_820801B0:
	// lwz r31,4(r22)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r22.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820802c0
	if (ctx.cr6.eq) goto loc_820802C0;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
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
	// lwzx r3,r7,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,140(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 140);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820801E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// addi r27,r1,112
	ctx.r27.s64 = ctx.r1.s64 + 112;
	// lwz r11,76(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 76);
	// lwz r25,156(r11)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x82082890
	ctx.lr = 0x82080208;
	sub_82082890(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r9,r20
	ctx.r9.u64 = ctx.r20.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82080230;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r8,76(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r7,156(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 156);
	// lwz r11,8248(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 8248);
	// addi r6,r11,1998
	ctx.r6.s64 = ctx.r11.s64 + 1998;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r7
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// lwz r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208025C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820802c0
	if (ctx.cr6.eq) goto loc_820802C0;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,156(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r10,8248(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8248);
	// addi r9,r10,1998
	ctx.r9.s64 = ctx.r10.s64 + 1998;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// lhz r6,24(r7)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r7.u32 + 24);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820802b8
	if (ctx.cr6.eq) goto loc_820802B8;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r10,r10,1998
	ctx.r10.s64 = ctx.r10.s64 + 1998;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,140(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 140);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820802B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r3,r28
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x820802c0
	if (ctx.cr6.eq) goto loc_820802C0;
loc_820802B8:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,0(r20)
	REX_STORE_U8(ctx.r20.u32 + 0, ctx.r11.u8);
loc_820802C0:
	// lbz r11,0(r20)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r20.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82080324
	if (!ctx.cr6.eq) goto loc_82080324;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r9,r10,r12
	ctx.r9.u64 = ctx.r10.u64 & ctx.r12.u64;
	// lwz r8,76(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r11,156(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 156);
	// addi r31,r11,10372
	ctx.r31.s64 = ctx.r11.s64 + 10372;
	// beq cr6,0x8208030c
	if (ctx.cr6.eq) goto loc_8208030C;
	// lwz r3,4(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// lhz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208030c
	if (ctx.cr6.eq) goto loc_8208030C;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82066ea8
	ctx.lr = 0x8208030C;
	sub_82066EA8(ctx, base);
loc_8208030C:
	// lwz r11,5024(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r26,r10,r31
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, ctx.r26.u32);
	// lwz r11,5024(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 5024);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,5024(r31)
	REX_STORE_U32(ctx.r31.u32 + 5024, ctx.r9.u32);
loc_82080324:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// ble cr6,0x8208034c
	if (!ctx.cr6.gt) goto loc_8208034C;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_82080334:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stb r24,8(r9)
	REX_STORE_U8(ctx.r9.u32 + 8, ctx.r24.u8);
	// stw r24,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r24.u32);
	// bne 0x82080334
	if (!ctx.cr0.eq) goto loc_82080334;
loc_8208034C:
	// stb r24,8(r21)
	REX_STORE_U8(ctx.r21.u32 + 8, ctx.r24.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r24,4(r21)
	REX_STORE_U32(ctx.r21.u32 + 4, ctx.r24.u32);
	// stb r24,8(r22)
	REX_STORE_U8(ctx.r22.u32 + 8, ctx.r24.u8);
	// stw r24,4(r22)
	REX_STORE_U32(ctx.r22.u32 + 4, ctx.r24.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
}
