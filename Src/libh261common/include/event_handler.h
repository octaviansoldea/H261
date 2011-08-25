#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <stdio.h>

#include "token.h"

class EventHandler {
public:
	enum EVENT_TYPE {
		EV_BITSTREAM_BEGIN,
		EV_BITSTREAM_END,
		EV_PICTURE_BEGIN,
		EV_PICTURE_END,
		EV_GOB_BEGIN,
		EV_GOB_END,
		EV_MB_BEGIN,
		EV_MB_END,
		EV_BLOCK_BEGIN,
		EV_BLOCK_END,
		EV_BLOCK_COEFFS,
		EV_TOKEN
	};

	enum STATUS {
		STS_OK = 0,
		STS_ERROR
	};

	//pTokenOrCoeffsTable is not NULL only if ev_type is EV_TOKEN or EV_BLOCK_COEFFS
	virtual STATUS handleEvent(EVENT_TYPE ev_type, const void *pTokenOrCoeffsTable = NULL) = 0;
};



#endif /* EVENT_HANDLER_H */
