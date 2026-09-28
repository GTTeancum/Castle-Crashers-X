DEFINE_REX_FUNC(sub_821220F8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82122110
	if (ctx.cr6.gt) goto loc_82122110;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82122110:
	// b 0x82122068
	sub_82122068(ctx, base);
	return;
}
