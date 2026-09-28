DEFINE_REX_FUNC(sub_8209C388) {
	REX_FUNC_PROLOGUE();
	// lis r5,-32234
	ctx.r5.s64 = -2112487424;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// addi r11,r11,27136
	ctx.r11.s64 = ctx.r11.s64 + 27136;
	// lwz r9,-23776(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + -23776);
	// cmpwi cr6,r9,624
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 624, ctx.xer);
	// blt cr6,0x8209c488
	if (ctx.cr6.lt) goto loc_8209C488;
	// cmpwi cr6,r9,625
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 625, ctx.xer);
	// bne cr6,0x8209c3d8
	if (!ctx.cr6.eq) goto loc_8209C3D8;
	// li r9,4357
	ctx.r9.s64 = 4357;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r9,r9,3533
	ctx.r9.u64 = ctx.r9.u64 | 3533;
loc_8209C3BC:
	// lwz r8,-4(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + -4);
	// addi r7,r11,2496
	ctx.r7.s64 = ctx.r11.s64 + 2496;
	// mullw r6,r8,r9
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r6,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8209c3bc
	if (ctx.cr6.lt) goto loc_8209C3BC;
loc_8209C3D8:
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// addi r8,r9,832
	ctx.r8.s64 = ctx.r9.s64 + 832;
loc_8209C3E4:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r11,908
	ctx.r7.s64 = ctx.r11.s64 + 908;
	// lwz r6,4(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,1588(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 1588);
	// rlwimi r6,r9,0,0,0
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000) | (ctx.r6.u64 & 0xFFFFFFFF7FFFFFFF);
	// rlwinm r3,r6,2,29,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x4;
	// rlwinm r9,r6,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// lwzx r6,r3,r8
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// xor r3,r6,r9
	ctx.r3.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// xor r9,r3,r4
	ctx.r9.u64 = ctx.r3.u64 ^ ctx.r4.u64;
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8209c3e4
	if (ctx.cr6.lt) goto loc_8209C3E4;
	// addi r10,r11,908
	ctx.r10.s64 = ctx.r11.s64 + 908;
loc_8209C420:
	// lwz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// lwz r6,4(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// addi r4,r11,2492
	ctx.r4.s64 = ctx.r11.s64 + 2492;
	// lwz r3,-908(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -908);
	// rlwimi r7,r6,0,1,31
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x7FFFFFFF) | (ctx.r7.u64 & 0xFFFFFFFF80000000);
	// cmpw cr6,r9,r4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, ctx.xer);
	// rlwinm r6,r7,2,29,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x4;
	// rlwinm r4,r7,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// lwzx r7,r6,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// xor r6,r7,r3
	ctx.r6.u64 = ctx.r7.u64 ^ ctx.r3.u64;
	// xor r4,r6,r4
	ctx.r4.u64 = ctx.r6.u64 ^ ctx.r4.u64;
	// stw r4,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// blt cr6,0x8209c420
	if (ctx.cr6.lt) goto loc_8209C420;
	// lwz r7,2492(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 2492);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r6,1584(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 1584);
	// rlwimi r10,r7,0,0,0
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80000000) | (ctx.r10.u64 & 0xFFFFFFFF7FFFFFFF);
	// rlwinm r7,r10,2,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x4;
	// rlwinm r4,r10,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// lwzx r3,r7,r8
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// xor r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r4.u64;
	// xor r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r6.u64;
	// stw r10,2492(r11)
	REX_STORE_U32(ctx.r11.u32 + 2492, ctx.r10.u32);
loc_8209C488:
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// lis r12,-25300
	ctx.r12.s64 = -1658060800;
	// stw r10,-23776(r5)
	REX_STORE_U32(ctx.r5.u32 + -23776, ctx.r10.u32);
	// ori r12,r12,22271
	ctx.r12.u64 = ctx.r12.u64 | 22271;
	// lwzx r7,r8,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// rlwinm r6,r7,21,11,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 21) & 0x1FFFFF;
	// xor r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// rlwinm r4,r5,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// and r4,r4,r12
	ctx.r4.u64 = ctx.r4.u64 & ctx.r12.u64;
	// xor r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// rlwinm r11,r3,15,0,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 15) & 0xFFFE0000;
	// rlwinm r11,r11,0,13,9
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFC7FFFF;
	// rlwinm r11,r11,0,4,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// xor r10,r11,r3
	ctx.r10.u64 = ctx.r11.u64 ^ ctx.r3.u64;
	// rlwinm r9,r10,14,18,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 14) & 0x3FFF;
	// xor r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// blr 
	return;
}
