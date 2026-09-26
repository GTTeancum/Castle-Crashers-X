DEFINE_REX_FUNC(sub_82115930) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r10,24(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// addi r11,r3,24
	ctx.r11.s64 = ctx.r3.s64 + 24;
	// b 0x82115960
	goto loc_82115960;
loc_8211593C:
	// lbz r9,52(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 52);
	// addi r3,r10,-4
	ctx.r3.s64 = ctx.r10.s64 + -4;
	// cmpw cr6,r9,r4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, ctx.xer);
	// bne cr6,0x8211595c
	if (!ctx.cr6.eq) goto loc_8211595C;
	// lwz r9,71(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 71);
	// lwz r8,0(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x82115978
	if (ctx.cr6.eq) goto loc_82115978;
loc_8211595C:
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_82115960:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82115970
	if (ctx.cr6.eq) goto loc_82115970;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8211593c
	if (!ctx.cr0.eq) goto loc_8211593C;
loc_82115970:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82115978:
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
	// bne 0x82115978
	if (!ctx.cr0.eq) goto loc_82115978;
	// blr 
	return;
}
