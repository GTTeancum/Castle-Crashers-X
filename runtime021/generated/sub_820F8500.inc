DEFINE_REX_FUNC(sub_820F8500) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,24(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r3,52
	ctx.r9.s64 = ctx.r3.s64 + 52;
	// lwz r8,8(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lbz r6,13(r3)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r4,4(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// srawi r31,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r7.s32 >> 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mullw r10,r6,r8
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// lwz r6,20(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// subf r7,r8,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r8.u64;
	// addze r8,r31
	temp.s64 = ctx.r31.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r31.u32;
	ctx.r8.s64 = temp.s64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r5,r6
	ctx.r11.u64 = ctx.r5.u64 + ctx.r6.u64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x820f8554
	if (ctx.cr6.lt) goto loc_820F8554;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
loc_820F8554:
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// lfs f13,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// std r6,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.r6.u64);
	// lfd f11,-48(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// addi r8,r8,127
	ctx.r8.s64 = ctx.r8.s64 + 127;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f13,9632(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 9632);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r6,r8,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// fdivs f10,f12,f9
	ctx.f10.f64 = double(float(ctx.f12.f64 / ctx.f9.f64));
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// beq cr6,0x820f85b0
	if (ctx.cr6.eq) goto loc_820F85B0;
loc_820F859C:
	// rlwinm r4,r8,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r4,r10
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplw cr6,r8,r6
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x820f859c
	if (ctx.cr6.lt) goto loc_820F859C;
loc_820F85B0:
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r31,-32255
	ctx.r31.s64 = -2113863680;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// lfs f12,-21608(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -21608);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-21604(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -21604);
	ctx.f13.f64 = double(temp.f32);
loc_820F85C8:
	// lbz r4,0(r8)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// std r4,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.r4.u64);
	// lfd f11,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fsubs f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// fmuls f5,f6,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// stfs f5,0(r8)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x820f85c8
	if (!ctx.cr0.eq) goto loc_820F85C8;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f11,4852(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4852);
	ctx.f11.f64 = double(temp.f32);
loc_820F85FC:
	// lbz r6,3(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// lfs f8,12(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// std r6,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.r6.u64);
	// lfd f6,-48(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fsubs f3,f4,f13
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// fmuls f2,f3,f12
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f12.f64));
	// stfs f2,12(r9)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// fadds f1,f2,f8
	ctx.f1.f64 = double(float(ctx.f2.f64 + ctx.f8.f64));
	// fmuls f8,f7,f2
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f2.f64));
	// fmuls f6,f1,f0
	ctx.f6.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fmuls f5,f6,f11
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// stfs f5,3072(r11)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r11.u32 + 3072, temp.u32);
	// stfs f8,3076(r11)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r11.u32 + 3076, temp.u32);
	// lbz r8,2(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// std r8,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.r8.u64);
	// lfs f2,8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lfd f4,-40(r1)
	ctx.f4.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f1,f3
	ctx.f1.f64 = double(float(ctx.f3.f64));
	// fsubs f8,f1,f13
	ctx.f8.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// fmuls f6,f8,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// stfs f6,8(r9)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// fadds f5,f6,f2
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f2.f64));
	// fmuls f3,f7,f6
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// fmuls f2,f4,f11
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f11.f64));
	// stfs f2,2048(r11)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + 2048, temp.u32);
	// stfs f3,2052(r11)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r11.u32 + 2052, temp.u32);
	// lbz r4,1(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// std r4,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r4.u64);
	// lfs f6,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// lfd f1,-32(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f8,f1
	ctx.f8.f64 = double(ctx.f1.s64);
	// frsp f5,f8
	ctx.f5.f64 = double(float(ctx.f8.f64));
	// fsubs f4,f5,f13
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f13.f64));
	// fmuls f3,f4,f12
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f12.f64));
	// stfs f3,4(r9)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fadds f2,f3,f6
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f6.f64));
	// fmuls f8,f7,f3
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f3.f64));
	// fmuls f1,f2,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// fmuls f6,f1,f11
	ctx.f6.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// stfs f6,1024(r11)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r11.u32 + 1024, temp.u32);
	// stfs f8,1028(r11)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r11.u32 + 1028, temp.u32);
	// lbz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// std r6,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r6.u64);
	// lfs f3,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lfd f5,-24(r1)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// fsubs f1,f2,f13
	ctx.f1.f64 = double(float(ctx.f2.f64 - ctx.f13.f64));
	// fmuls f8,f1,f12
	ctx.f8.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// stfs f8,0(r9)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fadds f6,f8,f3
	ctx.f6.f64 = double(float(ctx.f8.f64 + ctx.f3.f64));
	// fmuls f4,f7,f8
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// fadds f0,f9,f0
	ctx.f0.f64 = double(float(ctx.f9.f64 + ctx.f0.f64));
	// fmuls f3,f5,f11
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f11.f64));
	// stfs f3,0(r11)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f4,4(r11)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bne 0x820f85fc
	if (!ctx.cr0.eq) goto loc_820F85FC;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r7,13(r3)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// subf r6,r8,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r8.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// twllei r7,0
	if (ctx.r7.s32 == 0 || ctx.r7.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r8,r6,r7
	ctx.r8.u64 = uint32_t(ctx.r7.u32 ? ctx.r6.u32 / ctx.r7.u32 : 0);
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820f8728
	if (ctx.cr6.lt) goto loc_820F8728;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_820F8728:
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r10,24(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// subf r6,r7,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r7.u64;
	// stw r8,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// rlwinm r11,r6,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820f8748
	if (ctx.cr6.lt) goto loc_820F8748;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820F8748:
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r8,255
	ctx.r8.s64 = 255;
	// lfs f0,-21600(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21600);
	ctx.f0.f64 = double(temp.f32);
loc_820F8760:
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f11.u64);
	// lwz r11,-20(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
	// subfic r11,r11,128
	ctx.xer.ca = ctx.r11.u32 <= 128;
	ctx.r11.u64 = static_cast<uint64_t>(128) - ctx.r11.u64;
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// blt cr6,0x820f8788
	if (ctx.cr6.lt) goto loc_820F8788;
	// stb r8,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// b 0x820f879c
	goto loc_820F879C;
loc_820F8788:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x820f8798
	if (ctx.cr6.gt) goto loc_820F8798;
	// stb r5,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r5.u8);
	// b 0x820f879c
	goto loc_820F879C;
loc_820F8798:
	// stb r11,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r11.u8);
loc_820F879C:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x820f8760
	if (!ctx.cr0.eq) goto loc_820F8760;
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
