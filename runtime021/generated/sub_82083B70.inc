DEFINE_REX_FUNC(sub_82083B70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82083B78;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stb r31,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r31.u8);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,111
	ctx.r4.s64 = 111;
	// stw r31,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// stb r31,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r31.u8);
	// stw r31,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r31.u32);
	// stb r31,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r31.u8);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r31,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);
	// stb r31,144(r1)
	REX_STORE_U8(ctx.r1.u32 + 144, ctx.r31.u8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82083BC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// li r4,112
	ctx.r4.s64 = 112;
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82083BE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// li r4,113
	ctx.r4.s64 = 113;
	// lwz r6,12(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82083C00;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r5,r1,136
	ctx.r5.s64 = ctx.r1.s64 + 136;
	// li r4,114
	ctx.r4.s64 = 114;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82083C1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r31,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r31.u32);
	// addi r5,r1,152
	ctx.r5.s64 = ctx.r1.s64 + 152;
	// stb r31,160(r1)
	REX_STORE_U8(ctx.r1.u32 + 160, ctx.r31.u8);
	// li r4,115
	ctx.r4.s64 = 115;
	// stw r31,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r31.u32);
	// stb r31,176(r1)
	REX_STORE_U8(ctx.r1.u32 + 176, ctx.r31.u8);
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// stw r31,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r31.u32);
	// stb r31,192(r1)
	REX_STORE_U8(ctx.r1.u32 + 192, ctx.r31.u8);
	// stw r31,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r31.u32);
	// stb r31,208(r1)
	REX_STORE_U8(ctx.r1.u32 + 208, ctx.r31.u8);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82083C58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r5,r1,168
	ctx.r5.s64 = ctx.r1.s64 + 168;
	// li r4,116
	ctx.r4.s64 = 116;
	// lwz r6,12(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82083C74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r5,r1,184
	ctx.r5.s64 = ctx.r1.s64 + 184;
	// li r4,117
	ctx.r4.s64 = 117;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82083C90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r5,r1,200
	ctx.r5.s64 = ctx.r1.s64 + 200;
	// li r4,118
	ctx.r4.s64 = 118;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82083CAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r6,88(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lis r29,-32768
	ctx.r29.s64 = -2147483648;
	// cmpw cr6,r6,r29
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r29.s32, ctx.xer);
	// lfs f31,9728(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9728);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x82083ce4
	if (ctx.cr6.eq) goto loc_82083CE4;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82082700
	ctx.lr = 0x82083CCC;
	sub_82082700(ctx, base);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// sth r11,28(r30)
	REX_STORE_U16(ctx.r30.u32 + 28, ctx.r11.u16);
	// b 0x82083ce8
	goto loc_82083CE8;
loc_82083CE4:
	// sth r31,28(r30)
	REX_STORE_U16(ctx.r30.u32 + 28, ctx.r31.u16);
loc_82083CE8:
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82083d14
	if (ctx.cr6.eq) goto loc_82083D14;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82082700
	ctx.lr = 0x82083CFC;
	sub_82082700(ctx, base);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// sth r11,30(r30)
	REX_STORE_U16(ctx.r30.u32 + 30, ctx.r11.u16);
	// b 0x82083d18
	goto loc_82083D18;
loc_82083D14:
	// sth r31,30(r30)
	REX_STORE_U16(ctx.r30.u32 + 30, ctx.r31.u16);
loc_82083D18:
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82083d44
	if (ctx.cr6.eq) goto loc_82083D44;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x82082700
	ctx.lr = 0x82083D2C;
	sub_82082700(ctx, base);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// sth r11,32(r30)
	REX_STORE_U16(ctx.r30.u32 + 32, ctx.r11.u16);
	// b 0x82083d48
	goto loc_82083D48;
loc_82083D44:
	// sth r31,32(r30)
	REX_STORE_U16(ctx.r30.u32 + 32, ctx.r31.u16);
