#include <vector>

using namespace std;

#include "vlc_table.h"
#include "vlc_targets.h"



void VLC_MBA::initCodes(vector<string> & aarrstrVLC_init) const {
	
	aarrstrVLC_init.clear();
	aarrstrVLC_init.push_back("1");
	aarrstrVLC_init.push_back("011");
	aarrstrVLC_init.push_back("010");
	aarrstrVLC_init.push_back("0011");
	aarrstrVLC_init.push_back("0010");
	aarrstrVLC_init.push_back("00011");
	aarrstrVLC_init.push_back("00010");
	aarrstrVLC_init.push_back("0000111");
	aarrstrVLC_init.push_back("0000110");
	aarrstrVLC_init.push_back("00001011");
	aarrstrVLC_init.push_back("00001010");
	aarrstrVLC_init.push_back("00001001");
	aarrstrVLC_init.push_back("00001000");
	aarrstrVLC_init.push_back("00000111");
	aarrstrVLC_init.push_back("00000110");
	aarrstrVLC_init.push_back("0000010111");
	aarrstrVLC_init.push_back("0000010110");
	aarrstrVLC_init.push_back("0000010101");
	aarrstrVLC_init.push_back("0000010100");
	aarrstrVLC_init.push_back("0000010011");
	aarrstrVLC_init.push_back("0000010010");
	aarrstrVLC_init.push_back("00000100011");
	aarrstrVLC_init.push_back("00000100010");
	aarrstrVLC_init.push_back("00000100001");
	aarrstrVLC_init.push_back("00000100000");
	aarrstrVLC_init.push_back("00000011111");
	aarrstrVLC_init.push_back("00000011110");
	aarrstrVLC_init.push_back("00000011101");
	aarrstrVLC_init.push_back("00000011100");
	aarrstrVLC_init.push_back("00000011011");
	aarrstrVLC_init.push_back("00000011010");
	aarrstrVLC_init.push_back("00000011001");
	aarrstrVLC_init.push_back("00000011000");
	aarrstrVLC_init.push_back("00000001111");
	aarrstrVLC_init.push_back("0000000000000001");
	
}


VLC_MBA::VLC_MBA(){
	
	vector<string> arrstrVLC_init;
	initCodes(arrstrVLC_init);
	int nI;
	int nSize = arrstrVLC_init.size();
	for(nI = 0; nI < nSize; nI++){
		VLC_TableEntry entry;
		entry.m_arrnKey.push_back(nI);
		str2arrn(entry.m_arrnCode, arrstrVLC_init[nI]);
		m_tblKeyCode.push_back(entry);
	}

}

void VLC_MTYPE::initCodes(vector<string> & aarrstrVLC_init) const {
	
	aarrstrVLC_init.clear();
	aarrstrVLC_init.push_back("0001");
	aarrstrVLC_init.push_back("0000001");
	aarrstrVLC_init.push_back("1");
	aarrstrVLC_init.push_back("00001");
	aarrstrVLC_init.push_back("000000001");
	aarrstrVLC_init.push_back("00000001");
	aarrstrVLC_init.push_back("0000000001");
	aarrstrVLC_init.push_back("001");
	aarrstrVLC_init.push_back("01");
	aarrstrVLC_init.push_back("000001");
	
}

