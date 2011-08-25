#ifndef MB_LAYER_BITSTREAM_PARSER_H
#define MB_LAYER_BITSTREAM_PARSER_H

#include "block_layer_bitstream_parser.h"
#include "vlc_MBA.h"
#include "vlc_MTYPE.h"
#include "vlc_MVD.h"
#include "vlc_CBP.h"

class MBLayerBitstreamParser : public BitstreamParser {
public:
	MBLayerBitstreamParser(void);
	virtual ~MBLayerBitstreamParser(void);

	virtual STATUS parse(BitstreamReader * bsr,
						EventHandler *ev_hdlr,
						u32 quant);
private:
	BlockLayerBitstreamParser *m_blp;
	VLC_MBA *m_mba_psr;
	VLC_MTYPE *m_mtype_psr;
	VLC_MVD *m_mvd_psr;
	VLC_CBP *m_cbp_psr;

	virtual STATUS parse(BitstreamReader * bsr,	EventHandler *ev_hdlr) { return STS_ERR_INTERNAL; }

};


#endif /* MB_LAYER_BITSTREAM_PARSER_H */