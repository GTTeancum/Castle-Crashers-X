DEFINE_REX_FUNC(sub_8210DC98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e4
	ctx.lr = 0x8210DCA0;
	__savegprlr_15(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,308(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 308);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r18,r30,104
	ctx.r18.s64 = ctx.r30.s64 + 104;
	// mr r19,r5
	ctx.r19.u64 = ctx.r5.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// mr r20,r6
	ctx.r20.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// mr r23,r10
	ctx.r23.u64 = ctx.r10.u64;
	// li r17,0
	ctx.r17.s64 = 0;
	// rlwinm r22,r11,0,25,23
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// li r16,0
	ctx.r16.s64 = 0;
	// bl 0x8214a434
	ctx.lr = 0x8210DCE0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bge cr6,0x8210defc
	if (!ctx.cr6.lt) goto loc_8210DEFC;
	// li r15,0
	ctx.r15.s64 = 0;
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// beq cr6,0x8210ded8
	if (ctx.cr6.eq) goto loc_8210DED8;
	// mr r21,r31
	ctx.r21.u64 = ctx.r31.u64;
loc_8210DCFC:
	// lwz r10,0(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// rlwinm r11,r10,7,25,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0x7F;
	// rlwinm r10,r10,14,25,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 14) & 0x7F;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8210de1c
	if (!ctx.cr6.eq) goto loc_8210DE1C;
	// lwz r10,0(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// rlwinm. r9,r10,0,14,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8210def0
	if (!ctx.cr0.eq) goto loc_8210DEF0;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// subfic r11,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
	// clrlwi r10,r10,15
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFF;
	// ori r9,r9,65534
	ctx.r9.u64 = ctx.r9.u64 | 65534;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// bge cr6,0x8210def0
	if (!ctx.cr6.lt) goto loc_8210DEF0;
	// addi r9,r11,80
	ctx.r9.s64 = ctx.r11.s64 + 80;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r9,r30
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r30.u32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8210def0
	if (!ctx.cr6.lt) goto loc_8210DEF0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210dd58
	if (!ctx.cr6.eq) goto loc_8210DD58;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_8210DD58:
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x8210def0
	if (ctx.cr6.eq) goto loc_8210DEF0;
	// lis r9,255
	ctx.r9.s64 = 16711680;
	// subfic r8,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r8.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
	// lwz r11,712(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 712);
	// ori r9,r9,65534
	ctx.r9.u64 = ctx.r9.u64 | 65534;
	// addi r28,r30,712
	ctx.r28.s64 = ctx.r30.s64 + 712;
	// rlwinm r8,r8,24,0,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF000000;
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// or r27,r8,r10
	ctx.r27.u64 = ctx.r8.u64 | ctx.r10.u64;
	// beq cr6,0x8210dec8
	if (ctx.cr6.eq) goto loc_8210DEC8;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8210dec8
	if (ctx.cr0.eq) goto loc_8210DEC8;
loc_8210DD94:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r4,r29,-4
	ctx.r4.s64 = ctx.r29.s64 + -4;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8210ddac
	if (ctx.cr6.eq) goto loc_8210DDAC;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_8210DDAC:
	// lwz r31,168(r4)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r4.u32 + 168);
	// rlwinm. r11,r31,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8210de10
	if (!ctx.cr0.eq) goto loc_8210DE10;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x8210dddc
	if (ctx.cr6.eq) goto loc_8210DDDC;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210cb20
	ctx.lr = 0x8210DDCC;
	sub_8210CB20(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8210dddc
	if (!ctx.cr0.eq) goto loc_8210DDDC;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// b 0x8210de10
	goto loc_8210DE10;
loc_8210DDDC:
	// rlwinm. r11,r31,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8210de10
	if (!ctx.cr0.eq) goto loc_8210DE10;
	// lwz r3,68(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 68);
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// mr r8,r23
	ctx.r8.u64 = ctx.r23.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82115188
	ctx.lr = 0x8210DE04;
	sub_82115188(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8210dedc
	if (ctx.cr0.lt) goto loc_8210DEDC;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
loc_8210DE10:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8210dd94
	if (!ctx.cr6.eq) goto loc_8210DD94;
	// b 0x8210dec8
	goto loc_8210DEC8;
loc_8210DE1C:
	// lwz r9,172(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8210def0
	if (!ctx.cr6.eq) goto loc_8210DEF0;
	// addi r11,r10,44
	ctx.r11.s64 = ctx.r10.s64 + 44;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8210def0
	if (ctx.cr6.eq) goto loc_8210DEF0;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x8210de60
	if (ctx.cr6.eq) goto loc_8210DE60;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210cb20
	ctx.lr = 0x8210DE50;
	sub_8210CB20(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8210de60
	if (!ctx.cr0.eq) goto loc_8210DE60;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// b 0x8210dec8
	goto loc_8210DEC8;
loc_8210DE60:
	// lwz r11,168(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 168);
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8210defc
	if (!ctx.cr0.eq) goto loc_8210DEFC;
	// lwz r10,64(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 64);
	// lwz r11,168(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 168);
	// lwz r9,0(r21)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// subfc r11,r11,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// clrlwi r10,r9,14
	ctx.r10.u64 = ctx.r9.u32 & 0x3FFFF;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r9,r10,21
	ctx.r9.u64 = ctx.r10.u32 & 0x7FF;
	// rlwinm r10,r10,13,1,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 13) & 0x7F000000;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// or r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 | ctx.r9.u64;
	// bne 0x8210de9c
	if (!ctx.cr0.eq) goto loc_8210DE9C;
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
loc_8210DE9C:
	// lwz r3,68(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 68);
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// mr r8,r23
	ctx.r8.u64 = ctx.r23.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// bl 0x82115188
	ctx.lr = 0x8210DEBC;
	sub_82115188(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8210dedc
	if (ctx.cr0.lt) goto loc_8210DEDC;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
loc_8210DEC8:
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// addi r21,r21,4
	ctx.r21.s64 = ctx.r21.s64 + 4;
	// cmplw cr6,r15,r19
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, ctx.r19.u32, ctx.xer);
	// blt cr6,0x8210dcfc
	if (ctx.cr6.lt) goto loc_8210DCFC;
loc_8210DED8:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8210DEDC:
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x8214a444
	ctx.lr = 0x8210DEE4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82129934
	__restgprlr_15(ctx, base);
	return;
loc_8210DEF0:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4111
	ctx.r31.u64 = ctx.r31.u64 | 4111;
	// b 0x8210dedc
	goto loc_8210DEDC;
loc_8210DEFC:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4112
	ctx.r31.u64 = ctx.r31.u64 | 4112;
	// b 0x8210dedc
	goto loc_8210DEDC;
}
