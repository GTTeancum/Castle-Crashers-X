DEFINE_REX_FUNC(sub_820AE450) {
	REX_FUNC_PROLOGUE();
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r11,r5,725
	ctx.r11.s64 = ctx.r5.s64 + 725;
	// lwz r10,5192(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 5192);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// lwzx r31,r9,r3
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// bgt cr6,0x820ae528
	if (ctx.cr6.gt) goto loc_820AE528;
	// rlwinm r6,r31,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
loc_820AE478:
	// bge cr6,0x820ae4cc
	if (!ctx.cr6.lt) goto loc_820AE4CC;
	// addi r10,r11,726
	ctx.r10.s64 = ctx.r11.s64 + 726;
	// addi r9,r11,725
	ctx.r9.s64 = ctx.r11.s64 + 725;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r8,r3
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// lwzx r7,r7,r3
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r10,r10,r4
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r4.u32);
	// lhzx r9,r9,r4
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r4.u32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x820ae4c8
	if (ctx.cr6.lt) goto loc_820AE4C8;
	// bne cr6,0x820ae4cc
	if (!ctx.cr6.eq) goto loc_820AE4CC;
	// add r10,r7,r3
	ctx.r10.u64 = ctx.r7.u64 + ctx.r3.u64;
	// add r9,r8,r3
	ctx.r9.u64 = ctx.r8.u64 + ctx.r3.u64;
	// lbz r8,5200(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 5200);
	// lbz r7,5200(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 5200);
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x820ae4cc
	if (ctx.cr6.gt) goto loc_820AE4CC;
loc_820AE4C8:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_820AE4CC:
	// addi r10,r11,725
	ctx.r10.s64 = ctx.r11.s64 + 725;
	// lhzx r9,r6,r4
	ctx.r9.u64 = REX_LOAD_U16(ctx.r6.u32 + ctx.r4.u32);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r3
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r8,r7,r4
	ctx.r8.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r4.u32);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x820ae528
	if (ctx.cr6.lt) goto loc_820AE528;
	// bne cr6,0x820ae508
	if (!ctx.cr6.eq) goto loc_820AE508;
	// add r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 + ctx.r3.u64;
	// add r8,r31,r3
	ctx.r8.u64 = ctx.r31.u64 + ctx.r3.u64;
	// lbz r7,5200(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 5200);
	// lbz r9,5200(r8)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r8.u32 + 5200);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x820ae528
	if (!ctx.cr6.gt) goto loc_820AE528;
loc_820AE508:
	// addi r9,r5,725
	ctx.r9.s64 = ctx.r5.s64 + 725;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stwx r10,r8,r3
	REX_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r10.u32);
	// lwz r10,5192(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 5192);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x820ae478
	if (!ctx.cr6.gt) goto loc_820AE478;
loc_820AE528:
	// addi r11,r5,725
	ctx.r11.s64 = ctx.r5.s64 + 725;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r31,r10,r3
	REX_STORE_U32(ctx.r10.u32 + ctx.r3.u32, ctx.r31.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}
