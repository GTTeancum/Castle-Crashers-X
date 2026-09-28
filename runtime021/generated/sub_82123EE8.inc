DEFINE_REX_FUNC(sub_82123EE8) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// extsh r9,r4
	ctx.r9.s64 = ctx.r4.s16;
	// lhz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 36);
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// extsh. r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble 0x82123f34
	if (!ctx.cr0.gt) goto loc_82123F34;
	// lhz r10,38(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 38);
	// rlwinm. r8,r10,0,0,16
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF8000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x82123f24
	if (!ctx.cr0.eq) goto loc_82123F24;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// sth r4,32(r11)
	REX_STORE_U16(ctx.r11.u32 + 32, ctx.r4.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 32768;
	// sth r9,38(r11)
	REX_STORE_U16(ctx.r11.u32 + 38, ctx.r9.u16);
	// b 0x82123f5c
	goto loc_82123F5C;
loc_82123F24:
	// lhz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 32);
	// subf r8,r10,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r10.u64;
	// extsh. r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge 0x82123f3c
	if (!ctx.cr0.lt) goto loc_82123F3C;
loc_82123F34:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82123F3C:
	// lhz r8,34(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 34);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r7,r4,16
	ctx.r7.u64 = ctx.r4.u32 & 0xFFFF;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// subf r10,r10,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r10.u64;
	// extsh. r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ble 0x82123f60
	if (!ctx.cr0.gt) goto loc_82123F60;
loc_82123F5C:
	// sth r4,34(r11)
	REX_STORE_U16(ctx.r11.u32 + 34, ctx.r4.u16);
loc_82123F60:
	// rlwinm r7,r10,29,19,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFF;
	// rlwinm r9,r10,29,19,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFF;
	// clrlwi r6,r10,29
	ctx.r6.u64 = ctx.r10.u32 & 0x7;
	// li r8,1
	ctx.r8.s64 = 1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// lbzx r7,r7,r11
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r11.u32);
	// slw r6,r8,r6
	ctx.r6.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r6.u8 & 0x3F));
	// slw r10,r8,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// lbzx r5,r9,r11
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r11.u32);
	// and r8,r6,r7
	ctx.r8.u64 = ctx.r6.u64 & ctx.r7.u64;
	// or r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 | ctx.r5.u64;
	// cntlzw r8,r8
	ctx.r8.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// stbx r10,r9,r11
	REX_STORE_U8(ctx.r9.u32 + ctx.r11.u32, ctx.r10.u8);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blr 
	return;
}
