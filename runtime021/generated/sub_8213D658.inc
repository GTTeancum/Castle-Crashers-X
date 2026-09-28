DEFINE_REX_FUNC(sub_8213D658) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8213D660;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r7,76(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplw cr6,r30,r7
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8213d754
	if (ctx.cr6.eq) goto loc_8213D754;
	// li r11,4
	ctx.r11.s64 = 4;
	// stb r29,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r29.u8);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,88
	ctx.r11.s64 = ctx.r1.s64 + 88;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// lfs f0,9536(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,9540(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 9540);
	ctx.f31.f64 = double(temp.f32);
	// stw r8,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r11,r1,116
	ctx.r11.s64 = ctx.r1.s64 + 116;
	// addi r9,r31,36
	ctx.r9.s64 = ctx.r31.s64 + 36;
loc_8213D6CC:
	// lwz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stb r8,-4(r11)
	REX_STORE_U8(ctx.r11.u32 + -4, ctx.r8.u8);
	// cmplwi cr6,r6,65535
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 65535, ctx.xer);
	// stb r10,-3(r11)
	REX_STORE_U8(ctx.r11.u32 + -3, ctx.r10.u8);
	// bgt cr6,0x8213d6f8
	if (ctx.cr6.gt) goto loc_8213D6F8;
	// lbz r6,64(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 64);
	// slw r5,r29,r10
	ctx.r5.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r29.u32 << (ctx.r10.u8 & 0x3F));
	// and. r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 & ctx.r5.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x8213d6f8
	if (!ctx.cr0.eq) goto loc_8213D6F8;
	// stfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x8213d6fc
	goto loc_8213D6FC;
loc_8213D6F8:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_8213D6FC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// blt cr6,0x8213d6cc
	if (ctx.cr6.lt) goto loc_8213D6CC;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8213d720
	if (ctx.cr6.eq) goto loc_8213D720;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x820d8088
	ctx.lr = 0x8213D720;
	sub_820D8088(ctx, base);
loc_8213D720:
	// stw r30,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8213d734
	if (!ctx.cr6.eq) goto loc_8213D734;
	// lwz r30,80(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// b 0x8213d744
	goto loc_8213D744;
loc_8213D734:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820d8020
	ctx.lr = 0x8213D73C;
	sub_820D8020(ctx, base);
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stb r29,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r29.u8);
loc_8213D744:
	// stw r30,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// bl 0x820d8160
	ctx.lr = 0x8213D754;
	sub_820D8160(ctx, base);
loc_8213D754:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
