DEFINE_REX_FUNC(sub_820A89F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x820A8A00;
	__savegprlr_23(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lbz r11,28715(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a8cd8
	if (ctx.cr6.eq) goto loc_820A8CD8;
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// li r23,1
	ctx.r23.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x820a8a34
	if (!ctx.cr6.gt) goto loc_820A8A34;
loc_820A8A28:
	// rlwinm r23,r23,1,0,30
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820a8a28
	if (ctx.cr6.lt) goto loc_820A8A28;
loc_820A8A34:
	// lwz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// li r25,1
	ctx.r25.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x820a8a50
	if (!ctx.cr6.gt) goto loc_820A8A50;
loc_820A8A44:
	// rlwinm r25,r25,1,0,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r25,r11
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820a8a44
	if (ctx.cr6.lt) goto loc_820A8A44;
loc_820A8A50:
	// lwz r4,24(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// addi r11,r4,-1
	ctx.r11.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bgt cr6,0x820a8cc8
	if (ctx.cr6.gt) goto loc_820A8CC8;
	// lis r12,-32245
	ctx.r12.s64 = -2113208320;
	// addi r12,r12,-30088
	ctx.r12.s64 = ctx.r12.s64 + -30088;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_820A8AC8;
	case 1:
		goto loc_820A8CC8;
	case 2:
		goto loc_820A8CC8;
	case 3:
		goto loc_820A8CC8;
	case 4:
		goto loc_820A8AD4;
	case 5:
		goto loc_820A8CC8;
	case 6:
		goto loc_820A8AA4;
	case 7:
		goto loc_820A8AB0;
	case 8:
		goto loc_820A8AB0;
	case 9:
		goto loc_820A8ABC;
	case 10:
		goto loc_820A8ABC;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820A8AA4:
	// lis r26,6688
	ctx.r26.s64 = 438304768;
	// ori r26,r26,82
	ctx.r26.u64 = ctx.r26.u64 | 82;
	// b 0x820a8adc
	goto loc_820A8ADC;
loc_820A8AB0:
	// lis r26,6688
	ctx.r26.s64 = 438304768;
	// ori r26,r26,83
	ctx.r26.u64 = ctx.r26.u64 | 83;
	// b 0x820a8adc
	goto loc_820A8ADC;
loc_820A8ABC:
	// lis r26,6688
	ctx.r26.s64 = 438304768;
	// ori r26,r26,84
	ctx.r26.u64 = ctx.r26.u64 | 84;
	// b 0x820a8adc
	goto loc_820A8ADC;
loc_820A8AC8:
	// lis r26,6184
	ctx.r26.s64 = 405274624;
	// ori r26,r26,134
	ctx.r26.u64 = ctx.r26.u64 | 134;
	// b 0x820a8adc
	goto loc_820A8ADC;
loc_820A8AD4:
	// lis r26,6184
	ctx.r26.s64 = 405274624;
	// ori r26,r26,79
	ctx.r26.u64 = ctx.r26.u64 | 79;
loc_820A8ADC:
	// clrlwi r27,r29,23
	ctx.r27.u64 = ctx.r29.u32 & 0x1FF;
	// li r28,0
	ctx.r28.s64 = 0;
loc_820A8AE4:
	// mulli r11,r27,56
	ctx.r11.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(56));
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r31,r11,40
	ctx.r31.s64 = ctx.r11.s64 + 40;
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a8b48
	if (!ctx.cr6.eq) goto loc_820A8B48;
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r5,44(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 44);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// stw r28,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r28.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r28,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x820d7d00
	ctx.lr = 0x820A8B38;
	sub_820D7D00(ctx, base);
	// lwz r4,36(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// bl 0x820d7d70
	ctx.lr = 0x820A8B48;
	sub_820D7D70(ctx, base);
loc_820A8B48:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r27,1
	ctx.r10.s64 = ctx.r27.s64 + 1;
	// clrlwi r27,r10,23
	ctx.r27.u64 = ctx.r10.u32 & 0x1FF;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820a8ae4
	if (!ctx.cr6.eq) goto loc_820A8AE4;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820A8B70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bgt cr6,0x820a8cd8
	if (ctx.cr6.gt) goto loc_820A8CD8;
	// lis r12,-32245
	ctx.r12.s64 = -2113208320;
	// addi r12,r12,-29800
	ctx.r12.s64 = ctx.r12.s64 + -29800;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_820A8C68;
	case 1:
		goto loc_820A8C68;
	case 2:
		goto loc_820A8BDC;
	case 3:
		goto loc_820A8C68;
	case 4:
		goto loc_820A8CD8;
	case 5:
		goto loc_820A8C68;
	case 6:
		goto loc_820A8BDC;
	case 7:
		goto loc_820A8C68;
	case 8:
		goto loc_820A8C68;
	case 9:
		goto loc_820A8C68;
	case 10:
		goto loc_820A8C68;
	case 11:
		goto loc_820A8CAC;
	case 12:
		goto loc_820A8C68;
	case 13:
		goto loc_820A8CD8;
	case 14:
		goto loc_820A8BDC;
	case 15:
		goto loc_820A8BDC;
	case 16:
		goto loc_820A8C68;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820A8BDC:
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bfee8
	ctx.lr = 0x820A8BE8;
	sub_820BFEE8(ctx, base);
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bfc30
	ctx.lr = 0x820A8BF4;
	sub_820BFC30(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820c00b8
	ctx.lr = 0x820A8C00;
	sub_820C00B8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r6,8(r24)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r28,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r28,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f1,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f1.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820c4ff8
	ctx.lr = 0x820A8C34;
	sub_820C4FF8(ctx, base);
	// lis r6,16384
	ctx.r6.s64 = 1073741824;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r5,8(r24)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x820c46f8
	ctx.lr = 0x820A8C48;
	sub_820C46F8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820c46f8
	ctx.lr = 0x820A8C60;
	sub_820C46F8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
loc_820A8C68:
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bfee8
	ctx.lr = 0x820A8C74;
	sub_820BFEE8(ctx, base);
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bfc30
	ctx.lr = 0x820A8C80;
	sub_820BFC30(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820c00b8
	ctx.lr = 0x820A8C8C;
	sub_820C00B8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820c46f8
	ctx.lr = 0x820A8CA4;
	sub_820C46F8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
loc_820A8CAC:
	// lis r6,16384
	ctx.r6.s64 = 1073741824;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x820c46f8
	ctx.lr = 0x820A8CC0;
	sub_820C46F8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
loc_820A8CC8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,8064
	ctx.r3.s64 = ctx.r11.s64 + 8064;
	// bl 0x820798d8
	ctx.lr = 0x820A8CD4;
	sub_820798D8(ctx, base);
	// bl 0x8208c5d8
	ctx.lr = 0x820A8CD8;
	sub_8208C5D8(ctx, base);
loc_820A8CD8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
