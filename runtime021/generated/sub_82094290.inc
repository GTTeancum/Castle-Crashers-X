DEFINE_REX_FUNC(sub_82094290) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82094298;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r5,21
	ctx.r5.s64 = 21;
	// lwz r4,288(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// bl 0x82129a70
	ctx.lr = 0x820942B4;
	sub_82129A70(ctx, base);
	// addi r11,r31,248
	ctx.r11.s64 = ctx.r31.s64 + 248;
	// lbz r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// lbz r8,114(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 114);
	// addi r10,r1,113
	ctx.r10.s64 = ctx.r1.s64 + 113;
	// lbz r7,113(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 113);
	// lwz r6,116(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stb r8,113(r1)
	REX_STORE_U8(ctx.r1.u32 + 113, ctx.r8.u8);
	// stb r7,114(r1)
	REX_STORE_U8(ctx.r1.u32 + 114, ctx.r7.u8);
	// lbz r11,115(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 115);
	// stb r9,115(r1)
	REX_STORE_U8(ctx.r1.u32 + 115, ctx.r9.u8);
	// stb r11,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r11.u8);
	// lbz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r3,1(r10)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r5,2(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// stb r11,251(r31)
	REX_STORE_U8(ctx.r31.u32 + 251, ctx.r11.u8);
	// stb r5,250(r31)
	REX_STORE_U8(ctx.r31.u32 + 250, ctx.r5.u8);
	// stb r3,249(r31)
	REX_STORE_U8(ctx.r31.u32 + 249, ctx.r3.u8);
	// stb r4,248(r31)
	REX_STORE_U8(ctx.r31.u32 + 248, ctx.r4.u8);
	// stw r6,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r6.u32);
	// lbz r11,250(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 250);
	// cmplwi cr6,r11,67
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 67, ctx.xer);
	// bne cr6,0x82094328
	if (!ctx.cr6.eq) goto loc_82094328;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-2848
	ctx.r3.s64 = ctx.r11.s64 + -2848;
	// bl 0x8208c5d8
	ctx.lr = 0x82094318;
	sub_8208C5D8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_82094328:
	// addi r3,r31,256
	ctx.r3.s64 = ctx.r31.s64 + 256;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// bl 0x82093848
	ctx.lr = 0x82094334;
	sub_82093848(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r29,r31,36
	ctx.r29.s64 = ctx.r31.s64 + 36;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f31,18236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18236);
	ctx.f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82085d70
	ctx.lr = 0x82094350;
	sub_82085D70(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82085e18
	ctx.lr = 0x8209435C;
	sub_82085E18(ctx, base);
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// addi r10,r1,114
	ctx.r10.s64 = ctx.r1.s64 + 114;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r1,113
	ctx.r8.s64 = ctx.r1.s64 + 113;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// lbzx r4,r11,r10
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// lfs f0,9572(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9572);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lbzx r9,r11,r8
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r8.u32);
	// addi r11,r31,276
	ctx.r11.s64 = ctx.r31.s64 + 276;
	// lfs f13,9576(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 9576);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r30,12
	ctx.r3.s64 = ctx.r30.s64 + 12;
	// lbz r8,1(r7)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// stw r9,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r9.u32);
	// lwz r6,264(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r5,256(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// neg r11,r6
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r6.u64);
	// neg r9,r5
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// extsw r6,r11
	ctx.r6.s64 = ctx.r11.s32;
	// extsw r5,r9
	ctx.r5.s64 = ctx.r9.s32;
	// std r6,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r5,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f11,96(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmuls f5,f7,f0
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmuls f3,f5,f13
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// stfs f3,72(r31)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// fmuls f4,f6,f13
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// stfs f4,68(r31)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stb r4,276(r31)
	REX_STORE_U8(ctx.r31.u32 + 276, ctx.r4.u8);
	// stb r8,277(r31)
	REX_STORE_U8(ctx.r31.u32 + 277, ctx.r8.u8);
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// stb r7,278(r31)
	REX_STORE_U8(ctx.r31.u32 + 278, ctx.r7.u8);
	// stw r10,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r10.u32);
	// stw r4,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r4.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
