DEFINE_REX_FUNC(sub_8206DF58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8206DF60;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32215
	ctx.r31.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r27,r11,-1768
	ctx.r27.s64 = ctx.r11.s64 + -1768;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lbz r11,-22601(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206df9c
	if (!ctx.cr6.eq) goto loc_8206DF9C;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206DF9C;
	sub_820A71E8(ctx, base);
loc_8206DF9C:
	// bl 0x820b5eb8
	ctx.lr = 0x8206DFA0;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r11,29632
	ctx.r28.s64 = ctx.r11.s64 + 29632;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r10,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r28.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206DFB8;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206dfdc
	if (ctx.cr6.eq) goto loc_8206DFDC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82067020
	ctx.lr = 0x8206DFD4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206dfe0
	goto loc_8206DFE0;
loc_8206DFDC:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206DFE0:
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
	ctx.lr = 0x8206DFF8;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206e018
	if (!ctx.cr6.eq) goto loc_8206E018;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206E018;
	sub_820A71E8(ctx, base);
loc_8206E018:
	// bl 0x820b5eb8
	ctx.lr = 0x8206E01C;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206E02C;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206e050
	if (ctx.cr6.eq) goto loc_8206E050;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82067020
	ctx.lr = 0x8206E048;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206e054
	goto loc_8206E054;
loc_8206E050:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206E054:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206E064;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206e084
	if (!ctx.cr6.eq) goto loc_8206E084;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206E084;
	sub_820A71E8(ctx, base);
loc_8206E084:
	// bl 0x820b5eb8
	ctx.lr = 0x8206E088;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206E098;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206e0bc
	if (ctx.cr6.eq) goto loc_8206E0BC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82067020
	ctx.lr = 0x8206E0B4;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206e0c0
	goto loc_8206E0C0;
loc_8206E0BC:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206E0C0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206E0D0;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206e0f0
	if (!ctx.cr6.eq) goto loc_8206E0F0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206E0F0;
	sub_820A71E8(ctx, base);
loc_8206E0F0:
	// bl 0x820b5eb8
	ctx.lr = 0x8206E0F4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206E104;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206e128
	if (ctx.cr6.eq) goto loc_8206E128;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82067020
	ctx.lr = 0x8206E120;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206e12c
	goto loc_8206E12C;
loc_8206E128:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206E12C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206E13C;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206e15c
	if (!ctx.cr6.eq) goto loc_8206E15C;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206E15C;
	sub_820A71E8(ctx, base);
loc_8206E15C:
	// bl 0x820b5eb8
	ctx.lr = 0x8206E160;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206E170;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206e194
	if (ctx.cr6.eq) goto loc_8206E194;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82067020
	ctx.lr = 0x8206E18C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206e198
	goto loc_8206E198;
loc_8206E194:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206E198:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206E1A8;
	sub_82065F78(ctx, base);
	// lbz r11,-22601(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206e1c8
	if (!ctx.cr6.eq) goto loc_8206E1C8;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206E1C8;
	sub_820A71E8(ctx, base);
loc_8206E1C8:
	// bl 0x820b5eb8
	ctx.lr = 0x8206E1CC;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r28
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206E1DC;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206e200
	if (ctx.cr6.eq) goto loc_8206E200;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82067020
	ctx.lr = 0x8206E1F8;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206e204
	goto loc_8206E204;
loc_8206E200:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206E204:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206E214;
	sub_82065F78(ctx, base);
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// stw r29,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r29.u32);
	// addi r10,r11,-7632
	ctx.r10.s64 = ctx.r11.s64 + -7632;
	// stw r10,384(r30)
	REX_STORE_U32(ctx.r30.u32 + 384, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
