DEFINE_REX_FUNC(sub_82126B08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x82126B10;
	__savegprlr_22(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// mr r23,r8
	ctx.r23.u64 = ctx.r8.u64;
	// mr r22,r9
	ctx.r22.u64 = ctx.r9.u64;
	// ori r29,r10,1
	ctx.r29.u64 = ctx.r10.u64 | 1;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82126b40
	if (!ctx.cr6.eq) goto loc_82126B40;
	// rlwinm r29,r29,0,25,23
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
loc_82126B40:
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// beq cr6,0x82126b6c
	if (ctx.cr6.eq) goto loc_82126B6C;
	// addi r10,r27,4
	ctx.r10.s64 = ctx.r27.s64 + 4;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82126B58:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// add r31,r9,r31
	ctx.r31.u64 = ctx.r9.u64 + ctx.r31.u64;
	// bne 0x82126b58
	if (!ctx.cr0.eq) goto loc_82126B58;
loc_82126B6C:
	// rlwinm. r10,r29,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82126b80
	if (ctx.cr0.eq) goto loc_82126B80;
	// addi r11,r30,10
	ctx.r11.s64 = ctx.r30.s64 + 10;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// b 0x82126b84
	goto loc_82126B84;
loc_82126B80:
	// addi r11,r31,88
	ctx.r11.s64 = ctx.r31.s64 + 88;
loc_82126B84:
	// addi r4,r11,9
	ctx.r4.s64 = ctx.r11.s64 + 9;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82126b94
	if (ctx.cr6.eq) goto loc_82126B94;
	// addi r4,r4,8
	ctx.r4.s64 = ctx.r4.s64 + 8;
loc_82126B94:
	// cmplwi cr6,r31,1220
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1220, ctx.xer);
	// ble cr6,0x82126ba8
	if (!ctx.cr6.gt) goto loc_82126BA8;
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4102
	ctx.r3.u64 = ctx.r3.u64 | 4102;
	// b 0x82126c40
	goto loc_82126C40;
loc_82126BA8:
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x82108f48
	ctx.lr = 0x82126BB0;
	sub_82108F48(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82126bc4
	if (!ctx.cr0.eq) goto loc_82126BC4;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82126c40
	goto loc_82126C40;
loc_82126BC4:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// mr r8,r22
	ctx.r8.u64 = ctx.r22.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1
	ctx.r6.s64 = 1;
	// std r26,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r26.u64);
	// stw r26,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r26.u32);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82126198
	ctx.lr = 0x82126BEC;
	sub_82126198(ctx, base);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// bl 0x82126898
	ctx.lr = 0x82126C08;
	sub_82126898(ctx, base);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r3,80(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 80);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82125dd0
	ctx.lr = 0x82126C1C;
	sub_82125DD0(ctx, base);
	// lhz r11,72(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 72);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// rlwinm r6,r11,21,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 21) & 0x1;
	// bl 0x821231f0
	ctx.lr = 0x82126C34;
	sub_821231F0(ctx, base);
	// lwz r11,276(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r25,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r25.u32);
loc_82126C40:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
