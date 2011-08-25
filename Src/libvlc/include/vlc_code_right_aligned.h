#ifndef VLC_CODE_RIGHT_ALIGNED_H
#define VLC_CODE_RIGHT_ALIGNED_H

#include <ostream>

#include "h261_common.h"

struct VLC_CodeRightAligned {
	u32 m_unCode;
	int m_nLenInBits;

	enum STATUS {
		STS_OK = 0,
		STS_INDEX_EXCEED_BOUNDS
	};

//	STATUS getMask(u32 & aunMask, unsigned int aunBitsNr) const;

	

	VLC_CodeRightAligned & operator=(const std::string & astrKey);

//private:
//	u32 m_arrunMasks[33];
};

std::ostream & operator<<(std::ostream & aostreamStream, const VLC_CodeRightAligned & aCRA);

#endif //VLC_CODE_RIGHT_ALIGNED_H