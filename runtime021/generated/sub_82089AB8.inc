DEFINE_REX_FUNC(sub_82089AB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// bne cr6,0x82089b48
	if (!ctx.cr6.eq) goto loc_82089B48;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82089bd8
	if (ctx.cr6.eq) goto loc_82089BD8;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82089bd8
	if (ctx.cr6.eq) goto loc_82089BD8;
	// bl 0x82082bb0
	ctx.lr = 0x82089B00;
	sub_82082BB0(ctx, base);
	// clrlwi r30,r3,16
	ctx.r30.u64 = ctx.r3.u32 & 0xFFFF;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082bb0
	ctx.lr = 0x82089B0C;
	sub_82082BB0(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r11,-6612(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6612);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lfs f0,9724(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9724);
	ctx.f0.f64 = double(temp.f32);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// bl 0x820975d8
	ctx.lr = 0x82089B44;
	sub_820975D8(ctx, base);
	// b 0x82089be8
	goto loc_82089BE8;
loc_82089B48:
	// cmpwi cr6,r4,3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 3, ctx.xer);
	// bne cr6,0x82089bd8
	if (!ctx.cr6.eq) goto loc_82089BD8;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82089bd8
	if (ctx.cr6.eq) goto loc_82089BD8;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82089bd8
	if (ctx.cr6.eq) goto loc_82089BD8;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82089bd8
	if (ctx.cr6.eq) goto loc_82089BD8;
	// bl 0x82082bb0
	ctx.lr = 0x82089B88;
	sub_82082BB0(ctx, base);
	// clrlwi r30,r3,16
	ctx.r30.u64 = ctx.r3.u32 & 0xFFFF;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082bb0
	ctx.lr = 0x82089B94;
	sub_82082BB0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82082670
	ctx.lr = 0x82089BA0;
	sub_82082670(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r11,-6612(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6612);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lfs f0,9724(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9724);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// bl 0x820975d8
	ctx.lr = 0x82089BD4;
	sub_820975D8(ctx, base);
	// b 0x82089be8
	goto loc_82089BE8;
loc_82089BD8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-6316
	ctx.r3.s64 = ctx.r11.s64 + -6316;
	// bl 0x820798d8
	ctx.lr = 0x82089BE4;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x82089BE8;
	sub_8208C5D8(ctx, base);
loc_82089BE8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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
