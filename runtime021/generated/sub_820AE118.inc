DEFINE_REX_FUNC(sub_820AE118) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x820AE120;
	__savegprlr_21(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r24,292(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r22,r4
	ctx.r22.u64 = ctx.r4.u64;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// lwz r10,32(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// lwz r3,40(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 40);
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r21,r9
	ctx.r21.u64 = ctx.r9.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,288
	ctx.r4.s64 = 288;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820AE168;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820ae180
	if (!ctx.cr6.eq) goto loc_820AE180;
	// li r3,-4
	ctx.r3.s64 = -4;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
loc_820AE180:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r31,r11,16392
	ctx.r31.s64 = ctx.r11.s64 + 16392;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// addi r7,r31,-128
	ctx.r7.s64 = ctx.r31.s64 + -128;
	// addi r6,r31,-256
	ctx.r6.s64 = ctx.r31.s64 + -256;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// li r5,257
	ctx.r5.s64 = 257;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820adb18
	ctx.lr = 0x820AE1B8;
	sub_820ADB18(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x820ae2a4
	if (!ctx.cr6.eq) goto loc_820AE2A4;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ae2c0
	if (ctx.cr6.eq) goto loc_820AE2C0;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r7,r31,120
	ctx.r7.s64 = ctx.r31.s64 + 120;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// add r3,r11,r28
	ctx.r3.u64 = ctx.r11.u64 + ctx.r28.u64;
	// bl 0x820adb18
	ctx.lr = 0x820AE204;
	sub_820ADB18(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x820ae244
	if (!ctx.cr6.eq) goto loc_820AE244;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820ae224
	if (!ctx.cr6.eq) goto loc_820AE224;
	// cmplwi cr6,r29,257
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 257, ctx.xer);
	// bgt cr6,0x820ae274
	if (ctx.cr6.gt) goto loc_820AE274;
loc_820AE224:
	// lwz r3,40(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 40);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,36(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820AE238;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
loc_820AE244:
	// cmpwi cr6,r31,-3
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -3, ctx.xer);
	// bne cr6,0x820ae258
	if (!ctx.cr6.eq) goto loc_820AE258;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r10,r11,9212
	ctx.r10.s64 = ctx.r11.s64 + 9212;
	// b 0x820ae280
	goto loc_820AE280;
loc_820AE258:
	// cmpwi cr6,r31,-5
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -5, ctx.xer);
	// bne cr6,0x820ae26c
	if (!ctx.cr6.eq) goto loc_820AE26C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r10,r11,9244
	ctx.r10.s64 = ctx.r11.s64 + 9244;
	// b 0x820ae27c
	goto loc_820AE27C;
loc_820AE26C:
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// beq cr6,0x820ae284
	if (ctx.cr6.eq) goto loc_820AE284;
loc_820AE274:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r10,r11,9272
	ctx.r10.s64 = ctx.r11.s64 + 9272;
loc_820AE27C:
	// li r31,-3
	ctx.r31.s64 = -3;
loc_820AE280:
	// stw r10,24(r24)
	REX_STORE_U32(ctx.r24.u32 + 24, ctx.r10.u32);
loc_820AE284:
	// lwz r3,40(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 40);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,36(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820AE298;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
loc_820AE2A4:
	// cmpwi cr6,r26,-3
	ctx.cr6.compare<int32_t>(ctx.r26.s32, -3, ctx.xer);
	// bne cr6,0x820ae2b8
	if (!ctx.cr6.eq) goto loc_820AE2B8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r10,r11,9144
	ctx.r10.s64 = ctx.r11.s64 + 9144;
	// b 0x820ae2cc
	goto loc_820AE2CC;
loc_820AE2B8:
	// cmpwi cr6,r26,-4
	ctx.cr6.compare<int32_t>(ctx.r26.s32, -4, ctx.xer);
	// beq cr6,0x820ae2d0
	if (ctx.cr6.eq) goto loc_820AE2D0;
loc_820AE2C0:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r26,-3
	ctx.r26.s64 = -3;
	// addi r10,r11,9180
	ctx.r10.s64 = ctx.r11.s64 + 9180;
loc_820AE2CC:
	// stw r10,24(r24)
	REX_STORE_U32(ctx.r24.u32 + 24, ctx.r10.u32);
loc_820AE2D0:
	// lwz r3,40(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 40);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,36(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820AE2E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
