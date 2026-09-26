DEFINE_REX_FUNC(sub_821217D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e8
	ctx.lr = 0x821217D8;
	__savegprlr_16(ctx, base);
	// stwu r1,-896(r1)
	ea = -896 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// mr r17,r5
	ctx.r17.u64 = ctx.r5.u64;
	// mr r16,r6
	ctx.r16.u64 = ctx.r6.u64;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x82121810
	if (!ctx.cr6.gt) goto loc_82121810;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r19,r11,2
	ctx.r19.s64 = ctx.r11.s64 + 2;
	// b 0x821219d0
	goto loc_821219D0;
loc_82121810:
	// lhz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 328);
	// li r20,0
	ctx.r20.s64 = 0;
	// li r23,0
	ctx.r23.s64 = 0;
	// li r19,0
	ctx.r19.s64 = 0;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x821219c8
	if (ctx.cr0.eq) goto loc_821219C8;
	// addi r30,r1,244
	ctx.r30.s64 = ctx.r1.s64 + 244;
	// addi r21,r1,112
	ctx.r21.s64 = ctx.r1.s64 + 112;
	// addi r26,r31,72
	ctx.r26.s64 = ctx.r31.s64 + 72;
loc_82121838:
	// lwz r10,36(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// addi r22,r27,1
	ctx.r22.s64 = ctx.r27.s64 + 1;
	// lhz r9,328(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 328);
	// lhz r11,4(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 4);
	// cmplw cr6,r22,r9
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r9.u32, ctx.xer);
	// add r24,r10,r11
	ctx.r24.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bge cr6,0x8212185c
	if (!ctx.cr6.lt) goto loc_8212185C;
	// lhz r10,12(r26)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r26.u32 + 12);
	// b 0x82121860
	goto loc_82121860;
loc_8212185C:
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
loc_82121860:
	// addi r28,r30,-4
	ctx.r28.s64 = ctx.r30.s64 + -4;
	// subf r29,r11,r10
	ctx.r29.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r28,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r28.u32);
	// lis r6,255
	ctx.r6.s64 = 16711680;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// ori r6,r6,65535
	ctx.r6.u64 = ctx.r6.u64 | 65535;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82125c10
	ctx.lr = 0x8212188C;
	sub_82125C10(ctx, base);
	// lhz r11,6(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 6);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// rlwinm. r10,r11,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x821218dc
	if (!ctx.cr0.eq) goto loc_821218DC;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821219ac
	if (ctx.cr6.eq) goto loc_821219AC;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lis r5,-32646
	ctx.r5.s64 = -2139488256;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// ori r5,r5,4108
	ctx.r5.u64 = ctx.r5.u64 | 4108;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821218C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,330(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 330);
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// sth r11,330(r31)
	REX_STORE_U16(ctx.r31.u32 + 330, ctx.r11.u16);
	// b 0x821219ac
	goto loc_821219AC;
loc_821218DC:
	// rlwinm. r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x821218e8
	if (!ctx.cr0.eq) goto loc_821218E8;
	// add r19,r29,r19
	ctx.r19.u64 = ctx.r29.u64 + ctx.r19.u64;
loc_821218E8:
	// clrlwi r23,r23,16
	ctx.r23.u64 = ctx.r23.u32 & 0xFFFF;
	// cmplw cr6,r27,r23
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r23.u32, ctx.xer);
	// beq cr6,0x821219a0
	if (ctx.cr6.eq) goto loc_821219A0;
	// lwz r10,36(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// rlwinm. r11,r11,0,18,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r27,r10,r20
	ctx.r27.u64 = ctx.r10.u64 + ctx.r20.u64;
	// beq 0x82121954
	if (ctx.cr0.eq) goto loc_82121954;
	// lhz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 328);
	// li r7,0
	ctx.r7.s64 = 0;
	// lhz r3,6(r30)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r30.u32 + 6);
	// li r6,1
	ctx.r6.s64 = 1;
	// subf r11,r22,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r22.u64;
	// lhz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// lbz r4,9(r30)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r30.u32 + 9);
	// sth r3,86(r1)
	REX_STORE_U16(ctx.r1.u32 + 86, ctx.r3.u16);
	// rlwinm r8,r11,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82125a88
	ctx.lr = 0x8212193C;
	sub_82125A88(ctx, base);
	// subf r11,r25,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r25.u64;
	// lhz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r30.u32 + 4);
	// add r3,r3,r27
	ctx.r3.u64 = ctx.r3.u64 + ctx.r27.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// b 0x82121960
	goto loc_82121960;
loc_82121954:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_82121960:
	// bl 0x8212a760
	ctx.lr = 0x82121964;
	sub_8212A760(ctx, base);
	// rlwinm r11,r23,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r23,9
	ctx.r9.s64 = ctx.r23.s64 + 9;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lhz r7,78(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 78);
	// stwx r10,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r10.u32);
	// ori r10,r7,32768
	ctx.r10.u64 = ctx.r7.u64 | 32768;
	// sth r20,76(r11)
	REX_STORE_U16(ctx.r11.u32 + 76, ctx.r20.u16);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// sth r10,78(r11)
	REX_STORE_U16(ctx.r11.u32 + 78, ctx.r10.u16);
	// lhz r10,6(r26)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r26.u32 + 6);
	// rlwimi r9,r10,0,17,17
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000) | (ctx.r9.u64 & 0xFFFFFFFFFFFFBFFF);
	// andi. r10,r9,57343
	ctx.r10.u64 = ctx.r9.u64 & 57343;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sth r10,78(r11)
	REX_STORE_U16(ctx.r11.u32 + 78, ctx.r10.u16);
loc_821219A0:
	// addi r11,r23,1
	ctx.r11.s64 = ctx.r23.s64 + 1;
	// add r20,r29,r20
	ctx.r20.u64 = ctx.r29.u64 + ctx.r20.u64;
	// clrlwi r23,r11,16
	ctx.r23.u64 = ctx.r11.u32 & 0xFFFF;
loc_821219AC:
	// lhz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 328);
	// mr r27,r22
	ctx.r27.u64 = ctx.r22.u64;
	// addi r21,r21,4
	ctx.r21.s64 = ctx.r21.s64 + 4;
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// addi r26,r26,8
	ctx.r26.s64 = ctx.r26.s64 + 8;
	// cmplw cr6,r22,r11
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82121838
	if (ctx.cr6.lt) goto loc_82121838;
loc_821219C8:
	// sth r23,328(r31)
	REX_STORE_U16(ctx.r31.u32 + 328, ctx.r23.u16);
	// stw r20,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r20.u32);
loc_821219D0:
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// subfic r7,r11,1264
	ctx.xer.ca = ctx.r11.u32 <= 1264;
	ctx.r7.u64 = static_cast<uint64_t>(1264) - ctx.r11.u64;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// bl 0x82120f60
	ctx.lr = 0x821219F0;
	sub_82120F60(ctx, base);
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r11,r17,1
	ctx.r11.s64 = ctx.r17.s64 + 1;
	// stw r3,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// subf r10,r10,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r10.u64;
	// sth r11,334(r31)
	REX_STORE_U16(ctx.r31.u32 + 334, ctx.r11.u16);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,896
	ctx.r1.s64 = ctx.r1.s64 + 896;
	// b 0x82129938
	__restgprlr_16(ctx, base);
	return;
}
