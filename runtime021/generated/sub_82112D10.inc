DEFINE_REX_FUNC(sub_82112D10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82112D18;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lwz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// oris r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 16777216;
	// stw r11,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// lwz r10,152(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 152);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82112d4c
	if (!ctx.cr6.eq) goto loc_82112D4C;
	// bl 0x82112570
	ctx.lr = 0x82112D44;
	sub_82112570(ctx, base);
loc_82112D44:
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x82112f90
	goto loc_82112F90;
loc_82112D4C:
	// rlwinm. r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82112d7c
	if (ctx.cr0.eq) goto loc_82112D7C;
	// rlwinm r11,r11,0,12,10
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// stw r11,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// lwz r11,708(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 708);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,708(r29)
	REX_STORE_U32(ctx.r29.u32 + 708, ctx.r11.u32);
	// bne 0x82112d7c
	if (!ctx.cr0.eq) goto loc_82112D7C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8210f488
	ctx.lr = 0x82112D74;
	sub_8210F488(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82112f90
	if (!ctx.cr0.eq) goto loc_82112F90;
loc_82112D7C:
	// addi r26,r29,8
	ctx.r26.s64 = ctx.r29.s64 + 8;
	// lwz r4,60(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82116fb8
	ctx.lr = 0x82112D94;
	sub_82116FB8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82112f90
	if (!ctx.cr0.eq) goto loc_82112F90;
	// lwz r11,820(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 820);
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82112e04
	if (ctx.cr0.eq) goto loc_82112E04;
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82112dc0
	if (!ctx.cr6.eq) goto loc_82112DC0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82112570
	ctx.lr = 0x82112DC0;
	sub_82112570(ctx, base);
loc_82112DC0:
	// lwz r11,712(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 712);
	// addi r10,r29,712
	ctx.r10.s64 = ctx.r29.s64 + 712;
	// b 0x82112ddc
	goto loc_82112DDC;
loc_82112DCC:
	// lbz r9,164(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 164);
	// clrlwi. r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82112df0
	if (ctx.cr0.eq) goto loc_82112DF0;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82112DDC:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82112df8
	if (ctx.cr6.eq) goto loc_82112DF8;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82112dcc
	if (!ctx.cr0.eq) goto loc_82112DCC;
	// b 0x82112df8
	goto loc_82112DF8;
loc_82112DF0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82112d44
	if (!ctx.cr6.eq) goto loc_82112D44;
loc_82112DF8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82117908
	ctx.lr = 0x82112E00;
	sub_82117908(ctx, base);
	// b 0x82112d44
	goto loc_82112D44;
loc_82112E04:
	// lwz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82112e28
	if (!ctx.cr6.eq) goto loc_82112E28;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82111fb0
	ctx.lr = 0x82112E20;
	sub_82111FB0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82112f90
	if (!ctx.cr0.eq) goto loc_82112F90;
loc_82112E28:
	// lwz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// rlwinm. r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82112e90
	if (!ctx.cr0.eq) goto loc_82112E90;
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82112d44
	if (!ctx.cr0.eq) goto loc_82112D44;
	// lwz r10,152(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82112d44
	if (!ctx.cr6.eq) goto loc_82112D44;
	// lwz r4,156(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82112e78
	if (ctx.cr6.eq) goto loc_82112E78;
	// rlwinm. r11,r11,0,13,13
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82112d44
	if (ctx.cr0.eq) goto loc_82112D44;
	// lwz r10,12(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r4,12
	ctx.r11.s64 = ctx.r4.s64 + 12;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82112d44
	if (!ctx.cr6.eq) goto loc_82112D44;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8210dab8
	ctx.lr = 0x82112E74;
	sub_8210DAB8(ctx, base);
	// b 0x82112d44
	goto loc_82112D44;
loc_82112E78:
	// oris r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 67108864;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r11,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8210da60
	ctx.lr = 0x82112E8C;
	sub_8210DA60(ctx, base);
	// b 0x82112d44
	goto loc_82112D44;
loc_82112E90:
	// lwz r30,64(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82112ed8
	if (!ctx.cr6.eq) goto loc_82112ED8;
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// bl 0x82115208
	ctx.lr = 0x82112EA4;
	sub_82115208(ctx, base);
	// stw r30,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r30.u32);
loc_82112EA8:
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
	// bne 0x82112ea8
	if (!ctx.cr0.eq) goto loc_82112EA8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82112f90
	if (!ctx.cr6.eq) goto loc_82112F90;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82115638
	ctx.lr = 0x82112ED4;
	sub_82115638(ctx, base);
	// b 0x82112f90
	goto loc_82112F90;
loc_82112ED8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x821158d8
	ctx.lr = 0x82112EE4;
	sub_821158D8(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x82112f10
	if (!ctx.cr0.eq) goto loc_82112F10;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82115998
	ctx.lr = 0x82112EF8;
	sub_82115998(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x82112f10
	if (!ctx.cr0.eq) goto loc_82112F10;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82112570
	ctx.lr = 0x82112F0C;
	sub_82112570(ctx, base);
	// b 0x82112f78
	goto loc_82112F78;
loc_82112F10:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// blt cr6,0x82112f20
	if (ctx.cr6.lt) goto loc_82112F20;
	// lis r27,-32646
	ctx.r27.s64 = -2139488256;
	// ori r27,r27,4113
	ctx.r27.u64 = ctx.r27.u64 | 4113;
loc_82112F20:
	// lis r10,4626
	ctx.r10.s64 = 303169536;
	// lwz r11,128(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 128);
	// ori r10,r10,4626
	ctx.r10.u64 = ctx.r10.u64 | 4626;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82112f60
	if (ctx.cr6.eq) goto loc_82112F60;
	// lis r10,13364
	ctx.r10.s64 = 875823104;
	// ori r10,r10,13364
	ctx.r10.u64 = ctx.r10.u64 | 13364;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82112f60
	if (ctx.cr6.eq) goto loc_82112F60;
	// lwz r11,144(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 144);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82112f78
	if (!ctx.cr6.eq) goto loc_82112F78;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8210d130
	ctx.lr = 0x82112F5C;
	sub_8210D130(ctx, base);
	// b 0x82112f70
	goto loc_82112F70;
loc_82112F60:
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82116728
	ctx.lr = 0x82112F70;
	sub_82116728(ctx, base);
loc_82112F70:
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82112f7c
	if (!ctx.cr0.eq) goto loc_82112F7C;
loc_82112F78:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82112F7C:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82112f90
	if (ctx.cr6.eq) goto loc_82112F90;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82115c28
	ctx.lr = 0x82112F90;
	sub_82115C28(ctx, base);
loc_82112F90:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
