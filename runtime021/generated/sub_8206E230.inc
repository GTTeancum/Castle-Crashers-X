DEFINE_REX_FUNC(sub_8206E230) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x8206E238;
	__savegprlr_22(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bgt cr6,0x8206e80c
	if (ctx.cr6.gt) goto loc_8206E80C;
	// lis r12,-32249
	ctx.r12.s64 = -2113470464;
	// addi r12,r12,-7580
	ctx.r12.s64 = ctx.r12.s64 + -7580;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8206E280;
	case 1:
		goto loc_8206E414;
	case 2:
		goto loc_8206E4A4;
	case 3:
		goto loc_8206E6FC;
	case 4:
		goto loc_8206E404;
	case 5:
		goto loc_8206E78C;
	case 6:
		goto loc_8206E7F8;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8206E280:
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// lwz r10,-6628(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// lwz r11,24(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206e2a0
	if (ctx.cr6.eq) goto loc_8206E2A0;
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// stw r11,2872(r9)
	REX_STORE_U32(ctx.r9.u32 + 2872, ctx.r11.u32);
loc_8206E2A0:
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// li r22,1
	ctx.r22.s64 = 1;
	// lbz r9,2704(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 2704);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206e2bc
	if (ctx.cr6.eq) goto loc_8206E2BC;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// b 0x8206e2c4
	goto loc_8206E2C4;
loc_8206E2BC:
	// bl 0x820a0f88
	ctx.lr = 0x8206E2C0;
	sub_820A0F88(ctx, base);
	// lwz r10,-6628(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
loc_8206E2C4:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206e404
	if (ctx.cr6.eq) goto loc_8206E404;
	// lwz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8206e2fc
	if (ctx.cr6.eq) goto loc_8206E2FC;
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206e2fc
	if (ctx.cr6.eq) goto loc_8206E2FC;
	// lbz r11,1185(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 1185);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// bne cr6,0x8206e300
	if (!ctx.cr6.eq) goto loc_8206E300;
loc_8206E2FC:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8206E300:
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,624(r10)
	REX_STORE_U8(ctx.r10.u32 + 624, ctx.r11.u8);
	// lwz r3,20(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206E31C;
	sub_82067230(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,24(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x8206E330;
	sub_82067230(ctx, base);
	// lwz r7,48(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,596
	ctx.r4.s64 = 596;
	// lwz r3,28(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 28);
	// bl 0x82067230
	ctx.lr = 0x8206E344;
	sub_82067230(ctx, base);
	// lwz r6,48(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r6)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + 32);
	// bl 0x82067230
	ctx.lr = 0x8206E358;
	sub_82067230(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,36(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// bl 0x82067230
	ctx.lr = 0x8206E36C;
	sub_82067230(ctx, base);
	// lwz r4,64(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// bne cr6,0x8206e3b8
	if (!ctx.cr6.eq) goto loc_8206E3B8;
	// li r11,217
	ctx.r11.s64 = 217;
	// stw r29,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r29.u32);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// sth r11,84(r1)
	REX_STORE_U16(ctx.r1.u32 + 84, ctx.r11.u16);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r11,-6624(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x8206E398;
	sub_82052EA8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// subfic r8,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r8.u64 = static_cast<uint64_t>(0) - ctx.r9.u64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r7,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r6,r11,6
	ctx.r6.s64 = ctx.r11.s64 + 6;
	// sth r6,60(r31)
	REX_STORE_U16(ctx.r31.u32 + 60, ctx.r6.u16);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8206E3B8:
	// lwz r3,-6628(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// bl 0x820a39f0
	ctx.lr = 0x8206E3C0;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206e6d0
	if (ctx.cr6.eq) goto loc_8206E6D0;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r5,64(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-6596(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// bl 0x820a0988
	ctx.lr = 0x8206E3E0;
	sub_820A0988(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8206e6d0
	if (ctx.cr6.eq) goto loc_8206E6D0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,-6628(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// bl 0x820a37b8
	ctx.lr = 0x8206E3F8;
	sub_820A37B8(ctx, base);
	// sth r22,60(r31)
	REX_STORE_U16(ctx.r31.u32 + 60, ctx.r22.u16);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8206E404:
	// li r11,5
	ctx.r11.s64 = 5;
	// sth r11,60(r31)
	REX_STORE_U16(ctx.r31.u32 + 60, ctx.r11.u16);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8206E414:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,529
	ctx.r4.s64 = 529;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206E428;
	sub_82067230(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,530
	ctx.r4.s64 = 530;
	// lwz r3,24(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x8206E43C;
	sub_82067230(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,531
	ctx.r4.s64 = 531;
	// lwz r3,28(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 28);
	// bl 0x82067230
	ctx.lr = 0x8206E450;
	sub_82067230(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,532
	ctx.r4.s64 = 532;
	// lwz r3,32(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 32);
	// bl 0x82067230
	ctx.lr = 0x8206E464;
	sub_82067230(ctx, base);
	// lwz r7,48(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,36(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// bl 0x82067230
	ctx.lr = 0x8206E478;
	sub_82067230(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r10,828(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 828);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,828(r11)
	REX_STORE_U32(ctx.r11.u32 + 828, ctx.r10.u32);
	// bne 0x8206e80c
	if (!ctx.cr0.eq) goto loc_8206E80C;
	// li r9,5
	ctx.r9.s64 = 5;
	// li r10,300
	ctx.r10.s64 = 300;
	// sth r9,60(r31)
	REX_STORE_U16(ctx.r31.u32 + 60, ctx.r9.u16);
	// stw r10,828(r11)
	REX_STORE_U32(ctx.r11.u32 + 828, ctx.r10.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8206E4A4:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206E4B8;
	sub_82067230(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,24(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x8206E4CC;
	sub_82067230(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,596
	ctx.r4.s64 = 596;
	// lwz r3,28(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 28);
	// bl 0x82067230
	ctx.lr = 0x8206E4E0;
	sub_82067230(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 32);
	// bl 0x82067230
	ctx.lr = 0x8206E4F4;
	sub_82067230(ctx, base);
	// lwz r7,48(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,36(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// bl 0x82067230
	ctx.lr = 0x8206E508;
	sub_82067230(ctx, base);
	// lwz r4,64(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// bne cr6,0x8206e52c
	if (!ctx.cr6.eq) goto loc_8206E52C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// sth r10,60(r31)
	REX_STORE_U16(ctx.r31.u32 + 60, ctx.r10.u16);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8206E52C:
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// lwz r3,-6628(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// bl 0x820a39f0
	ctx.lr = 0x8206E538;
	sub_820A39F0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206e6d0
	if (ctx.cr6.eq) goto loc_8206E6D0;
	// lwz r11,-6628(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// li r22,1
	ctx.r22.s64 = 1;
	// lwz r10,64(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// slw r9,r22,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r22.u32 << (ctx.r10.u8 & 0x3F));
	// lwz r8,104(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// and r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8206e6e8
	if (ctx.cr6.eq) goto loc_8206E6E8;
	// lis r11,-32215
	ctx.r11.s64 = -2111242240;
	// lwz r11,2872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2872);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206e6d0
	if (!ctx.cr6.eq) goto loc_8206E6D0;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r23,r29
	ctx.r23.u64 = ctx.r29.u64;
	// mr r26,r29
	ctx.r26.u64 = ctx.r29.u64;
	// lwz r30,-6596(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// mr r25,r29
	ctx.r25.u64 = ctx.r29.u64;
	// mr r24,r29
	ctx.r24.u64 = ctx.r29.u64;
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
loc_8206E594:
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// rlwinm r10,r27,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r22,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r22.u8);
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// add r10,r27,r10
	ctx.r10.u64 = ctx.r27.u64 + ctx.r10.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r5,r11,97
	ctx.r5.s64 = ctx.r11.s64 + 97;
	// lwzx r4,r9,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r30.u32);
	// bl 0x8209d3d8
	ctx.lr = 0x8206E5C0;
	sub_8209D3D8(ctx, base);
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x8206E5DC;
	sub_8209D488(ctx, base);
	// lbz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// clrlwi r6,r26,16
	ctx.r6.u64 = ctx.r26.u32 & 0xFFFF;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// clrlwi r28,r4,24
	ctx.r28.u64 = ctx.r4.u32 & 0xFF;
	// cmplw cr6,r28,r6
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8206e6a8
	if (ctx.cr6.lt) goto loc_8206E6A8;
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// addi r5,r1,81
	ctx.r5.s64 = ctx.r1.s64 + 81;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// stb r29,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r29.u8);
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// stb r29,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r29.u8);
	// stb r29,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r29.u8);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stb r29,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
	// lwzx r4,r10,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x8206E620;
	sub_8209D488(ctx, base);
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x8206E63C;
	sub_8209D488(ctx, base);
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// addi r5,r1,82
	ctx.r5.s64 = ctx.r1.s64 + 82;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r7,r11,5
	ctx.r7.s64 = ctx.r11.s64 + 5;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r6,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x8206E658;
	sub_8209D488(ctx, base);
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// addi r4,r11,5
	ctx.r4.s64 = ctx.r11.s64 + 5;
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// bl 0x8209d488
	ctx.lr = 0x8206E674;
	sub_8209D488(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r9,81(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r8,82(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// rlwimi r10,r9,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 84);
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwimi r8,r7,8,0,23
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r8.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r11,r8,8,0,23
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r11.u64 & 0xFFFFFFFF000000FF);
	// cmplw cr6,r11,r25
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r25.u32, ctx.xer);
	// ble cr6,0x8206e6a8
	if (!ctx.cr6.gt) goto loc_8206E6A8;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
	// mr r23,r24
	ctx.r23.u64 = ctx.r24.u64;
	// clrlwi r26,r28,24
	ctx.r26.u64 = ctx.r28.u32 & 0xFF;
loc_8206E6A8:
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// clrlwi r24,r11,16
	ctx.r24.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r27,r24
	ctx.r27.u64 = ctx.r24.u64;
	// cmplwi cr6,r24,28
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 28, ctx.xer);
	// blt cr6,0x8206e594
	if (ctx.cr6.lt) goto loc_8206E594;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// lwz r3,64(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// clrlwi r5,r26,16
	ctx.r5.u64 = ctx.r26.u32 & 0xFFFF;
	// clrlwi r4,r23,16
	ctx.r4.u64 = ctx.r23.u32 & 0xFFFF;
	// bl 0x82052318
	ctx.lr = 0x8206E6D0;
	sub_82052318(ctx, base);
loc_8206E6D0:
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8206E6E8:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8206E6F4;
	sub_82053BC8(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8206E6FC:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,524
	ctx.r4.s64 = 524;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206E710;
	sub_82067230(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,525
	ctx.r4.s64 = 525;
	// lwz r3,24(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x8206E724;
	sub_82067230(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,28(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 28);
	// bl 0x82067230
	ctx.lr = 0x8206E738;
	sub_82067230(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,508
	ctx.r4.s64 = 508;
	// lwz r3,32(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 32);
	// bl 0x82067230
	ctx.lr = 0x8206E74C;
	sub_82067230(ctx, base);
	// lwz r7,48(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,509
	ctx.r4.s64 = 509;
	// lwz r3,36(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// bl 0x82067230
	ctx.lr = 0x8206E760;
	sub_82067230(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r10,828(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 828);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,828(r11)
	REX_STORE_U32(ctx.r11.u32 + 828, ctx.r10.u32);
	// bne 0x8206e80c
	if (!ctx.cr0.eq) goto loc_8206E80C;
	// li r9,5
	ctx.r9.s64 = 5;
	// li r10,300
	ctx.r10.s64 = 300;
	// sth r9,60(r31)
	REX_STORE_U16(ctx.r31.u32 + 60, ctx.r9.u16);
	// stw r10,828(r11)
	REX_STORE_U32(ctx.r11.u32 + 828, ctx.r10.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8206E78C:
	// li r11,217
	ctx.r11.s64 = 217;
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// sth r11,84(r1)
	REX_STORE_U16(ctx.r1.u32 + 84, ctx.r11.u16);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r11,-6624(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// bl 0x82052ea8
	ctx.lr = 0x8206E7A8;
	sub_82052EA8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// stw r29,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// stw r29,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r29.u32);
	// sth r29,60(r31)
	REX_STORE_U16(ctx.r31.u32 + 60, ctx.r29.u16);
	// lwz r4,-6628(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + -6628);
	// bl 0x820a37b8
	ctx.lr = 0x8206E7C8;
	sub_820A37B8(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r4,r9,9424
	ctx.r4.s64 = ctx.r9.s64 + 9424;
	// bl 0x82053a00
	ctx.lr = 0x8206E7D8;
	sub_82053A00(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-6624(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// bl 0x82077a98
	ctx.lr = 0x8206E7E4;
	sub_82077A98(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6624(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6624);
	// bl 0x8206dd58
	ctx.lr = 0x8206E7F0;
	sub_8206DD58(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8206E7F8:
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r29.u32);
	// sth r29,60(r31)
	REX_STORE_U16(ctx.r31.u32 + 60, ctx.r29.u16);
	// bl 0x8206e818
	ctx.lr = 0x8206E80C;
	sub_8206E818(ctx, base);
loc_8206E80C:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
