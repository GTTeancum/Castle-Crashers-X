DEFINE_REX_FUNC(sub_8213A8E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-2
	ctx.r11.s64 = -131072;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// ori r11,r11,31072
	ctx.r11.u64 = ctx.r11.u64 | 31072;
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82149a48
	ctx.lr = 0x8213A914;
	sub_82149A48(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8213a924
	if (!ctx.cr0.eq) goto loc_8213A924;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82137138
	ctx.lr = 0x8213A924;
	sub_82137138(ctx, base);
loc_8213A924:
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821499d8
	ctx.lr = 0x8213A940;
	sub_821499D8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8213a950
	if (!ctx.cr0.eq) goto loc_8213A950;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82137138
	ctx.lr = 0x8213A950;
	sub_82137138(ctx, base);
loc_8213A950:
	// lwz r3,1304(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 1304);
	// bl 0x82149998
	ctx.lr = 0x8213A958;
	sub_82149998(ctx, base);
	// b 0x8213a96c
	goto loc_8213A96C;
loc_8213A95C:
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x820b6020
	ctx.lr = 0x8213A964;
	sub_820B6020(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8213a238
	ctx.lr = 0x8213A96C;
	sub_8213A238(ctx, base);
loc_8213A96C:
	// lwz r11,1300(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1300);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x8213a95c
	if (!ctx.cr6.eq) goto loc_8213A95C;
	// bl 0x82149958
	ctx.lr = 0x8213A980;
	sub_82149958(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b6498
	ctx.lr = 0x8213A988;
	sub_820B6498(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82137138
	ctx.lr = 0x8213A990;
	sub_82137138(ctx, base);
}
