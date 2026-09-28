DEFINE_REX_FUNC(sub_821436A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x821436B0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82143788
	if (ctx.cr6.eq) goto loc_82143788;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r30,-32221
	ctx.r30.s64 = -2111635456;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821436e4
	if (ctx.cr6.eq) goto loc_821436E4;
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821436E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
loc_821436E4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82145058
	ctx.lr = 0x821436EC;
	sub_82145058(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82143708
	if (ctx.cr6.eq) goto loc_82143708;
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82143704;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
loc_82143708:
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82143724
	if (ctx.cr6.eq) goto loc_82143724;
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82143720;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
loc_82143724:
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82143740
	if (ctx.cr6.eq) goto loc_82143740;
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8214373C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
loc_82143740:
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8214375c
	if (ctx.cr6.eq) goto loc_8214375C;
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82143758;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
loc_8214375C:
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82143778
	if (ctx.cr6.eq) goto loc_82143778;
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82143774;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
loc_82143778:
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82143788;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82143788:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
