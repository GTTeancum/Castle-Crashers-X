DEFINE_REX_FUNC(sub_820C0DA8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x820C0DB0;
	__savegprlr_23(ctx, base);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// bl 0x8214a6e4
	ctx.lr = 0x820C0DC4;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lwz r11,16560(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16560);
	// addi r10,r3,-2
	ctx.r10.s64 = ctx.r3.s64 + -2;
	// addi r4,r28,28
	ctx.r4.s64 = ctx.r28.s64 + 28;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stw r11,16560(r31)
	REX_STORE_U32(ctx.r31.u32 + 16560, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// rlwinm r11,r10,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// li r5,24
	ctx.r5.s64 = 24;
	// xori r23,r11,1
	ctx.r23.u64 = ctx.r11.u64 ^ 1;
	// bl 0x82129a70
	ctx.lr = 0x820C0DF0;
	sub_82129A70(ctx, base);
	// lwz r11,13608(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13608);
	// lwz r29,132(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// clrlwi r10,r29,26
	ctx.r10.u64 = ctx.r29.u32 & 0x3F;
	// cmplwi cr6,r10,50
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 50, ctx.xer);
	// bne cr6,0x820c0e0c
	if (!ctx.cr6.eq) goto loc_820C0E0C;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x820c0e18
	goto loc_820C0E18;
loc_820C0E0C:
	// cmplwi cr6,r10,7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 7, ctx.xer);
	// bne cr6,0x820c0e20
	if (!ctx.cr6.eq) goto loc_820C0E20;
	// li r10,27
	ctx.r10.s64 = 27;
loc_820C0E18:
	// rlwimi r29,r10,1,26,31
	ctx.r29.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x3F) | (ctx.r29.u64 & 0xFFFFFFFFFFFFFFC0);
	// stw r29,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
loc_820C0E20:
	// lwz r10,140(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// rlwinm r30,r11,15,17,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0x7FFF;
	// lwz r9,128(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// addi r3,r31,14844
	ctx.r3.s64 = ctx.r31.s64 + 14844;
	// rlwimi r10,r30,0,19,30
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x1FFE) | (ctx.r10.u64 & 0xFFFFFFFFFFFFE001);
	// rlwimi r9,r11,25,22,29
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x3FC) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFC03);
	// rlwimi r30,r10,0,0,30
	ctx.r30.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE) | (ctx.r30.u64 & 0xFFFFFFFF00000001);
	// li r5,52
	ctx.r5.s64 = 52;
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r30,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r30.u32);
	// bl 0x82129a70
	ctx.lr = 0x820C0E50;
	sub_82129A70(ctx, base);
	// lwz r9,136(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// rlwinm r11,r30,2,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x2;
	// lwz r10,13612(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 13612);
	// clrlwi r8,r9,19
	ctx.r8.u64 = ctx.r9.u32 & 0x1FFF;
	// lwz r7,21632(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 21632);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r9,r9,19,19,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 19) & 0x1FFF;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r6,r29,0,0,19
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xFFFFF000;
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// clrlwi r5,r29,26
	ctx.r5.u64 = ctx.r29.u32 & 0x3F;
	// stw r8,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// li r24,0
	ctx.r24.s64 = 0;
	// stw r6,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// beq cr6,0x820c0f0c
	if (ctx.cr6.eq) goto loc_820C0F0C;
	// lwz r10,21624(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21624);
	// lwz r11,21628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21628);
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// bge cr6,0x820c0f0c
	if (!ctx.cr6.lt) goto loc_820C0F0C;
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// lwz r10,10896(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r24,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.r24.u32);
	// lwz r10,10896(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// lwz r11,21628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21628);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r24,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.r24.u32);
	// lwz r11,21628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21628);
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
	// lwz r11,10896(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x820cdf20
	ctx.lr = 0x820C0F08;
	sub_820CDF20(ctx, base);
	// li r29,1
	ctx.r29.s64 = 1;
loc_820C0F0C:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820c0f4c
	if (ctx.cr6.eq) goto loc_820C0F4C;
	// addi r10,r31,13640
	ctx.r10.s64 = ctx.r31.s64 + 13640;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// addi r8,r26,28
	ctx.r8.s64 = ctx.r26.s64 + 28;
loc_820C0F20:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820c0f40
	if (!ctx.cr0.eq) goto loc_820C0F40;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x820c0f20
	if (!ctx.cr6.eq) goto loc_820C0F20;
