DEFINE_REX_FUNC(sub_821422D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x821422E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821422f4
	if (!ctx.cr6.eq) goto loc_821422F4;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x82142388
	goto loc_82142388;
loc_821422F4:
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82142384
	if (ctx.cr6.eq) goto loc_82142384;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,64206
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64206, ctx.xer);
	// bne cr6,0x82142384
	if (!ctx.cr6.eq) goto loc_82142384;
	// lbz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// beq cr6,0x82142320
	if (ctx.cr6.eq) goto loc_82142320;
	// li r3,6115
	ctx.r3.s64 = 6115;
	// b 0x82142388
	goto loc_82142388;
loc_82142320:
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// bl 0x821436a8
	ctx.lr = 0x82142330;
	sub_821436A8(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lis r30,-32221
	ctx.r30.s64 = -2111635456;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82142350
	if (ctx.cr6.eq) goto loc_82142350;
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8214234C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r29.u32);
loc_82142350:
	// lwz r3,40(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8214236c
	if (ctx.cr6.eq) goto loc_8214236C;
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82142368;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r29.u32);
loc_8214236C:
	// lwz r11,24188(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24188);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8214237C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82142388
	goto loc_82142388;
loc_82142384:
	// li r3,6100
	ctx.r3.s64 = 6100;
loc_82142388:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
