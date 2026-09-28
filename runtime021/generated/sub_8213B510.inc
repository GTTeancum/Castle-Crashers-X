DEFINE_REX_FUNC(sub_8213B510) {
	REX_FUNC_PROLOGUE();
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8213b520
	if (!ctx.cr6.eq) goto loc_8213B520;
	// b 0x8213b320
	sub_8213B320(ctx, base);
	return;
loc_8213B520:
	// b 0x8213b160
	sub_8213B160(ctx, base);
	return;
}
