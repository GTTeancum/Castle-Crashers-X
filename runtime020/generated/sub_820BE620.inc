DEFINE_REX_FUNC(sub_820BE620) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r30,12456(r31)
	REX_STORE_U32(ctx.r31.u32 + 12456, ctx.r30.u32);
	// beq cr6,0x820be764
	if (ctx.cr6.eq) goto loc_820BE764;
	// lwz r11,12440(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12440);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820be658
	if (!ctx.cr6.eq) goto loc_820BE658;
	// bl 0x820be248
	ctx.lr = 0x820BE658;
	sub_820BE248(ctx, base);
loc_820BE658:
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// stw r11,10376(r31)
	REX_STORE_U32(ctx.r31.u32 + 10376, ctx.r11.u32);
	// lbz r10,10942(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 10942);
	// lbz r9,10943(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 10943);
	// rlwinm. r9,r9,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// stw r11,10560(r31)
	REX_STORE_U32(ctx.r31.u32 + 10560, ctx.r11.u32);
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// rlwimi r10,r11,5,26,26
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0x20) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r10,10942(r31)
	REX_STORE_U8(ctx.r31.u32 + 10942, ctx.r10.u8);
	// beq 0x820be740
	if (ctx.cr0.eq) goto loc_820BE740;
	// lbz r11,10940(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10940);
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820be698
	if (ctx.cr0.eq) goto loc_820BE698;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820be728
	goto loc_820BE728;
loc_820BE698:
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820be720
	if (ctx.cr0.eq) goto loc_820BE720;
	// lwz r11,12440(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12440);
	// lwz r10,12728(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12728);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820be6b8
	if (ctx.cr6.eq) goto loc_820BE6B8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820be720
	if (!ctx.cr6.eq) goto loc_820BE720;
loc_820BE6B8:
	// lwz r11,12444(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12444);
	// lwz r10,12732(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12732);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820be6d0
	if (ctx.cr6.eq) goto loc_820BE6D0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820be720
	if (!ctx.cr6.eq) goto loc_820BE720;
loc_820BE6D0:
	// lwz r11,12448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12448);
	// lwz r10,12736(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12736);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820be6e8
	if (ctx.cr6.eq) goto loc_820BE6E8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820be720
	if (!ctx.cr6.eq) goto loc_820BE720;
loc_820BE6E8:
	// lwz r11,12452(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12452);
	// lwz r10,12740(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12740);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820be700
	if (ctx.cr6.eq) goto loc_820BE700;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820be720
	if (!ctx.cr6.eq) goto loc_820BE720;
loc_820BE700:
	// lwz r11,12456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12456);
	// lwz r10,12744(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12744);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820be718
	if (ctx.cr6.eq) goto loc_820BE718;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820be720
	if (!ctx.cr6.eq) goto loc_820BE720;
loc_820BE718:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820be724
	goto loc_820BE724;
loc_820BE720:
	// li r11,0
	ctx.r11.s64 = 0;
loc_820BE724:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_820BE728:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820be740
	if (ctx.cr0.eq) goto loc_820BE740;
	// lwz r11,10368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10368);
	// lwz r10,13172(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 13172);
	// rlwimi r11,r10,18,0,13
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 18) & 0xFFFC0000) | (ctx.r11.u64 & 0xFFFFFFFF0003FFFF);
	// stw r11,10368(r31)
	REX_STORE_U32(ctx.r31.u32 + 10368, ctx.r11.u32);
loc_820BE740:
	// li r12,1
	ctx.r12.s64 = 1;
	// ld r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// rldicr r12,r12,55,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 55) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// b 0x820be784
	goto loc_820BE784;
loc_820BE764:
	// lwz r11,10560(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10560);
	// lbz r10,10942(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 10942);
	// rlwinm r11,r11,0,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// andi. r10,r10,223
	ctx.r10.u64 = ctx.r10.u64 & 223;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,10560(r31)
	REX_STORE_U32(ctx.r31.u32 + 10560, ctx.r11.u32);
	// stb r10,10942(r31)
	REX_STORE_U8(ctx.r31.u32 + 10942, ctx.r10.u8);
	// ld r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
