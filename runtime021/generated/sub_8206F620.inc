DEFINE_REX_FUNC(sub_8206F620) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8206F628;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a854
	ctx.lr = 0x8206F630;
	__savefpr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lis r28,-32768
	ctx.r28.s64 = -2147483648;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r11,r28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r28.s32, ctx.xer);
	// beq cr6,0x8206f908
	if (ctx.cr6.eq) goto loc_8206F908;
	// lis r12,7
	ctx.r12.s64 = 458752;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// lis r29,-32768
	ctx.r29.s64 = -2147483648;
	// and r9,r11,r12
	ctx.r9.u64 = ctx.r11.u64 & ctx.r12.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8206f670
	if (ctx.cr6.eq) goto loc_8206F670;
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x8206f694
	goto loc_8206F694;
loc_8206F670:
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8206f690
	if (ctx.cr6.eq) goto loc_8206F690;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x8206f688
	if (ctx.cr6.eq) goto loc_8206F688;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x8206f690
	if (!ctx.cr6.eq) goto loc_8206F690;
loc_8206F688:
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x8206f694
	goto loc_8206F694;
loc_8206F690:
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
loc_8206F694:
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stb r31,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r31.u8);
	// li r4,241
	ctx.r4.s64 = 241;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206F6B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r12,7
	ctx.r12.s64 = 458752;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// ori r12,r12,50881
	ctx.r12.u64 = ctx.r12.u64 | 50881;
	// and r9,r11,r12
	ctx.r9.u64 = ctx.r11.u64 & ctx.r12.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8206f6e8
	if (!ctx.cr6.eq) goto loc_8206F6E8;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8206f908
	if (ctx.cr6.eq) goto loc_8206F908;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// beq cr6,0x8206f6e8
	if (ctx.cr6.eq) goto loc_8206F6E8;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x8206f6ec
	if (!ctx.cr6.eq) goto loc_8206F6EC;
loc_8206F6E8:
	// lwz r31,84(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_8206F6EC:
	// cmpw cr6,r11,r28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r28.s32, ctx.xer);
	// beq cr6,0x8206f908
	if (ctx.cr6.eq) goto loc_8206F908;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,196(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 196);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206F708;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f30,9536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x8206f720
	if (!ctx.cr6.lt) goto loc_8206F720;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8206F720:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f31,9588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9588);
	ctx.f31.f64 = double(temp.f32);
	// lwz r9,200(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 200);
	// fmuls f28,f0,f31
	ctx.f28.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8206F740;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f30.f64);
	// bge cr6,0x8206f74c
	if (!ctx.cr6.lt) goto loc_8206F74C;
	// fneg f1,f1
	ctx.f1.u64 = ctx.f1.u64 ^ 0x8000000000000000;
loc_8206F74C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// fmuls f29,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,119
	ctx.r4.s64 = 119;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206F76C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r9,r28
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r28.s32, ctx.xer);
	// beq cr6,0x8206f780
	if (ctx.cr6.eq) goto loc_8206F780;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82082700
	ctx.lr = 0x8206F780;
	sub_82082700(ctx, base);
loc_8206F780:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,196(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 196);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206F794;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f30.f64);
	// ble cr6,0x8206f7c8
	if (!ctx.cr6.gt) goto loc_8206F7C8;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,188(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 188);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206F7B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,119
	ctx.r4.s64 = 119;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x8208b570
	ctx.lr = 0x8206F7C0;
	sub_8208B570(ctx, base);
	// fadds f31,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f31.f64 + ctx.f1.f64));
	// b 0x8206f7f0
	goto loc_8206F7F0;
loc_8206F7C8:
	// li r4,119
	ctx.r4.s64 = 119;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8208b570
	ctx.lr = 0x8206F7D4;
	sub_8208B570(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,188(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 188);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206F7EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fsubs f31,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f31.f64 - ctx.f1.f64));
loc_8206F7F0:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,122
	ctx.r4.s64 = 122;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206F80C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r9,r28
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r28.s32, ctx.xer);
	// beq cr6,0x8206f820
	if (ctx.cr6.eq) goto loc_8206F820;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82082700
	ctx.lr = 0x8206F820;
	sub_82082700(ctx, base);
loc_8206F820:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,192(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 192);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8206F834;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,122
	ctx.r4.s64 = 122;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// bl 0x8208b570
	ctx.lr = 0x8206F844;
	sub_8208B570(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fadds f27,f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = double(float(ctx.f30.f64 + ctx.f1.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,232(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 232);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8206F85C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f30,18248(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 18248);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f0,f1,f30
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// lwz r5,228(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 228);
	// fmuls f29,f0,f29
	ctx.f29.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8206F880;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fmuls f13,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// li r4,119
	ctx.r4.s64 = 119;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmuls f30,f13,f28
	ctx.f30.f64 = double(float(ctx.f13.f64 * ctx.f28.f64));
	// bl 0x8208b6f8
	ctx.lr = 0x8206F898;
	sub_8208B6F8(ctx, base);
	// li r4,122
	ctx.r4.s64 = 122;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f27.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8208b6f8
	ctx.lr = 0x8206F8A8;
	sub_8208B6F8(ctx, base);
	// li r4,239
	ctx.r4.s64 = 239;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8208b6f8
	ctx.lr = 0x8206F8B8;
	sub_8208B6F8(ctx, base);
	// li r4,240
	ctx.r4.s64 = 240;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x8208b6f8
	ctx.lr = 0x8206F8C8;
	sub_8208B6F8(ctx, base);
	// li r4,235
	ctx.r4.s64 = 235;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fsubs f1,f27,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f27.f64 - ctx.f29.f64));
	// bl 0x8208b6f8
	ctx.lr = 0x8206F8D8;
	sub_8208B6F8(ctx, base);
	// li r4,236
	ctx.r4.s64 = 236;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fadds f1,f29,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f29.f64 + ctx.f27.f64));
	// bl 0x8208b6f8
	ctx.lr = 0x8206F8E8;
	sub_8208B6F8(ctx, base);
	// li r4,238
	ctx.r4.s64 = 238;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fadds f1,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f30.f64 + ctx.f31.f64));
	// bl 0x8208b6f8
	ctx.lr = 0x8206F8F8;
	sub_8208B6F8(ctx, base);
	// li r4,237
	ctx.r4.s64 = 237;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fsubs f1,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f31.f64 - ctx.f30.f64));
	// bl 0x8208b6f8
	ctx.lr = 0x8206F908;
	sub_8208B6F8(ctx, base);
loc_8206F908:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8212a8a0
	ctx.lr = 0x8206F914;
	__restfpr_27(ctx, base);
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
