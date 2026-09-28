DEFINE_REX_FUNC(sub_8210C1A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x8210C1B0;
	__savegprlr_24(ctx, base);
	// stwu r1,-2096(r1)
	ea = -2096 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// stw r30,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r30.u32);
	// bl 0x82136f58
	ctx.lr = 0x8210C1CC;
	sub_82136F58(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r29,-1
	ctx.r29.s64 = -1;
	// li r27,1
	ctx.r27.s64 = 1;
loc_8210C1D8:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210c278
	if (ctx.cr6.eq) goto loc_8210C278;
	// subf r11,r11,r28
	ctx.r11.u64 = ctx.r28.u64 - ctx.r11.u64;
	// cmplwi cr6,r11,1000
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1000, ctx.xer);
	// blt cr6,0x8210c278
	if (ctx.cr6.lt) goto loc_8210C278;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8210c278
	if (ctx.cr6.eq) goto loc_8210C278;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lwz r6,44(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lhz r4,36(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 36);
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// li r24,2
	ctx.r24.s64 = 2;
	// stw r5,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r5.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// std r30,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r30.u64);
	// li r9,16
	ctx.r9.s64 = 16;
	// std r30,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r30.u64);
	// stw r6,97(r1)
	REX_STORE_U32(ctx.r1.u32 + 97, ctx.r6.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// sth r4,114(r1)
	REX_STORE_U16(ctx.r1.u32 + 114, ctx.r4.u16);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stb r30,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r30.u8);
	// li r5,1
	ctx.r5.s64 = 1;
	// sth r24,112(r1)
	REX_STORE_U16(ctx.r1.u32 + 112, ctx.r24.u16);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r29,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// bl 0x820fc858
	ctx.lr = 0x8210C25C;
	sub_820FC858(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8210c3b0
	if (!ctx.cr0.eq) goto loc_8210C3B0;
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8210c278
	if (!ctx.cr6.eq) goto loc_8210C278;
	// addi r11,r28,1
	ctx.r11.s64 = ctx.r28.s64 + 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_8210C278:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r7,r1,152
	ctx.r7.s64 = ctx.r1.s64 + 152;
	// stw r27,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r27.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r30,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r30.u32);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,244(r1)
	REX_STORE_U32(ctx.r1.u32 + 244, ctx.r11.u32);
	// bl 0x820fc7a0
	ctx.lr = 0x8210C2A4;
	sub_820FC7A0(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8210c3b0
	if (ctx.cr6.eq) goto loc_8210C3B0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8210c404
	if (!ctx.cr6.gt) goto loc_8210C404;
	// li r11,16
	ctx.r11.s64 = 16;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r8,r1,148
	ctx.r8.s64 = ctx.r1.s64 + 148;
	// stw r11,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1500
	ctx.r5.s64 = 1500;
	// addi r4,r1,512
	ctx.r4.s64 = ctx.r1.s64 + 512;
	// bl 0x820fc7e0
	ctx.lr = 0x8210C2D8;
	sub_820FC7E0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bgt 0x8210c2f8
	if (ctx.cr0.gt) goto loc_8210C2F8;
	// bl 0x820fc8b0
	ctx.lr = 0x8210C2E4;
	sub_820FC8B0(ctx, base);
	// cmpwi cr6,r3,10054
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 10054, ctx.xer);
	// beq cr6,0x8210c404
	if (ctx.cr6.eq) goto loc_8210C404;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8210c410
	if (!ctx.cr6.gt) goto loc_8210C410;
	// b 0x8210c3bc
	goto loc_8210C3BC;
loc_8210C2F8:
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x8210c404
	if (ctx.cr6.lt) goto loc_8210C404;
	// lbz r11,512(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 512);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8210c3c8
	if (!ctx.cr0.eq) goto loc_8210C3C8;
	// cmplwi cr6,r3,5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 5, ctx.xer);
	// blt cr6,0x8210c404
	if (ctx.cr6.lt) goto loc_8210C404;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210c404
	if (!ctx.cr6.eq) goto loc_8210C404;
	// lwz r11,513(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 513);
	// addi r3,r1,165
	ctx.r3.s64 = ctx.r1.s64 + 165;
	// stb r27,160(r1)
	REX_STORE_U8(ctx.r1.u32 + 160, ctx.r27.u8);
	// stw r11,161(r1)
	REX_STORE_U32(ctx.r1.u32 + 161, ctx.r11.u32);
	// bl 0x820d7fa8
	ctx.lr = 0x8210C334;
	sub_820D7FA8(ctx, base);
	// ld r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 12);
	// addi r4,r31,20
	ctx.r4.s64 = ctx.r31.s64 + 20;
	// addi r3,r1,209
	ctx.r3.s64 = ctx.r1.s64 + 209;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r12,201
	ctx.r12.s64 = 201;
	// stdx r11,r1,r12
	REX_STORE_U64(ctx.r1.u32 + ctx.r12.u32, ctx.r11.u64);
	// bl 0x82129a70
	ctx.lr = 0x8210C350;
	sub_82129A70(ctx, base);
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// li r10,65
	ctx.r10.s64 = 65;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stw r29,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stw r10,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// stw r9,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210c384
	if (ctx.cr6.eq) goto loc_8210C384;
	// addi r10,r31,124
	ctx.r10.s64 = ctx.r31.s64 + 124;
	// stw r11,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r10,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r10.u32);
loc_8210C384:
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// bl 0x820fc858
	ctx.lr = 0x8210C3A8;
	sub_820FC858(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8210c404
	if (ctx.cr0.eq) goto loc_8210C404;
loc_8210C3B0:
	// bl 0x820fc8b0
	ctx.lr = 0x8210C3B4;
	sub_820FC8B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble 0x8210c410
	if (!ctx.cr0.gt) goto loc_8210C410;
loc_8210C3BC:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r3,r11,32775
	ctx.r3.u64 = ctx.r11.u64 | 2147942400;
	// b 0x8210c410
	goto loc_8210C410;
loc_8210C3C8:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8210c404
	if (!ctx.cr6.eq) goto loc_8210C404;
	// cmplwi cr6,r3,65
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 65, ctx.xer);
	// blt cr6,0x8210c404
	if (ctx.cr6.lt) goto loc_8210C404;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210c404
	if (ctx.cr6.eq) goto loc_8210C404;
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,513(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 513);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8210c404
	if (!ctx.cr6.eq) goto loc_8210C404;
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// addi r8,r3,-65
	ctx.r8.s64 = ctx.r3.s64 + -65;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8210c418
	if (!ctx.cr6.gt) goto loc_8210C418;
loc_8210C404:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x8210c1d8
	if (!ctx.cr6.eq) goto loc_8210C1D8;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_8210C410:
	// addi r1,r1,2096
	ctx.r1.s64 = ctx.r1.s64 + 2096;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
loc_8210C418:
	// addi r7,r1,577
	ctx.r7.s64 = ctx.r1.s64 + 577;
	// addi r6,r1,561
	ctx.r6.s64 = ctx.r1.s64 + 561;
	// addi r5,r1,553
	ctx.r5.s64 = ctx.r1.s64 + 553;
	// addi r4,r1,517
	ctx.r4.s64 = ctx.r1.s64 + 517;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210bed0
	ctx.lr = 0x8210C430;
	sub_8210BED0(ctx, base);
	// stw r3,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x8210c410
	goto loc_8210C410;
}
