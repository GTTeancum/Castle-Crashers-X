DEFINE_REX_FUNC(sub_82149958) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214add4
	ctx.lr = 0x8214996C;
	__imp__NtCancelTimer(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82149980
	if (!ctx.cr0.lt) goto loc_82149980;
	// bl 0x820b7290
	ctx.lr = 0x82149978;
	sub_820B7290(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82149984
	goto loc_82149984;
loc_82149980:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82149984:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
