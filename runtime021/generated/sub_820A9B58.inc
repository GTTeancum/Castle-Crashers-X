DEFINE_REX_FUNC(sub_820A9B58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820A9B60;
	__savegprlr_28(ctx, base);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r29,r4,4
	ctx.r29.s64 = ctx.r4.s64 + 4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r11,8396
	ctx.r4.s64 = ctx.r11.s64 + 8396;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82127778
	ctx.lr = 0x820A9B80;
	sub_82127778(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820b64e0
	ctx.lr = 0x820A9BA0;
	sub_820B64E0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// bne cr6,0x820a9bc8
	if (!ctx.cr6.eq) goto loc_820A9BC8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r11,8416
	ctx.r3.s64 = ctx.r11.s64 + 8416;
	// bl 0x8208c5d8
	ctx.lr = 0x820A9BBC;
	sub_8208C5D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820A9BC8:
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820b6310
	ctx.lr = 0x820A9BE0;
	sub_820B6310(ctx, base);
	// lis r11,22608
	ctx.r11.s64 = 1481637888;
	// lwz r4,104(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// ori r10,r11,21042
	ctx.r10.u64 = ctx.r11.u64 | 21042;
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820a9c14
	if (ctx.cr6.eq) goto loc_820A9C14;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,8440
	ctx.r3.s64 = ctx.r11.s64 + 8440;
	// bl 0x8208c5d8
	ctx.lr = 0x820A9C00;
	sub_8208C5D8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820b6498
	ctx.lr = 0x820A9C08;
	sub_820B6498(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820A9C14:
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r3,108(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// stw r11,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r11.u32);
	// stw r3,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r3.u32);
	// bl 0x820a7390
	ctx.lr = 0x820A9C28;
	sub_820A7390(ctx, base);
	// stw r3,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r3.u32);
	// li r6,1028
	ctx.r6.s64 = 1028;
	// lwz r3,208(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// li r5,4096
	ctx.r5.s64 = 4096;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x820b6108
	ctx.lr = 0x820A9C40;
	sub_820B6108(ctx, base);
	// stw r3,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,200(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r4,196(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820b6310
	ctx.lr = 0x820A9C5C;
	sub_820B6310(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r5,208(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,204(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// bl 0x820b6310
	ctx.lr = 0x820A9C74;
	sub_820B6310(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820b6498
	ctx.lr = 0x820A9C7C;
	sub_820B6498(ctx, base);
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a9d24
	if (ctx.cr6.eq) goto loc_820A9D24;
	// addi r30,r10,4
	ctx.r30.s64 = ctx.r10.s64 + 4;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// lis r29,21592
	ctx.r29.s64 = 1415053312;
loc_820A9C9C:
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r9,-4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + -4);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r7,r9,0,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFF0000;
	// stw r8,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r8.u32);
	// cmplw cr6,r7,r29
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820a9cdc
	if (!ctx.cr6.eq) goto loc_820A9CDC;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r4,204(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// stw r3,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r3.u32);
	// bl 0x820d7d70
	ctx.lr = 0x820A9CD8;
	sub_820D7D70(ctx, base);
	// b 0x820a9d18
	goto loc_820A9D18;
loc_820A9CDC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,196(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// addi r11,r11,22
	ctx.r11.s64 = ctx.r11.s64 + 22;
	// lwz r10,108(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// lhz r10,20(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 20);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r7,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r7.u32);
	// stw r8,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r8.u32);
loc_820A9D18:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// bne 0x820a9c9c
	if (!ctx.cr0.eq) goto loc_820A9C9C;
loc_820A9D24:
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lwz r3,192(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820c4498
	ctx.lr = 0x820A9D34;
	sub_820C4498(ctx, base);
	// lwz r8,204(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r7,152(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r6,156(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r10,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r9.u32);
	// stb r11,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
	// stw r8,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r8.u32);
	// stw r7,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r7.u32);
	// stw r6,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r6.u32);
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
