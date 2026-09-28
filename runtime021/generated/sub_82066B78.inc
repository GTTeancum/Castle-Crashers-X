DEFINE_REX_FUNC(sub_82066B78) {
	REX_FUNC_PROLOGUE();
	// lwz r11,364(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r11,424(r3)
	REX_STORE_U8(ctx.r3.u32 + 424, ctx.r11.u8);
	// stb r10,340(r3)
	REX_STORE_U8(ctx.r3.u32 + 340, ctx.r10.u8);
	// stw r9,344(r3)
	REX_STORE_U32(ctx.r3.u32 + 344, ctx.r9.u32);
	// blr 
	return;
}
