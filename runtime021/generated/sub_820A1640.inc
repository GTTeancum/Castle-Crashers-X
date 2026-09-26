DEFINE_REX_FUNC(sub_820A1640) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,3
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 3, ctx.xer);
	// ble cr6,0x820a1668
	if (!ctx.cr6.gt) goto loc_820A1668;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820a1700
	goto loc_820A1700;
loc_820A1668:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820a16f4
	if (ctx.cr6.eq) goto loc_820A16F4;
	// addi r4,r31,124
	ctx.r4.s64 = ctx.r31.s64 + 124;
	// bl 0x820b6b80
	ctx.lr = 0x820A1680;
	sub_820B6B80(ctx, base);
	// cntlzw r11,r3
	ctx.r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stb r10,120(r31)
	REX_STORE_U8(ctx.r31.u32 + 120, ctx.r10.u8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a16b4
	if (ctx.cr6.eq) goto loc_820A16B4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,2
	ctx.r10.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r9,20(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820A16B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820a16c8
	goto loc_820A16C8;
loc_820A16B4:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,32(r31)
	REX_STORE_U16(ctx.r31.u32 + 32, ctx.r11.u16);
	// stb r11,34(r31)
	REX_STORE_U8(ctx.r31.u32 + 34, ctx.r11.u8);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
loc_820A16C8:
	// li r7,0
	ctx.r7.s64 = 0;
	// lbz r6,35(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r5,34(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 34);
	// lhz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 32);
	// bl 0x8209b9d0
	ctx.lr = 0x820A16E0;
	sub_8209B9D0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_820A16F4:
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
loc_820A1700:
	// stb r11,120(r31)
	REX_STORE_U8(ctx.r31.u32 + 120, ctx.r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
