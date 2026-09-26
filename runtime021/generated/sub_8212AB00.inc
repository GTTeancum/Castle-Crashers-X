DEFINE_REX_FUNC(sub_8212AB00) {
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f2
	ctx.f31.f64 = ctx.f2.f64;
	// lis r9,32752
	ctx.r9.s64 = 2146435072;
	// stfd f31,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.f31.u64);
	// lwz r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// stfd f1,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f1.u64);
	// lis r10,-16
	ctx.r10.s64 = -1048576;
	// fabs f0,f1
	ctx.f0.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8212ab88
	if (!ctx.cr6.eq) goto loc_8212AB88;
	// lwz r11,140(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8212abc4
	if (!ctx.cr6.eq) goto loc_8212ABC4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfd f13,9616(r11)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r11.u32 + 9616);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8212ab6c
	if (!ctx.cr6.gt) goto loc_8212AB6C;
loc_8212AB60:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lfd f0,32104(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 32104);
	// b 0x8212ac64
	goto loc_8212AC64;
loc_8212AB6C:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212ab80
	if (!ctx.cr6.lt) goto loc_8212AB80;
loc_8212AB74:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfd f0,-27816(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -27816);
	// b 0x8212ac64
	goto loc_8212AC64;
loc_8212AB80:
	// stfd f13,0(r31)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.f13.u64);
	// b 0x8212ac68
	goto loc_8212AC68;
loc_8212AB88:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8212abc4
	if (!ctx.cr6.eq) goto loc_8212ABC4;
	// lwz r11,140(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8212abc4
	if (!ctx.cr6.eq) goto loc_8212ABC4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfd f13,9616(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r11.u32 + 9616);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x8212ab74
	if (ctx.cr6.gt) goto loc_8212AB74;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8212ab60
	if (ctx.cr6.lt) goto loc_8212AB60;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// li r30,1
	ctx.r30.s64 = 1;
	// lfd f0,32112(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 32112);
	// b 0x8212ac64
	goto loc_8212AC64;
loc_8212ABC4:
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8212abfc
	if (!ctx.cr6.eq) goto loc_8212ABFC;
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8212ac68
	if (!ctx.cr6.eq) goto loc_8212AC68;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfd f0,-27816(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -27816);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bgt cr6,0x8212ab60
	if (ctx.cr6.gt) goto loc_8212AB60;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfd f13,9616(r11)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r11.u32 + 9616);
	// fsel f0,f31,f13,f0
	ctx.f0.f64 = ctx.f31.f64 >= 0.0 ? ctx.f13.f64 : ctx.f0.f64;
	// b 0x8212ac64
	goto loc_8212AC64;
loc_8212ABFC:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8212ac68
	if (!ctx.cr6.eq) goto loc_8212AC68;
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8212ac68
	if (!ctx.cr6.eq) goto loc_8212AC68;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8212aa90
	ctx.lr = 0x8212AC18;
	sub_8212AA90(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfd f0,-27816(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -27816);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// ble cr6,0x8212ac40
	if (!ctx.cr6.gt) goto loc_8212AC40;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// lfd f0,32104(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 32104);
	// bne cr6,0x8212ac64
	if (!ctx.cr6.eq) goto loc_8212AC64;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// b 0x8212ac64
	goto loc_8212AC64;
loc_8212AC40:
	// fcmpu cr6,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bge cr6,0x8212ac5c
	if (!ctx.cr6.lt) goto loc_8212AC5C;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x8212ac64
	if (!ctx.cr6.eq) goto loc_8212AC64;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// lfd f0,32136(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 32136);
	// b 0x8212ac64
	goto loc_8212AC64;
loc_8212AC5C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfd f0,9616(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 9616);
loc_8212AC64:
	// stfd f0,0(r31)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.f0.u64);
loc_8212AC68:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
