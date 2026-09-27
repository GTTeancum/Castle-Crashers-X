DEFINE_REX_FUNC(sub_82092B78) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,10344(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 10344);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lbz r8,1(r4)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// li r7,255
	ctx.r7.s64 = 255;
	// lbz r6,2(r4)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// stb r7,103(r11)
	REX_STORE_U8(ctx.r11.u32 + 103, ctx.r7.u8);
	// stb r10,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// stb r8,1(r9)
	REX_STORE_U8(ctx.r9.u32 + 1, ctx.r8.u8);
	// stb r6,2(r9)
	REX_STORE_U8(ctx.r9.u32 + 2, ctx.r6.u8);
	// lbz r4,-14(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + -14);
	// lbz r10,-15(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + -15);
	// lbz r5,-16(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -16);
	// stb r5,102(r11)
	REX_STORE_U8(ctx.r11.u32 + 102, ctx.r5.u8);
	// stb r10,101(r11)
	REX_STORE_U8(ctx.r11.u32 + 101, ctx.r10.u8);
	// stb r4,100(r11)
	REX_STORE_U8(ctx.r11.u32 + 100, ctx.r4.u8);
	// blr 
	return;
}
