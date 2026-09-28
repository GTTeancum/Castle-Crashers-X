DEFINE_REX_FUNC(sub_82063758) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82063760;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,18344
	ctx.r4.s64 = ctx.r11.s64 + 18344;
	// lwz r31,48(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,276(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 276);
	// lhz r28,8(r31)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// lwz r29,56(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// bl 0x8209d948
	ctx.lr = 0x82063788;
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
	ctx.lr = 0x820637A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82085078
	ctx.lr = 0x820637A8;
	sub_82085078(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r6,160(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 160);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820637BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82063ad0
	if (ctx.cr6.lt) goto loc_82063AD0;
	// beq cr6,0x82063948
	if (ctx.cr6.eq) goto loc_82063948;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x82063bf4
	if (!ctx.cr6.lt) goto loc_82063BF4;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,25
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 25, ctx.xer);
	// blt cr6,0x82063bf4
	if (ctx.cr6.lt) goto loc_82063BF4;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// bgt cr6,0x82063bf4
	if (ctx.cr6.gt) goto loc_82063BF4;
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820654f8
	ctx.lr = 0x820637F4;
	sub_820654F8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82063854
	if (ctx.cr6.eq) goto loc_82063854;
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// lis r10,30583
	ctx.r10.s64 = 2004287488;
	// lis r9,-1
	ctx.r9.s64 = -65536;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// ori r7,r10,30719
	ctx.r7.u64 = ctx.r10.u64 | 30719;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,1
	ctx.r5.s64 = 1;
	// ori r11,r9,255
	ctx.r11.u64 = ctx.r9.u64 | 255;
	// li r4,33
	ctx.r4.s64 = 33;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwzx r10,r6,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r31.u32);
	// stw r7,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r7.u32);
	// sth r5,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r5.u16);
	// lwz r9,24(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// stw r11,16(r9)
	REX_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8206384C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82063854:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820657b0
	ctx.lr = 0x82063860;
	sub_820657B0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820638c0
	if (ctx.cr6.eq) goto loc_820638C0;
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// lis r10,30583
	ctx.r10.s64 = 2004287488;
	// lis r5,-1
	ctx.r5.s64 = -65536;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// ori r7,r10,30719
	ctx.r7.u64 = ctx.r10.u64 | 30719;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r11,r5,255
	ctx.r11.u64 = ctx.r5.u64 | 255;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwzx r10,r6,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r31.u32);
	// stw r7,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r7.u32);
	// sth r9,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r9.u16);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r11,16(r9)
	REX_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820638B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_820638C0:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82065898
	ctx.lr = 0x820638CC;
	sub_82065898(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82063bf4
	if (ctx.cr6.eq) goto loc_82063BF4;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// lhz r31,10(r31)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r31.u32 + 10);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,17
	ctx.r5.s64 = 17;
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82053c70
	ctx.lr = 0x82063904;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82063bf4
	if (ctx.cr6.eq) goto loc_82063BF4;
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// sth r11,12(r30)
	REX_STORE_U16(ctx.r30.u32 + 12, ctx.r11.u16);
	// extsh r9,r31
	ctx.r9.s64 = ctx.r31.s16;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// slw r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r9.u8 & 0x3F));
	// lwz r11,-6628(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6628);
	// lwz r7,104(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82063bec
	if (ctx.cr6.eq) goto loc_82063BEC;
	// bl 0x82063f18
	ctx.lr = 0x82063940;
	sub_82063F18(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82063948:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,13
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 13, ctx.xer);
	// blt cr6,0x8206395c
	if (ctx.cr6.lt) goto loc_8206395C;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// ble cr6,0x8206396c
	if (!ctx.cr6.gt) goto loc_8206396C;
loc_8206395C:
	// cmplwi cr6,r11,41
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 41, ctx.xer);
	// blt cr6,0x82063bf4
	if (ctx.cr6.lt) goto loc_82063BF4;
	// cmplwi cr6,r11,48
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 48, ctx.xer);
	// bgt cr6,0x82063bf4
	if (ctx.cr6.gt) goto loc_82063BF4;
