DEFINE_REX_FUNC(sub_8209D028) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// lwz r3,804(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 804);
	// fmr f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f1.f64;
	// fmr f4,f2
	ctx.f4.f64 = ctx.f2.f64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r30,-6604(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -6604);
	// beq cr6,0x8209d0fc
	if (ctx.cr6.eq) goto loc_8209D0FC;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_8209D05C:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8209d05c
	if (!ctx.cr6.eq) goto loc_8209D05C;
	// subf r8,r3,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// addic. r31,r7,1
	ctx.xer.ca = ctx.r7.u32 > 4294967294;
	ctx.r31.s64 = ctx.r7.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble 0x8209d0a0
	if (!ctx.cr0.gt) goto loc_8209D0A0;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
loc_8209D088:
	// lbzx r7,r11,r3
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r11,r31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r31.s32, ctx.xer);
	// sth r7,0(r8)
	REX_STORE_U16(ctx.r8.u32 + 0, ctx.r7.u16);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// blt cr6,0x8209d088
	if (ctx.cr6.lt) goto loc_8209D088;
loc_8209D0A0:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mulli r9,r9,212
	ctx.r9.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(212));
	// add. r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8209d0c0
	if (!ctx.cr0.eq) goto loc_8209D0C0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,564
	ctx.r3.s64 = ctx.r11.s64 + 564;
	// bl 0x8208c5d8
	ctx.lr = 0x8209D0BC;
	sub_8208C5D8(ctx, base);
	// b 0x8209d0fc
	goto loc_8209D0FC;
loc_8209D0C0:
	// clrldi r11,r5,32
	ctx.r11.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// lwz r9,812(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 812);
	// clrldi r8,r6,32
	ctx.r8.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// std r11,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r11.u64);
	// lfd f0,160(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// std r8,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r8.u64);
	// lfd f13,160(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// frsp f1,f11
	ctx.f1.f64 = double(float(ctx.f11.f64));
	// frsp f2,f12
	ctx.f2.f64 = double(float(ctx.f12.f64));
	// bl 0x820a9e98
	ctx.lr = 0x8209D0FC;
	sub_820A9E98(ctx, base);
loc_8209D0FC:
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
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
