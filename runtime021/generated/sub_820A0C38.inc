DEFINE_REX_FUNC(sub_820A0C38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820A0C40;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// li r27,1
	ctx.r27.s64 = 1;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// slw r10,r27,r31
	ctx.r10.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r31.u8 & 0x3F));
	// lwz r11,-6628(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r9,36(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x820a0c8c
	if (!ctx.cr6.eq) goto loc_820A0C8C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r27,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r27.u32);
	// stw r11,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A0C8C:
	// lis r30,-32215
	ctx.r30.s64 = -2111242240;
	// li r25,0
	ctx.r25.s64 = 0;
	// lbz r11,2704(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 2704);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a0ca8
	if (ctx.cr6.eq) goto loc_820A0CA8;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// b 0x820a0ce0
	goto loc_820A0CE0;
loc_820A0CA8:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x820b6818
	ctx.lr = 0x820A0CB4;
	sub_820B6818(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a0cdc
	if (!ctx.cr6.eq) goto loc_820A0CDC;
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a0cdc
	if (ctx.cr6.eq) goto loc_820A0CDC;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stb r10,2704(r30)
	REX_STORE_U8(ctx.r30.u32 + 2704, ctx.r10.u8);
	// b 0x820a0ce0
	goto loc_820A0CE0;
loc_820A0CDC:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_820A0CE0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a0d04
	if (!ctx.cr6.eq) goto loc_820A0D04;
	// stw r27,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r27.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r25,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r25.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820A0D04:
	// addi r11,r31,5
	ctx.r11.s64 = ctx.r31.s64 + 5;
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r30,r11,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r30,r28
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r28.u32);
	// bl 0x8209d3d8
	ctx.lr = 0x820A0D1C;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r30,r28
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r28.u32);
	// bl 0x8209d488
	ctx.lr = 0x820A0D2C;
	sub_8209D488(ctx, base);
	// lbz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lwz r3,-6624(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -6624);
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// bl 0x82058478
	ctx.lr = 0x820A0D4C;
	sub_82058478(ctx, base);
	// lwz r11,-6628(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// clrlwi r5,r11,31
	ctx.r5.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820a0d68
	if (ctx.cr6.eq) goto loc_820A0D68;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_820A0D68:
	// rlwinm r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a0d78
	if (ctx.cr6.eq) goto loc_820A0D78;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_820A0D78:
	// rlwinm r9,r11,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a0d88
	if (ctx.cr6.eq) goto loc_820A0D88;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_820A0D88:
	// rlwinm r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a0d98
	if (ctx.cr6.eq) goto loc_820A0D98;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_820A0D98:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x820a0e7c
	if (!ctx.cr6.eq) goto loc_820A0E7C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwzx r4,r30,r28
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r28.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x820A0DB0;
	sub_8209D488(ctx, base);
	// lbz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f12,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfs f31,18268(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18268);
	ctx.f31.f64 = double(temp.f32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lwz r31,-6612(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + -6612);
	// lfs f13,108(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f10,f31
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f31.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x820a0e10
	if (ctx.cr6.eq) goto loc_820A0E10;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f13,100(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,108(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lwz r10,5376(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 5376);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a0e10
	if (ctx.cr6.eq) goto loc_820A0E10;
	// stfs f1,5384(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 5384, temp.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x820d8430
	ctx.lr = 0x820A0E0C;
	sub_820D8430(ctx, base);
	// lwz r31,-6612(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + -6612);
loc_820A0E10:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwzx r4,r30,r28
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r28.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x820A0E20;
	sub_8209D488(ctx, base);
	// lbz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f12,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lfs f13,104(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f10,f31
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f31.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x820a0e48
	if (ctx.cr6.eq) goto loc_820A0E48;
	// stfs f0,104(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 104, temp.u32);
loc_820A0E48:
	// li r5,73
	ctx.r5.s64 = 73;
	// lwzx r4,r30,r28
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r28.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x820A0E58;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r30,r28
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r28.u32);
	// bl 0x8209d488
	ctx.lr = 0x820A0E68;
	sub_8209D488(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// stb r7,8(r28)
	REX_STORE_U8(ctx.r28.u32 + 8, ctx.r7.u8);
loc_820A0E7C:
	// stw r25,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r25.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r25,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r25.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