VLC_MTYPE::VLC_MTYPE(){
	
	const int Prediction = 0;
	const int MQUANT = 1;
	const int MVD = 2;
	const int CBP = 3;
	const int TCOEFF = 4;

	vector<string> arrstrVLC_init;
	initCodes(arrstrVLC_init);
	int nI;
	int nSize = arrstrVLC_init.size();
	
	for(nI = 0; nI < nSize; nI++){
		VLC_TableEntry entry;
		
		entry.m_arrnKey.resize(5);
		for(int nJ = 0; nJ < 5; nJ++)
			entry.m_arrnKey[nJ] = 0;

		switch(nI){
			case MTYPE_INTRA_TCOEFF :
				entry.m_arrnKey[Prediction] = 0;
				entry.m_arrnKey[TCOEFF] = 1;
				break;
		    case MTYPE_INTRA_MQUANT_TCOEFF :
				entry.m_arrnKey[Prediction] = 0;
				entry.m_arrnKey[MQUANT] = 1;
				entry.m_arrnKey[TCOEFF] = 1;
				break;
			case MTYPE_INTER_CBP_TCOEFF :
				entry.m_arrnKey[Prediction] = 1;
				entry.m_arrnKey[CBP] = 1;
				entry.m_arrnKey[TCOEFF] = 1;
				break;
			case MTYPE_INTER_MQUANT_CBP_TCOEFF :
				entry.m_arrnKey[Prediction] = 1;
				entry.m_arrnKey[MQUANT] = 1;
				entry.m_arrnKey[CBP] = 1;
				entry.m_arrnKey[TCOEFF] = 1;
				break;
			case MTYPE_INTERMC_MVD :
				entry.m_arrnKey[Prediction] = 3;
				entry.m_arrnKey[MVD] = 1;
				break;
			case MTYPE_INTERMC_MVD_CBP_TCOEFF :
				entry.m_arrnKey[Prediction] = 4;
				entry.m_arrnKey[MVD] = 1;
				entry.m_arrnKey[CBP] = 1;
				entry.m_arrnKey[TCOEFF] = 1;
				break;
			case MTYPE_INTERMC_MQUANT_MVD_CBP_TCOEFF :
				entry.m_arrnKey[Prediction] = 3;
				entry.m_arrnKey[MQUANT] = 1;
				entry.m_arrnKey[MVD] = 1;
				entry.m_arrnKey[CBP] = 1;
				entry.m_arrnKey[TCOEFF] = 1;
				break;
			case MTYPE_INTERMCFIL_MVD :
				entry.m_arrnKey[Prediction] = 4;
				entry.m_arrnKey[MVD] = 1;
				break;
			case MTYPE_INTERMCFIL_MVD_CBP_TCOEFF :
				entry.m_arrnKey[Prediction] = 4;
				entry.m_arrnKey[MVD] = 1;
				entry.m_arrnKey[CBP] = 1;
				entry.m_arrnKey[TCOEFF] = 1;
				break;
			case MTYPE_INTERMCFIL_MQUANT_MVD_CBP_TCOEFF :
				entry.m_arrnKey[Prediction] = 4;
				entry.m_arrnKey[MQUANT] = 1;
				entry.m_arrnKey[MVD] = 1;
				entry.m_arrnKey[CBP] = 1;
				entry.m_arrnKey[TCOEFF] = 1;
				break;
			default:
				printf("Extremly erroneous code detected\n");
				exit(-1);
		};


		str2arrn(entry.m_arrnCode, arrstrVLC_init[nI]);
		m_tblKeyCode.push_back(entry);
	}


		
	
	

}
void VLC_MVD::initCodes(vector<string> & aarrstrVLC_init) const {
	
	aarrstrVLC_init.clear();
	aarrstrVLC_init.push_back("00000011001");
	aarrstrVLC_init.push_back("00000011011");
	aarrstrVLC_init.push_back("00000011101");
	aarrstrVLC_init.push_back("00000011111");
	aarrstrVLC_init.push_back("00000100001");
	aarrstrVLC_init.push_back("00000100011");
	aarrstrVLC_init.push_back("0000010011");
	aarrstrVLC_init.push_back("0000010101");
	aarrstrVLC_init.push_back("0000010111");
	aarrstrVLC_init.push_back("00000111");
	aarrstrVLC_init.push_back("00001001");
	aarrstrVLC_init.push_back("00001011");
	aarrstrVLC_init.push_back("0000111");
	aarrstrVLC_init.push_back("00011");
	aarrstrVLC_init.push_back("0011");
	aarrstrVLC_init.push_back("011");
	aarrstrVLC_init.push_back("1");
	aarrstrVLC_init.push_back("010");
	aarrstrVLC_init.push_back("0010");
	aarrstrVLC_init.push_back("00010");
	aarrstrVLC_init.push_back("0000110");
	aarrstrVLC_init.push_back("00001010");
	aarrstrVLC_init.push_back("00001000");
	aarrstrVLC_init.push_back("00000110");
	aarrstrVLC_init.push_back("0000010110");
	aarrstrVLC_init.push_back("0000010100");
	aarrstrVLC_init.push_back("0000010010");
	aarrstrVLC_init.push_back("00000100010");
	aarrstrVLC_init.push_back("00000100000");
	aarrstrVLC_init.push_back("00000011110");
	aarrstrVLC_init.push_back("00000011100");
	aarrstrVLC_init.push_back("00000011010");

}

