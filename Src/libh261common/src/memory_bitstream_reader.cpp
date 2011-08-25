#include <new>
#include "memory_bitstream_reader.h"

using namespace std;

MemoryBitstreamReader::MemoryBitstreamReader(const u8 *buf, 
											 size_t buf_size_in_bytes)
:m_buf(buf),m_bufSize(buf_size_in_bytes),
m_bytePtr(buf),m_bitPtr(7)
{}


inline BitstreamReader::STATUS 
MemoryBitstreamReader::doReadBits(u32 *bits, int nbits,
                                  const u8 **new_byte_ptr, int *new_bit_ptr)
{
	if (nbits < 0 || nbits > 32)
		return STS_ERR_INVALID_ARGUMENTS;

	*new_byte_ptr = m_bytePtr;
	*new_bit_ptr = m_bitPtr;
	*bits = 0;

	while (nbits > 0) {
		*bits <<= 1;
		*bits |= (((u32)1 << *new_bit_ptr) & **new_byte_ptr) != 0;


		if ((*new_bit_ptr)-- == 0) {
			if (++(*new_byte_ptr) >= m_buf + m_bufSize)
				return STS_EOF;
			*new_bit_ptr = 7;
		}

		nbits--;
	}
	
	return STS_OK;
}




BitstreamReader::STATUS MemoryBitstreamReader::readBits(u32 *bits, int nbits)
{
	const u8 *new_byte_ptr;
	int new_bit_ptr;
	STATUS sts = doReadBits(bits,nbits,&new_byte_ptr,&new_bit_ptr);

	if (sts != STS_OK)
		return sts;

	m_bytePtr = new_byte_ptr;
	m_bitPtr = new_bit_ptr;

	return STS_OK;
}


BitstreamReader::STATUS MemoryBitstreamReader::peekBits(u32 *bits, int nbits)
{
	const u8 *new_byte_ptr;
	int new_bit_ptr;
	STATUS sts = doReadBits(bits,nbits,&new_byte_ptr,&new_bit_ptr);

	return sts;
}
	

BitstreamReader::STATUS MemoryBitstreamReader::skipBits(int nbits)
{
	u32 dummy;

	STATUS sts = readBits(&dummy,nbits);

	return sts;
}





