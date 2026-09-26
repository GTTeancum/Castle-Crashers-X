DEFINE_REX_FUNC(sub_82122608) {
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
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// ld r11,40(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 40);
	// add r4,r4,r11
	ctx.r4.u64 = ctx.r4.u64 + ctx.r11.u64;
	// bl 0x821224c8
	ctx.lr = 0x82122628;
	sub_821224C8(ctx, base);
	// std r4,40(r8)
	REX_STORE_U64(ctx.r8.u32 + 40, ctx.r4.u64);
	// stw r7,52(r8)
	REX_STORE_U32(ctx.r8.u32 + 52, ctx.r7.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
