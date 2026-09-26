DEFINE_REX_FUNC(sub_820B93B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x820B93B8;
	__savegprlr_21(ctx, base);
	// addi r31,r1,-272
	ctx.r31.s64 = ctx.r1.s64 + -272;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// stw r24,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r24.u32);
	// li r22,0
	ctx.r22.s64 = 0;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r22,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r22.u32);
	// stw r29,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r29.u32);
	// mr r21,r7
	ctx.r21.u64 = ctx.r7.u64;
	// stw r5,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r5.u32);
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// stw r6,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r6.u32);
	// stw r21,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r21.u32);
	// addi r10,r31,128
	ctx.r10.s64 = ctx.r31.s64 + 128;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// li r11,6
	ctx.r11.s64 = 6;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820B93FC:
	// std r9,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x820b93fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820B93FC;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820b9474
	if (ctx.cr6.eq) goto loc_820B9474;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,48
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 48, ctx.xer);
	// bne cr6,0x820b9438
	if (!ctx.cr6.eq) goto loc_820B9438;
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// addi r3,r31,128
	ctx.r3.s64 = ctx.r31.s64 + 128;
	// bl 0x8212a760
	ctx.lr = 0x820B9434;
	sub_8212A760(ctx, base);
	// lwz r5,308(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
loc_820B9438:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x820b9460
	goto loc_820B9460;
loc_820B9460:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x820b9470
	if (!ctx.cr6.lt) goto loc_820B9470;
loc_820B9468:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820b993c
	goto loc_820B993C;
loc_820B9470:
	// lwz r6,316(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
loc_820B9474:
	// lis r23,-32215
	ctx.r23.s64 = -2111242240;
	// lwz r11,2880(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 2880);
	// rlwinm. r11,r11,0,10,10
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820b9488
	if (ctx.cr0.eq) goto loc_820B9488;
	// ori r24,r24,128
	ctx.r24.u64 = ctx.r24.u64 | 128;
loc_820B9488:
	// lwz r11,132(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b94a0
	if (!ctx.cr6.eq) goto loc_820B94A0;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r11,240(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 240);
	// stw r11,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
loc_820B94A0:
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b94b8
	if (!ctx.cr6.eq) goto loc_820B94B8;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r11,244(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 244);
	// stw r11,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
loc_820B94B8:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b94d0
	if (!ctx.cr6.eq) goto loc_820B94D0;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r11,252(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 252);
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
loc_820B94D0:
	// lwz r11,144(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b94e8
	if (!ctx.cr6.eq) goto loc_820B94E8;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r11,248(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 248);
	// stw r11,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r11.u32);
loc_820B94E8:
	// lwz r11,148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b9500
	if (!ctx.cr6.eq) goto loc_820B9500;
	// lis r11,32764
	ctx.r11.s64 = 2147221504;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
loc_820B9500:
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b9518
	if (ctx.cr6.eq) goto loc_820B9518;
	// lis r10,15
	ctx.r10.s64 = 983040;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820b9520
	if (!ctx.cr6.gt) goto loc_820B9520;
loc_820B9518:
	// lis r11,15
	ctx.r11.s64 = 983040;
	// stw r11,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
loc_820B9520:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// lis r30,1
	ctx.r30.s64 = 65536;
	// bne cr6,0x820b9578
	if (!ctx.cr6.eq) goto loc_820B9578;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r30,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r30.u32);
	// bne cr6,0x820b9548
	if (!ctx.cr6.eq) goto loc_820B9548;
	// lis r11,64
	ctx.r11.s64 = 4194304;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r27,r10,65535
	ctx.r27.u64 = ctx.r10.u64 | 65535;
	// b 0x820b9558
	goto loc_820B9558;
loc_820B9548:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r27,r11,65535
	ctx.r27.u64 = ctx.r11.u64 | 65535;
loc_820B9550:
	// add r11,r5,r27
	ctx.r11.u64 = ctx.r5.u64 + ctx.r27.u64;
	// rlwinm r11,r11,0,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
loc_820B9558:
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// clrlwi. r11,r24,31
	ctx.r11.u64 = ctx.r24.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r25,1424
	ctx.r25.s64 = 1424;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// bne 0x820b95b0
	if (!ctx.cr0.eq) goto loc_820B95B0;
	// beq cr6,0x820b95a4
	if (ctx.cr6.eq) goto loc_820B95A4;
	// oris r24,r24,32768
	ctx.r24.u64 = ctx.r24.u64 | 2147483648;
	// b 0x820b95b4
	goto loc_820B95B4;
loc_820B9578:
	// lis r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// ori r27,r11,65535
	ctx.r27.u64 = ctx.r11.u64 | 65535;
	// add r11,r6,r27
	ctx.r11.u64 = ctx.r6.u64 + ctx.r27.u64;
	// rlwinm r11,r11,0,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r11.u32);
	// bne cr6,0x820b9550
	if (!ctx.cr6.eq) goto loc_820B9550;
	// addis r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 1048576;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r11,r11,0,0,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFF00000;
	// b 0x820b9558
	goto loc_820B9558;