VLC_MVD::VLC_MVD(){
	
	
	vector<string> arrstrVLC_init;
	initCodes(arrstrVLC_init);
	int nI;
	int nSize = arrstrVLC_init.size();
	
	for(nI = 0; nI < nSize; nI++){
		VLC_TableEntry entry;
		
		entry.m_arrnKey.push_back(nI - 16);
		if(nI < 15)
			entry.m_arrnKey.push_back(nI + 16);
		if(nI > 17)
			entry.m_arrnKey.push_back(nI - 48);
	
		str2arrn(entry.m_arrnCode, arrstrVLC_init[nI]);
		m_tblKeyCode.push_back(entry);
	}


		
	
	

}



void VLC_CBP::initCodes(vector<string> & aarrstrVLC_init) const {

	aarrstrVLC_init.clear();
	aarrstrVLC_init.push_back("111");
	aarrstrVLC_init.push_back("1101");
	aarrstrVLC_init.push_back("1100");
	aarrstrVLC_init.push_back("1011");
	aarrstrVLC_init.push_back("1010");
	aarrstrVLC_init.push_back("10011");
	aarrstrVLC_init.push_back("10010");
	aarrstrVLC_init.push_back("10001");
	aarrstrVLC_init.push_back("10000");
	aarrstrVLC_init.push_back("01111");
	aarrstrVLC_init.push_back("01110");
	aarrstrVLC_init.push_back("01101");
	aarrstrVLC_init.push_back("01100");
	aarrstrVLC_init.push_back("01011");
	aarrstrVLC_init.push_back("01010");
	aarrstrVLC_init.push_back("01001");
	aarrstrVLC_init.push_back("01000");
	aarrstrVLC_init.push_back("001111");
	aarrstrVLC_init.push_back("001110");
	aarrstrVLC_init.push_back("001101");
	aarrstrVLC_init.push_back("001100");
	aarrstrVLC_init.push_back("0010111");
	aarrstrVLC_init.push_back("0010110");
	aarrstrVLC_init.push_back("0010101");
	aarrstrVLC_init.push_back("0010100");
	aarrstrVLC_init.push_back("0010011");
	aarrstrVLC_init.push_back("0010010");
	aarrstrVLC_init.push_back("0010001");
	aarrstrVLC_init.push_back("0010000");
	aarrstrVLC_init.push_back("00011111");
	aarrstrVLC_init.push_back("00011110");
	aarrstrVLC_init.push_back("00011101");
	aarrstrVLC_init.push_back("00011100");
	aarrstrVLC_init.push_back("00011011");
	aarrstrVLC_init.push_back("00011010");
	aarrstrVLC_init.push_back("00011001");
	aarrstrVLC_init.push_back("00011000");
	aarrstrVLC_init.push_back("00010111");
	aarrstrVLC_init.push_back("00010110");
	aarrstrVLC_init.push_back("00010101");
	aarrstrVLC_init.push_back("00010100");
	aarrstrVLC_init.push_back("00010011");
	aarrstrVLC_init.push_back("00010010");
	aarrstrVLC_init.push_back("00010001");
	aarrstrVLC_init.push_back("00010000");
	aarrstrVLC_init.push_back("00001111");
	aarrstrVLC_init.push_back("00001110");
	aarrstrVLC_init.push_back("00001101");
	aarrstrVLC_init.push_back("00001100");
	aarrstrVLC_init.push_back("00001011");
	aarrstrVLC_init.push_back("00001010");
	aarrstrVLC_init.push_back("00001001");
	aarrstrVLC_init.push_back("00001000");
	aarrstrVLC_init.push_back("00000111");
	aarrstrVLC_init.push_back("00000110");
	aarrstrVLC_init.push_back("00000101");
	aarrstrVLC_init.push_back("00000100");
	aarrstrVLC_init.push_back("000000111");
	aarrstrVLC_init.push_back("000000110");
	aarrstrVLC_init.push_back("000000101");
	aarrstrVLC_init.push_back("000000100");
	aarrstrVLC_init.push_back("000000011");
	aarrstrVLC_init.push_back("000000010");

}

