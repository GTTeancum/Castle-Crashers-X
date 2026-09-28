DEFINE_REX_FUNC(sub_82110B68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x82110B70;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r24,r30,104
	ctx.r24.s64 = ctx.r30.s64 + 104;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// bl 0x8214a434
	ctx.lr = 0x82110B98;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x82110bc8
	if (!ctx.cr6.eq) goto loc_82110BC8;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r10,820(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 820);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// rlwimi r10,r11,25,6,6
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x2000000) | (ctx.r10.u64 & 0xFFFFFFFFFDFFFFFF);
	// b 0x82110e20
	goto loc_82110E20;
loc_82110BC8:
	// cmpwi cr6,r27,16
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 16, ctx.xer);
	// beq cr6,0x82110bd8
	if (ctx.cr6.eq) goto loc_82110BD8;
	// cmpwi cr6,r27,17
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 17, ctx.xer);
	// bne cr6,0x82110c04
	if (!ctx.cr6.eq) goto loc_82110C04;
loc_82110BD8:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// beq cr6,0x82110e88
	if (ctx.cr6.eq) goto loc_82110E88;
	// li r10,-1
	ctx.r10.s64 = -1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82110e88
	if (!ctx.cr6.lt) goto loc_82110E88;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r26,r1,80
	ctx.r26.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r25,4
	ctx.r25.s64 = 4;
loc_82110C04:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82110c14
	if (!ctx.cr6.eq) goto loc_82110C14;
	// li r28,0
	ctx.r28.s64 = 0;
	// b 0x82110d4c
	goto loc_82110D4C;
loc_82110C14:
	// rlwinm r11,r31,7,25,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 7) & 0x7F;
	// rlwinm r9,r31,14,25,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 14) & 0x7F;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82110ca4
	if (!ctx.cr6.eq) goto loc_82110CA4;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// subfic r11,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
	// clrlwi r9,r31,15
	ctx.r9.u64 = ctx.r31.u32 & 0x1FFFF;
	// ori r10,r10,65534
	ctx.r10.u64 = ctx.r10.u64 | 65534;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// bge cr6,0x82110d3c
	if (!ctx.cr6.lt) goto loc_82110D3C;
	// addi r9,r11,80
	ctx.r9.s64 = ctx.r11.s64 + 80;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r9,r30
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r30.u32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82110d3c
	if (!ctx.cr6.lt) goto loc_82110D3C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82110c60
	if (!ctx.cr6.eq) goto loc_82110C60;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_82110C60:
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x82110d3c
	if (ctx.cr6.eq) goto loc_82110D3C;
	// rlwinm. r9,r31,0,14,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lis r9,255
	ctx.r9.s64 = 16711680;
	// ori r9,r9,65534
	ctx.r9.u64 = ctx.r9.u64 | 65534;
	// beq 0x82110c90
	if (ctx.cr0.eq) goto loc_82110C90;
	// subfic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 <= 4294967295;
	ctx.r11.u64 = static_cast<uint64_t>(-1) - ctx.r11.u64;
	// lis r8,-32768
	ctx.r8.s64 = -2147483648;
	// rlwimi r8,r11,24,1,7
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0x7F000000) | (ctx.r8.u64 & 0xFFFFFFFF80FFFFFF);
	// subf r11,r10,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r10.u64;
	// or r28,r8,r11
	ctx.r28.u64 = ctx.r8.u64 | ctx.r11.u64;
	// b 0x82110d4c
	goto loc_82110D4C;
loc_82110C90:
	// subfic r11,r11,127
	ctx.xer.ca = ctx.r11.u32 <= 127;
	ctx.r11.u64 = static_cast<uint64_t>(127) - ctx.r11.u64;
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// rlwinm r11,r11,24,0,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF000000;
	// or r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 | ctx.r10.u64;
	// b 0x82110d4c
	goto loc_82110D4C;
loc_82110CA4:
	// lwz r10,172(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82110cdc
	if (!ctx.cr6.eq) goto loc_82110CDC;
	// addi r11,r9,44
	ctx.r11.s64 = ctx.r9.s64 + 44;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110d3c
	if (ctx.cr6.eq) goto loc_82110D3C;
	// lwz r10,168(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 168);
	// lwz r9,64(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// subfc r10,r10,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r10.u32;
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// b 0x82110d0c
	goto loc_82110D0C;
loc_82110CDC:
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82110d3c
	if (!ctx.cr6.eq) goto loc_82110D3C;
	// addi r11,r11,44
	ctx.r11.s64 = ctx.r11.s64 + 44;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110d3c
	if (ctx.cr6.eq) goto loc_82110D3C;
	// lwz r10,168(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 168);
	// lwz r9,64(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// subfc r10,r10,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r10.u32;
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_82110D0C:
	// clrlwi r9,r31,21
	ctx.r9.u64 = ctx.r31.u32 & 0x7FF;
	// rlwinm r8,r31,13,1,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 13) & 0x7F000000;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// bne cr6,0x82110d24
	if (!ctx.cr6.eq) goto loc_82110D24;
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
loc_82110D24:
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82110d48
	if (ctx.cr6.eq) goto loc_82110D48;
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82110d4c
	if (ctx.cr6.eq) goto loc_82110D4C;
