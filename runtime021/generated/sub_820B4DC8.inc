DEFINE_REX_FUNC(sub_820B4DC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x820B4DD0;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8212a850
	ctx.lr = 0x820B4DD8;
	__savefpr_26(ctx, base);
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r14,r4
	ctx.r14.u64 = ctx.r4.u64;
	// stw r29,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// lwz r11,532(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 532);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x820b54d8
	if (!ctx.cr6.gt) goto loc_820B54D8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f27,9772(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9772);
	ctx.f27.f64 = double(temp.f32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f30,9768(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9768);
	ctx.f30.f64 = double(temp.f32);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lfs f28,9764(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9764);
	ctx.f28.f64 = double(temp.f32);
	// addi r5,r11,29632
	ctx.r5.s64 = ctx.r11.s64 + 29632;
	// lfs f31,9760(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9760);
	ctx.f31.f64 = double(temp.f32);
	// addi r4,r10,-1768
	ctx.r4.s64 = ctx.r10.s64 + -1768;
	// lfs f26,9756(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9756);
	ctx.f26.f64 = double(temp.f32);
	// lfs f29,9752(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 9752);
	ctx.f29.f64 = double(temp.f32);
	// stw r5,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r5.u32);
	// stw r4,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
loc_820B4E44:
	// lwz r11,528(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 528);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r31,65
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 65, ctx.xer);
	// bgt cr6,0x820b54b4
	if (ctx.cr6.gt) goto loc_820B54B4;
	// lis r12,-32245
	ctx.r12.s64 = -2113208320;
	// addi r12,r12,20084
	ctx.r12.s64 = ctx.r12.s64 + 20084;
	// rlwinm r0,r31,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r31.u32) {
	case 0:
		goto loc_820B4F7C;
	case 1:
		goto loc_820B54B4;
	case 2:
		goto loc_820B54B4;
	case 3:
		goto loc_820B54B4;
	case 4:
		goto loc_820B54B4;
	case 5:
		goto loc_820B54B4;
	case 6:
		goto loc_820B54B4;
	case 7:
		goto loc_820B54B4;
	case 8:
		goto loc_820B54B4;
	case 9:
		goto loc_820B54B4;
	case 10:
		goto loc_820B54B4;
	case 11:
		goto loc_820B54B4;
	case 12:
		goto loc_820B54B4;
	case 13:
		goto loc_820B54B4;
	case 14:
		goto loc_820B54B4;
	case 15:
		goto loc_820B54B4;
	case 16:
		goto loc_820B4F9C;
	case 17:
		goto loc_820B54B4;
	case 18:
		goto loc_820B4F9C;
	case 19:
		goto loc_820B54B4;
	case 20:
		goto loc_820B54B4;
	case 21:
		goto loc_820B54B4;
	case 22:
		goto loc_820B54B4;
	case 23:
		goto loc_820B54B4;
	case 24:
		goto loc_820B54B4;
	case 25:
		goto loc_820B54B4;
	case 26:
		goto loc_820B54B4;
	case 27:
		goto loc_820B54B4;
	case 28:
		goto loc_820B54B4;
	case 29:
		goto loc_820B54B4;
	case 30:
		goto loc_820B54B4;
	case 31:
		goto loc_820B54B4;
	case 32:
		goto loc_820B54B4;
	case 33:
		goto loc_820B54B4;
	case 34:
		goto loc_820B54B4;
	case 35:
		goto loc_820B54B4;
	case 36:
		goto loc_820B54B4;
	case 37:
		goto loc_820B54B4;
	case 38:
		goto loc_820B54B4;
	case 39:
		goto loc_820B54B4;
	case 40:
		goto loc_820B54B4;
	case 41:
		goto loc_820B54B4;
	case 42:
		goto loc_820B54B4;
	case 43:
		goto loc_820B54B4;
	case 44:
		goto loc_820B54B4;
	case 45:
		goto loc_820B54B4;
	case 46:
		goto loc_820B54B4;
	case 47:
		goto loc_820B54B4;
	case 48:
		goto loc_820B54B4;
	case 49:
		goto loc_820B54B4;
	case 50:
		goto loc_820B54B4;
	case 51:
		goto loc_820B54B4;
	case 52:
		goto loc_820B54B4;
	case 53:
		goto loc_820B54B4;
	case 54:
		goto loc_820B54B4;
	case 55:
		goto loc_820B54B4;
	case 56:
		goto loc_820B54B4;
	case 57:
		goto loc_820B54B4;
	case 58:
		goto loc_820B54B4;
	case 59:
		goto loc_820B54B4;
	case 60:
		goto loc_820B54B4;
	case 61:
		goto loc_820B54B4;
	case 62:
		goto loc_820B54B4;
	case 63:
		goto loc_820B54B4;
	case 64:
		goto loc_820B5388;
	case 65:
		goto loc_820B5388;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820B4F7C:
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r4,4(r30)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820B4F94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r3.u32);
	// b 0x820b54b4
	goto loc_820B54B4;
