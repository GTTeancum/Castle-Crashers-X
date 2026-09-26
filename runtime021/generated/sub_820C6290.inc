DEFINE_REX_FUNC(sub_820C6290) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x820C6298;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// clrlwi. r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r7,r11,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r11,14916(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 14916);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x820c6390
	if (ctx.cr0.eq) goto loc_820C6390;
	// bne cr6,0x820c62c4
	if (!ctx.cr6.eq) goto loc_820C62C4;
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// addi r11,r11,60
	ctx.r11.s64 = ctx.r11.s64 + 60;
loc_820C62C4:
	// add r10,r11,r6
	ctx.r10.u64 = ctx.r11.u64 + ctx.r6.u64;
	// lwz r9,14908(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 14908);
	// addi r11,r6,-1
	ctx.r11.s64 = ctx.r6.s64 + -1;
	// lwz r5,14920(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 14920);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// and r31,r8,r11
	ctx.r31.u64 = ctx.r8.u64 & ctx.r11.u64;
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + ctx.r31.u64;
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x820c632c
	if (ctx.cr6.gt) goto loc_820C632C;
	// lwz r10,13232(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 13232);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820c6324
	if (ctx.cr6.eq) goto loc_820C6324;
	// lwz r11,13236(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 13236);
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x820c631c
	if (ctx.cr6.eq) goto loc_820C631C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820c6324
	if (!ctx.cr6.eq) goto loc_820C6324;
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x820c6324
	if (!ctx.cr6.lt) goto loc_820C6324;
loc_820C631C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820c64b4
	goto loc_820C64B4;
loc_820C6324:
	// stw r4,14916(r3)
	REX_STORE_U32(ctx.r3.u32 + 14916, ctx.r4.u32);
	// b 0x820c6384
	goto loc_820C6384;
loc_820C632C:
	// lwz r9,14924(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 14924);
	// lwz r8,13232(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 13232);
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r31,r9,r11
	ctx.r31.u64 = ctx.r9.u64 & ctx.r11.u64;
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + ctx.r31.u64;
	// beq cr6,0x820c6370
	if (ctx.cr6.eq) goto loc_820C6370;
	// lwz r11,13236(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 13236);
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x820c631c
	if (ctx.cr6.eq) goto loc_820C631C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820c6370
	if (!ctx.cr6.eq) goto loc_820C6370;
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x820c631c
	if (ctx.cr6.lt) goto loc_820C631C;
loc_820C6370:
	// lwz r11,14928(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 14928);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820c631c
	if (ctx.cr6.gt) goto loc_820C631C;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// stw r4,14924(r3)
	REX_STORE_U32(ctx.r3.u32 + 14924, ctx.r4.u32);
loc_820C6384:
	// bl 0x820c5e50
	ctx.lr = 0x820C6388;
	sub_820C5E50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x820c64b4
	goto loc_820C64B4;
loc_820C6390:
	// bne cr6,0x820c639c
	if (!ctx.cr6.eq) goto loc_820C639C;
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_820C639C:
	// addi r11,r11,31
	ctx.r11.s64 = ctx.r11.s64 + 31;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// rlwinm r30,r11,0,0,26
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFE0;
	// bne cr6,0x820c63b0
	if (!ctx.cr6.eq) goto loc_820C63B0;
	// li r7,54
	ctx.r7.s64 = 54;
loc_820C63B0:
	// lwz r11,14912(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 14912);
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820c63c4
	if (!ctx.cr6.gt) goto loc_820C63C4;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
loc_820C63C4:
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,14908(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 14908);
	// add r31,r8,r30
	ctx.r31.u64 = ctx.r8.u64 + ctx.r30.u64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820c63dc
	if (!ctx.cr6.gt) goto loc_820C63DC;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_820C63DC:
	// subf r11,r30,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r30.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x820c63f4
	if (ctx.cr6.lt) goto loc_820C63F4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820C63F4:
	// lwz r10,14904(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 14904);
	// lwz r9,14924(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 14924);
	// lwz r6,14936(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 14936);
	// subf r5,r10,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r10.u64;
	// srawi r5,r5,2
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 2;
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r5,r6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// ble cr6,0x820c6418
	if (!ctx.cr6.gt) goto loc_820C6418;
	// li r11,1
	ctx.r11.s64 = 1;
loc_820C6418:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820c6448
	if (ctx.cr6.eq) goto loc_820C6448;
	// lwz r11,14920(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 14920);
	// addi r9,r9,31
	ctx.r9.s64 = ctx.r9.s64 + 31;
	// lbz r6,10942(r3)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r3.u32 + 10942);
	// stw r10,14924(r3)
	REX_STORE_U32(ctx.r3.u32 + 14924, ctx.r10.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r30,r9,0,0,26
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFE0;
	// ori r10,r6,4
	ctx.r10.u64 = ctx.r6.u64 | 4;
	// stw r11,14920(r3)
	REX_STORE_U32(ctx.r3.u32 + 14920, ctx.r11.u32);
	// add r31,r8,r30
	ctx.r31.u64 = ctx.r8.u64 + ctx.r30.u64;
	// stb r10,10942(r3)
	REX_STORE_U8(ctx.r3.u32 + 10942, ctx.r10.u8);
loc_820C6448:
	// lwz r8,13232(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 13232);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820c6494
	if (ctx.cr6.eq) goto loc_820C6494;
	// lwz r11,13236(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 13236);
	// lwz r10,14920(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 14920);
	// subf r9,r10,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmpwi cr6,r9,-1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, -1, ctx.xer);
	// beq cr6,0x820c6478
	if (ctx.cr6.eq) goto loc_820C6478;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x820c6494
	if (!ctx.cr6.eq) goto loc_820C6494;
	// cmplw cr6,r8,r31
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x820c6494
	if (!ctx.cr6.lt) goto loc_820C6494;
loc_820C6478:
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820c631c
	if (!ctx.cr6.eq) goto loc_820C631C;
	// subf r11,r30,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r30.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x820c631c
	if (ctx.cr6.lt) goto loc_820C631C;
loc_820C6494:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r5,14920(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 14920);
	// bl 0x820c5e50
	ctx.lr = 0x820C64A0;
	sub_820C5E50(ctx, base);
	// subf r11,r30,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r30.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_820C64B4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
