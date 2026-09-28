DEFINE_REX_FUNC(sub_8211DFA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x8211DFA8;
	__savegprlr_21(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,-20356
	ctx.r11.s64 = ctx.r11.s64 + -20356;
	// li r23,1
	ctx.r23.s64 = 1;
	// stw r6,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r6.u32);
	// addi r27,r31,176
	ctx.r27.s64 = ctx.r31.s64 + 176;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r23,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r23.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r21,r8
	ctx.r21.u64 = ctx.r8.u64;
	// bl 0x8211c420
	ctx.lr = 0x8211DFF0;
	sub_8211C420(ctx, base);
	// addi r26,r31,236
	ctx.r26.s64 = ctx.r31.s64 + 236;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8211c420
	ctx.lr = 0x8211DFFC;
	sub_8211C420(ctx, base);
	// addi r25,r31,296
	ctx.r25.s64 = ctx.r31.s64 + 296;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8211c420
	ctx.lr = 0x8211E008;
	sub_8211C420(ctx, base);
	// addi r24,r31,356
	ctx.r24.s64 = ctx.r31.s64 + 356;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8211c420
	ctx.lr = 0x8211E014;
	sub_8211C420(ctx, base);
	// stw r30,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// addi r3,r31,40
	ctx.r3.s64 = ctx.r31.s64 + 40;
	// bl 0x8214a424
	ctx.lr = 0x8211E024;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// stw r29,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r29.u32);
	// addi r9,r29,4
	ctx.r9.s64 = ctx.r29.s64 + 4;
loc_8211E02C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8211e02c
	if (!ctx.cr0.eq) goto loc_8211E02C;
	// addi r3,r31,68
	ctx.r3.s64 = ctx.r31.s64 + 68;
	// addi r4,r29,40
	ctx.r4.s64 = ctx.r29.s64 + 40;
	// li r5,68
	ctx.r5.s64 = 68;
	// bl 0x82129a70
	ctx.lr = 0x8211E058;
	sub_82129A70(ctx, base);
	// addi r3,r31,28
	ctx.r3.s64 = ctx.r31.s64 + 28;
	// li r5,6
	ctx.r5.s64 = 6;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// bl 0x82129a70
	ctx.lr = 0x8211E068;
	sub_82129A70(ctx, base);
	// addi r11,r31,160
	ctx.r11.s64 = ctx.r31.s64 + 160;
	// addi r10,r31,168
	ctx.r10.s64 = ctx.r31.s64 + 168;
	// stw r30,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
	// stw r30,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r30.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r30,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r30.u32);
	// std r30,136(r31)
	REX_STORE_U64(ctx.r31.u32 + 136, ctx.r30.u64);
	// stw r11,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
	// stw r11,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// stw r10,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r10.u32);
	// stw r10,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r10.u32);
	// bl 0x82122200
	ctx.lr = 0x8211E0A0;
	sub_82122200(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82122200
	ctx.lr = 0x8211E0AC;
	sub_82122200(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82122200
	ctx.lr = 0x8211E0B8;
	sub_82122200(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82122200
	ctx.lr = 0x8211E0C4;
	sub_82122200(ctx, base);
	// stw r30,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r30.u32);
	// stw r30,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r30.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// sth r30,440(r31)
	REX_STORE_U16(ctx.r31.u32 + 440, ctx.r30.u16);
	// addi r3,r31,444
	ctx.r3.s64 = ctx.r31.s64 + 444;
	// stw r30,424(r31)
	REX_STORE_U32(ctx.r31.u32 + 424, ctx.r30.u32);
	// addi r27,r31,424
	ctx.r27.s64 = ctx.r31.s64 + 424;
	// stw r30,428(r31)
	REX_STORE_U32(ctx.r31.u32 + 428, ctx.r30.u32);
	// stw r30,432(r31)
	REX_STORE_U32(ctx.r31.u32 + 432, ctx.r30.u32);
	// stw r30,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r30.u32);
	// bl 0x820d7ea8
	ctx.lr = 0x8211E0F0;
	sub_820D7EA8(ctx, base);
	// stw r30,448(r31)
	REX_STORE_U32(ctx.r31.u32 + 448, ctx.r30.u32);
	// stw r30,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r30.u32);
	// cntlzw r11,r28
	ctx.r11.u64 = ctx.r28.u32 == 0 ? 32 : __builtin_clz(ctx.r28.u32);
	// addi r3,r31,472
	ctx.r3.s64 = ctx.r31.s64 + 472;
	// rlwinm r26,r11,27,31,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82121bf8
	ctx.lr = 0x8211E10C;
	sub_82121BF8(ctx, base);
	// addi r11,r31,512
	ctx.r11.s64 = ctx.r31.s64 + 512;
	// addi r10,r31,520
	ctx.r10.s64 = ctx.r31.s64 + 520;
	// stw r11,512(r31)
	REX_STORE_U32(ctx.r31.u32 + 512, ctx.r11.u32);
	// addi r4,r29,108
	ctx.r4.s64 = ctx.r29.s64 + 108;
	// stw r11,516(r31)
	REX_STORE_U32(ctx.r31.u32 + 516, ctx.r11.u32);
	// addi r11,r31,532
	ctx.r11.s64 = ctx.r31.s64 + 532;
	// stw r10,520(r31)
	REX_STORE_U32(ctx.r31.u32 + 520, ctx.r10.u32);
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// stw r10,524(r31)
	REX_STORE_U32(ctx.r31.u32 + 524, ctx.r10.u32);
	// stw r30,528(r31)
	REX_STORE_U32(ctx.r31.u32 + 528, ctx.r30.u32);
	// lbz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r21.u32 + 0);
	// stb r11,532(r31)
	REX_STORE_U8(ctx.r31.u32 + 532, ctx.r11.u8);
	// lbz r11,1(r21)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r21.u32 + 1);
	// stb r11,533(r31)
	REX_STORE_U8(ctx.r31.u32 + 533, ctx.r11.u8);
	// lbz r11,2(r21)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r21.u32 + 2);
	// stb r11,534(r31)
	REX_STORE_U8(ctx.r31.u32 + 534, ctx.r11.u8);
	// lbz r11,3(r21)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r21.u32 + 3);
	// stb r11,535(r31)
	REX_STORE_U8(ctx.r31.u32 + 535, ctx.r11.u8);
	// stw r30,536(r31)
	REX_STORE_U32(ctx.r31.u32 + 536, ctx.r30.u32);
	// stw r30,540(r31)
	REX_STORE_U32(ctx.r31.u32 + 540, ctx.r30.u32);
	// stw r30,544(r31)
	REX_STORE_U32(ctx.r31.u32 + 544, ctx.r30.u32);
	// bl 0x82124f10
	ctx.lr = 0x8211E164;
	sub_82124F10(ctx, base);
	// std r30,552(r31)
	REX_STORE_U64(ctx.r31.u32 + 552, ctx.r30.u64);
	// stw r30,560(r31)
	REX_STORE_U32(ctx.r31.u32 + 560, ctx.r30.u32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// stw r30,564(r31)
	REX_STORE_U32(ctx.r31.u32 + 564, ctx.r30.u32);
	// addi r3,r31,572
	ctx.r3.s64 = ctx.r31.s64 + 572;
	// stw r30,568(r31)
	REX_STORE_U32(ctx.r31.u32 + 568, ctx.r30.u32);
	// bl 0x82121ff0
	ctx.lr = 0x8211E180;
	sub_82121FF0(ctx, base);
	// addi r11,r31,604
	ctx.r11.s64 = ctx.r31.s64 + 604;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r30,592(r31)
	REX_STORE_U32(ctx.r31.u32 + 592, ctx.r30.u32);
	// stw r30,596(r31)
	REX_STORE_U32(ctx.r31.u32 + 596, ctx.r30.u32);
	// addi r3,r31,624
	ctx.r3.s64 = ctx.r31.s64 + 624;
	// stw r30,600(r31)
	REX_STORE_U32(ctx.r31.u32 + 600, ctx.r30.u32);
	// stw r11,604(r31)
	REX_STORE_U32(ctx.r31.u32 + 604, ctx.r11.u32);
	// stw r11,608(r31)
	REX_STORE_U32(ctx.r31.u32 + 608, ctx.r11.u32);
	// std r10,616(r31)
	REX_STORE_U64(ctx.r31.u32 + 616, ctx.r10.u64);
	// bl 0x821080c8
	ctx.lr = 0x8211E1A8;
	sub_821080C8(ctx, base);
	// stw r30,636(r31)
	REX_STORE_U32(ctx.r31.u32 + 636, ctx.r30.u32);
	// addi r3,r31,640
	ctx.r3.s64 = ctx.r31.s64 + 640;
	// bl 0x821080c8
	ctx.lr = 0x8211E1B4;
	sub_821080C8(ctx, base);
	// stw r30,652(r31)
	REX_STORE_U32(ctx.r31.u32 + 652, ctx.r30.u32);
	// stw r30,656(r31)
	REX_STORE_U32(ctx.r31.u32 + 656, ctx.r30.u32);
	// addi r3,r31,872
	ctx.r3.s64 = ctx.r31.s64 + 872;
	// stw r30,660(r31)
	REX_STORE_U32(ctx.r31.u32 + 660, ctx.r30.u32);
	// bl 0x82123d30
	ctx.lr = 0x8211E1C8;
	sub_82123D30(ctx, base);
	// addi r3,r31,942
	ctx.r3.s64 = ctx.r31.s64 + 942;
	// bl 0x821241d0
	ctx.lr = 0x8211E1D0;
	sub_821241D0(ctx, base);
	// addi r11,r31,984
	ctx.r11.s64 = ctx.r31.s64 + 984;
	// addi r10,r31,992
	ctx.r10.s64 = ctx.r31.s64 + 992;
	// stw r11,984(r31)
	REX_STORE_U32(ctx.r31.u32 + 984, ctx.r11.u32);
	// addi r9,r31,1000
	ctx.r9.s64 = ctx.r31.s64 + 1000;
	// stw r11,988(r31)
	REX_STORE_U32(ctx.r31.u32 + 988, ctx.r11.u32);
	// addi r11,r31,1008
	ctx.r11.s64 = ctx.r31.s64 + 1008;
	// stw r10,992(r31)
	REX_STORE_U32(ctx.r31.u32 + 992, ctx.r10.u32);
	// addi r8,r31,1016
	ctx.r8.s64 = ctx.r31.s64 + 1016;
	// stw r10,996(r31)
	REX_STORE_U32(ctx.r31.u32 + 996, ctx.r10.u32);
	// stw r9,1000(r31)
	REX_STORE_U32(ctx.r31.u32 + 1000, ctx.r9.u32);
	// stw r9,1004(r31)
	REX_STORE_U32(ctx.r31.u32 + 1004, ctx.r9.u32);
	// stw r11,1008(r31)
	REX_STORE_U32(ctx.r31.u32 + 1008, ctx.r11.u32);
	// stw r11,1012(r31)
	REX_STORE_U32(ctx.r31.u32 + 1012, ctx.r11.u32);
	// stw r8,1016(r31)
	REX_STORE_U32(ctx.r31.u32 + 1016, ctx.r8.u32);
	// stw r8,1020(r31)
	REX_STORE_U32(ctx.r31.u32 + 1020, ctx.r8.u32);
	// stw r30,1024(r31)
	REX_STORE_U32(ctx.r31.u32 + 1024, ctx.r30.u32);
	// sth r30,1032(r31)
	REX_STORE_U16(ctx.r31.u32 + 1032, ctx.r30.u16);
	// lhz r11,148(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 148);
	// sth r11,1034(r31)
	REX_STORE_U16(ctx.r31.u32 + 1034, ctx.r11.u16);
	// lhz r11,150(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 150);
	// sth r11,1036(r31)
	REX_STORE_U16(ctx.r31.u32 + 1036, ctx.r11.u16);
	// lhz r11,152(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 152);
	// sth r11,1038(r31)
	REX_STORE_U16(ctx.r31.u32 + 1038, ctx.r11.u16);
	// lhz r10,154(r29)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r29.u32 + 154);
	// sth r11,1042(r31)
	REX_STORE_U16(ctx.r31.u32 + 1042, ctx.r11.u16);
	// sth r30,1046(r31)
	REX_STORE_U16(ctx.r31.u32 + 1046, ctx.r30.u16);
	// sth r30,1048(r31)
	REX_STORE_U16(ctx.r31.u32 + 1048, ctx.r30.u16);
	// sth r30,1050(r31)
	REX_STORE_U16(ctx.r31.u32 + 1050, ctx.r30.u16);
	// sth r10,1040(r31)
	REX_STORE_U16(ctx.r31.u32 + 1040, ctx.r10.u16);
	// sth r10,1044(r31)
	REX_STORE_U16(ctx.r31.u32 + 1044, ctx.r10.u16);
	// sth r30,1052(r31)
	REX_STORE_U16(ctx.r31.u32 + 1052, ctx.r30.u16);
	// sth r30,1054(r31)
	REX_STORE_U16(ctx.r31.u32 + 1054, ctx.r30.u16);
	// sth r30,1056(r31)
	REX_STORE_U16(ctx.r31.u32 + 1056, ctx.r30.u16);
	// stb r30,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r30.u8);
	// stb r23,1145(r31)
	REX_STORE_U8(ctx.r31.u32 + 1145, ctx.r23.u8);
	// stw r30,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r30.u32);
	// stw r30,1152(r31)
	REX_STORE_U32(ctx.r31.u32 + 1152, ctx.r30.u32);
	// stw r30,1156(r31)
	REX_STORE_U32(ctx.r31.u32 + 1156, ctx.r30.u32);
	// stw r30,1160(r31)
	REX_STORE_U32(ctx.r31.u32 + 1160, ctx.r30.u32);
	// stw r30,1164(r31)
	REX_STORE_U32(ctx.r31.u32 + 1164, ctx.r30.u32);
	// std r30,1168(r31)
	REX_STORE_U64(ctx.r31.u32 + 1168, ctx.r30.u64);
	// std r30,1176(r31)
	REX_STORE_U64(ctx.r31.u32 + 1176, ctx.r30.u64);
	// std r30,1184(r31)
	REX_STORE_U64(ctx.r31.u32 + 1184, ctx.r30.u64);
	// bl 0x82136f58
	ctx.lr = 0x8211E280;
	sub_82136F58(ctx, base);
	// stw r3,432(r31)
	REX_STORE_U32(ctx.r31.u32 + 432, ctx.r3.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820d7ea8
	ctx.lr = 0x8211E290;
	sub_820D7EA8(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8211e2a8
	if (!ctx.cr6.eq) goto loc_8211E2A8;
	// lwz r11,1148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r11.u32);
	// b 0x8211e2f8
	goto loc_8211E2F8;
loc_8211E2A8:
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r30,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// lwz r5,44(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// lwz r4,40(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 40);
	// bl 0x82120960
	ctx.lr = 0x8211E2C0;
	sub_82120960(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,17(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 17);
	// stw r10,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r10.u32);
	// lhz r10,3(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 3);
	// sth r10,1056(r31)
	REX_STORE_U16(ctx.r31.u32 + 1056, ctx.r10.u16);
	// lhz r10,5(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 5);
	// sth r10,1052(r31)
	REX_STORE_U16(ctx.r31.u32 + 1052, ctx.r10.u16);
	// lhz r10,7(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 7);
	// sth r10,1054(r31)
	REX_STORE_U16(ctx.r31.u32 + 1054, ctx.r10.u16);
	// lwz r10,21(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 21);
	// stw r10,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r10.u32);
	// lwz r4,13(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 13);
	// bl 0x8211b620
	ctx.lr = 0x8211E2F8;
	sub_8211B620(ctx, base);
loc_8211E2F8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