loc_820B4F9C:
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// ld r5,156(r30)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r30.u32 + 156);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// ld r6,164(r30)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r30.u32 + 164);
	// ld r7,172(r30)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r30.u32 + 172);
	// bl 0x820b5698
	ctx.lr = 0x820B4FB4;
	sub_820B5698(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820B4FC4:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x820b4fc4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820B4FC4;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x820b5788
	ctx.lr = 0x820B4FE4;
	sub_820B5788(ctx, base);
	// addi r11,r30,92
	ctx.r11.s64 = ctx.r30.s64 + 92;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// li r8,6
	ctx.r8.s64 = 6;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_820B4FF8:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x820b4ff8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820B4FF8;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r31,16
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 16, ctx.xer);
	// bne cr6,0x820b505c
	if (!ctx.cr6.eq) goto loc_820B505C;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f29
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r10,r10,16384
	ctx.r10.s64 = ctx.r10.s64 + 16384;
	// fmuls f11,f13,f29
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f29.f64));
	// stfs f11,4(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// lfd f10,144(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f26
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f26.f64));
	// fctiwz f6,f7
	ctx.f6.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x80000000U) : (ctx.f7.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// li r12,16
	ctx.r12.s64 = 16;
	// stfiwx f6,r11,r12
	REX_STORE_U32(ctx.r11.u32 + ctx.r12.u32, ctx.f6.u32);
	// b 0x820b50d8
	goto loc_820B50D8;
loc_820B505C:
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lfs f13,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// fmuls f5,f0,f31
	ctx.f5.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// fmuls f3,f13,f31
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// lfs f12,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// std r7,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r7.u64);
	// lfs f11,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// std r8,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r8.u64);
	// lfd f10,120(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// stfs f5,0(r11)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfd f9,128(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// frsp f1,f7
	ctx.f1.f64 = double(float(ctx.f7.f64));
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// stfs f3,8(r11)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// fmuls f2,f12,f31
	ctx.f2.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// stfs f2,12(r11)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// fmuls f4,f11,f31
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// stfs f4,4(r11)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fmuls f13,f1,f28
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f28.f64));
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fctiwz f11,f13
	ctx.f11.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// fmuls f0,f6,f28
	ctx.f0.f64 = double(float(ctx.f6.f64 * ctx.f28.f64));
	// fctiwz f12,f0
	ctx.f12.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// li r12,16
	ctx.r12.s64 = 16;
	// stfiwx f12,r11,r12
	REX_STORE_U32(ctx.r11.u32 + ctx.r12.u32, ctx.f12.u32);
	// li r12,20
	ctx.r12.s64 = 20;
	// stfiwx f11,r11,r12
	REX_STORE_U32(ctx.r11.u32 + ctx.r12.u32, ctx.f11.u32);
loc_820B50D8:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// stw r29,116(r30)
	REX_STORE_U32(ctx.r30.u32 + 116, ctx.r29.u32);
	// lbz r11,-22601(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b5100
	if (!ctx.cr6.eq) goto loc_820B5100;
	// li r6,32
	ctx.r6.s64 = 32;
	// lwz r3,112(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B5100;
	sub_820A71E8(ctx, base);
