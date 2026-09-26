DEFINE_REX_FUNC(sub_82050468) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82050470;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r11,r4,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x2;
	// li r30,0
	ctx.r30.s64 = 0;
	// clrlwi r29,r4,16
	ctx.r29.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// beq cr6,0x820505a4
	if (ctx.cr6.eq) goto loc_820505A4;
	// li r5,59
	ctx.r5.s64 = 59;
	// bl 0x8209d3d8
	ctx.lr = 0x820504A0;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x820504AC;
	sub_8209D488(ctx, base);
	// li r5,59
	ctx.r5.s64 = 59;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x820504B8;
	sub_8209D3D8(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// ori r5,r10,16
	ctx.r5.u64 = ctx.r10.u64 | 16;
	// bl 0x8209d538
	ctx.lr = 0x820504C8;
	sub_8209D538(ctx, base);
	// li r5,63
	ctx.r5.s64 = 63;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// bl 0x8209d3d8
	ctx.lr = 0x820504D8;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x820504E4;
	sub_8209D488(ctx, base);
	// li r5,63
	ctx.r5.s64 = 63;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x820504F0;
	sub_8209D3D8(ctx, base);
	// lbz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// ori r5,r8,64
	ctx.r5.u64 = ctx.r8.u64 | 64;
	// bl 0x8209d538
	ctx.lr = 0x82050500;
	sub_8209D538(ctx, base);
	// li r5,67
	ctx.r5.s64 = 67;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// bl 0x8209d3d8
	ctx.lr = 0x82050510;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x8205051C;
	sub_8209D488(ctx, base);
	// lbz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r5,67
	ctx.r5.s64 = 67;
	// ori r7,r6,10
	ctx.r7.u64 = ctx.r6.u64 | 10;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stb r7,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r7.u8);
	// bl 0x8209d3d8
	ctx.lr = 0x82050534;
	sub_8209D3D8(ctx, base);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x82050540;
	sub_8209D538(ctx, base);
	// li r5,52
	ctx.r5.s64 = 52;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x8205054C;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x82050558;
	sub_8209D488(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r5,52
	ctx.r5.s64 = 52;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// ori r7,r10,4
	ctx.r7.u64 = ctx.r10.u64 | 4;
	// bl 0x8209d3d8
	ctx.lr = 0x8205056C;
	sub_8209D3D8(ctx, base);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x82050578;
	sub_8209D538(ctx, base);
	// li r5,360
	ctx.r5.s64 = 360;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x82050584;
	sub_8209D3D8(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x82050590;
	sub_8209D538(ctx, base);
	// li r5,624
	ctx.r5.s64 = 624;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x8205059C;
	sub_8209D3D8(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// b 0x82050648
	goto loc_82050648;
loc_820505A4:
	// li r5,67
	ctx.r5.s64 = 67;
	// bl 0x8209d3d8
	ctx.lr = 0x820505AC;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x820505BC;
	sub_8209D488(ctx, base);
	// lbz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r12,245
	ctx.r12.s64 = 245;
	// li r5,67
	ctx.r5.s64 = 67;
	// and r7,r11,r12
	ctx.r7.u64 = ctx.r11.u64 & ctx.r12.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stb r7,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r7.u8);
	// bl 0x8209d3d8
	ctx.lr = 0x820505D8;
	sub_8209D3D8(ctx, base);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x820505E4;
	sub_8209D538(ctx, base);
	// li r5,52
	ctx.r5.s64 = 52;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x820505F0;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x820505FC;
	sub_8209D488(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r5,52
	ctx.r5.s64 = 52;
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// rlwinm r7,r7,0,30,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// bl 0x8209d3d8
	ctx.lr = 0x82050614;
	sub_8209D3D8(ctx, base);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x82050620;
	sub_8209D538(ctx, base);
	// li r5,360
	ctx.r5.s64 = 360;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x8205062C;
	sub_8209D3D8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x82050638;
	sub_8209D538(ctx, base);
	// li r5,624
	ctx.r5.s64 = 624;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x82050644;
	sub_8209D3D8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
loc_82050648:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x82050654;
	sub_8209D538(ctx, base);
	// rlwinm r11,r29,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x4;
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82050748
	if (ctx.cr6.eq) goto loc_82050748;
	// li r5,66
	ctx.r5.s64 = 66;
	// bl 0x8209d3d8
	ctx.lr = 0x82050670;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x8205067C;
	sub_8209D488(ctx, base);
	// li r5,66
	ctx.r5.s64 = 66;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x82050688;
	sub_8209D3D8(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// ori r5,r10,8
	ctx.r5.u64 = ctx.r10.u64 | 8;
	// bl 0x8209d538
	ctx.lr = 0x82050698;
	sub_8209D538(ctx, base);
	// li r5,67
	ctx.r5.s64 = 67;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// bl 0x8209d3d8
	ctx.lr = 0x820506A8;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x820506B4;
	sub_8209D488(ctx, base);
	// lbz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r5,67
	ctx.r5.s64 = 67;
	// ori r7,r8,84
	ctx.r7.u64 = ctx.r8.u64 | 84;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stb r7,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r7.u8);
	// bl 0x8209d3d8
	ctx.lr = 0x820506CC;
	sub_8209D3D8(ctx, base);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x820506D8;
	sub_8209D538(ctx, base);
	// li r5,52
	ctx.r5.s64 = 52;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x820506E4;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x820506F0;
	sub_8209D488(ctx, base);
	// lbz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r5,52
	ctx.r5.s64 = 52;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// ori r7,r6,8
	ctx.r7.u64 = ctx.r6.u64 | 8;
	// bl 0x8209d3d8
	ctx.lr = 0x82050704;
	sub_8209D3D8(ctx, base);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x82050710;
	sub_8209D538(ctx, base);
	// li r5,552
	ctx.r5.s64 = 552;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x8205071C;
	sub_8209D3D8(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x82050728;
	sub_8209D538(ctx, base);
	// li r5,744
	ctx.r5.s64 = 744;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x82050734;
	sub_8209D3D8(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x82050740;
	sub_8209D538(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82050748:
	// li r5,67
	ctx.r5.s64 = 67;
	// bl 0x8209d3d8
	ctx.lr = 0x82050750;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x82050760;
	sub_8209D488(ctx, base);
	// lbz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r12,235
	ctx.r12.s64 = 235;
	// li r5,67
	ctx.r5.s64 = 67;
	// and r7,r11,r12
	ctx.r7.u64 = ctx.r11.u64 & ctx.r12.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stb r7,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r7.u8);
	// bl 0x8209d3d8
	ctx.lr = 0x8205077C;
	sub_8209D3D8(ctx, base);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x82050788;
	sub_8209D538(ctx, base);
	// li r5,52
	ctx.r5.s64 = 52;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x82050794;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d488
	ctx.lr = 0x820507A0;
	sub_8209D488(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r5,52
	ctx.r5.s64 = 52;
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// rlwinm r7,r7,0,29,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// bl 0x8209d3d8
	ctx.lr = 0x820507B8;
	sub_8209D3D8(ctx, base);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x820507C4;
	sub_8209D538(ctx, base);
	// li r5,552
	ctx.r5.s64 = 552;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x820507D0;
	sub_8209D3D8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x820507DC;
	sub_8209D538(ctx, base);
	// li r5,744
	ctx.r5.s64 = 744;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d3d8
	ctx.lr = 0x820507E8;
	sub_8209D3D8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8209d538
	ctx.lr = 0x820507F4;
	sub_8209D538(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
