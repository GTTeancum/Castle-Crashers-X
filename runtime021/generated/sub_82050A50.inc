DEFINE_REX_FUNC(sub_82050A50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82050A58;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// addi r27,r28,60
	ctx.r27.s64 = ctx.r28.s64 + 60;
	// lis r25,-32218
	ctx.r25.s64 = -2111438848;
	// ori r29,r11,32769
	ctx.r29.u64 = ctx.r11.u64 | 32769;
loc_82050A78:
	// lwz r11,-6628(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -6628);
	// lwz r10,104(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// and r9,r10,r26
	ctx.r9.u64 = ctx.r10.u64 & ctx.r26.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82050f68
	if (ctx.cr6.eq) goto loc_82050F68;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x820a39f0
	ctx.lr = 0x82050A98;
	sub_820A39F0(ctx, base);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82050abc
	if (ctx.cr6.eq) goto loc_82050ABC;
	// li r5,6
	ctx.r5.s64 = 6;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050AB8;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050ABC:
	// clrlwi r30,r5,24
	ctx.r30.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82050c78
	if (ctx.cr6.eq) goto loc_82050C78;
	// lbz r11,12(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82050c78
	if (ctx.cr6.eq) goto loc_82050C78;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// addi r11,r11,-24
	ctx.r11.s64 = ctx.r11.s64 + -24;
	// cmplwi cr6,r11,80
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 80, ctx.xer);
	// bgt cr6,0x82050c64
	if (ctx.cr6.gt) goto loc_82050C64;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,2812
	ctx.r12.s64 = ctx.r12.s64 + 2812;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82050C40;
	case 1:
		goto loc_82050C64;
	case 2:
		goto loc_82050C64;
	case 3:
		goto loc_82050C64;
	case 4:
		goto loc_82050C64;
	case 5:
		goto loc_82050C64;
	case 6:
		goto loc_82050C64;
	case 7:
		goto loc_82050C64;
	case 8:
		goto loc_82050C64;
	case 9:
		goto loc_82050C64;
	case 10:
		goto loc_82050C64;
	case 11:
		goto loc_82050C64;
	case 12:
		goto loc_82050C64;
	case 13:
		goto loc_82050C64;
	case 14:
		goto loc_82050C64;
	case 15:
		goto loc_82050C64;
	case 16:
		goto loc_82050C64;
	case 17:
		goto loc_82050C64;
	case 18:
		goto loc_82050C64;
	case 19:
		goto loc_82050C64;
	case 20:
		goto loc_82050C64;
	case 21:
		goto loc_82050C64;
	case 22:
		goto loc_82050C40;
	case 23:
		goto loc_82050C40;
	case 24:
		goto loc_82050C40;
	case 25:
		goto loc_82050C40;
	case 26:
		goto loc_82050C64;
	case 27:
		goto loc_82050C64;
	case 28:
		goto loc_82050C64;
	case 29:
		goto loc_82050C64;
	case 30:
		goto loc_82050C64;
	case 31:
		goto loc_82050C64;
	case 32:
		goto loc_82050C64;
	case 33:
		goto loc_82050C64;
	case 34:
		goto loc_82050C64;
	case 35:
		goto loc_82050C64;
	case 36:
		goto loc_82050C64;
	case 37:
		goto loc_82050C64;
	case 38:
		goto loc_82050C64;
	case 39:
		goto loc_82050C64;
	case 40:
		goto loc_82050C64;
	case 41:
		goto loc_82050C64;
	case 42:
		goto loc_82050C64;
	case 43:
		goto loc_82050C64;
	case 44:
		goto loc_82050C64;
	case 45:
		goto loc_82050C64;
	case 46:
		goto loc_82050C64;
	case 47:
		goto loc_82050C64;
	case 48:
		goto loc_82050C64;
	case 49:
		goto loc_82050C64;
	case 50:
		goto loc_82050C64;
	case 51:
		goto loc_82050C64;
	case 52:
		goto loc_82050C64;
	case 53:
		goto loc_82050C64;
	case 54:
		goto loc_82050C64;
	case 55:
		goto loc_82050C64;
	case 56:
		goto loc_82050C64;
	case 57:
		goto loc_82050C64;
	case 58:
		goto loc_82050C64;
	case 59:
		goto loc_82050C64;
	case 60:
		goto loc_82050C64;
	case 61:
		goto loc_82050C64;
	case 62:
		goto loc_82050C64;
	case 63:
		goto loc_82050C64;
	case 64:
		goto loc_82050C64;
	case 65:
		goto loc_82050C64;
	case 66:
		goto loc_82050C64;
	case 67:
		goto loc_82050C64;
	case 68:
		goto loc_82050C64;
	case 69:
		goto loc_82050C64;
	case 70:
		goto loc_82050C64;
	case 71:
		goto loc_82050C64;
	case 72:
		goto loc_82050C64;
	case 73:
		goto loc_82050C64;
	case 74:
		goto loc_82050C64;
	case 75:
		goto loc_82050C64;
	case 76:
		goto loc_82050C64;
	case 77:
		goto loc_82050F68;
	case 78:
		goto loc_82050F68;
	case 79:
		goto loc_82050F68;
	case 80:
		goto loc_82050C54;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82050C40:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050C50;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050C54:
	// li r5,51
	ctx.r5.s64 = 51;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050C64;
	sub_820B5958(ctx, base);
