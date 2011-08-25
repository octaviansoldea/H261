#ifndef BITSTREAM_READER_H
#define BITSTREAM_READER_H

#include "h261_common.h"

class BitstreamReader {
public:
	enum STATUS {
		STS_OK = 0,
		STS_EOF,
		STS_ERR_NO_MEMORY,
		STS_ERR_INVALID_ARGUMENTS,
		STS_ERR_IO
	};

	//These methods are the only way to create BitstreamReader objects
	static STATUS create(const u8 *buffer, size_t buffer_size_in_bytes, BitstreamReader **br);
	static STATUS create(const char *filename, BitstreamReader **br);

	//This is the only way to destroy BitstreamReader objects
	virtual STATUS destroy(void) {delete this; return STS_OK;}

	virtual STATUS readBits(u32 *bits, int nbits) = 0;
	virtual STATUS peekBits(u32 *bits, int nbits) = 0;
	virtual STATUS skipBits(int nbits) = 0;

protected:
	BitstreamReader(void) {}
	virtual ~BitstreamReader(void) {}

	//Disallowed methods
	BitstreamReader(const BitstreamReader&);
	BitstreamReader& operator = (const BitstreamReader &);
};



#endif /* BITSTREAM_READER_H */