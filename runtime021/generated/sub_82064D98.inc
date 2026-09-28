DEFINE_REX_FUNC(sub_82064D98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82064DA0;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,18404
	ctx.r4.s64 = ctx.r11.s64 + 18404;
	// lwz r29,48(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,276(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 276);
	// lwz r30,56(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// bl 0x8209d948
	ctx.lr = 0x82064DC4;
	sub_8209D948(ctx, base);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82064DDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x82064DE4;
	sub_82085078(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,164(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 164);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82064DF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r31,356(r29)
	REX_STORE_U32(ctx.r29.u32 + 356, ctx.r31.u32);
	// li r3,15
	ctx.r3.s64 = 15;
	// addi r4,r5,20768
	ctx.r4.s64 = ctx.r5.s64 + 20768;
	// stw r11,360(r29)
	REX_STORE_U32(ctx.r29.u32 + 360, ctx.r11.u32);
	// lis r28,-32218
	ctx.r28.s64 = -2111438848;
	// sth r11,388(r29)
	REX_STORE_U16(ctx.r29.u32 + 388, ctx.r11.u16);
	// stw r4,364(r29)
	REX_STORE_U32(ctx.r29.u32 + 364, ctx.r4.u32);
	// sth r3,390(r29)
	REX_STORE_U16(ctx.r29.u32 + 390, ctx.r3.u16);
	// lhz r27,30(r31)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r31.u32 + 30);
	// addi r10,r27,5
	ctx.r10.s64 = ctx.r27.s64 + 5;
	// lwz r26,-6596(r28)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + -6596);
	// rlwinm r29,r10,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r29,r26
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r26.u32);
	// lbz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82064e50
	if (!ctx.cr6.eq) goto loc_82064E50;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,840
	ctx.r3.s64 = ctx.r11.s64 + 840;
	// bl 0x8208c5d8
	ctx.lr = 0x82064E4C;
	sub_8208C5D8(ctx, base);
	// b 0x82064e64
	goto loc_82064E64;
loc_82064E50:
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82064e64
	if (ctx.cr6.eq) goto loc_82064E64;
	// lhz r4,26(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 26);
	// bl 0x82050170
	ctx.lr = 0x82064E64;
	sub_82050170(ctx, base);
loc_82064E64:
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x820a0988
	ctx.lr = 0x82064E74;
	sub_820A0988(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x82064f10
	if (!ctx.cr6.eq) goto loc_82064F10;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r6,64
	ctx.r6.s64 = 64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-6624(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// bl 0x82077310
	ctx.lr = 0x82064E98;
	sub_82077310(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82064EAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82065000
	if (ctx.cr6.eq) goto loc_82065000;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x82064EC0;
	sub_82053BC8(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,529
	ctx.r4.s64 = 529;
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x82064ED4;
	sub_82067230(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,530
	ctx.r4.s64 = 530;
	// lwz r3,28(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// bl 0x82067230
	ctx.lr = 0x82064EE8;
	sub_82067230(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,531
	ctx.r4.s64 = 531;
	// lwz r3,32(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 32);
	// bl 0x82067230
	ctx.lr = 0x82064EFC;
	sub_82067230(ctx, base);
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,-22668(r8)
	REX_STORE_U32(ctx.r8.u32 + -22668, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
loc_82064F10:
	// lhz r11,26(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 26);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r7,-6596(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + -6596);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r29,r7
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r7.u32);
	// addi r5,r11,102
	ctx.r5.s64 = ctx.r11.s64 + 102;
	// bl 0x8209d3d8
	ctx.lr = 0x82064F34;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwzx r4,r29,r7
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r7.u32);
	// bl 0x8209d488
	ctx.lr = 0x82064F44;
	sub_8209D488(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r4,r10,18612
	ctx.r4.s64 = ctx.r10.s64 + 18612;
	// bl 0x8209d948
	ctx.lr = 0x82064F54;
	sub_8209D948(ctx, base);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82064F6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82085078
	ctx.lr = 0x82064F74;
	sub_82085078(ctx, base);
	// lbz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// addi r6,r11,255
	ctx.r6.s64 = ctx.r11.s64 + 255;
	// clrlwi r4,r6,24
	ctx.r4.u64 = ctx.r6.u32 & 0xFF;
	// stb r4,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r4.u8);
	// bl 0x82087f70
	ctx.lr = 0x82064F88;
	sub_82087F70(ctx, base);
	// lwz r11,-6596(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -6596);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwzx r4,r29,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// bl 0x8209d488
	ctx.lr = 0x82064F9C;
	sub_8209D488(ctx, base);
	// lbz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// addi r4,r5,18620
	ctx.r4.s64 = ctx.r5.s64 + 18620;
	// clrlwi r29,r10,24
	ctx.r29.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x8209d948
	ctx.lr = 0x82064FB8;
	sub_8209D948(ctx, base);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82064FD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x82064FD8;
	sub_82085078(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82087f70
	ctx.lr = 0x82064FE0;
	sub_82087F70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820643e0
	ctx.lr = 0x82064FE8;
	sub_820643E0(ctx, base);
	// lwz r7,0(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,172(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 172);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82065000;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82065000:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
