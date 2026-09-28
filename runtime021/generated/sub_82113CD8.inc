DEFINE_REX_FUNC(sub_82113CD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x82113CE0;
	__savegprlr_14(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r14,0
	ctx.r14.s64 = 0;
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r14,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r14.u32);
	// mr r26,r14
	ctx.r26.u64 = ctx.r14.u64;
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// mr r16,r14
	ctx.r16.u64 = ctx.r14.u64;
	// mr r15,r14
	ctx.r15.u64 = ctx.r14.u64;
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82113d1c
	if (!ctx.cr0.eq) goto loc_82113D1C;
loc_82113D10:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4106
	ctx.r30.u64 = ctx.r30.u64 | 4106;
	// b 0x821141dc
	goto loc_821141DC;
loc_82113D1C:
	// lwz r11,144(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82114108
	if (ctx.cr6.eq) goto loc_82114108;
	// cmplwi cr6,r6,25
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 25, ctx.xer);
	// blt cr6,0x82113d10
	if (ctx.cr6.lt) goto loc_82113D10;
	// lwz r17,1(r29)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r29.u32 + 1);
	// addi r10,r6,-25
	ctx.r10.s64 = ctx.r6.s64 + -25;
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// beq cr6,0x82113d10
	if (ctx.cr6.eq) goto loc_82113D10;
	// lwz r18,5(r29)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r29.u32 + 5);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x82113d10
	if (ctx.cr6.eq) goto loc_82113D10;
	// lwz r19,9(r29)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r29.u32 + 9);
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// beq cr6,0x82113d10
	if (ctx.cr6.eq) goto loc_82113D10;
	// cmplw cr6,r18,r19
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, ctx.r19.u32, ctx.xer);
	// beq cr6,0x82113d10
	if (ctx.cr6.eq) goto loc_82113D10;
	// lwz r23,13(r29)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r29.u32 + 13);
	// cmplwi cr6,r23,1
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 1, ctx.xer);
	// ble cr6,0x82114110
	if (!ctx.cr6.gt) goto loc_82114110;
	// cmplwi cr6,r23,128
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 128, ctx.xer);
	// bgt cr6,0x82114110
	if (ctx.cr6.gt) goto loc_82114110;
	// lwz r11,156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82113d88
	if (ctx.cr6.eq) goto loc_82113D88;
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82113d10
	if (ctx.cr6.gt) goto loc_82113D10;
