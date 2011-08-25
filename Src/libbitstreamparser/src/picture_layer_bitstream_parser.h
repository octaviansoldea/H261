#ifndef PICTURE_LAYER_BITSTREAM_PARSER_H
#define PICTURE_LAYER_BITSTREAM_PARSER_H

#include "bitstream_parser.h"
#include "gob_layer_bitstream_parser.h"

class PictureLayerBitstreamParser : public BitstreamParser {
public:
	explicit PictureLayerBitstreamParser(GOBLayerBitstreamParser *glp);
	virtual STATUS parse(BitstreamReader * bsr,EventHandler *ev_hdlr);
	virtual ~PictureLayerBitstreamParser(void);

private:
	GOBLayerBitstreamParser *m_glp;
};

#endif /* PICTURE_LAYER_BITSTREAM_PARSER_H */