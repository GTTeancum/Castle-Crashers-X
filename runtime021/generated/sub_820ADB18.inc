DEFINE_REX_FUNC(sub_820ADB18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x821298e0
	ctx.lr = 0x820ADB20;
	__savegprlr_14(ctx, base);
	// stw r7,52(r1)
	REX_STORE_U32(ctx.r1.u32 + 52, ctx.r7.u32);
	// li r15,0
	ctx.r15.s64 = 0;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// stw r5,36(r1)
	REX_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// stw r6,44(r1)
	REX_STORE_U32(ctx.r1.u32 + 44, ctx.r6.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r7,60(r1)
	REX_STORE_U32(ctx.r1.u32 + 60, ctx.r7.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r10,76(r1)
	REX_STORE_U32(ctx.r1.u32 + 76, ctx.r10.u32);
	// stw r15,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r15.u32);
	// stw r15,-364(r1)
	REX_STORE_U32(ctx.r1.u32 + -364, ctx.r15.u32);
	// stw r15,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r15.u32);
	// stw r15,-356(r1)
	REX_STORE_U32(ctx.r1.u32 + -356, ctx.r15.u32);
	// stw r15,-352(r1)
	REX_STORE_U32(ctx.r1.u32 + -352, ctx.r15.u32);
	// stw r15,-348(r1)
	REX_STORE_U32(ctx.r1.u32 + -348, ctx.r15.u32);
	// stw r15,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r15.u32);
	// stw r15,-340(r1)
	REX_STORE_U32(ctx.r1.u32 + -340, ctx.r15.u32);
	// stw r15,-336(r1)
	REX_STORE_U32(ctx.r1.u32 + -336, ctx.r15.u32);
	// stw r15,-332(r1)
	REX_STORE_U32(ctx.r1.u32 + -332, ctx.r15.u32);
	// stw r15,-328(r1)
	REX_STORE_U32(ctx.r1.u32 + -328, ctx.r15.u32);
	// stw r15,-324(r1)
	REX_STORE_U32(ctx.r1.u32 + -324, ctx.r15.u32);
	// stw r15,-320(r1)
	REX_STORE_U32(ctx.r1.u32 + -320, ctx.r15.u32);
	// stw r15,-316(r1)
	REX_STORE_U32(ctx.r1.u32 + -316, ctx.r15.u32);
	// stw r15,-312(r1)
	REX_STORE_U32(ctx.r1.u32 + -312, ctx.r15.u32);
	// stw r15,-308(r1)
	REX_STORE_U32(ctx.r1.u32 + -308, ctx.r15.u32);
loc_820ADB84:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r30,r1,-368
	ctx.r30.s64 = ctx.r1.s64 + -368;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r29,r10,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// lwzx r28,r29,r30
	ctx.r28.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// addi r8,r28,1
	ctx.r8.s64 = ctx.r28.s64 + 1;
	// stwx r8,r29,r30
	REX_STORE_U32(ctx.r29.u32 + ctx.r30.u32, ctx.r8.u32);
	// bne 0x820adb84
	if (!ctx.cr0.eq) goto loc_820ADB84;
	// lwz r11,-368(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bne cr6,0x820adbc4
	if (!ctx.cr6.eq) goto loc_820ADBC4;
	// stw r15,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r15.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r15,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r15.u32);
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
loc_820ADBC4:
	// li r21,1
	ctx.r21.s64 = 1;
	// lwz r23,0(r9)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r31,r1,-360
	ctx.r31.s64 = ctx.r1.s64 + -360;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
loc_820ADBD4:
	// lwz r10,-4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820adc40
	if (!ctx.cr6.eq) goto loc_820ADC40;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820adc24
	if (!ctx.cr6.eq) goto loc_820ADC24;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820adc2c
	if (!ctx.cr6.eq) goto loc_820ADC2C;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820adc34
	if (!ctx.cr6.eq) goto loc_820ADC34;
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820adc3c
	if (!ctx.cr6.eq) goto loc_820ADC3C;
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// addi r31,r31,20
	ctx.r31.s64 = ctx.r31.s64 + 20;
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// ble cr6,0x820adbd4
	if (!ctx.cr6.gt) goto loc_820ADBD4;
	// b 0x820adc40
	goto loc_820ADC40;
loc_820ADC24:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x820adc40
	goto loc_820ADC40;
loc_820ADC2C:
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// b 0x820adc40
	goto loc_820ADC40;
loc_820ADC34:
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// b 0x820adc40
	goto loc_820ADC40;
loc_820ADC3C:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_820ADC40:
	// mr r18,r11
	ctx.r18.u64 = ctx.r11.u64;
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x820adc50
	if (!ctx.cr6.lt) goto loc_820ADC50;
	// mr r23,r11
	ctx.r23.u64 = ctx.r11.u64;
loc_820ADC50:
	// li r31,15
	ctx.r31.s64 = 15;
	// addi r30,r1,-308
	ctx.r30.s64 = ctx.r1.s64 + -308;
loc_820ADC58:
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820adc70
	if (!ctx.cr6.eq) goto loc_820ADC70;
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r30,r30,-4
	ctx.r30.s64 = ctx.r30.s64 + -4;
	// bne 0x820adc58
	if (!ctx.cr0.eq) goto loc_820ADC58;
loc_820ADC70:
	// mr r14,r31
	ctx.r14.u64 = ctx.r31.u64;
	// cmplw cr6,r23,r31
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x820adc80
	if (!ctx.cr6.gt) goto loc_820ADC80;
	// mr r23,r31
	ctx.r23.u64 = ctx.r31.u64;
loc_820ADC80:
	// stw r23,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r23.u32);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// slw r30,r21,r11
	ctx.r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r11.u8 & 0x3F));
	// bge cr6,0x820adcbc
	if (!ctx.cr6.lt) goto loc_820ADCBC;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,-368
	ctx.r9.s64 = ctx.r1.s64 + -368;
	// add r9,r29,r9
	ctx.r9.u64 = ctx.r29.u64 + ctx.r9.u64;
loc_820ADC9C:
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// subf. r30,r10,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x820adeb4
	if (ctx.cr0.lt) goto loc_820ADEB4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// rlwinm r30,r30,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x820adc9c
	if (ctx.cr6.lt) goto loc_820ADC9C;
loc_820ADCBC:
	// rlwinm r29,r31,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,-368
	ctx.r9.s64 = ctx.r1.s64 + -368;
	// lwzx r11,r29,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r9.u32);
	// subf. r6,r11,r30
	ctx.r6.u64 = ctx.r30.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r6,-376(r1)
	REX_STORE_U32(ctx.r1.u32 + -376, ctx.r6.u32);
	// blt 0x820adeb4
	if (ctx.cr0.lt) goto loc_820ADEB4;
	// add r10,r11,r6
	ctx.r10.u64 = ctx.r11.u64 + ctx.r6.u64;
	// stw r15,-284(r1)
	REX_STORE_U32(ctx.r1.u32 + -284, ctx.r15.u32);
	// addic. r11,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r11.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stwx r10,r29,r9
	REX_STORE_U32(ctx.r29.u32 + ctx.r9.u32, ctx.r10.u32);
	// mr r31,r15
	ctx.r31.u64 = ctx.r15.u64;
	// beq 0x820add10
	if (ctx.cr0.eq) goto loc_820ADD10;
	// mr r9,r15
	ctx.r9.u64 = ctx.r15.u64;
loc_820ADCF0:
	// addi r10,r1,-364
	ctx.r10.s64 = ctx.r1.s64 + -364;
	// addi r8,r1,-280
	ctx.r8.s64 = ctx.r1.s64 + -280;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwzx r30,r9,r10
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r31,r30,r31
	ctx.r31.u64 = ctx.r30.u64 + ctx.r31.u64;
	// stwx r31,r9,r8
	REX_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r31.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x820adcf0
	if (!ctx.cr0.eq) goto loc_820ADCF0;
loc_820ADD10:
	// lwz r8,92(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r15
	ctx.r31.u64 = ctx.r15.u64;
loc_820ADD1C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820add48
	if (ctx.cr6.eq) goto loc_820ADD48;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,-288
	ctx.r3.s64 = ctx.r1.s64 + -288;
	// lwzx r11,r9,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r11,r9,r3
	REX_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r11.u32);
	// stwx r31,r10,r8
	REX_STORE_U32(ctx.r10.u32 + ctx.r8.u32, ctx.r31.u32);
