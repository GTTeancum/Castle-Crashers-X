DEFINE_REX_FUNC(sub_82091AC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x82091AC8;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,116
	ctx.r7.s64 = ctx.r1.s64 + 116;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,-6600(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6600);
	// bl 0x820b1078
	ctx.lr = 0x82091AF8;
	sub_820B1078(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82091c64
	if (ctx.cr6.eq) goto loc_82091C64;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r3,-6648(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6648);
	// bl 0x8208f930
	ctx.lr = 0x82091B10;
	sub_8208F930(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82066ea8
	ctx.lr = 0x82091B1C;
	sub_82066EA8(ctx, base);
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// lbz r9,-22601(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + -22601);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82091b44
	if (!ctx.cr6.eq) goto loc_82091B44;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r3,r11,-1768
	ctx.r3.s64 = ctx.r11.s64 + -1768;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82091B44;
	sub_820A71E8(ctx, base);
loc_82091B44:
	// bl 0x820b5eb8
	ctx.lr = 0x82091B48;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,96
	ctx.r4.s64 = 96;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82091B60;
	sub_8209BDD8(ctx, base);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lwz r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r5,120(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// addi r7,r30,96
	ctx.r7.s64 = ctx.r30.s64 + 96;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r26,0(r6)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// clrlwi r27,r28,16
	ctx.r27.u64 = ctx.r28.u32 & 0xFFFF;
	// lwz r25,4(r6)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r24,8(r6)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// addi r3,r29,80
	ctx.r3.s64 = ctx.r29.s64 + 80;
	// lwz r7,12(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// stw r9,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// stw r8,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r8.u32);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r10,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// stw r5,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r5.u32);
	// stw r10,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r10.u32);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// stw r10,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r9,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r9.u32);
	// stw r8,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r8.u32);
	// stw r9,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r9.u32);
	// stw r8,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// stw r27,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r27.u32);
	// stw r10,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// stw r31,92(r30)
	REX_STORE_U32(ctx.r30.u32 + 92, ctx.r31.u32);
	// stw r26,96(r30)
	REX_STORE_U32(ctx.r30.u32 + 96, ctx.r26.u32);
	// stw r25,100(r30)
	REX_STORE_U32(ctx.r30.u32 + 100, ctx.r25.u32);
	// stw r24,104(r30)
	REX_STORE_U32(ctx.r30.u32 + 104, ctx.r24.u32);
	// stw r7,108(r30)
	REX_STORE_U32(ctx.r30.u32 + 108, ctx.r7.u32);
	// sth r28,80(r30)
	REX_STORE_U16(ctx.r30.u32 + 80, ctx.r28.u16);
	// bl 0x82084448
	ctx.lr = 0x82091BFC;
	sub_82084448(ctx, base);
	// lwz r11,108(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 108);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82091c24
	if (!ctx.cr6.eq) goto loc_82091C24;
	// stw r31,108(r29)
	REX_STORE_U32(ctx.r29.u32 + 108, ctx.r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82066ea8
	ctx.lr = 0x82091C18;
	sub_82066EA8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
loc_82091C24:
	// addi r10,r11,84
	ctx.r10.s64 = ctx.r11.s64 + 84;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82091c48
	if (ctx.cr6.eq) goto loc_82091C48;
loc_82091C34:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r11,84
	ctx.r10.s64 = ctx.r11.s64 + 84;
	// lwz r9,84(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82091c34
	if (!ctx.cr6.eq) goto loc_82091C34;
loc_82091C48:
	// stw r31,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82066ea8
	ctx.lr = 0x82091C58;
	sub_82066EA8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
loc_82091C64:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// clrlwi r5,r28,16
	ctx.r5.u64 = ctx.r28.u32 & 0xFFFF;
	// addi r3,r11,-2984
	ctx.r3.s64 = ctx.r11.s64 + -2984;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x82091C78;
	sub_8208C5D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
