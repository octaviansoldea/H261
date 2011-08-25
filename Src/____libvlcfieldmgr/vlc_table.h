#ifndef VLC_TABLE
#define VLC_TABLE

#include <vector>



struct VLC_TableEntry{
	std::vector<int> m_arrnCode;
	std::vector<int> m_arrnKey;
};

class VLC_Table {
protected:
	std::vector<VLC_TableEntry> m_tblKeyCode;
	void str2arrn(std::vector<int> & aarrnDst, const std::string & astrSrc);
	virtual void initCodes(std::vector<std::string> & aarrstrVLC_init) const = 0;
public:
    int getKey(const std::vector<int> ** aarrnppKey, int anIndex) const;
    int getCode(const std::vector<int> ** aarrnppCode, int anIndex) const;

	virtual int getIndexStateSpecific(const std::vector<int> & aarrnCode, int anSpecificState) const;
	
	void getCodes(std::vector< std::vector<int> > & aarrarrnCodes);
	
};




#endif //VLC_TABLE