DEFINE_REX_FUNC(sub_82125C10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x82125C18;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// lbz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// mr r29,r8
	ctx.r29.u64 = ctx.r8.u64;
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// stw r25,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// addi r28,r6,1
	ctx.r28.s64 = ctx.r6.s64 + 1;
	// sth r25,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r25.u16);
	// addi r3,r26,1
	ctx.r3.s64 = ctx.r26.s64 + 1;
	// sth r25,10(r31)
	REX_STORE_U16(ctx.r31.u32 + 10, ctx.r25.u16);
	// stb r11,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r11.u8);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi. r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82125c68
	if (ctx.cr0.eq) goto loc_82125C68;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x82125c70
	goto loc_82125C70;
loc_82125C68:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82125ba8
	ctx.lr = 0x82125C70;
	sub_82125BA8(ctx, base);
loc_82125C70:
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82125d44
	if (ctx.cr6.eq) goto loc_82125D44;
	// cmplw cr6,r9,r28
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r28.u32, ctx.xer);
	// bge cr6,0x82125d44
	if (!ctx.cr6.lt) goto loc_82125D44;
	// lbz r8,12(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
	// rlwinm. r11,r8,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82125d04
	if (ctx.cr0.eq) goto loc_82125D04;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82125cd8
	if (ctx.cr6.eq) goto loc_82125CD8;
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
loc_82125CA0:
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// addi r29,r29,-1
	ctx.r29.s64 = ctx.r29.s64 + -1;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82125cd0
	if (!ctx.cr6.eq) goto loc_82125CD0;
	// lbz r7,13(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 13);
	// cmplwi cr6,r7,2
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 2, ctx.xer);
	// beq cr6,0x82125d44
	if (ctx.cr6.eq) goto loc_82125D44;
	// lbz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 12);
	// rlwinm. r7,r7,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x82125d54
	if (!ctx.cr0.eq) goto loc_82125D54;
loc_82125CD0:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82125ca0
	if (!ctx.cr6.eq) goto loc_82125CA0;
loc_82125CD8:
	// lbz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// lhz r9,10(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 10);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// sth r10,10(r31)
	REX_STORE_U16(ctx.r31.u32 + 10, ctx.r10.u16);
	// lbz r10,1(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// lhz r11,10(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 10);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
loc_82125D00:
	// sth r11,10(r31)
	REX_STORE_U16(ctx.r31.u32 + 10, ctx.r11.u16);
loc_82125D04:
	// rlwinm. r11,r8,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82125d6c
	if (ctx.cr0.eq) goto loc_82125D6C;
	// lbz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// lhz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// sth r10,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r10.u16);
	// lbz r10,1(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// sth r11,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r11.u16);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82125d7c
	if (!ctx.cr0.eq) goto loc_82125D7C;
loc_82125D44:
	// stb r25,13(r31)
	REX_STORE_U8(ctx.r31.u32 + 13, ctx.r25.u8);
loc_82125D48:
	// subf r3,r26,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r26.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
loc_82125D54:
	// lhz r11,10(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// rlwinm. r10,r8,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sth r11,10(r31)
	REX_STORE_U16(ctx.r31.u32 + 10, ctx.r11.u16);
	// beq 0x82125d04
	if (ctx.cr0.eq) goto loc_82125D04;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x82125d00
	goto loc_82125D00;
loc_82125D6C:
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// sth r11,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r11.u16);
loc_82125D7C:
	// rlwinm. r11,r8,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82125d90
	if (ctx.cr0.eq) goto loc_82125D90;
	// li r11,128
	ctx.r11.s64 = 128;
	// stb r11,13(r31)
	REX_STORE_U8(ctx.r31.u32 + 13, ctx.r11.u8);
	// b 0x82125da8
	goto loc_82125DA8;
loc_82125D90:
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// stb r11,13(r31)
	REX_STORE_U8(ctx.r31.u32 + 13, ctx.r11.u8);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x82125d44
	if (!ctx.cr6.lt) goto loc_82125D44;
loc_82125DA8:
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82125dc8
	if (!ctx.cr0.eq) goto loc_82125DC8;
	// subf r11,r26,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r26.u64;
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// bge cr6,0x82125d44
	if (!ctx.cr6.lt) goto loc_82125D44;
	// subf r11,r11,r24
	ctx.r11.u64 = ctx.r24.u64 - ctx.r11.u64;
	// sth r11,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r11.u16);
loc_82125DC8:
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// b 0x82125d48
	goto loc_82125D48;
}
