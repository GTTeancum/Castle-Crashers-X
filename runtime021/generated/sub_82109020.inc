DEFINE_REX_FUNC(sub_82109020) {
	REX_FUNC_PROLOGUE();
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82109030
	if (ctx.cr6.eq) goto loc_82109030;
	// b 0x82139b70
	sub_82139B70(ctx, base);
	return;
loc_82109030:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
