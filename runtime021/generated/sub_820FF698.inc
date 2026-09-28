DEFINE_REX_FUNC(sub_820FF698) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x820FF6A0;
	__savegprlr_23(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// mr r23,r10
	ctx.r23.u64 = ctx.r10.u64;
	// bl 0x820fe5f8
	ctx.lr = 0x820FF6D4;
	sub_820FE5F8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x820ff7c0
	if (ctx.cr0.lt) goto loc_820FF7C0;
	// lwz r26,80(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821096c8
	ctx.lr = 0x820FF6FC;
	sub_821096C8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x820ff7c0
	if (ctx.cr0.lt) goto loc_820FF7C0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r6,84(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// bl 0x82109f58
	ctx.lr = 0x820FF718;
	sub_82109F58(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x820ff72c
	if (!ctx.cr0.eq) goto loc_820FF72C;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x820ff77c
	goto loc_820FF77C;
loc_820FF72C:
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820ff750
	if (!ctx.cr6.eq) goto loc_820FF750;
	// lwz r31,8(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x82136f58
	ctx.lr = 0x820FF740;
	sub_82136F58(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_820FF750:
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// lwz r9,292(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82109820
	ctx.lr = 0x820FF774;
	sub_82109820(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x820ff790
	if (!ctx.cr0.lt) goto loc_820FF790;
loc_820FF77C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820ff7c0
	if (ctx.cr6.eq) goto loc_820FF7C0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82109fc8
	ctx.lr = 0x820FF78C;
	sub_82109FC8(ctx, base);
	// b 0x820ff7c0
	goto loc_820FF7C0;
loc_820FF790:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82109548
	ctx.lr = 0x820FF798;
	sub_82109548(ctx, base);
	// addi r10,r30,412
	ctx.r10.s64 = ctx.r30.s64 + 412;
	// lwz r9,300(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 300);
	// addi r11,r29,12
	ctx.r11.s64 = ctx.r29.s64 + 12;
	// stw r10,12(r29)
	REX_STORE_U32(ctx.r29.u32 + 12, ctx.r10.u32);
	// lwz r10,416(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 416);
	// stw r10,16(r29)
	REX_STORE_U32(ctx.r29.u32 + 16, ctx.r10.u32);
	// lwz r10,416(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 416);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,416(r30)
	REX_STORE_U32(ctx.r30.u32 + 416, ctx.r11.u32);
	// stw r29,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r29.u32);
loc_820FF7C0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
