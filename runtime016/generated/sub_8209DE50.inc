DEFINE_REX_FUNC(sub_8209DE50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8209DE58;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lbz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209df3c
	if (ctx.cr6.eq) goto loc_8209DF3C;
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
	// lwz r31,-6612(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + -6612);
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// bne cr6,0x8209de98
	if (!ctx.cr6.eq) goto loc_8209DE98;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-1368
	ctx.r3.s64 = ctx.r11.s64 + -1368;
	// bl 0x8208c5d8
	ctx.lr = 0x8209DE94;
	sub_8208C5D8(ctx, base);
	// b 0x8209dec0
	goto loc_8209DEC0;
loc_8209DE98:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r30,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// addi r3,r31,76
	ctx.r3.s64 = ctx.r31.s64 + 76;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r30.u32);
	// bl 0x82097720
	ctx.lr = 0x8209DEBC;
	sub_82097720(ctx, base);
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
loc_8209DEC0:
	// lwz r3,96(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 96);
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,10316(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10316);
	// stw r11,26332(r31)
	REX_STORE_U32(ctx.r31.u32 + 26332, ctx.r11.u32);
	// bl 0x820915f0
	ctx.lr = 0x8209DED8;
	sub_820915F0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8209cc98
	ctx.lr = 0x8209DEE4;
	sub_8209CC98(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,26332(r31)
	REX_STORE_U32(ctx.r31.u32 + 26332, ctx.r11.u32);
	// lwz r31,-6612(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + -6612);
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209df14
	if (!ctx.cr6.eq) goto loc_8209DF14;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-1308
	ctx.r3.s64 = ctx.r11.s64 + -1308;
	// bl 0x8208c5d8
	ctx.lr = 0x8209DF08;
	sub_8208C5D8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8209DF14:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// addi r3,r31,76
	ctx.r3.s64 = ctx.r31.s64 + 76;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// stw r8,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// bl 0x82097720
	ctx.lr = 0x8209DF38;
	sub_82097720(ctx, base);
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
loc_8209DF3C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
