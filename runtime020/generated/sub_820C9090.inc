DEFINE_REX_FUNC(sub_820C9090) {
	REX_FUNC_PROLOGUE();
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r3,1024
	ctx.r11.s64 = ctx.r3.s64 + 1024;
loc_820C9098:
	// li r9,255
	ctx.r9.s64 = 255;
	// lis r8,3
	ctx.r8.s64 = 196608;
	// divwu r9,r10,r9
	ctx.r9.u64 = uint32_t(ctx.r9.u32 ? ctx.r10.u32 / ctx.r9.u32 : 0);
	// ori r8,r8,65280
	ctx.r8.u64 = ctx.r8.u64 | 65280;
	// rlwinm r9,r9,6,16,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFC0;
	// addi r10,r10,1023
	ctx.r10.s64 = ctx.r10.s64 + 1023;
	// sth r9,-1024(r11)
	REX_STORE_U16(ctx.r11.u32 + -1024, ctx.r9.u16);
	// sth r9,-512(r11)
	REX_STORE_U16(ctx.r11.u32 + -512, ctx.r9.u16);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// sth r9,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r9.u16);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// blt cr6,0x820c9098
	if (ctx.cr6.lt) goto loc_820C9098;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x820c8d78
	sub_820C8D78(ctx, base);
	return;
}
