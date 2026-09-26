DEFINE_REX_FUNC(sub_82050000) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82050008;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d3d8
	ctx.lr = 0x82050020;
	sub_8209D3D8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x8205002C;
	sub_8209D538(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d3d8
	ctx.lr = 0x82050034;
	sub_8209D3D8(ctx, base);
	// li r5,9
	ctx.r5.s64 = 9;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x82050040;
	sub_8209D538(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d3d8
	ctx.lr = 0x8205004C;
	sub_8209D3D8(ctx, base);
	// li r5,9
	ctx.r5.s64 = 9;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x82050058;
	sub_8209D538(ctx, base);
	// li r5,73
	ctx.r5.s64 = 73;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d3d8
	ctx.lr = 0x82050064;
	sub_8209D3D8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x82050070;
	sub_8209D538(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r10,872
	ctx.r29.s64 = ctx.r10.s64 + 872;
	// addi r28,r11,840
	ctx.r28.s64 = ctx.r11.s64 + 840;
loc_82050088:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82050170
	ctx.lr = 0x82050090;
	sub_82050170(ctx, base);
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lbz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820500b8
	if (!ctx.cr6.eq) goto loc_820500B8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x820500B4;
	sub_8208C5D8(ctx, base);
	// b 0x820500d4
	goto loc_820500D4;
loc_820500B8:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820500d0
	if (ctx.cr6.lt) goto loc_820500D0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x820500CC;
	sub_8208C5D8(ctx, base);
	// b 0x820500d4
	goto loc_820500D4;
loc_820500D0:
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_820500D4:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x820500E4;
	sub_8209D538(ctx, base);
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,28
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 28, ctx.xer);
	// blt cr6,0x82050088
	if (ctx.cr6.lt) goto loc_82050088;
	// li r6,0
	ctx.r6.s64 = 0;
loc_820500FC:
	// addi r11,r6,4
	ctx.r11.s64 = ctx.r6.s64 + 4;
	// lbz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// bne cr6,0x82050124
	if (!ctx.cr6.eq) goto loc_82050124;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x82050120;
	sub_8208C5D8(ctx, base);
	// b 0x82050140
	goto loc_82050140;
loc_82050124:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8205013c
	if (ctx.cr6.lt) goto loc_8205013C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x82050138;
	sub_8208C5D8(ctx, base);
	// b 0x82050140
	goto loc_82050140;
loc_8205013C:
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82050140:
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x82050150;
	sub_8209D538(ctx, base);
	// addi r11,r6,1
	ctx.r11.s64 = ctx.r6.s64 + 1;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820500fc
	if (ctx.cr6.lt) goto loc_820500FC;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
