DEFINE_REX_FUNC(sub_8209DBC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x8209DBC8;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// bl 0x8209ca70
	ctx.lr = 0x8209DBE0;
	sub_8209CA70(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,1084
	ctx.r9.s64 = ctx.r11.s64 + 1084;
	// li r29,0
	ctx.r29.s64 = 0;
	// ori r11,r10,65535
	ctx.r11.u64 = ctx.r10.u64 | 65535;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r29,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r29.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// sth r11,100(r31)
	REX_STORE_U16(ctx.r31.u32 + 100, ctx.r11.u16);
	// addi r4,r30,4
	ctx.r4.s64 = ctx.r30.s64 + 4;
	// sth r11,102(r31)
	REX_STORE_U16(ctx.r31.u32 + 102, ctx.r11.u16);
	// addi r5,r8,-8128
	ctx.r5.s64 = ctx.r8.s64 + -8128;
	// stw r29,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r29,100(r1)
	REX_STORE_U8(ctx.r1.u32 + 100, ctx.r29.u8);
	// addi r11,r31,100
	ctx.r11.s64 = ctx.r31.s64 + 100;
	// bl 0x82075130
	ctx.lr = 0x8209DC24;
	sub_82075130(ctx, base);
	// lis r26,-32218
	ctx.r26.s64 = -2111438848;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6656(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + -6656);
	// bl 0x82095ff0
	ctx.lr = 0x8209DC38;
	sub_82095FF0(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r3,-6656(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + -6656);
	// li r5,1
	ctx.r5.s64 = 1;
	// lhz r6,0(r7)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r7.u32 + 0);
	// sth r6,100(r31)
	REX_STORE_U16(ctx.r31.u32 + 100, ctx.r6.u16);
	// lhz r4,2(r7)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r7.u32 + 2);
	// sth r4,102(r31)
	REX_STORE_U16(ctx.r31.u32 + 102, ctx.r4.u16);
	// lwz r4,0(r7)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// bl 0x82095da8
	ctx.lr = 0x8209DC5C;
	sub_82095DA8(ctx, base);
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lwz r30,20(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lbz r10,-22601(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -22601);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209dc88
	if (!ctx.cr6.eq) goto loc_8209DC88;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r3,r11,-1768
	ctx.r3.s64 = ctx.r11.s64 + -1768;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209DC88;
	sub_820A71E8(ctx, base);
loc_8209DC88:
	// bl 0x820b5eb8
	ctx.lr = 0x8209DC8C;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,29632
	ctx.r9.s64 = ctx.r11.s64 + 29632;
	// li r4,30492
	ctx.r4.s64 = 30492;
	// lwzx r3,r10,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8209DCA4;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209dcd4
	if (ctx.cr6.eq) goto loc_8209DCD4;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x820901a8
	ctx.lr = 0x8209DCC0;
	sub_820901A8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_8209DCD4:
	// stw r29,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
