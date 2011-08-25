#include "vlc_tcoeff.h"
#include "block_layer_bitstream_parser.h"
#include "blockCoeffsMgr.h"


BitstreamParser::STATUS 
BlockLayerBitstreamParser::parse(BitstreamReader *bsr, EventHandler *ev_hdlr,
								 u32 quant, u32 cbp, bool intra)
{
	EventHandler::STATUS evhdlr_sts;

	u32 mask;
	for (mask = 0x1<<5; mask!=0; mask>>=1) {
		evhdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_BLOCK_BEGIN);
		if (evhdlr_sts != EventHandler::STS_OK)
			return STS_ERR_TOKEN_HANDLER;

		if (intra || (cbp & mask)) {
			BlockCoeffsMgr blkCoeffsMgr;
			BlockCoeffsMgr::STATUS sts_blkCoeffs = blkCoeffsMgr.parseCoefficients(bsr, quant, intra);
			
			switch(sts_blkCoeffs) {
				case BlockCoeffsMgr::STS_ERR_BITSTREAM_SYNTAX :
					return(STS_ERR_BITSTREAM_SYNTAX);
				case BlockCoeffsMgr::STS_ERR_UNEXPECTED_EOF:
					return(STS_ERR_UNEXPECTED_EOF);
			}

			evhdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_BLOCK_COEFFS, &blkCoeffsMgr);
			if (evhdlr_sts != EventHandler::STS_OK)
				return STS_ERR_TOKEN_HANDLER;
		}
			
		evhdlr_sts = ev_hdlr->handleEvent(EventHandler::EV_BLOCK_END);
		if (evhdlr_sts != EventHandler::STS_OK)
			return STS_ERR_TOKEN_HANDLER;
	}

	return STS_OK;
}
