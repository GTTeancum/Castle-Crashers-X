DEFINE_REX_FUNC(sub_821151C8) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bne cr6,0x821151ec
	if (!ctx.cr6.eq) goto loc_821151EC;
	// addi r3,r3,-200
	ctx.r3.s64 = ctx.r3.s64 + -200;
	// bl 0x82118268
	ctx.lr = 0x821151E8;
	sub_82118268(ctx, base);
	// b 0x821151f4
	goto loc_821151F4;
loc_821151EC:
	// addi r3,r3,-1060
	ctx.r3.s64 = ctx.r3.s64 + -1060;
	// bl 0x8211e870
	ctx.lr = 0x821151F4;
	sub_8211E870(ctx, base);
loc_821151F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
