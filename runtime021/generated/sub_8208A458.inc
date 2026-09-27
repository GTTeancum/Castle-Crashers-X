DEFINE_REX_FUNC(sub_8208A458) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8208A460;
	__savegprlr_28(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
loc_8208A464:
	// add r11,r10,r4
	ctx.r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// lbzx r9,r10,r4
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// rotlwi r8,r9,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r7,1(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r6,2(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// or r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 | ctx.r7.u64;
	// lbz r11,3(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// rlwinm r9,r5,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r6
	ctx.r8.u64 = ctx.r9.u64 | ctx.r6.u64;
	// rlwinm r7,r8,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// or r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 | ctx.r11.u64;
	// stw r6,-48(r1)
	REX_STORE_U32(ctx.r1.u32 + -48, ctx.r6.u32);
	// lbz r5,-48(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -48);
	// lbz r6,-45(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + -45);
	// lbz r7,-46(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -46);
	// lbz r11,-47(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + -47);
	// xor r8,r11,r7
	ctx.r8.u64 = ctx.r11.u64 ^ ctx.r7.u64;
	// xor r9,r5,r6
	ctx.r9.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// xor r9,r8,r7
	ctx.r9.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// xor r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r11,r6,24
	ctx.r11.u64 = ctx.r6.u32 & 0xFF;
	// xor r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// stb r9,-46(r1)
	REX_STORE_U8(ctx.r1.u32 + -46, ctx.r9.u8);
	// xor r7,r11,r5
	ctx.r7.u64 = ctx.r11.u64 ^ ctx.r5.u64;
	// stb r11,-45(r1)
	REX_STORE_U8(ctx.r1.u32 + -45, ctx.r11.u8);
	// stb r6,-47(r1)
	REX_STORE_U8(ctx.r1.u32 + -47, ctx.r6.u8);
	// stb r7,-48(r1)
	REX_STORE_U8(ctx.r1.u32 + -48, ctx.r7.u8);
	// lwz r11,-48(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// rlwimi r9,r11,2,0,29
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC) | (ctx.r9.u64 & 0xFFFFFFFF00000003);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// rlwinm r7,r11,0,28,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// rlwimi r8,r9,2,0,28
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFF8) | (ctx.r8.u64 & 0xFFFFFFFF00000007);
	// rlwinm r6,r11,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// rlwinm r8,r8,2,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFF0;
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// rlwinm r5,r11,0,25,25
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r11,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	// or r6,r8,r6
	ctx.r6.u64 = ctx.r8.u64 | ctx.r6.u64;
	// rlwinm r31,r11,0,23,23
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r11,0,22,22
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// or r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 | ctx.r9.u64;
	// rlwinm r30,r11,0,21,21
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r11,0,20,20
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// or r5,r9,r5
	ctx.r5.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwinm r29,r11,0,19,19
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r11,0,18,18
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	// or r7,r5,r7
	ctx.r7.u64 = ctx.r5.u64 | ctx.r7.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r11,0,17,17
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	// or r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 | ctx.r31.u64;
	// rlwimi r9,r11,30,16,16
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x8000) | (ctx.r9.u64 & 0xFFFFFFFFFFFF7FFF);
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	// or r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r9,r9,31,16,17
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0xC000;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// or r8,r5,r30
	ctx.r8.u64 = ctx.r5.u64 | ctx.r30.u64;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// or r8,r5,r6
	ctx.r8.u64 = ctx.r5.u64 | ctx.r6.u64;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// or r5,r6,r29
	ctx.r5.u64 = ctx.r6.u64 | ctx.r29.u64;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// or r6,r8,r28
	ctx.r6.u64 = ctx.r8.u64 | ctx.r28.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// or r8,r5,r7
	ctx.r8.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// or r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 | ctx.r11.u64;
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// or r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 | ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8208a67c
	if (ctx.cr6.eq) goto loc_8208A67C;
	// add r11,r10,r4
	ctx.r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// lbzx r8,r10,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// rlwinm r7,r9,0,0,0
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000;
	// rotlwi r6,r8,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lbz r5,1(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// or r7,r6,r5
	ctx.r7.u64 = ctx.r6.u64 | ctx.r5.u64;
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// rlwinm r5,r7,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r5,r8
	ctx.r11.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r8,r11,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r8,r6
	ctx.r7.u64 = ctx.r8.u64 | ctx.r6.u64;
	// stw r7,-48(r1)
	REX_STORE_U32(ctx.r1.u32 + -48, ctx.r7.u32);
	// lbz r7,-46(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + -46);
	// lbz r5,-45(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + -45);
	// lbz r8,-48(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + -48);
	// xor r6,r8,r5
	ctx.r6.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// lbz r11,-47(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + -47);
	// clrlwi r6,r6,24
	ctx.r6.u64 = ctx.r6.u32 & 0xFF;
	// xor r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 ^ ctx.r7.u64;
	// xor r5,r6,r5
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r5.u64;
	// clrlwi r31,r11,24
	ctx.r31.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// xor r8,r31,r7
	ctx.r8.u64 = ctx.r31.u64 ^ ctx.r7.u64;
	// xor r7,r11,r6
	ctx.r7.u64 = ctx.r11.u64 ^ ctx.r6.u64;
	// stb r11,-45(r1)
	REX_STORE_U8(ctx.r1.u32 + -45, ctx.r11.u8);
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// stb r7,-48(r1)
	REX_STORE_U8(ctx.r1.u32 + -48, ctx.r7.u8);
	// xor r6,r8,r31
	ctx.r6.u64 = ctx.r8.u64 ^ ctx.r31.u64;
	// stb r8,-46(r1)
	REX_STORE_U8(ctx.r1.u32 + -46, ctx.r8.u8);
	// stb r6,-47(r1)
	REX_STORE_U8(ctx.r1.u32 + -47, ctx.r6.u8);
	// beq cr6,0x8208a64c
	if (ctx.cr6.eq) goto loc_8208A64C;
	// lwz r7,176(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 176);
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r3,160
	ctx.r11.s64 = ctx.r3.s64 + 160;
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8208a64c
	if (ctx.cr6.eq) goto loc_8208A64C;
	// stw r8,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
loc_8208A64C:
	// rlwinm r11,r9,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40000000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208a670
	if (ctx.cr6.eq) goto loc_8208A670;
	// lwz r8,180(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 180);
	// add r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r3,160
	ctx.r11.s64 = ctx.r3.s64 + 160;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8208a670
	if (ctx.cr6.eq) goto loc_8208A670;
	// stw r9,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
loc_8208A670:
	// lwz r11,-48(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -48);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8208a464
	goto loc_8208A464;
loc_8208A67C:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
