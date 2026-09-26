DEFINE_REX_FUNC(sub_820A1A20) {
	REX_FUNC_PROLOGUE();
	// lbz r10,2(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// li r11,1
	ctx.r11.s64 = 1;
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// bgt cr6,0x820a1aac
	if (ctx.cr6.gt) goto loc_820A1AAC;
	// lis r12,-32246
	ctx.r12.s64 = -2113273856;
	// addi r12,r12,6728
	ctx.r12.s64 = ctx.r12.s64 + 6728;
	// rlwinm r0,r10,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r10.u32) {
	case 0:
		goto loc_820A1A78;
	case 1:
		goto loc_820A1A90;
	case 2:
		goto loc_820A1AAC;
	case 3:
		goto loc_820A1A60;
	case 4:
		goto loc_820A1AA8;
	case 5:
		goto loc_820A1AA8;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820A1A60:
	// li r11,769
	ctx.r11.s64 = 769;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// sth r11,0(r3)
	REX_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
	// clrlwi r3,r10,16
	ctx.r3.u64 = ctx.r10.u32 & 0xFFFF;
	// blr 
	return;
loc_820A1A78:
	// li r11,27
	ctx.r11.s64 = 27;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// sth r11,0(r3)
	REX_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
	// clrlwi r3,r10,16
	ctx.r3.u64 = ctx.r10.u32 & 0xFFFF;
	// blr 
	return;
loc_820A1A90:
	// li r11,34
	ctx.r11.s64 = 34;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// sth r11,0(r3)
	REX_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
	// clrlwi r3,r10,16
	ctx.r3.u64 = ctx.r10.u32 & 0xFFFF;
	// blr 
	return;
loc_820A1AA8:
	// li r11,2
	ctx.r11.s64 = 2;
loc_820A1AAC:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// sth r11,0(r3)
	REX_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
	// clrlwi r3,r10,16
	ctx.r3.u64 = ctx.r10.u32 & 0xFFFF;
	// blr 
	return;
}
