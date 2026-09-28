DEFINE_REX_FUNC(sub_82058138) {
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
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r6,1
	ctx.r6.s64 = 1;
	// lhz r5,52(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x82058170;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820581f0
	if (ctx.cr6.eq) goto loc_820581F0;
	// lhz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820581a4
	if (ctx.cr6.lt) goto loc_820581A4;
	// beq cr6,0x8205819c
	if (ctx.cr6.eq) goto loc_8205819C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x820581b0
	if (!ctx.cr6.eq) goto loc_820581B0;
	// li r4,33
	ctx.r4.s64 = 33;
	// b 0x820581a8
	goto loc_820581A8;
loc_8205819C:
	// li r4,34
	ctx.r4.s64 = 34;
	// b 0x820581a8
	goto loc_820581A8;
loc_820581A4:
	// li r4,32
	ctx.r4.s64 = 32;
loc_820581A8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x820581B0;
	sub_82053BC8(ctx, base);
loc_820581B0:
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r11,20(r31)
	REX_STORE_U8(ctx.r31.u32 + 20, ctx.r11.u8);
	// li r7,2
	ctx.r7.s64 = 2;
	// sth r9,16(r31)
	REX_STORE_U16(ctx.r31.u32 + 16, ctx.r9.u16);
	// sth r8,18(r31)
	REX_STORE_U16(ctx.r31.u32 + 18, ctx.r8.u16);
	// lwz r6,24(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// sth r7,102(r6)
	REX_STORE_U16(ctx.r6.u32 + 102, ctx.r7.u16);
	// lhz r5,12(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// cmplwi cr6,r5,1
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1, ctx.xer);
	// beq cr6,0x820581f0
	if (ctx.cr6.eq) goto loc_820581F0;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,28(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// sth r11,102(r9)
	REX_STORE_U16(ctx.r9.u32 + 102, ctx.r11.u16);
loc_820581F0:
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
