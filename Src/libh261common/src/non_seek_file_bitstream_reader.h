#ifndef NON_SEEK_FILE_BITSTREAM_READER_H
#define NON_SEEK_FILE_BITSTREAM_READER_H

#include <stdio.h>

#include "bitstream_reader.h"

class NonSeekFileBitstreamReader : public BitstreamReader {
public:
	explicit NonSeekFileBitstreamReader(FILE *fp);
	virtual ~NonSeekFileBitstreamReader(void);
	virtual STATUS readBits(u32 *bits, int nbits);
	virtual STATUS peekBits(u32 *bits, int nbits);
	virtual STATUS skipBits(int nbits);

private:
	enum ACCESS_MODE {
		ACC_READ,
		ACC_PEEK,
		ACC_SKIP
	};
	

	STATUS accessBits(u32 *bits, int nbits, ACCESS_MODE acc_mode);
	STATUS refillBuffer(int buff_idx);
	

private:
	struct Buffer {
		enum {BUFFER_SIZE = BUFSIZ};
		u8 data[BUFFER_SIZE];
		u8 *endPtr;
		bool eofHit;
	} m_buffs[2];

	struct State {
		int buffIdx;
		u8 *bytePtr;
		int bitPtr;
	} m_curr_state;

	bool m_need_refill;
	FILE *m_file;

};

#endif /* NON_SEEK_FILE_BITSTREAM_READER_H */