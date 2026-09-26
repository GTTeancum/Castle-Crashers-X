DEFINE_REX_FUNC(sub_820735B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129914
	ctx.lr = 0x820735B8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,1
	ctx.r29.s64 = 1;
	// addi r28,r31,220
	ctx.r28.s64 = ctx.r31.s64 + 220;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r30,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// stw r29,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r29.u32);
	// bl 0x82073d80
	ctx.lr = 0x820735E0;
	sub_82073D80(ctx, base);
	// stb r30,236(r31)
	REX_STORE_U8(ctx.r31.u32 + 236, ctx.r30.u8);
	// stb r30,237(r31)
	REX_STORE_U8(ctx.r31.u32 + 237, ctx.r30.u8);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x820735F4;
	sub_82072AB8(ctx, base);
	// stb r29,236(r31)
	REX_STORE_U8(ctx.r31.u32 + 236, ctx.r29.u8);
	// stb r30,237(r31)
	REX_STORE_U8(ctx.r31.u32 + 237, ctx.r30.u8);
	// addi r28,r31,256
	ctx.r28.s64 = ctx.r31.s64 + 256;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073608;
	sub_82073D80(ctx, base);
	// stb r30,272(r31)
	REX_STORE_U8(ctx.r31.u32 + 272, ctx.r30.u8);
	// stb r30,273(r31)
	REX_STORE_U8(ctx.r31.u32 + 273, ctx.r30.u8);
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x8207361C;
	sub_82072AB8(ctx, base);
	// stb r29,272(r31)
	REX_STORE_U8(ctx.r31.u32 + 272, ctx.r29.u8);
	// stb r30,273(r31)
	REX_STORE_U8(ctx.r31.u32 + 273, ctx.r30.u8);
	// addi r28,r31,76
	ctx.r28.s64 = ctx.r31.s64 + 76;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073630;
	sub_82073D80(ctx, base);
	// stb r30,92(r31)
	REX_STORE_U8(ctx.r31.u32 + 92, ctx.r30.u8);
	// stb r30,93(r31)
	REX_STORE_U8(ctx.r31.u32 + 93, ctx.r30.u8);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073644;
	sub_82072AB8(ctx, base);
	// stb r30,92(r31)
	REX_STORE_U8(ctx.r31.u32 + 92, ctx.r30.u8);
	// addi r28,r31,112
	ctx.r28.s64 = ctx.r31.s64 + 112;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073654;
	sub_82073D80(ctx, base);
	// stb r30,128(r31)
	REX_STORE_U8(ctx.r31.u32 + 128, ctx.r30.u8);
	// stb r30,129(r31)
	REX_STORE_U8(ctx.r31.u32 + 129, ctx.r30.u8);
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073668;
	sub_82072AB8(ctx, base);
	// stb r30,128(r31)
	REX_STORE_U8(ctx.r31.u32 + 128, ctx.r30.u8);
	// addi r28,r31,148
	ctx.r28.s64 = ctx.r31.s64 + 148;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073678;
	sub_82073D80(ctx, base);
	// stb r30,164(r31)
	REX_STORE_U8(ctx.r31.u32 + 164, ctx.r30.u8);
	// stb r30,165(r31)
	REX_STORE_U8(ctx.r31.u32 + 165, ctx.r30.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x8207368C;
	sub_82072AB8(ctx, base);
	// stb r30,164(r31)
	REX_STORE_U8(ctx.r31.u32 + 164, ctx.r30.u8);
	// addi r28,r31,184
	ctx.r28.s64 = ctx.r31.s64 + 184;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x8207369C;
	sub_82073D80(ctx, base);
	// stb r30,200(r31)
	REX_STORE_U8(ctx.r31.u32 + 200, ctx.r30.u8);
	// stb r30,201(r31)
	REX_STORE_U8(ctx.r31.u32 + 201, ctx.r30.u8);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x820736B0;
	sub_82072AB8(ctx, base);
	// stb r30,200(r31)
	REX_STORE_U8(ctx.r31.u32 + 200, ctx.r30.u8);
	// addi r28,r31,292
	ctx.r28.s64 = ctx.r31.s64 + 292;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x820736C0;
	sub_82073D80(ctx, base);
	// stb r30,308(r31)
	REX_STORE_U8(ctx.r31.u32 + 308, ctx.r30.u8);
	// stb r30,309(r31)
	REX_STORE_U8(ctx.r31.u32 + 309, ctx.r30.u8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82072ab8
	ctx.lr = 0x820736D4;
	sub_82072AB8(ctx, base);
	// lis r4,-32767
	ctx.r4.s64 = -2147418112;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x820736E0;
	sub_82072AB8(ctx, base);
	// stb r29,308(r31)
	REX_STORE_U8(ctx.r31.u32 + 308, ctx.r29.u8);
	// stb r30,309(r31)
	REX_STORE_U8(ctx.r31.u32 + 309, ctx.r30.u8);
	// addi r28,r31,328
	ctx.r28.s64 = ctx.r31.s64 + 328;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x820736F4;
	sub_82073D80(ctx, base);
	// stb r30,344(r31)
	REX_STORE_U8(ctx.r31.u32 + 344, ctx.r30.u8);
	// stb r30,345(r31)
	REX_STORE_U8(ctx.r31.u32 + 345, ctx.r30.u8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82072ab8
	ctx.lr = 0x82073708;
	sub_82072AB8(ctx, base);
	// lis r4,-32766
	ctx.r4.s64 = -2147352576;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073714;
	sub_82072AB8(ctx, base);
	// stb r29,344(r31)
	REX_STORE_U8(ctx.r31.u32 + 344, ctx.r29.u8);
	// stb r30,345(r31)
	REX_STORE_U8(ctx.r31.u32 + 345, ctx.r30.u8);
	// addi r28,r31,364
	ctx.r28.s64 = ctx.r31.s64 + 364;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073728;
	sub_82073D80(ctx, base);
	// stb r30,380(r31)
	REX_STORE_U8(ctx.r31.u32 + 380, ctx.r30.u8);
	// stb r30,381(r31)
	REX_STORE_U8(ctx.r31.u32 + 381, ctx.r30.u8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x82072ab8
	ctx.lr = 0x8207373C;
	sub_82072AB8(ctx, base);
	// lis r4,-32764
	ctx.r4.s64 = -2147221504;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073748;
	sub_82072AB8(ctx, base);
	// stb r29,380(r31)
	REX_STORE_U8(ctx.r31.u32 + 380, ctx.r29.u8);
	// stb r30,381(r31)
	REX_STORE_U8(ctx.r31.u32 + 381, ctx.r30.u8);
	// addi r28,r31,400
	ctx.r28.s64 = ctx.r31.s64 + 400;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x8207375C;
	sub_82073D80(ctx, base);
	// stb r30,416(r31)
	REX_STORE_U8(ctx.r31.u32 + 416, ctx.r30.u8);
	// stb r30,417(r31)
	REX_STORE_U8(ctx.r31.u32 + 417, ctx.r30.u8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x82072ab8
	ctx.lr = 0x82073770;
	sub_82072AB8(ctx, base);
	// lis r4,-32760
	ctx.r4.s64 = -2146959360;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x8207377C;
	sub_82072AB8(ctx, base);
	// stb r29,416(r31)
	REX_STORE_U8(ctx.r31.u32 + 416, ctx.r29.u8);
	// stb r30,417(r31)
	REX_STORE_U8(ctx.r31.u32 + 417, ctx.r30.u8);
	// addi r28,r31,436
	ctx.r28.s64 = ctx.r31.s64 + 436;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073790;
	sub_82073D80(ctx, base);
	// stb r30,452(r31)
	REX_STORE_U8(ctx.r31.u32 + 452, ctx.r30.u8);
	// stb r30,453(r31)
	REX_STORE_U8(ctx.r31.u32 + 453, ctx.r30.u8);
	// li r4,8192
	ctx.r4.s64 = 8192;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x820737A4;
	sub_82072AB8(ctx, base);
	// stb r29,452(r31)
	REX_STORE_U8(ctx.r31.u32 + 452, ctx.r29.u8);
	// stb r30,453(r31)
	REX_STORE_U8(ctx.r31.u32 + 453, ctx.r30.u8);
	// addi r28,r31,472
	ctx.r28.s64 = ctx.r31.s64 + 472;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x820737B8;
	sub_82073D80(ctx, base);
	// stb r30,488(r31)
	REX_STORE_U8(ctx.r31.u32 + 488, ctx.r30.u8);
	// stb r30,489(r31)
	REX_STORE_U8(ctx.r31.u32 + 489, ctx.r30.u8);
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// ori r27,r11,32768
	ctx.r27.u64 = ctx.r11.u64 | 32768;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82072ab8
	ctx.lr = 0x820737D4;
	sub_82072AB8(ctx, base);
	// stb r29,488(r31)
	REX_STORE_U8(ctx.r31.u32 + 488, ctx.r29.u8);
	// stb r30,489(r31)
	REX_STORE_U8(ctx.r31.u32 + 489, ctx.r30.u8);
	// addi r28,r31,508
	ctx.r28.s64 = ctx.r31.s64 + 508;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x820737E8;
	sub_82073D80(ctx, base);
	// stb r30,524(r31)
	REX_STORE_U8(ctx.r31.u32 + 524, ctx.r30.u8);
	// stb r30,525(r31)
	REX_STORE_U8(ctx.r31.u32 + 525, ctx.r30.u8);
	// li r4,4096
	ctx.r4.s64 = 4096;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x820737FC;
	sub_82072AB8(ctx, base);
	// stb r29,524(r31)
	REX_STORE_U8(ctx.r31.u32 + 524, ctx.r29.u8);
	// stb r30,525(r31)
	REX_STORE_U8(ctx.r31.u32 + 525, ctx.r30.u8);
	// addi r28,r31,544
	ctx.r28.s64 = ctx.r31.s64 + 544;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073810;
	sub_82073D80(ctx, base);
	// stb r30,560(r31)
	REX_STORE_U8(ctx.r31.u32 + 560, ctx.r30.u8);
	// stb r30,561(r31)
	REX_STORE_U8(ctx.r31.u32 + 561, ctx.r30.u8);
	// li r4,16384
	ctx.r4.s64 = 16384;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073824;
	sub_82072AB8(ctx, base);
	// stb r29,560(r31)
	REX_STORE_U8(ctx.r31.u32 + 560, ctx.r29.u8);
	// stb r30,561(r31)
	REX_STORE_U8(ctx.r31.u32 + 561, ctx.r30.u8);
	// addi r29,r31,652
	ctx.r29.s64 = ctx.r31.s64 + 652;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073838;
	sub_82073D80(ctx, base);
	// stb r30,668(r31)
	REX_STORE_U8(ctx.r31.u32 + 668, ctx.r30.u8);
	// stb r30,669(r31)
	REX_STORE_U8(ctx.r31.u32 + 669, ctx.r30.u8);
	// li r4,256
	ctx.r4.s64 = 256;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x8207384C;
	sub_82072AB8(ctx, base);
	// stb r30,668(r31)
	REX_STORE_U8(ctx.r31.u32 + 668, ctx.r30.u8);
	// addi r29,r31,688
	ctx.r29.s64 = ctx.r31.s64 + 688;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x8207385C;
	sub_82073D80(ctx, base);
	// stb r30,704(r31)
	REX_STORE_U8(ctx.r31.u32 + 704, ctx.r30.u8);
	// stb r30,705(r31)
	REX_STORE_U8(ctx.r31.u32 + 705, ctx.r30.u8);
	// li r4,512
	ctx.r4.s64 = 512;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073870;
	sub_82072AB8(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stb r30,704(r31)
	REX_STORE_U8(ctx.r31.u32 + 704, ctx.r30.u8);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82073a1c
	if (ctx.cr6.lt) goto loc_82073A1C;
	// beq cr6,0x82073954
	if (ctx.cr6.eq) goto loc_82073954;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x82073af4
	if (!ctx.cr6.lt) goto loc_82073AF4;
	// addi r29,r31,580
	ctx.r29.s64 = ctx.r31.s64 + 580;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073898;
	sub_82073D80(ctx, base);
	// stb r30,596(r31)
	REX_STORE_U8(ctx.r31.u32 + 596, ctx.r30.u8);
	// stb r30,597(r31)
	REX_STORE_U8(ctx.r31.u32 + 597, ctx.r30.u8);
	// li r4,16384
	ctx.r4.s64 = 16384;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x820738AC;
	sub_82072AB8(ctx, base);
	// stb r30,596(r31)
	REX_STORE_U8(ctx.r31.u32 + 596, ctx.r30.u8);
	// addi r29,r31,616
	ctx.r29.s64 = ctx.r31.s64 + 616;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x820738BC;
	sub_82073D80(ctx, base);
	// stb r30,632(r31)
	REX_STORE_U8(ctx.r31.u32 + 632, ctx.r30.u8);
	// stb r30,633(r31)
	REX_STORE_U8(ctx.r31.u32 + 633, ctx.r30.u8);
	// li r4,4096
	ctx.r4.s64 = 4096;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x820738D0;
	sub_82072AB8(ctx, base);
	// stb r30,632(r31)
	REX_STORE_U8(ctx.r31.u32 + 632, ctx.r30.u8);
	// addi r29,r31,760
	ctx.r29.s64 = ctx.r31.s64 + 760;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x820738E0;
	sub_82073D80(ctx, base);
	// stb r30,776(r31)
	REX_STORE_U8(ctx.r31.u32 + 776, ctx.r30.u8);
	// stb r30,777(r31)
	REX_STORE_U8(ctx.r31.u32 + 777, ctx.r30.u8);
	// li r4,8192
	ctx.r4.s64 = 8192;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x820738F4;
	sub_82072AB8(ctx, base);
	// stb r30,776(r31)
	REX_STORE_U8(ctx.r31.u32 + 776, ctx.r30.u8);
	// addi r29,r31,724
	ctx.r29.s64 = ctx.r31.s64 + 724;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073904;
	sub_82073D80(ctx, base);
	// stb r30,740(r31)
	REX_STORE_U8(ctx.r31.u32 + 740, ctx.r30.u8);
	// stb r30,741(r31)
	REX_STORE_U8(ctx.r31.u32 + 741, ctx.r30.u8);
	// li r4,1024
	ctx.r4.s64 = 1024;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073918;
	sub_82072AB8(ctx, base);
	// stb r30,740(r31)
	REX_STORE_U8(ctx.r31.u32 + 740, ctx.r30.u8);
	// addi r29,r31,796
	ctx.r29.s64 = ctx.r31.s64 + 796;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073928;
	sub_82073D80(ctx, base);
	// stb r30,812(r31)
	REX_STORE_U8(ctx.r31.u32 + 812, ctx.r30.u8);
	// stb r30,813(r31)
	REX_STORE_U8(ctx.r31.u32 + 813, ctx.r30.u8);
	// li r4,2048
	ctx.r4.s64 = 2048;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x8207393C;
	sub_82072AB8(ctx, base);
	// stb r30,812(r31)
	REX_STORE_U8(ctx.r31.u32 + 812, ctx.r30.u8);
	// addi r29,r31,832
	ctx.r29.s64 = ctx.r31.s64 + 832;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x8207394C;
	sub_82073D80(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// b 0x82073ae0
	goto loc_82073AE0;
loc_82073954:
	// addi r29,r31,580
	ctx.r29.s64 = ctx.r31.s64 + 580;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073960;
	sub_82073D80(ctx, base);
	// stb r30,596(r31)
	REX_STORE_U8(ctx.r31.u32 + 596, ctx.r30.u8);
	// stb r30,597(r31)
	REX_STORE_U8(ctx.r31.u32 + 597, ctx.r30.u8);
	// li r4,1024
	ctx.r4.s64 = 1024;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073974;
	sub_82072AB8(ctx, base);
	// stb r30,596(r31)
	REX_STORE_U8(ctx.r31.u32 + 596, ctx.r30.u8);
	// addi r29,r31,616
	ctx.r29.s64 = ctx.r31.s64 + 616;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073984;
	sub_82073D80(ctx, base);
	// stb r30,632(r31)
	REX_STORE_U8(ctx.r31.u32 + 632, ctx.r30.u8);
	// stb r30,633(r31)
	REX_STORE_U8(ctx.r31.u32 + 633, ctx.r30.u8);
	// li r4,2048
	ctx.r4.s64 = 2048;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073998;
	sub_82072AB8(ctx, base);
	// stb r30,632(r31)
	REX_STORE_U8(ctx.r31.u32 + 632, ctx.r30.u8);
	// addi r29,r31,760
	ctx.r29.s64 = ctx.r31.s64 + 760;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x820739A8;
	sub_82073D80(ctx, base);
	// stb r30,776(r31)
	REX_STORE_U8(ctx.r31.u32 + 776, ctx.r30.u8);
	// stb r30,777(r31)
	REX_STORE_U8(ctx.r31.u32 + 777, ctx.r30.u8);
	// li r4,16384
	ctx.r4.s64 = 16384;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x820739BC;
	sub_82072AB8(ctx, base);
	// stb r30,776(r31)
	REX_STORE_U8(ctx.r31.u32 + 776, ctx.r30.u8);
	// addi r29,r31,724
	ctx.r29.s64 = ctx.r31.s64 + 724;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x820739CC;
	sub_82073D80(ctx, base);
	// stb r30,740(r31)
	REX_STORE_U8(ctx.r31.u32 + 740, ctx.r30.u8);
	// stb r30,741(r31)
	REX_STORE_U8(ctx.r31.u32 + 741, ctx.r30.u8);
	// li r4,8192
	ctx.r4.s64 = 8192;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x820739E0;
	sub_82072AB8(ctx, base);
	// stb r30,740(r31)
	REX_STORE_U8(ctx.r31.u32 + 740, ctx.r30.u8);
	// addi r29,r31,796
	ctx.r29.s64 = ctx.r31.s64 + 796;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x820739F0;
	sub_82073D80(ctx, base);
	// stb r30,812(r31)
	REX_STORE_U8(ctx.r31.u32 + 812, ctx.r30.u8);
	// stb r30,813(r31)
	REX_STORE_U8(ctx.r31.u32 + 813, ctx.r30.u8);
	// li r4,4096
	ctx.r4.s64 = 4096;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073A04;
	sub_82072AB8(ctx, base);
	// stb r30,812(r31)
	REX_STORE_U8(ctx.r31.u32 + 812, ctx.r30.u8);
	// addi r29,r31,832
	ctx.r29.s64 = ctx.r31.s64 + 832;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073A14;
	sub_82073D80(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// b 0x82073ae0
	goto loc_82073AE0;
loc_82073A1C:
	// addi r29,r31,580
	ctx.r29.s64 = ctx.r31.s64 + 580;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073A28;
	sub_82073D80(ctx, base);
	// stb r30,596(r31)
	REX_STORE_U8(ctx.r31.u32 + 596, ctx.r30.u8);
	// stb r30,597(r31)
	REX_STORE_U8(ctx.r31.u32 + 597, ctx.r30.u8);
	// li r4,1024
	ctx.r4.s64 = 1024;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073A3C;
	sub_82072AB8(ctx, base);
	// stb r30,596(r31)
	REX_STORE_U8(ctx.r31.u32 + 596, ctx.r30.u8);
	// addi r29,r31,616
	ctx.r29.s64 = ctx.r31.s64 + 616;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073A4C;
	sub_82073D80(ctx, base);
	// stb r30,632(r31)
	REX_STORE_U8(ctx.r31.u32 + 632, ctx.r30.u8);
	// stb r30,633(r31)
	REX_STORE_U8(ctx.r31.u32 + 633, ctx.r30.u8);
	// li r4,2048
	ctx.r4.s64 = 2048;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073A60;
	sub_82072AB8(ctx, base);
	// stb r30,632(r31)
	REX_STORE_U8(ctx.r31.u32 + 632, ctx.r30.u8);
	// addi r29,r31,760
	ctx.r29.s64 = ctx.r31.s64 + 760;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073A70;
	sub_82073D80(ctx, base);
	// stb r30,776(r31)
	REX_STORE_U8(ctx.r31.u32 + 776, ctx.r30.u8);
	// stb r30,777(r31)
	REX_STORE_U8(ctx.r31.u32 + 777, ctx.r30.u8);
	// li r4,8192
	ctx.r4.s64 = 8192;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073A84;
	sub_82072AB8(ctx, base);
	// stb r30,776(r31)
	REX_STORE_U8(ctx.r31.u32 + 776, ctx.r30.u8);
	// addi r29,r31,724
	ctx.r29.s64 = ctx.r31.s64 + 724;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073A94;
	sub_82073D80(ctx, base);
	// stb r30,740(r31)
	REX_STORE_U8(ctx.r31.u32 + 740, ctx.r30.u8);
	// stb r30,741(r31)
	REX_STORE_U8(ctx.r31.u32 + 741, ctx.r30.u8);
	// li r4,16384
	ctx.r4.s64 = 16384;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073AA8;
	sub_82072AB8(ctx, base);
	// stb r30,740(r31)
	REX_STORE_U8(ctx.r31.u32 + 740, ctx.r30.u8);
	// addi r29,r31,796
	ctx.r29.s64 = ctx.r31.s64 + 796;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073AB8;
	sub_82073D80(ctx, base);
	// stb r30,812(r31)
	REX_STORE_U8(ctx.r31.u32 + 812, ctx.r30.u8);
	// stb r30,813(r31)
	REX_STORE_U8(ctx.r31.u32 + 813, ctx.r30.u8);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82072ab8
	ctx.lr = 0x82073ACC;
	sub_82072AB8(ctx, base);
	// stb r30,812(r31)
	REX_STORE_U8(ctx.r31.u32 + 812, ctx.r30.u8);
	// addi r29,r31,832
	ctx.r29.s64 = ctx.r31.s64 + 832;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82073d80
	ctx.lr = 0x82073ADC;
	sub_82073D80(ctx, base);
	// li r4,4096
	ctx.r4.s64 = 4096;
loc_82073AE0:
	// stb r30,848(r31)
	REX_STORE_U8(ctx.r31.u32 + 848, ctx.r30.u8);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stb r30,849(r31)
	REX_STORE_U8(ctx.r31.u32 + 849, ctx.r30.u8);
	// bl 0x82072ab8
	ctx.lr = 0x82073AF0;
	sub_82072AB8(ctx, base);
	// stb r30,848(r31)
	REX_STORE_U8(ctx.r31.u32 + 848, ctx.r30.u8);
loc_82073AF4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82129964
	__restgprlr_27(ctx, base);
	return;
}
