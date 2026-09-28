DEFINE_REX_FUNC(sub_821299D0) {
	REX_FUNC_PROLOGUE();
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r8,-32234
	ctx.r8.s64 = -2112487424;
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// addi r30,r8,-32536
	ctx.r30.s64 = ctx.r8.s64 + -32536;
	// addi r11,r11,720
	ctx.r11.s64 = ctx.r11.s64 + 720;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// stw r11,-32536(r8)
	REX_STORE_U32(ctx.r8.u32 + -32536, ctx.r11.u32);
	// lis r31,-32237
	ctx.r31.s64 = -2112684032;
	// addi r10,r10,-2400
	ctx.r10.s64 = ctx.r10.s64 + -2400;
	// addi r9,r9,-2416
	ctx.r9.s64 = ctx.r9.s64 + -2416;
	// addi r11,r31,-2408
	ctx.r11.s64 = ctx.r31.s64 + -2408;
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// lis r3,-32237
	ctx.r3.s64 = -2112684032;
	// stw r9,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r9.u32);
	// lis r4,-32237
	ctx.r4.s64 = -2112684032;
	// stw r11,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// lis r5,-32237
	ctx.r5.s64 = -2112684032;
	// addi r10,r3,-2544
	ctx.r10.s64 = ctx.r3.s64 + -2544;
	// addi r9,r4,720
	ctx.r9.s64 = ctx.r4.s64 + 720;
	// addi r11,r5,640
	ctx.r11.s64 = ctx.r5.s64 + 640;
	// stw r10,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r10.u32);
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// stw r9,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r9.u32);
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// stw r11,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// lis r8,-32237
	ctx.r8.s64 = -2112684032;
	// addi r10,r6,-2512
	ctx.r10.s64 = ctx.r6.s64 + -2512;
	// addi r9,r7,-2728
	ctx.r9.s64 = ctx.r7.s64 + -2728;
	// addi r11,r8,-2888
	ctx.r11.s64 = ctx.r8.s64 + -2888;
	// stw r10,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r10.u32);
	// stw r9,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r9.u32);
	// stw r11,36(r30)
	REX_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
