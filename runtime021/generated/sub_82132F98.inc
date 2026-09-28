DEFINE_REX_FUNC(sub_82132F98) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lwz r10,3252(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 3252);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82132fbc
	if (!ctx.cr6.eq) goto loc_82132FBC;
	// lis r8,-32221
	ctx.r8.s64 = -2111635456;
	// li r10,-3
	ctx.r10.s64 = -3;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,3252(r11)
	REX_STORE_U32(ctx.r11.u32 + 3252, ctx.r9.u32);
	// stw r10,23768(r8)
	REX_STORE_U32(ctx.r8.u32 + 23768, ctx.r10.u32);
loc_82132FBC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
