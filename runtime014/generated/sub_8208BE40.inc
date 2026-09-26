DEFINE_REX_FUNC(sub_8208BE40) {
	REX_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,1(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,2(r3)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r7,3(r3)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r3,r7
	ctx.r11.u64 = ctx.r3.u64 | ctx.r7.u64;
	// stw r11,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r11.u32);
	// lbz r3,-15(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + -15);
	// lbz r6,-14(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + -14);
	// lbz r5,-13(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -13);
	// lbz r4,-16(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + -16);
	// xor r11,r4,r5
	ctx.r11.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// xor r10,r3,r6
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r6.u64;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// xor r7,r9,r5
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r5.u64;
	// xor r6,r8,r6
	ctx.r6.u64 = ctx.r8.u64 ^ ctx.r6.u64;
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// xor r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 ^ ctx.r9.u64;
	// stb r11,-13(r1)
	REX_STORE_U8(ctx.r1.u32 + -13, ctx.r11.u8);
	// xor r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 ^ ctx.r8.u64;
	// stb r10,-14(r1)
	REX_STORE_U8(ctx.r1.u32 + -14, ctx.r10.u8);
	// stb r5,-16(r1)
	REX_STORE_U8(ctx.r1.u32 + -16, ctx.r5.u8);
	// stb r4,-15(r1)
	REX_STORE_U8(ctx.r1.u32 + -15, ctx.r4.u8);
	// lwz r3,-16(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}
