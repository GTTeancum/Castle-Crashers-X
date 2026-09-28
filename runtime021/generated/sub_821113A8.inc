DEFINE_REX_FUNC(sub_821113A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x821113B0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821113d4
	if (ctx.cr0.eq) goto loc_821113D4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// b 0x821117d0
	goto loc_821117D0;
loc_821113D4:
	// lwz r7,140(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r8,144(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// cmpwi cr6,r7,2
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 2, ctx.xer);
	// bne cr6,0x82111414
	if (!ctx.cr6.eq) goto loc_82111414;
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// bne cr6,0x8211141c
	if (!ctx.cr6.eq) goto loc_8211141C;
	// lwz r10,712(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 712);
	// addi r11,r31,712
	ctx.r11.s64 = ctx.r31.s64 + 712;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821114bc
	if (!ctx.cr6.eq) goto loc_821114BC;
	// lwz r10,728(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 728);
	// addi r11,r31,728
	ctx.r11.s64 = ctx.r31.s64 + 728;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821114bc
	if (!ctx.cr6.eq) goto loc_821114BC;
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r8,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r8.u32);
loc_82111414:
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// beq cr6,0x821114bc
	if (ctx.cr6.eq) goto loc_821114BC;
loc_8211141C:
	// lwz r11,688(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 688);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,816(r31)
	REX_STORE_U32(ctx.r31.u32 + 816, ctx.r11.u32);
	// beq cr6,0x8211145c
	if (ctx.cr6.eq) goto loc_8211145C;
loc_82111430:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwcx. r10,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82111430
	if (!ctx.cr0.eq) goto loc_82111430;
	// lwz r11,816(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 816);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82111464
	goto loc_82111464;
loc_8211145C:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
loc_82111464:
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// li r6,36
	ctx.r6.s64 = 36;
	// lwz r5,136(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r30,132(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// oris r27,r11,32768
	ctx.r27.u64 = ctx.r11.u64 | 2147483648;
	// lwz r26,148(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// addi r11,r31,740
	ctx.r11.s64 = ctx.r31.s64 + 740;
	// stw r4,744(r31)
	REX_STORE_U32(ctx.r31.u32 + 744, ctx.r4.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r6,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r6.u32);
	// stw r5,748(r31)
	REX_STORE_U32(ctx.r31.u32 + 748, ctx.r5.u32);
	// stw r30,752(r31)
	REX_STORE_U32(ctx.r31.u32 + 752, ctx.r30.u32);
	// stw r7,756(r31)
	REX_STORE_U32(ctx.r31.u32 + 756, ctx.r7.u32);
	// stw r8,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r8.u32);
	// stw r26,764(r31)
	REX_STORE_U32(ctx.r31.u32 + 764, ctx.r26.u32);
	// stw r10,768(r31)
	REX_STORE_U32(ctx.r31.u32 + 768, ctx.r10.u32);
	// stw r9,772(r31)
	REX_STORE_U32(ctx.r31.u32 + 772, ctx.r9.u32);
	// stw r27,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r27.u32);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// stw r8,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r8.u32);
	// b 0x821117d4
	goto loc_821117D4;
loc_821114BC:
	// lwz r11,728(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 728);
	// addi r30,r31,728
	ctx.r30.s64 = ctx.r31.s64 + 728;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8211156c
	if (ctx.cr6.eq) goto loc_8211156C;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
