DEFINE_REX_FUNC(sub_820A8190) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129918
	ctx.lr = 0x820A8198;
	__savegprlr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a85e0
	if (ctx.cr6.eq) goto loc_820A85E0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x82129a70
	ctx.lr = 0x820A81BC;
	sub_82129A70(ctx, base);
	// lwz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x820a822c
	if (ctx.cr6.gt) goto loc_820A822C;
	// lis r12,-32245
	ctx.r12.s64 = -2113208320;
	// addi r12,r12,-32288
	ctx.r12.s64 = ctx.r12.s64 + -32288;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_820A81F8;
	case 1:
		goto loc_820A8200;
	case 2:
		goto loc_820A8208;
	case 3:
		goto loc_820A8210;
	case 4:
		goto loc_820A8218;
	case 5:
		goto loc_820A8220;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820A81F8:
	// li r4,7
	ctx.r4.s64 = 7;
	// b 0x820a8224
	goto loc_820A8224;
loc_820A8200:
	// li r4,8
	ctx.r4.s64 = 8;
	// b 0x820a8224
	goto loc_820A8224;
loc_820A8208:
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x820a8224
	goto loc_820A8224;
loc_820A8210:
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x820a8224
	goto loc_820A8224;
loc_820A8218:
	// li r4,4
	ctx.r4.s64 = 4;
	// b 0x820a8224
	goto loc_820A8224;
loc_820A8220:
	// li r4,15
	ctx.r4.s64 = 15;
loc_820A8224:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bc368
	ctx.lr = 0x820A822C;
	sub_820BC368(ctx, base);
