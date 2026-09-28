DEFINE_REX_FUNC(sub_820CC6D8) {
	REX_FUNC_PROLOGUE();
	// addi r11,r4,512
	ctx.r11.s64 = ctx.r4.s64 + 512;
	// addi r10,r3,2
	ctx.r10.s64 = ctx.r3.s64 + 2;
	// subf r6,r3,r4
	ctx.r6.u64 = ctx.r4.u64 - ctx.r3.u64;
	// li r9,128
	ctx.r9.s64 = 128;
loc_820CC6E8:
	// lhz r8,-512(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + -512);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// sth r8,-2(r10)
	REX_STORE_U16(ctx.r10.u32 + -2, ctx.r8.u16);
	// lhz r7,-512(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + -512);
	// lhzx r8,r6,r10
	ctx.r8.u64 = REX_LOAD_U16(ctx.r6.u32 + ctx.r10.u32);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// sth r8,0(r10)
	REX_STORE_U16(ctx.r10.u32 + 0, ctx.r8.u16);
	// lhz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// sth r8,510(r10)
	REX_STORE_U16(ctx.r10.u32 + 510, ctx.r8.u16);
	// lhz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// sth r8,512(r10)
	REX_STORE_U16(ctx.r10.u32 + 512, ctx.r8.u16);
	// lhz r8,512(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 512);
	// sth r8,1022(r10)
	REX_STORE_U16(ctx.r10.u32 + 1022, ctx.r8.u16);
	// lhz r8,514(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 514);
	// lhz r7,512(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 512);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// sth r8,1024(r10)
	REX_STORE_U16(ctx.r10.u32 + 1024, ctx.r8.u16);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x820cc6e8
	if (!ctx.cr0.eq) goto loc_820CC6E8;
	// blr 
	return;
}
