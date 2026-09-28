DEFINE_REX_FUNC(sub_82146B70) {
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
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x8212a858
	ctx.lr = 0x82146B88;
	__savefpr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// fmr f29,f2
	ctx.f29.f64 = ctx.f2.f64;
	// stfs f31,12(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stfs f29,16(r31)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// bl 0x82148ed8
	ctx.lr = 0x82146BA8;
	sub_82148ED8(ctx, base);
	// lha r11,22(r31)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 22));
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// lhz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r30,r11,1
	ctx.r30.u64 = ctx.r11.u64 ^ 1;
	// bne 0x82146bd4
	if (!ctx.cr0.eq) goto loc_82146BD4;
	// li r11,1
	ctx.r11.s64 = 1;
	// sth r11,24(r31)
	REX_STORE_U16(ctx.r31.u32 + 24, ctx.r11.u16);
loc_82146BD4:
	// lhz r11,26(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 26);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82146be8
	if (!ctx.cr0.eq) goto loc_82146BE8;
	// li r11,90
	ctx.r11.s64 = 90;
	// sth r11,26(r31)
	REX_STORE_U16(ctx.r31.u32 + 26, ctx.r11.u16);
loc_82146BE8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,9540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// bl 0x8212b338
	ctx.lr = 0x82146BF8;
	sub_8212B338(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f0,-4720(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4720);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f30,f13,f0
	ctx.f30.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x82148f38
	ctx.lr = 0x82146C14;
	sub_82148F38(ctx, base);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// lhz r5,24(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// fmr f2,f28
	ctx.f2.f64 = ctx.f28.f64;
	// bl 0x82148fa8
	ctx.lr = 0x82146C28;
	sub_82148FA8(ctx, base);
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82149030
	ctx.lr = 0x82146C34;
	sub_82149030(ctx, base);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// lhz r5,26(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 26);
	// lhz r4,24(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// bl 0x821491f0
	ctx.lr = 0x82146C48;
	sub_821491F0(ctx, base);
	// sth r3,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r3.u16);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x821492c0
	ctx.lr = 0x82146C5C;
	sub_821492C0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82146ca4
	if (ctx.cr0.eq) goto loc_82146CA4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lfs f0,4852(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4852);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lbz r3,87(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// bl 0x82148dc8
	ctx.lr = 0x82146C84;
	sub_82148DC8(ctx, base);
	// lbz r11,30(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 30);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82146cac
	if (ctx.cr0.eq) goto loc_82146CAC;
	// lhz r4,22(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 22);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82148c88
	ctx.lr = 0x82146C9C;
	sub_82148C88(ctx, base);
	// sth r3,20(r31)
	REX_STORE_U16(ctx.r31.u32 + 20, ctx.r3.u16);
	// b 0x82146cac
	goto loc_82146CAC;
loc_82146CA4:
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82148ee0
	ctx.lr = 0x82146CAC;
	sub_82148EE0(ctx, base);
loc_82146CAC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x8212a8a4
	ctx.lr = 0x82146CBC;
	__restfpr_28(ctx, base);
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
