DEFINE_REX_FUNC(sub_820B7958) {
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
	// bl 0x820b7880
	ctx.lr = 0x820B7968;
	sub_820B7880(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820b79a0
	if (!ctx.cr0.eq) goto loc_820B79A0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1676(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1676);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b7998
	if (ctx.cr6.eq) goto loc_820B7998;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820B7998;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820B7998:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8214a694
	ctx.lr = 0x820B79A0;
	__imp__HalReturnToFirmware(ctx, base);
loc_820B79A0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
