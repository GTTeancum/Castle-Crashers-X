DEFINE_REX_FUNC(sub_820CB8B8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,23984(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 23984);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,23996(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 23996);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// li r10,544
	ctx.r10.s64 = 544;
loc_820CB8D8:
	// lwz r9,23984(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 23984);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r8,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r9,23996(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 23996);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x820cb8d8
	if (ctx.cr6.lt) goto loc_820CB8D8;
	// blr 
	return;
}
