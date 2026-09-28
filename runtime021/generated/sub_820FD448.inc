DEFINE_REX_FUNC(sub_820FD448) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// cmpwi cr6,r4,26
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 26, ctx.xer);
	// bgt cr6,0x820fd6e4
	if (ctx.cr6.gt) goto loc_820FD6E4;
	// beq cr6,0x820fd6d0
	if (ctx.cr6.eq) goto loc_820FD6D0;
	// cmplwi cr6,r4,23
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 23, ctx.xer);
	// bgt cr6,0x820fd714
	if (ctx.cr6.gt) goto loc_820FD714;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-21192
	ctx.r12.s64 = ctx.r12.s64 + -21192;
	// lbzx r0,r12,r4
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r4.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32240
	ctx.r12.s64 = -2112880640;
	// addi r12,r12,-11100
	ctx.r12.s64 = ctx.r12.s64 + -11100;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r4.u32) {
	case 0:
		goto loc_820FD4A4;
	case 1:
		goto loc_820FD4C4;
	case 2:
		goto loc_820FD4D8;
	case 3:
		goto loc_820FD4EC;
	case 4:
		goto loc_820FD500;
	case 5:
		goto loc_820FD514;
	case 6:
		goto loc_820FD528;
	case 7:
		goto loc_820FD53C;
	case 8:
		goto loc_820FD554;
	case 9:
		goto loc_820FD56C;
	case 10:
		goto loc_820FD59C;
	case 11:
		goto loc_820FD5B0;
	case 12:
		goto loc_820FD6D0;
	case 13:
		goto loc_820FD5E4;
	case 14:
		goto loc_820FD614;
	case 15:
		goto loc_820FD62C;
	case 16:
		goto loc_820FD638;
	case 17:
		goto loc_820FD650;
	case 18:
		goto loc_820FD674;
	case 19:
		goto loc_820FD698;
	case 20:
		goto loc_820FD698;
	case 21:
		goto loc_820FD6BC;
	case 22:
		goto loc_820FD698;
	case 23:
		goto loc_820FD698;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820FD4A4:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD4C4:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lbz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 168);
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD4D8:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lbz r11,169(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 169);
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD4EC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lbz r11,170(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 170);
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD500:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lbz r11,171(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 171);
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD514:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD528:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD53C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm r11,r11,3,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x1;
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD554:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm r11,r11,4,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0x1;
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD56C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,4,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820fd58c
	if (ctx.cr0.eq) goto loc_820FD58C;
loc_820FD584:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820fd590
	goto loc_820FD590;
loc_820FD58C:
	// rlwinm r11,r11,7,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0x2;
loc_820FD590:
	// stw r11,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820fd7a8
	goto loc_820FD7A8;
loc_820FD59C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD5B0:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r5,520(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x820fd5d4
	if (ctx.cr6.lt) goto loc_820FD5D4;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lwz r4,516(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 516);
	// bl 0x82129a70
	ctx.lr = 0x820FD5CC;
	sub_82129A70(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820fd5dc
	goto loc_820FD5DC;
loc_820FD5D4:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,122
	ctx.r3.u64 = ctx.r3.u64 | 122;
loc_820FD5DC:
	// lwz r11,520(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// b 0x820fd7ac
	goto loc_820FD7AC;
loc_820FD5E4:
	// lwz r11,420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fd604
	if (ctx.cr6.eq) goto loc_820FD604;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD604:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// li r11,0
	ctx.r11.s64 = 0;
	// ori r3,r3,1168
	ctx.r3.u64 = ctx.r3.u64 | 1168;
	// b 0x820fd7ac
	goto loc_820FD7AC;
loc_820FD614:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm r11,r11,15,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0x1;
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD62C:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16385
	ctx.r3.u64 = ctx.r3.u64 | 16385;
	// b 0x820fd7b0
	goto loc_820FD7B0;
loc_820FD638:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lhz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 720);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD650:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820fd584
	if (!ctx.cr0.eq) goto loc_820FD584;
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// rlwinm r11,r11,19,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 19) & 0x2;
	// b 0x820fd590
	goto loc_820FD590;
loc_820FD674:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820fd584
	if (!ctx.cr0.eq) goto loc_820FD584;
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// rlwinm r11,r11,21,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 21) & 0x2;
	// b 0x820fd590
	goto loc_820FD590;
loc_820FD698:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// cmpwi cr6,r4,19
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 19, ctx.xer);
	// bne cr6,0x820fd6b4
	if (!ctx.cr6.eq) goto loc_820FD6B4;
	// lwz r11,532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 532);
	// b 0x820fd590
	goto loc_820FD590;
