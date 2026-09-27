DEFINE_REX_FUNC(sub_820D56B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820D56B8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mulli r11,r7,416
	ctx.r11.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(416));
	// add r28,r11,r4
	ctx.r28.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,40(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 40);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820d5718
	if (!ctx.cr6.eq) goto loc_820D5718;
	// ld r9,12536(r30)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r30.u32 + 12536);
	// addi r29,r30,12528
	ctx.r29.s64 = ctx.r30.s64 + 12528;
	// ld r10,56(r28)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r28.u32 + 56);
	// ld r11,48(r28)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r28.u32 + 48);
	// ld r8,12528(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 12528);
	// xor r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// ld r6,32(r31)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r31.u32 + 32);
	// ld r9,40(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// xor r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 ^ ctx.r8.u64;
	// and r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 & ctx.r9.u64;
	// and r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 & ctx.r6.u64;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x820d57d4
	if (ctx.cr6.eq) goto loc_820D57D4;
loc_820D5718:
	// lwz r11,64(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d5748
	if (ctx.cr6.eq) goto loc_820D5748;
	// lwz r10,10896(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 10896);
	// lwz r9,10908(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 10908);
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x820d5748
	if (!ctx.cr6.lt) goto loc_820D5748;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820d57e8
	goto loc_820D57E8;
loc_820D5748:
	// addi r11,r7,112
	ctx.r11.s64 = ctx.r7.s64 + 112;
	// lwz r10,32(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 32);
	// addi r29,r30,12528
	ctx.r29.s64 = ctx.r30.s64 + 12528;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwzx r11,r11,r4
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r4.u32);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lwz r11,872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 872);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x820d4b20
	ctx.lr = 0x820D5778;
	sub_820D4B20(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d57bc
	if (!ctx.cr6.eq) goto loc_820D57BC;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r10,r11,6424
	ctx.r10.s64 = ctx.r11.s64 + 6424;
loc_820D578C:
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_820D5790:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r8
	ea = ctx.r8.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x820d5790
	if (!ctx.cr0.eq) goto loc_820D5790;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// blt cr6,0x820d578c
	if (ctx.cr6.lt) goto loc_820D578C;
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_820D57BC:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// stw r11,40(r28)
	REX_STORE_U32(ctx.r28.u32 + 40, ctx.r11.u32);
	// ld r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// std r11,48(r28)
	REX_STORE_U64(ctx.r28.u32 + 48, ctx.r11.u64);
	// ld r11,12536(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 12536);
	// std r11,56(r28)
	REX_STORE_U64(ctx.r28.u32 + 56, ctx.r11.u64);
loc_820D57D4:
	// ld r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// li r3,1
	ctx.r3.s64 = 1;
	// ld r10,12536(r30)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + 12536);
	// std r11,11832(r30)
	REX_STORE_U64(ctx.r30.u32 + 11832, ctx.r11.u64);
	// std r10,11840(r30)
	REX_STORE_U64(ctx.r30.u32 + 11840, ctx.r10.u64);
loc_820D57E8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
