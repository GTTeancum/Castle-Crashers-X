DEFINE_REX_FUNC(sub_820B4580) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820B4588;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x820b4680
	if (ctx.cr6.eq) goto loc_820B4680;
loc_820B45A4:
	// cmpw cr6,r5,r7
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x820b45b8
	if (!ctx.cr6.lt) goto loc_820B45B8;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// b 0x820b45c0
	goto loc_820B45C0;
loc_820B45B8:
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
loc_820B45C0:
	// cmpw cr6,r26,r4
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x820b45cc
	if (!ctx.cr6.lt) goto loc_820B45CC;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
loc_820B45CC:
	// cmpw cr6,r26,r9
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x820b45d8
	if (!ctx.cr6.gt) goto loc_820B45D8;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
loc_820B45D8:
	// cmpw cr6,r6,r8
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x820b45ec
	if (!ctx.cr6.lt) goto loc_820B45EC;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// b 0x820b45f4
	goto loc_820B45F4;
loc_820B45EC:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
loc_820B45F4:
	// cmpw cr6,r25,r10
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x820b4600
	if (!ctx.cr6.lt) goto loc_820B4600;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_820B4600:
	// cmpw cr6,r25,r11
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x820b460c
	if (!ctx.cr6.gt) goto loc_820B460C;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_820B460C:
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subf r11,r4,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r4.u64;
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmpwi cr6,r10,64
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 64, ctx.xer);
	// blt cr6,0x820b4680
	if (ctx.cr6.lt) goto loc_820B4680;
	// add r11,r5,r7
	ctx.r11.u64 = ctx.r5.u64 + ctx.r7.u64;
	// add r10,r6,r8
	ctx.r10.u64 = ctx.r6.u64 + ctx.r8.u64;
	// add r9,r7,r26
	ctx.r9.u64 = ctx.r7.u64 + ctx.r26.u64;
	// srawi r7,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 1;
	// add r4,r8,r25
	ctx.r4.u64 = ctx.r8.u64 + ctx.r25.u64;
	// srawi r8,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 1;
	// srawi r31,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r9.s32 >> 1;
	// srawi r30,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r30.s64 = ctx.r4.s32 >> 1;
	// add r3,r31,r7
	ctx.r3.u64 = ctx.r31.u64 + ctx.r7.u64;
	// add r11,r30,r8
	ctx.r11.u64 = ctx.r30.u64 + ctx.r8.u64;
	// srawi r29,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r29.s64 = ctx.r3.s32 >> 1;
	// srawi r28,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r28.s64 = ctx.r11.s32 >> 1;
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x820b4580
	ctx.lr = 0x820B4668;
	sub_820B4580(ctx, base);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne cr6,0x820b45a4
	if (!ctx.cr6.eq) goto loc_820B45A4;
loc_820B4680:
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// lwz r8,72(r24)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r24.u32 + 72);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r7,68(r24)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r24.u32 + 68);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r6,64(r24)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r24.u32 + 64);
	// bl 0x820b4370
	ctx.lr = 0x820B469C;
	sub_820B4370(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
