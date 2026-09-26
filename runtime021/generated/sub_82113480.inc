DEFINE_REX_FUNC(sub_82113480) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82113488;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r25,r29,104
	ctx.r25.s64 = ctx.r29.s64 + 104;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8214a434
	ctx.lr = 0x8211349C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,820(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 820);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821134b0
	if (ctx.cr0.eq) goto loc_821134B0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82112bc0
	ctx.lr = 0x821134B0;
	sub_82112BC0(ctx, base);
loc_821134B0:
	// lwz r11,820(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 820);
	// li r10,3
	ctx.r10.s64 = 3;
	// li r28,0
	ctx.r28.s64 = 0;
	// rlwinm r11,r11,0,4,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// stw r10,144(r29)
	REX_STORE_U32(ctx.r29.u32 + 144, ctx.r10.u32);
	// stw r28,148(r29)
	REX_STORE_U32(ctx.r29.u32 + 148, ctx.r28.u32);
	// addi r27,r29,8
	ctx.r27.s64 = ctx.r29.s64 + 8;
	// stw r11,820(r29)
	REX_STORE_U32(ctx.r29.u32 + 820, ctx.r11.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82117908
	ctx.lr = 0x821134D8;
	sub_82117908(ctx, base);
	// addi r26,r29,728
	ctx.r26.s64 = ctx.r29.s64 + 728;
loc_821134DC:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x82113594
	if (ctx.cr6.eq) goto loc_82113594;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r30,r11,-12
	ctx.r30.s64 = ctx.r11.s64 + -12;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lbz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 44);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8211354c
	if (ctx.cr6.lt) goto loc_8211354C;
	// lwz r31,52(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// stw r28,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r28.u32);
	// beq cr6,0x8211353c
	if (ctx.cr6.eq) goto loc_8211353C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x82113550
	if (!ctx.cr6.lt) goto loc_82113550;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82115c28
	ctx.lr = 0x82113538;
	sub_82115C28(ctx, base);
	// b 0x82113550
	goto loc_82113550;
loc_8211353C:
	// lwz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// rlwinm r11,r11,0,4,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// stw r11,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// b 0x82113550
	goto loc_82113550;
loc_8211354C:
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
loc_82113550:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82113584
	if (ctx.cr6.eq) goto loc_82113584;
loc_82113558:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82113558
	if (!ctx.cr0.eq) goto loc_82113558;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82113584
	if (!ctx.cr6.eq) goto loc_82113584;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82115638
	ctx.lr = 0x82113584;
	sub_82115638(ctx, base);
loc_82113584:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82115c28
	ctx.lr = 0x82113590;
	sub_82115C28(ctx, base);
	// b 0x821134dc
	goto loc_821134DC;
loc_82113594:
	// addi r31,r29,712
	ctx.r31.s64 = ctx.r29.s64 + 712;
loc_82113598:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x821135bc
	if (ctx.cr6.eq) goto loc_821135BC;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x821135bc
	if (ctx.cr0.eq) goto loc_821135BC;
	// addi r4,r11,-4
	ctx.r4.s64 = ctx.r11.s64 + -4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82112570
	ctx.lr = 0x821135B8;
	sub_82112570(ctx, base);
	// b 0x82113598
	goto loc_82113598;
loc_821135BC:
	// addi r31,r29,720
	ctx.r31.s64 = ctx.r29.s64 + 720;
loc_821135C0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82113620
	if (ctx.cr6.eq) goto loc_82113620;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r3,r11,-12
	ctx.r3.s64 = ctx.r11.s64 + -12;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_821135F0:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r3
	ea = ctx.r3.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stwcx. r9,0,r3
	ea = ctx.r3.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x821135f0
	if (!ctx.cr0.eq) goto loc_821135F0;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821135c0
	if (!ctx.cr6.eq) goto loc_821135C0;
	// bl 0x82115638
	ctx.lr = 0x8211361C;
	sub_82115638(ctx, base);
	// b 0x821135c0
	goto loc_821135C0;
loc_82113620:
	// lwz r11,820(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 820);
	// lwz r3,164(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 164);
	// rlwinm r11,r11,0,3,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFF9FFFFFFF;
	// stw r11,820(r29)
	REX_STORE_U32(ctx.r29.u32 + 820, ctx.r11.u32);
	// bl 0x82115208
	ctx.lr = 0x82113634;
	sub_82115208(ctx, base);
	// stw r28,164(r29)
	REX_STORE_U32(ctx.r29.u32 + 164, ctx.r28.u32);
	// stw r28,136(r29)
	REX_STORE_U32(ctx.r29.u32 + 136, ctx.r28.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8214a444
	ctx.lr = 0x82113644;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8210e528
	ctx.lr = 0x8211364C;
	sub_8210E528(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f60
	ctx.lr = 0x82113658;
	sub_82108F60(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
