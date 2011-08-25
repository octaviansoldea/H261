#include <string>
#include <vector>

#include "h261_common.h"
#include "bitstream_reader.h"
#include "vlc_MTYPE.h"

using namespace std;

void VLC_MTYPE::initCodes() {
	
	vector<string> arrstrVLC_Init;

	arrstrVLC_Init.clear();
	
	arrstrVLC_Init.clear();
	arrstrVLC_Init.push_back("0001");
	arrstrVLC_Init.push_back("0000001");
	arrstrVLC_Init.push_back("1");
	arrstrVLC_Init.push_back("00001");
	arrstrVLC_Init.push_back("000000001");
	arrstrVLC_Init.push_back("00000001");
	arrstrVLC_Init.push_back("0000000001");
	arrstrVLC_Init.push_back("001");
	arrstrVLC_Init.push_back("01");
	arrstrVLC_Init.push_back("000001");

	int arrnMTYPEVals[MTYPE_MAX] = {
									MTYPE_INTRA_TCOEFF,
									MTYPE_INTRA_MQUANT_TCOEFF,
									MTYPE_INTER_CBP_TCOEFF,
									MTYPE_INTER_MQUANT_CBP_TCOEFF,
									MTYPE_INTERMC_MVD,
									 MTYPE_INTERMC_MVD_CBP_TCOEFF,
									 MTYPE_INTERMC_MQUANT_MVD_CBP_TCOEFF,
									MTYPE_INTERMCFIL_MVD,
									MTYPE_INTERMCFIL_MVD_CBP_TCOEFF,
									MTYPE_INTERMCFIL_MQUANT_MVD_CBP_TCOEFF
	};

	vector<vector<int> > arrarrn_Keys;
	int nI;
	for(nI = 0; nI < MTYPE_MAX; nI++) {
		vector<int> arrnVals;
		arrnVals.push_back(arrnMTYPEVals[nI]);
		arrarrn_Keys.push_back(arrnVals);
	}

	setCodes(arrarrn_Keys, arrstrVLC_Init);

}

VLC_MTYPE::VLC_MTYPE() {
	initCodes();
}

VLC_MTYPE::STATUS VLC_MTYPE::getNextMTYPE(u32 * aunpMask, BitstreamReader * apBR) const {
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
			*aunpMask = (u32)((*parrnKey)[0]);
			return(STS_OK);
		case VLC_Table::STS_ERR_INDEX_EXCEED_BOUNDS :
			return(STS_ERR_INDEX_EXCEED_BOUNDS);
		case VLC_Table::STS_ERR_PURE_VIRTUAL_CALL :
			return(STS_ERR_PURE_VIRTUAL_CALL);
		default:
			return(STS_ERR);
	}
}