DEFINE_REX_FUNC(sub_82112BC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 744);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-20712
	ctx.r12.s64 = ctx.r12.s64 + -20712;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32239
	ctx.r12.s64 = -2112815104;
	// addi r12,r12,11272
	ctx.r12.s64 = ctx.r12.s64 + 11272;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	// CC_SWITCH_CTR_REPAIR_V1
	// Original PPC has already computed CTR from the byte-offset table.
	switch (ctx.ctr.u32) {
	case 0x82112C08: goto loc_82112C08;
	case 0x82112C38: goto loc_82112C38;
	case 0x82112D10:
		sub_82112D10(ctx, base);
		return;
	default:
		// Unknown mappings must be reported by the SDK, never ignored.
		REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
		return;
	}

loc_82112C08:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,812(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// bl 0x82112570
	ctx.lr = 0x82112C14;
	sub_82112570(ctx, base);
	// lwz r11,144(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82112c38
	if (!ctx.cr6.eq) goto loc_82112C38;
	// lwz r10,712(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 712);
	// addi r11,r31,712
	ctx.r11.s64 = ctx.r31.s64 + 712;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82112c38
	if (!ctx.cr6.eq) goto loc_82112C38;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x82117908
	ctx.lr = 0x82112C38;
	sub_82117908(ctx, base);
loc_82112C38:
	// lwz r3,808(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 808);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82112c50
	if (ctx.cr6.eq) goto loc_82112C50;
	// bl 0x821151c8
	ctx.lr = 0x82112C4C;
	sub_821151C8(ctx, base);
	// stw r30,808(r31)
	REX_STORE_U32(ctx.r31.u32 + 808, ctx.r30.u32);
loc_82112C50:
	// lwz r4,812(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82112cb0
	if (ctx.cr6.eq) goto loc_82112CB0;
	// lwz r11,168(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 168);
	// rlwinm. r10,r11,0,9,9
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82112c78
	if (!ctx.cr0.eq) goto loc_82112C78;
	// rlwinm. r10,r11,0,4,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82112c78
	if (!ctx.cr0.eq) goto loc_82112C78;
	// rlwinm. r11,r11,0,5,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82112c80
	if (ctx.cr0.eq) goto loc_82112C80;
loc_82112C78:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210da60
	ctx.lr = 0x82112C80;
	sub_8210DA60(ctx, base);
loc_82112C80:
	// lwz r3,812(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 812);
loc_82112C84:
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
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
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
	// bne 0x82112c84
	if (!ctx.cr0.eq) goto loc_82112C84;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82112cac
	if (!ctx.cr6.eq) goto loc_82112CAC;
	// bl 0x82115638
	ctx.lr = 0x82112CAC;
	sub_82115638(ctx, base);
loc_82112CAC:
	// stw r30,812(r31)
	REX_STORE_U32(ctx.r31.u32 + 812, ctx.r30.u32);
loc_82112CB0:
	// lwz r4,816(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 816);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82112cec
	if (ctx.cr6.eq) goto loc_82112CEC;
loc_82112CBC:
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
	// bne 0x82112cbc
	if (!ctx.cr0.eq) goto loc_82112CBC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82112ce8
	if (!ctx.cr6.eq) goto loc_82112CE8;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82108f60
	ctx.lr = 0x82112CE8;
	sub_82108F60(ctx, base);
loc_82112CE8:
	// stw r30,816(r31)
	REX_STORE_U32(ctx.r31.u32 + 816, ctx.r30.u32);
loc_82112CEC:
	// lwz r11,820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 820);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// stw r11,820(r31)
	REX_STORE_U32(ctx.r31.u32 + 820, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
