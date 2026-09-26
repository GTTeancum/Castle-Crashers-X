DEFINE_REX_FUNC(sub_820C3568) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e4
	ctx.lr = 0x820C3570;
	__savegprlr_15(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// addi r11,r11,5648
	ctx.r11.s64 = ctx.r11.s64 + 5648;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// lwz r10,32(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mr r19,r6
	ctx.r19.u64 = ctx.r6.u64;
	// clrlwi r22,r10,26
	ctx.r22.u64 = ctx.r10.u32 & 0x3F;
	// mr r18,r7
	ctx.r18.u64 = ctx.r7.u64;
	// rlwinm r10,r22,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r17,r8
	ctx.r17.u64 = ctx.r8.u64;
	// mr r16,r9
	ctx.r16.u64 = ctx.r9.u64;
	// lbzx r21,r10,r11
	ctx.r21.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// bl 0x820c7d48
	ctx.lr = 0x820C35B0;
	sub_820C7D48(ctx, base);
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// cmpwi cr6,r15,4
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 4, ctx.xer);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bne cr6,0x820c3620
	if (!ctx.cr6.eq) goto loc_820C3620;
	// bl 0x820c2d58
	ctx.lr = 0x820C35D0;
	sub_820C2D58(ctx, base);
	// lwz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// lwz r10,48(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// rlwinm r9,r11,10,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 10) & 0x1FF;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mullw r31,r9,r21
	ctx.r31.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r21.s32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// rlwinm r8,r10,23,30,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x3;
	// rlwinm r31,r31,2,3,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0x1FFFFFFC;
	// lwz r25,92(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r27,96(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r24,100(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stw r25,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r25.u32);
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// bl 0x820c2f80
	ctx.lr = 0x820C361C;
	sub_820C2F80(ctx, base);
	// b 0x820c38c8
	goto loc_820C38C8;
loc_820C3620:
	// lwz r11,40(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 40);
	// rlwinm r31,r11,1,31,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// rlwinm r8,r31,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x820c2d58
	ctx.lr = 0x820C3630;
	sub_820C2D58(ctx, base);
	// lwz r28,48(r29)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// li r5,1
	ctx.r5.s64 = 1;
	// rlwinm r26,r28,23,30,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 23) & 0x3;
	// cmplwi cr6,r26,2
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 2, ctx.xer);
	// lwz r25,92(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r27,96(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// subf r9,r8,r25
	ctx.r9.u64 = ctx.r25.u64 - ctx.r8.u64;
	// lwz r24,100(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// subf r7,r8,r27
	ctx.r7.u64 = ctx.r27.u64 - ctx.r8.u64;
	// addi r11,r9,-1
	ctx.r11.s64 = ctx.r9.s64 + -1;
	// addi r10,r7,-1
	ctx.r10.s64 = ctx.r7.s64 + -1;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subf r11,r11,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r11.u64;
	// subf r10,r10,r31
	ctx.r10.u64 = ctx.r31.u64 - ctx.r10.u64;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// slw r4,r5,r11
	ctx.r4.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r11.u8 & 0x3F));
	// slw r3,r5,r10
	ctx.r3.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r10.u8 & 0x3F));
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// bne cr6,0x820c36a4
	if (!ctx.cr6.eq) goto loc_820C36A4;
	// subf r11,r8,r24
	ctx.r11.u64 = ctx.r24.u64 - ctx.r8.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// subf r11,r11,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r11.u64;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// slw r30,r5,r11
	ctx.r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r11.u8 & 0x3F));
	// b 0x820c36a8
	goto loc_820C36A8;
loc_820C36A4:
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
loc_820C36A8:
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// bne cr6,0x820c3770
	if (!ctx.cr6.eq) goto loc_820C3770;
	// cmplwi cr6,r4,16
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 16, ctx.xer);
	// ble cr6,0x820c36c4
	if (!ctx.cr6.gt) goto loc_820C36C4;
	// cmplwi cr6,r3,16
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 16, ctx.xer);
	// bgt cr6,0x820c36cc
	if (ctx.cr6.gt) goto loc_820C36CC;
loc_820C36C4:
	// rlwinm. r11,r28,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820c36d8
	if (!ctx.cr0.eq) goto loc_820C36D8;
loc_820C36CC:
	// stw r25,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r25.u32);
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
loc_820C36D8:
	// lwz r30,28(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// rlwinm r22,r30,1,31,31
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0x1;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// bl 0x820c2f80
	ctx.lr = 0x820C3700;
	sub_820C2F80(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// bne cr6,0x820c3760
	if (!ctx.cr6.eq) goto loc_820C3760;
	// lwz r11,32(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// rlwinm. r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820c3760
	if (!ctx.cr0.eq) goto loc_820C3760;
	// rlwinm. r10,r28,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820c3760
	if (!ctx.cr0.eq) goto loc_820C3760;
	// cmplwi cr6,r26,1
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 1, ctx.xer);
	// bne cr6,0x820c3760
	if (!ctx.cr6.eq) goto loc_820C3760;
	// lwz r10,44(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 44);
	// rlwinm. r10,r10,0,22,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x3C0;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820c3760
	if (!ctx.cr0.eq) goto loc_820C3760;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x820c3760
	if (!ctx.cr6.eq) goto loc_820C3760;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// clrlwi r3,r11,26
	ctx.r3.u64 = ctx.r11.u32 & 0x3F;
	// bl 0x820c2e60
	ctx.lr = 0x820C3748;
	sub_820C2E60(ctx, base);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// andc r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ~ctx.r11.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_820C3760:
	// rlwinm r11,r30,10,23,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 10) & 0x1FF;
	// mullw r11,r11,r21
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r21.s32);
	// rlwinm r31,r11,2,3,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x1FFFFFFC;
	// b 0x820c38c8
	goto loc_820C38C8;
