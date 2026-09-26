DEFINE_REX_FUNC(sub_820D94F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x820D9500;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r11,-32332
	ctx.r10.s64 = ctx.r11.s64 + -32332;
	// stw r10,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r10.u32);
	// bl 0x82053a98
	ctx.lr = 0x820D9518;
	sub_82053A98(ctx, base);
	// lwz r11,64(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d953c
	if (ctx.cr6.eq) goto loc_820D953C;
	// lwz r3,68(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D953C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820D953C:
	// lwz r11,304(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 304);
	// li r22,0
	ctx.r22.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d9598
	if (ctx.cr6.eq) goto loc_820D9598;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,22944
	ctx.r3.s64 = ctx.r11.s64 + 22944;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8214a9a4
	ctx.lr = 0x820D9560;
	__imp__KeSetEvent(ctx, base);
	// addi r31,r23,308
	ctx.r31.s64 = ctx.r23.s64 + 308;
	// li r30,6
	ctx.r30.s64 = 6;
	// li r29,-1
	ctx.r29.s64 = -1;
loc_820D956C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d958c
	if (ctx.cr6.eq) goto loc_820D958C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820b6020
	ctx.lr = 0x820D9580;
	sub_820B6020(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x820b6498
	ctx.lr = 0x820D9588;
	sub_820B6498(ctx, base);
	// stw r22,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r22.u32);
loc_820D958C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x820d956c
	if (!ctx.cr0.eq) goto loc_820D956C;
loc_820D9598:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// addi r30,r11,6792
	ctx.r30.s64 = ctx.r11.s64 + 6792;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x820D95A8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r31,r11,22876
	ctx.r31.s64 = ctx.r11.s64 + 22876;
	// lwz r11,22876(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 22876);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d95d0
	if (ctx.cr6.eq) goto loc_820D95D0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214a844
	ctx.lr = 0x820D95C8;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_820D95D0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a444
	ctx.lr = 0x820D95D8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// bl 0x8214abc4
	ctx.lr = 0x820D95DC;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r31,r11,22852
	ctx.r31.s64 = ctx.r11.s64 + 22852;
	// mr r30,r13
	ctx.r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d9604
	if (ctx.cr6.eq) goto loc_820D9604;
	// lwz r29,8(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820d9620
	if (ctx.cr6.eq) goto loc_820D9620;
loc_820D9604:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820D960C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stb r27,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r27.u8);
	// b 0x820d9624
	goto loc_820D9624;
loc_820D9620:
	// lbz r27,12(r31)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
loc_820D9624:
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// addi r21,r23,80
	ctx.r21.s64 = ctx.r23.s64 + 80;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x820e1fd0
	ctx.lr = 0x820D9640;
	sub_820E1FD0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820d9708
	if (ctx.cr6.eq) goto loc_820D9708;
loc_820D964C:
	// mr r11,r13
	ctx.r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820d968c
	if (ctx.cr6.eq) goto loc_820D968C;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820d968c
	if (!ctx.cr6.eq) goto loc_820D968C;
	// addic. r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bne 0x820d968c
	if (!ctx.cr0.eq) goto loc_820D968C;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// stb r11,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// bl 0x8214a794
	ctx.lr = 0x820D9684;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820D968C;
	__imp__KfLowerIrql(ctx, base);
loc_820D968C:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D96A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8214abc4
	ctx.lr = 0x820D96A4;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r30,r13
	ctx.r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d96c4
	if (ctx.cr6.eq) goto loc_820D96C4;
	// lwz r29,8(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820d96e0
	if (ctx.cr6.eq) goto loc_820D96E0;
loc_820D96C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820D96CC;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stb r27,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r27.u8);
	// b 0x820d96e4
	goto loc_820D96E4;
loc_820D96E0:
	// lbz r27,12(r31)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
loc_820D96E4:
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x820e1fd0
	ctx.lr = 0x820D96FC;
	sub_820E1FD0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x820d964c
	if (!ctx.cr6.eq) goto loc_820D964C;
loc_820D9708:
	// mr r11,r13
	ctx.r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820d9748
	if (ctx.cr6.eq) goto loc_820D9748;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820d9748
	if (!ctx.cr6.eq) goto loc_820D9748;
	// addic. r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bne 0x820d9748
	if (!ctx.cr0.eq) goto loc_820D9748;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// stb r11,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// bl 0x8214a794
	ctx.lr = 0x820D9740;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820D9748;
	__imp__KfLowerIrql(ctx, base);
loc_820D9748:
	// lbz r11,128(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + 128);
	// mr r24,r22
	ctx.r24.u64 = ctx.r22.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d98dc
	if (ctx.cr6.eq) goto loc_820D98DC;
	// mr r25,r22
	ctx.r25.u64 = ctx.r22.u64;
loc_820D975C:
	// lwz r11,124(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 124);
	// add r26,r25,r11
	ctx.r26.u64 = ctx.r25.u64 + ctx.r11.u64;
	// bl 0x8214abc4
	ctx.lr = 0x820D9768;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r30,r13
	ctx.r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d9788
	if (ctx.cr6.eq) goto loc_820D9788;
	// lwz r29,8(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820d97a4
	if (ctx.cr6.eq) goto loc_820D97A4;
