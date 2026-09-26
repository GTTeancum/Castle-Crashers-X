DEFINE_REX_FUNC(sub_820A1288) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820A1290;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r30,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r30.u32);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// addis r26,r31,2
	ctx.r26.s64 = ctx.r31.s64 + 131072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r26,r26,-5912
	ctx.r26.s64 = ctx.r26.s64 + -5912;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// li r7,100
	ctx.r7.s64 = 100;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820b6820
	ctx.lr = 0x820A12D0;
	sub_820B6820(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820a13c4
	if (!ctx.cr6.eq) goto loc_820A13C4;
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a13c4
	if (ctx.cr6.eq) goto loc_820A13C4;
	// addis r29,r31,2
	ctx.r29.s64 = ctx.r31.s64 + 131072;
	// addi r29,r29,-5904
	ctx.r29.s64 = ctx.r29.s64 + -5904;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a1310
	if (ctx.cr6.eq) goto loc_820A1310;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2872
	ctx.r3.s64 = ctx.r11.s64 + 2872;
	// bl 0x8208c5d8
	ctx.lr = 0x820A1308;
	sub_8208C5D8(ctx, base);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x820a7400
	ctx.lr = 0x820A1310;
	sub_820A7400(ctx, base);
loc_820A1310:
	// lwz r3,112(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x820a7390
	ctx.lr = 0x820A1318;
	sub_820A7390(ctx, base);
	// addi r11,r27,31268
	ctx.r11.s64 = ctx.r27.s64 + 31268;
	// stw r3,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// addis r7,r31,2
	ctx.r7.s64 = ctx.r31.s64 + 131072;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r7,-5944
	ctx.r7.s64 = ctx.r7.s64 + -5944;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// li r10,7
	ctx.r10.s64 = 7;
	// stwx r30,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r30.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820A1340:
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x820a1340
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820A1340;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r3,0(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r5,112(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x820b6ac0
	ctx.lr = 0x820A1360;
	sub_820B6AC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,997
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 997, ctx.xer);
	// beq cr6,0x820a1388
	if (ctx.cr6.eq) goto loc_820A1388;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2920
	ctx.r3.s64 = ctx.r11.s64 + 2920;
	// bl 0x8208c5d8
	ctx.lr = 0x820A1378;
	sub_8208C5D8(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x820a7400
	ctx.lr = 0x820A1380;
	sub_820A7400(ctx, base);
	// stw r30,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// b 0x820a13d0
	goto loc_820A13D0;
loc_820A1388:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// stw r30,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r30,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r30.u32);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r11,59620
	ctx.r8.u64 = ctx.r11.u64 | 59620;
	// ori r7,r10,59636
	ctx.r7.u64 = ctx.r10.u64 | 59636;
	// ori r6,r9,59628
	ctx.r6.u64 = ctx.r9.u64 | 59628;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stwx r5,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r5.u32);
	// stwx r27,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r27.u32);
	// stwx r30,r31,r6
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_820A13C4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,2820
	ctx.r3.s64 = ctx.r11.s64 + 2820;
	// bl 0x8208c5d8
	ctx.lr = 0x820A13D0;
	sub_8208C5D8(ctx, base);
loc_820A13D0:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r30.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
