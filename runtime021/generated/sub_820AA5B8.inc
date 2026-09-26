DEFINE_REX_FUNC(sub_820AA5B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820AA5C0;
	__savegprlr_28(ctx, base);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r31,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r31.u32);
	// cmplwi cr6,r28,16
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 16, ctx.xer);
	// stb r31,212(r1)
	REX_STORE_U8(ctx.r1.u32 + 212, ctx.r31.u8);
	// stw r6,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r6.u32);
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// stw r31,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r31.u32);
	// stb r31,292(r1)
	REX_STORE_U8(ctx.r1.u32 + 292, ctx.r31.u8);
	// bgt cr6,0x820aa988
	if (ctx.cr6.gt) goto loc_820AA988;
	// lis r12,-32245
	ctx.r12.s64 = -2113208320;
	// addi r12,r12,-23028
	ctx.r12.s64 = ctx.r12.s64 + -23028;
	// rlwinm r0,r28,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r28.u32) {
	case 0:
		goto loc_820AA6A4;
	case 1:
		goto loc_820AA650;
	case 2:
		goto loc_820AA66C;
	case 3:
		goto loc_820AA688;
	case 4:
		goto loc_820AA6A4;
	case 5:
		goto loc_820AA6C0;
	case 6:
		goto loc_820AA6DC;
	case 7:
		goto loc_820AA6F8;
	case 8:
		goto loc_820AA714;
	case 9:
		goto loc_820AA730;
	case 10:
		goto loc_820AA74C;
	case 11:
		goto loc_820AA768;
	case 12:
		goto loc_820AA788;
	case 13:
		goto loc_820AA7C0;
	case 14:
		goto loc_820AA7DC;
	case 15:
		goto loc_820AA7F8;
	case 16:
		goto loc_820AA7A4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820AA650:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8520
	ctx.r4.s64 = ctx.r11.s64 + 8520;
	// bl 0x82053a00
	ctx.lr = 0x820AA660;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8536
	ctx.r4.s64 = ctx.r10.s64 + 8536;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA66C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8556
	ctx.r4.s64 = ctx.r11.s64 + 8556;
	// bl 0x82053a00
	ctx.lr = 0x820AA67C;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8572
	ctx.r4.s64 = ctx.r10.s64 + 8572;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA688:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8520
	ctx.r4.s64 = ctx.r11.s64 + 8520;
	// bl 0x82053a00
	ctx.lr = 0x820AA698;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8584
	ctx.r4.s64 = ctx.r10.s64 + 8584;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA6A4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8520
	ctx.r4.s64 = ctx.r11.s64 + 8520;
	// bl 0x82053a00
	ctx.lr = 0x820AA6B4;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8596
	ctx.r4.s64 = ctx.r10.s64 + 8596;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA6C0:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8520
	ctx.r4.s64 = ctx.r11.s64 + 8520;
	// bl 0x82053a00
	ctx.lr = 0x820AA6D0;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8612
	ctx.r4.s64 = ctx.r10.s64 + 8612;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA6DC:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8556
	ctx.r4.s64 = ctx.r11.s64 + 8556;
	// bl 0x82053a00
	ctx.lr = 0x820AA6EC;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8624
	ctx.r4.s64 = ctx.r10.s64 + 8624;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA6F8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8520
	ctx.r4.s64 = ctx.r11.s64 + 8520;
	// bl 0x82053a00
	ctx.lr = 0x820AA708;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8636
	ctx.r4.s64 = ctx.r10.s64 + 8636;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA714:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8520
	ctx.r4.s64 = ctx.r11.s64 + 8520;
	// bl 0x82053a00
	ctx.lr = 0x820AA724;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8652
	ctx.r4.s64 = ctx.r10.s64 + 8652;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA730:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8520
	ctx.r4.s64 = ctx.r11.s64 + 8520;
	// bl 0x82053a00
	ctx.lr = 0x820AA740;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8664
	ctx.r4.s64 = ctx.r10.s64 + 8664;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA74C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8556
	ctx.r4.s64 = ctx.r11.s64 + 8556;
	// bl 0x82053a00
	ctx.lr = 0x820AA75C;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8680
	ctx.r4.s64 = ctx.r10.s64 + 8680;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA768:
	// stw r31,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r31.u32);
	// stw r31,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
	// stw r31,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r31.u32);
loc_820AA774:
	// stw r31,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r31.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820AA788:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8520
	ctx.r4.s64 = ctx.r11.s64 + 8520;
	// bl 0x82053a00
	ctx.lr = 0x820AA798;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8692
	ctx.r4.s64 = ctx.r10.s64 + 8692;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA7A4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8520
	ctx.r4.s64 = ctx.r11.s64 + 8520;
	// bl 0x82053a00
	ctx.lr = 0x820AA7B4;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8708
	ctx.r4.s64 = ctx.r10.s64 + 8708;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA7C0:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8520
	ctx.r4.s64 = ctx.r11.s64 + 8520;
	// bl 0x82053a00
	ctx.lr = 0x820AA7D0;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8728
	ctx.r4.s64 = ctx.r10.s64 + 8728;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA7DC:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8556
	ctx.r4.s64 = ctx.r11.s64 + 8556;
	// bl 0x82053a00
	ctx.lr = 0x820AA7EC;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8752
	ctx.r4.s64 = ctx.r10.s64 + 8752;
	// b 0x820aa810
	goto loc_820AA810;
