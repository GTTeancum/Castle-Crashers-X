DEFINE_REX_FUNC(sub_820CB468) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298f4
	ctx.lr = 0x820CB470;
	__savegprlr_19(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// li r19,1
	ctx.r19.s64 = 1;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820cb498
	if (ctx.cr6.eq) goto loc_820CB498;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820cb4ac
	if (!ctx.cr6.eq) goto loc_820CB4AC;
loc_820CB498:
	// lis r11,-32243
	ctx.r11.s64 = -2113077248;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r31,r11,-20384
	ctx.r31.s64 = ctx.r11.s64 + -20384;
	// addi r30,r10,-20368
	ctx.r30.s64 = ctx.r10.s64 + -20368;
	// li r19,0
	ctx.r19.s64 = 0;
loc_820CB4AC:
	// li r3,1488
	ctx.r3.s64 = 1488;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CB4B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// li r3,3878
	ctx.r3.s64 = 3878;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CB4C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,448
	ctx.r3.s64 = 448;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CB4D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// li r3,1403
	ctx.r3.s64 = 1403;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CB4E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// li r3,1404
	ctx.r3.s64 = 1404;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CB4F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// li r3,1405
	ctx.r3.s64 = 1405;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CB504;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// li r3,1402
	ctx.r3.s64 = 1402;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CB514;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r4,12
	ctx.r4.s64 = 12;
	// li r3,3200
	ctx.r3.s64 = 3200;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// bctrl 
	ctx.lr = 0x820CB528;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,3201
	ctx.r3.s64 = 3201;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CB534;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// li r3,3201
	ctx.r3.s64 = 3201;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CB544;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r3.u32);
	// li r3,3201
	ctx.r3.s64 = 3201;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CB554;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// li r3,3201
	ctx.r3.s64 = 3201;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CB564;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r3.u32);
	// li r3,3201
	ctx.r3.s64 = 3201;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x820CB574;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r3.u32);
	// li r22,0
	ctx.r22.s64 = 0;
	// stw r27,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r27.u32);
	// stw r31,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r30,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r30.u32);
	// beq cr6,0x820cb608
	if (ctx.cr6.eq) goto loc_820CB608;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,10232
	ctx.r4.s64 = ctx.r11.s64 + 10232;
	// bl 0x820cb088
	ctx.lr = 0x820CB5A0;
	sub_820CB088(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,16560(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 16560);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r10,10224
	ctx.r7.s64 = ctx.r10.s64 + 10224;
	// addi r4,r8,10180
	ctx.r4.s64 = ctx.r8.s64 + 10180;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,7645
	ctx.r5.s64 = 7645;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r11,1616(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1616);
	// lhz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// bl 0x820cb088
	ctx.lr = 0x820CB5D0;
	sub_820CB088(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r7,10900(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 10900);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r6,10896(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 10896);
	// addi r4,r11,10132
	ctx.r4.s64 = ctx.r11.s64 + 10132;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820cb088
	ctx.lr = 0x820CB5EC;
	sub_820CB088(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r5,10908(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 10908);
	// addi r4,r11,10096
	ctx.r4.s64 = ctx.r11.s64 + 10096;
	// lwz r11,10896(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 10896);
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x820cb088
	ctx.lr = 0x820CB608;
	sub_820CB088(ctx, base);
loc_820CB608:
	// lis r11,-32763
	ctx.r11.s64 = -2147155968;
	// ori r11,r11,272
	ctx.r11.u64 = ctx.r11.u64 | 272;
	// cmplw cr6,r25,r11
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820cb64c
	if (!ctx.cr6.eq) goto loc_820CB64C;
	// lis r11,2989
	ctx.r11.s64 = 195887104;
	// ori r11,r11,61453
	ctx.r11.u64 = ctx.r11.u64 | 61453;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820cb64c
	if (ctx.cr6.eq) goto loc_820CB64C;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x820cb64c
	if (ctx.cr6.eq) goto loc_820CB64C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// addi r4,r11,9936
	ctx.r4.s64 = ctx.r11.s64 + 9936;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820cb088
	ctx.lr = 0x820CB648;
	sub_820CB088(ctx, base);
	// b 0x820cb7f0
	goto loc_820CB7F0;
loc_820CB64C:
	// rlwinm r11,r28,0,0,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xF8000000;
	// lis r10,2048
	ctx.r10.s64 = 134217728;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820cb69c
	if (!ctx.cr6.eq) goto loc_820CB69C;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820cb690
	if (ctx.cr6.eq) goto loc_820CB690;
	// lwz r10,23992(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 23992);
	// rlwinm r9,r28,4,22,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 4) & 0x3F0;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// rldimi r11,r28,32,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r28.u64, 32) & 0x3F00000000) | (ctx.r11.u64 & 0xFFFFFFC0FFFFFFFF);
	// addi r4,r8,9760
	ctx.r4.s64 = ctx.r8.s64 + 9760;
	// lwzx r10,r10,r9
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x820cb088
	ctx.lr = 0x820CB68C;
	sub_820CB088(ctx, base);
	// b 0x820cb7f0
	goto loc_820CB7F0;
loc_820CB690:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r4,r11,9600
	ctx.r4.s64 = ctx.r11.s64 + 9600;
	// b 0x820cb7ec
	goto loc_820CB7EC;
loc_820CB69C:
	// bl 0x820cb108
	ctx.lr = 0x820CB6A0;
	sub_820CB108(ctx, base);
	// lis r12,32763
	ctx.r12.s64 = 2147155968;
	// lis r11,1025
	ctx.r11.s64 = 67174400;
	// ori r12,r12,61664
	ctx.r12.u64 = ctx.r12.u64 | 61664;
	// and r31,r25,r12
	ctx.r31.u64 = ctx.r25.u64 & ctx.r12.u64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820cb6dc
	if (!ctx.cr6.eq) goto loc_820CB6DC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,9464
	ctx.r4.s64 = ctx.r11.s64 + 9464;
	// bl 0x820cb088
	ctx.lr = 0x820CB6C8;
	sub_820CB088(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,9312
	ctx.r4.s64 = ctx.r11.s64 + 9312;
	// bl 0x820cb088
	ctx.lr = 0x820CB6D8;
	sub_820CB088(ctx, base);
	// li r22,1
	ctx.r22.s64 = 1;
loc_820CB6DC:
	// rlwinm. r11,r21,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820cb72c
	if (ctx.cr0.eq) goto loc_820CB72C;
	// rlwinm. r11,r21,0,21,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x7C0;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820cb72c
	if (!ctx.cr0.eq) goto loc_820CB72C;
	// rlwinm r11,r21,21,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 21) & 0xC;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lis r9,32
	ctx.r9.s64 = 2097152;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// rlwinm r11,r11,0,5,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7F00000;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820cb72c
	if (!ctx.cr6.eq) goto loc_820CB72C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,9176
	ctx.r4.s64 = ctx.r11.s64 + 9176;
	// bl 0x820cb088
	ctx.lr = 0x820CB718;
	sub_820CB088(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,9000
	ctx.r4.s64 = ctx.r11.s64 + 9000;
	// bl 0x820cb088
	ctx.lr = 0x820CB728;
	sub_820CB088(ctx, base);
	// li r22,1
	ctx.r22.s64 = 1;
loc_820CB72C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x820cb768
	if (!ctx.cr6.eq) goto loc_820CB768;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,8856
	ctx.r4.s64 = ctx.r11.s64 + 8856;
	// bl 0x820cb088
	ctx.lr = 0x820CB744;
	sub_820CB088(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,8704
	ctx.r4.s64 = ctx.r11.s64 + 8704;
	// bl 0x820cb088
	ctx.lr = 0x820CB754;
	sub_820CB088(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,8652
	ctx.r4.s64 = ctx.r11.s64 + 8652;
	// bl 0x820cb088
	ctx.lr = 0x820CB764;
	sub_820CB088(ctx, base);
	// li r22,1
	ctx.r22.s64 = 1;
loc_820CB768:
	// lis r11,64
	ctx.r11.s64 = 4194304;
	// rlwinm r10,r31,0,9,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0x7FFFE0;
	// ori r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 32;
	// rlwinm r10,r10,0,26,9
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFC0003F;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820cb7b4
	if (!ctx.cr6.eq) goto loc_820CB7B4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,8496
	ctx.r4.s64 = ctx.r11.s64 + 8496;
	// bl 0x820cb088
	ctx.lr = 0x820CB790;
	sub_820CB088(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,8336
	ctx.r4.s64 = ctx.r11.s64 + 8336;
	// bl 0x820cb088
	ctx.lr = 0x820CB7A0;
	sub_820CB088(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,8152
	ctx.r4.s64 = ctx.r11.s64 + 8152;
	// bl 0x820cb088
	ctx.lr = 0x820CB7B0;
	sub_820CB088(ctx, base);
	// li r22,1
	ctx.r22.s64 = 1;
loc_820CB7B4:
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x820cb7cc
	if (ctx.cr6.eq) goto loc_820CB7CC;
	// mr r5,r19
	ctx.r5.u64 = ctx.r19.u64;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820cb370
	ctx.lr = 0x820CB7CC;
	sub_820CB370(ctx, base);
loc_820CB7CC:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// beq cr6,0x820cb7e4
	if (ctx.cr6.eq) goto loc_820CB7E4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r4,r11,8008
	ctx.r4.s64 = ctx.r11.s64 + 8008;
	// b 0x820cb7ec
	goto loc_820CB7EC;
loc_820CB7E4:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r4,r11,7864
	ctx.r4.s64 = ctx.r11.s64 + 7864;
loc_820CB7EC:
	// bl 0x820cb088
	ctx.lr = 0x820CB7F0;
	sub_820CB088(ctx, base);
loc_820CB7F0:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82129944
	__restgprlr_19(ctx, base);
	return;
}
