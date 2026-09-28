DEFINE_REX_FUNC(sub_820E8540) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820E8548;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x8214abc4
	ctx.lr = 0x820E855C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r30,r11,22852
	ctx.r30.s64 = ctx.r11.s64 + 22852;
	// mr r29,r13
	ctx.r29.u64 = ctx.r13.u64;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e8584
	if (ctx.cr6.eq) goto loc_820E8584;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820e8598
	if (ctx.cr6.eq) goto loc_820E8598;
loc_820E8584:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820E858C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r29,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r29.u32);
	// stb r28,12(r30)
	REX_STORE_U8(ctx.r30.u32 + 12, ctx.r28.u8);
loc_820E8598:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lfd f1,-31632(r10)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r10.u32 + -31632);
	// bl 0x8212ac88
	ctx.lr = 0x820E85B0;
	sub_8212AC88(ctx, base);
	// lbz r9,56(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,116(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 116, temp.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820e863c
	if (ctx.cr6.eq) goto loc_820E863C;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,1
	ctx.r8.s64 = 1;
loc_820E85D0:
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,200(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// addi r6,r10,8
	ctx.r6.s64 = ctx.r10.s64 + 8;
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// add r5,r11,r31
	ctx.r5.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mulli r11,r10,88
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(88));
	// lwz r3,60(r5)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + 60);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r3,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// rlwinm r9,r6,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lbzx r5,r9,r31
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r31.u32);
	// lwz r4,80(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stb r8,12(r11)
	REX_STORE_U8(ctx.r11.u32 + 12, ctx.r8.u8);
	// ori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 | 1;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// stb r5,13(r11)
	REX_STORE_U8(ctx.r11.u32 + 13, ctx.r5.u8);
	// stw r3,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r3.u32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fctidz f9,f10
	ctx.f9.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfiwx f9,r11,r7
	REX_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.f9.u32);
	// lbz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820e85d0
	if (ctx.cr6.lt) goto loc_820E85D0;
loc_820E863C:
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820e8688
	if (ctx.cr6.eq) goto loc_820E8688;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820e8688
	if (!ctx.cr6.eq) goto loc_820E8688;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// bne 0x820e8688
	if (!ctx.cr0.eq) goto loc_820E8688;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r31,12(r30)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r30.u32 + 12);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stb r11,12(r30)
	REX_STORE_U8(ctx.r30.u32 + 12, ctx.r11.u8);
	// bl 0x8214a794
	ctx.lr = 0x820E8680;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820E8688;
	__imp__KfLowerIrql(ctx, base);
loc_820E8688:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
