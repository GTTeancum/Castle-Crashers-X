DEFINE_REX_FUNC(sub_82061760) {
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
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,24828(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24828);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820618d4
	if (!ctx.cr6.eq) goto loc_820618D4;
	// li r9,10
	ctx.r9.s64 = 10;
	// lwz r5,48(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,24828(r11)
	REX_STORE_U32(ctx.r11.u32 + 24828, ctx.r9.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// lhz r4,10(r5)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r5.u32 + 10);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,10
	ctx.r5.s64 = 10;
	// bl 0x82053c70
	ctx.lr = 0x820617B0;
	sub_82053C70(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820618d4
	if (ctx.cr6.eq) goto loc_820618D4;
	// lhz r11,34(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820618d4
	if (!ctx.cr6.eq) goto loc_820618D4;
	// lhz r9,24(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82061800
	if (!ctx.cr6.eq) goto loc_82061800;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820618d4
	if (ctx.cr6.eq) goto loc_820618D4;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x820618d4
	if (!ctx.cr6.eq) goto loc_820618D4;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820618d4
	if (ctx.cr6.eq) goto loc_820618D4;
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// b 0x82061824
	goto loc_82061824;
loc_82061800:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820618d4
	if (ctx.cr6.eq) goto loc_820618D4;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x820618d4
	if (!ctx.cr6.eq) goto loc_820618D4;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820618d4
	if (ctx.cr6.eq) goto loc_820618D4;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
loc_82061824:
	// cmplwi cr6,r10,10
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 10, ctx.xer);
	// blt cr6,0x820618d4
	if (ctx.cr6.lt) goto loc_820618D4;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x82061878
	if (!ctx.cr6.eq) goto loc_82061878;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82061858
	if (ctx.cr6.eq) goto loc_82061858;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x82061858
	if (!ctx.cr6.eq) goto loc_82061858;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// b 0x8206185c
	goto loc_8206185C;
loc_82061858:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8206185C:
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r11,1
	ctx.r11.s64 = 1;
	// sth r8,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r8.u16);
	// sth r7,24(r31)
	REX_STORE_U16(ctx.r31.u32 + 24, ctx.r7.u16);
	// stb r11,-22662(r9)
	REX_STORE_U8(ctx.r9.u32 + -22662, ctx.r11.u8);
loc_82061878:
	// lhz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 28);
	// addi r11,r11,9
	ctx.r11.s64 = ctx.r11.s64 + 9;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82061890
	if (!ctx.cr6.gt) goto loc_82061890;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820618a0
	goto loc_820618A0;
loc_82061890:
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// bgt cr6,0x820618a0
	if (ctx.cr6.gt) goto loc_820618A0;
	// addi r11,r10,-8
	ctx.r11.s64 = ctx.r10.s64 + -8;
loc_820618A0:
	// sth r11,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r11.u16);
	// lhz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820618cc
	if (!ctx.cr6.eq) goto loc_820618CC;
	// li r11,3
	ctx.r11.s64 = 3;
	// sth r11,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r11.u16);
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
loc_820618CC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82060508
	ctx.lr = 0x820618D4;
	sub_82060508(ctx, base);
loc_820618D4:
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
