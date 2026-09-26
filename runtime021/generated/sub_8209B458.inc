DEFINE_REX_FUNC(sub_8209B458) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129904
	ctx.lr = 0x8209B460;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r28,r3,8
	ctx.r28.s64 = ctx.r3.s64 + 8;
	// li r29,4
	ctx.r29.s64 = 4;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// li r31,0
	ctx.r31.s64 = 0;
loc_8209B478:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209b498
	if (ctx.cr6.eq) goto loc_8209B498;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8209B498;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8209B498:
	// stw r31,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x8209b478
	if (!ctx.cr0.eq) goto loc_8209B478;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lfs f31,9536(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 9536);
	ctx.f31.f64 = double(temp.f32);
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// li r30,1
	ctx.r30.s64 = 1;
	// lis r24,-32215
	ctx.r24.s64 = -2111242240;
	// addi r25,r8,29632
	ctx.r25.s64 = ctx.r8.s64 + 29632;
	// addi r27,r9,-344
	ctx.r27.s64 = ctx.r9.s64 + -344;
	// addi r26,r10,3124
	ctx.r26.s64 = ctx.r10.s64 + 3124;
	// addi r23,r11,-1768
	ctx.r23.s64 = ctx.r11.s64 + -1768;
loc_8209B4DC:
	// lbz r11,-22601(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8209b4fc
	if (!ctx.cr6.eq) goto loc_8209B4FC;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209B4FC;
	sub_820A71E8(ctx, base);
loc_8209B4FC:
	// bl 0x820b5eb8
	ctx.lr = 0x8209B500;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,140
	ctx.r4.s64 = 140;
	// lwzx r3,r11,r25
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x8209B510;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8209b5a8
	if (ctx.cr6.eq) goto loc_8209B5A8;
	// stw r29,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// addi r11,r3,84
	ctx.r11.s64 = ctx.r3.s64 + 84;
	// stw r27,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r27.u32);
	// addi r9,r3,36
	ctx.r9.s64 = ctx.r3.s64 + 36;
	// stw r31,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stb r30,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r30.u8);
	// stb r31,100(r3)
	REX_STORE_U8(ctx.r3.u32 + 100, ctx.r31.u8);
	// stb r31,101(r3)
	REX_STORE_U8(ctx.r3.u32 + 101, ctx.r31.u8);
	// stb r31,102(r3)
	REX_STORE_U8(ctx.r3.u32 + 102, ctx.r31.u8);
	// sth r31,28(r3)
	REX_STORE_U16(ctx.r3.u32 + 28, ctx.r31.u16);
	// stb r31,30(r3)
	REX_STORE_U8(ctx.r3.u32 + 30, ctx.r31.u8);
	// stb r31,35(r3)
	REX_STORE_U8(ctx.r3.u32 + 35, ctx.r31.u8);
loc_8209B550:
	// sth r31,0(r9)
	REX_STORE_U16(ctx.r9.u32 + 0, ctx.r31.u16);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stb r31,-16(r11)
	REX_STORE_U8(ctx.r11.u32 + -16, ctx.r31.u8);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// stb r31,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r31.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne 0x8209b550
	if (!ctx.cr0.eq) goto loc_8209B550;
	// addi r11,r3,108
	ctx.r11.s64 = ctx.r3.s64 + 108;
	// li r10,2
	ctx.r10.s64 = 2;
loc_8209B574:
	// stfs f31,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stfs f31,0(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bne 0x8209b574
	if (!ctx.cr0.eq) goto loc_8209B574;
	// stw r26,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r26.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stb r31,120(r3)
	REX_STORE_U8(ctx.r3.u32 + 120, ctx.r31.u8);
	// stw r31,124(r3)
	REX_STORE_U32(ctx.r3.u32 + 124, ctx.r31.u32);
	// stw r31,128(r3)
	REX_STORE_U32(ctx.r3.u32 + 128, ctx.r31.u32);
	// stw r31,132(r3)
	REX_STORE_U32(ctx.r3.u32 + 132, ctx.r31.u32);
	// stw r31,136(r3)
	REX_STORE_U32(ctx.r3.u32 + 136, ctx.r31.u32);
	// b 0x8209b5ac
	goto loc_8209B5AC;
loc_8209B5A8:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_8209B5AC:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x8209b4dc
	if (ctx.cr6.lt) goto loc_8209B4DC;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82129954
	__restgprlr_23(ctx, base);
	return;
}
