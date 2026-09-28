DEFINE_REX_FUNC(sub_8211CD00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x8211CD08;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x8211cd40
	if (ctx.cr6.eq) goto loc_8211CD40;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// li r11,2
	ctx.r11.s64 = 2;
loc_8211CD2C:
	// lhz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// add r24,r9,r24
	ctx.r24.u64 = ctx.r9.u64 + ctx.r24.u64;
	// bne 0x8211cd2c
	if (!ctx.cr0.eq) goto loc_8211CD2C;
loc_8211CD40:
	// addi r22,r25,40
	ctx.r22.s64 = ctx.r25.s64 + 40;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8214a434
	ctx.lr = 0x8211CD4C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,255
	ctx.r11.s64 = 16711680;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r28,r31
	ctx.r28.u64 = ctx.r31.u64;
	// ori r26,r11,65534
	ctx.r26.u64 = ctx.r11.u64 | 65534;
loc_8211CD5C:
	// lhz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8211cda0
	if (ctx.cr0.eq) goto loc_8211CDA0;
	// subfic r11,r30,127
	ctx.xer.ca = ctx.r30.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r30.u64;
	// rlwinm r27,r11,24,0,7
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF000000;
loc_8211CD74:
	// subf r11,r29,r26
	ctx.r11.u64 = ctx.r26.u64 - ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// or r4,r11,r27
	ctx.r4.u64 = ctx.r11.u64 | ctx.r27.u64;
	// bl 0x8211bbf0
	ctx.lr = 0x8211CD88;
	sub_8211BBF0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8211ce3c
	if (ctx.cr0.lt) goto loc_8211CE3C;
	// lhz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8211cd74
	if (ctx.cr6.lt) goto loc_8211CD74;
loc_8211CDA0:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r28,r28,2
	ctx.r28.s64 = ctx.r28.s64 + 2;
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// blt cr6,0x8211cd5c
	if (ctx.cr6.lt) goto loc_8211CD5C;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8211ce38
	if (ctx.cr6.eq) goto loc_8211CE38;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r3,r25,572
	ctx.r3.s64 = ctx.r25.s64 + 572;
	// bl 0x821220f8
	ctx.lr = 0x8211CDC4;
	sub_821220F8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8211cdd8
	if (!ctx.cr0.eq) goto loc_8211CDD8;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x8211ce3c
	goto loc_8211CE3C;
loc_8211CDD8:
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r27,r23
	ctx.r27.u64 = ctx.r23.u64;
loc_8211CDE0:
	// lhz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8211ce28
	if (ctx.cr0.eq) goto loc_8211CE28;
	// subfic r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 <= 4294967295;
	ctx.r11.u64 = static_cast<uint64_t>(-1) - ctx.r30.u64;
	// rlwinm r11,r11,24,0,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF000000;
	// oris r28,r11,32768
	ctx.r28.u64 = ctx.r11.u64 | 2147483648;
loc_8211CDFC:
	// subf r11,r29,r26
	ctx.r11.u64 = ctx.r26.u64 - ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// or r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 | ctx.r28.u64;
	// bl 0x8211b3b8
	ctx.lr = 0x8211CE10;
	sub_8211B3B8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8211ce3c
	if (ctx.cr0.lt) goto loc_8211CE3C;
	// lhz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8211cdfc
	if (ctx.cr6.lt) goto loc_8211CDFC;
loc_8211CE28:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r27,r27,2
	ctx.r27.s64 = ctx.r27.s64 + 2;
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// blt cr6,0x8211cde0
	if (ctx.cr6.lt) goto loc_8211CDE0;
loc_8211CE38:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8211CE3C:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8214a444
	ctx.lr = 0x8211CE44;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
