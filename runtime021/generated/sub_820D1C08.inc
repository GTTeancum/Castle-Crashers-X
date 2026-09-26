DEFINE_REX_FUNC(sub_820D1C08) {
	REX_FUNC_PROLOGUE();
	// addi r11,r3,23380
	ctx.r11.s64 = ctx.r3.s64 + 23380;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r10,41
	ctx.r10.s64 = 41;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820D1C18:
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x820d1c18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D1C18;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}
