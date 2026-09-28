DEFINE_REX_FUNC(sub_8206D980) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8206D988;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32215
	ctx.r29.s64 = -2111242240;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,616(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 616);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x8206dbb8
	if (ctx.cr6.gt) goto loc_8206DBB8;
	// lis r12,-32249
	ctx.r12.s64 = -2113470464;
	// addi r12,r12,-9800
	ctx.r12.s64 = ctx.r12.s64 + -9800;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8206D9CC;
	case 1:
		goto loc_8206DA0C;
	case 2:
		goto loc_8206DBB8;
	case 3:
		goto loc_8206DAD8;
	case 4:
		goto loc_8206DB94;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8206D9CC:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lbz r10,272(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 272);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206d9e8
	if (ctx.cr6.eq) goto loc_8206D9E8;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x8206dba8
	goto loc_8206DBA8;
loc_8206D9E8:
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lwz r11,820(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 820);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,820(r10)
	REX_STORE_U32(ctx.r10.u32 + 820, ctx.r11.u32);
	// bgt 0x8206dbb8
	if (ctx.cr0.gt) goto loc_8206DBB8;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,616(r29)
	REX_STORE_U32(ctx.r29.u32 + 616, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8206DA0C:
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// lwz r3,-6628(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// lwz r11,280(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 280);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8206dac8
	if (!ctx.cr6.gt) goto loc_8206DAC8;
	// lbz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8206daac
	if (!ctx.cr6.eq) goto loc_8206DAAC;
	// lhz r28,30(r31)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r31.u32 + 30);
	// bl 0x820a3900
	ctx.lr = 0x8206DA34;
	sub_820A3900(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r4,-6628(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x8206da84
	if (ctx.cr6.eq) goto loc_8206DA84;
	// bl 0x820a37b8
	ctx.lr = 0x8206DA48;
	sub_820A37B8(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// li r5,15
	ctx.r5.s64 = 15;
	// sth r11,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r11.u16);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82054d38
	ctx.lr = 0x8206DA60;
	sub_82054D38(ctx, base);
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// li r11,300
	ctx.r11.s64 = 300;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,616(r29)
	REX_STORE_U32(ctx.r29.u32 + 616, ctx.r10.u32);
	// stw r11,820(r9)
	REX_STORE_U32(ctx.r9.u32 + 820, ctx.r11.u32);
	// lwz r11,-6628(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6628);
	// stw r10,140(r11)
	REX_STORE_U32(ctx.r11.u32 + 140, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8206DA84:
	// li r6,0
	ctx.r6.s64 = 0;
	// extsh r5,r28
	ctx.r5.s64 = ctx.r28.s16;
	// bl 0x820a2ed8
	ctx.lr = 0x8206DA90;
	sub_820A2ED8(ctx, base);
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,300
	ctx.r10.s64 = 300;
	// stw r11,616(r29)
	REX_STORE_U32(ctx.r29.u32 + 616, ctx.r11.u32);
	// stw r10,820(r9)
	REX_STORE_U32(ctx.r9.u32 + 820, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8206DAAC:
	// li r4,36
	ctx.r4.s64 = 36;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8206DAB8;
	sub_82053BC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82057d78
	ctx.lr = 0x8206DAC0;
	sub_82057D78(ctx, base);
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x8206dba8
	goto loc_8206DBA8;
loc_8206DAC8:
	// li r11,12
	ctx.r11.s64 = 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// sth r11,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r11.u16);
	// b 0x8206db98
	goto loc_8206DB98;
loc_8206DAD8:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lbz r10,272(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 272);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206db78
	if (ctx.cr6.eq) goto loc_8206DB78;
	// lwz r5,24(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8206d9e8
	if (ctx.cr6.eq) goto loc_8206D9E8;
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r4,32
	ctx.r4.s64 = 32;
	// bl 0x821274b0
	ctx.lr = 0x8206DB08;
	sub_821274B0(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,105
	ctx.r6.s64 = 105;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-6596(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -6596);
	// bl 0x820a1138
	ctx.lr = 0x8206DB28;
	sub_820A1138(ctx, base);
	// li r4,40
	ctx.r4.s64 = 40;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82053bc8
	ctx.lr = 0x8206DB34;
	sub_82053BC8(ctx, base);
	// lhz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8206db64
	if (ctx.cr6.lt) goto loc_8206DB64;
	// beq cr6,0x8206db5c
	if (ctx.cr6.eq) goto loc_8206DB5C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8206db54
	if (ctx.cr6.eq) goto loc_8206DB54;
	// li r4,582
	ctx.r4.s64 = 582;
	// b 0x8206db68
	goto loc_8206DB68;
loc_8206DB54:
	// li r4,390
	ctx.r4.s64 = 390;
	// b 0x8206db68
	goto loc_8206DB68;
loc_8206DB5C:
	// li r4,389
	ctx.r4.s64 = 389;
	// b 0x8206db68
	goto loc_8206DB68;
loc_8206DB64:
	// li r4,382
	ctx.r4.s64 = 382;
loc_8206DB68:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x82067230
	ctx.lr = 0x8206DB78;
	sub_82067230(ctx, base);
loc_8206DB78:
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,300
	ctx.r10.s64 = 300;
	// stw r11,616(r29)
	REX_STORE_U32(ctx.r29.u32 + 616, ctx.r11.u32);
	// stw r10,820(r9)
	REX_STORE_U32(ctx.r9.u32 + 820, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8206DB94:
	// li r4,10
	ctx.r4.s64 = 10;
loc_8206DB98:
	// li r5,26
	ctx.r5.s64 = 26;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82054d38
	ctx.lr = 0x8206DBA4;
	sub_82054D38(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
loc_8206DBA8:
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// stw r10,616(r29)
	REX_STORE_U32(ctx.r29.u32 + 616, ctx.r10.u32);
	// li r11,300
	ctx.r11.s64 = 300;
	// stw r11,820(r9)
	REX_STORE_U32(ctx.r9.u32 + 820, ctx.r11.u32);
loc_8206DBB8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
