DEFINE_REX_FUNC(sub_820580F8) {
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
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// lhz r4,390(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 390);
	// bl 0x82053bc8
	ctx.lr = 0x82058110;
	sub_82053BC8(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-6628(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -6628);
	// stw r10,280(r11)
	REX_STORE_U32(ctx.r11.u32 + 280, ctx.r10.u32);
	// stb r10,272(r11)
	REX_STORE_U8(ctx.r11.u32 + 272, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
