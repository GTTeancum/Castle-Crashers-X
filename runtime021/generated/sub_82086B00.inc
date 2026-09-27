DEFINE_REX_FUNC(sub_82086B00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82086B08;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r10,r11,-6024
	ctx.r10.s64 = ctx.r11.s64 + -6024;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82086ba8
	ctx.lr = 0x82086B20;
	sub_82086BA8(ctx, base);
	// addi r3,r31,160
	ctx.r3.s64 = ctx.r31.s64 + 160;
	// bl 0x8207a7e0
	ctx.lr = 0x82086B28;
	sub_8207A7E0(ctx, base);
	// addi r30,r31,108
	ctx.r30.s64 = ctx.r31.s64 + 108;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r29,112(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82086b84
	if (ctx.cr6.eq) goto loc_82086B84;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82086b64
	if (!ctx.cr6.eq) goto loc_82086B64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r3,r11,-1768
	ctx.r3.s64 = ctx.r11.s64 + -1768;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82086B64;
	sub_820A71E8(ctx, base);
loc_82086B64:
	// bl 0x820b5eb8
	ctx.lr = 0x82086B68;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bf18
	ctx.lr = 0x82086B80;
	sub_8209BF18(ctx, base);
	// stw r28,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r28.u32);
loc_82086B84:
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// addi r3,r31,104
	ctx.r3.s64 = ctx.r31.s64 + 104;
	// stw r28,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r28.u32);
	// bl 0x82084be8
	ctx.lr = 0x82086B94;
	sub_82084BE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820861e0
	ctx.lr = 0x82086B9C;
	sub_820861E0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
