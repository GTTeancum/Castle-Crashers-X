DEFINE_REX_FUNC(sub_8205A318) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x8205A320;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// lhz r4,10(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// bl 0x82053c70
	ctx.lr = 0x8205A34C;
	sub_82053C70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8205b610
	if (ctx.cr6.eq) goto loc_8205B610;
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lhz r29,8(r11)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// bl 0x82053bc8
	ctx.lr = 0x8205A36C;
	sub_82053BC8(ctx, base);
	// lwz r10,48(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r9,276(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 276);
	// lwz r31,56(r9)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,164(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 164);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8205A390;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bgt cr6,0x8205b5d8
	if (ctx.cr6.gt) goto loc_8205B5D8;
	// lis r12,-32250
	ctx.r12.s64 = -2113536000;
	// addi r12,r12,-23620
	ctx.r12.s64 = ctx.r12.s64 + -23620;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8205A3D8;
	case 1:
		goto loc_8205A668;
	case 2:
		goto loc_8205A8A0;
	case 3:
		goto loc_8205AC98;
	case 4:
		goto loc_8205AF44;
	case 5:
		goto loc_8205B33C;
	case 6:
		goto loc_8205B4F4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8205A3D8:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r29,409
	ctx.r29.s64 = 409;
	// addi r4,r11,9524
	ctx.r4.s64 = ctx.r11.s64 + 9524;
	// bl 0x8209d948
	ctx.lr = 0x8205A3EC;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205A404;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A40C;
	sub_82085078(ctx, base);
	// li r4,410
	ctx.r4.s64 = 410;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A418;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,35
	ctx.r4.s64 = 35;
	// bl 0x82058508
	ctx.lr = 0x8205A424;
	sub_82058508(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,9532
	ctx.r4.s64 = ctx.r8.s64 + 9532;
	// bl 0x8209d948
	ctx.lr = 0x8205A434;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205A44C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A454;
	sub_82085078(ctx, base);
	// li r4,411
	ctx.r4.s64 = 411;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A460;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,35
	ctx.r4.s64 = 35;
	// bl 0x82058508
	ctx.lr = 0x8205A46C;
	sub_82058508(ctx, base);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r5,9540
	ctx.r4.s64 = ctx.r5.s64 + 9540;
	// bl 0x8209d948
	ctx.lr = 0x8205A47C;
	sub_8209D948(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8205A494;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A49C;
	sub_82085078(ctx, base);
	// li r4,412
	ctx.r4.s64 = 412;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A4A8;
	sub_82094B48(ctx, base);
	// li r4,35
	ctx.r4.s64 = 35;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205A4B4;
	sub_82058508(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r10,9548
	ctx.r4.s64 = ctx.r10.s64 + 9548;
	// bl 0x8209d948
	ctx.lr = 0x8205A4C4;
	sub_8209D948(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8205A4DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A4E4;
	sub_82085078(ctx, base);
	// li r4,413
	ctx.r4.s64 = 413;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A4F0;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,35
	ctx.r4.s64 = 35;
	// bl 0x82058508
	ctx.lr = 0x8205A4FC;
	sub_82058508(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r7,9556
	ctx.r4.s64 = ctx.r7.s64 + 9556;
	// bl 0x8209d948
	ctx.lr = 0x8205A50C;
	sub_8209D948(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8205A524;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A52C;
	sub_82085078(ctx, base);
	// li r4,414
	ctx.r4.s64 = 414;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A538;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,35
	ctx.r4.s64 = 35;
	// bl 0x82058508
	ctx.lr = 0x8205A544;
	sub_82058508(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r4,9564
	ctx.r4.s64 = ctx.r4.s64 + 9564;
	// bl 0x8209d948
	ctx.lr = 0x8205A554;
	sub_8209D948(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205A56C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A574;
	sub_82085078(ctx, base);
	// li r4,415
	ctx.r4.s64 = 415;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A580;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x82058508
	ctx.lr = 0x8205A58C;
	sub_82058508(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r9,9572
	ctx.r4.s64 = ctx.r9.s64 + 9572;
	// bl 0x8209d948
	ctx.lr = 0x8205A59C;
	sub_8209D948(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,100(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 100);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8205A5B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A5BC;
	sub_82085078(ctx, base);
	// li r4,416
	ctx.r4.s64 = 416;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A5C8;
	sub_82094B48(ctx, base);
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205A5D4;
	sub_82058508(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r6,9580
	ctx.r4.s64 = ctx.r6.s64 + 9580;
	// bl 0x8209d948
	ctx.lr = 0x8205A5E4;
	sub_8209D948(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8205A5FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A604;
	sub_82085078(ctx, base);
	// li r4,417
	ctx.r4.s64 = 417;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A610;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,28
	ctx.r4.s64 = 28;
	// bl 0x82058508
	ctx.lr = 0x8205A61C;
	sub_82058508(ctx, base);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// addi r4,r3,9588
	ctx.r4.s64 = ctx.r3.s64 + 9588;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x8209d948
	ctx.lr = 0x8205A62C;
	sub_8209D948(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205A644;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A64C;
	sub_82085078(ctx, base);
	// li r4,418
	ctx.r4.s64 = 418;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A658;
	sub_82094B48(ctx, base);
	// li r4,28
	ctx.r4.s64 = 28;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205A664;
	sub_82058508(ctx, base);
	// b 0x8205b5d8
	goto loc_8205B5D8;
loc_8205A668:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r29,153
	ctx.r29.s64 = 153;
	// addi r4,r11,9524
	ctx.r4.s64 = ctx.r11.s64 + 9524;
	// bl 0x8209d948
	ctx.lr = 0x8205A67C;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205A694;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A69C;
	sub_82085078(ctx, base);
	// li r4,419
	ctx.r4.s64 = 419;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A6A8;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,38
	ctx.r4.s64 = 38;
	// bl 0x82058508
	ctx.lr = 0x8205A6B4;
	sub_82058508(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,9532
	ctx.r4.s64 = ctx.r8.s64 + 9532;
	// bl 0x8209d948
	ctx.lr = 0x8205A6C4;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205A6DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A6E4;
	sub_82085078(ctx, base);
	// li r4,420
	ctx.r4.s64 = 420;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A6F0;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,38
	ctx.r4.s64 = 38;
	// bl 0x82058508
	ctx.lr = 0x8205A6FC;
	sub_82058508(ctx, base);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r5,9540
	ctx.r4.s64 = ctx.r5.s64 + 9540;
	// bl 0x8209d948
	ctx.lr = 0x8205A70C;
	sub_8209D948(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8205A724;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A72C;
	sub_82085078(ctx, base);
	// li r4,421
	ctx.r4.s64 = 421;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A738;
	sub_82094B48(ctx, base);
	// li r4,38
	ctx.r4.s64 = 38;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205A744;
	sub_82058508(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r10,9548
	ctx.r4.s64 = ctx.r10.s64 + 9548;
	// bl 0x8209d948
	ctx.lr = 0x8205A754;
	sub_8209D948(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8205A76C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A774;
	sub_82085078(ctx, base);
	// li r4,422
	ctx.r4.s64 = 422;
	// bl 0x82094b48
	ctx.lr = 0x8205A77C;
	sub_82094B48(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r7,9556
	ctx.r4.s64 = ctx.r7.s64 + 9556;
	// bl 0x8209d948
	ctx.lr = 0x8205A78C;
	sub_8209D948(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8205A7A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A7AC;
	sub_82085078(ctx, base);
	// li r4,423
	ctx.r4.s64 = 423;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A7B8;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,39
	ctx.r4.s64 = 39;
	// bl 0x82058508
	ctx.lr = 0x8205A7C4;
	sub_82058508(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r4,9564
	ctx.r4.s64 = ctx.r4.s64 + 9564;
	// bl 0x8209d948
	ctx.lr = 0x8205A7D4;
	sub_8209D948(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205A7EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A7F4;
	sub_82085078(ctx, base);
	// li r4,424
	ctx.r4.s64 = 424;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A800;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,38
	ctx.r4.s64 = 38;
	// bl 0x82058508
	ctx.lr = 0x8205A80C;
	sub_82058508(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r9,9572
	ctx.r4.s64 = ctx.r9.s64 + 9572;
	// bl 0x8209d948
	ctx.lr = 0x8205A81C;
	sub_8209D948(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,100(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 100);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8205A834;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A83C;
	sub_82085078(ctx, base);
	// li r4,425
	ctx.r4.s64 = 425;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A848;
	sub_82094B48(ctx, base);
	// li r4,39
	ctx.r4.s64 = 39;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205A854;
	sub_82058508(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r6,9580
	ctx.r4.s64 = ctx.r6.s64 + 9580;
	// bl 0x8209d948
	ctx.lr = 0x8205A864;
	sub_8209D948(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8205A87C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A884;
	sub_82085078(ctx, base);
	// li r4,426
	ctx.r4.s64 = 426;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A890;
	sub_82094B48(ctx, base);
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205A89C;
	sub_82058508(ctx, base);
	// b 0x8205b5d8
	goto loc_8205B5D8;
loc_8205A8A0:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r29,427
	ctx.r29.s64 = 427;
	// addi r4,r11,9524
	ctx.r4.s64 = ctx.r11.s64 + 9524;
	// bl 0x8209d948
	ctx.lr = 0x8205A8B4;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205A8CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A8D4;
	sub_82085078(ctx, base);
	// li r4,279
	ctx.r4.s64 = 279;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A8E0;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// bl 0x82058508
	ctx.lr = 0x8205A8EC;
	sub_82058508(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,9532
	ctx.r4.s64 = ctx.r8.s64 + 9532;
	// bl 0x8209d948
	ctx.lr = 0x8205A8FC;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205A914;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A91C;
	sub_82085078(ctx, base);
	// li r4,280
	ctx.r4.s64 = 280;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A928;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// bl 0x82058508
	ctx.lr = 0x8205A934;
	sub_82058508(ctx, base);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r5,9540
	ctx.r4.s64 = ctx.r5.s64 + 9540;
	// bl 0x8209d948
	ctx.lr = 0x8205A944;
	sub_8209D948(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8205A95C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A964;
	sub_82085078(ctx, base);
	// li r4,281
	ctx.r4.s64 = 281;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A970;
	sub_82094B48(ctx, base);
	// li r4,24
	ctx.r4.s64 = 24;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205A97C;
	sub_82058508(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r10,9548
	ctx.r4.s64 = ctx.r10.s64 + 9548;
	// bl 0x8209d948
	ctx.lr = 0x8205A98C;
	sub_8209D948(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8205A9A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A9AC;
	sub_82085078(ctx, base);
	// li r4,282
	ctx.r4.s64 = 282;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205A9B8;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// bl 0x82058508
	ctx.lr = 0x8205A9C4;
	sub_82058508(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r7,9556
	ctx.r4.s64 = ctx.r7.s64 + 9556;
	// bl 0x8209d948
	ctx.lr = 0x8205A9D4;
	sub_8209D948(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8205A9EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205A9F4;
	sub_82085078(ctx, base);
	// li r4,283
	ctx.r4.s64 = 283;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AA00;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// bl 0x82058508
	ctx.lr = 0x8205AA0C;
	sub_82058508(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r4,9564
	ctx.r4.s64 = ctx.r4.s64 + 9564;
	// bl 0x8209d948
	ctx.lr = 0x8205AA1C;
	sub_8209D948(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205AA34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AA3C;
	sub_82085078(ctx, base);
	// li r4,284
	ctx.r4.s64 = 284;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AA48;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// bl 0x82058508
	ctx.lr = 0x8205AA54;
	sub_82058508(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r9,9572
	ctx.r4.s64 = ctx.r9.s64 + 9572;
	// bl 0x8209d948
	ctx.lr = 0x8205AA64;
	sub_8209D948(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,100(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 100);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8205AA7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AA84;
	sub_82085078(ctx, base);
	// li r4,285
	ctx.r4.s64 = 285;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AA90;
	sub_82094B48(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205AA9C;
	sub_82058508(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r6,9580
	ctx.r4.s64 = ctx.r6.s64 + 9580;
	// bl 0x8209d948
	ctx.lr = 0x8205AAAC;
	sub_8209D948(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8205AAC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AACC;
	sub_82085078(ctx, base);
	// li r4,286
	ctx.r4.s64 = 286;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AAD8;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// bl 0x82058508
	ctx.lr = 0x8205AAE4;
	sub_82058508(ctx, base);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// addi r4,r3,9588
	ctx.r4.s64 = ctx.r3.s64 + 9588;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x8209d948
	ctx.lr = 0x8205AAF4;
	sub_8209D948(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205AB0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AB14;
	sub_82085078(ctx, base);
	// li r4,287
	ctx.r4.s64 = 287;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AB20;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// bl 0x82058508
	ctx.lr = 0x8205AB2C;
	sub_82058508(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r9,9596
	ctx.r4.s64 = ctx.r9.s64 + 9596;
	// bl 0x8209d948
	ctx.lr = 0x8205AB3C;
	sub_8209D948(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,100(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 100);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8205AB54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AB5C;
	sub_82085078(ctx, base);
	// li r4,288
	ctx.r4.s64 = 288;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AB68;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// bl 0x82058508
	ctx.lr = 0x8205AB74;
	sub_82058508(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r6,9604
	ctx.r4.s64 = ctx.r6.s64 + 9604;
	// bl 0x8209d948
	ctx.lr = 0x8205AB84;
	sub_8209D948(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8205AB9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205ABA4;
	sub_82085078(ctx, base);
	// li r4,151
	ctx.r4.s64 = 151;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205ABB0;
	sub_82094B48(ctx, base);
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205ABBC;
	sub_82058508(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r11,9616
	ctx.r4.s64 = ctx.r11.s64 + 9616;
	// bl 0x8209d948
	ctx.lr = 0x8205ABCC;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205ABE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205ABEC;
	sub_82085078(ctx, base);
	// li r4,153
	ctx.r4.s64 = 153;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205ABF8;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82058508
	ctx.lr = 0x8205AC04;
	sub_82058508(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,9624
	ctx.r4.s64 = ctx.r8.s64 + 9624;
	// bl 0x8209d948
	ctx.lr = 0x8205AC14;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205AC2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AC34;
	sub_82085078(ctx, base);
	// li r4,152
	ctx.r4.s64 = 152;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AC40;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82058508
	ctx.lr = 0x8205AC4C;
	sub_82058508(ctx, base);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r5,9632
	ctx.r4.s64 = ctx.r5.s64 + 9632;
	// bl 0x8209d948
	ctx.lr = 0x8205AC5C;
	sub_8209D948(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8205AC74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AC7C;
	sub_82085078(ctx, base);
	// li r4,154
	ctx.r4.s64 = 154;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AC88;
	sub_82094B48(ctx, base);
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205AC94;
	sub_82058508(ctx, base);
	// b 0x8205b5d8
	goto loc_8205B5D8;
loc_8205AC98:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r29,428
	ctx.r29.s64 = 428;
	// addi r4,r11,9524
	ctx.r4.s64 = ctx.r11.s64 + 9524;
	// bl 0x8209d948
	ctx.lr = 0x8205ACAC;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205ACC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205ACCC;
	sub_82085078(ctx, base);
	// li r4,289
	ctx.r4.s64 = 289;
	// bl 0x82094b48
	ctx.lr = 0x8205ACD4;
	sub_82094B48(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,9532
	ctx.r4.s64 = ctx.r8.s64 + 9532;
	// bl 0x8209d948
	ctx.lr = 0x8205ACE4;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205ACFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AD04;
	sub_82085078(ctx, base);
	// li r4,290
	ctx.r4.s64 = 290;
	// bl 0x82094b48
	ctx.lr = 0x8205AD0C;
	sub_82094B48(ctx, base);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r5,9540
	ctx.r4.s64 = ctx.r5.s64 + 9540;
	// bl 0x8209d948
	ctx.lr = 0x8205AD1C;
	sub_8209D948(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8205AD34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AD3C;
	sub_82085078(ctx, base);
	// li r4,291
	ctx.r4.s64 = 291;
	// bl 0x82094b48
	ctx.lr = 0x8205AD44;
	sub_82094B48(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r10,9548
	ctx.r4.s64 = ctx.r10.s64 + 9548;
	// bl 0x8209d948
	ctx.lr = 0x8205AD54;
	sub_8209D948(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8205AD6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AD74;
	sub_82085078(ctx, base);
	// li r4,292
	ctx.r4.s64 = 292;
	// bl 0x82094b48
	ctx.lr = 0x8205AD7C;
	sub_82094B48(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r7,9556
	ctx.r4.s64 = ctx.r7.s64 + 9556;
	// bl 0x8209d948
	ctx.lr = 0x8205AD8C;
	sub_8209D948(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8205ADA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205ADAC;
	sub_82085078(ctx, base);
	// li r4,293
	ctx.r4.s64 = 293;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205ADB8;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,36
	ctx.r4.s64 = 36;
	// bl 0x82058508
	ctx.lr = 0x8205ADC4;
	sub_82058508(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r4,9564
	ctx.r4.s64 = ctx.r4.s64 + 9564;
	// bl 0x8209d948
	ctx.lr = 0x8205ADD4;
	sub_8209D948(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205ADEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205ADF4;
	sub_82085078(ctx, base);
	// li r4,294
	ctx.r4.s64 = 294;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AE00;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,35
	ctx.r4.s64 = 35;
	// bl 0x82058508
	ctx.lr = 0x8205AE0C;
	sub_82058508(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r9,9572
	ctx.r4.s64 = ctx.r9.s64 + 9572;
	// bl 0x8209d948
	ctx.lr = 0x8205AE1C;
	sub_8209D948(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,100(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 100);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8205AE34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AE3C;
	sub_82085078(ctx, base);
	// li r4,295
	ctx.r4.s64 = 295;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AE48;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,33
	ctx.r4.s64 = 33;
	// bl 0x82058508
	ctx.lr = 0x8205AE54;
	sub_82058508(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r6,9580
	ctx.r4.s64 = ctx.r6.s64 + 9580;
	// bl 0x8209d948
	ctx.lr = 0x8205AE64;
	sub_8209D948(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8205AE7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AE84;
	sub_82085078(ctx, base);
	// li r4,296
	ctx.r4.s64 = 296;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AE90;
	sub_82094B48(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205AE9C;
	sub_82058508(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r11,9588
	ctx.r4.s64 = ctx.r11.s64 + 9588;
	// bl 0x8209d948
	ctx.lr = 0x8205AEAC;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205AEC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AECC;
	sub_82085078(ctx, base);
	// li r4,297
	ctx.r4.s64 = 297;
	// bl 0x82094b48
	ctx.lr = 0x8205AED4;
	sub_82094B48(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,9596
	ctx.r4.s64 = ctx.r8.s64 + 9596;
	// bl 0x8209d948
	ctx.lr = 0x8205AEE4;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205AEFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AF04;
	sub_82085078(ctx, base);
	// li r4,298
	ctx.r4.s64 = 298;
	// bl 0x82094b48
	ctx.lr = 0x8205AF0C;
	sub_82094B48(ctx, base);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r5,9640
	ctx.r4.s64 = ctx.r5.s64 + 9640;
	// bl 0x8209d948
	ctx.lr = 0x8205AF1C;
	sub_8209D948(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8205AF34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AF3C;
	sub_82085078(ctx, base);
	// li r4,299
	ctx.r4.s64 = 299;
	// b 0x8205b5d4
	goto loc_8205B5D4;
loc_8205AF44:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r29,429
	ctx.r29.s64 = 429;
	// addi r4,r11,9524
	ctx.r4.s64 = ctx.r11.s64 + 9524;
	// bl 0x8209d948
	ctx.lr = 0x8205AF58;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205AF70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AF78;
	sub_82085078(ctx, base);
	// li r4,300
	ctx.r4.s64 = 300;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AF84;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,29
	ctx.r4.s64 = 29;
	// bl 0x82058508
	ctx.lr = 0x8205AF90;
	sub_82058508(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,9532
	ctx.r4.s64 = ctx.r8.s64 + 9532;
	// bl 0x8209d948
	ctx.lr = 0x8205AFA0;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205AFB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205AFC0;
	sub_82085078(ctx, base);
	// li r4,301
	ctx.r4.s64 = 301;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205AFCC;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,33
	ctx.r4.s64 = 33;
	// bl 0x82058508
	ctx.lr = 0x8205AFD8;
	sub_82058508(ctx, base);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r5,9540
	ctx.r4.s64 = ctx.r5.s64 + 9540;
	// bl 0x8209d948
	ctx.lr = 0x8205AFE8;
	sub_8209D948(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8205B000;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B008;
	sub_82085078(ctx, base);
	// li r4,302
	ctx.r4.s64 = 302;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B014;
	sub_82094B48(ctx, base);
	// li r4,34
	ctx.r4.s64 = 34;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205B020;
	sub_82058508(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r10,9548
	ctx.r4.s64 = ctx.r10.s64 + 9548;
	// bl 0x8209d948
	ctx.lr = 0x8205B030;
	sub_8209D948(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8205B048;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B050;
	sub_82085078(ctx, base);
	// li r4,303
	ctx.r4.s64 = 303;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B05C;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,40
	ctx.r4.s64 = 40;
	// bl 0x82058508
	ctx.lr = 0x8205B068;
	sub_82058508(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r7,9556
	ctx.r4.s64 = ctx.r7.s64 + 9556;
	// bl 0x8209d948
	ctx.lr = 0x8205B078;
	sub_8209D948(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8205B090;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B098;
	sub_82085078(ctx, base);
	// li r4,304
	ctx.r4.s64 = 304;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B0A4;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,41
	ctx.r4.s64 = 41;
	// bl 0x82058508
	ctx.lr = 0x8205B0B0;
	sub_82058508(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r4,9564
	ctx.r4.s64 = ctx.r4.s64 + 9564;
	// bl 0x8209d948
	ctx.lr = 0x8205B0C0;
	sub_8209D948(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205B0D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B0E0;
	sub_82085078(ctx, base);
	// li r4,305
	ctx.r4.s64 = 305;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B0EC;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,42
	ctx.r4.s64 = 42;
	// bl 0x82058508
	ctx.lr = 0x8205B0F8;
	sub_82058508(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r9,9572
	ctx.r4.s64 = ctx.r9.s64 + 9572;
	// bl 0x8209d948
	ctx.lr = 0x8205B108;
	sub_8209D948(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,100(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 100);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8205B120;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B128;
	sub_82085078(ctx, base);
	// li r4,306
	ctx.r4.s64 = 306;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B134;
	sub_82094B48(ctx, base);
	// li r4,42
	ctx.r4.s64 = 42;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205B140;
	sub_82058508(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r6,9580
	ctx.r4.s64 = ctx.r6.s64 + 9580;
	// bl 0x8209d948
	ctx.lr = 0x8205B150;
	sub_8209D948(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8205B168;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B170;
	sub_82085078(ctx, base);
	// li r4,307
	ctx.r4.s64 = 307;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B17C;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,22
	ctx.r4.s64 = 22;
	// bl 0x82058508
	ctx.lr = 0x8205B188;
	sub_82058508(ctx, base);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// addi r4,r3,9588
	ctx.r4.s64 = ctx.r3.s64 + 9588;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x8209d948
	ctx.lr = 0x8205B198;
	sub_8209D948(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205B1B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B1B8;
	sub_82085078(ctx, base);
	// li r4,308
	ctx.r4.s64 = 308;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B1C4;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,22
	ctx.r4.s64 = 22;
	// bl 0x82058508
	ctx.lr = 0x8205B1D0;
	sub_82058508(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r9,9596
	ctx.r4.s64 = ctx.r9.s64 + 9596;
	// bl 0x8209d948
	ctx.lr = 0x8205B1E0;
	sub_8209D948(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,100(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 100);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8205B1F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B200;
	sub_82085078(ctx, base);
	// li r4,309
	ctx.r4.s64 = 309;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B20C;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,22
	ctx.r4.s64 = 22;
	// bl 0x82058508
	ctx.lr = 0x8205B218;
	sub_82058508(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r6,9640
	ctx.r4.s64 = ctx.r6.s64 + 9640;
	// bl 0x8209d948
	ctx.lr = 0x8205B228;
	sub_8209D948(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,100(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 100);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8205B240;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B248;
	sub_82085078(ctx, base);
	// li r4,310
	ctx.r4.s64 = 310;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B254;
	sub_82094B48(ctx, base);
	// li r4,24
	ctx.r4.s64 = 24;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205B260;
	sub_82058508(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r11,9648
	ctx.r4.s64 = ctx.r11.s64 + 9648;
	// bl 0x8209d948
	ctx.lr = 0x8205B270;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205B288;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B290;
	sub_82085078(ctx, base);
	// li r4,311
	ctx.r4.s64 = 311;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B29C;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// bl 0x82058508
	ctx.lr = 0x8205B2A8;
	sub_82058508(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,9656
	ctx.r4.s64 = ctx.r8.s64 + 9656;
	// bl 0x8209d948
	ctx.lr = 0x8205B2B8;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205B2D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B2D8;
	sub_82085078(ctx, base);
	// li r4,312
	ctx.r4.s64 = 312;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B2E4;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,25
	ctx.r4.s64 = 25;
	// bl 0x82058508
	ctx.lr = 0x8205B2F0;
	sub_82058508(ctx, base);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r5,9664
	ctx.r4.s64 = ctx.r5.s64 + 9664;
	// bl 0x8209d948
	ctx.lr = 0x8205B300;
	sub_8209D948(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8205B318;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B320;
	sub_82085078(ctx, base);
	// li r4,313
	ctx.r4.s64 = 313;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B32C;
	sub_82094B48(ctx, base);
	// li r4,24
	ctx.r4.s64 = 24;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205B338;
	sub_82058508(ctx, base);
	// b 0x8205b5d8
	goto loc_8205B5D8;
loc_8205B33C:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r29,430
	ctx.r29.s64 = 430;
	// addi r4,r11,9524
	ctx.r4.s64 = ctx.r11.s64 + 9524;
	// bl 0x8209d948
	ctx.lr = 0x8205B350;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205B368;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B370;
	sub_82085078(ctx, base);
	// li r4,431
	ctx.r4.s64 = 431;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B37C;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,38
	ctx.r4.s64 = 38;
	// bl 0x82058508
	ctx.lr = 0x8205B388;
	sub_82058508(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,9532
	ctx.r4.s64 = ctx.r8.s64 + 9532;
	// bl 0x8209d948
	ctx.lr = 0x8205B398;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205B3B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B3B8;
	sub_82085078(ctx, base);
	// li r4,432
	ctx.r4.s64 = 432;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B3C4;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,38
	ctx.r4.s64 = 38;
	// bl 0x82058508
	ctx.lr = 0x8205B3D0;
	sub_82058508(ctx, base);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r5,9540
	ctx.r4.s64 = ctx.r5.s64 + 9540;
	// bl 0x8209d948
	ctx.lr = 0x8205B3E0;
	sub_8209D948(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8205B3F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B400;
	sub_82085078(ctx, base);
	// li r4,433
	ctx.r4.s64 = 433;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B40C;
	sub_82094B48(ctx, base);
	// li r4,38
	ctx.r4.s64 = 38;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205B418;
	sub_82058508(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r10,9548
	ctx.r4.s64 = ctx.r10.s64 + 9548;
	// bl 0x8209d948
	ctx.lr = 0x8205B428;
	sub_8209D948(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8205B440;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B448;
	sub_82085078(ctx, base);
	// li r4,434
	ctx.r4.s64 = 434;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B454;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,39
	ctx.r4.s64 = 39;
	// bl 0x82058508
	ctx.lr = 0x8205B460;
	sub_82058508(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r7,9556
	ctx.r4.s64 = ctx.r7.s64 + 9556;
	// bl 0x8209d948
	ctx.lr = 0x8205B470;
	sub_8209D948(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,100(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 100);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8205B488;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B490;
	sub_82085078(ctx, base);
	// li r4,435
	ctx.r4.s64 = 435;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B49C;
	sub_82094B48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,39
	ctx.r4.s64 = 39;
	// bl 0x82058508
	ctx.lr = 0x8205B4A8;
	sub_82058508(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r4,9564
	ctx.r4.s64 = ctx.r4.s64 + 9564;
	// bl 0x8209d948
	ctx.lr = 0x8205B4B8;
	sub_8209D948(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8205B4D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B4D8;
	sub_82085078(ctx, base);
	// li r4,436
	ctx.r4.s64 = 436;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82094b48
	ctx.lr = 0x8205B4E4;
	sub_82094B48(ctx, base);
	// li r4,40
	ctx.r4.s64 = 40;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82058508
	ctx.lr = 0x8205B4F0;
	sub_82058508(ctx, base);
	// b 0x8205b5d8
	goto loc_8205B5D8;
loc_8205B4F4:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r29,437
	ctx.r29.s64 = 437;
	// addi r4,r11,9524
	ctx.r4.s64 = ctx.r11.s64 + 9524;
	// bl 0x8209d948
	ctx.lr = 0x8205B508;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205B520;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B528;
	sub_82085078(ctx, base);
	// li r4,438
	ctx.r4.s64 = 438;
	// bl 0x82094b48
	ctx.lr = 0x8205B530;
	sub_82094B48(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r8,9532
	ctx.r4.s64 = ctx.r8.s64 + 9532;
	// bl 0x8209d948
	ctx.lr = 0x8205B540;
	sub_8209D948(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8205B558;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B560;
	sub_82085078(ctx, base);
	// li r4,439
	ctx.r4.s64 = 439;
	// bl 0x82094b48
	ctx.lr = 0x8205B568;
	sub_82094B48(ctx, base);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r5,9540
	ctx.r4.s64 = ctx.r5.s64 + 9540;
	// bl 0x8209d948
	ctx.lr = 0x8205B578;
	sub_8209D948(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8205B590;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B598;
	sub_82085078(ctx, base);
	// li r4,440
	ctx.r4.s64 = 440;
	// bl 0x82094b48
	ctx.lr = 0x8205B5A0;
	sub_82094B48(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r10,9548
	ctx.r4.s64 = ctx.r10.s64 + 9548;
	// bl 0x8209d948
	ctx.lr = 0x8205B5B0;
	sub_8209D948(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8205B5C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B5D0;
	sub_82085078(ctx, base);
	// li r4,441
	ctx.r4.s64 = 441;
loc_8205B5D4:
	// bl 0x82094b48
	ctx.lr = 0x8205B5D8;
	sub_82094B48(ctx, base);
loc_8205B5D8:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r11,9672
	ctx.r4.s64 = ctx.r11.s64 + 9672;
	// bl 0x8209d948
	ctx.lr = 0x8205B5E8;
	sub_8209D948(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8205B600;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82085078
	ctx.lr = 0x8205B608;
	sub_82085078(ctx, base);
	// clrlwi r4,r29,16
	ctx.r4.u64 = ctx.r29.u32 & 0xFFFF;
	// bl 0x82094b48
	ctx.lr = 0x8205B610;
	sub_82094B48(ctx, base);
loc_8205B610:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
