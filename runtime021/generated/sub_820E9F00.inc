DEFINE_REX_FUNC(sub_820E9F00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x820E9F08;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r23,0
	ctx.r23.s64 = 0;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// addi r24,r31,296
	ctx.r24.s64 = ctx.r31.s64 + 296;
	// mr r26,r23
	ctx.r26.u64 = ctx.r23.u64;
	// mr r22,r23
	ctx.r22.u64 = ctx.r23.u64;
	// bl 0x8214abc4
	ctx.lr = 0x820E9F2C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r13
	ctx.r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e9f4c
	if (ctx.cr6.eq) goto loc_820E9F4C;
	// lwz r11,8(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820e9f5c
	if (ctx.cr6.eq) goto loc_820E9F5C;
loc_820E9F4C:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820E9F54;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// stb r29,12(r24)
	REX_STORE_U8(ctx.r24.u32 + 12, ctx.r29.u8);
	// stw r30,8(r24)
	REX_STORE_U32(ctx.r24.u32 + 8, ctx.r30.u32);
loc_820E9F5C:
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r11.u32);
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x820da528
	ctx.lr = 0x820E9F70;
	sub_820DA528(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ea970
	if (ctx.cr6.eq) goto loc_820EA970;
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x820dae88
	ctx.lr = 0x820E9F80;
	sub_820DAE88(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x820e9fe0
	if (!ctx.cr6.lt) goto loc_820E9FE0;
loc_820E9F8C:
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e9fd0
	if (ctx.cr6.eq) goto loc_820E9FD0;
	// lwz r9,8(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820e9fd0
	if (!ctx.cr6.eq) goto loc_820E9FD0;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r11.u32);
	// bne 0x820e9fd0
	if (!ctx.cr0.eq) goto loc_820E9FD0;
	// lbz r31,12(r24)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r24.u32 + 12);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r23,8(r24)
	REX_STORE_U32(ctx.r24.u32 + 8, ctx.r23.u32);
	// stb r23,12(r24)
	REX_STORE_U8(ctx.r24.u32 + 12, ctx.r23.u8);
	// bl 0x8214a794
	ctx.lr = 0x820E9FC8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820E9FD0;
	__imp__KfLowerIrql(ctx, base);
loc_820E9FD0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_820E9FE0:
	// bl 0x8214abc4
	ctx.lr = 0x820E9FE4;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r25,r11,22852
	ctx.r25.s64 = ctx.r11.s64 + 22852;
	// mr r30,r13
	ctx.r30.u64 = ctx.r13.u64;
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820ea00c
	if (ctx.cr6.eq) goto loc_820EA00C;
	// lwz r10,8(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820ea020
	if (ctx.cr6.eq) goto loc_820EA020;
loc_820EA00C:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820EA014;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// stw r30,8(r25)
	REX_STORE_U32(ctx.r25.u32 + 8, ctx.r30.u32);
	// stb r29,12(r25)
	REX_STORE_U8(ctx.r25.u32 + 12, ctx.r29.u8);
loc_820EA020:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stw r11,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820e26d0
	ctx.lr = 0x820EA034;
	sub_820E26D0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820ea098
	if (ctx.cr6.lt) goto loc_820EA098;
	// lbz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea078
	if (ctx.cr6.eq) goto loc_820EA078;
	// clrlwi r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_820EA058:
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// rlwinm r6,r9,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// lbzx r9,r6,r31
	ctx.r9.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r31.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// blt cr6,0x820ea058
	if (ctx.cr6.lt) goto loc_820EA058;
loc_820EA078:
	// stb r10,89(r1)
	REX_STORE_U8(ctx.r1.u32 + 89, ctx.r10.u8);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820e2960
	ctx.lr = 0x820EA08C;
	sub_820E2960(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x820ea34c
	if (!ctx.cr6.lt) goto loc_820EA34C;
loc_820EA098:
	// lwz r9,4(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820ea0e4
	if (ctx.cr6.eq) goto loc_820EA0E4;
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820ea0e4
	if (!ctx.cr6.eq) goto loc_820EA0E4;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// bne 0x820ea0e4
	if (!ctx.cr0.eq) goto loc_820EA0E4;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// lbz r29,12(r25)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r25.u32 + 12);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// stw r10,8(r25)
	REX_STORE_U32(ctx.r25.u32 + 8, ctx.r10.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stb r11,12(r25)
	REX_STORE_U8(ctx.r25.u32 + 12, ctx.r11.u8);
	// bl 0x8214a794
	ctx.lr = 0x820EA0DC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820EA0E4;
	__imp__KfLowerIrql(ctx, base);
loc_820EA0E4:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x820e9f8c
	if (!ctx.cr6.eq) goto loc_820E9F8C;
loc_820EA0EC:
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x820daf20
	ctx.lr = 0x820EA0F4;
	sub_820DAF20(ctx, base);
	// lbz r11,292(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 292);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820ea108
	if (!ctx.cr6.eq) goto loc_820EA108;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820e9750
	ctx.lr = 0x820EA108;
	sub_820E9750(ctx, base);
loc_820EA108:
	// lbz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea288
	if (ctx.cr6.eq) goto loc_820EA288;
	// mr r27,r23
	ctx.r27.u64 = ctx.r23.u64;
loc_820EA118:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x820da758
	ctx.lr = 0x820EA124;
	sub_820DA758(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820ea1c8
	if (ctx.cr6.eq) goto loc_820EA1C8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x820da9a0
	ctx.lr = 0x820EA144;
	sub_820DA9A0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ea1c8
	if (ctx.cr6.eq) goto loc_820EA1C8;
	// mulli r30,r27,88
	ctx.r30.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(88));
loc_820EA150:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r3,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// beq cr6,0x820ea170
	if (ctx.cr6.eq) goto loc_820EA170;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
loc_820EA170:
	// stw r3,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// add r3,r30,r11
	ctx.r3.u64 = ctx.r30.u64 + ctx.r11.u64;
	// bl 0x820eca70
	ctx.lr = 0x820EA180;
	sub_820ECA70(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// add r29,r5,r29
	ctx.r29.u64 = ctx.r5.u64 + ctx.r29.u64;
	// bl 0x820da7e8
	ctx.lr = 0x820EA198;
	sub_820DA7E8(ctx, base);
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r9,28(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// subf. r8,r9,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x820ea1c8
	if (ctx.cr0.eq) goto loc_820EA1C8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x820da9a0
	ctx.lr = 0x820EA1C0;
	sub_820DA9A0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820ea150
	if (!ctx.cr6.eq) goto loc_820EA150;
loc_820EA1C8:
	// addi r11,r27,138
	ctx.r11.s64 = ctx.r27.s64 + 138;
	// subf r10,r29,r28
	ctx.r10.u64 = ctx.r28.u64 - ctx.r29.u64;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r31.u32);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x820ea1e4
	if (ctx.cr6.gt) goto loc_820EA1E4;
	// li r22,1
	ctx.r22.s64 = 1;
loc_820EA1E4:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x820dcdc0
	ctx.lr = 0x820EA1F0;
	sub_820DCDC0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x820dcdc0
	ctx.lr = 0x820EA1FC;
	sub_820DCDC0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x820dacc0
	ctx.lr = 0x820EA208;
	sub_820DACC0(ctx, base);
	// lwz r10,200(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// mulli r11,r27,88
	ctx.r11.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(88));
	// stw r3,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r3.u32);
	// add r30,r11,r10
	ctx.r30.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// lwz r10,24(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// subf. r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lbz r29,13(r30)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r30.u32 + 13);
	// beq 0x820ea260
	if (ctx.cr0.eq) goto loc_820EA260;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820ea25c
	if (ctx.cr6.eq) goto loc_820EA25C;
	// rlwinm r26,r10,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r11,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_820EA23C:
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r28,r11
	ctx.r3.u64 = ctx.r28.u64 + ctx.r11.u64;
	// bl 0x82129fa0
	ctx.lr = 0x820EA250;
	sub_82129FA0(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r28,r28,1024
	ctx.r28.s64 = ctx.r28.s64 + 1024;
	// bne 0x820ea23c
	if (!ctx.cr0.eq) goto loc_820EA23C;
loc_820EA25C:
	// li r26,1
	ctx.r26.s64 = 1;
loc_820EA260:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x820ea274
	if (!ctx.cr6.eq) goto loc_820EA274;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x820dcdc0
	ctx.lr = 0x820EA274;
	sub_820DCDC0(ctx, base);
loc_820EA274:
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// lbz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// clrlwi r27,r11,24
	ctx.r27.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r27,r10
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820ea118
	if (ctx.cr6.lt) goto loc_820EA118;
loc_820EA288:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820e8e68
	ctx.lr = 0x820EA290;
	sub_820E8E68(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x8214abc4
	ctx.lr = 0x820EA298;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r13
	ctx.r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820ea2b8
	if (ctx.cr6.eq) goto loc_820EA2B8;
	// lwz r10,8(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820ea2cc
	if (ctx.cr6.eq) goto loc_820EA2CC;
loc_820EA2B8:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820EA2C0;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// stw r30,8(r25)
	REX_STORE_U32(ctx.r25.u32 + 8, ctx.r30.u32);
	// stb r29,12(r25)
	REX_STORE_U8(ctx.r25.u32 + 12, ctx.r29.u8);
loc_820EA2CC:
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r7.u32);
	// lbz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea310
	if (ctx.cr6.eq) goto loc_820EA310;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_820EA2E4:
	// lwz r9,200(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// mulli r10,r11,88
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(88));
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// lfs f0,40(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,36(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 36, temp.u32);
	// lbz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820ea2e4
	if (ctx.cr6.lt) goto loc_820EA2E4;
	// lwz r7,4(r25)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
loc_820EA310:
	// clrlwi r11,r26,24
	ctx.r11.u64 = ctx.r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea6a4
	if (ctx.cr6.eq) goto loc_820EA6A4;
	// lbz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 172);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820ea674
	if (!ctx.cr6.eq) goto loc_820EA674;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// mr r8,r23
	ctx.r8.u64 = ctx.r23.u64;
	// addi r9,r31,20
	ctx.r9.s64 = ctx.r31.s64 + 20;
loc_820EA338:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820ea600
	if (ctx.cr6.eq) goto loc_820EA600;
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x820ea604
	goto loc_820EA604;
loc_820EA34C:
	// lbz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea3ac
	if (ctx.cr6.eq) goto loc_820EA3AC;
	// lwz r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// li r7,256
	ctx.r7.s64 = 256;
loc_820EA364:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// mulli r8,r10,88
	ctx.r8.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(88));
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// addi r8,r10,8
	ctx.r8.s64 = ctx.r10.s64 + 8;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// rlwinm r5,r8,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// stw r9,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// stw r7,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r7.u32);
	// stw r23,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r23.u32);
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lbzx r11,r5,r31
	ctx.r11.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r31.u32);
	// rotlwi r11,r11,10
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 10);
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lbz r3,56(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// blt cr6,0x820ea364
	if (ctx.cr6.lt) goto loc_820EA364;
loc_820EA3AC:
	// lbz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 172);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820ea538
	if (ctx.cr6.eq) goto loc_820EA538;
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820ea538
	if (!ctx.cr6.eq) goto loc_820EA538;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// rlwinm r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lfs f31,9536(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x820ea468
	if (ctx.cr6.eq) goto loc_820EA468;
	// lbz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea44c
	if (ctx.cr6.eq) goto loc_820EA44C;
	// mr r8,r23
	ctx.r8.u64 = ctx.r23.u64;
loc_820EA3EC:
	// lwz r10,200(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// mulli r11,r8,88
	ctx.r11.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(88));
	// lfs f0,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// stfs f0,40(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 40, temp.u32);
	// lwz r10,200(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lfs f13,40(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,36(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 36, temp.u32);
	// lwz r10,200(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r10,r11,52
	ctx.r10.s64 = ctx.r11.s64 + 52;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820EA428:
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x820ea428
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820EA428;
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// stfs f31,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 48, temp.u32);
	// lbz r9,56(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x820ea3ec
	if (ctx.cr6.lt) goto loc_820EA3EC;
