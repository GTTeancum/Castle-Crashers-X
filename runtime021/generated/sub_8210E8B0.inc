DEFINE_REX_FUNC(sub_8210E8B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8210E8B8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lbz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 56);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8210eb74
	if (ctx.cr6.eq) goto loc_8210EB74;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8210eb10
	if (ctx.cr6.eq) goto loc_8210EB10;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// lwz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,812(r31)
	REX_STORE_U32(ctx.r31.u32 + 812, ctx.r11.u32);
	// stw r28,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r28.u32);
	// beq cr6,0x8210ea14
	if (ctx.cr6.eq) goto loc_8210EA14;
	// lwz r11,116(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 116);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,816(r31)
	REX_STORE_U32(ctx.r31.u32 + 816, ctx.r11.u32);
	// beq cr6,0x8210e934
	if (ctx.cr6.eq) goto loc_8210E934;
loc_8210E908:
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
	// bne 0x8210e908
	if (!ctx.cr0.eq) goto loc_8210E908;
	// lwz r4,816(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 816);
	// addi r30,r4,12
	ctx.r30.s64 = ctx.r4.s64 + 12;
	// lwz r29,8(r4)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// b 0x8210e93c
	goto loc_8210E93C;
loc_8210E934:
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_8210E93C:
	// lwz r3,812(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210e950
	if (ctx.cr6.eq) goto loc_8210E950;
	// bl 0x8210e3f8
	ctx.lr = 0x8210E94C;
	sub_8210E3F8(ctx, base);
	// b 0x8210e9b8
	goto loc_8210E9B8;
loc_8210E950:
	// lwz r4,696(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 696);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8210e988
	if (ctx.cr6.eq) goto loc_8210E988;
loc_8210E95C:
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
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
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
	// bne 0x8210e95c
	if (!ctx.cr0.eq) goto loc_8210E95C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210e988
	if (!ctx.cr6.eq) goto loc_8210E988;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82108f60
	ctx.lr = 0x8210E988;
	sub_82108F60(ctx, base);
loc_8210E988:
	// lwz r11,816(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 816);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210e9b0
	if (ctx.cr6.eq) goto loc_8210E9B0;
loc_8210E994:
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
	// bne 0x8210e994
	if (!ctx.cr0.eq) goto loc_8210E994;
loc_8210E9B0:
	// lwz r11,816(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 816);
	// stw r11,696(r31)
	REX_STORE_U32(ctx.r31.u32 + 696, ctx.r11.u32);
loc_8210E9B8:
	// lwz r9,136(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r7,132(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// li r6,12
	ctx.r6.s64 = 12;
	// lwz r11,812(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// addi r10,r31,740
	ctx.r10.s64 = ctx.r31.s64 + 740;
	// stw r6,744(r31)
	REX_STORE_U32(ctx.r31.u32 + 744, ctx.r6.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r8,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r8.u32);
	// stw r9,748(r31)
	REX_STORE_U32(ctx.r31.u32 + 748, ctx.r9.u32);
	// stw r7,752(r31)
	REX_STORE_U32(ctx.r31.u32 + 752, ctx.r7.u32);
	// beq cr6,0x8210e9fc
	if (ctx.cr6.eq) goto loc_8210E9FC;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// stw r9,756(r31)
	REX_STORE_U32(ctx.r31.u32 + 756, ctx.r9.u32);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// stw r11,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r11.u32);
	// b 0x8210ea08
	goto loc_8210EA08;
loc_8210E9FC:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r28,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r28.u32);
	// stw r11,756(r31)
	REX_STORE_U32(ctx.r31.u32 + 756, ctx.r11.u32);
loc_8210EA08:
	// stw r30,764(r31)
	REX_STORE_U32(ctx.r31.u32 + 764, ctx.r30.u32);
	// stw r29,768(r31)
	REX_STORE_U32(ctx.r31.u32 + 768, ctx.r29.u32);
	// b 0x8210ec34
	goto loc_8210EC34;
loc_8210EA14:
	// lwz r4,688(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 688);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8210ea4c
	if (ctx.cr6.eq) goto loc_8210EA4C;
loc_8210EA20:
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
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
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
	// bne 0x8210ea20
	if (!ctx.cr0.eq) goto loc_8210EA20;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210ea4c
	if (!ctx.cr6.eq) goto loc_8210EA4C;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82108f60
	ctx.lr = 0x8210EA4C;
	sub_82108F60(ctx, base);
loc_8210EA4C:
	// lwz r11,116(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 116);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,816(r31)
	REX_STORE_U32(ctx.r31.u32 + 816, ctx.r11.u32);
	// beq cr6,0x8210eaa4
	if (ctx.cr6.eq) goto loc_8210EAA4;
loc_8210EA5C:
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
	// bne 0x8210ea5c
	if (!ctx.cr0.eq) goto loc_8210EA5C;
	// lwz r11,816(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 816);
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
loc_8210EA84:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
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
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8210ea84
	if (!ctx.cr0.eq) goto loc_8210EA84;
	// b 0x8210eaac
	goto loc_8210EAAC;
