#ifndef XML_DUMP_EVENT_HANDLER_H
#define XML_DUMP_EVENT_HANDLER_H

#include <iostream>
#include "blockCoeffsMgr.h"
#include "event_handler.h"

class XMLDumpEventHandler : public EventHandler {
public:
	explicit XMLDumpEventHandler(std::ostream& os) : m_os(os), m_indent(0) {}
	virtual STATUS handleEvent(EVENT_TYPE ev_type, const void *pTokenOrCoeffsTable = NULL);

private:
	void indent(void);
	void printToken(const Token& token);
	void printCoeffs(const BlockCoeffsMgr & aCoeffsTable);
	std::ostream& m_os;
	int m_indent;
};


#endif /* XML_DUMP_EVENT_HANDLER_H */