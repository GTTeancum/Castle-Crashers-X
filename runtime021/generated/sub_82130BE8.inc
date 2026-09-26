DEFINE_REX_FUNC(sub_82130BE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x82130c14
	if (ctx.cr6.eq) goto loc_82130C14;
	// ble cr6,0x82130c20
	if (!ctx.cr6.gt) goto loc_82130C20;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bgt cr6,0x82130c20
	if (ctx.cr6.gt) goto loc_82130C20;
	// bl 0x821294e0
	ctx.lr = 0x82130C0C;
	sub_821294E0(ctx, base);
	// li r11,34
	ctx.r11.s64 = 34;
	// b 0x82130c1c
	goto loc_82130C1C;
loc_82130C14:
	// bl 0x821294e0
	ctx.lr = 0x82130C18;
	sub_821294E0(ctx, base);
	// li r11,33
	ctx.r11.s64 = 33;
loc_82130C1C:
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_82130C20:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