loc_82050C64:
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050C74;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050C78:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// addi r11,r11,-24
	ctx.r11.s64 = ctx.r11.s64 + -24;
	// cmplwi cr6,r11,82
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 82, ctx.xer);
	// bgt cr6,0x82050f5c
	if (ctx.cr6.gt) goto loc_82050F5C;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,3232
	ctx.r12.s64 = ctx.r12.s64 + 3232;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82050DEC;
	case 1:
		goto loc_82050F5C;
	case 2:
		goto loc_82050F5C;
	case 3:
		goto loc_82050F5C;
	case 4:
		goto loc_82050F5C;
	case 5:
		goto loc_82050F5C;
	case 6:
		goto loc_82050F5C;
	case 7:
		goto loc_82050F5C;
	case 8:
		goto loc_82050F5C;
	case 9:
		goto loc_82050F5C;
	case 10:
		goto loc_82050F5C;
	case 11:
		goto loc_82050F5C;
	case 12:
		goto loc_82050F5C;
	case 13:
		goto loc_82050F5C;
	case 14:
		goto loc_82050F5C;
	case 15:
		goto loc_82050F5C;
	case 16:
		goto loc_82050F5C;
	case 17:
		goto loc_82050F5C;
	case 18:
		goto loc_82050F5C;
	case 19:
		goto loc_82050F5C;
	case 20:
		goto loc_82050F5C;
	case 21:
		goto loc_82050F5C;
	case 22:
		goto loc_82050DEC;
	case 23:
		goto loc_82050DEC;
	case 24:
		goto loc_82050DEC;
	case 25:
		goto loc_82050DEC;
	case 26:
		goto loc_82050F5C;
	case 27:
		goto loc_82050F5C;
	case 28:
		goto loc_82050F5C;
	case 29:
		goto loc_82050F5C;
	case 30:
		goto loc_82050F5C;
	case 31:
		goto loc_82050F5C;
	case 32:
		goto loc_82050F5C;
	case 33:
		goto loc_82050F5C;
	case 34:
		goto loc_82050F5C;
	case 35:
		goto loc_82050F5C;
	case 36:
		goto loc_82050F5C;
	case 37:
		goto loc_82050F5C;
	case 38:
		goto loc_82050F5C;
	case 39:
		goto loc_82050F5C;
	case 40:
		goto loc_82050F5C;
	case 41:
		goto loc_82050F5C;
	case 42:
		goto loc_82050F5C;
	case 43:
		goto loc_82050F5C;
	case 44:
		goto loc_82050F5C;
	case 45:
		goto loc_82050F5C;
	case 46:
		goto loc_82050F5C;
	case 47:
		goto loc_82050F5C;
	case 48:
		goto loc_82050F5C;
	case 49:
		goto loc_82050F5C;
	case 50:
		goto loc_82050F5C;
	case 51:
		goto loc_82050F5C;
	case 52:
		goto loc_82050F5C;
	case 53:
		goto loc_82050F5C;
	case 54:
		goto loc_82050F5C;
	case 55:
		goto loc_82050F5C;
	case 56:
		goto loc_82050F5C;
	case 57:
		goto loc_82050F5C;
	case 58:
		goto loc_82050F5C;
	case 59:
		goto loc_82050F5C;
	case 60:
		goto loc_82050F5C;
	case 61:
		goto loc_82050F5C;
	case 62:
		goto loc_82050F5C;
	case 63:
		goto loc_82050F5C;
	case 64:
		goto loc_82050F5C;
	case 65:
		goto loc_82050F5C;
	case 66:
		goto loc_82050F5C;
	case 67:
		goto loc_82050F5C;
	case 68:
		goto loc_82050F5C;
	case 69:
		goto loc_82050F5C;
	case 70:
		goto loc_82050F5C;
	case 71:
		goto loc_82050F5C;
	case 72:
		goto loc_82050F5C;
	case 73:
		goto loc_82050F5C;
	case 74:
		goto loc_82050F5C;
	case 75:
		goto loc_82050F5C;
	case 76:
		goto loc_82050F5C;
	case 77:
		goto loc_82050E7C;
	case 78:
		goto loc_82050EB8;
	case 79:
		goto loc_82050ECC;
	case 80:
		goto loc_82050EE8;
	case 81:
		goto loc_82050F40;
	case 82:
		goto loc_82050F24;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82050DEC:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820510f8
	ctx.lr = 0x82050DF8;
	sub_820510F8(ctx, base);
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82050e54
	if (ctx.cr6.gt) goto loc_82050E54;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,3612
	ctx.r12.s64 = ctx.r12.s64 + 3612;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82050E2C;
	case 1:
		goto loc_82050E34;
	case 2:
		goto loc_82050E3C;
	case 3:
		goto loc_82050E44;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82050E2C:
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82050e48
	goto loc_82050E48;
