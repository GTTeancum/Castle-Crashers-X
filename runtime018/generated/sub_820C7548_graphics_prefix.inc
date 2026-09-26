DEFINE_REX_FUNC(sub_820C7548_graphics_prefix) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820C7550;
	__savegprlr_24(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lwz r11,10908(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10908);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c7594
	if (ctx.cr6.eq) goto loc_820C7594;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c7594
	if (ctx.cr6.eq) goto loc_820C7594;
	// bl 0x820c74d0
	ctx.lr = 0x820C7578;
	sub_820C74D0(ctx, base);
	// b 0x820c7584
	goto loc_820C7584;
loc_820C757C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x820b6068
	ctx.lr = 0x820C7584;
	sub_820B6068(ctx, base);
loc_820C7584:
	// lwz r10,10984(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 10984);
	// lwz r11,10988(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10988);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x820c757c
	if (!ctx.cr6.eq) goto loc_820C757C;
loc_820C7594:
	// lwz r11,14904(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14904);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c75e0
	if (ctx.cr6.eq) goto loc_820C75E0;
	// lwz r8,14908(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 14908);
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r9,r11,3
	ctx.r9.u64 = ctx.r11.u32 & 0x1FFFFFFF;
	// rlwinm r11,r8,12,20,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0xFFF;
	// addi r7,r10,512
	ctx.r7.s64 = ctx.r10.s64 + 512;
	// addi r10,r11,512
	ctx.r10.s64 = ctx.r11.s64 + 512;
	// clrlwi r11,r8,3
	ctx.r11.u64 = ctx.r8.u32 & 0x1FFFFFFF;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// rlwinm r8,r7,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r7,16384
	ctx.r7.s64 = 1073741824;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// subf r4,r7,r11
	ctx.r4.u64 = ctx.r11.u64 - ctx.r7.u64;
	// subf r3,r7,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r7.u64;
	// bl 0x820d6470
	ctx.lr = 0x820C75E0;
	sub_820D6470(ctx, base);
loc_820C75E0:
	// lis r30,-20096
	ctx.r30.s64 = -1317011456;
	// lwz r3,14836(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 14836);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82136708
	ctx.lr = 0x820C75F0;
	sub_82136708(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,14840(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 14840);
	// bl 0x82136708
	ctx.lr = 0x820C75FC;
	sub_82136708(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r29,14836(r31)
	REX_STORE_U32(ctx.r31.u32 + 14836, ctx.r29.u32);
	// stw r29,14840(r31)
	REX_STORE_U32(ctx.r31.u32 + 14840, ctx.r29.u32);
	// stw r29,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r29.u32);
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// bl 0x8214a7f4
	ctx.lr = 0x820C7618;
	__imp__VdSetSystemCommandBufferGpuIdentifierAddress(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,10900(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10900);
	// bl 0x82136708
	ctx.lr = 0x820C7624;
	sub_82136708(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,10896(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// bl 0x82136708
	ctx.lr = 0x820C7630;
	sub_82136708(ctx, base);
	// stw r29,10900(r31)
	REX_STORE_U32(ctx.r31.u32 + 10900, ctx.r29.u32);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// stw r29,10896(r31)
	REX_STORE_U32(ctx.r31.u32 + 10896, ctx.r29.u32);
	// bne cr6,0x820c7648
	if (!ctx.cr6.eq) goto loc_820C7648;
loc_820C7640:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820c797c
	goto loc_820C797C;
loc_820C7648:
	// lwz r25,4(r26)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// lwz r27,8(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lwz r28,12(r26)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// lwz r30,16(r26)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
	// lwz r11,20(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 20);
	// bne cr6,0x820c766c
	if (!ctx.cr6.eq) goto loc_820C766C;
	// lis r25,0
	ctx.r25.s64 = 0;
	// ori r25,r25,32768
	ctx.r25.u64 = ctx.r25.u64 | 32768;
loc_820C766C:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x820c7678
	if (!ctx.cr6.eq) goto loc_820C7678;
	// lis r28,32
	ctx.r28.s64 = 2097152;
loc_820C7678:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820c7684
	if (!ctx.cr6.eq) goto loc_820C7684;
	// li r11,32
	ctx.r11.s64 = 32;
loc_820C7684:
	// divwu r26,r28,r11
	ctx.r26.u64 = uint32_t(ctx.r11.u32 ? ctx.r28.u32 / ctx.r11.u32 : 0);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x820c76a8
	if (!ctx.cr6.eq) goto loc_820C76A8;
	// lis r4,-19072
	ctx.r4.s64 = -1249902592;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82136670
	ctx.lr = 0x820C76A0;
	sub_82136670(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stw r27,14836(r31)
	REX_STORE_U32(ctx.r31.u32 + 14836, ctx.r27.u32);
loc_820C76A8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820c76d4
	if (!ctx.cr6.eq) goto loc_820C76D4;
	// lis r11,8
	ctx.r11.s64 = 524288;
	// lis r4,-30848
	ctx.r4.s64 = -2021654528;
	// subfc r11,r11,r28
	ctx.xer.ca = ctx.r28.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r28.u64 - ctx.r11.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwimi r4,r11,28,2,3
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0x30000000) | (ctx.r4.u64 & 0xFFFFFFFFCFFFFFFF);
	// bl 0x82136670
	ctx.lr = 0x820C76CC;
	sub_82136670(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r30,14840(r31)
	REX_STORE_U32(ctx.r31.u32 + 14840, ctx.r30.u32);
loc_820C76D4:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x820c7974
	if (ctx.cr6.eq) goto loc_820C7974;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820c7974
	if (ctx.cr6.eq) goto loc_820C7974;
	// lis r4,-23168
	ctx.r4.s64 = -1518338048;
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82136670
	ctx.lr = 0x820C76F0;
	sub_82136670(ctx, base);
	// stw r3,10896(r31)
	REX_STORE_U32(ctx.r31.u32 + 10896, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820c7974
	if (ctx.cr0.eq) goto loc_820C7974;
	// lis r4,-27264
	ctx.r4.s64 = -1786773504;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82136670
	ctx.lr = 0x820C7708;
	sub_82136670(ctx, base);
	// stw r3,10900(r31)
	REX_STORE_U32(ctx.r31.u32 + 10900, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820c7974
	if (ctx.cr0.eq) goto loc_820C7974;
	// li r5,96
	ctx.r5.s64 = 96;
	// lwz r3,10896(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82129fa0
	ctx.lr = 0x820C7724;
	sub_82129FA0(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,10900(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10900);
	// bl 0x82129fa0
	ctx.lr = 0x820C7734;
	sub_82129FA0(ctx, base);
	// cntlzw r11,r25
	ctx.r11.u64 = ctx.r25.u32 == 0 ? 32 : __builtin_clz(ctx.r25.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// subfic r24,r11,28
	ctx.xer.ca = ctx.r11.u32 <= 28;
	ctx.r24.u64 = static_cast<uint64_t>(28) - ctx.r11.u64;
	// bl 0x8214a7e4
	ctx.lr = 0x820C7744;
	__imp__MmGetPhysicalAddress(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x8214a7d4
	ctx.lr = 0x820C774C;
	__imp__VdInitializeRingBuffer(ctx, base);
	// rlwinm r11,r25,23,9,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 23) & 0x7FFFFF;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// subfic r4,r11,31
	ctx.xer.ca = ctx.r11.u32 <= 31;
	ctx.r4.u64 = static_cast<uint64_t>(31) - ctx.r11.u64;
	// cmplwi cr6,r4,19
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 19, ctx.xer);
	// ble cr6,0x820c7764
	if (!ctx.cr6.gt) goto loc_820C7764;
	// li r4,19
	ctx.r4.s64 = 19;
loc_820C7764:
	// lwz r11,10896(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// addi r11,r11,60
	ctx.r11.s64 = ctx.r11.s64 + 60;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r11,r11,3
	ctx.r11.u64 = ctx.r11.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x8214a7c4
	ctx.lr = 0x820C7784;
	__imp__VdEnableRingBufferRPtrWriteBack(ctx, base);
	// rlwinm r11,r28,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFC;
	// lis r9,2989
	ctx.r9.s64 = 195887104;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// ori r7,r9,61453
	ctx.r7.u64 = ctx.r9.u64 | 61453;
	// rlwinm r8,r25,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r10,r26,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// stw r7,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r7.u32);
	// rlwinm r11,r28,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 30) & 0x3FFFFFFF;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// stw r9,14908(r31)
	REX_STORE_U32(ctx.r31.u32 + 14908, ctx.r9.u32);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// stw r11,14936(r31)
	REX_STORE_U32(ctx.r31.u32 + 14936, ctx.r11.u32);
	// stw r27,14896(r31)
	REX_STORE_U32(ctx.r31.u32 + 14896, ctx.r27.u32);
	// addi r9,r30,-4
	ctx.r9.s64 = ctx.r30.s64 + -4;
	// stw r30,14904(r31)
	REX_STORE_U32(ctx.r31.u32 + 14904, ctx.r30.u32);
	// addi r7,r10,-160
	ctx.r7.s64 = ctx.r10.s64 + -160;
	// stw r30,14924(r31)
	REX_STORE_U32(ctx.r31.u32 + 14924, ctx.r30.u32);
	// stw r30,14928(r31)
	REX_STORE_U32(ctx.r31.u32 + 14928, ctx.r30.u32);
	// stw r26,14912(r31)
	REX_STORE_U32(ctx.r31.u32 + 14912, ctx.r26.u32);
	// stw r8,14900(r31)
	REX_STORE_U32(ctx.r31.u32 + 14900, ctx.r8.u32);
	// lwz r11,10896(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// stw r29,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r29.u32);
	// lwz r11,10908(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10908);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r29,10952(r31)
	REX_STORE_U32(ctx.r31.u32 + 10952, ctx.r29.u32);
	// stw r9,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r9.u32);
	// stw r10,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// stw r7,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r7.u32);
	// stw r29,14916(r31)
	REX_STORE_U32(ctx.r31.u32 + 14916, ctx.r29.u32);
	// bne cr6,0x820c7808
	if (!ctx.cr6.eq) goto loc_820C7808;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,10908(r31)
	REX_STORE_U32(ctx.r31.u32 + 10908, ctx.r11.u32);
loc_820C7808:
	// lwz r11,10908(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10908);
	// lwz r10,10896(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,10896(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// lwz r9,14920(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 14920);
	// clrlwi r9,r9,30
	ctx.r9.u64 = ctx.r9.u32 & 0x3;
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// lwz r11,10896(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// bl 0x8214a7f4
	ctx.lr = 0x820C783C;
	__imp__VdSetSystemCommandBufferGpuIdentifierAddress(ctx, base);
	// lis r10,-16367
	ctx.r10.s64 = -1072627712;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// ori r9,r10,18432
	ctx.r9.u64 = ctx.r10.u64 | 18432;
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// li r8,1023
	ctx.r8.s64 = 1023;
	// addi r10,r11,5996
	ctx.r10.s64 = ctx.r11.s64 + 5996;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r11,8
	ctx.r11.s64 = 8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820C786C:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r11,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x820c786c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820C786C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r29,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// li r11,2048
	ctx.r11.s64 = 2048;
	// stw r29,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r29.u32);
	// li r9,7
	ctx.r9.s64 = 7;
	// sth r10,10924(r31)
	REX_STORE_U16(ctx.r31.u32 + 10924, ctx.r10.u16);
	// sth r11,10926(r31)
	REX_STORE_U16(ctx.r31.u32 + 10926, ctx.r11.u16);
	// li r4,19
	ctx.r4.s64 = 19;
	// sth r11,130(r1)
	REX_STORE_U16(ctx.r1.u32 + 130, ctx.r11.u16);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// sth r10,128(r1)
	REX_STORE_U16(ctx.r1.u32 + 128, ctx.r10.u16);
	// stw r9,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// stw r29,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r29.u32);
	// stw r29,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r29.u32);
	// stw r29,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r29.u32);
	// Checkpoint 018 diagnostic stop: next original instruction is bl 0x8214A7B4.
	base.fail(Error::unsupported, 0x8214A7B4u);
}
