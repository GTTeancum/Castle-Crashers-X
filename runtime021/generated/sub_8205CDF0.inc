DEFINE_REX_FUNC(sub_8205CDF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x8205CDF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r9,276(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 276);
	// lhz r11,102(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 102);
	// lwz r31,56(r9)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205d084
	if (!ctx.cr6.eq) goto loc_8205D084;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r11,13276
	ctx.r4.s64 = ctx.r11.s64 + 13276;
	// bl 0x8209d948
	ctx.lr = 0x8205CE2C;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205CE44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205CE4C;
	sub_82085078(ctx, base);
	// li r4,456
	ctx.r4.s64 = 456;
	// bl 0x82094b48
	ctx.lr = 0x8205CE54;
	sub_82094B48(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,13288
	ctx.r4.s64 = ctx.r8.s64 + 13288;
	// bl 0x8209d948
	ctx.lr = 0x8205CE64;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205CE7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205CE84;
	sub_82085078(ctx, base);
	// li r4,457
	ctx.r4.s64 = 457;
	// bl 0x82094b48
	ctx.lr = 0x8205CE8C;
	sub_82094B48(ctx, base);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r5,13300
	ctx.r4.s64 = ctx.r5.s64 + 13300;
	// bl 0x8209d948
	ctx.lr = 0x8205CE9C;
	sub_8209D948(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8205CEB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205CEBC;
	sub_82085078(ctx, base);
	// li r4,458
	ctx.r4.s64 = 458;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205CEC8;
	sub_82094B48(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r4,17
	ctx.r4.s64 = 17;
	// bl 0x82058508
	ctx.lr = 0x8205CED4;
	sub_82058508(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r10,13312
	ctx.r4.s64 = ctx.r10.s64 + 13312;
	// bl 0x8209d948
	ctx.lr = 0x8205CEE4;
	sub_8209D948(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8205CEFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205CF04;
	sub_82085078(ctx, base);
	// li r4,459
	ctx.r4.s64 = 459;
	// bl 0x82094b48
	ctx.lr = 0x8205CF0C;
	sub_82094B48(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r7,13324
	ctx.r4.s64 = ctx.r7.s64 + 13324;
	// bl 0x8209d948
	ctx.lr = 0x8205CF1C;
	sub_8209D948(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8205CF34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205CF3C;
	sub_82085078(ctx, base);
	// li r4,458
	ctx.r4.s64 = 458;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205CF48;
	sub_82094B48(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r4,17
	ctx.r4.s64 = 17;
	// bl 0x82058508
	ctx.lr = 0x8205CF54;
	sub_82058508(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r4,13336
	ctx.r4.s64 = ctx.r4.s64 + 13336;
	// bl 0x8209d948
	ctx.lr = 0x8205CF64;
	sub_8209D948(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205CF7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205CF84;
	sub_82085078(ctx, base);
	// li r4,153
	ctx.r4.s64 = 153;
	// bl 0x82094b48
	ctx.lr = 0x8205CF8C;
	sub_82094B48(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r9,13348
	ctx.r4.s64 = ctx.r9.s64 + 13348;
	// bl 0x8209d948
	ctx.lr = 0x8205CF9C;
	sub_8209D948(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,100(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 100);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8205CFB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205CFBC;
	sub_82085078(ctx, base);
	// li r4,460
	ctx.r4.s64 = 460;
	// bl 0x82094b48
	ctx.lr = 0x8205CFC4;
	sub_82094B48(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r6,13356
	ctx.r4.s64 = ctx.r6.s64 + 13356;
	// bl 0x8209d948
	ctx.lr = 0x8205CFD4;
	sub_8209D948(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8205CFEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205CFF4;
	sub_82085078(ctx, base);
	// li r4,461
	ctx.r4.s64 = 461;
	// bl 0x82094b48
	ctx.lr = 0x8205CFFC;
	sub_82094B48(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r11,13364
	ctx.r4.s64 = ctx.r11.s64 + 13364;
	// bl 0x8209d948
	ctx.lr = 0x8205D00C;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205D024;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205D02C;
	sub_82085078(ctx, base);
	// li r4,462
	ctx.r4.s64 = 462;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205D038;
	sub_82094B48(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82058508
	ctx.lr = 0x8205D044;
	sub_82058508(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,13372
	ctx.r4.s64 = ctx.r8.s64 + 13372;
	// bl 0x8209d948
	ctx.lr = 0x8205D054;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205D06C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82085078
	ctx.lr = 0x8205D074;
	sub_82085078(ctx, base);
	// li r4,454
	ctx.r4.s64 = 454;
	// bl 0x82094b48
	ctx.lr = 0x8205D07C;
	sub_82094B48(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8205D084:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8205d2cc
	if (!ctx.cr6.eq) goto loc_8205D2CC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r11,13276
	ctx.r4.s64 = ctx.r11.s64 + 13276;
	// bl 0x8209d948
	ctx.lr = 0x8205D09C;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205D0B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205D0BC;
	sub_82085078(ctx, base);
	// li r4,464
	ctx.r4.s64 = 464;
	// bl 0x82094b48
	ctx.lr = 0x8205D0C4;
	sub_82094B48(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,13288
	ctx.r4.s64 = ctx.r8.s64 + 13288;
	// bl 0x8209d948
	ctx.lr = 0x8205D0D4;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205D0EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205D0F4;
	sub_82085078(ctx, base);
	// li r4,464
	ctx.r4.s64 = 464;
	// bl 0x82094b48
	ctx.lr = 0x8205D0FC;
	sub_82094B48(ctx, base);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r5,13300
	ctx.r4.s64 = ctx.r5.s64 + 13300;
	// bl 0x8209d948
	ctx.lr = 0x8205D10C;
	sub_8209D948(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8205D124;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205D12C;
	sub_82085078(ctx, base);
	// li r4,464
	ctx.r4.s64 = 464;
	// bl 0x82094b48
	ctx.lr = 0x8205D134;
	sub_82094B48(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r10,13312
	ctx.r4.s64 = ctx.r10.s64 + 13312;
	// bl 0x8209d948
	ctx.lr = 0x8205D144;
	sub_8209D948(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8205D15C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205D164;
	sub_82085078(ctx, base);
	// li r4,459
	ctx.r4.s64 = 459;
	// bl 0x82094b48
	ctx.lr = 0x8205D16C;
	sub_82094B48(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r7,13324
	ctx.r4.s64 = ctx.r7.s64 + 13324;
	// bl 0x8209d948
	ctx.lr = 0x8205D17C;
	sub_8209D948(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8205D194;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205D19C;
	sub_82085078(ctx, base);
	// li r4,464
	ctx.r4.s64 = 464;
	// bl 0x82094b48
	ctx.lr = 0x8205D1A4;
	sub_82094B48(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r4,13336
	ctx.r4.s64 = ctx.r4.s64 + 13336;
	// bl 0x8209d948
	ctx.lr = 0x8205D1B4;
	sub_8209D948(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205D1CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205D1D4;
	sub_82085078(ctx, base);
	// li r4,464
	ctx.r4.s64 = 464;
	// bl 0x82094b48
	ctx.lr = 0x8205D1DC;
	sub_82094B48(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r9,13348
	ctx.r4.s64 = ctx.r9.s64 + 13348;
	// bl 0x8209d948
	ctx.lr = 0x8205D1EC;
	sub_8209D948(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,100(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 100);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8205D204;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205D20C;
	sub_82085078(ctx, base);
	// li r4,455
	ctx.r4.s64 = 455;
	// bl 0x82094b48
	ctx.lr = 0x8205D214;
	sub_82094B48(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r6,13356
	ctx.r4.s64 = ctx.r6.s64 + 13356;
	// bl 0x8209d948
	ctx.lr = 0x8205D224;
	sub_8209D948(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8205D23C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205D244;
	sub_82085078(ctx, base);
	// li r4,455
	ctx.r4.s64 = 455;
	// bl 0x82094b48
	ctx.lr = 0x8205D24C;
	sub_82094B48(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r11,13364
	ctx.r4.s64 = ctx.r11.s64 + 13364;
	// bl 0x8209d948
	ctx.lr = 0x8205D25C;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205D274;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8205D27C;
	sub_82085078(ctx, base);
	// li r4,464
	ctx.r4.s64 = 464;
	// bl 0x82094b48
	ctx.lr = 0x8205D284;
	sub_82094B48(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,13372
	ctx.r4.s64 = ctx.r8.s64 + 13372;
	// bl 0x8209d948
	ctx.lr = 0x8205D294;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205D2AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82085078
	ctx.lr = 0x8205D2B4;
	sub_82085078(ctx, base);
	// li r4,463
	ctx.r4.s64 = 463;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205D2C0;
	sub_82094B48(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82058508
	ctx.lr = 0x8205D2CC;
	sub_82058508(ctx, base);
loc_8205D2CC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
