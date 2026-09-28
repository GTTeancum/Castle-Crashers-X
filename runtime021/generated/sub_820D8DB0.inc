DEFINE_REX_FUNC(sub_820D8DB0) {
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
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r10,r11,22876
	ctx.r10.s64 = ctx.r11.s64 + 22876;
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x820d8de4
	if (!ctx.cr6.eq) goto loc_820D8DE4;
	// bl 0x820d89d8
	ctx.lr = 0x820D8DD0;
	sub_820D89D8(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,22892
	ctx.r3.s64 = ctx.r11.s64 + 22892;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8214a9a4
	ctx.lr = 0x820D8DE4;
	__imp__KeSetEvent(ctx, base);
loc_820D8DE4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
