DEFINE_REX_FUNC(sub_820B5FE8) {
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
	// bl 0x8214a4b4
	ctx.lr = 0x820B5FF8;
	__imp__NtReleaseSemaphore(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820b6008
	if (ctx.cr0.lt) goto loc_820B6008;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820b6010
	goto loc_820B6010;
loc_820B6008:
	// bl 0x820b73c0
	ctx.lr = 0x820B600C;
	sub_820B73C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_820B6010:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
