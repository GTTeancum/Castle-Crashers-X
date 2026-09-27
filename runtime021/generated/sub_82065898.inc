DEFINE_REX_FUNC(sub_82065898) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820658A0;
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
	// bne cr6,0x82065960
	if (!ctx.cr6.eq) goto loc_82065960;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
loc_820658C4:
	// lwz r11,-6632(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6632);
	// rlwinm r31,r30,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r31,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x82078d90
	ctx.lr = 0x820658D4;
	sub_82078D90(ctx, base);
	// addi r11,r3,436
	ctx.r11.s64 = ctx.r3.s64 + 436;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820658ec
	if (!ctx.cr6.eq) goto loc_820658EC;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820658f0
	goto loc_820658F0;
loc_820658EC:
	// lbz r11,22(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
loc_820658F0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82065950
	if (!ctx.cr6.eq) goto loc_82065950;
	// lwz r11,-6632(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6632);
	// lwzx r3,r31,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x82078d90
	ctx.lr = 0x82065908;
	sub_82078D90(ctx, base);
	// addi r11,r3,220
	ctx.r11.s64 = ctx.r3.s64 + 220;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82065920
	if (!ctx.cr6.eq) goto loc_82065920;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82065924
	goto loc_82065924;
loc_82065920:
	// lbz r11,22(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
loc_82065924:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82065950
	if (!ctx.cr6.eq) goto loc_82065950;
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// blt cr6,0x820658c4
	if (ctx.cr6.lt) goto loc_820658C4;
loc_82065944:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82065950:
	// sth r28,10(r27)
	REX_STORE_U16(ctx.r27.u32 + 10, ctx.r28.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82065960:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82065944
	if (ctx.cr6.lt) goto loc_82065944;
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// rlwinm r31,r11,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-6632(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6632);
	// lwzx r3,r31,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x82078d90
	ctx.lr = 0x8206597C;
	sub_82078D90(ctx, base);
	// addi r11,r3,436
	ctx.r11.s64 = ctx.r3.s64 + 436;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82065994
	if (!ctx.cr6.eq) goto loc_82065994;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82065998
	goto loc_82065998;
loc_82065994:
	// lbz r11,22(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
loc_82065998:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820659d8
	if (!ctx.cr6.eq) goto loc_820659D8;
	// lwz r11,-6632(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6632);
	// lwzx r3,r31,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x82078d90
	ctx.lr = 0x820659B0;
	sub_82078D90(ctx, base);
	// addi r11,r3,220
	ctx.r11.s64 = ctx.r3.s64 + 220;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820659c8
	if (!ctx.cr6.eq) goto loc_820659C8;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820659cc
	goto loc_820659CC;
loc_820659C8:
	// lbz r11,22(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
loc_820659CC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82065944
	if (ctx.cr6.eq) goto loc_82065944;
loc_820659D8:
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
