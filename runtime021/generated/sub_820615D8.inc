DEFINE_REX_FUNC(sub_820615D8) {
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
	// bne cr6,0x82061748
	if (!ctx.cr6.eq) goto loc_82061748;
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
	ctx.lr = 0x82061628;
	sub_82053C70(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82061748
	if (ctx.cr6.eq) goto loc_82061748;
	// lhz r11,34(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82061748
	if (!ctx.cr6.eq) goto loc_82061748;
	// lhz r9,24(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82061678
	if (!ctx.cr6.eq) goto loc_82061678;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82061748
	if (ctx.cr6.eq) goto loc_82061748;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82061748
	if (!ctx.cr6.eq) goto loc_82061748;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82061748
	if (ctx.cr6.eq) goto loc_82061748;
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// b 0x8206169c
	goto loc_8206169C;
loc_82061678:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82061748
	if (ctx.cr6.eq) goto loc_82061748;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82061748
	if (!ctx.cr6.eq) goto loc_82061748;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82061748
	if (ctx.cr6.eq) goto loc_82061748;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
loc_8206169C:
	// cmplwi cr6,r10,10
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 10, ctx.xer);
	// blt cr6,0x82061748
	if (ctx.cr6.lt) goto loc_82061748;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x820616f0
	if (!ctx.cr6.eq) goto loc_820616F0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820616d0
	if (ctx.cr6.eq) goto loc_820616D0;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x820616d0
	if (!ctx.cr6.eq) goto loc_820616D0;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// b 0x820616d4
	goto loc_820616D4;
loc_820616D0:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_820616D4:
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
loc_820616F0:
	// lhz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// blt cr6,0x82061704
	if (ctx.cr6.lt) goto loc_82061704;
	// addi r11,r11,-9
	ctx.r11.s64 = ctx.r11.s64 + -9;
	// b 0x82061714
	goto loc_82061714;
loc_82061704:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// addi r11,r10,-8
	ctx.r11.s64 = ctx.r10.s64 + -8;
	// beq cr6,0x82061714
	if (ctx.cr6.eq) goto loc_82061714;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82061714:
	// lhz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// sth r11,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r11.u16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82061740
	if (!ctx.cr6.eq) goto loc_82061740;
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
loc_82061740:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82060508
	ctx.lr = 0x82061748;
	sub_82060508(ctx, base);
loc_82061748:
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