loc_820ADD48:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplw cr6,r31,r4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x820add1c
	if (ctx.cr6.lt) goto loc_820ADD1C;
	// addi r11,r1,-288
	ctx.r11.s64 = ctx.r1.s64 + -288;
	// stw r15,-224(r1)
	REX_STORE_U32(ctx.r1.u32 + -224, ctx.r15.u32);
	// mr r24,r15
	ctx.r24.u64 = ctx.r15.u64;
	// mr r17,r8
	ctx.r17.u64 = ctx.r8.u64;
	// li r26,-1
	ctx.r26.s64 = -1;
	// mr r30,r15
	ctx.r30.u64 = ctx.r15.u64;
	// lwzx r10,r29,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// neg r29,r23
	ctx.r29.s64 = static_cast<int64_t>(-ctx.r23.u64);
	// stw r15,-288(r1)
	REX_STORE_U32(ctx.r1.u32 + -288, ctx.r15.u32);
	// mr r27,r15
	ctx.r27.u64 = ctx.r15.u64;
	// cmpw cr6,r18,r14
	ctx.cr6.compare<int32_t>(ctx.r18.s32, ctx.r14.s32, ctx.xer);
	// stw r10,28(r1)
	REX_STORE_U32(ctx.r1.u32 + 28, ctx.r10.u32);
	// bgt cr6,0x820ae014
	if (ctx.cr6.gt) goto loc_820AE014;
	// rlwinm r11,r18,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r19,84(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r9,r1,-368
	ctx.r9.s64 = ctx.r1.s64 + -368;
	// addi r10,r18,-1
	ctx.r10.s64 = ctx.r18.s64 + -1;
	// add r16,r11,r9
	ctx.r16.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_820ADD9C:
	// lwz r20,0(r16)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x820ae000
	if (ctx.cr6.eq) goto loc_820AE000;
