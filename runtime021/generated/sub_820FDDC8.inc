DEFINE_REX_FUNC(sub_820FDDC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820FDDD0;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// rlwinm. r11,r26,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// std r25,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r25.u64);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq 0x820fdf48
	if (ctx.cr0.eq) goto loc_820FDF48;
	// bne cr6,0x820fdeb4
	if (!ctx.cr6.eq) goto loc_820FDEB4;
	// lwz r11,248(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 248);
	// addi r29,r28,248
	ctx.r29.s64 = ctx.r28.s64 + 248;
	// b 0x820fde58
	goto loc_820FDE58;
loc_820FDE08:
	// lwz r11,304(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 304);
	// addi r5,r30,-92
	ctx.r5.s64 = ctx.r30.s64 + -92;
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820fde54
	if (!ctx.cr0.eq) goto loc_820FDE54;
	// lwz r11,84(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820fde54
	if (!ctx.cr6.eq) goto loc_820FDE54;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820fddc8
	ctx.lr = 0x820FDE3C;
	sub_820FDDC8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820fe334
	if (ctx.cr0.lt) goto loc_820FE334;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_820FDE54:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_820FDE58:
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820fde6c
	if (ctx.cr6.eq) goto loc_820FDE6C;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// bne 0x820fde08
	if (!ctx.cr0.eq) goto loc_820FDE08;
loc_820FDE6C:
	// clrlwi. r11,r26,31
	ctx.r11.u64 = ctx.r26.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fde90
	if (ctx.cr0.eq) goto loc_820FDE90;
	// rlwinm. r11,r26,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// beq 0x820fde88
	if (ctx.cr0.eq) goto loc_820FDE88;
	// lwz r10,716(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 716);
	// b 0x820fdea8
	goto loc_820FDEA8;
loc_820FDE88:
	// lwz r10,712(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 712);
	// b 0x820fdea8
	goto loc_820FDEA8;
loc_820FDE90:
	// rlwinm. r11,r26,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// beq 0x820fdea4
	if (ctx.cr0.eq) goto loc_820FDEA4;
	// ld r10,656(r28)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r28.u32 + 656);
	// b 0x820fdea8
	goto loc_820FDEA8;
loc_820FDEA4:
	// ld r10,648(r28)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r28.u32 + 648);
loc_820FDEA8:
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_820FDEAC:
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// b 0x820fe330
	goto loc_820FE330;
loc_820FDEB4:
	// lwz r3,400(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 400);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fe330
	if (ctx.cr6.eq) goto loc_820FE330;
	// lwz r11,396(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 396);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820fe330
	if (!ctx.cr0.eq) goto loc_820FE330;
	// clrlwi. r11,r26,31
	ctx.r11.u64 = ctx.r26.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r6,8192
	ctx.r6.s64 = 536870912;
	// beq 0x820fdf14
	if (ctx.cr0.eq) goto loc_820FDF14;
	// rlwinm. r11,r26,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fdee8
	if (ctx.cr0.eq) goto loc_820FDEE8;
	// ori r6,r6,6
	ctx.r6.u64 = ctx.r6.u64 | 6;
	// b 0x820fdeec
	goto loc_820FDEEC;
loc_820FDEE8:
	// ori r6,r6,2
	ctx.r6.u64 = ctx.r6.u64 | 2;
loc_820FDEEC:
	// stw r25,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82108ea0
	ctx.lr = 0x820FDF04;
	sub_82108EA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820fe334
	if (ctx.cr0.lt) goto loc_820FE334;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x820fdeac
	goto loc_820FDEAC;
loc_820FDF14:
	// rlwinm. r11,r26,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fdf24
	if (ctx.cr0.eq) goto loc_820FDF24;
	// ori r6,r6,7
	ctx.r6.u64 = ctx.r6.u64 | 7;
	// b 0x820fdf28
	goto loc_820FDF28;
loc_820FDF24:
	// ori r6,r6,3
	ctx.r6.u64 = ctx.r6.u64 | 3;
loc_820FDF28:
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// li r8,8
	ctx.r8.s64 = 8;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82108ea0
	ctx.lr = 0x820FDF3C;
	sub_82108EA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820fe334
	if (ctx.cr0.lt) goto loc_820FE334;
	// b 0x820fe330
	goto loc_820FE330;
loc_820FDF48:
	// bne cr6,0x820fe104
	if (!ctx.cr6.eq) goto loc_820FE104;
	// lwz r11,248(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 248);
	// addi r30,r28,248
	ctx.r30.s64 = ctx.r28.s64 + 248;
	// ori r26,r26,8
	ctx.r26.u64 = ctx.r26.u64 | 8;
	// b 0x820fdfa0
	goto loc_820FDFA0;
loc_820FDF5C:
	// lwz r11,-8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -8);
	// addi r5,r29,-92
	ctx.r5.s64 = ctx.r29.s64 + -92;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820fdf9c
	if (!ctx.cr6.eq) goto loc_820FDF9C;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820fddc8
	ctx.lr = 0x820FDF84;
	sub_820FDDC8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x820fe334
	if (ctx.cr0.lt) goto loc_820FE334;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_820FDF9C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
loc_820FDFA0:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820fdfb4
	if (ctx.cr6.eq) goto loc_820FDFB4;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// bne 0x820fdf5c
	if (!ctx.cr0.eq) goto loc_820FDF5C;
loc_820FDFB4:
	// rlwinm. r11,r26,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fe074
	if (ctx.cr0.eq) goto loc_820FE074;
	// clrlwi. r8,r26,31
	ctx.r8.u64 = ctx.r26.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x820fdfe4
	if (ctx.cr0.eq) goto loc_820FDFE4;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// rlwinm. r9,r26,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fdfdc
	if (ctx.cr0.eq) goto loc_820FDFDC;
	// lwz r10,700(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 700);
loc_820FDFD4:
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x820fe004
	goto loc_820FE004;
loc_820FDFDC:
	// lwz r10,696(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 696);
	// b 0x820fdfd4
	goto loc_820FDFD4;
loc_820FDFE4:
	// rlwinm. r9,r26,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fdff8
	if (ctx.cr0.eq) goto loc_820FDFF8;
	// ld r10,624(r28)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r28.u32 + 624);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// b 0x820fdfd4
	goto loc_820FDFD4;
loc_820FDFF8:
	// ld r11,616(r28)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r28.u32 + 616);
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_820FE004:
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// beq cr6,0x820fe02c
	if (ctx.cr6.eq) goto loc_820FE02C;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820fe024
	if (ctx.cr6.eq) goto loc_820FE024;
	// lwz r11,708(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 708);
	// b 0x820fe040
	goto loc_820FE040;
loc_820FE024:
	// lwz r11,704(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 704);
	// b 0x820fe040
	goto loc_820FE040;
loc_820FE02C:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820fe03c
	if (ctx.cr6.eq) goto loc_820FE03C;
	// ld r11,640(r28)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r28.u32 + 640);
	// b 0x820fe040
	goto loc_820FE040;
loc_820FE03C:
	// ld r11,632(r28)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r28.u32 + 632);
loc_820FE040:
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r8,r28,380
	ctx.r8.s64 = ctx.r28.s64 + 380;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r9,384(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 384);
	// lwz r8,388(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 388);
	// lwz r7,392(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 392);
	// lwz r11,380(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 380);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r8,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// stw r7,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// b 0x820fe090
	goto loc_820FE090;
loc_820FE074:
	// lwz r11,24(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// std r25,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r25.u64);
	// std r25,8(r10)
	REX_STORE_U64(ctx.r10.u32 + 8, ctx.r25.u64);
	// stwx r27,r11,r9
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, ctx.r27.u32);
loc_820FE090:
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r11,r28,552
	ctx.r11.s64 = ctx.r28.s64 + 552;
	// addi r10,r28,664
	ctx.r10.s64 = ctx.r28.s64 + 664;
	// li r7,4
	ctx.r7.s64 = 4;
