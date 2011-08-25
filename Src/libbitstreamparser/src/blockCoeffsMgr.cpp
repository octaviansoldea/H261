#include <iostream>

#include "BlockCoeffsMgr.h"

using namespace std;

BlockCoeffsMgr::BlockCoeffsMgr() : m_nCol(0), m_nLine(0), m_tcoeff_psr(new VLC_TCOEFF) {
}

BlockCoeffsMgr::~BlockCoeffsMgr() {
	delete m_tcoeff_psr;
}

BlockCoeffsMgr::STATUS BlockCoeffsMgr::parseCoefficients(BitstreamReader *bsr, u32 quant, bool intra) {

	TCoeff coeff;
	bool first_coeff = true;
	bool intra_DC = intra;

	do {
		VLC_TCOEFF::STATUS vlc_sts = 
			m_tcoeff_psr->getNextTCOEFF(&coeff, bsr, intra_DC ? 0 : quant, first_coeff,	intra_DC);
		switch (vlc_sts) {
				case VLC_TCOEFF::STS_EOF:
					 return STS_ERR_UNEXPECTED_EOF;
				default:
					return STS_ERR_BITSTREAM_SYNTAX;

				case VLC_TCOEFF::STS_OK: {
					Token tok_coeff(Token::TOK_TCOEFF, coeff.m_nRun, coeff.m_RecLevel, coeff.m_bIsEOB);
					insertNext(tok_coeff);
					}
					break;
		}

		first_coeff = intra_DC = false;
	} while (!coeff.m_bIsEOB);
	return(BlockCoeffsMgr::STS_OK);
}

Token BlockCoeffsMgr::getCoeff(int anCol, int anLine) const {
	if(isIndexValid(anCol) && isIndexValid(anLine)) {
		return(m_tblCoeffs[anCol][anLine]);
	} else {
		cout << "Problems in coefficients TBR" << endl;
		exit(-1);
	}
}

Token BlockCoeffsMgr::getCoeff(int anIndxLinear) const {
	div_t divRes = div(anIndxLinear, 8);
	int nLine = divRes.quot;
	int nCol = divRes.rem;
	return(getCoeff(nCol, nLine));
}

int BlockCoeffsMgr::getElemsNr() const {
	return(m_nCol * 8 + m_nLine);
}

void BlockCoeffsMgr::insertNext(Token aToken) {
	if(isFull()) {
		cout << "Problems in coefficients TBR" << endl;
		exit(-1);
	}
	m_tblCoeffs[m_nCol][m_nLine] = aToken;
	m_nLine++;
	if(m_nLine == 8) {
		m_nLine = 0;
		m_nCol++;
	}
}

bool BlockCoeffsMgr::isIndexValid(int anIndex) const {
	if((anIndex >= 0) && (anIndex < 8)) 
		return(true);
	return(false);
}

bool BlockCoeffsMgr::isFull() const {
	return(m_nCol == 8);
}