loc_820ADDA8:
	// add r11,r29,r23
	ctx.r11.u64 = ctx.r29.u64 + ctx.r23.u64;
	// addi r20,r20,-1
	ctx.r20.s64 = ctx.r20.s64 + -1;
	// cmpw cr6,r18,r11
	ctx.cr6.compare<int32_t>(ctx.r18.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x820adecc
	if (!ctx.cr6.gt) goto loc_820ADECC;
	// addi r22,r20,1
	ctx.r22.s64 = ctx.r20.s64 + 1;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
	// subf r28,r23,r29
	ctx.r28.u64 = ctx.r29.u64 - ctx.r23.u64;
loc_820ADDC4:
	// add r29,r29,r23
	ctx.r29.u64 = ctx.r29.u64 + ctx.r23.u64;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// subf r3,r29,r14
	ctx.r3.u64 = ctx.r14.u64 - ctx.r29.u64;
	// add r28,r28,r23
	ctx.r28.u64 = ctx.r28.u64 + ctx.r23.u64;
	// add r25,r25,r23
	ctx.r25.u64 = ctx.r25.u64 + ctx.r23.u64;
	// cmplw cr6,r3,r23
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r23.u32, ctx.xer);
	// ble cr6,0x820adde4
	if (!ctx.cr6.gt) goto loc_820ADDE4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
loc_820ADDE4:
	// subf r11,r29,r18
	ctx.r11.u64 = ctx.r18.u64 - ctx.r29.u64;
	// slw r9,r21,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r11.u8 & 0x3F));
	// cmplw cr6,r9,r22
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r22.u32, ctx.xer);
	// ble cr6,0x820ade38
	if (!ctx.cr6.gt) goto loc_820ADE38;
	// subf r9,r20,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r20.u64;
	// mr r31,r16
	ctx.r31.u64 = ctx.r16.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x820ade38
	if (!ctx.cr6.lt) goto loc_820ADE38;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x820ade38
	if (!ctx.cr6.lt) goto loc_820ADE38;
loc_820ADE14:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r9,r4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, ctx.xer);
	// ble cr6,0x820ade38
	if (!ctx.cr6.gt) goto loc_820ADE38;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// subf r9,r4,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r4.u64;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x820ade14
	if (ctx.cr6.lt) goto loc_820ADE14;
