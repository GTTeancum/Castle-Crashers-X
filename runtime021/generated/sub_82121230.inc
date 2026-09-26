DEFINE_REX_FUNC(sub_82121230) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lhz r10,328(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 328);
	// addi r10,r10,9
	ctx.r10.s64 = ctx.r10.s64 + 9;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stwx r9,r10,r11
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u32);
	// lwz r9,32(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// lhz r10,328(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 328);
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r9,76(r10)
	REX_STORE_U16(ctx.r10.u32 + 76, ctx.r9.u16);
	// lhz r10,328(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 328);
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r9,r10,78
	ctx.r9.s64 = ctx.r10.s64 + 78;
	// lhz r9,78(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 78);
	// rlwimi r9,r4,15,0,16
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 15) & 0xFFFF8000) | (ctx.r9.u64 & 0xFFFFFFFF00007FFF);
	// sth r9,78(r10)
	REX_STORE_U16(ctx.r10.u32 + 78, ctx.r9.u16);
	// lhz r10,328(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 328);
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r9,r10,78
	ctx.r9.s64 = ctx.r10.s64 + 78;
	// lhz r9,78(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 78);
	// rlwimi r9,r5,14,17,17
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 14) & 0x4000) | (ctx.r9.u64 & 0xFFFFFFFFFFFFBFFF);
	// sth r9,78(r10)
	REX_STORE_U16(ctx.r10.u32 + 78, ctx.r9.u16);
	// lhz r10,328(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 328);
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r9,r10,78
	ctx.r9.s64 = ctx.r10.s64 + 78;
	// lhz r9,78(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 78);
	// rlwimi r9,r6,13,18,18
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 13) & 0x2000) | (ctx.r9.u64 & 0xFFFFFFFFFFFFDFFF);
	// sth r9,78(r10)
	REX_STORE_U16(ctx.r10.u32 + 78, ctx.r9.u16);
	// lhz r3,328(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 328);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// sth r10,328(r11)
	REX_STORE_U16(ctx.r11.u32 + 328, ctx.r10.u16);
	// blr 
	return;
}
