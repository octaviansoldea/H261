#include <string>
#include <vector>

#include "h261_common.h"
#include "bitstream_reader.h"
#include "vlc_TCOEFF.h"
#include "BasicDefinitions.h"

using namespace std;

void VLC_TCOEFF::introduceRunLevelSign(vector<vector<int> > & aarrarrn_Keys, int anRun, int anLevel, int anSign){
		vector<int> arrnVals;
		arrnVals.push_back(anRun);
		arrnVals.push_back(anLevel);
		arrnVals.push_back(anSign);
		aarrarrn_Keys.push_back(arrnVals);
}

void VLC_TCOEFF::initCodes() {
	
	vector<string> arrstrVLC_Init;

	arrstrVLC_Init.clear();
	
	arrstrVLC_Init.clear();
	arrstrVLC_Init.push_back("10");
	//arrstrVLC_Init.push_back("10");
	arrstrVLC_Init.push_back("11");
	arrstrVLC_Init.push_back("110");
	arrstrVLC_Init.push_back("111");
	arrstrVLC_Init.push_back("01000");
	arrstrVLC_Init.push_back("01001");
	arrstrVLC_Init.push_back("001010");
	arrstrVLC_Init.push_back("001011");
	arrstrVLC_Init.push_back("00001100");
	arrstrVLC_Init.push_back("00001101");
	arrstrVLC_Init.push_back("001001100");
	arrstrVLC_Init.push_back("001001101");
	arrstrVLC_Init.push_back("001000010");
	arrstrVLC_Init.push_back("001000011");
	arrstrVLC_Init.push_back("00000010100");
	arrstrVLC_Init.push_back("00000010101");
	arrstrVLC_Init.push_back("0000000111010");
	arrstrVLC_Init.push_back("0000000111011");
	arrstrVLC_Init.push_back("0000000110000");
	arrstrVLC_Init.push_back("0000000110001");
	arrstrVLC_Init.push_back("0000000100110");
	arrstrVLC_Init.push_back("0000000100111");
	arrstrVLC_Init.push_back("0000000100000");
	arrstrVLC_Init.push_back("0000000100001");
	arrstrVLC_Init.push_back("00000000110100");
	arrstrVLC_Init.push_back("00000000110101");
	arrstrVLC_Init.push_back("00000000110010");
	arrstrVLC_Init.push_back("00000000110011");
	arrstrVLC_Init.push_back("00000000110000");
	arrstrVLC_Init.push_back("00000000110001");
	arrstrVLC_Init.push_back("00000000101110");
	arrstrVLC_Init.push_back("00000000101111");
	arrstrVLC_Init.push_back("0110");
	arrstrVLC_Init.push_back("0111");
	arrstrVLC_Init.push_back("0001100");
	arrstrVLC_Init.push_back("0001101");
	arrstrVLC_Init.push_back("001001010");
	arrstrVLC_Init.push_back("001001011");
	arrstrVLC_Init.push_back("00000011000");
	arrstrVLC_Init.push_back("00000011001");
	arrstrVLC_Init.push_back("0000000110110");
	arrstrVLC_Init.push_back("0000000110111");
	arrstrVLC_Init.push_back("00000000101100");
	arrstrVLC_Init.push_back("00000000101101");
	arrstrVLC_Init.push_back("00000000101010");
	arrstrVLC_Init.push_back("00000000101011");
	arrstrVLC_Init.push_back("01010");
	arrstrVLC_Init.push_back("01011");
	arrstrVLC_Init.push_back("00001000");
	arrstrVLC_Init.push_back("00001001");
	arrstrVLC_Init.push_back("00000010110");
	arrstrVLC_Init.push_back("00000010111");
	arrstrVLC_Init.push_back("0000000101000");
	arrstrVLC_Init.push_back("0000000101001");
	arrstrVLC_Init.push_back("00000000101000");
	arrstrVLC_Init.push_back("00000000101001");
    arrstrVLC_Init.push_back("001110");
	arrstrVLC_Init.push_back("001111");
	arrstrVLC_Init.push_back("001001000");
	arrstrVLC_Init.push_back("001001001");
	arrstrVLC_Init.push_back("0000000111000");
	arrstrVLC_Init.push_back("0000000111001");
	arrstrVLC_Init.push_back("00000000100110");
	arrstrVLC_Init.push_back("00000000100111");
	arrstrVLC_Init.push_back("001100");
	arrstrVLC_Init.push_back("001101");
	arrstrVLC_Init.push_back("00000011110");
	arrstrVLC_Init.push_back("00000011111");
	arrstrVLC_Init.push_back("0000000100100");
	arrstrVLC_Init.push_back("0000000100101");
	arrstrVLC_Init.push_back("0001110");
	arrstrVLC_Init.push_back("0001111");
	arrstrVLC_Init.push_back("00000010010");
	arrstrVLC_Init.push_back("00000010011");
	arrstrVLC_Init.push_back("00000000100100");
	arrstrVLC_Init.push_back("00000000100101");
	arrstrVLC_Init.push_back("0001010");
	arrstrVLC_Init.push_back("0001011");
	arrstrVLC_Init.push_back("0000000111100");
	arrstrVLC_Init.push_back("0000000111101");
	arrstrVLC_Init.push_back("0001000");
	arrstrVLC_Init.push_back("0001001");
	arrstrVLC_Init.push_back("0000000101010");
	arrstrVLC_Init.push_back("0000000101011");
	arrstrVLC_Init.push_back("00001110");
	arrstrVLC_Init.push_back("00001111");
	arrstrVLC_Init.push_back("0000000100010");
	arrstrVLC_Init.push_back("0000000100011");
	arrstrVLC_Init.push_back("00001010");
	arrstrVLC_Init.push_back("00001011");
	arrstrVLC_Init.push_back("00000000100010");
	arrstrVLC_Init.push_back("00000000100011");
	arrstrVLC_Init.push_back("001001110");
	arrstrVLC_Init.push_back("001001111");
	arrstrVLC_Init.push_back("00000000100000");
	arrstrVLC_Init.push_back("00000000100001");
	arrstrVLC_Init.push_back("001000110");
	arrstrVLC_Init.push_back("001000111");
	arrstrVLC_Init.push_back("001000100");
	arrstrVLC_Init.push_back("001000101");
	arrstrVLC_Init.push_back("001000000");
	arrstrVLC_Init.push_back("001000001");
	arrstrVLC_Init.push_back("00000011100");
	arrstrVLC_Init.push_back("00000011101");
	arrstrVLC_Init.push_back("00000011010");
	arrstrVLC_Init.push_back("00000011011");
	arrstrVLC_Init.push_back("00000010000");
	arrstrVLC_Init.push_back("00000010001");
	arrstrVLC_Init.push_back("0000000111110");
	arrstrVLC_Init.push_back("0000000111111");
	arrstrVLC_Init.push_back("0000000110100");
	arrstrVLC_Init.push_back("0000000110101");
	arrstrVLC_Init.push_back("0000000110010");
	arrstrVLC_Init.push_back("0000000110011");
	arrstrVLC_Init.push_back("0000000101110");
	arrstrVLC_Init.push_back("0000000101111");
	arrstrVLC_Init.push_back("0000000101100");
	arrstrVLC_Init.push_back("0000000101101");
	arrstrVLC_Init.push_back("00000000111110");
	arrstrVLC_Init.push_back("00000000111111");
	arrstrVLC_Init.push_back("00000000111100");
	arrstrVLC_Init.push_back("00000000111101");
	arrstrVLC_Init.push_back("00000000111010");
	arrstrVLC_Init.push_back("00000000111011");
	arrstrVLC_Init.push_back("00000000111000");
	arrstrVLC_Init.push_back("00000000111001");
	arrstrVLC_Init.push_back("00000000110110");
	arrstrVLC_Init.push_back("00000000110111");
	arrstrVLC_Init.push_back("000001");

	vector<vector<int> > arrarrn_Keys;
	int nCount = 0;
	vector<int> arrnVals;
	arrnVals.push_back(TCOEFF_EOB_OR_0_1_FIRSTCOEFF);
	arrarrn_Keys.push_back(arrnVals);
	nCount++;

	int nRun, nLevel, nSign;
	
	//for(nSign = 0; nSign <= 1; nSign++){
		introduceRunLevelSign(arrarrn_Keys, 0, 1, 1);
	//}
	
	for(nSign = 0; nSign <= 1; nSign++){
		introduceRunLevelSign(arrarrn_Keys, 0, 1, nSign);
	}

	for(nLevel = 2; nLevel <= 15; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(arrarrn_Keys, 0, nLevel, nSign);
		}
	}

	for(nLevel = 1; nLevel <= 7; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(arrarrn_Keys, 1, 1, nSign);
		}
	}

	for(nLevel = 1; nLevel <= 5; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(arrarrn_Keys, 2, 1, nSign);
		}
	}

	for(nLevel = 1; nLevel <= 4; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(arrarrn_Keys, 3, 1, nSign);
		}
	}

	for(nLevel = 1; nLevel <= 3; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(arrarrn_Keys, 4, 1, nSign);
		}
	}

	for(nLevel = 1; nLevel <= 3; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(arrarrn_Keys, 5, 1, nSign);
		}
	}

	for(nLevel = 1; nLevel <= 2; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(arrarrn_Keys, 6, 1, nSign);
		}
	}

	for(nLevel = 1; nLevel <= 2; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(arrarrn_Keys, 7, 1, nSign);
		}
	}

	for(nLevel = 1; nLevel <= 2; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(arrarrn_Keys, 8, 1, nSign);
		}
	}

    for(nLevel = 1; nLevel <= 2; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(arrarrn_Keys, 9, 1, nSign);
		}
	}

	for(nLevel = 1; nLevel <= 2; nLevel++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(arrarrn_Keys, 10, 1, nSign);
		}
	}

	for(nRun = 11; nRun <= 26; nRun++){
		for(nSign = 0; nSign <= 1; nSign++){
			introduceRunLevelSign(arrarrn_Keys, nRun, 1, nSign);
		}
	}

	arrnVals.clear();
	arrnVals.push_back(TCOEFF_ESCAPE);
	arrarrn_Keys.push_back(arrnVals);
	setCodes(arrarrn_Keys, arrstrVLC_Init);

}

