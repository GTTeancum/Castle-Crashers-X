DEFINE_REX_FUNC(sub_8213FB58) {
	REX_FUNC_PROLOGUE();
	// ld r9,40(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 40);
	// li r8,20
	ctx.r8.s64 = 20;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,372(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 372);
	// divdu r9,r9,r8
	ctx.r9.u64 = ctx.r8.u64 ? ctx.r9.u64 / ctx.r8.u64 : 0;
	// addi r8,r3,372
	ctx.r8.s64 = ctx.r3.s64 + 372;
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,72(r3)
	REX_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// sth r9,64(r3)
	REX_STORE_U16(ctx.r3.u32 + 64, ctx.r9.u16);
	// std r11,296(r3)
	REX_STORE_U64(ctx.r3.u32 + 296, ctx.r11.u64);
	// stw r11,304(r3)
	REX_STORE_U32(ctx.r3.u32 + 304, ctx.r11.u32);
	// stb r11,308(r3)
	REX_STORE_U8(ctx.r3.u32 + 308, ctx.r11.u8);
	// stw r11,312(r3)
	REX_STORE_U32(ctx.r3.u32 + 312, ctx.r11.u32);
	// beq cr6,0x8213fbf0
	if (ctx.cr6.eq) goto loc_8213FBF0;
	// addi r7,r3,364
	ctx.r7.s64 = ctx.r3.s64 + 364;
loc_8213FB9C:
	// lwz r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8213fbc4
	if (ctx.cr6.eq) goto loc_8213FBC4;
	// lwz r6,4(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8213fbb8
	if (!ctx.cr6.eq) goto loc_8213FBB8;
	// stw r11,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
loc_8213FBB8:
	// lwz r6,4(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stw r6,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// stw r11,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r11.u32);
loc_8213FBC4:
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// lwz r9,4(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8213fbdc
	if (ctx.cr6.eq) goto loc_8213FBDC;
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// b 0x8213fbe0
	goto loc_8213FBE0;
loc_8213FBDC:
	// stw r10,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
loc_8213FBE0:
	// stw r10,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r10.u32);
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8213fb9c
	if (!ctx.cr6.eq) goto loc_8213FB9C;
loc_8213FBF0:
	// addi r10,r3,80
	ctx.r10.s64 = ctx.r3.s64 + 80;
	// li r11,25
	ctx.r11.s64 = 25;
loc_8213FBF8:
	// ld r9,280(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 280);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// std r9,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bne 0x8213fbf8
	if (!ctx.cr0.eq) goto loc_8213FBF8;
	// blr 
	return;
}
