#include <vector>

#include "mb_layer_bitstream_parser.h"

using namespace std;

MBLayerBitstreamParser::MBLayerBitstreamParser(void)
: 
m_blp(new BlockLayerBitstreamParser),
m_mba_psr(new VLC_MBA),
m_mtype_psr(new VLC_MTYPE),
m_mvd_psr(new VLC_MVD),
m_cbp_psr(new VLC_CBP)
{}


MBLayerBitstreamParser::~MBLayerBitstreamParser(void)
{
	delete m_cbp_psr;
	delete m_mvd_psr;
	delete m_mtype_psr;
	delete m_mba_psr;
	delete m_blp;
}



BitstreamParser::STATUS 
MBLayerBitstreamParser::parse(BitstreamReader *bsr, EventHandler *ev_hdlr, u32 quant)
{
	VLC_MBA::STATUS mba_sts;
	int mba;

	VLC_MTYPE::STATUS mtype_sts;
	u32 mtype;

	VLC_MVD::STATUS mvd_sts;
	int mv_x;
	int mv_y;

	VLC_CBP::STATUS cbp_sts;
	int cbp = 0; //EMIL: type should be u32!!!


	u32 val;
	BitstreamReader::STATUS bsr_sts;

	while ((bsr_sts = bsr->peekBits(&val,16)) == BitstreamReader::STS_OK &&
		val != START_CODE_PREFIX) {
		EventHandler::STATUS evhdlr_sts;

		//MBA
		mba_sts = m_mba_psr->getNextMBA(&mba, bsr);
		switch (mba_sts) {
			case VLC_MBA::STS_EOF:
				return STS_ERR_UNEXPECTED_EOF;

			default:
				return STS_ERR_BITSTREAM_SYNTAX;

			case VLC_MBA::STS_OK:
				break;
		}

		if (mba == VLC_MBA::MBA_stuffing) {
			Token tok_mba_stuff(Token::TOK_MBA_STUFFING);

			evhdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&tok_mba_stuff);
			if (evhdlr_sts != EventHandler::STS_OK)
				return STS_ERR_TOKEN_HANDLER;

			continue;
		}

		evhdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_MB_BEGIN);
		if (evhdlr_sts != EventHandler::STS_OK)
			return STS_ERR_TOKEN_HANDLER;

		Token tok_mba(Token::TOK_MBA,(u32)mba);
		evhdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&tok_mba);
		if (evhdlr_sts != EventHandler::STS_OK)
			return STS_ERR_TOKEN_HANDLER;


		//MTYPE
		mtype_sts = m_mtype_psr->getNextMTYPE(&mtype, bsr);
		switch (mtype_sts) {
			case VLC_MTYPE::STS_EOF:
				return STS_ERR_UNEXPECTED_EOF;

			default:
				return STS_ERR_BITSTREAM_SYNTAX;

			case VLC_MTYPE::STS_OK:
				break;
		}

		Token tok_mtype(Token::TOK_MTYPE, mtype);
		evhdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&tok_mtype);
		if (evhdlr_sts != EventHandler::STS_OK)
			return STS_ERR_TOKEN_HANDLER;

		bool has_mquant = ((mtype & VLC_MTYPE::FIELD_MQUANT) != 0);
		bool has_mvd = ((mtype & VLC_MTYPE::FIELD_MVD) != 0);
		bool has_cbp = ((mtype & VLC_MTYPE::FIELD_CBP) != 0);
		bool has_tcoeff = ((mtype & VLC_MTYPE::FIELD_TCOEFF) != 0);
		bool is_intra = ((mtype & VLC_MTYPE::FIELD_INTRA) != 0);

		//MQUANT
		if (has_mquant) {
			u32 mquant;

			bsr_sts = bsr->readBits(&mquant,5);
			switch (bsr_sts) {
				case BitstreamReader::STS_EOF:
					return STS_ERR_UNEXPECTED_EOF;

				default:
					return STS_ERR_BITSTREAM_SYNTAX;

				case BitstreamReader::STS_OK:
					break;
			}

			Token tok_mquant(Token::TOK_MQUANT,mquant);
			evhdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&tok_mquant);
			if (evhdlr_sts != EventHandler::STS_OK)
				return STS_ERR_TOKEN_HANDLER;

			quant = mquant;
		}

		//MVD
		if (has_mvd) {
			mvd_sts = m_mvd_psr->getNextMVD(&mv_x, &mv_y, bsr);
			switch (mvd_sts) {
			case VLC_MVD::STS_EOF:
				return STS_ERR_UNEXPECTED_EOF;

			default:
				return STS_ERR_BITSTREAM_SYNTAX;

			case VLC_MVD::STS_OK:
				break;
			}
			
			Token tok_mvd(Token::TOK_MVD,(s16)mv_x,(s16)mv_y);
			evhdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&tok_mvd);
			if (evhdlr_sts != EventHandler::STS_OK)
				return STS_ERR_TOKEN_HANDLER;

		}

		//CBP
		if (has_cbp) {
			cbp_sts = m_cbp_psr->getNextCBP(&cbp, bsr);
			switch (mvd_sts) {
			case VLC_CBP::STS_EOF:
				return STS_ERR_UNEXPECTED_EOF;

			default:
				return STS_ERR_BITSTREAM_SYNTAX;

			case VLC_CBP::STS_OK:
				break;
			}

			Token tok_cbp(Token::TOK_CBP,(u32)cbp);
			evhdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&tok_cbp);
			if (evhdlr_sts != EventHandler::STS_OK)
				return STS_ERR_TOKEN_HANDLER;
		}


		if (has_tcoeff) {
			BlockLayerBitstreamParser::STATUS blp_sts;

			blp_sts = m_blp->parse(bsr,ev_hdlr,quant,cbp,is_intra);

			if (blp_sts != STS_OK)
				return blp_sts;
		}

		evhdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_MB_END);
		if (evhdlr_sts != EventHandler::STS_OK)
			return STS_ERR_TOKEN_HANDLER;
	}

	switch (bsr_sts) {
	case BitstreamReader::STS_OK:
		return STS_OK;

	case BitstreamReader::STS_EOF:
		while ((bsr_sts = bsr->skipBits(1)) == BitstreamReader::STS_OK) {
			//Skip everything until EOF
		}

		return STS_OK;

	default:
		return STS_ERR_BITSTREAM_IO;
	}
}
