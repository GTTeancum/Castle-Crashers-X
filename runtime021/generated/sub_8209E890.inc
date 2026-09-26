DEFINE_REX_FUNC(sub_8209E890) {
	REX_FUNC_PROLOGUE();
	// lhbrx r6,0,r3
	ctx.r6.u64 = __builtin_bswap16(REX_LOAD_U16(ctx.r3.u32));
	// addi r11,r3,2
	ctx.r11.s64 = ctx.r3.s64 + 2;
	// addi r8,r3,4
	ctx.r8.s64 = ctx.r3.s64 + 4;
	// addi r7,r3,6
	ctx.r7.s64 = ctx.r3.s64 + 6;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r6,0(r3)
	REX_STORE_U16(ctx.r3.u32 + 0, ctx.r6.u16);
	// lhbrx r5,0,r11
	ctx.r5.u64 = __builtin_bswap16(REX_LOAD_U16(ctx.r11.u32));
	// sth r5,2(r3)
	REX_STORE_U16(ctx.r3.u32 + 2, ctx.r5.u16);
	// lhbrx r4,0,r8
	ctx.r4.u64 = __builtin_bswap16(REX_LOAD_U16(ctx.r8.u32));
	// sth r4,4(r3)
	REX_STORE_U16(ctx.r3.u32 + 4, ctx.r4.u16);
	// lhbrx r11,0,r7
	ctx.r11.u64 = __builtin_bswap16(REX_LOAD_U16(ctx.r7.u32));
	// sth r11,6(r3)
	REX_STORE_U16(ctx.r3.u32 + 6, ctx.r11.u16);
	// lhbrx r8,0,r9
	ctx.r8.u64 = __builtin_bswap16(REX_LOAD_U16(ctx.r9.u32));
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// sth r8,8(r3)
	REX_STORE_U16(ctx.r3.u32 + 8, ctx.r8.u16);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
loc_8209E8D8:
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// addi r6,r11,8
	ctx.r6.s64 = ctx.r11.s64 + 8;
	// addi r5,r11,14
	ctx.r5.s64 = ctx.r11.s64 + 14;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwbrx r8,0,r8
	ctx.r8.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r8.u32));
	// stw r8,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r8.u32);
	// lwbrx r4,0,r11
	ctx.r4.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r11.u32));
	// stw r4,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// lwbrx r3,0,r7
	ctx.r3.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r7.u32));
	// stw r3,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// lwbrx r8,0,r6
	ctx.r8.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r6.u32));
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// lhbrx r7,0,r5
	ctx.r7.u64 = __builtin_bswap16(REX_LOAD_U16(ctx.r5.u32));
	// sth r7,14(r11)
	REX_STORE_U16(ctx.r11.u32 + 14, ctx.r7.u16);
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// lhz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// cmpw cr6,r10,r6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x8209e8d8
	if (ctx.cr6.lt) goto loc_8209E8D8;
	// blr 
	return;
}
