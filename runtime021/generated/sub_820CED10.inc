DEFINE_REX_FUNC(sub_820CED10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f8
	ctx.lr = 0x820CED18;
	__savegprlr_20(ctx, base);
	// stwu r1,-3376(r1)
	ea = -3376 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r22,r6
	ctx.r22.u64 = ctx.r6.u64;
	// mr r20,r8
	ctx.r20.u64 = ctx.r8.u64;
	// mr r21,r9
	ctx.r21.u64 = ctx.r9.u64;
	// clrlwi. r11,r4,31
	ctx.r11.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r23,0
	ctx.r23.s64 = 0;
	// beq 0x820ced50
	if (ctx.cr0.eq) goto loc_820CED50;
	// bl 0x820cc748
	ctx.lr = 0x820CED40;
	sub_820CC748(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820c7228
	ctx.lr = 0x820CED48;
	sub_820C7228(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820cf02c
	goto loc_820CF02C;
loc_820CED50:
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r11,r11,3
	ctx.r11.u64 = ctx.r11.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addis r30,r11,-16384
	ctx.r30.s64 = ctx.r11.s64 + -1073741824;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820cf014
	if (!ctx.cr6.eq) goto loc_820CF014;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bgt cr6,0x820cf014
	if (ctx.cr6.gt) goto loc_820CF014;
	// lwz r26,21684(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 21684);
	// lwz r28,16(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r28,r26
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r26.u32, ctx.xer);
	// bgt cr6,0x820cf00c
	if (ctx.cr6.gt) goto loc_820CF00C;
	// lwz r27,21688(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 21688);
	// lwz r29,20(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmplw cr6,r29,r27
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r27.u32, ctx.xer);
	// bgt cr6,0x820cf00c
	if (ctx.cr6.gt) goto loc_820CF00C;
	// addi r24,r7,4096
	ctx.r24.s64 = ctx.r7.s64 + 4096;
	// cmplwi cr6,r24,16384
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 16384, ctx.xer);
	// blt cr6,0x820cedc0
	if (ctx.cr6.lt) goto loc_820CEDC0;
	// mr r24,r23
	ctx.r24.u64 = ctx.r23.u64;
	// addi r25,r25,4
	ctx.r25.s64 = ctx.r25.s64 + 4;
	// addi r22,r22,-1
	ctx.r22.s64 = ctx.r22.s64 + -1;
loc_820CEDC0:
	// li r5,52
	ctx.r5.s64 = 52;
	// stw r23,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r23.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x82129fa0
	ctx.lr = 0x820CEDD4;
	sub_82129FA0(ctx, base);
	// lwz r11,21708(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21708);
	// lwz r10,21704(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21704);
	// lfs f0,24(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,28(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r31,21752
	ctx.r3.s64 = ctx.r31.s64 + 21752;
	// stw r28,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// stw r29,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r9,r11,56
	ctx.r9.s64 = ctx.r11.s64 + 56;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// fmuls f0,f12,f13
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r7,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
loc_820CEE4C:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x820cee6c
	if (!ctx.cr0.eq) goto loc_820CEE6C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x820cee4c
	if (!ctx.cr6.eq) goto loc_820CEE4C;
