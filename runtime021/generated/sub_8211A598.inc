DEFINE_REX_FUNC(sub_8211A598) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8211A5A0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// cmpwi cr6,r5,4096
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4096, ctx.xer);
	// bgt cr6,0x8211a8bc
	if (ctx.cr6.gt) goto loc_8211A8BC;
	// beq cr6,0x8211a8a8
	if (ctx.cr6.eq) goto loc_8211A8A8;
	// addi r11,r5,-1
	ctx.r11.s64 = ctx.r5.s64 + -1;
	// cmplwi cr6,r11,27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 27, ctx.xer);
	// bgt cr6,0x8211a8ec
	if (ctx.cr6.gt) goto loc_8211A8EC;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-20424
	ctx.r12.s64 = ctx.r12.s64 + -20424;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32238
	ctx.r12.s64 = -2112749568;
	// addi r12,r12,-23056
	ctx.r12.s64 = ctx.r12.s64 + -23056;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8211A5F0;
	case 1:
		goto loc_8211A60C;
	case 2:
		goto loc_8211A8EC;
	case 3:
		goto loc_8211A620;
	case 4:
		goto loc_8211A69C;
	case 5:
		goto loc_8211A6B0;
	case 6:
		goto loc_8211A8EC;
	case 7:
		goto loc_8211A8EC;
	case 8:
		goto loc_8211A6C4;
	case 9:
		goto loc_8211A6D8;
	case 10:
		goto loc_8211A6EC;
	case 11:
		goto loc_8211A700;
	case 12:
		goto loc_8211A714;
	case 13:
		goto loc_8211A728;
	case 14:
		goto loc_8211A8EC;
	case 15:
		goto loc_8211A73C;
	case 16:
		goto loc_8211A750;
	case 17:
		goto loc_8211A764;
	case 18:
		goto loc_8211A7B4;
	case 19:
		goto loc_8211A804;
	case 20:
		goto loc_8211A8EC;
	case 21:
		goto loc_8211A818;
	case 22:
		goto loc_8211A82C;
	case 23:
		goto loc_8211A840;
	case 24:
		goto loc_8211A854;
	case 25:
		goto loc_8211A868;
	case 26:
		goto loc_8211A880;
	case 27:
		goto loc_8211A894;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8211A5F0:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,664(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 664);
loc_8211A600:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x8211a68c
	goto loc_8211A68C;
loc_8211A60C:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,668(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 668);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A620:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8211a630
	if (!ctx.cr6.eq) goto loc_8211A630;
	// lwz r11,68(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// b 0x8211a678
	goto loc_8211A678;
