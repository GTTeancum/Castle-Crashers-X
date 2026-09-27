DEFINE_REX_FUNC(sub_820B46A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820B46B0;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// bl 0x820b1fb0
	ctx.lr = 0x820B46C0;
	sub_820B1FB0(ctx, base);
	// lwz r29,52(r27)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r27.u32 + 52);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820b4914
	if (ctx.cr6.eq) goto loc_820B4914;
loc_820B46CC:
	// lwz r28,20(r29)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x80000000U) : (ctx.f10.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f9.u64);
	// lwz r8,92(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge cr6,0x820b470c
	if (!ctx.cr6.lt) goto loc_820B470C;
	// neg r8,r8
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r8.u64);
loc_820B470C:
	// cmpwi cr6,r8,48
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 48, ctx.xer);
	// bgt cr6,0x820b4718
	if (ctx.cr6.gt) goto loc_820B4718;
	// li r8,32
	ctx.r8.s64 = 32;
loc_820B4718:
	// lwz r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r7,12(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r5,4(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r6,8(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// subf r10,r7,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r7.u64;
	// subf r9,r4,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r4.u64;
	// mullw r11,r10,r10
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r10.s32);
	// mullw r3,r9,r9
	ctx.r3.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r9.s32);
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// extsw r3,r11
	ctx.r3.s64 = ctx.r11.s32;
	// std r3,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// fsqrts f12,f13
	ctx.f12.f64 = double(float(sqrt(ctx.f13.f64)));
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f11.u64);
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x820b4898
	if (!ctx.cr6.gt) goto loc_820B4898;
	// mullw r31,r10,r8
	ctx.r31.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mullw r8,r9,r8
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// rotlwi r10,r31,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r31.u32, 1);
	// rotlwi r9,r8,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r30,r8,r11
	ctx.r30.u64 = uint32_t((ctx.r11.s32 && !(ctx.r8.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r8.s32 / ctx.r11.s32 : 0);
	// divw r31,r31,r11
	ctx.r31.u64 = uint32_t((ctx.r11.s32 && !(ctx.r31.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r31.s32 / ctx.r11.s32 : 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// subf r7,r31,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r31.u64;
	// add r6,r6,r30
	ctx.r6.u64 = ctx.r6.u64 + ctx.r30.u64;
	// add r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 + ctx.r30.u64;
	// subf r4,r30,r4
	ctx.r4.u64 = ctx.r4.u64 - ctx.r30.u64;
	// addi r28,r28,12
	ctx.r28.s64 = ctx.r28.s64 + 12;
	// andc r26,r11,r10
	ctx.r26.u64 = ctx.r11.u64 & ~ctx.r10.u64;
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// andc r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ~ctx.r9.u64;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// add r7,r7,r30
	ctx.r7.u64 = ctx.r7.u64 + ctx.r30.u64;
	// add r6,r6,r31
	ctx.r6.u64 = ctx.r6.u64 + ctx.r31.u64;
	// add r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 + ctx.r31.u64;
	// add r4,r4,r31
	ctx.r4.u64 = ctx.r4.u64 + ctx.r31.u64;
	// twlgei r26,-1
	if (ctx.r26.s32 == -1 || ctx.r26.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// twlgei r11,-1
	if (ctx.r11.s32 == -1 || ctx.r11.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// bl 0x820b1ae8
	ctx.lr = 0x820B47D8;
	sub_820B1AE8(ctx, base);
	// lwz r7,12(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// lwz r5,4(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// subf r4,r30,r7
	ctx.r4.u64 = ctx.r7.u64 - ctx.r30.u64;
	// lwz r6,8(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// subf r11,r30,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r30.u64;
	// subf r6,r31,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r31.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// add r6,r6,r30
	ctx.r6.u64 = ctx.r6.u64 + ctx.r30.u64;
	// add r5,r11,r31
	ctx.r5.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// subf r26,r30,r7
	ctx.r26.u64 = ctx.r7.u64 - ctx.r30.u64;
	// subf r7,r31,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r31.u64;
	// subf r4,r31,r26
	ctx.r4.u64 = ctx.r26.u64 - ctx.r31.u64;
	// bl 0x820b1ae8
	ctx.lr = 0x820B481C;
	sub_820B1AE8(ctx, base);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r5,12(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// subf r6,r31,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r31.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// subf r11,r30,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r30.u64;
	// subf r5,r31,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r31.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// add r6,r6,r30
	ctx.r6.u64 = ctx.r6.u64 + ctx.r30.u64;
	// subf r7,r31,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r31.u64;
	// add r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 + ctx.r30.u64;
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// bl 0x820b1ae8
	ctx.lr = 0x820B4858;
	sub_820B1AE8(ctx, base);
	// lwz r7,4(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// subf r6,r30,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r30.u64;
	// add r5,r7,r30
	ctx.r5.u64 = ctx.r7.u64 + ctx.r30.u64;
	// add r7,r6,r31
	ctx.r7.u64 = ctx.r6.u64 + ctx.r31.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// add r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 + ctx.r31.u64;
	// lwz r6,0(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// subf r11,r30,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r30.u64;
	// subf r6,r31,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r31.u64;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x820b1ae8
	ctx.lr = 0x820B4890;
	sub_820B1AE8(ctx, base);
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// bl 0x820b1fb0
	ctx.lr = 0x820B4898;
	sub_820B1FB0(ctx, base);
loc_820B4898:
	// lwz r29,24(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820b46cc
	if (!ctx.cr6.eq) goto loc_820B46CC;
	// lwz r30,52(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 52);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820b4908
	if (ctx.cr6.eq) goto loc_820B4908;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// addi r28,r10,29632
	ctx.r28.s64 = ctx.r10.s64 + 29632;
	// addi r26,r11,-1768
	ctx.r26.s64 = ctx.r11.s64 + -1768;
loc_820B48C4:
	// lbz r11,-22601(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// lwz r31,24(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820b48e8
	if (!ctx.cr6.eq) goto loc_820B48E8;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820B48E8;
	sub_820A71E8(ctx, base);
loc_820B48E8:
	// bl 0x820b5eb8
	ctx.lr = 0x820B48EC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// bl 0x8209bf18
	ctx.lr = 0x820B48FC;
	sub_8209BF18(ctx, base);
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x820b48c4
	if (!ctx.cr6.eq) goto loc_820B48C4;
loc_820B4908:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r27)
	REX_STORE_U32(ctx.r27.u32 + 52, ctx.r11.u32);
	// stw r11,56(r27)
	REX_STORE_U32(ctx.r27.u32 + 56, ctx.r11.u32);
loc_820B4914:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
