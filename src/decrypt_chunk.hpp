using _BYTE = unsigned char;

inline unsigned char __ROR1__(unsigned char value, int shift)
{
	shift &= 7;
	return (value >> shift) | (value << (8 - shift));
}

// In IDA start finding from il2cpp::vm::GlobalMetadata::Initialize
//
// char __fastcall il2cpp::vm::GlobalMetadata::Initialize(_DWORD *imagesCount, _DWORD *assembliesCount)
// {
//	...
// 	...
//
// 	MetadataFile = vm::MetadataLoader::LoadMetadataFile("global-metadata.dat");
// 	s_GlobalMetadata = MetadataFile;
// 	if ( !MetadataFile )
// 		return 0;
// 	v5 = 0;
// 	v16 = 0LL;
// 	if ( !(unsigned __int8)sub_1806CF800(MetadataFile, &v16) )// <----- decryption step
void __fastcall DecryptChunk(const unsigned char* a1, size_t a2, const unsigned char* a3, unsigned char* a4, size_t a5)
{
	__int64 v9; // rsi
	unsigned int v10; // edx
	unsigned int v11; // eax
	unsigned int v12; // edx
	unsigned int v13; // eax
	__int64 v14; // r9
	__int64 v15; // rdx
	char v16; // r8
	__int64 v17; // rcx

	if (a5)
	{
		v9 = 0LL;
		if (a2)
		{
			while (2)
			{
				switch (*(_BYTE*)(v9 + a1))
				{
					case 0:
						*(_BYTE*)(0xB330B7AF % a5 + a4) = __ROR1__(*(_BYTE*)(0xB330B7AF % a5 + a4), (a3[182] + 1) & 7);
						goto LABEL_263;
					case 1:
						*(_BYTE*)(0xFE6BF3B6 % a5 + a4) = *(_BYTE*)(0xFE6BF3B6 % a5 + a4) - a3[161] + 32;
						goto LABEL_263;
					case 2:
						*(_BYTE*)(0x8CC11BA1 % a5 + a4) ^= a3[224] ^ 0x23;
						goto LABEL_263;
					case 3:
						*(_BYTE*)(0xF81D0FE0 % a5 + a4) = *(_BYTE*)(0xF81D0FE0 % a5 + a4) - a3[35] - 90;
						goto LABEL_263;
					case 4:
						*(_BYTE*)(0xFFA6EF23 % a5 + a4) = *(_BYTE*)(0xFFA6EF23 % a5 + a4) - a3[90] + 75;
						goto LABEL_263;
					case 5:
						*(_BYTE*)(0x26201D5A % a5 + a4) = *(_BYTE*)(0x26201D5A % a5 + a4) - a3[181] + 92;
						goto LABEL_263;
					case 6:
						*(_BYTE*)(0x6DA02EB5 % a5 + a4) ^= a3[164] ^ 0xD7;
						goto LABEL_263;
					case 7:
						*(_BYTE*)(0xCFCD26A4 % a5 + a4) = __ROR1__(*(_BYTE*)(0xCFCD26A4 % a5 + a4), (a3[215] - 2) & 7);
						goto LABEL_263;
					case 8:
						*(_BYTE*)(0x82EEBAD7 % a5 + a4) = *(_BYTE*)(0x82EEBAD7 % a5 + a4) - a3[62] - 9;
						goto LABEL_263;
					case 9:
						*(_BYTE*)(0x11808A3E % a5 + a4) = __ROR1__(*(_BYTE*)(0x11808A3E % a5 + a4), a3[9] & 7);
						goto LABEL_263;
					case 0xA:
						*(_BYTE*)(0x8F177809 % a5 + a4) = __ROR1__(*(_BYTE*)(0x8F177809 % a5 + a4), (a3[168] + 3) & 7);
						goto LABEL_263;
					case 0xB:
						*(_BYTE*)(0xF6DD9AA8 % a5 + a4) ^= a3[203] ^ 0x62;
						goto LABEL_263;
					case 0xC:
						*(_BYTE*)(0xC89A6ECB % a5 + a4) ^= a3[98] ^ 0x9D;
						goto LABEL_263;
					case 0xD:
						*(_BYTE*)(0xF8263E62 % a5 + a4) = __ROR1__(*(_BYTE*)(0xF8263E62 % a5 + a4), (a3[157] - 4) & 7);
						goto LABEL_263;
					case 0xE:
						v10 = 0xFB6BEB9D % a5;
						v11 = (unsigned __int8)a3[236] + 1614192383;
						goto LABEL_261;
					case 0xF:
						*(_BYTE*)(0x7B4F8FEC % a5 + a4) = *(_BYTE*)(0x7B4F8FEC % a5 + a4) - a3[255] + 58;
						goto LABEL_263;
					case 0x10:
						*(_BYTE*)(0x60369EFF % a5 + a4) ^= a3[198] ^ 0x71;
						goto LABEL_263;
					case 0x11:
						*(_BYTE*)(0x3EBB7DC6 % a5 + a4) = *(_BYTE*)(0x3EBB7DC6 % a5 + a4) - a3[113] - 112;
						goto LABEL_263;
					case 0x12:
						v12 = 0x8AAEBD71 % a5;
						v13 = (unsigned __int8)a3[112] + 259923827;
						goto LABEL_23;
					case 0x13:
						v10 = 0x2BF6A70 % a5;
						v11 = (unsigned __int8)a3[115] - 1335899030;
						goto LABEL_261;
					case 0x14:
						*(_BYTE*)(0xF7E1F73 % a5 + a4) = __ROR1__(*(_BYTE*)(0xF7E1F73 % a5 + a4), (a3[106] - 3) & 7);
						goto LABEL_263;
					case 0x15:
						*(_BYTE*)(0xB05FCC6A % a5 + a4) = *(_BYTE*)(0xB05FCC6A % a5 + a4) - a3[133] - 52;
						goto LABEL_263;
					case 0x16:
						v10 = 0xC6916185 % a5;
						v11 = (unsigned __int8)a3[52] - 187825113;
						goto LABEL_261;
					case 0x17:
						*(_BYTE*)(0x6EE8CE34 % a5 + a4) = *(_BYTE*)(0x6EE8CE34 % a5 + a4) - a3[39] - 78;
						goto LABEL_263;
					case 0x18:
						v12 = 0xF4CE0427 % a5;
						v13 = (unsigned __int8)a3[78] + 1081707481;
						goto LABEL_23;
					case 0x19:
						*(_BYTE*)(0xE74BEE4E % a5 + a4) ^= a3[217] ^ 0x38;
						goto LABEL_263;
					case 0x1A:
						v12 = 0x40798BD9 % a5;
						v13 = (unsigned __int8)a3[56] - 1378246373;
						goto LABEL_23;
					case 0x1B:
						v10 = 0x2B6A9F38 % a5;
						v11 = (unsigned __int8)a3[27] - 1464473742;
						goto LABEL_261;
					case 0x1C:
						*(_BYTE*)(0xADD9A11B % a5 + a4) = *(_BYTE*)(0xADD9A11B % a5 + a4) - a3[114] - 109;
						goto LABEL_263;
					case 0x1D:
						*(_BYTE*)(0xA8B5E772 % a5 + a4) = __ROR1__(*(_BYTE*)(0xA8B5E772 % a5 + a4), (a3[109] - 4) & 7);
						goto LABEL_263;
					case 0x1E:
						v12 = 0xDD5306D % a5;
						v13 = (unsigned __int8)a3[124] - 694252977;
						goto LABEL_23;
					case 0x1F:
						*(_BYTE*)(0x8CB017C % a5 + a4) = __ROR1__(*(_BYTE*)(0x8CB017C % a5 + a4), (a3[79] - 2) & 7);
						goto LABEL_263;
					case 0x20:
						v12 = 0xD69E8A4F % a5;
						v13 = (unsigned __int8)a3[214] + 1588495169;
						goto LABEL_23;
					case 0x21:
						*(_BYTE*)(0x37F4FBD6 % a5 + a4) -= a3[65];
						goto LABEL_263;
					case 0x22:
						*(_BYTE*)(0x5EAE8341 % a5 + a4) = __ROR1__(*(_BYTE*)(0x5EAE8341 % a5 + a4), (*a3 + 3) & 7);
						goto LABEL_263;
					case 0x23:
						*(_BYTE*)(0xC8BB5900 % a5 + a4) = __ROR1__(*(_BYTE*)(0xC8BB5900 % a5 + a4), (a3[195] + 2) & 7);
						goto LABEL_263;
					case 0x24:
						*(_BYTE*)(0x749893C3 % a5 + a4) = __ROR1__(*(_BYTE*)(0x749893C3 % a5 + a4), (a3[122] - 3) & 7);
						goto LABEL_263;
					case 0x25:
						*(_BYTE*)(0xE4E5AF7A % a5 + a4) = *(_BYTE*)(0xE4E5AF7A % a5 + a4) - a3[85] + 60;
						goto LABEL_263;
					case 0x26:
						*(_BYTE*)(0x627FF855 % a5 + a4) ^= a3[196] ^ 0x77;
						goto LABEL_263;
					case 0x27:
						*(_BYTE*)(0xBF9C49C4 % a5 + a4) = __ROR1__(*(_BYTE*)(0xBF9C49C4 % a5 + a4), (a3[119] - 2) & 7);
						goto LABEL_263;
					case 0x28:
						v12 = 0x2235D177 % a5;
						v13 = (unsigned __int8)a3[94] - 280476759;
						goto LABEL_23;
					case 0x29:
						*(_BYTE*)(0x598DC65E % a5 + a4) = *(_BYTE*)(0x598DC65E % a5 + a4) - a3[169] + 56;
						goto LABEL_263;
					case 0x2A:
						*(_BYTE*)(0xEF4843A9 % a5 + a4) ^= a3[200] ^ 0x6B;
						goto LABEL_263;
					case 0x2B:
						v10 = 0x2F41B7C8 % a5;
						v11 = (unsigned __int8)a3[107] + 1795179650;
						goto LABEL_261;
					case 0x2C:
						v10 = 0xE8A976B % a5;
						v11 = (unsigned __int8)a3[130] - 1629595331;
						goto LABEL_261;
					case 0x2D:
						*(_BYTE*)(0x6B004482 % a5 + a4) ^= a3[61] ^ 0xC;
						goto LABEL_263;
					case 0x2E:
						*(_BYTE*)(0x9EDE593D % a5 + a4) ^= a3[12] ^ 0x9F;
						goto LABEL_263;
					case 0x2F:
						*(_BYTE*)(0x3EF6C70C % a5 + a4) ^= a3[159] ^ 0xE6;
						goto LABEL_263;
					case 0x30:
						*(_BYTE*)(0x2545799F % a5 + a4) ^= a3[230] ^ 0x11;
						goto LABEL_263;
					case 0x31:
						*(_BYTE*)(0x71816DE6 % a5 + a4) = __ROR1__(*(_BYTE*)(0x71816DE6 % a5 + a4), a3[17] & 7);
						goto LABEL_263;
					case 0x32:
						*(_BYTE*)(0x56856D11 % a5 + a4) = *(_BYTE*)(0x56856D11 % a5 + a4) - a3[144] - 19;
						goto LABEL_263;
					case 0x33:
						*(_BYTE*)(0xB4C1DB90 % a5 + a4) = *(_BYTE*)(0xB4C1DB90 % a5 + a4) - a3[19] + 118;
						goto LABEL_263;
					case 0x34:
						*(_BYTE*)(0xF2E34C13 % a5 + a4) ^= a3[138] ^ 0x25;
						goto LABEL_263;
					case 0x35:
						*(_BYTE*)(0x6BEAC68A % a5 + a4) = *(_BYTE*)(0x6BEAC68A % a5 + a4) - a3[37] - 84;
						goto LABEL_263;
					case 0x36:
						*(_BYTE*)(0x6CC0F325 % a5 + a4) = __ROR1__(*(_BYTE*)(0x6CC0F325 % a5 + a4), (a3[84] - 1) & 7);
						goto LABEL_263;
					case 0x37:
						v10 = 0xD3E89954 % a5;
						v11 = (unsigned __int8)a3[199] + 1917784686;
						goto LABEL_261;
					case 0x38:
						*(_BYTE*)(0x192322C7 % a5 + a4) ^= a3[110] ^ 0x79;
						goto LABEL_263;
					case 0x39:
						*(_BYTE*)(0x724F126E % a5 + a4) ^= a3[121] ^ 0x58;
						goto LABEL_263;
					case 0x3A:
						v12 = 0xE1689F79 % a5;
						v13 = (unsigned __int8)a3[88] + 1740263867;
						goto LABEL_23;
					case 0x3B:
						*(_BYTE*)(0x4B3E458 % a5 + a4) = *(_BYTE*)(0x4B3E458 % a5 + a4) - a3[187] + 110;
						goto LABEL_263;
					case 0x3C:
						*(_BYTE*)(0x67BA51BB % a5 + a4) = __ROR1__(*(_BYTE*)(0x67BA51BB % a5 + a4), (a3[146] - 3) & 7);
						goto LABEL_263;
					case 0x3D:
						*(_BYTE*)(0x3BDE5592 % a5 + a4) = __ROR1__(*(_BYTE*)(0x3BDE5592 % a5 + a4), (a3[13] - 4) & 7);
						goto LABEL_263;
					case 0x3E:
						v10 = 0x5BFC660D % a5;
						v11 = (unsigned __int8)a3[156] - 314020625;
						goto LABEL_261;
					case 0x3F:
						v10 = 0x2973E09C % a5;
						v11 = (unsigned __int8)a3[239] - 1140206602;
						goto LABEL_261;
					case 0x40:
						v12 = 0xED486CEF % a5;
						v13 = (unsigned __int8)a3[246] - 466060575;
						goto LABEL_23;
					case 0x41:
						*(_BYTE*)(0xBC09D3F6 % a5 + a4) = *(_BYTE*)(0xBC09D3F6 % a5 + a4) - a3[225] - 32;
						goto LABEL_263;
					case 0x42:
						*(_BYTE*)(0xE4387AE1 % a5 + a4) = *(_BYTE*)(0xE4387AE1 % a5 + a4) - a3[32] - 99;
						goto LABEL_263;
					case 0x43:
						*(_BYTE*)(0xC4C3F220 % a5 + a4) = __ROR1__(*(_BYTE*)(0xC4C3F220 % a5 + a4), (a3[99] + 2) & 7);
						goto LABEL_263;
					case 0x44:
						*(_BYTE*)(0x948B4863 % a5 + a4) = *(_BYTE*)(0x948B4863 % a5 + a4) - a3[154] + 11;
						goto LABEL_263;
					case 0x45:
						*(_BYTE*)(0x1AE8119A % a5 + a4) ^= a3[245] ^ 0xE4;
						goto LABEL_263;
					case 0x46:
						v12 = 0x88E951F5 % a5;
						v13 = (unsigned __int8)a3[228] + 567474199;
						goto LABEL_23;
					case 0x47:
						*(_BYTE*)(0x550EBCE4 % a5 + a4) = __ROR1__(*(_BYTE*)(0x550EBCE4 % a5 + a4), (a3[23] - 2) & 7);
						goto LABEL_263;
					case 0x48:
						*(_BYTE*)(0x21D2F817 % a5 + a4) ^= a3[126] ^ 0x49;
						goto LABEL_263;
					case 0x49:
						*(_BYTE*)(0x8CD8D27E % a5 + a4) ^= a3[73] ^ 0xE8;
						goto LABEL_263;
					case 0x4A:
						*(_BYTE*)(0x68FF9F49 % a5 + a4) = __ROR1__(*(_BYTE*)(0x68FF9F49 % a5 + a4), (a3[232] + 3) & 7);
						goto LABEL_263;
					case 0x4B:
						v10 = 0x895224E8 % a5;
						v11 = (unsigned __int8)a3[11] - 848749918;
						goto LABEL_261;
					case 0x4C:
						*(_BYTE*)(0xA4B5D00B % a5 + a4) = *(_BYTE*)(0xA4B5D00B % a5 + a4) - a3[162] + 35;
						goto LABEL_263;
					case 0x4D:
						v10 = 0xCD691AA2 % a5;
						v11 = (unsigned __int8)a3[221] + 857951788;
						goto LABEL_261;
					case 0x4E:
						*(_BYTE*)(0xD2E456DD % a5 + a4) = __ROR1__(*(_BYTE*)(0xD2E456DD % a5 + a4), (a3[44] - 1) & 7);
						goto LABEL_263;
					case 0x4F:
						v12 = 0x33234E2C % a5;
						v13 = (unsigned __int8)a3[63] + 1098329606;
						goto LABEL_23;
					case 0x50:
						*(_BYTE*)(0xB204643F % a5 + a4) ^= a3[6] ^ 0xB1;
						goto LABEL_263;
					case 0x51:
						v12 = 0x41772E06 % a5;
						v13 = (unsigned __int8)a3[177] + 435330224;
						goto LABEL_23;
					case 0x52:
						*(_BYTE*)(0x6E0CACB1 % a5 + a4) ^= a3[176] ^ 0xB3;
						goto LABEL_263;
					case 0x53:
						*(_BYTE*)(0x19F29CB0 % a5 + a4) = *(_BYTE*)(0x19F29CB0 % a5 + a4) - a3[179] + 86;
						goto LABEL_263;
					case 0x54:
						*(_BYTE*)(0xF9FD88B3 % a5 + a4) = *(_BYTE*)(0xF9FD88B3 % a5 + a4) - a3[170] + 59;
						goto LABEL_263;
					case 0x55:
						*(_BYTE*)(0x49690AA % a5 + a4) = __ROR1__(*(_BYTE*)(0x49690AA % a5 + a4), (a3[197] - 4) & 7);
						goto LABEL_263;
					case 0x56:
						v10 = 0xA2CE14C5 % a5;
						v11 = (unsigned __int8)a3[116] + 247615847;
						goto LABEL_261;
					case 0x57:
						v12 = 0x138FB474 % a5;
						v13 = (unsigned __int8)a3[103] + 1706296974;
						goto LABEL_23;
					case 0x58:
						*(_BYTE*)(0xEC25167 % a5 + a4) ^= a3[142] ^ 0x19;
						goto LABEL_263;
					case 0x59:
						v12 = 0x65B4068E % a5;
						v13 = (unsigned __int8)a3[25] + 99449208;
						goto LABEL_23;
					case 0x5A:
						v10 = 0xB4724319 % a5;
						v11 = (unsigned __int8)a3[120] + 1862931035;
						goto LABEL_261;
					case 0x5B:
						*(_BYTE*)(0x5ED7978 % a5 + a4) = __ROR1__(*(_BYTE*)(0x5ED7978 % a5 + a4), (a3[91] + 2) & 7);
						goto LABEL_263;
					case 0x5C:
						*(_BYTE*)(0x6F0A125B % a5 + a4) = *(_BYTE*)(0x6F0A125B % a5 + a4) - a3[178] + 83;
						goto LABEL_263;
					case 0x5D:
						v12 = 0x96F993B2 % a5;
						v13 = (unsigned __int8)a3[173] - 1239019588;
						goto LABEL_23;
					case 0x5E:
						*(_BYTE*)(0x418B2BAD % a5 + a4) ^= a3[188] ^ 0x8F;
						goto LABEL_263;
					case 0x5F:
						*(_BYTE*)(0xB6260FBC % a5 + a4) = __ROR1__(*(_BYTE*)(0xB6260FBC % a5 + a4), (a3[143] - 2) & 7);
						goto LABEL_263;
					case 0x60:
						*(_BYTE*)(0x29165F8F % a5 + a4) ^= a3[22] ^ 0x81;
						goto LABEL_263;
					case 0x61:
						v12 = 0x94F27C16 % a5;
						v13 = (unsigned __int8)a3[129] - 2000757952;
						goto LABEL_23;
					case 0x62:
						*(_BYTE*)(0x1E870281 % a5 + a4) = *(_BYTE*)(0x1E870281 % a5 + a4) - a3[64] - 3;
						goto LABEL_263;
					case 0x63:
						*(_BYTE*)(0x88BEDB40 % a5 + a4) = *(_BYTE*)(0x88BEDB40 % a5 + a4) - a3[3] + 70;
						goto LABEL_263;
					case 0x64:
						*(_BYTE*)(0xA9E70D03 % a5 + a4) = *(_BYTE*)(0xA9E70D03 % a5 + a4) - a3[186] + 107;
						goto LABEL_263;
					case 0x65:
						*(_BYTE*)(0x88EF43BA % a5 + a4) = __ROR1__(*(_BYTE*)(0x88EF43BA % a5 + a4), (a3[149] - 4) & 7);
						goto LABEL_263;
					case 0x66:
						*(_BYTE*)(0xBE843B95 % a5 + a4) = *(_BYTE*)(0xBE843B95 % a5 + a4) - a3[4] + 73;
						goto LABEL_263;
					case 0x67:
						v12 = 0x972C8004 % a5;
						v13 = (unsigned __int8)a3[183] + 715763358;
						goto LABEL_23;
					case 0x68:
						*(_BYTE*)(0x8CAE2EB7 % a5 + a4) ^= a3[158] ^ 0xE9;
						goto LABEL_263;
					case 0x69:
						v10 = 0x2AA9AE9E % a5;
						v11 = (unsigned __int8)a3[233] - 1097407992;
						goto LABEL_261;
					case 0x6A:
						v12 = 0x9E658AE9 % a5;
						v13 = (unsigned __int8)a3[8] + 2122586283;
						goto LABEL_23;
					case 0x6B:
						v12 = 0xBE96E208 % a5;
						v13 = (unsigned __int8)a3[171] - 450314046;
						goto LABEL_23;
					case 0x6C:
						*(_BYTE*)(0x7E8418AB % a5 + a4) ^= a3[194] ^ 0x7D;
						goto LABEL_263;
					case 0x6D:
						*(_BYTE*)(0xE528C0C2 % a5 + a4) = __ROR1__(*(_BYTE*)(0xE528C0C2 % a5 + a4), (a3[125] - 4) & 7);
						goto LABEL_263;
					case 0x6E:
						v12 = 0x6625E47D % a5;
						v13 = (unsigned __int8)a3[76] - 1973723425;
						goto LABEL_23;
					case 0x6F:
						*(_BYTE*)(0x8BDD254C % a5 + a4) ^= a3[223] ^ 0x26;
						goto LABEL_263;
					case 0x70:
						v10 = 0x8A5B5EDF % a5;
						v11 = (unsigned __int8)a3[38] - 1267958703;
						goto LABEL_261;
					case 0x71:
						v12 = 0xC2E4BE26 % a5;
						v13 = (unsigned __int8)a3[81] + 685354448;
						goto LABEL_23;
					case 0x72:
						*(_BYTE*)(0xB46C7C51 % a5 + a4) = *(_BYTE*)(0xB46C7C51 % a5 + a4) - a3[208] - 83;
						goto LABEL_263;
					case 0x73:
						*(_BYTE*)(0x28D9ADD0 % a5 + a4) ^= a3[83] ^ 0xCA;
						goto LABEL_263;
					case 0x74:
						v12 = 0x6134D553 % a5;
						v13 = (unsigned __int8)a3[202] - 933181851;
						goto LABEL_23;
					case 0x75:
						v12 = 0x652B2ACA % a5;
						v13 = (unsigned __int8)a3[101] - 1360650348;
						goto LABEL_23;
					case 0x76:
						*(_BYTE*)(0xC860C665 % a5 + a4) ^= a3[148] ^ 7;
						goto LABEL_263;
					case 0x77:
						v12 = 0xAEE61F94 % a5;
						v13 = (unsigned __int8)a3[7] - 1966945618;
						goto LABEL_23;
					case 0x78:
						*(_BYTE*)(0x72939007 % a5 + a4) ^= a3[174] ^ 0xB9;
						goto LABEL_263;
					case 0x79:
						v12 = 0x8AC2CAAE % a5;
						v13 = (unsigned __int8)a3[185] - 2103484776;
						goto LABEL_23;
					case 0x7A:
						v10 = 0x7DBE76B9 % a5;
						v11 = (unsigned __int8)a3[152] - 382672133;
						goto LABEL_261;
					case 0x7B:
						v12 = 0x829F5E98 % a5;
						v13 = (unsigned __int8)a3[251] - 372268590;
						goto LABEL_23;
					case 0x7C:
						v12 = 0xE930E2FB % a5;
						v13 = (unsigned __int8)a3[210] + 1328120141;
						goto LABEL_23;
					case 0x7D:
						*(_BYTE*)(0xE9CFA1D2 % a5 + a4) ^= a3[77] ^ 0xDC;
						goto LABEL_263;
					case 0x7E:
						v12 = 0x4F29814D % a5;
						v13 = (unsigned __int8)a3[220] - 537894353;
						goto LABEL_23;
					case 0x7F:
						*(_BYTE*)(0x9CE98EDC % a5 + a4) = *(_BYTE*)(0x9CE98EDC % a5 + a4) - a3[47] - 54;
						goto LABEL_263;
					case 0x80:
						*(_BYTE*)(0xDFF0622F % a5 + a4) = *(_BYTE*)(0xDFF0622F % a5 + a4) - a3[54] - 33;
						goto LABEL_263;
					case 0x81:
						*(_BYTE*)(0x60F6F436 % a5 + a4) = *(_BYTE*)(0x60F6F436 % a5 + a4) - a3[33] - 96;
						goto LABEL_263;
					case 0x82:
						v12 = 0x52C21A21 % a5;
						v13 = (unsigned __int8)a3[96] + 1662247331;
						goto LABEL_23;
					case 0x83:
						*(_BYTE*)(0xE5341460 % a5 + a4) ^= a3[163] ^ 0xDA;
						goto LABEL_263;
					case 0x84:
						*(_BYTE*)(0x6313E1A3 % a5 + a4) ^= a3[218] ^ 0x35;
						goto LABEL_263;
					case 0x85:
						v10 = 0xC3C345DA % a5;
						v11 = (unsigned __int8)a3[53] + 16618276;
						goto LABEL_261;
					case 0x86:
						*(_BYTE*)(0x64F8B535 % a5 + a4) = *(_BYTE*)(0x64F8B535 % a5 + a4) - a3[36] - 87;
						goto LABEL_263;
					case 0x87:
						v10 = 0xFD9324 % a5;
						v11 = (unsigned __int8)a3[87] - 968336706;
						goto LABEL_261;
					case 0x88:
						v10 = 0x11AF7557 % a5;
						v11 = (unsigned __int8)a3[190] - 173930871;
						goto LABEL_261;
					case 0x89:
						*(_BYTE*)(0xC6485ABE % a5 + a4) = *(_BYTE*)(0xC6485ABE % a5 + a4) - a3[137] - 40;
						goto LABEL_263;
					case 0x8A:
						*(_BYTE*)(0xF5A20689 % a5 + a4) = *(_BYTE*)(0xF5A20689 % a5 + a4) - a3[40] - 75;
						goto LABEL_263;
					case 0x8B:
						*(_BYTE*)(0x3C97EF28 % a5 + a4) ^= a3[75] ^ 0xE2;
						goto LABEL_263;
					case 0x8C:
						*(_BYTE*)(0x735D714B % a5 + a4) ^= a3[226] ^ 0x1D;
						goto LABEL_263;
					case 0x8D:
						*(_BYTE*)(0xCC0736E2 % a5 + a4) ^= a3[29] ^ 0x6C;
						goto LABEL_263;
					case 0x8E:
						*(_BYTE*)(0x2B4B021D % a5 + a4) = *(_BYTE*)(0x2B4B021D % a5 + a4) - a3[108] - 127;
						goto LABEL_263;
					case 0x8F:
						*(_BYTE*)(0x712C4C6C % a5 + a4) = *(_BYTE*)(0x712C4C6C % a5 + a4) - a3[127] - 70;
						goto LABEL_263;
					case 0x90:
						*(_BYTE*)(0x5632697F % a5 + a4) = __ROR1__(*(_BYTE*)(0x5632697F % a5 + a4), (a3[70] + 1) & 7);
						goto LABEL_263;
					case 0x91:
						*(_BYTE*)(0x9E121E46 % a5 + a4) = *(_BYTE*)(0x9E121E46 % a5 + a4) - a3[241] + 16;
						goto LABEL_263;
					case 0x92:
						v12 = 0x50CCDBF1 % a5;
						v13 = (unsigned __int8)a3[240] - 923717133;
						goto LABEL_23;
					case 0x93:
						*(_BYTE*)(0xBFF0EF0 % a5 + a4) = *(_BYTE*)(0xBFF0EF0 % a5 + a4) - a3[243] + 22;
						goto LABEL_263;
					case 0x94:
						*(_BYTE*)(0xC8F131F3 % a5 + a4) = __ROR1__(*(_BYTE*)(0xC8F131F3 % a5 + a4), (a3[234] - 3) & 7);
						goto LABEL_263;
					case 0x95:
						*(_BYTE*)(0x4C7094EA % a5 + a4) ^= a3[5] ^ 0xB4;
						goto LABEL_263;
					case 0x96:
						v12 = 0xC1210805 % a5;
						v13 = (unsigned __int8)a3[180] - 2055283033;
						goto LABEL_23;
					case 0x97:
						*(_BYTE*)(0x9AF3DAB4 % a5 + a4) ^= a3[167] ^ 0xCE;
						goto LABEL_263;
					case 0x98:
						*(_BYTE*)(0x857EDEA7 % a5 + a4) = __ROR1__(*(_BYTE*)(0x857EDEA7 % a5 + a4), (a3[206] + 1) & 7);
						goto LABEL_263;
					case 0x99:
						*(_BYTE*)(0xBEC35ECE % a5 + a4) ^= a3[89] ^ 0xB8;
						goto LABEL_263;
					case 0x9A:
						v12 = 0xC5753A59 % a5;
						v13 = (unsigned __int8)a3[184] - 543767653;
						goto LABEL_23;
					case 0x9B:
						*(_BYTE*)(0x825193B8 % a5 + a4) ^= a3[155] ^ 0xF2;
						goto LABEL_263;
					case 0x9C:
						*(_BYTE*)(0xDF96C39B % a5 + a4) = *(_BYTE*)(0xDF96C39B % a5 + a4) - a3[242] + 19;
						goto LABEL_263;
					case 0x9D:
						v10 = 0xB8287FF2 % a5;
						v11 = (unsigned __int8)a3[237] - 1077518852;
						goto LABEL_261;
					case 0x9E:
						v12 = 0x197F66ED % a5;
						v13 = (unsigned __int8)a3[252] - 1950452529;
						goto LABEL_23;
					case 0x9F:
						v12 = 0xBFC65DFC % a5;
						v13 = (unsigned __int8)a3[207] + 1381973078;
						goto LABEL_23;
					case 0xA0:
						*(_BYTE*)(0x8BBE74CF % a5 + a4) = *(_BYTE*)(0x8BBE74CF % a5 + a4) - a3[86] + 63;
						goto LABEL_263;
					case 0xA1:
						*(_BYTE*)(0x525F3C56 % a5 + a4) = __ROR1__(*(_BYTE*)(0x525F3C56 % a5 + a4), a3[193] & 7);
						goto LABEL_263;
					case 0xA2:
						v10 = 0xA11C1C1 % a5;
						v11 = (unsigned __int8)a3[128] - 763771325;
						goto LABEL_261;
					case 0xA3:
						v12 = 0xDEAB9D80 % a5;
						v13 = (unsigned __int8)a3[67] + 875304954;
						goto LABEL_23;
					case 0xA4:
						v12 = 0xD279C643 % a5;
						v13 = (unsigned __int8)a3[250] + 1643036373;
						goto LABEL_23;
					case 0xA5:
						v12 = 0x342C17FA % a5;
						v13 = (unsigned __int8)a3[213] - 2121664956;
						goto LABEL_23;
					case 0xA6:
						*(_BYTE*)(0x61EEBED5 % a5 + a4) = *(_BYTE*)(0x61EEBED5 % a5 + a4) - a3[68] + 9;
						goto LABEL_263;
					case 0xA7:
						*(_BYTE*)(0x8189F644 % a5 + a4) = __ROR1__(*(_BYTE*)(0x8189F644 % a5 + a4), (a3[247] - 2) & 7);
						goto LABEL_263;
					case 0xA8:
						v12 = 0x3BECBF7 % a5;
						v13 = (unsigned __int8)a3[222] - 1730342359;
						goto LABEL_23;
					case 0xA9:
						*(_BYTE*)(0x6FCD6DE % a5 + a4) ^= a3[41] ^ 0x48;
						goto LABEL_263;
					case 0xAA:
						v12 = 0x98DD1229 % a5;
						v13 = (unsigned __int8)a3[72] + 1051318763;
						goto LABEL_23;
					case 0xAB:
						*(_BYTE*)(0x24DD4C48 % a5 + a4) = __ROR1__(*(_BYTE*)(0x24DD4C48 % a5 + a4), (a3[235] + 2) & 7);
						goto LABEL_263;
					case 0xAC:
						v10 = 0x3EA9D9EB % a5;
						v11 = (unsigned __int8)a3[2] - 117723203;
						goto LABEL_261;
					case 0xAD:
						*(_BYTE*)(0xEFCC7D02 % a5 + a4) ^= a3[189] ^ 0x8C;
						goto LABEL_263;
					case 0xAE:
						v12 = 0xF8FBAFBD % a5;
						v13 = (unsigned __int8)a3[140] - 512654305;
						goto LABEL_23;
					case 0xAF:
						*(_BYTE*)(0xFF18C38C % a5 + a4) ^= a3[31] ^ 0x66;
						goto LABEL_263;
					case 0xB0:
						v12 = 0xE171841F % a5;
						v13 = (unsigned __int8)a3[102] - 1370109039;
						goto LABEL_23;
					case 0xB1:
						*(_BYTE*)(0xF474E66 % a5 + a4) = __ROR1__(*(_BYTE*)(0xF474E66 % a5 + a4), a3[145] & 7);
						goto LABEL_263;
					case 0xB2:
						*(_BYTE*)(0xAE55CB91 % a5 + a4) = *(_BYTE*)(0xAE55CB91 % a5 + a4) - a3[16] + 109;
						goto LABEL_263;
					case 0xB3:
						*(_BYTE*)(0x21EAC010 % a5 + a4) = *(_BYTE*)(0x21EAC010 % a5 + a4) - a3[147] - 10;
						goto LABEL_263;
					case 0xB4:
						v10 = 0x359A9E93 % a5;
						v11 = (unsigned __int8)a3[10] - 189343323;
						goto LABEL_261;
					case 0xB5:
						*(_BYTE*)(0x4D2ECF0A % a5 + a4) ^= a3[165] ^ 0xD4;
						goto LABEL_263;
					case 0xB6:
						v10 = 0xF4B6D9A5 % a5;
						v11 = (unsigned __int8)a3[212] + 745291079;
						goto LABEL_261;
					case 0xB7:
						*(_BYTE*)(0x40C0E5D4 % a5 + a4) ^= a3[71] ^ 0xEE;
						goto LABEL_263;
					case 0xB8:
						v12 = 0x2C6C3D47 % a5;
						v13 = (unsigned __int8)a3[238] - 675377671;
						goto LABEL_23;
					case 0xB9:
						v10 = 0xF2FDC2EE % a5;
						v11 = (unsigned __int8)a3[249] - 1064560424;
						goto LABEL_261;
					case 0xBA:
						*(_BYTE*)(0xD7BE8DF9 % a5 + a4) = __ROR1__(*(_BYTE*)(0xD7BE8DF9 % a5 + a4), (a3[216] + 3) & 7);
						goto LABEL_263;
					case 0xBB:
						v10 = 0xC08C18D8 % a5;
						v11 = (unsigned __int8)a3[59] - 640930286;
						goto LABEL_261;
					case 0xBC:
						*(_BYTE*)(0x3FA3B43B % a5 + a4) ^= a3[18] ^ 0x8D;
						goto LABEL_263;
					case 0xBD:
						v10 = 0xD9CC2E12 % a5;
						v11 = (unsigned __int8)a3[141] - 188449508;
						goto LABEL_261;
					case 0xBE:
						*(_BYTE*)(0x3934DC8D % a5 + a4) ^= a3[28] ^ 0x6F;
						goto LABEL_263;
					case 0xBF:
						*(_BYTE*)(0xF4C47D1C % a5 + a4) ^= a3[111] ^ 0x76;
						goto LABEL_263;
					case 0xC0:
						*(_BYTE*)(0xCA68976F % a5 + a4) ^= a3[118] ^ 0x61;
						goto LABEL_263;
					case 0xC1:
						v12 = 0x2F735476 % a5;
						v13 = (unsigned __int8)a3[97] - 1381140832;
						goto LABEL_23;
					case 0xC2:
						v12 = 0x119DF961 % a5;
						v13 = (unsigned __int8)a3[160] + 1853930211;
						goto LABEL_23;
					case 0xC3:
						*(_BYTE*)(0xADAD76A0 % a5 + a4) = __ROR1__(*(_BYTE*)(0xADAD76A0 % a5 + a4), (a3[227] + 2) & 7);
						goto LABEL_263;
					case 0xC4:
						*(_BYTE*)(0x6E80BAE3 % a5 + a4) ^= a3[26] ^ 0x75;
						goto LABEL_263;
					case 0xC5:
						*(_BYTE*)(0x16F1BA1A % a5 + a4) = __ROR1__(*(_BYTE*)(0x16F1BA1A % a5 + a4), (a3[117] - 4) & 7);
						goto LABEL_263;
					case 0xC6:
						*(_BYTE*)(0x1F0E5875 % a5 + a4) = *(_BYTE*)(0x1F0E5875 % a5 + a4) - a3[100] + 105;
						goto LABEL_263;
					case 0xC7:
						*(_BYTE*)(0x7BD9A964 % a5 + a4) ^= a3[151] ^ 0xFE;
						goto LABEL_263;
					case 0xC8:
						*(_BYTE*)(0x59C43297 % a5 + a4) ^= a3[254] ^ 0xC9;
						goto LABEL_263;
					case 0xC9:
						*(_BYTE*)(0xA80F22FE % a5 + a4) = __ROR1__(*(_BYTE*)(0xA80F22FE % a5 + a4), a3[201] & 7);
						goto LABEL_263;
					case 0xCA:
						*(_BYTE*)(0x763EADC9 % a5 + a4) = *(_BYTE*)(0x763EADC9 % a5 + a4) - a3[104] + 117;
						goto LABEL_263;
					case 0xCB:
						*(_BYTE*)(0x4CEEF968 % a5 + a4) = *(_BYTE*)(0x4CEEF968 % a5 + a4) - a3[139] - 34;
						goto LABEL_263;
					case 0xCC:
						*(_BYTE*)(0x7FD1528B % a5 + a4) = __ROR1__(*(_BYTE*)(0x7FD1528B % a5 + a4), (a3[34] - 3) & 7);
						goto LABEL_263;
					case 0xCD:
						v10 = 0x12409322 % a5;
						v11 = (unsigned __int8)a3[93] + 1168804524;
						goto LABEL_261;
					case 0xCE:
						v10 = 0xA9DFED5D % a5;
						v11 = (unsigned __int8)a3[172] + 469806783;
						goto LABEL_261;
					case 0xCF:
						v12 = 0x45AA8AAC % a5;
						v13 = (unsigned __int8)a3[191] - 422818170;
						goto LABEL_23;
					case 0xD0:
						v10 = 0x1C00AEBF % a5;
						v11 = (unsigned __int8)a3[134] + 2083474225;
						goto LABEL_261;
					case 0xD1:
						*(_BYTE*)(0xE6CC4E86 % a5 + a4) = __ROR1__(*(_BYTE*)(0xE6CC4E86 % a5 + a4), a3[49] & 7);
						goto LABEL_263;
					case 0xD2:
						v12 = 0x7C2F4B31 % a5;
						v13 = (unsigned __int8)a3[48] + 261692211;
						goto LABEL_23;
					case 0xD3:
						*(_BYTE*)(0xFD24C130 % a5 + a4) = *(_BYTE*)(0xFD24C130 % a5 + a4) - a3[51] - 42;
						goto LABEL_263;
					case 0xD4:
						*(_BYTE*)(0xF991B33 % a5 + a4) ^= a3[42] ^ 0x45;
						goto LABEL_263;
					case 0xD5:
						*(_BYTE*)(0xCE2DD92A % a5 + a4) ^= a3[69] ^ 0xF4;
						goto LABEL_263;
					case 0xD6:
						*(_BYTE*)(0x4ECA3B45 % a5 + a4) = *(_BYTE*)(0x4ECA3B45 % a5 + a4) - a3[244] + 25;
						goto LABEL_263;
					case 0xD7:
						*(_BYTE*)(0x7D5540F4 % a5 + a4) ^= a3[231] ^ 0xE;
						goto LABEL_263;
					case 0xD8:
						v12 = 0xF043ABE7 % a5;
						v13 = (unsigned __int8)a3[14] - 993889895;
						goto LABEL_23;
					case 0xD9:
						v12 = 0x2CB9F70E % a5;
						v13 = (unsigned __int8)a3[153] - 1395200520;
						goto LABEL_23;
					case 0xDA:
						*(_BYTE*)(0xC4C27199 % a5 + a4) = __ROR1__(*(_BYTE*)(0xC4C27199 % a5 + a4), (a3[248] + 3) & 7);
						goto LABEL_263;
					case 0xDB:
						*(_BYTE*)(0xACD6EDF8 % a5 + a4) ^= a3[219] ^ 0x32;
						goto LABEL_263;
					case 0xDC:
						*(_BYTE*)(0xDABFB4DB % a5 + a4) = *(_BYTE*)(0xDABFB4DB % a5 + a4) - a3[50] - 45;
						goto LABEL_263;
					case 0xDD:
						*(_BYTE*)(0x7A82AC32 % a5 + a4) = *(_BYTE*)(0x7A82AC32 % a5 + a4) - a3[45] - 60;
						goto LABEL_263;
					case 0xDE:
						v12 = 0x4AF1E22D % a5;
						v13 = (unsigned __int8)a3[60] + 1574357519;
						goto LABEL_23;
					case 0xDF:
						*(_BYTE*)(0x5EBEC3C % a5 + a4) = __ROR1__(*(_BYTE*)(0x5EBEC3C % a5 + a4), (a3[15] - 2) & 7);
						goto LABEL_263;
					case 0xE0:
						*(_BYTE*)(0x5DD6CA0F % a5 + a4) = *(_BYTE*)(0x5DD6CA0F % a5 + a4) - a3[150] - 1;
						goto LABEL_263;
					case 0xE1:
						*(_BYTE*)(0x527B3C96 % a5 + a4) = *(_BYTE*)(0x527B3C96 % a5 + a4) - a3[1] + 64;
						goto LABEL_263;
					case 0xE2:
						*(_BYTE*)(0x7A8EC101 % a5 + a4) = __ROR1__(*(_BYTE*)(0x7A8EC101 % a5 + a4), (a3[192] + 3) & 7);
						goto LABEL_263;
					case 0xE3:
						*(_BYTE*)(0xBEC19FC0 % a5 + a4) ^= a3[131] ^ 0x3A;
						goto LABEL_263;
					case 0xE4:
						v12 = 0x1190BF83 % a5;
						v13 = (unsigned __int8)a3[58] - 1979743723;
						goto LABEL_23;
					case 0xE5:
						*(_BYTE*)(0x7CDC2C3A % a5 + a4) = __ROR1__(*(_BYTE*)(0x7CDC2C3A % a5 + a4), (a3[21] - 4) & 7);
						goto LABEL_263;
					case 0xE6:
						v12 = 0x89FF8215 % a5;
						v13 = (unsigned __int8)a3[132] - 1364743881;
						goto LABEL_23;
					case 0xE7:
						*(_BYTE*)(0xC6F4AC84 % a5 + a4) = *(_BYTE*)(0xC6F4AC84 % a5 + a4) - a3[55] - 30;
						goto LABEL_263;
					case 0xE8:
						v12 = 0xAEA7A937 % a5;
						v13 = (unsigned __int8)a3[30] + 1072617833;
						goto LABEL_23;
					case 0xE9:
						*(_BYTE*)(0x78C73F1E % a5 + a4) = *(_BYTE*)(0x78C73F1E % a5 + a4) - a3[105] + 120;
						goto LABEL_263;
					case 0xEA:
						*(_BYTE*)(0x3FEED969 % a5 + a4) ^= a3[136] ^ 0x2B;
						goto LABEL_263;
					case 0xEB:
						v10 = 0x3E54F688 % a5;
						v11 = (unsigned __int8)a3[43] + 1227585858;
						goto LABEL_261;
					case 0xEC:
						v12 = 0xBA3BDB2B % a5;
						v13 = (unsigned __int8)a3[66] + 480230141;
						goto LABEL_23;
					case 0xED:
						v12 = 0x492B7942 % a5;
						v13 = (unsigned __int8)a3[253] + 1223270860;
						goto LABEL_23;
					case 0xEE:
						v10 = 0x1C9FBAFD % a5;
						v11 = (unsigned __int8)a3[204] + 432531807;
						goto LABEL_261;
					case 0xEF:
						v12 = 0x48E9A1CC % a5;
						v13 = (unsigned __int8)a3[95] - 1997988186;
						goto LABEL_23;
					case 0xF0:
						*(_BYTE*)(0x19C7E95F % a5 + a4) = *(_BYTE*)(0x19C7E95F % a5 + a4) - a3[166] + 47;
						goto LABEL_263;
					case 0xF1:
						*(_BYTE*)(0x88E91EA6 % a5 + a4) ^= a3[209] ^ 0x50;
						goto LABEL_263;
					case 0xF2:
						v10 = 0xAD815AD1 % a5;
						v11 = (unsigned __int8)a3[80] + 592750547;
						goto LABEL_261;
					case 0xF3:
						*(_BYTE*)(0x64351250 % a5 + a4) ^= a3[211] ^ 0x4A;
						goto LABEL_263;
					case 0xF4:
						*(_BYTE*)(0x2354A7D3 % a5 + a4) = *(_BYTE*)(0x2354A7D3 % a5 + a4) - a3[74] + 27;
						goto LABEL_263;
					case 0xF5:
						*(_BYTE*)(0xA35B34A % a5 + a4) = *(_BYTE*)(0xA35B34A % a5 + a4) - a3[229] - 20;
						goto LABEL_263;
					case 0xF6:
						v10 = 0x3F032CE5 % a5;
						v11 = (unsigned __int8)a3[20] - 34788729;
						goto LABEL_261;
					case 0xF7:
						*(_BYTE*)(0xA1B8EC14 % a5 + a4) = *(_BYTE*)(0xA1B8EC14 % a5 + a4) - a3[135] - 46;
						goto LABEL_263;
					case 0xF8:
						*(_BYTE*)(0xFDED2A87 % a5 + a4) = __ROR1__(*(_BYTE*)(0xFDED2A87 % a5 + a4), (a3[46] + 1) & 7);
						goto LABEL_263;
					case 0xF9:
						*(_BYTE*)(0x853FFB2E % a5 + a4) = *(_BYTE*)(0x853FFB2E % a5 + a4) - a3[57] - 24;
						goto LABEL_263;
					case 0xFA:
						v10 = 0x60A8E539 % a5;
						v11 = (unsigned __int8)a3[24] + 1716700539;
						goto LABEL_261;
					case 0xFB:
						v12 = 0x6ABA1318 % a5;
						v13 = (unsigned __int8)a3[123] + 437516882;
					LABEL_23:
						v14 = v12;
						v15 = v13 % a5;
						v16 = *(_BYTE*)(v15 + a4) - 1;
						*(_BYTE*)(v14 + a4) -= v16;
						goto LABEL_262;
					case 0xFC:
						*(_BYTE*)(0x6652C57B % a5 + a4) ^= a3[82] ^ 0xCD;
						goto LABEL_263;
					case 0xFD:
						*(_BYTE*)(0x1A13FA52 % a5 + a4) ^= a3[205] ^ 0x5C;
						goto LABEL_263;
					case 0xFE:
						*(_BYTE*)(0xEF5E77CD % a5 + a4) = __ROR1__(*(_BYTE*)(0xEF5E77CD % a5 + a4), (a3[92] - 1) & 7);
						goto LABEL_263;
					case 0xFF:
						v10 = 0xB144AB5C % a5;
						v11 = (unsigned __int8)a3[175] - 1447103306;
					LABEL_261:
						v17 = v10;
						v15 = v11 % a5;
						v16 = *(_BYTE*)(v17 + a4);
						*(_BYTE*)(v17 + a4) = *(_BYTE*)(v15 + a4);
					LABEL_262:
						*(_BYTE*)(v15 + a4) = v16;
					LABEL_263:
						if (++v9 >= a2)
							return;
						continue;
				}
			}
		}
	}
}