loc_820EA44C:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820EA468;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820EA468:
	// lbz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 172);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820ea4e8
	if (ctx.cr6.eq) goto loc_820EA4E8;
	// lhz r10,174(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 174);
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// lwz r9,200(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// addis r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 65536;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// lfs f13,40(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// sth r7,174(r31)
	REX_STORE_U16(ctx.r31.u32 + 174, ctx.r7.u16);
	// beq cr6,0x820ea4b0
	if (ctx.cr6.eq) goto loc_820EA4B0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,-27764(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27764);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// b 0x820ea4b4
	goto loc_820EA4B4;
loc_820EA4B0:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_820EA4B4:
	// lbz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea4e8
	if (ctx.cr6.eq) goto loc_820EA4E8;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_820EA4C4:
	// lwz r10,200(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// mulli r9,r11,88
	ctx.r9.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(88));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// stfs f0,40(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 40, temp.u32);
	// lbz r9,56(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x820ea4c4
	if (ctx.cr6.lt) goto loc_820EA4C4;
loc_820EA4E8:
	// lwz r9,4(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820ea0ec
	if (ctx.cr6.eq) goto loc_820EA0EC;
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820ea0ec
	if (!ctx.cr6.eq) goto loc_820EA0EC;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// bne 0x820ea0ec
	if (!ctx.cr0.eq) goto loc_820EA0EC;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// lbz r30,12(r25)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r25.u32 + 12);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// stw r10,8(r25)
	REX_STORE_U32(ctx.r25.u32 + 8, ctx.r10.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stb r11,12(r25)
	REX_STORE_U8(ctx.r25.u32 + 12, ctx.r11.u8);
	// bl 0x8214a794
	ctx.lr = 0x820EA52C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820EA534;
	__imp__KfLowerIrql(ctx, base);
	// b 0x820ea0ec
	goto loc_820EA0EC;
loc_820EA538:
	// lbz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea5ac
	if (ctx.cr6.eq) goto loc_820EA5AC;
	// mr r26,r23
	ctx.r26.u64 = ctx.r23.u64;
loc_820EA548:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// mulli r10,r26,88
	ctx.r10.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(88));
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,24(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// lbz r30,13(r28)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r28.u32 + 13);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea594
	if (ctx.cr6.eq) goto loc_820EA594;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820ea594
	if (ctx.cr6.eq) goto loc_820EA594;
	// rlwinm r27,r11,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
loc_820EA574:
	// lwz r11,20(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r29
	ctx.r3.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x82129fa0
	ctx.lr = 0x820EA588;
	sub_82129FA0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,1024
	ctx.r29.s64 = ctx.r29.s64 + 1024;
	// bne 0x820ea574
	if (!ctx.cr0.eq) goto loc_820EA574;
loc_820EA594:
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// lbz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r26,r11
	ctx.r26.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820ea548
	if (ctx.cr6.lt) goto loc_820EA548;
loc_820EA5AC:
	// lwz r9,4(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820ea5f8
	if (ctx.cr6.eq) goto loc_820EA5F8;
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820ea5f8
	if (!ctx.cr6.eq) goto loc_820EA5F8;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// bne 0x820ea5f8
	if (!ctx.cr0.eq) goto loc_820EA5F8;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// lbz r31,12(r25)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r25.u32 + 12);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// stw r10,8(r25)
	REX_STORE_U32(ctx.r25.u32 + 8, ctx.r10.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stb r11,12(r25)
	REX_STORE_U8(ctx.r25.u32 + 12, ctx.r11.u8);
	// bl 0x8214a794
	ctx.lr = 0x820EA5F0;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820EA5F8;
	__imp__KfLowerIrql(ctx, base);
loc_820EA5F8:
	// li r30,1
	ctx.r30.s64 = 1;
	// b 0x820e9f8c
	goto loc_820E9F8C;
loc_820EA600:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_820EA604:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820ea61c
	if (ctx.cr6.eq) goto loc_820EA61C;
	// lwz r10,8(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// b 0x820ea620
	goto loc_820EA620;
loc_820EA61C:
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_820EA620:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea648
	if (ctx.cr6.eq) goto loc_820EA648;
	// lbz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 116);
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// cntlzw r6,r11
	ctx.r6.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// or r8,r4,r8
	ctx.r8.u64 = ctx.r4.u64 | ctx.r8.u64;
	// b 0x820ea338
	goto loc_820EA338;
loc_820EA648:
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820ea6a4
	if (!ctx.cr6.eq) goto loc_820EA6A4;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820EA670;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820ea6a0
	goto loc_820EA6A0;
loc_820EA674:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x820ea6a4
	if (!ctx.cr6.eq) goto loc_820EA6A4;
	// rlwinm r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820ea6a4
	if (!ctx.cr6.eq) goto loc_820EA6A4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820EA6A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820EA6A0:
	// lwz r7,4(r25)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
loc_820EA6A4:
	// lbz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 172);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820ea6e8
	if (ctx.cr6.eq) goto loc_820EA6E8;
	// lhz r10,174(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 174);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820ea6cc
	if (ctx.cr6.eq) goto loc_820EA6CC;
	// rlwinm r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea6e8
	if (ctx.cr6.eq) goto loc_820EA6E8;
loc_820EA6CC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820EA6E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,4(r25)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
loc_820EA6E8:
	// lbz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 172);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820ea704
	if (ctx.cr6.eq) goto loc_820EA704;
	// rlwinm r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea8a4
	if (ctx.cr6.eq) goto loc_820EA8A4;
loc_820EA704:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r27,r31,20
	ctx.r27.s64 = ctx.r31.s64 + 20;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820ea720
	if (ctx.cr6.eq) goto loc_820EA720;
	// lwz r10,8(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// b 0x820ea724
	goto loc_820EA724;
loc_820EA720:
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_820EA724:
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea8a4
	if (ctx.cr6.eq) goto loc_820EA8A4;
loc_820EA730:
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820ea748
	if (ctx.cr6.eq) goto loc_820EA748;
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// b 0x820ea74c
	goto loc_820EA74C;
loc_820EA748:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_820EA74C:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820ea764
	if (ctx.cr6.eq) goto loc_820EA764;
	// lwz r10,8(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// subf r28,r10,r11
	ctx.r28.u64 = ctx.r11.u64 - ctx.r10.u64;
	// b 0x820ea768
	goto loc_820EA768;
loc_820EA764:
	// mr r28,r23
	ctx.r28.u64 = ctx.r23.u64;
loc_820EA768:
	// lbz r11,116(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 116);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x820ea89c
	if (!ctx.cr6.eq) goto loc_820EA89C;
	// mr r11,r13
	ctx.r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x820ea7bc
	if (ctx.cr6.eq) goto loc_820EA7BC;
	// lwz r10,8(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820ea7bc
	if (!ctx.cr6.eq) goto loc_820EA7BC;
	// addic. r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// bne 0x820ea7bc
	if (!ctx.cr0.eq) goto loc_820EA7BC;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// lbz r29,12(r25)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r25.u32 + 12);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// stb r11,12(r25)
	REX_STORE_U8(ctx.r25.u32 + 12, ctx.r11.u8);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r10,8(r25)
	REX_STORE_U32(ctx.r25.u32 + 8, ctx.r10.u32);
	// bl 0x8214a794
	ctx.lr = 0x820EA7B4;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820EA7BC;
	__imp__KfLowerIrql(ctx, base);
loc_820EA7BC:
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820ea800
	if (ctx.cr6.eq) goto loc_820EA800;
	// lwz r9,8(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820ea800
	if (!ctx.cr6.eq) goto loc_820EA800;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r11.u32);
	// bne 0x820ea800
	if (!ctx.cr0.eq) goto loc_820EA800;
	// lbz r29,12(r24)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r24.u32 + 12);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stb r23,12(r24)
	REX_STORE_U8(ctx.r24.u32 + 12, ctx.r23.u8);
	// stw r23,8(r24)
	REX_STORE_U32(ctx.r24.u32 + 8, ctx.r23.u32);
	// bl 0x8214a794
	ctx.lr = 0x820EA7F8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820EA800;
	__imp__KfLowerIrql(ctx, base);
loc_820EA800:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820EA81C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8214abc4
	ctx.lr = 0x820EA820;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r9,4(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r13
	ctx.r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820ea840
	if (ctx.cr6.eq) goto loc_820EA840;
	// lwz r11,8(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820ea850
	if (ctx.cr6.eq) goto loc_820EA850;
loc_820EA840:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820EA848;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// stw r30,8(r24)
	REX_STORE_U32(ctx.r24.u32 + 8, ctx.r30.u32);
	// stb r29,12(r24)
	REX_STORE_U8(ctx.r24.u32 + 12, ctx.r29.u8);
loc_820EA850:
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r11.u32);
	// bl 0x8214abc4
	ctx.lr = 0x820EA860;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r13
	ctx.r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820ea880
	if (ctx.cr6.eq) goto loc_820EA880;
	// lwz r10,8(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820ea894
	if (ctx.cr6.eq) goto loc_820EA894;
loc_820EA880:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820EA888;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// stw r30,8(r25)
	REX_STORE_U32(ctx.r25.u32 + 8, ctx.r30.u32);
	// stb r29,12(r25)
	REX_STORE_U8(ctx.r25.u32 + 12, ctx.r29.u8);
loc_820EA894:
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r7.u32);
loc_820EA89C:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x820ea730
	if (!ctx.cr6.eq) goto loc_820EA730;
