DEFINE_REX_FUNC(sub_820CB370) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820CB378;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// addi r4,r11,7720
	ctx.r4.s64 = ctx.r11.s64 + 7720;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x820cb088
	ctx.lr = 0x820CB398;
	sub_820CB088(ctx, base);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x820cb460
	if (!ctx.cr6.eq) goto loc_820CB460;
	// lwz r11,152(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 152);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820cb3c4
	if (!ctx.cr6.eq) goto loc_820CB3C4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r6,164(r26)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r26.u32 + 164);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,172(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 172);
	// addi r4,r11,7592
	ctx.r4.s64 = ctx.r11.s64 + 7592;
	// bl 0x820cb088
	ctx.lr = 0x820CB3C4;
	sub_820CB088(ctx, base);
loc_820CB3C4:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r4,r11,7456
	ctx.r4.s64 = ctx.r11.s64 + 7456;
	// bl 0x820cb088
	ctx.lr = 0x820CB3D4;
	sub_820CB088(ctx, base);
	// lwz r30,116(r26)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r26.u32 + 116);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820cb434
	if (ctx.cr6.eq) goto loc_820CB434;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r27,r11,7432
	ctx.r27.s64 = ctx.r11.s64 + 7432;
loc_820CB3E8:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x820cb428
	if (!ctx.cr6.gt) goto loc_820CB428;
	// addi r31,r30,12
	ctx.r31.s64 = ctx.r30.s64 + 12;
loc_820CB3FC:
	// lwz r11,-4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// clrlwi r6,r11,8
	ctx.r6.u64 = ctx.r11.u32 & 0xFFFFFF;
	// bl 0x820cb088
	ctx.lr = 0x820CB414;
	sub_820CB088(ctx, base);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820cb3fc
	if (ctx.cr6.lt) goto loc_820CB3FC;
loc_820CB428:
	// lwz r30,0(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820cb3e8
	if (!ctx.cr6.eq) goto loc_820CB3E8;
loc_820CB434:
	// lwz r11,152(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 152);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820cb460
	if (!ctx.cr6.eq) goto loc_820CB460;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r4,r11,7288
	ctx.r4.s64 = ctx.r11.s64 + 7288;
	// bl 0x820cb088
	ctx.lr = 0x820CB450;
	sub_820CB088(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r4,r11,7144
	ctx.r4.s64 = ctx.r11.s64 + 7144;
	// bl 0x820cb088
	ctx.lr = 0x820CB460;
	sub_820CB088(ctx, base);
loc_820CB460:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
