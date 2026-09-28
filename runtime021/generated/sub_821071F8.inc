DEFINE_REX_FUNC(sub_821071F8) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r3,400(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 400);
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x82108e68
	ctx.lr = 0x82107220;
	sub_82108E68(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82107244
	if (!ctx.cr0.lt) goto loc_82107244;
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// ori r11,r11,4119
	ctx.r11.u64 = ctx.r11.u64 | 4119;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x82107278
	if (!ctx.cr6.eq) goto loc_82107278;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1617
	ctx.r3.u64 = ctx.r3.u64 | 1617;
	// b 0x82107278
	goto loc_82107278;
loc_82107244:
	// lwz r11,404(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 404);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,404(r30)
	REX_STORE_U32(ctx.r30.u32 + 404, ctx.r11.u32);
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// b 0x82107264
	goto loc_82107264;
loc_8210725C:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
loc_82107264:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210725c
	if (!ctx.cr6.eq) goto loc_8210725C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82106ff0
	ctx.lr = 0x82107274;
	sub_82106FF0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82107278:
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
