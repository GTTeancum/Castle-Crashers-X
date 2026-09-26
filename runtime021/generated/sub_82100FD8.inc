DEFINE_REX_FUNC(sub_82100FD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x82100FE0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// addi r3,r31,200
	ctx.r3.s64 = ctx.r31.s64 + 200;
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// bne cr6,0x82101000
	if (!ctx.cr6.eq) goto loc_82101000;
	// bl 0x820b6ca8
	ctx.lr = 0x82101000;
	sub_820B6CA8(ctx, base);
loc_82101000:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// li r30,0
	ctx.r30.s64 = 0;
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r30,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r30.u32);
	// beq 0x82101038
	if (ctx.cr0.eq) goto loc_82101038;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// bl 0x820d7f18
	ctx.lr = 0x8210102C;
	sub_820D7F18(ctx, base);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm r11,r11,0,7,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFDFFFFFF;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
loc_82101038:
	// lwz r3,408(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210104c
	if (ctx.cr6.eq) goto loc_8210104C;
	// bl 0x8210c510
	ctx.lr = 0x82101048;
	sub_8210C510(ctx, base);
	// stw r30,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r30.u32);
loc_8210104C:
	// lwz r11,524(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// addi r29,r31,524
	ctx.r29.s64 = ctx.r31.s64 + 524;
