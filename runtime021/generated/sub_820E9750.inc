DEFINE_REX_FUNC(sub_820E9750) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820E9758;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r24,1
	ctx.r24.s64 = 1;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// lbz r11,56(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e97b0
	if (ctx.cr6.eq) goto loc_820E97B0;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
loc_820E977C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,184(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 184);
	// bl 0x820da6f8
	ctx.lr = 0x820E9788;
	sub_820DA6F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820e97ac
	if (ctx.cr6.eq) goto loc_820E97AC;
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// lbz r10,56(r28)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + 56);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820e977c
	if (ctx.cr6.lt) goto loc_820E977C;
	// b 0x820e97b0
	goto loc_820E97B0;
loc_820E97AC:
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
loc_820E97B0:
	// bl 0x8214abc4
	ctx.lr = 0x820E97B4;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r27,r11,22852
	ctx.r27.s64 = ctx.r11.s64 + 22852;
	// mr r31,r13
	ctx.r31.u64 = ctx.r13.u64;
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820e97dc
	if (ctx.cr6.eq) goto loc_820E97DC;
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820e97f0
	if (ctx.cr6.eq) goto loc_820E97F0;
loc_820E97DC:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820E97E4;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// stw r31,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r31.u32);
	// stb r30,12(r27)
	REX_STORE_U8(ctx.r27.u32 + 12, ctx.r30.u8);
loc_820E97F0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r28,20
	ctx.r11.s64 = ctx.r28.s64 + 20;
	// stw r10,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r10.u32);
	// lwz r9,20(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x820e998c
	if (ctx.cr6.eq) goto loc_820E998C;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r30,r11,r9
	ctx.r30.u64 = ctx.r9.u64 - ctx.r11.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820e998c
	if (ctx.cr6.eq) goto loc_820E998C;
	// lbz r11,116(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 116);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e998c
	if (ctx.cr6.eq) goto loc_820E998C;
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e998c
	if (ctx.cr6.eq) goto loc_820E998C;
	// lbz r11,118(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 118);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e9890
	if (ctx.cr6.eq) goto loc_820E9890;
	// clrlwi r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e998c
	if (ctx.cr6.eq) goto loc_820E998C;
	// lbz r11,119(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 119);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820e998c
	if (!ctx.cr6.eq) goto loc_820E998C;
	// lbz r11,56(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e9888
	if (ctx.cr6.eq) goto loc_820E9888;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
loc_820E9864:
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r3,184(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 184);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820daa48
	ctx.lr = 0x820E9874;
	sub_820DAA48(ctx, base);
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// lbz r10,56(r28)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + 56);
	// clrlwi r31,r11,24
	ctx.r31.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820e9864
	if (ctx.cr6.lt) goto loc_820E9864;
loc_820E9888:
	// stb r24,119(r30)
	REX_STORE_U8(ctx.r30.u32 + 119, ctx.r24.u8);
	// b 0x820e9988
	goto loc_820E9988;
loc_820E9890:
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e98e8
	if (ctx.cr6.eq) goto loc_820E98E8;
	// lbz r11,56(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e98e8
	if (ctx.cr6.eq) goto loc_820E98E8;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
loc_820E98B0:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,184(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 184);
	// bl 0x820dac78
	ctx.lr = 0x820E98BC;
	sub_820DAC78(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820e98e0
	if (!ctx.cr6.eq) goto loc_820E98E0;
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// lbz r10,56(r28)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + 56);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820e98b0
	if (ctx.cr6.lt) goto loc_820E98B0;
	// b 0x820e98e4
	goto loc_820E98E4;
loc_820E98E0:
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
loc_820E98E4:
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
loc_820E98E8:
	// clrlwi r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e998c
	if (ctx.cr6.eq) goto loc_820E998C;
	// lbz r11,56(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e9984
	if (ctx.cr6.eq) goto loc_820E9984;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// li r26,3
	ctx.r26.s64 = 3;
loc_820E9908:
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// stw r25,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r4,12(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// addi r29,r11,-128
	ctx.r29.s64 = ctx.r11.s64 + -128;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// stw r25,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r25.u32);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// stw r25,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r25.u32);
	// stb r24,90(r1)
	REX_STORE_U8(ctx.r1.u32 + 90, ctx.r24.u8);
	// bl 0x820e7de8
	ctx.lr = 0x820E993C;
	sub_820E7DE8(ctx, base);
	// rlwinm r9,r29,25,30,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 25) & 0x3;
	// stw r3,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stb r9,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r9.u8);
	// lwz r4,12(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x820e7eb0
	ctx.lr = 0x820E9958;
	sub_820E7EB0(ctx, base);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// stb r26,89(r1)
	REX_STORE_U8(ctx.r1.u32 + 89, ctx.r26.u8);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,184(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 184);
	// bl 0x820dac00
	ctx.lr = 0x820E9970;
	sub_820DAC00(ctx, base);
	// addi r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 1;
	// lbz r7,56(r28)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r28.u32 + 56);
	// clrlwi r31,r8,24
	ctx.r31.u64 = ctx.r8.u32 & 0xFF;
	// cmplw cr6,r31,r7
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x820e9908
	if (ctx.cr6.lt) goto loc_820E9908;
loc_820E9984:
	// stb r24,118(r30)
	REX_STORE_U8(ctx.r30.u32 + 118, ctx.r24.u8);
loc_820E9988:
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
loc_820E998C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// mr r11,r13
	ctx.r11.u64 = ctx.r13.u64;
	// beq cr6,0x820e99d4
	if (ctx.cr6.eq) goto loc_820E99D4;
	// lwz r9,8(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820e99d4
	if (!ctx.cr6.eq) goto loc_820E99D4;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
	// bne 0x820e99d4
	if (!ctx.cr0.eq) goto loc_820E99D4;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// lbz r31,12(r27)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r27.u32 + 12);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// stb r11,12(r27)
	REX_STORE_U8(ctx.r27.u32 + 12, ctx.r11.u8);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r10,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r10.u32);
	// bl 0x8214a794
	ctx.lr = 0x820E99CC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820E99D4;
	__imp__KfLowerIrql(ctx, base);
loc_820E99D4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
