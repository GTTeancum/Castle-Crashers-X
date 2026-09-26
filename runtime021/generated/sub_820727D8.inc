DEFINE_REX_FUNC(sub_820727D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820727E0;
	__savegprlr_27(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,1
	ctx.r29.s64 = 1;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// lbz r11,22(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 22);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// lfs f0,9536(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// stb r30,19(r10)
	REX_STORE_U8(ctx.r10.u32 + 19, ctx.r30.u8);
	// stb r30,22(r10)
	REX_STORE_U8(ctx.r10.u32 + 22, ctx.r30.u8);
	// stb r11,21(r10)
	REX_STORE_U8(ctx.r10.u32 + 21, ctx.r11.u8);
	// beq cr6,0x820729c8
	if (ctx.cr6.eq) goto loc_820729C8;
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// ld r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r9,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lwz r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r7,116(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
loc_82072838:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82072848
	if (ctx.cr6.eq) goto loc_82072848;
	// cmplw cr6,r6,r10
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8207284c
	if (ctx.cr6.eq) goto loc_8207284C;
loc_82072848:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_8207284C:
	// cmplw cr6,r7,r3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x82072948
	if (ctx.cr6.eq) goto loc_82072948;
	// lbz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 20);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82072918
	if (!ctx.cr6.eq) goto loc_82072918;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x82072870
	if (!ctx.cr6.eq) goto loc_82072870;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82072870:
	// lwz r11,4(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82072880
	if (!ctx.cr6.eq) goto loc_82072880;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82072880:
	// lwz r9,8(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// rlwinm r28,r9,0,0,0
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820728d8
	if (ctx.cr6.eq) goto loc_820728D8;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8207289c
	if (!ctx.cr6.eq) goto loc_8207289C;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_8207289C:
	// lbz r28,30(r5)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r5.u32 + 30);
	// rlwinm r27,r9,16,16,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF;
	// and r28,r28,r27
	ctx.r28.u64 = ctx.r28.u64 & ctx.r27.u64;
	// clrlwi r28,r28,20
	ctx.r28.u64 = ctx.r28.u32 & 0xFFF;
	// cntlzw r28,r28
	ctx.r28.u64 = ctx.r28.u32 == 0 ? 32 : __builtin_clz(ctx.r28.u32);
	// rlwinm r28,r28,27,31,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 27) & 0x1;
	// xori r28,r28,1
	ctx.r28.u64 = ctx.r28.u64 ^ 1;
	// clrlwi r28,r28,24
	ctx.r28.u64 = ctx.r28.u32 & 0xFF;
	// std r28,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r28.u64);
	// lfd f13,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// beq cr6,0x820728d8
	if (ctx.cr6.eq) goto loc_820728D8;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
loc_820728D8:
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820728e4
	if (!ctx.cr6.eq) goto loc_820728E4;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_820728E4:
	// lhz r11,28(r5)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r5.u32 + 28);
	// and r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cntlzw r11,r9
	ctx.r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	ctx.r11.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// std r11,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r11.u64);
	// lfd f13,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// beq cr6,0x82072918
	if (ctx.cr6.eq) goto loc_82072918;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
loc_82072918:
	// stb r8,0(r4)
	REX_STORE_U8(ctx.r4.u32 + 0, ctx.r8.u8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x82072930
	if (!ctx.cr6.eq) goto loc_82072930;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82072930:
	// lwz r11,4(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82072940
	if (!ctx.cr6.eq) goto loc_82072940;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82072940:
	// lwz r7,0(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// b 0x82072838
	goto loc_82072838;
loc_82072948:
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820729c8
	if (ctx.cr6.eq) goto loc_820729C8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r7,12(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// addi r3,r11,-8292
	ctx.r3.s64 = ctx.r11.s64 + -8292;
loc_82072964:
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// blt cr6,0x82072998
	if (ctx.cr6.lt) goto loc_82072998;
	// beq cr6,0x8207297c
	if (ctx.cr6.eq) goto loc_8207297C;
	// stb r30,19(r10)
	REX_STORE_U8(ctx.r10.u32 + 19, ctx.r30.u8);
	// bl 0x8208c5d8
	ctx.lr = 0x82072978;
	sub_8208C5D8(ctx, base);
	// b 0x820729b0
	goto loc_820729B0;
loc_8207297C:
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lbzx r6,r8,r11
	ctx.r6.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r11.u32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x820729ac
	if (!ctx.cr6.eq) goto loc_820729AC;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// stb r30,19(r10)
	REX_STORE_U8(ctx.r10.u32 + 19, ctx.r30.u8);
	// b 0x820729b0
	goto loc_820729B0;
loc_82072998:
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lbzx r6,r8,r11
	ctx.r6.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r11.u32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820729b0
	if (ctx.cr6.eq) goto loc_820729B0;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
loc_820729AC:
	// stb r29,19(r10)
	REX_STORE_U8(ctx.r10.u32 + 19, ctx.r29.u8);
loc_820729B0:
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820729c8
	if (!ctx.cr6.eq) goto loc_820729C8;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplw cr6,r8,r31
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x82072964
	if (ctx.cr6.lt) goto loc_82072964;
loc_820729C8:
	// lbz r11,23(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 23);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820729e8
	if (ctx.cr6.eq) goto loc_820729E8;
	// lbz r11,19(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 19);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82072a24
	if (!ctx.cr6.eq) goto loc_82072A24;
	// stb r30,23(r10)
	REX_STORE_U8(ctx.r10.u32 + 23, ctx.r30.u8);
	// b 0x82072a24
	goto loc_82072A24;
loc_820729E8:
	// lbz r11,16(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82072a10
	if (!ctx.cr6.eq) goto loc_82072A10;
	// lbz r11,17(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 17);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82072a10
	if (!ctx.cr6.eq) goto loc_82072A10;
	// lbz r11,19(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 19);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82072a24
	if (ctx.cr6.eq) goto loc_82072A24;
	// b 0x82072a20
	goto loc_82072A20;
loc_82072A10:
	// lbz r11,19(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 19);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82072a24
	if (ctx.cr6.eq) goto loc_82072A24;
	// stb r29,23(r10)
	REX_STORE_U8(ctx.r10.u32 + 23, ctx.r29.u8);
loc_82072A20:
	// stb r29,22(r10)
	REX_STORE_U8(ctx.r10.u32 + 22, ctx.r29.u8);
loc_82072A24:
	// lbz r9,17(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 17);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82072aac
	if (ctx.cr6.eq) goto loc_82072AAC;
	// lbz r9,24(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 24);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82072a84
	if (ctx.cr6.eq) goto loc_82072A84;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82072a74
	if (ctx.cr6.eq) goto loc_82072A74;
	// lfs f13,28(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f1
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// stfs f12,28(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bgt cr6,0x82072aac
	if (ctx.cr6.gt) goto loc_82072AAC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stb r29,22(r10)
	REX_STORE_U8(ctx.r10.u32 + 22, ctx.r29.u8);
	// addi r9,r11,18248
	ctx.r9.s64 = ctx.r11.s64 + 18248;
	// lfs f0,12(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,28(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82072A74:
	// stb r30,24(r10)
	REX_STORE_U8(ctx.r10.u32 + 24, ctx.r30.u8);
	// stfs f0,28(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82072A84:
	// lbz r11,23(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 23);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82072aac
	if (ctx.cr6.eq) goto loc_82072AAC;
	// lbz r11,22(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 22);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82072aac
	if (ctx.cr6.eq) goto loc_82072AAC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stb r29,24(r10)
	REX_STORE_U8(ctx.r10.u32 + 24, ctx.r29.u8);
	// lfs f0,18248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18248);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,28(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 28, temp.u32);
loc_82072AAC:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
