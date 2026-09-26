DEFINE_REX_FUNC(sub_82073B00) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r30,12
	ctx.r31.s64 = ctx.r30.s64 + 12;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073B24;
	sub_82073D80(ctx, base);
	// addi r11,r30,220
	ctx.r11.s64 = ctx.r30.s64 + 220;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073B38;
	sub_82073E20(ctx, base);
	// addi r10,r30,256
	ctx.r10.s64 = ctx.r30.s64 + 256;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073B4C;
	sub_82073E20(ctx, base);
	// addi r9,r30,292
	ctx.r9.s64 = ctx.r30.s64 + 292;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073B60;
	sub_82073E20(ctx, base);
	// addi r8,r30,328
	ctx.r8.s64 = ctx.r30.s64 + 328;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073B74;
	sub_82073E20(ctx, base);
	// addi r7,r30,364
	ctx.r7.s64 = ctx.r30.s64 + 364;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073B88;
	sub_82073E20(ctx, base);
	// addi r6,r30,400
	ctx.r6.s64 = ctx.r30.s64 + 400;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073B9C;
	sub_82073E20(ctx, base);
	// addi r5,r30,436
	ctx.r5.s64 = ctx.r30.s64 + 436;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073BB0;
	sub_82073E20(ctx, base);
	// addi r4,r30,472
	ctx.r4.s64 = ctx.r30.s64 + 472;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073BC4;
	sub_82073E20(ctx, base);
	// addi r11,r30,508
	ctx.r11.s64 = ctx.r30.s64 + 508;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073BD8;
	sub_82073E20(ctx, base);
	// addi r10,r30,544
	ctx.r10.s64 = ctx.r30.s64 + 544;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073BEC;
	sub_82073E20(ctx, base);
	// addi r9,r30,580
	ctx.r9.s64 = ctx.r30.s64 + 580;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073C00;
	sub_82073E20(ctx, base);
	// addi r8,r30,616
	ctx.r8.s64 = ctx.r30.s64 + 616;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073C14;
	sub_82073E20(ctx, base);
	// addi r7,r30,652
	ctx.r7.s64 = ctx.r30.s64 + 652;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073C28;
	sub_82073E20(ctx, base);
	// addi r6,r30,688
	ctx.r6.s64 = ctx.r30.s64 + 688;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073C3C;
	sub_82073E20(ctx, base);
	// addi r5,r30,760
	ctx.r5.s64 = ctx.r30.s64 + 760;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073C50;
	sub_82073E20(ctx, base);
	// addi r4,r30,724
	ctx.r4.s64 = ctx.r30.s64 + 724;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073C64;
	sub_82073E20(ctx, base);
	// addi r11,r30,796
	ctx.r11.s64 = ctx.r30.s64 + 796;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073C78;
	sub_82073E20(ctx, base);
	// addi r10,r30,832
	ctx.r10.s64 = ctx.r30.s64 + 832;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073C8C;
	sub_82073E20(ctx, base);
	// addi r9,r30,76
	ctx.r9.s64 = ctx.r30.s64 + 76;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073CA0;
	sub_82073E20(ctx, base);
	// addi r8,r30,112
	ctx.r8.s64 = ctx.r30.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073CB4;
	sub_82073E20(ctx, base);
	// addi r7,r30,148
	ctx.r7.s64 = ctx.r30.s64 + 148;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82073e20
	ctx.lr = 0x82073CC8;
	sub_82073E20(ctx, base);
	// addi r6,r30,184
	ctx.r6.s64 = ctx.r30.s64 + 184;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82073e20
	ctx.lr = 0x82073CDC;
	sub_82073E20(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
