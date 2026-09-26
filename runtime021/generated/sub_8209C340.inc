DEFINE_REX_FUNC(sub_8209C340) {
	REX_FUNC_PROLOGUE();
	// lis r8,-32234
	ctx.r8.s64 = -2112487424;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r9,624
	ctx.r9.s64 = 624;
	// addi r10,r11,27136
	ctx.r10.s64 = ctx.r11.s64 + 27136;
	// stw r9,-23776(r8)
	REX_STORE_U32(ctx.r8.u32 + -23776, ctx.r9.u32);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// addi r11,r10,4
	ctx.r11.s64 = ctx.r10.s64 + 4;
	// ori r9,r9,3533
	ctx.r9.u64 = ctx.r9.u64 | 3533;
	// stw r3,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
loc_8209C364:
	// lwz r8,-4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// addi r7,r10,2496
	ctx.r7.s64 = ctx.r10.s64 + 2496;
	// mullw r6,r8,r9
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r6,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8209c364
	if (ctx.cr6.lt) goto loc_8209C364;
	// blr 
	return;
}
