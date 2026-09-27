DEFINE_REX_FUNC(sub_82066CD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 424);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82066e48
	if (ctx.cr6.eq) goto loc_82066E48;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfs f12,428(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 428);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lfs f0,9700(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9700);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,9540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9540);
	ctx.f13.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
	// fmuls f8,f9,f1
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f1.f64));
	// fmadds f0,f8,f0,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f8.f64, ctx.f0.f64, ctx.f12.f64)));
	// stfs f0,428(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 428, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82066d4c
	if (!ctx.cr6.gt) goto loc_82066D4C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f13,428(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 428, temp.u32);
	// stb r30,424(r31)
	REX_STORE_U8(ctx.r31.u32 + 424, ctx.r30.u8);
	// stb r11,340(r31)
	REX_STORE_U8(ctx.r31.u32 + 340, ctx.r11.u8);
	// b 0x82066de0
	goto loc_82066DE0;
loc_82066D4C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,9536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9536);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82066de0
	if (!ctx.cr6.lt) goto loc_82066DE0;
	// lwz r11,344(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 344);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f13,428(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 428, temp.u32);
	// stb r10,424(r31)
	REX_STORE_U8(ctx.r31.u32 + 424, ctx.r10.u8);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82066db4
	if (!ctx.cr6.eq) goto loc_82066DB4;
	// lwz r11,360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// stw r10,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82066dd0
	if (!ctx.cr6.eq) goto loc_82066DD0;
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82066ddc
	if (ctx.cr6.eq) goto loc_82066DDC;
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82066ddc
	if (ctx.cr6.eq) goto loc_82066DDC;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// b 0x82066dd8
	goto loc_82066DD8;
loc_82066DB4:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82066de0
	if (!ctx.cr6.eq) goto loc_82066DE0;
	// lwz r11,364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82066ddc
	if (ctx.cr6.eq) goto loc_82066DDC;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r10.u32);
loc_82066DD0:
	// lwz r3,356(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82066DD8:
	// bctrl 
	ctx.lr = 0x82066DDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82066DDC:
	// stw r30,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r30.u32);
loc_82066DE0:
	// lhz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82066e14
	if (ctx.cr6.eq) goto loc_82066E14;
	// addi r11,r31,20
	ctx.r11.s64 = ctx.r31.s64 + 20;
loc_82066DF4:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,428(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 428);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stfs f0,12(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// lhz r8,4(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82066df4
	if (ctx.cr6.lt) goto loc_82066DF4;
loc_82066E14:
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82066e48
	if (ctx.cr6.eq) goto loc_82066E48;
	// addi r11,r31,276
	ctx.r11.s64 = ctx.r31.s64 + 276;
loc_82066E28:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,428(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 428);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stfs f0,12(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// lhz r8,6(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82066e28
	if (ctx.cr6.lt) goto loc_82066E28;
loc_82066E48:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
