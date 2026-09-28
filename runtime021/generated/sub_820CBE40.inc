DEFINE_REX_FUNC(sub_820CBE40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820CBE48;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8214a6e4
	ctx.lr = 0x820CBE54;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x820cbe64
	if (ctx.cr6.eq) goto loc_820CBE64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d2e58
	ctx.lr = 0x820CBE64;
	sub_820D2E58(ctx, base);
loc_820CBE64:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cbea8
	if (ctx.cr6.eq) goto loc_820CBEA8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820be620
	ctx.lr = 0x820CBE80;
	sub_820BE620(ctx, base);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_820CBE84:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820be2d8
	ctx.lr = 0x820CBE94;
	sub_820BE2D8(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x820cbe84
	if (ctx.cr6.lt) goto loc_820CBE84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c74d0
	ctx.lr = 0x820CBEA8;
	sub_820C74D0(ctx, base);
loc_820CBEA8:
	// lwz r3,14828(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 14828);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820cbebc
	if (ctx.cr6.eq) goto loc_820CBEBC;
	// bl 0x820c8178
	ctx.lr = 0x820CBEB8;
	sub_820C8178(ctx, base);
	// stw r29,14828(r31)
	REX_STORE_U32(ctx.r31.u32 + 14828, ctx.r29.u32);
loc_820CBEBC:
	// lwz r3,14832(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 14832);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820cbed0
	if (ctx.cr6.eq) goto loc_820CBED0;
	// bl 0x820c8178
	ctx.lr = 0x820CBECC;
	sub_820C8178(ctx, base);
	// stw r29,14832(r31)
	REX_STORE_U32(ctx.r31.u32 + 14832, ctx.r29.u32);
loc_820CBED0:
	// lwz r3,14824(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 14824);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820cbee4
	if (ctx.cr6.eq) goto loc_820CBEE4;
	// bl 0x820c8178
	ctx.lr = 0x820CBEE0;
	sub_820C8178(ctx, base);
	// stw r29,14824(r31)
	REX_STORE_U32(ctx.r31.u32 + 14824, ctx.r29.u32);
loc_820CBEE4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
