DEFINE_REX_FUNC(sub_820B0D80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820B0D88;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x820b0da4
	if (!ctx.cr6.eq) goto loc_820B0DA4;
loc_820B0D98:
	// li r3,-102
	ctx.r3.s64 = -102;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820B0DA4:
	// lwz r31,124(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 124);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820b0d98
	if (ctx.cr6.eq) goto loc_820B0D98;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r29,-32234
	ctx.r29.s64 = -2112487424;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820b0dcc
	if (ctx.cr6.eq) goto loc_820B0DCC;
	// lwz r11,-28288(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -28288);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820B0DCC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820B0DCC:
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b0de8
	if (ctx.cr6.eq) goto loc_820B0DE8;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x820ad370
	ctx.lr = 0x820B0DE8;
	sub_820AD370(ctx, base);
loc_820B0DE8:
	// lwz r11,-28288(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -28288);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r30.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820B0DFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r30,124(r28)
	REX_STORE_U32(ctx.r28.u32 + 124, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
