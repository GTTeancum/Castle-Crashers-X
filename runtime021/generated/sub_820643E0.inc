DEFINE_REX_FUNC(sub_820643E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298fc
	ctx.lr = 0x820643E8;
	__savegprlr_21(ctx, base);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r4,r10,18416
	ctx.r4.s64 = ctx.r10.s64 + 18416;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lhz r31,30(r30)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r30.u32 + 30);
	// lhz r24,26(r30)
	ctx.r24.u64 = REX_LOAD_U16(ctx.r30.u32 + 26);
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r9,276(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 276);
	// lwz r27,56(r9)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r9.u32 + 56);
	// bl 0x8209d948
	ctx.lr = 0x82064414;
	sub_8209D948(ctx, base);
	// lwz r8,8(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r7,18428
	ctx.r4.s64 = ctx.r7.s64 + 18428;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x8209d948
	ctx.lr = 0x8206442C;
	sub_8209D948(ctx, base);
	// lwz r6,0(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82064444;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x8206444C;
	sub_82085078(ctx, base);
	// lwz r4,0(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82064464;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8206446C;
	sub_82085078(ctx, base);
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r9,18440
	ctx.r4.s64 = ctx.r9.s64 + 18440;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x8209d948
	ctx.lr = 0x82064484;
	sub_8209D948(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r24,1
	ctx.r5.s64 = ctx.r24.s64 + 1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8208b608
	ctx.lr = 0x82064494;
	sub_8208B608(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,18452
	ctx.r4.s64 = ctx.r8.s64 + 18452;
	// bl 0x8209d948
	ctx.lr = 0x820644A4;
	sub_8209D948(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r3,-6628(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + -6628);
	// bl 0x820a3df8
	ctx.lr = 0x820644BC;
	sub_820A3DF8(ctx, base);
	// lwz r6,0(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820644D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82085078
	ctx.lr = 0x820644D8;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// bl 0x82094858
	ctx.lr = 0x820644E4;
	sub_82094858(ctx, base);
	// lwz r4,0(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820644F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82085078
	ctx.lr = 0x82064500;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// bl 0x82094858
	ctx.lr = 0x8206450C;
	sub_82094858(ctx, base);
	// lis r26,-32218
	ctx.r26.s64 = -2111438848;
	// addi r10,r31,5
	ctx.r10.s64 = ctx.r31.s64 + 5;
	// li r5,69
	ctx.r5.s64 = 69;
	// rlwinm r31,r10,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwz r25,-6596(r26)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// lwzx r4,r31,r25
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r25.u32);
	// bl 0x8209d3d8
	ctx.lr = 0x8206452C;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r25
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r25.u32);
	// bl 0x8209d488
	ctx.lr = 0x8206453C;
	sub_8209D488(ctx, base);
	// addi r5,r1,114
	ctx.r5.s64 = ctx.r1.s64 + 114;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r25
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r25.u32);
	// bl 0x8209d488
	ctx.lr = 0x8206454C;
	sub_8209D488(ctx, base);
	// addi r5,r1,115
	ctx.r5.s64 = ctx.r1.s64 + 115;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r25
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r25.u32);
	// bl 0x8209d488
	ctx.lr = 0x8206455C;
	sub_8209D488(ctx, base);
	// addi r5,r1,113
	ctx.r5.s64 = ctx.r1.s64 + 113;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r25
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r25.u32);
	// bl 0x8209d488
	ctx.lr = 0x8206456C;
	sub_8209D488(ctx, base);
	// lbz r8,112(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lbz r9,114(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 114);
	// li r4,32
	ctx.r4.s64 = 32;
	// lbz r7,115(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 115);
	// addi r25,r11,18464
	ctx.r25.s64 = ctx.r11.s64 + 18464;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// clrlwi r6,r9,16
	ctx.r6.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// rlwimi r7,r6,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// rlwinm r11,r7,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// lbz r8,113(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 113);
	// or r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 | ctx.r8.u64;
	// bl 0x82070f20
	ctx.lr = 0x820645AC;
	sub_82070F20(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r7,18472
	ctx.r4.s64 = ctx.r7.s64 + 18472;
	// bl 0x8209d948
	ctx.lr = 0x820645BC;
	sub_8209D948(ctx, base);
	// lwz r6,0(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820645D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x82085078
	ctx.lr = 0x820645DC;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x820645E8;
	sub_82094A98(ctx, base);
	// lwz r4,0(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820645FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x82085078
	ctx.lr = 0x82064604;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x82064610;
	sub_82094A98(ctx, base);
	// addi r11,r24,4
	ctx.r11.s64 = ctx.r24.s64 + 4;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r10,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r24,-6596(r26)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// lwzx r4,r31,r24
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r24.u32);
	// bl 0x8209d3d8
	ctx.lr = 0x82064630;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r24
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r24.u32);
	// bl 0x8209d488
	ctx.lr = 0x82064640;
	sub_8209D488(ctx, base);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r24
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r24.u32);
	// bl 0x8209d488
	ctx.lr = 0x82064650;
	sub_8209D488(ctx, base);
	// lbz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 128);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// clrlwi r24,r8,24
	ctx.r24.u64 = ctx.r8.u32 & 0xFF;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r22,r24
	ctx.r22.u64 = ctx.r24.u64;
	// bl 0x82070f20
	ctx.lr = 0x82064674;
	sub_82070F20(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r7,18480
	ctx.r4.s64 = ctx.r7.s64 + 18480;
	// bl 0x8209d948
	ctx.lr = 0x82064684;
	sub_8209D948(ctx, base);
	// lwz r6,0(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8206469C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x82085078
	ctx.lr = 0x820646A4;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x820646B0;
	sub_82094A98(ctx, base);
	// lwz r4,0(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820646C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x82085078
	ctx.lr = 0x820646CC;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x820646D8;
	sub_82094A98(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwz r23,-6596(r26)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// lwzx r4,r31,r23
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r23.u32);
	// bl 0x8209d488
	ctx.lr = 0x820646EC;
	sub_8209D488(ctx, base);
	// addi r5,r1,114
	ctx.r5.s64 = ctx.r1.s64 + 114;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r23
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r23.u32);
	// bl 0x8209d488
	ctx.lr = 0x820646FC;
	sub_8209D488(ctx, base);
	// addi r5,r1,115
	ctx.r5.s64 = ctx.r1.s64 + 115;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r23
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r23.u32);
	// bl 0x8209d488
	ctx.lr = 0x8206470C;
	sub_8209D488(ctx, base);
	// addi r5,r1,113
	ctx.r5.s64 = ctx.r1.s64 + 113;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r23
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r23.u32);
	// bl 0x8209d488
	ctx.lr = 0x8206471C;
	sub_8209D488(ctx, base);
	// lbz r8,112(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lbz r10,114(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 114);
	// lbz r7,115(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 115);
	// addi r4,r9,18492
	ctx.r4.s64 = ctx.r9.s64 + 18492;
	// rlwimi r10,r8,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwimi r7,r6,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// rlwinm r5,r7,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// extsw r11,r5
	ctx.r11.s64 = ctx.r5.s32;
	// lbz r9,113(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 113);
	// or r23,r11,r9
	ctx.r23.u64 = ctx.r11.u64 | ctx.r9.u64;
	// bl 0x8209d948
	ctx.lr = 0x82064754;
	sub_8209D948(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// rotlwi r5,r23,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r23.u32, 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8208b608
	ctx.lr = 0x82064764;
	sub_8208B608(ctx, base);
	// addi r8,r24,18
	ctx.r8.s64 = ctx.r24.s64 + 18;
	// addi r11,r24,-1
	ctx.r11.s64 = ctx.r24.s64 + -1;
	// mullw r10,r8,r24
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r24.s32);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r8
	ctx.r7.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r21,r6,1,0,30
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r5,r21
	ctx.r11.u64 = ctx.r21.u64 - ctx.r5.u64;
	// addi r24,r11,-190
	ctx.r24.s64 = ctx.r11.s64 + -190;
	// clrldi r4,r24,32
	ctx.r4.u64 = ctx.r24.u64 & 0xFFFFFFFF;
	// subf r3,r4,r23
	ctx.r3.u64 = ctx.r23.u64 - ctx.r4.u64;
	// bl 0x8212b180
	ctx.lr = 0x8206479C;
	sub_8212B180(ctx, base);
	// subf r3,r24,r21
	ctx.r3.u64 = ctx.r21.u64 - ctx.r24.u64;
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// clrldi r10,r3,32
	ctx.r10.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// std r10,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lfd f12,120(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lfs f0,18236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18236);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// fctidz f7,f8
	ctx.f7.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.f7.u64);
	// lwz r24,124(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// cmplwi cr6,r24,1
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 1, ctx.xer);
	// bge cr6,0x820647e4
	if (!ctx.cr6.lt) goto loc_820647E4;
	// li r24,1
	ctx.r24.s64 = 1;
	// b 0x820647f0
	goto loc_820647F0;
