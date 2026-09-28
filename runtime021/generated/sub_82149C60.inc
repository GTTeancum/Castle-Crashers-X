DEFINE_REX_FUNC(sub_82149C60) {
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
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r31,r11,-8
	ctx.r31.s64 = ctx.r11.s64 + -8;
	// addi r4,r10,-4380
	ctx.r4.s64 = ctx.r10.s64 + -4380;
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x82053380
	ctx.lr = 0x82149C8C;
	sub_82053380(ctx, base);
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r31,32
	ctx.r3.s64 = ctx.r31.s64 + 32;
	// bl 0x82075298
	ctx.lr = 0x82149C98;
	sub_82075298(ctx, base);
	// lis r9,-32235
	ctx.r9.s64 = -2112552960;
	// addi r3,r9,-24512
	ctx.r3.s64 = ctx.r9.s64 + -24512;
	// bl 0x82127fb0
	ctx.lr = 0x82149CA4;
	sub_82127FB0(ctx, base);
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
