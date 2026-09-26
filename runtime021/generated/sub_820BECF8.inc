DEFINE_REX_FUNC(sub_820BECF8) {
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
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,1488(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1488);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820bed3c
	if (ctx.cr6.eq) goto loc_820BED3C;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820bed3c
	if (ctx.cr6.eq) goto loc_820BED3C;
	// li r3,2
	ctx.r3.s64 = 2;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820BED3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820BED3C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c74d0
	ctx.lr = 0x820BED44;
	sub_820C74D0(ctx, base);
	// addi r30,r31,14944
	ctx.r30.s64 = ctx.r31.s64 + 14944;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a434
	ctx.lr = 0x820BED50;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,11320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 11320);
	// lbz r10,10942(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 10942);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mulli r11,r11,80
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(80));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// lwz r11,11376(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 11376);
	// stb r10,10942(r31)
	REX_STORE_U8(ctx.r31.u32 + 10942, ctx.r10.u8);
	// stw r11,10888(r31)
	REX_STORE_U32(ctx.r31.u32 + 10888, ctx.r11.u32);
	// bl 0x8214a444
	ctx.lr = 0x820BED78;
	__imp__RtlLeaveCriticalSection(ctx, base);
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
