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
						*(_BYTE*)(0xCEDF1960 % a5 + a4) = __ROR1__(*(_BYTE*)(0xCEDF1960 % a5 + a4), (a3[163] + 2) & 7);
						goto LABEL_263;
					case 1:
						*(_BYTE*)(0x2266D2A3 % a5 + a4) ^= a3[218] ^ 0x35;
						goto LABEL_263;
					case 2:
						*(_BYTE*)(0x60CE72DA % a5 + a4) ^= a3[53] ^ 0x24;
						goto LABEL_263;
					case 3:
						*(_BYTE*)(0xCCB2E35 % a5 + a4) = __ROR1__(*(_BYTE*)(0xCCB2E35 % a5 + a4), (a3[36] - 1) & 7);
						goto LABEL_263;
					case 4:
						*(_BYTE*)(0x5CAA2824 % a5 + a4) = __ROR1__(*(_BYTE*)(0x5CAA2824 % a5 + a4), (a3[87] - 2) & 7);
						goto LABEL_263;
					case 5:
						*(_BYTE*)(0x953DB657 % a5 + a4) = __ROR1__(*(_BYTE*)(0x953DB657 % a5 + a4), (a3[190] + 1) & 7);
						goto LABEL_263;
					case 6:
						v12 = 0xC7E197BE % a5;
						v13 = (unsigned __int8)a3[137] - 1748823000;
					LABEL_23:
						v14 = v12;
						v15 = v13 % a5;
						v16 = *(_BYTE*)(v15 + a4) - 1;
						*(_BYTE*)(v14 + a4) -= v16;
						goto LABEL_262;
					case 7:
						*(_BYTE*)(0x5C0A4F89 % a5 + a4) = __ROR1__(*(_BYTE*)(0x5C0A4F89 % a5 + a4), (a3[40] + 3) & 7);
						goto LABEL_263;
					case 8:
						*(_BYTE*)(0x97C31428 % a5 + a4) ^= a3[75] ^ 0xE2;
						goto LABEL_263;
					case 9:
						v12 = 0x46B0024B % a5;
						v13 = (unsigned __int8)a3[226] - 535160035;
						goto LABEL_23;
					case 0xA:
						*(_BYTE*)(0xF39383E2 % a5 + a4) = *(_BYTE*)(0xF39383E2 % a5 + a4) - a3[29] - 108;
						goto LABEL_263;
					case 0xB:
						v12 = 0xE01A1B1D % a5;
						v13 = (unsigned __int8)a3[108] + 1872906879;
						goto LABEL_23;
					case 0xC:
						v10 = 0xA063016C % a5;
						v11 = (unsigned __int8)a3[127] - 1400472762;
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
					case 0xD:
						*(_BYTE*)(0x6FA24A7F % a5 + a4) = *(_BYTE*)(0x6FA24A7F % a5 + a4) - a3[70] + 15;
						goto LABEL_263;
					case 0xE:
						v12 = 0xAC867B46 % a5;
						v13 = (unsigned __int8)a3[241] + 1608406000;
						goto LABEL_23;
					case 0xF:
						*(_BYTE*)(0x2523C4F1 % a5 + a4) = __ROR1__(*(_BYTE*)(0x2523C4F1 % a5 + a4), (a3[240] + 3) & 7);
						goto LABEL_263;
					case 0x10:
						*(_BYTE*)(0x5FDE53F0 % a5 + a4) = __ROR1__(*(_BYTE*)(0x5FDE53F0 % a5 + a4), (a3[243] + 2) & 7);
						goto LABEL_263;
					case 0x11:
						*(_BYTE*)(0xEAA762F3 % a5 + a4) = __ROR1__(*(_BYTE*)(0xEAA762F3 % a5 + a4), (a3[234] - 3) & 7);
						goto LABEL_263;
					case 0x12:
						*(_BYTE*)(0xDF5201EA % a5 + a4) ^= a3[5] ^ 0xB4;
						goto LABEL_263;
					case 0x13:
						v10 = 0x3070C105 % a5;
						v11 = (unsigned __int8)a3[180] - 294363225;
						goto LABEL_261;
					case 0x14:
						*(_BYTE*)(0xA528AFB4 % a5 + a4) ^= a3[167] ^ 0xCE;
						goto LABEL_263;
					case 0x15:
						v12 = 0xEE745FA7 % a5;
						v13 = (unsigned __int8)a3[206] + 780059481;
						goto LABEL_23;
					case 0x16:
						*(_BYTE*)(0x3D26DBCE % a5 + a4) ^= a3[89] ^ 0xB8;
						goto LABEL_263;
					case 0x17:
						*(_BYTE*)(0x2E7EC359 % a5 + a4) = *(_BYTE*)(0x2E7EC359 % a5 + a4) - a3[184] + 101;
						goto LABEL_263;
					case 0x18:
						*(_BYTE*)(0x6A98F8B8 % a5 + a4) = __ROR1__(*(_BYTE*)(0x6A98F8B8 % a5 + a4), (a3[155] + 2) & 7);
						goto LABEL_263;
					case 0x19:
						*(_BYTE*)(0x4C94949B % a5 + a4) = *(_BYTE*)(0x4C94949B % a5 + a4) - a3[242] + 19;
						goto LABEL_263;
					case 0x1A:
						*(_BYTE*)(0x4FB30CF2 % a5 + a4) ^= a3[237] ^ 0xFC;
						goto LABEL_263;
					case 0x1B:
						v10 = 0xC753BFED % a5;
						v11 = (unsigned __int8)a3[252] - 2007132721;
						goto LABEL_261;
					case 0x1C:
						v10 = 0x28ED52FC % a5;
						v11 = (unsigned __int8)a3[207] + 71686486;
						goto LABEL_261;
					case 0x1D:
						*(_BYTE*)(0x885D95CF % a5 + a4) ^= a3[86] ^ 0xC1;
						goto LABEL_263;
					case 0x1E:
						*(_BYTE*)(0x445D956 % a5 + a4) = *(_BYTE*)(0x445D956 % a5 + a4) - a3[193] - 128;
						goto LABEL_263;
					case 0x1F:
						*(_BYTE*)(0xD11EAC1 % a5 + a4) ^= a3[128] ^ 0x43;
						goto LABEL_263;
					case 0x20:
						*(_BYTE*)(0x5B8F2280 % a5 + a4) = *(_BYTE*)(0x5B8F2280 % a5 + a4) - a3[67] + 6;
						goto LABEL_263;
					case 0x21:
						v10 = 0x5A233743 % a5;
						v11 = (unsigned __int8)a3[250] + 952874965;
						goto LABEL_261;
					case 0x22:
						*(_BYTE*)(0xF233C4FA % a5 + a4) = *(_BYTE*)(0xF233C4FA % a5 + a4) - a3[213] - 68;
						goto LABEL_263;
					case 0x23:
						v10 = 0x38CBB7D5 % a5;
						v11 = (unsigned __int8)a3[68] + 1923845367;
						goto LABEL_261;
					case 0x24:
						*(_BYTE*)(0x9A170B44 % a5 + a4) = __ROR1__(*(_BYTE*)(0x9A170B44 % a5 + a4), (a3[247] - 2) & 7);
						goto LABEL_263;
					case 0x25:
						*(_BYTE*)(0x72AB8CF7 % a5 + a4) ^= a3[222] ^ 0x29;
						goto LABEL_263;
					case 0x26:
						*(_BYTE*)(0xE07A93DE % a5 + a4) = *(_BYTE*)(0xE07A93DE % a5 + a4) - a3[41] - 72;
						goto LABEL_263;
					case 0x27:
						v10 = 0xA997DB29 % a5;
						v11 = (unsigned __int8)a3[72] - 1830622485;
						goto LABEL_261;
					case 0x28:
						*(_BYTE*)(0xEB10F148 % a5 + a4) ^= a3[235] ^ 2;
						goto LABEL_263;
					case 0x29:
						*(_BYTE*)(0x92E2EAEB % a5 + a4) ^= a3[2] ^ 0xBD;
						goto LABEL_263;
					case 0x2A:
						*(_BYTE*)(0x4EA54A02 % a5 + a4) = __ROR1__(*(_BYTE*)(0x4EA54A02 % a5 + a4), (a3[189] - 4) & 7);
						goto LABEL_263;
					case 0x2B:
						*(_BYTE*)(0xD9E548BD % a5 + a4) = *(_BYTE*)(0xD9E548BD % a5 + a4) - a3[140] - 31;
						goto LABEL_263;
					case 0x2C:
						*(_BYTE*)(0x33FFF88C % a5 + a4) = __ROR1__(*(_BYTE*)(0x33FFF88C % a5 + a4), (a3[31] - 2) & 7);
						goto LABEL_263;
					case 0x2D:
						v10 = 0x4BCFE51F % a5;
						v11 = (unsigned __int8)a3[102] + 1057961105;
						goto LABEL_261;
					case 0x2E:
						*(_BYTE*)(0x4F02B66 % a5 + a4) = __ROR1__(*(_BYTE*)(0x4F02B66 % a5 + a4), a3[145] & 7);
						goto LABEL_263;
					case 0x2F:
						v10 = 0x3F0F3491 % a5;
						v11 = (unsigned __int8)a3[16] - 87601261;
						goto LABEL_261;
					case 0x30:
						*(_BYTE*)(0xEAA28510 % a5 + a4) = __ROR1__(*(_BYTE*)(0xEAA28510 % a5 + a4), (a3[147] + 2) & 7);
						goto LABEL_263;
					case 0x31:
						*(_BYTE*)(0xFAC74F93 % a5 + a4) ^= a3[10] ^ 0xA5;
						goto LABEL_263;
					case 0x32:
						*(_BYTE*)(0xEFACBC0A % a5 + a4) ^= a3[165] ^ 0xD4;
						goto LABEL_263;
					case 0x33:
						*(_BYTE*)(0x473112A5 % a5 + a4) ^= a3[212] ^ 0x47;
						goto LABEL_263;
					case 0x34:
						*(_BYTE*)(0x6B763AD4 % a5 + a4) = __ROR1__(*(_BYTE*)(0x6B763AD4 % a5 + a4), (a3[71] - 2) & 7);
						goto LABEL_263;
					case 0x35:
						v12 = 0xD5E03E47 % a5;
						v13 = (unsigned __int8)a3[238] - 382036231;
						goto LABEL_23;
					case 0x36:
						*(_BYTE*)(0xC9E5BFEE % a5 + a4) ^= a3[249] ^ 0xD8;
						goto LABEL_263;
					case 0x37:
						*(_BYTE*)(0xE93A96F9 % a5 + a4) ^= a3[216] ^ 0x3B;
						goto LABEL_263;
					case 0x38:
						*(_BYTE*)(0x997BFDD8 % a5 + a4) = __ROR1__(*(_BYTE*)(0x997BFDD8 % a5 + a4), (a3[59] + 2) & 7);
						goto LABEL_263;
					case 0x39:
						*(_BYTE*)(0x1CA8053B % a5 + a4) ^= a3[18] ^ 0x8D;
						goto LABEL_263;
					case 0x3A:
						*(_BYTE*)(0x5B433B12 % a5 + a4) ^= a3[141] ^ 0x1C;
						goto LABEL_263;
					case 0x3B:
						*(_BYTE*)(0x7B43B58D % a5 + a4) ^= a3[28] ^ 0x6F;
						goto LABEL_263;
					case 0x3C:
						*(_BYTE*)(0xAB3BF21C % a5 + a4) ^= a3[111] ^ 0x76;
						goto LABEL_263;
					case 0x3D:
						v10 = 0xC116386F % a5;
						v11 = (unsigned __int8)a3[118] - 1021271455;
						goto LABEL_261;
					case 0x3E:
						*(_BYTE*)(0x4D2E7176 % a5 + a4) ^= a3[97] ^ 0xA0;
						goto LABEL_263;
					case 0x3F:
						v10 = 0xC320A261 % a5;
						v11 = (unsigned __int8)a3[160] + 482388963;
						goto LABEL_261;
					case 0x40:
						*(_BYTE*)(0x49097BA0 % a5 + a4) = __ROR1__(*(_BYTE*)(0x49097BA0 % a5 + a4), (a3[227] + 2) & 7);
						goto LABEL_263;
					case 0x41:
						*(_BYTE*)(0x1CC0ABE3 % a5 + a4) = *(_BYTE*)(0x1CC0ABE3 % a5 + a4) - a3[26] - 117;
						goto LABEL_263;
					case 0x42:
						*(_BYTE*)(0xDB35E71A % a5 + a4) ^= a3[117] ^ 0x64;
						goto LABEL_263;
					case 0x43:
						v12 = 0x7535D175 % a5;
						v13 = (unsigned __int8)a3[100] - 2041613417;
						goto LABEL_23;
					case 0x44:
						*(_BYTE*)(0x60873E64 % a5 + a4) = __ROR1__(*(_BYTE*)(0x60873E64 % a5 + a4), (a3[151] - 2) & 7);
						goto LABEL_263;
					case 0x45:
						*(_BYTE*)(0x864F7397 % a5 + a4) = *(_BYTE*)(0x864F7397 % a5 + a4) - a3[254] + 55;
						goto LABEL_263;
					case 0x46:
						v12 = 0xE2B15FFE % a5;
						v13 = (unsigned __int8)a3[201] + 1365974632;
						goto LABEL_23;
					case 0x47:
						*(_BYTE*)(0x958BF6C9 % a5 + a4) = __ROR1__(*(_BYTE*)(0x958BF6C9 % a5 + a4), (a3[104] + 3) & 7);
						goto LABEL_263;
					case 0x48:
						v10 = 0x516B1E68 % a5;
						v11 = (unsigned __int8)a3[139] + 363192354;
						goto LABEL_261;
					case 0x49:
						*(_BYTE*)(0xDB30E38B % a5 + a4) ^= a3[34] ^ 0x5D;
						goto LABEL_263;
					case 0x4A:
						v10 = 0x15A5E022 % a5;
						v11 = (unsigned __int8)a3[93] + 1468153772;
						goto LABEL_261;
					case 0x4B:
						v12 = 0x6F24065D % a5;
						v13 = (unsigned __int8)a3[172] + 1368231871;
						goto LABEL_23;
					case 0x4C:
						*(_BYTE*)(0x57823FAC % a5 + a4) = __ROR1__(*(_BYTE*)(0x57823FAC % a5 + a4), (a3[191] - 2) & 7);
						goto LABEL_263;
					case 0x4D:
						*(_BYTE*)(0x518D8FBF % a5 + a4) = *(_BYTE*)(0x518D8FBF % a5 + a4) - a3[134] - 49;
						goto LABEL_263;
					case 0x4E:
						v10 = 0x54E9AB86 % a5;
						v11 = (unsigned __int8)a3[49] + 1442121264;
						goto LABEL_261;
					case 0x4F:
						*(_BYTE*)(0x158B3431 % a5 + a4) = *(_BYTE*)(0x158B3431 % a5 + a4) - a3[48] - 51;
						goto LABEL_263;
					case 0x50:
						v10 = 0x55F50630 % a5;
						v11 = (unsigned __int8)a3[51] + 1971865130;
						goto LABEL_261;
					case 0x51:
						*(_BYTE*)(0x267C4C33 % a5 + a4) = *(_BYTE*)(0x267C4C33 % a5 + a4) - a3[42] - 69;
						goto LABEL_263;
					case 0x52:
						*(_BYTE*)(0x7588462A % a5 + a4) = __ROR1__(*(_BYTE*)(0x7588462A % a5 + a4), (a3[69] - 4) & 7);
						goto LABEL_263;
					case 0x53:
						*(_BYTE*)(0xA4AEF445 % a5 + a4) = __ROR1__(*(_BYTE*)(0xA4AEF445 % a5 + a4), (a3[244] - 1) & 7);
						goto LABEL_263;
					case 0x54:
						*(_BYTE*)(0x67CB15F4 % a5 + a4) ^= a3[231] ^ 0xE;
						goto LABEL_263;
					case 0x55:
						*(_BYTE*)(0xFC762CE7 % a5 + a4) = *(_BYTE*)(0xFC762CE7 % a5 + a4) - a3[14] + 103;
						goto LABEL_263;
					case 0x56:
						*(_BYTE*)(0xF566740E % a5 + a4) = *(_BYTE*)(0xF566740E % a5 + a4) - a3[153] + 8;
						goto LABEL_263;
					case 0x57:
						*(_BYTE*)(0xB2F0FA99 % a5 + a4) ^= a3[248] ^ 0xDB;
						goto LABEL_263;
					case 0x58:
						v10 = 0xD9AF52F8 % a5;
						v11 = (unsigned __int8)a3[219] + 1663449394;
						goto LABEL_261;
					case 0x59:
						*(_BYTE*)(0xFE0A85DB % a5 + a4) = *(_BYTE*)(0xFE0A85DB % a5 + a4) - a3[50] - 45;
						goto LABEL_263;
					case 0x5A:
						v10 = 0x63263932 % a5;
						v11 = (unsigned __int8)a3[45] + 1895031100;
						goto LABEL_261;
					case 0x5B:
						*(_BYTE*)(0xA97B3B2D % a5 + a4) = *(_BYTE*)(0xA97B3B2D % a5 + a4) - a3[60] - 15;
						goto LABEL_263;
					case 0x5C:
						*(_BYTE*)(0x70F3E13C % a5 + a4) = __ROR1__(*(_BYTE*)(0x70F3E13C % a5 + a4), (a3[15] - 2) & 7);
						goto LABEL_263;
					case 0x5D:
						*(_BYTE*)(0x18D2EB0F % a5 + a4) = *(_BYTE*)(0x18D2EB0F % a5 + a4) - a3[150] - 1;
						goto LABEL_263;
					case 0x5E:
						*(_BYTE*)(0x7D4AD996 % a5 + a4) ^= a3[1] ^ 0xC0;
						goto LABEL_263;
					case 0x5F:
						*(_BYTE*)(0xF6D3EA01 % a5 + a4) = __ROR1__(*(_BYTE*)(0xF6D3EA01 % a5 + a4), (a3[192] + 3) & 7);
						goto LABEL_263;
					case 0x60:
						*(_BYTE*)(0x23D624C0 % a5 + a4) = *(_BYTE*)(0x23D624C0 % a5 + a4) - a3[131] - 58;
						goto LABEL_263;
					case 0x61:
						v10 = 0xE4A73083 % a5;
						v11 = (unsigned __int8)a3[58] + 1337031445;
						goto LABEL_261;
					case 0x62:
						v10 = 0x4C9CD93A % a5;
						v11 = (unsigned __int8)a3[21] - 1492991612;
						goto LABEL_261;
					case 0x63:
						*(_BYTE*)(0x4FB17B15 % a5 + a4) = __ROR1__(*(_BYTE*)(0x4FB17B15 % a5 + a4), (a3[132] - 1) & 7);
						goto LABEL_263;
					case 0x64:
						v10 = 0xA702C184 % a5;
						v11 = (unsigned __int8)a3[55] - 1110574050;
						goto LABEL_261;
					case 0x65:
						*(_BYTE*)(0xB116A37 % a5 + a4) ^= a3[30] ^ 0x69;
						goto LABEL_263;
					case 0x66:
						*(_BYTE*)(0xBDCDFC1E % a5 + a4) = __ROR1__(*(_BYTE*)(0xBDCDFC1E % a5 + a4), a3[105] & 7);
						goto LABEL_263;
					case 0x67:
						*(_BYTE*)(0x720EA269 % a5 + a4) = __ROR1__(*(_BYTE*)(0x720EA269 % a5 + a4), (a3[136] + 3) & 7);
						goto LABEL_263;
					case 0x68:
						*(_BYTE*)(0x74599B88 % a5 + a4) = *(_BYTE*)(0x74599B88 % a5 + a4) - a3[43] - 66;
						goto LABEL_263;
					case 0x69:
						*(_BYTE*)(0x4301EC2B % a5 + a4) ^= a3[66] ^ 0xFD;
						goto LABEL_263;
					case 0x6A:
						*(_BYTE*)(0x7E5D4642 % a5 + a4) = *(_BYTE*)(0x7E5D4642 % a5 + a4) - a3[253] + 52;
						goto LABEL_263;
					case 0x6B:
						v10 = 0x1E7E53FD % a5;
						v11 = (unsigned __int8)a3[204] + 885213791;
						goto LABEL_261;
					case 0x6C:
						*(_BYTE*)(0x2EF1D6CC % a5 + a4) ^= a3[95] ^ 0xA6;
						goto LABEL_263;
					case 0x6D:
						v10 = 0x34C34A5F % a5;
						v11 = (unsigned __int8)a3[166] + 1002423249;
						goto LABEL_261;
					case 0x6E:
						*(_BYTE*)(0x20BAFBA6 % a5 + a4) ^= a3[209] ^ 0x50;
						goto LABEL_263;
					case 0x6F:
						*(_BYTE*)(0x3BBFC3D1 % a5 + a4) = *(_BYTE*)(0x3BBFC3D1 % a5 + a4) - a3[80] + 45;
						goto LABEL_263;
					case 0x70:
						*(_BYTE*)(0x885DD750 % a5 + a4) ^= a3[211] ^ 0x4A;
						goto LABEL_263;
					case 0x71:
						*(_BYTE*)(0xDA2E58D3 % a5 + a4) = __ROR1__(*(_BYTE*)(0xDA2E58D3 % a5 + a4), (a3[74] - 3) & 7);
						goto LABEL_263;
					case 0x72:
						*(_BYTE*)(0xCBACA04A % a5 + a4) = __ROR1__(*(_BYTE*)(0xCBACA04A % a5 + a4), (a3[229] - 4) & 7);
						goto LABEL_263;
					case 0x73:
						v12 = 0x589265E5 % a5;
						v13 = (unsigned __int8)a3[20] + 790506375;
						goto LABEL_23;
					case 0x74:
						*(_BYTE*)(0xB2F4114 % a5 + a4) = __ROR1__(*(_BYTE*)(0xB2F4114 % a5 + a4), (a3[135] - 2) & 7);
						goto LABEL_263;
					case 0x75:
						*(_BYTE*)(0x2F1E2B87 % a5 + a4) = __ROR1__(*(_BYTE*)(0x2F1E2B87 % a5 + a4), (a3[46] + 1) & 7);
						goto LABEL_263;
					case 0x76:
						v12 = 0xF8F0F82E % a5;
						v13 = (unsigned __int8)a3[57] + 1857746968;
						goto LABEL_23;
					case 0x77:
						*(_BYTE*)(0xFFC9EE39 % a5 + a4) ^= a3[24] ^ 0x7B;
						goto LABEL_263;
					case 0x78:
						v10 = 0x6EBAF818 % a5;
						v11 = (unsigned __int8)a3[123] + 119801682;
						goto LABEL_261;
					case 0x79:
						*(_BYTE*)(0x4624167B % a5 + a4) = *(_BYTE*)(0x4624167B % a5 + a4) - a3[82] + 51;
						goto LABEL_263;
					case 0x7A:
						v12 = 0x7240752 % a5;
						v13 = (unsigned __int8)a3[205] + 1478303836;
						goto LABEL_23;
					case 0x7B:
						*(_BYTE*)(0x92A250CD % a5 + a4) = *(_BYTE*)(0x92A250CD % a5 + a4) - a3[92] + 81;
						goto LABEL_263;
					case 0x7C:
						v10 = 0x581D205C % a5;
						v11 = (unsigned __int8)a3[175] - 1562177098;
						goto LABEL_261;
					case 0x7D:
						v12 = 0x157BADAF % a5;
						v13 = (unsigned __int8)a3[182] - 1655455327;
						goto LABEL_23;
					case 0x7E:
						*(_BYTE*)(0xA2E311B6 % a5 + a4) = *(_BYTE*)(0xA2E311B6 % a5 + a4) - a3[161] + 32;
						goto LABEL_263;
					case 0x7F:
						v10 = 0x9D53C1A1 % a5;
						v11 = (unsigned __int8)a3[224] - 1874934493;
						goto LABEL_261;
					case 0x80:
						v12 = 0xAC7D1DE0 % a5;
						v13 = (unsigned __int8)a3[35] + 1261476698;
						goto LABEL_23;
					case 0x81:
						*(_BYTE*)(0x903EC523 % a5 + a4) = __ROR1__(*(_BYTE*)(0x903EC523 % a5 + a4), (a3[90] - 3) & 7);
						goto LABEL_263;
					case 0x82:
						*(_BYTE*)(0x4B309B5A % a5 + a4) ^= a3[181] ^ 0xA4;
						goto LABEL_263;
					case 0x83:
						v12 = 0xD9E6B4B5 % a5;
						v13 = (unsigned __int8)a3[164] - 539397929;
						goto LABEL_23;
					case 0x84:
						v12 = 0xD89194A4 % a5;
						v13 = (unsigned __int8)a3[215] + 1964533822;
						goto LABEL_23;
					case 0x85:
						v12 = 0xDFD970D7 % a5;
						v13 = (unsigned __int8)a3[62] + 1430773257;
						goto LABEL_23;
					case 0x86:
						v12 = 0x7518683E % a5;
						v13 = (unsigned __int8)a3[9] - 1318819672;
						goto LABEL_23;
					case 0x87:
						v10 = 0x5547DE09 % a5;
						v11 = (unsigned __int8)a3[168] - 776076085;
						goto LABEL_261;
					case 0x88:
						v10 = 0xB16468A8 % a5;
						v11 = (unsigned __int8)a3[203] + 311655522;
						goto LABEL_261;
					case 0x89:
						v10 = 0xD1BE04CB % a5;
						v11 = (unsigned __int8)a3[98] + 1788621213;
						goto LABEL_261;
					case 0x8A:
						*(_BYTE*)(0x12937C62 % a5 + a4) = __ROR1__(*(_BYTE*)(0x12937C62 % a5 + a4), (a3[157] - 4) & 7);
						goto LABEL_263;
					case 0x8B:
						*(_BYTE*)(0x6A9C319D % a5 + a4) = *(_BYTE*)(0x6A9C319D % a5 + a4) - a3[236] + 1;
						goto LABEL_263;
					case 0x8C:
						v10 = 0xD256BDEC % a5;
						v11 = (unsigned __int8)a3[255] - 2136204346;
						goto LABEL_261;
					case 0x8D:
						v12 = 0xCD5914FF % a5;
						v13 = (unsigned __int8)a3[198] - 1999314063;
						goto LABEL_23;
					case 0x8E:
						*(_BYTE*)(0x80AC1BC6 % a5 + a4) = *(_BYTE*)(0x80AC1BC6 % a5 + a4) - a3[113] - 112;
						goto LABEL_263;
					case 0x8F:
						*(_BYTE*)(0x88D4E371 % a5 + a4) = __ROR1__(*(_BYTE*)(0x88D4E371 % a5 + a4), (a3[112] + 3) & 7);
						goto LABEL_263;
					case 0x90:
						*(_BYTE*)(0x9C64F870 % a5 + a4) ^= a3[115] ^ 0x6A;
						goto LABEL_263;
					case 0x91:
						v12 = 0xE6457573 % a5;
						v13 = (unsigned __int8)a3[106] - 159160443;
						goto LABEL_23;
					case 0x92:
						*(_BYTE*)(0x20E1CA6A % a5 + a4) = *(_BYTE*)(0x20E1CA6A % a5 + a4) - a3[133] - 52;
						goto LABEL_263;
					case 0x93:
						*(_BYTE*)(0xF6836785 % a5 + a4) = *(_BYTE*)(0xF6836785 % a5 + a4) - a3[52] - 39;
						goto LABEL_263;
					case 0x94:
						*(_BYTE*)(0x3AAABC34 % a5 + a4) ^= a3[39] ^ 0x4E;
						goto LABEL_263;
					case 0x95:
						v12 = 0xDEC03A27 % a5;
						v13 = (unsigned __int8)a3[78] + 133001689;
						goto LABEL_23;
					case 0x96:
						v12 = 0x21CD4C4E % a5;
						v13 = (unsigned __int8)a3[217] + 1344728376;
						goto LABEL_23;
					case 0x97:
						*(_BYTE*)(0x7ED71D9 % a5 + a4) = *(_BYTE*)(0x7ED71D9 % a5 + a4) - a3[56] - 27;
						goto LABEL_263;
					case 0x98:
						v10 = 0x5026ED38 % a5;
						v11 = (unsigned __int8)a3[27] + 990160242;
						goto LABEL_261;
					case 0x99:
						*(_BYTE*)(0x2E5CB71B % a5 + a4) = __ROR1__(*(_BYTE*)(0x2E5CB71B % a5 + a4), (a3[114] - 3) & 7);
						goto LABEL_263;
					case 0x9A:
						*(_BYTE*)(0x3B04A572 % a5 + a4) = *(_BYTE*)(0x3B04A572 % a5 + a4) - a3[109] - 124;
						goto LABEL_263;
					case 0x9B:
						v12 = 0x7B60F66D % a5;
						v13 = (unsigned __int8)a3[124] + 1626898511;
						goto LABEL_23;
					case 0x9C:
						v10 = 0x32BFAF7C % a5;
						v11 = (unsigned __int8)a3[79] + 1614748118;
						goto LABEL_261;
					case 0x9D:
						*(_BYTE*)(0x60F8804F % a5 + a4) = __ROR1__(*(_BYTE*)(0x60F8804F % a5 + a4), (a3[214] + 1) & 7);
						goto LABEL_263;
					case 0x9E:
						*(_BYTE*)(0x603F19D6 % a5 + a4) ^= a3[65];
						goto LABEL_263;
					case 0x9F:
						*(_BYTE*)(0xEFC82941 % a5 + a4) = *(_BYTE*)(0xEFC82941 % a5 + a4) - *a3 + 61;
						goto LABEL_263;
					case 0xA0:
						v12 = 0xD7866700 % a5;
						v13 = (unsigned __int8)a3[195] - 1346818694;
						goto LABEL_23;
					case 0xA1:
						*(_BYTE*)(0x61EF69C3 % a5 + a4) ^= a3[122] ^ 0x55;
						goto LABEL_263;
					case 0xA2:
						v10 = 0xAFB92D7A % a5;
						v11 = (unsigned __int8)a3[85] - 734283836;
						goto LABEL_261;
					case 0xA3:
						*(_BYTE*)(0xA97D7E55 % a5 + a4) = *(_BYTE*)(0xA97D7E55 % a5 + a4) - a3[196] - 119;
						goto LABEL_263;
					case 0xA4:
						v10 = 0xD43BB7C4 % a5;
						v11 = (unsigned __int8)a3[119] + 534291550;
						goto LABEL_261;
					case 0xA5:
						*(_BYTE*)(0x878F8777 % a5 + a4) ^= a3[94] ^ 0xA9;
						goto LABEL_263;
					case 0xA6:
						*(_BYTE*)(0x1FD8A45E % a5 + a4) ^= a3[169] ^ 0xC8;
						goto LABEL_263;
					case 0xA7:
						v10 = 0x195FA9A9 % a5;
						v11 = (unsigned __int8)a3[200] + 1926049131;
						goto LABEL_261;
					case 0xA8:
						*(_BYTE*)(0x1A1385C8 % a5 + a4) ^= a3[107] ^ 0x82;
						goto LABEL_263;
					case 0xA9:
						v12 = 0x72CD2D6B % a5;
						v13 = (unsigned __int8)a3[130] - 635068611;
						goto LABEL_23;
					case 0xAA:
						v12 = 0xB0108282 % a5;
						v13 = (unsigned __int8)a3[61] + 1303966988;
						goto LABEL_23;
					case 0xAB:
						*(_BYTE*)(0xDA259F3D % a5 + a4) = *(_BYTE*)(0xDA259F3D % a5 + a4) - a3[12] + 97;
						goto LABEL_263;
					case 0xAC:
						v10 = 0x4DB8F50C % a5;
						v11 = (unsigned __int8)a3[159] + 553978854;
						goto LABEL_261;
					case 0xAD:
						*(_BYTE*)(0x1736EF9F % a5 + a4) ^= a3[230] ^ 0x11;
						goto LABEL_263;
					case 0xAE:
						v12 = 0x21050BE6 % a5;
						v13 = (unsigned __int8)a3[17] - 527275632;
						goto LABEL_23;
					case 0xAF:
						*(_BYTE*)(0x17F29311 % a5 + a4) ^= a3[144] ^ 0x13;
						goto LABEL_263;
					case 0xB0:
						*(_BYTE*)(0xE0926990 % a5 + a4) = __ROR1__(*(_BYTE*)(0xE0926990 % a5 + a4), (a3[19] + 2) & 7);
						goto LABEL_263;
					case 0xB1:
						*(_BYTE*)(0x7F29A213 % a5 + a4) = __ROR1__(*(_BYTE*)(0x7F29A213 % a5 + a4), (a3[138] - 3) & 7);
						goto LABEL_263;
					case 0xB2:
						*(_BYTE*)(0x77EFC48A % a5 + a4) = __ROR1__(*(_BYTE*)(0x77EFC48A % a5 + a4), (a3[37] - 4) & 7);
						goto LABEL_263;
					case 0xB3:
						*(_BYTE*)(0x9629F925 % a5 + a4) = __ROR1__(*(_BYTE*)(0x9629F925 % a5 + a4), (a3[84] - 1) & 7);
						goto LABEL_263;
					case 0xB4:
						v10 = 0x4F458754 % a5;
						v11 = (unsigned __int8)a3[199] - 784109458;
						goto LABEL_261;
					case 0xB5:
						v10 = 0x204458C7 % a5;
						v11 = (unsigned __int8)a3[110] - 947681927;
						goto LABEL_261;
					case 0xB6:
						v10 = 0xD143706E % a5;
						v11 = (unsigned __int8)a3[121] + 695939672;
						goto LABEL_261;
					case 0xB7:
						v10 = 0xC7838579 % a5;
						v11 = (unsigned __int8)a3[88] - 736335941;
						goto LABEL_261;
					case 0xB8:
						v12 = 0x297B3258 % a5;
						v13 = (unsigned __int8)a3[187] + 1183847314;
						goto LABEL_23;
					case 0xB9:
						*(_BYTE*)(0xD41C67BB % a5 + a4) = __ROR1__(*(_BYTE*)(0xD41C67BB % a5 + a4), (a3[146] - 3) & 7);
						goto LABEL_263;
					case 0xBA:
						v10 = 0x46901392 % a5;
						v11 = (unsigned __int8)a3[13] - 958165348;
						goto LABEL_261;
					case 0xBB:
						*(_BYTE*)(0xAC5F2C0D % a5 + a4) ^= a3[156] ^ 0xEF;
						goto LABEL_263;
					case 0xBC:
						*(_BYTE*)(0xC6E38E9C % a5 + a4) = __ROR1__(*(_BYTE*)(0xC6E38E9C % a5 + a4), (a3[239] - 2) & 7);
						goto LABEL_263;
					case 0xBD:
						*(_BYTE*)(0xC93162EF % a5 + a4) = __ROR1__(*(_BYTE*)(0xC93162EF % a5 + a4), (a3[246] + 1) & 7);
						goto LABEL_263;
					case 0xBE:
						v12 = 0xEBA6F1F6 % a5;
						v13 = (unsigned __int8)a3[225] - 847642592;
						goto LABEL_23;
					case 0xBF:
						v10 = 0x6B5920E1 % a5;
						v11 = (unsigned __int8)a3[32] + 2170467;
						goto LABEL_261;
					case 0xC0:
						v12 = 0xCD7A0020 % a5;
						v13 = (unsigned __int8)a3[99] + 654217114;
						goto LABEL_23;
					case 0xC1:
						v12 = 0x211E63 % a5;
						v13 = (unsigned __int8)a3[154] - 669132811;
						goto LABEL_23;
					case 0xC2:
						*(_BYTE*)(0x26FE8F9A % a5 + a4) = __ROR1__(*(_BYTE*)(0x26FE8F9A % a5 + a4), (a3[245] - 4) & 7);
						goto LABEL_263;
					case 0xC3:
						v10 = 0xD81DD7F5 % a5;
						v11 = (unsigned __int8)a3[228] + 689679895;
						goto LABEL_261;
					case 0xC4:
						*(_BYTE*)(0xED092AE4 % a5 + a4) = __ROR1__(*(_BYTE*)(0xED092AE4 % a5 + a4), (a3[23] - 2) & 7);
						goto LABEL_263;
					case 0xC5:
						*(_BYTE*)(0x291BAE17 % a5 + a4) ^= a3[126] ^ 0x49;
						goto LABEL_263;
					case 0xC6:
						*(_BYTE*)(0xE956B07E % a5 + a4) = *(_BYTE*)(0xE956B07E % a5 + a4) - a3[73] + 24;
						goto LABEL_263;
					case 0xC7:
						*(_BYTE*)(0x5C7E0549 % a5 + a4) ^= a3[232] ^ 0xB;
						goto LABEL_263;
					case 0xC8:
						*(_BYTE*)(0x73EEF2E8 % a5 + a4) = *(_BYTE*)(0x73EEF2E8 % a5 + a4) - a3[11] + 94;
						goto LABEL_263;
					case 0xC9:
						*(_BYTE*)(0xF597660B % a5 + a4) = *(_BYTE*)(0xF597660B % a5 + a4) - a3[162] + 35;
						goto LABEL_263;
					case 0xCA:
						v10 = 0x889C58A2 % a5;
						v11 = (unsigned __int8)a3[221] - 1591706580;
						goto LABEL_261;
					case 0xCB:
						*(_BYTE*)(0xF7C29CDD % a5 + a4) = __ROR1__(*(_BYTE*)(0xF7C29CDD % a5 + a4), (a3[44] - 1) & 7);
						goto LABEL_263;
					case 0xCC:
						v10 = 0xA1207C2C % a5;
						v11 = (unsigned __int8)a3[63] + 1108200454;
						goto LABEL_261;
					case 0xCD:
						v12 = 0x3244DA3F % a5;
						v13 = (unsigned __int8)a3[6] + 1212207793;
						goto LABEL_23;
					case 0xCE:
						*(_BYTE*)(0x420DCC06 % a5 + a4) = *(_BYTE*)(0x420DCC06 % a5 + a4) - a3[177] + 80;
						goto LABEL_263;
					case 0xCF:
						*(_BYTE*)(0x4840D2B1 % a5 + a4) = __ROR1__(*(_BYTE*)(0x4840D2B1 % a5 + a4), (a3[176] + 3) & 7);
						goto LABEL_263;
					case 0xD0:
						*(_BYTE*)(0xD76E2AB0 % a5 + a4) = __ROR1__(*(_BYTE*)(0xD76E2AB0 % a5 + a4), (a3[179] + 2) & 7);
						goto LABEL_263;
					case 0xD1:
						v12 = 0x3D42DEB3 % a5;
						v13 = (unsigned __int8)a3[170] - 751953211;
						goto LABEL_23;
					case 0xD2:
						v12 = 0xA79E8EAA % a5;
						v13 = (unsigned __int8)a3[197] + 369599092;
						goto LABEL_23;
					case 0xD3:
						v12 = 0xD32E1AC5 % a5;
						v13 = (unsigned __int8)a3[116] - 1399683225;
						goto LABEL_23;
					case 0xD4:
						v10 = 0x1607A274 % a5;
						v11 = (unsigned __int8)a3[103] + 2090558606;
						goto LABEL_261;
					case 0xD5:
						*(_BYTE*)(0xAC928767 % a5 + a4) ^= a3[142] ^ 0x19;
						goto LABEL_263;
					case 0xD6:
						v10 = 0x7C9B648E % a5;
						v11 = (unsigned __int8)a3[25] + 1514129272;
						goto LABEL_261;
					case 0xD7:
						*(_BYTE*)(0xFEB42919 % a5 + a4) = *(_BYTE*)(0xFEB42919 % a5 + a4) - a3[120] - 91;
						goto LABEL_263;
					case 0xD8:
						*(_BYTE*)(0x5A3FC778 % a5 + a4) = *(_BYTE*)(0x5A3FC778 % a5 + a4) - a3[91] + 78;
						goto LABEL_263;
					case 0xD9:
						*(_BYTE*)(0x38CB285B % a5 + a4) ^= a3[178] ^ 0xAD;
						goto LABEL_263;
					case 0xDA:
						v10 = 0xC58E51B2 % a5;
						v11 = (unsigned __int8)a3[173] - 829375044;
						goto LABEL_261;
					case 0xDB:
						*(_BYTE*)(0x7244F1AD % a5 + a4) ^= a3[188] ^ 0x8F;
						goto LABEL_263;
					case 0xDC:
						v12 = 0xCE90BDBC % a5;
						v13 = (unsigned __int8)a3[143] + 258120214;
						goto LABEL_23;
					case 0xDD:
						*(_BYTE*)(0x400E558F % a5 + a4) = *(_BYTE*)(0x400E558F % a5 + a4) - a3[22] + 127;
						goto LABEL_263;
					case 0xDE:
						v10 = 0xF629A16 % a5;
						v11 = (unsigned __int8)a3[129] - 354424512;
						goto LABEL_261;
					case 0xDF:
						*(_BYTE*)(0xD12EA881 % a5 + a4) = *(_BYTE*)(0xD12EA881 % a5 + a4) - a3[64] - 3;
						goto LABEL_263;
					case 0xE0:
						*(_BYTE*)(0xEADFE940 % a5 + a4) = __ROR1__(*(_BYTE*)(0xEADFE940 % a5 + a4), (a3[3] + 2) & 7);
						goto LABEL_263;
					case 0xE1:
						v10 = 0x753BE303 % a5;
						v11 = (unsigned __int8)a3[186] + 57655701;
						goto LABEL_261;
					case 0xE2:
						*(_BYTE*)(0x31C8C1BA % a5 + a4) = __ROR1__(*(_BYTE*)(0x31C8C1BA % a5 + a4), (a3[149] - 4) & 7);
						goto LABEL_263;
					case 0xE3:
						*(_BYTE*)(0x36FC195 % a5 + a4) = *(_BYTE*)(0x36FC195 % a5 + a4) - a3[4] + 73;
						goto LABEL_263;
					case 0xE4:
						v12 = 0xEA01EE04 % a5;
						v13 = (unsigned __int8)a3[183] + 282758302;
						goto LABEL_23;
					case 0xE5:
						*(_BYTE*)(0x8F65E4B7 % a5 + a4) = *(_BYTE*)(0x8F65E4B7 % a5 + a4) - a3[158] + 23;
						goto LABEL_263;
					case 0xE6:
						v10 = 0x10DA8C9E % a5;
						v11 = (unsigned __int8)a3[233] + 947826696;
						goto LABEL_261;
					case 0xE7:
						*(_BYTE*)(0x80CAF0E9 % a5 + a4) ^= a3[8] ^ 0xAB;
						goto LABEL_263;
					case 0xE8:
						v10 = 0x387EB008 % a5;
						v11 = (unsigned __int8)a3[171] + 570359490;
						goto LABEL_261;
					case 0xE9:
						v12 = 0xD84AEAB % a5;
						v13 = (unsigned __int8)a3[194] + 1377512061;
						goto LABEL_23;
					case 0xEA:
						*(_BYTE*)(0x21FEFEC2 % a5 + a4) = *(_BYTE*)(0x21FEFEC2 % a5 + a4) - a3[125] - 76;
						goto LABEL_263;
					case 0xEB:
						*(_BYTE*)(0x521B2A7D % a5 + a4) ^= a3[76] ^ 0xDF;
						goto LABEL_263;
					case 0xEC:
						*(_BYTE*)(0xC095534C % a5 + a4) ^= a3[223] ^ 0x26;
						goto LABEL_263;
					case 0xED:
						*(_BYTE*)(0x626AD4DF % a5 + a4) = *(_BYTE*)(0x626AD4DF % a5 + a4) - a3[38] - 81;
						goto LABEL_263;
					case 0xEE:
						*(_BYTE*)(0xB80E5C26 % a5 + a4) ^= a3[81] ^ 0xD0;
						goto LABEL_263;
					case 0xEF:
						*(_BYTE*)(0xBCE7A251 % a5 + a4) = __ROR1__(*(_BYTE*)(0xBCE7A251 % a5 + a4), (a3[208] + 3) & 7);
						goto LABEL_263;
					case 0xF0:
						v12 = 0x37803BD0 % a5;
						v13 = (unsigned __int8)a3[83] + 1521887434;
						goto LABEL_23;
					case 0xF1:
						v10 = 0x1CF92B53 % a5;
						v11 = (unsigned __int8)a3[202] - 851981211;
						goto LABEL_261;
					case 0xF2:
						*(_BYTE*)(0x5AB628CA % a5 + a4) ^= a3[101] ^ 0x94;
						goto LABEL_263;
					case 0xF3:
						v12 = 0xCD37CC65 % a5;
						v13 = (unsigned __int8)a3[148] - 527251961;
						goto LABEL_23;
					case 0xF4:
						*(_BYTE*)(0xCFF90D94 % a5 + a4) = __ROR1__(*(_BYTE*)(0xCFF90D94 % a5 + a4), (a3[7] - 2) & 7);
						goto LABEL_263;
					case 0xF5:
						*(_BYTE*)(0xE092C607 % a5 + a4) ^= a3[174] ^ 0xB9;
						goto LABEL_263;
					case 0xF6:
						v10 = 0xAD1D28AE % a5;
						v11 = (unsigned __int8)a3[185] - 167990120;
						goto LABEL_261;
					case 0xF7:
						*(_BYTE*)(0x31A75CB9 % a5 + a4) ^= a3[152] ^ 0xFB;
						goto LABEL_263;
					case 0xF8:
						*(_BYTE*)(0xF5FCAC98 % a5 + a4) = *(_BYTE*)(0xF5FCAC98 % a5 + a4) - a3[251] + 46;
						goto LABEL_263;
					case 0xF9:
						v12 = 0x41D0F8FB % a5;
						v13 = (unsigned __int8)a3[210] + 498747213;
						goto LABEL_23;
					case 0xFA:
						*(_BYTE*)(0xA7C75FD2 % a5 + a4) = *(_BYTE*)(0xA7C75FD2 % a5 + a4) - a3[77] + 36;
						goto LABEL_263;
					case 0xFB:
						v10 = 0x1DBA474D % a5;
						v11 = (unsigned __int8)a3[220] - 612935633;
						goto LABEL_261;
					case 0xFC:
						*(_BYTE*)(0xF7CF3CDC % a5 + a4) = *(_BYTE*)(0xF7CF3CDC % a5 + a4) - a3[47] - 54;
						goto LABEL_263;
					case 0xFD:
						v12 = 0xDB77582F % a5;
						v13 = (unsigned __int8)a3[54] + 644923425;
						goto LABEL_23;
					case 0xFE:
						*(_BYTE*)(0x29BA1236 % a5 + a4) = __ROR1__(*(_BYTE*)(0x29BA1236 % a5 + a4), a3[33] & 7);
						goto LABEL_263;
					case 0xFF:
						v12 = 0x2670C021 % a5;
						v13 = (unsigned __int8)a3[96] + 799520675;
						goto LABEL_23;
				}
			}
		}
	}
}