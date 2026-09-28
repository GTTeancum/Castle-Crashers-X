DEFINE_REX_FUNC(sub_82120960) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,26
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 26, ctx.xer);
	// stw r4,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// bge cr6,0x82120978
	if (!ctx.cr6.lt) goto loc_82120978;
loc_82120970:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82120978:
	// lhz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r4.u32 + 0);
	// addi r9,r5,-2
	ctx.r9.s64 = ctx.r5.s64 + -2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82120970
	if (!ctx.cr6.eq) goto loc_82120970;
	// addi r10,r4,26
	ctx.r10.s64 = ctx.r4.s64 + 26;
	// addi r9,r5,-26
	ctx.r9.s64 = ctx.r5.s64 + -26;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// blr 
	return;
}
