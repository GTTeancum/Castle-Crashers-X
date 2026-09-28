DEFINE_REX_FUNC(sub_820A59E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820A59F0;
	__savegprlr_26(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,844
	ctx.r8.s64 = ctx.r11.s64 + 844;
	// rlwinm r7,r4,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r5,6396
	ctx.r3.s64 = ctx.r5.s64 + 6396;
	// lwzx r5,r10,r8
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// lwzx r4,r7,r8
	ctx.r4.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// bl 0x8208c5d8
	ctx.lr = 0x820A5A24;
	sub_8208C5D8(ctx, base);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x820a5a90
	if (!ctx.cr6.eq) goto loc_820A5A90;
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820a5a68
	if (ctx.cr6.eq) goto loc_820A5A68;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r3,-6652(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6652);
	// bl 0x8209b730
	ctx.lr = 0x820A5A44;
	sub_8209B730(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
loc_820A5A4C:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r4,-6596(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + -6596);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x820a0540
	ctx.lr = 0x820A5A5C;
	sub_820A0540(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// blt cr6,0x820a5a4c
	if (ctx.cr6.lt) goto loc_820A5A4C;
loc_820A5A68:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820a49e0
	ctx.lr = 0x820A5A70;
	sub_820A49E0(ctx, base);
	// lis r11,-32747
	ctx.r11.s64 = -2146107392;
	// ori r10,r11,20994
	ctx.r10.u64 = ctx.r11.u64 | 20994;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x820a5d78
	if (!ctx.cr6.eq) goto loc_820A5D78;
loc_820A5A80:
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A5A90:
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// bne cr6,0x820a5b18
	if (!ctx.cr6.eq) goto loc_820A5B18;
	// lbz r11,1185(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a5d78
	if (!ctx.cr6.eq) goto loc_820A5D78;
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A5AB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820a5d78
	if (!ctx.cr6.eq) goto loc_820A5D78;
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a5d78
	if (ctx.cr6.eq) goto loc_820A5D78;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A5ADC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820a5d78
	if (!ctx.cr6.eq) goto loc_820A5D78;
	// lwz r3,24(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820a5af4
	if (ctx.cr6.eq) goto loc_820A5AF4;
	// bl 0x820a7400
	ctx.lr = 0x820A5AF4;
	sub_820A7400(ctx, base);
loc_820A5AF4:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x820a7390
	ctx.lr = 0x820A5AFC;
	sub_820A7390(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stw r11,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// bl 0x82051fa8
	ctx.lr = 0x820A5B10;
	sub_82051FA8(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A5B18:
	// cmpwi cr6,r9,6
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 6, ctx.xer);
	// bne cr6,0x820a5b30
	if (!ctx.cr6.eq) goto loc_820A5B30;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,1184(r30)
	REX_STORE_U8(ctx.r30.u32 + 1184, ctx.r11.u8);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A5B30:
	// cmpwi cr6,r9,7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 7, ctx.xer);
	// beq cr6,0x820a5b40
	if (ctx.cr6.eq) goto loc_820A5B40;
	// cmpwi cr6,r9,8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 8, ctx.xer);
	// bne cr6,0x820a5d78
	if (!ctx.cr6.eq) goto loc_820A5D78;
loc_820A5B40:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r31,r11,9424
	ctx.r31.s64 = ctx.r11.s64 + 9424;
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// li r27,208
	ctx.r27.s64 = 208;
	// stb r10,1184(r30)
	REX_STORE_U8(ctx.r30.u32 + 1184, ctx.r10.u8);
	// li r26,2
	ctx.r26.s64 = 2;
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820a5bc8
	if (!ctx.cr6.eq) goto loc_820A5BC8;
	// cmpwi cr6,r9,7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 7, ctx.xer);
	// bne cr6,0x820a5bc8
	if (!ctx.cr6.eq) goto loc_820A5BC8;
	// sth r27,112(r1)
	REX_STORE_U16(ctx.r1.u32 + 112, ctx.r27.u16);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,-6624(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x820A5B84;
	sub_82052EA8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820a5c00
	if (!ctx.cr6.eq) goto loc_820A5C00;
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A5BA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820a5bb8
	if (!ctx.cr6.eq) goto loc_820A5BB8;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x820a5bb8
	if (!ctx.cr6.eq) goto loc_820A5BB8;
	// stw r26,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r26.u32);
loc_820A5BB8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x820a37b8
	ctx.lr = 0x820A5BC4;
	sub_820A37B8(ctx, base);
	// b 0x820a5c00
	goto loc_820A5C00;
loc_820A5BC8:
	// cmpwi cr6,r9,8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 8, ctx.xer);
	// bne cr6,0x820a5c00
	if (!ctx.cr6.eq) goto loc_820A5C00;
	// lbz r9,1185(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 1185);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820a5c00
	if (ctx.cr6.eq) goto loc_820A5C00;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820a5c00
	if (ctx.cr6.eq) goto loc_820A5C00;
	// stb r10,1185(r30)
	REX_STORE_U8(ctx.r30.u32 + 1185, ctx.r10.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82053a00
	ctx.lr = 0x820A5BF4;
	sub_82053A00(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-6624(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -6624);
	// bl 0x82077a98
	ctx.lr = 0x820A5C00;
	sub_82077A98(ctx, base);
loc_820A5C00:
	// lwz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820a5c44
	if (!ctx.cr6.eq) goto loc_820A5C44;
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r10,r11,1245
	ctx.r10.u64 = ctx.r11.u64 | 1245;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x820a5d78
	if (!ctx.cr6.eq) goto loc_820A5D78;
	// li r11,6
	ctx.r11.s64 = 6;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r11,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82053a00
	ctx.lr = 0x820A5C30;
	sub_82053A00(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-6624(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -6624);
	// bl 0x82077a98
	ctx.lr = 0x820A5C3C;
	sub_82077A98(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A5C44:
	// lis r11,-32747
	ctx.r11.s64 = -2146107392;
	// ori r11,r11,20994
	ctx.r11.u64 = ctx.r11.u64 | 20994;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x820a5d34
	if (ctx.cr6.gt) goto loc_820A5D34;
	// beq cr6,0x820a5a80
	if (ctx.cr6.eq) goto loc_820A5A80;
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r11,r11,1245
	ctx.r11.u64 = ctx.r11.u64 | 1245;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x820a5cf4
	if (ctx.cr6.gt) goto loc_820A5CF4;
	// beq cr6,0x820a5ce4
	if (ctx.cr6.eq) goto loc_820A5CE4;
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r9,r11,1226
	ctx.r9.u64 = ctx.r11.u64 | 1226;
	// subf. r11,r9,r28
	ctx.r11.u64 = ctx.r28.u64 - ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820a5c94
	if (ctx.cr0.eq) goto loc_820A5C94;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bne cr6,0x820a5d78
	if (!ctx.cr6.eq) goto loc_820A5D78;
loc_820A5C84:
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r11,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A5C94:
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x820a5cbc
	if (!ctx.cr6.eq) goto loc_820A5CBC;
	// sth r27,112(r1)
	REX_STORE_U16(ctx.r1.u32 + 112, ctx.r27.u16);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,-6624(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x820A5CB0;
	sub_82052EA8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820a5d78
	if (!ctx.cr6.eq) goto loc_820A5D78;
loc_820A5CBC:
	// lbz r11,1185(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a5cd8
	if (ctx.cr6.eq) goto loc_820A5CD8;
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A5CD8:
	// stw r26,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r26.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A5CE4:
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A5CF4:
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r10,r11,1617
	ctx.r10.u64 = ctx.r11.u64 | 1617;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x820a5d24
	if (ctx.cr6.eq) goto loc_820A5D24;
	// lis r11,-32747
	ctx.r11.s64 = -2146107392;
	// ori r10,r11,20993
	ctx.r10.u64 = ctx.r11.u64 | 20993;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x820a5d78
	if (!ctx.cr6.eq) goto loc_820A5D78;
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r11,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A5D24:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A5D34:
	// cmpwi cr6,r28,1229
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 1229, ctx.xer);
	// bgt cr6,0x820a5d60
	if (ctx.cr6.gt) goto loc_820A5D60;
	// beq cr6,0x820a5c84
	if (ctx.cr6.eq) goto loc_820A5C84;
	// lis r11,-32747
	ctx.r11.s64 = -2146107392;
	// ori r10,r11,21001
	ctx.r10.u64 = ctx.r11.u64 | 21001;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x820a5d78
	if (!ctx.cr6.eq) goto loc_820A5D78;
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r11,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A5D60:
	// cmpwi cr6,r28,10049
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 10049, ctx.xer);
	// beq cr6,0x820a5d70
	if (ctx.cr6.eq) goto loc_820A5D70;
	// cmpwi cr6,r28,10065
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 10065, ctx.xer);
	// bne cr6,0x820a5d78
	if (!ctx.cr6.eq) goto loc_820A5D78;
loc_820A5D70:
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r11,140(r30)
	REX_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
loc_820A5D78:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
