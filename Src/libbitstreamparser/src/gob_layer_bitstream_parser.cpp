#include <stdio.h>
#include "gob_layer_bitstream_parser.h"

GOBLayerBitstreamParser::GOBLayerBitstreamParser(MBLayerBitstreamParser *mblp)
: m_mblp(mblp)
{
}



GOBLayerBitstreamParser::~GOBLayerBitstreamParser(void)
{
	delete m_mblp;
}



BitstreamParser::STATUS 
GOBLayerBitstreamParser::parse(BitstreamReader *bsr, EventHandler *ev_hdlr)
{
	STATUS sts;
	BitstreamReader::STATUS bsr_sts;
	EventHandler::STATUS ev_hdlr_sts;
	u32 val;
	Token token;
	u32 gquant;

	ev_hdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_GOB_BEGIN);
	switch (ev_hdlr_sts) {
	case EventHandler::STS_OK:
		break;

	case EventHandler::STS_ERROR:
	default:
		return STS_ERR_TOKEN_HANDLER;
	}

	//GOB start code
	bsr_sts = bsr->readBits(&val,16);
	switch (bsr_sts) {
	case BitstreamReader::STS_OK: 
		if (val != GOB_START_CODE)
			return STS_ERR_BITSTREAM_SYNTAX;
		token = Token(Token::TOK_GBSC,val);
		ev_hdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&token);
		if (ev_hdlr_sts != EventHandler::STS_OK)
			return STS_ERR_TOKEN_HANDLER;
		break;

	case BitstreamReader::STS_EOF:
		return STS_ERR_UNEXPECTED_EOF;

	default:
		return STS_ERR_BITSTREAM_IO;
	}

	//GOB number
	bsr_sts = bsr->readBits(&val,4);
	switch (bsr_sts) {
	case BitstreamReader::STS_OK: 
		token = Token(Token::TOK_GN,val);
		ev_hdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&token);
		if (ev_hdlr_sts != EventHandler::STS_OK)
			return STS_ERR_TOKEN_HANDLER;
		break;

	case BitstreamReader::STS_EOF:
		return STS_ERR_UNEXPECTED_EOF;

	default:
		return STS_ERR_BITSTREAM_IO;
	}


	//GQUANT
	bsr_sts = bsr->readBits(&val,5);
	switch (bsr_sts) {
	case BitstreamReader::STS_OK: 
		token = Token(Token::TOK_GQUANT,val);
		ev_hdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&token);
		if (ev_hdlr_sts != EventHandler::STS_OK)
			return STS_ERR_TOKEN_HANDLER;
		break;

	case BitstreamReader::STS_EOF:
		return STS_ERR_UNEXPECTED_EOF;

	default:
		return STS_ERR_BITSTREAM_IO;
	}

	gquant = val;

	for (;;) {
		//GEI
		bsr_sts = bsr->readBits(&val,1);
		switch (bsr_sts) {
		case BitstreamReader::STS_OK: 
			token = Token(Token::TOK_GEI,val);
			ev_hdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&token);
			if (ev_hdlr_sts != EventHandler::STS_OK)
				return STS_ERR_TOKEN_HANDLER;
			break;

		case BitstreamReader::STS_EOF:
			return STS_ERR_UNEXPECTED_EOF;

		default:
			return STS_ERR_BITSTREAM_IO;
		}

		if (val == 0)
			break;

		//GSPARE
		bsr_sts = bsr->readBits(&val,8);
		switch (bsr_sts) {
		case BitstreamReader::STS_OK: 
			token = Token(Token::TOK_GSPARE,val);
			ev_hdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&token);
			if (ev_hdlr_sts != EventHandler::STS_OK)
				return STS_ERR_TOKEN_HANDLER;
			break;

		case BitstreamReader::STS_EOF:
			return STS_ERR_UNEXPECTED_EOF;

		default:
			return STS_ERR_BITSTREAM_IO;
		}

	}

	//Parse macroblock
	sts = m_mblp->parse(bsr,ev_hdlr,gquant);

	if (sts != STS_OK)
		return sts;

	ev_hdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_GOB_END);
	switch (ev_hdlr_sts) {
	case EventHandler::STS_OK:
		break;

	case EventHandler::STS_ERROR:
	default:
		return STS_ERR_TOKEN_HANDLER;
	}

	return STS_OK;
}
