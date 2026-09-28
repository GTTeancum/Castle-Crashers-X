DEFINE_REX_FUNC(sub_821434D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x821434E0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x821434f8
	if (!ctx.cr6.eq) goto loc_821434F8;
loc_821434F0:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x821436a0
	goto loc_821436A0;
loc_821434F8:
	// lis r29,-32221
	ctx.r29.s64 = -2111635456;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r4,116
	ctx.r4.s64 = 116;
	// stw r30,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,24184(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82143518;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x821434f0
	if (ctx.cr0.eq) goto loc_821434F0;
	// stw r31,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r31.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f12,-11312(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -11312);
	ctx.f12.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,100
	ctx.r10.s64 = 100;
	// stfs f12,32(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// lfs f0,9540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9540);
	ctx.f0.f64 = double(temp.f32);
	// sth r11,92(r31)
	REX_STORE_U16(ctx.r31.u32 + 92, ctx.r11.u16);
	// lfs f13,9536(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9536);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// lfs f12,-11316(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -11316);
	ctx.f12.f64 = double(temp.f32);
	// stw r30,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// lfs f11,1896(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 1896);
	ctx.f11.f64 = double(temp.f32);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// stfs f0,28(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// stw r30,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// sth r30,56(r31)
	REX_STORE_U16(ctx.r31.u32 + 56, ctx.r30.u16);
	// stfs f0,40(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// sth r30,58(r31)
	REX_STORE_U16(ctx.r31.u32 + 58, ctx.r30.u16);
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// stw r30,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// stfs f13,48(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stfs f0,52(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// sth r30,94(r31)
	REX_STORE_U16(ctx.r31.u32 + 94, ctx.r30.u16);
	// stfs f0,60(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 60, temp.u32);
	// sth r10,96(r31)
	REX_STORE_U16(ctx.r31.u32 + 96, ctx.r10.u16);
	// stfs f0,64(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// li r3,644
	ctx.r3.s64 = 644;
	// stfs f12,76(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// stfs f13,80(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// stfs f11,108(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// lwz r11,24184(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821435E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821434f0
	if (ctx.cr0.eq) goto loc_821434F0;
	// lwz r11,24184(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24184);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,80
	ctx.r3.s64 = 80;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82143600;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821434f0
	if (ctx.cr0.eq) goto loc_821434F0;
	// lwz r11,24184(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24184);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,65
	ctx.r3.s64 = 65;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82143620;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821434f0
	if (ctx.cr0.eq) goto loc_821434F0;
	// lwz r11,24184(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24184);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,65
	ctx.r3.s64 = 65;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82143640;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821434f0
	if (ctx.cr0.eq) goto loc_821434F0;
	// lwz r11,24184(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24184);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,102
	ctx.r3.s64 = 102;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82143660;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821434f0
	if (ctx.cr0.eq) goto loc_821434F0;
	// lwz r11,24184(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24184);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,104
	ctx.r3.s64 = 104;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82143680;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821434f0
	if (ctx.cr0.eq) goto loc_821434F0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821476e0
	ctx.lr = 0x82143694;
	sub_821476E0(ctx, base);
	// cntlzw r11,r3
	ctx.r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r3,r11,1
	ctx.r3.u64 = ctx.r11.u64 ^ 1;
loc_821436A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
