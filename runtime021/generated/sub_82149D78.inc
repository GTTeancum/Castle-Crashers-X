DEFINE_REX_FUNC(sub_82149D78) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// li r9,255
	ctx.r9.s64 = 255;
	// addi r11,r11,-22008
	ctx.r11.s64 = ctx.r11.s64 + -22008;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
loc_82149D8C:
	// stw r10,-12(r11)
	REX_STORE_U32(ctx.r11.u32 + -12, ctx.r10.u32);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r10.u32);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// bge 0x82149d8c
	if (!ctx.cr0.lt) goto loc_82149D8C;
	// blr 
	return;
}
