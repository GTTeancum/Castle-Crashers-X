DEFINE_REX_FUNC(sub_82109570) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// ori r11,r11,996
	ctx.r11.u64 = ctx.r11.u64 | 996;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x8210958c
	if (ctx.cr6.eq) goto loc_8210958C;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8210958C:
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r3,r11,1
	ctx.r3.u64 = ctx.r11.u64 ^ 1;
	// blr 
	return;
}
