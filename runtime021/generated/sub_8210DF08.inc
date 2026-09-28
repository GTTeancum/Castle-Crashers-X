DEFINE_REX_FUNC(sub_8210DF08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8210DF10;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r27,r29,104
	ctx.r27.s64 = ctx.r29.s64 + 104;
	// rlwinm r30,r31,7,25,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 7) & 0x7F;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// rlwinm r28,r31,14,25,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 14) & 0x7F;
	// bl 0x8214a434
	ctx.lr = 0x8210DF30;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x8210dfe8
	if (!ctx.cr6.eq) goto loc_8210DFE8;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8210df48
	if (ctx.cr6.eq) goto loc_8210DF48;
	// li r28,0
	ctx.r28.s64 = 0;
	// b 0x8210df98
	goto loc_8210DF98;
loc_8210DF48:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// subfic r11,r30,127
	ctx.xer.ca = ctx.r30.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r30.u64;
	// ori r10,r10,65534
	ctx.r10.u64 = ctx.r10.u64 | 65534;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bge cr6,0x8210e008
	if (!ctx.cr6.lt) goto loc_8210E008;
	// addi r9,r11,80
	ctx.r9.s64 = ctx.r11.s64 + 80;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r9,r29
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8210e008
	if (!ctx.cr6.gt) goto loc_8210E008;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210df80
	if (!ctx.cr6.eq) goto loc_8210DF80;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
loc_8210DF80:
	// lis r9,255
	ctx.r9.s64 = 16711680;
	// subfic r11,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
	// ori r9,r9,65534
	ctx.r9.u64 = ctx.r9.u64 | 65534;
	// rlwinm r11,r11,24,0,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF000000;
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// or r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 | ctx.r10.u64;
loc_8210DF98:
	// addi r29,r29,712
	ctx.r29.s64 = ctx.r29.s64 + 712;
	// lwz r30,0(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8210dfd0
	goto loc_8210DFD0;
loc_8210DFA4:
	// lwz r11,164(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 164);
	// rlwinm. r10,r11,0,6,6
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8210dfcc
	if (!ctx.cr0.eq) goto loc_8210DFCC;
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8210dfcc
	if (!ctx.cr0.eq) goto loc_8210DFCC;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,64(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// bl 0x82115190
	ctx.lr = 0x8210DFC4;
	sub_82115190(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8210e060
	if (!ctx.cr0.eq) goto loc_8210E060;
loc_8210DFCC:
	// lwz r30,0(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8210DFD0:
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8210dfe0
	if (ctx.cr6.eq) goto loc_8210DFE0;
	// cmplwi r30,0
	ctx.cr0.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne 0x8210dfa4
	if (!ctx.cr0.eq) goto loc_8210DFA4;
loc_8210DFE0:
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8210e060
	goto loc_8210E060;
loc_8210DFE8:
	// lwz r11,172(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 172);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8210e008
	if (!ctx.cr6.eq) goto loc_8210E008;
	// addi r11,r28,44
	ctx.r11.s64 = ctx.r28.s64 + 44;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210e014
	if (!ctx.cr6.eq) goto loc_8210E014;
loc_8210E008:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4111
	ctx.r31.u64 = ctx.r31.u64 | 4111;
	// b 0x8210e060
	goto loc_8210E060;
loc_8210E014:
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// rlwinm. r10,r10,0,6,6
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8210e02c
	if (ctx.cr0.eq) goto loc_8210E02C;
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4112
	ctx.r31.u64 = ctx.r31.u64 | 4112;
	// b 0x8210e060
	goto loc_8210E060;
loc_8210E02C:
	// lwz r10,168(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 168);
	// clrlwi r9,r31,21
	ctx.r9.u64 = ctx.r31.u32 & 0x7FF;
	// lwz r8,64(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// rlwinm r7,r31,13,1,7
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 13) & 0x7F000000;
	// subfc r10,r10,r8
	ctx.xer.ca = ctx.r8.u32 >= ctx.r10.u32;
	ctx.r10.u64 = ctx.r8.u64 - ctx.r10.u64;
	// or r4,r7,r9
	ctx.r4.u64 = ctx.r7.u64 | ctx.r9.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8210e054
	if (!ctx.cr0.eq) goto loc_8210E054;
	// oris r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 2147483648;
loc_8210E054:
	// lwz r3,68(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// bl 0x82115190
	ctx.lr = 0x8210E05C;
	sub_82115190(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8210E060:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8214a444
	ctx.lr = 0x8210E068;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
