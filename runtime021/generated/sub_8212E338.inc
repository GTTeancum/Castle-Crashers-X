DEFINE_REX_FUNC(sub_8212E338) {
	REX_FUNC_PROLOGUE();
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// blt cr6,0x8212e364
	if (ctx.cr6.lt) goto loc_8212E364;
	// cmpwi cr6,r3,255
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 255, ctx.xer);
	// bgt cr6,0x8212e364
	if (ctx.cr6.gt) goto loc_8212E364;
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,32376(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32376);
	// lwz r11,200(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 200);
	// lhzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// and r3,r11,r4
	ctx.r3.u64 = ctx.r11.u64 & ctx.r4.u64;
	// blr 
	return;
loc_8212E364:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
