DEFINE_REX_FUNC(sub_82058440) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r9,48(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// lhz r10,8(r9)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r9.u32 + 8);
	// lwz r11,-6628(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -6628);
	// addi r7,r10,-5
	ctx.r7.s64 = ctx.r10.s64 + -5;
	// lhz r6,10(r9)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r9.u32 + 10);
	// srawi r5,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 2;
	// extsh r3,r6
	ctx.r3.s64 = ctx.r6.s16;
	// addze r4,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r4.s64 = temp.s64;
	// mulli r10,r4,56
	ctx.r10.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(56));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ld r4,320(r11)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r11.u32 + 320);
	// b 0x820b5d40
	sub_820B5D40(ctx, base);
	return;
}
