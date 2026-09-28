DEFINE_REX_FUNC(sub_82139C00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x82139C08;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// addi r24,r28,1376
	ctx.r24.s64 = ctx.r28.s64 + 1376;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r22,0
	ctx.r22.s64 = 0;
	// bl 0x82136c88
	ctx.lr = 0x82139C28;
	sub_82136C88(ctx, base);
	// addi r31,r28,1112
	ctx.r31.s64 = ctx.r28.s64 + 1112;
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// li r29,4
	ctx.r29.s64 = 4;
loc_82139C34:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82139c48
	if (ctx.cr6.eq) goto loc_82139C48;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8213c7a0
	ctx.lr = 0x82139C48;
	sub_8213C7A0(ctx, base);
loc_82139C48:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r30,r30,12
	ctx.r30.s64 = ctx.r30.s64 + 12;
	// bne 0x82139c34
	if (!ctx.cr0.eq) goto loc_82139C34;
	// addi r23,r28,1832
	ctx.r23.s64 = ctx.r28.s64 + 1832;
	// li r5,408
	ctx.r5.s64 = 408;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x82136c88
	ctx.lr = 0x82139C6C;
	sub_82136C88(ctx, base);
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// mr r27,r22
	ctx.r27.u64 = ctx.r22.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82139db4
	if (!ctx.cr6.gt) goto loc_82139DB4;
	// addi r31,r28,1128
	ctx.r31.s64 = ctx.r28.s64 + 1128;
	// mr r25,r23
	ctx.r25.u64 = ctx.r23.u64;
	// li r26,-1
	ctx.r26.s64 = -1;
loc_82139C88:
	// lwz r11,1308(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 1308);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82139d84
	if (!ctx.cr6.eq) goto loc_82139D84;
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// ld r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82139cd8
	if (ctx.cr6.eq) goto loc_82139CD8;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// addi r11,r30,36
	ctx.r11.s64 = ctx.r30.s64 + 36;
	// li r8,4
	ctx.r8.s64 = 4;
loc_82139CB4:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82139cc4
	if (ctx.cr6.lt) goto loc_82139CC4;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_82139CC4:
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bne 0x82139cb4
	if (!ctx.cr0.eq) goto loc_82139CB4;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// b 0x82139cdc
	goto loc_82139CDC;
loc_82139CD8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_82139CDC:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// addi r5,r27,1
	ctx.r5.s64 = ctx.r27.s64 + 1;
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82139d84
	if (!ctx.cr6.lt) goto loc_82139D84;
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// addi r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 4;
loc_82139CF4:
	// lwz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r9,r10,36
	ctx.r9.s64 = ctx.r10.s64 + 36;
loc_82139D04:
	// lwz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82139d14
	if (ctx.cr6.lt) goto loc_82139D14;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
loc_82139D14:
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x82139d04
	if (!ctx.cr0.eq) goto loc_82139D04;
	// ld r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// cmpldi cr6,r10,0
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, 0, ctx.xer);
	// beq cr6,0x82139d3c
	if (ctx.cr6.eq) goto loc_82139D3C;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x82139d3c
	if (!ctx.cr6.lt) goto loc_82139D3C;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_82139D3C:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplw cr6,r5,r4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x82139cf4
	if (ctx.cr6.lt) goto loc_82139CF4;
	// cmplw cr6,r29,r27
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x82139d84
	if (ctx.cr6.eq) goto loc_82139D84;
	// addi r11,r29,282
	ctx.r11.s64 = ctx.r29.s64 + 282;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r28
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// xor r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r30.u64;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwzx r10,r11,r28
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// xor r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// stwx r10,r11,r28
	REX_STORE_U32(ctx.r11.u32 + ctx.r28.u32, ctx.r10.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// xor r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 ^ ctx.r10.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82139D84:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82139d9c
	if (ctx.cr6.eq) goto loc_82139D9C;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// bl 0x8213e1f0
	ctx.lr = 0x82139D9C;
	sub_8213E1F0(ctx, base);
loc_82139D9C:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r25,r25,12
	ctx.r25.s64 = ctx.r25.s64 + 12;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82139c88
	if (ctx.cr6.lt) goto loc_82139C88;
loc_82139DB4:
	// lis r10,-32234
	ctx.r10.s64 = -2112487424;
	// stw r22,1308(r28)
	REX_STORE_U32(ctx.r28.u32 + 1308, ctx.r22.u32);
	// addi r11,r28,1328
	ctx.r11.s64 = ctx.r28.s64 + 1328;
	// addi r10,r10,-29740
	ctx.r10.s64 = ctx.r10.s64 + -29740;
	// addi r8,r11,48
	ctx.r8.s64 = ctx.r11.s64 + 48;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// lwz r7,12(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// bge cr6,0x82139e14
	if (!ctx.cr6.lt) goto loc_82139E14;
	// addi r6,r24,48
	ctx.r6.s64 = ctx.r24.s64 + 48;
	// subf r5,r11,r24
	ctx.r5.u64 = ctx.r24.u64 - ctx.r11.u64;
loc_82139DE0:
	// add r10,r5,r11
	ctx.r10.u64 = ctx.r5.u64 + ctx.r11.u64;
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// bge cr6,0x82139e08
	if (!ctx.cr6.lt) goto loc_82139E08;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r4,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stwx r10,r4,r11
	REX_STORE_U32(ctx.r4.u32 + ctx.r11.u32, ctx.r10.u32);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82139de0
	if (ctx.cr6.lt) goto loc_82139DE0;
loc_82139E08:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82139e14
	if (ctx.cr6.eq) goto loc_82139E14;
	// mr r22,r9
	ctx.r22.u64 = ctx.r9.u64;
loc_82139E14:
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r11,r11,-29804
	ctx.r11.s64 = ctx.r11.s64 + -29804;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,12(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x821395d8
	ctx.lr = 0x82139E30;
	sub_821395D8(ctx, base);
	// cmplw cr6,r3,r22
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r22.u32, ctx.xer);
	// ble cr6,0x82139e3c
	if (!ctx.cr6.gt) goto loc_82139E3C;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_82139E3C:
	// lwz r11,1324(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 1324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82139e50
	if (!ctx.cr6.eq) goto loc_82139E50;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,1324(r28)
	REX_STORE_U32(ctx.r28.u32 + 1324, ctx.r11.u32);
loc_82139E50:
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// lwz r6,1324(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 1324);
	// addi r30,r23,408
	ctx.r30.s64 = ctx.r23.s64 + 408;
	// addi r10,r11,-29772
	ctx.r10.s64 = ctx.r11.s64 + -29772;
	// addi r31,r28,1424
	ctx.r31.s64 = ctx.r28.s64 + 1424;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// cmplw cr6,r23,r30
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r30.u32, ctx.xer);
	// lwz r5,12(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// bge cr6,0x82139e98
	if (!ctx.cr6.lt) goto loc_82139E98;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_82139E78:
	// lwzx r9,r10,r11
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// ble cr6,0x82139e8c
	if (!ctx.cr6.gt) goto loc_82139E8C;
	// li r9,1
	ctx.r9.s64 = 1;
	// stwx r9,r10,r11
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u32);
loc_82139E8C:
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x82139e78
	if (ctx.cr6.lt) goto loc_82139E78;