loc_8210EAA4:
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
loc_8210EAAC:
	// lwz r7,816(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 816);
	// li r6,32
	ctx.r6.s64 = 32;
	// lwz r5,136(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r3,132(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// addi r10,r31,740
	ctx.r10.s64 = ctx.r31.s64 + 740;
	// lwz r11,812(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// stw r4,744(r31)
	REX_STORE_U32(ctx.r31.u32 + 744, ctx.r4.u32);
	// stw r7,688(r31)
	REX_STORE_U32(ctx.r31.u32 + 688, ctx.r7.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r6,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r6.u32);
	// stw r5,748(r31)
	REX_STORE_U32(ctx.r31.u32 + 748, ctx.r5.u32);
	// stw r3,752(r31)
	REX_STORE_U32(ctx.r31.u32 + 752, ctx.r3.u32);
	// beq cr6,0x8210eaf8
	if (ctx.cr6.eq) goto loc_8210EAF8;
	// lwz r7,60(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// stw r7,756(r31)
	REX_STORE_U32(ctx.r31.u32 + 756, ctx.r7.u32);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// stw r11,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r11.u32);
	// b 0x8210eb04
	goto loc_8210EB04;
loc_8210EAF8:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r28,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r28.u32);
	// stw r11,756(r31)
	REX_STORE_U32(ctx.r31.u32 + 756, ctx.r11.u32);
loc_8210EB04:
	// stw r9,764(r31)
	REX_STORE_U32(ctx.r31.u32 + 764, ctx.r9.u32);
	// stw r8,768(r31)
	REX_STORE_U32(ctx.r31.u32 + 768, ctx.r8.u32);
	// b 0x8210ec34
	goto loc_8210EC34;
loc_8210EB10:
	// lwz r10,52(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,28
	ctx.r8.s64 = 28;
	// li r7,10
	ctx.r7.s64 = 10;
	// addi r11,r31,740
	ctx.r11.s64 = ctx.r31.s64 + 740;
	// stw r10,812(r31)
	REX_STORE_U32(ctx.r31.u32 + 812, ctx.r10.u32);
	// stw r9,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r9.u32);
	// lwz r6,132(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// lwz r10,812(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// lwz r9,820(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// stw r8,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r8.u32);
	// lwz r8,136(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// stw r7,744(r31)
	REX_STORE_U32(ctx.r31.u32 + 744, ctx.r7.u32);
	// stw r8,748(r31)
	REX_STORE_U32(ctx.r31.u32 + 748, ctx.r8.u32);
	// stw r6,752(r31)
	REX_STORE_U32(ctx.r31.u32 + 752, ctx.r6.u32);
	// oris r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 2147483648;
	// lwz r8,60(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// stw r8,756(r31)
	REX_STORE_U32(ctx.r31.u32 + 756, ctx.r8.u32);
	// lwz r8,72(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 72);
	// stw r8,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r8.u32);
	// lwz r10,160(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 160);
	// stw r10,764(r31)
	REX_STORE_U32(ctx.r31.u32 + 764, ctx.r10.u32);
	// stw r9,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r9.u32);
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// b 0x8210ec44
	goto loc_8210EC44;
loc_8210EB74:
	// lwz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,812(r31)
	REX_STORE_U32(ctx.r31.u32 + 812, ctx.r11.u32);
	// stw r28,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r28.u32);
	// lwz r11,812(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8210eba0
	if (!ctx.cr0.eq) goto loc_8210EBA0;
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,168(r11)
	REX_STORE_U32(ctx.r11.u32 + 168, ctx.r10.u32);
loc_8210EBA0:
	// lwz r11,812(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// rlwinm r10,r10,0,4,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// stw r10,168(r11)
	REX_STORE_U32(ctx.r11.u32 + 168, ctx.r10.u32);
	// lwz r11,812(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210ebdc
	if (ctx.cr6.eq) goto loc_8210EBDC;
loc_8210EBC0:
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
	// bne 0x8210ebc0
	if (!ctx.cr0.eq) goto loc_8210EBC0;
loc_8210EBDC:
	// lwz r9,132(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// li r8,28
	ctx.r8.s64 = 28;
	// lwz r7,136(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r6,8
	ctx.r6.s64 = 8;
	// lwz r5,812(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// addi r10,r31,740
	ctx.r10.s64 = ctx.r31.s64 + 740;
	// stw r11,816(r31)
	REX_STORE_U32(ctx.r31.u32 + 816, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r6,744(r31)
	REX_STORE_U32(ctx.r31.u32 + 744, ctx.r6.u32);
	// stw r9,752(r31)
	REX_STORE_U32(ctx.r31.u32 + 752, ctx.r9.u32);
	// stw r7,748(r31)
	REX_STORE_U32(ctx.r31.u32 + 748, ctx.r7.u32);
	// stw r8,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r8.u32);
	// lwz r9,60(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 60);
	// stw r9,756(r31)
	REX_STORE_U32(ctx.r31.u32 + 756, ctx.r9.u32);
	// beq cr6,0x8210ec2c
	if (ctx.cr6.eq) goto loc_8210EC2C;
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// stw r9,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r9.u32);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,764(r31)
	REX_STORE_U32(ctx.r31.u32 + 764, ctx.r11.u32);
	// b 0x8210ec34
	goto loc_8210EC34;
loc_8210EC2C:
	// stw r28,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r28.u32);
	// stw r28,764(r31)
	REX_STORE_U32(ctx.r31.u32 + 764, ctx.r28.u32);
loc_8210EC34:
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r11.u32);
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
loc_8210EC44:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
