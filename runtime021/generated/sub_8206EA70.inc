DEFINE_REX_FUNC(sub_8206EA70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8206EA78;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32215
	ctx.r26.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r24,r11,-1768
	ctx.r24.s64 = ctx.r11.s64 + -1768;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206eab4
	if (!ctx.cr6.eq) goto loc_8206EAB4;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206EAB4;
	sub_820A71E8(ctx, base);
loc_8206EAB4:
	// bl 0x820b5eb8
	ctx.lr = 0x8206EAB8;
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
	ctx.lr = 0x8206EAD0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206eaf4
	if (ctx.cr6.eq) goto loc_8206EAF4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,497
	ctx.r6.s64 = 497;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x8206EAEC;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206eaf8
	goto loc_8206EAF8;
loc_8206EAF4:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206EAF8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f31,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206EB10;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r26)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206eb30
	if (!ctx.cr6.eq) goto loc_8206EB30;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206EB30;
	sub_820A71E8(ctx, base);
loc_8206EB30:
	// bl 0x820b5eb8
	ctx.lr = 0x8206EB34;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206EB44;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206eb68
	if (ctx.cr6.eq) goto loc_8206EB68;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,498
	ctx.r6.s64 = 498;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x8206EB60;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206eb6c
	goto loc_8206EB6C;
loc_8206EB68:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206EB6C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206EB7C;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206eb9c
	if (!ctx.cr6.eq) goto loc_8206EB9C;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206EB9C;
	sub_820A71E8(ctx, base);
loc_8206EB9C:
	// bl 0x820b5eb8
	ctx.lr = 0x8206EBA0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206EBB0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206ebd4
	if (ctx.cr6.eq) goto loc_8206EBD4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,499
	ctx.r6.s64 = 499;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x8206EBCC;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206ebd8
	goto loc_8206EBD8;
loc_8206EBD4:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206EBD8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206EBE8;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206ec08
	if (!ctx.cr6.eq) goto loc_8206EC08;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206EC08;
	sub_820A71E8(ctx, base);
loc_8206EC08:
	// bl 0x820b5eb8
	ctx.lr = 0x8206EC0C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206EC1C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206ec40
	if (ctx.cr6.eq) goto loc_8206EC40;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x8206EC38;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206ec44
	goto loc_8206EC44;
loc_8206EC40:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206EC44:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206EC54;
	sub_82065F78(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lbz r7,-22601(r26)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-4704
	ctx.r8.s64 = ctx.r10.s64 + -4704;
	// stw r27,356(r29)
	REX_STORE_U32(ctx.r29.u32 + 356, ctx.r27.u32);
	// sth r9,388(r29)
	REX_STORE_U16(ctx.r29.u32 + 388, ctx.r9.u16);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r8,360(r29)
	REX_STORE_U32(ctx.r29.u32 + 360, ctx.r8.u32);
	// bne cr6,0x8206ec8c
	if (!ctx.cr6.eq) goto loc_8206EC8C;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206EC8C;
	sub_820A71E8(ctx, base);
loc_8206EC8C:
	// bl 0x820b5eb8
	ctx.lr = 0x8206EC90;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206ECA0;
	sub_8209BDD8(ctx, base);
	// lis r10,-21846
	ctx.r10.s64 = -1431699456;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// ori r30,r10,43775
	ctx.r30.u64 = ctx.r10.u64 | 43775;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r28,r11,9460
	ctx.r28.s64 = ctx.r11.s64 + 9460;
	// beq cr6,0x8206ece8
	if (ctx.cr6.eq) goto loc_8206ECE8;
	// lwz r23,4(r27)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206ECC4;
	sub_82066F80(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r23,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r23.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x8206ECDC;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8206ecec
	goto loc_8206ECEC;
loc_8206ECE8:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206ECEC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206ECFC;
	sub_82065F78(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lbz r7,-22601(r26)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r26.u32 + -22601);
	// li r9,15
	ctx.r9.s64 = 15;
	// addi r8,r10,-4672
	ctx.r8.s64 = ctx.r10.s64 + -4672;
	// stw r27,356(r29)
	REX_STORE_U32(ctx.r29.u32 + 356, ctx.r27.u32);
	// sth r9,390(r29)
	REX_STORE_U16(ctx.r29.u32 + 390, ctx.r9.u16);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r8,364(r29)
	REX_STORE_U32(ctx.r29.u32 + 364, ctx.r8.u32);
	// bne cr6,0x8206ed34
	if (!ctx.cr6.eq) goto loc_8206ED34;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206ED34;
	sub_820A71E8(ctx, base);
loc_8206ED34:
	// bl 0x820b5eb8
	ctx.lr = 0x8206ED38;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206ED48;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206ed80
	if (ctx.cr6.eq) goto loc_8206ED80;
	// lwz r27,4(r27)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82066f80
	ctx.lr = 0x8206ED5C;
	sub_82066F80(ctx, base);
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82067e00
	ctx.lr = 0x8206ED74;
	sub_82067E00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// b 0x8206ed84
	goto loc_8206ED84;
loc_8206ED80:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206ED84:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206ED94;
	sub_82065F78(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