VLC_CBP::VLC_CBP(){
	
	int arrnKeyVals[] = {60,  4,  8, 16, 32, 12, 48, 20, 40, 28, 
		                 44, 52, 56,  1, 61,  2, 62, 24, 36,  3,
						 63,  5,  9, 17, 33,  6, 10, 18, 34,  7,
						 11, 19, 35, 13, 49, 21, 41, 14, 50, 22,
						 42, 15, 51, 23, 43, 25, 37, 26, 38, 29,
						 45, 53, 57, 30, 46, 54, 58, 31, 47, 55,
						 59, 27, 39};

	vector<string> arrstrVLC_init;
	initCodes(arrstrVLC_init);
	int nI;
	int nSize = arrstrVLC_init.size();
	
	for(nI = 0; nI < nSize; nI++){
		VLC_TableEntry entry;
		
		entry.m_arrnKey.push_back(arrnKeyVals[nI]);
		str2arrn(entry.m_arrnCode, arrstrVLC_init[nI]);
		m_tblKeyCode.push_back(entry);
	}


		
	
	

}





void VLC_TCOEFF::initCodes(vector<string> & aarrstrVLC_init) const {
	
	aarrstrVLC_init.clear();
	aarrstrVLC_init.push_back("10");
	aarrstrVLC_init.push_back("10");
	aarrstrVLC_init.push_back("11");
	aarrstrVLC_init.push_back("110");
	aarrstrVLC_init.push_back("111");
	aarrstrVLC_init.push_back("01000");
	aarrstrVLC_init.push_back("01001");
	aarrstrVLC_init.push_back("001010");
	aarrstrVLC_init.push_back("001011");
	aarrstrVLC_init.push_back("00001100");
	aarrstrVLC_init.push_back("00001101");
	aarrstrVLC_init.push_back("001001100");
	aarrstrVLC_init.push_back("001001101");
	aarrstrVLC_init.push_back("001000010");
	aarrstrVLC_init.push_back("001000011");
	aarrstrVLC_init.push_back("00000010100");
	aarrstrVLC_init.push_back("00000010101");
	aarrstrVLC_init.push_back("0000000111010");
	aarrstrVLC_init.push_back("0000000111011");
	aarrstrVLC_init.push_back("0000000110000");
	aarrstrVLC_init.push_back("0000000110001");
	aarrstrVLC_init.push_back("0000000100110");
	aarrstrVLC_init.push_back("0000000100111");
	aarrstrVLC_init.push_back("0000000100000");
	aarrstrVLC_init.push_back("0000000100001");
	aarrstrVLC_init.push_back("00000000110100");
	aarrstrVLC_init.push_back("00000000110101");
	aarrstrVLC_init.push_back("00000000110010");
	aarrstrVLC_init.push_back("00000000110011");
	aarrstrVLC_init.push_back("00000000110000");
	aarrstrVLC_init.push_back("00000000110001");
	aarrstrVLC_init.push_back("00000000101110");
	aarrstrVLC_init.push_back("00000000101111");
	aarrstrVLC_init.push_back("0110");
	aarrstrVLC_init.push_back("0111");
	aarrstrVLC_init.push_back("0001100");
	aarrstrVLC_init.push_back("0001101");
	aarrstrVLC_init.push_back("001001010");
	aarrstrVLC_init.push_back("001001011");
	aarrstrVLC_init.push_back("00000011000");
	aarrstrVLC_init.push_back("00000011001");
	aarrstrVLC_init.push_back("0000000110110");
	aarrstrVLC_init.push_back("0000000110111");
	aarrstrVLC_init.push_back("00000000101100");
	aarrstrVLC_init.push_back("00000000101101");
	aarrstrVLC_init.push_back("00000000101010");
	aarrstrVLC_init.push_back("00000000101011");
	aarrstrVLC_init.push_back("01010");
	aarrstrVLC_init.push_back("01011");
	aarrstrVLC_init.push_back("00001000");
	aarrstrVLC_init.push_back("00001001");
	aarrstrVLC_init.push_back("00000010110");
	aarrstrVLC_init.push_back("00000010111");
	aarrstrVLC_init.push_back("0000000101000");
	aarrstrVLC_init.push_back("0000000101001");
	aarrstrVLC_init.push_back("00000000101000");
	aarrstrVLC_init.push_back("00000000101001");
    aarrstrVLC_init.push_back("001110");
	aarrstrVLC_init.push_back("001111");
	aarrstrVLC_init.push_back("001001000");
	aarrstrVLC_init.push_back("001001001");
	aarrstrVLC_init.push_back("0000000111000");
	aarrstrVLC_init.push_back("0000000111001");
	aarrstrVLC_init.push_back("00000000100110");
	aarrstrVLC_init.push_back("00000000100111");
	aarrstrVLC_init.push_back("001100");
	aarrstrVLC_init.push_back("001101");
	aarrstrVLC_init.push_back("00000011110");
	aarrstrVLC_init.push_back("00000011111");
	aarrstrVLC_init.push_back("0000000100100");
	aarrstrVLC_init.push_back("0000000100101");
	aarrstrVLC_init.push_back("0001110");
	aarrstrVLC_init.push_back("0001111");
	aarrstrVLC_init.push_back("00000010010");
	aarrstrVLC_init.push_back("00000010011");
	aarrstrVLC_init.push_back("00000000100100");
	aarrstrVLC_init.push_back("00000000100101");
	aarrstrVLC_init.push_back("0001010");
	aarrstrVLC_init.push_back("0001011");
	aarrstrVLC_init.push_back("0000000111100");
	aarrstrVLC_init.push_back("0000000111101");
	aarrstrVLC_init.push_back("0001000");
	aarrstrVLC_init.push_back("0001001");
	aarrstrVLC_init.push_back("0000000101010");
	aarrstrVLC_init.push_back("0000000101011");
	aarrstrVLC_init.push_back("00001110");
	aarrstrVLC_init.push_back("00001111");
	aarrstrVLC_init.push_back("0000000100010");
	aarrstrVLC_init.push_back("0000000100011");
	aarrstrVLC_init.push_back("00001010");
	aarrstrVLC_init.push_back("00001011");
	aarrstrVLC_init.push_back("00000000100010");
	aarrstrVLC_init.push_back("00000000100011");
	aarrstrVLC_init.push_back("001001110");
	aarrstrVLC_init.push_back("001001111");
	aarrstrVLC_init.push_back("00000000100000");
	aarrstrVLC_init.push_back("00000000100001");
	aarrstrVLC_init.push_back("001000110");
	aarrstrVLC_init.push_back("001000111");
	aarrstrVLC_init.push_back("001000100");
	aarrstrVLC_init.push_back("001000101");
	aarrstrVLC_init.push_back("001000000");
	aarrstrVLC_init.push_back("001000001");
	aarrstrVLC_init.push_back("00000011100");
	aarrstrVLC_init.push_back("00000011101");
	aarrstrVLC_init.push_back("00000011010");
	aarrstrVLC_init.push_back("00000011011");
	aarrstrVLC_init.push_back("00000010000");
	aarrstrVLC_init.push_back("00000010001");
	aarrstrVLC_init.push_back("0000000111110");
	aarrstrVLC_init.push_back("0000000111111");
	aarrstrVLC_init.push_back("0000000110100");
	aarrstrVLC_init.push_back("0000000110101");
	aarrstrVLC_init.push_back("0000000110010");
	aarrstrVLC_init.push_back("0000000110011");
	aarrstrVLC_init.push_back("0000000101110");
	aarrstrVLC_init.push_back("0000000101111");
	aarrstrVLC_init.push_back("0000000101100");
	aarrstrVLC_init.push_back("0000000101101");
	aarrstrVLC_init.push_back("00000000111110");
	aarrstrVLC_init.push_back("00000000111111");
	aarrstrVLC_init.push_back("00000000111100");
	aarrstrVLC_init.push_back("00000000111101");
	aarrstrVLC_init.push_back("00000000111010");
	aarrstrVLC_init.push_back("00000000111011");
	aarrstrVLC_init.push_back("00000000111000");
	aarrstrVLC_init.push_back("00000000111001");
	aarrstrVLC_init.push_back("00000000110110");
	aarrstrVLC_init.push_back("00000000110111");
	aarrstrVLC_init.push_back("000001");

}
void VLC_TCOEFF::introduceRunLevelSign(int anRun, int anLevel, int anSign, const string & astrCode){
		VLC_TableEntry entry;
		entry.m_arrnKey.push_back(anRun);
		entry.m_arrnKey.push_back(anLevel);
		entry.m_arrnKey.push_back(anSign);
		str2arrn(entry.m_arrnCode, astrCode);
		m_tblKeyCode.push_back(entry);
}