loc_82050E34:
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x82050e48
	goto loc_82050E48;
loc_82050E3C:
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x82050e48
	goto loc_82050E48;
loc_82050E44:
	// li r5,3
	ctx.r5.s64 = 3;
loc_82050E48:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050E54;
	sub_820B5958(ctx, base);
loc_82050E54:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x82050e70
	if (ctx.cr6.eq) goto loc_82050E70;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x820b5958
	ctx.lr = 0x82050E6C;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050E70:
	// li r5,9
	ctx.r5.s64 = 9;
	// bl 0x820b5958
	ctx.lr = 0x82050E78;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050E7C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x82050e98
	if (ctx.cr6.eq) goto loc_82050E98;
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050E94;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050E98:
	// li r5,52
	ctx.r5.s64 = 52;
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x820b5958
	ctx.lr = 0x82050EA4;
	sub_820B5958(ctx, base);
	// li r5,9
	ctx.r5.s64 = 9;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050EB4;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050EB8:
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050EC8;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050ECC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x82050e98
	if (ctx.cr6.eq) goto loc_82050E98;
	// li r5,13
	ctx.r5.s64 = 13;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050EE4;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050EE8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x82050f04
	if (ctx.cr6.eq) goto loc_82050F04;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050F00;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050F04:
	// li r5,51
	ctx.r5.s64 = 51;
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x820b5958
	ctx.lr = 0x82050F10;
	sub_820B5958(ctx, base);
	// li r5,9
	ctx.r5.s64 = 9;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050F20;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050F24:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x82050e98
	if (ctx.cr6.eq) goto loc_82050E98;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050F3C;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050F40:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x82050e98
	if (ctx.cr6.eq) goto loc_82050E98;
	// li r5,11
	ctx.r5.s64 = 11;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050F58;
	sub_820B5958(ctx, base);
	// b 0x82050f68
	goto loc_82050F68;
loc_82050F5C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820515c8
	ctx.lr = 0x82050F68;
	sub_820515C8(ctx, base);
loc_82050F68:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// rotlwi r26,r26,1
	ctx.r26.u64 = __builtin_rotateleft32(ctx.r26.u32, 1);
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// blt cr6,0x82050a78
	if (ctx.cr6.lt) goto loc_82050A78;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,16(r28)
	REX_STORE_U32(ctx.r28.u32 + 16, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
