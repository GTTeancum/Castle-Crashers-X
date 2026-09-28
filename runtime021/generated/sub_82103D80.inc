DEFINE_REX_FUNC(sub_82103D80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82103D88;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lwz r11,404(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 404);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,404(r30)
	REX_STORE_U32(ctx.r30.u32 + 404, ctx.r11.u32);
	// lwz r31,20(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 20);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82103e4c
	if (ctx.cr6.eq) goto loc_82103E4C;
	// addi r28,r30,256
	ctx.r28.s64 = ctx.r30.s64 + 256;
loc_82103DB0:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r29,88(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820fe778
	ctx.lr = 0x82103DC4;
	sub_820FE778(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210b298
	ctx.lr = 0x82103DCC;
	sub_8210B298(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82109430
	ctx.lr = 0x82103DE0;
	sub_82109430(ctx, base);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82103dfc
	if (ctx.cr0.eq) goto loc_82103DFC;
	// lbz r11,171(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 171);
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// stb r11,171(r30)
	REX_STORE_U8(ctx.r30.u32 + 171, ctx.r11.u8);
	// b 0x82103e08
	goto loc_82103E08;
loc_82103DFC:
	// lbz r11,170(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 170);
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// stb r11,170(r30)
	REX_STORE_U8(ctx.r30.u32 + 170, ctx.r11.u8);
loc_82103E08:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210bc10
	ctx.lr = 0x82103E10;
	sub_8210BC10(ctx, base);
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82103db0
	if (!ctx.cr6.eq) goto loc_82103DB0;
	// lwz r11,720(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 720);
	// rlwinm. r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82103e40
	if (!ctx.cr0.eq) goto loc_82103E40;
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82103e40
	if (ctx.cr0.eq) goto loc_82103E40;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82102940
	ctx.lr = 0x82103E40;
	sub_82102940(ctx, base);
loc_82103E40:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// bl 0x820fcea0
	ctx.lr = 0x82103E4C;
	sub_820FCEA0(ctx, base);
loc_82103E4C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
