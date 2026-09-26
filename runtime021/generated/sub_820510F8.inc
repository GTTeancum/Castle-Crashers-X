DEFINE_REX_FUNC(sub_820510F8) {
	REX_FUNC_PROLOGUE();
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r10,59
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 59, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// lis r12,-32251
	ctx.r12.s64 = -2113601536;
	// addi r12,r12,4388
	ctx.r12.s64 = ctx.r12.s64 + 4388;
	// rlwinm r0,r10,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r10.u32) {
	case 0:
		goto loc_82051214;
	case 1:
		goto loc_82051224;
	case 2:
		goto loc_82051234;
	case 3:
		goto loc_82051244;
	case 4:
		goto loc_82051254;
	case 5:
		goto loc_82051264;
	case 6:
		goto loc_82051274;
	case 7:
		goto loc_82051284;
	case 8:
		goto loc_82051294;
	case 9:
		goto loc_820512A4;
	case 10:
		goto loc_820512B4;
	case 11:
		goto loc_820512C4;
	case 12:
		goto loc_820512D4;
	case 13:
		goto loc_820512E4;
	case 14:
		goto loc_820512F4;
	case 15:
		goto loc_82051304;
	case 16:
		goto loc_82051314;
	case 17:
		goto loc_82051324;
	case 18:
		goto loc_82051334;
	case 19:
		goto loc_82051344;
	case 20:
		goto loc_82051354;
	case 21:
		goto loc_82051364;
	case 22:
		goto loc_82051374;
	case 23:
		goto loc_82051384;
	case 24:
		goto loc_82051394;
	case 25:
		goto loc_820513A4;
	case 26:
		goto loc_820513B4;
	case 27:
		goto loc_820513C4;
	case 28:
		goto loc_820513D4;
	case 29:
		goto loc_820513E4;
	case 30:
		goto loc_820513F4;
	case 31:
		goto loc_82051404;
	case 32:
		goto loc_82051414;
	case 33:
		goto loc_82051424;
	case 34:
		goto loc_82051434;
	case 35:
		goto loc_82051444;
	case 36:
		goto loc_82051454;
	case 37:
		goto loc_82051464;
	case 38:
		goto loc_820515C4;
	case 39:
		goto loc_82051474;
	case 40:
		goto loc_82051484;
	case 41:
		goto loc_82051494;
	case 42:
		goto loc_820514A4;
	case 43:
		goto loc_820514B4;
	case 44:
		goto loc_820514C4;
	case 45:
		goto loc_820514D4;
	case 46:
		goto loc_820514E4;
	case 47:
		goto loc_820514F4;
	case 48:
		goto loc_82051504;
	case 49:
		goto loc_82051514;
	case 50:
		goto loc_82051524;
	case 51:
		goto loc_82051534;
	case 52:
		goto loc_82051544;
	case 53:
		goto loc_82051554;
	case 54:
		goto loc_82051564;
	case 55:
		goto loc_82051574;
	case 56:
		goto loc_82051584;
	case 57:
		goto loc_82051594;
	case 58:
		goto loc_820515A4;
	case 59:
		goto loc_820515B4;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82051214:
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051224:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051234:
	// li r5,43
	ctx.r5.s64 = 43;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051244:
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051254:
	// li r5,38
	ctx.r5.s64 = 38;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051264:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051274:
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051284:
	// li r5,39
	ctx.r5.s64 = 39;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051294:
	// li r5,10
	ctx.r5.s64 = 10;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820512A4:
	// li r5,34
	ctx.r5.s64 = 34;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820512B4:
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820512C4:
	// li r5,33
	ctx.r5.s64 = 33;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820512D4:
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820512E4:
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820512F4:
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051304:
	// li r5,9
	ctx.r5.s64 = 9;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051314:
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051324:
	// li r5,11
	ctx.r5.s64 = 11;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051334:
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051344:
	// li r5,13
	ctx.r5.s64 = 13;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051354:
	// li r5,14
	ctx.r5.s64 = 14;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051364:
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051374:
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051384:
	// li r5,35
	ctx.r5.s64 = 35;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051394:
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820513A4:
	// li r5,41
	ctx.r5.s64 = 41;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820513B4:
	// li r5,42
	ctx.r5.s64 = 42;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820513C4:
	// li r5,17
	ctx.r5.s64 = 17;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820513D4:
	// li r5,18
	ctx.r5.s64 = 18;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820513E4:
	// li r5,19
	ctx.r5.s64 = 19;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820513F4:
	// li r5,20
	ctx.r5.s64 = 20;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051404:
	// li r5,21
	ctx.r5.s64 = 21;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051414:
	// li r5,22
	ctx.r5.s64 = 22;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051424:
	// li r5,23
	ctx.r5.s64 = 23;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051434:
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051444:
	// li r5,25
	ctx.r5.s64 = 25;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051454:
	// li r5,26
	ctx.r5.s64 = 26;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051464:
	// li r5,27
	ctx.r5.s64 = 27;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051474:
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051484:
	// li r5,29
	ctx.r5.s64 = 29;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051494:
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820514A4:
	// li r5,31
	ctx.r5.s64 = 31;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820514B4:
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820514C4:
	// li r5,49
	ctx.r5.s64 = 49;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820514D4:
	// li r5,44
	ctx.r5.s64 = 44;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820514E4:
	// li r5,47
	ctx.r5.s64 = 47;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820514F4:
	// li r5,45
	ctx.r5.s64 = 45;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051504:
	// li r5,46
	ctx.r5.s64 = 46;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051514:
	// li r5,48
	ctx.r5.s64 = 48;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051524:
	// li r5,50
	ctx.r5.s64 = 50;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051534:
	// li r5,43
	ctx.r5.s64 = 43;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051544:
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051554:
	// li r5,37
	ctx.r5.s64 = 37;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051564:
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051574:
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051584:
	// li r5,50
	ctx.r5.s64 = 50;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_82051594:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820515A4:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820515B4:
	// li r5,22
	ctx.r5.s64 = 22;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820b5958
	sub_820B5958(ctx, base);
	return;
loc_820515C4:
	// blr 
	return;
}
