DEFINE_REX_FUNC(sub_82108ED8) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82108ee4
	if (ctx.cr6.eq) goto loc_82108EE4;
	// b 0x82110b68
	sub_82110B68(ctx, base);
	return;
loc_82108EE4:
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// b 0x8210db60
	sub_8210DB60(ctx, base);
	return;
}
