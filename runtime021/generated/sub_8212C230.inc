DEFINE_REX_FUNC(sub_8212C230) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
loc_8212C238:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = REX_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// lbzu r5,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r5.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// cmpwi cr7,r6,0
	ctx.cr7.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// subf. r3,r6,r5
	ctx.r3.u64 = ctx.r5.u64 - ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr7,0x8212c280
	if (ctx.cr7.eq) goto loc_8212C280;
	// beq 0x8212c238
	if (ctx.cr0.eq) goto loc_8212C238;
	// cmpwi cr5,r6,65
	ctx.cr5.compare<int32_t>(ctx.r6.s32, 65, ctx.xer);
	// cmpwi cr6,r6,90
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 90, ctx.xer);
	// blt cr5,0x8212c264
	if (ctx.cr5.lt) goto loc_8212C264;
	// bgt cr6,0x8212c264
	if (ctx.cr6.gt) goto loc_8212C264;
	// ori r6,r6,32
	ctx.r6.u64 = ctx.r6.u64 | 32;
loc_8212C264:
	// cmpwi r5,65
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 65, ctx.xer);
	// cmpwi cr1,r5,90
	ctx.cr1.compare<int32_t>(ctx.r5.s32, 90, ctx.xer);
	// blt 0x8212c278
	if (ctx.cr0.lt) goto loc_8212C278;
	// bgt cr1,0x8212c278
	if (ctx.cr1.gt) goto loc_8212C278;
	// ori r5,r5,32
	ctx.r5.u64 = ctx.r5.u64 | 32;
loc_8212C278:
	// subf. r3,r6,r5
	ctx.r3.u64 = ctx.r5.u64 - ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8212c238
	if (ctx.cr0.eq) goto loc_8212C238;
loc_8212C280:
	// blr 
	return;
}