loc_820FE0A0:
	// lwz r9,0(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820fe0ec
	if (ctx.cr6.eq) goto loc_820FE0EC;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrlwi. r9,r26,31
	ctx.r9.u64 = ctx.r26.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fe0d0
	if (ctx.cr0.eq) goto loc_820FE0D0;
	// rlwinm. r9,r26,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fe0c8
	if (ctx.cr0.eq) goto loc_820FE0C8;
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// b 0x820fe0e4
	goto loc_820FE0E4;
loc_820FE0C8:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x820fe0e4
	goto loc_820FE0E4;
loc_820FE0D0:
	// rlwinm. r9,r26,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820fe0e0
	if (ctx.cr0.eq) goto loc_820FE0E0;
	// ld r9,32(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 32);
	// b 0x820fe0e4
	goto loc_820FE0E4;
loc_820FE0E0:
	// ld r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
loc_820FE0E4:
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// std r9,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r9.u64);
loc_820FE0EC:
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x820fe0a0
	if (!ctx.cr0.eq) goto loc_820FE0A0;
	// b 0x820fe330
	goto loc_820FE330;
loc_820FE104:
	// rlwinm. r3,r26,0,28,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820fe14c
	if (ctx.cr0.eq) goto loc_820FE14C;
	// lwz r10,84(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 84);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// b 0x820fe120
	goto loc_820FE120;
loc_820FE118:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r10,84(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 84);
loc_820FE120:
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x820fe118
	if (!ctx.cr0.eq) goto loc_820FE118;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
loc_820FE130:
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820fe130
	if (!ctx.cr6.eq) goto loc_820FE130;
	// b 0x820fe154
	goto loc_820FE154;
