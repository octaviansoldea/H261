#ifndef GOB_LAYER_BITSTREAM_PARSER_H
#define GOB_LAYER_BITSTREAM_PARSER_H

#include "mb_layer_bitstream_parser.h"


class GOBLayerBitstreamParser : public BitstreamParser {
public:
	explicit GOBLayerBitstreamParser(MBLayerBitstreamParser *mblp);

	virtual STATUS parse(BitstreamReader *bsr, EventHandler *ev_hdlr);

	virtual ~GOBLayerBitstreamParser(void);
private:
	MBLayerBitstreamParser *m_mblp;
};


#endif /* GOB_LAYER_BITSTREAM_PARSER_H */
