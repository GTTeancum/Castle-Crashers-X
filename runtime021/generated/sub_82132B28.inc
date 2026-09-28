DEFINE_REX_FUNC(sub_82132B28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82132B30;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// sth r27,166(r1)
	REX_STORE_U16(ctx.r1.u32 + 166, ctx.r27.u16);
	// bl 0x8212bf08
	ctx.lr = 0x82132B44;
	sub_8212BF08(ctx, base);
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82132dec
	if (ctx.cr6.eq) goto loc_82132DEC;
	// bl 0x8212bf08
	ctx.lr = 0x82132B54;
	sub_8212BF08(ctx, base);
	// addi r11,r3,64
	ctx.r11.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82132dec
	if (ctx.cr6.eq) goto loc_82132DEC;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82132bd8
	if (!ctx.cr0.eq) goto loc_82132BD8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212e910
	ctx.lr = 0x82132B74;
	sub_8212E910(ctx, base);
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// addi r30,r11,2976
	ctx.r30.s64 = ctx.r11.s64 + 2976;
	// addi r28,r10,32392
	ctx.r28.s64 = ctx.r10.s64 + 32392;
	// beq cr6,0x82132bc4
	if (ctx.cr6.eq) goto loc_82132BC4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212e910
	ctx.lr = 0x82132B94;
	sub_8212E910(ctx, base);
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x82132bc4
	if (ctx.cr6.eq) goto loc_82132BC4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212e910
	ctx.lr = 0x82132BA4;
	sub_8212E910(ctx, base);
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8212e910
	ctx.lr = 0x82132BB4;
	sub_8212E910(ctx, base);
	// lwzx r10,r29,r30
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// rlwinm r11,r3,6,21,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x82132bc8
	goto loc_82132BC8;
loc_82132BC4:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_82132BC8:
	// lbz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 40);
	// rlwinm r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x82132c14
	if (!ctx.cr6.eq) goto loc_82132C14;
loc_82132BD8:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-2
	ctx.xer.ca = ctx.r11.u32 > 1;
	ctx.r11.s64 = ctx.r11.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// blt 0x82132c00
	if (ctx.cr0.lt) goto loc_82132C00;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// sth r27,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r27.u16);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x82132e00
	goto loc_82132E00;
loc_82132C00:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// clrlwi r3,r27,16
	ctx.r3.u64 = ctx.r27.u32 & 0xFFFF;
	// bl 0x82135188
	ctx.lr = 0x82132C0C;
	sub_82135188(ctx, base);
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// b 0x82132e04
	goto loc_82132E04;
loc_82132C14:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212e910
	ctx.lr = 0x82132C1C;
	sub_8212E910(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82132c5c
	if (ctx.cr6.eq) goto loc_82132C5C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212e910
	ctx.lr = 0x82132C2C;
	sub_8212E910(ctx, base);
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x82132c5c
	if (ctx.cr6.eq) goto loc_82132C5C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212e910
	ctx.lr = 0x82132C3C;
	sub_8212E910(ctx, base);
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8212e910
	ctx.lr = 0x82132C4C;
	sub_8212E910(ctx, base);
	// lwzx r10,r29,r30
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// rlwinm r11,r3,6,21,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x82132c60
	goto loc_82132C60;
loc_82132C5C:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_82132C60:
	// lbz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 40);
	// rlwinm r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82132d0c
	if (!ctx.cr6.eq) goto loc_82132D0C;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// blt 0x82132ca0
	if (ctx.cr0.lt) goto loc_82132CA0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r10,166(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 166);
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// b 0x82132cb0
	goto loc_82132CB0;
loc_82132CA0:
	// lbz r11,166(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 166);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// bl 0x8212c3f0
	ctx.lr = 0x82132CB0;
	sub_8212C3F0(ctx, base);
loc_82132CB0:
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82132cc0
	if (!ctx.cr6.eq) goto loc_82132CC0;
loc_82132CB8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82132e04
	goto loc_82132E04;
loc_82132CC0:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// blt 0x82132cf0
	if (ctx.cr0.lt) goto loc_82132CF0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r10,167(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 167);
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// b 0x82132d00
	goto loc_82132D00;
loc_82132CF0:
	// lbz r11,167(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 167);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// bl 0x8212c3f0
	ctx.lr = 0x82132D00;
	sub_8212C3F0(ctx, base);
loc_82132D00:
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82132e00
	if (!ctx.cr6.eq) goto loc_82132E00;
	// b 0x82132cb8
	goto loc_82132CB8;
loc_82132D0C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212e910
	ctx.lr = 0x82132D14;
	sub_8212E910(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82132d54
	if (ctx.cr6.eq) goto loc_82132D54;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212e910
	ctx.lr = 0x82132D24;
	sub_8212E910(ctx, base);
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x82132d54
	if (ctx.cr6.eq) goto loc_82132D54;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8212e910
	ctx.lr = 0x82132D34;
	sub_8212E910(ctx, base);
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8212e910
	ctx.lr = 0x82132D44;
	sub_8212E910(ctx, base);
	// lwzx r10,r29,r30
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// rlwinm r11,r3,6,21,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x82132d58
	goto loc_82132D58;
loc_82132D54:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_82132D58:
	// lbz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// rlwinm. r11,r11,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82132bd8
	if (ctx.cr0.eq) goto loc_82132BD8;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82132b00
	ctx.lr = 0x82132D78;
	sub_82132B00(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82132cb8
	if (!ctx.cr0.eq) goto loc_82132CB8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82132e00
	if (!ctx.cr6.gt) goto loc_82132E00;
loc_82132D90:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
	// lbzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// blt 0x82132dc4
	if (ctx.cr0.lt) goto loc_82132DC4;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stb r11,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// b 0x82132dd0
	goto loc_82132DD0;
loc_82132DC4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// bl 0x8212c3f0
	ctx.lr = 0x82132DD0;
	sub_8212C3F0(ctx, base);
loc_82132DD0:
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82132cb8
	if (ctx.cr6.eq) goto loc_82132CB8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82132d90
	if (ctx.cr6.lt) goto loc_82132D90;
	// b 0x82132e00
	goto loc_82132E00;
loc_82132DEC:
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r27,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r27.u16);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// sth r11,82(r1)
	REX_STORE_U16(ctx.r1.u32 + 82, ctx.r11.u16);
	// bl 0x821370c8
	ctx.lr = 0x82132E00;
	sub_821370C8(ctx, base);
loc_82132E00:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_82132E04:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
