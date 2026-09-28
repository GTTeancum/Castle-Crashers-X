DEFINE_REX_FUNC(sub_82055120) {
	REX_FUNC_PROLOGUE();
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// lhz r4,390(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 390);
	// b 0x82053bc8
	sub_82053BC8(ctx, base);
	return;
}