loc_820B95A4:
	// li r25,1452
	ctx.r25.s64 = 1452;
	// li r21,-1
	ctx.r21.s64 = -1;
	// b 0x820b95b4
	goto loc_820B95B4;
loc_820B95B0:
	// bne cr6,0x820b9468
	if (!ctx.cr6.eq) goto loc_820B9468;
loc_820B95B4:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// beq cr6,0x820b96bc
	if (ctx.cr6.eq) goto loc_820B96BC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b9610
	if (ctx.cr6.eq) goto loc_820B9610;
	// lwz r10,156(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820b9468
	if (ctx.cr6.eq) goto loc_820B9468;
	// lwz r11,160(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b9468
	if (ctx.cr6.eq) goto loc_820B9468;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820b9468
	if (ctx.cr6.gt) goto loc_820B9468;
	// rlwinm. r9,r24,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820b9468
	if (!ctx.cr0.eq) goto loc_820B9468;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// stw r29,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r29.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// add r28,r10,r29
	ctx.r28.u64 = ctx.r10.u64 + ctx.r29.u64;
	// bl 0x82129fa0
	ctx.lr = 0x820B960C;
	sub_82129FA0(ctx, base);
	// b 0x820b96ac
	goto loc_820B96AC;
loc_820B9610:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,96
	ctx.r4.s64 = ctx.r31.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214a714
	ctx.lr = 0x820B9620;
	__imp__NtQueryVirtualMemory(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820b9468
	if (ctx.cr0.lt) goto loc_820B9468;
	// lwz r3,96(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmplw cr6,r3,r29
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820b9468
	if (!ctx.cr6.eq) goto loc_820B9468;
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820b9468
	if (ctx.cr6.eq) goto loc_820B9468;
	// stw r3,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// bne cr6,0x820b96a4
	if (!ctx.cr6.eq) goto loc_820B96A4;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82129fa0
	ctx.lr = 0x820B9658;
	sub_82129FA0(ctx, base);
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,96
	ctx.r4.s64 = ctx.r31.s64 + 96;
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r11.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214a714
	ctx.lr = 0x820B9678;
	__imp__NtQueryVirtualMemory(ctx, base);
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// blt 0x820b96ac
	if (ctx.cr0.lt) goto loc_820B96AC;
	// lwz r10,112(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmplwi cr6,r10,8192
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8192, ctx.xer);
	// bne cr6,0x820b96ac
	if (!ctx.cr6.eq) goto loc_820B96AC;
	// lwz r10,108(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// b 0x820b96ac
	goto loc_820B96AC;
loc_820B96A4:
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stw r30,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r30.u32);
loc_820B96AC:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// li r26,1
	ctx.r26.s64 = 1;
	// stw r10,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// b 0x820b9708
	goto loc_820B9708;
loc_820B96BC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b9468
	if (!ctx.cr6.eq) goto loc_820B9468;
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,8192
	ctx.r5.u64 = ctx.r5.u64 | 8192;
	// addi r4,r31,308
	ctx.r4.s64 = ctx.r31.s64 + 308;
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// bl 0x8214a6b4
	ctx.lr = 0x820B96E0;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820b9468
	if (ctx.cr0.lt) goto loc_820B9468;
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b96fc
	if (!ctx.cr6.eq) goto loc_820B96FC;
	// stw r30,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r30.u32);
loc_820B96FC:
	// lwz r10,80(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// stw r10,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
loc_820B9708:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x820b9768
	if (!ctx.cr6.eq) goto loc_820B9768;
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,4096
	ctx.r5.u64 = ctx.r5.u64 | 4096;
	// addi r4,r31,316
	ctx.r4.s64 = ctx.r31.s64 + 316;
	// addi r3,r31,84
	ctx.r3.s64 = ctx.r31.s64 + 84;
	// bl 0x8214a6b4
	ctx.lr = 0x820B9730;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x820b975c
	if (!ctx.cr0.lt) goto loc_820B975C;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820b9468
	if (!ctx.cr6.eq) goto loc_820B9468;
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// addi r4,r31,308
	ctx.r4.s64 = ctx.r31.s64 + 308;
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// bl 0x8214a6f4
	ctx.lr = 0x820B9758;
	__imp__NtFreeVirtualMemory(ctx, base);
	// b 0x820b9468
	goto loc_820B9468;
loc_820B975C:
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// lwz r10,80(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// add r28,r28,r11
	ctx.r28.u64 = ctx.r28.u64 + ctx.r11.u64;
