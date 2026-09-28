DEFINE_REX_FUNC(sub_820641D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820641E0;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r11,56(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 56);
	// lwz r26,48(r27)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r27.u32 + 48);
	// addi r11,r11,6104
	ctx.r11.s64 = ctx.r11.s64 + 6104;
	// lhz r31,30(r27)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r27.u32 + 30);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x820643d8
	if (ctx.cr6.eq) goto loc_820643D8;
	// lwz r11,276(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 276);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// addi r4,r10,18404
	ctx.r4.s64 = ctx.r10.s64 + 18404;
	// lwz r30,56(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// bl 0x8209d948
	ctx.lr = 0x82064218;
	sub_8209D948(ctx, base);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82064230;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82085078
	ctx.lr = 0x82064238;
	sub_82085078(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,160(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 160);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82064248;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r5,r3,16
	ctx.r5.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r5,1
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1, ctx.xer);
	// bne cr6,0x820643d8
	if (!ctx.cr6.eq) goto loc_820643D8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x820657b0
	ctx.lr = 0x82064260;
	sub_820657B0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82064308
	if (ctx.cr6.eq) goto loc_82064308;
	// clrlwi r11,r31,16
	ctx.r11.u64 = ctx.r31.u32 & 0xFFFF;
	// lhz r31,26(r27)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r27.u32 + 26);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// rlwinm r29,r9,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r30,-6596(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + -6596);
loc_82064284:
	// clrlwi r11,r31,16
	ctx.r11.u64 = ctx.r31.u32 & 0xFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r31,28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 28, ctx.xer);
	// blt cr6,0x8206429c
	if (ctx.cr6.lt) goto loc_8206429C;
	// li r31,0
	ctx.r31.s64 = 0;
loc_8206429C:
	// clrlwi r11,r31,16
	ctx.r11.u64 = ctx.r31.u32 & 0xFFFF;
	// lwzx r4,r29,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8209d3d8
	ctx.lr = 0x820642BC;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r4,r29,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x820642CC;
	sub_8209D488(ctx, base);
	// lbz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r9,128
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 128, ctx.xer);
	// bne cr6,0x82064284
	if (!ctx.cr6.eq) goto loc_82064284;
	// sth r31,26(r27)
	REX_STORE_U16(ctx.r27.u32 + 26, ctx.r31.u16);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r11,284(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 284);
	// lwz r3,56(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,172(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820642F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820643e0
	ctx.lr = 0x82064300;
	sub_820643E0(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x820643c0
	goto loc_820643C0;
loc_82064308:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x820656c8
	ctx.lr = 0x82064314;
	sub_820656C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820643d8
	if (ctx.cr6.eq) goto loc_820643D8;
	// clrlwi r11,r31,16
	ctx.r11.u64 = ctx.r31.u32 & 0xFFFF;
	// lhz r31,26(r27)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r27.u32 + 26);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// lis r11,0
	ctx.r11.s64 = 0;
	// rlwinm r29,r9,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r28,r11,65535
	ctx.r28.u64 = ctx.r11.u64 | 65535;
	// lwz r30,-6596(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + -6596);
loc_82064340:
	// clrlwi r11,r31,16
	ctx.r11.u64 = ctx.r31.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82064350
	if (!ctx.cr6.eq) goto loc_82064350;
	// li r31,28
	ctx.r31.s64 = 28;
loc_82064350:
	// clrlwi r11,r31,16
	ctx.r11.u64 = ctx.r31.u32 & 0xFFFF;
	// lwzx r4,r29,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + ctx.r28.u64;
	// clrlwi r31,r10,16
	ctx.r31.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r9,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8209d3d8
	ctx.lr = 0x82064378;
	sub_8209D3D8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwzx r4,r29,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x82064388;
	sub_8209D488(ctx, base);
	// lbz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r7,128
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 128, ctx.xer);
	// bne cr6,0x82064340
	if (!ctx.cr6.eq) goto loc_82064340;
	// sth r31,26(r27)
	REX_STORE_U16(ctx.r27.u32 + 26, ctx.r31.u16);
	// li r4,18
	ctx.r4.s64 = 18;
	// lwz r11,284(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 284);
	// lwz r3,56(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,172(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820643B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820643e0
	ctx.lr = 0x820643BC;
	sub_820643E0(ctx, base);
	// li r4,18
	ctx.r4.s64 = 18;
loc_820643C0:
	// lwz r8,276(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + 276);
	// lwz r3,56(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 56);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,172(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 172);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820643D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820643D8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
