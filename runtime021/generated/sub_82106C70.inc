DEFINE_REX_FUNC(sub_82106C70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x82106C78;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x82106cc4
	if (!ctx.cr6.eq) goto loc_82106CC4;
	// lis r4,-32761
	ctx.r4.s64 = -2147024896;
	// ori r4,r4,1226
	ctx.r4.u64 = ctx.r4.u64 | 1226;
	// bl 0x821002a8
	ctx.lr = 0x82106C9C;
	sub_821002A8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82106e58
	if (ctx.cr0.lt) goto loc_82106E58;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// oris r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 1048576;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x82100718
	ctx.lr = 0x82106CC0;
	sub_82100718(ctx, base);
	// b 0x82106e58
	goto loc_82106E58;
loc_82106CC4:
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x82106ce0
	if (ctx.cr6.lt) goto loc_82106CE0;
loc_82106CCC:
	// lwz r3,396(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// bl 0x8210bc10
	ctx.lr = 0x82106CD4;
	sub_8210BC10(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// b 0x82106e54
	goto loc_82106E54;
loc_82106CE0:
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x82106cf4
	if (!ctx.cr6.eq) goto loc_82106CF4;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r11,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82106ccc
	if (!ctx.cr0.eq) goto loc_82106CCC;
loc_82106CF4:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r28,r31,248
	ctx.r28.s64 = ctx.r31.s64 + 248;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82106db4
	if (ctx.cr6.eq) goto loc_82106DB4;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82106db4
	if (ctx.cr0.eq) goto loc_82106DB4;
loc_82106D14:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r29,r27,-92
	ctx.r29.s64 = ctx.r27.s64 + -92;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82106d2c
	if (ctx.cr6.eq) goto loc_82106D2C;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
loc_82106D2C:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82106dac
	if (ctx.cr6.eq) goto loc_82106DAC;
	// lwz r4,100(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 100);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82106d50
	if (!ctx.cr6.eq) goto loc_82106D50;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x82106dac
	if (!ctx.cr6.eq) goto loc_82106DAC;
loc_82106D50:
	// lwz r11,396(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 396);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82106dac
	if (ctx.cr0.eq) goto loc_82106DAC;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82106da8
	if (ctx.cr6.eq) goto loc_82106DA8;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82106d84
	if (ctx.cr6.eq) goto loc_82106D84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r5,100(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// bl 0x82108e78
	ctx.lr = 0x82106D7C;
	sub_82108E78(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x82106d8c
	goto loc_82106D8C;
loc_82106D84:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_82106D8C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82106da8
	if (ctx.cr6.lt) goto loc_82106DA8;
	// bne cr6,0x82106dac
	if (!ctx.cr6.eq) goto loc_82106DAC;
	// lwz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// lwz r10,24(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82106dac
	if (!ctx.cr6.lt) goto loc_82106DAC;
loc_82106DA8:
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_82106DAC:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x82106d14
	if (!ctx.cr6.eq) goto loc_82106D14;
loc_82106DB4:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm r10,r10,0,2,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// ori r10,r10,128
	ctx.r10.u64 = ctx.r10.u64 | 128;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// stw r11,396(r30)
	REX_STORE_U32(ctx.r30.u32 + 396, ctx.r11.u32);
	// rlwinm. r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r3,396(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// beq 0x82106e2c
	if (ctx.cr0.eq) goto loc_82106E2C;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x8210bc10
	ctx.lr = 0x82106DFC;
	sub_8210BC10(ctx, base);
	// stw r30,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82109548
	ctx.lr = 0x82106E08;
	sub_82109548(ctx, base);
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// addi r4,r31,48
	ctx.r4.s64 = ctx.r31.s64 + 48;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x82129a70
	ctx.lr = 0x82106E18;
	sub_82129A70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821061d0
	ctx.lr = 0x82106E20;
	sub_821061D0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82106e3c
	if (!ctx.cr0.lt) goto loc_82106E3C;
	// b 0x82106e58
	goto loc_82106E58;
loc_82106E2C:
	// bl 0x8210bc10
	ctx.lr = 0x82106E30;
	sub_8210BC10(ctx, base);
	// stw r30,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82109548
	ctx.lr = 0x82106E3C;
	sub_82109548(ctx, base);
loc_82106E3C:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82106E54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82106E54:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82106E58:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
