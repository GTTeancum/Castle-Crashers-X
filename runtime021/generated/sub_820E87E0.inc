DEFINE_REX_FUNC(sub_820E87E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129908
	ctx.lr = 0x820E87E8;
	__savegprlr_24(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lbz r3,56(r9)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r9.u32 + 56);
	// rotlwi r11,r3,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rlwinm r12,r8,0,0,27
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x8212b374
	ctx.lr = 0x820E8810;
	sub_8212B374(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// li r24,1
	ctx.r24.s64 = 1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + ctx.r12.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x820e8990
	if (ctx.cr6.eq) goto loc_820E8990;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r9,64
	ctx.r10.s64 = ctx.r9.s64 + 64;
	// addi r8,r4,4
	ctx.r8.s64 = ctx.r4.s64 + 4;
	// addi r28,r9,276
	ctx.r28.s64 = ctx.r9.s64 + 276;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r25,16
	ctx.r25.s64 = 16;
	// ori r30,r11,48000
	ctx.r30.u64 = ctx.r11.u64 | 48000;
loc_820E8848:
	// lwz r6,-4(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + -4);
	// li r26,3968
	ctx.r26.s64 = 3968;
	// lwz r11,204(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 204);
	// mullw r11,r11,r6
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r6.s32);
	// rlwinm r6,r11,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// divwu r11,r6,r30
	ctx.r11.u64 = uint32_t(ctx.r30.u32 ? ctx.r6.u32 / ctx.r30.u32 : 0);
	// addi r6,r11,16
	ctx.r6.s64 = ctx.r11.s64 + 16;
	// sth r6,0(r28)
	REX_STORE_U16(ctx.r28.u32 + 0, ctx.r6.u16);
	// lbz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// beq cr6,0x820e8878
	if (ctx.cr6.eq) goto loc_820E8878;
	// li r26,1920
	ctx.r26.s64 = 1920;
loc_820E8878:
	// lbz r29,1(r10)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820e888c
	if (!ctx.cr6.eq) goto loc_820E888C;
	// li r11,8
	ctx.r11.s64 = 8;
	// b 0x820e88f0
	goto loc_820E88F0;
loc_820E888C:
	// addi r11,r11,127
	ctx.r11.s64 = ctx.r11.s64 + 127;
	// rlwinm r11,r11,25,7,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1FFFFFF;
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// rlwinm r27,r11,7,0,24
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// and r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 & ctx.r11.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820e88b4
	if (ctx.cr6.eq) goto loc_820E88B4;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// subfic r6,r11,32
	ctx.xer.ca = ctx.r11.u32 <= 32;
	ctx.r6.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// slw r11,r24,r6
	ctx.r11.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r6.u8 & 0x3F));
loc_820E88B4:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x820e88c4
	if (!ctx.cr6.lt) goto loc_820E88C4;
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x820e88d0
	goto loc_820E88D0;
loc_820E88C4:
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// ble cr6,0x820e88d0
	if (!ctx.cr6.gt) goto loc_820E88D0;
	// li r11,8
	ctx.r11.s64 = 8;
loc_820E88D0:
	// rlwinm r6,r11,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// cmplwi cr6,r29,255
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 255, ctx.xer);
	// add r6,r6,r27
	ctx.r6.u64 = ctx.r6.u64 + ctx.r27.u64;
	// beq cr6,0x820e88e8
	if (ctx.cr6.eq) goto loc_820E88E8;
	// rlwinm r29,r29,7,0,24
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 7) & 0xFFFFFF80;
	// add r6,r29,r6
	ctx.r6.u64 = ctx.r29.u64 + ctx.r6.u64;
loc_820E88E8:
	// cmplw cr6,r6,r26
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r26.u32, ctx.xer);
	// ble cr6,0x820e88f4
	if (!ctx.cr6.gt) goto loc_820E88F4;
loc_820E88F0:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
loc_820E88F4:
	// lwz r29,-4(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + -4);
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// addi r28,r28,2
	ctx.r28.s64 = ctx.r28.s64 + 2;
	// stw r29,-4(r8)
	REX_STORE_U32(ctx.r8.u32 + -4, ctx.r29.u32);
	// lbz r29,0(r10)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// stw r6,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// stb r11,5(r8)
	REX_STORE_U8(ctx.r8.u32 + 5, ctx.r11.u8);
	// stb r29,4(r8)
	REX_STORE_U8(ctx.r8.u32 + 4, ctx.r29.u8);
	// addi r8,r8,12
	ctx.r8.s64 = ctx.r8.s64 + 12;
	// lwz r11,200(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 200);
	// add r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lbz r11,264(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 264);
	// stw r11,84(r6)
	REX_STORE_U32(ctx.r6.u32 + 84, ctx.r11.u32);
	// lfs f0,116(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// lwz r29,-4(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + -4);
	// std r29,80(r31)
	REX_STORE_U64(ctx.r31.u32 + 80, ctx.r29.u64);
	// lfd f13,80(r31)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r31.u32 + 80);
	// lwz r11,200(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 200);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lbz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// stb r6,13(r11)
	REX_STORE_U8(ctx.r11.u32 + 13, ctx.r6.u8);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lwz r29,80(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// ori r29,r29,1
	ctx.r29.u64 = ctx.r29.u64 | 1;
	// stb r24,12(r11)
	REX_STORE_U8(ctx.r11.u32 + 12, ctx.r24.u8);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stw r29,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r29.u32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// fctidz f9,f10
	ctx.f9.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfiwx f9,r11,r25
	REX_STORE_U32(ctx.r11.u32 + ctx.r25.u32, ctx.f9.u32);
	// lwz r11,200(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 200);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r6,80(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// ori r6,r6,2
	ctx.r6.u64 = ctx.r6.u64 | 2;
	// addi r7,r7,88
	ctx.r7.s64 = ctx.r7.s64 + 88;
	// stw r30,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r30.u32);
	// stw r6,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r6.u32);
	// bne 0x820e8848
	if (!ctx.cr0.eq) goto loc_820E8848;
loc_820E8990:
	// lbz r11,264(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 264);
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820e89a8
	if (ctx.cr6.eq) goto loc_820E89A8;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
loc_820E89A8:
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r9,184
	ctx.r6.s64 = ctx.r9.s64 + 184;
	// bl 0x820da200
	ctx.lr = 0x820E89B8;
	sub_820DA200(ctx, base);
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x82129958
	__restgprlr_24(ctx, base);
	return;
}
