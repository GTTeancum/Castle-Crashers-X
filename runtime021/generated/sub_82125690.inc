DEFINE_REX_FUNC(sub_82125690) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821256ac
	if (!ctx.cr6.eq) goto loc_821256AC;
	// stw r5,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r5,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
loc_821256A4:
	// stw r5,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// blr 
	return;
loc_821256AC:
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821256f4
	if (ctx.cr6.eq) goto loc_821256F4;
	// lbz r9,21(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 21);
	// mulli r9,r9,24
	ctx.r9.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(24));
	// subf r9,r9,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r9.u64;
	// addi r9,r9,-48
	ctx.r9.s64 = ctx.r9.s64 + -48;
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x821256f4
	if (!ctx.cr6.eq) goto loc_821256F4;
	// lbz r9,21(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 21);
	// lbz r8,21(r5)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r5.u32 + 21);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x821256f4
	if (!ctx.cr6.gt) goto loc_821256F4;
	// subf r11,r10,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r10.u64;
	// li r9,24
	ctx.r9.s64 = 24;
	// divw r11,r11,r9
	ctx.r11.u64 = uint32_t((ctx.r9.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r11.s32 / ctx.r9.s32 : 0);
	// stb r11,20(r10)
	REX_STORE_U8(ctx.r10.u32 + 20, ctx.r11.u8);
	// b 0x821256a4
	goto loc_821256A4;
loc_821256F4:
	// stw r5,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// lhz r9,832(r4)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r4.u32 + 832);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lbz r8,21(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 21);
	// mulli r8,r8,24
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(24));
	// subf r8,r8,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r8.u64;
	// lhz r8,784(r8)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r8.u32 + 784);
	// subf r8,r9,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r9.u64;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplwi cr6,r8,32768
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 32768, ctx.xer);
	// blt cr6,0x8212572c
	if (ctx.cr6.lt) goto loc_8212572C;
	// stw r5,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
loc_82125724:
	// stw r5,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// blr 
	return;
loc_8212572C:
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
loc_82125730:
	// lbz r10,21(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// mulli r10,r10,24
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(24));
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// lhz r7,832(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 832);
	// subf r7,r9,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r9.u64;
	// clrlwi r7,r7,16
	ctx.r7.u64 = ctx.r7.u32 & 0xFFFF;
	// cmplwi cr6,r7,32768
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 32768, ctx.xer);
	// blt cr6,0x82125760
	if (ctx.cr6.lt) goto loc_82125760;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82125730
	goto loc_82125730;
loc_82125760:
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// bne cr6,0x8212581c
	if (!ctx.cr6.eq) goto loc_8212581C;
	// lbz r10,21(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// lbz r9,21(r5)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r5.u32 + 21);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x821257a8
	if (!ctx.cr6.lt) goto loc_821257A8;
loc_82125778:
	// lbz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 20);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x821257e8
	if (ctx.cr0.eq) goto loc_821257E8;
	// mulli r9,r10,24
	ctx.r9.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(24));
	// lbz r8,21(r5)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r5.u32 + 21);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r9,21(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82125778
	if (ctx.cr6.lt) goto loc_82125778;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821257fc
	if (!ctx.cr6.eq) goto loc_821257FC;
loc_821257A8:
	// subf r10,r5,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r5.u64;
	// li r9,24
	ctx.r9.s64 = 24;
	// li r8,0
	ctx.r8.s64 = 0;
	// divw r10,r10,r9
	ctx.r10.u64 = uint32_t((ctx.r9.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r10.s32 / ctx.r9.s32 : 0);
	// stb r10,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r10.u8);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821257d8
	if (!ctx.cr6.eq) goto loc_821257D8;
	// stw r5,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_821257D8:
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// b 0x82125724
	goto loc_82125724;
loc_821257E8:
	// subf r10,r11,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r11.u64;
	// li r9,24
	ctx.r9.s64 = 24;
	// divw r10,r10,r9
	ctx.r10.u64 = uint32_t((ctx.r9.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r10.s32 / ctx.r9.s32 : 0);
	// stb r10,20(r11)
	REX_STORE_U8(ctx.r11.u32 + 20, ctx.r10.u8);
	// blr 
	return;
loc_821257FC:
	// li r9,24
	ctx.r9.s64 = 24;
	// subf r8,r10,r5
	ctx.r8.u64 = ctx.r5.u64 - ctx.r10.u64;
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// divw r8,r8,r9
	ctx.r8.u64 = uint32_t((ctx.r9.s32 && !(ctx.r8.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r8.s32 / ctx.r9.s32 : 0);
	// divw r11,r11,r9
	ctx.r11.u64 = uint32_t((ctx.r9.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r11.s32 / ctx.r9.s32 : 0);
	// stb r8,20(r10)
	REX_STORE_U8(ctx.r10.u32 + 20, ctx.r8.u8);
	// stb r11,20(r5)
	REX_STORE_U8(ctx.r5.u32 + 20, ctx.r11.u8);
	// blr 
	return;
loc_8212581C:
	// stw r5,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}
