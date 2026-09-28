DEFINE_REX_FUNC(sub_820A6B60) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820a6cc0
	if (!ctx.cr6.eq) goto loc_820A6CC0;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820b5ce0
	ctx.lr = 0x820A6B90;
	sub_820B5CE0(ctx, base);
	// ld r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// rldicl r11,r11,16,48
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 16) & 0xFFFF;
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// bne cr6,0x820a6bbc
	if (!ctx.cr6.eq) goto loc_820A6BBC;
	// rlwinm r11,r11,0,24,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a6bbc
	if (ctx.cr6.eq) goto loc_820A6BBC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x820a6cc0
	goto loc_820A6CC0;
loc_820A6BBC:
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lbz r10,1378(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1378);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820a6bd8
	if (!ctx.cr6.eq) goto loc_820A6BD8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x820a6cc0
	goto loc_820A6CC0;
loc_820A6BD8:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// bl 0x820fc2b8
	ctx.lr = 0x820A6BF8;
	sub_820FC2B8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,18
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 18, ctx.xer);
	// bne cr6,0x820a6c3c
	if (!ctx.cr6.eq) goto loc_820A6C3C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a6e08
	ctx.lr = 0x820A6C0C;
	sub_820A6E08(ctx, base);
loc_820A6C0C:
	// lwz r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x820a7390
	ctx.lr = 0x820A6C14;
	sub_820A7390(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r3.u32);
	// bne cr6,0x820a6c5c
	if (!ctx.cr6.eq) goto loc_820A6C5C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r3,r11,7368
	ctx.r3.s64 = ctx.r11.s64 + 7368;
	// bl 0x8208c5d8
	ctx.lr = 0x820A6C30;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// b 0x820a6cc0
	goto loc_820A6CC0;
loc_820A6C3C:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820a6c0c
	if (ctx.cr6.eq) goto loc_820A6C0C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,7316
	ctx.r3.s64 = ctx.r11.s64 + 7316;
	// bl 0x8208c5d8
	ctx.lr = 0x820A6C50;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// b 0x820a6cc0
	goto loc_820A6CC0;
loc_820A6C5C:
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r31,32
	ctx.r7.s64 = ctx.r31.s64 + 32;
	// stw r9,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
	// li r10,7
	ctx.r10.s64 = 7;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820A6C74:
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x820a6c74
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820A6C74;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,72(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r5,96(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x820b6ac0
	ctx.lr = 0x820A6C94;
	sub_820B6AC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,997
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 997, ctx.xer);
	// beq cr6,0x820a6cb8
	if (ctx.cr6.eq) goto loc_820A6CB8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,7444
	ctx.r3.s64 = ctx.r11.s64 + 7444;
	// bl 0x8208c5d8
	ctx.lr = 0x820A6CAC;
	sub_8208C5D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// b 0x820a6cc0
	goto loc_820A6CC0;
loc_820A6CB8:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_820A6CC0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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
