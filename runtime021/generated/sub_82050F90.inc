DEFINE_REX_FUNC(sub_82050F90) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,44(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82050fc8
	if (ctx.cr6.eq) goto loc_82050FC8;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82050fd8
	if (!ctx.cr6.eq) goto loc_82050FD8;
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x82050fcc
	goto loc_82050FCC;
loc_82050FC8:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82050FCC:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5958
	ctx.lr = 0x82050FD8;
	sub_820B5958(ctx, base);
loc_82050FD8:
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// cmplwi cr6,r11,17
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 17, ctx.xer);
	// bgt cr6,0x820510dc
	if (ctx.cr6.gt) goto loc_820510DC;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,4092
	ctx.r12.s64 = ctx.r12.s64 + 4092;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82051044;
	case 1:
		goto loc_8205104C;
	case 2:
		goto loc_82051054;
	case 3:
		goto loc_8205105C;
	case 4:
		goto loc_82051064;
	case 5:
		goto loc_8205106C;
	case 6:
		goto loc_82051074;
	case 7:
		goto loc_8205107C;
	case 8:
		goto loc_82051084;
	case 9:
		goto loc_8205108C;
	case 10:
		goto loc_82051094;
	case 11:
		goto loc_8205109C;
	case 12:
		goto loc_820510A4;
	case 13:
		goto loc_820510AC;
	case 14:
		goto loc_820510B4;
	case 15:
		goto loc_820510BC;
	case 16:
		goto loc_820510C4;
	case 17:
		goto loc_820510CC;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82051044:
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x820510d0
	goto loc_820510D0;
loc_8205104C:
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x820510d0
	goto loc_820510D0;
loc_82051054:
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x820510d0
	goto loc_820510D0;
loc_8205105C:
	// li r5,4
	ctx.r5.s64 = 4;
	// b 0x820510d0
	goto loc_820510D0;
loc_82051064:
	// li r5,3
	ctx.r5.s64 = 3;
	// b 0x820510d0
	goto loc_820510D0;
loc_8205106C:
	// li r5,5
	ctx.r5.s64 = 5;
	// b 0x820510d0
	goto loc_820510D0;
loc_82051074:
	// li r5,6
	ctx.r5.s64 = 6;
	// b 0x820510d0
	goto loc_820510D0;
loc_8205107C:
	// li r5,7
	ctx.r5.s64 = 7;
	// b 0x820510d0
	goto loc_820510D0;
loc_82051084:
	// li r5,8
	ctx.r5.s64 = 8;
	// b 0x820510d0
	goto loc_820510D0;
loc_8205108C:
	// li r5,9
	ctx.r5.s64 = 9;
	// b 0x820510d0
	goto loc_820510D0;
loc_82051094:
	// li r5,10
	ctx.r5.s64 = 10;
	// b 0x820510d0
	goto loc_820510D0;
loc_8205109C:
	// li r5,11
	ctx.r5.s64 = 11;
	// b 0x820510d0
	goto loc_820510D0;
loc_820510A4:
	// li r5,12
	ctx.r5.s64 = 12;
	// b 0x820510d0
	goto loc_820510D0;
loc_820510AC:
	// li r5,13
	ctx.r5.s64 = 13;
	// b 0x820510d0
	goto loc_820510D0;
loc_820510B4:
	// li r5,14
	ctx.r5.s64 = 14;
	// b 0x820510d0
	goto loc_820510D0;
loc_820510BC:
	// li r5,15
	ctx.r5.s64 = 15;
	// b 0x820510d0
	goto loc_820510D0;
loc_820510C4:
	// li r5,16
	ctx.r5.s64 = 16;
	// b 0x820510d0
	goto loc_820510D0;
loc_820510CC:
	// li r5,17
	ctx.r5.s64 = 17;
loc_820510D0:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820b5958
	ctx.lr = 0x820510DC;
	sub_820B5958(ctx, base);
loc_820510DC:
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