loc_820BE784:
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// lwz r11,12716(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12716);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820be860
	if (!ctx.cr6.eq) goto loc_820BE860;
	// lbz r11,10940(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10940);
	// rlwinm. r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820be860
	if (!ctx.cr0.eq) goto loc_820BE860;
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820be860
	if (!ctx.cr0.eq) goto loc_820BE860;
	// lbz r10,12187(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 12187);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x820be860
	if (!ctx.cr0.eq) goto loc_820BE860;
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820be7c4
	if (ctx.cr0.eq) goto loc_820BE7C4;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820be854
	goto loc_820BE854;
loc_820BE7C4:
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820be84c
	if (ctx.cr0.eq) goto loc_820BE84C;
	// lwz r11,12440(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12440);
	// lwz r10,12728(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12728);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820be7e4
	if (ctx.cr6.eq) goto loc_820BE7E4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820be84c
	if (!ctx.cr6.eq) goto loc_820BE84C;
loc_820BE7E4:
	// lwz r11,12444(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12444);
	// lwz r10,12732(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12732);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820be7fc
	if (ctx.cr6.eq) goto loc_820BE7FC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820be84c
	if (!ctx.cr6.eq) goto loc_820BE84C;
loc_820BE7FC:
	// lwz r11,12448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12448);
	// lwz r10,12736(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12736);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820be814
	if (ctx.cr6.eq) goto loc_820BE814;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820be84c
	if (!ctx.cr6.eq) goto loc_820BE84C;
loc_820BE814:
	// lwz r11,12452(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12452);
	// lwz r10,12740(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12740);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820be82c
	if (ctx.cr6.eq) goto loc_820BE82C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820be84c
	if (!ctx.cr6.eq) goto loc_820BE84C;
loc_820BE82C:
	// lwz r11,12456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12456);
	// lwz r10,12744(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12744);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820be844
	if (ctx.cr6.eq) goto loc_820BE844;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820be84c
	if (!ctx.cr6.eq) goto loc_820BE84C;
loc_820BE844:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820be850
	goto loc_820BE850;
loc_820BE84C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_820BE850:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_820BE854:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne 0x820be864
	if (!ctx.cr0.eq) goto loc_820BE864;
loc_820BE860:
	// li r10,0
	ctx.r10.s64 = 0;
loc_820BE864:
	// lbz r9,10940(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 10940);
	// lwz r11,11876(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 11876);
	// rlwimi r9,r10,0,31,31
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFFE);
	// stb r9,10940(r31)
	REX_STORE_U8(ctx.r31.u32 + 10940, ctx.r9.u8);
	// lwz r10,12456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12456);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,11876(r31)
	REX_STORE_U32(ctx.r31.u32 + 11876, ctx.r11.u32);
	// bne cr6,0x820be888
	if (!ctx.cr6.eq) goto loc_820BE888;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820BE888:
	// lwz r10,10548(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 10548);
	// rlwimi r10,r11,1,30,30
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFD);
	// stw r10,10548(r31)
	REX_STORE_U32(ctx.r31.u32 + 10548, ctx.r10.u32);
	// ld r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// lwz r10,12456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12456);
	// lwz r11,11880(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 11880);
	// stw r11,11880(r31)
	REX_STORE_U32(ctx.r31.u32 + 11880, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820be8c0
	if (!ctx.cr6.eq) goto loc_820BE8C0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820BE8C0:
	// lwz r10,10548(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 10548);
	// rlwimi r11,r10,0,0,30
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE) | (ctx.r11.u64 & 0xFFFFFFFF00000001);
	// stw r11,10548(r31)
	REX_STORE_U32(ctx.r31.u32 + 10548, ctx.r11.u32);
	// ld r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
