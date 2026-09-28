DEFINE_REX_FUNC(sub_821141E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x821141F0;
	__savegprlr_23(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// li r24,0
	ctx.r24.s64 = 0;
	// lis r10,-32646
	ctx.r10.s64 = -2139488256;
	// lis r9,-32646
	ctx.r9.s64 = -2139488256;
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,26(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 26);
	// ori r26,r10,4104
	ctx.r26.u64 = ctx.r10.u64 | 4104;
	// ori r23,r9,4106
	ctx.r23.u64 = ctx.r9.u64 | 4106;
	// mr r27,r24
	ctx.r27.u64 = ctx.r24.u64;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x82114230
	if (!ctx.cr6.lt) goto loc_82114230;
	// mr r31,r23
	ctx.r31.u64 = ctx.r23.u64;
	// b 0x821144e0
	goto loc_821144E0;
loc_82114230:
	// lwz r9,160(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 160);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r25,30
	ctx.r10.s64 = ctx.r25.s64 + 30;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lhz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// sth r9,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r9.u16);
loc_82114250:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82114270
	if (!ctx.cr0.eq) goto loc_82114270;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x82114250
	if (!ctx.cr6.eq) goto loc_82114250;
loc_82114270:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82114284
	if (ctx.cr0.eq) goto loc_82114284;
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4111
	ctx.r31.u64 = ctx.r31.u64 | 4111;
	// b 0x821144e0
	goto loc_821144E0;
loc_82114284:
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r25,16
	ctx.r4.s64 = ctx.r25.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210ccc0
	ctx.lr = 0x82114294;
	sub_8210CCC0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x821144d4
	if (!ctx.cr0.eq) goto loc_821144D4;
	// lwz r11,22(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 22);
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82114358
	if (!ctx.cr6.eq) goto loc_82114358;
	// lwz r10,26(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 26);
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// blt cr6,0x82114394
	if (ctx.cr6.lt) goto loc_82114394;
	// lwz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1);
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x82114394
	if (!ctx.cr6.eq) goto loc_82114394;
	// lwz r28,5(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 5);
	// lis r11,4096
	ctx.r11.s64 = 268435456;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82114598
	if (ctx.cr6.gt) goto loc_82114598;
	// lwz r11,820(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 820);
	// rlwinm. r11,r11,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82114394
	if (ctx.cr0.eq) goto loc_82114394;
	// lwz r10,152(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 152);
	// lwz r11,704(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 704);
	// lwz r9,156(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 156);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82114304
	if (ctx.cr6.lt) goto loc_82114304;
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4101
	ctx.r31.u64 = ctx.r31.u64 | 4101;
	// b 0x821144d4
	goto loc_821144D4;
loc_82114304:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821155f0
	ctx.lr = 0x82114310;
	sub_821155F0(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x82114324
	if (!ctx.cr0.eq) goto loc_82114324;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x821144d4
	goto loc_821144D4;
loc_82114324:
	// lwz r9,704(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 704);
	// addi r11,r30,712
	ctx.r11.s64 = ctx.r30.s64 + 712;
	// addi r10,r27,4
	ctx.r10.s64 = ctx.r27.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// stw r9,704(r30)
	REX_STORE_U32(ctx.r30.u32 + 704, ctx.r9.u32);
	// stw r11,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
	// lwz r11,716(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 716);
	// stw r11,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
	// lwz r11,716(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 716);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r10,716(r30)
	REX_STORE_U32(ctx.r30.u32 + 716, ctx.r10.u32);
	// b 0x82114414
	goto loc_82114414;
loc_82114358:
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x82114598
	if (!ctx.cr6.eq) goto loc_82114598;
	// lwz r10,26(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 26);
	// cmplwi cr6,r10,13
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 13, ctx.xer);
	// blt cr6,0x82114394
	if (ctx.cr6.lt) goto loc_82114394;
	// lwz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1);
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x82114394
	if (!ctx.cr6.eq) goto loc_82114394;
	// lwz r28,9(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 9);
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// cmplw cr6,r28,r10
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82114598
	if (ctx.cr6.gt) goto loc_82114598;
	// lwz r10,820(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 820);
	// rlwinm. r10,r10,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8211439c
	if (!ctx.cr0.eq) goto loc_8211439C;
loc_82114394:
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// b 0x821144d4
	goto loc_821144D4;
loc_8211439C:
	// lwz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 5);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82114598
	if (ctx.cr6.eq) goto loc_82114598;
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x82114598
	if (ctx.cr6.eq) goto loc_82114598;
	// lwz r10,712(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 712);
	// addi r9,r30,712
	ctx.r9.s64 = ctx.r30.s64 + 712;
	// b 0x821143d4
	goto loc_821143D4;
loc_821143C0:
	// lwz r7,56(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// addi r11,r10,-4
	ctx.r11.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x821143e8
	if (ctx.cr6.eq) goto loc_821143E8;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_821143D4:
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x821143e4
	if (ctx.cr6.eq) goto loc_821143E4;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x821143c0
	if (!ctx.cr0.eq) goto loc_821143C0;
loc_821143E4:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_821143E8:
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82114598
	if (ctx.cr6.eq) goto loc_82114598;
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// rlwinm. r9,r10,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82114598
	if (ctx.cr0.eq) goto loc_82114598;
	// lwz r11,68(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82114598
	if (!ctx.cr6.eq) goto loc_82114598;
	// rlwinm. r11,r10,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82114598
	if (!ctx.cr0.eq) goto loc_82114598;
loc_82114414:
	// lwz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// li r9,3
	ctx.r9.s64 = 3;
	// lwz r8,168(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 168);
	// li r7,2
	ctx.r7.s64 = 2;
	// lwz r11,700(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 700);
	// stb r9,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r9.u8);
	// stw r7,97(r1)
	REX_STORE_U32(ctx.r1.u32 + 97, ctx.r7.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,101(r1)
	REX_STORE_U32(ctx.r1.u32 + 101, ctx.r10.u32);
	// stw r8,105(r1)
	REX_STORE_U32(ctx.r1.u32 + 105, ctx.r8.u32);
	// beq cr6,0x8211444c
	if (ctx.cr6.eq) goto loc_8211444C;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,109(r1)
	REX_STORE_U32(ctx.r1.u32 + 109, ctx.r11.u32);
	// b 0x82114450
	goto loc_82114450;
loc_8211444C:
	// stw r24,109(r1)
	REX_STORE_U32(ctx.r1.u32 + 109, ctx.r24.u32);
loc_82114450:
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,17
	ctx.r5.s64 = 17;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82115160
	ctx.lr = 0x8211446C;
	sub_82115160(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x821144d4
	if (!ctx.cr0.eq) goto loc_821144D4;
loc_82114474:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82114474
	if (!ctx.cr0.eq) goto loc_82114474;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// stw r11,68(r29)
	REX_STORE_U32(ctx.r29.u32 + 68, ctx.r11.u32);
	// bne cr6,0x821144a8
	if (!ctx.cr6.eq) goto loc_821144A8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82115670
	ctx.lr = 0x821144A8;
	sub_82115670(ctx, base);
loc_821144A8:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82115420
	ctx.lr = 0x821144B4;
	sub_82115420(ctx, base);
	// lwz r11,700(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 700);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8211459c
	if (ctx.cr6.eq) goto loc_8211459C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210f620
	ctx.lr = 0x821144CC;
	sub_8210F620(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8211459c
	if (ctx.cr0.eq) goto loc_8211459C;
loc_821144D4:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82114518
	if (!ctx.cr6.eq) goto loc_82114518;
loc_821144E0:
	// addi r11,r1,88
	ctx.r11.s64 = ctx.r1.s64 + 88;
	// li r10,4
	ctx.r10.s64 = 4;
	// cmpw cr6,r31,r26
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r26.s32, ctx.xer);
	// stw r24,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r24.u32);
	// stb r24,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r24.u8);
	// stb r10,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r10.u8);
	// stw r23,89(r1)
	REX_STORE_U32(ctx.r1.u32 + 89, ctx.r23.u32);
	// bne cr6,0x82114504
	if (!ctx.cr6.eq) goto loc_82114504;
	// stw r26,89(r1)
	REX_STORE_U32(ctx.r1.u32 + 89, ctx.r26.u32);
loc_82114504:
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82115178
	ctx.lr = 0x82114514;
	sub_82115178(ctx, base);
	// b 0x8211452c
	goto loc_8211452C;
loc_82114518:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821138a0
	ctx.lr = 0x8211452C;
	sub_821138A0(ctx, base);
loc_8211452C:
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82114538
	if (ctx.cr0.lt) goto loc_82114538;
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
loc_82114538:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8211459c
	if (ctx.cr6.eq) goto loc_8211459C;
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// addi r11,r27,4
	ctx.r11.s64 = ctx.r27.s64 + 4;
	// lwz r8,8(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// stw r8,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// lwz r10,8(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r8,4(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r11,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
	// stw r11,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
loc_82114564:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r27
	ea = ctx.r27.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stwcx. r9,0,r27
	ea = ctx.r27.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82114564
	if (!ctx.cr0.eq) goto loc_82114564;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8211459c
	if (!ctx.cr6.eq) goto loc_8211459C;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82115638
	ctx.lr = 0x82114594;
	sub_82115638(ctx, base);
	// b 0x8211459c
	goto loc_8211459C;
loc_82114598:
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
loc_8211459C:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x821151c8
	ctx.lr = 0x821145A4;
	sub_821151C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
