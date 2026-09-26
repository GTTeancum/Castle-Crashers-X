DEFINE_REX_FUNC(sub_82050170) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82050178;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r4,1,15,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1FFFE;
	// clrlwi r30,r4,16
	ctx.r30.u64 = ctx.r4.u32 & 0xFFFF;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r5,r11,97
	ctx.r5.s64 = ctx.r11.s64 + 97;
	// bl 0x8209d3d8
	ctx.lr = 0x820501A0;
	sub_8209D3D8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x820501AC;
	sub_8209D538(ctx, base);
	// li r31,4
	ctx.r31.s64 = 4;
loc_820501B0:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x820501C0;
	sub_8209D538(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x820501b0
	if (!ctx.cr0.eq) goto loc_820501B0;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r30,27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 27, ctx.xer);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bgt cr6,0x8205032c
	if (ctx.cr6.gt) goto loc_8205032C;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,496
	ctx.r12.s64 = ctx.r12.s64 + 496;
	// rlwinm r0,r30,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r30.u32) {
	case 0:
		goto loc_82050260;
	case 1:
		goto loc_82050268;
	case 2:
		goto loc_82050270;
	case 3:
		goto loc_82050278;
	case 4:
		goto loc_82050280;
	case 5:
		goto loc_82050288;
	case 6:
		goto loc_82050290;
	case 7:
		goto loc_82050298;
	case 8:
		goto loc_820502A0;
	case 9:
		goto loc_820502A8;
	case 10:
		goto loc_820502B0;
	case 11:
		goto loc_820502B8;
	case 12:
		goto loc_820502C0;
	case 13:
		goto loc_820502C8;
	case 14:
		goto loc_820502D0;
	case 15:
		goto loc_820502D0;
	case 16:
		goto loc_820502D8;
	case 17:
		goto loc_820502E0;
	case 18:
		goto loc_820502E8;
	case 19:
		goto loc_820502F0;
	case 20:
		goto loc_820502F8;
	case 21:
		goto loc_82050300;
	case 22:
		goto loc_82050280;
	case 23:
		goto loc_82050308;
	case 24:
		goto loc_82050310;
	case 25:
		goto loc_82050318;
	case 26:
		goto loc_82050320;
	case 27:
		goto loc_82050328;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82050260:
	// li r5,3
	ctx.r5.s64 = 3;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050268:
	// li r5,25
	ctx.r5.s64 = 25;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050270:
	// li r5,39
	ctx.r5.s64 = 39;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050278:
	// li r5,56
	ctx.r5.s64 = 56;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050280:
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050288:
	// li r5,19
	ctx.r5.s64 = 19;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050290:
	// li r5,10
	ctx.r5.s64 = 10;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050298:
	// li r5,18
	ctx.r5.s64 = 18;
	// b 0x8205032c
	goto loc_8205032C;
loc_820502A0:
	// li r5,34
	ctx.r5.s64 = 34;
	// b 0x8205032c
	goto loc_8205032C;
loc_820502A8:
	// li r5,27
	ctx.r5.s64 = 27;
	// b 0x8205032c
	goto loc_8205032C;
loc_820502B0:
	// li r5,47
	ctx.r5.s64 = 47;
	// b 0x8205032c
	goto loc_8205032C;
loc_820502B8:
	// li r5,36
	ctx.r5.s64 = 36;
	// b 0x8205032c
	goto loc_8205032C;
loc_820502C0:
	// li r5,12
	ctx.r5.s64 = 12;
	// b 0x8205032c
	goto loc_8205032C;
loc_820502C8:
	// li r5,33
	ctx.r5.s64 = 33;
	// b 0x8205032c
	goto loc_8205032C;
loc_820502D0:
	// li r5,15
	ctx.r5.s64 = 15;
	// b 0x8205032c
	goto loc_8205032C;
loc_820502D8:
	// li r5,6
	ctx.r5.s64 = 6;
	// b 0x8205032c
	goto loc_8205032C;
loc_820502E0:
	// li r5,45
	ctx.r5.s64 = 45;
	// b 0x8205032c
	goto loc_8205032C;
loc_820502E8:
	// li r5,26
	ctx.r5.s64 = 26;
	// b 0x8205032c
	goto loc_8205032C;
loc_820502F0:
	// li r5,57
	ctx.r5.s64 = 57;
	// b 0x8205032c
	goto loc_8205032C;
loc_820502F8:
	// li r5,43
	ctx.r5.s64 = 43;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050300:
	// li r5,20
	ctx.r5.s64 = 20;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050308:
	// li r5,35
	ctx.r5.s64 = 35;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050310:
	// li r5,31
	ctx.r5.s64 = 31;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050318:
	// li r5,48
	ctx.r5.s64 = 48;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050320:
	// li r5,50
	ctx.r5.s64 = 50;
	// b 0x8205032c
	goto loc_8205032C;
loc_82050328:
	// li r5,68
	ctx.r5.s64 = 68;
loc_8205032C:
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x82050338;
	sub_8209D538(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x82050344;
	sub_8209D538(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x82050350;
	sub_8209D538(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x82050358;
	sub_8209D538(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x82050360;
	sub_8209D538(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x82050368;
	sub_8209D538(ctx, base);
	// li r31,3
	ctx.r31.s64 = 3;
loc_8205036C:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x8205037C;
	sub_8209D538(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8205036c
	if (!ctx.cr0.eq) goto loc_8205036C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x8205038C;
	sub_8209D538(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x82050394;
	sub_8209D538(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x8205039C;
	sub_8209D538(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x820503A4;
	sub_8209D538(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8209d538
	ctx.lr = 0x820503AC;
	sub_8209D538(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r8,r11,1008
	ctx.r8.s64 = ctx.r11.s64 + 1008;
	// addi r10,r10,840
	ctx.r10.s64 = ctx.r10.s64 + 840;
loc_820503C0:
	// lbz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820503d8
	if (!ctx.cr6.eq) goto loc_820503D8;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x820503D4;
	sub_8208C5D8(ctx, base);
	// b 0x82050408
	goto loc_82050408;
loc_820503D8:
	// lwz r7,8(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r11,12(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x820503f4
	if (ctx.cr6.lt) goto loc_820503F4;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x820503F0;
	sub_8208C5D8(ctx, base);
	// b 0x82050408
	goto loc_82050408;
loc_820503F4:
	// lwz r7,4(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// stbx r29,r7,r11
	REX_STORE_U8(ctx.r7.u32 + ctx.r11.u32, ctx.r29.u8);
	// lwz r11,12(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// stw r5,12(r6)
	REX_STORE_U32(ctx.r6.u32 + 12, ctx.r5.u32);
loc_82050408:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x820503c0
	if (!ctx.cr0.eq) goto loc_820503C0;
	// lbz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8205042c
	if (!ctx.cr6.eq) goto loc_8205042C;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x82050424;
	sub_8208C5D8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8205042C:
	// lwz r10,8(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r11,12(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8205044c
	if (ctx.cr6.lt) goto loc_8205044C;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x8208c5d8
	ctx.lr = 0x82050444;
	sub_8208C5D8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
loc_8205044C:
	// lwz r10,4(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// stbx r29,r10,r11
	REX_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r29.u8);
	// lwz r11,12(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,12(r6)
	REX_STORE_U32(ctx.r6.u32 + 12, ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
