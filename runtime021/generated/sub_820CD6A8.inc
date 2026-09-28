DEFINE_REX_FUNC(sub_820CD6A8) {
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
	// stfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f30.u64);
	// stfd f31,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// cmplwi cr6,r31,18
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 18, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bgt cr6,0x820cdb64
	if (ctx.cr6.gt) goto loc_820CDB64;
	// lis r12,-32256
	ctx.r12.s64 = -2113929216;
	// addi r12,r12,14200
	ctx.r12.s64 = ctx.r12.s64 + 14200;
	// rlwinm r0,r31,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32243
	ctx.r12.s64 = -2113077248;
	// addi r12,r12,-10492
	ctx.r12.s64 = ctx.r12.s64 + -10492;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r31.u32) {
	case 0:
		goto loc_820CD704;
	case 1:
		goto loc_820CD724;
	case 2:
		goto loc_820CD750;
	case 3:
		goto loc_820CD768;
	case 4:
		goto loc_820CD7CC;
	case 5:
		goto loc_820CD7FC;
	case 6:
		goto loc_820CD838;
	case 7:
		goto loc_820CD8D8;
	case 8:
		goto loc_820CD95C;
	case 9:
		goto loc_820CD9BC;
	case 10:
		goto loc_820CDA1C;
	case 11:
		goto loc_820CDA50;
	case 12:
		goto loc_820CDA94;
	case 13:
		goto loc_820CDAC0;
	case 14:
		goto loc_820CDAE8;
	case 15:
		goto loc_820CDB10;
	case 16:
		goto loc_820CDB44;
	case 17:
		goto loc_820CD8C8;
	case 18:
		goto loc_820CD8D8;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820CD704:
	// lwz r11,21576(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21576);
	// lfs f0,21592(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 21592);
	ctx.f0.f64 = double(temp.f32);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// b 0x820cdb68
	goto loc_820CDB68;
loc_820CD724:
	// lwz r11,21576(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21576);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820cdb64
	if (ctx.cr6.eq) goto loc_820CDB64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfs f0,21588(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 21588);
	ctx.f0.f64 = double(temp.f32);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// b 0x820cdb68
	goto loc_820CDB68;
loc_820CD750:
	// lwz r11,16560(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16560);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
loc_820CD75C:
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// b 0x820cdb68
	goto loc_820CDB68;
loc_820CD768:
	// lwz r11,21616(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21616);
	// lwz r9,21576(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 21576);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
loc_820CD794:
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f12,9536(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 9536);
	ctx.f12.f64 = double(temp.f32);
loc_820CD79C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,1896(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1896);
	ctx.f0.f64 = double(temp.f32);
loc_820CD7A4:
	// fmuls f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x820cd7b8
	if (!ctx.cr6.lt) goto loc_820CD7B8;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
	// b 0x820cd7c4
	goto loc_820CD7C4;
loc_820CD7B8:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x820cd7c4
	if (ctx.cr6.gt) goto loc_820CD7C4;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_820CD7C4:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64;
	// b 0x820cdb68
	goto loc_820CDB68;
loc_820CD7CC:
	// lwz r11,21576(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21576);
	// lwz r9,21620(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 21620);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
loc_820CD7F0:
	// frsp f11,f11
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fdivs f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 / ctx.f13.f64));
	// b 0x820cd794
	goto loc_820CD794;
loc_820CD7FC:
	// lwz r11,21576(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21576);
	// lwz r9,21620(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 21620);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// lwz r7,21616(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 21616);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// std r6,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// b 0x820cd7f0
	goto loc_820CD7F0;
loc_820CD838:
	// lwz r11,21624(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21624);
	// lwz r8,10896(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 10896);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// clrlwi r9,r11,29
	ctx.r9.u64 = ctx.r11.u32 & 0x7;
	// addi r6,r10,16
	ctx.r6.s64 = ctx.r10.s64 + 16;
	// clrlwi r10,r7,29
	ctx.r10.u64 = ctx.r7.u32 & 0x7;
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwbrx r31,r7,r8
	ctx.r31.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32));
	// cmpldi cr6,r31,0
	ctx.cr6.compare<uint64_t>(ctx.r31.u64, 0, ctx.xer);
	// lwbrx r30,r10,r8
	ctx.r30.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32));
	// lwbrx r10,r9,r8
	ctx.r10.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32));
	// beq cr6,0x820cdb64
	if (ctx.cr6.eq) goto loc_820CDB64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// cmpldi cr6,r10,0
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, 0, ctx.xer);
	// stw r11,21624(r3)
	REX_STORE_U32(ctx.r3.u32 + 21624, ctx.r11.u32);
	// beq cr6,0x820cdb64
	if (ctx.cr6.eq) goto loc_820CDB64;
	// cmpldi cr6,r30,0
	ctx.cr6.compare<uint64_t>(ctx.r30.u64, 0, ctx.xer);
	// beq cr6,0x820cdb64
	if (ctx.cr6.eq) goto loc_820CDB64;
	// li r11,1
	ctx.r11.s64 = 1;
	// cmpld cr6,r10,r30
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, ctx.r30.u64, ctx.xer);
	// rldicr r11,r11,32,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bgt cr6,0x820cd8ac
	if (ctx.cr6.gt) goto loc_820CD8AC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_820CD8AC:
	// cmpld cr6,r31,r10
	ctx.cr6.compare<uint64_t>(ctx.r31.u64, ctx.r10.u64, ctx.xer);
	// bgt cr6,0x820cd8b8
	if (ctx.cr6.gt) goto loc_820CD8B8;
	// add r31,r31,r11
	ctx.r31.u64 = ctx.r31.u64 + ctx.r11.u64;
