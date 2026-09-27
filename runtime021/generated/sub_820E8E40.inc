DEFINE_REX_FUNC(sub_820E8E40) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 68);
	// lbz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 12);
	// mulli r10,r10,120
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(120));
	// mulli r11,r9,88
	ctx.r11.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(88));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r8,r11,312
	ctx.r8.s64 = ctx.r11.s64 + 312;
	// stw r8,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}
