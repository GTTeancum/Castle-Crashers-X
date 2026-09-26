DEFINE_REX_FUNC(sub_820A7990_platform_prefix) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8212990c
	ctx.lr = 0x820A7998;
	__savegprlr_25(ctx, base);
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32218
	ctx.r8.s64 = -2111438848;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r11,r1,288
	ctx.r11.s64 = ctx.r1.s64 + 288;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// lwz r31,-6616(r8)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r8.u32 + -6616);
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820A79C4:
	// std r9,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r9.u64);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bdnz 0x820a79c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820A79C4;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x8214a214
	ctx.lr = 0x820A79D8;
	__imp__XGetVideoMode(ctx, base);
	// lwz r9,300(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 300);
	// lwz r6,304(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 304);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lwz r7,312(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 312);
	// cntlzw r5,r9
	ctx.r5.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cntlzw r3,r6
	ctx.r3.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// addi r4,r7,-3
	ctx.r4.s64 = ctx.r7.s64 + -3;
	// rlwinm r9,r5,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// rlwinm r6,r3,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// cntlzw r5,r4
	ctx.r5.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// xori r7,r9,1
	ctx.r7.u64 = ctx.r9.u64 ^ 1;
	// xori r9,r6,1
	ctx.r9.u64 = ctx.r6.u64 ^ 1;
	// rlwinm r6,r5,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stb r7,28712(r31)
	REX_STORE_U8(ctx.r31.u32 + 28712, ctx.r7.u8);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// stb r9,28713(r31)
	REX_STORE_U8(ctx.r31.u32 + 28713, ctx.r9.u8);
	// li r10,15
	ctx.r10.s64 = 15;
	// stb r6,28714(r31)
	REX_STORE_U8(ctx.r31.u32 + 28714, ctx.r6.u8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820A7A24:
	// std r8,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r8.u64);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bdnz 0x820a7a24
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820A7A24;
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820a7a64
	if (ctx.cr6.eq) goto loc_820A7A64;
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1280
	ctx.r11.s64 = 1280;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// beq cr6,0x820a7a5c
	if (ctx.cr6.eq) goto loc_820A7A5C;
	// li r10,720
	ctx.r10.s64 = 720;
	// b 0x820a7a70
	goto loc_820A7A70;
loc_820A7A5C:
	// li r10,960
	ctx.r10.s64 = 960;
	// b 0x820a7a70
	goto loc_820A7A70;
loc_820A7A64:
	// li r11,640
	ctx.r11.s64 = 640;
	// li r10,480
	ctx.r10.s64 = 480;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
loc_820A7A70:
	// clrlwi r11,r6,24
	ctx.r11.u64 = ctx.r6.u32 & 0xFF;
	// stw r10,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820a7aa4
	if (ctx.cr6.eq) goto loc_820A7AA4;
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820a7aa4
	if (!ctx.cr6.eq) goto loc_820A7AA4;
	// lwz r11,292(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// cmplwi cr6,r11,576
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 576, ctx.xer);
	// bne cr6,0x820a7aa4
	if (!ctx.cr6.eq) goto loc_820A7AA4;
	// lwz r11,204(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 204);
	// ori r10,r11,1
	ctx.r10.u64 = ctx.r11.u64 | 1;
	// stw r10,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r10.u32);
loc_820A7AA4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,308(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,6184
	ctx.r10.s64 = 405274624;
	// stw r28,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r28.u32);
	// lis r9,11552
	ctx.r9.s64 = 757071872;
	// stw r28,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r28.u32);
	// li r29,1
	ctx.r29.s64 = 1;
	// ori r25,r10,390
	ctx.r25.u64 = ctx.r10.u64 | 390;
	// ori r8,r9,406
	ctx.r8.u64 = ctx.r9.u64 | 406;
	// lfs f0,9848(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9848);
	ctx.f0.f64 = double(temp.f32);
	// stw r25,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r25.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// stw r29,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r29.u32);
	// stw r29,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r29.u32);
	// stw r8,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r8.u32);
	// stw r29,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r29.u32);
	// bge cr6,0x820a7af4
	if (!ctx.cr6.lt) goto loc_820A7AF4;
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// stw r11,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r11.u32);
	// b 0x820a7af8
	goto loc_820A7AF8;
loc_820A7AF4:
	// stw r29,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r29.u32);
loc_820A7AF8:
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// Checkpoint 018 diagnostic stop: next original instruction is bl 0x820BEFD0.
	return;
}