loc_820CD8B8:
	// subf r3,r10,r31
	ctx.r3.u64 = ctx.r31.u64 - ctx.r10.u64;
	// bl 0x8212b180
	ctx.lr = 0x820CD8C0;
	sub_8212B180(ctx, base);
	// subf r3,r30,r31
	ctx.r3.u64 = ctx.r31.u64 - ctx.r30.u64;
	// b 0x820cd998
	goto loc_820CD998;
loc_820CD8C8:
	// lwz r11,23348(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 23348);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x820cd75c
	goto loc_820CD75C;
loc_820CD8D8:
	// bl 0x820cd148
	ctx.lr = 0x820CD8DC;
	sub_820CD148(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cdb64
	if (ctx.cr0.eq) goto loc_820CDB64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r11,5148
	ctx.r7.s64 = ctx.r11.s64 + 5148;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// cmpwi cr6,r31,7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 7, ctx.xer);
	// lwz r9,5148(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 5148);
	// ld r11,4(r7)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r7.u32 + 4);
	// ld r10,484(r7)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r7.u32 + 484);
	// ld r8,12(r7)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r7.u32 + 12);
	// ld r7,492(r7)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r7.u32 + 492);
	// subf r31,r11,r10
	ctx.r31.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// subf r3,r8,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r8.u64;
	// bne cr6,0x820cd924
	if (!ctx.cr6.eq) goto loc_820CD924;
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// subf r3,r11,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r11.u64;
loc_820CD924:
	// cmpldi cr6,r3,0
	ctx.cr6.compare<uint64_t>(ctx.r3.u64, 0, ctx.xer);
	// beq cr6,0x820cdb64
	if (ctx.cr6.eq) goto loc_820CDB64;
	// bl 0x8212b180
	ctx.lr = 0x820CD930;
	sub_8212B180(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x8212b180
	ctx.lr = 0x820CD93C;
	sub_8212B180(ctx, base);
	// fdiv f11,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f31.f64 / ctx.f1.f64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f13,9540(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9540);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9536);
	ctx.f12.f64 = double(temp.f32);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fsubs f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// b 0x820cd79c
	goto loc_820CD79C;
loc_820CD95C:
	// bl 0x820cd148
	ctx.lr = 0x820CD960;
	sub_820CD148(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cdb64
	if (ctx.cr0.eq) goto loc_820CDB64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r11,r11,5148
	ctx.r11.s64 = ctx.r11.s64 + 5148;
	// ld r10,124(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 124);
	// ld r9,604(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 604);
	// subf r31,r10,r9
	ctx.r31.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmpldi cr6,r31,0
	ctx.cr6.compare<uint64_t>(ctx.r31.u64, 0, ctx.xer);
	// beq cr6,0x820cdb64
	if (ctx.cr6.eq) goto loc_820CDB64;
	// ld r10,132(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 132);
	// ld r11,612(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 612);
loc_820CD98C:
	// subf r3,r10,r11
	ctx.r3.u64 = ctx.r11.u64 - ctx.r10.u64;
	// bl 0x8212b180
	ctx.lr = 0x820CD994;
	sub_8212B180(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820CD998:
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x8212b180
	ctx.lr = 0x820CD9A0;
	sub_8212B180(ctx, base);
	// fdiv f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64 / ctx.f1.f64;
loc_820CD9A4:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// frsp f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f12,9536(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9536);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,1896(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1896);
	ctx.f0.f64 = double(temp.f32);
	// b 0x820cd7a4
	goto loc_820CD7A4;
loc_820CD9BC:
	// bl 0x820cd148
	ctx.lr = 0x820CD9C0;
	sub_820CD148(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cdb64
	if (ctx.cr0.eq) goto loc_820CDB64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r31,r11,5148
	ctx.r31.s64 = ctx.r11.s64 + 5148;
	// ld r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 124);
	// ld r10,604(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 604);
	// subf r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmpldi cr6,r3,0
	ctx.cr6.compare<uint64_t>(ctx.r3.u64, 0, ctx.xer);
	// beq cr6,0x820cdb64
	if (ctx.cr6.eq) goto loc_820CDB64;
	// bl 0x8212b180
	ctx.lr = 0x820CD9E8;
	sub_8212B180(ctx, base);
	// ld r11,132(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 132);
	// ld r10,612(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 612);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// subf r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	// bl 0x8212b180
	ctx.lr = 0x820CD9FC;
	sub_8212B180(ctx, base);
	// ld r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 140);
	// ld r10,620(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 620);
	// fsub f30,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f31.f64 - ctx.f1.f64;
	// subf r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	// bl 0x8212b180
	ctx.lr = 0x820CDA10;
	sub_8212B180(ctx, base);
	// fsub f13,f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f30.f64 - ctx.f1.f64;
	// fdiv f13,f13,f31
	ctx.f13.f64 = ctx.f13.f64 / ctx.f31.f64;
	// b 0x820cd9a4
	goto loc_820CD9A4;
loc_820CDA1C:
	// bl 0x820cd148
	ctx.lr = 0x820CDA20;
	sub_820CD148(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cdb64
	if (ctx.cr0.eq) goto loc_820CDB64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r11,r11,5148
	ctx.r11.s64 = ctx.r11.s64 + 5148;
	// ld r10,124(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 124);
	// ld r9,604(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 604);
	// subf r31,r10,r9
	ctx.r31.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmpldi cr6,r31,0
	ctx.cr6.compare<uint64_t>(ctx.r31.u64, 0, ctx.xer);
	// beq cr6,0x820cdb64
	if (ctx.cr6.eq) goto loc_820CDB64;
	// ld r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 140);
	// ld r11,620(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 620);
	// b 0x820cd98c
	goto loc_820CD98C;
loc_820CDA50:
	// bl 0x820cd148
	ctx.lr = 0x820CDA54;
	sub_820CD148(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cdb64
	if (ctx.cr0.eq) goto loc_820CDB64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r8,r11,5148
	ctx.r8.s64 = ctx.r11.s64 + 5148;
	// ld r11,444(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 444);
	// ld r10,924(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 924);
	// ld r9,436(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 436);
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// ld r11,4(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 4);
	// ld r10,484(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 484);
	// ld r8,916(r8)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r8.u32 + 916);
	// subf r9,r9,r7
	ctx.r9.u64 = ctx.r7.u64 - ctx.r9.u64;
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
loc_820CDA88:
	// subf r4,r11,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r11.u64;
loc_820CDA8C:
	// bl 0x820cc9c0
	ctx.lr = 0x820CDA90;
	sub_820CC9C0(ctx, base);
	// b 0x820cdb68
	goto loc_820CDB68;
loc_820CDA94:
	// bl 0x820cd148
	ctx.lr = 0x820CDA98;
	sub_820CD148(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cdb64
	if (ctx.cr0.eq) goto loc_820CDB64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r8,r11,5148
	ctx.r8.s64 = ctx.r11.s64 + 5148;
	// ld r11,4(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 4);
	// ld r10,484(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 484);
	// ld r9,452(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 452);
	// ld r8,932(r8)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r8.u32 + 932);
loc_820CDAB8:
	// subf r3,r9,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r9.u64;
	// b 0x820cda88
	goto loc_820CDA88;
loc_820CDAC0:
	// bl 0x820cd148
	ctx.lr = 0x820CDAC4;
	sub_820CD148(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cdb64
	if (ctx.cr0.eq) goto loc_820CDB64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r8,r11,5148
	ctx.r8.s64 = ctx.r11.s64 + 5148;
	// ld r11,4(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 4);
	// ld r10,484(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 484);
	// ld r9,236(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 236);
	// ld r8,716(r8)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r8.u32 + 716);
	// b 0x820cdab8
	goto loc_820CDAB8;
loc_820CDAE8:
	// bl 0x820cd148
	ctx.lr = 0x820CDAEC;
	sub_820CD148(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cdb64
	if (ctx.cr0.eq) goto loc_820CDB64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r8,r11,5148
	ctx.r8.s64 = ctx.r11.s64 + 5148;
	// ld r11,4(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 4);
	// ld r10,484(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 484);
	// ld r9,92(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 92);
	// ld r8,572(r8)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r8.u32 + 572);
	// b 0x820cdab8
	goto loc_820CDAB8;
loc_820CDB10:
	// bl 0x820cd148
	ctx.lr = 0x820CDB14;
	sub_820CD148(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cdb64
	if (ctx.cr0.eq) goto loc_820CDB64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r8,r11,5148
	ctx.r8.s64 = ctx.r11.s64 + 5148;
	// ld r11,460(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 460);
	// ld r10,940(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 940);
loc_820CDB2C:
	// ld r9,4(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 4);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// ld r8,484(r8)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r8.u32 + 484);
	// rldicr r3,r11,1,62
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// subf r4,r9,r8
	ctx.r4.u64 = ctx.r8.u64 - ctx.r9.u64;
	// b 0x820cda8c
	goto loc_820CDA8C;
loc_820CDB44:
	// bl 0x820cd148
	ctx.lr = 0x820CDB48;
	sub_820CD148(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820cdb64
	if (ctx.cr0.eq) goto loc_820CDB64;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// addi r8,r11,5148
	ctx.r8.s64 = ctx.r11.s64 + 5148;
	// ld r11,468(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 468);
	// ld r10,948(r8)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r8.u32 + 948);
	// b 0x820cdb2c
	goto loc_820CDB2C;
loc_820CDB64:
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
loc_820CDB68:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f31,-32(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
