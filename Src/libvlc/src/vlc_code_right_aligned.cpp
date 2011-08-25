#include <Singleton.h>
#include <Trace.h>

#include "h261_common.h"

#include "vlc_code_right_aligned.h"

/*
VLC_CodeRightAligned::STATUS VLC_CodeRightAligned::getMask(u32 & aunMask, unsigned int aunBitsNr) const {
	if(aunBitsNr > 32) {
		return(STS_INDEX_EXCEED_BOUNDS);
	}
	aunMask = m_arrunMasks[aunBitsNr];
	return(STS_OK);
}

VLC_CodeRightAligned::VLC_CodeRightAligned() {

	m_arrunMasks[0] = 0;
	for(int nI = 1; nI < 33; nI++) {
		m_arrunMasks[nI] = (m_arrunMasks[nI - 1] << 1) | 0x0001;
	}

}
*/

VLC_CodeRightAligned & VLC_CodeRightAligned::operator=(const std::string & astrKey) {
	m_nLenInBits = (int)astrKey.length();
	if(m_nLenInBits > 32)
		Singleton<Trace>::instance()->printErrorMessage("VLC_CodeRightAligned::operator= - key longer than 32\n");
	m_unCode = 0;
	int nI;
	for(nI = 0; nI < m_nLenInBits; nI++) {
		m_unCode <<= 1;
		if(astrKey[nI] == '1')
			m_unCode += 1;
	}
	return(*this);
}

std::ostream & operator<<(std::ostream & aostreamStream, const VLC_CodeRightAligned & aCRA) {
	int nI;
	for(nI = aCRA.m_nLenInBits; nI > 0; nI--) {
		int nBitVal = aCRA.m_unCode & (0x01 << (nI - 1));
		aostreamStream << nBitVal;
	}
	return(aostreamStream);
}