DEFINE_REX_FUNC(xstart) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820B7098;
	__savegprlr_28(ctx, base);
	// addi r31,r1,-496
	ctx.r31.s64 = ctx.r1.s64 + -496;
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,3244(r9)
	REX_STORE_U32(ctx.r9.u32 + 3244, ctx.r11.u32);
	// stw r10,3248(r8)
	REX_STORE_U32(ctx.r8.u32 + 3248, ctx.r10.u32);
	// bl 0x820b7958
	ctx.lr = 0x820B70C8;
	sub_820B7958(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x820b77a8
	ctx.lr = 0x820B70D0;
	sub_820B77A8(ctx, base);
	// bl 0x820b6ea8
	ctx.lr = 0x820B70D4;
	sub_820B6EA8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820b70e4
	if (ctx.cr0.eq) goto loc_820B70E4;
	// bl 0x8214a404
	ctx.lr = 0x820B70E0;
	__imp__XamLoaderTerminateTitle(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_820B70E4:
	// bl 0x8212a630
	ctx.lr = 0x820B70E8;
	sub_8212A630(ctx, base);
	// bl 0x820b7730
	ctx.lr = 0x820B70EC;
	sub_820B7730(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x820b7650
	ctx.lr = 0x820B70F4;
	sub_820B7650(ctx, base);
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// lwz r11,904(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 904);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820b721c
	if (ctx.cr6.eq) goto loc_820B721C;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r31,112
	ctx.r30.s64 = ctx.r31.s64 + 112;
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// stw r30,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// stw r28,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r28.u32);
	// bl 0x820b7640
	ctx.lr = 0x820B711C;
	sub_820B7640(ctx, base);
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820b7200
	if (ctx.cr0.eq) goto loc_820B7200;
	// addi r10,r31,192
	ctx.r10.s64 = ctx.r31.s64 + 192;
	// stw r10,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
loc_820B7130:
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// stb r11,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r11.u8);
loc_820B7138:
	// extsb. r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820b7174
	if (ctx.cr0.eq) goto loc_820B7174;
	// cmpwi cr6,r9,32
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 32, ctx.xer);
	// beq cr6,0x820b7150
	if (ctx.cr6.eq) goto loc_820B7150;
	// cmpwi cr6,r9,9
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 9, ctx.xer);
	// bne cr6,0x820b7174
	if (!ctx.cr6.eq) goto loc_820B7174;
loc_820B7150:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// stb r29,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r29.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// stw r10,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// stb r11,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r11.u8);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x820b7138
	goto loc_820B7138;
loc_820B7174:
	// extsb. r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x820b71ec
	if (ctx.cr0.eq) goto loc_820B71EC;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// stw r28,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r28.u32);
	// stw r30,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// stw r8,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r8.u32);
loc_820B7198:
	// cmpwi cr6,r9,34
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 34, ctx.xer);
	// beq cr6,0x820b71b0
	if (ctx.cr6.eq) goto loc_820B71B0;
	// stb r11,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// b 0x820b71bc
	goto loc_820B71BC;
loc_820B71B0:
	// cntlzw r11,r8
	ctx.r11.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r8,r11,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stw r8,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r8.u32);
loc_820B71BC:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// extsb. r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stb r11,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r11.u8);
	// beq 0x820b71ec
	if (ctx.cr0.eq) goto loc_820B71EC;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x820b7198
	if (!ctx.cr6.eq) goto loc_820B7198;
	// cmpwi cr6,r9,32
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 32, ctx.xer);
	// beq cr6,0x820b71ec
	if (ctx.cr6.eq) goto loc_820B71EC;
	// cmpwi cr6,r9,9
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 9, ctx.xer);
	// bne cr6,0x820b7198
	if (!ctx.cr6.eq) goto loc_820B7198;
loc_820B71EC:
	// extsb. r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820b71fc
	if (ctx.cr0.eq) goto loc_820B71FC;
	// cmpwi cr6,r28,16
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 16, ctx.xer);
	// ble cr6,0x820b7130
	if (!ctx.cr6.gt) goto loc_820B7130;
loc_820B71FC:
	// stb r29,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r29.u8);
loc_820B7200:
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
	// stw r29,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
	// addi r4,r31,112
	ctx.r4.s64 = ctx.r31.s64 + 112;
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// b 0x820b7224
	goto loc_820B7224;
loc_820B721C:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_820B7224:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82070ac8
	ctx.lr = 0x820B722C;
	sub_82070AC8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8212a270
	ctx.lr = 0x820B7234;
	sub_8212A270(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r11,4704
	ctx.r3.s64 = ctx.r11.s64 + 4704;
	// bl 0x8214a5a4
	ctx.lr = 0x820B7244;
	__imp__DbgPrint(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// bl 0x8214a404
	ctx.lr = 0x820B7254;
	__imp__XamLoaderTerminateTitle(ctx, base);
}
