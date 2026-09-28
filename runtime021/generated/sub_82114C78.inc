DEFINE_REX_FUNC(sub_82114C78) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82114C80;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// stw r28,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// bl 0x8210c7e8
	ctx.lr = 0x82114CA4;
	sub_8210C7E8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82114de8
	if (ctx.cr0.lt) goto loc_82114DE8;
	// addi r3,r30,104
	ctx.r3.s64 = ctx.r30.s64 + 104;
	// bl 0x8214a434
	ctx.lr = 0x82114CB4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r27,1
	ctx.r27.s64 = 1;
	// b 0x82114db0
	goto loc_82114DB0;
loc_82114CBC:
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82114e04
	if (ctx.cr6.eq) goto loc_82114E04;
	// lwz r11,820(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 820);
	// rlwinm r11,r11,0,6,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFBFFFFFF;
	// stw r11,820(r30)
	REX_STORE_U32(ctx.r30.u32 + 820, ctx.r11.u32);
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-20680
	ctx.r12.s64 = ctx.r12.s64 + -20680;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32239
	ctx.r12.s64 = -2112815104;
	// addi r12,r12,19716
	ctx.r12.s64 = ctx.r12.s64 + 19716;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82114D04;
	case 1:
		goto loc_82114D18;
	case 2:
		goto loc_82114D28;
	case 3:
		goto loc_82114D38;
	case 4:
		goto loc_82114D48;
	case 5:
		goto loc_82114D58;
	case 6:
		goto loc_82114D68;
	case 7:
		goto loc_82114D74;
	case 8:
		goto loc_82114D80;
	case 9:
		goto loc_82114D04;
	case 10:
		goto loc_82114D04;
	case 11:
		goto loc_82114D04;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82114D04:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821148c0
	ctx.lr = 0x82114D10;
	sub_821148C0(ctx, base);
loc_82114D10:
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82114d8c
	goto loc_82114D8C;
loc_82114D18:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210ce28
	ctx.lr = 0x82114D24;
	sub_8210CE28(ctx, base);
	// b 0x82114d10
	goto loc_82114D10;
loc_82114D28:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210cf10
	ctx.lr = 0x82114D34;
	sub_8210CF10(ctx, base);
	// b 0x82114d10
	goto loc_82114D10;
loc_82114D38:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210cfc8
	ctx.lr = 0x82114D44;
	sub_8210CFC8(ctx, base);
	// b 0x82114d10
	goto loc_82114D10;
loc_82114D48:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82111c50
	ctx.lr = 0x82114D54;
	sub_82111C50(ctx, base);
	// b 0x82114d10
	goto loc_82114D10;
loc_82114D58:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82111d58
	ctx.lr = 0x82114D64;
	sub_82111D58(ctx, base);
	// b 0x82114d10
	goto loc_82114D10;
loc_82114D68:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82114bc0
	ctx.lr = 0x82114D70;
	sub_82114BC0(ctx, base);
	// b 0x82114d10
	goto loc_82114D10;
loc_82114D74:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821141e8
	ctx.lr = 0x82114D7C;
	sub_821141E8(ctx, base);
	// b 0x82114d10
	goto loc_82114D10;
loc_82114D80:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x821151c8
	ctx.lr = 0x82114D88;
	sub_821151C8(ctx, base);
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
loc_82114D8C:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// blt cr6,0x82114e04
	if (ctx.cr6.lt) goto loc_82114E04;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82114e18
	if (!ctx.cr6.eq) goto loc_82114E18;
	// lwz r11,820(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 820);
	// rlwinm. r11,r11,0,5,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82114dd0
	if (ctx.cr0.eq) goto loc_82114DD0;
loc_82114DB0:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821113a8
	ctx.lr = 0x82114DBC;
	sub_821113A8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82114de8
	if (ctx.cr0.lt) goto loc_82114DE8;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82114e04
	if (!ctx.cr6.eq) goto loc_82114E04;
loc_82114DD0:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,164(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 164);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82115198
	ctx.lr = 0x82114DE0;
	sub_82115198(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x82114cbc
	if (!ctx.cr0.lt) goto loc_82114CBC;
loc_82114DE8:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82114dfc
	if (ctx.cr6.eq) goto loc_82114DFC;
	// bl 0x821151c8
	ctx.lr = 0x82114DF8;
	sub_821151C8(ctx, base);
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
loc_82114DFC:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x82114e0c
	if (ctx.cr6.eq) goto loc_82114E0C;
loc_82114E04:
	// addi r3,r30,104
	ctx.r3.s64 = ctx.r30.s64 + 104;
	// bl 0x8214a444
	ctx.lr = 0x82114E0C;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82114E0C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
loc_82114E18:
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// b 0x82114e04
	goto loc_82114E04;
}
