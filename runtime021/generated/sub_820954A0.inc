DEFINE_REX_FUNC(sub_820954A0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82095694
	if (ctx.cr6.eq) goto loc_82095694;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82095694
	if (ctx.cr6.eq) goto loc_82095694;
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// addi r11,r11,-80
	ctx.r11.s64 = ctx.r11.s64 + -80;
	// cmplwi cr6,r11,21
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 21, ctx.xer);
	// bgt cr6,0x82095694
	if (ctx.cr6.gt) goto loc_82095694;
	// lis r12,-32247
	ctx.r12.s64 = -2113339392;
	// addi r12,r12,21756
	ctx.r12.s64 = ctx.r12.s64 + 21756;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82095588;
	case 1:
		goto loc_82095694;
	case 2:
		goto loc_82095694;
	case 3:
		goto loc_82095694;
	case 4:
		goto loc_82095694;
	case 5:
		goto loc_82095554;
	case 6:
		goto loc_82095694;
	case 7:
		goto loc_82095694;
	case 8:
		goto loc_82095694;
	case 9:
		goto loc_82095694;
	case 10:
		goto loc_82095694;
	case 11:
		goto loc_82095694;
	case 12:
		goto loc_82095694;
	case 13:
		goto loc_82095694;
	case 14:
		goto loc_82095694;
	case 15:
		goto loc_82095694;
	case 16:
		goto loc_82095694;
	case 17:
		goto loc_82095694;
	case 18:
		goto loc_82095694;
	case 19:
		goto loc_82095574;
	case 20:
		goto loc_8209562C;
	case 21:
		goto loc_820955A0;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82095554:
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082670
	ctx.lr = 0x8209555C;
	sub_82082670(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r7,236(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 236);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82095570;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82095694
	goto loc_82095694;
loc_82095574:
	// bl 0x82082bb0
	ctx.lr = 0x82095578;
	sub_82082BB0(ctx, base);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82058508
	ctx.lr = 0x82095584;
	sub_82058508(ctx, base);
	// b 0x82095694
	goto loc_82095694;
loc_82095588:
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82082700
	ctx.lr = 0x82095590;
	sub_82082700(ctx, base);
	// lwz r11,216(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 216);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// b 0x82095690
	goto loc_82095690;
loc_820955A0:
	// bl 0x82082890
	ctx.lr = 0x820955A4;
	sub_82082890(ctx, base);
	// lwz r10,156(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// sth r3,148(r31)
	REX_STORE_U16(ctx.r31.u32 + 148, ctx.r3.u16);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r9,76(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,156(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r10,10316(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 10316);
	// bne cr6,0x820955cc
	if (!ctx.cr6.eq) goto loc_820955CC;
	// addi r4,r10,12
	ctx.r4.s64 = ctx.r10.s64 + 12;
	// b 0x820955d8
	goto loc_820955D8;
loc_820955CC:
	// lwz r10,28(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_820955D8:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82094858
	ctx.lr = 0x820955E4;
	sub_82094858(ctx, base);
	// lhz r11,160(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 160);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82095694
	if (ctx.cr6.eq) goto loc_82095694;
	// lhz r10,100(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 100);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82095694
	if (!ctx.cr6.lt) goto loc_82095694;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// extsw r8,r11
	ctx.r8.s64 = ctx.r11.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fdivs f1,f10,f9
	ctx.f1.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// b 0x82095680
	goto loc_82095680;
loc_8209562C:
	// bl 0x82082bb0
	ctx.lr = 0x82095630;
	sub_82082BB0(ctx, base);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82094b48
	ctx.lr = 0x8209563C;
	sub_82094B48(ctx, base);
	// lhz r11,160(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 160);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82095694
	if (ctx.cr6.eq) goto loc_82095694;
	// lhz r10,100(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 100);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82095694
	if (!ctx.cr6.lt) goto loc_82095694;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// fdivs f1,f9,f11
	ctx.f1.f64 = double(float(ctx.f9.f64 / ctx.f11.f64));
loc_82095680:
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,216(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 216);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_82095690:
	// bctrl 
	ctx.lr = 0x82095694;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82095694:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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