loc_820B5100:
	// bl 0x820b5eb8
	ctx.lr = 0x820B5104;
	sub_820B5EB8(ctx, base);
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,2048
	ctx.r4.s64 = 2048;
	// lwzx r3,r10,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820B5118;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,88(r30)
	REX_STORE_U32(ctx.r30.u32 + 88, ctx.r3.u32);
	// bne cr6,0x820b5130
	if (!ctx.cr6.eq) goto loc_820B5130;
	// li r11,128
	ctx.r11.s64 = 128;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x820b54b4
	goto loc_820B54B4;
loc_820B5130:
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// addi r6,r30,16
	ctx.r6.s64 = ctx.r30.s64 + 16;
	// lbz r16,16(r30)
	ctx.r16.u64 = REX_LOAD_U8(ctx.r30.u32 + 16);
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addic. r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lbz r15,15(r10)
	ctx.r15.u64 = REX_LOAD_U8(ctx.r10.u32 + 15);
	// ble 0x820b5310
	if (!ctx.cr0.gt) goto loc_820B5310;
	// addi r19,r30,32
	ctx.r19.s64 = ctx.r30.s64 + 32;
	// subfic r17,r30,-16
	ctx.xer.ca = ctx.r30.u32 <= 4294967280;
	ctx.r17.u64 = static_cast<uint64_t>(-16) - ctx.r30.u64;
loc_820B5154:
	// lbz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 0);
	// addi r24,r6,1
	ctx.r24.s64 = ctx.r6.s64 + 1;
	// lbz r10,1(r6)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r6.u32 + 1);
	// subf. r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820b52f0
	if (ctx.cr0.eq) goto loc_820B52F0;
	// ld r10,-8(r19)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r19.u32 + -8);
	// ld r9,0(r19)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r19.u32 + 0);
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lbz r10,91(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 91);
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// std r9,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lbz r5,107(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 107);
	// bne cr6,0x820b5194
	if (!ctx.cr6.eq) goto loc_820B5194;
	// clrlwi r9,r5,24
	ctx.r9.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r9,255
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 255, ctx.xer);
	// beq cr6,0x820b519c
	if (ctx.cr6.eq) goto loc_820B519C;
loc_820B5194:
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,116(r30)
	REX_STORE_U32(ctx.r30.u32 + 116, ctx.r9.u32);
