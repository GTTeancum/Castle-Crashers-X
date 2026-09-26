DEFINE_REX_FUNC(sub_82070AC8_post_init) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	(void)temp;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4096
	ctx.r6.s64 = 4096;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,256
	ctx.r4.s64 = 16777216;
	// lwz r11,-6656(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6656);
	// lwz r3,136(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// bl 0x8209bc98
	ctx.lr = 0x82070BC4;
	sub_8209BC98(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r4,r10,-9040
	ctx.r4.s64 = ctx.r10.s64 + -9040;
	// bl 0x82053a00
	ctx.lr = 0x82070BD4;
	sub_82053A00(ctx, base);
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r11,-6604(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6604);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r3,r11,212
	ctx.r3.s64 = ctx.r11.s64 + 212;
	// bl 0x820a9b58
	ctx.lr = 0x82070BEC;
	sub_820A9B58(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f31,9536(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r7,12(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82070C0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// Diagnostic continuation stop: next original instruction is the unresolved indirect dispatch result at lr=0x82070C0C.
	return;
}
