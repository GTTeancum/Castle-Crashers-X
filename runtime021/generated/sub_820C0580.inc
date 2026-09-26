DEFINE_REX_FUNC(sub_820C0580) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820C0588;
	__savegprlr_29(ctx, base);
	// stwu r1,-1648(r1)
	ea = -1648 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lis r11,10280
	ctx.r11.s64 = 673710080;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// ori r30,r11,310
	ctx.r30.u64 = ctx.r11.u64 | 310;
	// bne cr6,0x820c05cc
	if (!ctx.cr6.eq) goto loc_820C05CC;
	// cmpw cr6,r31,r30
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r30.s32, ctx.xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bne cr6,0x820c05c4
	if (!ctx.cr6.eq) goto loc_820C05C4;
	// bl 0x820c90e0
	ctx.lr = 0x820C05BC;
	sub_820C90E0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// b 0x820c05d4
	goto loc_820C05D4;
loc_820C05C4:
	// bl 0x820c9090
	ctx.lr = 0x820C05C8;
	sub_820C9090(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
loc_820C05CC:
	// cmpw cr6,r31,r30
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r30.s32, ctx.xer);
	// bne cr6,0x820c05e0
	if (!ctx.cr6.eq) goto loc_820C05E0;
loc_820C05D4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820c8f90
	ctx.lr = 0x820C05DC;
	sub_820C8F90(ctx, base);
	// b 0x820c05e8
	goto loc_820C05E8;
loc_820C05E0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820c8e98
	ctx.lr = 0x820C05E8;
	sub_820C8E98(ctx, base);
loc_820C05E8:
	// addi r1,r1,1648
	ctx.r1.s64 = ctx.r1.s64 + 1648;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
