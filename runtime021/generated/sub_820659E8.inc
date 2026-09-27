DEFINE_REX_FUNC(sub_820659E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820659F0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// extsh r11,r29
	ctx.r11.s64 = ctx.r29.s16;
	// cmpwi cr6,r11,-2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -2, ctx.xer);
	// bne cr6,0x82065ab0
	if (!ctx.cr6.eq) goto loc_82065AB0;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
loc_82065A14:
	// lwz r11,-6632(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6632);
	// rlwinm r31,r30,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r31,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x82078d90
	ctx.lr = 0x82065A24;
	sub_82078D90(ctx, base);
	// addi r11,r3,472
	ctx.r11.s64 = ctx.r3.s64 + 472;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82065a3c
	if (!ctx.cr6.eq) goto loc_82065A3C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82065a40
	goto loc_82065A40;
loc_82065A3C:
	// lbz r11,22(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
loc_82065A40:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82065aa0
	if (!ctx.cr6.eq) goto loc_82065AA0;
	// lwz r11,-6632(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6632);
	// lwzx r3,r31,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x82078d90
	ctx.lr = 0x82065A58;
	sub_82078D90(ctx, base);
	// addi r11,r3,256
	ctx.r11.s64 = ctx.r3.s64 + 256;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82065a70
	if (!ctx.cr6.eq) goto loc_82065A70;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82065a74
	goto loc_82065A74;
loc_82065A70:
	// lbz r11,22(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
loc_82065A74:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82065aa0
	if (!ctx.cr6.eq) goto loc_82065AA0;
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// blt cr6,0x82065a14
	if (ctx.cr6.lt) goto loc_82065A14;
loc_82065A94:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82065AA0:
	// sth r28,10(r27)
	REX_STORE_U16(ctx.r27.u32 + 10, ctx.r28.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82065AB0:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82065a94
	if (ctx.cr6.lt) goto loc_82065A94;
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// rlwinm r31,r11,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-6632(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6632);
	// lwzx r3,r31,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x82078d90
	ctx.lr = 0x82065ACC;
	sub_82078D90(ctx, base);
	// addi r11,r3,472
	ctx.r11.s64 = ctx.r3.s64 + 472;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82065ae4
	if (!ctx.cr6.eq) goto loc_82065AE4;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82065ae8
	goto loc_82065AE8;
loc_82065AE4:
	// lbz r11,22(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
loc_82065AE8:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82065b28
	if (!ctx.cr6.eq) goto loc_82065B28;
	// lwz r11,-6632(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6632);
	// lwzx r3,r31,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x82078d90
	ctx.lr = 0x82065B00;
	sub_82078D90(ctx, base);
	// addi r11,r3,256
	ctx.r11.s64 = ctx.r3.s64 + 256;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82065b18
	if (!ctx.cr6.eq) goto loc_82065B18;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82065b1c
	goto loc_82065B1C;
loc_82065B18:
	// lbz r11,22(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
loc_82065B1C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82065a94
	if (ctx.cr6.eq) goto loc_82065A94;
loc_82065B28:
	// sth r29,10(r27)
	REX_STORE_U16(ctx.r27.u32 + 10, ctx.r29.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
