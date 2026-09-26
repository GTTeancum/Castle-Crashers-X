DEFINE_REX_FUNC(sub_82095FF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82095FF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r5,4
	ctx.r11.s64 = ctx.r5.s64 + 4;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
loc_8209600C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stbx r9,r10,r11
	REX_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x8209600c
	if (!ctx.cr6.eq) goto loc_8209600C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r29,r11,-1716
	ctx.r29.s64 = ctx.r11.s64 + -1716;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82128688
	ctx.lr = 0x82096034;
	sub_82128688(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82128688
	ctx.lr = 0x82096044;
	sub_82128688(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8209607c
	if (!ctx.cr6.eq) goto loc_8209607C;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lbz r30,-22602(r11)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r11.u32 + -22602);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8209b0e0
	ctx.lr = 0x82096064;
	sub_8209B0E0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r30,0(r31)
	REX_STORE_U16(ctx.r31.u32 + 0, ctx.r30.u16);
	// sth r10,2(r31)
	REX_STORE_U16(ctx.r31.u32 + 2, ctx.r10.u16);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8209607C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8209b030
	ctx.lr = 0x82096084;
	sub_8209B030(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8209b0e0
	ctx.lr = 0x8209608C;
	sub_8209B0E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r30,0(r31)
	REX_STORE_U16(ctx.r31.u32 + 0, ctx.r30.u16);
	// sth r11,2(r31)
	REX_STORE_U16(ctx.r31.u32 + 2, ctx.r11.u16);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
