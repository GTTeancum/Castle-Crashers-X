DEFINE_REX_FUNC(sub_821159F0) {
	REX_FUNC_PROLOGUE();
	// addi r11,r3,24
	ctx.r11.s64 = ctx.r3.s64 + 24;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82115a94
	if (ctx.cr6.eq) goto loc_82115A94;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82115a94
	if (ctx.cr0.eq) goto loc_82115A94;
loc_82115A14:
	// lwz r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82115a2c
	if (ctx.cr6.eq) goto loc_82115A2C;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_82115A2C:
	// lwz r9,36(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82115a5c
	if (!ctx.cr6.eq) goto loc_82115A5C;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82115a54
	if (ctx.cr6.eq) goto loc_82115A54;
	// lbz r9,56(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 56);
	// stb r9,0(r6)
	REX_STORE_U8(ctx.r6.u32 + 0, ctx.r9.u8);
	// lwz r10,32(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// stw r10,1(r6)
	REX_STORE_U32(ctx.r6.u32 + 1, ctx.r10.u32);
	// addi r6,r6,5
	ctx.r6.s64 = ctx.r6.s64 + 5;
loc_82115A54:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// b 0x82115a8c
	goto loc_82115A8C;
loc_82115A5C:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82115a88
	if (ctx.cr6.eq) goto loc_82115A88;
	// lbz r9,56(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 56);
	// stb r9,0(r6)
	REX_STORE_U8(ctx.r6.u32 + 0, ctx.r9.u8);
	// lwz r9,32(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// stw r9,1(r6)
	REX_STORE_U32(ctx.r6.u32 + 1, ctx.r9.u32);
	// lwz r9,36(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// stw r9,5(r6)
	REX_STORE_U32(ctx.r6.u32 + 5, ctx.r9.u32);
	// lwz r10,128(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 128);
	// stw r10,9(r6)
	REX_STORE_U32(ctx.r6.u32 + 9, ctx.r10.u32);
	// addi r6,r6,13
	ctx.r6.s64 = ctx.r6.s64 + 13;
loc_82115A88:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
loc_82115A8C:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82115a14
	if (!ctx.cr6.eq) goto loc_82115A14;
loc_82115A94:
	// stw r3,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// stw r7,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}
