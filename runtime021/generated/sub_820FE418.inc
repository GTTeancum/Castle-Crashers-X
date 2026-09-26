DEFINE_REX_FUNC(sub_820FE418) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129910
	ctx.lr = 0x820FE420;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r31,228
	ctx.r3.s64 = ctx.r31.s64 + 228;
	// addi r11,r11,-21112
	ctx.r11.s64 = ctx.r11.s64 + -21112;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// bl 0x821080c8
	ctx.lr = 0x820FE450;
	sub_821080C8(ctx, base);
	// addi r3,r31,240
	ctx.r3.s64 = ctx.r31.s64 + 240;
	// bl 0x82107c10
	ctx.lr = 0x820FE458;
	sub_82107C10(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = ctx.r31.s64 + 256;
	// bl 0x82109340
	ctx.lr = 0x820FE460;
	sub_82109340(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,424
	ctx.r3.s64 = ctx.r31.s64 + 424;
	// bl 0x82108f78
	ctx.lr = 0x820FE470;
	sub_82108F78(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// stw r27,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r27.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// stw r28,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r28.u32);
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// std r30,40(r31)
	REX_STORE_U64(ctx.r31.u32 + 40, ctx.r30.u64);
	// bl 0x82129fa0
	ctx.lr = 0x820FE4AC;
	sub_82129FA0(ctx, base);
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// bl 0x82129fa0
	ctx.lr = 0x820FE4BC;
	sub_82129FA0(ctx, base);
	// stb r30,168(r31)
	REX_STORE_U8(ctx.r31.u32 + 168, ctx.r30.u8);
	// stb r30,169(r31)
	REX_STORE_U8(ctx.r31.u32 + 169, ctx.r30.u8);
	// addi r11,r31,248
	ctx.r11.s64 = ctx.r31.s64 + 248;
	// stb r30,170(r31)
	REX_STORE_U8(ctx.r31.u32 + 170, ctx.r30.u8);
	// li r10,254
	ctx.r10.s64 = 254;
	// stb r30,171(r31)
	REX_STORE_U8(ctx.r31.u32 + 171, ctx.r30.u8);
	// li r5,84
	ctx.r5.s64 = 84;
	// stb r30,172(r31)
	REX_STORE_U8(ctx.r31.u32 + 172, ctx.r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r30,173(r31)
	REX_STORE_U8(ctx.r31.u32 + 173, ctx.r30.u8);
	// addi r3,r31,432
	ctx.r3.s64 = ctx.r31.s64 + 432;
	// stw r30,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r30.u32);
	// stw r30,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r30.u32);
	// stw r30,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r30.u32);
	// stw r30,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r30.u32);
	// stw r30,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r30.u32);
	// stw r30,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r30.u32);
	// std r30,200(r31)
	REX_STORE_U64(ctx.r31.u32 + 200, ctx.r30.u64);
	// std r30,208(r31)
	REX_STORE_U64(ctx.r31.u32 + 208, ctx.r30.u64);
	// std r30,216(r31)
	REX_STORE_U64(ctx.r31.u32 + 216, ctx.r30.u64);
	// stw r30,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r30.u32);
	// stw r11,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r11.u32);
	// stw r11,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r11.u32);
	// addi r11,r31,412
	ctx.r11.s64 = ctx.r31.s64 + 412;
	// stw r30,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r30.u32);
	// stw r30,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r30.u32);
	// stw r30,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r30.u32);
	// stw r30,392(r31)
	REX_STORE_U32(ctx.r31.u32 + 392, ctx.r30.u32);
	// stw r30,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r30.u32);
	// stw r30,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r30.u32);
	// stw r30,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r30.u32);
	// stw r30,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r30.u32);
	// stw r11,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r11.u32);
	// stw r11,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r11.u32);
	// stw r30,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r30.u32);
	// stw r10,428(r31)
	REX_STORE_U32(ctx.r31.u32 + 428, ctx.r10.u32);
	// bl 0x82129fa0
	ctx.lr = 0x820FE550;
	sub_82129FA0(ctx, base);
	// addi r10,r31,524
	ctx.r10.s64 = ctx.r31.s64 + 524;
	// stw r30,516(r31)
	REX_STORE_U32(ctx.r31.u32 + 516, ctx.r30.u32);
	// li r9,3500
	ctx.r9.s64 = 3500;
	// stw r30,520(r31)
	REX_STORE_U32(ctx.r31.u32 + 520, ctx.r30.u32);
	// stw r10,524(r31)
	REX_STORE_U32(ctx.r31.u32 + 524, ctx.r10.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r10,528(r31)
	REX_STORE_U32(ctx.r31.u32 + 528, ctx.r10.u32);
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// stw r9,532(r31)
	REX_STORE_U32(ctx.r31.u32 + 532, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,540(r31)
	REX_STORE_U32(ctx.r31.u32 + 540, ctx.r9.u32);
	// lis r9,14336
	ctx.r9.s64 = 939524096;
	// stw r11,536(r31)
	REX_STORE_U32(ctx.r31.u32 + 536, ctx.r11.u32);
	// stw r11,544(r31)
	REX_STORE_U32(ctx.r31.u32 + 544, ctx.r11.u32);
	// stw r10,548(r31)
	REX_STORE_U32(ctx.r31.u32 + 548, ctx.r10.u32);
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
	// stw r9,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82129960
	__restgprlr_26(ctx, base);
	return;
}