loc_820FD6B4:
	// lwz r11,536(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 536);
	// b 0x820fd590
	goto loc_820FD590;
loc_820FD6BC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,548(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 548);
	// b 0x820fd794
	goto loc_820FD794;
loc_820FD6D0:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// addi r3,r31,424
	ctx.r3.s64 = ctx.r31.s64 + 424;
	// bl 0x82108fd8
	ctx.lr = 0x820FD6E0;
	sub_82108FD8(ctx, base);
	// b 0x820fd7b0
	goto loc_820FD7B0;
loc_820FD6E4:
	// cmpwi cr6,r4,4096
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4096, ctx.xer);
	// beq cr6,0x820fd784
	if (ctx.cr6.eq) goto loc_820FD784;
	// cmpwi cr6,r4,4097
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4097, ctx.xer);
	// beq cr6,0x820fd774
	if (ctx.cr6.eq) goto loc_820FD774;
	// cmpwi cr6,r4,4098
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4098, ctx.xer);
	// beq cr6,0x820fd76c
	if (ctx.cr6.eq) goto loc_820FD76C;
	// cmpwi cr6,r4,4099
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4099, ctx.xer);
	// beq cr6,0x820fd764
	if (ctx.cr6.eq) goto loc_820FD764;
	// cmpwi cr6,r4,4100
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4100, ctx.xer);
	// beq cr6,0x820fd75c
	if (ctx.cr6.eq) goto loc_820FD75C;
	// cmpwi cr6,r4,4101
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4101, ctx.xer);
	// beq cr6,0x820fd720
	if (ctx.cr6.eq) goto loc_820FD720;
loc_820FD714:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// b 0x820fd7b0
	goto loc_820FD7B0;
loc_820FD720:
	// li r6,3
	ctx.r6.s64 = 3;
loc_820FD724:
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82108ef8
	ctx.lr = 0x820FD738;
	sub_82108EF8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x820fd77c
	if (!ctx.cr0.lt) goto loc_820FD77C;
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// ori r11,r11,4097
	ctx.r11.u64 = ctx.r11.u64 | 4097;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x820fd7b0
	if (!ctx.cr6.eq) goto loc_820FD7B0;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,122
	ctx.r3.u64 = ctx.r3.u64 | 122;
	// b 0x820fd7b0
	goto loc_820FD7B0;
loc_820FD75C:
	// li r6,6
	ctx.r6.s64 = 6;
	// b 0x820fd724
	goto loc_820FD724;
loc_820FD764:
	// li r6,5
	ctx.r6.s64 = 5;
	// b 0x820fd724
	goto loc_820FD724;
loc_820FD76C:
	// li r6,2
	ctx.r6.s64 = 2;
	// b 0x820fd724
	goto loc_820FD724;
loc_820FD774:
	// li r6,1
	ctx.r6.s64 = 1;
	// b 0x820fd724
	goto loc_820FD724;
loc_820FD77C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820fd7b0
	goto loc_820FD7B0;
loc_820FD784:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x820fd7a0
	if (ctx.cr6.lt) goto loc_820FD7A0;
	// lwz r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
loc_820FD794:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// b 0x820fd7a8
	goto loc_820FD7A8;
loc_820FD7A0:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,122
	ctx.r3.u64 = ctx.r3.u64 | 122;
loc_820FD7A8:
	// li r11,4
	ctx.r11.s64 = 4;
loc_820FD7AC:
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_820FD7B0:
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
