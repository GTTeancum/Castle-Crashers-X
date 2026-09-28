DEFINE_REX_FUNC(sub_82114870) {
	REX_FUNC_PROLOGUE();
	// lbz r11,56(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 56);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x821148b8
	if (ctx.cr6.eq) goto loc_821148B8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x821148b0
	if (ctx.cr6.eq) goto loc_821148B0;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x821148a8
	if (ctx.cr6.eq) goto loc_821148A8;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x821148a0
	if (ctx.cr6.eq) goto loc_821148A0;
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4106
	ctx.r3.u64 = ctx.r3.u64 | 4106;
	// blr 
	return;
loc_821148A0:
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x8210ff60
	sub_8210FF60(ctx, base);
	return;
loc_821148A8:
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x8210ff60
	sub_8210FF60(ctx, base);
	return;
loc_821148B0:
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x8210faf8
	sub_8210FAF8(ctx, base);
	return;
loc_821148B8:
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x821139e0
	sub_821139E0(ctx, base);
	return;
}
