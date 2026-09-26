DEFINE_REX_FUNC(sub_8212C298) {
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
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lwz r11,3232(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 3232);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8212c2c0
	if (ctx.cr0.eq) goto loc_8212C2C0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212C2BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8212c2cc
	goto loc_8212C2CC;
loc_8212C2C0:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x821325c0
	ctx.lr = 0x8212C2C8;
	sub_821325C0(ctx, base);
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_8212C2CC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
