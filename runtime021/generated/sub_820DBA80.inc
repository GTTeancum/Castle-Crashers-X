DEFINE_REX_FUNC(sub_820DBA80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lbz r10,268(r13)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r13.u32 + 268);
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// lwz r11,22960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 22960);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,12(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// blr 
	return;
}
