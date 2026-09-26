DEFINE_REX_FUNC(sub_82065F78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82065F80;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a858
	ctx.lr = 0x82065F88;
	__savefpr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// lfs f0,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f2,f0
	ctx.cr6.compare(ctx.f2.f64, ctx.f0.f64);
	// beq cr6,0x82065fb0
	if (ctx.cr6.eq) goto loc_82065FB0;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82065FB0:
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lbz r8,392(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 392);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r11,-6596(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -6596);
	// lfs f31,18248(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 18248);
	ctx.f31.f64 = double(temp.f32);
	// lwz r4,16(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// std r4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r3,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// frsp f30,f12
	ctx.f30.f64 = double(float(ctx.f12.f64));
	// frsp f29,f11
	ctx.f29.f64 = double(float(ctx.f11.f64));
	// beq cr6,0x82066100
	if (ctx.cr6.eq) goto loc_82066100;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f0,9672(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9672);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,36(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 36, temp.u32);
	// lhz r7,398(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 398);
	// lhz r5,396(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 396);
	// lfs f0,9668(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9668);
	ctx.f0.f64 = double(temp.f32);
	// lhz r6,400(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 400);
	// extsw r10,r6
	ctx.r10.s64 = ctx.r6.s32;
	// rotlwi r11,r7,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// lhz r4,394(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 394);
	// extsw r6,r5
	ctx.r6.s64 = ctx.r5.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// lfd f10,80(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// rotlwi r3,r4,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// std r6,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// lfd f9,80(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// extsw r4,r3
	ctx.r4.s64 = ctx.r3.s32;
	// lfs f13,404(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 404);
	ctx.f13.f64 = double(temp.f32);
	// std r5,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lfs f12,408(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 408);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f30,f0
	ctx.f11.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// fcfid f1,f9
	ctx.f1.f64 = double(ctx.f9.s64);
	// lfs f0,9664(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9664);
	ctx.f0.f64 = double(temp.f32);
	// fcfid f2,f10
	ctx.f2.f64 = double(ctx.f10.s64);
	// stb r29,20(r30)
	REX_STORE_U8(ctx.r30.u32 + 20, ctx.r29.u8);
	// fcfid f4,f8
	ctx.f4.f64 = double(ctx.f8.s64);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// fmuls f7,f30,f0
	ctx.f7.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// lfs f0,9660(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9660);
	ctx.f0.f64 = double(temp.f32);
	// frsp f6,f1
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// frsp f8,f2
	ctx.f8.f64 = double(float(ctx.f2.f64));
	// frsp f10,f4
	ctx.f10.f64 = double(float(ctx.f4.f64));
	// frsp f3,f5
	ctx.f3.f64 = double(float(ctx.f5.f64));
	// fnmsubs f4,f6,f31,f8
	ctx.f4.f64 = double(float(-std::fma(ctx.f6.f64, ctx.f31.f64, -ctx.f8.f64)));
	// fdivs f9,f11,f3
	ctx.f9.f64 = double(float(ctx.f11.f64 / ctx.f3.f64));
	// fmadds f2,f4,f0,f12
	ctx.f2.f64 = double(float(std::fma(ctx.f4.f64, ctx.f0.f64, ctx.f12.f64)));
	// stfs f2,8(r30)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// fmadds f5,f9,f10,f7
	ctx.f5.f64 = double(float(std::fma(ctx.f9.f64, ctx.f10.f64, ctx.f7.f64)));
	// fadds f3,f5,f13
	ctx.f3.f64 = double(float(ctx.f5.f64 + ctx.f13.f64));
	// stfs f3,4(r30)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// lhz r3,394(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 394);
	// lhz r11,398(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 398);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r10,398(r31)
	REX_STORE_U16(ctx.r31.u32 + 398, ctx.r10.u16);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x82066118
	if (!ctx.cr6.gt) goto loc_82066118;
	// lhz r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 400);
	// li r10,1
	ctx.r10.s64 = 1;
	// lhz r9,396(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 396);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// sth r10,398(r31)
	REX_STORE_U16(ctx.r31.u32 + 398, ctx.r10.u16);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r7,400(r31)
	REX_STORE_U16(ctx.r31.u32 + 400, ctx.r7.u16);
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x82066118
	if (!ctx.cr6.gt) goto loc_82066118;
	// stb r29,392(r31)
	REX_STORE_U8(ctx.r31.u32 + 392, ctx.r29.u8);
	// b 0x82066118
	goto loc_82066118;
loc_82066100:
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82066118
	if (!ctx.cr6.eq) goto loc_82066118;
	// stfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// stb r10,20(r30)
	REX_STORE_U8(ctx.r30.u32 + 20, ctx.r10.u8);
	// stfs f2,8(r30)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
loc_82066118:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206612C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// beq cr6,0x82066244
	if (ctx.cr6.eq) goto loc_82066244;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82066148;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 5, ctx.xer);
	// beq cr6,0x82066244
	if (ctx.cr6.eq) goto loc_82066244;
	// lhz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,9656(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9656);
	ctx.f0.f64 = double(temp.f32);
	// stwx r30,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r30.u32);
	// lhz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// sth r6,4(r31)
	REX_STORE_U16(ctx.r31.u32 + 4, ctx.r6.u16);
	// clrlwi r4,r6,16
	ctx.r4.u64 = ctx.r6.u32 & 0xFFFF;
	// std r5,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmsubs f29,f29,f31,f10
	ctx.f29.f64 = double(float(std::fma(ctx.f29.f64, ctx.f31.f64, -ctx.f10.f64)));
	// beq cr6,0x82066260
	if (ctx.cr6.eq) goto loc_82066260;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// addi r30,r31,20
	ctx.r30.s64 = ctx.r31.s64 + 20;
	// lfs f28,9652(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9652);
	ctx.f28.f64 = double(temp.f32);
loc_820661B0:
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820661D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x820661e0
	if (!ctx.cr6.eq) goto loc_820661E0;
	// sth r29,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r29.u16);
loc_820661E0:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lbz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 20);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206621c
	if (ctx.cr6.eq) goto loc_8206621C;
	// clrldi r11,r28,32
	ctx.r11.u64 = ctx.r28.u64 & 0xFFFFFFFF;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// fmuls f0,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f31.f64));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f0,4(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fadds f10,f11,f29
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f29.f64));
	// fadds f9,f10,f28
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f28.f64));
	// stfs f9,8(r10)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r10.u32 + 8, temp.u32);
loc_8206621C:
	// lhz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r28,r28,30
	ctx.r28.s64 = ctx.r28.s64 + 30;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820661b0
	if (ctx.cr6.lt) goto loc_820661B0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a8a4
	ctx.lr = 0x82066240;
	__restfpr_28(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82066244:
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// addi r11,r11,69
	ctx.r11.s64 = ctx.r11.s64 + 69;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r10,r31
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, ctx.r30.u32);
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// sth r9,6(r31)
	REX_STORE_U16(ctx.r31.u32 + 6, ctx.r9.u16);
loc_82066260:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a8a4
	ctx.lr = 0x8206626C;
	__restfpr_28(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
