#include <string>
#include <vector>

#include "h261_common.h"
#include "bitstream_reader.h"
#include "vlc_MBA.h"

using namespace std;

void VLC_MBA::initCodes() {
	
	vector<string> arrstrVLC_Init;

	arrstrVLC_Init.clear();
	
	arrstrVLC_Init.push_back("1");
	arrstrVLC_Init.push_back("011");
	arrstrVLC_Init.push_back("010");
	arrstrVLC_Init.push_back("0011");
	arrstrVLC_Init.push_back("0010");
	arrstrVLC_Init.push_back("00011");
	arrstrVLC_Init.push_back("00010");
	arrstrVLC_Init.push_back("0000111");
	arrstrVLC_Init.push_back("0000110");
	arrstrVLC_Init.push_back("00001011");
	arrstrVLC_Init.push_back("00001010");
	arrstrVLC_Init.push_back("00001001");
	arrstrVLC_Init.push_back("00001000");
	arrstrVLC_Init.push_back("00000111");
	arrstrVLC_Init.push_back("00000110");
	arrstrVLC_Init.push_back("0000010111");
	arrstrVLC_Init.push_back("0000010110");
	arrstrVLC_Init.push_back("0000010101");
	arrstrVLC_Init.push_back("0000010100");
	arrstrVLC_Init.push_back("0000010011");
	arrstrVLC_Init.push_back("0000010010");
	arrstrVLC_Init.push_back("00000100011");
	arrstrVLC_Init.push_back("00000100010");
	arrstrVLC_Init.push_back("00000100001");
	arrstrVLC_Init.push_back("00000100000");
	arrstrVLC_Init.push_back("00000011111");
	arrstrVLC_Init.push_back("00000011110");
	arrstrVLC_Init.push_back("00000011101");
	arrstrVLC_Init.push_back("00000011100");
	arrstrVLC_Init.push_back("00000011011");
	arrstrVLC_Init.push_back("00000011010");
	arrstrVLC_Init.push_back("00000011001");
	arrstrVLC_Init.push_back("00000011000");
	arrstrVLC_Init.push_back("00000001111");
	arrstrVLC_Init.push_back("0000000000000001");

	vector<vector<int> > arrarrn_Keys;
	int nI;
	for(nI = 0; nI < (MBA_MAX - 1); nI++) {
		vector<int> arrnVals;
		arrnVals.push_back(nI + 1);
		arrarrn_Keys.push_back(arrnVals);
	}

	setCodes(arrarrn_Keys, arrstrVLC_Init);

}

VLC_MBA::VLC_MBA() {
	initCodes();
}

VLC_MBA::STATUS VLC_MBA::getNextMBA(int * apnMBA, BitstreamReader * apBR) const {
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
			*apnMBA = (*parrnKey)[0];
			return(STS_OK);
		case VLC_Table::STS_ERR_INDEX_EXCEED_BOUNDS :
			return(STS_ERR_INDEX_EXCEED_BOUNDS);
		case VLC_Table::STS_ERR_PURE_VIRTUAL_CALL :
			return(STS_ERR_PURE_VIRTUAL_CALL);
		default:
			return(STS_ERR);
	}
}