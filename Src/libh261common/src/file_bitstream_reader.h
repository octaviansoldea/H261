#ifndef FILE_BITSTREAM_READER_H
#define FILE_BITSTREAM_READER_H

#include <stdio.h>
#include "bitstream_reader.h"

class FileBitstreamReader : public BitstreamReader {
public:
	FileBitstreamReader(FILE *fp);
	virtual ~FileBitstreamReader(void);
	virtual STATUS readBits(u32 *bits, int nbits);
	virtual STATUS peekBits(u32 *bits, int nbits);
	virtual STATUS skipBits(int nbits);
private:
	STATUS doReadBits(u32 *bits, int nbits, bool *new_refill,
                      u8 *new_byte_buf, int *new_bit_ptr);
	FILE *m_file;
	u8 m_byteBuf;
	int m_bitPtr;
	bool m_refill;
};


#endif /* FILE_BITSTREAM_READER_H */