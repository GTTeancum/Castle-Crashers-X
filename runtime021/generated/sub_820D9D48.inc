DEFINE_REX_FUNC(sub_820D9D48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820D9D50;
	__savegprlr_24(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// bl 0x82053a98
	ctx.lr = 0x820D9D60;
	sub_82053A98(ctx, base);
	// lbz r11,1(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 1);
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stb r11,128(r30)
	REX_STORE_U8(ctx.r30.u32 + 128, ctx.r11.u8);
	// beq cr6,0x820d9e48
	if (ctx.cr6.eq) goto loc_820D9E48;
	// lis r11,1489
	ctx.r11.s64 = 97583104;
	// ori r10,r11,29789
	ctx.r10.u64 = ctx.r11.u64 | 29789;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x820d9d9c
	if (ctx.cr6.gt) goto loc_820D9D9C;
	// mulli r11,r31,44
	ctx.r11.s64 = static_cast<int64_t>(ctx.r31.u64 * static_cast<uint64_t>(44));
	// li r10,-5
	ctx.r10.s64 = -5;
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820d9da0
	if (!ctx.cr6.gt) goto loc_820D9DA0;
loc_820D9D9C:
	// li r4,-1
	ctx.r4.s64 = -1;
loc_820D9DA0:
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820D9DB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820d9e28
	if (ctx.cr6.eq) goto loc_820D9E28;
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// stw r31,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// addic. r7,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r7.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// blt 0x820d9e20
	if (ctx.cr0.lt) goto loc_820D9E20;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r6,24
	ctx.r6.s64 = 24;
loc_820D9DDC:
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// stw r10,-12(r11)
	REX_STORE_U32(ctx.r11.u32 + -12, ctx.r10.u32);
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// stw r10,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r10.u32);
	// stw r5,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r5.u32);
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r9,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r9.u32);
	// addi r10,r10,44
	ctx.r10.s64 = ctx.r10.s64 + 44;
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r6,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r6.u32);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// stw r8,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// stw r9,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// stw r8,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r8.u32);
	// addi r11,r11,44
	ctx.r11.s64 = ctx.r11.s64 + 44;
	// bge 0x820d9ddc
	if (!ctx.cr0.lt) goto loc_820D9DDC;
loc_820D9E20:
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// b 0x820d9e2c
	goto loc_820D9E2C;
