DEFINE_REX_FUNC(sub_8210BC48) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// b 0x820b6ca8
	sub_820B6CA8(ctx, base);
	return;
}
