DEFINE_REX_FUNC(sub_82122D30) {
	REX_FUNC_PROLOGUE();
	// addis r11,r4,-4096
	ctx.r11.s64 = ctx.r4.s64 + -268435456;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82122d78
	if (ctx.cr0.eq) goto loc_82122D78;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82122d70
	if (ctx.cr6.eq) goto loc_82122D70;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x82122d68
	if (ctx.cr6.eq) goto loc_82122D68;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82122d60
	if (ctx.cr6.eq) goto loc_82122D60;
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4105
	ctx.r3.u64 = ctx.r3.u64 | 4105;
	// blr 
	return;
loc_82122D60:
	// lwz r11,180(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 180);
	// b 0x82122d7c
	goto loc_82122D7C;
loc_82122D68:
	// lwz r11,176(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 176);
	// b 0x82122d7c
	goto loc_82122D7C;
loc_82122D70:
	// ld r11,288(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 288);
	// b 0x82122d7c
	goto loc_82122D7C;
loc_82122D78:
	// ld r11,224(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 224);
loc_82122D7C:
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}
