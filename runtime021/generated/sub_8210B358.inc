DEFINE_REX_FUNC(sub_8210B358) {
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
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r5,36
	ctx.r5.s64 = 36;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8210b394
	if (!ctx.cr6.eq) goto loc_8210B394;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r31,r31,1245
	ctx.r31.u64 = ctx.r31.u64 | 1245;
	// bl 0x82129fa0
	ctx.lr = 0x8210B390;
	sub_82129FA0(ctx, base);
	// b 0x8210b3a0
	goto loc_8210B3A0;
loc_8210B394:
	// addi r4,r11,44
	ctx.r4.s64 = ctx.r11.s64 + 44;
	// bl 0x82129a70
	ctx.lr = 0x8210B39C;
	sub_82129A70(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
loc_8210B3A0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
