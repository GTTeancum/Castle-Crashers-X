DEFINE_REX_FUNC(sub_820D1C30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820D1C38;
	__savegprlr_25(ctx, base);
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r10,22360
	ctx.r9.s64 = ctx.r10.s64 + 22360;
	// addi r29,r11,6
	ctx.r29.s64 = ctx.r11.s64 + 6;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lwz r10,22360(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 22360);
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// lis r27,-32038
	ctx.r27.s64 = -2099642368;
	// lwz r11,4(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// li r5,54
	ctx.r5.s64 = 54;
	// lhz r9,8(r9)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,90
	ctx.r3.s64 = ctx.r1.s64 + 90;
	// ori r27,r27,7
	ctx.r27.u64 = ctx.r27.u64 | 7;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// sth r9,88(r1)
	REX_STORE_U16(ctx.r1.u32 + 88, ctx.r9.u16);
	// bl 0x82129fa0
	ctx.lr = 0x820D1C84;
	sub_82129FA0(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r9,r11,22344
	ctx.r9.s64 = ctx.r11.s64 + 22344;
	// addi r10,r10,6864
	ctx.r10.s64 = ctx.r10.s64 + 6864;
	// li r5,51
	ctx.r5.s64 = 51;
	// stw r10,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,22344(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 22344);
	// addi r3,r1,161
	ctx.r3.s64 = ctx.r1.s64 + 161;
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r8,8(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lbz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 12);
	// stw r11,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// stw r10,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r10.u32);
	// stw r8,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r8.u32);
	// stb r9,160(r1)
	REX_STORE_U8(ctx.r1.u32 + 160, ctx.r9.u8);
	// bl 0x82129fa0
	ctx.lr = 0x820D1CC8;
	sub_82129FA0(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r9,r11,22332
	ctx.r9.s64 = ctx.r11.s64 + 22332;
	// addi r10,r10,6888
	ctx.r10.s64 = ctx.r10.s64 + 6888;
	// li r5,54
	ctx.r5.s64 = 54;
	// stw r10,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,22332(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 22332);
	// addi r3,r1,226
	ctx.r3.s64 = ctx.r1.s64 + 226;
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lhz r9,8(r9)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + 8);
	// stw r11,216(r1)
	REX_STORE_U32(ctx.r1.u32 + 216, ctx.r11.u32);
	// stw r10,220(r1)
	REX_STORE_U32(ctx.r1.u32 + 220, ctx.r10.u32);
	// sth r9,224(r1)
	REX_STORE_U16(ctx.r1.u32 + 224, ctx.r9.u16);
	// bl 0x82129fa0
	ctx.lr = 0x820D1D04;
	sub_82129FA0(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r10,r10,6912
	ctx.r10.s64 = ctx.r10.s64 + 6912;
	// addi r11,r11,22312
	ctx.r11.s64 = ctx.r11.s64 + 22312;
	// stw r10,280(r1)
	REX_STORE_U32(ctx.r1.u32 + 280, ctx.r10.u32);
	// addi r9,r1,284
	ctx.r9.s64 = ctx.r1.s64 + 284;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// li r11,19
	ctx.r11.s64 = 19;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820D1D28:
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r11,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r11.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bdnz 0x820d1d28
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820D1D28;
	// li r5,45
	ctx.r5.s64 = 45;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,303
	ctx.r3.s64 = ctx.r1.s64 + 303;
	// bl 0x82129fa0
	ctx.lr = 0x820D1D4C;
	sub_82129FA0(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,22284
	ctx.r4.s64 = ctx.r11.s64 + 22284;
	// addi r11,r10,6968
	ctx.r11.s64 = ctx.r10.s64 + 6968;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// li r5,27
	ctx.r5.s64 = 27;
	// stw r11,348(r1)
	REX_STORE_U32(ctx.r1.u32 + 348, ctx.r11.u32);
	// bl 0x82129a70
	ctx.lr = 0x820D1D6C;
	sub_82129A70(ctx, base);
	// li r5,37
	ctx.r5.s64 = 37;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,379
	ctx.r3.s64 = ctx.r1.s64 + 379;
	// bl 0x82129fa0
	ctx.lr = 0x820D1D7C;
	sub_82129FA0(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,22256
	ctx.r4.s64 = ctx.r11.s64 + 22256;
	// addi r11,r10,7056
	ctx.r11.s64 = ctx.r10.s64 + 7056;
	// addi r3,r1,420
	ctx.r3.s64 = ctx.r1.s64 + 420;
	// li r5,25
	ctx.r5.s64 = 25;
	// stw r11,416(r1)
	REX_STORE_U32(ctx.r1.u32 + 416, ctx.r11.u32);
	// bl 0x82129a70
	ctx.lr = 0x820D1D9C;
	sub_82129A70(ctx, base);
	// li r5,39
	ctx.r5.s64 = 39;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,445
	ctx.r3.s64 = ctx.r1.s64 + 445;
	// bl 0x82129fa0
	ctx.lr = 0x820D1DAC;
	sub_82129FA0(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r9,r11,22240
	ctx.r9.s64 = ctx.r11.s64 + 22240;
	// addi r10,r10,7152
	ctx.r10.s64 = ctx.r10.s64 + 7152;
	// li r5,49
	ctx.r5.s64 = 49;
	// stw r10,484(r1)
	REX_STORE_U32(ctx.r1.u32 + 484, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,22240(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 22240);
	// addi r3,r1,503
	ctx.r3.s64 = ctx.r1.s64 + 503;
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r8,8(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lhz r7,12(r9)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r9.u32 + 12);
	// lbz r9,14(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 14);
	// stw r11,488(r1)
	REX_STORE_U32(ctx.r1.u32 + 488, ctx.r11.u32);
	// stw r10,492(r1)
	REX_STORE_U32(ctx.r1.u32 + 492, ctx.r10.u32);
	// stw r8,496(r1)
	REX_STORE_U32(ctx.r1.u32 + 496, ctx.r8.u32);
	// sth r7,500(r1)
	REX_STORE_U16(ctx.r1.u32 + 500, ctx.r7.u16);
	// stb r9,502(r1)
	REX_STORE_U8(ctx.r1.u32 + 502, ctx.r9.u8);
	// bl 0x82129fa0
	ctx.lr = 0x820D1DF8;
	sub_82129FA0(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r9,r11,22224
	ctx.r9.s64 = ctx.r11.s64 + 22224;
	// addi r10,r10,7128
	ctx.r10.s64 = ctx.r10.s64 + 7128;
	// li r5,51
	ctx.r5.s64 = 51;
	// stw r10,552(r1)
	REX_STORE_U32(ctx.r1.u32 + 552, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,22224(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 22224);
	// addi r3,r1,569
	ctx.r3.s64 = ctx.r1.s64 + 569;
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r8,8(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lbz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 12);
	// stw r11,556(r1)
	REX_STORE_U32(ctx.r1.u32 + 556, ctx.r11.u32);
	// stw r10,560(r1)
	REX_STORE_U32(ctx.r1.u32 + 560, ctx.r10.u32);
	// stw r8,564(r1)
	REX_STORE_U32(ctx.r1.u32 + 564, ctx.r8.u32);
	// stb r9,568(r1)
	REX_STORE_U8(ctx.r1.u32 + 568, ctx.r9.u8);
	// bl 0x82129fa0
	ctx.lr = 0x820D1E3C;
	sub_82129FA0(ctx, base);
	// lis r11,-32243
	ctx.r11.s64 = -2113077248;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,7152
	ctx.r11.s64 = ctx.r11.s64 + 7152;
	// addi r31,r1,80
	ctx.r31.s64 = ctx.r1.s64 + 80;
	// stw r11,620(r1)
	REX_STORE_U32(ctx.r1.u32 + 620, ctx.r11.u32);
loc_820D1E50:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_820D1E54:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820d1e54
	if (!ctx.cr6.eq) goto loc_820D1E54;
	// subf r11,r31,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r31.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rotlwi r30,r11,0
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x82127fe0
	ctx.lr = 0x820D1E80;
	sub_82127FE0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820d1eb8
	if (ctx.cr0.eq) goto loc_820D1EB8;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r31,r31,68
	ctx.r31.s64 = ctx.r31.s64 + 68;
	// cmplwi cr6,r28,8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 8, ctx.xer);
	// blt cr6,0x820d1e50
	if (ctx.cr6.lt) goto loc_820D1E50;
loc_820D1E98:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r4,r11,14312
	ctx.r4.s64 = ctx.r11.s64 + 14312;
loc_820D1EA0:
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82128830
	ctx.lr = 0x820D1EAC;
	sub_82128830(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820D1EB8:
	// mulli r10,r28,68
	ctx.r10.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(68));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// add r11,r30,r29
	ctx.r11.u64 = ctx.r30.u64 + ctx.r29.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// lwzx r11,r10,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820D1ED4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r27,730
	ctx.r27.s64 = 47841280;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820d1e98
	if (ctx.cr0.eq) goto loc_820D1E98;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r4,r11,22216
	ctx.r4.s64 = ctx.r11.s64 + 22216;
	// b 0x820d1ea0
	goto loc_820D1EA0;
}