loc_821114E4:
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,736(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 736);
	// addi r29,r10,-12
	ctx.r29.s64 = ctx.r10.s64 + -12;
	// addic. r11,r11,1
	ctx.xer.ca = ctx.r11.u32 > 4294967294;
	ctx.r11.s64 = ctx.r11.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82111504
	if (!ctx.cr0.eq) goto loc_82111504;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82111504:
	// lwz r9,36(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82111554
	if (!ctx.cr6.eq) goto loc_82111554;
	// stw r11,736(r31)
	REX_STORE_U32(ctx.r31.u32 + 736, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lbz r11,56(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82111638
	if (!ctx.cr0.eq) goto loc_82111638;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x82115c28
	ctx.lr = 0x8211152C;
	sub_82115C28(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8211156c
	if (ctx.cr6.eq) goto loc_8211156C;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// b 0x821114e4
	goto loc_821114E4;
loc_82111554:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r30,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
loc_8211156C:
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// li r29,0
	ctx.r29.s64 = 0;
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x821117cc
	if (!ctx.cr0.eq) goto loc_821117CC;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// addi r30,r31,720
	ctx.r30.s64 = ctx.r31.s64 + 720;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x821117cc
	if (ctx.cr6.eq) goto loc_821117CC;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_821115A4:
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// addi r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -12;
	// stw r11,812(r31)
	REX_STORE_U32(ctx.r31.u32 + 812, ctx.r11.u32);
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// rlwinm. r9,r10,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x821115e0
	if (!ctx.cr0.eq) goto loc_821115E0;
	// rlwinm. r9,r10,0,3,3
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x821115e0
	if (!ctx.cr0.eq) goto loc_821115E0;
	// rlwinm. r9,r10,0,9,9
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82111658
	if (!ctx.cr0.eq) goto loc_82111658;
	// rlwinm. r9,r10,0,4,4
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8211170c
	if (!ctx.cr0.eq) goto loc_8211170C;
	// rlwinm. r10,r10,0,5,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82111768
	if (!ctx.cr0.eq) goto loc_82111768;
loc_821115E0:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x821115e0
	if (!ctx.cr0.eq) goto loc_821115E0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8211160c
	if (!ctx.cr6.eq) goto loc_8211160C;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82115638
	ctx.lr = 0x8211160C;
	sub_82115638(ctx, base);
loc_8211160C:
	// stw r29,812(r31)
	REX_STORE_U32(ctx.r31.u32 + 812, ctx.r29.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x821117cc
	if (ctx.cr6.eq) goto loc_821117CC;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// b 0x821115a4
	goto loc_821115A4;
loc_82111638:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210e8b0
	ctx.lr = 0x82111644;
	sub_8210E8B0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x82115c28
	ctx.lr = 0x82111650;
	sub_82115C28(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x821117d4
	goto loc_821117D4;
loc_82111658:
	// lwz r4,84(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82111680
	if (ctx.cr6.eq) goto loc_82111680;
loc_82111664:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r4
	ea = ctx.r4.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r4
	ea = ctx.r4.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82111664
	if (!ctx.cr0.eq) goto loc_82111664;
loc_82111680:
	// stw r4,816(r31)
	REX_STORE_U32(ctx.r31.u32 + 816, ctx.r4.u32);
	// lwz r3,812(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// bl 0x8210e3f8
	ctx.lr = 0x8211168C;
	sub_8210E3F8(ctx, base);
	// li r9,12
	ctx.r9.s64 = 12;
	// lwz r8,132(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r9,744(r31)
	REX_STORE_U32(ctx.r31.u32 + 744, ctx.r9.u32);
	// lwz r7,812(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// stw r10,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r10.u32);
	// addi r10,r31,740
	ctx.r10.s64 = ctx.r31.s64 + 740;
	// lwz r11,816(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 816);
	// stw r8,752(r31)
	REX_STORE_U32(ctx.r31.u32 + 752, ctx.r8.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r9,136(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// stw r9,748(r31)
	REX_STORE_U32(ctx.r31.u32 + 748, ctx.r9.u32);
	// lwz r9,60(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 60);
	// stw r9,756(r31)
	REX_STORE_U32(ctx.r31.u32 + 756, ctx.r9.u32);
	// lwz r9,72(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 72);
	// stw r9,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r9.u32);
	// beq cr6,0x821116e4
	if (ctx.cr6.eq) goto loc_821116E4;
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// stw r9,764(r31)
	REX_STORE_U32(ctx.r31.u32 + 764, ctx.r9.u32);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,768(r31)
	REX_STORE_U32(ctx.r31.u32 + 768, ctx.r11.u32);
	// b 0x821116ec
	goto loc_821116EC;
loc_821116E4:
	// stw r29,764(r31)
	REX_STORE_U32(ctx.r31.u32 + 764, ctx.r29.u32);
	// stw r29,768(r31)
	REX_STORE_U32(ctx.r31.u32 + 768, ctx.r29.u32);
loc_821116EC:
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r11.u32);
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// lwz r11,812(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// rlwinm r10,r10,0,10,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFBFFFFF;
	// b 0x821117c0
	goto loc_821117C0;
loc_8211170C:
	// lwz r9,136(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r10,28
	ctx.r10.s64 = 28;
	// lwz r8,132(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// li r7,9
	ctx.r7.s64 = 9;
	// stw r10,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r10.u32);
	// addi r10,r31,740
	ctx.r10.s64 = ctx.r31.s64 + 740;
	// stw r7,744(r31)
	REX_STORE_U32(ctx.r31.u32 + 744, ctx.r7.u32);
	// lwz r7,820(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// stw r9,748(r31)
	REX_STORE_U32(ctx.r31.u32 + 748, ctx.r9.u32);
	// stw r8,752(r31)
	REX_STORE_U32(ctx.r31.u32 + 752, ctx.r8.u32);
	// oris r9,r7,32768
	ctx.r9.u64 = ctx.r7.u64 | 2147483648;
	// lwz r8,60(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// stw r8,756(r31)
	REX_STORE_U32(ctx.r31.u32 + 756, ctx.r8.u32);
	// lwz r8,72(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// stw r8,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r8.u32);
	// lwz r11,160(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// stw r11,764(r31)
	REX_STORE_U32(ctx.r31.u32 + 764, ctx.r11.u32);
	// stw r9,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r9.u32);
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// lwz r11,812(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// rlwinm r10,r10,0,5,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// b 0x821117c0
	goto loc_821117C0;
loc_82111768:
	// lwz r9,136(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r10,28
	ctx.r10.s64 = 28;
	// lwz r8,132(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// li r7,10
	ctx.r7.s64 = 10;
	// stw r10,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r10.u32);
	// addi r10,r31,740
	ctx.r10.s64 = ctx.r31.s64 + 740;
	// stw r7,744(r31)
	REX_STORE_U32(ctx.r31.u32 + 744, ctx.r7.u32);
	// lwz r7,820(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// stw r9,748(r31)
	REX_STORE_U32(ctx.r31.u32 + 748, ctx.r9.u32);
	// stw r8,752(r31)
	REX_STORE_U32(ctx.r31.u32 + 752, ctx.r8.u32);
	// oris r9,r7,32768
	ctx.r9.u64 = ctx.r7.u64 | 2147483648;
	// lwz r8,60(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// stw r8,756(r31)
	REX_STORE_U32(ctx.r31.u32 + 756, ctx.r8.u32);
	// lwz r8,72(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// stw r8,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r8.u32);
	// lwz r11,160(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// stw r11,764(r31)
	REX_STORE_U32(ctx.r31.u32 + 764, ctx.r11.u32);
	// stw r9,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r9.u32);
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// lwz r11,812(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// rlwinm r10,r10,0,6,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFBFFFFFF;
loc_821117C0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,168(r11)
	REX_STORE_U32(ctx.r11.u32 + 168, ctx.r10.u32);
	// b 0x821117d4
	goto loc_821117D4;
loc_821117CC:
	// stw r29,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r29.u32);
loc_821117D0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_821117D4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
