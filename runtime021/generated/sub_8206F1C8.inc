DEFINE_REX_FUNC(sub_8206F1C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lfs f31,9536(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bne cr6,0x8206f210
	if (!ctx.cr6.eq) goto loc_8206F210;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206f210
	if (!ctx.cr6.eq) goto loc_8206F210;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8206f0f8
	ctx.lr = 0x8206F20C;
	sub_8206F0F8(ctx, base);
	// b 0x8206f374
	goto loc_8206F374;
loc_8206F210:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// addi r9,r11,-22624
	ctx.r9.s64 = ctx.r11.s64 + -22624;
	// lfs f10,12(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f12,f10,f0
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f0.f64));
	// lfs f9,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f11,f9,f13
	ctx.f11.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// lfs f8,-22624(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22624);
	ctx.f8.f64 = double(temp.f32);
	// lis r6,-32215
	ctx.r6.s64 = -2111242240;
	// fsubs f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f0.f64));
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lfs f8,-12(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12);
	ctx.f8.f64 = double(temp.f32);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// fsubs f5,f8,f13
	ctx.f5.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// lfs f8,-4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f6,-8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f8,f8,f13
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsubs f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f0.f64));
	// stfs f0,2804(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 2804, temp.u32);
	// stfs f13,2800(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 2800, temp.u32);
	// lis r4,-32215
	ctx.r4.s64 = -2111242240;
	// stfs f10,2796(r6)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r6.u32 + 2796, temp.u32);
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// stfs f9,2792(r5)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r5.u32 + 2792, temp.u32);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// lis r6,-32215
	ctx.r6.s64 = -2111242240;
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// stfs f12,2784(r4)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r4.u32 + 2784, temp.u32);
	// li r11,9
	ctx.r11.s64 = 9;
	// stfs f11,2780(r10)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r10.u32 + 2780, temp.u32);
	// fmuls f3,f5,f12
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// stfs f8,2776(r9)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r9.u32 + 2776, temp.u32);
	// fmuls f2,f8,f12
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// stfs f7,2772(r8)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r8.u32 + 2772, temp.u32);
	// stw r11,2788(r7)
	REX_STORE_U32(ctx.r7.u32 + 2788, ctx.r11.u32);
	// fmsubs f0,f4,f11,f3
	ctx.f0.f64 = double(float(std::fma(ctx.f4.f64, ctx.f11.f64, -ctx.f3.f64)));
	// stfs f0,2768(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 2768, temp.u32);
	// fmsubs f13,f7,f11,f2
	ctx.f13.f64 = double(float(std::fma(ctx.f7.f64, ctx.f11.f64, -ctx.f2.f64)));
	// stfs f13,2764(r5)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r5.u32 + 2764, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x8206f2cc
	if (ctx.cr6.lt) goto loc_8206F2CC;
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// bge cr6,0x8206f2e0
	if (!ctx.cr6.lt) goto loc_8206F2E0;
loc_8206F2CC:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x8206f2f0
	if (ctx.cr6.gt) goto loc_8206F2F0;
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// bgt cr6,0x8206f2f0
	if (ctx.cr6.gt) goto loc_8206F2F0;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
loc_8206F2E0:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8206f370
	if (!ctx.cr6.eq) goto loc_8206F370;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// b 0x8206f374
	goto loc_8206F374;
loc_8206F2F0:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x8206f32c
	if (ctx.cr6.lt) goto loc_8206F32C;
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// bgt cr6,0x8206f32c
	if (ctx.cr6.gt) goto loc_8206F32C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206f314
	if (ctx.cr6.eq) goto loc_8206F314;
	// bl 0x8206f1c8
	ctx.lr = 0x8206F30C;
	sub_8206F1C8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// bne cr6,0x8206f374
	if (!ctx.cr6.eq) goto loc_8206F374;
loc_8206F314:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8206f0f8
	ctx.lr = 0x8206F31C;
	sub_8206F0F8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// bne cr6,0x8206f374
	if (!ctx.cr6.eq) goto loc_8206F374;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// b 0x8206f368
	goto loc_8206F368;
loc_8206F32C:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x8206f374
	if (ctx.cr6.gt) goto loc_8206F374;
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// blt cr6,0x8206f374
	if (ctx.cr6.lt) goto loc_8206F374;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206f354
	if (ctx.cr6.eq) goto loc_8206F354;
	// bl 0x8206f1c8
	ctx.lr = 0x8206F34C;
	sub_8206F1C8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// bne cr6,0x8206f374
	if (!ctx.cr6.eq) goto loc_8206F374;
loc_8206F354:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8206f0f8
	ctx.lr = 0x8206F35C;
	sub_8206F0F8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// bne cr6,0x8206f374
	if (!ctx.cr6.eq) goto loc_8206F374;
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
loc_8206F368:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206f374
	if (ctx.cr6.eq) goto loc_8206F374;
loc_8206F370:
	// bl 0x8206f1c8
	ctx.lr = 0x8206F374;
	sub_8206F1C8(ctx, base);
loc_8206F374:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