loc_820ADE38:
	// lwz r4,0(r19)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// slw r27,r21,r11
	ctx.r27.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r11.u8 & 0x3F));
	// add r3,r4,r27
	ctx.r3.u64 = ctx.r4.u64 + ctx.r27.u64;
	// cmplwi cr6,r3,1440
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1440, ctx.xer);
	// bgt cr6,0x820adeb4
	if (ctx.cr6.gt) goto loc_820ADEB4;
	// stw r3,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r3.u32);
	// rlwinm r9,r26,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,76(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 76);
	// addi r31,r1,-224
	ctx.r31.s64 = ctx.r1.s64 + -224;
	// rlwinm r3,r4,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r9,r31
	ctx.r4.u64 = ctx.r9.u64 + ctx.r31.u64;
	// add r30,r3,r6
	ctx.r30.u64 = ctx.r3.u64 + ctx.r6.u64;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// stwx r30,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r30.u32);
	// beq cr6,0x820adebc
	if (ctx.cr6.eq) goto loc_820ADEBC;
	// lwz r6,-4(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + -4);
	// srw r5,r24,r28
	ctx.r5.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r24.u32 >> (ctx.r28.u8 & 0x3F));
	// subf r4,r6,r30
	ctx.r4.u64 = ctx.r30.u64 - ctx.r6.u64;
	// stb r11,-384(r1)
	REX_STORE_U8(ctx.r1.u32 + -384, ctx.r11.u8);
	// rlwinm r31,r5,3,0,28
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// stb r23,-383(r1)
	REX_STORE_U8(ctx.r1.u32 + -383, ctx.r23.u8);
	// srawi r4,r4,3
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 3;
	// lwz r7,60(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 60);
	// addi r3,r1,-288
	ctx.r3.s64 = ctx.r1.s64 + -288;
	// std r10,-304(r1)
	REX_STORE_U64(ctx.r1.u32 + -304, ctx.r10.u64);
	// subf r5,r5,r4
	ctx.r5.u64 = ctx.r4.u64 - ctx.r5.u64;
	// stw r5,-380(r1)
	REX_STORE_U32(ctx.r1.u32 + -380, ctx.r5.u32);
	// ld r4,-384(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + -384);
	// stwx r24,r9,r3
	REX_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r24.u32);
	// stdx r4,r31,r6
	REX_STORE_U64(ctx.r31.u32 + ctx.r6.u32, ctx.r4.u64);
	// b 0x820adec0
	goto loc_820ADEC0;
loc_820ADEB4:
	// li r3,-3
	ctx.r3.s64 = -3;
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
loc_820ADEBC:
	// stw r30,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r30.u32);
loc_820ADEC0:
	// cmpw cr6,r18,r25
	ctx.cr6.compare<int32_t>(ctx.r18.s32, ctx.r25.s32, ctx.xer);
	// bgt cr6,0x820addc4
	if (ctx.cr6.gt) goto loc_820ADDC4;
	// lwz r5,36(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 36);
loc_820ADECC:
	// lwz r11,28(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 28);
	// subf r9,r29,r18
	ctx.r9.u64 = ctx.r18.u64 - ctx.r29.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stb r9,-383(r1)
	REX_STORE_U8(ctx.r1.u32 + -383, ctx.r9.u8);
	// add r4,r11,r8
	ctx.r4.u64 = ctx.r11.u64 + ctx.r8.u64;
	// cmplw cr6,r17,r4
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x820adef4
	if (ctx.cr6.lt) goto loc_820ADEF4;
	// li r11,192
	ctx.r11.s64 = 192;
	// stb r11,-384(r1)
	REX_STORE_U8(ctx.r1.u32 + -384, ctx.r11.u8);
	// b 0x820adf4c
	goto loc_820ADF4C;
loc_820ADEF4:
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// addi r17,r17,4
	ctx.r17.s64 = ctx.r17.s64 + 4;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// bge cr6,0x820adf28
	if (!ctx.cr6.lt) goto loc_820ADF28;
	// li r9,256
	ctx.r9.s64 = 256;
	// stw r11,-380(r1)
	REX_STORE_U32(ctx.r1.u32 + -380, ctx.r11.u32);
	// subfc r6,r9,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r9.u32;
	ctx.r6.u64 = ctx.r11.u64 - ctx.r9.u64;
	// subfe r4,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r4,0,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFE0;
	// rlwinm r11,r11,0,26,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// addi r3,r11,96
	ctx.r3.s64 = ctx.r11.s64 + 96;
	// stb r3,-384(r1)
	REX_STORE_U8(ctx.r1.u32 + -384, ctx.r3.u8);
	// b 0x820adf4c
	goto loc_820ADF4C;