VLC_TCOEFF::VLC_TCOEFF() {
	initCodes();
}

VLC_TCOEFF::STATUS VLC_TCOEFF::getNextRunLevel(TCoeff * apTCoeff, 
											   BitstreamReader * apBR,
											   bool abIsFirstCoeff) const {
	u32 bits;
	int nBitsPeekable;

	VLC_Tree::STATUS sts_VLC_Tree = m_Tree.peekMaxBits(&bits, &nBitsPeekable, apBR);
	switch(sts_VLC_Tree) {
		case VLC_Tree::STS_OK :
			break;
		case VLC_Tree::STS_EOF :
			return(STS_EOF);
		default:
			return(STS_ERR);
	};

	if(nBitsPeekable < 2)
		return(STS_ERR);

	apTCoeff->m_bIsEOB = false;

	bool bFirstBit, bSecondBit, bThirdBit;
	bFirstBit = !!(bits & (0x1<<(nBitsPeekable - 1)));
	bSecondBit = !!(bits & (0x1<<(nBitsPeekable - 2)));
	if(nBitsPeekable >= 3)
		bThirdBit = !!(bits & (0x1<<(nBitsPeekable - 1)));

	if(bFirstBit) {
		apTCoeff->m_nRun = 0;
		if(abIsFirstCoeff) {
			apTCoeff->m_nLevel = (bSecondBit ? -1 : 1);
			apBR->readBits(&bits, 2);
			return(STS_OK);
		} else {
			if(!bSecondBit) {
				apTCoeff->m_bIsEOB = true;
				apBR->readBits(&bits, 2);
				return(STS_OK);
			} else { 
				if(nBitsPeekable >= 3){
					apTCoeff->m_nLevel = (bSecondBit ? -1 : 1);
					apBR->readBits(&bits, 3);
					return(STS_OK);
				} else {
					return(STS_ERR);
				}
			}
		}
	}

	int nIndex;
	sts_VLC_Tree = m_Tree.getKey(&nIndex, apBR);
	switch(sts_VLC_Tree) {
		case VLC_Tree::STS_OK :
			break;
		case VLC_Tree::STS_EOF :
			return(STS_EOF);
		case VLC_Tree::STS_ERR_NOT_IN_TREE :
			return(STS_ERR_NOT_IN_TREE);
		default:
			return(STS_ERR);
	}

	const vector<int> * parrnKey;
	VLC_Table::STATUS sts_VLC_Table = m_Table.getKey(&parrnKey, nIndex);
	if((parrnKey->size() != 1) && ((parrnKey->size() != 3)))
		return(STS_ERR_INVALID_KEY);

	switch(sts_VLC_Table) {
		case VLC_Table::STS_OK :
			if(parrnKey->size() == 3) {
				apTCoeff->m_nRun = (*parrnKey)[0];
				apTCoeff->m_nLevel = (*parrnKey)[1];
				apTCoeff->m_nLevel *= ((*parrnKey)[2] == 0 ? 1 : -1);
				return(STS_OK);
			}
			break;
		case VLC_Table::STS_ERR_INDEX_EXCEED_BOUNDS :
			return(STS_ERR_INDEX_EXCEED_BOUNDS);
		case VLC_Table::STS_ERR_PURE_VIRTUAL_CALL :
			return(STS_ERR_PURE_VIRTUAL_CALL);
		default:
			return(STS_ERR);
	}

	apTCoeff->m_bEscapeDetected = true;

	//6 bits escape query
	if( ((*parrnKey)[0]) != TCOEFF_ESCAPE) {
		return(STS_ERR);
	}
	//6 bits run
	sts_VLC_Tree = m_Tree.peekMaxBits(&bits, &nBitsPeekable, apBR);
	switch(sts_VLC_Tree) {
		case VLC_Tree::STS_OK :
			break;
		case VLC_Tree::STS_EOF :
			return(STS_EOF);
		default:
			return(STS_ERR);
	};
	if(nBitsPeekable < 14) {
		return(STS_ERR);
	}

	u32 u32RunLen = (bits >> (nBitsPeekable - 6)) & 0x3F;// 0x3F = binary_111111 = decimal_63
	apTCoeff->m_nRun = u32RunLen;

	//8 bits level
	u32RunLen = (bits >> (nBitsPeekable - 14)) & 0xFF;
	if((u32RunLen == 0x80) || (u32RunLen == 0x00)) //0x81 = binary_10000001 = decimal_129 which is forbidden
	{
		return(STS_ERR);
	}
	apTCoeff->m_nLevel = (((u32RunLen & 0x80) != 0)? -1 : 1);
	if(apTCoeff->m_nLevel > 0)
		apTCoeff->m_nLevel = (u32RunLen & 0x7F);
	else
		(apTCoeff->m_nLevel) *= (128 - (u32RunLen & 0x7F));//decimal_128 = binary_10000000 = 0x80

	apBR->readBits(&bits, 14);


	

	return(STS_OK);
}


