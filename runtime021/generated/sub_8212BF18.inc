DEFINE_REX_FUNC(sub_8212BF18) {
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
	// lis r31,-32215
	ctx.r31.s64 = -2111242240;
	// lwz r3,3240(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3240);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8212bf44
	if (!ctx.cr6.eq) goto loc_8212BF44;
	// li r3,512
	ctx.r3.s64 = 512;
	// b 0x8212bf50
	goto loc_8212BF50;
loc_8212BF44:
	// cmpwi cr6,r3,20
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 20, ctx.xer);
	// bge cr6,0x8212bf54
	if (!ctx.cr6.lt) goto loc_8212BF54;
	// li r3,20
	ctx.r3.s64 = 20;
loc_8212BF50:
	// stw r3,3240(r31)
	REX_STORE_U32(ctx.r31.u32 + 3240, ctx.r3.u32);
loc_8212BF54:
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x8212e218
	ctx.lr = 0x8212BF5C;
	sub_8212E218(ctx, base);
	// lis r30,-32215
	ctx.r30.s64 = -2111242240;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,3236(r30)
	REX_STORE_U32(ctx.r30.u32 + 3236, ctx.r3.u32);
	// bne 0x8212bf94
	if (!ctx.cr0.eq) goto loc_8212BF94;
	// li r11,20
	ctx.r11.s64 = 20;
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r11,3240(r31)
	REX_STORE_U32(ctx.r31.u32 + 3240, ctx.r11.u32);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8212e218
	ctx.lr = 0x8212BF80;
	sub_8212E218(ctx, base);
	// stw r3,3236(r30)
	REX_STORE_U32(ctx.r30.u32 + 3236, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8212bf94
	if (!ctx.cr0.eq) goto loc_8212BF94;
	// li r3,26
	ctx.r3.s64 = 26;
	// b 0x8212c020
	goto loc_8212C020;
loc_8212BF94:
	// lis r11,-32235
	ctx.r11.s64 = -2112552960;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,31272
	ctx.r9.s64 = ctx.r11.s64 + 31272;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// b 0x8212bfac
	goto loc_8212BFAC;
loc_8212BFA8:
	// lwz r3,3236(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 3236);
loc_8212BFAC:
	// stwx r11,r10,r3
	REX_STORE_U32(ctx.r10.u32 + ctx.r3.u32, ctx.r11.u32);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r8,r9,640
	ctx.r8.s64 = ctx.r9.s64 + 640;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x8212bfa8
	if (ctx.cr6.lt) goto loc_8212BFA8;
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r9,16
	ctx.r8.s64 = ctx.r9.s64 + 16;
	// addi r7,r10,2976
	ctx.r7.s64 = ctx.r10.s64 + 2976;
loc_8212BFD4:
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// rlwinm r6,r11,6,21,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0x7C0;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r7
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// lwzx r10,r10,r6
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x8212c000
	if (ctx.cr6.eq) goto loc_8212C000;
	// cmpwi cr6,r10,-2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -2, ctx.xer);
	// beq cr6,0x8212c000
	if (ctx.cr6.eq) goto loc_8212C000;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8212c008
	if (!ctx.cr6.eq) goto loc_8212C008;
loc_8212C000:
	// li r10,-2
	ctx.r10.s64 = -2;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
loc_8212C008:
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// addi r10,r9,112
	ctx.r10.s64 = ctx.r9.s64 + 112;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8212bfd4
	if (ctx.cr6.lt) goto loc_8212BFD4;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8212C020:
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
