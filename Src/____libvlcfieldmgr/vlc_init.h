#ifndef VLC_INIT_H
#define VLC_INIT_H

#include <string>

using namespace std;

struct ValueCode{
	string m_strValue;
	string m_strCode;

	ValueCode(const string & astrValue, const string & astrCode) : 
		m_strValue(astrValue), m_strCode(astrCode)
	{}

};




#endif //VLC_INIT_H