loc_820A822C:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r30,1
	ctx.r30.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820a8260
	if (ctx.cr6.lt) goto loc_820A8260;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x820a827c
	if (!ctx.cr6.lt) goto loc_820A827C;
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a827c
	if (ctx.cr6.eq) goto loc_820A827C;
	// stb r30,30212(r31)
	REX_STORE_U8(ctx.r31.u32 + 30212, ctx.r30.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x820a8274
	goto loc_820A8274;
loc_820A8260:
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a827c
	if (ctx.cr6.eq) goto loc_820A827C;
	// stb r29,30212(r31)
	REX_STORE_U8(ctx.r31.u32 + 30212, ctx.r29.u8);
	// li r4,0
	ctx.r4.s64 = 0;
loc_820A8274:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb740
	ctx.lr = 0x820A827C;
	sub_820BB740(ctx, base);
loc_820A827C:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// bgt cr6,0x820a84a0
	if (ctx.cr6.gt) goto loc_820A84A0;
	// lis r12,-32245
	ctx.r12.s64 = -2113208320;
	// addi r12,r12,-32096
	ctx.r12.s64 = ctx.r12.s64 + -32096;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_820A82D4;
	case 1:
		goto loc_820A82EC;
	case 2:
		goto loc_820A8330;
	case 3:
		goto loc_820A8374;
	case 4:
		goto loc_820A8484;
	case 5:
		goto loc_820A8484;
	case 6:
		goto loc_820A83B8;
	case 7:
		goto loc_820A83FC;
	case 8:
		goto loc_820A8440;
	case 9:
		goto loc_820A8484;
	case 10:
		goto loc_820A8484;
	case 11:
		goto loc_820A8484;
	case 12:
		goto loc_820A8484;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820A82D4:
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a84a0
	if (ctx.cr6.eq) goto loc_820A84A0;
	// stb r29,30212(r31)
	REX_STORE_U8(ctx.r31.u32 + 30212, ctx.r29.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x820a8498
	goto loc_820A8498;
loc_820A82EC:
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a8308
	if (ctx.cr6.eq) goto loc_820A8308;
	// stb r30,30212(r31)
	REX_STORE_U8(ctx.r31.u32 + 30212, ctx.r30.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb740
	ctx.lr = 0x820A8308;
	sub_820BB740(ctx, base);
loc_820A8308:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb860
	ctx.lr = 0x820A8314;
	sub_820BB860(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb8f0
	ctx.lr = 0x820A8320;
	sub_820BB8F0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb7d0
	ctx.lr = 0x820A832C;
	sub_820BB7D0(ctx, base);
	// b 0x820a84a0
	goto loc_820A84A0;
loc_820A8330:
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a834c
	if (ctx.cr6.eq) goto loc_820A834C;
	// stb r30,30212(r31)
	REX_STORE_U8(ctx.r31.u32 + 30212, ctx.r30.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb740
	ctx.lr = 0x820A834C;
	sub_820BB740(ctx, base);
loc_820A834C:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb860
	ctx.lr = 0x820A8358;
	sub_820BB860(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb8f0
	ctx.lr = 0x820A8364;
	sub_820BB8F0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb7d0
	ctx.lr = 0x820A8370;
	sub_820BB7D0(ctx, base);
	// b 0x820a84a0
	goto loc_820A84A0;
loc_820A8374:
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a8390
	if (ctx.cr6.eq) goto loc_820A8390;
	// stb r30,30212(r31)
	REX_STORE_U8(ctx.r31.u32 + 30212, ctx.r30.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb740
	ctx.lr = 0x820A8390;
	sub_820BB740(ctx, base);
loc_820A8390:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb860
	ctx.lr = 0x820A839C;
	sub_820BB860(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb8f0
	ctx.lr = 0x820A83A8;
	sub_820BB8F0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb7d0
	ctx.lr = 0x820A83B4;
	sub_820BB7D0(ctx, base);
	// b 0x820a84a0
	goto loc_820A84A0;
loc_820A83B8:
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a83d4
	if (ctx.cr6.eq) goto loc_820A83D4;
	// stb r30,30212(r31)
	REX_STORE_U8(ctx.r31.u32 + 30212, ctx.r30.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb740
	ctx.lr = 0x820A83D4;
	sub_820BB740(ctx, base);
loc_820A83D4:
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb860
	ctx.lr = 0x820A83E0;
	sub_820BB860(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb8f0
	ctx.lr = 0x820A83EC;
	sub_820BB8F0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb7d0
	ctx.lr = 0x820A83F8;
	sub_820BB7D0(ctx, base);
	// b 0x820a84a0
	goto loc_820A84A0;
loc_820A83FC:
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a8418
	if (ctx.cr6.eq) goto loc_820A8418;
	// stb r30,30212(r31)
	REX_STORE_U8(ctx.r31.u32 + 30212, ctx.r30.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb740
	ctx.lr = 0x820A8418;
	sub_820BB740(ctx, base);
loc_820A8418:
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb860
	ctx.lr = 0x820A8424;
	sub_820BB860(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb8f0
	ctx.lr = 0x820A8430;
	sub_820BB8F0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb7d0
	ctx.lr = 0x820A843C;
	sub_820BB7D0(ctx, base);
	// b 0x820a84a0
	goto loc_820A84A0;
loc_820A8440:
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a845c
	if (ctx.cr6.eq) goto loc_820A845C;
	// stb r30,30212(r31)
	REX_STORE_U8(ctx.r31.u32 + 30212, ctx.r30.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb740
	ctx.lr = 0x820A845C;
	sub_820BB740(ctx, base);
loc_820A845C:
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb860
	ctx.lr = 0x820A8468;
	sub_820BB860(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb8f0
	ctx.lr = 0x820A8474;
	sub_820BB8F0(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb7d0
	ctx.lr = 0x820A8480;
	sub_820BB7D0(ctx, base);
	// b 0x820a84a0
	goto loc_820A84A0;
loc_820A8484:
	// lbz r11,28715(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28715);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a84a0
	if (ctx.cr6.eq) goto loc_820A84A0;
	// stb r30,30212(r31)
	REX_STORE_U8(ctx.r31.u32 + 30212, ctx.r30.u8);
	// li r4,1
	ctx.r4.s64 = 1;
loc_820A8498:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb740
	ctx.lr = 0x820A84A0;
	sub_820BB740(ctx, base);
loc_820A84A0:
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x820a84cc
	if (ctx.cr6.eq) goto loc_820A84CC;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x820a84c4
	if (ctx.cr6.eq) goto loc_820A84C4;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820a84d8
	if (!ctx.cr6.eq) goto loc_820A84D8;
	// li r4,4
	ctx.r4.s64 = 4;
	// b 0x820a84d0
	goto loc_820A84D0;
loc_820A84C4:
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x820a84d0
	goto loc_820A84D0;
loc_820A84CC:
	// li r4,7
	ctx.r4.s64 = 7;
loc_820A84D0:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bbe40
	ctx.lr = 0x820A84D8;
	sub_820BBE40(ctx, base);
loc_820A84D8:
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820a84f0
	if (ctx.cr6.lt) goto loc_820A84F0;
	// bne cr6,0x820a84fc
	if (!ctx.cr6.eq) goto loc_820A84FC;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x820a84f4
	goto loc_820A84F4;
loc_820A84F0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_820A84F4:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bbe10
	ctx.lr = 0x820A84FC;
	sub_820BBE10(ctx, base);
loc_820A84FC:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x820a8598
	if (ctx.cr6.gt) goto loc_820A8598;
	// lis r12,-32245
	ctx.r12.s64 = -2113208320;
	// addi r12,r12,-31456
	ctx.r12.s64 = ctx.r12.s64 + -31456;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_820A8530;
	case 1:
		goto loc_820A8540;
	case 2:
		goto loc_820A8554;
	case 3:
		goto loc_820A8574;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_820A8530:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb708
	ctx.lr = 0x820A853C;
	sub_820BB708(ctx, base);
	// b 0x820a8598
	goto loc_820A8598;
loc_820A8540:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb708
	ctx.lr = 0x820A854C;
	sub_820BB708(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// b 0x820a8584
	goto loc_820A8584;
loc_820A8554:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb708
	ctx.lr = 0x820A8560;
	sub_820BB708(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bbbc8
	ctx.lr = 0x820A856C;
	sub_820BBBC8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x820a8590
	goto loc_820A8590;
loc_820A8574:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb708
	ctx.lr = 0x820A8580;
	sub_820BB708(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
loc_820A8584:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bbbc8
	ctx.lr = 0x820A858C;
	sub_820BBBC8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
loc_820A8590:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bbb68
	ctx.lr = 0x820A8598;
	sub_820BBB68(ctx, base);
loc_820A8598:
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x820a85c4
	if (ctx.cr6.eq) goto loc_820A85C4;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x820a85bc
	if (ctx.cr6.eq) goto loc_820A85BC;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820a85d0
	if (!ctx.cr6.eq) goto loc_820A85D0;
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x820a85c8
	goto loc_820A85C8;
loc_820A85BC:
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x820a85c8
	goto loc_820A85C8;
loc_820A85C4:
	// li r4,0
	ctx.r4.s64 = 0;
loc_820A85C8:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x820bb6a8
	ctx.lr = 0x820A85D0;
	sub_820BB6A8(ctx, base);
loc_820A85D0:
	// addi r3,r31,29128
	ctx.r3.s64 = ctx.r31.s64 + 29128;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82129a70
	ctx.lr = 0x820A85E0;
	sub_82129A70(ctx, base);
loc_820A85E0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82129968
	__restgprlr_28(ctx, base);
	return;
}
