DEFINE_REX_FUNC(sub_82062E80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x82062E88;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r23,r11,-1768
	ctx.r23.s64 = ctx.r11.s64 + -1768;
	// li r24,17
	ctx.r24.s64 = 17;
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// sth r24,16(r30)
	REX_STORE_U16(ctx.r30.u32 + 16, ctx.r24.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062ecc
	if (!ctx.cr6.eq) goto loc_82062ECC;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062ECC;
	sub_820A71E8(ctx, base);
loc_82062ECC:
	// bl 0x820b5eb8
	ctx.lr = 0x82062ED0;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r25,r11,29632
	ctx.r25.s64 = ctx.r11.s64 + 29632;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r10,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062EE8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82062f0c
	if (ctx.cr6.eq) goto loc_82062F0C;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,497
	ctx.r6.s64 = 497;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x82062F04;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062f10
	goto loc_82062F10;
loc_82062F0C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82062F10:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f31,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062F28;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82062f48
	if (!ctx.cr6.eq) goto loc_82062F48;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062F48;
	sub_820A71E8(ctx, base);
loc_82062F48:
	// bl 0x820b5eb8
	ctx.lr = 0x82062F4C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062F5C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82062f80
	if (ctx.cr6.eq) goto loc_82062F80;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,498
	ctx.r6.s64 = 498;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x82062F78;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062f84
	goto loc_82062F84;
loc_82062F80:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82062F84:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82062F94;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82062fb4
	if (!ctx.cr6.eq) goto loc_82062FB4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82062FB4;
	sub_820A71E8(ctx, base);
loc_82062FB4:
	// bl 0x820b5eb8
	ctx.lr = 0x82062FB8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82062FC8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82062fec
	if (ctx.cr6.eq) goto loc_82062FEC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,499
	ctx.r6.s64 = 499;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x82062FE4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82062ff0
	goto loc_82062FF0;
loc_82062FEC:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82062FF0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82063000;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82063020
	if (!ctx.cr6.eq) goto loc_82063020;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82063020;
	sub_820A71E8(ctx, base);
loc_82063020:
	// bl 0x820b5eb8
	ctx.lr = 0x82063024;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82063034;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82063058
	if (ctx.cr6.eq) goto loc_82063058;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x82063050;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206305c
	goto loc_8206305C;
loc_82063058:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206305C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206306C;
	sub_82065F78(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lbz r9,-22601(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// addi r8,r10,14128
	ctx.r8.s64 = ctx.r10.s64 + 14128;
	// sth r24,388(r30)
	REX_STORE_U16(ctx.r30.u32 + 388, ctx.r24.u16);
	// stw r27,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r27.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,360(r30)
	REX_STORE_U32(ctx.r30.u32 + 360, ctx.r8.u32);
	// bne cr6,0x820630a0
	if (!ctx.cr6.eq) goto loc_820630A0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820630A0;
	sub_820A71E8(ctx, base);
loc_820630A0:
	// bl 0x820b5eb8
	ctx.lr = 0x820630A4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820630B4;
	sub_8209BDD8(ctx, base);
	// lis r10,-21846
	ctx.r10.s64 = -1431699456;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// ori r29,r10,43775
	ctx.r29.u64 = ctx.r10.u64 | 43775;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r28,r11,9460
	ctx.r28.s64 = ctx.r11.s64 + 9460;
	// beq cr6,0x820630fc
	if (ctx.cr6.eq) goto loc_820630FC;
	// lwz r22,4(r27)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x820630D8;
	sub_82066F80(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r22,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r22.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x820630F0;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// b 0x82063100
	goto loc_82063100;
loc_820630FC:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82063100:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x82063110;
	sub_82065F78(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lbz r9,-22601(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// addi r8,r10,20768
	ctx.r8.s64 = ctx.r10.s64 + 20768;
	// stw r27,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r27.u32);
	// sth r24,390(r30)
	REX_STORE_U16(ctx.r30.u32 + 390, ctx.r24.u16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,364(r30)
	REX_STORE_U32(ctx.r30.u32 + 364, ctx.r8.u32);
	// bne cr6,0x82063144
	if (!ctx.cr6.eq) goto loc_82063144;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82063144;
	sub_820A71E8(ctx, base);
loc_82063144:
	// bl 0x820b5eb8
	ctx.lr = 0x82063148;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82063158;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82063190
	if (ctx.cr6.eq) goto loc_82063190;
	// lwz r27,4(r27)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206316C;
	sub_82066F80(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x82063184;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// b 0x82063194
	goto loc_82063194;
loc_82063190:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82063194:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x820631A4;
	sub_82065F78(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
