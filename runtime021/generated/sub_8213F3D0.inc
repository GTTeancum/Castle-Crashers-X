DEFINE_REX_FUNC(sub_8213F3D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x8213F3D8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,304(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 304);
	// lwz r9,312(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// lhz r8,68(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 68);
	// lhz r7,64(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 64);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfd f13,9616(r10)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r10.u32 + 9616);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// subf r10,r8,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r8.u64;
	// fdiv f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 / ctx.f0.f64;
	// fcmpu cr6,f11,f13
	ctx.cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bge cr6,0x8213f428
	if (!ctx.cr6.lt) goto loc_8213F428;
	// fdiv f12,f12,f0
	ctx.f12.f64 = ctx.f12.f64 / ctx.f0.f64;
	// b 0x8213f42c
	goto loc_8213F42C;
loc_8213F428:
	// fmr f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f13.f64;
loc_8213F42C:
	// lfd f11,288(r31)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r31.u32 + 288);
	// fmul f0,f11,f0
	ctx.f0.f64 = ctx.f11.f64 * ctx.f0.f64;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8213f440
	if (ctx.cr6.lt) goto loc_8213F440;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_8213F440:
	// fsub f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f13.f64 - ctx.f0.f64;
	// addi r11,r10,10
	ctx.r11.s64 = ctx.r10.s64 + 10;
	// fmul f12,f0,f12
	ctx.f12.f64 = ctx.f0.f64 * ctx.f12.f64;
	// stfd f0,296(r31)
	REX_STORE_U64(ctx.r31.u32 + 296, ctx.f0.u64);
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r26,0
	ctx.r26.s64 = 0;
	// lfdx f0,r11,r31
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + ctx.r31.u32);
	// fmadd f0,f13,f0,f12
	ctx.f0.f64 = std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f12.f64);
	// stfdx f0,r11,r31
	REX_STORE_U64(ctx.r11.u32 + ctx.r31.u32, ctx.f0.u64);
	// lfd f0,280(r31)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r31.u32 + 280);
	// stw r26,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r26.u32);
	// stw r26,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r26.u32);
	// lfdx f13,r11,r31
	ctx.f13.u64 = REX_LOAD_U64(ctx.r11.u32 + ctx.r31.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8213f5a0
	if (!ctx.cr6.lt) goto loc_8213F5A0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8213f5fc
	if (ctx.cr6.eq) goto loc_8213F5FC;
	// addi r11,r10,9
	ctx.r11.s64 = ctx.r10.s64 + 9;
	// fsub f13,f13,f0
	ctx.f13.f64 = ctx.f13.f64 - ctx.f0.f64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lfdx f12,r11,r31
	ctx.f12.u64 = REX_LOAD_U64(ctx.r11.u32 + ctx.r31.u32);
	// fsub f0,f12,f0
	ctx.f0.f64 = ctx.f12.f64 - ctx.f0.f64;
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8213f5fc
	if (!ctx.cr6.lt) goto loc_8213F5FC;
	// ld r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// li r10,20
	ctx.r10.s64 = 20;
	// lwz r28,372(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// addi r30,r31,372
	ctx.r30.s64 = ctx.r31.s64 + 372;
	// addi r11,r11,-20
	ctx.r11.s64 = ctx.r11.s64 + -20;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// divdu r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 ? ctx.r11.u64 / ctx.r10.u64 : 0;
	// std r11,40(r31)
	REX_STORE_U64(ctx.r31.u32 + 40, ctx.r11.u64);
	// sth r10,64(r31)
	REX_STORE_U16(ctx.r31.u32 + 64, ctx.r10.u16);
	// beq cr6,0x8213f5fc
	if (ctx.cr6.eq) goto loc_8213F5FC;
	// lwz r27,0(r28)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ld r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// ld r29,24(r27)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r27.u32 + 24);
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// bl 0x8213ec70
	ctx.lr = 0x8213F4EC;
	sub_8213EC70(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8213f5fc
	if (ctx.cr0.eq) goto loc_8213F5FC;
	// ld r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// cmpld cr6,r11,r29
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r29.u64, ctx.xer);
	// ble cr6,0x8213f5fc
	if (!ctx.cr6.gt) goto loc_8213F5FC;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r10,r29,20
	ctx.r10.s64 = ctx.r29.s64 + 20;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8213f590
	if (ctx.cr6.eq) goto loc_8213F590;
loc_8213F514:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// ld r9,24(r9)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r9.u32 + 24);
	// cmpld cr6,r9,r10
	ctx.cr6.compare<uint64_t>(ctx.r9.u64, ctx.r10.u64, ctx.xer);
	// bgt cr6,0x8213f538
	if (ctx.cr6.gt) goto loc_8213F538;
	// bne cr6,0x8213f52c
	if (!ctx.cr6.eq) goto loc_8213F52C;
	// li r8,1
	ctx.r8.s64 = 1;
loc_8213F52C:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8213f514
	if (!ctx.cr6.eq) goto loc_8213F514;
loc_8213F538:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8213f590
	if (ctx.cr6.eq) goto loc_8213F590;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8213f568
	if (ctx.cr6.eq) goto loc_8213F568;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8213f55c
	if (!ctx.cr6.eq) goto loc_8213F55C;
	// stw r26,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r26.u32);
loc_8213F55C:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stw r26,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r26.u32);
loc_8213F568:
	// stw r26,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r26.u32);
	// addi r11,r31,364
	ctx.r11.s64 = ctx.r31.s64 + 364;
	// lwz r10,368(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8213f584
	if (ctx.cr6.eq) goto loc_8213F584;
	// stw r28,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r28.u32);
	// b 0x8213f588
	goto loc_8213F588;
loc_8213F584:
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
loc_8213F588:
	// stw r28,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r28.u32);
	// b 0x8213f5fc
	goto loc_8213F5FC;
loc_8213F590:
	// ld r11,24(r27)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r27.u32 + 24);
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// std r11,24(r27)
	REX_STORE_U64(ctx.r27.u32 + 24, ctx.r11.u64);
	// b 0x8213f5fc
	goto loc_8213F5FC;
loc_8213F5A0:
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r11,25
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 25, ctx.xer);
	// bge cr6,0x8213f5fc
	if (!ctx.cr6.lt) goto loc_8213F5FC;
	// addi r11,r10,11
	ctx.r11.s64 = ctx.r10.s64 + 11;
	// fsub f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f13.f64 - ctx.f0.f64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lfdx f12,r11,r31
	ctx.f12.u64 = REX_LOAD_U64(ctx.r11.u32 + ctx.r31.u32);
	// fsub f0,f12,f0
	ctx.f0.f64 = ctx.f12.f64 - ctx.f0.f64;
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8213f5fc
	if (!ctx.cr6.lt) goto loc_8213F5FC;
	// ld r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x8213f5fc
	if (ctx.cr6.eq) goto loc_8213F5FC;
	// addi r10,r11,-20
	ctx.r10.s64 = ctx.r11.s64 + -20;
	// ld r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// li r9,20
	ctx.r9.s64 = 20;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// std r10,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r10.u64);
	// divdu r10,r11,r9
	ctx.r10.u64 = ctx.r9.u64 ? ctx.r11.u64 / ctx.r9.u64 : 0;
	// std r11,40(r31)
	REX_STORE_U64(ctx.r31.u32 + 40, ctx.r11.u64);
	// sth r10,64(r31)
	REX_STORE_U16(ctx.r31.u32 + 64, ctx.r10.u16);
loc_8213F5FC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
