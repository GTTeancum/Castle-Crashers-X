DEFINE_REX_FUNC(sub_8206A840) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8206A848;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// ori r9,r10,59648
	ctx.r9.u64 = ctx.r10.u64 | 59648;
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r11,-6596(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// lwzx r3,r11,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206a8b0
	if (ctx.cr6.eq) goto loc_8206A8B0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,102
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 102, ctx.xer);
	// beq cr6,0x8206a8ac
	if (ctx.cr6.eq) goto loc_8206A8AC;
	// li r11,102
	ctx.r11.s64 = 102;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stb r27,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r27.u8);
	// stw r27,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r27.u32);
	// stw r27,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r27.u32);
	// stw r27,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r27.u32);
	// stw r27,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r27.u32);
	// stb r27,40(r3)
	REX_STORE_U8(ctx.r3.u32 + 40, ctx.r27.u8);
	// stw r27,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r27.u32);
	// stw r27,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r27.u32);
	// stw r27,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r27.u32);
	// stw r27,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r27.u32);
loc_8206A8AC:
	// bl 0x82050a50
	ctx.lr = 0x8206A8B0;
	sub_82050A50(ctx, base);
loc_8206A8B0:
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// li r30,72
	ctx.r30.s64 = 72;
	// lwz r3,-6628(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
loc_8206A8C0:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820a39f0
	ctx.lr = 0x8206A8C8;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,-6628(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206a91c
	if (ctx.cr6.eq) goto loc_8206A91C;
	// lhzx r11,r30,r3
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + ctx.r3.u32);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// bne cr6,0x8206a8f8
	if (!ctx.cr6.eq) goto loc_8206A8F8;
	// rlwinm r11,r11,0,24,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8206a8fc
	if (!ctx.cr6.eq) goto loc_8206A8FC;
loc_8206A8F8:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8206A8FC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206a91c
	if (ctx.cr6.eq) goto loc_8206A91C;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820a32c0
	ctx.lr = 0x8206A918;
	sub_820A32C0(ctx, base);
	// lwz r3,-6628(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
loc_8206A91C:
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r30,104
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 104, ctx.xer);
	// blt cr6,0x8206a8c0
	if (ctx.cr6.lt) goto loc_8206A8C0;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820a37b8
	ctx.lr = 0x8206A938;
	sub_820A37B8(ctx, base);
	// lwz r3,48(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// li r31,-2
	ctx.r31.s64 = -2;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206a958
	if (ctx.cr6.eq) goto loc_8206A958;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82066610
	ctx.lr = 0x8206A950;
	sub_82066610(ctx, base);
	// lwz r11,48(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// lhz r31,10(r11)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
loc_8206A958:
	// lwz r11,56(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 56);
	// li r10,26
	ctx.r10.s64 = 26;
	// lhz r30,52(r28)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r28.u32 + 52);
	// addi r11,r11,11336
	ctx.r11.s64 = ctx.r11.s64 + 11336;
	// sth r10,52(r28)
	REX_STORE_U16(ctx.r28.u32 + 52, ctx.r10.u16);
	// stw r11,48(r28)
	REX_STORE_U32(ctx.r28.u32 + 48, ctx.r11.u32);
	// lbz r9,14(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 14);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206a984
	if (ctx.cr6.eq) goto loc_8206A984;
	// sth r31,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r31.u16);
	// sth r31,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r31.u16);
loc_8206A984:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,48(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// bl 0x82066610
	ctx.lr = 0x8206A990;
	sub_82066610(ctx, base);
	// lwz r11,48(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// clrlwi r5,r30,16
	ctx.r5.u64 = ctx.r30.u32 & 0xFFFF;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lhz r6,16(r11)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r11.u32 + 16);
	// rlwinm r10,r6,28,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0x1;
	// rlwinm r9,r6,30,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x1;
	// rlwinm r8,r6,29,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x1;
	// clrlwi r7,r6,31
	ctx.r7.u64 = ctx.r6.u32 & 0x1;
	// rlwinm r6,r6,31,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x1;
	// bl 0x82053c70
	ctx.lr = 0x8206A9BC;
	sub_82053C70(ctx, base);
	// lhz r11,12(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8206a9ec
	if (ctx.cr6.lt) goto loc_8206A9EC;
	// beq cr6,0x8206a9e4
	if (ctx.cr6.eq) goto loc_8206A9E4;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8206a9dc
	if (ctx.cr6.eq) goto loc_8206A9DC;
	// li r4,582
	ctx.r4.s64 = 582;
	// b 0x8206a9f0
	goto loc_8206A9F0;
loc_8206A9DC:
	// li r4,390
	ctx.r4.s64 = 390;
	// b 0x8206a9f0
	goto loc_8206A9F0;
loc_8206A9E4:
	// li r4,389
	ctx.r4.s64 = 389;
	// b 0x8206a9f0
	goto loc_8206A9F0;
loc_8206A9EC:
	// li r4,382
	ctx.r4.s64 = 382;
loc_8206A9F0:
	// lwz r11,48(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206AA00;
	sub_82067230(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
