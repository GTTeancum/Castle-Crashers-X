DEFINE_REX_FUNC(sub_82062388) {
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
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r4,-6628(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820623ac
	if (ctx.cr6.eq) goto loc_820623AC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820a1d20
	ctx.lr = 0x820623AC;
	sub_820A1D20(ctx, base);
loc_820623AC:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,2780
	ctx.r3.s64 = ctx.r11.s64 + 2780;
	// bl 0x820b6908
	ctx.lr = 0x820623BC;
	sub_820B6908(ctx, base);
}