VLC_TCOEFF::VLC_TCOEFF(){

	vector<string> arrstrVLC_init;
	initCodes(arrstrVLC_init);
	int nSize = arrstrVLC_init.size();
	int nCount = 0;
	
	{
		VLC_TableEntry entry;
		entry.m_arrnKey.push_back(TCOEFF_EOB);
		str2arrn(entry.m_arrnCode, arrstrVLC_init[0]);
		m_tblKeyCode.push_back(entry);
		nCount++;
	}

	int nRun, nLevel, nSign;

	for(nSign = 0; nSign <= 1; nSign++){
		introduceRunLevelSign(0, 1, nSign, arrstrVLC_init[nCount++]);
	}


	for(nLevel = 1; nLevel <= 15; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(0, 1, nSign, arrstrVLC_init[nCount++]);
		}
	}

	for(nLevel = 1; nLevel <= 7; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(1, 1, nSign, arrstrVLC_init[nCount++]);
		}
	}

	for(nLevel = 1; nLevel <= 5; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(2, 1, nSign, arrstrVLC_init[nCount++]);
		}
	}

	for(nLevel = 1; nLevel <= 4; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(3, 1, nSign, arrstrVLC_init[nCount++]);
		}
	}

	for(nLevel = 1; nLevel <= 3; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(4, 1, nSign, arrstrVLC_init[nCount++]);
		}
	}

	for(nLevel = 1; nLevel <= 3; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(5, 1, nSign, arrstrVLC_init[nCount++]);
		}
	}

	for(nLevel = 1; nLevel <= 2; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(6, 1, nSign, arrstrVLC_init[nCount++]);
		}
	}

	for(nLevel = 1; nLevel <= 2; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(7, 1, nSign, arrstrVLC_init[nCount++]);
		}
	}

	for(nLevel = 1; nLevel <= 2; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(8, 1, nSign, arrstrVLC_init[nCount++]);
		}
	}

    for(nLevel = 1; nLevel <= 2; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(9, 1, nSign, arrstrVLC_init[nCount++]);
		}
	}

	for(nLevel = 1; nLevel <= 2; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(10, 1, nSign, arrstrVLC_init[nCount++]);
		}
	}

	for(nRun = 11; nRun <= 26; nRun++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(nRun, 1, nSign, arrstrVLC_init[nCount++]);
		}
	}

	{
		VLC_TableEntry entry;
		entry.m_arrnKey.push_back(TCOEFF_ESCAPE);
		str2arrn(entry.m_arrnCode, arrstrVLC_init[TCOEFF_ESCAPE]);
		m_tblKeyCode.push_back(entry);
	}

}


int VLC_TCOEFF::getIndexStateSpecific(const vector<int> & aarrnCode, int anSpecificState) const {

	if(aarrnCode[0] != 1)
		return(0);

	switch (anSpecificState) {
		case 0 :
			//EMIL: was if(aarrnCode[2] == 0)
			if(aarrnCode[1] == 0)
				return(TCOEFF_0_1_FIRSTCOEFF);
			else
				return(TCOEFF_0_1_FIRSTCOEFF_M);
			break;
		case 1 :
			if(aarrnCode[2] == 0)
				return(TCOEFF_0_1_NOTFIRSTCOEFF);
			else
				return(TCOEFF_0_1_NOTFIRSTCOEFF_M);
			break;
		default :
		{
			printf("Error: Problems detected in string in TCOEFF");
		    exit(-1);
		}
	}

}