loc_82110D3C:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4111
	ctx.r31.u64 = ctx.r31.u64 | 4111;
	// b 0x82110e90
	goto loc_82110E90;
loc_82110D48:
	// lwz r29,60(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
loc_82110D4C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82110d98
	if (ctx.cr6.eq) goto loc_82110D98;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210e678
	ctx.lr = 0x82110D60;
	sub_8210E678(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82110e88
	if (ctx.cr0.eq) goto loc_82110E88;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82110e88
	if (ctx.cr6.eq) goto loc_82110E88;
	// lwz r3,68(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82110e88
	if (ctx.cr6.eq) goto loc_82110E88;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82115290
	ctx.lr = 0x82110D90;
	sub_82115290(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82110e90
	goto loc_82110E90;
loc_82110D98:
	// cmpwi cr6,r27,26
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 26, ctx.xer);
	// bne cr6,0x82110dbc
	if (!ctx.cr6.eq) goto loc_82110DBC;
	// lwz r11,820(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 820);
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r11,r11,5,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0x1;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x82110dbc
	if (!ctx.cr6.eq) goto loc_82110DBC;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x82110e90
	goto loc_82110E90;
loc_82110DBC:
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// lwz r3,164(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 164);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82115290
	ctx.lr = 0x82110DD4;
	sub_82115290(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82110e90
	if (ctx.cr0.lt) goto loc_82110E90;
	// cmpwi cr6,r27,4096
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4096, ctx.xer);
	// bgt cr6,0x82110e28
	if (ctx.cr6.gt) goto loc_82110E28;
	// beq cr6,0x82110e38
	if (ctx.cr6.eq) goto loc_82110E38;
	// addi r11,r27,-1
	ctx.r11.s64 = ctx.r27.s64 + -1;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-20744
	ctx.r12.s64 = ctx.r12.s64 + -20744;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// lis r12,-32239
	ctx.r12.s64 = -2112815104;
	// addi r12,r12,3604
	ctx.r12.s64 = ctx.r12.s64 + 3604;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82110E38;
	case 1:
		goto loc_82110E38;
	case 2:
		goto loc_82110E90;
	case 3:
		goto loc_82110E38;
	case 4:
		goto loc_82110E38;
	case 5:
		goto loc_82110E38;
	case 6:
		goto loc_82110E90;
	case 7:
		goto loc_82110E90;
	case 8:
		goto loc_82110E38;
	case 9:
		goto loc_82110E90;
	case 10:
		goto loc_82110E90;
	case 11:
		goto loc_82110E90;
	case 12:
		goto loc_82110E90;
	case 13:
		goto loc_82110E38;
	case 14:
		goto loc_82110E90;
	case 15:
		goto loc_82110E90;
	case 16:
		goto loc_82110E90;
	case 17:
		goto loc_82110E38;
	case 18:
		goto loc_82110E38;
	case 19:
		goto loc_82110E38;
	case 20:
		goto loc_82110E90;
	case 21:
		goto loc_82110E38;
	case 22:
		goto loc_82110E38;
	case 23:
		goto loc_82110E38;
	case 24:
		goto loc_82110E38;
	case 25:
		goto loc_82110E14;
	case 26:
		goto loc_82110E38;
	case 27:
		goto loc_82110E38;
	case 28:
		goto loc_82110E14;
	case 29:
		goto loc_82110E14;
	case 30:
		goto loc_82110E14;
	case 31:
		goto loc_82110E14;
	case 32:
		goto loc_82110E20;
	case 33:
		goto loc_82110E20;
	case 34:
		goto loc_82110E20;
	case 35:
		goto loc_82110E20;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82110E14:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r10,820(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 820);
	// rlwimi r10,r11,27,4,4
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x8000000) | (ctx.r10.u64 & 0xFFFFFFFFF7FFFFFF);
loc_82110E20:
	// stw r10,820(r30)
	REX_STORE_U32(ctx.r30.u32 + 820, ctx.r10.u32);
	// b 0x82110e90
	goto loc_82110E90;
loc_82110E28:
	// cmpwi cr6,r27,4097
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4097, ctx.xer);
	// beq cr6,0x82110e90
	if (ctx.cr6.eq) goto loc_82110E90;
	// cmpwi cr6,r27,4103
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4103, ctx.xer);
	// bgt cr6,0x82110e90
	if (ctx.cr6.gt) goto loc_82110E90;
loc_82110E38:
	// lwz r11,712(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 712);
	// addi r29,r30,712
	ctx.r29.s64 = ctx.r30.s64 + 712;
	// b 0x82110e70
	goto loc_82110E70;
loc_82110E44:
	// lwz r3,64(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82110e6c
	if (ctx.cr6.eq) goto loc_82110E6C;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82115290
	ctx.lr = 0x82110E64;
	sub_82115290(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82110e90
	if (ctx.cr0.lt) goto loc_82110E90;
loc_82110E6C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_82110E70:
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82110e90
	if (ctx.cr6.eq) goto loc_82110E90;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// bne 0x82110e44
	if (!ctx.cr0.eq) goto loc_82110E44;
	// b 0x82110e90
	goto loc_82110E90;
loc_82110E88:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4105
	ctx.r31.u64 = ctx.r31.u64 | 4105;
loc_82110E90:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8214a444
	ctx.lr = 0x82110E98;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
