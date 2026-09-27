DEFINE_REX_FUNC(sub_820E1D00) {
	REX_FUNC_PROLOGUE();
	// lbz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x820e1d10
	if (ctx.cr6.gt) goto loc_820E1D10;
	// b 0x820ebaf0
	sub_820EBAF0(ctx, base);
	return;
loc_820E1D10:
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x820e1d1c
	if (!ctx.cr6.eq) goto loc_820E1D1C;
	// b 0x820ea9c8
	sub_820EA9C8(ctx, base);
	return;
loc_820E1D1C:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16385
	ctx.r3.u64 = ctx.r3.u64 | 16385;
	// blr 
	return;
}
