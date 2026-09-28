DEFINE_REX_FUNC(sub_821304E8) {
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
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8213051c
	if (ctx.cr6.eq) goto loc_8213051C;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r10,-19804(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -19804);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82130540
	if (ctx.cr6.eq) goto loc_82130540;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82130518;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82130540
	goto loc_82130540;
loc_8213051C:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r10,-19800(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -19800);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82130538
	if (ctx.cr6.eq) goto loc_82130538;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82130538;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82130538:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8212a598
	ctx.lr = 0x82130540;
	sub_8212A598(ctx, base);
loc_82130540:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
