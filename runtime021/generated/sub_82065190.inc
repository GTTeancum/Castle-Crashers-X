DEFINE_REX_FUNC(sub_82065190) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82065198;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r4,-6628(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// lbz r11,29(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 29);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82065374
	if (!ctx.cr6.eq) goto loc_82065374;
	// lwz r10,36(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 36);
	// li r31,0
	ctx.r31.s64 = 0;
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// stw r31,116(r4)
	REX_STORE_U32(ctx.r4.u32 + 116, ctx.r31.u32);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820651f0
	if (ctx.cr6.eq) goto loc_820651F0;
	// lwz r8,108(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 108);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820651ec
	if (ctx.cr6.eq) goto loc_820651EC;
	// li r9,1
	ctx.r9.s64 = 1;
	// b 0x820651f0
	goto loc_820651F0;
loc_820651EC:
	// li r11,1
	ctx.r11.s64 = 1;
loc_820651F0:
	// rlwinm r8,r10,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82065218
	if (ctx.cr6.eq) goto loc_82065218;
	// lwz r8,108(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 108);
	// rlwinm r7,r8,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82065214
	if (ctx.cr6.eq) goto loc_82065214;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// b 0x82065218
	goto loc_82065218;
loc_82065214:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82065218:
	// rlwinm r8,r10,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82065240
	if (ctx.cr6.eq) goto loc_82065240;
	// lwz r8,108(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 108);
	// rlwinm r7,r8,0,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8206523c
	if (ctx.cr6.eq) goto loc_8206523C;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// b 0x82065240
	goto loc_82065240;
loc_8206523C:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82065240:
	// rlwinm r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82065268
	if (ctx.cr6.eq) goto loc_82065268;
	// lwz r10,108(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 108);
	// rlwinm r8,r10,0,28,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82065264
	if (ctx.cr6.eq) goto loc_82065264;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// b 0x82065268
	goto loc_82065268;
loc_82065264:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82065268:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820652b4
	if (ctx.cr6.eq) goto loc_820652B4;
	// lbz r11,180(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 180);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206529c
	if (ctx.cr6.eq) goto loc_8206529C;
	// stb r31,180(r4)
	REX_STORE_U8(ctx.r4.u32 + 180, ctx.r31.u8);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r5,184(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 184);
	// li r6,8
	ctx.r6.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6624(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// bl 0x82077310
	ctx.lr = 0x8206529C;
	sub_82077310(ctx, base);
loc_8206529C:
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82054d38
	ctx.lr = 0x820652AC;
	sub_82054D38(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820652B4:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820652d4
	if (!ctx.cr6.eq) goto loc_820652D4;
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82054d38
	ctx.lr = 0x820652CC;
	sub_82054D38(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820652D4:
	// lbz r11,180(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 180);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82065324
	if (ctx.cr6.eq) goto loc_82065324;
	// lwz r11,184(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 184);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// sth r11,30(r30)
	REX_STORE_U16(ctx.r30.u32 + 30, ctx.r11.u16);
	// bl 0x820a3050
	ctx.lr = 0x820652F0;
	sub_820A3050(ctx, base);
	// lwz r11,-6628(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// li r6,8
	ctx.r6.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r31,180(r11)
	REX_STORE_U8(ctx.r11.u32 + 180, ctx.r31.u8);
	// lwz r3,-6624(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + -6624);
	// lwz r5,184(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// bl 0x82077310
	ctx.lr = 0x82065310;
	sub_82077310(ctx, base);
	// li r4,38
	ctx.r4.s64 = 38;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8206531C;
	sub_82053BC8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82065324:
	// li r4,26
	ctx.r4.s64 = 26;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82053bc8
	ctx.lr = 0x82065330;
	sub_82053BC8(ctx, base);
	// lhz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82065360
	if (ctx.cr6.lt) goto loc_82065360;
	// beq cr6,0x82065358
	if (ctx.cr6.eq) goto loc_82065358;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82065350
	if (ctx.cr6.eq) goto loc_82065350;
	// li r4,582
	ctx.r4.s64 = 582;
	// b 0x82065364
	goto loc_82065364;
loc_82065350:
	// li r4,390
	ctx.r4.s64 = 390;
	// b 0x82065364
	goto loc_82065364;
loc_82065358:
	// li r4,389
	ctx.r4.s64 = 389;
	// b 0x82065364
	goto loc_82065364;
loc_82065360:
	// li r4,382
	ctx.r4.s64 = 382;
loc_82065364:
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x82065374;
	sub_82067230(ctx, base);
loc_82065374:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
