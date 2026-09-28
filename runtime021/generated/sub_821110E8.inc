DEFINE_REX_FUNC(sub_821110E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x821110F0;
	__savegprlr_22(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// addi r22,r28,104
	ctx.r22.s64 = ctx.r28.s64 + 104;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// bl 0x8214a434
	ctx.lr = 0x82111120;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8210e678
	ctx.lr = 0x8211112C;
	sub_8210E678(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82111148
	if (ctx.cr0.eq) goto loc_82111148;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82111148
	if (ctx.cr6.eq) goto loc_82111148;
	// lwz r3,68(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82111154
	if (!ctx.cr6.eq) goto loc_82111154;
loc_82111148:
	// lis r27,-32646
	ctx.r27.s64 = -2139488256;
	// ori r27,r27,4105
	ctx.r27.u64 = ctx.r27.u64 | 4105;
	// b 0x82111390
	goto loc_82111390;
loc_82111154:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lis r10,255
	ctx.r10.s64 = 16711680;
	// ori r24,r11,65534
	ctx.r24.u64 = ctx.r11.u64 | 65534;
	// ori r23,r10,65534
	ctx.r23.u64 = ctx.r10.u64 | 65534;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82111174
	if (!ctx.cr6.eq) goto loc_82111174;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82111230
	goto loc_82111230;
loc_82111174:
	// rlwinm r11,r30,7,25,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 7) & 0x7F;
	// rlwinm r10,r30,14,25,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 14) & 0x7F;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821111dc
	if (!ctx.cr6.eq) goto loc_821111DC;
	// subfic r11,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
	// clrlwi r10,r30,15
	ctx.r10.u64 = ctx.r30.u32 & 0x1FFFF;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// subf r10,r10,r24
	ctx.r10.u64 = ctx.r24.u64 - ctx.r10.u64;
	// bge cr6,0x821111fc
	if (!ctx.cr6.lt) goto loc_821111FC;
	// addi r9,r11,80
	ctx.r9.s64 = ctx.r11.s64 + 80;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r9,r28
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r28.u32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x821111fc
	if (!ctx.cr6.lt) goto loc_821111FC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821111b8
	if (!ctx.cr6.eq) goto loc_821111B8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_821111B8:
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x821111fc
	if (ctx.cr6.eq) goto loc_821111FC;
	// rlwinm. r9,r30,0,14,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x821111fc
	if (!ctx.cr0.eq) goto loc_821111FC;
	// subfic r11,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
	// subf r10,r10,r23
	ctx.r10.u64 = ctx.r23.u64 - ctx.r10.u64;
	// rlwinm r11,r11,24,0,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF000000;
	// or r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 | ctx.r10.u64;
	// b 0x82111230
	goto loc_82111230;
loc_821111DC:
	// lwz r9,172(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 172);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x821111fc
	if (!ctx.cr6.eq) goto loc_821111FC;
	// addi r11,r10,44
	ctx.r11.s64 = ctx.r10.s64 + 44;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82111208
	if (!ctx.cr6.eq) goto loc_82111208;
loc_821111FC:
	// lis r27,-32646
	ctx.r27.s64 = -2139488256;
	// ori r27,r27,4111
	ctx.r27.u64 = ctx.r27.u64 | 4111;
	// b 0x82111390
	goto loc_82111390;
loc_82111208:
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// clrlwi r9,r30,21
	ctx.r9.u64 = ctx.r30.u32 & 0x7FF;
	// lwz r10,168(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 168);
	// rlwinm r8,r30,13,1,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 13) & 0x7F000000;
	// subfc r11,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// or r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 | ctx.r9.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82111230
	if (!ctx.cr0.eq) goto loc_82111230;
	// oris r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 2147483648;
loc_82111230:
	// lwz r30,0(r26)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// lwz r10,308(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 308);
	// rlwinm r11,r30,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// add r29,r11,r31
	ctx.r29.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// bl 0x821153d0
	ctx.lr = 0x82111258;
	sub_821153D0(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq 0x82111270
	if (ctx.cr0.eq) goto loc_82111270;
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// ori r11,r11,4097
	ctx.r11.u64 = ctx.r11.u64 | 4097;
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x82111390
	if (!ctx.cr6.eq) goto loc_82111390;
loc_82111270:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x82111280
	if (!ctx.cr6.lt) goto loc_82111280;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_82111280:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82111390
	if (ctx.cr6.eq) goto loc_82111390;
loc_82111288:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,56
	ctx.r5.s64 = 56;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82129a70
	ctx.lr = 0x82111298;
	sub_82129A70(ctx, base);
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r26,132(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// clrlwi. r11,r26,31
	ctx.r11.u64 = ctx.r26.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821112ec
	if (ctx.cr0.eq) goto loc_821112EC;
	// lwz r8,88(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r11,r8,8
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFFFF;
	// subf r11,r11,r23
	ctx.r11.u64 = ctx.r23.u64 - ctx.r11.u64;
	// bne cr6,0x821112c4
	if (!ctx.cr6.eq) goto loc_821112C4;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_821112C4:
	// subfic r7,r10,127
	ctx.xer.ca = ctx.r10.u32 <= 127;
	ctx.r7.u64 = static_cast<uint64_t>(127) - ctx.r10.u64;
	// subfic r6,r10,-1
	ctx.xer.ca = ctx.r10.u32 <= 4294967295;
	ctx.r6.u64 = static_cast<uint64_t>(-1) - ctx.r10.u64;
	// rlwinm r7,r7,18,0,13
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 18) & 0xFFFC0000;
	// rlwinm r6,r6,25,0,6
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 25) & 0xFE000000;
	// subf r11,r11,r24
	ctx.r11.u64 = ctx.r24.u64 - ctx.r11.u64;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r8,r8,18,14,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 18) & 0x20000;
	// or r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 | ctx.r11.u64;
	// or r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 | ctx.r8.u64;
	// b 0x82111314
	goto loc_82111314;
loc_821112EC:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r8,60(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// clrlwi r7,r11,8
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFFFF;
	// lwz r6,172(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 172);
	// rlwinm r11,r11,19,14,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 19) & 0x3F800;
	// rlwinm r8,r8,25,0,6
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0xFE000000;
	// or r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 | ctx.r7.u64;
	// rlwinm r7,r6,18,0,13
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 18) & 0xFFFC0000;
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
	// or r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 | ctx.r11.u64;
loc_82111314:
	// lwz r8,136(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 136);
	// addi r3,r31,28
	ctx.r3.s64 = ctx.r31.s64 + 28;
	// lwz r7,92(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// lwz r8,132(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 132);
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lwz r8,60(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 60);
	// stw r8,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// lwz r9,72(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 72);
	// stw r9,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r7,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// bl 0x82129a70
	ctx.lr = 0x82111354;
	sub_82129A70(ctx, base);
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lwz r10,116(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// addi r29,r29,56
	ctx.r29.s64 = ctx.r29.s64 + 56;
	// lwz r9,120(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r8,124(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r7,128(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r10,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r9,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r9.u32);
	// stw r8,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r8.u32);
	// stw r7,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r7.u32);
	// stw r26,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r26.u32);
	// addi r31,r31,64
	ctx.r31.s64 = ctx.r31.s64 + 64;
	// bne 0x82111288
	if (!ctx.cr0.eq) goto loc_82111288;
loc_82111390:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8214a444
	ctx.lr = 0x82111398;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
