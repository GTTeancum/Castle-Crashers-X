DEFINE_REX_FUNC(sub_820A1E50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e4
	ctx.lr = 0x820A1E58;
	__savegprlr_15(ctx, base);
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r18,1
	ctx.r18.s64 = 1;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r16,36(r31)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// stw r26,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
	// mr r24,r18
	ctx.r24.u64 = ctx.r18.u64;
	// stw r26,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r26.u32);
	// addi r27,r31,40
	ctx.r27.s64 = ctx.r31.s64 + 40;
	// stw r26,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r26.u32);
	// addi r23,r31,124
	ctx.r23.s64 = ctx.r31.s64 + 124;
	// stw r26,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r20,6
	ctx.r20.s64 = 6;
	// li r15,2
	ctx.r15.s64 = 2;
	// lis r17,-32218
	ctx.r17.s64 = -2111438848;
	// lis r21,-32218
	ctx.r21.s64 = -2111438848;
	// addi r19,r10,3528
	ctx.r19.s64 = ctx.r10.s64 + 3528;
	// addi r22,r11,9424
	ctx.r22.s64 = ctx.r11.s64 + 9424;
loc_820A1EAC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820b5a00
	ctx.lr = 0x820A1EB4;
	sub_820B5A00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820a2090
	if (ctx.cr6.eq) goto loc_820A2090;
	// addi r11,r3,-2
	ctx.r11.s64 = ctx.r3.s64 + -2;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r25,r18
	ctx.r25.u64 = ctx.r18.u64;
	// rlwinm r28,r10,27,31,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x820b6c58
	ctx.lr = 0x820A1EDC;
	sub_820B6C58(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ld r30,144(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// bl 0x820b5ce0
	ctx.lr = 0x820A1EEC;
	sub_820B5CE0(ctx, base);
	// ld r9,0(r27)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r27.u32 + 0);
	// cmpld cr6,r9,r30
	ctx.cr6.compare<uint64_t>(ctx.r9.u64, ctx.r30.u64, ctx.xer);
	// beq cr6,0x820a1f5c
	if (ctx.cr6.eq) goto loc_820A1F5C;
	// and r11,r24,r16
	ctx.r11.u64 = ctx.r24.u64 & ctx.r16.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a1f50
	if (ctx.cr6.eq) goto loc_820A1F50;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a39f0
	ctx.lr = 0x820A1F10;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a1f50
	if (ctx.cr6.eq) goto loc_820A1F50;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x820a37b8
	ctx.lr = 0x820A1F28;
	sub_820A37B8(ctx, base);
	// stb r26,1185(r31)
	REX_STORE_U8(ctx.r31.u32 + 1185, ctx.r26.u8);
	// stb r26,1377(r31)
	REX_STORE_U8(ctx.r31.u32 + 1377, ctx.r26.u8);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// stw r20,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r20.u32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82053a00
	ctx.lr = 0x820A1F40;
	sub_82053A00(ctx, base);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r3,-6624(r21)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r21.u32 + -6624);
	// bl 0x82077a98
	ctx.lr = 0x820A1F4C;
	sub_82077A98(ctx, base);
	// b 0x820a1f60
	goto loc_820A1F60;
loc_820A1F50:
	// ld r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r27.u32 + 0);
	// cmpld cr6,r11,r30
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r30.u64, ctx.xer);
	// bne cr6,0x820a1f60
	if (!ctx.cr6.eq) goto loc_820A1F60;
loc_820A1F5C:
	// mr r25,r26
	ctx.r25.u64 = ctx.r26.u64;
loc_820A1F60:
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// slw r10,r28,r29
	ctx.r10.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r29.u8 & 0x3F));
	// std r30,0(r27)
	REX_STORE_U64(ctx.r27.u32 + 0, ctx.r30.u64);
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// std r11,32(r27)
	REX_STORE_U64(ctx.r27.u32 + 32, ctx.r11.u64);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// lwz r9,104(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r8.u32);
	// beq cr6,0x820a2064
	if (ctx.cr6.eq) goto loc_820A2064;
	// lhz r11,32(r27)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + 32);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// bne cr6,0x820a1fd0
	if (!ctx.cr6.eq) goto loc_820A1FD0;
	// rlwinm r11,r11,0,24,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a1fd0
	if (ctx.cr6.eq) goto loc_820A1FD0;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// mr r30,r18
	ctx.r30.u64 = ctx.r18.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x820A1FB0;
	sub_8208C5D8(ctx, base);
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// li r4,254
	ctx.r4.s64 = 254;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820b5a10
	ctx.lr = 0x820A1FC0;
	sub_820B5A10(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a1ffc
	if (!ctx.cr6.eq) goto loc_820A1FFC;
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// b 0x820a1fec
	goto loc_820A1FEC;
loc_820A1FD0:
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// li r4,254
	ctx.r4.s64 = 254;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820b5a10
	ctx.lr = 0x820A1FE0;
	sub_820B5A10(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a1ffc
	if (!ctx.cr6.eq) goto loc_820A1FFC;
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_820A1FEC:
	// lwz r10,108(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// slw r9,r11,r29
	ctx.r9.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r29.u8 & 0x3F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r8.u32);
loc_820A1FFC:
	// clrlwi r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a2060
	if (!ctx.cr6.eq) goto loc_820A2060;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,252
	ctx.r4.s64 = 252;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820b5a10
	ctx.lr = 0x820A2018;
	sub_820B5A10(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a2064
	if (!ctx.cr6.eq) goto loc_820A2064;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820a2060
	if (!ctx.cr6.eq) goto loc_820A2060;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,251
	ctx.r4.s64 = 251;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820b5a10
	ctx.lr = 0x820A203C;
	sub_820B5A10(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820a2058
	if (!ctx.cr6.eq) goto loc_820A2058;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820a2058
	if (ctx.cr6.eq) goto loc_820A2058;
	// stw r18,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r18.u32);
	// b 0x820a2064
	goto loc_820A2064;
loc_820A2058:
	// stw r15,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r15.u32);
	// b 0x820a2064
	goto loc_820A2064;
loc_820A2060:
	// stw r26,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r26.u32);
loc_820A2064:
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// clrlwi r10,r25,24
	ctx.r10.u64 = ctx.r25.u32 & 0xFF;
	// or r9,r24,r11
	ctx.r9.u64 = ctx.r24.u64 | ctx.r11.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// beq cr6,0x820a2120
	if (ctx.cr6.eq) goto loc_820A2120;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r4,-6596(r17)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r17.u32 + -6596);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a0540
	ctx.lr = 0x820A208C;
	sub_820A0540(ctx, base);
	// b 0x820a2120
	goto loc_820A2120;
loc_820A2090:
	// std r26,0(r27)
	REX_STORE_U64(ctx.r27.u32 + 0, ctx.r26.u64);
	// std r26,32(r27)
	REX_STORE_U64(ctx.r27.u32 + 32, ctx.r26.u64);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a20cc
	if (ctx.cr6.eq) goto loc_820A20CC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a3900
	ctx.lr = 0x820A20AC;
	sub_820A3900(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820a20cc
	if (!ctx.cr6.eq) goto loc_820A20CC;
	// and r11,r24,r16
	ctx.r11.u64 = ctx.r24.u64 & ctx.r16.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a20cc
	if (ctx.cr6.eq) goto loc_820A20CC;
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// or r10,r11,r24
	ctx.r10.u64 = ctx.r11.u64 | ctx.r24.u64;
	// stw r10,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);
loc_820A20CC:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a39f0
	ctx.lr = 0x820A20D8;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a2120
	if (ctx.cr6.eq) goto loc_820A2120;
	// lbz r11,1185(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a2120
	if (ctx.cr6.eq) goto loc_820A2120;
	// lbz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 180);
	// stb r26,1185(r31)
	REX_STORE_U8(ctx.r31.u32 + 1185, ctx.r26.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stb r26,1377(r31)
	REX_STORE_U8(ctx.r31.u32 + 1377, ctx.r26.u8);
	// bne cr6,0x820a2120
	if (!ctx.cr6.eq) goto loc_820A2120;
	// stw r20,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r20.u32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x82053a00
	ctx.lr = 0x820A2114;
	sub_82053A00(ctx, base);
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// lwz r3,-6624(r21)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r21.u32 + -6624);
	// bl 0x82077a98
	ctx.lr = 0x820A2120;
	sub_82077A98(ctx, base);
loc_820A2120:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a6490
	ctx.lr = 0x820A2128;
	sub_820A6490(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r23,r23,4
	ctx.r23.s64 = ctx.r23.s64 + 4;
	// addi r27,r27,8
	ctx.r27.s64 = ctx.r27.s64 + 8;
	// rotlwi r24,r24,1
	ctx.r24.u64 = __builtin_rotateleft32(ctx.r24.u32, 1);
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x820a1eac
	if (ctx.cr6.lt) goto loc_820A1EAC;
	// stb r26,9(r31)
	REX_STORE_U8(ctx.r31.u32 + 9, ctx.r26.u8);
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
}