loc_820CEE6C:
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x820cee98
	if (ctx.cr0.eq) goto loc_820CEE98;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// li r5,56
	ctx.r5.s64 = 56;
	// bl 0x82129a70
	ctx.lr = 0x820CEE80;
	sub_82129A70(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820d1788
	ctx.lr = 0x820CEE98;
	sub_820D1788(ctx, base);
loc_820CEE98:
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820ceeb0
	if (ctx.cr0.eq) goto loc_820CEEB0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r29,r30,36
	ctx.r29.s64 = ctx.r30.s64 + 36;
	// b 0x820ceed8
	goto loc_820CEED8;
loc_820CEEB0:
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ceed0
	if (ctx.cr0.eq) goto loc_820CEED0;
	// addi r4,r30,36
	ctx.r4.s64 = ctx.r30.s64 + 36;
	// addi r3,r1,1728
	ctx.r3.s64 = ctx.r1.s64 + 1728;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r29,r1,1728
	ctx.r29.s64 = ctx.r1.s64 + 1728;
	// bl 0x820cc6d8
	ctx.lr = 0x820CEECC;
	sub_820CC6D8(ctx, base);
	// b 0x820ceed8
	goto loc_820CEED8;
loc_820CEED0:
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
loc_820CEED8:
	// lwz r11,23344(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 23344);
	// cmpw cr6,r5,r11
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x820cef20
	if (!ctx.cr6.eq) goto loc_820CEF20;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x820cef58
	if (ctx.cr6.eq) goto loc_820CEF58;
	// addi r10,r31,21808
	ctx.r10.s64 = ctx.r31.s64 + 21808;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// addi r8,r29,1536
	ctx.r8.s64 = ctx.r29.s64 + 1536;
loc_820CEEF8:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820cef18
	if (!ctx.cr0.eq) goto loc_820CEF18;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x820ceef8
	if (!ctx.cr6.eq) goto loc_820CEEF8;
loc_820CEF18:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820cef58
	if (ctx.cr0.eq) goto loc_820CEF58;
loc_820CEF20:
	// stw r5,23344(r31)
	REX_STORE_U32(ctx.r31.u32 + 23344, ctx.r5.u32);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x820cef44
	if (ctx.cr6.eq) goto loc_820CEF44;
	// addi r3,r31,21808
	ctx.r3.s64 = ctx.r31.s64 + 21808;
	// li r5,1536
	ctx.r5.s64 = 1536;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82129a70
	ctx.lr = 0x820CEF3C;
	sub_82129A70(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// b 0x820cef48
	goto loc_820CEF48;
loc_820CEF44:
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
loc_820CEF48:
	// lis r4,10280
	ctx.r4.s64 = 673710080;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r4,r4,262
	ctx.r4.u64 = ctx.r4.u64 | 262;
	// bl 0x820c0580
	ctx.lr = 0x820CEF58;
	sub_820C0580(ctx, base);
loc_820CEF58:
	// lwz r11,21536(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21536);
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// clrlwi r10,r11,1
	ctx.r10.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// stw r10,21536(r31)
	REX_STORE_U32(ctx.r31.u32 + 21536, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,20(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// srawi r29,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r29.s64 = ctx.r11.s32 >> 31;
	// lwz r7,16(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x820ce128
	ctx.lr = 0x820CEF84;
	sub_820CE128(ctx, base);
	// lwz r10,21536(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21536);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r9,21692(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 21692);
	// rlwimi r10,r29,31,0,0
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 31) & 0x80000000) | (ctx.r10.u64 & 0xFFFFFFFF7FFFFFFF);
	// stw r23,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r23.u32);
	// stw r11,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r11.u32);
	// rlwinm r9,r9,12,0,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFFFF000;
	// stw r10,21536(r31)
	REX_STORE_U32(ctx.r31.u32 + 21536, ctx.r10.u32);
	// lfs f0,32(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lwz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// clrlwi. r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// lwz r7,16(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// stw r9,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// stw r7,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r7.u32);
	// stw r10,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// beq 0x820cefd4
	if (ctx.cr0.eq) goto loc_820CEFD4;
	// addi r4,r30,36
	ctx.r4.s64 = ctx.r30.s64 + 36;
	// b 0x820cefe0
	goto loc_820CEFE0;
loc_820CEFD4:
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cefec
	if (ctx.cr0.eq) goto loc_820CEFEC;
	// addi r4,r1,1728
	ctx.r4.s64 = ctx.r1.s64 + 1728;
loc_820CEFE0:
	// li r5,1536
	ctx.r5.s64 = 1536;
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// bl 0x82129a70
	ctx.lr = 0x820CEFEC;
	sub_82129A70(ctx, base);
loc_820CEFEC:
	// cmplwi cr6,r21,1560
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 1560, ctx.xer);
	// li r5,1560
	ctx.r5.s64 = 1560;
	// bgt cr6,0x820ceffc
	if (ctx.cr6.gt) goto loc_820CEFFC;
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
loc_820CEFFC:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x82129a70
	ctx.lr = 0x820CF008;
	sub_82129A70(ctx, base);
	// b 0x820cf018
	goto loc_820CF018;
loc_820CF00C:
	// li r23,7
	ctx.r23.s64 = 7;
	// b 0x820cf018
	goto loc_820CF018;
loc_820CF014:
	// li r23,6
	ctx.r23.s64 = 6;
loc_820CF018:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,1572
	ctx.r4.s64 = ctx.r30.s64 + 1572;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d6470
	ctx.lr = 0x820CF028;
	sub_820D6470(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
loc_820CF02C:
	// addi r1,r1,3376
	ctx.r1.s64 = ctx.r1.s64 + 3376;
	// b 0x82129948
	__restgprlr_20(ctx, base);
	return;
}
