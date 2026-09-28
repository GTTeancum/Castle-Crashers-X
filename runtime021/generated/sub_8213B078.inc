DEFINE_REX_FUNC(sub_8213B078) {
	REX_FUNC_PROLOGUE();
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r11,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8213b098
	if (!ctx.cr6.eq) goto loc_8213B098;
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// addi r11,r11,-29772
	ctx.r11.s64 = ctx.r11.s64 + -29772;
	// b 0x8213b0a0
	goto loc_8213B0A0;
loc_8213B098:
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// addi r11,r11,-29804
	ctx.r11.s64 = ctx.r11.s64 + -29804;
loc_8213B0A0:
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}
