DEFINE_REX_FUNC(sub_82065008) {
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
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,15
	ctx.r5.s64 = 15;
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x82065044;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820650ac
	if (ctx.cr6.eq) goto loc_820650AC;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lwz r11,-6628(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -6628);
	// lhz r6,10(r10)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// lwz r30,-6596(r7)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r7.u32 + -6596);
	// extsh r31,r6
	ctx.r31.s64 = ctx.r6.s16;
	// lwz r5,36(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// slw r4,r8,r31
	ctx.r4.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r31.u8 & 0x3F));
	// and r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 & ctx.r4.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820650ac
	if (ctx.cr6.eq) goto loc_820650AC;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5d50
	ctx.lr = 0x82065098;
	sub_820B5D50(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820650ac
	if (!ctx.cr6.eq) goto loc_820650AC;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,59644
	ctx.r10.u64 = ctx.r11.u64 | 59644;
	// stwx r31,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r31.u32);
loc_820650AC:
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
