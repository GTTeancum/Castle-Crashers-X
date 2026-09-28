DEFINE_REX_FUNC(sub_8211C9A0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8211c9fc
	if (!ctx.cr6.eq) goto loc_8211C9FC;
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r10,416(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 416);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// lwz r10,56(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8211c9f0
	if (ctx.cr6.lt) goto loc_8211C9F0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8211c9f0
	if (ctx.cr6.eq) goto loc_8211C9F0;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-32646
	ctx.r9.s64 = -2139488256;
	// stb r11,1145(r3)
	REX_STORE_U8(ctx.r3.u32 + 1145, ctx.r11.u8);
	// li r10,3
	ctx.r10.s64 = 3;
	// stb r11,1144(r3)
	REX_STORE_U8(ctx.r3.u32 + 1144, ctx.r11.u8);
	// ori r11,r9,4103
	ctx.r11.u64 = ctx.r9.u64 | 4103;
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// b 0x8211a3b8
	sub_8211A3B8(ctx, base);
	return;
loc_8211C9F0:
	// lbz r11,1144(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1144);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// b 0x8211ca14
	goto loc_8211CA14;
loc_8211C9FC:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// lbz r11,1144(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1144);
	// bne cr6,0x8211ca10
	if (!ctx.cr6.eq) goto loc_8211CA10;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// b 0x8211ca14
	goto loc_8211CA14;
loc_8211CA10:
	// ori r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 128;
loc_8211CA14:
	// stb r11,1144(r3)
	REX_STORE_U8(ctx.r3.u32 + 1144, ctx.r11.u8);
	// blr 
	return;
}
