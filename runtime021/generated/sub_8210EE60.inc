DEFINE_REX_FUNC(sub_8210EE60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x8210EE68;
	__savegprlr_22(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r23,0
	ctx.r23.s64 = 0;
	// cmplwi cr6,r6,14
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 14, ctx.xer);
	// bge cr6,0x8210ee90
	if (!ctx.cr6.lt) goto loc_8210EE90;
loc_8210EE84:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4106
	ctx.r30.u64 = ctx.r30.u64 | 4106;
	// b 0x8210f0ac
	goto loc_8210F0AC;
loc_8210EE90:
	// lwz r25,2(r28)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r28.u32 + 2);
	// addi r5,r6,-14
	ctx.r5.s64 = ctx.r6.s64 + -14;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x8210f06c
	if (ctx.cr6.eq) goto loc_8210F06C;
	// lwz r11,20(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 20);
	// cmplw cr6,r25,r11
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8210f06c
	if (ctx.cr6.eq) goto loc_8210F06C;
	// lwz r11,712(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 712);
	// addi r10,r22,712
	ctx.r10.s64 = ctx.r22.s64 + 712;
	// b 0x8210eecc
	goto loc_8210EECC;
loc_8210EEB8:
	// lwz r9,56(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// addi r31,r11,-4
	ctx.r31.s64 = ctx.r11.s64 + -4;
	// cmplw cr6,r9,r25
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x8210eee0
	if (ctx.cr6.eq) goto loc_8210EEE0;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_8210EECC:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8210eedc
	if (ctx.cr6.eq) goto loc_8210EEDC;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8210eeb8
	if (!ctx.cr0.eq) goto loc_8210EEB8;
loc_8210EEDC:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8210EEE0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8210ee84
	if (ctx.cr6.eq) goto loc_8210EE84;
	// lbz r11,1(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 1);
	// addi r30,r28,14
	ctx.r30.s64 = ctx.r28.s64 + 14;
	// lwz r27,6(r28)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r28.u32 + 6);
	// lwz r26,10(r28)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + 10);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8210efa4
	if (ctx.cr6.eq) goto loc_8210EFA4;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8210ef7c
	if (ctx.cr6.eq) goto loc_8210EF7C;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8210ef5c
	if (ctx.cr6.eq) goto loc_8210EF5C;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x8210ee84
	if (!ctx.cr6.eq) goto loc_8210EE84;
	// lis r11,4096
	ctx.r11.s64 = 268435456;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8210ef34
	if (!ctx.cr6.gt) goto loc_8210EF34;
loc_8210EF28:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4102
	ctx.r30.u64 = ctx.r30.u64 | 4102;
	// b 0x8210f0ac
	goto loc_8210F0AC;
loc_8210EF34:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8210efd0
	if (ctx.cr6.eq) goto loc_8210EFD0;
	// li r3,257
	ctx.r3.s64 = 257;
loc_8210EF40:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8210e160
	ctx.lr = 0x8210EF48;
	sub_8210E160(ctx, base);
	// mr. r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// bne 0x8210efd0
	if (!ctx.cr0.eq) goto loc_8210EFD0;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x8210f074
	goto loc_8210F074;
loc_8210EF5C:
	// lis r11,4096
	ctx.r11.s64 = 268435456;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8210ef28
	if (ctx.cr6.gt) goto loc_8210EF28;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8210efd0
	if (ctx.cr6.eq) goto loc_8210EFD0;
	// li r3,258
	ctx.r3.s64 = 258;
	// b 0x8210ef40
	goto loc_8210EF40;
loc_8210EF7C:
	// li r29,8
	ctx.r29.s64 = 8;
	// cmplwi cr6,r5,8
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 8, ctx.xer);
	// bne cr6,0x8210ee84
	if (!ctx.cr6.eq) goto loc_8210EE84;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210ee84
	if (ctx.cr6.eq) goto loc_8210EE84;
	// lwz r10,60(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 60);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8210efd0
	if (!ctx.cr6.eq) goto loc_8210EFD0;
	// b 0x8210ee84
	goto loc_8210EE84;
loc_8210EFA4:
	// li r29,38
	ctx.r29.s64 = 38;
	// cmplwi cr6,r5,38
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 38, ctx.xer);
	// bne cr6,0x8210ee84
	if (!ctx.cr6.eq) goto loc_8210EE84;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82129a70
	ctx.lr = 0x8210EFBC;
	sub_82129A70(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8210cc60
	ctx.lr = 0x8210EFC8;
	sub_8210CC60(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8210ee84
	if (ctx.cr0.eq) goto loc_8210EE84;
loc_8210EFD0:
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
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
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
	// bne 0x8210efd0
	if (!ctx.cr0.eq) goto loc_8210EFD0;
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// stw r23,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r23.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// stw r11,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// lbz r10,1(r28)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + 1);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r6,60(r24)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r24.u32 + 60);
	// addi r3,r22,8
	ctx.r3.s64 = ctx.r22.s64 + 8;
	// bl 0x82116898
	ctx.lr = 0x8210F028;
	sub_82116898(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8210f074
	if (ctx.cr0.eq) goto loc_8210F074;
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
loc_8210F03C:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8210f03c
	if (!ctx.cr0.eq) goto loc_8210F03C;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210f06c
	if (!ctx.cr6.eq) goto loc_8210F06C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82115638
	ctx.lr = 0x8210F06C;
	sub_82115638(ctx, base);
loc_8210F06C:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4106
	ctx.r30.u64 = ctx.r30.u64 | 4106;
loc_8210F074:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x8210f0ac
	if (ctx.cr6.eq) goto loc_8210F0AC;
loc_8210F07C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r23
	ea = ctx.r23.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r23
	ea = ctx.r23.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8210f07c
	if (!ctx.cr0.eq) goto loc_8210F07C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210f0ac
	if (!ctx.cr6.eq) goto loc_8210F0AC;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lwz r3,4(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 4);
	// bl 0x82108f60
	ctx.lr = 0x8210F0AC;
	sub_82108F60(ctx, base);
loc_8210F0AC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