VLC_TCOEFF::STATUS VLC_TCOEFF::getNextTCOEFF(TCoeff * apTCoeff,
											 BitstreamReader * apBR,
						                     int anQuant,
											 bool abIsFirstCoeff,
											 bool abIsIntraDC) const {

	if(abIsIntraDC && (abIsFirstCoeff == false))
		return(STS_ERR);

	if(abIsIntraDC && (anQuant != 0))
		return(STS_ERR);

	//Intra DC coefficient
	if(abIsIntraDC) {

		u32 bits;
		int nBitsPeekable;

		VLC_Tree::STATUS sts_VLC_Tree = m_Tree.peekMaxBits(&bits, &nBitsPeekable, apBR);
		switch(sts_VLC_Tree) {
			case VLC_Tree::STS_OK :
				break;
			case VLC_Tree::STS_EOF :
				return(STS_EOF);
			default:
				return(STS_ERR);
		};

		if(nBitsPeekable < 8)
			return(STS_ERR);

		apBR->readBits(&bits, 8);
		
		//0x80 = 10000000b = 128 dec
		if((bits == 0x00) || (bits == 0x128))
			return(STS_ERR);
		if(bits == 0xFF) {
			apTCoeff->m_RecLevel = 1024;
		}
		else {
			apTCoeff->m_RecLevel = bits * 8;
		}
	} else {
		//Non Intra DC coefficient

		if(anQuant == 0)
			return(STS_ERR);

		VLC_TCOEFF::STATUS sts = getNextRunLevel(apTCoeff, 
												 apBR, 
												 abIsFirstCoeff);
		if(sts != STS_OK)
			return(sts);

		if(apTCoeff->m_bIsEOB)
			return(STS_OK);

		bool bOdd = ((anQuant % 2) != 0);
		if(apTCoeff->m_nLevel == 0) {
			apTCoeff->m_RecLevel = 0;
		} else if(apTCoeff->m_nLevel > 0) {
			if(bOdd) {
				apTCoeff->m_RecLevel = anQuant * (2 * (apTCoeff->m_nLevel) + 1);
			}
			else {
				apTCoeff->m_RecLevel = anQuant * (2 * (apTCoeff->m_nLevel) - 1);
			}
		}
		else {
			if(bOdd) {
				apTCoeff->m_RecLevel = anQuant * (2 * (apTCoeff->m_nLevel) - 1);
			}
			else {
				apTCoeff->m_RecLevel = anQuant * (2 * (apTCoeff->m_nLevel) + 1);
			}
		}
		apTCoeff->m_nLevel = MIN(MAX(apTCoeff->m_nLevel, -2048), 2047);
	}
	return(STS_OK);
}