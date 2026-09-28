DEFINE_REX_FUNC(sub_8211B0B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82123db0
	ctx.lr = 0x8211B0CC;
	sub_82123DB0(ctx, base);
	// addi r31,r31,872
	ctx.r31.s64 = ctx.r31.s64 + 872;
loc_8211B0D0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lhz r4,90(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 90);
	// bl 0x82123aa0
	ctx.lr = 0x8211B0DC;
	sub_82123AA0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82119f20
	ctx.lr = 0x8211B0E4;
	sub_82119F20(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8211b0d0
	if (!ctx.cr0.eq) goto loc_8211B0D0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