loc_820C0F40:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// li r27,1
	ctx.r27.s64 = 1;
	// bne 0x820c0f50
	if (!ctx.cr0.eq) goto loc_820C0F50;
loc_820C0F4C:
	// mr r27,r24
	ctx.r27.u64 = ctx.r24.u64;
loc_820C0F50:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// beq cr6,0x820c0fa4
	if (ctx.cr6.eq) goto loc_820C0FA4;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,916(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820c0f84
	if (ctx.cr6.eq) goto loc_820C0F84;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820c0f80
	if (!ctx.cr6.gt) goto loc_820C0F80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7228
	ctx.lr = 0x820C0F80;
	sub_820C7228(ctx, base);
loc_820C0F80:
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
loc_820C0F84:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x820c0f98
	if (ctx.cr6.eq) goto loc_820C0F98;
	// lwz r11,23956(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 23956);
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// stw r11,23956(r31)
	REX_STORE_U32(ctx.r31.u32 + 23956, ctx.r11.u32);
loc_820C0F98:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d3ef8
	ctx.lr = 0x820C0FA4;
	sub_820D3EF8(ctx, base);
loc_820C0FA4:
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8214a784
	ctx.lr = 0x820C0FB0;
	__imp__VdGetSystemCommandBuffer(ctx, base);
	// lwz r11,21532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21532);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c0fcc
	if (ctx.cr6.eq) goto loc_820C0FCC;
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r10,10896(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// b 0x820c101c
	goto loc_820C101C;
loc_820C0FCC:
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7458
	ctx.lr = 0x820C0FD8;
	sub_820C7458(ctx, base);
	// addi r9,r1,100
	ctx.r9.s64 = ctx.r1.s64 + 100;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r11,10896(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwz r7,116(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// addi r8,r1,108
	ctx.r8.s64 = ctx.r1.s64 + 108;
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// addi r5,r11,8
	ctx.r5.s64 = ctx.r11.s64 + 8;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
	// bl 0x8214a774
	ctx.lr = 0x820C1014;
	__imp__VdSwap(ctx, base);
	// addi r11,r30,256
	ctx.r11.s64 = ctx.r30.s64 + 256;
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_820C101C:
	// lwz r11,212(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 212);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r11,23348(r31)
	REX_STORE_U32(ctx.r31.u32 + 23348, ctx.r11.u32);
	// beq cr6,0x820c105c
	if (ctx.cr6.eq) goto loc_820C105C;
	// lwz r11,21628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21628);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,10896(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 10896);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x820cdf20
	ctx.lr = 0x820C1050;
	sub_820CDF20(ctx, base);
	// lwz r11,21628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21628);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,21628(r31)
	REX_STORE_U32(ctx.r31.u32 + 21628, ctx.r11.u32);
loc_820C105C:
	// lwz r11,216(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 216);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c106c
	if (ctx.cr6.eq) goto loc_820C106C;
	// stw r11,23976(r31)
	REX_STORE_U32(ctx.r31.u32 + 23976, ctx.r11.u32);
loc_820C106C:
	// lwz r30,16708(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 16708);
	// stw r24,16708(r31)
	REX_STORE_U32(ctx.r31.u32 + 16708, ctx.r24.u32);
	// rlwinm. r11,r30,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c1094
	if (ctx.cr0.eq) goto loc_820C1094;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// addi r4,r31,13544
	ctx.r4.s64 = ctx.r31.s64 + 13544;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cbf48
	ctx.lr = 0x820C108C;
	sub_820CBF48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7228
	ctx.lr = 0x820C1094;
	sub_820C7228(ctx, base);
loc_820C1094:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x820c10b8
	if (ctx.cr6.eq) goto loc_820C10B8;
	// addi r3,r31,13640
	ctx.r3.s64 = ctx.r31.s64 + 13640;
	// li r5,28
	ctx.r5.s64 = 28;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82129a70
	ctx.lr = 0x820C10AC;
	sub_82129A70(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d19b8
	ctx.lr = 0x820C10B8;
	sub_820D19B8(ctx, base);
loc_820C10B8:
	// lwz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r8,216(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 216);
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r11,3
	ctx.r10.u64 = ctx.r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	ctx.r11.s64 = ctx.r9.s64 + 512;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// rlwinm r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// add r26,r11,r10
	ctx.r26.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq cr6,0x820c11a4
	if (ctx.cr6.eq) goto loc_820C11A4;
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// cmplw cr6,r11,r25
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r25.u32, ctx.xer);
	// bne cr6,0x820c11a4
	if (!ctx.cr6.eq) goto loc_820C11A4;
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addi r3,r31,13668
	ctx.r3.s64 = ctx.r31.s64 + 13668;
	// mr r27,r24
	ctx.r27.u64 = ctx.r24.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// lis r28,10280
	ctx.r28.s64 = 673710080;
	// bne cr6,0x820c110c
	if (!ctx.cr6.eq) goto loc_820C110C;
	// ori r28,r28,310
	ctx.r28.u64 = ctx.r28.u64 | 310;
	// b 0x820c1110
	goto loc_820C1110;
loc_820C110C:
	// ori r28,r28,262
	ctx.r28.u64 = ctx.r28.u64 | 262;
loc_820C1110:
	// lwz r11,236(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 236);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820c116c
	if (ctx.cr6.eq) goto loc_820C116C;
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r8,r11,56
	ctx.r8.s64 = ctx.r11.s64 + 56;
loc_820C1128:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820c1148
	if (!ctx.cr0.eq) goto loc_820C1148;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x820c1128
	if (!ctx.cr6.eq) goto loc_820C1128;
loc_820C1148:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820c116c
	if (ctx.cr0.eq) goto loc_820C116C;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// li r5,56
	ctx.r5.s64 = 56;
	// bl 0x82129a70
	ctx.lr = 0x820C115C;
	sub_82129A70(ctx, base);
	// lbz r11,10942(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10942);
	// ori r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 16;
	// stb r11,10942(r31)
	REX_STORE_U8(ctx.r31.u32 + 10942, ctx.r11.u8);
	// b 0x820c1188
	goto loc_820C1188;
loc_820C116C:
	// lbz r11,10942(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10942);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c118c
	if (ctx.cr0.eq) goto loc_820C118C;
	// lwz r11,352(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 352);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820c118c
	if (!ctx.cr6.eq) goto loc_820C118C;
	// addi r29,r31,13724
	ctx.r29.s64 = ctx.r31.s64 + 13724;
loc_820C1188:
	// ori r30,r30,4
	ctx.r30.u64 = ctx.r30.u64 | 4;
loc_820C118C:
	// lbz r11,10943(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10943);
	// rlwinm. r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820c119c
	if (!ctx.cr0.eq) goto loc_820C119C;
	// ori r30,r30,3
	ctx.r30.u64 = ctx.r30.u64 | 3;
loc_820C119C:
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
	// b 0x820c11f0
	goto loc_820C11F0;
loc_820C11A4:
	// lbz r11,10942(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10942);
	// addi r29,r31,13724
	ctx.r29.s64 = ctx.r31.s64 + 13724;
	// lwz r28,13608(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 13608);
	// addi r27,r31,15004
	ctx.r27.s64 = ctx.r31.s64 + 15004;
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c11dc
	if (ctx.cr0.eq) goto loc_820C11DC;
	// li r5,56
	ctx.r5.s64 = 56;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,13668
	ctx.r3.s64 = ctx.r31.s64 + 13668;
	// bl 0x82129fa0
	ctx.lr = 0x820C11CC;
	sub_82129FA0(ctx, base);
	// lbz r11,10942(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10942);
	// ori r30,r30,4
	ctx.r30.u64 = ctx.r30.u64 | 4;
	// andi. r11,r11,239
	ctx.r11.u64 = ctx.r11.u64 & 239;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r11,10942(r31)
	REX_STORE_U8(ctx.r31.u32 + 10942, ctx.r11.u8);
loc_820C11DC:
	// lbz r11,10943(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10943);
	// rlwinm. r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820c11ec
	if (ctx.cr0.eq) goto loc_820C11EC;
	// ori r30,r30,3
	ctx.r30.u64 = ctx.r30.u64 | 3;
loc_820C11EC:
	// andi. r11,r11,191
	ctx.r11.u64 = ctx.r11.u64 & 191;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
loc_820C11F0:
	// stb r11,10943(r31)
	REX_STORE_U8(ctx.r31.u32 + 10943, ctx.r11.u8);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,928(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 928);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820c1210
	if (!ctx.cr6.eq) goto loc_820C1210;
	// lbz r11,10941(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10941);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c1214
	if (ctx.cr0.eq) goto loc_820C1214;
loc_820C1210:
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
loc_820C1214:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x820c1244
	if (ctx.cr6.eq) goto loc_820C1244;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// lwz r7,96(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820c0bc0
	ctx.lr = 0x820C1240;
	sub_820C0BC0(ctx, base);
	// b 0x820c1250
	goto loc_820C1250;
loc_820C1244:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x820c0b40
	ctx.lr = 0x820C1250;
	sub_820C0B40(ctx, base);
loc_820C1250:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// lwz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r5,104(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r27,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820cf728
	ctx.lr = 0x820C1278;
	sub_820CF728(ctx, base);
	// rlwinm. r11,r30,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c12f8
	if (ctx.cr0.eq) goto loc_820C12F8;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// beq cr6,0x820c12f8
	if (ctx.cr6.eq) goto loc_820C12F8;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820c12a0
	if (!ctx.cr6.gt) goto loc_820C12A0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7228
	ctx.lr = 0x820C12A0;
	sub_820C7228(ctx, base);
loc_820C12A0:
	// lis r11,-16382
	ctx.r11.s64 = -1073610752;
	// li r10,7758
	ctx.r10.s64 = 7758;
	// ori r11,r11,8448
	ctx.r11.u64 = ctx.r11.u64 | 8448;
	// li r9,-2
	ctx.r9.s64 = -2;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// addi r8,r1,184
	ctx.r8.s64 = ctx.r1.s64 + 184;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// stwu r10,4(r7)
	ea = 4 + ctx.r7.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r7.u32 = ea;
	// stwu r9,4(r7)
	ea = 4 + ctx.r7.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r7.u32 = ea;
	// stwu r11,4(r7)
	ea = 4 + ctx.r7.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r7.u32 = ea;
	// std r24,0(r8)
	REX_STORE_U64(ctx.r8.u32 + 0, ctx.r24.u64);
	// stw r24,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r24.u32);
	// stw r7,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r7.u32);
	// bl 0x8214a764
	ctx.lr = 0x820C12E4;
	__imp__VdPersistDisplay(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820c12f8
	if (ctx.cr0.eq) goto loc_820C12F8;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r4,160(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// bl 0x8214a504
	ctx.lr = 0x820C12F8;
	__imp__MmFreePhysicalMemory(ctx, base);
loc_820C12F8:
	// lwz r30,10908(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 10908);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,10928(r31)
	REX_STORE_U32(ctx.r31.u32 + 10928, ctx.r30.u32);
	// bl 0x820c7228
	ctx.lr = 0x820C1308;
	sub_820C7228(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d19e8
	ctx.lr = 0x820C1318;
	sub_820D19E8(ctx, base);
	// lwz r11,14912(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14912);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r4,r11,30,2,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// bl 0x820c6f68
	ctx.lr = 0x820C1328;
	sub_820C6F68(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,14940(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 14940);
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c6b18
	ctx.lr = 0x820C1340;
	sub_820C6B18(ctx, base);
	// lwz r11,23980(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 23980);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c138c
	if (ctx.cr0.eq) goto loc_820C138C;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820be8f8
	ctx.lr = 0x820C135C;
	sub_820BE8F8(ctx, base);
loc_820C135C:
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820be9f0
	ctx.lr = 0x820C1364;
	sub_820BE9F0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820c1380
	if (ctx.cr0.eq) goto loc_820C1380;
	// lwz r11,16568(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16568);
	// lwz r10,16560(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16560);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// bge cr6,0x820c135c
	if (!ctx.cr6.lt) goto loc_820C135C;
loc_820C1380:
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820be928
	ctx.lr = 0x820C1388;
	sub_820BE928(ctx, base);
	// b 0x820c1390
	goto loc_820C1390;
loc_820C138C:
	// stw r30,14940(r31)
	REX_STORE_U32(ctx.r31.u32 + 14940, ctx.r30.u32);
loc_820C1390:
	// lbz r11,10941(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10941);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// andi. r11,r11,239
	ctx.r11.u64 = ctx.r11.u64 & 239;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r11,10941(r31)
	REX_STORE_U8(ctx.r31.u32 + 10941, ctx.r11.u8);
	// bl 0x820cf9d0
	ctx.lr = 0x820C13A4;
	sub_820CF9D0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820bde48
	ctx.lr = 0x820C13B0;
	sub_820BDE48(ctx, base);
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
