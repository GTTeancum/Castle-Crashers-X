DEFINE_REX_FUNC(sub_820521F8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r10,r3,-1
	ctx.r10.s64 = ctx.r3.s64 + -1;
	// addi r11,r11,27352
	ctx.r11.s64 = ctx.r11.s64 + 27352;
	// cmplwi cr6,r10,24
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 24, ctx.xer);
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// bgt cr6,0x8205230c
	if (ctx.cr6.gt) goto loc_8205230C;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,8744
	ctx.r12.s64 = ctx.r12.s64 + 8744;
	// rlwinm r0,r10,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r10.u32) {
	case 0:
		goto loc_820522AC;
	case 1:
		goto loc_8205228C;
	case 2:
		goto loc_820522EC;
	case 3:
		goto loc_820522EC;
	case 4:
		goto loc_820522EC;
	case 5:
		goto loc_820522CC;
	case 6:
		goto loc_820522CC;
	case 7:
		goto loc_8205230C;
	case 8:
		goto loc_8205230C;
	case 9:
		goto loc_8205230C;
	case 10:
		goto loc_8205230C;
	case 11:
		goto loc_8205230C;
	case 12:
		goto loc_8205230C;
	case 13:
		goto loc_8205230C;
	case 14:
		goto loc_8205230C;
	case 15:
		goto loc_820522CC;
	case 16:
		goto loc_8205230C;
	case 17:
		goto loc_8205230C;
	case 18:
		goto loc_8205230C;
	case 19:
		goto loc_8205230C;
	case 20:
		goto loc_820522AC;
	case 21:
		goto loc_820522EC;
	case 22:
		goto loc_820522EC;
	case 23:
		goto loc_820522EC;
	case 24:
		goto loc_820522CC;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8205228C:
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// sth r9,8(r11)
	REX_STORE_U16(ctx.r11.u32 + 8, ctx.r9.u16);
	// sth r8,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r8.u16);
	// blr 
	return;
loc_820522AC:
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// sth r8,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r8.u16);
	// sth r9,8(r11)
	REX_STORE_U16(ctx.r11.u32 + 8, ctx.r9.u16);
	// blr 
	return;
loc_820522CC:
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// sth r9,8(r11)
	REX_STORE_U16(ctx.r11.u32 + 8, ctx.r9.u16);
	// sth r8,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r8.u16);
	// blr 
	return;
loc_820522EC:
	// li r10,3
	ctx.r10.s64 = 3;
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r8,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r8.u16);
	// sth r10,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r10.u16);
	// sth r9,8(r11)
	REX_STORE_U16(ctx.r11.u32 + 8, ctx.r9.u16);
loc_8205230C:
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}
