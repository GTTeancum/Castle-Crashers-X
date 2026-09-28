DEFINE_REX_FUNC(sub_820E8E68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f0
	ctx.lr = 0x820E8E70;
	__savegprlr_18(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r20,0
	ctx.r20.s64 = 0;
	// li r25,1
	ctx.r25.s64 = 1;
	// mr r24,r20
	ctx.r24.u64 = ctx.r20.u64;
	// lbz r11,56(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e8ed8
	if (ctx.cr6.eq) goto loc_820E8ED8;
	// mr r31,r20
	ctx.r31.u64 = ctx.r20.u64;
loc_820E8E94:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820da690
	ctx.lr = 0x820E8EA0;
	sub_820DA690(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820e8f3c
	if (ctx.cr6.eq) goto loc_820E8F3C;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820da6f8
	ctx.lr = 0x820E8EB4;
	sub_820DA6F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820e8ec0
	if (!ctx.cr6.eq) goto loc_820E8EC0;
	// mr r25,r20
	ctx.r25.u64 = ctx.r20.u64;
loc_820E8EC0:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// lbz r10,56(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820e8e94
	if (ctx.cr6.lt) goto loc_820E8E94;
loc_820E8ED8:
	// bl 0x8214abc4
	ctx.lr = 0x820E8EDC;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r21,r11,22852
	ctx.r21.s64 = ctx.r11.s64 + 22852;
	// mr r31,r13
	ctx.r31.u64 = ctx.r13.u64;
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e8f04
	if (ctx.cr6.eq) goto loc_820E8F04;
	// lwz r10,8(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 8);
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820e8f18
	if (ctx.cr6.eq) goto loc_820E8F18;
loc_820E8F04:
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820E8F0C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// stw r31,8(r21)
	REX_STORE_U32(ctx.r21.u32 + 8, ctx.r31.u32);
	// stb r30,12(r21)
	REX_STORE_U8(ctx.r21.u32 + 12, ctx.r30.u8);
loc_820E8F18:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r19,r29,20
	ctx.r19.s64 = ctx.r29.s64 + 20;
	// stw r11,4(r21)
	REX_STORE_U32(ctx.r21.u32 + 4, ctx.r11.u32);
	// lwz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r19,r11
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820e8f48
	if (ctx.cr6.eq) goto loc_820E8F48;
	// lwz r10,8(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 8);
	// subf r30,r10,r11
	ctx.r30.u64 = ctx.r11.u64 - ctx.r10.u64;
	// b 0x820e8f4c
	goto loc_820E8F4C;
loc_820E8F3C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
loc_820E8F48:
	// mr r30,r20
	ctx.r30.u64 = ctx.r20.u64;
loc_820E8F4C:
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// li r18,4
	ctx.r18.s64 = 4;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820e92c4
	if (ctx.cr6.eq) goto loc_820E92C4;
	// lwz r11,272(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e905c
	if (ctx.cr6.eq) goto loc_820E905C;
	// lwz r10,168(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 168);
	// lwz r9,268(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 268);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x820e905c
	if (ctx.cr6.lt) goto loc_820E905C;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x820e8f88
	if (!ctx.cr6.eq) goto loc_820E8F88;
	// li r11,-1
	ctx.r11.s64 = -1;
	// b 0x820e8f90
	goto loc_820E8F90;
loc_820E8F88:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,272(r29)
	REX_STORE_U32(ctx.r29.u32 + 272, ctx.r11.u32);
loc_820E8F90:
	// stw r11,272(r29)
	REX_STORE_U32(ctx.r29.u32 + 272, ctx.r11.u32);
	// addi r31,r29,296
	ctx.r31.s64 = ctx.r29.s64 + 296;
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// lwz r8,20(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r7,268(r29)
	REX_STORE_U32(ctx.r29.u32 + 268, ctx.r7.u32);
	// lwz r11,300(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 300);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e8ff0
	if (ctx.cr6.eq) goto loc_820E8FF0;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820e8ff0
	if (!ctx.cr6.eq) goto loc_820E8FF0;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bne 0x820e8ff0
	if (!ctx.cr0.eq) goto loc_820E8FF0;
	// lbz r28,12(r31)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r20,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r20.u8);
	// stw r20,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r20.u32);
	// bl 0x8214a794
	ctx.lr = 0x820E8FE8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820E8FF0;
	__imp__KfLowerIrql(ctx, base);
loc_820E8FF0:
	// lwz r11,180(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 180);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e901c
	if (ctx.cr6.eq) goto loc_820E901C;
	// lwz r10,12(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r9,36(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// stw r20,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r20.u32);
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820E901C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820E901C:
	// bl 0x8214abc4
	ctx.lr = 0x820E9020;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r13
	ctx.r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e9040
	if (ctx.cr6.eq) goto loc_820E9040;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820e9050
	if (ctx.cr6.eq) goto loc_820E9050;
loc_820E9040:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820E9048;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// stb r28,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r28.u8);
loc_820E9050:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_820E905C:
	// lwz r11,288(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 288);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e90ac
	if (ctx.cr6.eq) goto loc_820E90AC;
	// lbz r11,198(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 198);
	// lbz r10,56(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// stw r20,288(r29)
	REX_STORE_U32(ctx.r29.u32 + 288, ctx.r20.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,272(r29)
	REX_STORE_U32(ctx.r29.u32 + 272, ctx.r11.u32);
	// beq cr6,0x820e90ac
	if (ctx.cr6.eq) goto loc_820E90AC;
	// addi r30,r29,188
	ctx.r30.s64 = ctx.r29.s64 + 188;
	// mr r31,r20
	ctx.r31.u64 = ctx.r20.u64;
loc_820E9088:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820dac00
	ctx.lr = 0x820E9098;
	sub_820DAC00(ctx, base);
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// lbz r10,56(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// clrlwi r31,r11,24
	ctx.r31.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820e9088
	if (ctx.cr6.lt) goto loc_820E9088;
loc_820E90AC:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x820e92c4
	if (ctx.cr6.eq) goto loc_820E92C4;
	// lwz r11,8(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 8);
	// lwzx r10,r11,r27
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// cmplw cr6,r19,r10
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r10.u32, ctx.xer);
	// subf r26,r11,r10
	ctx.r26.u64 = ctx.r10.u64 - ctx.r11.u64;
	// bne cr6,0x820e90d0
	if (!ctx.cr6.eq) goto loc_820E90D0;
	// mr r26,r20
	ctx.r26.u64 = ctx.r20.u64;
loc_820E90D0:
	// lbz r11,116(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 116);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e9150
	if (ctx.cr6.eq) goto loc_820E9150;
	// lbz r11,56(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// mr r30,r20
	ctx.r30.u64 = ctx.r20.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e913c
	if (ctx.cr6.eq) goto loc_820E913C;
	// mr r31,r20
	ctx.r31.u64 = ctx.r20.u64;
loc_820E90F0:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r5,8(r27)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820da610
	ctx.lr = 0x820E9100;
	sub_820DA610(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820e9120
	if (ctx.cr6.eq) goto loc_820E9120;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820dab80
	ctx.lr = 0x820E9114;
	sub_820DAB80(ctx, base);
	// rlwinm r11,r3,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e9138
	if (ctx.cr6.eq) goto loc_820E9138;
loc_820E9120:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// lbz r10,56(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// clrlwi r31,r11,24
	ctx.r31.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820e90f0
	if (ctx.cr6.lt) goto loc_820E90F0;
	// b 0x820e913c
	goto loc_820E913C;
loc_820E9138:
	// li r30,1
	ctx.r30.s64 = 1;
loc_820E913C:
	// clrlwi r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820e9154
	if (!ctx.cr6.eq) goto loc_820E9154;
	// stb r18,116(r27)
	REX_STORE_U8(ctx.r27.u32 + 116, ctx.r18.u8);
	// b 0x820e9154
	goto loc_820E9154;
loc_820E9150:
	// li r24,1
	ctx.r24.s64 = 1;
loc_820E9154:
	// lbz r11,116(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 116);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x820e92b8
	if (!ctx.cr6.eq) goto loc_820E92B8;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x820e9184
	if (!ctx.cr6.eq) goto loc_820E9184;
	// lbz r11,172(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 172);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820e9184
	if (ctx.cr6.eq) goto loc_820E9184;
	// rlwinm r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e92b8
	if (ctx.cr6.eq) goto loc_820E92B8;
loc_820E9184:
	// lwz r10,4(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// mr r11,r13
	ctx.r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820e91d4
	if (ctx.cr6.eq) goto loc_820E91D4;
	// lwz r10,8(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820e91d4
	if (!ctx.cr6.eq) goto loc_820E91D4;
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r21)
	REX_STORE_U32(ctx.r21.u32 + 4, ctx.r11.u32);
	// bne 0x820e91d4
	if (!ctx.cr0.eq) goto loc_820E91D4;
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
	// lbz r31,12(r21)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r21.u32 + 12);
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
	// stb r11,12(r21)
	REX_STORE_U8(ctx.r21.u32 + 12, ctx.r11.u8);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// stw r10,8(r21)
	REX_STORE_U32(ctx.r21.u32 + 8, ctx.r10.u32);
	// bl 0x8214a794
	ctx.lr = 0x820E91CC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820E91D4;
	__imp__KfLowerIrql(ctx, base);
loc_820E91D4:
	// lwz r11,300(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 300);
	// addi r31,r29,296
	ctx.r31.s64 = ctx.r29.s64 + 296;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e921c
	if (ctx.cr6.eq) goto loc_820E921C;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820e921c
	if (!ctx.cr6.eq) goto loc_820E921C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bne 0x820e921c
	if (!ctx.cr0.eq) goto loc_820E921C;
	// lbz r30,12(r31)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r20,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r20.u8);
	// stw r20,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r20.u32);
	// bl 0x8214a794
	ctx.lr = 0x820E9214;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820E921C;
	__imp__KfLowerIrql(ctx, base);
loc_820E921C:
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// addi r3,r29,16
	ctx.r3.s64 = ctx.r29.s64 + 16;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820E9238;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8214abc4
	ctx.lr = 0x820E923C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r13
	ctx.r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820e925c
	if (ctx.cr6.eq) goto loc_820E925C;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820e926c
	if (ctx.cr6.eq) goto loc_820E926C;
loc_820E925C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820E9264;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// stb r28,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r28.u8);
loc_820E926C:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x8214abc4
	ctx.lr = 0x820E927C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r13
	ctx.r31.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e929c
	if (ctx.cr6.eq) goto loc_820E929C;
	// lwz r10,8(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 8);
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820e92b0
	if (ctx.cr6.eq) goto loc_820E92B0;
loc_820E929C:
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820E92A4;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// stw r31,8(r21)
	REX_STORE_U32(ctx.r21.u32 + 8, ctx.r31.u32);
	// stb r30,12(r21)
	REX_STORE_U8(ctx.r21.u32 + 12, ctx.r30.u8);
loc_820E92B0:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,4(r21)
	REX_STORE_U32(ctx.r21.u32 + 4, ctx.r11.u32);
loc_820E92B8:
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x820e90ac
	if (!ctx.cr6.eq) goto loc_820E90AC;
loc_820E92C4:
	// lbz r11,292(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 292);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820e92e0
	if (!ctx.cr6.eq) goto loc_820E92E0;
	// clrlwi r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820e92e0
	if (!ctx.cr6.eq) goto loc_820E92E0;
	// mr r24,r20
	ctx.r24.u64 = ctx.r20.u64;
loc_820E92E0:
	// lwz r10,4(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// mr r11,r13
	ctx.r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820e9330
	if (ctx.cr6.eq) goto loc_820E9330;
	// lwz r10,8(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820e9330
	if (!ctx.cr6.eq) goto loc_820E9330;
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r21)
	REX_STORE_U32(ctx.r21.u32 + 4, ctx.r11.u32);
	// bne 0x820e9330
	if (!ctx.cr0.eq) goto loc_820E9330;
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
	// lbz r31,12(r21)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r21.u32 + 12);
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
	// stb r11,12(r21)
	REX_STORE_U8(ctx.r21.u32 + 12, ctx.r11.u8);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// stw r10,8(r21)
	REX_STORE_U32(ctx.r21.u32 + 8, ctx.r10.u32);
	// bl 0x8214a794
	ctx.lr = 0x820E9328;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820E9330;
	__imp__KfLowerIrql(ctx, base);
loc_820E9330:
	// clrlwi r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e9698
	if (ctx.cr6.eq) goto loc_820E9698;
	// bl 0x8214abc4
	ctx.lr = 0x820E9340;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r13
	ctx.r31.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820e9360
	if (ctx.cr6.eq) goto loc_820E9360;
	// lwz r9,8(r21)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r21.u32 + 8);
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x820e9378
	if (ctx.cr6.eq) goto loc_820E9378;
loc_820E9360:
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x8214a7a4
	ctx.lr = 0x820E9368;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// stb r30,12(r21)
	REX_STORE_U8(ctx.r21.u32 + 12, ctx.r30.u8);
	// stw r9,8(r21)
	REX_STORE_U32(ctx.r21.u32 + 8, ctx.r9.u32);
loc_820E9378:
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r10,4(r21)
	REX_STORE_U32(ctx.r21.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// cmplw cr6,r19,r11
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820e9398
	if (ctx.cr6.eq) goto loc_820E9398;
	// lwz r8,8(r19)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r19.u32 + 8);
	// subf r31,r8,r11
	ctx.r31.u64 = ctx.r11.u64 - ctx.r8.u64;
	// b 0x820e939c
	goto loc_820E939C;
loc_820E9398:
	// mr r31,r20
	ctx.r31.u64 = ctx.r20.u64;
loc_820E939C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820e9654
	if (ctx.cr6.eq) goto loc_820E9654;
	// li r22,3
	ctx.r22.s64 = 3;
loc_820E93A8:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x820e964c
	if (ctx.cr6.eq) goto loc_820E964C;
	// lwz r11,8(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 8);
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmplw cr6,r19,r10
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r10.u32, ctx.xer);
	// subf r23,r11,r10
	ctx.r23.u64 = ctx.r10.u64 - ctx.r11.u64;
	// bne cr6,0x820e93cc
	if (!ctx.cr6.eq) goto loc_820E93CC;
	// mr r23,r20
	ctx.r23.u64 = ctx.r20.u64;
loc_820E93CC:
	// lbz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 116);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820e9640
	if (!ctx.cr6.eq) goto loc_820E9640;
	// lbz r11,56(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// li r24,1
	ctx.r24.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e9630
	if (ctx.cr6.eq) goto loc_820E9630;
	// mr r30,r20
	ctx.r30.u64 = ctx.r20.u64;
loc_820E93EC:
	// lbz r11,292(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 292);
	// mr r28,r20
	ctx.r28.u64 = ctx.r20.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820e9404
	if (!ctx.cr6.eq) goto loc_820E9404;
	// li r28,1
	ctx.r28.s64 = 1;
	// b 0x820e941c
	goto loc_820E941C;
loc_820E9404:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820e941c
	if (ctx.cr6.eq) goto loc_820E941C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820da6f8
	ctx.lr = 0x820E9418;
	sub_820DA6F8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_820E941C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r6,12(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r5,8(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820da538
	ctx.lr = 0x820E9430;
	sub_820DA538(ctx, base);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x820e9484
	if (ctx.cr6.eq) goto loc_820E9484;
	// lbz r11,292(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 292);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820e946c
	if (!ctx.cr6.eq) goto loc_820E946C;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,28(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820e7de8
	ctx.lr = 0x820E945C;
	sub_820E7DE8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// rlwinm r6,r11,25,30,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x3;
	// b 0x820e9478
	goto loc_820E9478;
loc_820E946C:
	// rlwinm r11,r30,14,0,17
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 14) & 0xFFFFC000;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// addi r5,r11,32
	ctx.r5.s64 = ctx.r11.s64 + 32;
loc_820E9478:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820dad68
	ctx.lr = 0x820E9484;
	sub_820DAD68(ctx, base);
loc_820E9484:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e95d0
	if (ctx.cr6.eq) goto loc_820E95D0;
	// stw r20,188(r29)
	REX_STORE_U32(ctx.r29.u32 + 188, ctx.r20.u32);
	// addi r27,r29,188
	ctx.r27.s64 = ctx.r29.s64 + 188;
	// stw r20,192(r29)
	REX_STORE_U32(ctx.r29.u32 + 192, ctx.r20.u32);
	// stw r20,196(r29)
	REX_STORE_U32(ctx.r29.u32 + 196, ctx.r20.u32);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lbz r11,292(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 292);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// stb r10,198(r29)
	REX_STORE_U8(ctx.r29.u32 + 198, ctx.r10.u8);
	// bne cr6,0x820e9588
	if (!ctx.cr6.eq) goto loc_820E9588;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r26,r11,-128
	ctx.r26.s64 = ctx.r11.s64 + -128;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// bl 0x820e7de8
	ctx.lr = 0x820E94D4;
	sub_820E7DE8(ctx, base);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r6,20(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r20,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r20.u32);
	// bl 0x820e7de8
	ctx.lr = 0x820E94F4;
	sub_820E7DE8(ctx, base);
	// lwz r6,20(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r28,r6,25,30,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 25) & 0x3;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x820e9558
	if (!ctx.cr6.eq) goto loc_820E9558;
	// cmplwi cr6,r6,512
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 512, ctx.xer);
	// blt cr6,0x820e9538
	if (ctx.cr6.lt) goto loc_820E9538;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820e956c
	if (!ctx.cr6.eq) goto loc_820E956C;
	// addi r6,r6,-512
	ctx.r6.s64 = ctx.r6.s64 + -512;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x820e7de8
	ctx.lr = 0x820E9530;
	sub_820E7DE8(ctx, base);
	// mr r28,r18
	ctx.r28.u64 = ctx.r18.u64;
	// b 0x820e956c
	goto loc_820E956C;
loc_820E9538:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x820e7de8
	ctx.lr = 0x820E9550;
	sub_820E7DE8(ctx, base);
	// mr r28,r20
	ctx.r28.u64 = ctx.r20.u64;
	// b 0x820e956c
	goto loc_820E956C;
loc_820E9558:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820e7de8
	ctx.lr = 0x820E956C;
	sub_820E7DE8(ctx, base);
loc_820E956C:
	// rlwinm r11,r26,25,30,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 25) & 0x3;
	// stw r3,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// stw r25,192(r29)
	REX_STORE_U32(ctx.r29.u32 + 192, ctx.r25.u32);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// stb r11,196(r29)
	REX_STORE_U8(ctx.r29.u32 + 196, ctx.r11.u8);
	// stb r28,197(r29)
	REX_STORE_U8(ctx.r29.u32 + 197, ctx.r28.u8);
	// b 0x820e95ec
	goto loc_820E95EC;
loc_820E9588:
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
	// add r9,r30,r10
	ctx.r9.u64 = ctx.r30.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r11,r9,r31
	ctx.r11.u64 = ctx.r9.u64 + ctx.r31.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,40(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// stw r6,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r6.u32);
	// lwz r5,44(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// stw r5,192(r29)
	REX_STORE_U32(ctx.r29.u32 + 192, ctx.r5.u32);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lbzx r4,r7,r31
	ctx.r4.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r31.u32);
	// stb r4,196(r29)
	REX_STORE_U8(ctx.r29.u32 + 196, ctx.r4.u8);
	// lbz r3,49(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 49);
	// stb r3,197(r29)
	REX_STORE_U8(ctx.r29.u32 + 197, ctx.r3.u8);
	// b 0x820e95ec
	goto loc_820E95EC;
loc_820E95D0:
	// lbz r11,292(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 292);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820e95f8
	if (!ctx.cr6.eq) goto loc_820E95F8;
	// stw r20,188(r29)
	REX_STORE_U32(ctx.r29.u32 + 188, ctx.r20.u32);
	// addi r5,r29,188
	ctx.r5.s64 = ctx.r29.s64 + 188;
	// stw r20,192(r29)
	REX_STORE_U32(ctx.r29.u32 + 192, ctx.r20.u32);
	// stw r20,196(r29)
	REX_STORE_U32(ctx.r29.u32 + 196, ctx.r20.u32);
loc_820E95EC:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820dac00
	ctx.lr = 0x820E95F8;
	sub_820DAC00(ctx, base);
loc_820E95F8:
	// lbz r11,292(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 292);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x820e9618
	if (ctx.cr6.eq) goto loc_820E9618;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820da690
	ctx.lr = 0x820E9610;
	sub_820DA690(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820e961c
	if (!ctx.cr6.eq) goto loc_820E961C;
loc_820E9618:
	// mr r24,r20
	ctx.r24.u64 = ctx.r20.u64;
loc_820E961C:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lbz r10,56(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// clrlwi r30,r11,24
	ctx.r30.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820e93ec
	if (ctx.cr6.lt) goto loc_820E93EC;
loc_820E9630:
	// clrlwi r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	// stb r22,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r22.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e964c
	if (ctx.cr6.eq) goto loc_820E964C;
loc_820E9640:
	// mr r31,r23
	ctx.r31.u64 = ctx.r23.u64;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// bne cr6,0x820e93a8
	if (!ctx.cr6.eq) goto loc_820E93A8;
loc_820E964C:
	// lwz r9,8(r21)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r21.u32 + 8);
	// lwz r10,4(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
loc_820E9654:
	// mr r11,r13
	ctx.r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820e9698
	if (ctx.cr6.eq) goto loc_820E9698;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820e9698
	if (!ctx.cr6.eq) goto loc_820E9698;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r21)
	REX_STORE_U32(ctx.r21.u32 + 4, ctx.r11.u32);
	// bne 0x820e9698
	if (!ctx.cr0.eq) goto loc_820E9698;
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
	// lbz r31,12(r21)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r21.u32 + 12);
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
	// stb r11,12(r21)
	REX_STORE_U8(ctx.r21.u32 + 12, ctx.r11.u8);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// stw r10,8(r21)
	REX_STORE_U32(ctx.r21.u32 + 8, ctx.r10.u32);
	// bl 0x8214a794
	ctx.lr = 0x820E9690;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8214abd4
	ctx.lr = 0x820E9698;
	__imp__KfLowerIrql(ctx, base);
loc_820E9698:
	// lwz r11,120(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e96f4
	if (ctx.cr6.eq) goto loc_820E96F4;
	// lbz r11,56(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e96f0
	if (ctx.cr6.eq) goto loc_820E96F0;
	// mr r31,r20
	ctx.r31.u64 = ctx.r20.u64;
loc_820E96B4:
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// addi r10,r31,15
	ctx.r10.s64 = ctx.r31.s64 + 15;
	// add r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 + ctx.r29.u64;
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lhz r7,124(r9)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r9.u32 + 124);
	// lwzx r5,r8,r29
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r29.u32);
	// rlwinm r6,r7,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1FFFFFF;
	// bl 0x820dad68
	ctx.lr = 0x820E96DC;
	sub_820DAD68(ctx, base);
	// addi r6,r31,1
	ctx.r6.s64 = ctx.r31.s64 + 1;
	// lbz r5,56(r29)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// clrlwi r31,r6,24
	ctx.r31.u64 = ctx.r6.u32 & 0xFF;
	// cmplw cr6,r31,r5
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x820e96b4
	if (ctx.cr6.lt) goto loc_820E96B4;
loc_820E96F0:
	// stw r20,120(r29)
	REX_STORE_U32(ctx.r29.u32 + 120, ctx.r20.u32);
loc_820E96F4:
	// lbz r11,56(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e9744
	if (ctx.cr6.eq) goto loc_820E9744;
	// mr r31,r20
	ctx.r31.u64 = ctx.r20.u64;
loc_820E9704:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820da6f8
	ctx.lr = 0x820E9710;
	sub_820DA6F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820e9730
	if (!ctx.cr6.eq) goto loc_820E9730;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// bl 0x820dab80
	ctx.lr = 0x820E9724;
	sub_820DAB80(ctx, base);
	// rlwinm r11,r3,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820e8f3c
	if (ctx.cr6.eq) goto loc_820E8F3C;
loc_820E9730:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// lbz r10,56(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 56);
	// clrlwi r31,r11,24
	ctx.r31.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820e9704
	if (ctx.cr6.lt) goto loc_820E9704;
loc_820E9744:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
}
