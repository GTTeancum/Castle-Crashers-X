DEFINE_REX_FUNC(sub_820C6A40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x820C6A48;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// lwz r11,11008(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 11008);
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820c6adc
	if (ctx.cr6.eq) goto loc_820C6ADC;
	// addi r24,r30,11012
	ctx.r24.s64 = ctx.r30.s64 + 11012;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8214a754
	ctx.lr = 0x820C6A80;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r11,11008(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 11008);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820c6ac8
	if (ctx.cr6.eq) goto loc_820C6AC8;
	// oris r11,r27,33024
	ctx.r11.u64 = ctx.r27.u64 | 2164260864;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r10,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x820c6178
	ctx.lr = 0x820C6AB8;
	sub_820C6178(ctx, base);
	// lwz r11,11008(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 11008);
	// li r29,1
	ctx.r29.s64 = 1;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r11,11008(r30)
	REX_STORE_U32(ctx.r30.u32 + 11008, ctx.r11.u32);
loc_820C6AC8:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8214a744
	ctx.lr = 0x820C6AD4;
	__imp__KfReleaseSpinLock(ctx, base);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x820c6b08
	if (!ctx.cr6.eq) goto loc_820C6B08;
loc_820C6ADC:
	// lwz r11,11008(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 11008);
	// clrlwi r10,r27,8
	ctx.r10.u64 = ctx.r27.u32 & 0xFFFFFF;
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// oris r10,r10,33024
	ctx.r10.u64 = ctx.r10.u64 | 2164260864;
	// stw r11,11008(r30)
	REX_STORE_U32(ctx.r30.u32 + 11008, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820c65a8
	ctx.lr = 0x820C6B08;
	sub_820C65A8(ctx, base);
loc_820C6B08:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