loc_82113D88:
	// lwz r27,17(r29)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r29.u32 + 17);
	// addi r11,r23,-1
	ctx.r11.s64 = ctx.r23.s64 + -1;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82113d10
	if (ctx.cr6.gt) goto loc_82113D10;
	// mulli r11,r27,42
	ctx.r11.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(42));
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82113d10
	if (ctx.cr6.gt) goto loc_82113D10;
	// lwz r22,21(r29)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r29.u32 + 21);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r22,r11
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82113d10
	if (!ctx.cr6.eq) goto loc_82113D10;
	// lis r11,4096
	ctx.r11.s64 = 268435456;
	// cmplw cr6,r22,r11
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82113d10
	if (ctx.cr6.gt) goto loc_82113D10;
	// lwz r11,60(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 60);
	// clrlwi r28,r11,24
	ctx.r28.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r28,r23
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r23.u32, ctx.xer);
	// bge cr6,0x82113d10
	if (!ctx.cr6.lt) goto loc_82113D10;
	// subf r11,r19,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r19.u64;
	// lwz r3,68(r21)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r21.u32 + 68);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r24,r11,27,31,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// bl 0x82115238
	ctx.lr = 0x82113DE8;
	sub_82115238(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82114118
	if (!ctx.cr0.eq) goto loc_82114118;
	// lwz r15,156(r31)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// stw r23,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r23.u32);
loc_82113DF8:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r21
	ea = ctx.r21.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r21
	ea = ctx.r21.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82113df8
	if (!ctx.cr0.eq) goto loc_82113DF8;
	// addi r11,r28,44
	ctx.r11.s64 = ctx.r28.s64 + 44;
	// li r20,2
	ctx.r20.s64 = 2;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r16,1
	ctx.r16.s64 = 1;
	// addi r28,r29,25
	ctx.r28.s64 = ctx.r29.s64 + 25;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// stwx r21,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r21.u32);
	// lwz r11,168(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 168);
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// stw r11,168(r21)
	REX_STORE_U32(ctx.r21.u32 + 168, ctx.r11.u32);
	// beq cr6,0x82113fdc
	if (ctx.cr6.eq) goto loc_82113FDC;
	// addi r25,r28,4
	ctx.r25.s64 = ctx.r28.s64 + 4;
loc_82113E44:
	// lwz r30,0(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82114110
	if (ctx.cr6.eq) goto loc_82114110;
	// clrlwi r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	// cmplw cr6,r11,r23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r23.u32, ctx.xer);
	// bgt cr6,0x82114110
	if (ctx.cr6.gt) goto loc_82114110;
	// addi r11,r11,44
	ctx.r11.s64 = ctx.r11.s64 + 44;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r29,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r31.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82114110
	if (!ctx.cr6.eq) goto loc_82114110;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// li r5,38
	ctx.r5.s64 = 38;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// bl 0x82129a70
	ctx.lr = 0x82113E80;
	sub_82129A70(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821155f0
	ctx.lr = 0x82113E8C;
	sub_821155F0(ctx, base);
	// mr. r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq 0x82114008
	if (ctx.cr0.eq) goto loc_82114008;
	// stw r30,60(r26)
	REX_STORE_U32(ctx.r26.u32 + 60, ctx.r30.u32);
loc_82113E98:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r26
	ea = ctx.r26.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r26
	ea = ctx.r26.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82113e98
	if (!ctx.cr0.eq) goto loc_82113E98;
	// stwx r26,r29,r31
	REX_STORE_U32(ctx.r29.u32 + ctx.r31.u32, ctx.r26.u32);
	// subf r11,r19,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r19.u64;
	// lwz r10,168(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 168);
	// oris r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 1073741824;
	// stw r10,168(r26)
	REX_STORE_U32(ctx.r26.u32 + 168, ctx.r10.u32);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r26,20
	ctx.r4.s64 = ctx.r26.s64 + 20;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// or r24,r11,r24
	ctx.r24.u64 = ctx.r11.u64 | ctx.r24.u64;
	// bl 0x8210cd28
	ctx.lr = 0x82113EE8;
	sub_8210CD28(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82114118
	if (!ctx.cr0.eq) goto loc_82114118;
	// lwz r11,160(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// stw r18,109(r1)
	REX_STORE_U32(ctx.r1.u32 + 109, ctx.r18.u32);
	// stb r20,104(r1)
	REX_STORE_U8(ctx.r1.u32 + 104, ctx.r20.u8);
	// stw r20,105(r1)
	REX_STORE_U32(ctx.r1.u32 + 105, ctx.r20.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lhz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 84);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lwz r11,700(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 700);
	// sth r10,84(r1)
	REX_STORE_U16(ctx.r1.u32 + 84, ctx.r10.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82113f28
	if (ctx.cr6.eq) goto loc_82113F28;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,113(r1)
	REX_STORE_U32(ctx.r1.u32 + 113, ctx.r11.u32);
	// b 0x82113f2c
	goto loc_82113F2C;
loc_82113F28:
	// stw r14,113(r1)
	REX_STORE_U32(ctx.r1.u32 + 113, ctx.r14.u32);
loc_82113F2C:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r3,164(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// li r6,13
	ctx.r6.s64 = 13;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82115158
	ctx.lr = 0x82113F4C;
	sub_82115158(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82114118
	if (ctx.cr0.lt) goto loc_82114118;
loc_82113F54:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r26
	ea = ctx.r26.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r26
	ea = ctx.r26.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82113f54
	if (!ctx.cr0.eq) goto loc_82113F54;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,68(r26)
	REX_STORE_U32(ctx.r26.u32 + 68, ctx.r11.u32);
	// lwz r11,700(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 700);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82113f98
	if (ctx.cr6.eq) goto loc_82113F98;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210f620
	ctx.lr = 0x82113F90;
	sub_8210F620(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82114118
	if (!ctx.cr0.eq) goto loc_82114118;
loc_82113F98:
	// lwz r9,704(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 704);
	// addi r11,r31,712
	ctx.r11.s64 = ctx.r31.s64 + 712;
	// addi r10,r26,4
	ctx.r10.s64 = ctx.r26.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// stw r9,704(r31)
	REX_STORE_U32(ctx.r31.u32 + 704, ctx.r9.u32);
	// addi r28,r28,42
	ctx.r28.s64 = ctx.r28.s64 + 42;
	// stw r11,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// addi r25,r25,42
	ctx.r25.s64 = ctx.r25.s64 + 42;
	// lwz r11,716(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 716);
	// stw r11,8(r26)
	REX_STORE_U32(ctx.r26.u32 + 8, ctx.r11.u32);
	// mr r26,r14
	ctx.r26.u64 = ctx.r14.u64;
	// lwz r11,716(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 716);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r14,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r14.u32);
	// stw r10,716(r31)
	REX_STORE_U32(ctx.r31.u32 + 716, ctx.r10.u32);
	// bne 0x82113e44
	if (!ctx.cr0.eq) goto loc_82113E44;
loc_82113FDC:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x82114110
	if (ctx.cr6.eq) goto loc_82114110;
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x82114038
	if (ctx.cr6.eq) goto loc_82114038;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,258
	ctx.r3.s64 = 258;
	// bl 0x8210e160
	ctx.lr = 0x82113FFC;
	sub_8210E160(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,692(r31)
	REX_STORE_U32(ctx.r31.u32 + 692, ctx.r3.u32);
	// bne 0x82114014
	if (!ctx.cr0.eq) goto loc_82114014;
loc_82114008:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x82114118
	goto loc_82114118;
loc_82114014:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r3
	ea = ctx.r3.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r3
	ea = ctx.r3.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82114014
	if (!ctx.cr0.eq) goto loc_82114014;
	// lwz r11,692(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 692);
	// stw r11,688(r31)
	REX_STORE_U32(ctx.r31.u32 + 688, ctx.r11.u32);
loc_82114038:
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x82115670
	ctx.lr = 0x82114040;
	sub_82115670(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,164(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// bl 0x82115150
	ctx.lr = 0x8211404C;
	sub_82115150(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82114118
	if (ctx.cr0.lt) goto loc_82114118;
	// lwz r10,156(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x82114088
	if (!ctx.cr6.gt) goto loc_82114088;
	// addi r10,r31,176
	ctx.r10.s64 = ctx.r31.s64 + 176;
loc_82114068:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82114088
	if (ctx.cr6.eq) goto loc_82114088;
	// lwz r9,156(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82114068
	if (ctx.cr6.lt) goto loc_82114068;
loc_82114088:
	// clrlwi r10,r18,24
	ctx.r10.u64 = ctx.r18.u32 & 0xFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82114110
	if (!ctx.cr6.eq) goto loc_82114110;
	// addi r10,r11,44
	ctx.r10.s64 = ctx.r11.s64 + 44;
	// stw r17,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r17.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// stwx r9,r10,r31
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, ctx.r9.u32);
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// stw r17,736(r31)
	REX_STORE_U32(ctx.r31.u32 + 736, ctx.r17.u32);
	// bl 0x82115850
	ctx.lr = 0x821140C4;
	sub_82115850(ctx, base);
	// lwz r11,60(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 60);
	// lwz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821140d8
	if (!ctx.cr6.eq) goto loc_821140D8;
	// stw r21,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r21.u32);
loc_821140D8:
	// stw r20,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r20.u32);
	// lwz r11,168(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 168);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// stw r11,168(r21)
	REX_STORE_U32(ctx.r21.u32 + 168, ctx.r11.u32);
	// lwz r11,704(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 704);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,704(r31)
	REX_STORE_U32(ctx.r31.u32 + 704, ctx.r11.u32);
	// bne 0x82114108
	if (!ctx.cr0.eq) goto loc_82114108;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210f2a0
	ctx.lr = 0x82114100;
	sub_8210F2A0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82114118
	if (!ctx.cr0.eq) goto loc_82114118;
loc_82114108:
	// mr r30,r14
	ctx.r30.u64 = ctx.r14.u64;
	// b 0x821141dc
	goto loc_821141DC;
loc_82114110:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4106
	ctx.r30.u64 = ctx.r30.u64 | 4106;
loc_82114118:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82114148
	if (ctx.cr6.eq) goto loc_82114148;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821138a0
	ctx.lr = 0x82114138;
	sub_821138A0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8211417c
	if (ctx.cr0.lt) goto loc_8211417C;
	// mr r30,r14
	ctx.r30.u64 = ctx.r14.u64;
	// b 0x8211417c
	goto loc_8211417C;
loc_82114148:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x8211417c
	if (ctx.cr6.eq) goto loc_8211417C;
loc_82114150:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r26
	ea = ctx.r26.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r26
	ea = ctx.r26.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82114150
	if (!ctx.cr0.eq) goto loc_82114150;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8211417c
	if (!ctx.cr6.eq) goto loc_8211417C;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82115638
	ctx.lr = 0x8211417C;
	sub_82115638(ctx, base);
loc_8211417C:
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// beq cr6,0x821141dc
	if (ctx.cr6.eq) goto loc_821141DC;
	// lwz r29,712(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 712);
	// addi r28,r31,712
	ctx.r28.s64 = ctx.r31.s64 + 712;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x821141cc
	if (ctx.cr6.eq) goto loc_821141CC;
	// cmplwi r29,0
	ctx.cr0.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq 0x821141cc
	if (ctx.cr0.eq) goto loc_821141CC;
loc_8211419C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r4,r29,-4
	ctx.r4.s64 = ctx.r29.s64 + -4;
	// mr r29,r14
	ctx.r29.u64 = ctx.r14.u64;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x821141b4
	if (ctx.cr6.eq) goto loc_821141B4;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_821141B4:
	// cmplw cr6,r4,r21
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r21.u32, ctx.xer);
	// beq cr6,0x821141c4
	if (ctx.cr6.eq) goto loc_821141C4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82112570
	ctx.lr = 0x821141C4;
	sub_82112570(ctx, base);
loc_821141C4:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8211419c
	if (!ctx.cr6.eq) goto loc_8211419C;
loc_821141CC:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210ca68
	ctx.lr = 0x821141D8;
	sub_8210CA68(ctx, base);
	// stw r15,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r15.u32);
loc_821141DC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
