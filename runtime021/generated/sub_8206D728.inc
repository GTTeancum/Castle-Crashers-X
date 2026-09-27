DEFINE_REX_FUNC(sub_8206D728) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8206D730;
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
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r28,r11,-1768
	ctx.r28.s64 = ctx.r11.s64 + -1768;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lbz r11,-22601(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206d76c
	if (!ctx.cr6.eq) goto loc_8206D76C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206D76C;
	sub_820A71E8(ctx, base);
loc_8206D76C:
	// bl 0x820b5eb8
	ctx.lr = 0x8206D770;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r11,29632
	ctx.r29.s64 = ctx.r11.s64 + 29632;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r10,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206D788;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206d7a0
	if (ctx.cr6.eq) goto loc_8206D7A0;
	// li r4,582
	ctx.r4.s64 = 582;
	// bl 0x82067778
	ctx.lr = 0x8206D798;
	sub_82067778(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206d7a4
	goto loc_8206D7A4;
loc_8206D7A0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206D7A4:
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
	ctx.lr = 0x8206D7BC;
	sub_82065F78(ctx, base);
	// lbz r10,-22601(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206d7dc
	if (!ctx.cr6.eq) goto loc_8206D7DC;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8206D7DC;
	sub_820A71E8(ctx, base);
loc_8206D7DC:
	// bl 0x820b5eb8
	ctx.lr = 0x8206D7E0;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8206D7F0;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206d814
	if (ctx.cr6.eq) goto loc_8206D814;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,474
	ctx.r6.s64 = 474;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82067020
	ctx.lr = 0x8206D80C;
	sub_82067020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8206d818
	goto loc_8206D818;
loc_8206D814:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206D818:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82065f78
	ctx.lr = 0x8206D828;
	sub_82065F78(ctx, base);
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r10,255
	ctx.r10.s64 = 255;
	// stw r27,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r27.u32);
	// addi r9,r11,-9856
	ctx.r9.s64 = ctx.r11.s64 + -9856;
	// sth r10,16(r30)
	REX_STORE_U16(ctx.r30.u32 + 16, ctx.r10.u16);
	// stw r9,384(r30)
	REX_STORE_U32(ctx.r30.u32 + 384, ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
