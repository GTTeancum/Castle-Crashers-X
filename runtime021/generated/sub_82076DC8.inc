DEFINE_REX_FUNC(sub_82076DC8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32218
	ctx.r30.s64 = -2111438848;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-6636(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -6636);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lbz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 8);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82076e10
	if (ctx.cr6.eq) goto loc_82076E10;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
loc_82076E10:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x82076ee0
	if (ctx.cr6.gt) goto loc_82076EE0;
	// lis r12,-32249
	ctx.r12.s64 = -2113470464;
	// addi r12,r12,28212
	ctx.r12.s64 = ctx.r12.s64 + 28212;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82076EEC;
	case 1:
		goto loc_82076E4C;
	case 2:
		goto loc_82076EEC;
	case 3:
		goto loc_82076E9C;
	case 4:
		goto loc_82076EEC;
	case 5:
		goto loc_82076ED4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82076E4C:
	// lwz r11,1756(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1756);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82076eec
	if (ctx.cr6.eq) goto loc_82076EEC;
	// bl 0x82078d90
	ctx.lr = 0x82076E60;
	sub_82078D90(ctx, base);
	// lbz r11,70(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 70);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076eec
	if (ctx.cr6.eq) goto loc_82076EEC;
	// lbz r11,238(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 238);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x82076e80
	if (ctx.cr6.eq) goto loc_82076E80;
	// lbz r11,242(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 242);
loc_82076E80:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82076eec
	if (ctx.cr6.eq) goto loc_82076EEC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,-6636(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -6636);
	// bl 0x8209dfe8
	ctx.lr = 0x82076E98;
	sub_8209DFE8(ctx, base);
	// b 0x82076eec
	goto loc_82076EEC;
loc_82076E9C:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,9(r31)
	REX_STORE_U8(ctx.r31.u32 + 9, ctx.r9.u8);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x82076eec
	if (!ctx.cr6.gt) goto loc_82076EEC;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// addi r11,r31,40
	ctx.r11.s64 = ctx.r31.s64 + 40;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82076eec
	if (ctx.cr6.eq) goto loc_82076EEC;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// bne 0x82076eec
	if (!ctx.cr0.eq) goto loc_82076EEC;
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// b 0x82076eec
	goto loc_82076EEC;
loc_82076ED4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-8120
	ctx.r3.s64 = ctx.r11.s64 + -8120;
	// b 0x82076ee8
	goto loc_82076EE8;
loc_82076EE0:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-8072
	ctx.r3.s64 = ctx.r11.s64 + -8072;
loc_82076EE8:
	// bl 0x8208c5d8
	ctx.lr = 0x82076EEC;
	sub_8208C5D8(ctx, base);
loc_82076EEC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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
