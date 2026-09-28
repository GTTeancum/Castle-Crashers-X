DEFINE_REX_FUNC(sub_8206B5D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8206B5D8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r4,r11,18344
	ctx.r4.s64 = ctx.r11.s64 + 18344;
	// lwz r31,48(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// lwz r3,8(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r10,276(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 276);
	// lhz r28,8(r31)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// lwz r30,56(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// bl 0x8209d948
	ctx.lr = 0x8206B600;
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
	ctx.lr = 0x8206B618;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82085078
	ctx.lr = 0x8206B620;
	sub_82085078(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r7,0(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r6,160(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 160);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8206B634;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8206b9a8
	if (ctx.cr6.lt) goto loc_8206B9A8;
	// beq cr6,0x8206b7c8
	if (ctx.cr6.eq) goto loc_8206B7C8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8206baa8
	if (!ctx.cr6.lt) goto loc_8206BAA8;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,25
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 25, ctx.xer);
	// blt cr6,0x8206baa8
	if (ctx.cr6.lt) goto loc_8206BAA8;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// bgt cr6,0x8206baa8
	if (ctx.cr6.gt) goto loc_8206BAA8;
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820654f8
	ctx.lr = 0x8206B66C;
	sub_820654F8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206b6cc
	if (ctx.cr6.eq) goto loc_8206B6CC;
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
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8206B6C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206B6CC:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820657b0
	ctx.lr = 0x8206B6D8;
	sub_820657B0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206b738
	if (ctx.cr6.eq) goto loc_8206B738;
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
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8206B730;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206B738:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82065898
	ctx.lr = 0x8206B744;
	sub_82065898(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206baa8
	if (ctx.cr6.eq) goto loc_8206BAA8;
	// li r10,1
	ctx.r10.s64 = 1;
	// lhz r4,10(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 10);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82053c70
	ctx.lr = 0x8206B774;
	sub_82053C70(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206baa8
	if (ctx.cr6.eq) goto loc_8206BAA8;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r4,25
	ctx.r4.s64 = 25;
	// sth r11,12(r29)
	REX_STORE_U16(ctx.r29.u32 + 12, ctx.r11.u16);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8206B794;
	sub_82053BC8(ctx, base);
	// lhz r11,12(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8206b98c
	if (ctx.cr6.lt) goto loc_8206B98C;
	// beq cr6,0x8206b970
	if (ctx.cr6.eq) goto loc_8206B970;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8206b954
	if (ctx.cr6.eq) goto loc_8206B954;
	// lwz r11,48(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// li r4,582
	ctx.r4.s64 = 582;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206B7C0;
	sub_82067230(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206B7C8:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,13
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 13, ctx.xer);
	// blt cr6,0x8206b7dc
	if (ctx.cr6.lt) goto loc_8206B7DC;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// ble cr6,0x8206b7ec
	if (!ctx.cr6.gt) goto loc_8206B7EC;
loc_8206B7DC:
	// cmplwi cr6,r11,41
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 41, ctx.xer);
	// blt cr6,0x8206baa8
	if (ctx.cr6.lt) goto loc_8206BAA8;
	// cmplwi cr6,r11,48
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 48, ctx.xer);
	// bgt cr6,0x8206baa8
	if (ctx.cr6.gt) goto loc_8206BAA8;
loc_8206B7EC:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820655e0
	ctx.lr = 0x8206B7F8;
	sub_820655E0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206b858
	if (ctx.cr6.eq) goto loc_8206B858;
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// lis r10,30583
	ctx.r10.s64 = 2004287488;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// ori r7,r10,30719
	ctx.r7.u64 = ctx.r10.u64 | 30719;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-1
	ctx.r9.s64 = -65536;
	// li r4,17
	ctx.r4.s64 = 17;
	// ori r11,r9,255
	ctx.r11.u64 = ctx.r9.u64 | 255;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8206B850;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206B858:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820657b0
	ctx.lr = 0x8206B864;
	sub_820657B0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206b8c4
	if (ctx.cr6.eq) goto loc_8206B8C4;
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
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8206B8BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206B8C4:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82065898
	ctx.lr = 0x8206B8D0;
	sub_82065898(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206baa8
	if (ctx.cr6.eq) goto loc_8206BAA8;
	// li r10,1
	ctx.r10.s64 = 1;
	// lhz r4,10(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 10);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82053c70
	ctx.lr = 0x8206B900;
	sub_82053C70(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206baa8
	if (ctx.cr6.eq) goto loc_8206BAA8;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r4,25
	ctx.r4.s64 = 25;
	// sth r11,12(r29)
	REX_STORE_U16(ctx.r29.u32 + 12, ctx.r11.u16);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8206B920;
	sub_82053BC8(ctx, base);
	// lhz r11,12(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8206b98c
	if (ctx.cr6.lt) goto loc_8206B98C;
	// beq cr6,0x8206b970
	if (ctx.cr6.eq) goto loc_8206B970;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8206b954
	if (ctx.cr6.eq) goto loc_8206B954;
	// lwz r11,48(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// li r4,582
	ctx.r4.s64 = 582;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206B94C;
	sub_82067230(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206B954:
	// lwz r11,48(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// li r4,390
	ctx.r4.s64 = 390;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206B968;
	sub_82067230(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206B970:
	// lwz r11,48(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// li r4,389
	ctx.r4.s64 = 389;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206B984;
	sub_82067230(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206B98C:
	// lwz r11,48(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// li r4,382
	ctx.r4.s64 = 382;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206B9A0;
	sub_82067230(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206B9A8:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8206b9cc
	if (ctx.cr6.eq) goto loc_8206B9CC;
	// cmplwi cr6,r11,78
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 78, ctx.xer);
	// bge cr6,0x8206b9cc
	if (!ctx.cr6.lt) goto loc_8206B9CC;
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// blt cr6,0x8206baa8
	if (ctx.cr6.lt) goto loc_8206BAA8;
	// cmplwi cr6,r11,63
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 63, ctx.xer);
	// bgt cr6,0x8206baa8
	if (ctx.cr6.gt) goto loc_8206BAA8;
loc_8206B9CC:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820656c8
	ctx.lr = 0x8206B9D8;
	sub_820656C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206ba38
	if (ctx.cr6.eq) goto loc_8206BA38;
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
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8206BA30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206BA38:
	// li r4,-2
	ctx.r4.s64 = -2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82065898
	ctx.lr = 0x8206BA44;
	sub_82065898(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206baa8
	if (ctx.cr6.eq) goto loc_8206BAA8;
	// li r10,1
	ctx.r10.s64 = 1;
	// lhz r4,10(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 10);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82053c70
	ctx.lr = 0x8206BA74;
	sub_82053C70(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206baa8
	if (ctx.cr6.eq) goto loc_8206BAA8;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r29)
	REX_STORE_U16(ctx.r29.u32 + 12, ctx.r11.u16);
	// li r4,2
	ctx.r4.s64 = 2;
	// sth r10,14(r29)
	REX_STORE_U16(ctx.r29.u32 + 14, ctx.r10.u16);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x820b5d30
	ctx.lr = 0x8206BA9C;
	sub_820B5D30(ctx, base);
	// li r4,23
	ctx.r4.s64 = 23;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8206BAA8;
	sub_82053BC8(ctx, base);
loc_8206BAA8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
