DEFINE_REX_FUNC(sub_82122D88) {
	REX_FUNC_PROLOGUE();
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r11,r3,48
	ctx.r11.s64 = ctx.r3.s64 + 48;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82122da8
	if (!ctx.cr6.eq) goto loc_82122DA8;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82122DA8:
	// addi r3,r10,-4
	ctx.r3.s64 = ctx.r10.s64 + -4;
	// b 0x82126860
	sub_82126860(ctx, base);
	return;
}
