DEFINE_REX_FUNC(sub_82054C38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82054C40;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// lwz r3,1344(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 1344);
	// bl 0x82067230
	ctx.lr = 0x82054C68;
	sub_82067230(ctx, base);
	// lwz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,1348(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 1348);
	// bl 0x82067230
	ctx.lr = 0x82054C7C;
	sub_82067230(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lis r9,30583
	ctx.r9.s64 = 2004287488;
	// lis r8,-1
	ctx.r8.s64 = -65536;
	// addi r11,r11,1308
	ctx.r11.s64 = ctx.r11.s64 + 1308;
	// ori r7,r9,30719
	ctx.r7.u64 = ctx.r9.u64 | 30719;
	// ori r4,r8,255
	ctx.r4.u64 = ctx.r8.u64 | 255;
	// li r6,1
	ctx.r6.s64 = 1;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// lhz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// addi r3,r5,20768
	ctx.r3.s64 = ctx.r5.s64 + 20768;
	// addi r10,r10,5
	ctx.r10.s64 = ctx.r10.s64 + 5;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stw r7,16(r8)
	REX_STORE_U32(ctx.r8.u32 + 16, ctx.r7.u32);
	// sth r6,8(r11)
	REX_STORE_U16(ctx.r11.u32 + 8, ctx.r6.u16);
	// lwz r7,24(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// stw r4,16(r7)
	REX_STORE_U32(ctx.r7.u32 + 16, ctx.r4.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// stw r31,1664(r11)
	REX_STORE_U32(ctx.r11.u32 + 1664, ctx.r31.u32);
	// stw r3,1672(r11)
	REX_STORE_U32(ctx.r11.u32 + 1672, ctx.r3.u32);
	// sth r27,1698(r11)
	REX_STORE_U16(ctx.r11.u32 + 1698, ctx.r27.u16);
	// lwz r6,48(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lhz r5,10(r6)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r6.u32 + 10);
	// sth r5,1320(r11)
	REX_STORE_U16(ctx.r11.u32 + 1320, ctx.r5.u16);
	// sth r5,1318(r11)
	REX_STORE_U16(ctx.r11.u32 + 1318, ctx.r5.u16);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// beq cr6,0x82054d00
	if (ctx.cr6.eq) goto loc_82054D00;
	// lwz r10,1332(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1332);
	// stw r31,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r31.u32);
	// stw r30,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r30.u32);
	// b 0x82054d14
	goto loc_82054D14;
loc_82054D00:
	// lwz r8,1332(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 1332);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r10,20768
	ctx.r9.s64 = ctx.r10.s64 + 20768;
	// stw r31,24(r8)
	REX_STORE_U32(ctx.r8.u32 + 24, ctx.r31.u32);
	// stw r9,28(r8)
	REX_STORE_U32(ctx.r8.u32 + 28, ctx.r9.u32);
loc_82054D14:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,1336(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1336);
	// stw r31,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r31.u32);
	// stw r29,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r29.u32);
	// bl 0x82053bc8
	ctx.lr = 0x82054D30;
	sub_82053BC8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
