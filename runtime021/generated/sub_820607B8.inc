DEFINE_REX_FUNC(sub_820607B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e4
	ctx.lr = 0x820607C0;
	__savegprlr_15(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r30,-32221
	ctx.r30.s64 = -2111635456;
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,24828(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24828);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lhz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 12);
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// beq cr6,0x82060820
	if (ctx.cr6.eq) goto loc_82060820;
	// extsh r29,r11
	ctx.r29.s64 = ctx.r11.s16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82065d08
	ctx.lr = 0x820607F0;
	sub_82065D08(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82060820
	if (!ctx.cr6.eq) goto loc_82060820;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// bl 0x82065df0
	ctx.lr = 0x82060808;
	sub_82065DF0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82060820
	if (!ctx.cr6.eq) goto loc_82060820;
	// lwz r11,24828(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24828);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,24828(r30)
	REX_STORE_U32(ctx.r30.u32 + 24828, ctx.r11.u32);
loc_82060820:
	// lhz r11,34(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82061458
	if (ctx.cr6.gt) goto loc_82061458;
	// lis r12,-32250
	ctx.r12.s64 = -2113536000;
	// addi r12,r12,2120
	ctx.r12.s64 = ctx.r12.s64 + 2120;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82060858;
	case 1:
		goto loc_820608A8;
	case 2:
		goto loc_82060978;
	case 3:
		goto loc_82061388;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82060858:
	// li r11,0
	ctx.r11.s64 = 0;
	// lhz r8,24(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// lhz r6,28(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 28);
	// lhz r4,26(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 26);
	// lhz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bl 0x82051a20
	ctx.lr = 0x82060874;
	sub_82051A20(ctx, base);
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// lhz r4,30(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 30);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r7,9
	ctx.r7.s64 = 9;
	// lwz r3,-6628(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -6628);
	// bl 0x820a5620
	ctx.lr = 0x8206088C;
	sub_820A5620(ctx, base);
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// li r8,2
	ctx.r8.s64 = 2;
	// li r11,300
	ctx.r11.s64 = 300;
	// sth r8,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r8.u16);
	// stw r11,792(r9)
	REX_STORE_U32(ctx.r9.u32 + 792, ctx.r11.u32);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
loc_820608A8:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lhz r9,24(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// lwz r11,-6628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -6628);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82060918
	if (ctx.cr6.eq) goto loc_82060918;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x82060918
	if (ctx.cr6.eq) goto loc_82060918;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x82060904
	if (ctx.cr6.eq) goto loc_82060904;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82060938
	if (ctx.cr6.eq) goto loc_82060938;
	// lwz r3,60(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r3,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// bne cr6,0x820608f4
	if (!ctx.cr6.eq) goto loc_820608F4;
	// bl 0x820520f0
	ctx.lr = 0x820608F4;
	sub_820520F0(ctx, base);
loc_820608F4:
	// li r11,3
	ctx.r11.s64 = 3;
	// sth r11,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r11.u16);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
loc_82060904:
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// lwz r11,792(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 792);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,792(r10)
	REX_STORE_U32(ctx.r10.u32 + 792, ctx.r11.u32);
	// bgt 0x82061458
	if (ctx.cr0.gt) goto loc_82061458;
loc_82060918:
	// li r11,6
	ctx.r11.s64 = 6;
	// li r5,15
	ctx.r5.s64 = 15;
	// sth r11,46(r31)
	REX_STORE_U16(ctx.r31.u32 + 46, ctx.r11.u16);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82054d38
	ctx.lr = 0x82060930;
	sub_82054D38(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
loc_82060938:
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r9,4
	ctx.r9.s64 = 4;
	// sth r11,46(r31)
	REX_STORE_U16(ctx.r31.u32 + 46, ctx.r11.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// sth r9,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r9.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// bl 0x82067230
	ctx.lr = 0x8206095C;
	sub_82067230(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 36);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82067230
	ctx.lr = 0x82060970;
	sub_82067230(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
loc_82060978:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lhz r9,30(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 30);
	// lhz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820612ec
	if (ctx.cr6.eq) goto loc_820612EC;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bne cr6,0x820612ec
	if (!ctx.cr6.eq) goto loc_820612EC;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820612ec
	if (ctx.cr6.eq) goto loc_820612EC;
	// lwz r16,8(r11)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x820612ec
	if (ctx.cr6.eq) goto loc_820612EC;
	// li r17,0
	ctx.r17.s64 = 0;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// li r15,4
	ctx.r15.s64 = 4;
	// mr r29,r17
	ctx.r29.u64 = ctx.r17.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82060abc
	if (!ctx.cr6.eq) goto loc_82060ABC;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// clrlwi r3,r9,16
	ctx.r3.u64 = ctx.r9.u32 & 0xFFFF;
	// li r28,-1
	ctx.r28.s64 = -1;
	// bl 0x820b59f8
	ctx.lr = 0x820609E0;
	sub_820B59F8(ctx, base);
	// ld r19,80(r1)
	ctx.r19.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r18,80(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r8,r17
	ctx.r8.u64 = ctx.r17.u64;
	// lwz r20,80(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x82060aa4
	if (ctx.cr6.eq) goto loc_82060AA4;
	// lwz r7,40(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
loc_820609FC:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x82060a0c
	if (!ctx.cr6.eq) goto loc_82060A0C;
	// mr r9,r17
	ctx.r9.u64 = ctx.r17.u64;
	// b 0x82060a48
	goto loc_82060A48;
loc_82060A0C:
	// lwz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82060a20
	if (ctx.cr6.eq) goto loc_82060A20;
	// mr r9,r17
	ctx.r9.u64 = ctx.r17.u64;
	// b 0x82060a48
	goto loc_82060A48;
loc_82060A20:
	// lwz r10,4(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// li r9,1
	ctx.r9.s64 = 1;
	// add r6,r8,r11
	ctx.r6.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r11,r6,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r20,r11,24
	ctx.r20.s64 = ctx.r11.s64 + 24;
	// lwz r18,8(r11)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// ld r19,16(r11)
	ctx.r19.u64 = REX_LOAD_U64(ctx.r11.u32 + 16);
loc_82060A48:
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82060a90
	if (ctx.cr6.eq) goto loc_82060A90;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
loc_82060A5C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r6,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r6.u64;
	// beq cr6,0x82060a80
	if (ctx.cr6.eq) goto loc_82060A80;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82060a5c
	if (ctx.cr6.eq) goto loc_82060A5C;
loc_82060A80:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82060a90
	if (!ctx.cr6.eq) goto loc_82060A90;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r8,r16
	ctx.r8.u64 = ctx.r16.u64;
loc_82060A90:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplw cr6,r8,r16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r16.u32, ctx.xer);
	// blt cr6,0x820609fc
	if (ctx.cr6.lt) goto loc_820609FC;
	// cmpwi cr6,r28,-1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, -1, ctx.xer);
	// bne cr6,0x82060ab4
	if (!ctx.cr6.eq) goto loc_82060AB4;
loc_82060AA4:
	// li r11,8
	ctx.r11.s64 = 8;
	// sth r15,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r15.u16);
	// sth r11,46(r31)
	REX_STORE_U16(ctx.r31.u32 + 46, ctx.r11.u16);
	// b 0x82060ad8
	goto loc_82060AD8;
loc_82060AB4:
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// b 0x82060ad8
	goto loc_82060AD8;
loc_82060ABC:
	// ld r19,80(r1)
	ctx.r19.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r18,80(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r20,80(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bne cr6,0x82060ad8
	if (!ctx.cr6.eq) goto loc_82060AD8;
	// lhz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 28);
	// addi r30,r11,-1
	ctx.r30.s64 = ctx.r11.s64 + -1;
loc_82060AD8:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82060b04
	if (ctx.cr6.eq) goto loc_82060B04;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82060b04
	if (!ctx.cr6.eq) goto loc_82060B04;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82060b04
	if (ctx.cr6.eq) goto loc_82060B04;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82060b08
	goto loc_82060B08;
loc_82060B04:
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
loc_82060B08:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// bl 0x820670f8
	ctx.lr = 0x82060B18;
	sub_820670F8(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,507
	ctx.r4.s64 = 507;
	// lwz r3,36(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// bl 0x82067230
	ctx.lr = 0x82060B2C;
	sub_82067230(ctx, base);
	// lhz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r8,r9,18280
	ctx.r8.s64 = ctx.r9.s64 + 18280;
	// rotlwi r7,r10,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// lwzx r6,r7,r8
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// clrlwi r11,r6,16
	ctx.r11.u64 = ctx.r6.u32 & 0xFFFF;
	// blt cr6,0x82061078
	if (ctx.cr6.lt) goto loc_82061078;
	// beq cr6,0x82060e18
	if (ctx.cr6.eq) goto loc_82060E18;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bne cr6,0x820612dc
	if (!ctx.cr6.eq) goto loc_820612DC;
	// clrlwi r22,r11,16
	ctx.r22.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r22,5
	ctx.r8.s64 = ctx.r22.s64 + 5;
	// add r11,r29,r10
	ctx.r11.u64 = ctx.r29.u64 + ctx.r10.u64;
	// clrlwi r29,r8,16
	ctx.r29.u64 = ctx.r8.u32 & 0xFFFF;
	// lhz r10,8(r9)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r9.u32 + 8);
	// lis r7,30583
	ctx.r7.s64 = 2004287488;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r6,r10,5
	ctx.r6.s64 = ctx.r10.s64 + 5;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r5,16
	ctx.r11.u64 = ctx.r5.u32 & 0xFFFF;
	// ori r3,r7,30719
	ctx.r3.u64 = ctx.r7.u64 | 30719;
	// addi r10,r11,5
	ctx.r10.s64 = ctx.r11.s64 + 5;
	// lis r8,-1
	ctx.r8.s64 = -65536;
	// lwzx r7,r4,r9
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r5,r8,255
	ctx.r5.u64 = ctx.r8.u64 | 255;
	// addi r21,r30,9
	ctx.r21.s64 = ctx.r30.s64 + 9;
	// mr r23,r30
	ctx.r23.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r21
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r21.u32, ctx.xer);
	// stw r3,16(r7)
	REX_STORE_U32(ctx.r7.u32 + 16, ctx.r3.u32);
	// sth r11,8(r9)
	REX_STORE_U16(ctx.r9.u32 + 8, ctx.r11.u16);
	// lwzx r4,r6,r9
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// stw r5,16(r4)
	REX_STORE_U32(ctx.r4.u32 + 16, ctx.r5.u32);
	// bge cr6,0x820612dc
	if (!ctx.cr6.lt) goto loc_820612DC;
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r26,80(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r27,80(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lwz r24,80(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r28,r11,4,0,27
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r25,r11,18304
	ctx.r25.s64 = ctx.r11.s64 + 18304;
loc_82060BE4:
	// cmplw cr6,r23,r16
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r16.u32, ctx.xer);
	// bge cr6,0x82060dac
	if (!ctx.cr6.lt) goto loc_82060DAC;
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82060c00
	if (!ctx.cr6.eq) goto loc_82060C00;
	// mr r10,r17
	ctx.r10.u64 = ctx.r17.u64;
	// b 0x82060c30
	goto loc_82060C30;
loc_82060C00:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x82060c14
	if (ctx.cr6.eq) goto loc_82060C14;
	// mr r10,r17
	ctx.r10.u64 = ctx.r17.u64;
	// b 0x82060c30
	goto loc_82060C30;
loc_82060C14:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r20,r11,24
	ctx.r20.s64 = ctx.r11.s64 + 24;
	// lwz r18,8(r11)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// ld r19,16(r11)
	ctx.r19.u64 = REX_LOAD_U64(ctx.r11.u32 + 16);
loc_82060C30:
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82060dac
	if (ctx.cr6.eq) goto loc_82060DAC;
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// clrlwi r30,r8,16
	ctx.r30.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r3,r7,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// bl 0x820670f8
	ctx.lr = 0x82060C64;
	sub_820670F8(ctx, base);
	// addi r6,r30,5
	ctx.r6.s64 = ctx.r30.s64 + 5;
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r29,r6,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// lwzx r3,r29,r3
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r3.u32);
	// bl 0x820673b8
	ctx.lr = 0x82060C80;
	sub_820673B8(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// addi r9,r11,6376
	ctx.r9.s64 = ctx.r11.s64 + 6376;
	// clrlwi r30,r10,16
	ctx.r30.u64 = ctx.r10.u32 & 0xFFFF;
	// lwzx r7,r29,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r8.u32);
	// stw r31,24(r7)
	REX_STORE_U32(ctx.r7.u32 + 24, ctx.r31.u32);
	// stw r9,28(r7)
	REX_STORE_U32(ctx.r7.u32 + 28, ctx.r9.u32);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82060cf0
	if (ctx.cr6.eq) goto loc_82060CF0;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82060cc8
	if (!ctx.cr6.eq) goto loc_82060CC8;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// add r9,r10,r28
	ctx.r9.u64 = ctx.r10.u64 + ctx.r28.u64;
	// lwz r26,44(r9)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
loc_82060CC8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82060cf0
	if (ctx.cr6.eq) goto loc_82060CF0;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82060cf0
	if (!ctx.cr6.eq) goto loc_82060CF0;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lwz r11,44(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// addi r27,r11,24
	ctx.r27.s64 = ctx.r11.s64 + 24;
loc_82060CF0:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// ld r6,16(r27)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r27.u32 + 16);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ld r5,16(r26)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r26.u32 + 16);
	// bl 0x82127778
	ctx.lr = 0x82060D04;
	sub_82127778(ctx, base);
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r6,48(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// clrlwi r30,r8,16
	ctx.r30.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r3,r7,r6
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// bl 0x820673b8
	ctx.lr = 0x82060D2C;
	sub_820673B8(ctx, base);
	// addi r5,r30,5
	ctx.r5.s64 = ctx.r30.s64 + 5;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// addi r3,r30,1
	ctx.r3.s64 = ctx.r30.s64 + 1;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// rotlwi r4,r19,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r19.u32, 0);
	// clrlwi r30,r3,16
	ctx.r30.u64 = ctx.r3.u32 & 0xFFFF;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x820670f8
	ctx.lr = 0x82060D50;
	sub_820670F8(ctx, base);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82060d7c
	if (ctx.cr6.eq) goto loc_82060D7C;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82060d7c
	if (!ctx.cr6.eq) goto loc_82060D7C;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lwz r11,44(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// addi r24,r11,48
	ctx.r24.s64 = ctx.r11.s64 + 48;
loc_82060D7C:
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,16(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 16);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r10,568
	ctx.r4.s64 = ctx.r10.s64 + 568;
	// clrlwi r29,r7,16
	ctx.r29.u64 = ctx.r7.u32 & 0xFFFF;
	// lwzx r3,r6,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// bl 0x82067230
	ctx.lr = 0x82060DA8;
	sub_82067230(ctx, base);
	// b 0x82060df8
	goto loc_82060DF8;
loc_82060DAC:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// ble cr6,0x82060df8
	if (!ctx.cr6.gt) goto loc_82060DF8;
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
loc_82060DB8:
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// clrlwi r29,r8,16
	ctx.r29.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r6,r7,r10
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// stw r31,24(r6)
	REX_STORE_U32(ctx.r6.u32 + 24, ctx.r31.u32);
	// stw r17,28(r6)
	REX_STORE_U32(ctx.r6.u32 + 28, ctx.r17.u32);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwzx r3,r7,r3
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// bl 0x82067230
	ctx.lr = 0x82060DF0;
	sub_82067230(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82060db8
	if (!ctx.cr0.eq) goto loc_82060DB8;
loc_82060DF8:
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// addi r28,r28,48
	ctx.r28.s64 = ctx.r28.s64 + 48;
	// cmplw cr6,r23,r21
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r21.u32, ctx.xer);
	// blt cr6,0x82060be4
	if (ctx.cr6.lt) goto loc_82060BE4;
	// sth r15,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r15.u16);
	// sth r17,46(r31)
	REX_STORE_U16(ctx.r31.u32 + 46, ctx.r17.u16);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
loc_82060E18:
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// clrlwi r23,r11,16
	ctx.r23.u64 = ctx.r11.u32 & 0xFFFF;
	// lis r7,30583
	ctx.r7.s64 = 2004287488;
	// addi r8,r23,5
	ctx.r8.s64 = ctx.r23.s64 + 5;
	// ori r6,r7,30719
	ctx.r6.u64 = ctx.r7.u64 | 30719;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r9.u32 + 8);
	// clrlwi r29,r8,16
	ctx.r29.u64 = ctx.r8.u32 & 0xFFFF;
	// lis r5,-1
	ctx.r5.s64 = -65536;
	// addi r4,r11,5
	ctx.r4.s64 = ctx.r11.s64 + 5;
	// add r11,r10,r29
	ctx.r11.u64 = ctx.r10.u64 + ctx.r29.u64;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// ori r10,r5,255
	ctx.r10.u64 = ctx.r5.u64 | 255;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r22,r30,9
	ctx.r22.s64 = ctx.r30.s64 + 9;
	// lwzx r7,r3,r9
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// mr r24,r30
	ctx.r24.u64 = ctx.r30.u64;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r30,r22
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r22.u32, ctx.xer);
	// stw r6,16(r7)
	REX_STORE_U32(ctx.r7.u32 + 16, ctx.r6.u32);
	// sth r11,8(r9)
	REX_STORE_U16(ctx.r9.u32 + 8, ctx.r11.u16);
	// lwzx r4,r5,r9
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// stw r10,16(r4)
	REX_STORE_U32(ctx.r4.u32 + 16, ctx.r10.u32);
	// bge cr6,0x820612dc
	if (!ctx.cr6.lt) goto loc_820612DC;
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r26,80(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r27,80(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r28,r11,4,0,27
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r25,r11,18304
	ctx.r25.s64 = ctx.r11.s64 + 18304;
loc_82060E9C:
	// cmplw cr6,r24,r16
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r16.u32, ctx.xer);
	// bge cr6,0x8206100c
	if (!ctx.cr6.lt) goto loc_8206100C;
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82060eb8
	if (!ctx.cr6.eq) goto loc_82060EB8;
	// mr r10,r17
	ctx.r10.u64 = ctx.r17.u64;
	// b 0x82060ee8
	goto loc_82060EE8;
loc_82060EB8:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x82060ecc
	if (ctx.cr6.eq) goto loc_82060ECC;
	// mr r10,r17
	ctx.r10.u64 = ctx.r17.u64;
	// b 0x82060ee8
	goto loc_82060EE8;
loc_82060ECC:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r20,r11,24
	ctx.r20.s64 = ctx.r11.s64 + 24;
	// lwz r18,8(r11)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// ld r19,16(r11)
	ctx.r19.u64 = REX_LOAD_U64(ctx.r11.u32 + 16);
loc_82060EE8:
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206100c
	if (ctx.cr6.eq) goto loc_8206100C;
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// clrlwi r30,r8,16
	ctx.r30.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r3,r7,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// bl 0x820670f8
	ctx.lr = 0x82060F1C;
	sub_820670F8(ctx, base);
	// addi r6,r30,5
	ctx.r6.s64 = ctx.r30.s64 + 5;
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r29,r6,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// lwzx r3,r29,r3
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r3.u32);
	// bl 0x820673b8
	ctx.lr = 0x82060F38;
	sub_820673B8(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// addi r9,r11,6376
	ctx.r9.s64 = ctx.r11.s64 + 6376;
	// clrlwi r30,r10,16
	ctx.r30.u64 = ctx.r10.u32 & 0xFFFF;
	// lwzx r7,r29,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r8.u32);
	// stw r31,24(r7)
	REX_STORE_U32(ctx.r7.u32 + 24, ctx.r31.u32);
	// stw r9,28(r7)
	REX_STORE_U32(ctx.r7.u32 + 28, ctx.r9.u32);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82060fa8
	if (ctx.cr6.eq) goto loc_82060FA8;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82060f80
	if (!ctx.cr6.eq) goto loc_82060F80;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// add r9,r10,r28
	ctx.r9.u64 = ctx.r10.u64 + ctx.r28.u64;
	// lwz r26,44(r9)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
loc_82060F80:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82060fa8
	if (ctx.cr6.eq) goto loc_82060FA8;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82060fa8
	if (!ctx.cr6.eq) goto loc_82060FA8;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lwz r11,44(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// addi r27,r11,24
	ctx.r27.s64 = ctx.r11.s64 + 24;
loc_82060FA8:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// ld r6,16(r27)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r27.u32 + 16);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ld r5,16(r26)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r26.u32 + 16);
	// bl 0x82127778
	ctx.lr = 0x82060FBC;
	sub_82127778(ctx, base);
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r6,48(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// clrlwi r30,r8,16
	ctx.r30.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r3,r7,r6
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// bl 0x820673b8
	ctx.lr = 0x82060FE4;
	sub_820673B8(ctx, base);
	// addi r5,r30,5
	ctx.r5.s64 = ctx.r30.s64 + 5;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// addi r3,r30,1
	ctx.r3.s64 = ctx.r30.s64 + 1;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// rotlwi r4,r19,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r19.u32, 0);
	// clrlwi r29,r3,16
	ctx.r29.u64 = ctx.r3.u32 & 0xFFFF;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x820670f8
	ctx.lr = 0x82061008;
	sub_820670F8(ctx, base);
	// b 0x82061058
	goto loc_82061058;
loc_8206100C:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// ble cr6,0x82061058
	if (!ctx.cr6.gt) goto loc_82061058;
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
loc_82061018:
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// clrlwi r29,r8,16
	ctx.r29.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r6,r7,r10
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// stw r31,24(r6)
	REX_STORE_U32(ctx.r6.u32 + 24, ctx.r31.u32);
	// stw r17,28(r6)
	REX_STORE_U32(ctx.r6.u32 + 28, ctx.r17.u32);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwzx r3,r7,r3
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// bl 0x82067230
	ctx.lr = 0x82061050;
	sub_82067230(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82061018
	if (!ctx.cr0.eq) goto loc_82061018;
loc_82061058:
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// addi r28,r28,48
	ctx.r28.s64 = ctx.r28.s64 + 48;
	// cmplw cr6,r24,r22
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r22.u32, ctx.xer);
	// blt cr6,0x82060e9c
	if (ctx.cr6.lt) goto loc_82060E9C;
	// sth r15,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r15.u16);
	// sth r17,46(r31)
	REX_STORE_U16(ctx.r31.u32 + 46, ctx.r17.u16);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
loc_82061078:
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// clrlwi r25,r11,16
	ctx.r25.u64 = ctx.r11.u32 & 0xFFFF;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r25,5
	ctx.r8.s64 = ctx.r25.s64 + 5;
	// add r10,r29,r10
	ctx.r10.u64 = ctx.r29.u64 + ctx.r10.u64;
	// clrlwi r29,r8,16
	ctx.r29.u64 = ctx.r8.u32 & 0xFFFF;
	// lhz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r9.u32 + 8);
	// lis r7,30583
	ctx.r7.s64 = 2004287488;
	// lis r6,-1
	ctx.r6.s64 = -65536;
	// addi r5,r11,5
	ctx.r5.s64 = ctx.r11.s64 + 5;
	// add r11,r10,r29
	ctx.r11.u64 = ctx.r10.u64 + ctx.r29.u64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r10,r7,30719
	ctx.r10.u64 = ctx.r7.u64 | 30719;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// ori r8,r6,255
	ctx.r8.u64 = ctx.r6.u64 | 255;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// lwzx r7,r4,r9
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// addi r24,r30,9
	ctx.r24.s64 = ctx.r30.s64 + 9;
	// addi r6,r11,5
	ctx.r6.s64 = ctx.r11.s64 + 5;
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r30,r24
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r24.u32, ctx.xer);
	// stw r10,16(r7)
	REX_STORE_U32(ctx.r7.u32 + 16, ctx.r10.u32);
	// sth r11,8(r9)
	REX_STORE_U16(ctx.r9.u32 + 8, ctx.r11.u16);
	// lwzx r4,r5,r9
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// stw r8,16(r4)
	REX_STORE_U32(ctx.r4.u32 + 16, ctx.r8.u32);
	// bge cr6,0x820612dc
	if (!ctx.cr6.lt) goto loc_820612DC;
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r27,80(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r28,r11,4,0,27
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
loc_820610F4:
	// cmplw cr6,r26,r16
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r16.u32, ctx.xer);
	// bge cr6,0x82061280
	if (!ctx.cr6.lt) goto loc_82061280;
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82061110
	if (!ctx.cr6.eq) goto loc_82061110;
	// mr r10,r17
	ctx.r10.u64 = ctx.r17.u64;
	// b 0x82061140
	goto loc_82061140;
loc_82061110:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x82061124
	if (ctx.cr6.eq) goto loc_82061124;
	// mr r10,r17
	ctx.r10.u64 = ctx.r17.u64;
	// b 0x82061140
	goto loc_82061140;
loc_82061124:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r20,r11,24
	ctx.r20.s64 = ctx.r11.s64 + 24;
	// lwz r18,8(r11)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// ld r19,16(r11)
	ctx.r19.u64 = REX_LOAD_U64(ctx.r11.u32 + 16);
loc_82061140:
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82061280
	if (ctx.cr6.eq) goto loc_82061280;
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// clrlwi r30,r8,16
	ctx.r30.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r3,r7,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// bl 0x820670f8
	ctx.lr = 0x82061174;
	sub_820670F8(ctx, base);
	// addi r6,r30,5
	ctx.r6.s64 = ctx.r30.s64 + 5;
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r29,r6,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// lwzx r3,r29,r3
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r3.u32);
	// bl 0x820673b8
	ctx.lr = 0x82061190;
	sub_820673B8(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// addi r9,r11,6376
	ctx.r9.s64 = ctx.r11.s64 + 6376;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// lwzx r7,r29,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r8.u32);
	// stw r9,28(r7)
	REX_STORE_U32(ctx.r7.u32 + 28, ctx.r9.u32);
	// stw r31,24(r7)
	REX_STORE_U32(ctx.r7.u32 + 24, ctx.r31.u32);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820611dc
	if (ctx.cr6.eq) goto loc_820611DC;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x820611dc
	if (!ctx.cr6.eq) goto loc_820611DC;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lwz r11,44(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
	// addi r27,r11,24
	ctx.r27.s64 = ctx.r11.s64 + 24;
loc_820611DC:
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,16(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r30,r8,16
	ctx.r30.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r3,r7,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// bl 0x820670f8
	ctx.lr = 0x82061204;
	sub_820670F8(ctx, base);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206122c
	if (ctx.cr6.eq) goto loc_8206122C;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x8206122c
	if (!ctx.cr6.eq) goto loc_8206122C;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lwz r27,44(r10)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
loc_8206122C:
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,16(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r10,540
	ctx.r4.s64 = ctx.r10.s64 + 540;
	// clrlwi r30,r7,16
	ctx.r30.u64 = ctx.r7.u32 & 0xFFFF;
	// lwzx r3,r6,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// bl 0x82067230
	ctx.lr = 0x82061258;
	sub_82067230(ctx, base);
	// addi r5,r30,5
	ctx.r5.s64 = ctx.r30.s64 + 5;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// addi r3,r30,1
	ctx.r3.s64 = ctx.r30.s64 + 1;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// rotlwi r4,r19,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r19.u32, 0);
	// clrlwi r29,r3,16
	ctx.r29.u64 = ctx.r3.u32 & 0xFFFF;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x820670f8
	ctx.lr = 0x8206127C;
	sub_820670F8(ctx, base);
	// b 0x820612cc
	goto loc_820612CC;
loc_82061280:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x820612cc
	if (!ctx.cr6.gt) goto loc_820612CC;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
loc_8206128C:
	// clrlwi r11,r29,16
	ctx.r11.u64 = ctx.r29.u32 & 0xFFFF;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// clrlwi r29,r8,16
	ctx.r29.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r6,r7,r10
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// stw r31,24(r6)
	REX_STORE_U32(ctx.r6.u32 + 24, ctx.r31.u32);
	// stw r17,28(r6)
	REX_STORE_U32(ctx.r6.u32 + 28, ctx.r17.u32);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwzx r3,r7,r3
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// bl 0x82067230
	ctx.lr = 0x820612C4;
	sub_82067230(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8206128c
	if (!ctx.cr0.eq) goto loc_8206128C;
loc_820612CC:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r28,r28,48
	ctx.r28.s64 = ctx.r28.s64 + 48;
	// cmplw cr6,r26,r24
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r24.u32, ctx.xer);
	// blt cr6,0x820610f4
	if (ctx.cr6.lt) goto loc_820610F4;
loc_820612DC:
	// sth r15,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r15.u16);
	// sth r17,46(r31)
	REX_STORE_U16(ctx.r31.u32 + 46, ctx.r17.u16);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
loc_820612EC:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,4
	ctx.r9.s64 = 4;
	// sth r10,46(r31)
	REX_STORE_U16(ctx.r31.u32 + 46, ctx.r10.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// sth r9,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r9.u16);
	// beq cr6,0x82061358
	if (ctx.cr6.eq) goto loc_82061358;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82061358
	if (!ctx.cr6.eq) goto loc_82061358;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82061358
	if (ctx.cr6.eq) goto loc_82061358;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82061358
	if (ctx.cr6.eq) goto loc_82061358;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// bl 0x820670f8
	ctx.lr = 0x8206133C;
	sub_820670F8(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,507
	ctx.r4.s64 = 507;
	// lwz r3,36(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// bl 0x82067230
	ctx.lr = 0x82061350;
	sub_82067230(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
loc_82061358:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// bl 0x82067230
	ctx.lr = 0x8206136C;
	sub_82067230(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,36(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// bl 0x82067230
	ctx.lr = 0x82061380;
	sub_82067230(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
loc_82061388:
	// lhz r11,46(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 46);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82061418
	if (ctx.cr6.eq) goto loc_82061418;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x820613fc
	if (ctx.cr6.eq) goto loc_820613FC;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bne cr6,0x82061440
	if (!ctx.cr6.eq) goto loc_82061440;
	// lhz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820613cc
	if (!ctx.cr6.eq) goto loc_820613CC;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r4,500
	ctx.r4.s64 = 500;
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x820613C4;
	sub_82067230(ctx, base);
	// li r4,501
	ctx.r4.s64 = 501;
	// b 0x82061430
	goto loc_82061430;
loc_820613CC:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// bne cr6,0x820613ec
	if (!ctx.cr6.eq) goto loc_820613EC;
	// li r4,502
	ctx.r4.s64 = 502;
	// bl 0x82067230
	ctx.lr = 0x820613E4;
	sub_82067230(ctx, base);
	// li r4,503
	ctx.r4.s64 = 503;
	// b 0x82061430
	goto loc_82061430;
loc_820613EC:
	// li r4,504
	ctx.r4.s64 = 504;
	// bl 0x82067230
	ctx.lr = 0x820613F4;
	sub_82067230(ctx, base);
	// li r4,505
	ctx.r4.s64 = 505;
	// b 0x82061430
	goto loc_82061430;
loc_820613FC:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,480
	ctx.r4.s64 = 480;
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x82061410;
	sub_82067230(ctx, base);
	// li r4,481
	ctx.r4.s64 = 481;
	// b 0x82061430
	goto loc_82061430;
loc_82061418:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// bl 0x82067230
	ctx.lr = 0x8206142C;
	sub_82067230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
loc_82061430:
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,28(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// bl 0x82067230
	ctx.lr = 0x82061440;
	sub_82067230(ctx, base);
loc_82061440:
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// li r17,0
	ctx.r17.s64 = 0;
	// li r11,300
	ctx.r11.s64 = 300;
	// sth r17,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r17.u16);
	// sth r17,46(r31)
	REX_STORE_U16(ctx.r31.u32 + 46, ctx.r17.u16);
	// stw r11,792(r10)
	REX_STORE_U32(ctx.r10.u32 + 792, ctx.r11.u32);
loc_82061458:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
}