loc_820C3770:
	// srw r11,r9,r23
	ctx.r11.u64 = ctx.r23.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r23.u8 & 0x3F));
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bgt cr6,0x820c3788
	if (ctx.cr6.gt) goto loc_820C3788;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
loc_820C3788:
	// srw r10,r7,r23
	ctx.r10.u64 = ctx.r23.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r23.u8 & 0x3F));
	// add r25,r11,r8
	ctx.r25.u64 = ctx.r11.u64 + ctx.r8.u64;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bgt cr6,0x820c379c
	if (ctx.cr6.gt) goto loc_820C379C;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
loc_820C379C:
	// add r27,r10,r8
	ctx.r27.u64 = ctx.r10.u64 + ctx.r8.u64;
	// cmplwi cr6,r26,2
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 2, ctx.xer);
	// bne cr6,0x820c37c4
	if (!ctx.cr6.eq) goto loc_820C37C4;
	// subf r11,r8,r24
	ctx.r11.u64 = ctx.r24.u64 - ctx.r8.u64;
	// srw r11,r11,r23
	ctx.r11.u64 = ctx.r23.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r23.u8 & 0x3F));
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bgt cr6,0x820c37bc
	if (ctx.cr6.gt) goto loc_820C37BC;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
loc_820C37BC:
	// add r24,r11,r8
	ctx.r24.u64 = ctx.r11.u64 + ctx.r8.u64;
	// b 0x820c37c8
	goto loc_820C37C8;
loc_820C37C4:
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
loc_820C37C8:
	// rlwinm. r11,r28,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820c385c
	if (ctx.cr0.eq) goto loc_820C385C;
	// subf r10,r8,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r8.u64;
	// subf r11,r8,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r8.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cntlzw r7,r11
	ctx.r7.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// subf r11,r10,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r10.u64;
	// subf r10,r7,r31
	ctx.r10.u64 = ctx.r31.u64 - ctx.r7.u64;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x820c3804
	if (ctx.cr6.lt) goto loc_820C3804;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820C3804:
	// addic. r11,r11,-4
	ctx.xer.ca = ctx.r11.u32 > 3;
	ctx.r11.s64 = ctx.r11.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt 0x820c3810
	if (ctx.cr0.gt) goto loc_820C3810;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820C3810:
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820c385c
	if (ctx.cr6.lt) goto loc_820C385C;
	// subf r10,r8,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r8.u64;
	// subf r11,r8,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r8.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cntlzw r9,r11
	ctx.r9.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// subf r11,r10,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r10.u64;
	// subf r10,r9,r31
	ctx.r10.u64 = ctx.r31.u64 - ctx.r9.u64;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x820c384c
	if (ctx.cr6.lt) goto loc_820C384C;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_820C384C:
	// addic. r11,r11,-4
	ctx.xer.ca = ctx.r11.u32 > 3;
	ctx.r11.s64 = ctx.r11.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r23,r11
	ctx.r23.u64 = ctx.r11.u64;
	// bgt 0x820c385c
	if (ctx.cr0.gt) goto loc_820C385C;
	// li r23,0
	ctx.r23.s64 = 0;
loc_820C385C:
	// srw r11,r4,r23
	ctx.r11.u64 = ctx.r23.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r23.u8 & 0x3F));
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// bgt cr6,0x820c3870
	if (ctx.cr6.gt) goto loc_820C3870;
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
loc_820C3870:
	// srw r11,r3,r23
	ctx.r11.u64 = ctx.r23.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (ctx.r23.u8 & 0x3F));
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bgt cr6,0x820c3884
	if (ctx.cr6.gt) goto loc_820C3884;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
loc_820C3884:
	// srw r11,r30,r23
	ctx.r11.u64 = ctx.r23.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r23.u8 & 0x3F));
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bgt cr6,0x820c3898
	if (ctx.cr6.gt) goto loc_820C3898;
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
loc_820C3898:
	// lwz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// bl 0x820c2f80
	ctx.lr = 0x820C38BC;
	sub_820C2F80(ctx, base);
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mullw r11,r11,r21
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r21.s32);
	// rlwinm r31,r11,29,3,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
loc_820C38C8:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r25,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r25.u32);
	// stw r27,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r27.u32);
	// mullw r11,r31,r11
	ctx.r11.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r11.s32);
	// stw r24,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r24.u32);
	// stw r31,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r31.u32);
	// stw r11,0(r16)
	REX_STORE_U32(ctx.r16.u32 + 0, ctx.r11.u32);
	// lwz r10,28(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// rlwinm. r10,r10,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820c3908
	if (!ctx.cr0.eq) goto loc_820C3908;
	// cmplwi cr6,r23,1
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 1, ctx.xer);
	// bgt cr6,0x820c3908
	if (ctx.cr6.gt) goto loc_820C3908;
	// cmpwi cr6,r15,3
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 3, ctx.xer);
	// beq cr6,0x820c3924
	if (ctx.cr6.eq) goto loc_820C3924;
	// cmpwi cr6,r15,20
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 20, ctx.xer);
	// beq cr6,0x820c3924
	if (ctx.cr6.eq) goto loc_820C3924;
loc_820C3908:
	// lwz r10,48(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// rlwinm r10,r10,0,21,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x600;
	// cmplwi cr6,r10,1024
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1024, ctx.xer);
	// beq cr6,0x820c3924
	if (ctx.cr6.eq) goto loc_820C3924;
	// addi r11,r11,4095
	ctx.r11.s64 = ctx.r11.s64 + 4095;
	// rlwinm r11,r11,0,0,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFF000;
	// stw r11,0(r16)
	REX_STORE_U32(ctx.r16.u32 + 0, ctx.r11.u32);
loc_820C3924:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
}
