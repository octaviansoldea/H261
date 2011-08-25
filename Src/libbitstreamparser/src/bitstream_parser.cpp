#include <new>
#include "bitstream_parser.h"
#include "picture_layer_bitstream_parser.h"
#include "gob_layer_bitstream_parser.h"
#include "mb_layer_bitstream_parser.h"

using namespace std;


BitstreamParser::STATUS BitstreamParser::create(BitstreamParser **psr)
{
	MBLayerBitstreamParser *mblp;
	GOBLayerBitstreamParser *glp;
	PictureLayerBitstreamParser *plp;


	try {
		mblp = new MBLayerBitstreamParser;
	}
	catch (...) {
		mblp = NULL;
	}

	if (mblp == NULL)
		return STS_ERR_NO_MEMORY;

	
	try {
		glp = new GOBLayerBitstreamParser(mblp);
	}
	catch(...) {
		glp = NULL;
	}

	if (glp == NULL) {
		delete mblp;
		return STS_ERR_NO_MEMORY;
	}

	try {
		plp = new PictureLayerBitstreamParser(glp);
	}
	catch (...) {
		plp = NULL;
	}

	if (plp == NULL) {
		delete glp;
		return STS_ERR_NO_MEMORY;
	}

	*psr = plp;

	return STS_OK;
}

