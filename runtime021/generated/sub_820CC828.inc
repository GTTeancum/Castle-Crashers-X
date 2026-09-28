DEFINE_REX_FUNC(sub_820CC828) {
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
	// lwz r4,21680(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 21680);
	// bl 0x820c0a98
	ctx.lr = 0x820CC844;
	sub_820C0A98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,21696(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 21696);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r5,21688(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 21688);
	// lwz r4,21684(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 21684);
	// bl 0x820d1788
	ctx.lr = 0x820CC85C;
	sub_820D1788(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,21700(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 21700);
	// lwz r4,21680(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 21680);
	// bl 0x820c0580
	ctx.lr = 0x820CC86C;
	sub_820C0580(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7228
	ctx.lr = 0x820CC874;
	sub_820C7228(ctx, base);
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
