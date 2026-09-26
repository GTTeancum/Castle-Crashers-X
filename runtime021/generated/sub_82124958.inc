DEFINE_REX_FUNC(sub_82124958) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x82124960;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// bl 0x82124718
	ctx.lr = 0x82124978;
	sub_82124718(ctx, base);
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x82124b48
	goto loc_82124B48;
loc_82124980:
	// oris r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 268435456;
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// bl 0x82125628
	ctx.lr = 0x82124990;
	sub_82125628(ctx, base);
	// stw r3,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r3.u32);
	// lbz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 16);
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// lbz r11,21(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 21);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// addi r30,r3,4
	ctx.r30.s64 = ctx.r3.s64 + 4;
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r27,r11,r3
	ctx.r27.u64 = ctx.r3.u64 - ctx.r11.u64;
	// beq 0x821249f4
	if (ctx.cr0.eq) goto loc_821249F4;
	// subf r11,r27,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r27.u64;
	// ld r10,816(r27)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r27.u32 + 816);
	// li r9,24
	ctx.r9.s64 = 24;
	// addi r11,r11,-48
	ctx.r11.s64 = ctx.r11.s64 + -48;
	// li r28,2
	ctx.r28.s64 = 2;
	// divw r11,r11,r9
	ctx.r11.u64 = uint32_t((ctx.r9.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r11.s32 / ctx.r9.s32 : 0);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// std r11,72(r31)
	REX_STORE_U64(ctx.r31.u32 + 72, ctx.r11.u64);
	// lbz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821249f4
	if (ctx.cr0.eq) goto loc_821249F4;
	// lhz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 80);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,80(r31)
	REX_STORE_U16(ctx.r31.u32 + 80, ctx.r11.u16);
loc_821249F4:
	// lbz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 12);
	// rlwinm. r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82124a18
	if (ctx.cr0.eq) goto loc_82124A18;
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ori r28,r28,1
	ctx.r28.u64 = ctx.r28.u64 | 1;
	// bne 0x82124a18
	if (!ctx.cr0.eq) goto loc_82124A18;
	// lhz r11,82(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 82);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,82(r31)
	REX_STORE_U16(ctx.r31.u32 + 82, ctx.r11.u16);
loc_82124A18:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82124a28
	if (ctx.cr6.eq) goto loc_82124A28;
	// ori r28,r28,4
	ctx.r28.u64 = ctx.r28.u64 | 4;
loc_82124A28:
	// lbz r11,13(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 13);
	// cmplwi cr6,r11,128
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 128, ctx.xer);
	// bne cr6,0x82124aa0
	if (!ctx.cr6.eq) goto loc_82124AA0;
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lhz r29,8(r30)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82124ba8
	if (ctx.cr6.eq) goto loc_82124BA8;
	// lbz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 12);
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82124ba8
	if (ctx.cr0.eq) goto loc_82124BA8;
	// lwz r10,88(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82124a74
	if (ctx.cr6.eq) goto loc_82124A74;
	// lwz r9,92(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x82129a70
	ctx.lr = 0x82124A74;
	sub_82129A70(ctx, base);
loc_82124A74:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// subf. r11,r29,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// bne 0x82124b20
	if (!ctx.cr0.eq) goto loc_82124B20;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82124b20
	if (ctx.cr6.eq) goto loc_82124B20;
	// lwz r6,92(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// ori r7,r28,8
	ctx.r7.u64 = ctx.r28.u64 | 8;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// b 0x82124bc4
	goto loc_82124BC4;
loc_82124AA0:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82124bd4
	if (ctx.cr6.eq) goto loc_82124BD4;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x82124bf4
	if (ctx.cr6.eq) goto loc_82124BF4;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82124c30
	if (!ctx.cr6.eq) goto loc_82124C30;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lhz r5,8(r30)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82125e38
	ctx.lr = 0x82124AC8;
	sub_82125E38(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,6
	ctx.r3.s64 = 6;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lhz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r30,r11,-4
	ctx.r30.s64 = ctx.r11.s64 + -4;
	// stw r4,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r4.u32);
	// stw r4,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r4.u32);
	// bl 0x82108f48
	ctx.lr = 0x82124AF8;
	sub_82108F48(ctx, base);
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82124b14
	if (ctx.cr0.eq) goto loc_82124B14;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// bl 0x82129a70
	ctx.lr = 0x82124B14;
	sub_82129A70(ctx, base);
loc_82124B14:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
loc_82124B20:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x821210b0
	ctx.lr = 0x82124B2C;
	sub_821210B0(ctx, base);
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// rlwinm r11,r11,0,4,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r25,4(r26)
	REX_STORE_U32(ctx.r26.u32 + 4, ctx.r25.u32);
	// bl 0x82124718
	ctx.lr = 0x82124B48;
	sub_82124718(ctx, base);
loc_82124B48:
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// cmpldi cr6,r3,0
	ctx.cr6.compare<uint64_t>(ctx.r3.u64, 0, ctx.xer);
	// bne cr6,0x82124980
	if (!ctx.cr6.eq) goto loc_82124980;
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82124b68
	if (!ctx.cr0.eq) goto loc_82124B68;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
loc_82124B60:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
loc_82124B68:
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x82125908
	ctx.lr = 0x82124B74;
	sub_82125908(ctx, base);
	// addi r3,r31,60
	ctx.r3.s64 = ctx.r31.s64 + 60;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x82125908
	ctx.lr = 0x82124B80;
	sub_82125908(ctx, base);
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// stw r25,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r25.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// oris r11,r11,20480
	ctx.r11.u64 = ctx.r11.u64 | 1342177280;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82124500
	ctx.lr = 0x82124BA4;
	sub_82124500(ctx, base);
	// b 0x82124c28
	goto loc_82124C28;
loc_82124BA8:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82124bb8
	if (ctx.cr6.eq) goto loc_82124BB8;
	// lwz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x82124bbc
	goto loc_82124BBC;
loc_82124BB8:
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
loc_82124BBC:
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
loc_82124BC4:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82124820
	ctx.lr = 0x82124BD0;
	sub_82124820(ctx, base);
	// b 0x82124c28
	goto loc_82124C28;
loc_82124BD4:
	// lhz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r6,r11,-9
	ctx.r6.s64 = ctx.r11.s64 + -9;
	// addi r5,r10,9
	ctx.r5.s64 = ctx.r10.s64 + 9;
	// bl 0x821244a8
	ctx.lr = 0x82124BF0;
	sub_821244A8(ctx, base);
	// b 0x82124c28
	goto loc_82124C28;
loc_82124BF4:
	// lhz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// addic. r6,r11,-6
	ctx.xer.ca = ctx.r11.u32 > 5;
	ctx.r6.s64 = ctx.r11.s64 + -6;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq 0x82124c0c
	if (ctx.cr0.eq) goto loc_82124C0C;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r5,r11,6
	ctx.r5.s64 = ctx.r11.s64 + 6;
	// b 0x82124c10
	goto loc_82124C10;
loc_82124C0C:
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
loc_82124C10:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82124500
	ctx.lr = 0x82124C1C;
	sub_82124500(ctx, base);
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
loc_82124C28:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82124b60
	goto loc_82124B60;
loc_82124C30:
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// rlwinm r11,r11,0,4,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
}
