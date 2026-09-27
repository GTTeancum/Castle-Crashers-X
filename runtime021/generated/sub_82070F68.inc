DEFINE_REX_FUNC(sub_82070F68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,129
	ctx.r4.s64 = 129;
	// addi r5,r11,-9024
	ctx.r5.s64 = ctx.r11.s64 + -9024;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8209d840
	ctx.lr = 0x82070F8C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,130
	ctx.r4.s64 = 130;
	// addi r5,r10,-9016
	ctx.r5.s64 = ctx.r10.s64 + -9016;
	// bl 0x8209d840
	ctx.lr = 0x82070F9C;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,131
	ctx.r4.s64 = 131;
	// addi r5,r9,-9004
	ctx.r5.s64 = ctx.r9.s64 + -9004;
	// bl 0x8209d840
	ctx.lr = 0x82070FAC;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,132
	ctx.r4.s64 = 132;
	// addi r5,r8,-8992
	ctx.r5.s64 = ctx.r8.s64 + -8992;
	// bl 0x8209d840
	ctx.lr = 0x82070FBC;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,133
	ctx.r4.s64 = 133;
	// addi r5,r7,-8976
	ctx.r5.s64 = ctx.r7.s64 + -8976;
	// bl 0x8209d840
	ctx.lr = 0x82070FCC;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,134
	ctx.r4.s64 = 134;
	// addi r5,r6,-8968
	ctx.r5.s64 = ctx.r6.s64 + -8968;
	// bl 0x8209d840
	ctx.lr = 0x82070FDC;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,135
	ctx.r4.s64 = 135;
	// addi r5,r5,-8956
	ctx.r5.s64 = ctx.r5.s64 + -8956;
	// bl 0x8209d840
	ctx.lr = 0x82070FEC;
	sub_8209D840(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// addi r5,r4,-8940
	ctx.r5.s64 = ctx.r4.s64 + -8940;
	// li r4,136
	ctx.r4.s64 = 136;
	// bl 0x8209d840
	ctx.lr = 0x82070FFC;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,137
	ctx.r4.s64 = 137;
	// addi r5,r11,-8928
	ctx.r5.s64 = ctx.r11.s64 + -8928;
	// bl 0x8209d840
	ctx.lr = 0x8207100C;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,138
	ctx.r4.s64 = 138;
	// addi r5,r10,-8900
	ctx.r5.s64 = ctx.r10.s64 + -8900;
	// bl 0x8209d840
	ctx.lr = 0x8207101C;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,139
	ctx.r4.s64 = 139;
	// addi r5,r9,-8884
	ctx.r5.s64 = ctx.r9.s64 + -8884;
	// bl 0x8209d840
	ctx.lr = 0x8207102C;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,140
	ctx.r4.s64 = 140;
	// addi r5,r8,-8872
	ctx.r5.s64 = ctx.r8.s64 + -8872;
	// bl 0x8209d840
	ctx.lr = 0x8207103C;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,141
	ctx.r4.s64 = 141;
	// addi r5,r7,-8864
	ctx.r5.s64 = ctx.r7.s64 + -8864;
	// bl 0x8209d840
	ctx.lr = 0x8207104C;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,142
	ctx.r4.s64 = 142;
	// addi r5,r6,-8856
	ctx.r5.s64 = ctx.r6.s64 + -8856;
	// bl 0x8209d840
	ctx.lr = 0x8207105C;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,143
	ctx.r4.s64 = 143;
	// addi r5,r5,-8836
	ctx.r5.s64 = ctx.r5.s64 + -8836;
	// bl 0x8209d840
	ctx.lr = 0x8207106C;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,144
	ctx.r4.s64 = 144;
	// addi r5,r3,-8820
	ctx.r5.s64 = ctx.r3.s64 + -8820;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209d840
	ctx.lr = 0x82071080;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,145
	ctx.r4.s64 = 145;
	// addi r5,r11,-8800
	ctx.r5.s64 = ctx.r11.s64 + -8800;
	// bl 0x8209d840
	ctx.lr = 0x82071090;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,146
	ctx.r4.s64 = 146;
	// addi r5,r10,-8784
	ctx.r5.s64 = ctx.r10.s64 + -8784;
	// bl 0x8209d840
	ctx.lr = 0x820710A0;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,147
	ctx.r4.s64 = 147;
	// addi r5,r9,-8764
	ctx.r5.s64 = ctx.r9.s64 + -8764;
	// bl 0x8209d840
	ctx.lr = 0x820710B0;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r5,r8,-8748
	ctx.r5.s64 = ctx.r8.s64 + -8748;
	// bl 0x8209d840
	ctx.lr = 0x820710C0;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,149
	ctx.r4.s64 = 149;
	// addi r5,r7,-8732
	ctx.r5.s64 = ctx.r7.s64 + -8732;
	// bl 0x8209d840
	ctx.lr = 0x820710D0;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,150
	ctx.r4.s64 = 150;
	// addi r5,r6,-8716
	ctx.r5.s64 = ctx.r6.s64 + -8716;
	// bl 0x8209d840
	ctx.lr = 0x820710E0;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,151
	ctx.r4.s64 = 151;
	// addi r5,r5,-8700
	ctx.r5.s64 = ctx.r5.s64 + -8700;
	// bl 0x8209d840
	ctx.lr = 0x820710F0;
	sub_8209D840(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// addi r5,r4,-8680
	ctx.r5.s64 = ctx.r4.s64 + -8680;
	// li r4,152
	ctx.r4.s64 = 152;
	// bl 0x8209d840
	ctx.lr = 0x82071100;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,153
	ctx.r4.s64 = 153;
	// addi r5,r11,-8660
	ctx.r5.s64 = ctx.r11.s64 + -8660;
	// bl 0x8209d840
	ctx.lr = 0x82071110;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,154
	ctx.r4.s64 = 154;
	// addi r5,r10,-8648
	ctx.r5.s64 = ctx.r10.s64 + -8648;
	// bl 0x8209d840
	ctx.lr = 0x82071120;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,155
	ctx.r4.s64 = 155;
	// addi r5,r9,-8632
	ctx.r5.s64 = ctx.r9.s64 + -8632;
	// bl 0x8209d840
	ctx.lr = 0x82071130;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,156
	ctx.r4.s64 = 156;
	// addi r5,r8,-8616
	ctx.r5.s64 = ctx.r8.s64 + -8616;
	// bl 0x8209d840
	ctx.lr = 0x82071140;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,157
	ctx.r4.s64 = 157;
	// addi r5,r7,-8600
	ctx.r5.s64 = ctx.r7.s64 + -8600;
	// bl 0x8209d840
	ctx.lr = 0x82071150;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,158
	ctx.r4.s64 = 158;
	// addi r5,r6,-8580
	ctx.r5.s64 = ctx.r6.s64 + -8580;
	// bl 0x8209d840
	ctx.lr = 0x82071160;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,159
	ctx.r4.s64 = 159;
	// addi r5,r5,-8560
	ctx.r5.s64 = ctx.r5.s64 + -8560;
	// bl 0x8209d840
	ctx.lr = 0x82071170;
	sub_8209D840(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r4,160
	ctx.r4.s64 = 160;
	// addi r5,r3,-8544
	ctx.r5.s64 = ctx.r3.s64 + -8544;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8209d840
	ctx.lr = 0x82071184;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,161
	ctx.r4.s64 = 161;
	// addi r5,r11,-8532
	ctx.r5.s64 = ctx.r11.s64 + -8532;
	// bl 0x8209d840
	ctx.lr = 0x82071194;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,162
	ctx.r4.s64 = 162;
	// addi r5,r10,-8520
	ctx.r5.s64 = ctx.r10.s64 + -8520;
	// bl 0x8209d840
	ctx.lr = 0x820711A4;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,163
	ctx.r4.s64 = 163;
	// addi r5,r9,-8496
	ctx.r5.s64 = ctx.r9.s64 + -8496;
	// bl 0x8209d840
	ctx.lr = 0x820711B4;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,164
	ctx.r4.s64 = 164;
	// addi r5,r8,-8476
	ctx.r5.s64 = ctx.r8.s64 + -8476;
	// bl 0x8209d840
	ctx.lr = 0x820711C4;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,165
	ctx.r4.s64 = 165;
	// addi r5,r7,-8460
	ctx.r5.s64 = ctx.r7.s64 + -8460;
	// bl 0x8209d840
	ctx.lr = 0x820711D4;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,166
	ctx.r4.s64 = 166;
	// addi r5,r6,-8448
	ctx.r5.s64 = ctx.r6.s64 + -8448;
	// bl 0x8209d840
	ctx.lr = 0x820711E4;
	sub_8209D840(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,167
	ctx.r4.s64 = 167;
	// addi r5,r5,-8432
	ctx.r5.s64 = ctx.r5.s64 + -8432;
	// bl 0x8209d840
	ctx.lr = 0x820711F4;
	sub_8209D840(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// addi r5,r4,-8416
	ctx.r5.s64 = ctx.r4.s64 + -8416;
	// li r4,168
	ctx.r4.s64 = 168;
	// bl 0x8209d840
	ctx.lr = 0x82071204;
	sub_8209D840(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r4,169
	ctx.r4.s64 = 169;
	// addi r5,r11,-8404
	ctx.r5.s64 = ctx.r11.s64 + -8404;
	// bl 0x8209d840
	ctx.lr = 0x82071214;
	sub_8209D840(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,170
	ctx.r4.s64 = 170;
	// addi r5,r10,-8388
	ctx.r5.s64 = ctx.r10.s64 + -8388;
	// bl 0x8209d840
	ctx.lr = 0x82071224;
	sub_8209D840(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,171
	ctx.r4.s64 = 171;
	// addi r5,r9,-8376
	ctx.r5.s64 = ctx.r9.s64 + -8376;
	// bl 0x8209d840
	ctx.lr = 0x82071234;
	sub_8209D840(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,172
	ctx.r4.s64 = 172;
	// addi r5,r8,-8360
	ctx.r5.s64 = ctx.r8.s64 + -8360;
	// bl 0x8209d840
	ctx.lr = 0x82071244;
	sub_8209D840(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,173
	ctx.r4.s64 = 173;
	// addi r5,r7,-8344
	ctx.r5.s64 = ctx.r7.s64 + -8344;
	// bl 0x8209d840
	ctx.lr = 0x82071254;
	sub_8209D840(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,174
	ctx.r4.s64 = 174;
	// addi r5,r6,-8328
	ctx.r5.s64 = ctx.r6.s64 + -8328;
	// bl 0x8209d840
	ctx.lr = 0x82071264;
	sub_8209D840(ctx, base);
	// bl 0x8206fdb8
	ctx.lr = 0x82071268;
	sub_8206FDB8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}
