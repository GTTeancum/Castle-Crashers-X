DEFINE_REX_FUNC(sub_8213A990) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f0
	ctx.lr = 0x8213A998;
	__savegprlr_18(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8213aaac
	if (!ctx.cr6.eq) goto loc_8213AAAC;
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// lis r10,-32236
	ctx.r10.s64 = -2112618496;
	// addi r11,r11,-26776
	ctx.r11.s64 = ctx.r11.s64 + -26776;
	// lis r9,-32236
	ctx.r9.s64 = -2112618496;
	// lis r8,-32236
	ctx.r8.s64 = -2112618496;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// addi r10,r10,-24096
	ctx.r10.s64 = ctx.r10.s64 + -24096;
	// addi r9,r9,-26736
	ctx.r9.s64 = ctx.r9.s64 + -26736;
	// addi r11,r8,-26600
	ctx.r11.s64 = ctx.r8.s64 + -26600;
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r7,-32236
	ctx.r7.s64 = -2112618496;
	// stw r9,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lis r6,-32236
	ctx.r6.s64 = -2112618496;
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// lis r5,-32236
	ctx.r5.s64 = -2112618496;
	// addi r10,r7,-26488
	ctx.r10.s64 = ctx.r7.s64 + -26488;
	// addi r9,r6,-23632
	ctx.r9.s64 = ctx.r6.s64 + -23632;
	// addi r11,r5,-23520
	ctx.r11.s64 = ctx.r5.s64 + -23520;
	// stw r10,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// lis r4,-32236
	ctx.r4.s64 = -2112618496;
	// stw r9,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// lis r31,-32236
	ctx.r31.s64 = -2112618496;
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lis r30,-32236
	ctx.r30.s64 = -2112618496;
	// addi r10,r4,-26376
	ctx.r10.s64 = ctx.r4.s64 + -26376;
	// addi r9,r31,-26336
	ctx.r9.s64 = ctx.r31.s64 + -26336;
	// addi r11,r30,-26152
	ctx.r11.s64 = ctx.r30.s64 + -26152;
	// stw r10,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r10.u32);
	// lis r29,-32236
	ctx.r29.s64 = -2112618496;
	// stw r9,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// lis r28,-32236
	ctx.r28.s64 = -2112618496;
	// stw r11,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// lis r27,-32236
	ctx.r27.s64 = -2112618496;
	// addi r10,r29,-23408
	ctx.r10.s64 = ctx.r29.s64 + -23408;
	// addi r9,r28,-23144
	ctx.r9.s64 = ctx.r28.s64 + -23144;
	// addi r11,r27,-23048
	ctx.r11.s64 = ctx.r27.s64 + -23048;
	// stw r10,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// lis r26,-32236
	ctx.r26.s64 = -2112618496;
	// stw r9,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
	// lis r25,-32236
	ctx.r25.s64 = -2112618496;
	// stw r11,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// lis r24,-32236
	ctx.r24.s64 = -2112618496;
	// addi r10,r26,-26016
	ctx.r10.s64 = ctx.r26.s64 + -26016;
	// addi r9,r25,-25928
	ctx.r9.s64 = ctx.r25.s64 + -25928;
	// addi r11,r24,-22856
	ctx.r11.s64 = ctx.r24.s64 + -22856;
	// stw r10,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r10.u32);
	// lis r23,-32236
	ctx.r23.s64 = -2112618496;
	// stw r9,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r9.u32);
	// lis r22,-32236
	ctx.r22.s64 = -2112618496;
	// stw r11,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// lis r21,-32236
	ctx.r21.s64 = -2112618496;
	// addi r10,r23,-22768
	ctx.r10.s64 = ctx.r23.s64 + -22768;
	// addi r9,r22,-22664
	ctx.r9.s64 = ctx.r22.s64 + -22664;
	// addi r11,r21,-25880
	ctx.r11.s64 = ctx.r21.s64 + -25880;
	// stw r10,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// lis r20,-32236
	ctx.r20.s64 = -2112618496;
	// stw r9,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r9.u32);
	// lis r19,-32236
	ctx.r19.s64 = -2112618496;
	// stw r11,72(r3)
	REX_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// lis r18,-32236
	ctx.r18.s64 = -2112618496;
	// addi r10,r20,-25872
	ctx.r10.s64 = ctx.r20.s64 + -25872;
	// addi r9,r19,-22528
	ctx.r9.s64 = ctx.r19.s64 + -22528;
	// addi r11,r18,-22416
	ctx.r11.s64 = ctx.r18.s64 + -22416;
	// stw r10,76(r3)
	REX_STORE_U32(ctx.r3.u32 + 76, ctx.r10.u32);
	// stw r9,80(r3)
	REX_STORE_U32(ctx.r3.u32 + 80, ctx.r9.u32);
	// stw r11,84(r3)
	REX_STORE_U32(ctx.r3.u32 + 84, ctx.r11.u32);
loc_8213AAAC:
	// b 0x82129940
	__restgprlr_18(ctx, base);
	return;
}
