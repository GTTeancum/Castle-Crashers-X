DEFINE_REX_FUNC(sub_8211B100) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8211B108;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r6,16
	ctx.r11.u64 = ctx.r6.u32 & 0xFFFF;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x8211b128
	if (!ctx.cr6.lt) goto loc_8211B128;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// b 0x8211b154
	goto loc_8211B154;
loc_8211B128:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// bge cr6,0x8211b144
	if (!ctx.cr6.lt) goto loc_8211B144;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,15
	ctx.r11.s64 = ctx.r11.s64 + 15;
	// b 0x8211b150
	goto loc_8211B150;
loc_8211B144:
	// addi r11,r11,-16
	ctx.r11.s64 = ctx.r11.s64 + -16;
	// rlwinm r11,r11,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r11,r11,103
	ctx.r11.s64 = ctx.r11.s64 + 103;
loc_8211B150:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
loc_8211B154:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lhz r10,1050(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 1050);
	// clrlwi r9,r5,16
	ctx.r9.u64 = ctx.r5.u32 & 0xFFFF;
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r10,32768
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32768, ctx.xer);
	// bge cr6,0x8211b184
	if (!ctx.cr6.lt) goto loc_8211B184;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8211b224
	goto loc_8211B224;
loc_8211B184:
	// lwz r10,1148(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 1148);
	// addi r31,r30,1008
	ctx.r31.s64 = ctx.r30.s64 + 1008;
	// sth r11,1050(r30)
	REX_STORE_U16(ctx.r30.u32 + 1050, ctx.r11.u16);
	// rlwinm r11,r10,0,12,10
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// stw r27,1028(r30)
	REX_STORE_U32(ctx.r30.u32 + 1028, ctx.r27.u32);
	// stw r11,1148(r30)
	REX_STORE_U32(ctx.r30.u32 + 1148, ctx.r11.u32);
	// lwz r11,1008(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1008);
	// b 0x8211b218
	goto loc_8211B218;
loc_8211B1A4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x8211b1b4
	if (!ctx.cr6.eq) goto loc_8211B1B4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8211B1B4:
	// lhz r10,324(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 324);
	// addi r29,r11,-8
	ctx.r29.s64 = ctx.r11.s64 + -8;
	// subf r11,r28,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r28.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// blt cr6,0x8211b220
	if (ctx.cr6.lt) goto loc_8211B220;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82121a98
	ctx.lr = 0x8211B1D4;
	sub_82121A98(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8211b200
	if (ctx.cr6.eq) goto loc_8211B200;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
loc_8211B200:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821180d8
	ctx.lr = 0x8211B208;
	sub_821180D8(ctx, base);
	// lhz r11,1042(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 1042);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,1042(r30)
	REX_STORE_U16(ctx.r30.u32 + 1042, ctx.r11.u16);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_8211B218:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x8211b1a4
	if (!ctx.cr6.eq) goto loc_8211B1A4;
loc_8211B220:
	// li r31,1
	ctx.r31.s64 = 1;
loc_8211B224:
	// lhz r11,1032(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 1032);
	// lhz r10,1050(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 1050);
	// lhz r9,1056(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 1056);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8211b294
	if (ctx.cr6.lt) goto loc_8211B294;
	// lwz r10,120(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 120);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8211b294
	if (ctx.cr6.eq) goto loc_8211B294;
	// lwz r11,1028(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1028);
	// subf r11,r11,r27
	ctx.r11.u64 = ctx.r27.u64 - ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// subf r4,r11,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r11.u64;
	// blt cr6,0x8211b264
	if (ctx.cr6.lt) goto loc_8211B264;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8211B264:
	// lwz r11,412(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 412);
	// addi r3,r30,356
	ctx.r3.s64 = ctx.r30.s64 + 356;
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211b28c
	if (ctx.cr0.eq) goto loc_8211B28C;
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8211b294
	if (ctx.cr6.lt) goto loc_8211B294;
loc_8211B28C:
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x82122270
	ctx.lr = 0x8211B294;
	sub_82122270(ctx, base);
loc_8211B294:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