loc_82083D48:
	// lwz r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82083d74
	if (ctx.cr6.eq) goto loc_82083D74;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x82082700
	ctx.lr = 0x82083D5C;
	sub_82082700(ctx, base);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// sth r11,40(r30)
	REX_STORE_U16(ctx.r30.u32 + 40, ctx.r11.u16);
	// b 0x82083d78
	goto loc_82083D78;
loc_82083D74:
	// sth r31,40(r30)
	REX_STORE_U16(ctx.r30.u32 + 40, ctx.r31.u16);
loc_82083D78:
	// lwz r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82083d94
	if (ctx.cr6.eq) goto loc_82083D94;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// bl 0x82082bb0
	ctx.lr = 0x82083D8C;
	sub_82082BB0(ctx, base);
	// sth r3,34(r30)
	REX_STORE_U16(ctx.r30.u32 + 34, ctx.r3.u16);
	// b 0x82083d98
	goto loc_82083D98;
loc_82083D94:
	// sth r31,34(r30)
	REX_STORE_U16(ctx.r30.u32 + 34, ctx.r31.u16);
loc_82083D98:
	// lwz r11,168(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82083db4
	if (ctx.cr6.eq) goto loc_82083DB4;
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// bl 0x82082bb0
	ctx.lr = 0x82083DAC;
	sub_82082BB0(ctx, base);
	// sth r3,36(r30)
	REX_STORE_U16(ctx.r30.u32 + 36, ctx.r3.u16);
	// b 0x82083db8
	goto loc_82083DB8;
loc_82083DB4:
	// sth r31,36(r30)
	REX_STORE_U16(ctx.r30.u32 + 36, ctx.r31.u16);
loc_82083DB8:
	// lwz r11,184(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82083dd4
	if (ctx.cr6.eq) goto loc_82083DD4;
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// bl 0x82082bb0
	ctx.lr = 0x82083DCC;
	sub_82082BB0(ctx, base);
	// sth r3,38(r30)
	REX_STORE_U16(ctx.r30.u32 + 38, ctx.r3.u16);
	// b 0x82083dd8
	goto loc_82083DD8;
loc_82083DD4:
	// sth r31,38(r30)
	REX_STORE_U16(ctx.r30.u32 + 38, ctx.r31.u16);
loc_82083DD8:
	// lwz r11,200(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82083df4
	if (ctx.cr6.eq) goto loc_82083DF4;
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// bl 0x82082bb0
	ctx.lr = 0x82083DEC;
	sub_82082BB0(ctx, base);
	// sth r3,42(r30)
	REX_STORE_U16(ctx.r30.u32 + 42, ctx.r3.u16);
	// b 0x82083df8
	goto loc_82083DF8;
loc_82083DF4:
	// sth r31,42(r30)
	REX_STORE_U16(ctx.r30.u32 + 42, ctx.r31.u16);
loc_82083DF8:
	// lhz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 28);
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// blt cr6,0x82083e08
	if (ctx.cr6.lt) goto loc_82083E08;
	// sth r31,28(r30)
	REX_STORE_U16(ctx.r30.u32 + 28, ctx.r31.u16);
loc_82083E08:
	// lhz r11,30(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 30);
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// blt cr6,0x82083e18
	if (ctx.cr6.lt) goto loc_82083E18;
	// sth r31,30(r30)
	REX_STORE_U16(ctx.r30.u32 + 30, ctx.r31.u16);
loc_82083E18:
	// lhz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 32);
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// blt cr6,0x82083e28
	if (ctx.cr6.lt) goto loc_82083E28;
	// sth r31,32(r30)
	REX_STORE_U16(ctx.r30.u32 + 32, ctx.r31.u16);
loc_82083E28:
	// lhz r11,40(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 40);
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// blt cr6,0x82083e38
	if (ctx.cr6.lt) goto loc_82083E38;
	// sth r31,40(r30)
	REX_STORE_U16(ctx.r30.u32 + 40, ctx.r31.u16);
loc_82083E38:
	// lwz r3,44(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82083e4c
	if (ctx.cr6.eq) goto loc_82083E4C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820837c0
	ctx.lr = 0x82083E4C;
	sub_820837C0(ctx, base);
loc_82083E4C:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
