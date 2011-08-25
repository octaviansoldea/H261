#ifndef MEMORY_BITSTREAM_READER_H
#define MEMORY_BITSTREAM_READER_H

#include <stddef.h>
#include "bitstream_reader.h"
#include "h261_common.h"

class MemoryBitstreamReader : public BitstreamReader {
public:
	MemoryBitstreamReader(const u8 *buf, size_t buf_size_in_bytes);
	virtual STATUS readBits(u32 *bits, int nbits);
	virtual STATUS peekBits(u32 *bits, int nbits);
	virtual STATUS skipBits(int nbits);

private:
	STATUS doReadBits(u32 *bits, int nbits,
                      const u8 **new_byte_ptr, int *new_bit_ptr);

	const u8 *m_buf;
	size_t m_bufSize;
	const u8 *m_bytePtr;
	int m_bitPtr;
};

#endif /* MEMORY_BITSTREAM_READER_H */