loc_820FE14C:
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// li r8,1
	ctx.r8.s64 = 1;
loc_820FE154:
	// rlwinm. r11,r26,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fe248
	if (ctx.cr0.eq) goto loc_820FE248;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820fe21c
	if (ctx.cr6.eq) goto loc_820FE21C;
	// clrlwi r5,r26,31
	ctx.r5.u64 = ctx.r26.u32 & 0x1;
	// rlwinm r4,r26,0,30,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x2;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
loc_820FE174:
	// lwz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820fe1c8
	if (ctx.cr6.eq) goto loc_820FE1C8;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820fe1ac
	if (ctx.cr6.eq) goto loc_820FE1AC;
	// lwz r10,332(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 332);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// beq cr6,0x820fe210
	if (ctx.cr6.eq) goto loc_820FE210;
	// lwz r11,340(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 340);
loc_820FE1A4:
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x820fe20c
	goto loc_820FE20C;
loc_820FE1AC:
	// lwz r10,328(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 328);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// beq cr6,0x820fe210
	if (ctx.cr6.eq) goto loc_820FE210;
	// lwz r11,336(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 336);
	// b 0x820fe1a4
	goto loc_820FE1A4;
loc_820FE1C8:
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820fe1f0
	if (ctx.cr6.eq) goto loc_820FE1F0;
	// ld r9,240(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 240);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// beq cr6,0x820fe210
	if (ctx.cr6.eq) goto loc_820FE210;
	// ld r11,256(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 256);
	// b 0x820fe208
	goto loc_820FE208;
loc_820FE1F0:
	// ld r9,232(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 232);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// beq cr6,0x820fe210
	if (ctx.cr6.eq) goto loc_820FE210;
	// ld r11,248(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 248);
loc_820FE208:
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_820FE20C:
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_820FE210:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x820fe174
	if (!ctx.cr0.eq) goto loc_820FE174;
loc_820FE21C:
	// lwz r11,380(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 380);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r9,384(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 384);
	// addi r7,r28,380
	ctx.r7.s64 = ctx.r28.s64 + 380;
	// lwz r7,388(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 388);
	// lwz r6,392(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 392);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r7,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// stw r6,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
	// b 0x820fe264
	goto loc_820FE264;
loc_820FE248:
	// lwz r11,24(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// std r25,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r25.u64);
	// std r25,8(r10)
	REX_STORE_U64(ctx.r10.u32 + 8, ctx.r25.u64);
	// stwx r27,r11,r9
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, ctx.r27.u32);
loc_820FE264:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820fe330
	if (ctx.cr6.eq) goto loc_820FE330;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
loc_820FE274:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r10,r11,200
	ctx.r10.s64 = ctx.r11.s64 + 200;
	// addi r9,r11,312
	ctx.r9.s64 = ctx.r11.s64 + 312;
loc_820FE288:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fe310
	if (ctx.cr6.eq) goto loc_820FE310;
	// rlwinm. r11,r26,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820fe2d0
	if (ctx.cr0.eq) goto loc_820FE2D0;
	// clrlwi. r11,r26,31
	ctx.r11.u64 = ctx.r26.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fe2bc
	if (ctx.cr0.eq) goto loc_820FE2BC;
	// lwz r11,-32(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -32);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// beq cr6,0x820fe304
	if (ctx.cr6.eq) goto loc_820FE304;
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x820fe2fc
	goto loc_820FE2FC;
loc_820FE2BC:
	// ld r11,-64(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + -64);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// beq cr6,0x820fe304
	if (ctx.cr6.eq) goto loc_820FE304;
	// ld r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// b 0x820fe2fc
	goto loc_820FE2FC;
loc_820FE2D0:
	// clrlwi. r11,r26,31
	ctx.r11.u64 = ctx.r26.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820fe2ec
	if (ctx.cr0.eq) goto loc_820FE2EC;
	// lwz r11,-48(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -48);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// beq cr6,0x820fe304
	if (ctx.cr6.eq) goto loc_820FE304;
	// lwz r8,-16(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + -16);
	// b 0x820fe2fc
	goto loc_820FE2FC;
loc_820FE2EC:
	// ld r11,-96(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + -96);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// beq cr6,0x820fe304
	if (ctx.cr6.eq) goto loc_820FE304;
	// ld r8,-32(r10)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r10.u32 + -32);
loc_820FE2FC:
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
loc_820FE304:
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_820FE310:
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x820fe288
	if (!ctx.cr0.eq) goto loc_820FE288;
	// addic. r4,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// bne 0x820fe274
	if (!ctx.cr0.eq) goto loc_820FE274;
loc_820FE330:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
loc_820FE334:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8212995c
	__restgprlr_25(ctx, base);
	return;
}
