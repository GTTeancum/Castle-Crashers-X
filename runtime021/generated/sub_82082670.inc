DEFINE_REX_FUNC(sub_82082670) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,512
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 512, ctx.xer);
	// bgt cr6,0x820826c4
	if (ctx.cr6.gt) goto loc_820826C4;
	// beq cr6,0x820826e8
	if (ctx.cr6.eq) goto loc_820826E8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x820826bc
	if (ctx.cr6.eq) goto loc_820826BC;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x820826e8
	if (ctx.cr6.eq) goto loc_820826E8;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bne cr6,0x820826e0
	if (!ctx.cr6.eq) goto loc_820826E0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,9536(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bne cr6,0x820826b4
	if (!ctx.cr6.eq) goto loc_820826B4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820826B4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
loc_820826BC:
	// lbz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 4);
	// blr 
	return;
loc_820826C4:
	// cmpwi cr6,r11,1024
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1024, ctx.xer);
	// beq cr6,0x820826e8
	if (ctx.cr6.eq) goto loc_820826E8;
	// cmpwi cr6,r11,16384
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16384, ctx.xer);
	// beq cr6,0x820826e8
	if (ctx.cr6.eq) goto loc_820826E8;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x820826e8
	if (ctx.cr6.eq) goto loc_820826E8;
loc_820826E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_820826E8:
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}
