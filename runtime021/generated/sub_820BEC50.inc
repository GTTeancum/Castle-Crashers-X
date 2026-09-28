DEFINE_REX_FUNC(sub_820BEC50) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// lwz r3,23984(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 23984);
	// bl 0x82136708
	ctx.lr = 0x820BEC70;
	sub_82136708(ctx, base);
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// lwz r3,23992(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 23992);
	// bl 0x82136708
	ctx.lr = 0x820BEC7C;
	sub_82136708(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,23984(r31)
	REX_STORE_U32(ctx.r31.u32 + 23984, ctx.r11.u32);
	// stw r11,23992(r31)
	REX_STORE_U32(ctx.r31.u32 + 23992, ctx.r11.u32);
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