loc_820ADF28:
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// lwz r9,52(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 52);
	// lwz r6,44(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 44);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r4,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// lwzx r3,r4,r6
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// stb r11,-384(r1)
	REX_STORE_U8(ctx.r1.u32 + -384, ctx.r11.u8);
	// stw r3,-380(r1)
	REX_STORE_U32(ctx.r1.u32 + -380, ctx.r3.u32);
loc_820ADF4C:
	// subf r9,r29,r18
	ctx.r9.u64 = ctx.r18.u64 - ctx.r29.u64;
	// srw r11,r24,r29
	ctx.r11.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r24.u32 >> (ctx.r29.u8 & 0x3F));
	// slw r4,r21,r9
	ctx.r4.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r9.u8 & 0x3F));
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// bge cr6,0x820adf84
	if (!ctx.cr6.lt) goto loc_820ADF84;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// ld r31,-384(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -384);
	// rlwinm r3,r4,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + ctx.r30.u64;
loc_820ADF70:
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// std r31,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.r31.u64);
	// add r9,r3,r9
	ctx.r9.u64 = ctx.r3.u64 + ctx.r9.u64;
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x820adf70
	if (ctx.cr6.lt) goto loc_820ADF70;
loc_820ADF84:
	// slw r9,r21,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r10.u8 & 0x3F));
	// and r11,r9,r24
	ctx.r11.u64 = ctx.r9.u64 & ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820adfa8
	if (ctx.cr6.eq) goto loc_820ADFA8;
loc_820ADF94:
	// xor r24,r9,r24
	ctx.r24.u64 = ctx.r9.u64 ^ ctx.r24.u64;
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// and r11,r9,r24
	ctx.r11.u64 = ctx.r9.u64 & ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820adf94
	if (!ctx.cr6.eq) goto loc_820ADF94;
loc_820ADFA8:
	// addi r4,r1,-288
	ctx.r4.s64 = ctx.r1.s64 + -288;
	// rlwinm r11,r26,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// xor r24,r9,r24
	ctx.r24.u64 = ctx.r9.u64 ^ ctx.r24.u64;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// slw r4,r21,r29
	ctx.r4.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r29.u8 & 0x3F));
	// addi r9,r4,-1
	ctx.r9.s64 = ctx.r4.s64 + -1;
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// and r4,r9,r24
	ctx.r4.u64 = ctx.r9.u64 & ctx.r24.u64;
	// cmplw cr6,r4,r6
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x820adff4
	if (ctx.cr6.eq) goto loc_820ADFF4;
loc_820ADFD0:
	// subf r29,r23,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r23.u64;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// slw r9,r21,r29
	ctx.r9.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r29.u8 & 0x3F));
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r26,r26,-1
	ctx.r26.s64 = ctx.r26.s64 + -1;
	// and r4,r9,r24
	ctx.r4.u64 = ctx.r9.u64 & ctx.r24.u64;
	// cmplw cr6,r4,r6
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x820adfd0
	if (!ctx.cr6.eq) goto loc_820ADFD0;
loc_820ADFF4:
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// bne cr6,0x820adda8
	if (!ctx.cr6.eq) goto loc_820ADDA8;
	// lwz r6,-376(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -376);
loc_820AE000:
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// addi r16,r16,4
	ctx.r16.s64 = ctx.r16.s64 + 4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r18,r14
	ctx.cr6.compare<int32_t>(ctx.r18.s32, ctx.r14.s32, ctx.xer);
	// ble cr6,0x820add9c
	if (!ctx.cr6.gt) goto loc_820ADD9C;
loc_820AE014:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x820ae028
	if (ctx.cr6.eq) goto loc_820AE028;
	// cmpwi cr6,r14,1
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 1, ctx.xer);
	// li r3,-5
	ctx.r3.s64 = -5;
	// bne cr6,0x820ae02c
	if (!ctx.cr6.eq) goto loc_820AE02C;
loc_820AE028:
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
loc_820AE02C:
	// b 0x82129930
	__restgprlr_14(ctx, base);
	return;
}
