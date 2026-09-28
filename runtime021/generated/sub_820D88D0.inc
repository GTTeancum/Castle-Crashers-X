DEFINE_REX_FUNC(sub_820D88D0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,304(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 304);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lbz r11,268(r13)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r13.u32 + 268);
	// li r10,1
	ctx.r10.s64 = 1;
	// stbx r10,r11,r4
	REX_STORE_U8(ctx.r11.u32 + ctx.r4.u32, ctx.r10.u8);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r9,328(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 328);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820d88fc
	if (!ctx.cr6.eq) goto loc_820D88FC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820D88FC:
	// lwz r9,324(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 324);
	// rldicr r8,r11,56,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 56) & 0xFF00000000000000;
	// li r11,1
	ctx.r11.s64 = 1;
	// sradi r10,r8,8
	ctx.xer.ca = (ctx.r8.s64 < 0) & ((ctx.r8.u64 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r8.s64 >> 8;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820d8918
	if (!ctx.cr6.eq) goto loc_820D8918;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820D8918:
	// rldicr r11,r11,56,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 56) & 0xFF00000000000000;
	// lwz r9,320(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 320);
	// or r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 | ctx.r10.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// sradi r10,r8,8
	ctx.xer.ca = (ctx.r8.s64 < 0) & ((ctx.r8.u64 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r8.s64 >> 8;
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x820d8938
	if (!ctx.cr6.eq) goto loc_820D8938;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820D8938:
	// rldicr r11,r11,56,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 56) & 0xFF00000000000000;
	// lwz r9,316(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 316);
	// or r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 | ctx.r10.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// sradi r10,r8,8
	ctx.xer.ca = (ctx.r8.s64 < 0) & ((ctx.r8.u64 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r8.s64 >> 8;
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x820d8958
	if (!ctx.cr6.eq) goto loc_820D8958;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820D8958:
	// rldicr r11,r11,56,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 56) & 0xFF00000000000000;
	// lwz r9,312(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 312);
	// or r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 | ctx.r10.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// sradi r10,r8,8
	ctx.xer.ca = (ctx.r8.s64 < 0) & ((ctx.r8.u64 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r8.s64 >> 8;
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x820d8978
	if (!ctx.cr6.eq) goto loc_820D8978;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820D8978:
	// rldicr r11,r11,56,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 56) & 0xFF00000000000000;
	// lwz r9,308(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 308);
	// or r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 | ctx.r10.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// sradi r9,r8,8
	ctx.xer.ca = (ctx.r8.s64 < 0) & ((ctx.r8.u64 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r8.s64 >> 8;
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x820d8998
	if (!ctx.cr6.eq) goto loc_820D8998;
	// li r10,0
	ctx.r10.s64 = 0;
loc_820D8998:
	// ld r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 0);
	// rldicr r10,r10,56,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 56) & 0xFF00000000000000;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_820D89AC:
	// cmpd cr6,r10,r11
	ctx.cr6.compare<int64_t>(ctx.r10.s64, ctx.r11.s64, ctx.xer);
	// beq cr6,0x820d89c8
	if (ctx.cr6.eq) goto loc_820D89C8;
	// db16cyc 
	// ld r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 0);
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// bne cr6,0x820d89ac
	if (!ctx.cr6.eq) goto loc_820D89AC;
	// blr 
	return;
loc_820D89C8:
	// li r11,0
	ctx.r11.s64 = 0;
	// std r11,0(r4)
	REX_STORE_U64(ctx.r4.u32 + 0, ctx.r11.u64);
	// blr 
	return;
}
