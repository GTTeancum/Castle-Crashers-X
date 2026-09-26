DEFINE_REX_FUNC(sub_8206C1D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8206C1D8;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8206c230
	if (!ctx.cr6.eq) goto loc_8206C230;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f0,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// stb r9,424(r10)
	REX_STORE_U8(ctx.r10.u32 + 424, ctx.r9.u8);
	// stfs f0,428(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 428, temp.u32);
	// stb r8,340(r10)
	REX_STORE_U8(ctx.r10.u32 + 340, ctx.r8.u8);
	// lwz r7,48(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lhz r6,10(r7)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r7.u32 + 10);
	// cmplwi cr6,r6,32768
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 32768, ctx.xer);
	// blt cr6,0x8206c508
	if (ctx.cr6.lt) goto loc_8206C508;
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// li r11,-2
	ctx.r11.s64 = -2;
	// sth r11,12(r10)
	REX_STORE_U16(ctx.r10.u32 + 12, ctx.r11.u16);
	// sth r11,10(r10)
	REX_STORE_U16(ctx.r10.u32 + 10, ctx.r11.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206C230:
	// rlwinm r11,r4,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c298
	if (ctx.cr6.eq) goto loc_8206C298;
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,-22668(r10)
	REX_STORE_U32(ctx.r10.u32 + -22668, ctx.r11.u32);
	// bl 0x82053bc8
	ctx.lr = 0x8206C254;
	sub_82053BC8(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,585
	ctx.r4.s64 = 585;
	// lwz r3,24(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x8206C268;
	sub_82067230(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,586
	ctx.r4.s64 = 586;
	// lwz r3,28(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 28);
	// bl 0x82067230
	ctx.lr = 0x8206C27C;
	sub_82067230(ctx, base);
	// lwz r7,48(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 32);
	// bl 0x82067230
	ctx.lr = 0x8206C290;
	sub_82067230(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206C298:
	// rlwinm r11,r4,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c300
	if (ctx.cr6.eq) goto loc_8206C300;
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,-22668(r10)
	REX_STORE_U32(ctx.r10.u32 + -22668, ctx.r11.u32);
	// bl 0x82053bc8
	ctx.lr = 0x8206C2BC;
	sub_82053BC8(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,529
	ctx.r4.s64 = 529;
	// lwz r3,24(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x8206C2D0;
	sub_82067230(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,530
	ctx.r4.s64 = 530;
	// lwz r3,28(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 28);
	// bl 0x82067230
	ctx.lr = 0x8206C2E4;
	sub_82067230(ctx, base);
	// lwz r7,48(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r4,531
	ctx.r4.s64 = 531;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 32);
	// bl 0x82067230
	ctx.lr = 0x8206C2F8;
	sub_82067230(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206C300:
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r29,-32218
	ctx.r29.s64 = -2111438848;
	// lis r8,30583
	ctx.r8.s64 = 2004287488;
	// lis r7,-1
	ctx.r7.s64 = -65536;
	// ori r6,r8,30719
	ctx.r6.u64 = ctx.r8.u64 | 30719;
	// li r28,1
	ctx.r28.s64 = 1;
	// lhz r10,8(r9)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r9.u32 + 8);
	// ori r5,r7,255
	ctx.r5.u64 = ctx.r7.u64 | 255;
	// lwz r11,-6628(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// addi r4,r10,5
	ctx.r4.s64 = ctx.r10.s64 + 5;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r3,r9
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// stw r6,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r6.u32);
	// sth r28,8(r9)
	REX_STORE_U16(ctx.r9.u32 + 8, ctx.r28.u16);
	// lwz r9,24(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 24);
	// stw r5,16(r9)
	REX_STORE_U32(ctx.r9.u32 + 16, ctx.r5.u32);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c354
	if (ctx.cr6.eq) goto loc_8206C354;
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// b 0x8206c358
	goto loc_8206C358;
loc_8206C354:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8206C358:
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r30,48(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 48);
	// bne cr6,0x8206c3a0
	if (!ctx.cr6.eq) goto loc_8206C3A0;
	// li r11,222
	ctx.r11.s64 = 222;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-6624(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x8206C388;
	sub_82052EA8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beq cr6,0x8206c3a0
	if (ctx.cr6.eq) goto loc_8206C3A0;
	// stb r27,21(r30)
	REX_STORE_U8(ctx.r30.u32 + 21, ctx.r27.u8);
	// li r4,393
	ctx.r4.s64 = 393;
	// b 0x8206c3a8
	goto loc_8206C3A8;
loc_8206C3A0:
	// stb r28,21(r30)
	REX_STORE_U8(ctx.r30.u32 + 21, ctx.r28.u8);
	// li r4,0
	ctx.r4.s64 = 0;
loc_8206C3A8:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82067230
	ctx.lr = 0x8206C3B4;
	sub_82067230(ctx, base);
	// lwz r11,-6628(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,20(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r3,20(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8206c3e8
	if (ctx.cr6.eq) goto loc_8206C3E8;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206c3e8
	if (ctx.cr6.eq) goto loc_8206C3E8;
	// lbz r11,1185(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// bne cr6,0x8206c3ec
	if (!ctx.cr6.eq) goto loc_8206C3EC;
loc_8206C3E8:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8206C3EC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// bne cr6,0x8206c404
	if (!ctx.cr6.eq) goto loc_8206C404;
	// li r4,392
	ctx.r4.s64 = 392;
loc_8206C404:
	// bl 0x82067230
	ctx.lr = 0x8206C408;
	sub_82067230(ctx, base);
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lbz r9,2704(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 2704);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r30,28(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// beq cr6,0x8206c428
	if (ctx.cr6.eq) goto loc_8206C428;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x8206c42c
	goto loc_8206C42C;
loc_8206C428:
	// bl 0x820a0f88
	ctx.lr = 0x8206C42C;
	sub_820A0F88(ctx, base);
loc_8206C42C:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r4,601
	ctx.r4.s64 = 601;
	// bne cr6,0x8206c448
	if (!ctx.cr6.eq) goto loc_8206C448;
	// li r4,600
	ctx.r4.s64 = 600;
loc_8206C448:
	// bl 0x82067230
	ctx.lr = 0x8206C44C;
	sub_82067230(ctx, base);
	// lwz r3,-6628(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r31,44(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// beq cr6,0x8206c484
	if (ctx.cr6.eq) goto loc_8206C484;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c484
	if (ctx.cr6.eq) goto loc_8206C484;
	// lbz r11,1185(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// bne cr6,0x8206c488
	if (!ctx.cr6.eq) goto loc_8206C488;
loc_8206C484:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8206C488:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c4f4
	if (ctx.cr6.eq) goto loc_8206C4F4;
	// bl 0x82068470
	ctx.lr = 0x8206C498;
	sub_82068470(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c4f4
	if (ctx.cr6.eq) goto loc_8206C4F4;
	// lwz r11,-6628(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -6628);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c4c0
	if (ctx.cr6.eq) goto loc_8206C4C0;
	// lhz r30,2(r11)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x8206c4c4
	goto loc_8206C4C4;
loc_8206C4C0:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8206C4C4:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c4f4
	if (ctx.cr6.eq) goto loc_8206C4F4;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8206c4f4
	if (ctx.cr6.eq) goto loc_8206C4F4;
	// stb r27,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r27.u8);
	// li r4,445
	ctx.r4.s64 = 445;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82067230
	ctx.lr = 0x8206C4EC;
	sub_82067230(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_8206C4F4:
	// stb r28,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r28.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82067230
	ctx.lr = 0x8206C508;
	sub_82067230(ctx, base);
loc_8206C508:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