loc_820B9768:
	// addi r11,r10,1431
	ctx.r11.s64 = ctx.r10.s64 + 1431;
	// li r8,8
	ctx.r8.s64 = 8;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r9,r25,128
	ctx.r9.s64 = ctx.r25.s64 + 128;
	// addi r10,r10,76
	ctx.r10.s64 = ctx.r10.s64 + 76;
loc_820B977C:
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bne 0x820b977c
	if (!ctx.cr0.eq) goto loc_820B977C;
	// stw r22,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r22.u32);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// lwz r10,2880(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 2880);
	// rlwinm. r10,r10,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820b97c4
	if (ctx.cr0.eq) goto loc_820B97C4;
	// lwz r10,80(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// addi r9,r9,1548
	ctx.r9.s64 = ctx.r9.s64 + 1548;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stw r11,380(r10)
	REX_STORE_U32(ctx.r10.u32 + 380, ctx.r11.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,380(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 380);
	// addi r29,r11,1548
	ctx.r29.s64 = ctx.r11.s64 + 1548;
loc_820B97C4:
	// addi r11,r9,15
	ctx.r11.s64 = ctx.r9.s64 + 15;
	// lwz r10,80(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lis r9,-4353
	ctx.r9.s64 = -285278208;
	// rlwinm r30,r11,0,0,27
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// li r11,1
	ctx.r11.s64 = 1;
	// rlwinm r8,r30,28,16,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 28) & 0xFFFF;
	// ori r9,r9,61183
	ctx.r9.u64 = ctx.r9.u64 | 61183;
	// sth r8,0(r10)
	REX_STORE_U16(ctx.r10.u32 + 0, ctx.r8.u16);
	// lis r12,24577
	ctx.r12.s64 = 1610678272;
	// ori r12,r12,125
	ctx.r12.u64 = ctx.r12.u64 | 125;
	// and r10,r24,r12
	ctx.r10.u64 = ctx.r24.u64 & ctx.r12.u64;
	// lwz r8,80(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// stb r11,5(r8)
	REX_STORE_U8(ctx.r8.u32 + 5, ctx.r11.u8);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// stw r9,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// stw r24,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r24.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// stw r10,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// sth r27,368(r11)
	REX_STORE_U16(ctx.r11.u32 + 368, ctx.r27.u16);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// subf r10,r11,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r11.u64;
	// sth r10,58(r11)
	REX_STORE_U16(ctx.r11.u32 + 58, ctx.r10.u16);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// stw r22,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r22.u32);
	// bl 0x8214a6e4
	ctx.lr = 0x820B9830;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// li r10,128
	ctx.r10.s64 = 128;
	// stb r3,379(r11)
	REX_STORE_U8(ctx.r11.u32 + 379, ctx.r3.u8);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// addi r11,r11,384
	ctx.r11.s64 = ctx.r11.s64 + 384;
loc_820B9844:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bne 0x820b9844
	if (!ctx.cr0.eq) goto loc_820B9844;
	// lwz r10,80(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r21,-1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, -1, ctx.xer);
	// addi r11,r10,88
	ctx.r11.s64 = ctx.r10.s64 + 88;
	// stw r11,88(r10)
	REX_STORE_U32(ctx.r10.u32 + 88, ctx.r11.u32);
	// stw r11,92(r10)
	REX_STORE_U32(ctx.r10.u32 + 92, ctx.r11.u32);
	// bne cr6,0x820b987c
	if (!ctx.cr6.eq) goto loc_820B987C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r21,r29
	ctx.r21.u64 = ctx.r29.u64;
	// bl 0x8214a424
	ctx.lr = 0x820B987C;
	__imp__RtlInitializeCriticalSection(ctx, base);
loc_820B987C:
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r21,1408(r11)
	REX_STORE_U32(ctx.r11.u32 + 1408, ctx.r21.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r7,84(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r4,r30,r3
	ctx.r4.u64 = ctx.r30.u64 + ctx.r3.u64;
	// bl 0x820b8ca0
	ctx.lr = 0x820B98A8;
	sub_820B8CA0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820b9468
	if (ctx.cr0.eq) goto loc_820B9468;
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// rlwinm. r10,r24,0,15,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x10000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sth r22,56(r11)
	REX_STORE_U16(ctx.r11.u32 + 56, ctx.r22.u16);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// stw r10,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// stw r10,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,144(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r10,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r10.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,148(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// stw r10,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r10.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,152(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// addi r10,r10,15
	ctx.r10.s64 = ctx.r10.s64 + 15;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r10,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,164(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// stw r10,1412(r11)
	REX_STORE_U32(ctx.r11.u32 + 1412, ctx.r10.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// li r10,31
	ctx.r10.s64 = 31;
	// li r9,-16
	ctx.r9.s64 = -16;
	// stw r10,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r10.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// stw r9,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r9.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
loc_820B993C:
	// addi r1,r31,272
	ctx.r1.s64 = ctx.r31.s64 + 272;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
