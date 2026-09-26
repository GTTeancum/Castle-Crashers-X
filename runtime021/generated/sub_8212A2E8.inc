DEFINE_REX_FUNC(sub_8212A2E8) {
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
	// lis r30,-32235
	ctx.r30.s64 = -2112552960;
	// lwz r3,31240(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 31240);
	// bl 0x8214acc4
	ctx.lr = 0x8212A308;
	__imp__KeTlsGetValue(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8212a324
	if (!ctx.cr0.eq) goto loc_8212A324;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r3,31240(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 31240);
	// lwz r4,23248(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 23248);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x8214acd4
	ctx.lr = 0x8212A324;
	__imp__KeTlsSetValue(ctx, base);
loc_8212A324:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
