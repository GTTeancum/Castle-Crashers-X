DEFINE_REX_FUNC(sub_82051A20) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82051b00
	if (ctx.cr6.lt) goto loc_82051B00;
	// beq cr6,0x82051aa4
	if (ctx.cr6.eq) goto loc_82051AA4;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82051b54
	if (!ctx.cr6.eq) goto loc_82051B54;
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x82051b54
	if (ctx.cr6.gt) goto loc_82051B54;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,6748
	ctx.r12.s64 = ctx.r12.s64 + 6748;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82051A74;
	case 1:
		goto loc_82051A7C;
	case 2:
		goto loc_82051A84;
	case 3:
		goto loc_82051A8C;
	case 4:
		goto loc_82051A94;
	case 5:
		goto loc_82051A9C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82051A74:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_82051A7C:
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
loc_82051A84:
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
loc_82051A8C:
	// li r3,23
	ctx.r3.s64 = 23;
	// blr 
	return;
loc_82051A94:
	// li r3,24
	ctx.r3.s64 = 24;
	// blr 
	return;
loc_82051A9C:
	// li r3,22
	ctx.r3.s64 = 22;
	// blr 
	return;
loc_82051AA4:
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x82051b54
	if (ctx.cr6.gt) goto loc_82051B54;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,6856
	ctx.r12.s64 = ctx.r12.s64 + 6856;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82051AE0;
	case 1:
		goto loc_82051AE8;
	case 2:
		goto loc_82051B4C;
	case 3:
		goto loc_82051AF0;
	case 4:
		goto loc_82051AF8;
	case 5:
		goto loc_82051B4C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82051AE0:
	// li r3,25
	ctx.r3.s64 = 25;
	// blr 
	return;
loc_82051AE8:
	// li r3,16
	ctx.r3.s64 = 16;
	// blr 
	return;
loc_82051AF0:
	// li r3,6
	ctx.r3.s64 = 6;
	// blr 
	return;
loc_82051AF8:
	// li r3,7
	ctx.r3.s64 = 7;
	// blr 
	return;
loc_82051B00:
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x82051b54
	if (ctx.cr6.gt) goto loc_82051B54;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,6948
	ctx.r12.s64 = ctx.r12.s64 + 6948;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82051B54;
	case 1:
		goto loc_82051B3C;
	case 2:
		goto loc_82051B44;
	case 3:
		goto loc_82051B4C;
	case 4:
		goto loc_82051B4C;
	case 5:
		goto loc_82051B4C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82051B3C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82051B44:
	// li r3,21
	ctx.r3.s64 = 21;
	// blr 
	return;
loc_82051B4C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82051B54:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
}
