#ifndef BLOCK_COEFFS_MGR_H
#define BLOCK_COEFFS_MGR_H

#include "event_handler.h"
#include "Token.h"
#include "vlc_TCOEFF.h"

struct BlockCoeffsMgr {

	enum STATUS {
		STS_OK = 0,
		STS_ERR_UNEXPECTED_EOF,
		STS_ERR_BITSTREAM_SYNTAX,
		STS_ERR
	};

	BlockCoeffsMgr();
	~BlockCoeffsMgr();

	STATUS parseCoefficients(BitstreamReader *bsr, u32 quant, bool intra);
	
	Token getCoeff(int anCol, int anLine) const;
	Token getCoeff(int anIndxLinear) const;
	int getElemsNr() const;
private:

	void insertNext(Token aToken);
	
	Token m_tblCoeffs[8][8];

	int m_nCol;
	int m_nLine;

	bool isFull() const;
	bool isIndexValid(int anIndex) const;

	VLC_TCOEFF *m_tcoeff_psr;
};

#endif //BLOCK_COEFFS_MGR_H