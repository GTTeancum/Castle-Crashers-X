DEFINE_REX_FUNC(sub_82101D80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge cr6,0x82101dc8
	if (!ctx.cr6.lt) goto loc_82101DC8;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// rlwinm r11,r11,0,25,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x82105c40
	ctx.lr = 0x82101DBC;
	sub_82105C40(ctx, base);
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82101fdc
	if (ctx.cr0.eq) goto loc_82101FDC;
loc_82101DC8:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82101f20
	if (ctx.cr0.eq) goto loc_82101F20;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r10,8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 8, ctx.xer);
	// bge cr6,0x82101f20
	if (!ctx.cr6.lt) goto loc_82101F20;
	// rlwinm r11,r11,0,25,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x821005e8
	ctx.lr = 0x82101DF0;
	sub_821005E8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82101e3c
	if (ctx.cr6.eq) goto loc_82101E3C;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// lwz r5,520(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// rlwinm r11,r11,0,10,10
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200000;
	// lwz r4,516(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 516);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// addi r7,r11,5
	ctx.r7.s64 = ctx.r11.s64 + 5;
	// bl 0x820d7f18
	ctx.lr = 0x82101E28;
	sub_820D7F18(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82101e3c
	if (!ctx.cr0.eq) goto loc_82101E3C;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// oris r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 33554432;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
loc_82101E3C:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82101ec8
	if (!ctx.cr6.eq) goto loc_82101EC8;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ff170
	ctx.lr = 0x82101E74;
	sub_820FF170(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82101ec8
	if (ctx.cr0.lt) goto loc_82101EC8;
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// addi r30,r31,408
	ctx.r30.s64 = ctx.r31.s64 + 408;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82101ea4
	if (!ctx.cr6.eq) goto loc_82101EA4;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r6,1199
	ctx.r6.s64 = 1199;
	// li r5,1001
	ctx.r5.s64 = 1001;
	// addi r4,r31,92
	ctx.r4.s64 = ctx.r31.s64 + 92;
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// bl 0x8210c5b0
	ctx.lr = 0x82101EA4;
	sub_8210C5B0(ctx, base);
loc_82101EA4:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82101ebc
	if (ctx.cr6.lt) goto loc_82101EBC;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8210c058
	ctx.lr = 0x82101EBC;
	sub_8210C058(ctx, base);
loc_82101EBC:
	// li r3,260
	ctx.r3.s64 = 260;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82108f60
	ctx.lr = 0x82101EC8;
	sub_82108F60(ctx, base);
loc_82101EC8:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82101ef0
	if (ctx.cr6.eq) goto loc_82101EF0;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82101ef0
	if (ctx.cr6.eq) goto loc_82101EF0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82101f28
	if (!ctx.cr6.eq) goto loc_82101F28;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r11,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82101f28
	if (ctx.cr0.eq) goto loc_82101F28;
loc_82101EF0:
	// ld r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 48);
	// addi r4,r31,92
	ctx.r4.s64 = ctx.r31.s64 + 92;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// li r5,16
	ctx.r5.s64 = 16;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// bl 0x82129a70
	ctx.lr = 0x82101F08;
	sub_82129A70(ctx, base);
	// li r6,24
	ctx.r6.s64 = 24;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,111
	ctx.r4.s64 = 111;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82100538
	ctx.lr = 0x82101F1C;
	sub_82100538(ctx, base);
	// b 0x82101f28
	goto loc_82101F28;
loc_82101F20:
	// rlwinm r11,r11,0,25,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
loc_82101F28:
	// lwz r10,720(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r11,r10,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821020a8
	if (ctx.cr0.eq) goto loc_821020A8;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r10,r10,0,26,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// stw r10,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r10.u32);
	// beq cr6,0x82102094
	if (ctx.cr6.eq) goto loc_82102094;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82102050
	if (ctx.cr6.eq) goto loc_82102050;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// addi r11,r31,524
	ctx.r11.s64 = ctx.r31.s64 + 524;
	// beq cr6,0x82102004
	if (ctx.cr6.eq) goto loc_82102004;
	// lwz r9,524(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821020a8
	if (!ctx.cr6.eq) goto loc_821020A8;
	// oris r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 524288;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r10.u32);
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// std r11,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r11.u64);
	// std r11,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r11.u64);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// std r11,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r11.u64);
	// stw r11,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r11.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x821388e0
	ctx.lr = 0x82101F94;
	sub_821388E0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82101ff4
	if (ctx.cr0.eq) goto loc_82101FF4;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x82101ff4
	if (ctx.cr6.eq) goto loc_82101FF4;
loc_82101FA4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82136e38
	ctx.lr = 0x82101FAC;
	sub_82136E38(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82101fbc
	if (ctx.cr0.lt) goto loc_82101FBC;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
loc_82101FBC:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x82101fdc
	if (ctx.cr6.eq) goto loc_82101FDC;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82105c40
	ctx.lr = 0x82101FDC;
	sub_82105C40(ctx, base);
loc_82101FDC:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82101FF4:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,4936
	ctx.r11.s64 = ctx.r11.s64 + 4936;
loc_82101FFC:
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// b 0x82101fdc
	goto loc_82101FDC;
loc_82102004:
	// lwz r10,524(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821020a8
	if (!ctx.cr6.eq) goto loc_821020A8;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// std r11,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r11.u64);
	// std r11,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r11.u64);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// std r11,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r11.u64);
	// stw r11,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r11.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82138da0
	ctx.lr = 0x82102034;
	sub_82138DA0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82102044
	if (ctx.cr0.eq) goto loc_82102044;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x82101fa4
	if (!ctx.cr6.eq) goto loc_82101FA4;
loc_82102044:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,21224
	ctx.r11.s64 = ctx.r11.s64 + 21224;
	// b 0x82101ffc
	goto loc_82101FFC;
loc_82102050:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r31,200
	ctx.r30.s64 = ctx.r31.s64 + 200;
	// std r11,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r11.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r11,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r11.u64);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// std r11,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r11.u64);
	// stw r11,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r11.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82138d08
	ctx.lr = 0x82102078;
	sub_82138D08(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82102088
	if (ctx.cr0.eq) goto loc_82102088;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x82101fa4
	if (!ctx.cr6.eq) goto loc_82101FA4;
loc_82102088:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,24584
	ctx.r11.s64 = ctx.r11.s64 + 24584;
	// b 0x82101ffc
	goto loc_82101FFC;
loc_82102094:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82104c20
	ctx.lr = 0x8210209C;
	sub_82104C20(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82101fbc
	if (!ctx.cr0.eq) goto loc_82101FBC;
	// b 0x82101fdc
	goto loc_82101FDC;
loc_821020A8:
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// rlwinm. r10,r11,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x821020d0
	if (ctx.cr0.eq) goto loc_821020D0;
	// rlwinm r11,r11,0,24,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFEFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x821061d0
	ctx.lr = 0x821020C4;
	sub_821061D0(ctx, base);
loc_821020C4:
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82101fbc
	if (ctx.cr0.lt) goto loc_82101FBC;
	// b 0x82101fdc
	goto loc_82101FDC;
loc_821020D0:
	// rlwinm. r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82101fdc
	if (ctx.cr0.eq) goto loc_82101FDC;
	// rlwinm r11,r11,0,23,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// bl 0x821015d0
	ctx.lr = 0x821020E8;
	sub_821015D0(ctx, base);
	// b 0x821020c4
	goto loc_821020C4;
}