loc_820D9E28:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_820D9E2C:
	// stw r11,124(r30)
	REX_STORE_U32(ctx.r30.u32 + 124, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820d9e48
	if (!ctx.cr6.eq) goto loc_820D9E48;
loc_820D9E38:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
loc_820D9E48:
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d9e5c
	if (ctx.cr6.eq) goto loc_820D9E5C;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// b 0x820d9e68
	goto loc_820D9E68;
loc_820D9E5C:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r11,-32560
	ctx.r10.s64 = ctx.r11.s64 + -32560;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
loc_820D9E68:
	// addi r5,r30,60
	ctx.r5.s64 = ctx.r30.s64 + 60;
	// lwz r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x820db8b8
	ctx.lr = 0x820D9E78;
	sub_820DB8B8(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// blt cr6,0x820da0dc
	if (ctx.cr6.lt) goto loc_820DA0DC;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// li r27,1
	ctx.r27.s64 = 1;
	// addi r11,r10,22944
	ctx.r11.s64 = ctx.r10.s64 + 22944;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// lis r6,-32221
	ctx.r6.s64 = -2111635456;
	// stb r9,22944(r10)
	REX_STORE_U8(ctx.r10.u32 + 22944, ctx.r9.u8);
	// addi r7,r11,8
	ctx.r7.s64 = ctx.r11.s64 + 8;
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// addi r10,r6,22928
	ctx.r10.s64 = ctx.r6.s64 + 22928;
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// stb r8,22928(r6)
	REX_STORE_U8(ctx.r6.u32 + 22928, ctx.r8.u8);
	// addi r9,r10,8
	ctx.r9.s64 = ctx.r10.s64 + 8;
	// stw r7,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// lis r4,-32221
	ctx.r4.s64 = -2111635456;
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// stw r9,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// addi r3,r4,22908
	ctx.r3.s64 = ctx.r4.s64 + 22908;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214ac34
	ctx.lr = 0x820D9EEC;
	__imp__KeInitializeSemaphore(ctx, base);
	// lis r3,-32221
	ctx.r3.s64 = -2111635456;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// addi r11,r3,22892
	ctx.r11.s64 = ctx.r3.s64 + 22892;
	// lis r6,-32221
	ctx.r6.s64 = -2111635456;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// stb r10,22892(r3)
	REX_STORE_U8(ctx.r3.u32 + 22892, ctx.r10.u8);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// addi r3,r6,22876
	ctx.r3.s64 = ctx.r6.s64 + 22876;
	// lis r7,-32242
	ctx.r7.s64 = -2113011712;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// addi r10,r11,8
	ctx.r10.s64 = ctx.r11.s64 + 8;
	// addi r9,r7,-29264
	ctx.r9.s64 = ctx.r7.s64 + -29264;
	// lis r8,32128
	ctx.r8.s64 = 2105540608;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r9,22876(r6)
	REX_STORE_U32(ctx.r6.u32 + 22876, ctx.r9.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r8,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// bl 0x8214a844
	ctx.lr = 0x820D9F38;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
	// stw r25,304(r30)
	REX_STORE_U32(ctx.r30.u32 + 304, ctx.r25.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lbz r3,2(r24)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r24.u32 + 2);
	// bl 0x820d87c0
	ctx.lr = 0x820D9F48;
	sub_820D87C0(ctx, base);
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// addi r29,r30,308
	ctx.r29.s64 = ctx.r30.s64 + 308;
	// lis r28,-32256
	ctx.r28.s64 = -2113929216;
loc_820D9F54:
	// addi r11,r1,98
	ctx.r11.s64 = ctx.r1.s64 + 98;
	// stw r25,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r25.u32);
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// clrlwi r10,r11,30
	ctx.r10.u64 = ctx.r11.u32 & 0x3;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d9fe8
	if (ctx.cr6.eq) goto loc_820D9FE8;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// addi r7,r10,-25992
	ctx.r7.s64 = ctx.r10.s64 + -25992;
	// bne cr6,0x820d9f84
	if (!ctx.cr6.eq) goto loc_820D9F84;
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// addi r7,r11,-26192
	ctx.r7.s64 = ctx.r11.s64 + -26192;
loc_820D9F84:
	// slw r11,r27,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r31.u8 & 0x3F));
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwimi r9,r11,24,0,7
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF000000) | (ctx.r9.u64 & 0xFFFFFFFF00FFFFFF);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x8214a5e4
	ctx.lr = 0x820D9FA8;
	__imp__ExCreateThread(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820d9e38
	if (ctx.cr6.lt) goto loc_820D9E38;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,1684(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 1684);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214a474
	ctx.lr = 0x820D9FC0;
	__imp__ObReferenceObjectByHandle(ctx, base);
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8214a464
	ctx.lr = 0x820D9FCC;
	__imp__KeSetBasePriorityThread(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8214ac24
	ctx.lr = 0x820D9FD4;
	__imp__KeResumeThread(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8214a454
	ctx.lr = 0x820D9FDC;
	__imp__ObDereferenceObject(ctx, base);
	// lwz r11,304(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 304);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,304(r30)
	REX_STORE_U32(ctx.r30.u32 + 304, ctx.r11.u32);
loc_820D9FE8:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,6
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 6, ctx.xer);
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// blt cr6,0x820d9f54
	if (ctx.cr6.lt) goto loc_820D9F54;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lbz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// std r25,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r25.u64);
	// std r25,8(r10)
	REX_STORE_U64(ctx.r10.u32 + 8, ctx.r25.u64);
	// stw r25,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r25.u32);
	// stb r25,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r25.u8);
	// stb r25,116(r1)
	REX_STORE_U8(ctx.r1.u32 + 116, ctx.r25.u8);
	// bgt cr6,0x820da028
	if (ctx.cr6.gt) goto loc_820DA028;
	// li r11,6
	ctx.r11.s64 = 6;
loc_820DA028:
	// lis r10,0
	ctx.r10.s64 = 0;
	// stb r11,117(r1)
	REX_STORE_U8(ctx.r1.u32 + 117, ctx.r11.u8);
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// ori r8,r10,48000
	ctx.r8.u64 = ctx.r10.u64 | 48000;
	// li r29,3
	ctx.r29.s64 = 3;
	// stw r8,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
loc_820DA040:
	// addi r11,r1,98
	ctx.r11.s64 = ctx.r1.s64 + 98;
	// lbzx r10,r28,r11
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820da084
	if (ctx.cr6.eq) goto loc_820DA084;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
loc_820DA054:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// blt cr6,0x820da084
	if (ctx.cr6.lt) goto loc_820DA084;
	// add r11,r29,r31
	ctx.r11.u64 = ctx.r29.u64 + ctx.r31.u64;
	// lwz r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x820e29d0
	ctx.lr = 0x820DA074;
	sub_820E29D0(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,2
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 2, ctx.xer);
	// blt cr6,0x820da054
	if (ctx.cr6.lt) goto loc_820DA054;
loc_820DA084:
	// addi r29,r29,2
	ctx.r29.s64 = ctx.r29.s64 + 2;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplwi cr6,r29,15
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 15, ctx.xer);
	// blt cr6,0x820da040
	if (ctx.cr6.lt) goto loc_820DA040;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// blt cr6,0x820da0dc
	if (ctx.cr6.lt) goto loc_820DA0DC;
	// addi r31,r30,64
	ctx.r31.s64 = ctx.r30.s64 + 64;
	// lwz r3,8(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820e3040
	ctx.lr = 0x820DA0AC;
	sub_820E3040(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820da0e0
	if (ctx.cr6.lt) goto loc_820DA0E0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// addi r4,r10,11056
	ctx.r4.s64 = ctx.r10.s64 + 11056;
	// lwz r3,68(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,28(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820DA0D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
loc_820DA0DC:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_820DA0E0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
