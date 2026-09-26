DEFINE_REX_FUNC(sub_82050900) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r5,6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 6, ctx.xer);
	// bgt cr6,0x82050a18
	if (ctx.cr6.gt) goto loc_82050A18;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,2368
	ctx.r12.s64 = ctx.r12.s64 + 2368;
	// rlwinm r0,r5,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r5.u32) {
	case 0:
		goto loc_8205095C;
	case 1:
		goto loc_82050974;
	case 2:
		goto loc_82050974;
	case 3:
		goto loc_820509A0;
	case 4:
		goto loc_820509E0;
	case 5:
		goto loc_820509E8;
	case 6:
		goto loc_820509FC;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8205095C:
	// addi r11,r6,-1
	ctx.r11.s64 = ctx.r6.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,12(r3)
	REX_STORE_U8(ctx.r3.u32 + 12, ctx.r9.u8);
	// bl 0x82050a50
	ctx.lr = 0x82050970;
	sub_82050A50(ctx, base);
	// b 0x82050a28
	goto loc_82050A28;
loc_82050974:
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bgt cr6,0x82050a28
	if (ctx.cr6.gt) goto loc_82050A28;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r5,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// stw r6,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r6.u32);
	// stw r31,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r31.u32);
	// stb r11,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r11.u8);
	// stw r31,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// bl 0x82050a50
	ctx.lr = 0x8205099C;
	sub_82050A50(ctx, base);
	// b 0x82050a28
	goto loc_82050A28;
loc_820509A0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x820509d8
	if (ctx.cr6.eq) goto loc_820509D8;
	// stw r6,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stb r31,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r31.u8);
	// stw r31,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r31.u32);
	// stw r31,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r31.u32);
	// stw r31,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r31.u32);
	// stw r31,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// stb r31,40(r3)
	REX_STORE_U8(ctx.r3.u32 + 40, ctx.r31.u8);
	// stw r31,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r31.u32);
	// stw r31,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r31.u32);
	// stw r31,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r31.u32);
	// stw r31,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r31.u32);
loc_820509D8:
	// bl 0x82050a50
	ctx.lr = 0x820509DC;
	sub_82050A50(ctx, base);
	// b 0x82050a28
	goto loc_82050A28;
loc_820509E0:
	// stw r6,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// b 0x82050a28
	goto loc_82050A28;
loc_820509E8:
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// li r4,10
	ctx.r4.s64 = 10;
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// bl 0x820b5958
	ctx.lr = 0x820509F8;
	sub_820B5958(ctx, base);
	// b 0x82050a28
	goto loc_82050A28;
loc_820509FC:
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// li r10,900
	ctx.r10.s64 = 900;
	// addi r11,r11,15
	ctx.r11.s64 = ctx.r11.s64 + 15;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r3
	REX_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u32);
	// bl 0x82050a50
	ctx.lr = 0x82050A14;
	sub_82050A50(ctx, base);
	// b 0x82050a28
	goto loc_82050A28;
loc_82050A18:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r3,r11,6848
	ctx.r3.s64 = ctx.r11.s64 + 6848;
	// bl 0x8208c5d8
	ctx.lr = 0x82050A28;
	sub_8208C5D8(ctx, base);
loc_82050A28:
	// stw r31,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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
