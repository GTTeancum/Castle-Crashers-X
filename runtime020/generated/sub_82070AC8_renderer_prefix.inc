DEFINE_REX_FUNC(sub_82070AC8_renderer_prefix) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x82070AD0;
	__savegprlr_24(ctx, base);
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x820701d0
	ctx.lr = 0x82070AE0;
	sub_820701D0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r3,r11,26304
	ctx.r3.s64 = ctx.r11.s64 + 26304;
	// bl 0x8214a424
	ctx.lr = 0x82070AEC;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r9,-32234
	ctx.r9.s64 = -2112487424;
	// lis r8,-32234
	ctx.r8.s64 = -2112487424;
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r11,r11,29584
	ctx.r11.s64 = ctx.r11.s64 + 29584;
	// addi r10,r10,29696
	ctx.r10.s64 = ctx.r10.s64 + 29696;
	// stw r11,-28292(r9)
	REX_STORE_U32(ctx.r9.u32 + -28292, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,-28288(r8)
	REX_STORE_U32(ctx.r8.u32 + -28288, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8209a728
	ctx.lr = 0x82070B18;
	sub_8209A728(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// li r27,1
	ctx.r27.s64 = 1;
	// lwz r3,-6652(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + -6652);
	// stb r27,4(r3)
	REX_STORE_U8(ctx.r3.u32 + 4, ctx.r27.u8);
	// bl 0x8209b458
	ctx.lr = 0x82070B2C;
	sub_8209B458(ctx, base);
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r26,r11,-1768
	ctx.r26.s64 = ctx.r11.s64 + -1768;
	// lbz r6,-22601(r29)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r29.u32 + -22601);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x82070b58
	if (!ctx.cr6.eq) goto loc_82070B58;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82070B58;
	sub_820A71E8(ctx, base);
loc_82070B58:
	// bl 0x820b5eb8
	ctx.lr = 0x82070B5C;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r25,r11,29632
	ctx.r25.s64 = ctx.r11.s64 + 29632;
	// li r4,30216
	ctx.r4.s64 = 30216;
	// lwzx r3,r10,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82070B74;
	sub_8209BDD8(ctx, base);
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82070b8c
	if (ctx.cr6.eq) goto loc_82070B8C;
	// bl 0x820a7668
	ctx.lr = 0x82070B84;
	sub_820A7668(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82070b90
	goto loc_82070B90;
loc_82070B8C:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_82070B90:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r31,r11,-6616
	ctx.r31.s64 = ctx.r11.s64 + -6616;
	// stw r4,-6616(r11)
	REX_STORE_U32(ctx.r11.u32 + -6616, ctx.r4.u32);
	// Checkpoint 019 diagnostic stop: next original instruction is bl 0x820A7990.
	(void)temp;
	return;
}
