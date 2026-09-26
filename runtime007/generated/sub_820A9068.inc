DEFINE_REX_FUNC(sub_820A9068) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820A9070;
	__savegprlr_25(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8212a834
	ctx.lr = 0x820A9078;
	__savefpr_19(ctx, base);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a92f4
	if (ctx.cr6.eq) goto loc_820A92F4;
	// lfs f12,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f11,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f10,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f11,f12
	ctx.f9.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// lfs f8,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// fadds f7,f8,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// lfs f6,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// lfs f13,18248(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18248);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,9536(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fmuls f30,f9,f13
	ctx.f30.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmuls f29,f7,f13
	ctx.f29.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f5,8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// fadds f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 + ctx.f5.f64));
	// fsubs f3,f12,f30
	ctx.f3.f64 = double(float(ctx.f12.f64 - ctx.f30.f64));
	// fsubs f2,f11,f30
	ctx.f2.f64 = double(float(ctx.f11.f64 - ctx.f30.f64));
	// fsubs f0,f10,f29
	ctx.f0.f64 = double(float(ctx.f10.f64 - ctx.f29.f64));
	// fsubs f12,f8,f29
	ctx.f12.f64 = double(float(ctx.f8.f64 - ctx.f29.f64));
	// fmuls f28,f4,f13
	ctx.f28.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// fmr f27,f3
	ctx.f27.f64 = ctx.f3.f64;
	// fmr f26,f2
	ctx.f26.f64 = ctx.f2.f64;
	// fmr f25,f0
	ctx.f25.f64 = ctx.f0.f64;
	// fmr f24,f0
	ctx.f24.f64 = ctx.f0.f64;
	// fmr f23,f2
	ctx.f23.f64 = ctx.f2.f64;
	// fmr f22,f12
	ctx.f22.f64 = ctx.f12.f64;
	// fmr f21,f3
	ctx.f21.f64 = ctx.f3.f64;
	// fmr f20,f12
	ctx.f20.f64 = ctx.f12.f64;
	// bl 0x82127a08
	ctx.lr = 0x820A9148;
	sub_82127A08(ctx, base);
	// frsp f19,f1
	ctx.fpscr.disableFlushMode();
	ctx.f19.f64 = double(float(ctx.f1.f64));
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82127ae8
	ctx.lr = 0x820A9154;
	sub_82127AE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lbz r30,447(r1)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r1.u32 + 447);
	// fmuls f10,f25,f19
	ctx.f10.f64 = double(float(ctx.f25.f64 * ctx.f19.f64));
	// stfs f28,168(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmuls f9,f27,f19
	ctx.f9.f64 = double(float(ctx.f27.f64 * ctx.f19.f64));
	// stfs f28,152(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fmuls f8,f24,f19
	ctx.f8.f64 = double(float(ctx.f24.f64 * ctx.f19.f64));
	// stfs f28,136(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fmuls f7,f26,f19
	ctx.f7.f64 = double(float(ctx.f26.f64 * ctx.f19.f64));
	// stfs f28,120(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmuls f6,f22,f19
	ctx.f6.f64 = double(float(ctx.f22.f64 * ctx.f19.f64));
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// fmuls f5,f23,f19
	ctx.f5.f64 = double(float(ctx.f23.f64 * ctx.f19.f64));
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// fmuls f4,f20,f19
	ctx.f4.f64 = double(float(ctx.f20.f64 * ctx.f19.f64));
	// fmuls f3,f21,f19
	ctx.f3.f64 = double(float(ctx.f21.f64 * ctx.f19.f64));
	// fmsubs f2,f27,f11,f10
	ctx.f2.f64 = double(float(std::fma(ctx.f27.f64, ctx.f11.f64, -ctx.f10.f64)));
	// fmadds f1,f25,f11,f9
	ctx.f1.f64 = double(float(std::fma(ctx.f25.f64, ctx.f11.f64, ctx.f9.f64)));
	// fmsubs f0,f26,f11,f8
	ctx.f0.f64 = double(float(std::fma(ctx.f26.f64, ctx.f11.f64, -ctx.f8.f64)));
	// fmadds f13,f24,f11,f7
	ctx.f13.f64 = double(float(std::fma(ctx.f24.f64, ctx.f11.f64, ctx.f7.f64)));
	// fmsubs f12,f23,f11,f6
	ctx.f12.f64 = double(float(std::fma(ctx.f23.f64, ctx.f11.f64, -ctx.f6.f64)));
	// fmadds f10,f22,f11,f5
	ctx.f10.f64 = double(float(std::fma(ctx.f22.f64, ctx.f11.f64, ctx.f5.f64)));
	// fmsubs f9,f21,f11,f4
	ctx.f9.f64 = double(float(std::fma(ctx.f21.f64, ctx.f11.f64, -ctx.f4.f64)));
	// fmadds f8,f20,f11,f3
	ctx.f8.f64 = double(float(std::fma(ctx.f20.f64, ctx.f11.f64, ctx.f3.f64)));
	// fadds f7,f2,f30
	ctx.f7.f64 = double(float(ctx.f2.f64 + ctx.f30.f64));
	// stfs f7,160(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// fadds f6,f1,f29
	ctx.f6.f64 = double(float(ctx.f1.f64 + ctx.f29.f64));
	// stfs f6,164(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fadds f5,f0,f30
	ctx.f5.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// stfs f5,144(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fadds f4,f13,f29
	ctx.f4.f64 = double(float(ctx.f13.f64 + ctx.f29.f64));
	// stfs f4,148(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fadds f3,f12,f30
	ctx.f3.f64 = double(float(ctx.f12.f64 + ctx.f30.f64));
	// stfs f3,128(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fadds f2,f10,f29
	ctx.f2.f64 = double(float(ctx.f10.f64 + ctx.f29.f64));
	// fadds f1,f9,f30
	ctx.f1.f64 = double(float(ctx.f9.f64 + ctx.f30.f64));
	// fadds f0,f8,f29
	ctx.f0.f64 = double(float(ctx.f8.f64 + ctx.f29.f64));
	// lfs f31,9540(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9540);
	ctx.f31.f64 = double(temp.f32);
	// stfs f2,132(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f1,112(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// beq cr6,0x820a9214
	if (ctx.cr6.eq) goto loc_820A9214;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A9210;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820a9218
	goto loc_820A9218;
loc_820A9214:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_820A9218:
	// lfs f0,164(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// beq cr6,0x820a9244
	if (ctx.cr6.eq) goto loc_820A9244;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A9240;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820a9248
	goto loc_820A9248;
loc_820A9244:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_820A9248:
	// lfs f0,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// beq cr6,0x820a9274
	if (ctx.cr6.eq) goto loc_820A9274;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A9270;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820a9278
	goto loc_820A9278;
loc_820A9274:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_820A9278:
	// lfs f0,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// beq cr6,0x820a92a4
	if (ctx.cr6.eq) goto loc_820A92A4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A92A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820a92a8
	goto loc_820A92A8;
loc_820A92A4:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_820A92A8:
	// lwz r6,452(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 452);
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// stw r25,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r25.u32);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// stw r6,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820A92F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820A92F4:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8212a880
	ctx.lr = 0x820A9300;
	__restfpr_19(ctx, base);
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
