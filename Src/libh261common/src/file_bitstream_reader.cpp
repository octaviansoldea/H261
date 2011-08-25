#include <new>
#include "file_bitstream_reader.h"

using namespace std;

FileBitstreamReader::FileBitstreamReader(FILE *fp)
: m_file(fp), m_byteBuf(0),
m_bitPtr(7), m_refill(true)
{}

FileBitstreamReader::~FileBitstreamReader(void)
{
	fclose(m_file);
}


inline BitstreamReader::STATUS 
FileBitstreamReader::doReadBits(u32 *bits, int nbits, bool *new_refill,
                                u8 *new_byte_buf, int *new_bit_ptr)
{
	if (nbits < 0 || nbits > 32)
		return STS_ERR_INVALID_ARGUMENTS;

	*new_refill = m_refill;
	*new_byte_buf = m_byteBuf;
	*new_bit_ptr = m_bitPtr;
	*bits = 0;

	while (nbits > 0) {
		if (*new_refill) {
			int c = getc(m_file);
			if (c == EOF) {
				if (ferror(m_file)) {
					return STS_ERR_IO;
				}
				clearerr(m_file);
				return STS_EOF;
			}

			*new_byte_buf = (u8)c;
			*new_bit_ptr = 7;

			*new_refill = false;
		}
		*bits <<= 1;
		*bits |= (((u32)1 << *new_bit_ptr) & *new_byte_buf) != 0;

		if (--(*new_bit_ptr) < 0)
			*new_refill = true;

		nbits--;
	}

	return STS_OK;
}


BitstreamReader::STATUS 
FileBitstreamReader::readBits(u32 *bits, int nbits)
{
	STATUS sts;
	bool new_refill;
	u8 new_byte_buf;
	int new_bit_ptr;
	fpos_t old_file_pos;

	if (fgetpos(m_file,&old_file_pos) != 0)
		return STS_ERR_IO;

	sts = doReadBits(bits, nbits, &new_refill, &new_byte_buf, &new_bit_ptr);
	if (sts != STS_OK) {
		fsetpos(m_file,&old_file_pos);
		return sts;
	}

	m_refill = new_refill;
	m_byteBuf = new_byte_buf;
	m_bitPtr = new_bit_ptr;

	return sts;
}




BitstreamReader::STATUS 
FileBitstreamReader::peekBits(u32 *bits, int nbits)
{
	STATUS sts;
	bool new_refill;
	u8 new_byte_buf;
	int new_bit_ptr;
	fpos_t old_file_pos;

	if (fgetpos(m_file,&old_file_pos) != 0)
		return STS_ERR_IO;

	sts = doReadBits(bits, nbits, &new_refill, &new_byte_buf, &new_bit_ptr);
	
	fsetpos(m_file,&old_file_pos);

	return sts;
}


BitstreamReader::STATUS 
FileBitstreamReader::skipBits(int nbits)
{
	STATUS sts;
	u32 dummy;

	sts = readBits(&dummy,nbits);

	return sts;
}


