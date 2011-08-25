#include <vector>

#include "vlc_table.h"

using namespace std;

void VLC_Table::str2arrn(vector<int> & aarrnDst, const string & astrSrc){
	for(int nI = 0; nI < ((int)astrSrc.size()); nI++)
		aarrnDst.push_back(astrSrc[nI] == '1');
	
}

int VLC_Table::getKey(const vector<int> ** aarrnppKey, int anIndex) const{
	if((anIndex < 0) || (anIndex >= (int)m_tblKeyCode.size()))
		return(0);
	const VLC_TableEntry & entry = m_tblKeyCode[anIndex];
	*aarrnppKey = &entry.m_arrnKey;
	return(1);
}

int VLC_Table::getCode(const vector<int> ** aarrnppCode, int anIndex) const{
	if((anIndex < 0) || (anIndex >= (int)m_tblKeyCode.size()))
		return(0);
	const VLC_TableEntry & entry = m_tblKeyCode[anIndex];
	*aarrnppCode = &entry.m_arrnCode;
	return(1);
}

int VLC_Table::getIndexStateSpecific(const vector<int> & aarrnCode, int anSpecificState) const {
	printf("Error: A innapropriate virtual call to getIndexStateSpecific occured\n");
	exit(-1);
}

void VLC_Table::getCodes(std::vector< std::vector<int> > & aarrarrnCodes) {
	vector<string> arrstrVLC_init;
	initCodes(arrstrVLC_init);
	int nI;
	int nSize = arrstrVLC_init.size();
	for(nI = 0; nI < nSize; nI++){
		vector<int> arrnCode;
		str2arrn(arrnCode, arrstrVLC_init[nI]);
		aarrarrnCodes.push_back(arrnCode);
	}
}
