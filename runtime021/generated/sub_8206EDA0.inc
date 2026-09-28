DEFINE_REX_FUNC(sub_8206EDA0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,64(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r4,15
	ctx.r4.s64 = 15;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// sth r10,60(r3)
	REX_STORE_U16(ctx.r3.u32 + 60, ctx.r10.u16);
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// stw r8,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r8.u32);
	// b 0x82053bc8
	sub_82053BC8(ctx, base);
	return;
}