loc_820EA8A4:
	// mr r11,r13
	ctx.r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x820ea8ec
	if (ctx.cr6.eq) goto loc_820EA8EC;
	// lwz r10,8(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820ea8ec
	if (!ctx.cr6.eq) goto loc_820EA8EC;
	// addic. r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// bne 0x820ea8ec
	if (!ctx.cr0.eq) goto loc_820EA8EC;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// lbz r30,12(r25)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r25.u32 + 12);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// stb r11,12(r25)
	REX_STORE_U8(ctx.r25.u32 + 12, ctx.r11.u8);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r10,8(r25)
	REX_STORE_U32(ctx.r25.u32 + 8, ctx.r10.u32);
	// bl 0x8214a794
	ctx.lr = 0x820EA8E4;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820EA8EC;
	__imp__KfLowerIrql(ctx, base);
loc_820EA8EC:
	// clrlwi r11,r22,24
	ctx.r11.u64 = ctx.r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ea970
	if (ctx.cr6.eq) goto loc_820EA970;
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x820da528
	ctx.lr = 0x820EA900;
	sub_820DA528(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ea970
	if (ctx.cr6.eq) goto loc_820EA970;
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x820db138
	ctx.lr = 0x820EA910;
	sub_820DB138(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge cr6,0x820ea970
	if (!ctx.cr6.lt) goto loc_820EA970;
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820ea960
	if (ctx.cr6.eq) goto loc_820EA960;
	// lwz r9,8(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820ea960
	if (!ctx.cr6.eq) goto loc_820EA960;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r11.u32);
	// bne 0x820ea960
	if (!ctx.cr0.eq) goto loc_820EA960;
	// lbz r30,12(r24)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r24.u32 + 12);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r23,8(r24)
	REX_STORE_U32(ctx.r24.u32 + 8, ctx.r23.u32);
	// stb r23,12(r24)
	REX_STORE_U8(ctx.r24.u32 + 12, ctx.r23.u8);
	// bl 0x8214a794
	ctx.lr = 0x820EA958;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820EA960;
	__imp__KfLowerIrql(ctx, base);
loc_820EA960:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_820EA970:
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820ea9b4
	if (ctx.cr6.eq) goto loc_820EA9B4;
	// lwz r9,8(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820ea9b4
	if (!ctx.cr6.eq) goto loc_820EA9B4;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r11.u32);
	// bne 0x820ea9b4
	if (!ctx.cr0.eq) goto loc_820EA9B4;
	// lbz r31,12(r24)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r24.u32 + 12);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r23,8(r24)
	REX_STORE_U32(ctx.r24.u32 + 8, ctx.r23.u32);
	// stb r23,12(r24)
	REX_STORE_U8(ctx.r24.u32 + 12, ctx.r23.u8);
	// bl 0x8214a794
	ctx.lr = 0x820EA9AC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820EA9B4;
	__imp__KfLowerIrql(ctx, base);
loc_820EA9B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
