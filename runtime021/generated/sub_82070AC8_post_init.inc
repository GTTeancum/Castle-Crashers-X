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
	// lis r6,-32218
	ctx.r6.s64 = -2111438848;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r8,-32221
	ctx.r8.s64 = -2111635456;
	// lwz r3,-6604(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6604);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r27,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,-6596(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + -6596);
	// li r6,140
	ctx.r6.s64 = 140;
	// lfs f2,9540(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 9540);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// lbz r7,9(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 9);
	// subfic r5,r7,0
	ctx.xer.ca = ctx.r7.u32 <= 0;
	ctx.r5.u64 = static_cast<uint64_t>(0) - ctx.r7.u64;
	// subfe r11,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r5.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r11,0,25,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x78;
	// rlwinm r11,r11,0,28,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// lwz r8,-26316(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + -26316);
	// addi r5,r11,51
	ctx.r5.s64 = ctx.r11.s64 + 51;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x8209d028
	ctx.lr = 0x82070C60;
	sub_8209D028(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82070C78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// Diagnostic continuation stop: next original instruction is the unresolved indirect dispatch result at lr=0x82070C78.
	return;
}
