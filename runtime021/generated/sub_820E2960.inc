DEFINE_REX_FUNC(sub_820E2960) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// bne cr6,0x820e2970
	if (!ctx.cr6.eq) goto loc_820E2970;
	// li r3,0
	ctx.r3.s64 = 0;
loc_820E2970:
	// b 0x820e2838
	sub_820E2838(ctx, base);
	return;
}
