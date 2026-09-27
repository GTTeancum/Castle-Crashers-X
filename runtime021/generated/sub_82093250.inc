DEFINE_REX_FUNC(sub_82093250) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x82093258;
	__savegprlr_25(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lbz r11,10345(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 10345);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820935a0
	if (!ctx.cr6.eq) goto loc_820935A0;
	// lbz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// addi r26,r28,80
	ctx.r26.s64 = ctx.r28.s64 + 80;
	// lbz r10,1(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 1);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lwz r8,96(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 96);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r29,r6,24,24,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// rlwimi r29,r6,8,16,23
	ctx.r29.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF00) | (ctx.r29.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r10,r29,16
	ctx.r10.u64 = ctx.r29.u32 & 0xFFFF;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x820932e4
	if (ctx.cr6.gt) goto loc_820932E4;
	// lwz r11,4(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820932c4
	if (ctx.cr6.eq) goto loc_820932C4;
	// lwz r9,8(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// subf r8,r11,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r11.u64;
	// srawi r9,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x820932c8
	if (ctx.cr6.lt) goto loc_820932C8;
loc_820932C4:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_820932C8:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820932e4
	if (ctx.cr6.eq) goto loc_820932E4;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
loc_820932E4:
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r3,-6648(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6648);
	// bl 0x8208fd90
	ctx.lr = 0x820932F0;
	sub_8208FD90(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82066ea8
	ctx.lr = 0x820932FC;
	sub_82066EA8(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// sth r29,80(r30)
	REX_STORE_U16(ctx.r30.u32 + 80, ctx.r29.u16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r9,64(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82093318;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 2;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r28,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// stw r28,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// bl 0x82093848
	ctx.lr = 0x82093338;
	sub_82093848(ctx, base);
	// addi r27,r3,2
	ctx.r27.s64 = ctx.r3.s64 + 2;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82094768
	ctx.lr = 0x82093348;
	sub_82094768(ctx, base);
	// add r11,r27,r31
	ctx.r11.u64 = ctx.r27.u64 + ctx.r31.u64;
	// lbzx r8,r27,r31
	ctx.r8.u64 = REX_LOAD_U8(ctx.r27.u32 + ctx.r31.u32);
	// addi r29,r27,2
	ctx.r29.s64 = ctx.r27.s64 + 2;
	// rotlwi r6,r8,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// lbz r7,1(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// or r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 | ctx.r7.u64;
	// clrlwi r27,r5,16
	ctx.r27.u64 = ctx.r5.u32 & 0xFFFF;
	// rlwinm r4,r27,0,23,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820933d4
	if (ctx.cr6.eq) goto loc_820933D4;
	// add r11,r29,r31
	ctx.r11.u64 = ctx.r29.u64 + ctx.r31.u64;
	// lbzx r10,r29,r31
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + ctx.r31.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// rotlwi r9,r10,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// addi r7,r29,2
	ctx.r7.s64 = ctx.r29.s64 + 2;
	// lbz r8,1(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// clrlwi r5,r6,16
	ctx.r5.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwinm r4,r5,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFF;
	// rlwimi r4,r5,8,16,23
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// bl 0x82084570
	ctx.lr = 0x820933A0;
	sub_82084570(ctx, base);
	// clrlwi r5,r6,16
	ctx.r5.u64 = ctx.r6.u32 & 0xFFFF;
	// stw r3,136(r30)
	REX_STORE_U32(ctx.r30.u32 + 136, ctx.r3.u32);
	// add r11,r7,r31
	ctx.r11.u64 = ctx.r7.u64 + ctx.r31.u64;
	// stw r5,92(r30)
	REX_STORE_U32(ctx.r30.u32 + 92, ctx.r5.u32);
	// addi r29,r7,2
	ctx.r29.s64 = ctx.r7.s64 + 2;
	// lbzx r4,r7,r31
	ctx.r4.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r31.u32);
	// rotlwi r3,r4,8
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r4.u32, 8);
	// lbz r11,1(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// or r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 | ctx.r11.u64;
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwinm r8,r9,24,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// rlwimi r8,r9,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// sth r8,96(r30)
	REX_STORE_U16(ctx.r30.u32 + 96, ctx.r8.u16);
loc_820933D4:
	// rlwinm r11,r27,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209346c
	if (ctx.cr6.eq) goto loc_8209346C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r28,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r28,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// addi r9,r11,-7056
	ctx.r9.s64 = ctx.r11.s64 + -7056;
	// stw r28,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r28.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// add r3,r29,r31
	ctx.r3.u64 = ctx.r29.u64 + ctx.r31.u64;
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stb r28,116(r1)
	REX_STORE_U8(ctx.r1.u32 + 116, ctx.r28.u8);
	// sth r28,120(r1)
	REX_STORE_U16(ctx.r1.u32 + 120, ctx.r28.u16);
	// sth r28,138(r1)
	REX_STORE_U16(ctx.r1.u32 + 138, ctx.r28.u16);
	// sth r28,134(r1)
	REX_STORE_U16(ctx.r1.u32 + 134, ctx.r28.u16);
	// sth r28,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r28.u16);
	// sth r28,130(r1)
	REX_STORE_U16(ctx.r1.u32 + 130, ctx.r28.u16);
	// stw r28,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r28.u32);
	// bl 0x8208be40
	ctx.lr = 0x82093428;
	sub_8208BE40(ctx, base);
	// rlwinm r8,r3,16,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFF;
	// rlwinm r7,r3,24,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFF;
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// sth r8,128(r1)
	REX_STORE_U16(ctx.r1.u32 + 128, ctx.r8.u16);
	// rlwinm r5,r3,8,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFF;
	// sth r7,126(r1)
	REX_STORE_U16(ctx.r1.u32 + 126, ctx.r7.u16);
	// sth r6,124(r1)
	REX_STORE_U16(ctx.r1.u32 + 124, ctx.r6.u16);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// sth r5,136(r1)
	REX_STORE_U16(ctx.r1.u32 + 136, ctx.r5.u16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bl 0x820837c0
	ctx.lr = 0x82093458;
	sub_820837C0(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r11,r4,-7008
	ctx.r11.s64 = ctx.r4.s64 + -7008;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// bl 0x82079970
	ctx.lr = 0x8209346C;
	sub_82079970(ctx, base);
loc_8209346C:
	// rlwinm r11,r27,0,22,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209347c
	if (ctx.cr6.eq) goto loc_8209347C;
	// addi r29,r29,2
	ctx.r29.s64 = ctx.r29.s64 + 2;
loc_8209347C:
	// rlwinm r11,r27,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82093558
	if (ctx.cr6.eq) goto loc_82093558;
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// lbzx r9,r29,r31
	ctx.r9.u64 = REX_LOAD_U8(ctx.r29.u32 + ctx.r31.u32);
	// addi r6,r30,124
	ctx.r6.s64 = ctx.r30.s64 + 124;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lbzx r5,r11,r31
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stb r9,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r9.u8);
	// li r9,5
	ctx.r9.s64 = 5;
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r4,1(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// rotlwi r3,r5,8
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// lbzx r5,r11,r31
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// or r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 | ctx.r3.u64;
	// lbz r3,1(r8)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r8.u32 + 1);
	// rotlwi r8,r5,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// clrlwi r5,r4,16
	ctx.r5.u64 = ctx.r4.u32 & 0xFFFF;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbzx r4,r11,r31
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// or r3,r8,r3
	ctx.r3.u64 = ctx.r8.u64 | ctx.r3.u64;
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rotlwi r4,r4,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r4.u32, 8);
	// lbz r10,1(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// lbzx r29,r11,r31
	ctx.r29.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// or r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 | ctx.r4.u64;
	// lbz r8,1(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 1);
	// rotlwi r29,r29,8
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r29.u32, 8);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// or r8,r29,r8
	ctx.r8.u64 = ctx.r29.u64 | ctx.r8.u64;
	// rlwinm r29,r3,24,24,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFF;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwinm r4,r5,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFF;
	// rlwinm r28,r10,24,24,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// rlwinm r25,r8,24,24,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF;
	// rlwimi r29,r3,8,16,23
	ctx.r29.u64 = (__builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFF00) | (ctx.r29.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwimi r4,r5,8,16,23
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwimi r28,r10,8,16,23
	ctx.r28.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF00) | (ctx.r28.u64 & 0xFFFFFFFFFFFF00FF);
	// sth r29,84(r1)
	REX_STORE_U16(ctx.r1.u32 + 84, ctx.r29.u16);
	// rlwimi r25,r8,8,16,23
	ctx.r25.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF00) | (ctx.r25.u64 & 0xFFFFFFFFFFFF00FF);
	// sth r4,82(r1)
	REX_STORE_U16(ctx.r1.u32 + 82, ctx.r4.u16);
	// sth r28,86(r1)
	REX_STORE_U16(ctx.r1.u32 + 86, ctx.r28.u16);
	// addi r29,r11,2
	ctx.r29.s64 = ctx.r11.s64 + 2;
	// sth r25,88(r1)
	REX_STORE_U16(ctx.r1.u32 + 88, ctx.r25.u16);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82093544:
	// lhz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r7.u32 + 0);
	// addi r7,r7,2
	ctx.r7.s64 = ctx.r7.s64 + 2;
	// sth r11,0(r6)
	REX_STORE_U16(ctx.r6.u32 + 0, ctx.r11.u16);
	// addi r6,r6,2
	ctx.r6.s64 = ctx.r6.s64 + 2;
	// bdnz 0x82093544
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82093544;
loc_82093558:
	// add r4,r29,r31
	ctx.r4.u64 = ctx.r29.u64 + ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820953c0
	ctx.lr = 0x82093564;
	sub_820953C0(ctx, base);
	// rlwinm r11,r27,0,0,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82093588
	if (ctx.cr6.eq) goto loc_82093588;
	// add r11,r3,r29
	ctx.r11.u64 = ctx.r3.u64 + ctx.r29.u64;
	// rlwinm r5,r27,31,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 31) & 0x1;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x82094858
	ctx.lr = 0x82093588;
	sub_82094858(ctx, base);
loc_82093588:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82084448
	ctx.lr = 0x82093594;
	sub_82084448(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82066ea8
	ctx.lr = 0x820935A0;
	sub_82066EA8(ctx, base);
loc_820935A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
