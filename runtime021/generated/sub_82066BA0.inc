DEFINE_REX_FUNC(sub_82066BA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,416(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 416);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,9536(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// lhz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x82066c4c
	if (ctx.cr6.eq) goto loc_82066C4C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82066c18
	if (ctx.cr6.eq) goto loc_82066C18;
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// lis r10,-1
	ctx.r10.s64 = -65536;
	// lwz r9,420(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// ori r7,r10,255
	ctx.r7.u64 = ctx.r10.u64 | 255;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r31
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r31.u32);
	// stw r9,16(r5)
	REX_STORE_U32(ctx.r5.u32 + 16, ctx.r9.u32);
	// lwz r4,420(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// cmplw cr6,r4,r7
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x82066c0c
	if (!ctx.cr6.eq) goto loc_82066C0C;
	// lis r11,30583
	ctx.r11.s64 = 2004287488;
	// ori r11,r11,30719
	ctx.r11.u64 = ctx.r11.u64 | 30719;
	// b 0x82066c14
	goto loc_82066C14;
loc_82066C0C:
	// lis r11,-1
	ctx.r11.s64 = -65536;
	// ori r11,r11,255
	ctx.r11.u64 = ctx.r11.u64 | 255;
loc_82066C14:
	// stw r11,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r11.u32);
loc_82066C18:
	// lfs f13,416(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 416);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f1
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// stfs f12,416(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bgt cr6,0x82066cb8
	if (ctx.cr6.gt) goto loc_82066CB8;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stfs f0,416(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
	// stb r11,424(r31)
	REX_STORE_U8(ctx.r31.u32 + 424, ctx.r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82066C4C:
	// lfs f0,432(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 432);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f13,432(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 432, temp.u32);
	// beq cr6,0x82066cb8
	if (ctx.cr6.eq) goto loc_82066CB8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,9700(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9700);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x82127a08
	ctx.lr = 0x82066C70;
	sub_82127A08(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// li r8,255
	ctx.r8.s64 = 255;
	// addi r7,r11,5
	ctx.r7.s64 = ctx.r11.s64 + 5;
	// lfs f0,9708(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9708);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,9704(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9704);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// lwzx r5,r6,r31
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r31.u32);
	// fctidz f10,f11
	ctx.f10.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lbz r4,87(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// rotlwi r11,r4,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 8);
	// or r10,r11,r4
	ctx.r10.u64 = ctx.r11.u64 | ctx.r4.u64;
	// rlwimi r8,r10,16,0,15
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000) | (ctx.r8.u64 & 0xFFFFFFFF0000FFFF);
	// stw r8,16(r5)
	REX_STORE_U32(ctx.r5.u32 + 16, ctx.r8.u32);
loc_82066CB8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
