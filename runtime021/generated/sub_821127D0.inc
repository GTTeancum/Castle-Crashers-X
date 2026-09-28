DEFINE_REX_FUNC(sub_821127D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298ec
	ctx.lr = 0x821127D8;
	__savegprlr_17(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r18,0
	ctx.r18.s64 = 0;
	// mr r19,r4
	ctx.r19.u64 = ctx.r4.u64;
	// mr r17,r18
	ctx.r17.u64 = ctx.r18.u64;
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
	// lwz r10,156(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 156);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8211281c
	if (ctx.cr6.eq) goto loc_8211281C;
	// addi r9,r29,176
	ctx.r9.s64 = ctx.r29.s64 + 176;
loc_82112800:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8211281c
	if (ctx.cr6.eq) goto loc_8211281C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82112800
	if (ctx.cr6.lt) goto loc_82112800;
loc_8211281C:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82112830
	if (ctx.cr6.lt) goto loc_82112830;
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4101
	ctx.r31.u64 = ctx.r31.u64 | 4101;
	// b 0x82112b44
	goto loc_82112B44;
loc_82112830:
	// lwz r10,52(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 52);
	// lwz r22,36(r19)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r19.u32 + 36);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r9,168(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 168);
	// rlwinm. r9,r9,0,6,6
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82112854
	if (ctx.cr0.eq) goto loc_82112854;
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4113
	ctx.r31.u64 = ctx.r31.u64 | 4113;
	// b 0x82112b44
	goto loc_82112B44;
loc_82112854:
	// rlwinm r9,r22,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 | ctx.r11.u64;
	// stw r9,60(r10)
	REX_STORE_U32(ctx.r10.u32 + 60, ctx.r9.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r22,64(r10)
	REX_STORE_U32(ctx.r10.u32 + 64, ctx.r22.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_82112870:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r8,0,r10
	ea = ctx.r10.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r8.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stwcx. r8,0,r10
	ea = ctx.r10.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r8.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82112870
	if (!ctx.cr0.eq) goto loc_82112870;
	// addi r11,r11,44
	ctx.r11.s64 = ctx.r11.s64 + 44;
	// li r3,259
	ctx.r3.s64 = 259;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r11,r29
	REX_STORE_U32(ctx.r11.u32 + ctx.r29.u32, ctx.r9.u32);
	// lwz r11,168(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 168);
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// stw r11,168(r9)
	REX_STORE_U32(ctx.r9.u32 + 168, ctx.r11.u32);
	// lwz r10,704(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 704);
	// lwz r11,152(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 152);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mulli r11,r11,42
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(42));
	// addi r30,r11,25
	ctx.r30.s64 = ctx.r11.s64 + 25;
	// addi r4,r30,16
	ctx.r4.s64 = ctx.r30.s64 + 16;
	// bl 0x82108f48
	ctx.lr = 0x821128C8;
	sub_82108F48(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// li r21,5
	ctx.r21.s64 = 5;
	// beq 0x821128ec
	if (ctx.cr0.eq) goto loc_821128EC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r19,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r19.u32);
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r18,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r18.u32);
	// stb r21,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r21.u8);
loc_821128EC:
	// mr r20,r31
	ctx.r20.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82112904
	if (!ctx.cr6.eq) goto loc_82112904;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x82112b08
	goto loc_82112B08;
loc_82112904:
	// stw r22,17(r31)
	REX_STORE_U32(ctx.r31.u32 + 17, ctx.r22.u32);
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// stw r11,21(r31)
	REX_STORE_U32(ctx.r31.u32 + 21, ctx.r11.u32);
	// lwz r11,24(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 24);
	// stw r11,25(r31)
	REX_STORE_U32(ctx.r31.u32 + 25, ctx.r11.u32);
	// lwz r11,156(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 156);
	// stw r11,29(r31)
	REX_STORE_U32(ctx.r31.u32 + 29, ctx.r11.u32);
	// lwz r11,692(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 692);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82112940
	if (ctx.cr6.eq) goto loc_82112940;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,21(r30)
	REX_STORE_U32(ctx.r30.u32 + 21, ctx.r11.u32);
	// b 0x82112944
	goto loc_82112944;
loc_82112940:
	// stw r18,21(r30)
	REX_STORE_U32(ctx.r30.u32 + 21, ctx.r18.u32);
loc_82112944:
	// lwz r11,712(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 712);
	// addi r28,r29,712
	ctx.r28.s64 = ctx.r29.s64 + 712;
	// li r26,25
	ctx.r26.s64 = 25;
	// addi r27,r30,25
	ctx.r27.s64 = ctx.r30.s64 + 25;
	// mr r25,r18
	ctx.r25.u64 = ctx.r18.u64;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x821129cc
	if (ctx.cr6.eq) goto loc_821129CC;
	// mr r23,r11
	ctx.r23.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x821129cc
	if (ctx.cr0.eq) goto loc_821129CC;
	// addi r24,r27,4
	ctx.r24.s64 = ctx.r27.s64 + 4;
loc_82112970:
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r23,-4
	ctx.r11.s64 = ctx.r23.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x821129b4
	if (ctx.cr6.eq) goto loc_821129B4;
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x821129b4
	if (ctx.cr0.eq) goto loc_821129B4;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// addi r4,r11,20
	ctx.r4.s64 = ctx.r11.s64 + 20;
	// li r5,38
	ctx.r5.s64 = 38;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// bl 0x82129a70
	ctx.lr = 0x821129A4;
	sub_82129A70(ctx, base);
	// addi r26,r26,42
	ctx.r26.s64 = ctx.r26.s64 + 42;
	// addi r27,r27,42
	ctx.r27.s64 = ctx.r27.s64 + 42;
	// addi r24,r24,42
	ctx.r24.s64 = ctx.r24.s64 + 42;
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
loc_821129B4:
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x821129cc
	if (ctx.cr6.eq) goto loc_821129CC;
	// mr r23,r11
	ctx.r23.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82112970
	if (!ctx.cr0.eq) goto loc_82112970;
loc_821129CC:
	// stw r25,17(r30)
	REX_STORE_U32(ctx.r30.u32 + 17, ctx.r25.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r30,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r30.u32);
	// stw r26,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r26.u32);
	// lwz r11,692(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 692);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82112a24
	if (ctx.cr6.eq) goto loc_82112A24;
loc_821129E8:
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
	// bne 0x821129e8
	if (!ctx.cr0.eq) goto loc_821129E8;
	// lwz r11,692(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 692);
	// li r6,2
	ctx.r6.s64 = 2;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r11,692(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 692);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
loc_82112A24:
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r21,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r21.u32);
	// stw r18,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r18.u32);
	// lis r4,32767
	ctx.r4.s64 = 2147418112;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// li r9,131
	ctx.r9.s64 = 131;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// ori r4,r4,65534
	ctx.r4.u64 = ctx.r4.u64 | 65534;
	// lwz r3,68(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// bl 0x82115188
	ctx.lr = 0x82112A58;
	sub_82115188(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82112b08
	if (!ctx.cr0.eq) goto loc_82112B08;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r20,r18
	ctx.r20.u64 = ctx.r18.u64;
	// lwz r28,148(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82112adc
	if (ctx.cr6.eq) goto loc_82112ADC;
	// addi r30,r29,8
	ctx.r30.s64 = ctx.r29.s64 + 8;
loc_82112A78:
	// addic. r22,r22,1
	ctx.xer.ca = ctx.r22.u32 > 4294967294;
	ctx.r22.s64 = ctx.r22.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// bne 0x82112a84
	if (!ctx.cr0.eq) goto loc_82112A84;
	// li r22,1
	ctx.r22.s64 = 1;
loc_82112A84:
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821158d8
	ctx.lr = 0x82112A90;
	sub_821158D8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82112AB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82115c28
	ctx.lr = 0x82112AC4;
	sub_82115C28(ctx, base);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x82112b44
	if (ctx.cr6.lt) goto loc_82112B44;
	// cmplw cr6,r22,r28
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82112a78
	if (!ctx.cr6.eq) goto loc_82112A78;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r18,148(r11)
	REX_STORE_U32(ctx.r11.u32 + 148, ctx.r18.u32);
loc_82112ADC:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82112b58
	if (!ctx.cr0.eq) goto loc_82112B58;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// li r17,1
	ctx.r17.s64 = 1;
	// bl 0x82116728
	ctx.lr = 0x82112B00;
	sub_82116728(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82112b58
	if (ctx.cr0.eq) goto loc_82112B58;
loc_82112B08:
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x82112b3c
	if (ctx.cr6.eq) goto loc_82112B3C;
loc_82112B10:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r20
	ea = ctx.r20.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r20
	ea = ctx.r20.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82112b10
	if (!ctx.cr0.eq) goto loc_82112B10;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82112b3c
	if (!ctx.cr6.eq) goto loc_82112B3C;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x821117e0
	ctx.lr = 0x82112B3C;
	sub_821117E0(ctx, base);
loc_82112B3C:
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// bne cr6,0x82112b58
	if (!ctx.cr6.eq) goto loc_82112B58;
loc_82112B44:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// bl 0x82116728
	ctx.lr = 0x82112B54;
	sub_82116728(ctx, base);
	// mr r31,r18
	ctx.r31.u64 = ctx.r18.u64;
loc_82112B58:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
}