loc_8206396C:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820655e0
	ctx.lr = 0x82063978;
	sub_820655E0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820639d8
	if (ctx.cr6.eq) goto loc_820639D8;
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// lis r10,30583
	ctx.r10.s64 = 2004287488;
	// lis r9,-1
	ctx.r9.s64 = -65536;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// ori r7,r10,30719
	ctx.r7.u64 = ctx.r10.u64 | 30719;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,2
	ctx.r5.s64 = 2;
	// ori r11,r9,255
	ctx.r11.u64 = ctx.r9.u64 | 255;
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwzx r10,r6,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r31.u32);
	// stw r7,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r7.u32);
	// sth r5,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r5.u16);
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// stw r11,16(r9)
	REX_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820639D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_820639D8:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820657b0
	ctx.lr = 0x820639E4;
	sub_820657B0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82063a44
	if (ctx.cr6.eq) goto loc_82063A44;
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// lis r10,30583
	ctx.r10.s64 = 2004287488;
	// lis r5,-1
	ctx.r5.s64 = -65536;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// ori r7,r10,30719
	ctx.r7.u64 = ctx.r10.u64 | 30719;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r11,r5,255
	ctx.r11.u64 = ctx.r5.u64 | 255;
	// li r4,49
	ctx.r4.s64 = 49;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwzx r10,r6,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r31.u32);
	// stw r7,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r7.u32);
	// sth r9,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r9.u16);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r11,16(r9)
	REX_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82063A3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82063A44:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82065898
	ctx.lr = 0x82063A50;
	sub_82065898(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82063bf4
	if (ctx.cr6.eq) goto loc_82063BF4;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// lhz r31,10(r31)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r31.u32 + 10);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,17
	ctx.r5.s64 = 17;
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82053c70
	ctx.lr = 0x82063A88;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82063bf4
	if (ctx.cr6.eq) goto loc_82063BF4;
	// li r11,3
	ctx.r11.s64 = 3;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// sth r11,12(r30)
	REX_STORE_U16(ctx.r30.u32 + 12, ctx.r11.u16);
	// extsh r9,r31
	ctx.r9.s64 = ctx.r31.s16;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// slw r7,r8,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// lwz r11,-6628(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6628);
	// lwz r6,104(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// and r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 & ctx.r6.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82063bec
	if (ctx.cr6.eq) goto loc_82063BEC;
	// bl 0x82063dc8
	ctx.lr = 0x82063AC8;
	sub_82063DC8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82063AD0:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82063af4
	if (ctx.cr6.eq) goto loc_82063AF4;
	// cmplwi cr6,r11,78
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 78, ctx.xer);
	// bge cr6,0x82063af4
	if (!ctx.cr6.lt) goto loc_82063AF4;
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// blt cr6,0x82063bf4
	if (ctx.cr6.lt) goto loc_82063BF4;
	// cmplwi cr6,r11,63
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 63, ctx.xer);
	// bgt cr6,0x82063bf4
	if (ctx.cr6.gt) goto loc_82063BF4;
loc_82063AF4:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820656c8
	ctx.lr = 0x82063B00;
	sub_820656C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82063b60
	if (ctx.cr6.eq) goto loc_82063B60;
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// lis r10,30583
	ctx.r10.s64 = 2004287488;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// ori r7,r10,30719
	ctx.r7.u64 = ctx.r10.u64 | 30719;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r5,-1
	ctx.r5.s64 = -65536;
	// li r4,2
	ctx.r4.s64 = 2;
	// ori r11,r5,255
	ctx.r11.u64 = ctx.r5.u64 | 255;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwzx r10,r6,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r31.u32);
	// stw r7,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r7.u32);
	// sth r9,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r9.u16);
	// lwz r9,24(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// stw r11,16(r9)
	REX_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82063B58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82063B60:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82065898
	ctx.lr = 0x82063B6C;
	sub_82065898(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82063bf4
	if (ctx.cr6.eq) goto loc_82063BF4;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// lhz r31,10(r31)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r31.u32 + 10);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,17
	ctx.r5.s64 = 17;
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82053c70
	ctx.lr = 0x82063BA4;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82063bf4
	if (ctx.cr6.eq) goto loc_82063BF4;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// sth r11,12(r30)
	REX_STORE_U16(ctx.r30.u32 + 12, ctx.r11.u16);
	// extsh r9,r31
	ctx.r9.s64 = ctx.r31.s16;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// slw r7,r8,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// lwz r11,-6628(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6628);
	// lwz r6,104(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// and r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 & ctx.r6.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82063bec
	if (ctx.cr6.eq) goto loc_82063BEC;
	// bl 0x82063c00
	ctx.lr = 0x82063BE4;
	sub_82063C00(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82063BEC:
	// li r4,18
	ctx.r4.s64 = 18;
	// bl 0x82053bc8
	ctx.lr = 0x82063BF4;
	sub_82053BC8(ctx, base);
loc_82063BF4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