loc_820647E4:
	// cmplwi cr6,r24,100
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 100, ctx.xer);
	// ble cr6,0x820647f0
	if (!ctx.cr6.gt) goto loc_820647F0;
	// li r24,100
	ctx.r24.s64 = 100;
loc_820647F0:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r11,18500
	ctx.r4.s64 = ctx.r11.s64 + 18500;
	// bl 0x8209d948
	ctx.lr = 0x82064800;
	sub_8209D948(ctx, base);
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82064818;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x82085078
	ctx.lr = 0x82064820;
	sub_82085078(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r4,r24,16
	ctx.r4.u64 = ctx.r24.u32 & 0xFFFF;
	// lwz r7,164(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 164);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82064834;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x8209d488
	ctx.lr = 0x82064848;
	sub_8209D488(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r6,18504
	ctx.r4.s64 = ctx.r6.s64 + 18504;
	// bl 0x8209d948
	ctx.lr = 0x82064858;
	sub_8209D948(ctx, base);
	// lbz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// clrlwi r5,r11,24
	ctx.r5.u64 = ctx.r11.u32 & 0xFF;
	// stb r5,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r5.u8);
	// bl 0x8208b608
	ctx.lr = 0x82064874;
	sub_8208B608(ctx, base);
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x8209d488
	ctx.lr = 0x82064888;
	sub_8209D488(ctx, base);
	// lbz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// addi r4,r10,18516
	ctx.r4.s64 = ctx.r10.s64 + 18516;
	// clrlwi r24,r8,24
	ctx.r24.u64 = ctx.r8.u32 & 0xFF;
	// stb r24,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r24.u8);
	// bl 0x8209d948
	ctx.lr = 0x820648A8;
	sub_8209D948(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8208b608
	ctx.lr = 0x820648B8;
	sub_8208B608(ctx, base);
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x8209d488
	ctx.lr = 0x820648CC;
	sub_8209D488(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// lbz r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82070f20
	ctx.lr = 0x820648E0;
	sub_82070F20(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r6,18528
	ctx.r4.s64 = ctx.r6.s64 + 18528;
	// bl 0x8209d948
	ctx.lr = 0x820648F0;
	sub_8209D948(ctx, base);
	// lwz r5,0(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82064908;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82085078
	ctx.lr = 0x82064910;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x8206491C;
	sub_82094A98(ctx, base);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82064930;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82085078
	ctx.lr = 0x82064938;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x82064944;
	sub_82094A98(ctx, base);
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x8209d488
	ctx.lr = 0x82064958;
	sub_8209D488(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lbz r27,112(r1)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// bl 0x82070f20
	ctx.lr = 0x82064970;
	sub_82070F20(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,18540
	ctx.r4.s64 = ctx.r8.s64 + 18540;
	// bl 0x8209d948
	ctx.lr = 0x82064980;
	sub_8209D948(ctx, base);
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82064998;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82085078
	ctx.lr = 0x820649A0;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x820649AC;
	sub_82094A98(ctx, base);
	// lwz r5,0(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x820649C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82085078
	ctx.lr = 0x820649C8;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x820649D4;
	sub_82094A98(ctx, base);
	// addi r11,r22,23
	ctx.r11.s64 = ctx.r22.s64 + 23;
	// mulli r9,r27,28
	ctx.r9.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(28));
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// clrlwi r6,r11,16
	ctx.r6.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x82070f20
	ctx.lr = 0x820649FC;
	sub_82070F20(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r10,18552
	ctx.r4.s64 = ctx.r10.s64 + 18552;
	// bl 0x8209d948
	ctx.lr = 0x82064A0C;
	sub_8209D948(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82064A24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82085078
	ctx.lr = 0x82064A2C;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x82064A38;
	sub_82094A98(ctx, base);
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82064A4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82085078
	ctx.lr = 0x82064A54;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x82064A60;
	sub_82094A98(ctx, base);
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x8209d488
	ctx.lr = 0x82064A74;
	sub_8209D488(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// lbz r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82070f20
	ctx.lr = 0x82064A88;
	sub_82070F20(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r10,18568
	ctx.r4.s64 = ctx.r10.s64 + 18568;
	// bl 0x8209d948
	ctx.lr = 0x82064A98;
	sub_8209D948(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82064AB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82085078
	ctx.lr = 0x82064AB8;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x82064AC4;
	sub_82094A98(ctx, base);
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82064AD8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82085078
	ctx.lr = 0x82064AE0;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x82064AEC;
	sub_82094A98(ctx, base);
	// lwz r11,-6596(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -6596);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwzx r4,r31,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x8209d488
	ctx.lr = 0x82064B00;
	sub_8209D488(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// lbz r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82070f20
	ctx.lr = 0x82064B14;
	sub_82070F20(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r10,18580
	ctx.r4.s64 = ctx.r10.s64 + 18580;
	// bl 0x8209d948
	ctx.lr = 0x82064B24;
	sub_8209D948(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82064B3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82085078
	ctx.lr = 0x82064B44;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x82064B50;
	sub_82094A98(ctx, base);
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82064B64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82085078
	ctx.lr = 0x82064B6C;
	sub_82085078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82094a98
	ctx.lr = 0x82064B78;
	sub_82094A98(ctx, base);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x8212994c
	__restgprlr_21(ctx, base);
	return;
}
