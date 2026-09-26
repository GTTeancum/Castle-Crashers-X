DEFINE_REX_FUNC(sub_82125A88) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82125A90;
	__savegprlr_28(ctx, base);
	// rlwinm. r30,r10,0,0,27
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// li r31,0
	ctx.r31.s64 = 0;
	// bne 0x82125aa8
	if (!ctx.cr0.eq) goto loc_82125AA8;
	// clrlwi r31,r10,24
	ctx.r31.u64 = ctx.r10.u32 & 0xFF;
	// b 0x82125af8
	goto loc_82125AF8;
loc_82125AA8:
	// cmplwi cr6,r10,16383
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16383, ctx.xer);
	// ble cr6,0x82125ad8
	if (!ctx.cr6.gt) goto loc_82125AD8;
	// li r30,192
	ctx.r30.s64 = 192;
	// rlwinm r29,r10,16,24,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFF;
	// rlwimi r30,r10,8,26,31
	ctx.r30.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0x3F) | (ctx.r30.u64 & 0xFFFFFFFFFFFFFFC0);
	// rlwinm r28,r10,24,24,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r29,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r29.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r28,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// b 0x82125aec
	goto loc_82125AEC;
loc_82125AD8:
	// cmplwi cr6,r10,127
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 127, ctx.xer);
	// ble cr6,0x82125af0
	if (!ctx.cr6.gt) goto loc_82125AF0;
	// li r30,128
	ctx.r30.s64 = 128;
	// rlwimi r30,r10,24,25,31
	ctx.r30.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0x7F) | (ctx.r30.u64 & 0xFFFFFFFFFFFFFF80);
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
loc_82125AEC:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82125AF0:
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82125AF8:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x82125b08
	if (ctx.cr6.eq) goto loc_82125B08;
	// clrlwi r10,r31,24
	ctx.r10.u64 = ctx.r31.u32 & 0xFF;
	// ori r31,r10,64
	ctx.r31.u64 = ctx.r10.u64 | 64;
loc_82125B08:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x82125b38
	if (ctx.cr6.eq) goto loc_82125B38;
	// clrlwi r10,r31,24
	ctx.r10.u64 = ctx.r31.u32 & 0xFF;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ori r31,r10,32
	ctx.r31.u64 = ctx.r10.u64 | 32;
	// bne cr6,0x82125b38
	if (!ctx.cr6.eq) goto loc_82125B38;
	// lhz r10,86(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 86);
	// rlwinm r7,r10,24,8,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// stb r7,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r7.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82125B38:
	// clrlwi. r10,r9,31
	ctx.r10.u64 = ctx.r9.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82125b54
	if (!ctx.cr0.eq) goto loc_82125B54;
	// cmplwi cr6,r9,510
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 510, ctx.xer);
	// bgt cr6,0x82125b54
	if (ctx.cr6.gt) goto loc_82125B54;
	// rlwinm r10,r9,31,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0xFF;
loc_82125B4C:
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// b 0x82125b7c
	goto loc_82125B7C;
loc_82125B54:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82125b64
	if (ctx.cr6.eq) goto loc_82125B64;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82125b4c
	goto loc_82125B4C;
loc_82125B64:
	// rlwinm r10,r9,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r31,24
	ctx.r10.u64 = ctx.r31.u32 & 0xFF;
	// ori r31,r10,16
	ctx.r31.u64 = ctx.r10.u64 | 16;
	// stb r9,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
loc_82125B7C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r4,128
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 128, ctx.xer);
	// bne cr6,0x82125b94
	if (!ctx.cr6.eq) goto loc_82125B94;
	// clrlwi r10,r31,24
	ctx.r10.u64 = ctx.r31.u32 & 0xFF;
	// ori r31,r10,128
	ctx.r31.u64 = ctx.r10.u64 | 128;
	// b 0x82125b9c
	goto loc_82125B9C;
loc_82125B94:
	// stb r4,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r4.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82125B9C:
	// stb r31,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r31.u8);
	// subf r3,r3,r11
	ctx.r3.u64 = ctx.r11.u64 - ctx.r3.u64;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
