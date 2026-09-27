DEFINE_REX_FUNC(sub_82079D50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298ec
	ctx.lr = 0x82079D58;
	__savegprlr_17(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r4
	ctx.r20.u64 = ctx.r4.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r3,10316(r20)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r20.u32 + 10316);
	// bl 0x8209d948
	ctx.lr = 0x82079D74;
	sub_8209D948(ctx, base);
	// sth r3,28(r30)
	REX_STORE_U16(ctx.r30.u32 + 28, ctx.r3.u16);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_82079D7C:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82079d7c
	if (!ctx.cr6.eq) goto loc_82079D7C;
	// subf r11,r24,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r24.u64;
	// li r23,0
	ctx.r23.s64 = 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// add r10,r11,r24
	ctx.r10.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r27,r11,2
	ctx.r27.s64 = ctx.r11.s64 + 2;
	// lbzx r9,r11,r24
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r24.u32);
	// lbz r8,1(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// rotlwi r7,r9,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// or r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 | ctx.r8.u64;
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// rlwinm r4,r5,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFF;
	// rlwimi r4,r5,8,16,23
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// extsh r21,r4
	ctx.r21.s64 = ctx.r4.s16;
	// sth r4,32(r30)
	REX_STORE_U16(ctx.r30.u32 + 32, ctx.r4.u16);
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// ble cr6,0x82079ee0
	if (!ctx.cr6.gt) goto loc_82079EE0;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// mr r28,r23
	ctx.r28.u64 = ctx.r23.u64;
	// lis r22,-32768
	ctx.r22.s64 = -2147483648;
	// lis r18,-32215
	ctx.r18.s64 = -2111242240;
	// addi r19,r11,29632
	ctx.r19.s64 = ctx.r11.s64 + 29632;
	// addi r17,r10,-1768
	ctx.r17.s64 = ctx.r10.s64 + -1768;
loc_82079DF0:
	// add r26,r27,r24
	ctx.r26.u64 = ctx.r27.u64 + ctx.r24.u64;
	// lwz r3,10316(r20)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r20.u32 + 10316);
	// stb r23,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r23.u8);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// stw r22,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r22.u32);
	// stw r23,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r23.u32);
	// bl 0x8209d948
	ctx.lr = 0x82079E0C;
	sub_8209D948(ctx, base);
	// addi r11,r28,6
	ctx.r11.s64 = ctx.r28.s64 + 6;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// rlwinm r29,r11,3,0,28
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r29,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82079e34
	if (ctx.cr6.eq) goto loc_82079E34;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8208bf38
	ctx.lr = 0x82079E30;
	sub_8208BF38(ctx, base);
	// b 0x82079ea4
	goto loc_82079EA4;
loc_82079E34:
	// lbz r11,-22601(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82079e54
	if (!ctx.cr6.eq) goto loc_82079E54;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x82079E54;
	sub_820A71E8(ctx, base);
loc_82079E54:
	// bl 0x820b5eb8
	ctx.lr = 0x82079E58;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,12
	ctx.r4.s64 = 12;
	// lwzx r3,r11,r19
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r19.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82079E68;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82079e80
	if (ctx.cr6.eq) goto loc_82079E80;
	// stw r23,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r23.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r22,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r22.u32);
	// b 0x82079e84
	goto loc_82079E84;
loc_82079E80:
	// mr r31,r23
	ctx.r31.u64 = ctx.r23.u64;
loc_82079E84:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8208bf38
	ctx.lr = 0x82079E94;
	sub_8208BF38(ctx, base);
	// rlwinm r11,r28,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 3) & 0xFFFFFFF8;
	// stwx r31,r29,r30
	REX_STORE_U32(ctx.r29.u32 + ctx.r30.u32, ctx.r31.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// sth r25,44(r11)
	REX_STORE_U16(ctx.r11.u32 + 44, ctx.r25.u16);
loc_82079EA4:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_82079EA8:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82079ea8
	if (!ctx.cr6.eq) goto loc_82079EA8;
	// subf r11,r26,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r26.u64;
	// addi r10,r28,1
	ctx.r10.s64 = ctx.r28.s64 + 1;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// cmpw cr6,r11,r21
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r21.s32, ctx.xer);
	// addi r27,r10,1
	ctx.r27.s64 = ctx.r10.s64 + 1;
	// blt cr6,0x82079df0
	if (ctx.cr6.lt) goto loc_82079DF0;
loc_82079EE0:
	// add r11,r27,r24
	ctx.r11.u64 = ctx.r27.u64 + ctx.r24.u64;
	// lbzx r10,r27,r24
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + ctx.r24.u32);
	// addi r3,r27,2
	ctx.r3.s64 = ctx.r27.s64 + 2;
	// rotlwi r9,r10,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r8,1(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// rlwinm r5,r6,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// rlwimi r5,r6,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// sth r5,30(r30)
	REX_STORE_U16(ctx.r30.u32 + 30, ctx.r5.u16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82079f28
	if (ctx.cr6.eq) goto loc_82079F28;
	// add r10,r3,r24
	ctx.r10.u64 = ctx.r3.u64 + ctx.r24.u64;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stw r10,36(r30)
	REX_STORE_U32(ctx.r30.u32 + 36, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
loc_82079F28:
	// stw r23,36(r30)
	REX_STORE_U32(ctx.r30.u32 + 36, ctx.r23.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8212993c
	__restgprlr_17(ctx, base);
	return;
}
