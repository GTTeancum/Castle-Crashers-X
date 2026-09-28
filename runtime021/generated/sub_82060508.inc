DEFINE_REX_FUNC(sub_82060508) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82060510;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,15
	ctx.r5.s64 = 15;
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x8206053C;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820606d0
	if (ctx.cr6.eq) goto loc_820606D0;
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,35
	ctx.r5.s64 = 35;
	// sth r11,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r11.u16);
	// li r4,506
	ctx.r4.s64 = 506;
	// lwz r3,24(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x82060564;
	sub_82067230(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,28(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 28);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82067230
	ctx.lr = 0x82060578;
	sub_82067230(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 32);
	// bl 0x82067230
	ctx.lr = 0x8206058C;
	sub_82067230(ctx, base);
	// lhz r5,12(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r6,r7,18280
	ctx.r6.s64 = ctx.r7.s64 + 18280;
	// rotlwi r4,r5,2
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// lwzx r3,r4,r6
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// rlwinm r10,r11,2,14,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x3FFFC;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// addi r29,r10,5
	ctx.r29.s64 = ctx.r10.s64 + 5;
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// bge cr6,0x820605f8
	if (!ctx.cr6.lt) goto loc_820605F8;
loc_820605C8:
	// addi r11,r30,5
	ctx.r11.s64 = ctx.r30.s64 + 5;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r9,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x82067230
	ctx.lr = 0x820605E4;
	sub_82067230(ctx, base);
	// addi r8,r30,1
	ctx.r8.s64 = ctx.r30.s64 + 1;
	// clrlwi r11,r8,16
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFF;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x820605c8
	if (ctx.cr6.lt) goto loc_820605C8;
loc_820605F8:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lhz r10,26(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 26);
	// li r3,489
	ctx.r3.s64 = 489;
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// addi r7,r11,5
	ctx.r7.s64 = ctx.r11.s64 + 5;
	// stw r3,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,338
	ctx.r4.s64 = 338;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r6,r10,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// stw r4,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// li r3,493
	ctx.r3.s64 = 493;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r10,490
	ctx.r10.s64 = 490;
	// stw r3,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r7,491
	ctx.r7.s64 = 491;
	// lwzx r3,r5,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// li r4,492
	ctx.r4.s64 = 492;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r7,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// li r10,494
	ctx.r10.s64 = 494;
	// stw r4,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// li r7,495
	ctx.r7.s64 = 495;
	// lwzx r4,r6,r8
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// li r9,496
	ctx.r9.s64 = 496;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r5,20
	ctx.r5.s64 = 20;
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// clrlwi r30,r11,16
	ctx.r30.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// bl 0x82067230
	ctx.lr = 0x82060674;
	sub_82067230(ctx, base);
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// lbz r7,-22662(r8)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r8.u32 + -22662);
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820606ac
	if (ctx.cr6.eq) goto loc_820606AC;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r4,495
	ctx.r4.s64 = 495;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x82067230
	ctx.lr = 0x820606A4;
	sub_82067230(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_820606AC:
	// lhz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// addi r7,r11,5
	ctx.r7.s64 = ctx.r11.s64 + 5;
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rotlwi r6,r10,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r6,r8
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// lwzx r3,r3,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// bl 0x82067230
	ctx.lr = 0x820606D0;
	sub_82067230(ctx, base);
loc_820606D0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
