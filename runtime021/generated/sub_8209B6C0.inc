DEFINE_REX_FUNC(sub_8209B6C0) {
	REX_FUNC_PROLOGUE();
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r6,r3,8
	ctx.r6.s64 = ctx.r3.s64 + 8;
	// stb r8,24(r3)
	REX_STORE_U8(ctx.r3.u32 + 24, ctx.r8.u8);
	// li r5,4
	ctx.r5.s64 = 4;
loc_8209B6D0:
	// lbz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209b71c
	if (ctx.cr6.eq) goto loc_8209B71C;
	// lwz r7,0(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8209b71c
	if (ctx.cr6.eq) goto loc_8209B71C;
	// addi r11,r7,84
	ctx.r11.s64 = ctx.r7.s64 + 84;
	// addi r9,r7,36
	ctx.r9.s64 = ctx.r7.s64 + 36;
	// li r10,16
	ctx.r10.s64 = 16;
loc_8209B6F4:
	// sth r8,0(r9)
	REX_STORE_U16(ctx.r9.u32 + 0, ctx.r8.u16);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stb r8,-16(r11)
	REX_STORE_U8(ctx.r11.u32 + -16, ctx.r8.u8);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// stb r8,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne 0x8209b6f4
	if (!ctx.cr0.eq) goto loc_8209B6F4;
	// stb r8,102(r7)
	REX_STORE_U8(ctx.r7.u32 + 102, ctx.r8.u8);
	// stb r8,101(r7)
	REX_STORE_U8(ctx.r7.u32 + 101, ctx.r8.u8);
	// stb r8,100(r7)
	REX_STORE_U8(ctx.r7.u32 + 100, ctx.r8.u8);
loc_8209B71C:
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bne 0x8209b6d0
	if (!ctx.cr0.eq) goto loc_8209B6D0;
	// blr 
	return;
}
