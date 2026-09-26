DEFINE_REX_FUNC(sub_820C01C0) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// lhz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// b 0x820c01f4
	goto loc_820C01F4;
loc_820C01E8:
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lhz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
loc_820C01F4:
	// cmplwi cr6,r9,255
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 255, ctx.xer);
	// bne cr6,0x820c01e8
	if (!ctx.cr6.eq) goto loc_820C01E8;
	// mulli r11,r11,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(12));
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// addi r3,r11,56
	ctx.r3.s64 = ctx.r11.s64 + 56;
	// bl 0x82136670
	ctx.lr = 0x820C020C;
	sub_82136670(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x820c021c
	if (!ctx.cr0.eq) goto loc_820C021C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820c022c
	goto loc_820C022C;
loc_820C021C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820c00d0
	ctx.lr = 0x820C0228;
	sub_820C00D0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820C022C:
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
