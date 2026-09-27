DEFINE_REX_FUNC(sub_8207BF88) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,156(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r11,8248(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8248);
	// addi r8,r11,1998
	ctx.r8.s64 = ctx.r11.s64 + 1998;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r9
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lbz r5,140(r6)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r6.u32 + 140);
	// ori r11,r5,4
	ctx.r11.u64 = ctx.r5.u64 | 4;
	// stb r11,140(r6)
	REX_STORE_U8(ctx.r6.u32 + 140, ctx.r11.u8);
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,156(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r11,8248(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 8248);
	// addi r7,r11,1998
	ctx.r7.s64 = ctx.r11.s64 + 1998;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r8
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// lbz r4,140(r5)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r5.u32 + 140);
	// clrlwi r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	// rlwinm r11,r11,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stb r11,140(r5)
	REX_STORE_U8(ctx.r5.u32 + 140, ctx.r11.u8);
	// blr 
	return;
}
