DEFINE_REX_FUNC(sub_820C8BF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820C8BF8;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a858
	ctx.lr = 0x820C8C00;
	__savefpr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// cntlzw r11,r29
	ctx.r11.u64 = ctx.r29.u32 == 0 ? 32 : __builtin_clz(ctx.r29.u32);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r31,r11,1
	ctx.r31.u64 = ctx.r11.u64 ^ 1;
	// bl 0x8214a814
	ctx.lr = 0x820C8C20;
	__imp__VdGetCurrentDisplayGamma(ctx, base);
	// lis r10,-32235
	ctx.r10.s64 = -2112552960;
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,1816
	ctx.r10.s64 = ctx.r10.s64 + 1816;
	// addi r9,r9,960
	ctx.r9.s64 = ctx.r9.s64 + 960;
	// rlwinm r8,r31,11,0,20
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 11) & 0xFFFFF800;
	// lis r7,-32221
	ctx.r7.s64 = -2111635456;
	// add r28,r8,r9
	ctx.r28.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r7,952
	ctx.r9.s64 = ctx.r7.s64 + 952;
	// lwzx r7,r11,r10
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x820c8c64
	if (!ctx.cr6.eq) goto loc_820C8C64;
	// lfsx f0,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f2
	ctx.cr6.compare(ctx.f0.f64, ctx.f2.f64);
	// beq cr6,0x820c8d64
	if (ctx.cr6.eq) goto loc_820C8D64;
loc_820C8C64:
	// stfsx f2,r11,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, temp.u32);
	// stwx r8,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r31,0
	ctx.r31.s64 = 0;
	// lfd f29,9960(r11)
	ctx.f29.u64 = REX_LOAD_U64(ctx.r11.u32 + 9960);
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// lfd f30,6408(r10)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r10.u32 + 6408);
	// lfs f31,9540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9540);
	ctx.f31.f64 = double(temp.f32);
	// lfs f28,6400(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 6400);
	ctx.f28.f64 = double(temp.f32);
	// b 0x820c8ca0
	goto loc_820C8CA0;
loc_820C8C98:
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_820C8CA0:
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f1,f0,f28
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// bne cr6,0x820c8cd0
	if (!ctx.cr6.eq) goto loc_820C8CD0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x820c8a90
	ctx.lr = 0x820C8CC8;
	sub_820C8A90(ctx, base);
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_820C8CD0:
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// beq cr6,0x820c8d0c
	if (ctx.cr6.eq) goto loc_820C8D0C;
	// cmplwi cr6,r8,2
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 2, ctx.xer);
	// beq cr6,0x820c8d00
	if (ctx.cr6.eq) goto loc_820C8D00;
	// cmplwi cr6,r8,3
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 3, ctx.xer);
	// bne cr6,0x820c8d00
	if (!ctx.cr6.eq) goto loc_820C8D00;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x820c8cf4
	if (!ctx.cr6.eq) goto loc_820C8CF4;
	// fdivs f2,f31,f2
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f31.f64 / ctx.f2.f64));
loc_820C8CF4:
	// bl 0x8212ac88
	ctx.lr = 0x820C8CF8;
	sub_8212AC88(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// b 0x820c8d14
	goto loc_820C8D14;
loc_820C8D00:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820c8b40
	ctx.lr = 0x820C8D08;
	sub_820C8B40(ctx, base);
	// b 0x820c8d14
	goto loc_820C8D14;
loc_820C8D0C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820c8a90
	ctx.lr = 0x820C8D14;
	sub_820C8A90(ctx, base);
loc_820C8D14:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x820c8d24
	if (ctx.cr6.eq) goto loc_820C8D24;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820c8a90
	ctx.lr = 0x820C8D24;
	sub_820C8A90(ctx, base);
loc_820C8D24:
	// fmadd f0,f1,f30,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = std::fma(ctx.f1.f64, ctx.f30.f64, ctx.f29.f64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x820c8d44
	if (!ctx.cr6.lt) goto loc_820C8D44;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x820c8d50
	goto loc_820C8D50;
loc_820C8D44:
	// cmpwi cr6,r11,1023
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1023, ctx.xer);
	// ble cr6,0x820c8d50
	if (!ctx.cr6.gt) goto loc_820C8D50;
	// li r11,1023
	ctx.r11.s64 = 1023;
loc_820C8D50:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// sth r11,0(r30)
	REX_STORE_U16(ctx.r30.u32 + 0, ctx.r11.u16);
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// cmpwi cr6,r31,1024
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1024, ctx.xer);
	// blt cr6,0x820c8c98
	if (ctx.cr6.lt) goto loc_820C8C98;
loc_820C8D64:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a8a4
	ctx.lr = 0x820C8D74;
	__restfpr_28(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
