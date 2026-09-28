DEFINE_REX_FUNC(sub_82149B18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r31,r11,-22576
	ctx.r31.s64 = ctx.r11.s64 + -22576;
	// addi r4,r10,-10088
	ctx.r4.s64 = ctx.r10.s64 + -10088;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053a00
	ctx.lr = 0x82149B40;
	sub_82053A00(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r3,r31,68
	ctx.r3.s64 = ctx.r31.s64 + 68;
	// addi r4,r9,-10100
	ctx.r4.s64 = ctx.r9.s64 + -10100;
	// bl 0x82053a00
	ctx.lr = 0x82149B50;
	sub_82053A00(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r3,r31,136
	ctx.r3.s64 = ctx.r31.s64 + 136;
	// addi r4,r8,-10112
	ctx.r4.s64 = ctx.r8.s64 + -10112;
	// bl 0x82053a00
	ctx.lr = 0x82149B60;
	sub_82053A00(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r3,r31,204
	ctx.r3.s64 = ctx.r31.s64 + 204;
	// addi r4,r7,-10124
	ctx.r4.s64 = ctx.r7.s64 + -10124;
	// bl 0x82053a00
	ctx.lr = 0x82149B70;
	sub_82053A00(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
