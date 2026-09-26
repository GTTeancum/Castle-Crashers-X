DEFINE_REX_FUNC(sub_8209BA50) {
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
	// lbz r11,102(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 102);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209ba80
	if (!ctx.cr6.eq) goto loc_8209BA80;
	// sth r11,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r11.u16);
	// stb r11,30(r31)
	REX_STORE_U8(ctx.r31.u32 + 30, ctx.r11.u8);
	// b 0x8209bb18
	goto loc_8209BB18;
loc_8209BA80:
	// addi r10,r11,255
	ctx.r10.s64 = ctx.r11.s64 + 255;
	// lbz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 100);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r9,r11,18
	ctx.r9.s64 = ctx.r11.s64 + 18;
	// stb r10,102(r31)
	REX_STORE_U8(ctx.r31.u32 + 102, ctx.r10.u8);
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r5,r7,r31
	ctx.r5.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r31.u32);
	// sth r5,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r5.u16);
	// lbz r4,68(r8)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r8.u32 + 68);
	// bl 0x8209b8d8
	ctx.lr = 0x8209BAAC;
	sub_8209B8D8(ctx, base);
	// lbz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 100);
	// lis r3,-32218
	ctx.r3.s64 = -2111438848;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// add r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r8,r10,188
	ctx.r8.s64 = ctx.r10.s64 + 188;
	// sth r8,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r8.u16);
	// lwz r11,-6624(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + -6624);
	// lbz r30,84(r9)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + 84);
	// addi r3,r11,1672
	ctx.r3.s64 = ctx.r11.s64 + 1672;
	// stb r30,31(r31)
	REX_STORE_U8(ctx.r31.u32 + 31, ctx.r30.u8);
	// bl 0x82052ea8
	ctx.lr = 0x8209BADC;
	sub_82052EA8(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// stw r6,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// lbz r5,31(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 31);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x8209baf8
	if (!ctx.cr6.eq) goto loc_8209BAF8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_8209BAF8:
	// lbz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 100);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// stb r10,100(r31)
	REX_STORE_U8(ctx.r31.u32 + 100, ctx.r10.u8);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8209bb18
	if (ctx.cr6.lt) goto loc_8209BB18;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,100(r31)
	REX_STORE_U8(ctx.r31.u32 + 100, ctx.r11.u8);
loc_8209BB18:
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
