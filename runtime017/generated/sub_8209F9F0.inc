DEFINE_REX_FUNC(sub_8209F9F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82129900
	ctx.lr = 0x8209F9F8;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x820b6998
	ctx.lr = 0x8209FA04;
	sub_820B6998(ctx, base);
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// li r22,1
	ctx.r22.s64 = 1;
	// li r23,2
	ctx.r23.s64 = 2;
	// li r24,3
	ctx.r24.s64 = 3;
	// li r25,4
	ctx.r25.s64 = 4;
	// li r29,5
	ctx.r29.s64 = 5;
	// li r28,6
	ctx.r28.s64 = 6;
	// li r26,7
	ctx.r26.s64 = 7;
	// li r30,8
	ctx.r30.s64 = 8;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgt cr6,0x8209fab0
	if (ctx.cr6.gt) goto loc_8209FAB0;
	// lis r12,-32246
	ctx.r12.s64 = -2113273856;
	// addi r12,r12,-1460
	ctx.r12.s64 = ctx.r12.s64 + -1460;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8209FAB0;
	case 1:
		goto loc_8209FA90;
	case 2:
		goto loc_8209FA70;
	case 3:
		goto loc_8209FA78;
	case 4:
		goto loc_8209FA80;
	case 5:
		goto loc_8209FA88;
	case 6:
		goto loc_8209FA98;
	case 7:
		goto loc_8209FAA0;
	case 8:
		goto loc_8209FAA8;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8209FA70:
	// stw r22,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r22.u32);
	// b 0x8209fab4
	goto loc_8209FAB4;
loc_8209FA78:
	// stw r23,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r23.u32);
	// b 0x8209fab4
	goto loc_8209FAB4;
loc_8209FA80:
	// stw r24,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r24.u32);
	// b 0x8209fab4
	goto loc_8209FAB4;
loc_8209FA88:
	// stw r25,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r25.u32);
	// b 0x8209fab4
	goto loc_8209FAB4;
loc_8209FA90:
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// b 0x8209fab4
	goto loc_8209FAB4;
loc_8209FA98:
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// b 0x8209fab4
	goto loc_8209FAB4;
loc_8209FAA0:
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// b 0x8209fab4
	goto loc_8209FAB4;
loc_8209FAA8:
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// b 0x8209fab4
	goto loc_8209FAB4;
loc_8209FAB0:
	// stw r27,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
loc_8209FAB4:
	// bl 0x8214a1e4
	ctx.lr = 0x8209FAB8;
	__imp__XGetGameRegion(ctx, base);
	// cmplwi cr6,r3,511
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 511, ctx.xer);
	// bgt cr6,0x8209ff30
	if (ctx.cr6.gt) goto loc_8209FF30;
	// beq cr6,0x8209ff20
	if (ctx.cr6.eq) goto loc_8209FF20;
	// addi r11,r3,-255
	ctx.r11.s64 = ctx.r3.s64 + -255;
	// cmplwi cr6,r11,253
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 253, ctx.xer);
	// bgt cr6,0x8209fee0
	if (ctx.cr6.gt) goto loc_8209FEE0;
	// lis r12,-32246
	ctx.r12.s64 = -2113273856;
	// addi r12,r12,-1304
	ctx.r12.s64 = ctx.r12.s64 + -1304;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8209FEE0;
	case 1:
		goto loc_8209FEE0;
	case 2:
		goto loc_8209FEF0;
	case 3:
		goto loc_8209FF00;
	case 4:
		goto loc_8209FEE0;
	case 5:
		goto loc_8209FEE0;
	case 6:
		goto loc_8209FEE0;
	case 7:
		goto loc_8209FEE0;
	case 8:
		goto loc_8209FEE0;
	case 9:
		goto loc_8209FEE0;
	case 10:
		goto loc_8209FEE0;
	case 11:
		goto loc_8209FEE0;
	case 12:
		goto loc_8209FEE0;
	case 13:
		goto loc_8209FEE0;
	case 14:
		goto loc_8209FEE0;
	case 15:
		goto loc_8209FEE0;
	case 16:
		goto loc_8209FEE0;
	case 17:
		goto loc_8209FEE0;
	case 18:
		goto loc_8209FEE0;
	case 19:
		goto loc_8209FEE0;
	case 20:
		goto loc_8209FEE0;
	case 21:
		goto loc_8209FEE0;
	case 22:
		goto loc_8209FEE0;
	case 23:
		goto loc_8209FEE0;
	case 24:
		goto loc_8209FEE0;
	case 25:
		goto loc_8209FEE0;
	case 26:
		goto loc_8209FEE0;
	case 27:
		goto loc_8209FEE0;
	case 28:
		goto loc_8209FEE0;
	case 29:
		goto loc_8209FEE0;
	case 30:
		goto loc_8209FEE0;
	case 31:
		goto loc_8209FEE0;
	case 32:
		goto loc_8209FEE0;
	case 33:
		goto loc_8209FEE0;
	case 34:
		goto loc_8209FEE0;
	case 35:
		goto loc_8209FEE0;
	case 36:
		goto loc_8209FEE0;
	case 37:
		goto loc_8209FEE0;
	case 38:
		goto loc_8209FEE0;
	case 39:
		goto loc_8209FEE0;
	case 40:
		goto loc_8209FEE0;
	case 41:
		goto loc_8209FEE0;
	case 42:
		goto loc_8209FEE0;
	case 43:
		goto loc_8209FEE0;
	case 44:
		goto loc_8209FEE0;
	case 45:
		goto loc_8209FEE0;
	case 46:
		goto loc_8209FEE0;
	case 47:
		goto loc_8209FEE0;
	case 48:
		goto loc_8209FEE0;
	case 49:
		goto loc_8209FEE0;
	case 50:
		goto loc_8209FEE0;
	case 51:
		goto loc_8209FEE0;
	case 52:
		goto loc_8209FEE0;
	case 53:
		goto loc_8209FEE0;
	case 54:
		goto loc_8209FEE0;
	case 55:
		goto loc_8209FEE0;
	case 56:
		goto loc_8209FEE0;
	case 57:
		goto loc_8209FEE0;
	case 58:
		goto loc_8209FEE0;
	case 59:
		goto loc_8209FEE0;
	case 60:
		goto loc_8209FEE0;
	case 61:
		goto loc_8209FEE0;
	case 62:
		goto loc_8209FEE0;
	case 63:
		goto loc_8209FEE0;
	case 64:
		goto loc_8209FEE0;
	case 65:
		goto loc_8209FEE0;
	case 66:
		goto loc_8209FEE0;
	case 67:
		goto loc_8209FEE0;
	case 68:
		goto loc_8209FEE0;
	case 69:
		goto loc_8209FEE0;
	case 70:
		goto loc_8209FEE0;
	case 71:
		goto loc_8209FEE0;
	case 72:
		goto loc_8209FEE0;
	case 73:
		goto loc_8209FEE0;
	case 74:
		goto loc_8209FEE0;
	case 75:
		goto loc_8209FEE0;
	case 76:
		goto loc_8209FEE0;
	case 77:
		goto loc_8209FEE0;
	case 78:
		goto loc_8209FEE0;
	case 79:
		goto loc_8209FEE0;
	case 80:
		goto loc_8209FEE0;
	case 81:
		goto loc_8209FEE0;
	case 82:
		goto loc_8209FEE0;
	case 83:
		goto loc_8209FEE0;
	case 84:
		goto loc_8209FEE0;
	case 85:
		goto loc_8209FEE0;
	case 86:
		goto loc_8209FEE0;
	case 87:
		goto loc_8209FEE0;
	case 88:
		goto loc_8209FEE0;
	case 89:
		goto loc_8209FEE0;
	case 90:
		goto loc_8209FEE0;
	case 91:
		goto loc_8209FEE0;
	case 92:
		goto loc_8209FEE0;
	case 93:
		goto loc_8209FEE0;
	case 94:
		goto loc_8209FEE0;
	case 95:
		goto loc_8209FEE0;
	case 96:
		goto loc_8209FEE0;
	case 97:
		goto loc_8209FEE0;
	case 98:
		goto loc_8209FEE0;
	case 99:
		goto loc_8209FEE0;
	case 100:
		goto loc_8209FEE0;
	case 101:
		goto loc_8209FEE0;
	case 102:
		goto loc_8209FEE0;
	case 103:
		goto loc_8209FEE0;
	case 104:
		goto loc_8209FEE0;
	case 105:
		goto loc_8209FEE0;
	case 106:
		goto loc_8209FEE0;
	case 107:
		goto loc_8209FEE0;
	case 108:
		goto loc_8209FEE0;
	case 109:
		goto loc_8209FEE0;
	case 110:
		goto loc_8209FEE0;
	case 111:
		goto loc_8209FEE0;
	case 112:
		goto loc_8209FEE0;
	case 113:
		goto loc_8209FEE0;
	case 114:
		goto loc_8209FEE0;
	case 115:
		goto loc_8209FEE0;
	case 116:
		goto loc_8209FEE0;
	case 117:
		goto loc_8209FEE0;
	case 118:
		goto loc_8209FEE0;
	case 119:
		goto loc_8209FEE0;
	case 120:
		goto loc_8209FEE0;
	case 121:
		goto loc_8209FEE0;
	case 122:
		goto loc_8209FEE0;
	case 123:
		goto loc_8209FEE0;
	case 124:
		goto loc_8209FEE0;
	case 125:
		goto loc_8209FEE0;
	case 126:
		goto loc_8209FEE0;
	case 127:
		goto loc_8209FEE0;
	case 128:
		goto loc_8209FEE0;
	case 129:
		goto loc_8209FEE0;
	case 130:
		goto loc_8209FEE0;
	case 131:
		goto loc_8209FEE0;
	case 132:
		goto loc_8209FEE0;
	case 133:
		goto loc_8209FEE0;
	case 134:
		goto loc_8209FEE0;
	case 135:
		goto loc_8209FEE0;
	case 136:
		goto loc_8209FEE0;
	case 137:
		goto loc_8209FEE0;
	case 138:
		goto loc_8209FEE0;
	case 139:
		goto loc_8209FEE0;
	case 140:
		goto loc_8209FEE0;
	case 141:
		goto loc_8209FEE0;
	case 142:
		goto loc_8209FEE0;
	case 143:
		goto loc_8209FEE0;
	case 144:
		goto loc_8209FEE0;
	case 145:
		goto loc_8209FEE0;
	case 146:
		goto loc_8209FEE0;
	case 147:
		goto loc_8209FEE0;
	case 148:
		goto loc_8209FEE0;
	case 149:
		goto loc_8209FEE0;
	case 150:
		goto loc_8209FEE0;
	case 151:
		goto loc_8209FEE0;
	case 152:
		goto loc_8209FEE0;
	case 153:
		goto loc_8209FEE0;
	case 154:
		goto loc_8209FEE0;
	case 155:
		goto loc_8209FEE0;
	case 156:
		goto loc_8209FEE0;
	case 157:
		goto loc_8209FEE0;
	case 158:
		goto loc_8209FEE0;
	case 159:
		goto loc_8209FEE0;
	case 160:
		goto loc_8209FEE0;
	case 161:
		goto loc_8209FEE0;
	case 162:
		goto loc_8209FEE0;
	case 163:
		goto loc_8209FEE0;
	case 164:
		goto loc_8209FEE0;
	case 165:
		goto loc_8209FEE0;
	case 166:
		goto loc_8209FEE0;
	case 167:
		goto loc_8209FEE0;
	case 168:
		goto loc_8209FEE0;
	case 169:
		goto loc_8209FEE0;
	case 170:
		goto loc_8209FEE0;
	case 171:
		goto loc_8209FEE0;
	case 172:
		goto loc_8209FEE0;
	case 173:
		goto loc_8209FEE0;
	case 174:
		goto loc_8209FEE0;
	case 175:
		goto loc_8209FEE0;
	case 176:
		goto loc_8209FEE0;
	case 177:
		goto loc_8209FEE0;
	case 178:
		goto loc_8209FEE0;
	case 179:
		goto loc_8209FEE0;
	case 180:
		goto loc_8209FEE0;
	case 181:
		goto loc_8209FEE0;
	case 182:
		goto loc_8209FEE0;
	case 183:
		goto loc_8209FEE0;
	case 184:
		goto loc_8209FEE0;
	case 185:
		goto loc_8209FEE0;
	case 186:
		goto loc_8209FEE0;
	case 187:
		goto loc_8209FEE0;
	case 188:
		goto loc_8209FEE0;
	case 189:
		goto loc_8209FEE0;
	case 190:
		goto loc_8209FEE0;
	case 191:
		goto loc_8209FEE0;
	case 192:
		goto loc_8209FEE0;
	case 193:
		goto loc_8209FEE0;
	case 194:
		goto loc_8209FEE0;
	case 195:
		goto loc_8209FEE0;
	case 196:
		goto loc_8209FEE0;
	case 197:
		goto loc_8209FEE0;
	case 198:
		goto loc_8209FEE0;
	case 199:
		goto loc_8209FEE0;
	case 200:
		goto loc_8209FEE0;
	case 201:
		goto loc_8209FEE0;
	case 202:
		goto loc_8209FEE0;
	case 203:
		goto loc_8209FEE0;
	case 204:
		goto loc_8209FEE0;
	case 205:
		goto loc_8209FEE0;
	case 206:
		goto loc_8209FEE0;
	case 207:
		goto loc_8209FEE0;
	case 208:
		goto loc_8209FEE0;
	case 209:
		goto loc_8209FEE0;
	case 210:
		goto loc_8209FEE0;
	case 211:
		goto loc_8209FEE0;
	case 212:
		goto loc_8209FEE0;
	case 213:
		goto loc_8209FEE0;
	case 214:
		goto loc_8209FEE0;
	case 215:
		goto loc_8209FEE0;
	case 216:
		goto loc_8209FEE0;
	case 217:
		goto loc_8209FEE0;
	case 218:
		goto loc_8209FEE0;
	case 219:
		goto loc_8209FEE0;
	case 220:
		goto loc_8209FEE0;
	case 221:
		goto loc_8209FEE0;
	case 222:
		goto loc_8209FEE0;
	case 223:
		goto loc_8209FEE0;
	case 224:
		goto loc_8209FEE0;
	case 225:
		goto loc_8209FEE0;
	case 226:
		goto loc_8209FEE0;
	case 227:
		goto loc_8209FEE0;
	case 228:
		goto loc_8209FEE0;
	case 229:
		goto loc_8209FEE0;
	case 230:
		goto loc_8209FEE0;
	case 231:
		goto loc_8209FEE0;
	case 232:
		goto loc_8209FEE0;
	case 233:
		goto loc_8209FEE0;
	case 234:
		goto loc_8209FEE0;
	case 235:
		goto loc_8209FEE0;
	case 236:
		goto loc_8209FEE0;
	case 237:
		goto loc_8209FEE0;
	case 238:
		goto loc_8209FEE0;
	case 239:
		goto loc_8209FEE0;
	case 240:
		goto loc_8209FEE0;
	case 241:
		goto loc_8209FEE0;
	case 242:
		goto loc_8209FEE0;
	case 243:
		goto loc_8209FEE0;
	case 244:
		goto loc_8209FEE0;
	case 245:
		goto loc_8209FEE0;
	case 246:
		goto loc_8209FEE0;
	case 247:
		goto loc_8209FEE0;
	case 248:
		goto loc_8209FEE0;
	case 249:
		goto loc_8209FEE0;
	case 250:
		goto loc_8209FEE0;
	case 251:
		goto loc_8209FEE0;
	case 252:
		goto loc_8209FEE0;
	case 253:
		goto loc_8209FF10;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8209FEE0:
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// stb r22,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r22.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8209FEF0:
	// stw r23,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r23.u32);
	// stb r22,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r22.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8209FF00:
	// stw r24,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r24.u32);
	// stb r22,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r22.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8209FF10:
	// stw r25,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// stb r22,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r22.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8209FF20:
	// stw r22,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r22.u32);
	// stb r22,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r22.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8209FF30:
	// cmplwi cr6,r3,767
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 767, ctx.xer);
	// bgt cr6,0x8209ff7c
	if (ctx.cr6.gt) goto loc_8209FF7C;
	// beq cr6,0x8209ff6c
	if (ctx.cr6.eq) goto loc_8209FF6C;
	// cmplwi cr6,r3,513
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 513, ctx.xer);
	// beq cr6,0x8209ff5c
	if (ctx.cr6.eq) goto loc_8209FF5C;
	// cmplwi cr6,r3,766
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 766, ctx.xer);
	// bne cr6,0x8209fee0
	if (!ctx.cr6.eq) goto loc_8209FEE0;
	// stw r26,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r26.u32);
	// stb r22,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r22.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8209FF5C:
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// stb r22,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r22.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8209FF6C:
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// stb r22,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r22.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
loc_8209FF7C:
	// cmplwi cr6,r3,1023
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1023, ctx.xer);
	// bne cr6,0x8209fee0
	if (!ctx.cr6.eq) goto loc_8209FEE0;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stb r22,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r22.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82129950
	__restgprlr_22(ctx, base);
	return;
}
