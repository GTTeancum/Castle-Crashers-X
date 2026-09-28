DEFINE_REX_FUNC(sub_82149DB0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// li r10,255
	ctx.r10.s64 = 255;
	// addi r11,r11,-16888
	ctx.r11.s64 = ctx.r11.s64 + -16888;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82149DC0:
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stb r9,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r9.u8);
	// addi r11,r11,68
	ctx.r11.s64 = ctx.r11.s64 + 68;
	// bge 0x82149dc0
	if (!ctx.cr0.lt) goto loc_82149DC0;
	// blr 
	return;
}
