DEFINE_REX_FUNC(sub_8209B9D0) {
	REX_FUNC_PROLOGUE();
	// lbz r11,102(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 102);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209b9f8
	if (!ctx.cr6.eq) goto loc_8209B9F8;
	// lis r10,-32234
	ctx.r10.s64 = -2112487424;
	// lbz r9,-28146(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + -28146);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
loc_8209B9F8:
	// lbz r11,101(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 101);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r4,r10,r3
	REX_STORE_U16(ctx.r10.u32 + ctx.r3.u32, ctx.r4.u16);
	// lbz r11,101(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 101);
	// add r9,r11,r3
	ctx.r9.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stb r5,68(r9)
	REX_STORE_U8(ctx.r9.u32 + 68, ctx.r5.u8);
	// lbz r11,101(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 101);
	// add r8,r11,r3
	ctx.r8.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stb r6,84(r8)
	REX_STORE_U8(ctx.r8.u32 + 84, ctx.r6.u8);
	// lbz r10,102(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 102);
	// lbz r11,101(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 101);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// clrlwi r5,r7,24
	ctx.r5.u64 = ctx.r7.u32 & 0xFF;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stb r5,101(r3)
	REX_STORE_U8(ctx.r3.u32 + 101, ctx.r5.u8);
	// cmplwi cr6,r5,16
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 16, ctx.xer);
	// stb r6,102(r3)
	REX_STORE_U8(ctx.r3.u32 + 102, ctx.r6.u8);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,101(r3)
	REX_STORE_U8(ctx.r3.u32 + 101, ctx.r11.u8);
	// blr 
	return;
}
