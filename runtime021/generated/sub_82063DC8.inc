DEFINE_REX_FUNC(sub_82063DC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82063DD0;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,192
	ctx.r11.s64 = 192;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// lis r27,-32218
	ctx.r27.s64 = -2111438848;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,-6624(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// lhz r9,10(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// extsh r30,r9
	ctx.r30.s64 = ctx.r9.s16;
	// bl 0x82052ea8
	ctx.lr = 0x82063E00;
	sub_82052EA8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r7,r30,1
	ctx.r7.s64 = ctx.r30.s64 + 1;
	// lwz r11,-6624(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -6624);
	// li r6,193
	ctx.r6.s64 = 193;
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// sth r6,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r6.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r7,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// bl 0x82052ea8
	ctx.lr = 0x82063E24;
	sub_82052EA8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,194
	ctx.r4.s64 = 194;
	// lwz r11,-6624(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -6624);
	// li r28,0
	ctx.r28.s64 = 0;
	// sth r4,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r4.u16);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r28.u32);
	// bl 0x82052ea8
	ctx.lr = 0x82063E48;
	sub_82052EA8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r9,195
	ctx.r9.s64 = 195;
	// lwz r11,-6624(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -6624);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r9,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r9.u16);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// stw r28,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r28.u32);
	// bl 0x82052ea8
	ctx.lr = 0x82063E68;
	sub_82052EA8(ctx, base);
	// li r29,1
	ctx.r29.s64 = 1;
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r28,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// sth r28,18(r31)
	REX_STORE_U16(ctx.r31.u32 + 18, ctx.r28.u16);
	// sth r8,12(r31)
	REX_STORE_U16(ctx.r31.u32 + 12, ctx.r8.u16);
	// lis r4,-32218
	ctx.r4.s64 = -2111438848;
	// sth r7,16(r31)
	REX_STORE_U16(ctx.r31.u32 + 16, ctx.r7.u16);
	// addi r6,r31,12
	ctx.r6.s64 = ctx.r31.s64 + 12;
	// stb r29,20(r31)
	REX_STORE_U8(ctx.r31.u32 + 20, ctx.r29.u8);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// sth r29,14(r31)
	REX_STORE_U16(ctx.r31.u32 + 14, ctx.r29.u16);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-6628(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + -6628);
	// bl 0x820a2b00
	ctx.lr = 0x82063EA4;
	sub_820A2B00(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r10,-6624(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + -6624);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r7,r30,188
	ctx.r7.s64 = ctx.r30.s64 + 188;
	// addi r3,r10,1672
	ctx.r3.s64 = ctx.r10.s64 + 1672;
	// sth r7,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r7.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f13,9536(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9536);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,9880(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9880);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,-6612(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6612);
	// stfs f13,116(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 116, temp.u32);
	// stb r29,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r29.u8);
	// lfs f13,108(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f13,112(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 112, temp.u32);
	// stfs f12,120(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 120, temp.u32);
	// bl 0x82052ea8
	ctx.lr = 0x82063EEC;
	sub_82052EA8(ctx, base);
	// stw r29,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r5,18352
	ctx.r4.s64 = ctx.r5.s64 + 18352;
	// bl 0x82053a00
	ctx.lr = 0x82063F00;
	sub_82053A00(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,-6624(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -6624);
	// bl 0x820778d0
	ctx.lr = 0x82063F0C;
	sub_820778D0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