loc_820AA7F8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,8556
	ctx.r4.s64 = ctx.r11.s64 + 8556;
	// bl 0x82053a00
	ctx.lr = 0x820AA808;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,8764
	ctx.r4.s64 = ctx.r10.s64 + 8764;
loc_820AA810:
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x82053a00
	ctx.lr = 0x820AA818;
	sub_82053A00(ctx, base);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,360
	ctx.r3.s64 = ctx.r1.s64 + 360;
	// bl 0x820aa488
	ctx.lr = 0x820AA830;
	sub_820AA488(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x820aa988
	if (ctx.cr6.eq) goto loc_820AA988;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x820c0440
	ctx.lr = 0x820AA844;
	sub_820C0440(ctx, base);
	// stw r3,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820aa988
	if (ctx.cr6.eq) goto loc_820AA988;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,360
	ctx.r3.s64 = ctx.r1.s64 + 360;
	// bl 0x820aa488
	ctx.lr = 0x820AA868;
	sub_820AA488(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x820aa988
	if (ctx.cr6.eq) goto loc_820AA988;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x820c0330
	ctx.lr = 0x820AA87C;
	sub_820C0330(ctx, base);
	// stw r3,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820aa988
	if (ctx.cr6.eq) goto loc_820AA988;
	// lis r12,-32245
	ctx.r12.s64 = -2113208320;
	// addi r12,r12,-22368
	ctx.r12.s64 = ctx.r12.s64 + -22368;
	// rlwinm r0,r28,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r28.u32) {
	case 0:
		goto loc_820AA8E4;
	case 1:
		goto loc_820AA8E4;
	case 2:
		goto loc_820AA9A0;
	case 3:
		goto loc_820AA8E4;
	case 4:
		goto loc_820AA8E4;
	case 5:
		goto loc_820AA8E4;
	case 6:
		goto loc_820AA9A0;
	case 7:
		goto loc_820AA8E4;
	case 8:
		goto loc_820AA8E4;
	case 9:
		goto loc_820AA8E4;
	case 10:
		goto loc_820AA9A0;
	case 11:
		goto loc_820AA9A0;
	case 12:
		goto loc_820AA8E4;
	case 13:
		goto loc_820AA988;
	case 14:
		goto loc_820AA9A0;
	case 15:
		goto loc_820AA9A0;
	case 16:
		goto loc_820AA8E4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820AA8E4:
	// lis r11,42
	ctx.r11.s64 = 2752512;
	// sth r31,96(r1)
	REX_STORE_U16(ctx.r1.u32 + 96, ctx.r31.u16);
	// lis r10,44
	ctx.r10.s64 = 2883584;
	// sth r31,98(r1)
	REX_STORE_U16(ctx.r1.u32 + 98, ctx.r31.u16);
	// ori r8,r11,9145
	ctx.r8.u64 = ctx.r11.u64 | 9145;
	// stb r31,104(r1)
	REX_STORE_U8(ctx.r1.u32 + 104, ctx.r31.u8);
	// lis r9,24
	ctx.r9.s64 = 1572864;
	// stb r31,105(r1)
	REX_STORE_U8(ctx.r1.u32 + 105, ctx.r31.u8);
	// ori r6,r10,9125
	ctx.r6.u64 = ctx.r10.u64 | 9125;
	// stw r8,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// ori r11,r9,10374
	ctx.r11.u64 = ctx.r9.u64 | 10374;
	// stb r31,106(r1)
	REX_STORE_U8(ctx.r1.u32 + 106, ctx.r31.u8);
	// li r7,12
	ctx.r7.s64 = 12;
	// sth r31,108(r1)
	REX_STORE_U16(ctx.r1.u32 + 108, ctx.r31.u16);
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r6,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// li r4,20
	ctx.r4.s64 = 20;
	// sth r7,110(r1)
	REX_STORE_U16(ctx.r1.u32 + 110, ctx.r7.u16);
	// li r10,10
	ctx.r10.s64 = 10;
	// stb r31,116(r1)
	REX_STORE_U8(ctx.r1.u32 + 116, ctx.r31.u8);
	// li r9,255
	ctx.r9.s64 = 255;
	// stb r5,117(r1)
	REX_STORE_U8(ctx.r1.u32 + 117, ctx.r5.u8);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stb r31,118(r1)
	REX_STORE_U8(ctx.r1.u32 + 118, ctx.r31.u8);
	// sth r31,120(r1)
	REX_STORE_U16(ctx.r1.u32 + 120, ctx.r31.u16);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// sth r4,122(r1)
	REX_STORE_U16(ctx.r1.u32 + 122, ctx.r4.u16);
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// stb r31,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r31.u8);
	// stb r10,129(r1)
	REX_STORE_U8(ctx.r1.u32 + 129, ctx.r10.u8);
	// stb r31,130(r1)
	REX_STORE_U8(ctx.r1.u32 + 130, ctx.r31.u8);
	// sth r9,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r9.u16);
	// sth r31,134(r1)
	REX_STORE_U16(ctx.r1.u32 + 134, ctx.r31.u16);
	// stw r8,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// stb r31,140(r1)
	REX_STORE_U8(ctx.r1.u32 + 140, ctx.r31.u8);
	// stb r31,141(r1)
	REX_STORE_U8(ctx.r1.u32 + 141, ctx.r31.u8);
	// stb r31,142(r1)
	REX_STORE_U8(ctx.r1.u32 + 142, ctx.r31.u8);
	// bl 0x820c01c0
	ctx.lr = 0x820AA97C;
	sub_820C01C0(ctx, base);
	// stw r3,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820aa774
	if (!ctx.cr6.eq) goto loc_820AA774;
loc_820AA988:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820AA9A0:
	// lis r9,42
	ctx.r9.s64 = 2752512;
	// sth r31,144(r1)
	REX_STORE_U16(ctx.r1.u32 + 144, ctx.r31.u16);
	// lis r8,24
	ctx.r8.s64 = 1572864;
	// sth r31,146(r1)
	REX_STORE_U16(ctx.r1.u32 + 146, ctx.r31.u16);
	// ori r7,r9,9145
	ctx.r7.u64 = ctx.r9.u64 | 9145;
	// stb r31,152(r1)
	REX_STORE_U8(ctx.r1.u32 + 152, ctx.r31.u8);
	// li r6,12
	ctx.r6.s64 = 12;
	// stb r31,153(r1)
	REX_STORE_U8(ctx.r1.u32 + 153, ctx.r31.u8);
	// lis r11,44
	ctx.r11.s64 = 2883584;
	// stw r7,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r7.u32);
	// ori r9,r8,10374
	ctx.r9.u64 = ctx.r8.u64 | 10374;
	// sth r6,158(r1)
	REX_STORE_U16(ctx.r1.u32 + 158, ctx.r6.u16);
	// ori r11,r11,9125
	ctx.r11.u64 = ctx.r11.u64 | 9125;
	// stb r31,154(r1)
	REX_STORE_U8(ctx.r1.u32 + 154, ctx.r31.u8);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r31,156(r1)
	REX_STORE_U16(ctx.r1.u32 + 156, ctx.r31.u16);
	// li r5,20
	ctx.r5.s64 = 20;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// li r4,28
	ctx.r4.s64 = 28;
	// stb r31,164(r1)
	REX_STORE_U8(ctx.r1.u32 + 164, ctx.r31.u8);
	// li r8,10
	ctx.r8.s64 = 10;
	// stb r10,165(r1)
	REX_STORE_U8(ctx.r1.u32 + 165, ctx.r10.u8);
	// li r7,255
	ctx.r7.s64 = 255;
	// stb r31,166(r1)
	REX_STORE_U8(ctx.r1.u32 + 166, ctx.r31.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// sth r31,168(r1)
	REX_STORE_U16(ctx.r1.u32 + 168, ctx.r31.u16);
	// li r28,1
	ctx.r28.s64 = 1;
	// sth r5,170(r1)
	REX_STORE_U16(ctx.r1.u32 + 170, ctx.r5.u16);
	// stw r11,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r11.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stb r31,176(r1)
	REX_STORE_U8(ctx.r1.u32 + 176, ctx.r31.u8);
	// stb r10,177(r1)
	REX_STORE_U8(ctx.r1.u32 + 177, ctx.r10.u8);
	// stb r28,178(r1)
	REX_STORE_U8(ctx.r1.u32 + 178, ctx.r28.u8);
	// sth r31,180(r1)
	REX_STORE_U16(ctx.r1.u32 + 180, ctx.r31.u16);
	// sth r4,182(r1)
	REX_STORE_U16(ctx.r1.u32 + 182, ctx.r4.u16);
	// stw r9,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
	// stb r31,188(r1)
	REX_STORE_U8(ctx.r1.u32 + 188, ctx.r31.u8);
	// stb r8,189(r1)
	REX_STORE_U8(ctx.r1.u32 + 189, ctx.r8.u8);
	// stb r31,190(r1)
	REX_STORE_U8(ctx.r1.u32 + 190, ctx.r31.u8);
	// sth r7,192(r1)
	REX_STORE_U16(ctx.r1.u32 + 192, ctx.r7.u16);
	// sth r31,194(r1)
	REX_STORE_U16(ctx.r1.u32 + 194, ctx.r31.u16);
	// stw r6,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r6.u32);
	// stb r31,200(r1)
	REX_STORE_U8(ctx.r1.u32 + 200, ctx.r31.u8);
	// stb r31,201(r1)
	REX_STORE_U8(ctx.r1.u32 + 201, ctx.r31.u8);
	// stb r31,202(r1)
	REX_STORE_U8(ctx.r1.u32 + 202, ctx.r31.u8);
	// bl 0x820c01c0
	ctx.lr = 0x820AAA58;
	sub_820C01C0(ctx, base);
	// stw r3,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820aa774
	if (!ctx.cr6.eq) goto loc_820AA774;
	// stw r28,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
