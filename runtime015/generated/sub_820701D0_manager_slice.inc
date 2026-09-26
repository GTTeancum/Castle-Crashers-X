// Diagnostic mid-function entry. The instruction translation below is copied
// verbatim from sealed sub_820701D0 [0x82070434,0x820704C4). It is not claimed
// to be an original function boundary.
static void sub_820701D0_manager_slice(Context &ctx, Machine &base) {
  REX_FUNC_PROLOGUE();
  PPCRegister temp{};
	// bl 0x820b5eb8
	ctx.lr = 0x82070438;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,140
	ctx.r4.s64 = 140;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82070448;
	sub_8209BDD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820704b8
	if (ctx.cr6.eq) goto loc_820704B8;
	// stb r28,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// addi r30,r31,76
	ctx.r30.s64 = ctx.r31.s64 + 76;
	// stb r28,1(r31)
	REX_STORE_U8(ctx.r31.u32 + 1, ctx.r28.u8);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82097650
	ctx.lr = 0x82070468;
	sub_82097650(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r28,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r28.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r28.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lfs f0,18080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18080);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 100, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 104, temp.u32);
	// stfs f0,108(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// stw r28,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r28.u32);
	// stw r28,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r28.u32);
	// stw r28,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r28.u32);
	// stw r28,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r28.u32);
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// bl 0x82097720
	ctx.lr = 0x820704A8;
	sub_82097720(ctx, base);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// stw r31,-6612(r10)
	REX_STORE_U32(ctx.r10.u32 + -6612, ctx.r31.u32);
	// b 0x820704c4
	goto loc_820704C4;
loc_820704B8:
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r11,-6612(r10)
	REX_STORE_U32(ctx.r10.u32 + -6612, ctx.r11.u32);
loc_820704C4:
  return;
}
