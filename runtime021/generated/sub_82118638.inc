DEFINE_REX_FUNC(sub_82118638) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x82118640;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r24,1
	ctx.r24.s64 = 1;
	// stw r8,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// addi r11,r11,-20668
	ctx.r11.s64 = ctx.r11.s64 + -20668;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// addi r10,r10,-20460
	ctx.r10.s64 = ctx.r10.s64 + -20460;
	// stw r24,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r24.u32);
	// addi r9,r9,-20468
	ctx.r9.s64 = ctx.r9.s64 + -20468;
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// addi r29,r31,340
	ctx.r29.s64 = ctx.r31.s64 + 340;
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// stw r9,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// mr r22,r7
	ctx.r22.u64 = ctx.r7.u64;
	// addi r28,r31,20
	ctx.r28.s64 = ctx.r31.s64 + 20;
	// bl 0x82117bf8
	ctx.lr = 0x821186B0;
	sub_82117BF8(ctx, base);
	// addi r27,r31,392
	ctx.r27.s64 = ctx.r31.s64 + 392;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82117bf8
	ctx.lr = 0x821186C4;
	sub_82117BF8(ctx, base);
	// addi r10,r26,32
	ctx.r10.s64 = ctx.r26.s64 + 32;
	// addi r11,r31,32
	ctx.r11.s64 = ctx.r31.s64 + 32;
	// stw r26,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r26.u32);
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// addi r3,r31,40
	ctx.r3.s64 = ctx.r31.s64 + 40;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bl 0x8211fcd8
	ctx.lr = 0x821186E4;
	sub_8211FCD8(ctx, base);
	// stw r24,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r24.u32);
	// stw r30,440(r31)
	REX_STORE_U32(ctx.r31.u32 + 440, ctx.r30.u32);
	// addi r3,r31,164
	ctx.r3.s64 = ctx.r31.s64 + 164;
	// bl 0x8214a424
	ctx.lr = 0x821186F4;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// addi r11,r31,192
	ctx.r11.s64 = ctx.r31.s64 + 192;
	// addi r10,r31,280
	ctx.r10.s64 = ctx.r31.s64 + 280;
	// stw r11,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r11.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// addi r11,r31,292
	ctx.r11.s64 = ctx.r31.s64 + 292;
	// stw r30,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r30.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r10,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r10.u32);
	// stw r10,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r10.u32);
	// stw r11,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
	// stw r11,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r11.u32);
	// bl 0x82117bf8
	ctx.lr = 0x82118730;
	sub_82117BF8(ctx, base);
	// addi r11,r31,332
	ctx.r11.s64 = ctx.r31.s64 + 332;
	// stw r23,432(r31)
	REX_STORE_U32(ctx.r31.u32 + 432, ctx.r23.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r30.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r30,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r30.u32);
	// stw r11,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
	// stw r11,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
	// bl 0x82117bf8
	ctx.lr = 0x8211875C;
	sub_82117BF8(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r22,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r22.u32);
	// addi r3,r31,236
	ctx.r3.s64 = ctx.r31.s64 + 236;
	// stw r11,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
	// bl 0x8214a424
	ctx.lr = 0x82118770;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// stw r30,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r30.u32);
	// stw r30,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r30.u32);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// stw r30,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r30.u32);
	// stw r30,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r30.u32);
	// std r30,304(r31)
	REX_STORE_U64(ctx.r31.u32 + 304, ctx.r30.u64);
	// stw r30,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r30.u32);
	// beq cr6,0x821187a8
	if (ctx.cr6.eq) goto loc_821187A8;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// stw r11,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r11.u32);
	// lhz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x821187b0
	if (!ctx.cr0.eq) goto loc_821187B0;
	// b 0x821187ac
	goto loc_821187AC;
loc_821187A8:
	// stw r30,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r30.u32);
loc_821187AC:
	// li r11,1000
	ctx.r11.s64 = 1000;
loc_821187B0:
	// sth r11,268(r31)
	REX_STORE_U16(ctx.r31.u32 + 268, ctx.r11.u16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211fb60
	ctx.lr = 0x821187BC;
	sub_8211FB60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
