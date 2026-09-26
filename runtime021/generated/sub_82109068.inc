DEFINE_REX_FUNC(sub_82109068) {
	REX_FUNC_PROLOGUE();
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82109090
	if (ctx.cr6.eq) goto loc_82109090;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32221
	ctx.r10.s64 = -2111635456;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r10,23128
	ctx.r5.s64 = ctx.r10.s64 + 23128;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_82109090:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
