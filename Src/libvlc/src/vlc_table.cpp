#include <vector>

#include "vlc_table.h"

using namespace std;

/*
void VLC_Table::str2arrn(vector<int> & aarrnDst, const string & astrSrc) const {
	for(int nI = 0; nI < ((int)astrSrc.size()); nI++)
		aarrnDst.push_back(astrSrc[nI] == '1');
	
}
*/

 VLC_Table::STATUS VLC_Table::getKey(const std::vector<int> ** apparrnKey, int anIndex) const {
	if((anIndex < 0) || (anIndex >= (int)m_tblKeyCode.size()))
		return(STS_ERR_INDEX_EXCEED_BOUNDS);
	const VLC_TableEntry & entry = m_tblKeyCode[anIndex];
	*apparrnKey = &entry.m_arrnKey;
	return(STS_OK);
}

 VLC_Table::STATUS VLC_Table::getCode(const VLC_CodeRightAligned ** appCodeRightAligned, int anIndex) const {
	if((anIndex < 0) || (anIndex >= (int)m_tblKeyCode.size()))
		return(STS_ERR_INDEX_EXCEED_BOUNDS);
	const VLC_TableEntry & entry = m_tblKeyCode[anIndex];
	*appCodeRightAligned = &entry.m_Code;
	return(STS_OK);
}

/*
VLC_Table::STATUS VLC_Table::initCodes(std::vector<std::string> & aarrstrVLC_init) const{
	printf("Error: A innapropriate virtual call to getIndexStateSpecific occured\n");
	return(STS_ERR_PURE_VIRTUAL_CALL);
}
*/

 bool VLC_Table::addKeyCode(const std::vector<int> & aarrnKey, const std::string & astrCode, int anAt) {

		VLC_TableEntry entry;
		int nSize = (int)aarrnKey.size();
		int nI;
		for(nI = 0; nI < nSize; nI++)
			entry.m_arrnKey.push_back(aarrnKey[nI]);
		entry.m_Code = astrCode;
		m_tblKeyCode.push_back(entry);
		return(m_tblKeyCode.size() == (anAt + 1));

 }