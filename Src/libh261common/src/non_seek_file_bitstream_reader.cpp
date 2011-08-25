#include "non_seek_file_bitstream_reader.h"


NonSeekFileBitstreamReader::NonSeekFileBitstreamReader(FILE *fp)
: m_need_refill(true), m_file(fp)
{
	int i;

	for (i=0; i<2; i++) {
		Buffer *curr_buff = &m_buffs[i];

		curr_buff->endPtr = curr_buff->data;
		curr_buff->eofHit = false;
	}

	m_curr_state.buffIdx = 0;
	m_curr_state.bytePtr = m_buffs[0].data;
	m_curr_state.bitPtr = 7;
}





NonSeekFileBitstreamReader::~NonSeekFileBitstreamReader(void)
{
	if (m_file) {
		fclose(m_file);
	}
}





BitstreamReader::STATUS 
NonSeekFileBitstreamReader::refillBuffer(int buff_idx)
{
	Buffer *curr_buff = &m_buffs[buff_idx];
	size_t sz = Buffer::BUFFER_SIZE;
	STATUS sts = STS_OK;
	curr_buff->endPtr = curr_buff->data;

	if (curr_buff->eofHit)
		return STS_EOF;

	while (sz > 0) {

		size_t nbytes = fread(curr_buff->endPtr,1,sz,m_file);
		if (nbytes == 0) {
			curr_buff->eofHit = true;
			if (ferror(m_file))
				return STS_ERR_IO;
			break;
		}

		sz -= nbytes;
		curr_buff->endPtr += nbytes;
	}

	if (curr_buff->data == curr_buff->endPtr)
		sts = STS_EOF;

	return sts;
}



BitstreamReader::STATUS 
NonSeekFileBitstreamReader::accessBits(u32 *bits, int nbits, NonSeekFileBitstreamReader::ACCESS_MODE acc_mode)
{
	if (nbits < 0 || nbits > 32)
		return STS_ERR_INVALID_ARGUMENTS;

	if (acc_mode != ACC_SKIP)
		*bits = 0;

	State new_state = m_curr_state;

	while (nbits > 0) {
		Buffer *curr_buff = &m_buffs[new_state.buffIdx];

		if (new_state.bytePtr == curr_buff->endPtr) {
			if (curr_buff->eofHit)
				return STS_EOF;

			int new_buff_idx = (new_state.buffIdx + 1) % 2;
			if (m_need_refill) {
				STATUS sts = refillBuffer(new_buff_idx);
				if (sts != STS_OK)
					return sts;

			}

			m_need_refill = (acc_mode != ACC_PEEK);
			new_state.buffIdx = new_buff_idx;
			curr_buff = &m_buffs[new_state.buffIdx];
			new_state.bytePtr = curr_buff->data;
			new_state.bitPtr = 7;
		}

		if (acc_mode != ACC_SKIP) {
			*bits <<= 1;
			*bits |= ((*new_state.bytePtr &  (u8(1) << new_state.bitPtr)) ? 1 : 0);
		}

		if (new_state.bitPtr-- == 0) {
			new_state.bytePtr++;
			new_state.bitPtr = 7;
		}

		nbits--;
	}

	if (acc_mode != ACC_PEEK)
		m_curr_state = new_state;

	return STS_OK;
}




BitstreamReader::STATUS 
NonSeekFileBitstreamReader::readBits(u32 *bits, int nbits)
{
	STATUS sts;

	sts = accessBits(bits,nbits,ACC_READ);

	return sts;
}




BitstreamReader::STATUS 
NonSeekFileBitstreamReader::peekBits(u32 *bits, int nbits)
{
	STATUS sts;

	sts = accessBits(bits,nbits,ACC_PEEK);

	return sts;
}




BitstreamReader::STATUS 
NonSeekFileBitstreamReader::skipBits(int nbits)
{
	STATUS sts;

	sts = accessBits(NULL,nbits,ACC_SKIP);

	return sts;
}
