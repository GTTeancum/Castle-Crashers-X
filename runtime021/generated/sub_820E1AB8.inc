DEFINE_REX_FUNC(sub_820E1AB8) {
	REX_FUNC_PROLOGUE();
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// addi r4,r11,8
	ctx.r4.s64 = ctx.r11.s64 + 8;
	// addi r3,r10,12
	ctx.r3.s64 = ctx.r10.s64 + 12;
	// lwz r9,72(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// stw r9,172(r10)
	REX_STORE_U32(ctx.r10.u32 + 172, ctx.r9.u32);
	// lwz r8,76(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// stw r8,176(r10)
	REX_STORE_U32(ctx.r10.u32 + 176, ctx.r8.u32);
	// lbz r6,69(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 69);
	// lbz r5,68(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 68);
	// b 0x820e7168
	sub_820E7168(ctx, base);
	return;
}
