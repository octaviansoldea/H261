#ifndef VLC_TABLE
#define VLC_TABLE

#include <vector>
#include <string>

#include "vlc_code_right_aligned.h"

struct VLC_TableEntry{
	VLC_CodeRightAligned m_Code;
	std::vector<int> m_arrnKey;
};

struct VLC_Table {
	enum STATUS {
		STS_OK = 0,
		STS_ERR_INDEX_EXCEED_BOUNDS,
		STS_ERR_PURE_VIRTUAL_CALL
	};

    STATUS getKey(const std::vector<int> ** apparrnKey, int anIndex) const;
    STATUS getCode(const VLC_CodeRightAligned ** appCodeRightAligned, int anIndex) const;

	bool addKeyCode(const std::vector<int> & aarrnKey, const std::string & astrCode, int anAt);

private:

	std::vector<VLC_TableEntry> m_tblKeyCode;
	//void str2arrn(std::vector<int> & aarrnDst, const std::string & astrSrc) const;
	//virtual STATUS initCodes(std::vector<std::string> & aarrstrVLC_init) const = 0;
};

#endif //VLC_TABLE