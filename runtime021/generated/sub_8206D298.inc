DEFINE_REX_FUNC(sub_8206D298) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,217
	ctx.r11.s64 = 217;
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-6624(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x8206D2CC;
	sub_82052EA8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r4,-6628(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + -6628);
	// bl 0x820a37b8
	ctx.lr = 0x8206D2E8;
	sub_820A37B8(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r7,9424
	ctx.r4.s64 = ctx.r7.s64 + 9424;
	// bl 0x82053a00
	ctx.lr = 0x8206D2F8;
	sub_82053A00(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,-6624(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// bl 0x82077a98
	ctx.lr = 0x8206D304;
	sub_82077A98(ctx, base);
	// lwz r5,48(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,-6624(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r11,10(r5)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r5.u32 + 10);
	// extsh r5,r11
	ctx.r5.s64 = ctx.r11.s16;
	// bl 0x82077310
	ctx.lr = 0x8206D320;
	sub_82077310(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
