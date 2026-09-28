DEFINE_REX_FUNC(sub_8211CA20) {
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
	// lwz r30,1148(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// rlwinm. r11,r30,0,8,8
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x800000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211cb00
	if (ctx.cr0.eq) goto loc_8211CB00;
	// lwz r9,452(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8211cab4
	if (ctx.cr6.eq) goto loc_8211CAB4;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// subf r10,r10,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r10.u64;
	// blt cr6,0x8211ca70
	if (ctx.cr6.lt) goto loc_8211CA70;
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// b 0x8211ca74
	goto loc_8211CA74;
loc_8211CA70:
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
loc_8211CA74:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8211cab4
	if (ctx.cr6.lt) goto loc_8211CAB4;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8211cba8
	if (ctx.cr6.eq) goto loc_8211CBA8;
	// lis r10,-32646
	ctx.r10.s64 = -2139488256;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,3
	ctx.r9.s64 = 3;
	// ori r10,r10,4103
	ctx.r10.u64 = ctx.r10.u64 | 4103;
	// stb r11,1145(r31)
	REX_STORE_U8(ctx.r31.u32 + 1145, ctx.r11.u8);
	// stw r9,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r11.u8);
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// bl 0x8211a3b8
	ctx.lr = 0x8211CAB0;
	sub_8211A3B8(ctx, base);
	// b 0x8211cba8
	goto loc_8211CBA8;
loc_8211CAB4:
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// beq cr6,0x8211cac4
	if (ctx.cr6.eq) goto loc_8211CAC4;
	// addi r3,r31,664
	ctx.r3.s64 = ctx.r31.s64 + 664;
	// bl 0x82125390
	ctx.lr = 0x8211CAC4;
	sub_82125390(ctx, base);
loc_8211CAC4:
	// lwz r10,452(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// lbz r9,1144(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 1144);
	// lwz r11,1148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1148);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// ori r9,r9,64
	ctx.r9.u64 = ctx.r9.u64 | 64;
	// rlwinm. r8,r11,0,10,10
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r10,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r10.u32);
	// stb r9,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r9.u8);
	// beq 0x8211cba8
	if (ctx.cr0.eq) goto loc_8211CBA8;
	// rlwinm r10,r11,0,11,9
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFDFFFFF;
	// lwz r11,444(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 444);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r10,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r10.u32);
	// stw r11,444(r31)
	REX_STORE_U32(ctx.r31.u32 + 444, ctx.r11.u32);
	// b 0x8211cba8
	goto loc_8211CBA8;
loc_8211CB00:
	// rlwinm. r11,r30,0,9,9
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x400000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8211cb3c
	if (!ctx.cr0.eq) goto loc_8211CB3C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211ae00
	ctx.lr = 0x8211CB14;
	sub_8211AE00(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8211cba8
	if (ctx.cr0.eq) goto loc_8211CBA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8211cb3c
	if (ctx.cr6.eq) goto loc_8211CB3C;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r3,r31,356
	ctx.r3.s64 = ctx.r31.s64 + 356;
	// bl 0x82122270
	ctx.lr = 0x8211CB38;
	sub_82122270(ctx, base);
	// b 0x8211cba8
	goto loc_8211CBA8;
loc_8211CB3C:
	// lhz r8,1032(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 1032);
	// li r10,1
	ctx.r10.s64 = 1;
	// lhz r9,1050(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 1050);
	// lwz r11,444(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 444);
	// rlwimi r30,r10,23,8,10
	ctx.r30.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0xE00000) | (ctx.r30.u64 & 0xFFFFFFFFFF1FFFFF);
	// lbz r7,1144(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 1144);
	// subf r9,r9,r8
	ctx.r9.u64 = ctx.r8.u64 - ctx.r9.u64;
	// stw r10,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r10.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lhz r8,1056(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 1056);
	// ori r10,r7,64
	ctx.r10.u64 = ctx.r7.u64 | 64;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// stw r30,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r30.u32);
	// stw r11,444(r31)
	REX_STORE_U32(ctx.r31.u32 + 444, ctx.r11.u32);
	// stb r10,1144(r31)
	REX_STORE_U8(ctx.r31.u32 + 1144, ctx.r10.u8);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8211cba0
	if (ctx.cr6.lt) goto loc_8211CBA0;
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8211cba0
	if (ctx.cr6.eq) goto loc_8211CBA0;
	// lwz r10,1028(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1028);
	// subf r10,r10,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r10.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// oris r11,r30,16
	ctx.r11.u64 = ctx.r30.u64 | 1048576;
	// bge cr6,0x8211cba4
	if (!ctx.cr6.lt) goto loc_8211CBA4;
loc_8211CBA0:
	// rlwinm r11,r30,0,12,10
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
loc_8211CBA4:
	// stw r11,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r11.u32);
loc_8211CBA8:
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
