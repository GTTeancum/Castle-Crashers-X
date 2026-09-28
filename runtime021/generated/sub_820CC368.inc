DEFINE_REX_FUNC(sub_820CC368) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cc390
	if (ctx.cr6.eq) goto loc_820CC390;
	// bl 0x820c74d0
	ctx.lr = 0x820CC390;
	sub_820C74D0(ctx, base);
loc_820CC390:
	// lwz r3,21640(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 21640);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820cc3ac
	if (ctx.cr6.eq) goto loc_820CC3AC;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// bl 0x82136708
	ctx.lr = 0x820CC3A8;
	sub_82136708(ctx, base);
	// stw r30,21640(r31)
	REX_STORE_U32(ctx.r31.u32 + 21640, ctx.r30.u32);
loc_820CC3AC:
	// lwz r3,21636(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 21636);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820cc3c8
	if (ctx.cr6.eq) goto loc_820CC3C8;
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// bl 0x82136708
	ctx.lr = 0x820CC3C0;
	sub_82136708(ctx, base);
	// stw r30,21636(r31)
	REX_STORE_U32(ctx.r31.u32 + 21636, ctx.r30.u32);
	// stw r30,21644(r31)
	REX_STORE_U32(ctx.r31.u32 + 21644, ctx.r30.u32);
loc_820CC3C8:
	// stw r30,21648(r31)
	REX_STORE_U32(ctx.r31.u32 + 21648, ctx.r30.u32);
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
