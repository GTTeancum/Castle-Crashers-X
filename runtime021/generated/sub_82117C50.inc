DEFINE_REX_FUNC(sub_82117C50) {
	REX_FUNC_PROLOGUE();
	// cmpwi cr6,r4,4096
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4096, ctx.xer);
	// bgt cr6,0x82117ed8
	if (ctx.cr6.gt) goto loc_82117ED8;
	// beq cr6,0x82117ec4
	if (ctx.cr6.eq) goto loc_82117EC4;
	// addi r11,r4,-1
	ctx.r11.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r11,27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 27, ctx.xer);
	// bgt cr6,0x82117f2c
	if (ctx.cr6.gt) goto loc_82117F2C;
	// lis r12,-32255
	ctx.r12.s64 = -2113863680;
	// addi r12,r12,-20536
	ctx.r12.s64 = ctx.r12.s64 + -20536;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32239
	ctx.r12.s64 = -2112815104;
	// addi r12,r12,31888
	ctx.r12.s64 = ctx.r12.s64 + 31888;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// nop 
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82117C90;
	case 1:
		goto loc_82117CA4;
	case 2:
		goto loc_82117CB8;
	case 3:
		goto loc_82117CCC;
	case 4:
		goto loc_82117CE0;
	case 5:
		goto loc_82117CF4;
	case 6:
		goto loc_82117D08;
	case 7:
		goto loc_82117D1C;
	case 8:
		goto loc_82117D30;
	case 9:
		goto loc_82117D44;
	case 10:
		goto loc_82117D58;
	case 11:
		goto loc_82117D6C;
	case 12:
		goto loc_82117D80;
	case 13:
		goto loc_82117D94;
	case 14:
		goto loc_82117DA8;
	case 15:
		goto loc_82117DBC;
	case 16:
		goto loc_82117DD0;
	case 17:
		goto loc_82117DE4;
	case 18:
		goto loc_82117DF8;
	case 19:
		goto loc_82117E0C;
	case 20:
		goto loc_82117E20;
	case 21:
		goto loc_82117E34;
	case 22:
		goto loc_82117E48;
	case 23:
		goto loc_82117E5C;
	case 24:
		goto loc_82117E70;
	case 25:
		goto loc_82117E84;
	case 26:
		goto loc_82117E9C;
	case 27:
		goto loc_82117EB0;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82117C90:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,108(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117CA4:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,112(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 112);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117CB8:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,116(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 116);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117CCC:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117CE0:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,120(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 120);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117CF4:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117D08:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,136(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117D1C:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117D30:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117D44:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lhz r11,148(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 148);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117D58:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lhz r11,150(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 150);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117D6C:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lhz r11,152(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 152);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117D80:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lhz r11,154(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 154);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117D94:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,56(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117DA8:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,144(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117DBC:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,64(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117DD0:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,68(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117DE4:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117DF8:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117E0C:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,72(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 72);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117E20:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,156(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117E34:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117E48:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,76(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117E5C:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,80(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117E70:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,84(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117E84:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,440(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 440);
	// rlwinm r11,r11,5,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0x1;
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117E9C:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,92(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117EB0:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117EC4:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,128(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 128);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117ED8:
	// cmpwi cr6,r4,4097
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4097, ctx.xer);
	// beq cr6,0x82117f9c
	if (ctx.cr6.eq) goto loc_82117F9C;
	// cmpwi cr6,r4,4099
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4099, ctx.xer);
	// beq cr6,0x82117f88
	if (ctx.cr6.eq) goto loc_82117F88;
	// cmpwi cr6,r4,4100
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4100, ctx.xer);
	// beq cr6,0x82117f74
	if (ctx.cr6.eq) goto loc_82117F74;
	// cmpwi cr6,r4,4101
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4101, ctx.xer);
	// beq cr6,0x82117f60
	if (ctx.cr6.eq) goto loc_82117F60;
	// cmpwi cr6,r4,4102
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4102, ctx.xer);
	// beq cr6,0x82117f4c
	if (ctx.cr6.eq) goto loc_82117F4C;
	// cmpwi cr6,r4,4103
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4103, ctx.xer);
	// beq cr6,0x82117f38
	if (ctx.cr6.eq) goto loc_82117F38;
	// cmpwi cr6,r4,4104
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4104, ctx.xer);
	// bne cr6,0x82117f2c
	if (!ctx.cr6.eq) goto loc_82117F2C;
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117f24
	if (ctx.cr6.lt) goto loc_82117F24;
	// lwz r11,160(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 160);
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
loc_82117F24:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
loc_82117F2C:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4105
	ctx.r3.u64 = ctx.r3.u64 | 4105;
	// blr 
	return;
loc_82117F38:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,132(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 132);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117F4C:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lhz r11,100(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 100);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117F60:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lhz r11,98(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 98);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117F74:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lhz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 96);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117F88:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// b 0x82117fac
	goto loc_82117FAC;
loc_82117F9C:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82117fb8
	if (ctx.cr6.lt) goto loc_82117FB8;
	// lwz r11,272(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 272);
loc_82117FAC:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// b 0x82117fc0
	goto loc_82117FC0;
loc_82117FB8:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4097
	ctx.r3.u64 = ctx.r3.u64 | 4097;
loc_82117FC0:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}
