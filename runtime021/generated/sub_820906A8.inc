DEFINE_REX_FUNC(sub_820906A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820906B0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32215
	ctx.r30.s64 = -2111242240;
	// lis r11,-32221
	ctx.r11.s64 = -2111635456;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r28,r11,-1768
	ctx.r28.s64 = ctx.r11.s64 + -1768;
	// lbz r11,-22601(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + -22601);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820906e4
	if (!ctx.cr6.eq) goto loc_820906E4;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820906E4;
	sub_820A71E8(ctx, base);
loc_820906E4:
	// bl 0x820b5eb8
	ctx.lr = 0x820906E8;
	sub_820B5EB8(ctx, base);
	// lis r11,-32218
	ctx.r11.s64 = -2111438848;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r11,29632
	ctx.r29.s64 = ctx.r11.s64 + 29632;
	// li r4,48
	ctx.r4.s64 = 48;
	// lwzx r3,r10,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82090700;
	sub_8209BDD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x82090748
	if (ctx.cr6.eq) goto loc_82090748;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stb r11,12(r3)
	REX_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// stw r11,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stw r11,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r11,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r9,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// stw r10,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// stw r10,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r10.u32);
loc_82090748:
	// lbz r10,-22601(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + -22601);
	// stw r11,10316(r31)
	REX_STORE_U32(ctx.r31.u32 + 10316, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8209076c
	if (!ctx.cr6.eq) goto loc_8209076C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x8209076C;
	sub_820A71E8(ctx, base);
loc_8209076C:
	// bl 0x820b5eb8
	ctx.lr = 0x82090770;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,2
	ctx.r4.s64 = 131072;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x82090780;
	sub_8209BDD8(ctx, base);
	// lbz r10,-22601(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + -22601);
	// stw r3,10320(r31)
	REX_STORE_U32(ctx.r31.u32 + 10320, ctx.r3.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820907a4
	if (!ctx.cr6.eq) goto loc_820907A4;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820907A4;
	sub_820A71E8(ctx, base);
loc_820907A4:
	// bl 0x820b5eb8
	ctx.lr = 0x820907A8;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,0
	ctx.r4.s64 = 0;
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820907BC;
	sub_8209BDD8(ctx, base);
	// lbz r10,-22601(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + -22601);
	// stw r3,10324(r31)
	REX_STORE_U32(ctx.r31.u32 + 10324, ctx.r3.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820907e0
	if (!ctx.cr6.eq) goto loc_820907E0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// bl 0x820a71e8
	ctx.lr = 0x820907E0;
	sub_820A71E8(ctx, base);
loc_820907E0:
	// bl 0x820b5eb8
	ctx.lr = 0x820907E4;
	sub_820B5EB8(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,0
	ctx.r4.s64 = 0;
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// bl 0x8209bdd8
	ctx.lr = 0x820907F8;
	sub_8209BDD8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r3,10328(r31)
	REX_STORE_U32(ctx.r31.u32 + 10328, ctx.r3.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82090814;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r8,16384
	ctx.r8.s64 = 16384;
	// lwz r9,10328(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 10328);
	// li r6,8192
	ctx.r6.s64 = 8192;
	// lwz r7,10324(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 10324);
	// lis r4,2
	ctx.r4.s64 = 131072;
	// lwz r5,10320(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 10320);
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d758
	ctx.lr = 0x82090838;
	sub_8209D758(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// addi r5,r7,-4280
	ctx.r5.s64 = ctx.r7.s64 + -4280;
	// bl 0x8209d840
	ctx.lr = 0x8209084C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r6,-4272
	ctx.r5.s64 = ctx.r6.s64 + -4272;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090860;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r5,-4268
	ctx.r5.s64 = ctx.r5.s64 + -4268;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090874;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r5,r3,-4260
	ctx.r5.s64 = ctx.r3.s64 + -4260;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090888;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r5,r11,-4252
	ctx.r5.s64 = ctx.r11.s64 + -4252;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x8209089C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r5,r10,-4244
	ctx.r5.s64 = ctx.r10.s64 + -4244;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820908B0;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r5,r9,-4232
	ctx.r5.s64 = ctx.r9.s64 + -4232;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820908C4;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r5,r8,-4224
	ctx.r5.s64 = ctx.r8.s64 + -4224;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820908D8;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,9
	ctx.r4.s64 = 9;
	// addi r5,r7,-4216
	ctx.r5.s64 = ctx.r7.s64 + -4216;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820908EC;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r5,r6,-4212
	ctx.r5.s64 = ctx.r6.s64 + -4212;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090900;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,11
	ctx.r4.s64 = 11;
	// addi r5,r5,-4204
	ctx.r5.s64 = ctx.r5.s64 + -4204;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090914;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r5,r3,-4196
	ctx.r5.s64 = ctx.r3.s64 + -4196;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090928;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,13
	ctx.r4.s64 = 13;
	// addi r5,r11,-4188
	ctx.r5.s64 = ctx.r11.s64 + -4188;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x8209093C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,14
	ctx.r4.s64 = 14;
	// addi r5,r10,-4180
	ctx.r5.s64 = ctx.r10.s64 + -4180;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090950;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,15
	ctx.r4.s64 = 15;
	// addi r5,r9,-4176
	ctx.r5.s64 = ctx.r9.s64 + -4176;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090964;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r5,r8,-4168
	ctx.r5.s64 = ctx.r8.s64 + -4168;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090978;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,17
	ctx.r4.s64 = 17;
	// addi r5,r7,-4164
	ctx.r5.s64 = ctx.r7.s64 + -4164;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x8209098C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,18
	ctx.r4.s64 = 18;
	// addi r5,r6,-4160
	ctx.r5.s64 = ctx.r6.s64 + -4160;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820909A0;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,19
	ctx.r4.s64 = 19;
	// addi r5,r5,-4156
	ctx.r5.s64 = ctx.r5.s64 + -4156;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820909B4;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,20
	ctx.r4.s64 = 20;
	// addi r5,r3,-4152
	ctx.r5.s64 = ctx.r3.s64 + -4152;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820909C8;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,21
	ctx.r4.s64 = 21;
	// addi r5,r11,-4144
	ctx.r5.s64 = ctx.r11.s64 + -4144;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820909DC;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,22
	ctx.r4.s64 = 22;
	// addi r5,r10,-4136
	ctx.r5.s64 = ctx.r10.s64 + -4136;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820909F0;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r5,r9,-4132
	ctx.r5.s64 = ctx.r9.s64 + -4132;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090A04;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r8,-4124
	ctx.r5.s64 = ctx.r8.s64 + -4124;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090A18;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,25
	ctx.r4.s64 = 25;
	// addi r5,r7,-4112
	ctx.r5.s64 = ctx.r7.s64 + -4112;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090A2C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,26
	ctx.r4.s64 = 26;
	// addi r5,r6,-4088
	ctx.r5.s64 = ctx.r6.s64 + -4088;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090A40;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,27
	ctx.r4.s64 = 27;
	// addi r5,r5,-4068
	ctx.r5.s64 = ctx.r5.s64 + -4068;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090A54;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r5,r3,-4052
	ctx.r5.s64 = ctx.r3.s64 + -4052;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090A68;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// li r4,29
	ctx.r4.s64 = 29;
	// addi r5,r11,-4040
	ctx.r5.s64 = ctx.r11.s64 + -4040;
	// bl 0x8209d840
	ctx.lr = 0x82090A7C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,30
	ctx.r4.s64 = 30;
	// addi r5,r10,-4028
	ctx.r5.s64 = ctx.r10.s64 + -4028;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090A90;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,31
	ctx.r4.s64 = 31;
	// addi r5,r9,-4016
	ctx.r5.s64 = ctx.r9.s64 + -4016;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090AA4;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r5,r8,-4004
	ctx.r5.s64 = ctx.r8.s64 + -4004;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090AB8;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,33
	ctx.r4.s64 = 33;
	// addi r5,r7,-3996
	ctx.r5.s64 = ctx.r7.s64 + -3996;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090ACC;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,34
	ctx.r4.s64 = 34;
	// addi r5,r6,-3984
	ctx.r5.s64 = ctx.r6.s64 + -3984;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090AE0;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,35
	ctx.r4.s64 = 35;
	// addi r5,r5,-3968
	ctx.r5.s64 = ctx.r5.s64 + -3968;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090AF4;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r5,r3,-3956
	ctx.r5.s64 = ctx.r3.s64 + -3956;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090B08;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,37
	ctx.r4.s64 = 37;
	// addi r5,r11,-3948
	ctx.r5.s64 = ctx.r11.s64 + -3948;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090B1C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,38
	ctx.r4.s64 = 38;
	// addi r5,r10,-3936
	ctx.r5.s64 = ctx.r10.s64 + -3936;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090B30;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,39
	ctx.r4.s64 = 39;
	// addi r5,r9,-3920
	ctx.r5.s64 = ctx.r9.s64 + -3920;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090B44;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r5,r8,-3912
	ctx.r5.s64 = ctx.r8.s64 + -3912;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090B58;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,41
	ctx.r4.s64 = 41;
	// addi r5,r7,-3904
	ctx.r5.s64 = ctx.r7.s64 + -3904;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090B6C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,42
	ctx.r4.s64 = 42;
	// addi r5,r6,-3896
	ctx.r5.s64 = ctx.r6.s64 + -3896;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090B80;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,43
	ctx.r4.s64 = 43;
	// addi r5,r5,-3884
	ctx.r5.s64 = ctx.r5.s64 + -3884;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090B94;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,44
	ctx.r4.s64 = 44;
	// addi r5,r3,-3872
	ctx.r5.s64 = ctx.r3.s64 + -3872;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090BA8;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,45
	ctx.r4.s64 = 45;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// addi r5,r11,-3860
	ctx.r5.s64 = ctx.r11.s64 + -3860;
	// bl 0x8209d840
	ctx.lr = 0x82090BBC;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,46
	ctx.r4.s64 = 46;
	// addi r5,r10,-3848
	ctx.r5.s64 = ctx.r10.s64 + -3848;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090BD0;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,47
	ctx.r4.s64 = 47;
	// addi r5,r9,-3840
	ctx.r5.s64 = ctx.r9.s64 + -3840;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090BE4;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,48
	ctx.r4.s64 = 48;
	// addi r5,r8,-3824
	ctx.r5.s64 = ctx.r8.s64 + -3824;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090BF8;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,49
	ctx.r4.s64 = 49;
	// addi r5,r7,-3812
	ctx.r5.s64 = ctx.r7.s64 + -3812;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090C0C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,50
	ctx.r4.s64 = 50;
	// addi r5,r6,-3796
	ctx.r5.s64 = ctx.r6.s64 + -3796;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090C20;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,51
	ctx.r4.s64 = 51;
	// addi r5,r5,-3784
	ctx.r5.s64 = ctx.r5.s64 + -3784;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090C34;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,52
	ctx.r4.s64 = 52;
	// addi r5,r3,-3764
	ctx.r5.s64 = ctx.r3.s64 + -3764;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090C48;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,53
	ctx.r4.s64 = 53;
	// addi r5,r11,-3748
	ctx.r5.s64 = ctx.r11.s64 + -3748;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090C5C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,54
	ctx.r4.s64 = 54;
	// addi r5,r10,-3740
	ctx.r5.s64 = ctx.r10.s64 + -3740;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090C70;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,55
	ctx.r4.s64 = 55;
	// addi r5,r9,-3732
	ctx.r5.s64 = ctx.r9.s64 + -3732;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090C84;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,56
	ctx.r4.s64 = 56;
	// addi r5,r8,-3716
	ctx.r5.s64 = ctx.r8.s64 + -3716;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090C98;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,57
	ctx.r4.s64 = 57;
	// addi r5,r7,-3700
	ctx.r5.s64 = ctx.r7.s64 + -3700;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090CAC;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,58
	ctx.r4.s64 = 58;
	// addi r5,r6,-3684
	ctx.r5.s64 = ctx.r6.s64 + -3684;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090CC0;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,59
	ctx.r4.s64 = 59;
	// addi r5,r5,-3672
	ctx.r5.s64 = ctx.r5.s64 + -3672;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090CD4;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,60
	ctx.r4.s64 = 60;
	// addi r5,r3,-3660
	ctx.r5.s64 = ctx.r3.s64 + -3660;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090CE8;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r5,r11,-3644
	ctx.r5.s64 = ctx.r11.s64 + -3644;
	// li r4,61
	ctx.r4.s64 = 61;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090CFC;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,62
	ctx.r4.s64 = 62;
	// addi r5,r10,-3628
	ctx.r5.s64 = ctx.r10.s64 + -3628;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090D10;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,63
	ctx.r4.s64 = 63;
	// addi r5,r9,-3612
	ctx.r5.s64 = ctx.r9.s64 + -3612;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090D24;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r5,r8,-3596
	ctx.r5.s64 = ctx.r8.s64 + -3596;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090D38;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,65
	ctx.r4.s64 = 65;
	// addi r5,r7,-3584
	ctx.r5.s64 = ctx.r7.s64 + -3584;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090D4C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,66
	ctx.r4.s64 = 66;
	// addi r5,r6,-3572
	ctx.r5.s64 = ctx.r6.s64 + -3572;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090D60;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,67
	ctx.r4.s64 = 67;
	// addi r5,r5,-3556
	ctx.r5.s64 = ctx.r5.s64 + -3556;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090D74;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,68
	ctx.r4.s64 = 68;
	// addi r5,r3,-3544
	ctx.r5.s64 = ctx.r3.s64 + -3544;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090D88;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,69
	ctx.r4.s64 = 69;
	// addi r5,r11,-3536
	ctx.r5.s64 = ctx.r11.s64 + -3536;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090D9C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,70
	ctx.r4.s64 = 70;
	// addi r5,r10,-3524
	ctx.r5.s64 = ctx.r10.s64 + -3524;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090DB0;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,71
	ctx.r4.s64 = 71;
	// addi r5,r9,-3516
	ctx.r5.s64 = ctx.r9.s64 + -3516;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090DC4;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,72
	ctx.r4.s64 = 72;
	// addi r5,r8,-3504
	ctx.r5.s64 = ctx.r8.s64 + -3504;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090DD8;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,73
	ctx.r4.s64 = 73;
	// addi r5,r7,-3496
	ctx.r5.s64 = ctx.r7.s64 + -3496;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090DEC;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,74
	ctx.r4.s64 = 74;
	// addi r5,r6,-3480
	ctx.r5.s64 = ctx.r6.s64 + -3480;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090E00;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,75
	ctx.r4.s64 = 75;
	// addi r5,r5,-3472
	ctx.r5.s64 = ctx.r5.s64 + -3472;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090E14;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,76
	ctx.r4.s64 = 76;
	// addi r5,r3,-3464
	ctx.r5.s64 = ctx.r3.s64 + -3464;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090E28;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,77
	ctx.r4.s64 = 77;
	// addi r5,r11,-3456
	ctx.r5.s64 = ctx.r11.s64 + -3456;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090E3C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,78
	ctx.r4.s64 = 78;
	// addi r5,r10,-3452
	ctx.r5.s64 = ctx.r10.s64 + -3452;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090E50;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,79
	ctx.r4.s64 = 79;
	// addi r5,r9,-3448
	ctx.r5.s64 = ctx.r9.s64 + -3448;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090E64;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r5,r8,-3444
	ctx.r5.s64 = ctx.r8.s64 + -3444;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090E78;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,81
	ctx.r4.s64 = 81;
	// addi r5,r7,-3436
	ctx.r5.s64 = ctx.r7.s64 + -3436;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090E8C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,82
	ctx.r4.s64 = 82;
	// addi r5,r6,-3428
	ctx.r5.s64 = ctx.r6.s64 + -3428;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090EA0;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,83
	ctx.r4.s64 = 83;
	// addi r5,r5,-3412
	ctx.r5.s64 = ctx.r5.s64 + -3412;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090EB4;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,84
	ctx.r4.s64 = 84;
	// addi r5,r3,-3396
	ctx.r5.s64 = ctx.r3.s64 + -3396;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090EC8;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,85
	ctx.r4.s64 = 85;
	// addi r5,r11,-3388
	ctx.r5.s64 = ctx.r11.s64 + -3388;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090EDC;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,86
	ctx.r4.s64 = 86;
	// addi r5,r10,-3376
	ctx.r5.s64 = ctx.r10.s64 + -3376;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090EF0;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,87
	ctx.r4.s64 = 87;
	// addi r5,r9,-3368
	ctx.r5.s64 = ctx.r9.s64 + -3368;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090F04;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r5,r8,-3360
	ctx.r5.s64 = ctx.r8.s64 + -3360;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090F18;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,89
	ctx.r4.s64 = 89;
	// addi r5,r7,-3348
	ctx.r5.s64 = ctx.r7.s64 + -3348;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090F2C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,90
	ctx.r4.s64 = 90;
	// addi r5,r6,-3340
	ctx.r5.s64 = ctx.r6.s64 + -3340;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090F40;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,91
	ctx.r4.s64 = 91;
	// addi r5,r5,-3324
	ctx.r5.s64 = ctx.r5.s64 + -3324;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090F54;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,92
	ctx.r4.s64 = 92;
	// addi r5,r3,-3316
	ctx.r5.s64 = ctx.r3.s64 + -3316;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090F68;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,93
	ctx.r4.s64 = 93;
	// addi r5,r11,-3304
	ctx.r5.s64 = ctx.r11.s64 + -3304;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090F7C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,94
	ctx.r4.s64 = 94;
	// addi r5,r10,-3296
	ctx.r5.s64 = ctx.r10.s64 + -3296;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090F90;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,95
	ctx.r4.s64 = 95;
	// addi r5,r9,-3280
	ctx.r5.s64 = ctx.r9.s64 + -3280;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090FA4;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,96
	ctx.r4.s64 = 96;
	// addi r5,r8,-3268
	ctx.r5.s64 = ctx.r8.s64 + -3268;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090FB8;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,97
	ctx.r4.s64 = 97;
	// addi r5,r7,-3252
	ctx.r5.s64 = ctx.r7.s64 + -3252;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090FCC;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,98
	ctx.r4.s64 = 98;
	// addi r5,r6,-3240
	ctx.r5.s64 = ctx.r6.s64 + -3240;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090FE0;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,99
	ctx.r4.s64 = 99;
	// addi r5,r5,-3232
	ctx.r5.s64 = ctx.r5.s64 + -3232;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82090FF4;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,100
	ctx.r4.s64 = 100;
	// addi r5,r3,-3224
	ctx.r5.s64 = ctx.r3.s64 + -3224;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091008;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,101
	ctx.r4.s64 = 101;
	// addi r5,r11,-3216
	ctx.r5.s64 = ctx.r11.s64 + -3216;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x8209101C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,102
	ctx.r4.s64 = 102;
	// addi r5,r10,-3208
	ctx.r5.s64 = ctx.r10.s64 + -3208;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091030;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,103
	ctx.r4.s64 = 103;
	// addi r5,r9,-3200
	ctx.r5.s64 = ctx.r9.s64 + -3200;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091044;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,104
	ctx.r4.s64 = 104;
	// addi r5,r8,-3192
	ctx.r5.s64 = ctx.r8.s64 + -3192;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091058;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,105
	ctx.r4.s64 = 105;
	// addi r5,r7,-3184
	ctx.r5.s64 = ctx.r7.s64 + -3184;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x8209106C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,106
	ctx.r4.s64 = 106;
	// addi r5,r6,-3176
	ctx.r5.s64 = ctx.r6.s64 + -3176;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091080;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,107
	ctx.r4.s64 = 107;
	// addi r5,r5,-3160
	ctx.r5.s64 = ctx.r5.s64 + -3160;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091094;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,108
	ctx.r4.s64 = 108;
	// addi r5,r3,-3156
	ctx.r5.s64 = ctx.r3.s64 + -3156;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820910A8;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,109
	ctx.r4.s64 = 109;
	// addi r5,r11,-3148
	ctx.r5.s64 = ctx.r11.s64 + -3148;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820910BC;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// li r4,110
	ctx.r4.s64 = 110;
	// addi r5,r10,-3140
	ctx.r5.s64 = ctx.r10.s64 + -3140;
	// bl 0x8209d840
	ctx.lr = 0x820910D0;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,111
	ctx.r4.s64 = 111;
	// addi r5,r9,-3132
	ctx.r5.s64 = ctx.r9.s64 + -3132;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820910E4;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,112
	ctx.r4.s64 = 112;
	// addi r5,r8,-3128
	ctx.r5.s64 = ctx.r8.s64 + -3128;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820910F8;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,113
	ctx.r4.s64 = 113;
	// addi r5,r7,-3124
	ctx.r5.s64 = ctx.r7.s64 + -3124;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x8209110C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,114
	ctx.r4.s64 = 114;
	// addi r5,r6,-3120
	ctx.r5.s64 = ctx.r6.s64 + -3120;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091120;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,115
	ctx.r4.s64 = 115;
	// addi r5,r5,-3116
	ctx.r5.s64 = ctx.r5.s64 + -3116;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091134;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,116
	ctx.r4.s64 = 116;
	// addi r5,r3,-3112
	ctx.r5.s64 = ctx.r3.s64 + -3112;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091148;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,117
	ctx.r4.s64 = 117;
	// addi r5,r11,-3108
	ctx.r5.s64 = ctx.r11.s64 + -3108;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x8209115C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,118
	ctx.r4.s64 = 118;
	// addi r5,r10,-3104
	ctx.r5.s64 = ctx.r10.s64 + -3104;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091170;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,119
	ctx.r4.s64 = 119;
	// addi r5,r9,-3100
	ctx.r5.s64 = ctx.r9.s64 + -3100;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091184;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,120
	ctx.r4.s64 = 120;
	// addi r5,r8,-3096
	ctx.r5.s64 = ctx.r8.s64 + -3096;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091198;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,121
	ctx.r4.s64 = 121;
	// addi r5,r7,-3088
	ctx.r5.s64 = ctx.r7.s64 + -3088;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820911AC;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,122
	ctx.r4.s64 = 122;
	// addi r5,r6,-3080
	ctx.r5.s64 = ctx.r6.s64 + -3080;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820911C0;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,123
	ctx.r4.s64 = 123;
	// addi r5,r5,-3076
	ctx.r5.s64 = ctx.r5.s64 + -3076;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820911D4;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,124
	ctx.r4.s64 = 124;
	// addi r5,r3,-3068
	ctx.r5.s64 = ctx.r3.s64 + -3068;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820911E8;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,125
	ctx.r4.s64 = 125;
	// addi r5,r11,-3060
	ctx.r5.s64 = ctx.r11.s64 + -3060;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x820911FC;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,126
	ctx.r4.s64 = 126;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// addi r5,r10,-3052
	ctx.r5.s64 = ctx.r10.s64 + -3052;
	// bl 0x8209d840
	ctx.lr = 0x82091210;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,127
	ctx.r4.s64 = 127;
	// addi r5,r9,-3044
	ctx.r5.s64 = ctx.r9.s64 + -3044;
	// lwz r3,10316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// bl 0x8209d840
	ctx.lr = 0x82091224;
	sub_8209D840(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r4,10316(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 10316);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8209123C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
