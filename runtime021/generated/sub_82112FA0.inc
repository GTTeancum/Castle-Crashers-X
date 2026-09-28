DEFINE_REX_FUNC(sub_82112FA0) {
	REX_FUNC_PROLOGUE();
	// lbz r11,56(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 56);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82112fe8
	if (ctx.cr6.eq) goto loc_82112FE8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82112fe0
	if (ctx.cr6.eq) goto loc_82112FE0;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82112fd8
	if (ctx.cr6.eq) goto loc_82112FD8;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x82112fd0
	if (ctx.cr6.eq) goto loc_82112FD0;
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4106
	ctx.r3.u64 = ctx.r3.u64 | 4106;
	// blr 
	return;
loc_82112FD0:
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x8210feb8
	sub_8210FEB8(ctx, base);
	return;
loc_82112FD8:
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x8210fd48
	sub_8210FD48(ctx, base);
	return;
loc_82112FE0:
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x8210fa50
	sub_8210FA50(ctx, base);
	return;
loc_82112FE8:
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x821127d0
	sub_821127D0(ctx, base);
	return;
}
