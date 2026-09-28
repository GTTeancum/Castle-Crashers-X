DEFINE_REX_FUNC(sub_82121180) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cntlzw r9,r5
	ctx.r9.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// clrlwi r10,r6,16
	ctx.r10.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwinm r3,r9,10,16,16
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 10) & 0x8000;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// lhz r5,838(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 838);
	// xori r3,r3,32768
	ctx.r3.u64 = ctx.r3.u64 ^ 32768;
	// stw r8,828(r11)
	REX_STORE_U32(ctx.r11.u32 + 828, ctx.r8.u32);
	// stw r7,824(r11)
	REX_STORE_U32(ctx.r11.u32 + 824, ctx.r7.u32);
	// clrlwi r8,r5,17
	ctx.r8.u64 = ctx.r5.u32 & 0x7FFF;
	// subf r7,r10,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r10.u64;
	// sth r4,832(r11)
	REX_STORE_U16(ctx.r11.u32 + 832, ctx.r4.u16);
	// or r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 | ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// rldicr r3,r6,0,47
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u64, 0) & 0xFFFFFFFFFFFF0000;
	// sth r8,838(r11)
	REX_STORE_U16(ctx.r11.u32 + 838, ctx.r8.u16);
	// clrldi r4,r4,48
	ctx.r4.u64 = ctx.r4.u64 & 0xFFFF;
	// sth r5,834(r11)
	REX_STORE_U16(ctx.r11.u32 + 834, ctx.r5.u16);
	// clrlwi r7,r7,16
	ctx.r7.u64 = ctx.r7.u32 & 0xFFFF;
	// sth r5,836(r11)
	REX_STORE_U16(ctx.r11.u32 + 836, ctx.r5.u16);
	// or r8,r3,r4
	ctx.r8.u64 = ctx.r3.u64 | ctx.r4.u64;
	// cmplwi cr6,r7,32768
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 32768, ctx.xer);
	// bge cr6,0x821211f0
	if (!ctx.cr6.lt) goto loc_821211F0;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x821211e8
	if (!ctx.cr6.lt) goto loc_821211E8;
	// addis r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 65536;
loc_821211E8:
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// b 0x82121200
	goto loc_82121200;
loc_821211F0:
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82121200
	if (!ctx.cr6.gt) goto loc_82121200;
	// lis r10,-1
	ctx.r10.s64 = -65536;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
loc_82121200:
	// rldicr r10,r8,5,58
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u64, 5) & 0xFFFFFFFFFFFFFFE0;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// std r10,816(r11)
	REX_STORE_U64(ctx.r11.u32 + 816, ctx.r10.u64);
	// blr 
	return;
}
