DEFINE_REX_FUNC(sub_82129550) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8212a3b8
	ctx.lr = 0x8212956C;
	sub_8212A3B8(ctx, base);
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r31,r11,31200
	ctx.r31.s64 = ctx.r11.s64 + 31200;
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// beq 0x82129584
	if (ctx.cr0.eq) goto loc_82129584;
	// addi r11,r3,12
	ctx.r11.s64 = ctx.r3.s64 + 12;
loc_82129584:
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// bl 0x8212a3b8
	ctx.lr = 0x8212958C;
	sub_8212A3B8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// beq 0x8212959c
	if (ctx.cr0.eq) goto loc_8212959C;
	// addi r7,r3,8
	ctx.r7.s64 = ctx.r3.s64 + 8;
loc_8212959C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82129470
	ctx.lr = 0x821295A4;
	sub_82129470(ctx, base);
	// stw r3,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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
