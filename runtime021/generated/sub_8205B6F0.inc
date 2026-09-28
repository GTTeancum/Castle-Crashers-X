DEFINE_REX_FUNC(sub_8205B6F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x8205B6F8;
	__savegprlr_14(ctx, base);
	// stfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -176, ctx.f29.u64);
	// stfd f30,-168(r1)
	REX_STORE_U64(ctx.r1.u32 + -168, ctx.f30.u64);
	// stfd f31,-160(r1)
	REX_STORE_U64(ctx.r1.u32 + -160, ctx.f31.u64);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r23,-32215
	ctx.r23.s64 = -2111242240;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stw r28,420(r1)
	REX_STORE_U32(ctx.r1.u32 + 420, ctx.r28.u32);
	// lwz r25,2812(r23)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r23.u32 + 2812);
	// clrlwi r11,r25,31
	ctx.r11.u64 = ctx.r25.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205b740
	if (!ctx.cr6.eq) goto loc_8205B740;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// ori r25,r25,1
	ctx.r25.u64 = ctx.r25.u64 | 1;
	// stw r25,2812(r23)
	REX_STORE_U32(ctx.r23.u32 + 2812, ctx.r25.u32);
	// lwz r11,-6596(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,2808(r10)
	REX_STORE_U32(ctx.r10.u32 + 2808, ctx.r11.u32);
loc_8205B740:
	// rlwinm r10,r25,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x2;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r31,r11,112
	ctx.r31.s64 = ctx.r11.s64 + 112;
	// bne cr6,0x8205c320
	if (!ctx.cr6.eq) goto loc_8205C320;
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r8,r11,13252
	ctx.r8.s64 = ctx.r11.s64 + 13252;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r11,-6640(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -6640);
	// addi r6,r10,13228
	ctx.r6.s64 = ctx.r10.s64 + 13228;
	// addi r10,r7,9480
	ctx.r10.s64 = ctx.r7.s64 + 9480;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r4,r4,13208
	ctx.r4.s64 = ctx.r4.s64 + 13208;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rotlwi r7,r9,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lis r29,-32255
	ctx.r29.s64 = -2113863680;
	// addi r30,r10,1
	ctx.r30.s64 = ctx.r10.s64 + 1;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// rlwinm r26,r30,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r10,13184
	ctx.r30.s64 = ctx.r10.s64 + 13184;
	// lwz r10,1392(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 1392);
	// rotlwi r5,r7,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// addi r29,r29,13160
	ctx.r29.s64 = ctx.r29.s64 + 13160;
	// rotlwi r3,r5,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lis r27,-32255
	ctx.r27.s64 = -2113863680;
	// rotlwi r28,r3,0
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lwzx r10,r26,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + ctx.r10.u32);
	// lis r26,-32255
	ctx.r26.s64 = -2113863680;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// ori r9,r25,2
	ctx.r9.u64 = ctx.r25.u64 | 2;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lis r24,-32255
	ctx.r24.s64 = -2113863680;
	// stw r9,2812(r23)
	REX_STORE_U32(ctx.r23.u32 + 2812, ctx.r9.u32);
	// rotlwi r9,r28,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r28.u32, 0);
	// addi r27,r27,13128
	ctx.r27.s64 = ctx.r27.s64 + 13128;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r23,12(r11)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r26,r26,13100
	ctx.r26.s64 = ctx.r26.s64 + 13100;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r24,r24,13080
	ctx.r24.s64 = ctx.r24.s64 + 13080;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r23,1396(r23)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r23.u32 + 1396);
	// lwzx r10,r10,r23
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r23.u32);
	// stw r7,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// stw r10,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// stw r8,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,1400(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 1400);
	// lwzx r10,r10,r8
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// stw r6,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r6.u32);
	// stw r5,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r5.u32);
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,1404(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 1404);
	// lwzx r10,r5,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// stw r4,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r4.u32);
	// stw r3,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// stw r10,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r5,1408(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 1408);
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r6,r5
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r29,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r29.u32);
	// stw r28,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r28.u32);
	// stw r10,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// rlwinm r8,r3,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,1412(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 1412);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lis r16,-32255
	ctx.r16.s64 = -2113863680;
	// lwzx r10,r8,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r10,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// lis r21,-32255
	ctx.r21.s64 = -2113863680;
	// stw r27,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r27.u32);
	// lis r20,-32255
	ctx.r20.s64 = -2113863680;
	// stw r9,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// addi r9,r8,13056
	ctx.r9.s64 = ctx.r8.s64 + 13056;
	// lwz r30,12(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r8,r7,13032
	ctx.r8.s64 = ctx.r7.s64 + 13032;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r29,r10,1
	ctx.r29.s64 = ctx.r10.s64 + 1;
	// addi r7,r6,13016
	ctx.r7.s64 = ctx.r6.s64 + 13016;
	// lwz r27,1416(r30)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r30.u32 + 1416);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r6,r5,13004
	ctx.r6.s64 = ctx.r5.s64 + 13004;
	// addi r5,r4,12972
	ctx.r5.s64 = ctx.r4.s64 + 12972;
	// addi r4,r3,12952
	ctx.r4.s64 = ctx.r3.s64 + 12952;
	// addi r3,r10,12940
	ctx.r3.s64 = ctx.r10.s64 + 12940;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// rlwinm r29,r29,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,12888
	ctx.r28.s64 = ctx.r10.s64 + 12888;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r30,-32255
	ctx.r30.s64 = -2113863680;
	// addi r23,r10,12860
	ctx.r23.s64 = ctx.r10.s64 + 12860;
	// lwzx r10,r29,r27
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r27.u32);
	// lis r27,-32255
	ctx.r27.s64 = -2113863680;
	// stw r10,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// rotlwi r29,r25,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r25.u32, 0);
	// stw r26,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
	// addi r30,r30,12916
	ctx.r30.s64 = ctx.r30.s64 + 12916;
	// stw r25,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r25.u32);
	// lis r26,-32255
	ctx.r26.s64 = -2113863680;
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// addi r27,r16,12740
	ctx.r27.s64 = ctx.r16.s64 + 12740;
	// lwz r16,80(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lis r18,-32255
	ctx.r18.s64 = -2113863680;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r25,12(r11)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r25,1424(r25)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r25.u32 + 1424);
	// addi r21,r21,12832
	ctx.r21.s64 = ctx.r21.s64 + 12832;
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// rotlwi r27,r29,0
	ctx.r27.u64 = __builtin_rotateleft32(ctx.r29.u32, 0);
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// addi r20,r20,12804
	ctx.r20.s64 = ctx.r20.s64 + 12804;
	// stw r26,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// addi r18,r18,12768
	ctx.r18.s64 = ctx.r18.s64 + 12768;
	// lwzx r10,r10,r25
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r25.u32);
	// stw r9,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// rotlwi r9,r27,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r27.u32, 0);
	// stw r8,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r8.u32);
	// addi r8,r16,12716
	ctx.r8.s64 = ctx.r16.s64 + 12716;
	// stw r7,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r7.u32);
	// mr r22,r9
	ctx.r22.u64 = ctx.r9.u64;
	// stw r10,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// mr r19,r9
	ctx.r19.u64 = ctx.r9.u64;
	// stw r3,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r3.u32);
	// mr r17,r9
	ctx.r17.u64 = ctx.r9.u64;
	// stw r30,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// mr r16,r9
	ctx.r16.u64 = ctx.r9.u64;
	// stw r29,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r29.u32);
	// stw r24,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r24.u32);
	// stw r6,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r6.u32);
	// stw r5,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r5.u32);
	// stw r4,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r4.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r27,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// lwz r6,12(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// rotlwi r4,r26,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r26.u32, 0);
	// stw r8,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r4,12676
	ctx.r3.s64 = ctx.r4.s64 + 12676;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r10,1420(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 1420);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r3,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// lis r29,-32255
	ctx.r29.s64 = -2113863680;
	// stw r8,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// rotlwi r15,r8,0
	ctx.r15.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwzx r10,r5,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stw r27,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r27.u32);
	// lis r30,-32255
	ctx.r30.s64 = -2113863680;
	// stw r28,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r28.u32);
	// lis r26,-32255
	ctx.r26.s64 = -2113863680;
	// lwz r27,88(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// stw r5,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stw r10,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r10.u32);
	// lwz r6,12(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r25,92(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// stw r5,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// stw r8,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// rotlwi r8,r16,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r16.u32, 0);
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// rotlwi r5,r8,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// stw r5,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,1492(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 1492);
	// addi r14,r27,12320
	ctx.r14.s64 = ctx.r27.s64 + 12320;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwzx r10,r3,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// stw r10,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r10.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r22,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r22.u32);
	// addi r4,r10,12536
	ctx.r4.s64 = ctx.r10.s64 + 12536;
	// stw r23,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r23.u32);
	// lis r22,-32255
	ctx.r22.s64 = -2113863680;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lis r23,-32255
	ctx.r23.s64 = -2113863680;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r28,12(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r24,r22,12396
	ctx.r24.s64 = ctx.r22.s64 + 12396;
	// lwz r22,1428(r28)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r28.u32 + 1428);
	// lis r28,-32255
	ctx.r28.s64 = -2113863680;
	// lwzx r10,r10,r22
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r22.u32);
	// addi r22,r3,12296
	ctx.r22.s64 = ctx.r3.s64 + 12296;
	// rotlwi r3,r5,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r10,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r10.u32);
	// stw r20,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r20.u32);
	// addi r10,r25,12216
	ctx.r10.s64 = ctx.r25.s64 + 12216;
	// rotlwi r29,r3,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r19,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r19.u32);
	// lwz r19,96(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// rotlwi r27,r29,0
	ctx.r27.u64 = __builtin_rotateleft32(ctx.r29.u32, 0);
	// lwz r20,80(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r3,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// addi r19,r19,12272
	ctx.r19.s64 = ctx.r19.s64 + 12272;
	// rotlwi r25,r27,0
	ctx.r25.u64 = __builtin_rotateleft32(ctx.r27.u32, 0);
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// stw r21,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r21.u32);
	// addi r20,r20,12352
	ctx.r20.s64 = ctx.r20.s64 + 12352;
	// stw r27,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// lwz r21,12(r11)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r25,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r25.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r21,1432(r21)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r21.u32 + 1432);
	// stw r22,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r22.u32);
	// addi r22,r15,12168
	ctx.r22.s64 = ctx.r15.s64 + 12168;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r24,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r24.u32);
	// std r22,184(r1)
	REX_STORE_U64(ctx.r1.u32 + 184, ctx.r22.u64);
	// addi r9,r9,12648
	ctx.r9.s64 = ctx.r9.s64 + 12648;
	// lwz r24,96(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r7,r7,12616
	ctx.r7.s64 = ctx.r7.s64 + 12616;
	// stw r19,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r19.u32);
	// lis r19,-32255
	ctx.r19.s64 = -2113863680;
	// stw r20,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r20.u32);
	// addi r6,r6,12576
	ctx.r6.s64 = ctx.r6.s64 + 12576;
	// lwzx r10,r10,r21
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r21.u32);
	// lis r21,-32255
	ctx.r21.s64 = -2113863680;
	// stw r17,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r17.u32);
	// addi r30,r30,12508
	ctx.r30.s64 = ctx.r30.s64 + 12508;
	// stw r18,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r18.u32);
	// addi r28,r28,12484
	ctx.r28.s64 = ctx.r28.s64 + 12484;
	// lwz r18,100(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r26,r26,12456
	ctx.r26.s64 = ctx.r26.s64 + 12456;
	// lwz r17,104(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// addi r23,r23,12420
	ctx.r23.s64 = ctx.r23.s64 + 12420;
	// stw r10,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r10.u32);
	// lis r20,-32255
	ctx.r20.s64 = -2113863680;
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lis r15,-32255
	ctx.r15.s64 = -2113863680;
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// stw r18,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r18.u32);
	// lis r18,-32255
	ctx.r18.s64 = -2113863680;
	// stw r17,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r17.u32);
	// lis r17,-32255
	ctx.r17.s64 = -2113863680;
	// stw r24,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r24.u32);
	// rotlwi r24,r25,0
	ctx.r24.u64 = __builtin_rotateleft32(ctx.r25.u32, 0);
	// stw r14,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r14.u32);
	// lis r14,-32255
	ctx.r14.s64 = -2113863680;
	// stw r24,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r24.u32);
	// lwz r22,12(r11)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r22,1436(r22)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r22.u32 + 1436);
	// lwzx r10,r10,r22
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r22.u32);
	// lwz r22,100(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stw r22,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r22.u32);
	// stw r10,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r10.u32);
	// lwz r22,104(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// stw r16,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r16.u32);
	// lis r16,-32255
	ctx.r16.s64 = -2113863680;
	// stw r22,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r22.u32);
	// lwz r22,108(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// stw r22,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r22.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r22,108(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r22,1440(r22)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r22.u32 + 1440);
	// lwzx r10,r10,r22
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r22.u32);
	// stw r10,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r10.u32);
	// stw r9,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r9.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r8,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r8.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r9,r9,12136
	ctx.r9.s64 = ctx.r9.s64 + 12136;
	// addi r8,r8,12120
	ctx.r8.s64 = ctx.r8.s64 + 12120;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r22,108(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r22,1444(r22)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r22.u32 + 1444);
	// lwzx r10,r10,r22
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r22.u32);
	// stw r7,220(r31)
	REX_STORE_U32(ctx.r31.u32 + 220, ctx.r7.u32);
	// addi r7,r21,12096
	ctx.r7.s64 = ctx.r21.s64 + 12096;
	// stw r5,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r5.u32);
	// addi r5,r19,12036
	ctx.r5.s64 = ctx.r19.s64 + 12036;
	// stw r10,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r10.u32);
	// stw r6,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r6.u32);
	// addi r19,r16,11932
	ctx.r19.s64 = ctx.r16.s64 + 11932;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r21,r18,12012
	ctx.r21.s64 = ctx.r18.s64 + 12012;
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// addi r18,r15,11888
	ctx.r18.s64 = ctx.r15.s64 + 11888;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r22,108(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// std r18,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r18.u64);
	// addi r6,r20,12056
	ctx.r6.s64 = ctx.r20.s64 + 12056;
	// addi r20,r17,11980
	ctx.r20.s64 = ctx.r17.s64 + 11980;
	// lwz r15,80(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r17,r14,11860
	ctx.r17.s64 = ctx.r14.s64 + 11860;
	// lwz r14,112(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r16,1448(r22)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r22.u32 + 1448);
	// lwzx r10,r10,r16
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r16.u32);
	// stw r10,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r10.u32);
	// stw r3,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r3.u32);
	// stw r4,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r4.u32);
	// lwz r22,128(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// std r17,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.r17.u64);
	// lwz r16,88(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r17,96(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,1452(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 1452);
	// lwzx r10,r10,r4
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	// stw r10,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r10.u32);
	// stw r30,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r30.u32);
	// lis r30,-32255
	ctx.r30.s64 = -2113863680;
	// stw r29,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r29.u32);
	// lis r29,-32255
	ctx.r29.s64 = -2113863680;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r4,1472(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 1472);
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r3,r4
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// stw r10,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r10.u32);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// stw r28,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r28.u32);
	// lis r28,-32255
	ctx.r28.s64 = -2113863680;
	// stw r27,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r27.u32);
	// lis r27,-32255
	ctx.r27.s64 = -2113863680;
	// lwz r10,120(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// stw r10,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r18,12(r11)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r18,1476(r18)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r18.u32 + 1476);
	// lwzx r10,r10,r18
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r18.u32);
	// stw r10,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r10.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r26,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r26.u32);
	// addi r10,r10,11812
	ctx.r10.s64 = ctx.r10.s64 + 11812;
	// stw r25,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r25.u32);
	// lis r26,-32255
	ctx.r26.s64 = -2113863680;
	// lwz r25,12(r11)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r25,1456(r25)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r25.u32 + 1456);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r25
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// stw r9,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r9.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r8,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r8.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r7,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r7.u32);
	// addi r9,r9,11784
	ctx.r9.s64 = ctx.r9.s64 + 11784;
	// stw r6,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r6.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r11,r11,11836
	ctx.r11.s64 = ctx.r11.s64 + 11836;
	// stw r5,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r5.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// stw r10,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r10.u32);
	// stw r9,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r9.u32);
	// addi r10,r7,11728
	ctx.r10.s64 = ctx.r7.s64 + 11728;
	// addi r9,r6,11704
	ctx.r9.s64 = ctx.r6.s64 + 11704;
	// stw r11,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r11.u32);
	// stw r10,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r10.u32);
	// addi r10,r4,11664
	ctx.r10.s64 = ctx.r4.s64 + 11664;
	// stw r9,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r9.u32);
	// addi r11,r8,11756
	ctx.r11.s64 = ctx.r8.s64 + 11756;
	// addi r9,r3,11648
	ctx.r9.s64 = ctx.r3.s64 + 11648;
	// stw r10,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r10.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stw r11,372(r31)
	REX_STORE_U32(ctx.r31.u32 + 372, ctx.r11.u32);
	// addi r10,r29,11552
	ctx.r10.s64 = ctx.r29.s64 + 11552;
	// stw r9,392(r31)
	REX_STORE_U32(ctx.r31.u32 + 392, ctx.r9.u32);
	// addi r11,r5,11676
	ctx.r11.s64 = ctx.r5.s64 + 11676;
	// stw r16,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r16.u32);
	// addi r9,r28,11532
	ctx.r9.s64 = ctx.r28.s64 + 11532;
	// stw r10,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r10.u32);
	// stw r11,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// addi r10,r26,11456
	ctx.r10.s64 = ctx.r26.s64 + 11456;
	// stw r9,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r9.u32);
	// addi r11,r30,11632
	ctx.r11.s64 = ctx.r30.s64 + 11632;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r10,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r10.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r22,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r22.u32);
	// addi r10,r9,11396
	ctx.r10.s64 = ctx.r9.s64 + 11396;
	// stw r17,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r17.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r16,128(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// addi r11,r27,11484
	ctx.r11.s64 = ctx.r27.s64 + 11484;
	// ld r22,184(r1)
	ctx.r22.u64 = REX_LOAD_U64(ctx.r1.u32 + 184);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// ld r18,176(r1)
	ctx.r18.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// addi r9,r8,11340
	ctx.r9.s64 = ctx.r8.s64 + 11340;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// addi r8,r7,11292
	ctx.r8.s64 = ctx.r7.s64 + 11292;
	// ld r17,168(r1)
	ctx.r17.u64 = REX_LOAD_U64(ctx.r1.u32 + 168);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// stw r10,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r10.u32);
	// addi r7,r6,11236
	ctx.r7.s64 = ctx.r6.s64 + 11236;
	// stw r24,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r24.u32);
	// lis r30,-32255
	ctx.r30.s64 = -2113863680;
	// stw r23,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r23.u32);
	// addi r6,r5,11188
	ctx.r6.s64 = ctx.r5.s64 + 11188;
	// stw r15,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r15.u32);
	// lis r29,-32255
	ctx.r29.s64 = -2113863680;
	// stw r14,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r14.u32);
	// addi r5,r4,11140
	ctx.r5.s64 = ctx.r4.s64 + 11140;
	// stw r16,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r16.u32);
	// addi r4,r3,11088
	ctx.r4.s64 = ctx.r3.s64 + 11088;
	// stw r22,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r22.u32);
	// addi r3,r30,11036
	ctx.r3.s64 = ctx.r30.s64 + 11036;
	// stw r21,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r21.u32);
	// addi r30,r29,10992
	ctx.r30.s64 = ctx.r29.s64 + 10992;
	// stw r20,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r20.u32);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r19,348(r31)
	REX_STORE_U32(ctx.r31.u32 + 348, ctx.r19.u32);
	// stw r18,352(r31)
	REX_STORE_U32(ctx.r31.u32 + 352, ctx.r18.u32);
	// lis r27,-32255
	ctx.r27.s64 = -2113863680;
	// stw r17,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r17.u32);
	// lis r25,-32255
	ctx.r25.s64 = -2113863680;
	// stw r9,424(r31)
	REX_STORE_U32(ctx.r31.u32 + 424, ctx.r9.u32);
	// lis r24,-32255
	ctx.r24.s64 = -2113863680;
	// stw r8,428(r31)
	REX_STORE_U32(ctx.r31.u32 + 428, ctx.r8.u32);
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// stw r7,432(r31)
	REX_STORE_U32(ctx.r31.u32 + 432, ctx.r7.u32);
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// stw r6,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r6.u32);
	// stw r5,440(r31)
	REX_STORE_U32(ctx.r31.u32 + 440, ctx.r5.u32);
	// stw r4,444(r31)
	REX_STORE_U32(ctx.r31.u32 + 444, ctx.r4.u32);
	// stw r3,448(r31)
	REX_STORE_U32(ctx.r31.u32 + 448, ctx.r3.u32);
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// stw r30,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r30.u32);
	// stw r11,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r11.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r28,460(r31)
	REX_STORE_U32(ctx.r31.u32 + 460, ctx.r28.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r29,456(r31)
	REX_STORE_U32(ctx.r31.u32 + 456, ctx.r29.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r9,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stw r7,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// stw r6,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// stw r5,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r4,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// stw r3,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r8,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// stw r9,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r9.u32);
	// rotlwi r4,r8,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r7,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// stw r6,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r6.u32);
	// rotlwi r9,r29,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r29.u32, 0);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r10,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// stw r8,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r8.u32);
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
	// stw r7,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r7.u32);
	// mr r23,r10
	ctx.r23.u64 = ctx.r10.u64;
	// stw r6,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r6.u32);
	// addi r27,r27,10948
	ctx.r27.s64 = ctx.r27.s64 + 10948;
	// stw r26,468(r31)
	REX_STORE_U32(ctx.r31.u32 + 468, ctx.r26.u32);
	// addi r25,r25,10920
	ctx.r25.s64 = ctx.r25.s64 + 10920;
	// stw r23,480(r31)
	REX_STORE_U32(ctx.r31.u32 + 480, ctx.r23.u32);
	// lis r22,-32255
	ctx.r22.s64 = -2113863680;
	// stw r27,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r27.u32);
	// lis r20,-32255
	ctx.r20.s64 = -2113863680;
	// stw r25,472(r31)
	REX_STORE_U32(ctx.r31.u32 + 472, ctx.r25.u32);
	// lis r19,-32255
	ctx.r19.s64 = -2113863680;
	// lwz r27,120(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lis r18,-32255
	ctx.r18.s64 = -2113863680;
	// lwz r26,112(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r25,108(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lwz r23,104(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// addi r28,r4,10260
	ctx.r28.s64 = ctx.r4.s64 + 10260;
	// stw r5,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r5.u32);
	// addi r24,r24,10896
	ctx.r24.s64 = ctx.r24.s64 + 10896;
	// stw r3,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r3.u32);
	// lis r21,-32255
	ctx.r21.s64 = -2113863680;
	// lis r17,-32255
	ctx.r17.s64 = -2113863680;
	// stw r24,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r24.u32);
	// lis r16,-32255
	ctx.r16.s64 = -2113863680;
	// rotlwi r4,r9,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// addi r11,r22,10856
	ctx.r11.s64 = ctx.r22.s64 + 10856;
	// lwz r22,100(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r8,r20,10780
	ctx.r8.s64 = ctx.r20.s64 + 10780;
	// lwz r20,96(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r7,r19,10756
	ctx.r7.s64 = ctx.r19.s64 + 10756;
	// lwz r19,92(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// addi r6,r18,10728
	ctx.r6.s64 = ctx.r18.s64 + 10728;
	// lwz r18,88(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lis r15,-32255
	ctx.r15.s64 = -2113863680;
	// stw r4,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r4.u32);
	// lis r14,-32255
	ctx.r14.s64 = -2113863680;
	// addi r10,r21,10828
	ctx.r10.s64 = ctx.r21.s64 + 10828;
	// addi r5,r17,10648
	ctx.r5.s64 = ctx.r17.s64 + 10648;
	// addi r3,r16,10612
	ctx.r3.s64 = ctx.r16.s64 + 10612;
	// addi r29,r14,10556
	ctx.r29.s64 = ctx.r14.s64 + 10556;
	// lwz r14,156(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// addi r26,r26,10496
	ctx.r26.s64 = ctx.r26.s64 + 10496;
	// lwz r24,136(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// stw r28,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// addi r28,r27,10532
	ctx.r28.s64 = ctx.r27.s64 + 10532;
	// lwz r17,144(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// addi r14,r14,10112
	ctx.r14.s64 = ctx.r14.s64 + 10112;
	// std r26,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r26.u64);
	// addi r24,r24,10236
	ctx.r24.s64 = ctx.r24.s64 + 10236;
	// lwz r26,160(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// addi r17,r17,10208
	ctx.r17.s64 = ctx.r17.s64 + 10208;
	// stw r14,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r14.u32);
	// lis r14,-32255
	ctx.r14.s64 = -2113863680;
	// std r28,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r28.u64);
	// addi r30,r15,10580
	ctx.r30.s64 = ctx.r15.s64 + 10580;
	// std r29,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r29.u64);
	// rotlwi r27,r4,0
	ctx.r27.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// lwz r29,176(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r26,r26,10092
	ctx.r26.s64 = ctx.r26.s64 + 10092;
	// lwz r28,168(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// rotlwi r21,r27,0
	ctx.r21.u64 = __builtin_rotateleft32(ctx.r27.u32, 0);
	// stw r24,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r24.u32);
	// addi r29,r29,9968
	ctx.r29.s64 = ctx.r29.s64 + 9968;
	// stw r17,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r17.u32);
	// addi r28,r28,9992
	ctx.r28.s64 = ctx.r28.s64 + 9992;
	// lwz r15,152(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// addi r25,r25,10460
	ctx.r25.s64 = ctx.r25.s64 + 10460;
	// stw r14,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r14.u32);
	// lis r14,-32255
	ctx.r14.s64 = -2113863680;
	// addi r15,r15,10176
	ctx.r15.s64 = ctx.r15.s64 + 10176;
	// stw r27,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r27.u32);
	// std r27,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r27.u64);
	// mr r24,r21
	ctx.r24.u64 = ctx.r21.u64;
	// lwz r27,164(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// addi r23,r23,10428
	ctx.r23.s64 = ctx.r23.s64 + 10428;
	// lwz r16,80(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r22,r22,10400
	ctx.r22.s64 = ctx.r22.s64 + 10400;
	// stw r14,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r14.u32);
	// lis r14,-32255
	ctx.r14.s64 = -2113863680;
	// stw r15,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r15.u32);
	// addi r27,r27,10024
	ctx.r27.s64 = ctx.r27.s64 + 10024;
	// std r30,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r30.u64);
	// lis r15,-32255
	ctx.r15.s64 = -2113863680;
	// lwz r30,184(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// addi r20,r20,10356
	ctx.r20.s64 = ctx.r20.s64 + 10356;
	// stw r21,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r21.u32);
	// addi r19,r19,10324
	ctx.r19.s64 = ctx.r19.s64 + 10324;
	// stw r14,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r14.u32);
	// addi r18,r18,10300
	ctx.r18.s64 = ctx.r18.s64 + 10300;
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// lis r27,-32255
	ctx.r27.s64 = -2113863680;
	// stw r28,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// addi r16,r16,10280
	ctx.r16.s64 = ctx.r16.s64 + 10280;
	// stw r27,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r27.u32);
	// lis r27,-32255
	ctx.r27.s64 = -2113863680;
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// addi r30,r30,9944
	ctx.r30.s64 = ctx.r30.s64 + 9944;
	// stw r27,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r27.u32);
	// lis r14,-32255
	ctx.r14.s64 = -2113863680;
	// lwz r29,120(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r28,176(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r27,168(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// stw r15,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r15.u32);
	// lis r15,-32255
	ctx.r15.s64 = -2113863680;
	// stw r26,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r26.u32);
	// rotlwi r26,r21,0
	ctx.r26.u64 = __builtin_rotateleft32(ctx.r21.u32, 0);
	// stw r15,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r15.u32);
	// lis r15,-32255
	ctx.r15.s64 = -2113863680;
	// stw r21,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r21.u32);
	// mr r17,r26
	ctx.r17.u64 = ctx.r26.u64;
	// stw r27,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// stw r15,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r15.u32);
	// stw r26,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r26.u32);
	// lwz r27,164(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// lwz r15,184(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// stw r27,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r27.u32);
	// rotlwi r27,r21,0
	ctx.r27.u64 = __builtin_rotateleft32(ctx.r21.u32, 0);
	// stw r27,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r27.u32);
	// stw r15,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r15.u32);
	// lis r15,-32255
	ctx.r15.s64 = -2113863680;
	// stw r9,492(r31)
	REX_STORE_U32(ctx.r31.u32 + 492, ctx.r9.u32);
	// lwz r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// stw r10,488(r31)
	REX_STORE_U32(ctx.r31.u32 + 488, ctx.r10.u32);
	// addi r9,r9,9892
	ctx.r9.s64 = ctx.r9.s64 + 9892;
	// lwz r10,176(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// stw r29,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r29.u32);
	// std r9,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// addi r10,r10,9924
	ctx.r10.s64 = ctx.r10.s64 + 9924;
	// lwz r9,184(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// stw r30,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r30.u32);
	// ld r29,192(r1)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r1.u32 + 192);
	// stw r28,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r28.u32);
	// lwz r27,160(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// stw r8,496(r31)
	REX_STORE_U32(ctx.r31.u32 + 496, ctx.r8.u32);
	// stw r6,504(r31)
	REX_STORE_U32(ctx.r31.u32 + 504, ctx.r6.u32);
	// stw r29,524(r31)
	REX_STORE_U32(ctx.r31.u32 + 524, ctx.r29.u32);
	// addi r29,r9,9728
	ctx.r29.s64 = ctx.r9.s64 + 9728;
	// lwz r8,128(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// stw r27,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r27.u32);
	// lwz r27,156(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// addi r8,r8,9860
	ctx.r8.s64 = ctx.r8.s64 + 9860;
	// lwz r6,120(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// stw r7,500(r31)
	REX_STORE_U32(ctx.r31.u32 + 500, ctx.r7.u32);
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// stw r11,484(r31)
	REX_STORE_U32(ctx.r31.u32 + 484, ctx.r11.u32);
	// addi r6,r6,9852
	ctx.r6.s64 = ctx.r6.s64 + 9852;
	// stw r4,512(r31)
	REX_STORE_U32(ctx.r31.u32 + 512, ctx.r4.u32);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r27,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r27.u32);
	// rotlwi r27,r26,0
	ctx.r27.u64 = __builtin_rotateleft32(ctx.r26.u32, 0);
	// ld r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// stw r27,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r27.u32);
	// ld r27,208(r1)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r1.u32 + 208);
	// ld r28,200(r1)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r1.u32 + 200);
	// ld r26,216(r1)
	ctx.r26.u64 = REX_LOAD_U64(ctx.r1.u32 + 216);
	// lwz r9,184(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// std r7,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r7.u64);
	// lwz r7,112(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// std r8,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r8.u64);
	// std r6,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// stw r9,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
	// lwz r9,176(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r8,108(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r6,104(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// stw r27,532(r31)
	REX_STORE_U32(ctx.r31.u32 + 532, ctx.r27.u32);
	// addi r27,r15,9680
	ctx.r27.s64 = ctx.r15.s64 + 9680;
	// stw r5,508(r31)
	REX_STORE_U32(ctx.r31.u32 + 508, ctx.r5.u32);
	// addi r5,r7,9824
	ctx.r5.s64 = ctx.r7.s64 + 9824;
	// stw r9,580(r31)
	REX_STORE_U32(ctx.r31.u32 + 580, ctx.r9.u32);
	// lwz r9,168(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// stw r3,516(r31)
	REX_STORE_U32(ctx.r31.u32 + 516, ctx.r3.u32);
	// addi r3,r8,9792
	ctx.r3.s64 = ctx.r8.s64 + 9792;
	// stw r30,520(r31)
	REX_STORE_U32(ctx.r31.u32 + 520, ctx.r30.u32);
	// addi r30,r6,9756
	ctx.r30.s64 = ctx.r6.s64 + 9756;
	// stw r28,528(r31)
	REX_STORE_U32(ctx.r31.u32 + 528, ctx.r28.u32);
	// addi r28,r14,9712
	ctx.r28.s64 = ctx.r14.s64 + 9712;
	// lwz r15,100(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stw r9,584(r31)
	REX_STORE_U32(ctx.r31.u32 + 584, ctx.r9.u32);
	// lwz r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// stw r26,536(r31)
	REX_STORE_U32(ctx.r31.u32 + 536, ctx.r26.u32);
	// stw r25,540(r31)
	REX_STORE_U32(ctx.r31.u32 + 540, ctx.r25.u32);
	// stw r24,544(r31)
	REX_STORE_U32(ctx.r31.u32 + 544, ctx.r24.u32);
	// stw r23,548(r31)
	REX_STORE_U32(ctx.r31.u32 + 548, ctx.r23.u32);
	// stw r9,588(r31)
	REX_STORE_U32(ctx.r31.u32 + 588, ctx.r9.u32);
	// lwz r9,164(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// stw r22,552(r31)
	REX_STORE_U32(ctx.r31.u32 + 552, ctx.r22.u32);
	// stw r21,556(r31)
	REX_STORE_U32(ctx.r31.u32 + 556, ctx.r21.u32);
	// stw r20,560(r31)
	REX_STORE_U32(ctx.r31.u32 + 560, ctx.r20.u32);
	// stw r19,564(r31)
	REX_STORE_U32(ctx.r31.u32 + 564, ctx.r19.u32);
	// stw r9,592(r31)
	REX_STORE_U32(ctx.r31.u32 + 592, ctx.r9.u32);
	// lwz r9,136(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// stw r18,568(r31)
	REX_STORE_U32(ctx.r31.u32 + 568, ctx.r18.u32);
	// stw r17,572(r31)
	REX_STORE_U32(ctx.r31.u32 + 572, ctx.r17.u32);
	// stw r16,576(r31)
	REX_STORE_U32(ctx.r31.u32 + 576, ctx.r16.u32);
	// stw r9,596(r31)
	REX_STORE_U32(ctx.r31.u32 + 596, ctx.r9.u32);
	// lwz r9,160(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// stw r9,600(r31)
	REX_STORE_U32(ctx.r31.u32 + 600, ctx.r9.u32);
	// lwz r9,156(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// stw r9,604(r31)
	REX_STORE_U32(ctx.r31.u32 + 604, ctx.r9.u32);
	// lwz r9,152(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// stw r9,608(r31)
	REX_STORE_U32(ctx.r31.u32 + 608, ctx.r9.u32);
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// lwz r26,92(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r25,88(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r24,184(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// ld r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// ld r8,128(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// ld r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// stw r28,672(r31)
	REX_STORE_U32(ctx.r31.u32 + 672, ctx.r28.u32);
	// lwz r28,420(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 420);
	// stw r15,612(r31)
	REX_STORE_U32(ctx.r31.u32 + 612, ctx.r15.u32);
	// stw r26,616(r31)
	REX_STORE_U32(ctx.r31.u32 + 616, ctx.r26.u32);
	// stw r25,620(r31)
	REX_STORE_U32(ctx.r31.u32 + 620, ctx.r25.u32);
	// stw r24,624(r31)
	REX_STORE_U32(ctx.r31.u32 + 624, ctx.r24.u32);
	// stw r11,628(r31)
	REX_STORE_U32(ctx.r31.u32 + 628, ctx.r11.u32);
	// stw r10,632(r31)
	REX_STORE_U32(ctx.r31.u32 + 632, ctx.r10.u32);
	// stw r9,636(r31)
	REX_STORE_U32(ctx.r31.u32 + 636, ctx.r9.u32);
	// stw r8,640(r31)
	REX_STORE_U32(ctx.r31.u32 + 640, ctx.r8.u32);
	// stw r7,644(r31)
	REX_STORE_U32(ctx.r31.u32 + 644, ctx.r7.u32);
	// stw r6,648(r31)
	REX_STORE_U32(ctx.r31.u32 + 648, ctx.r6.u32);
	// stw r5,652(r31)
	REX_STORE_U32(ctx.r31.u32 + 652, ctx.r5.u32);
	// stw r4,656(r31)
	REX_STORE_U32(ctx.r31.u32 + 656, ctx.r4.u32);
	// stw r3,660(r31)
	REX_STORE_U32(ctx.r31.u32 + 660, ctx.r3.u32);
	// stw r30,664(r31)
	REX_STORE_U32(ctx.r31.u32 + 664, ctx.r30.u32);
	// stw r29,668(r31)
	REX_STORE_U32(ctx.r31.u32 + 668, ctx.r29.u32);
	// stw r27,676(r31)
	REX_STORE_U32(ctx.r31.u32 + 676, ctx.r27.u32);
loc_8205C320:
	// lis r30,-32215
	ctx.r30.s64 = -2111242240;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r29,1
	ctx.r29.s64 = 1;
	// lhz r11,-22664(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + -22664);
	// lfs f31,17916(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17916);
	ctx.f31.f64 = double(temp.f32);
	// lfs f29,9748(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9748);
	ctx.f29.f64 = double(temp.f32);
	// lfs f30,9744(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9744);
	ctx.f30.f64 = double(temp.f32);
loc_8205C344:
	// addi r10,r29,5
	ctx.r10.s64 = ctx.r29.s64 + 5;
	// lwz r9,48(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfs f13,8(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// fcmpu cr6,f13,f30
	ctx.cr6.compare(ctx.f13.f64, ctx.f30.f64);
	// bge cr6,0x8205c3ac
	if (!ctx.cr6.lt) goto loc_8205C3AC;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// stfs f29,8(r3)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,170
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 170, ctx.xer);
	// bge cr6,0x8205c38c
	if (!ctx.cr6.lt) goto loc_8205C38C;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// bl 0x82067518
	ctx.lr = 0x8205C388;
	sub_82067518(ctx, base);
	// b 0x8205c394
	goto loc_8205C394;
loc_8205C38C:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82067230
	ctx.lr = 0x8205C394;
	sub_82067230(ctx, base);
loc_8205C394:
	// lhz r11,-22664(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + -22664);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r11,-22664(r30)
	REX_STORE_U16(ctx.r30.u32 + -22664, ctx.r11.u16);
	// cmplwi cr6,r11,180
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 180, ctx.xer);
	// bgt cr6,0x8205c3d4
	if (ctx.cr6.gt) goto loc_8205C3D4;
loc_8205C3AC:
	// addi r10,r29,1
	ctx.r10.s64 = ctx.r29.s64 + 1;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// ble cr6,0x8205c344
	if (!ctx.cr6.gt) goto loc_8205C344;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -176);
	// lfd f30,-168(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
loc_8205C3D4:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// sth r11,-22664(r30)
	REX_STORE_U16(ctx.r30.u32 + -22664, ctx.r11.u16);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8205C3E8;
	sub_82053BC8(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -176);
	// lfd f30,-168(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
