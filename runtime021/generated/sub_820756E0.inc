DEFINE_REX_FUNC(sub_820756E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lis r10,-32218
	ctx.r10.s64 = -2111438848;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,-6616(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -6616);
	// lwz r11,-6624(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -6624);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r3,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,44(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82075720;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,120(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 120);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82075734;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,-32234
	ctx.r10.s64 = -2112487424;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// addi r10,r10,-22612
	ctx.r10.s64 = ctx.r10.s64 + -22612;
	// lwz r11,-6596(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + -6596);
	// stb r3,9(r11)
	REX_STORE_U8(ctx.r11.u32 + 9, ctx.r3.u8);
	// beq cr6,0x82075760
	if (ctx.cr6.eq) goto loc_82075760;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f0,9604(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9604);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82075768
	goto loc_82075768;
loc_82075760:
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f0,9600(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9600);
	ctx.f0.f64 = double(temp.f32);
loc_82075768:
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// subfic r10,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r9.u64;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// subfe r7,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// rlwinm r10,r7,0,24,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xF0;
	// lis r6,-32221
	ctx.r6.s64 = -2111635456;
	// lis r5,-32221
	ctx.r5.s64 = -2111635456;
	// lfs f13,18248(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18248);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r10,r10,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f12,9608(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9608);
	ctx.f12.f64 = double(temp.f32);
	// li r4,480
	ctx.r4.s64 = 480;
	// addi r3,r10,640
	ctx.r3.s64 = ctx.r10.s64 + 640;
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// stfs f13,-1784(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + -1784, temp.u32);
	// stw r4,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r4.u32);
	// stfs f0,-1776(r5)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + -1776, temp.u32);
	// stw r3,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