loc_820B519C:
	// lbz r27,106(r1)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r1.u32 + 106);
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// lbz r29,0(r6)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r6.u32 + 0);
	// rlwinm r25,r10,16,0,15
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lbz r27,0(r24)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// lbz r9,88(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 88);
	// subf r5,r10,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r10.u64;
	// lbz r8,89(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 89);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// lbz r7,90(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 90);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// lbz r3,104(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + 104);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// stw r27,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// subf r6,r7,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r7.u64;
	// lbz r26,105(r1)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r1.u32 + 105);
	// subf r4,r9,r3
	ctx.r4.u64 = ctx.r3.u64 - ctx.r9.u64;
	// rlwinm r28,r6,16,0,15
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// subf r3,r8,r26
	ctx.r3.u64 = ctx.r26.u64 - ctx.r8.u64;
	// rlwinm r26,r5,16,0,15
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r31,r3,16,0,15
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rotlwi r5,r31,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r31.u32, 1);
	// rotlwi r4,r28,1
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r28.u32, 1);
	// rotlwi r3,r26,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r26.u32, 1);
	// rotlwi r6,r10,1
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// divw r22,r31,r11
	ctx.r22.u64 = uint32_t((ctx.r11.s32 && !(ctx.r31.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r31.s32 / ctx.r11.s32 : 0);
	// andc r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 & ~ctx.r6.u64;
	// andc r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 & ~ctx.r5.u64;
	// andc r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 & ~ctx.r4.u64;
	// andc r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 & ~ctx.r3.u64;
	// lwz r31,88(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// divw r21,r28,r11
	ctx.r21.u64 = uint32_t((ctx.r11.s32 && !(ctx.r28.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r28.s32 / ctx.r11.s32 : 0);
	// divw r20,r26,r11
	ctx.r20.u64 = uint32_t((ctx.r11.s32 && !(ctx.r26.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r26.s32 / ctx.r11.s32 : 0);
	// divw r23,r10,r11
	ctx.r23.u64 = uint32_t((ctx.r11.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r10.s32 / ctx.r11.s32 : 0);
	// twlgei r6,-1
	if (ctx.r6.s32 == -1 || ctx.r6.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// twlgei r5,-1
	if (ctx.r5.s32 == -1 || ctx.r5.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// twlgei r4,-1
	if (ctx.r4.s32 == -1 || ctx.r4.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// twlgei r3,-1
	if (ctx.r3.s32 == -1 || ctx.r3.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// rotlwi r28,r9,16
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r9.u32, 16);
	// rotlwi r27,r8,16
	ctx.r27.u64 = __builtin_rotateleft32(ctx.r8.u32, 16);
	// rotlwi r26,r7,16
	ctx.r26.u64 = __builtin_rotateleft32(ctx.r7.u32, 16);
	// cmpw cr6,r29,r31
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r31.s32, ctx.xer);
	// bgt cr6,0x820b52f0
	if (ctx.cr6.gt) goto loc_820B52F0;
	// rlwinm r31,r29,3,0,28
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFF8;
loc_820B5268:
	// lwz r11,88(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// srawi r10,r28,16
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r28.s32 >> 16;
	// srawi r9,r27,16
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r27.s32 >> 16;
	// srawi r6,r26,16
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r26.s32 >> 16;
	// srawi r5,r25,16
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r25.s32 >> 16;
	// stbx r10,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u8);
	// lwz r11,88(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// add r4,r31,r11
	ctx.r4.u64 = ctx.r31.u64 + ctx.r11.u64;
	// stb r9,1(r4)
	REX_STORE_U8(ctx.r4.u32 + 1, ctx.r9.u8);
	// lwz r11,88(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// stb r6,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, ctx.r6.u8);
	// lwz r11,88(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// add r9,r31,r11
	ctx.r9.u64 = ctx.r31.u64 + ctx.r11.u64;
	// stb r5,3(r9)
	REX_STORE_U8(ctx.r9.u32 + 3, ctx.r5.u8);
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r8,88(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// ldx r4,r31,r8
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + ctx.r8.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820B52C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,88(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// add r5,r31,r11
	ctx.r5.u64 = ctx.r31.u64 + ctx.r11.u64;
	// add r28,r28,r23
	ctx.r28.u64 = ctx.r28.u64 + ctx.r23.u64;
	// add r27,r27,r22
	ctx.r27.u64 = ctx.r27.u64 + ctx.r22.u64;
	// add r26,r26,r21
	ctx.r26.u64 = ctx.r26.u64 + ctx.r21.u64;
	// add r25,r25,r20
	ctx.r25.u64 = ctx.r25.u64 + ctx.r20.u64;
	// stw r3,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r3.u32);
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// lbz r4,0(r24)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// cmpw cr6,r29,r4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r4.s32, ctx.xer);
	// ble cr6,0x820b5268
	if (!ctx.cr6.gt) goto loc_820B5268;
loc_820B52F0:
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// add r10,r24,r17
	ctx.r10.u64 = ctx.r24.u64 + ctx.r17.u64;
	// addi r19,r19,8
	ctx.r19.s64 = ctx.r19.s64 + 8;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x820b5154
	if (ctx.cr6.lt) goto loc_820B5154;
	// li r29,0
	ctx.r29.s64 = 0;
loc_820B5310:
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// ble cr6,0x820b534c
	if (!ctx.cr6.gt) goto loc_820B534C;
	// rlwinm r8,r16,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// mr r10,r16
	ctx.r10.u64 = ctx.r16.u64;
loc_820B5324:
	// lwz r11,88(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r6,r8,r11
	ctx.r6.u64 = ctx.r8.u64 + ctx.r11.u64;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// lwzx r5,r8,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// stw r5,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
	// lwz r4,4(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// stw r4,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r4.u32);
	// bne 0x820b5324
	if (!ctx.cr0.eq) goto loc_820B5324;
loc_820B534C:
	// cmpwi cr6,r15,256
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 256, ctx.xer);
	// bge cr6,0x820b54b4
	if (!ctx.cr6.lt) goto loc_820B54B4;
	// rlwinm r9,r15,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_820B535C:
	// lwz r10,88(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// lwzx r6,r9,r10
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r11,2048
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2048, ctx.xer);
	// stw r6,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// lwz r5,4(r7)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// stw r5,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r5.u32);
	// blt cr6,0x820b535c
	if (ctx.cr6.lt) goto loc_820B535C;
	// b 0x820b54b4
	goto loc_820B54B4;
loc_820B5388:
	// lwz r11,120(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820b54b4
	if (ctx.cr6.eq) goto loc_820B54B4;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,36(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r4,32(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// bl 0x820b1a08
	ctx.lr = 0x820B53A8;
	sub_820B1A08(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,148(r30)
	REX_STORE_U32(ctx.r30.u32 + 148, ctx.r3.u32);
	// bne cr6,0x820b53c0
	if (!ctx.cr6.eq) goto loc_820B53C0;
	// lwz r11,120(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 120);
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// stw r10,148(r30)
	REX_STORE_U32(ctx.r30.u32 + 148, ctx.r10.u32);
loc_820B53C0:
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// ld r5,156(r30)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r30.u32 + 156);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// ld r6,164(r30)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r30.u32 + 164);
	// ld r7,172(r30)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r30.u32 + 172);
	// bl 0x820b5698
	ctx.lr = 0x820B53D8;
	sub_820B5698(ctx, base);
	// addi r31,r30,124
	ctx.r31.s64 = ctx.r30.s64 + 124;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820B53EC:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x820b53ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820B53EC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x820b5788
	ctx.lr = 0x820B540C;
	sub_820B5788(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820B541C:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x820b541c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820B541C;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lfs f13,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// fmuls f10,f0,f30
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// fmuls f9,f13,f30
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// std r8,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r8.u64);
	// lfd f5,152(r1)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// std r9,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r9.u64);
	// lfd f6,136(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f4,f6
	ctx.f4.f64 = double(ctx.f6.s64);
	// lfs f12,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fcfid f3,f5
	ctx.f3.f64 = double(ctx.f5.s64);
	// lfs f11,12(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// stfs f10,0(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// fmuls f8,f12,f30
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// stfs f9,4(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// fmuls f7,f11,f30
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f30.f64));
	// stfs f8,8(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// stfs f7,12(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// frsp f1,f3
	ctx.f1.f64 = double(float(ctx.f3.f64));
	// fmuls f0,f2,f27
	ctx.f0.f64 = double(float(ctx.f2.f64 * ctx.f27.f64));
	// fmuls f13,f1,f27
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f27.f64));
	// fctiwz f12,f0
	ctx.f12.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// li r12,16
	ctx.r12.s64 = 16;
	// stfiwx f12,r31,r12
	REX_STORE_U32(ctx.r31.u32 + ctx.r12.u32, ctx.f12.u32);
	// fctiwz f11,f13
	ctx.f11.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// li r12,20
	ctx.r12.s64 = 20;
	// stfiwx f11,r31,r12
	REX_STORE_U32(ctx.r31.u32 + ctx.r12.u32, ctx.f11.u32);
	// stw r29,152(r30)
	REX_STORE_U32(ctx.r30.u32 + 152, ctx.r29.u32);
loc_820B54B4:
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,532(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 532);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r8,r10,180
	ctx.r8.s64 = ctx.r10.s64 + 180;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// blt cr6,0x820b4e44
	if (ctx.cr6.lt) goto loc_820B4E44;
loc_820B54D8:
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8212a89c
	ctx.lr = 0x820B54E4;
	__restfpr_26(ctx, base);
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
