#ifndef BITSTREAM_PARSER_H
#define BITSTREAM_PARSER_H

#include "bitstream_reader.h"
#include "event_handler.h"


class BitstreamParser {
public:
	enum STATUS {
		STS_OK = 0,
		STS_EOF,
		STS_ERR_NO_MEMORY,
		STS_ERR_UNEXPECTED_EOF,
		STS_ERR_TOKEN_HANDLER,
		STS_ERR_BITSTREAM_SYNTAX,
		STS_ERR_BITSTREAM_IO,
		STS_ERR_INTERNAL
	};

	// This is the only way to create a BitstreamParser
	static STATUS create(BitstreamParser **psr);
	
	//This is the only way to destroy a BitstreamParser
	virtual void destroy(void) { delete this; }

	virtual STATUS parse(BitstreamReader *bsr, EventHandler *ev_hdlr) = 0;

protected:
	BitstreamParser() {}
	virtual ~BitstreamParser() {}

	enum {
		START_CODE_PREFIX	= 0x0001,
		GOB_START_CODE		= 0x0001,
		PICTURE_START_CODE	= 0x00010
	};


private:
	//disable compiler-provided methods
	BitstreamParser(const BitstreamParser &);
	BitstreamReader& operator = (const BitstreamParser&);
};

#endif /* BITSTREAM_PARSER_H */