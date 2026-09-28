DEFINE_REX_FUNC(sub_8206D0D8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r9,10(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// lwz r3,-6624(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -6624);
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// b 0x82077310
	sub_82077310(ctx, base);
	return;
}
