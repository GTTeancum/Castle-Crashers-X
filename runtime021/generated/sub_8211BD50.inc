DEFINE_REX_FUNC(sub_8211BD50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x8211BD58;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r31,r30,1016
	ctx.r31.s64 = ctx.r30.s64 + 1016;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,1016(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1016);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8211bd7c
	if (ctx.cr6.eq) goto loc_8211BD7C;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8211BD7C:
	// addi r11,r3,8
	ctx.r11.s64 = ctx.r3.s64 + 8;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8211bdc8
	if (ctx.cr6.eq) goto loc_8211BDC8;
	// lhz r10,838(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 838);
	// rlwinm. r10,r10,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8211c060
	if (!ctx.cr0.eq) goto loc_8211C060;
	// lhz r10,1044(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 1044);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,1044(r30)
	REX_STORE_U16(ctx.r30.u32 + 1044, ctx.r10.u16);
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
	// bl 0x821180d8
	ctx.lr = 0x8211BDC4;
	sub_821180D8(ctx, base);
	// b 0x8211c060
	goto loc_8211C060;
loc_8211BDC8:
	// lhz r29,832(r3)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r3.u32 + 832);
	// lbz r11,1148(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 1148);
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// clrlwi r27,r11,31
	ctx.r27.u64 = ctx.r11.u32 & 0x1;
loc_8211BDD8:
	// lhz r11,838(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 838);
	// rlwinm. r11,r11,0,0,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211bdec
	if (ctx.cr0.eq) goto loc_8211BDEC;
	// lhz r28,832(r3)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r3.u32 + 832);
	// li r27,1
	ctx.r27.s64 = 1;
loc_8211BDEC:
	// lhz r11,1044(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 1044);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,1044(r30)
	REX_STORE_U16(ctx.r30.u32 + 1044, ctx.r11.u16);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8211be24
	if (ctx.cr6.eq) goto loc_8211BE24;
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
loc_8211BE24:
	// bl 0x821180d8
	ctx.lr = 0x8211BE28;
	sub_821180D8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8211be58
	if (ctx.cr6.eq) goto loc_8211BE58;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x8211be44
	if (!ctx.cr6.eq) goto loc_8211BE44;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8211BE44:
	// lhz r10,828(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 828);
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8211bdd8
	if (ctx.cr0.eq) goto loc_8211BDD8;
	// b 0x8211be5c
	goto loc_8211BE5C;
loc_8211BE58:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8211BE5C:
	// lwz r6,1148(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1148);
	// rlwinm. r11,r6,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8211be70
	if (!ctx.cr0.eq) goto loc_8211BE70;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x8211c060
	if (ctx.cr6.eq) goto loc_8211C060;
loc_8211BE70:
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8211c060
	if (ctx.cr6.eq) goto loc_8211C060;
	// lhz r8,872(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 872);
	// subf r11,r29,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r29.u64;
	// extsh. r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8211bec8
	if (!ctx.cr0.gt) goto loc_8211BEC8;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8211bec0
	if (ctx.cr6.lt) goto loc_8211BEC0;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8211beb0
	if (!ctx.cr6.lt) goto loc_8211BEB0;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// b 0x8211bebc
	goto loc_8211BEBC;
loc_8211BEB0:
	// addi r11,r11,-72
	ctx.r11.s64 = ctx.r11.s64 + -72;
	// srawi r11,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 5;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
loc_8211BEBC:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
loc_8211BEC0:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x8211becc
	goto loc_8211BECC;
loc_8211BEC8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8211BECC:
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8211bf24
	if (ctx.cr6.eq) goto loc_8211BF24;
	// lhz r11,832(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 832);
	// subf r11,r11,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r11.u64;
	// extsh. r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8211bf24
	if (!ctx.cr0.gt) goto loc_8211BF24;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8211bf20
	if (ctx.cr6.lt) goto loc_8211BF20;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8211bf10
	if (!ctx.cr6.lt) goto loc_8211BF10;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// b 0x8211bf1c
	goto loc_8211BF1C;
loc_8211BF10:
	// addi r11,r11,-72
	ctx.r11.s64 = ctx.r11.s64 + -72;
	// srawi r11,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 5;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
loc_8211BF1C:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
loc_8211BF20:
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_8211BF24:
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8211bf44
	if (!ctx.cr6.eq) goto loc_8211BF44;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x8211c060
	if (ctx.cr6.eq) goto loc_8211C060;
	// oris r11,r6,256
	ctx.r11.u64 = ctx.r6.u64 | 16777216;
	// b 0x8211c014
	goto loc_8211C014;
loc_8211BF44:
	// li r31,-1
	ctx.r31.s64 = -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8211bf80
	if (ctx.cr6.lt) goto loc_8211BF80;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// bge cr6,0x8211bf70
	if (!ctx.cr6.lt) goto loc_8211BF70;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,15
	ctx.r11.s64 = ctx.r11.s64 + 15;
	// b 0x8211bf7c
	goto loc_8211BF7C;
loc_8211BF70:
	// addi r11,r11,-16
	ctx.r11.s64 = ctx.r11.s64 + -16;
	// rlwinm r11,r11,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r11,r11,103
	ctx.r11.s64 = ctx.r11.s64 + 103;
loc_8211BF7C:
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
loc_8211BF80:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x8211bfbc
	if (ctx.cr6.eq) goto loc_8211BFBC;
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r31,104(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 104);
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// clrlwi r10,r28,16
	ctx.r10.u64 = ctx.r28.u32 & 0xFFFF;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// oris r11,r6,256
	ctx.r11.u64 = ctx.r6.u64 | 16777216;
	// blt cr6,0x8211bfb8
	if (ctx.cr6.lt) goto loc_8211BFB8;
	// rlwinm r11,r6,0,8,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFEFFFFFF;
loc_8211BFB8:
	// stw r11,1148(r30)
	REX_STORE_U32(ctx.r30.u32 + 1148, ctx.r11.u32);
loc_8211BFBC:
	// lwz r8,1148(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1148);
	// rlwinm. r11,r8,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211c000
	if (ctx.cr0.eq) goto loc_8211C000;
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// lhz r11,874(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 874);
	// lhz r9,872(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 872);
	// lhz r6,1040(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 1040);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x8211c000
	if (!ctx.cr6.lt) goto loc_8211C000;
	// lwz r11,116(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 116);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8211bffc
	if (!ctx.cr6.gt) goto loc_8211BFFC;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_8211BFFC:
	// li r7,1
	ctx.r7.s64 = 1;
loc_8211C000:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8211c060
	if (ctx.cr6.eq) goto loc_8211C060;
	// rlwinm. r11,r8,0,8,8
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x800000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211c01c
	if (ctx.cr0.eq) goto loc_8211C01C;
	// oris r11,r8,32
	ctx.r11.u64 = ctx.r8.u64 | 2097152;
loc_8211C014:
	// stw r11,1148(r30)
	REX_STORE_U32(ctx.r30.u32 + 1148, ctx.r11.u32);
	// b 0x8211c060
	goto loc_8211C060;
loc_8211C01C:
	// oris r11,r8,64
	ctx.r11.u64 = ctx.r8.u64 | 4194304;
	// stw r11,1148(r30)
	REX_STORE_U32(ctx.r30.u32 + 1148, ctx.r11.u32);
	// bl 0x82136f58
	ctx.lr = 0x8211C028;
	sub_82136F58(ctx, base);
	// lwz r10,412(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 412);
	// addi r11,r30,356
	ctx.r11.s64 = ctx.r30.s64 + 356;
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// beq 0x8211c054
	if (ctx.cr0.eq) goto loc_8211C054;
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// subf r10,r10,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r10.u64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8211c060
	if (ctx.cr6.lt) goto loc_8211C060;
loc_8211C054:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82122270
	ctx.lr = 0x8211C060;
	sub_82122270(ctx, base);
loc_8211C060:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
