DEFINE_REX_FUNC(sub_820790E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r4,132
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 132, ctx.xer);
	// bgt cr6,0x820798b8
	if (ctx.cr6.gt) goto loc_820798B8;
	// lis r12,-32248
	ctx.r12.s64 = -2113404928;
	// addi r12,r12,-28396
	ctx.r12.s64 = ctx.r12.s64 + -28396;
	// rlwinm r0,r4,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r4.u32) {
	case 0:
		goto loc_820798C4;
	case 1:
		goto loc_82079874;
	case 2:
		goto loc_82079448;
	case 3:
		goto loc_82079448;
	case 4:
		goto loc_820795AC;
	case 5:
		goto loc_820795AC;
	case 6:
		goto loc_82079710;
	case 7:
		goto loc_82079710;
	case 8:
		goto loc_8207948C;
	case 9:
		goto loc_820794B0;
	case 10:
		goto loc_82079874;
	case 11:
		goto loc_82079874;
	case 12:
		goto loc_820794D4;
	case 13:
		goto loc_820794F8;
	case 14:
		goto loc_82079448;
	case 15:
		goto loc_82079448;
	case 16:
		goto loc_820795AC;
	case 17:
		goto loc_820795AC;
	case 18:
		goto loc_820795AC;
	case 19:
		goto loc_820795AC;
	case 20:
		goto loc_820795AC;
	case 21:
		goto loc_820795AC;
	case 22:
		goto loc_82079710;
	case 23:
		goto loc_82079710;
	case 24:
		goto loc_82079874;
	case 25:
		goto loc_820798B8;
	case 26:
		goto loc_820798B8;
	case 27:
		goto loc_820795AC;
	case 28:
		goto loc_820798B8;
	case 29:
		goto loc_820798B8;
	case 30:
		goto loc_820798B8;
	case 31:
		goto loc_820798B8;
	case 32:
		goto loc_820795AC;
	case 33:
		goto loc_820795AC;
	case 34:
		goto loc_820795AC;
	case 35:
		goto loc_820798B8;
	case 36:
		goto loc_820798B8;
	case 37:
		goto loc_82079328;
	case 38:
		goto loc_8207934C;
	case 39:
		goto loc_82079370;
	case 40:
		goto loc_82079394;
	case 41:
		goto loc_820798B8;
	case 42:
		goto loc_820798B8;
	case 43:
		goto loc_820798B8;
	case 44:
		goto loc_820798B8;
	case 45:
		goto loc_820798B8;
	case 46:
		goto loc_820798B8;
	case 47:
		goto loc_820798B8;
	case 48:
		goto loc_820798B8;
	case 49:
		goto loc_82079448;
	case 50:
		goto loc_820795AC;
	case 51:
		goto loc_82079710;
	case 52:
		goto loc_82079874;
	case 53:
		goto loc_82079448;
	case 54:
		goto loc_820795AC;
	case 55:
		goto loc_82079710;
	case 56:
		goto loc_82079874;
	case 57:
		goto loc_820798B8;
	case 58:
		goto loc_820798B8;
	case 59:
		goto loc_820798B8;
	case 60:
		goto loc_820798B8;
	case 61:
		goto loc_820798B8;
	case 62:
		goto loc_820798B8;
	case 63:
		goto loc_820798B8;
	case 64:
		goto loc_820798B8;
	case 65:
		goto loc_82079448;
	case 66:
		goto loc_82079448;
	case 67:
		goto loc_82079448;
	case 68:
		goto loc_82079448;
	case 69:
		goto loc_82079448;
	case 70:
		goto loc_820798B8;
	case 71:
		goto loc_820798B8;
	case 72:
		goto loc_820798B8;
	case 73:
		goto loc_820798B8;
	case 74:
		goto loc_820798B8;
	case 75:
		goto loc_820798B8;
	case 76:
		goto loc_820798B8;
	case 77:
		goto loc_820798B8;
	case 78:
		goto loc_820798B8;
	case 79:
		goto loc_820798B8;
	case 80:
		goto loc_820798B8;
	case 81:
		goto loc_82079448;
	case 82:
		goto loc_820798B8;
	case 83:
		goto loc_82079448;
	case 84:
		goto loc_820798B8;
	case 85:
		goto loc_820798B8;
	case 86:
		goto loc_820798B8;
	case 87:
		goto loc_82079448;
	case 88:
		goto loc_820795F0;
	case 89:
		goto loc_82079614;
	case 90:
		goto loc_82079638;
	case 91:
		goto loc_820798B8;
	case 92:
		goto loc_820798B8;
	case 93:
		goto loc_820798B8;
	case 94:
		goto loc_820798B8;
	case 95:
		goto loc_820798B8;
	case 96:
		goto loc_8207965C;
	case 97:
		goto loc_82079710;
	case 98:
		goto loc_82079710;
	case 99:
		goto loc_82079710;
	case 100:
		goto loc_82079710;
	case 101:
		goto loc_82079710;
	case 102:
		goto loc_82079710;
	case 103:
		goto loc_82079710;
	case 104:
		goto loc_82079710;
	case 105:
		goto loc_82079754;
	case 106:
		goto loc_82079778;
	case 107:
		goto loc_8207979C;
	case 108:
		goto loc_820797C0;
	case 109:
		goto loc_82079874;
	case 110:
		goto loc_82079874;
	case 111:
		goto loc_82079874;
	case 112:
		goto loc_82079874;
	case 113:
		goto loc_82079874;
	case 114:
		goto loc_82079874;
	case 115:
		goto loc_82079874;
	case 116:
		goto loc_82079874;
	case 117:
		goto loc_820793B8;
	case 118:
		goto loc_820793DC;
	case 119:
		goto loc_82079400;
	case 120:
		goto loc_82079424;
	case 121:
		goto loc_8207951C;
	case 122:
		goto loc_82079540;
	case 123:
		goto loc_82079564;
	case 124:
		goto loc_82079588;
	case 125:
		goto loc_82079680;
	case 126:
		goto loc_820796A4;
	case 127:
		goto loc_820796C8;
	case 128:
		goto loc_820796EC;
	case 129:
		goto loc_820797E4;
	case 130:
		goto loc_82079808;
	case 131:
		goto loc_8207982C;
	case 132:
		goto loc_82079850;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82079328:
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079338;
	sub_82078D90(ctx, base);
	// bl 0x82078ab0
	ctx.lr = 0x8207933C;
	sub_82078AB0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8207934C:
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x8207935C;
	sub_82078D90(ctx, base);
	// bl 0x82078bb0
	ctx.lr = 0x82079360;
	sub_82078BB0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079370:
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079380;
	sub_82078D90(ctx, base);
	// bl 0x82078b30
	ctx.lr = 0x82079384;
	sub_82078B30(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079394:
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x820793A4;
	sub_82078D90(ctx, base);
	// bl 0x82078c30
	ctx.lr = 0x820793A8;
	sub_82078C30(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820793B8:
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x820793C8;
	sub_82078D90(ctx, base);
	// bl 0x82078910
	ctx.lr = 0x820793CC;
	sub_82078910(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820793DC:
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x820793EC;
	sub_82078D90(ctx, base);
	// bl 0x820789e0
	ctx.lr = 0x820793F0;
	sub_820789E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079400:
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079410;
	sub_82078D90(ctx, base);
	// bl 0x82078978
	ctx.lr = 0x82079414;
	sub_82078978(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079424:
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079434;
	sub_82078D90(ctx, base);
	// bl 0x82078a48
	ctx.lr = 0x82079438;
	sub_82078A48(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079448:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// stw r4,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// bl 0x82073fa0
	ctx.lr = 0x82079464;
	sub_82073FA0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820798c8
	if (ctx.cr6.eq) goto loc_820798C8;
	// lbz r3,19(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 19);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8207948C:
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x8207949C;
	sub_82078D90(ctx, base);
	// bl 0x82078ab0
	ctx.lr = 0x820794A0;
	sub_82078AB0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820794B0:
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x820794C0;
	sub_82078D90(ctx, base);
	// bl 0x82078bb0
	ctx.lr = 0x820794C4;
	sub_82078BB0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820794D4:
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x820794E4;
	sub_82078D90(ctx, base);
	// bl 0x82078b30
	ctx.lr = 0x820794E8;
	sub_82078B30(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820794F8:
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079508;
	sub_82078D90(ctx, base);
	// bl 0x82078c30
	ctx.lr = 0x8207950C;
	sub_82078C30(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8207951C:
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x8207952C;
	sub_82078D90(ctx, base);
	// bl 0x82078910
	ctx.lr = 0x82079530;
	sub_82078910(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079540:
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079550;
	sub_82078D90(ctx, base);
	// bl 0x820789e0
	ctx.lr = 0x82079554;
	sub_820789E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079564:
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079574;
	sub_82078D90(ctx, base);
	// bl 0x82078978
	ctx.lr = 0x82079578;
	sub_82078978(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079588:
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079598;
	sub_82078D90(ctx, base);
	// bl 0x82078a48
	ctx.lr = 0x8207959C;
	sub_82078A48(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820795AC:
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// stw r4,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// bl 0x82073fa0
	ctx.lr = 0x820795C8;
	sub_82073FA0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820798c8
	if (ctx.cr6.eq) goto loc_820798C8;
	// lbz r3,19(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 19);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820795F0:
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079600;
	sub_82078D90(ctx, base);
	// bl 0x82078ab0
	ctx.lr = 0x82079604;
	sub_82078AB0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079614:
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079624;
	sub_82078D90(ctx, base);
	// bl 0x82078bb0
	ctx.lr = 0x82079628;
	sub_82078BB0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079638:
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079648;
	sub_82078D90(ctx, base);
	// bl 0x82078b30
	ctx.lr = 0x8207964C;
	sub_82078B30(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8207965C:
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x8207966C;
	sub_82078D90(ctx, base);
	// bl 0x82078c30
	ctx.lr = 0x82079670;
	sub_82078C30(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079680:
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079690;
	sub_82078D90(ctx, base);
	// bl 0x82078910
	ctx.lr = 0x82079694;
	sub_82078910(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820796A4:
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x820796B4;
	sub_82078D90(ctx, base);
	// bl 0x820789e0
	ctx.lr = 0x820796B8;
	sub_820789E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820796C8:
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x820796D8;
	sub_82078D90(ctx, base);
	// bl 0x82078978
	ctx.lr = 0x820796DC;
	sub_82078978(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820796EC:
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x820796FC;
	sub_82078D90(ctx, base);
	// bl 0x82078a48
	ctx.lr = 0x82079700;
	sub_82078A48(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079710:
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// stw r4,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// bl 0x82073fa0
	ctx.lr = 0x8207972C;
	sub_82073FA0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820798c8
	if (ctx.cr6.eq) goto loc_820798C8;
	// lbz r3,19(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 19);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079754:
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079764;
	sub_82078D90(ctx, base);
	// bl 0x82078ab0
	ctx.lr = 0x82079768;
	sub_82078AB0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079778:
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079788;
	sub_82078D90(ctx, base);
	// bl 0x82078bb0
	ctx.lr = 0x8207978C;
	sub_82078BB0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8207979C:
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x820797AC;
	sub_82078D90(ctx, base);
	// bl 0x82078b30
	ctx.lr = 0x820797B0;
	sub_82078B30(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820797C0:
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x820797D0;
	sub_82078D90(ctx, base);
	// bl 0x82078c30
	ctx.lr = 0x820797D4;
	sub_82078C30(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820797E4:
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x820797F4;
	sub_82078D90(ctx, base);
	// bl 0x82078910
	ctx.lr = 0x820797F8;
	sub_82078910(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079808:
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079818;
	sub_82078D90(ctx, base);
	// bl 0x820789e0
	ctx.lr = 0x8207981C;
	sub_820789E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8207982C:
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x8207983C;
	sub_82078D90(ctx, base);
	// bl 0x82078978
	ctx.lr = 0x82079840;
	sub_82078978(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079850:
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// bl 0x82078d90
	ctx.lr = 0x82079860;
	sub_82078D90(ctx, base);
	// bl 0x82078a48
	ctx.lr = 0x82079864;
	sub_82078A48(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82079874:
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820798c4
	if (ctx.cr6.eq) goto loc_820798C4;
	// stw r4,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// bl 0x82073fa0
	ctx.lr = 0x82079890;
	sub_82073FA0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820798c8
	if (ctx.cr6.eq) goto loc_820798C8;
	// lbz r3,19(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 19);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820798B8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-7868
	ctx.r3.s64 = ctx.r11.s64 + -7868;
	// bl 0x8208c5d8
	ctx.lr = 0x820798C4;
	sub_8208C5D8(ctx, base);
loc_820798C4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820798C8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}
