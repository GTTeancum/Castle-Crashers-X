DEFINE_REX_FUNC(sub_8211A318) {
	REX_FUNC_PROLOGUE();
	// lwz r10,1020(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 1020);
	// addi r11,r3,1016
	ctx.r11.s64 = ctx.r3.s64 + 1016;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8211a35c
	if (ctx.cr6.eq) goto loc_8211A35C;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8211a35c
	if (ctx.cr0.eq) goto loc_8211A35C;
	// lhz r9,832(r4)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r4.u32 + 832);
loc_8211A334:
	// lhz r8,824(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 824);
	// subf r8,r8,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r8.u64;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplwi cr6,r8,32768
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 32768, ctx.xer);
	// blt cr6,0x8211a38c
	if (ctx.cr6.lt) goto loc_8211A38C;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8211a35c
	if (ctx.cr6.eq) goto loc_8211A35C;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8211a334
	if (!ctx.cr0.eq) goto loc_8211A334;
loc_8211A35C:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// stw r11,12(r4)
	REX_STORE_U32(ctx.r4.u32 + 12, ctx.r11.u32);
	// stw r9,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8211A378:
	// lhz r11,1044(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 1044);
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// sth r11,1044(r3)
	REX_STORE_U16(ctx.r3.u32 + 1044, ctx.r11.u16);
	// blr 
	return;
loc_8211A38C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8211a35c
	if (ctx.cr6.eq) goto loc_8211A35C;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r4,8
	ctx.r11.s64 = ctx.r4.s64 + 8;
	// stw r10,12(r4)
	REX_STORE_U32(ctx.r4.u32 + 12, ctx.r10.u32);
	// stw r9,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r11.u32);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// b 0x8211a378
	goto loc_8211A378;
}