loc_8211A630:
	// addi r29,r3,472
	ctx.r29.s64 = ctx.r3.s64 + 472;
	// addi r5,r3,532
	ctx.r5.s64 = ctx.r3.s64 + 532;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82121f40
	ctx.lr = 0x8211A64C;
	sub_82121F40(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8211a674
	if (!ctx.cr0.eq) goto loc_8211A674;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82121ef0
	ctx.lr = 0x8211A660;
	sub_82121EF0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8211a674
	if (!ctx.cr0.eq) goto loc_8211A674;
loc_8211A668:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4111
	ctx.r3.u64 = ctx.r3.u64 | 4111;
	// b 0x8211a694
	goto loc_8211A694;
loc_8211A674:
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
loc_8211A678:
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x8211a980
	if (!ctx.cr6.lt) goto loc_8211A980;
loc_8211A684:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4097
	ctx.r3.u64 = ctx.r3.u64 | 4097;
loc_8211A68C:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_8211A694:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
loc_8211A69C:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,676(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 676);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A6B0:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,680(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 680);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A6C4:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,80(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A6D8:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lhz r11,1034(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 1034);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A6EC:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lhz r11,1036(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 1036);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A700:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lhz r11,1038(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 1038);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A714:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lhz r11,1040(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 1040);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A728:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,84(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A73C:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,92(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A750:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A764:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8211a774
	if (!ctx.cr6.eq) goto loc_8211A774;
	// lwz r11,72(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 72);
	// b 0x8211a678
	goto loc_8211A678;
loc_8211A774:
	// addi r29,r3,472
	ctx.r29.s64 = ctx.r3.s64 + 472;
	// addi r5,r3,532
	ctx.r5.s64 = ctx.r3.s64 + 532;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82121f40
	ctx.lr = 0x8211A790;
	sub_82121F40(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8211a7ac
	if (!ctx.cr0.eq) goto loc_8211A7AC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82121ef0
	ctx.lr = 0x8211A7A4;
	sub_82121EF0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8211a668
	if (ctx.cr0.eq) goto loc_8211A668;
loc_8211A7AC:
	// lwz r11,144(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// b 0x8211a678
	goto loc_8211A678;
loc_8211A7B4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8211a7c4
	if (!ctx.cr6.eq) goto loc_8211A7C4;
	// lwz r11,76(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// b 0x8211a678
	goto loc_8211A678;
loc_8211A7C4:
	// addi r29,r3,472
	ctx.r29.s64 = ctx.r3.s64 + 472;
	// addi r5,r3,532
	ctx.r5.s64 = ctx.r3.s64 + 532;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82121f40
	ctx.lr = 0x8211A7E0;
	sub_82121F40(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8211a7fc
	if (!ctx.cr0.eq) goto loc_8211A7FC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82121ef0
	ctx.lr = 0x8211A7F4;
	sub_82121EF0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8211a668
	if (ctx.cr0.eq) goto loc_8211A668;
loc_8211A7FC:
	// lwz r11,148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// b 0x8211a678
	goto loc_8211A678;
loc_8211A804:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,100(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A818:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A82C:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A840:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,108(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A854:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,112(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 112);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A868:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,1148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1148);
	// rlwinm r11,r11,13,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 13) & 0x1;
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A880:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,120(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 120);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A894:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,132(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 132);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A8A8:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,684(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 684);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A8BC:
	// cmpwi cr6,r5,4098
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4098, ctx.xer);
	// beq cr6,0x8211a95c
	if (ctx.cr6.eq) goto loc_8211A95C;
	// cmpwi cr6,r5,4099
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4099, ctx.xer);
	// beq cr6,0x8211a948
	if (ctx.cr6.eq) goto loc_8211A948;
	// cmpwi cr6,r5,4100
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4100, ctx.xer);
	// beq cr6,0x8211a934
	if (ctx.cr6.eq) goto loc_8211A934;
	// cmpwi cr6,r5,4101
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4101, ctx.xer);
	// beq cr6,0x8211a920
	if (ctx.cr6.eq) goto loc_8211A920;
	// cmpwi cr6,r5,4102
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4102, ctx.xer);
	// beq cr6,0x8211a90c
	if (ctx.cr6.eq) goto loc_8211A90C;
	// cmpwi cr6,r5,4103
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4103, ctx.xer);
	// beq cr6,0x8211a8f8
	if (ctx.cr6.eq) goto loc_8211A8F8;
loc_8211A8EC:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4105
	ctx.r3.u64 = ctx.r3.u64 | 4105;
	// b 0x8211a694
	goto loc_8211A694;
loc_8211A8F8:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,688(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 688);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A90C:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lhz r11,128(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 128);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A920:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lhz r11,126(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 126);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A934:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lhz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 124);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A948:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,116(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 116);
	// b 0x8211a600
	goto loc_8211A600;
loc_8211A95C:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8211a684
	if (ctx.cr6.lt) goto loc_8211A684;
	// lwz r11,1148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1148);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8211a97c
	if (ctx.cr0.eq) goto loc_8211A97C;
	// lwz r11,424(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 424);
	// b 0x8211a980
	goto loc_8211A980;
loc_8211A97C:
	// lwz r11,428(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 428);
loc_8211A980:
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8211a68c
	goto loc_8211A68C;
}
