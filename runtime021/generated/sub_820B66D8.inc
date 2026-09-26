DEFINE_REX_FUNC(sub_820B66D8) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,259
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 259, ctx.xer);
	// bne cr6,0x820b6744
	if (!ctx.cr6.eq) goto loc_820B6744;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x820b6724
	if (ctx.cr6.eq) goto loc_820B6724;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b6718
	if (ctx.cr6.eq) goto loc_820B6718;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_820B6718:
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x820b6020
	ctx.lr = 0x820B6720;
	sub_820B6020(ctx, base);
	// b 0x820b6728
	goto loc_820B6728;
loc_820B6724:
	// li r3,258
	ctx.r3.s64 = 258;
loc_820B6728:
	// cmplwi cr6,r3,258
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 258, ctx.xer);
	// bne cr6,0x820b673c
	if (!ctx.cr6.eq) goto loc_820B673C;
	// li r3,996
	ctx.r3.s64 = 996;
	// bl 0x820b73c8
	ctx.lr = 0x820B6738;
	sub_820B73C8(ctx, base);
	// b 0x820b6764
	goto loc_820B6764;
loc_820B673C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820b6764
	if (!ctx.cr6.eq) goto loc_820B6764;
loc_820B6744:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820b6760
	if (ctx.cr6.lt) goto loc_820B6760;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820b6768
	goto loc_820B6768;
loc_820B6760:
	// bl 0x820b7290
	ctx.lr = 0x820B6764;
	sub_820B7290(ctx, base);
loc_820B6764:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820B6768:
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
