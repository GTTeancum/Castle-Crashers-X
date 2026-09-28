DEFINE_REX_FUNC(sub_82132F50) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82132f7c
	if (ctx.cr6.eq) goto loc_82132F7C;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82132f7c
	if (ctx.cr6.eq) goto loc_82132F7C;
	// lbz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82132f84
	if (!ctx.cr0.eq) goto loc_82132F84;
	// beq cr6,0x82132f7c
	if (ctx.cr6.eq) goto loc_82132F7C;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r11,0(r3)
	REX_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
loc_82132F7C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82132F84:
	// beq cr6,0x82132f90
	if (ctx.cr6.eq) goto loc_82132F90;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// sth r11,0(r3)
	REX_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
loc_82132F90:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}
