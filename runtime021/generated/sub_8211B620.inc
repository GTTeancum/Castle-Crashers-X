DEFINE_REX_FUNC(sub_8211B620) {
	REX_FUNC_PROLOGUE();
	// lwz r11,1148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1148);
	// lwz r10,424(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 424);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r4,428(r3)
	REX_STORE_U32(ctx.r3.u32 + 428, ctx.r4.u32);
	// xor r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r4.u64;
	// beq 0x8211b644
	if (ctx.cr0.eq) goto loc_8211B644;
	// rlwinm r11,r10,16,16,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// b 0x8211b64c
	goto loc_8211B64C;
loc_8211B644:
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwinm r10,r10,16,16,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF;
loc_8211B64C:
	// clrldi r9,r10,48
	ctx.r9.u64 = ctx.r10.u64 & 0xFFFF;
	// addis r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 65536;
	// oris r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 | 65536;
	// rlwinm r7,r10,0,16,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFF00;
	// std r9,616(r3)
	REX_STORE_U64(ctx.r3.u32 + 616, ctx.r9.u64);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// sth r10,872(r3)
	REX_STORE_U16(ctx.r3.u32 + 872, ctx.r10.u16);
	// sth r10,874(r3)
	REX_STORE_U16(ctx.r3.u32 + 874, ctx.r10.u16);
	// sth r7,876(r3)
	REX_STORE_U16(ctx.r3.u32 + 876, ctx.r7.u16);
	// sth r11,1032(r3)
	REX_STORE_U16(ctx.r3.u32 + 1032, ctx.r11.u16);
	// sth r11,1046(r3)
	REX_STORE_U16(ctx.r3.u32 + 1046, ctx.r11.u16);
	// sth r11,1048(r3)
	REX_STORE_U16(ctx.r3.u32 + 1048, ctx.r11.u16);
	// sth r11,1050(r3)
	REX_STORE_U16(ctx.r3.u32 + 1050, ctx.r11.u16);
	// sth r11,974(r3)
	REX_STORE_U16(ctx.r3.u32 + 974, ctx.r11.u16);
	// sth r11,976(r3)
	REX_STORE_U16(ctx.r3.u32 + 976, ctx.r11.u16);
	// sth r8,978(r3)
	REX_STORE_U16(ctx.r3.u32 + 978, ctx.r8.u16);
	// blr 
	return;
}
