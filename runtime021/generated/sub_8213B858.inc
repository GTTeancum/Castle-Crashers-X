DEFINE_REX_FUNC(sub_8213B858) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x8213B860;
	__savegprlr_26(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// ori r26,r11,16385
	ctx.r26.u64 = ctx.r11.u64 | 16385;
	// lwz r10,36(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8213b990
	if (ctx.cr6.eq) goto loc_8213B990;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82136c88
	ctx.lr = 0x8213B890;
	sub_82136C88(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r5,8
	ctx.r5.s64 = 8;
	// stb r31,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r31.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r31,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r31.u8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,9540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x82136c88
	ctx.lr = 0x8213B8B8;
	sub_82136C88(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stb r30,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82136c88
	ctx.lr = 0x8213B8D8;
	sub_82136C88(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stw r27,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82136c88
	ctx.lr = 0x8213B8F4;
	sub_82136C88(ctx, base);
	// lwz r3,60(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// addi r11,r1,104
	ctx.r11.s64 = ctx.r1.s64 + 104;
	// stb r30,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r30.u8);
	// addi r28,r29,60
	ctx.r28.s64 = ctx.r29.s64 + 60;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8213b924
	if (ctx.cr6.eq) goto loc_8213B924;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8213b98c
	if (ctx.cr6.eq) goto loc_8213B98C;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x820d8160
	ctx.lr = 0x8213B920;
	sub_820D8160(ctx, base);
	// b 0x8213b988
	goto loc_8213B988;
loc_8213B924:
	// li r5,92
	ctx.r5.s64 = 92;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82136c88
	ctx.lr = 0x8213B934;
	sub_82136C88(ctx, base);
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// li r10,16000
	ctx.r10.s64 = 16000;
	// stw r29,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r29.u32);
	// addi r11,r11,-20312
	ctx.r11.s64 = ctx.r11.s64 + -20312;
	// stb r30,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r30.u8);
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// stb r30,116(r1)
	REX_STORE_U8(ctx.r1.u32 + 116, ctx.r30.u8);
	// stw r11,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r11.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stb r30,169(r1)
	REX_STORE_U8(ctx.r1.u32 + 169, ctx.r30.u8);
	// stb r30,170(r1)
	REX_STORE_U8(ctx.r1.u32 + 170, ctx.r30.u8);
	// stb r31,176(r1)
	REX_STORE_U8(ctx.r1.u32 + 176, ctx.r31.u8);
	// stw r31,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r31.u32);
	// stw r9,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
	// stw r31,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r31.u32);
	// stw r31,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r31.u32);
	// lwz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// stb r11,171(r1)
	REX_STORE_U8(ctx.r1.u32 + 171, ctx.r11.u8);
	// bl 0x820d8588
	ctx.lr = 0x8213B988;
	sub_820D8588(ctx, base);
loc_8213B988:
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
loc_8213B98C:
	// stw r30,64(r29)
	REX_STORE_U32(ctx.r29.u32 + 64, ctx.r30.u32);
loc_8213B990:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
