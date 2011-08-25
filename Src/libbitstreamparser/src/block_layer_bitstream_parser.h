#ifndef BLOCK_LAYER_BITSTREAM_PARSER_H
#define BLOCK_LAYER_BITSTREAM_PARSER_H

#include "bitstream_parser.h"

class VLC_TCOEFF;

class BlockLayerBitstreamParser : public BitstreamParser {
public:
	//TBR explicit BlockLayerBitstreamParser(void);

	virtual STATUS parse(BitstreamReader *bsr, EventHandler *ev_hdlr,
						u32 quant, u32 cbp, bool intra);

	//virtual ~BlockLayerBitstreamParser(void);
private:
	virtual STATUS parse(BitstreamReader *bsr, EventHandler *ev_hdlr) { return STS_ERR_INTERNAL;}
};


#endif /* GOB_LAYER_BITSTREAM_PARSER_H */
