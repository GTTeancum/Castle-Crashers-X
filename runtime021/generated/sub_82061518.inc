DEFINE_REX_FUNC(sub_82061518) {
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
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,10
	ctx.r5.s64 = 10;
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x82061550;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820615c0
	if (ctx.cr6.eq) goto loc_820615C0;
	// lhz r11,34(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820615c0
	if (!ctx.cr6.eq) goto loc_820615C0;
	// lhz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820615a8
	if (ctx.cr6.lt) goto loc_820615A8;
	// beq cr6,0x8206159c
	if (ctx.cr6.eq) goto loc_8206159C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x820615ac
	if (!ctx.cr6.lt) goto loc_820615AC;
	// lbz r11,-22662(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + -22662);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820615ac
	if (!ctx.cr6.eq) goto loc_820615AC;
	// sth r11,24(r31)
	REX_STORE_U16(ctx.r31.u32 + 24, ctx.r11.u16);
	// b 0x820615ac
	goto loc_820615AC;
loc_8206159C:
	// li r11,2
	ctx.r11.s64 = 2;
	// sth r11,24(r31)
	REX_STORE_U16(ctx.r31.u32 + 24, ctx.r11.u16);
	// b 0x820615ac
	goto loc_820615AC;
loc_820615A8:
	// sth r9,24(r31)
	REX_STORE_U16(ctx.r31.u32 + 24, ctx.r9.u16);
loc_820615AC:
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r9,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r9.u16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,-22662(r10)
	REX_STORE_U8(ctx.r10.u32 + -22662, ctx.r11.u8);
	// bl 0x82060508
	ctx.lr = 0x820615C0;
	sub_82060508(ctx, base);
loc_820615C0:
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
