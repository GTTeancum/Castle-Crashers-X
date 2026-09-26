DEFINE_REX_FUNC(sub_8212A340) {
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
	// lis r31,-32235
	ctx.r31.s64 = -2112552960;
	// li r30,-1
	ctx.r30.s64 = -1;
	// lwz r3,31236(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 31236);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8212a380
	if (ctx.cr6.eq) goto loc_8212A380;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,23256(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 23256);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8212A378;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r11,31236(r31)
	REX_STORE_U32(ctx.r31.u32 + 31236, ctx.r11.u32);
loc_8212A380:
	// lis r31,-32235
	ctx.r31.s64 = -2112552960;
	// lwz r3,31240(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 31240);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8212a39c
	if (ctx.cr6.eq) goto loc_8212A39C;
	// bl 0x8214ace4
	ctx.lr = 0x8212A394;
	__imp__KeTlsFree(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r11,31240(r31)
	REX_STORE_U32(ctx.r31.u32 + 31240, ctx.r11.u32);
loc_8212A39C:
	// bl 0x8212f288
	ctx.lr = 0x8212A3A0;
	sub_8212F288(ctx, base);
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
