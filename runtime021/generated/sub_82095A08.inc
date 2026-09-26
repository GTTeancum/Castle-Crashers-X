DEFINE_REX_FUNC(sub_82095A08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82095A10;
	__savegprlr_27(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r11,65535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65535, ctx.xer);
	// bne cr6,0x82095a38
	if (!ctx.cr6.eq) goto loc_82095A38;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x82095a64
	goto loc_82095A64;
loc_82095A38:
	// rlwinm r10,r31,2,14,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r9,r31,16
	ctx.r9.u64 = ctx.r31.u32 & 0xFFFF;
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r8,-22008
	ctx.r10.s64 = ctx.r8.s64 + -22008;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r10,8
	ctx.r5.s64 = ctx.r10.s64 + 8;
	// mulli r11,r11,140
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(140));
	// lwzx r10,r6,r5
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r30,8(r4)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
loc_82095A64:
	// clrlwi r11,r31,16
	ctx.r11.u64 = ctx.r31.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82095b04
	if (!ctx.cr6.eq) goto loc_82095B04;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
loc_82095A74:
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209b258
	ctx.lr = 0x82095A84;
	sub_8209B258(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82095acc
	if (ctx.cr6.eq) goto loc_82095ACC;
loc_82095A90:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,112(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x82095840
	ctx.lr = 0x82095A9C;
	sub_82095840(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82095b58
	if (!ctx.cr6.eq) goto loc_82095B58;
	// cmplwi cr6,r28,3
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 3, ctx.xer);
	// beq cr6,0x82095b34
	if (ctx.cr6.eq) goto loc_82095B34;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// bl 0x8209b258
	ctx.lr = 0x82095AC0;
	sub_8209B258(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82095a90
	if (!ctx.cr6.eq) goto loc_82095A90;
loc_82095ACC:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x8209bf18
	ctx.lr = 0x82095AD8;
	sub_8209BF18(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8209b1e0
	ctx.lr = 0x82095AE8;
	sub_8209B1E0(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// addi r3,r11,-1800
	ctx.r3.s64 = ctx.r11.s64 + -1800;
	// bl 0x8208c5d8
	ctx.lr = 0x82095AF8;
	sub_8208C5D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82095B04:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8209bdd8
	ctx.lr = 0x82095B10;
	sub_8209BDD8(ctx, base);
	// stw r3,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82095a74
	if (!ctx.cr6.eq) goto loc_82095A74;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-1848
	ctx.r3.s64 = ctx.r11.s64 + -1848;
	// bl 0x8208c5d8
	ctx.lr = 0x82095B28;
	sub_8208C5D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82095B34:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8209b1e0
	ctx.lr = 0x82095B44;
	sub_8209B1E0(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// addi r3,r11,-1760
	ctx.r3.s64 = ctx.r11.s64 + -1760;
	// bl 0x8208c5d8
	ctx.lr = 0x82095B54;
	sub_8208C5D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82095B58:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