loc_820D9788:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820D9790;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stb r27,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r27.u8);
	// b 0x820d97a8
	goto loc_820D97A8;
loc_820D97A4:
	// lbz r27,12(r31)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
loc_820D97A8:
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x820e1fd0
	ctx.lr = 0x820D97C0;
	sub_820E1FD0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820d9888
	if (ctx.cr6.eq) goto loc_820D9888;
loc_820D97CC:
	// mr r11,r13
	ctx.r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820d980c
	if (ctx.cr6.eq) goto loc_820D980C;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820d980c
	if (!ctx.cr6.eq) goto loc_820D980C;
	// addic. r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bne 0x820d980c
	if (!ctx.cr0.eq) goto loc_820D980C;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// stb r11,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// bl 0x8214a794
	ctx.lr = 0x820D9804;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820D980C;
	__imp__KfLowerIrql(ctx, base);
loc_820D980C:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D9820;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8214abc4
	ctx.lr = 0x820D9824;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r30,r13
	ctx.r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820d9844
	if (ctx.cr6.eq) goto loc_820D9844;
	// lwz r29,8(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820d9860
	if (ctx.cr6.eq) goto loc_820D9860;
loc_820D9844:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820D984C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stb r27,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r27.u8);
	// b 0x820d9864
	goto loc_820D9864;
loc_820D9860:
	// lbz r27,12(r31)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
loc_820D9864:
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x820e1fd0
	ctx.lr = 0x820D987C;
	sub_820E1FD0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x820d97cc
	if (!ctx.cr6.eq) goto loc_820D97CC;
loc_820D9888:
	// mr r11,r13
	ctx.r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820d98c8
	if (ctx.cr6.eq) goto loc_820D98C8;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820d98c8
	if (!ctx.cr6.eq) goto loc_820D98C8;
	// addic. r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bne 0x820d98c8
	if (!ctx.cr0.eq) goto loc_820D98C8;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// stb r11,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// bl 0x8214a794
	ctx.lr = 0x820D98C0;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820D98C8;
	__imp__KfLowerIrql(ctx, base);
loc_820D98C8:
	// lbz r11,128(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + 128);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// addi r25,r25,44
	ctx.r25.s64 = ctx.r25.s64 + 44;
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820d975c
	if (ctx.cr6.lt) goto loc_820D975C;
loc_820D98DC:
	// lwz r3,64(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 64);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d98fc
	if (ctx.cr6.eq) goto loc_820D98FC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D98F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r22,64(r23)
	REX_STORE_U32(ctx.r23.u32 + 64, ctx.r22.u32);
loc_820D98FC:
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// stw r11,22960(r10)
	REX_STORE_U32(ctx.r10.u32 + 22960, ctx.r11.u32);
	// lwz r3,60(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 60);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d991c
	if (ctx.cr6.eq) goto loc_820D991C;
	// bl 0x820db258
	ctx.lr = 0x820D9918;
	sub_820DB258(ctx, base);
	// stw r22,60(r23)
	REX_STORE_U32(ctx.r23.u32 + 60, ctx.r22.u32);
loc_820D991C:
	// addi r31,r23,12
	ctx.r31.s64 = ctx.r23.s64 + 12;
	// li r29,6
	ctx.r29.s64 = 6;
loc_820D9924:
	// li r30,2
	ctx.r30.s64 = 2;
loc_820D9928:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d993c
	if (ctx.cr6.eq) goto loc_820D993C;
	// bl 0x820db258
	ctx.lr = 0x820D9938;
	sub_820DB258(ctx, base);
	// stw r22,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r22.u32);
loc_820D993C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x820d9928
	if (!ctx.cr0.eq) goto loc_820D9928;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x820d9924
	if (!ctx.cr0.eq) goto loc_820D9924;
	// addi r3,r21,24
	ctx.r3.s64 = ctx.r21.s64 + 24;
	// bl 0x820d9470
	ctx.lr = 0x820D9958;
	sub_820D9470(ctx, base);
	// addi r3,r21,12
	ctx.r3.s64 = ctx.r21.s64 + 12;
	// bl 0x820d9470
	ctx.lr = 0x820D9960;
	sub_820D9470(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x820d9470
	ctx.lr = 0x820D9968;
	sub_820D9470(ctx, base);
	// addi r3,r23,68
	ctx.r3.s64 = ctx.r23.s64 + 68;
	// bl 0x820d9470
	ctx.lr = 0x820D9970;
	sub_820D9470(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 8);
	// addi r10,r11,-32352
	ctx.r10.s64 = ctx.r11.s64 + -32352;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r10.u32);
	// beq cr6,0x820d999c
	if (ctx.cr6.eq) goto loc_820D999C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D9998;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r22,8(r23)
	REX_STORE_U32(ctx.r23.u32 + 8, ctx.r22.u32);
loc_820D999C:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r11,-32372
	ctx.r10.s64 = ctx.r11.s64 + -32372;
	// stw r10,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r10.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
