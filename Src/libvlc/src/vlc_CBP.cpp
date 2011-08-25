#include <string>
#include <vector>

#include "h261_common.h"
#include "bitstream_reader.h"
#include "vlc_CBP.h"

using namespace std;

void VLC_CBP::initCodes() {
	
	vector<string> arrstrVLC_Init;

	arrstrVLC_Init.clear();
	
	arrstrVLC_Init.clear();
	arrstrVLC_Init.push_back("111");
	arrstrVLC_Init.push_back("1101");
	arrstrVLC_Init.push_back("1100");
	arrstrVLC_Init.push_back("1011");
	arrstrVLC_Init.push_back("1010");
	arrstrVLC_Init.push_back("10011");
	arrstrVLC_Init.push_back("10010");
	arrstrVLC_Init.push_back("10001");
	arrstrVLC_Init.push_back("10000");
	arrstrVLC_Init.push_back("01111");
	arrstrVLC_Init.push_back("01110");
	arrstrVLC_Init.push_back("01101");
	arrstrVLC_Init.push_back("01100");
	arrstrVLC_Init.push_back("01011");
	arrstrVLC_Init.push_back("01010");
	arrstrVLC_Init.push_back("01001");
	arrstrVLC_Init.push_back("01000");
	arrstrVLC_Init.push_back("001111");
	arrstrVLC_Init.push_back("001110");
	arrstrVLC_Init.push_back("001101");
	arrstrVLC_Init.push_back("001100");
	arrstrVLC_Init.push_back("0010111");
	arrstrVLC_Init.push_back("0010110");
	arrstrVLC_Init.push_back("0010101");
	arrstrVLC_Init.push_back("0010100");
	arrstrVLC_Init.push_back("0010011");
	arrstrVLC_Init.push_back("0010010");
	arrstrVLC_Init.push_back("0010001");
	arrstrVLC_Init.push_back("0010000");
	arrstrVLC_Init.push_back("00011111");
	arrstrVLC_Init.push_back("00011110");
	arrstrVLC_Init.push_back("00011101");
	arrstrVLC_Init.push_back("00011100");
	arrstrVLC_Init.push_back("00011011");
	arrstrVLC_Init.push_back("00011010");
	arrstrVLC_Init.push_back("00011001");
	arrstrVLC_Init.push_back("00011000");
	arrstrVLC_Init.push_back("00010111");
	arrstrVLC_Init.push_back("00010110");
	arrstrVLC_Init.push_back("00010101");
	arrstrVLC_Init.push_back("00010100");
	arrstrVLC_Init.push_back("00010011");
	arrstrVLC_Init.push_back("00010010");
	arrstrVLC_Init.push_back("00010001");
	arrstrVLC_Init.push_back("00010000");
	arrstrVLC_Init.push_back("00001111");
	arrstrVLC_Init.push_back("00001110");
	arrstrVLC_Init.push_back("00001101");
	arrstrVLC_Init.push_back("00001100");
	arrstrVLC_Init.push_back("00001011");
	arrstrVLC_Init.push_back("00001010");
	arrstrVLC_Init.push_back("00001001");
	arrstrVLC_Init.push_back("00001000");
	arrstrVLC_Init.push_back("00000111");
	arrstrVLC_Init.push_back("00000110");
	arrstrVLC_Init.push_back("00000101");
	arrstrVLC_Init.push_back("00000100");
	arrstrVLC_Init.push_back("000000111");
	arrstrVLC_Init.push_back("000000110");
	arrstrVLC_Init.push_back("000000101");
	arrstrVLC_Init.push_back("000000100");
	arrstrVLC_Init.push_back("000000011");
	arrstrVLC_Init.push_back("000000010");

	int arrnEnums[CBP_MAX] = {CBP_60, CBP_4,  CBP_8,  CBP_16, CBP_32, CBP_12,
		                      CBP_48, CBP_20, CBP_40, CBP_28, CBP_44, CBP_52,
		                      CBP_56, CBP_1,  CBP_61, CBP_2,  CBP_62, CBP_24,
		                      CBP_36, CBP_3,  CBP_63, CBP_5,  CBP_9,  CBP_17,
		                      CBP_33, CBP_6,  CBP_10, CBP_18, CBP_34,  CBP_7, 
							  CBP_11, CBP_19, CBP_35, CBP_13, CBP_49, CBP_21,
		                      CBP_41, CBP_14, CBP_50, CBP_22, CBP_42, CBP_15,
		                      CBP_51, CBP_23, CBP_43, CBP_25, CBP_37, CBP_26,
		                      CBP_38, CBP_29, CBP_45, CBP_53, CBP_57, CBP_30,
		                      CBP_46, CBP_54, CBP_58, CBP_31, CBP_47, CBP_55,
		                      CBP_59, CBP_27, CBP_39
	};

	vector<vector<int> > arrarrn_Keys;
	int nI;
	for(nI = 0; nI < (CBP_MAX - 1); nI++) {
		vector<int> arrnVals;
		arrnVals.push_back(arrnEnums[nI]);
		arrarrn_Keys.push_back(arrnVals);
	}

	setCodes(arrarrn_Keys, arrstrVLC_Init);

}

VLC_CBP::VLC_CBP() {
	initCodes();
}

VLC_CBP::STATUS VLC_CBP::getNextCBP(int * apnCBP, BitstreamReader * apBR) const {
	int nIndex;
	VLC_Tree::STATUS sts_VLC_Tree = m_Tree.getKey(&nIndex, apBR);
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
	if(parrnKey->size() != 1)
		return(STS_ERR_INVALID_KEY);

	switch(sts_VLC_Table) {
		case VLC_Table::STS_OK :
			*apnCBP = (*parrnKey)[0];
			return(STS_OK);
		case VLC_Table::STS_ERR_INDEX_EXCEED_BOUNDS :
			return(STS_ERR_INDEX_EXCEED_BOUNDS);
		case VLC_Table::STS_ERR_PURE_VIRTUAL_CALL :
			return(STS_ERR_PURE_VIRTUAL_CALL);
		default:
			return(STS_ERR);
	}
}