DEFINE_REX_FUNC(sub_82089F70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82089F78;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8208a218
	if (ctx.cr6.eq) goto loc_8208A218;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x8208a218
	if (ctx.cr6.eq) goto loc_8208A218;
	// addi r11,r4,-78
	ctx.r11.s64 = ctx.r4.s64 + -78;
	// cmplwi cr6,r11,19
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 19, ctx.xer);
	// bgt cr6,0x8208a218
	if (ctx.cr6.gt) goto loc_8208A218;
	// lis r12,-32247
	ctx.r12.s64 = -2113339392;
	// addi r12,r12,-24636
	ctx.r12.s64 = ctx.r12.s64 + -24636;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8208A014;
	case 1:
		goto loc_8208A040;
	case 2:
		goto loc_8208A06C;
	case 3:
		goto loc_8208A098;
	case 4:
		goto loc_8208A218;
	case 5:
		goto loc_8208A218;
	case 6:
		goto loc_8208A0C4;
	case 7:
		goto loc_8208A14C;
	case 8:
		goto loc_8208A218;
	case 9:
		goto loc_8208A17C;
	case 10:
		goto loc_8208A1D0;
	case 11:
		goto loc_8208A218;
	case 12:
		goto loc_8208A218;
	case 13:
		goto loc_8208A1FC;
	case 14:
		goto loc_8208A218;
	case 15:
		goto loc_8208A218;
	case 16:
		goto loc_8208A218;
	case 17:
		goto loc_8208A218;
	case 18:
		goto loc_8208A218;
	case 19:
		goto loc_8208A208;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8208A014:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082700
	ctx.lr = 0x8208A020;
	sub_82082700(ctx, base);
	// lwz r11,208(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 208);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208A030;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8208A040:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082700
	ctx.lr = 0x8208A04C;
	sub_82082700(ctx, base);
	// lwz r11,212(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 212);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208A05C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8208A06C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082700
	ctx.lr = 0x8208A078;
	sub_82082700(ctx, base);
	// lwz r11,216(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 216);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208A088;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8208A098:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082700
	ctx.lr = 0x8208A0A4;
	sub_82082700(ctx, base);
	// lwz r11,220(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 220);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208A0B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8208A0C4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82082bb0
	ctx.lr = 0x8208A0CC;
	sub_82082BB0(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// extsh r30,r3
	ctx.r30.s64 = ctx.r3.s16;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208a0f8
	if (!ctx.cr6.eq) goto loc_8208A0F8;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6648(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6648);
	// bl 0x8208f9e8
	ctx.lr = 0x8208A0EC;
	sub_8208F9E8(ctx, base);
	// stw r3,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82066ea8
	ctx.lr = 0x8208A0F8;
	sub_82066EA8(ctx, base);
loc_8208A0F8:
	// extsh r9,r30
	ctx.r9.s64 = ctx.r30.s16;
	// lwz r4,76(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,9728(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9728);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,44(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 44);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lhz r8,86(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 86);
	// sth r8,40(r4)
	REX_STORE_U16(ctx.r4.u32 + 40, ctx.r8.u16);
	// beq cr6,0x8208a208
	if (ctx.cr6.eq) goto loc_8208A208;
	// bl 0x820837c0
	ctx.lr = 0x8208A13C;
	sub_820837C0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8208A14C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082670
	ctx.lr = 0x8208A158;
	sub_82082670(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r7,236(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 236);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8208A16C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8208A17C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 232);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8208A190;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x82082700
	ctx.lr = 0x8208A19C;
	sub_82082700(ctx, base);
	// fdivs f13,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 / ctx.f31.f64));
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,18236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18236);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,220(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 220);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8208A1C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8208A1D0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082700
	ctx.lr = 0x8208A1DC;
	sub_82082700(ctx, base);
	// lwz r11,224(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 224);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208A1EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8208A1FC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82082890
	ctx.lr = 0x8208A204;
	sub_82082890(ctx, base);
	// sth r3,100(r31)
	REX_STORE_U16(ctx.r31.u32 + 100, ctx.r3.u16);
loc_8208A208:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8208A218:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
