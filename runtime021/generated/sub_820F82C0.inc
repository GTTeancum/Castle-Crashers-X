DEFINE_REX_FUNC(sub_820F82C0) {
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
	// addi r5,r3,52
	ctx.r5.s64 = ctx.r3.s64 + 52;
	// lwz r8,8(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lbz r4,13(r3)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// srawi r31,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r7.s32 >> 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mullw r9,r4,r8
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// subf r8,r8,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r8.u64;
	// addze r10,r31
	temp.s64 = ctx.r31.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r31.u32;
	ctx.r10.s64 = temp.s64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 + ctx.r7.u64;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x820f8314
	if (ctx.cr6.lt) goto loc_820F8314;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_820F8314:
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// lfs f13,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// std r7,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r7.u64);
	// lfd f11,-32(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// addi r10,r10,127
	ctx.r10.s64 = ctx.r10.s64 + 127;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f13,9632(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 9632);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r7,r10,25,7,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// fdivs f10,f12,f9
	ctx.f10.f64 = double(float(ctx.f12.f64 / ctx.f9.f64));
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// beq cr6,0x820f8370
	if (ctx.cr6.eq) goto loc_820F8370;
loc_820F835C:
	// rlwinm r4,r10,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r4,r11
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x820f835c
	if (ctx.cr6.lt) goto loc_820F835C;
loc_820F8370:
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r31,-32255
	ctx.r31.s64 = -2113863680;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// li r7,2
	ctx.r7.s64 = 2;
	// lfs f12,-21608(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -21608);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-21604(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -21604);
	ctx.f13.f64 = double(temp.f32);
loc_820F8388:
	// lbz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// std r4,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r4.u64);
	// lfd f11,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fsubs f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// fmuls f5,f6,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// stfs f5,0(r10)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x820f8388
	if (!ctx.cr0.eq) goto loc_820F8388;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,4852(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4852);
	ctx.f11.f64 = double(temp.f32);
loc_820F83BC:
	// lbz r7,1(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lfs f8,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// std r7,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r7.u64);
	// lfd f6,-32(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fsubs f3,f4,f13
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// fmuls f2,f3,f12
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f12.f64));
	// stfs f2,4(r5)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// fadds f1,f2,f8
	ctx.f1.f64 = double(float(ctx.f2.f64 + ctx.f8.f64));
	// fmuls f8,f7,f2
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f2.f64));
	// fmuls f6,f1,f0
	ctx.f6.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fmuls f5,f6,f11
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// stfs f5,1024(r9)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r9.u32 + 1024, temp.u32);
	// stfs f8,1028(r9)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r9.u32 + 1028, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// std r10,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r10.u64);
	// lfs f2,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfd f4,-24(r1)
	ctx.f4.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f1,f3
	ctx.f1.f64 = double(float(ctx.f3.f64));
	// fsubs f8,f1,f13
	ctx.f8.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// fmuls f6,f8,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// stfs f6,0(r5)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fadds f5,f6,f2
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f2.f64));
	// fmuls f3,f7,f6
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// fadds f0,f9,f0
	ctx.f0.f64 = double(float(ctx.f9.f64 + ctx.f0.f64));
	// fmuls f2,f4,f11
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f11.f64));
	// stfs f2,0(r9)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f3,4(r9)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// bne 0x820f83bc
	if (!ctx.cr0.eq) goto loc_820F83BC;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r8,13(r3)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// subf r7,r10,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r10.u64;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// twllei r8,0
	if (ctx.r8.s32 == 0 || ctx.r8.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r10,r7,r8
	ctx.r10.u64 = uint32_t(ctx.r8.u32 ? ctx.r7.u32 / ctx.r8.u32 : 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820f8470
	if (ctx.cr6.lt) goto loc_820F8470;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_820F8470:
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// subf r10,r11,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r11.u64;
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x820f8490
	if (!ctx.cr6.lt) goto loc_820F8490;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820F8490:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,255
	ctx.r8.s64 = 255;
	// lfs f0,-21600(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -21600);
	ctx.f0.f64 = double(temp.f32);
loc_820F84AC:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f11.u64);
	// lwz r10,-20(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
	// subfic r10,r10,128
	ctx.xer.ca = ctx.r10.u32 <= 128;
	ctx.r10.u64 = static_cast<uint64_t>(128) - ctx.r10.u64;
	// cmpwi cr6,r10,255
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 255, ctx.xer);
	// blt cr6,0x820f84d4
	if (ctx.cr6.lt) goto loc_820F84D4;
	// stb r8,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
	// b 0x820f84e8
	goto loc_820F84E8;
loc_820F84D4:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt cr6,0x820f84e4
	if (ctx.cr6.gt) goto loc_820F84E4;
	// stb r6,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r6.u8);
	// b 0x820f84e8
	goto loc_820F84E8;
loc_820F84E4:
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
loc_820F84E8:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bne 0x820f84ac
	if (!ctx.cr0.eq) goto loc_820F84AC;
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
