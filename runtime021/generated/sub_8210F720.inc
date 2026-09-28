DEFINE_REX_FUNC(sub_8210F720) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8210F728;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// addi r31,r29,-8
	ctx.r31.s64 = ctx.r29.s64 + -8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,28(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 28);
	// bl 0x8210e730
	ctx.lr = 0x8210F744;
	sub_8210E730(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmpwi cr6,r6,-1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, -1, ctx.xer);
	// bne cr6,0x8210f860
	if (!ctx.cr6.eq) goto loc_8210F860;
	// lwz r9,20(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// lwz r11,12(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8210f770
	if (!ctx.cr6.eq) goto loc_8210F770;
	// lis r6,4626
	ctx.r6.s64 = 303169536;
	// li r30,0
	ctx.r30.s64 = 0;
	// ori r6,r6,4626
	ctx.r6.u64 = ctx.r6.u64 | 4626;
	// b 0x8210f800
	goto loc_8210F800;
loc_8210F770:
	// lwz r11,712(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 712);
	// addi r10,r31,712
	ctx.r10.s64 = ctx.r31.s64 + 712;
	// b 0x8210f790
	goto loc_8210F790;
loc_8210F77C:
	// lwz r8,56(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// addi r30,r11,-4
	ctx.r30.s64 = ctx.r11.s64 + -4;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8210f7a4
	if (ctx.cr6.eq) goto loc_8210F7A4;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_8210F790:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8210f7a0
	if (ctx.cr6.eq) goto loc_8210F7A0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8210f77c
	if (!ctx.cr0.eq) goto loc_8210F77C;
loc_8210F7A0:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8210F7A4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8210f7b8
	if (!ctx.cr6.eq) goto loc_8210F7B8;
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4106
	ctx.r31.u64 = ctx.r31.u64 | 4106;
	// b 0x8210f87c
	goto loc_8210F87C;
loc_8210F7B8:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r30
	ea = ctx.r30.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r30
	ea = ctx.r30.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8210f7b8
	if (!ctx.cr0.eq) goto loc_8210F7B8;
	// lbz r11,168(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 168);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210f7ec
	if (ctx.cr0.eq) goto loc_8210F7EC;
	// lis r6,-32646
	ctx.r6.s64 = -2139488256;
	// ori r6,r6,4113
	ctx.r6.u64 = ctx.r6.u64 | 4113;
	// b 0x8210f7f4
	goto loc_8210F7F4;
loc_8210F7EC:
	// lis r6,4626
	ctx.r6.s64 = 303169536;
	// ori r6,r6,4626
	ctx.r6.u64 = ctx.r6.u64 | 4626;
loc_8210F7F4:
	// lwz r11,152(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 152);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,152(r30)
	REX_STORE_U32(ctx.r30.u32 + 152, ctx.r11.u32);
loc_8210F800:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82117100
	ctx.lr = 0x8210F810;
	sub_82117100(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x8210f878
	if (!ctx.cr0.lt) goto loc_8210F878;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8210f87c
	if (ctx.cr6.eq) goto loc_8210F87C;
	// lwz r11,152(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 152);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,152(r30)
	REX_STORE_U32(ctx.r30.u32 + 152, ctx.r11.u32);
loc_8210F82C:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r30
	ea = ctx.r30.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r30
	ea = ctx.r30.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8210f82c
	if (!ctx.cr0.eq) goto loc_8210F82C;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210f87c
	if (!ctx.cr6.eq) goto loc_8210F87C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82115638
	ctx.lr = 0x8210F85C;
	sub_82115638(ctx, base);
	// b 0x8210f87c
	goto loc_8210F87C;
loc_8210F860:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r5,60(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 60);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82117510
	ctx.lr = 0x8210F870;
	sub_82117510(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8210f87c
	if (ctx.cr0.lt) goto loc_8210F87C;
loc_8210F878:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8210F87C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
