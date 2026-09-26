DEFINE_REX_FUNC(sub_820D0F80) {
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
	// stwu r1,-784(r1)
	ea = -784 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x820d0fbc
	if (!ctx.cr6.eq) goto loc_820D0FBC;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// std r11,0(r8)
	REX_STORE_U64(ctx.r8.u32 + 0, ctx.r11.u64);
	// stw r11,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r11.u32);
loc_820D0FBC:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f9,5984(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 5984);
	ctx.f9.f64 = double(temp.f32);
	// fcmpu cr6,f0,f9
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// bge cr6,0x820d0fd4
	if (!ctx.cr6.lt) goto loc_820D0FD4;
	// fmr f0,f9
	ctx.f0.f64 = ctx.f9.f64;
loc_820D0FD4:
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f11,9540(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9540);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x820d0fe8
	if (!ctx.cr6.gt) goto loc_820D0FE8;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
loc_820D0FE8:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lfs f12,14688(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 14688);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,9672(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9672);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f13,f0,f12,f13
	ctx.f13.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f12.f64, -ctx.f13.f64)));
	// fmadds f10,f13,f0,f11
	ctx.f10.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f11.f64)));
	// beq cr6,0x820d10a4
	if (ctx.cr6.eq) goto loc_820D10A4;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x820d10a4
	if (ctx.cr6.eq) goto loc_820D10A4;
	// lfs f0,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f9
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// bge cr6,0x820d1020
	if (!ctx.cr6.lt) goto loc_820D1020;
	// fmr f0,f9
	ctx.f0.f64 = ctx.f9.f64;
loc_820D1020:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x820d102c
	if (!ctx.cr6.gt) goto loc_820D102C;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
loc_820D102C:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f13,14684(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14684);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f12,f13
	ctx.f8.f64 = double(float(std::fma(ctx.f0.f64, ctx.f12.f64, ctx.f13.f64)));
	// lfs f13,14680(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 14680);
	ctx.f13.f64 = double(temp.f32);
	// lfd f12,14672(r7)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r7.u32 + 14672);
	// fcmpu cr6,f1,f12
	ctx.cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// fnmsubs f13,f8,f0,f13
	ctx.f13.f64 = double(float(-std::fma(ctx.f8.f64, ctx.f0.f64, -ctx.f13.f64)));
	// ble cr6,0x820d1064
	if (!ctx.cr6.gt) goto loc_820D1064;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfd f0,14664(r9)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 14664);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x820d1068
	if (ctx.cr6.lt) goto loc_820D1068;
loc_820D1064:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_820D1068:
	// fcmpu cr6,f10,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// bge cr6,0x820d1074
	if (!ctx.cr6.lt) goto loc_820D1074;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_820D1074:
	// fcmpu cr6,f13,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bge cr6,0x820d1080
	if (!ctx.cr6.lt) goto loc_820D1080;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_820D1080:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,9632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9632);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f1.f64));
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// blt cr6,0x820d1098
	if (ctx.cr6.lt) goto loc_820D1098;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
loc_820D1098:
	// fmuls f13,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmuls f13,f13,f10
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// b 0x820d10e8
	goto loc_820D10E8;
loc_820D10A4:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfd f0,14656(r9)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 14656);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x820d10c4
	if (!ctx.cr6.gt) goto loc_820D10C4;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfd f0,14648(r9)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 14648);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x820d10c8
	if (ctx.cr6.lt) goto loc_820D10C8;
loc_820D10C4:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_820D10C8:
	// fcmpu cr6,f10,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// bge cr6,0x820d10d4
	if (!ctx.cr6.lt) goto loc_820D10D4;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_820D10D4:
	// fdivs f0,f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f11.f64 / ctx.f1.f64));
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// blt cr6,0x820d10e4
	if (ctx.cr6.lt) goto loc_820D10E4;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
loc_820D10E4:
	// fmuls f13,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
loc_820D10E8:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,4860(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4860);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,31
	ctx.r11.s64 = 2031616;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// lfs f0,14644(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14644);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// lfs f10,4852(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4852);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f0,f1,f0,f10
	ctx.f0.f64 = double(float(std::fma(ctx.f1.f64, ctx.f0.f64, ctx.f10.f64)));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// stw r9,648(r31)
	REX_STORE_U32(ctx.r31.u32 + 648, ctx.r9.u32);
	// ble cr6,0x820d1130
	if (!ctx.cr6.gt) goto loc_820D1130;
	// stw r11,648(r31)
	REX_STORE_U32(ctx.r31.u32 + 648, ctx.r11.u32);
loc_820D1130:
	// lfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// cmpwi cr6,r5,2
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 2, ctx.xer);
	// bne cr6,0x820d117c
	if (!ctx.cr6.eq) goto loc_820D117C;
	// lfs f0,8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f9
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// bge cr6,0x820d1150
	if (!ctx.cr6.lt) goto loc_820D1150;
	// fmr f0,f9
	ctx.f0.f64 = ctx.f9.f64;
loc_820D1150:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x820d115c
	if (!ctx.cr6.gt) goto loc_820D115C;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
loc_820D115C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f13,5928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5928);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4848(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4848);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f12,f0,f13,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f13,9548(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9548);
	ctx.f13.f64 = double(temp.f32);
	// b 0x820d11fc
	goto loc_820D11FC;
loc_820D117C:
	// cmpwi cr6,r5,3
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 3, ctx.xer);
	// bne cr6,0x820d11bc
	if (!ctx.cr6.eq) goto loc_820D11BC;
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f9
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// bge cr6,0x820d1194
	if (!ctx.cr6.lt) goto loc_820D1194;
	// fmr f0,f9
	ctx.f0.f64 = ctx.f9.f64;
loc_820D1194:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x820d11a0
	if (!ctx.cr6.gt) goto loc_820D11A0;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
loc_820D11A0:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,9572(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9572);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14640(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14640);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// fmadds f2,f13,f0,f10
	ctx.f2.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f10.f64)));
	// b 0x820d120c
	goto loc_820D120C;
loc_820D11BC:
	// cmpwi cr6,r5,5
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 5, ctx.xer);
	// bne cr6,0x820d1204
	if (!ctx.cr6.eq) goto loc_820D1204;
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f9
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// bge cr6,0x820d11d4
	if (!ctx.cr6.lt) goto loc_820D11D4;
	// fmr f0,f9
	ctx.f0.f64 = ctx.f9.f64;
loc_820D11D4:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x820d11e0
	if (!ctx.cr6.gt) goto loc_820D11E0;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
loc_820D11E0:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,9712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9712);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9716(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9716);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f12,f0,f13,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f13,14368(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 14368);
	ctx.f13.f64 = double(temp.f32);
loc_820D11FC:
	// fmadds f2,f12,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// b 0x820d120c
	goto loc_820D120C;
loc_820D1204:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f2,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f2.f64 = double(temp.f32);
loc_820D120C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r3,7
	ctx.r3.s64 = 7;
	// bne cr6,0x820d121c
	if (!ctx.cr6.eq) goto loc_820D121C;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
loc_820D121C:
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x820d0b00
	ctx.lr = 0x820D1230;
	sub_820D0B00(ctx, base);
	// li r6,16
	ctx.r6.s64 = 16;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,8
	ctx.r4.s64 = ctx.r31.s64 + 8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820d02c0
	ctx.lr = 0x820D1244;
	sub_820D02C0(ctx, base);
	// addi r1,r1,784
	ctx.r1.s64 = ctx.r1.s64 + 784;
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
