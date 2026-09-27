DEFINE_REX_FUNC(sub_82065DF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82065DF8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// extsh r11,r31
	ctx.r11.s64 = ctx.r31.s16;
	// cmpwi cr6,r11,-2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -2, ctx.xer);
	// bne cr6,0x82065e84
	if (!ctx.cr6.eq) goto loc_82065E84;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
loc_82065E1C:
	// lwz r11,-6632(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6632);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// bl 0x82078d90
	ctx.lr = 0x82065E2C;
	sub_82078D90(ctx, base);
	// addi r11,r3,616
	ctx.r11.s64 = ctx.r3.s64 + 616;
	// lbz r9,18(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82065e44
	if (!ctx.cr6.eq) goto loc_82065E44;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82065e48
	goto loc_82065E48;
loc_82065E44:
	// lbz r11,19(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 19);
loc_82065E48:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82065e74
	if (!ctx.cr6.eq) goto loc_82065E74;
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// extsh r29,r11
	ctx.r29.s64 = ctx.r11.s16;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmpwi cr6,r31,4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4, ctx.xer);
	// blt cr6,0x82065e1c
	if (ctx.cr6.lt) goto loc_82065E1C;
loc_82065E68:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82065E74:
	// sth r29,10(r28)
	REX_STORE_U16(ctx.r28.u32 + 10, ctx.r29.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82065E84:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82065e68
	if (ctx.cr6.lt) goto loc_82065E68;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-6632(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6632);
	// lwzx r3,r9,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// bl 0x82078d90
	ctx.lr = 0x82065EA0;
	sub_82078D90(ctx, base);
	// addi r11,r3,616
	ctx.r11.s64 = ctx.r3.s64 + 616;
	// lbz r8,18(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82065eb8
	if (!ctx.cr6.eq) goto loc_82065EB8;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82065ebc
	goto loc_82065EBC;
loc_82065EB8:
	// lbz r11,19(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 19);
loc_82065EBC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82065e68
	if (ctx.cr6.eq) goto loc_82065E68;
	// sth r31,10(r28)
	REX_STORE_U16(ctx.r28.u32 + 10, ctx.r31.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
