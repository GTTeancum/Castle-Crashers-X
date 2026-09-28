DEFINE_REX_FUNC(sub_8212C038) {
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
	// bl 0x82129468
	ctx.lr = 0x8212C048;
	sub_82129468(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lbz r11,23220(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 23220);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8212c05c
	if (ctx.cr0.eq) goto loc_8212C05C;
	// bl 0x821324d8
	ctx.lr = 0x8212C05C;
	sub_821324D8(ctx, base);
loc_8212C05C:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lwz r3,3236(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 3236);
	// bl 0x82129880
	ctx.lr = 0x8212C068;
	sub_82129880(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
