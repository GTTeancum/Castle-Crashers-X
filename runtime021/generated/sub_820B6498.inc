DEFINE_REX_FUNC(sub_820B6498) {
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
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lwz r11,188(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 188);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820B64B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820b64c8
	if (ctx.cr0.lt) goto loc_820B64C8;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820b64d0
	goto loc_820B64D0;
loc_820B64C8:
	// bl 0x820b7290
	ctx.lr = 0x820B64CC;
	sub_820B7290(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_820B64D0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
