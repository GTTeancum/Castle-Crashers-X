DEFINE_REX_FUNC(sub_82063730) {
	REX_FUNC_PROLOGUE();
	// lhz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82063750
	if (ctx.cr6.lt) goto loc_82063750;
	// beq cr6,0x8206374c
	if (ctx.cr6.eq) goto loc_8206374C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// b 0x82063dc8
	sub_82063DC8(ctx, base);
	return;
loc_8206374C:
	// b 0x82063f18
	sub_82063F18(ctx, base);
	return;
loc_82063750:
	// b 0x82063c00
	sub_82063C00(ctx, base);
	return;
}
