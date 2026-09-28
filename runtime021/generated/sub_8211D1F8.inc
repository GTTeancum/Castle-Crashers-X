DEFINE_REX_FUNC(sub_8211D1F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8211d260
	if (!ctx.cr6.eq) goto loc_8211D260;
	// lwz r11,1148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1148);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// rlwinm r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8211d260
	if (ctx.cr6.eq) goto loc_8211D260;
	// lwz r10,44(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 44);
	// lwz r11,40(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 40);
	// cmplwi cr6,r10,11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 11, ctx.xer);
	// bne cr6,0x8211d260
	if (!ctx.cr6.eq) goto loc_8211D260;
	// lhz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// bne cr6,0x8211d260
	if (!ctx.cr6.eq) goto loc_8211D260;
	// lwz r10,428(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 428);
	// lwz r9,424(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 424);
	// lwz r8,3(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 3);
	// xor r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8211d260
	if (!ctx.cr6.eq) goto loc_8211D260;
	// lwz r4,7(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 7);
	// bl 0x8211b690
	ctx.lr = 0x8211D260;
	sub_8211B690(ctx, base);
loc_8211D260:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
