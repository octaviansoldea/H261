#include <stdio.h>
#include "picture_layer_bitstream_parser.h"

PictureLayerBitstreamParser::PictureLayerBitstreamParser(GOBLayerBitstreamParser *glp)
: m_glp(glp)
{
}

PictureLayerBitstreamParser::~PictureLayerBitstreamParser(void)
{
	delete m_glp;
}


BitstreamParser::STATUS PictureLayerBitstreamParser::
parse(BitstreamReader *bsr, EventHandler *ev_hdlr)
{
	STATUS sts;
	BitstreamReader::STATUS bsr_sts;
	EventHandler::STATUS ev_hdlr_sts;
	u32 val;
	Token token;
	int ngobs;

	ev_hdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_PICTURE_BEGIN);
	switch (ev_hdlr_sts) {
	case EventHandler::STS_OK:
		break;

	case EventHandler::STS_ERROR:
	default:
		return STS_ERR_TOKEN_HANDLER;
	}

	//Picture start code
	bsr_sts = bsr->readBits(&val,20);
	switch (bsr_sts) {
	case BitstreamReader::STS_OK: 
		if (val != PICTURE_START_CODE)
			return STS_ERR_BITSTREAM_SYNTAX;
		token = Token(Token::TOK_PSC,val);
		ev_hdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&token);
		if (ev_hdlr_sts != EventHandler::STS_OK)
			return STS_ERR_TOKEN_HANDLER;
		break;

	case BitstreamReader::STS_EOF:
		return STS_ERR_UNEXPECTED_EOF;

	default:
		return STS_ERR_BITSTREAM_IO;
	}

	//Time Reference
	bsr_sts = bsr->readBits(&val,5);
	switch (bsr_sts) {
	case BitstreamReader::STS_OK: 
		token = Token(Token::TOK_TR,val);
		ev_hdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&token);
		if (ev_hdlr_sts != EventHandler::STS_OK)
			return STS_ERR_TOKEN_HANDLER;
		break;

	case BitstreamReader::STS_EOF:
		return STS_ERR_UNEXPECTED_EOF;

	default:
		return STS_ERR_BITSTREAM_IO;
	}


	//PTYPE
	bsr_sts = bsr->readBits(&val,6);
	switch (bsr_sts) {
	case BitstreamReader::STS_OK: 
		token = Token(Token::TOK_PTYPE,val);
		ev_hdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_TOKEN,&token);
		if (ev_hdlr_sts != EventHandler::STS_OK)
			return STS_ERR_TOKEN_HANDLER;
		break;

	case BitstreamReader::STS_EOF:
		return STS_ERR_UNEXPECTED_EOF;

	default:
		return STS_ERR_BITSTREAM_IO;
	}

	if (val & 0x04) 
		ngobs = 6; //CIF
	else
		ngobs = 3; //QCIF

	for (;;) {
		//PEI
		bsr_sts = bsr->readBits(&val,1);
		switch (bsr_sts) {
		case BitstreamReader::STS_OK: 
			token = Token(Token::TOK_PEI,val);
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

		//PSPARE
		bsr_sts = bsr->readBits(&val,8);
		switch (bsr_sts) {
		case BitstreamReader::STS_OK: 
			token = Token(Token::TOK_PSPARE,val);
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

	int gob;
	for (gob=0; gob < ngobs; gob++) {
		//Parse GOB
		sts = m_glp->parse(bsr,ev_hdlr);

		if (sts != STS_OK)
			return sts;
	}

	ev_hdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_PICTURE_END);
	switch (ev_hdlr_sts) {
	case EventHandler::STS_OK:
		break;

	case EventHandler::STS_ERROR:
	default:
		return STS_ERR_TOKEN_HANDLER;
	}

	return STS_OK;
}
