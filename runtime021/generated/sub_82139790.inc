DEFINE_REX_FUNC(sub_82139790) {
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
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// blt cr6,0x821397f4
	if (ctx.cr6.lt) goto loc_821397F4;
	// beq cr6,0x821397d0
	if (ctx.cr6.eq) goto loc_821397D0;
	// cmplwi cr6,r4,3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 3, ctx.xer);
	// blt cr6,0x821397c4
	if (ctx.cr6.lt) goto loc_821397C4;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,87
	ctx.r31.u64 = ctx.r31.u64 | 87;
	// b 0x821397fc
	goto loc_821397FC;
loc_821397C4:
	// addi r3,r3,1272
	ctx.r3.s64 = ctx.r3.s64 + 1272;
	// bl 0x8214a444
	ctx.lr = 0x821397CC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x821397fc
	goto loc_821397FC;
loc_821397D0:
	// addi r3,r3,1272
	ctx.r3.s64 = ctx.r3.s64 + 1272;
	// bl 0x8214abb4
	ctx.lr = 0x821397D8;
	__imp__RtlTryEnterCriticalSection(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// bne cr6,0x821397e8
	if (!ctx.cr6.eq) goto loc_821397E8;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x821397fc
	goto loc_821397FC;
loc_821397E8:
	// lis r31,-32768
	ctx.r31.s64 = -2147483648;
	// ori r31,r31,16388
	ctx.r31.u64 = ctx.r31.u64 | 16388;
	// b 0x821397fc
	goto loc_821397FC;
loc_821397F4:
	// addi r3,r3,1272
	ctx.r3.s64 = ctx.r3.s64 + 1272;
	// bl 0x8214a434
	ctx.lr = 0x821397FC;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_821397FC:
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