loc_82101054:
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82101098
	if (ctx.cr6.eq) goto loc_82101098;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r28,r11,-4
	ctx.r28.s64 = ctx.r11.s64 + -4;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// bl 0x8210bc48
	ctx.lr = 0x82101088;
	sub_8210BC48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8210be88
	ctx.lr = 0x82101090;
	sub_8210BE88(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x82101054
	goto loc_82101054;
loc_82101098:
	// lwz r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821010f0
	if (ctx.cr6.eq) goto loc_821010F0;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r5,r11,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// bl 0x82100718
	ctx.lr = 0x821010C0;
	sub_82100718(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x821010f0
	if (!ctx.cr0.lt) goto loc_821010F0;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821010f0
	if (ctx.cr6.eq) goto loc_821010F0;
	// bl 0x82108e28
	ctx.lr = 0x821010D8;
	sub_82108E28(ctx, base);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// stw r30,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r30.u32);
	// rlwinm r11,r11,0,16,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFEFFFF;
	// stw r30,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r30.u32);
	// rlwinm r11,r11,0,10,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFF3FFFFF;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
loc_821010F0:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ffcb0
	ctx.lr = 0x82101100;
	sub_820FFCB0(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101190
	if (ctx.cr6.eq) goto loc_82101190;
	// rlwinm. r11,r11,0,12,12
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82101120
	if (!ctx.cr0.eq) goto loc_82101120;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821388e0
	ctx.lr = 0x82101120;
	sub_821388E0(ctx, base);
loc_82101120:
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82136f68
	ctx.lr = 0x82101128;
	sub_82136F68(ctx, base);
	// lis r12,-16649
	ctx.r12.s64 = -1091108864;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// li r5,60
	ctx.r5.s64 = 60;
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// ori r12,r12,63551
	ctx.r12.u64 = ctx.r12.u64 | 63551;
	// std r30,40(r31)
	REX_STORE_U64(ctx.r31.u32 + 40, ctx.r30.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// and r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 & ctx.r12.u64;
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x82129fa0
	ctx.lr = 0x82101154;
	sub_82129FA0(ctx, base);
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// bl 0x82129fa0
	ctx.lr = 0x82101164;
	sub_82129FA0(ctx, base);
	// lwz r4,184(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// stb r30,168(r31)
	REX_STORE_U8(ctx.r31.u32 + 168, ctx.r30.u8);
	// stb r30,169(r31)
	REX_STORE_U8(ctx.r31.u32 + 169, ctx.r30.u8);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82101184
	if (ctx.cr6.eq) goto loc_82101184;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82108f60
	ctx.lr = 0x82101180;
	sub_82108F60(ctx, base);
	// stw r30,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r30.u32);
loc_82101184:
	// stw r30,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r30.u32);
	// stw r30,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r30.u32);
	// b 0x821011a8
	goto loc_821011A8;
loc_82101190:
	// lis r12,-16641
	ctx.r12.s64 = -1090584576;
	// stb r30,168(r31)
	REX_STORE_U8(ctx.r31.u32 + 168, ctx.r30.u8);
	// stb r30,169(r31)
	REX_STORE_U8(ctx.r31.u32 + 169, ctx.r30.u8);
	// ori r12,r12,64511
	ctx.r12.u64 = ctx.r12.u64 | 64511;
	// and r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 & ctx.r12.u64;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
loc_821011A8:
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// addi r29,r31,412
	ctx.r29.s64 = ctx.r31.s64 + 412;
	// b 0x821011c4
	goto loc_821011C4;
loc_821011B4:
	// addi r3,r11,-12
	ctx.r3.s64 = ctx.r11.s64 + -12;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82109a50
	ctx.lr = 0x821011C0;
	sub_82109A50(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
loc_821011C4:
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x821011d4
	if (ctx.cr6.eq) goto loc_821011D4;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x821011b4
	if (!ctx.cr0.eq) goto loc_821011B4;
loc_821011D4:
	// addi r3,r31,240
	ctx.r3.s64 = ctx.r31.s64 + 240;
	// bl 0x82107c20
	ctx.lr = 0x821011DC;
	sub_82107C20(ctx, base);
	// addi r3,r31,228
	ctx.r3.s64 = ctx.r31.s64 + 228;
	// bl 0x821080e0
	ctx.lr = 0x821011E4;
	sub_821080E0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fcfb0
	ctx.lr = 0x821011F4;
	sub_820FCFB0(ctx, base);
	// lis r12,-53
	ctx.r12.s64 = -3473408;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// ori r12,r12,65503
	ctx.r12.u64 = ctx.r12.u64 | 65503;
	// and r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 & ctx.r12.u64;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// std r30,552(r31)
	REX_STORE_U64(ctx.r31.u32 + 552, ctx.r30.u64);
	// std r30,560(r31)
	REX_STORE_U64(ctx.r31.u32 + 560, ctx.r30.u64);
	// std r30,568(r31)
	REX_STORE_U64(ctx.r31.u32 + 568, ctx.r30.u64);
	// std r30,576(r31)
	REX_STORE_U64(ctx.r31.u32 + 576, ctx.r30.u64);
	// std r30,584(r31)
	REX_STORE_U64(ctx.r31.u32 + 584, ctx.r30.u64);
	// std r30,592(r31)
	REX_STORE_U64(ctx.r31.u32 + 592, ctx.r30.u64);
	// std r30,600(r31)
	REX_STORE_U64(ctx.r31.u32 + 600, ctx.r30.u64);
	// std r30,608(r31)
	REX_STORE_U64(ctx.r31.u32 + 608, ctx.r30.u64);
	// std r30,616(r31)
	REX_STORE_U64(ctx.r31.u32 + 616, ctx.r30.u64);
	// std r30,624(r31)
	REX_STORE_U64(ctx.r31.u32 + 624, ctx.r30.u64);
	// std r30,632(r31)
	REX_STORE_U64(ctx.r31.u32 + 632, ctx.r30.u64);
	// std r30,640(r31)
	REX_STORE_U64(ctx.r31.u32 + 640, ctx.r30.u64);
	// std r30,648(r31)
	REX_STORE_U64(ctx.r31.u32 + 648, ctx.r30.u64);
	// std r30,656(r31)
	REX_STORE_U64(ctx.r31.u32 + 656, ctx.r30.u64);
	// std r30,664(r31)
	REX_STORE_U64(ctx.r31.u32 + 664, ctx.r30.u64);
	// std r30,672(r31)
	REX_STORE_U64(ctx.r31.u32 + 672, ctx.r30.u64);
	// std r30,680(r31)
	REX_STORE_U64(ctx.r31.u32 + 680, ctx.r30.u64);
	// std r30,688(r31)
	REX_STORE_U64(ctx.r31.u32 + 688, ctx.r30.u64);
	// stw r30,696(r31)
	REX_STORE_U32(ctx.r31.u32 + 696, ctx.r30.u32);
	// stw r30,700(r31)
	REX_STORE_U32(ctx.r31.u32 + 700, ctx.r30.u32);
	// stw r30,704(r31)
	REX_STORE_U32(ctx.r31.u32 + 704, ctx.r30.u32);
	// stw r30,708(r31)
	REX_STORE_U32(ctx.r31.u32 + 708, ctx.r30.u32);
	// stw r30,712(r31)
	REX_STORE_U32(ctx.r31.u32 + 712, ctx.r30.u32);
	// stw r30,716(r31)
	REX_STORE_U32(ctx.r31.u32 + 716, ctx.r30.u32);
	// lwz r4,20(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x82101298
	if (ctx.cr6.eq) goto loc_82101298;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r27,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r27.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82101298;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82101298:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
