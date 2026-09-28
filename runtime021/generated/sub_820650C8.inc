DEFINE_REX_FUNC(sub_820650C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32215
	ctx.r31.s64 = -2111242240;
	// lbz r11,2704(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 2704);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820650f0
	if (ctx.cr6.eq) goto loc_820650F0;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82065128
	goto loc_82065128;
loc_820650F0:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820b6818
	ctx.lr = 0x820650FC;
	sub_820B6818(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82065124
	if (!ctx.cr6.eq) goto loc_82065124;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82065124
	if (ctx.cr6.eq) goto loc_82065124;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r10,2704(r31)
	REX_STORE_U8(ctx.r31.u32 + 2704, ctx.r10.u8);
	// b 0x82065128
	goto loc_82065128;
loc_82065124:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82065128:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82065168
	if (!ctx.cr6.eq) goto loc_82065168;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,18628
	ctx.r4.s64 = ctx.r11.s64 + 18628;
	// bl 0x82053a00
	ctx.lr = 0x82065144;
	sub_82053A00(ctx, base);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,-6624(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -6624);
	// bl 0x820778d0
	ctx.lr = 0x82065154;
	sub_820778D0(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82065168:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r4,-6628(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82065180
	if (ctx.cr6.eq) goto loc_82065180;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x820a1d20
	ctx.lr = 0x82065180;
	sub_820A1D20(ctx, base);
loc_82065180:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,2780
	ctx.r3.s64 = ctx.r11.s64 + 2780;
	// bl 0x820b6908
	ctx.lr = 0x82065190;
	sub_820B6908(ctx, base);
}
