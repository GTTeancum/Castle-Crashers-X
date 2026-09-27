DEFINE_REX_FUNC(sub_820D8648) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820d875c
	if (ctx.cr6.eq) goto loc_820D875C;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820d875c
	if (ctx.cr6.eq) goto loc_820D875C;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820d868c
	if (!ctx.cr6.eq) goto loc_820D868C;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bgt cr6,0x820d875c
	if (ctx.cr6.gt) goto loc_820D875C;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stb r3,0(r5)
	REX_STORE_U8(ctx.r5.u32 + 0, ctx.r3.u8);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r11,r11,-32552
	ctx.r11.s64 = ctx.r11.s64 + -32552;
	// addi r10,r11,48
	ctx.r10.s64 = ctx.r11.s64 + 48;
	// stw r10,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// blr 
	return;
loc_820D868C:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x820d86b8
	if (!ctx.cr6.eq) goto loc_820D86B8;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bgt cr6,0x820d875c
	if (ctx.cr6.gt) goto loc_820D875C;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stb r3,0(r5)
	REX_STORE_U8(ctx.r5.u32 + 0, ctx.r3.u8);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r11,r11,-32552
	ctx.r11.s64 = ctx.r11.s64 + -32552;
	// addi r10,r11,96
	ctx.r10.s64 = ctx.r11.s64 + 96;
	// stw r10,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// blr 
	return;
loc_820D86B8:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x820d8728
	if (ctx.cr6.eq) goto loc_820D8728;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x820d86f8
	if (ctx.cr6.eq) goto loc_820D86F8;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x820d875c
	if (!ctx.cr6.eq) goto loc_820D875C;
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// bne cr6,0x820d875c
	if (!ctx.cr6.eq) goto loc_820D875C;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r11,r11,-32552
	ctx.r11.s64 = ctx.r11.s64 + -32552;
	// stb r10,0(r5)
	REX_STORE_U8(ctx.r5.u32 + 0, ctx.r10.u8);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r9,r11,144
	ctx.r9.s64 = ctx.r11.s64 + 144;
	// stw r9,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// blr 
	return;
loc_820D86F8:
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x820d8708
	if (ctx.cr6.eq) goto loc_820D8708;
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// bne cr6,0x820d875c
	if (!ctx.cr6.eq) goto loc_820D875C;
loc_820D8708:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r11,-32552
	ctx.r11.s64 = ctx.r11.s64 + -32552;
	// stb r10,0(r5)
	REX_STORE_U8(ctx.r5.u32 + 0, ctx.r10.u8);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r9,r11,48
	ctx.r9.s64 = ctx.r11.s64 + 48;
	// stw r9,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// blr 
	return;
loc_820D8728:
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x820d8740
	if (ctx.cr6.eq) goto loc_820D8740;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x820d8740
	if (ctx.cr6.eq) goto loc_820D8740;
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// bne cr6,0x820d875c
	if (!ctx.cr6.eq) goto loc_820D875C;
loc_820D8740:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r11,-32552
	ctx.r9.s64 = ctx.r11.s64 + -32552;
	// stb r10,0(r5)
	REX_STORE_U8(ctx.r5.u32 + 0, ctx.r10.u8);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// stw r9,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// blr 
	return;
loc_820D875C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
