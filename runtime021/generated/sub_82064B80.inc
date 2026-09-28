DEFINE_REX_FUNC(sub_82064B80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x82064B88;
	__savegprlr_23(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,18404
	ctx.r4.s64 = ctx.r11.s64 + 18404;
	// lwz r28,48(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,276(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 276);
	// lwz r31,56(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// bl 0x8209d948
	ctx.lr = 0x82064BAC;
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
	ctx.lr = 0x82064BC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x82064BCC;
	sub_82085078(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,164(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 164);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82064BE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r24,0
	ctx.r24.s64 = 0;
	// addi r9,r5,9524
	ctx.r9.s64 = ctx.r5.s64 + 9524;
	// addi r8,r4,9532
	ctx.r8.s64 = ctx.r4.s64 + 9532;
	// addi r7,r3,9540
	ctx.r7.s64 = ctx.r3.s64 + 9540;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r26,r11,18592
	ctx.r26.s64 = ctx.r11.s64 + 18592;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r25,r10,18604
	ctx.r25.s64 = ctx.r10.s64 + 18604;
	// stw r7,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r26,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// stw r25,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// addi r27,r1,80
	ctx.r27.s64 = ctx.r1.s64 + 80;
loc_82064C2C:
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r4,0(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// bl 0x8209d948
	ctx.lr = 0x82064C38;
	sub_8209D948(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82064C50;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x82085078
	ctx.lr = 0x82064C58;
	sub_82085078(ctx, base);
	// addi r9,r29,526
	ctx.r9.s64 = ctx.r29.s64 + 526;
	// clrlwi r4,r9,16
	ctx.r4.u64 = ctx.r9.u32 & 0xFFFF;
	// bl 0x82094b48
	ctx.lr = 0x82064C64;
	sub_82094B48(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// cmpwi cr6,r29,3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 3, ctx.xer);
	// blt cr6,0x82064c2c
	if (ctx.cr6.lt) goto loc_82064C2C;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x8209d948
	ctx.lr = 0x82064C80;
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
	ctx.lr = 0x82064C98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x82064CA0;
	sub_82085078(ctx, base);
	// li r4,90
	ctx.r4.s64 = 90;
	// bl 0x82094b48
	ctx.lr = 0x82064CA8;
	sub_82094B48(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x8209d948
	ctx.lr = 0x82064CB4;
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
	ctx.lr = 0x82064CCC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x82064CD4;
	sub_82085078(ctx, base);
	// li r4,95
	ctx.r4.s64 = 95;
	// bl 0x82094b48
	ctx.lr = 0x82064CDC;
	sub_82094B48(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// stw r30,356(r28)
	REX_STORE_U32(ctx.r28.u32 + 356, ctx.r30.u32);
	// addi r5,r7,19864
	ctx.r5.s64 = ctx.r7.s64 + 19864;
	// sth r24,388(r28)
	REX_STORE_U16(ctx.r28.u32 + 388, ctx.r24.u16);
	// addi r4,r6,19720
	ctx.r4.s64 = ctx.r6.s64 + 19720;
	// sth r24,390(r28)
	REX_STORE_U16(ctx.r28.u32 + 390, ctx.r24.u16);
	// stw r5,360(r28)
	REX_STORE_U32(ctx.r28.u32 + 360, ctx.r5.u32);
	// stw r4,364(r28)
	REX_STORE_U32(ctx.r28.u32 + 364, ctx.r4.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