loc_82139E98:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821395d8
	ctx.lr = 0x82139EA4;
	sub_821395D8(ctx, base);
	// addi r10,r31,408
	ctx.r10.s64 = ctx.r31.s64 + 408;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82139ee0
	if (!ctx.cr6.lt) goto loc_82139EE0;
	// subf r8,r23,r31
	ctx.r8.u64 = ctx.r31.u64 - ctx.r23.u64;
loc_82139EB8:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x82139ee0
	if (!ctx.cr6.lt) goto loc_82139EE0;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwzx r7,r7,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// stwx r7,r9,r11
	REX_STORE_U32(ctx.r9.u32 + ctx.r11.u32, ctx.r7.u32);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// add r9,r11,r8
	ctx.r9.u64 = ctx.r11.u64 + ctx.r8.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82139eb8
	if (ctx.cr6.lt) goto loc_82139EB8;
loc_82139EE0:
	// cmplw cr6,r3,r22
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r22.u32, ctx.xer);
	// ble cr6,0x82139eec
	if (!ctx.cr6.gt) goto loc_82139EEC;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_82139EEC:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x82139f00
	if (ctx.cr6.eq) goto loc_82139F00;
	// lwz r11,1320(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 1320);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,1320(r28)
	REX_STORE_U32(ctx.r28.u32 + 1320, ctx.r11.u32);
loc_82139F00:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
