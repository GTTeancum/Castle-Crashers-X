DEFINE_REX_FUNC(sub_820CCA98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820ccabc
	if (!ctx.cr6.eq) goto loc_820CCABC;
	// lis r3,-32038
	ctx.r3.s64 = -2099642368;
	// ori r3,r3,23
	ctx.r3.u64 = ctx.r3.u64 | 23;
	// b 0x820ccb2c
	goto loc_820CCB2C;
loc_820CCABC:
	// lbz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 4);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,107
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 107, ctx.xer);
	// bgt cr6,0x820ccb0c
	if (ctx.cr6.gt) goto loc_820CCB0C;
	// beq cr6,0x820ccaf8
	if (ctx.cr6.eq) goto loc_820CCAF8;
	// cmpwi cr6,r11,97
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 97, ctx.xer);
	// beq cr6,0x820ccaf8
	if (ctx.cr6.eq) goto loc_820CCAF8;
	// cmpwi cr6,r11,98
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 98, ctx.xer);
	// ble cr6,0x820ccb28
	if (!ctx.cr6.gt) goto loc_820CCB28;
	// cmpwi cr6,r11,100
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 100, ctx.xer);
	// ble cr6,0x820ccaf8
	if (!ctx.cr6.gt) goto loc_820CCAF8;
	// cmpwi cr6,r11,101
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 101, ctx.xer);
	// ble cr6,0x820ccb28
	if (!ctx.cr6.gt) goto loc_820CCB28;
	// cmpwi cr6,r11,103
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 103, ctx.xer);
	// bgt cr6,0x820ccb28
	if (ctx.cr6.gt) goto loc_820CCB28;
loc_820CCAF8:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r4,r11,14312
	ctx.r4.s64 = ctx.r11.s64 + 14312;
	// bl 0x8214a804
	ctx.lr = 0x820CCB08;
	__imp__sprintf(ctx, base);
	// b 0x820ccb28
	goto loc_820CCB28;
loc_820CCB0C:
	// cmpwi cr6,r11,109
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 109, ctx.xer);
	// beq cr6,0x820ccb20
	if (ctx.cr6.eq) goto loc_820CCB20;
	// cmpwi cr6,r11,116
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 116, ctx.xer);
	// bne cr6,0x820ccb28
	if (!ctx.cr6.eq) goto loc_820CCB28;
	// b 0x820ccaf8
	goto loc_820CCAF8;
loc_820CCB20:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x820d1c30
	ctx.lr = 0x820CCB28;
	sub_820D1C30(ctx, base);
loc_820CCB28:
	// lis r3,730
	ctx.r3.s64 = 47841280;
loc_820CCB2C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
