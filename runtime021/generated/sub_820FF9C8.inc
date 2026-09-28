DEFINE_REX_FUNC(sub_820FF9C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820FF9D0;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,548(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 548);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
	// ble cr6,0x820ff9f8
	if (!ctx.cr6.gt) goto loc_820FF9F8;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,4336
	ctx.r3.u64 = ctx.r3.u64 | 4336;
	// b 0x820ffb2c
	goto loc_820FFB2C;
loc_820FF9F8:
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x820ffb24
	if (ctx.cr6.lt) goto loc_820FFB24;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bge cr6,0x820ffb24
	if (!ctx.cr6.lt) goto loc_820FFB24;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820ffa4c
	if (ctx.cr6.eq) goto loc_820FFA4C;
	// lwz r11,24(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// clrldi r30,r7,32
	ctx.r30.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// addi r11,r11,13
	ctx.r11.s64 = ctx.r11.s64 + 13;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// ldx r31,r11,r5
	ctx.r31.u64 = REX_LOAD_U64(ctx.r11.u32 + ctx.r5.u32);
	// add r31,r30,r31
	ctx.r31.u64 = ctx.r30.u64 + ctx.r31.u64;
	// stdx r31,r11,r5
	REX_STORE_U64(ctx.r11.u32 + ctx.r5.u32, ctx.r31.u64);
	// lwz r11,24(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// addi r11,r11,66
	ctx.r11.s64 = ctx.r11.s64 + 66;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r5
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r5.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stwx r31,r11,r5
	REX_STORE_U32(ctx.r11.u32 + ctx.r5.u32, ctx.r31.u32);
	// b 0x820ffab4
	goto loc_820FFAB4;
loc_820FFA4C:
	// lwz r30,248(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// addi r28,r3,248
	ctx.r28.s64 = ctx.r3.s64 + 248;
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x820ffab4
	if (ctx.cr6.eq) goto loc_820FFAB4;
	// cmplwi r30,0
	ctx.cr0.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq 0x820ffab4
	if (ctx.cr0.eq) goto loc_820FFAB4;
	// clrldi r27,r7,32
	ctx.r27.u64 = ctx.r7.u64 & 0xFFFFFFFF;
loc_820FFA68:
	// lwz r31,24(r4)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// addi r11,r30,-92
	ctx.r11.s64 = ctx.r30.s64 + -92;
	// addi r31,r31,13
	ctx.r31.s64 = ctx.r31.s64 + 13;
	// rlwinm r31,r31,3,0,28
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// ldx r29,r31,r11
	ctx.r29.u64 = REX_LOAD_U64(ctx.r31.u32 + ctx.r11.u32);
	// add r29,r27,r29
	ctx.r29.u64 = ctx.r27.u64 + ctx.r29.u64;
	// stdx r29,r31,r11
	REX_STORE_U64(ctx.r31.u32 + ctx.r11.u32, ctx.r29.u64);
	// lwz r31,24(r4)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// addi r31,r31,66
	ctx.r31.s64 = ctx.r31.s64 + 66;
	// rlwinm r31,r31,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r31,r11
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stwx r29,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r29.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x820ffab4
	if (ctx.cr6.eq) goto loc_820FFAB4;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x820ffa68
	if (!ctx.cr0.eq) goto loc_820FFA68;
loc_820FFAB4:
	// rlwinm. r11,r8,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820ffb04
	if (ctx.cr0.eq) goto loc_820FFB04;
	// lwz r11,720(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 720);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820ffb00
	if (!ctx.cr0.eq) goto loc_820FFB00;
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820ffae8
	if (ctx.cr6.eq) goto loc_820FFAE8;
	// lwz r11,24(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 24);
	// lwz r10,100(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// slw r11,r26,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r26.u32 << (ctx.r11.u8 & 0x3F));
	// b 0x820ffaec
	goto loc_820FFAEC;
loc_820FFAE8:
	// li r11,240
	ctx.r11.s64 = 240;
loc_820FFAEC:
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r5,396(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 396);
	// li r10,5
	ctx.r10.s64 = 5;
	// stb r11,100(r1)
	REX_STORE_U8(ctx.r1.u32 + 100, ctx.r11.u8);
loc_820FFB00:
	// rlwinm r8,r8,0,30,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
loc_820FFB04:
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// stb r26,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r26.u8);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// bl 0x820ff3a8
	ctx.lr = 0x820FFB20;
	sub_820FF3A8(ctx, base);
	// b 0x820ffb2c
	goto loc_820FFB2C;
loc_820FFB24:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1609
	ctx.r3.u64 = ctx.r3.u64 | 1609;
loc_820FFB2C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
