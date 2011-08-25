#include <windows.h>
#include <string>

#include "BasicDefinitions.h"
#include "BasicStringDefinitions.h"

std::string itostr(int anVal) {
	char pchVal[MAX_STR_LEN];
	sprintf(pchVal, "%d", anVal);
	std::string strVal(pchVal);
	return(strVal);
}

std::string GetLastErrorString() {
	LPVOID lpMsgBuf;
	DWORD dw = GetLastError(); 

	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0,
		NULL );

		//printf("failed with error %d: %s", dw, lpMsgBuf); 
		std::string strVal((char *)lpMsgBuf);
		LocalFree(lpMsgBuf);
		return(strVal);

}

bool isInString(const std::string & astrName, const std::string & astrField) {
	bool bRes = false;
	int indexCh = astrName.find ( astrField , 0 );
	if (indexCh != std::string::npos )
		bRes = true;
	return(bRes);
}