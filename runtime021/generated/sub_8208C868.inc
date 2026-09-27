DEFINE_REX_FUNC(sub_8208C868) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8208C870;
	__savegprlr_28(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r5,16
	ctx.r11.u64 = ctx.r5.u32 & 0xFFFF;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-40
	ctx.r11.s64 = ctx.r11.s64 + -40;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 31, ctx.xer);
	// bgt cr6,0x8208cb74
	if (ctx.cr6.gt) goto loc_8208CB74;
	// lis r12,-32247
	ctx.r12.s64 = -2113339392;
	// addi r12,r12,-14168
	ctx.r12.s64 = ctx.r12.s64 + -14168;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8208CAF0;
	case 1:
		goto loc_8208CB28;
	case 2:
		goto loc_8208CB74;
	case 3:
		goto loc_8208CB74;
	case 4:
		goto loc_8208CB74;
	case 5:
		goto loc_8208CB74;
	case 6:
		goto loc_8208CB74;
	case 7:
		goto loc_8208CB74;
	case 8:
		goto loc_8208CB74;
	case 9:
		goto loc_8208CB74;
	case 10:
		goto loc_8208CB74;
	case 11:
		goto loc_8208CB74;
	case 12:
		goto loc_8208CB74;
	case 13:
		goto loc_8208CB74;
	case 14:
		goto loc_8208CB74;
	case 15:
		goto loc_8208CB74;
	case 16:
		goto loc_8208CB74;
	case 17:
		goto loc_8208CB74;
	case 18:
		goto loc_8208CB74;
	case 19:
		goto loc_8208CB74;
	case 20:
		goto loc_8208CB74;
	case 21:
		goto loc_8208CB74;
	case 22:
		goto loc_8208CB74;
	case 23:
		goto loc_8208CB74;
	case 24:
		goto loc_8208CB74;
	case 25:
		goto loc_8208CB74;
	case 26:
		goto loc_8208CB74;
	case 27:
		goto loc_8208C928;
	case 28:
		goto loc_8208C9A8;
	case 29:
		goto loc_8208C9DC;
	case 30:
		goto loc_8208CA10;
	case 31:
		goto loc_8208CA80;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8208C928:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82082890
	ctx.lr = 0x8208C930;
	sub_82082890(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r3,94(r31)
	REX_STORE_U16(ctx.r31.u32 + 94, ctx.r3.u16);
	// lwz r10,10316(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 10316);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208c94c
	if (!ctx.cr6.eq) goto loc_8208C94C;
	// addi r30,r10,12
	ctx.r30.s64 = ctx.r10.s64 + 12;
	// b 0x8208c958
	goto loc_8208C958;
loc_8208C94C:
	// lwz r10,28(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r9,r10
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_8208C958:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82053a00
	ctx.lr = 0x8208C964;
	sub_82053A00(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lhz r5,94(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 94);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r4,-6612(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// bl 0x82096b48
	ctx.lr = 0x8208C97C;
	sub_82096B48(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lhz r5,94(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 94);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r3,r10,-5724
	ctx.r3.s64 = ctx.r10.s64 + -5724;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820798d8
	ctx.lr = 0x8208C994;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x8208C998;
	sub_8208C5D8(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,92(r31)
	REX_STORE_U8(ctx.r31.u32 + 92, ctx.r9.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8208C9A8:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f13,100(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r11,16260
	ctx.r9.s64 = ctx.r11.s64 + 16260;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// lfs f0,1976(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1976);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f11.u64);
	// lwz r7,148(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// stw r7,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8208C9DC:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f13,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r11,16260
	ctx.r9.s64 = ctx.r11.s64 + 16260;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// lfs f0,1976(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1976);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f11.u64);
	// lwz r7,148(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// stw r7,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8208CA10:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82082700
	ctx.lr = 0x8208CA18;
	sub_82082700(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,9588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9588);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfs f13,16260(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 16260);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8208ca44
	if (ctx.cr6.lt) goto loc_8208CA44;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,9540(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8208ca48
	if (!ctx.cr6.gt) goto loc_8208CA48;
loc_8208CA44:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
loc_8208CA48:
	// lbz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 136);
	// stfs f0,100(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 100, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208cb74
	if (ctx.cr6.eq) goto loc_8208CB74;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lfs f1,96(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lhz r5,104(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 104);
	// fmr f2,f0
	ctx.f2.f64 = ctx.f0.f64;
	// lwz r11,-6612(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8209f400
	ctx.lr = 0x8208CA78;
	sub_8209F400(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8208CA80:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82082700
	ctx.lr = 0x8208CA88;
	sub_82082700(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,9588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9588);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfs f13,9536(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8208cab4
	if (ctx.cr6.lt) goto loc_8208CAB4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,9540(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8208cab8
	if (!ctx.cr6.gt) goto loc_8208CAB8;
loc_8208CAB4:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
loc_8208CAB8:
	// lbz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 136);
	// stfs f0,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 96, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208cb74
	if (ctx.cr6.eq) goto loc_8208CB74;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lfs f2,100(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lhz r5,104(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 104);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// lwz r11,-6612(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8209f400
	ctx.lr = 0x8208CAE8;
	sub_8209F400(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8208CAF0:
	// li r4,1
	ctx.r4.s64 = 1;
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// bne cr6,0x8208cb10
	if (!ctx.cr6.eq) goto loc_8208CB10;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82082700
	ctx.lr = 0x8208CB04;
	sub_82082700(ctx, base);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x82082bb0
	ctx.lr = 0x8208CB0C;
	sub_82082BB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_8208CB10:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8208cb74
	if (ctx.cr6.eq) goto loc_8208CB74;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8208c790
	ctx.lr = 0x8208CB20;
	sub_8208C790(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8208CB28:
	// lbz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 136);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208cb74
	if (ctx.cr6.eq) goto loc_8208CB74;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8208cb6c
	if (!ctx.cr6.gt) goto loc_8208CB6C;
	// addi r30,r31,104
	ctx.r30.s64 = ctx.r31.s64 + 104;
	// lis r28,-32218
	ctx.r28.s64 = -2111438848;
loc_8208CB48:
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r4,-6612(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + -6612);
	// lhz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// bl 0x82096e50
	ctx.lr = 0x8208CB58;
	sub_82096E50(ctx, base);
	// lbz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 136);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8208cb48
	if (ctx.cr6.lt) goto loc_8208CB48;
loc_8208CB6C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,136(r31)
	REX_STORE_U8(ctx.r31.u32 + 136, ctx.r11.u8);
loc_8208CB74:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
