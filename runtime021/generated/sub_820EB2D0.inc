DEFINE_REX_FUNC(sub_820EB2D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820EB2D8;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// addi r29,r31,4
	ctx.r29.s64 = ctx.r31.s64 + 4;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820e1d28
	ctx.lr = 0x820EB2F4;
	sub_820E1D28(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r30,r31,184
	ctx.r30.s64 = ctx.r31.s64 + 184;
	// addi r8,r11,-27264
	ctx.r8.s64 = ctx.r11.s64 + -27264;
	// addi r7,r10,-27304
	ctx.r7.s64 = ctx.r10.s64 + -27304;
	// addi r6,r9,-27400
	ctx.r6.s64 = ctx.r9.s64 + -27400;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// li r5,76
	ctx.r5.s64 = 76;
	// stw r7,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r6,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82129fa0
	ctx.lr = 0x820EB32C;
	sub_82129FA0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// stw r11,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r11.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r11,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820e1ab8
	ctx.lr = 0x820EB348;
	sub_820E1AB8(ctx, base);
	// lis r4,0
	ctx.r4.s64 = 0;
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// lbz r8,69(r28)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r28.u32 + 69);
	// ori r11,r4,48000
	ctx.r11.u64 = ctx.r4.u64 | 48000;
	// lbz r6,56(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r10,r3,-27144
	ctx.r10.s64 = ctx.r3.s64 + -27144;
	// stw r8,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r8.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r4,60(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r8,264(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// ori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 | 1;
	// std r4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lbz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 52);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stb r6,197(r31)
	REX_STORE_U8(ctx.r31.u32 + 197, ctx.r6.u8);
	// rotlwi r6,r7,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stb r3,196(r31)
	REX_STORE_U8(ctx.r31.u32 + 196, ctx.r3.u8);
	// stw r7,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r7.u32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fctidz f9,f10
	ctx.f9.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfiwx f9,r30,r5
	REX_STORE_U32(ctx.r30.u32 + ctx.r5.u32, ctx.f9.u32);
	// ori r5,r6,2
	ctx.r5.u64 = ctx.r6.u64 | 2;
	// stw r11,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r11.u32);
	// stw r5,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r5.u32);
	// lbz r4,197(r31)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r31.u32 + 197);
	// lbz r3,196(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 196);
	// rotlwi r11,r3,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 2);
	// lwzx r10,r11,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// mullw r8,r10,r4
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// sth r9,110(r31)
	REX_STORE_U16(ctx.r31.u32 + 110, ctx.r9.u16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r8,108(r31)
	REX_STORE_U16(ctx.r31.u32 + 108, ctx.r8.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
