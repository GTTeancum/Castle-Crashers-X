DEFINE_REX_FUNC(sub_82127728) {
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
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,23264(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 23264);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8212774c
	if (ctx.cr0.eq) goto loc_8212774C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212774C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8212774C:
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x8212c368
	ctx.lr = 0x82127754;
	sub_8212C368(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212bcb8
	ctx.lr = 0x82127760;
	sub_8212BCB8(ctx, base);
	// bl 0x8212bc08
	ctx.lr = 0x82127764;
	sub_8212BC08(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
