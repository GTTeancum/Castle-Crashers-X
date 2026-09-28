DEFINE_REX_FUNC(sub_82101348) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212991c
	ctx.lr = 0x82101350;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x8210136c
	if (!ctx.cr6.lt) goto loc_8210136C;
	// bl 0x82100fd8
	ctx.lr = 0x82101368;
	sub_82100FD8(ctx, base);
	// b 0x82101490
	goto loc_82101490;
loc_8210136C:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x820ffcb0
	ctx.lr = 0x82101378;
	sub_820FFCB0(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821013bc
	if (ctx.cr6.eq) goto loc_821013BC;
	// bl 0x82136f68
	ctx.lr = 0x8210138C;
	sub_82136F68(ctx, base);
	// lis r12,-16393
	ctx.r12.s64 = -1074331648;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// li r5,60
	ctx.r5.s64 = 60;
	// ori r12,r12,64511
	ctx.r12.u64 = ctx.r12.u64 | 64511;
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r30,40(r31)
	REX_STORE_U64(ctx.r31.u32 + 40, ctx.r30.u64);
	// and r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 & ctx.r12.u64;
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x82129fa0
	ctx.lr = 0x821013B8;
	sub_82129FA0(ctx, base);
	// b 0x821013cc
	goto loc_821013CC;
loc_821013BC:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm r11,r11,0,22,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFBFF;
	// rlwinm r11,r11,0,2,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
loc_821013CC:
	// stb r30,168(r31)
	REX_STORE_U8(ctx.r31.u32 + 168, ctx.r30.u8);
	// addi r3,r31,228
	ctx.r3.s64 = ctx.r31.s64 + 228;
	// stb r30,169(r31)
	REX_STORE_U8(ctx.r31.u32 + 169, ctx.r30.u8);
	// bl 0x821080e0
	ctx.lr = 0x821013DC;
	sub_821080E0(ctx, base);
	// addi r3,r31,240
	ctx.r3.s64 = ctx.r31.s64 + 240;
	// bl 0x82107c20
	ctx.lr = 0x821013E4;
	sub_82107C20(ctx, base);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm r11,r11,0,14,12
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFBFFFF;
	// rlwinm r11,r11,0,12,9
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFCFFFFF;
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
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// beq cr6,0x8210146c
	if (ctx.cr6.eq) goto loc_8210146C;
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// beq cr6,0x8210146c
	if (ctx.cr6.eq) goto loc_8210146C;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_8210146C:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// stw r29,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
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
	ctx.lr = 0x82101490;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82101490:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8212996c
	__restgprlr_29(ctx, base);
	return;
}
