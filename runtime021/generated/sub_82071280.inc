DEFINE_REX_FUNC(sub_82071280) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x82071288;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a848
	ctx.lr = 0x82071290;
	__savefpr_24(ctx, base);
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r11,r11,-129
	ctx.r11.s64 = ctx.r11.s64 + -129;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,45
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 45, ctx.xer);
	// bgt cr6,0x82072640
	if (ctx.cr6.gt) goto loc_82072640;
	// lis r12,-32249
	ctx.r12.s64 = -2113470464;
	// addi r12,r12,4812
	ctx.r12.s64 = ctx.r12.s64 + 4812;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82071384;
	case 1:
		goto loc_82071404;
	case 2:
		goto loc_8207145C;
	case 3:
		goto loc_82071480;
	case 4:
		goto loc_820714C4;
	case 5:
		goto loc_820714F0;
	case 6:
		goto loc_8207151C;
	case 7:
		goto loc_82071548;
	case 8:
		goto loc_82071574;
	case 9:
		goto loc_820715A0;
	case 10:
		goto loc_820715CC;
	case 11:
		goto loc_82072664;
	case 12:
		goto loc_82071604;
	case 13:
		goto loc_8207165C;
	case 14:
		goto loc_820717DC;
	case 15:
		goto loc_82071824;
	case 16:
		goto loc_820718A8;
	case 17:
		goto loc_82071930;
	case 18:
		goto loc_82071980;
	case 19:
		goto loc_82071A28;
	case 20:
		goto loc_82071A7C;
	case 21:
		goto loc_82071AF0;
	case 22:
		goto loc_82071DAC;
	case 23:
		goto loc_82071E00;
	case 24:
		goto loc_82071EE0;
	case 25:
		goto loc_82071F34;
	case 26:
		goto loc_82071F5C;
	case 27:
		goto loc_82071F5C;
	case 28:
		goto loc_82071FF4;
	case 29:
		goto loc_8207201C;
	case 30:
		goto loc_8207208C;
	case 31:
		goto loc_8207245C;
	case 32:
		goto loc_820720E4;
	case 33:
		goto loc_82072164;
	case 34:
		goto loc_820721AC;
	case 35:
		goto loc_82072208;
	case 36:
		goto loc_820722D0;
	case 37:
		goto loc_82072300;
	case 38:
		goto loc_8207235C;
	case 39:
		goto loc_82072404;
	case 40:
		goto loc_8207243C;
	case 41:
		goto loc_820724A4;
	case 42:
		goto loc_820724F8;
	case 43:
		goto loc_82072540;
	case 44:
		goto loc_8207256C;
	case 45:
		goto loc_820725D4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82071384:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082670
	ctx.lr = 0x8207138C;
	sub_82082670(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82072664
	if (!ctx.cr6.eq) goto loc_82072664;
	// lwz r30,10316(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 10316);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082890
	ctx.lr = 0x820713A4;
	sub_82082890(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820713b8
	if (!ctx.cr6.eq) goto loc_820713B8;
	// addi r11,r30,12
	ctx.r11.s64 = ctx.r30.s64 + 12;
	// b 0x820713c4
	goto loc_820713C4;
loc_820713B8:
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_820713C4:
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
loc_820713C8:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x820713c8
	if (!ctx.cr6.eq) goto loc_820713C8;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// bl 0x8209bba0
	ctx.lr = 0x820713F0;
	sub_8209BBA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071400;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071404:
	// lwz r30,10316(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 10316);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082890
	ctx.lr = 0x82071410;
	sub_82082890(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82071424
	if (!ctx.cr6.eq) goto loc_82071424;
	// addi r4,r30,12
	ctx.r4.s64 = ctx.r30.s64 + 12;
	// b 0x82071430
	goto loc_82071430;
loc_82071424:
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r9
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_82071430:
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82053a00
	ctx.lr = 0x82071438;
	sub_82053A00(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lwz r3,-6624(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// bl 0x820778d0
	ctx.lr = 0x82071448;
	sub_820778D0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071458;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207145C:
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r10.u8);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x8207147C;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071480:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082890
	ctx.lr = 0x82071488;
	sub_82082890(ctx, base);
	// sth r3,128(r1)
	REX_STORE_U16(ctx.r1.u32 + 128, ctx.r3.u16);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r11,-6624(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x820714A0;
	sub_82052EA8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820714C0;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820714C4:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-6596(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// lbz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 8);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stw r8,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r8.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820714EC;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820714F0:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-6596(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stw r9,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r9.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071518;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207151C:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820b6070
	ctx.lr = 0x82071524;
	sub_820B6070(ctx, base);
	// lhz r9,140(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 140);
	// li r11,4
	ctx.r11.s64 = 4;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stw r9,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r9.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071544;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071548:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-6596(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stw r9,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r9.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071570;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071574:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x8207157C;
	sub_82082BB0(ctx, base);
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,100
	ctx.r10.s64 = 100;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x8207159C;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820715A0:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-6596(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// lbz r9,9(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 9);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stb r9,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r9.u8);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820715C8;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820715CC:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-6596(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addi r9,r11,-576
	ctx.r9.s64 = ctx.r11.s64 + -576;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r7,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r7.u8);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071600;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071604:
	// lwz r30,10316(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 10316);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082890
	ctx.lr = 0x82071610;
	sub_82082890(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82071624
	if (!ctx.cr6.eq) goto loc_82071624;
	// addi r4,r30,12
	ctx.r4.s64 = ctx.r30.s64 + 12;
	// b 0x82071630
	goto loc_82071630;
loc_82071624:
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r9
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_82071630:
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82053a00
	ctx.lr = 0x82071638;
	sub_82053A00(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lwz r3,-6624(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// bl 0x82077a98
	ctx.lr = 0x82071648;
	sub_82077A98(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071658;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207165C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082890
	ctx.lr = 0x82071664;
	sub_82082890(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82071694
	if (!ctx.cr6.eq) goto loc_82071694;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6624(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// bl 0x8206dd58
	ctx.lr = 0x82071680;
	sub_8206DD58(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071690;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071694:
	// lwz r30,10316(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 10316);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082890
	ctx.lr = 0x820716A0;
	sub_82082890(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820716b4
	if (!ctx.cr6.eq) goto loc_820716B4;
	// addi r4,r30,12
	ctx.r4.s64 = ctx.r30.s64 + 12;
	// b 0x820716c0
	goto loc_820716C0;
loc_820716B4:
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r9
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_820716C0:
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82053a00
	ctx.lr = 0x820716C8;
	sub_82053A00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r11,r1,180
	ctx.r11.s64 = ctx.r1.s64 + 180;
	// addi r10,r10,-8312
	ctx.r10.s64 = ctx.r10.s64 + -8312;
loc_820716D4:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// beq cr6,0x820716f8
	if (ctx.cr6.eq) goto loc_820716F8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820716d4
	if (ctx.cr6.eq) goto loc_820716D4;
loc_820716F8:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82071740
	if (!ctx.cr6.eq) goto loc_82071740;
	// li r3,68
	ctx.r3.s64 = 68;
	// bl 0x820a7390
	ctx.lr = 0x82071708;
	sub_820A7390(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820717b8
	if (ctx.cr6.eq) goto loc_820717B8;
	// lwz r11,76(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 76);
	// lwz r4,156(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x8206ddc8
	ctx.lr = 0x8207171C;
	sub_8206DDC8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-6624(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// bl 0x8206dd58
	ctx.lr = 0x8207172C;
	sub_8206DD58(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x8207173C;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071740:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r11,r1,180
	ctx.r11.s64 = ctx.r1.s64 + 180;
	// addi r10,r10,-8304
	ctx.r10.s64 = ctx.r10.s64 + -8304;
loc_8207174C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// beq cr6,0x82071770
	if (ctx.cr6.eq) goto loc_82071770;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8207174c
	if (ctx.cr6.eq) goto loc_8207174C;
loc_82071770:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82072664
	if (!ctx.cr6.eq) goto loc_82072664;
	// li r3,60
	ctx.r3.s64 = 60;
	// bl 0x820a7390
	ctx.lr = 0x82071780;
	sub_820A7390(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820717b8
	if (ctx.cr6.eq) goto loc_820717B8;
	// lwz r11,76(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 76);
	// lwz r4,156(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x820619f0
	ctx.lr = 0x82071794;
	sub_820619F0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-6624(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// bl 0x8206dd58
	ctx.lr = 0x820717A4;
	sub_8206DD58(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820717B4;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820717B8:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6624(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// bl 0x8206dd58
	ctx.lr = 0x820717C8;
	sub_8206DD58(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820717D8;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820717DC:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082890
	ctx.lr = 0x820717E4;
	sub_82082890(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082bb0
	ctx.lr = 0x820717F0;
	sub_82082BB0(ctx, base);
	// sth r30,128(r1)
	REX_STORE_U16(ctx.r1.u32 + 128, ctx.r30.u16);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r11,-6624(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x8207180C;
	sub_82052EA8(ctx, base);
	// stw r31,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071820;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071824:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// and r9,r11,r12
	ctx.r9.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82071848
	if (ctx.cr6.eq) goto loc_82071848;
loc_82071840:
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x82071868
	goto loc_82071868;
loc_82071848:
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82071864
	if (ctx.cr6.eq) goto loc_82071864;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x82071840
	if (ctx.cr6.eq) goto loc_82071840;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// beq cr6,0x82071840
	if (ctx.cr6.eq) goto loc_82071840;
loc_82071864:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82071868:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082bb0
	ctx.lr = 0x82071870;
	sub_82082BB0(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r11,-8296
	ctx.r4.s64 = ctx.r11.s64 + -8296;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82127778
	ctx.lr = 0x82071884;
	sub_82127778(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82094858
	ctx.lr = 0x82071894;
	sub_82094858(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820718A4;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820718A8:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// and r9,r11,r12
	ctx.r9.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820718cc
	if (ctx.cr6.eq) goto loc_820718CC;
loc_820718C4:
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x820718ec
	goto loc_820718EC;
loc_820718CC:
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x820718e8
	if (ctx.cr6.eq) goto loc_820718E8;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x820718c4
	if (ctx.cr6.eq) goto loc_820718C4;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// beq cr6,0x820718c4
	if (ctx.cr6.eq) goto loc_820718C4;
loc_820718E8:
	// li r30,0
	ctx.r30.s64 = 0;
loc_820718EC:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082bb0
	ctx.lr = 0x820718F4;
	sub_82082BB0(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r11,18464
	ctx.r5.s64 = ctx.r11.s64 + 18464;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82070f20
	ctx.lr = 0x8207190C;
	sub_82070F20(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82094a98
	ctx.lr = 0x8207191C;
	sub_82094A98(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x8207192C;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071930:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82071938;
	sub_82082BB0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82082700
	ctx.lr = 0x82071944;
	sub_82082700(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x82082bb0
	ctx.lr = 0x82071950;
	sub_82082BB0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,-6624(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// lwz r3,1756(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 1756);
	// bl 0x82078fe8
	ctx.lr = 0x8207196C;
	sub_82078FE8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x8207197C;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071980:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82071988;
	sub_82082BB0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x82071a04
	if (ctx.cr6.lt) goto loc_82071A04;
	// cmpwi cr6,r31,4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4, ctx.xer);
	// bge cr6,0x82071a04
	if (!ctx.cr6.lt) goto loc_82071A04;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,-6596(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// bl 0x820a0988
	ctx.lr = 0x820719B0;
	sub_820A0988(ctx, base);
	// lwz r29,128(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// cmpwi cr6,r29,5
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 5, ctx.xer);
	// bne cr6,0x820719d4
	if (!ctx.cr6.eq) goto loc_820719D4;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r6,64
	ctx.r6.s64 = 64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-6624(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6624);
	// bl 0x82077310
	ctx.lr = 0x820719D4;
	sub_82077310(ctx, base);
loc_820719D4:
	// addi r11,r29,-5
	ctx.r11.s64 = ctx.r29.s64 + -5;
	// li r10,2
	ctx.r10.s64 = 2;
	// cntlzw r9,r11
	ctx.r9.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// stb r7,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r7.u8);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071A00;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071A04:
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r10.u8);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071A24;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071A28:
	// li r11,218
	ctx.r11.s64 = 218;
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// sth r11,128(r1)
	REX_STORE_U16(ctx.r1.u32 + 128, ctx.r11.u16);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r11,-6624(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82071A44;
	sub_82052EA8(ctx, base);
	// lwz r11,-6624(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6624);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r3,212(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 212);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82071A68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071A78;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071A7C:
	// li r11,218
	ctx.r11.s64 = 218;
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// sth r11,128(r1)
	REX_STORE_U16(ctx.r1.u32 + 128, ctx.r11.u16);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r11,-6624(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x82071A98;
	sub_82052EA8(ctx, base);
	// lwz r11,-6624(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6624);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r3,212(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 212);
	// lfs f1,9540(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9540);
	ctx.f1.f64 = double(temp.f32);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82071AC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-6624(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6624);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,212(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 212);
	// lwz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,20(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 20);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82071ADC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071AEC;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071AF0:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// li r29,0
	ctx.r29.s64 = 0;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// and r8,r11,r12
	ctx.r8.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82071b1c
	if (ctx.cr6.eq) goto loc_82071B1C;
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x82071b40
	goto loc_82071B40;
loc_82071B1C:
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82071b3c
	if (ctx.cr6.eq) goto loc_82071B3C;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x82071b34
	if (ctx.cr6.eq) goto loc_82071B34;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x82071b3c
	if (!ctx.cr6.eq) goto loc_82071B3C;
loc_82071B34:
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x82071b40
	goto loc_82071B40;
loc_82071B3C:
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_82071B40:
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// and r8,r11,r12
	ctx.r8.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82071b64
	if (ctx.cr6.eq) goto loc_82071B64;
	// lwz r31,4(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x82071b88
	goto loc_82071B88;
loc_82071B64:
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82071b84
	if (ctx.cr6.eq) goto loc_82071B84;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x82071b7c
	if (ctx.cr6.eq) goto loc_82071B7C;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x82071b84
	if (!ctx.cr6.eq) goto loc_82071B84;
loc_82071B7C:
	// lwz r31,4(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x82071b88
	goto loc_82071B88;
loc_82071B84:
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_82071B88:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82072664
	if (ctx.cr6.eq) goto loc_82072664;
	// stw r29,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r29.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stb r29,168(r1)
	REX_STORE_U8(ctx.r1.u32 + 168, ctx.r29.u8);
	// li r4,119
	ctx.r4.s64 = 119;
	// stw r29,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r29,152(r1)
	REX_STORE_U8(ctx.r1.u32 + 152, ctx.r29.u8);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82071BBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82082700
	ctx.lr = 0x82071BC4;
	sub_82082700(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = ctx.f1.f64;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r4,122
	ctx.r4.s64 = 122;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82071BE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82082700
	ctx.lr = 0x82071BEC;
	sub_82082700(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// fmr f24,f1
	ctx.fpscr.disableFlushMode();
	ctx.f24.f64 = ctx.f1.f64;
	// stb r29,188(r1)
	REX_STORE_U8(ctx.r1.u32 + 188, ctx.r29.u8);
	// stb r29,189(r1)
	REX_STORE_U8(ctx.r1.u32 + 189, ctx.r29.u8);
	// stb r29,190(r1)
	REX_STORE_U8(ctx.r1.u32 + 190, ctx.r29.u8);
	// lfs f0,9536(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,18236(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 18236);
	ctx.f13.f64 = double(temp.f32);
	// fmr f29,f0
	ctx.f29.f64 = ctx.f0.f64;
	// fmr f28,f0
	ctx.f28.f64 = ctx.f0.f64;
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// fmr f27,f0
	ctx.f27.f64 = ctx.f0.f64;
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fmr f31,f13
	ctx.f31.f64 = ctx.f13.f64;
	// stfs f31,192(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// fmr f30,f13
	ctx.f30.f64 = ctx.f13.f64;
	// stfs f30,196(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// fmr f26,f0
	ctx.f26.f64 = ctx.f0.f64;
	// stfs f29,200(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f28,204(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f27,208(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f26,212(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
loc_82071C48:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82071C5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r9,225
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 225, ctx.xer);
	// beq cr6,0x82071d14
	if (ctx.cr6.eq) goto loc_82071D14;
	// lbz r11,86(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 86);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82071cf4
	if (ctx.cr6.eq) goto loc_82071CF4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r29,r1,176
	ctx.r29.s64 = ctx.r1.s64 + 176;
	// bl 0x82083658
	ctx.lr = 0x82071C84;
	sub_82083658(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x82085ad8
	ctx.lr = 0x82071C94;
	sub_82085AD8(ctx, base);
	// lbz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 12);
	// lbz r10,13(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lbz r9,14(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 14);
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f31,16(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,20(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f30.f64 = double(temp.f32);
	// stb r11,188(r1)
	REX_STORE_U8(ctx.r1.u32 + 188, ctx.r11.u8);
	// lfs f29,24(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f29.f64 = double(temp.f32);
	// stb r10,189(r1)
	REX_STORE_U8(ctx.r1.u32 + 189, ctx.r10.u8);
	// lfs f28,28(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f28.f64 = double(temp.f32);
	// stb r9,190(r1)
	REX_STORE_U8(ctx.r1.u32 + 190, ctx.r9.u8);
	// lfs f27,32(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f27.f64 = double(temp.f32);
	// lfs f26,36(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f26.f64 = double(temp.f32);
	// stfs f31,192(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f30,196(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f29,200(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f28,204(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f27,208(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f26,212(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
loc_82071CF4:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82071D08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82071c48
	if (!ctx.cr6.eq) goto loc_82071C48;
loc_82071D14:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// li r4,119
	ctx.r4.s64 = 119;
	// lfs f0,9572(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9572);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// lfs f13,9588(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9588);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f28,f0
	ctx.f12.f64 = double(float(ctx.f28.f64 * ctx.f0.f64));
	// fmuls f11,f30,f13
	ctx.f11.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmuls f10,f31,f13
	ctx.f10.f64 = double(float(ctx.f31.f64 * ctx.f13.f64));
	// fmuls f9,f29,f0
	ctx.f9.f64 = double(float(ctx.f29.f64 * ctx.f0.f64));
	// fmuls f8,f12,f24
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f24.f64));
	// fmuls f7,f11,f24
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f24.f64));
	// fmadds f6,f10,f25,f8
	ctx.f6.f64 = double(float(std::fma(ctx.f10.f64, ctx.f25.f64, ctx.f8.f64)));
	// fmadds f5,f9,f25,f7
	ctx.f5.f64 = double(float(std::fma(ctx.f9.f64, ctx.f25.f64, ctx.f7.f64)));
	// fmadds f4,f27,f0,f6
	ctx.f4.f64 = double(float(std::fma(ctx.f27.f64, ctx.f0.f64, ctx.f6.f64)));
	// stfs f4,164(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmadds f3,f26,f0,f5
	ctx.f3.f64 = double(float(std::fma(ctx.f26.f64, ctx.f0.f64, ctx.f5.f64)));
	// stfs f3,148(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,16(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82071D7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r4,122
	ctx.r4.s64 = 122;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,16(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82071D98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071DA8;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071DAC:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82071DB4;
	sub_82082BB0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r1,480
	ctx.r5.s64 = ctx.r1.s64 + 480;
	// lwz r3,-6628(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// bl 0x820a3df8
	ctx.lr = 0x82071DC8;
	sub_820A3DF8(ctx, base);
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82053a00
	ctx.lr = 0x82071DD4;
	sub_82053A00(ctx, base);
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// lwz r3,10316(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x82071DE0;
	sub_8209D948(ctx, base);
	// li r10,8
	ctx.r10.s64 = 8;
	// sth r3,4(r30)
	REX_STORE_U16(ctx.r30.u32 + 4, ctx.r3.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071DFC;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071E00:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82071E08;
	sub_82082BB0(ctx, base);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// li r29,0
	ctx.r29.s64 = 0;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// and r8,r11,r12
	ctx.r8.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82071e38
	if (ctx.cr6.eq) goto loc_82071E38;
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x82071e5c
	goto loc_82071E5C;
loc_82071E38:
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82071e58
	if (ctx.cr6.eq) goto loc_82071E58;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x82071e50
	if (ctx.cr6.eq) goto loc_82071E50;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x82071e58
	if (!ctx.cr6.eq) goto loc_82071E58;
loc_82071E50:
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x82071e5c
	goto loc_82071E5C;
loc_82071E58:
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_82071E5C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// and r8,r11,r12
	ctx.r8.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82071e80
	if (ctx.cr6.eq) goto loc_82071E80;
loc_82071E78:
	// lwz r31,4(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x82071e9c
	goto loc_82071E9C;
loc_82071E80:
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82071e98
	if (ctx.cr6.eq) goto loc_82071E98;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x82071e78
	if (ctx.cr6.eq) goto loc_82071E78;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// beq cr6,0x82071e78
	if (ctx.cr6.eq) goto loc_82071E78;
loc_82071E98:
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_82071E9C:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lwz r3,-6628(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// bl 0x820a3df8
	ctx.lr = 0x82071EAC;
	sub_820A3DF8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82094858
	ctx.lr = 0x82071EBC;
	sub_82094858(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82094858
	ctx.lr = 0x82071ECC;
	sub_82094858(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071EDC;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071EE0:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lbz r10,2704(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2704);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82071f10
	if (ctx.cr6.eq) goto loc_82071F10;
	// li r3,1
	ctx.r3.s64 = 1;
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r3,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r3.u8);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071F0C;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071F10:
	// bl 0x820a0f88
	ctx.lr = 0x82071F14;
	sub_820A0F88(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r3,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r3.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071F30;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071F34:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r4,-6628(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82071f4c
	if (ctx.cr6.eq) goto loc_82071F4C;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a1d20
	ctx.lr = 0x82071F4C;
	sub_820A1D20(ctx, base);
loc_82071F4C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,2780
	ctx.r3.s64 = ctx.r11.s64 + 2780;
	// bl 0x820b6908
	ctx.lr = 0x82071F5C;
	sub_820B6908(ctx, base);
loc_82071F5C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82071F64;
	sub_82082BB0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082bb0
	ctx.lr = 0x82071F70;
	sub_82082BB0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// bne cr6,0x82071fb0
	if (!ctx.cr6.eq) goto loc_82071FB0;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,-6596(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// bl 0x820a1138
	ctx.lr = 0x82071F9C;
	sub_820A1138(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071FAC;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071FB0:
	// cmpwi cr6,r29,3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 3, ctx.xer);
	// bne cr6,0x82072664
	if (!ctx.cr6.eq) goto loc_82072664;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82082bb0
	ctx.lr = 0x82071FC0;
	sub_82082BB0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,-6596(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// bl 0x820a1138
	ctx.lr = 0x82071FE0;
	sub_820A1138(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82071FF0;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82071FF4:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82071FFC;
	sub_82082BB0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x820b5d30
	ctx.lr = 0x82072008;
	sub_820B5D30(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82072018;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207201C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82072024;
	sub_82082BB0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082848
	ctx.lr = 0x82072030;
	sub_82082848(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r31,r3,-1
	ctx.r31.s64 = ctx.r3.s64 + -1;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,-6596(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// bl 0x820a0e98
	ctx.lr = 0x8207204C;
	sub_820A0E98(ctx, base);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// add r8,r30,r11
	ctx.r8.u64 = ctx.r30.u64 + ctx.r11.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,1
	ctx.r6.s64 = 1;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-6624(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -6624);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stb r7,88(r5)
	REX_STORE_U8(ctx.r5.u32 + 88, ctx.r7.u8);
	// stb r6,76(r11)
	REX_STORE_U8(ctx.r11.u32 + 76, ctx.r6.u8);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82072088;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207208C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82072094;
	sub_82082BB0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r9,r10,r3
	ctx.r9.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r3.u8 & 0x3F));
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r8,36(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// and r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82072664
	if (ctx.cr6.eq) goto loc_82072664;
	// lis r11,22593
	ctx.r11.s64 = 1480654848;
	// li r5,1
	ctx.r5.s64 = 1;
	// ori r10,r11,2231
	ctx.r10.u64 = ctx.r11.u64 | 2231;
	// li r6,0
	ctx.r6.s64 = 0;
	// rldimi r5,r10,32,0
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r5.u64 & 0xFFFFFFFF);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x820b5d50
	ctx.lr = 0x820720D0;
	sub_820B5D50(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820720E0;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820720E4:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82072104
	if (ctx.cr6.eq) goto loc_82072104;
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x8207210c
	goto loc_8207210C;
loc_82072104:
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// li r10,0
	ctx.r10.s64 = 0;
loc_8207210C:
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82072140
	if (ctx.cr6.eq) goto loc_82072140;
	// stw r11,628(r10)
	REX_STORE_U32(ctx.r10.u32 + 628, ctx.r11.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x8207213C;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82072140:
	// lwz r11,628(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 628);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82072160;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82072164:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x8207216C;
	sub_82082BB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x8207145c
	if (ctx.cr6.lt) goto loc_8207145C;
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bge cr6,0x8207145c
	if (!ctx.cr6.lt) goto loc_8207145C;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r3,-6628(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// bl 0x820a39f0
	ctx.lr = 0x8207218C;
	sub_820A39F0(ctx, base);
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r3,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r3.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820721A8;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820721AC:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x820721B4;
	sub_82082BB0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8207145c
	if (ctx.cr6.lt) goto loc_8207145C;
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// bge cr6,0x8207145c
	if (!ctx.cr6.lt) goto loc_8207145C;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// slw r8,r10,r3
	ctx.r8.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r3.u8 & 0x3F));
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r7,36(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 ^ 1;
	// stb r3,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r3.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82072204;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82072208:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82072210;
	sub_82082BB0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82072248
	if (ctx.cr6.eq) goto loc_82072248;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82072248
	if (ctx.cr6.eq) goto loc_82072248;
	// lbz r9,1185(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1185);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// bne cr6,0x8207224c
	if (!ctx.cr6.eq) goto loc_8207224C;
loc_82072248:
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
loc_8207224C:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82072278
	if (!ctx.cr6.eq) goto loc_82072278;
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r29,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r29.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82072274;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82072278:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820722ac
	if (ctx.cr6.eq) goto loc_820722AC;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x820a4238
	ctx.lr = 0x82072288;
	sub_820A4238(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820722ac
	if (ctx.cr6.eq) goto loc_820722AC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820722A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x820722b0
	if (!ctx.cr6.eq) goto loc_820722B0;
loc_820722AC:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_820722B0:
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r11,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r11.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820722CC;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820722D0:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x820722D8;
	sub_82082BB0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,-6628(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// bl 0x820a31a0
	ctx.lr = 0x820722EC;
	sub_820A31A0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820722FC;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82072300:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x8207232c
	if (!ctx.cr6.eq) goto loc_8207232C;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,-6628(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// bl 0x820a37b8
	ctx.lr = 0x82072318;
	sub_820A37B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82072328;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207232C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82072334;
	sub_82082BB0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,-6628(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// bl 0x820a32c0
	ctx.lr = 0x82072348;
	sub_820A32C0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82072358;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207235C:
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// lwz r3,-6628(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// bl 0x82068470
	ctx.lr = 0x82072368;
	sub_82068470(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82072664
	if (ctx.cr6.eq) goto loc_82072664;
	// lwz r11,-6628(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820723a4
	if (!ctx.cr6.eq) goto loc_820723A4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,4564
	ctx.r3.s64 = ctx.r11.s64 + 4564;
	// bl 0x8208c5d8
	ctx.lr = 0x82072390;
	sub_8208C5D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820723A0;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820723A4:
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820723cc
	if (!ctx.cr6.eq) goto loc_820723CC;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,1184(r11)
	REX_STORE_U8(ctx.r11.u32 + 1184, ctx.r10.u8);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820723C8;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820723CC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820723DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x82072664
	if (!ctx.cr6.lt) goto loc_82072664;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,4624
	ctx.r3.s64 = ctx.r11.s64 + 4624;
	// bl 0x8208c5d8
	ctx.lr = 0x820723F0;
	sub_8208C5D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82072400;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82072404:
	// lis r31,-32218
	ctx.r31.s64 = -2111438848;
	// lwz r3,-6628(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// bl 0x82068470
	ctx.lr = 0x82072410;
	sub_82068470(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82072664
	if (ctx.cr6.eq) goto loc_82072664;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,-6628(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + -6628);
	// bl 0x820a36d8
	ctx.lr = 0x82072428;
	sub_820A36D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82072438;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207243C:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r3,-6628(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// bl 0x820a58c8
	ctx.lr = 0x82072448;
	sub_820A58C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82072458;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207245C:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8207247C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x82072664
	if (!ctx.cr6.lt) goto loc_82072664;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,6228
	ctx.r3.s64 = ctx.r11.s64 + 6228;
	// bl 0x8208c5d8
	ctx.lr = 0x82072490;
	sub_8208C5D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820724A0;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820724A4:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820724d4
	if (ctx.cr6.eq) goto loc_820724D4;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820724d4
	if (ctx.cr6.eq) goto loc_820724D4;
	// lbz r11,1185(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x820724d8
	if (!ctx.cr6.eq) goto loc_820724D8;
loc_820724D4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_820724D8:
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r11,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r11.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820724F4;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820724F8:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82072514
	if (ctx.cr6.eq) goto loc_82072514;
	// lhz r11,2(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// b 0x82072518
	goto loc_82072518;
loc_82072514:
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
loc_82072518:
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r9,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r9.u8);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x8207253C;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82072540:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lbz r9,180(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 180);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stb r9,4(r30)
	REX_STORE_U8(ctx.r30.u32 + 4, ctx.r9.u8);
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82072568;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8207256C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x82072574;
	sub_82082BB0(ctx, base);
	// addi r30,r3,-1
	ctx.r30.s64 = ctx.r3.s64 + -1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082bb0
	ctx.lr = 0x82072580;
	sub_82082BB0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6652);
	// lbz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820725b0
	if (!ctx.cr6.eq) goto loc_820725B0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r3,35(r11)
	REX_STORE_U8(ctx.r11.u32 + 35, ctx.r3.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820725AC;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820725B0:
	// addi r10,r30,2
	ctx.r10.s64 = ctx.r30.s64 + 2;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stb r3,35(r11)
	REX_STORE_U8(ctx.r11.u32 + 35, ctx.r3.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x820725D0;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_820725D4:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082bb0
	ctx.lr = 0x820725DC;
	sub_82082BB0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82082bb0
	ctx.lr = 0x820725E8;
	sub_82082BB0(ctx, base);
	// addi r29,r3,-1
	ctx.r29.s64 = ctx.r3.s64 + -1;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82082bb0
	ctx.lr = 0x820725F4;
	sub_82082BB0(ctx, base);
	// cmplwi cr6,r3,3
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 3, ctx.xer);
	// bge cr6,0x82072664
	if (!ctx.cr6.lt) goto loc_82072664;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r9,r10,r30
	ctx.r9.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r4,-6628(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r8,104(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 104);
	// and r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82072664
	if (ctx.cr6.eq) goto loc_82072664;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820a4038
	ctx.lr = 0x8207262C;
	sub_820A4038(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x8207263C;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_82072640:
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8206f988
	ctx.lr = 0x82072654;
	sub_8206F988(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82072668
	if (ctx.cr6.eq) goto loc_82072668;
loc_82072664:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82072668:
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a894
	ctx.lr = 0x82072674;
	__restfpr_24(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
