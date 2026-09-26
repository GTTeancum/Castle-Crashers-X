DEFINE_REX_FUNC(sub_820836E0) {
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
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r11,2820
	ctx.r31.s64 = ctx.r11.s64 + 2820;
	// lwz r11,2868(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 2868);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82083798
	if (!ctx.cr6.eq) goto loc_82083798;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// addi r9,r10,-7056
	ctx.r9.s64 = ctx.r10.s64 + -7056;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,2868(r8)
	REX_STORE_U32(ctx.r8.u32 + 2868, ctx.r11.u32);
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stb r11,20(r31)
	REX_STORE_U8(ctx.r31.u32 + 20, ctx.r11.u8);
	// li r11,255
	ctx.r11.s64 = 255;
	// stw r9,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stw r10,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// li r10,255
	ctx.r10.s64 = 255;
	// sth r9,24(r31)
	REX_STORE_U16(ctx.r31.u32 + 24, ctx.r9.u16);
	// li r9,255
	ctx.r9.s64 = 255;
	// sth r11,32(r31)
	REX_STORE_U16(ctx.r31.u32 + 32, ctx.r11.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,40(r31)
	REX_STORE_U16(ctx.r31.u32 + 40, ctx.r10.u16);
	// sth r9,30(r31)
	REX_STORE_U16(ctx.r31.u32 + 30, ctx.r9.u16);
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r10,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r10.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,42(r31)
	REX_STORE_U16(ctx.r31.u32 + 42, ctx.r11.u16);
	// sth r11,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r11.u16);
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// sth r9,38(r31)
	REX_STORE_U16(ctx.r31.u32 + 38, ctx.r9.u16);
	// sth r10,36(r31)
	REX_STORE_U16(ctx.r31.u32 + 36, ctx.r10.u16);
	// addi r3,r11,-24536
	ctx.r3.s64 = ctx.r11.s64 + -24536;
	// stw r9,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// bl 0x82127fb0
	ctx.lr = 0x82083798;
	sub_82127FB0(ctx, base);
loc_82083798:
	// lwz r3,76(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 76);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820837a8
	if (!ctx.cr6.eq) goto loc_820837A8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820837A8:
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
