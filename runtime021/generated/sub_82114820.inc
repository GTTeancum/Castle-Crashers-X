DEFINE_REX_FUNC(sub_82114820) {
	REX_FUNC_PROLOGUE();
	// lbz r11,56(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 56);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82114868
	if (ctx.cr6.eq) goto loc_82114868;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82114860
	if (ctx.cr6.eq) goto loc_82114860;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82114858
	if (ctx.cr6.eq) goto loc_82114858;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x82114850
	if (ctx.cr6.eq) goto loc_82114850;
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4106
	ctx.r3.u64 = ctx.r3.u64 | 4106;
	// blr 
	return;
loc_82114850:
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x8210fdf0
	sub_8210FDF0(ctx, base);
	return;
loc_82114858:
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x8210fc10
	sub_8210FC10(ctx, base);
	return;
loc_82114860:
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x82113b00
	sub_82113B00(ctx, base);
	return;
loc_82114868:
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x8210f888
	sub_8210F888(ctx, base);
	return;
}
