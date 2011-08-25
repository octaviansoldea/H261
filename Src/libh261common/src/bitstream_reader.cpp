#include <new>

//#include "bistream_reader.h"
#include "memory_bitstream_reader.h"
#include "file_bitstream_reader.h"
#include "non_seek_file_bitstream_reader.h"

using namespace std;


BitstreamReader::STATUS 
BitstreamReader::create(const u8 *buffer, size_t buffer_size_in_bytes, BitstreamReader **br)
{
	BitstreamReader *brd;

	try {
		brd = new MemoryBitstreamReader(buffer,buffer_size_in_bytes);
	}
	catch (bad_alloc) {
		brd = NULL;
	}
	catch (...) {
		brd = NULL;
	}

	if (brd == NULL)
		return STS_ERR_NO_MEMORY;

	*br = brd;

	return STS_OK;
}




BitstreamReader::STATUS BitstreamReader::create(const char *filename, BitstreamReader **br)
{
	FILE *fp;
	BitstreamReader *brd;

	fp = fopen(filename,"rb");

	if (fp == NULL)
		return STS_ERR_IO;

	try {
//		brd = new FileBitstreamReader(fp);
		brd = new NonSeekFileBitstreamReader(fp);
	}
	catch (bad_alloc) {
		brd = NULL;
	}
	catch (...) {
		brd = NULL;
	}

	if (brd == NULL) {
		fclose(fp);
		*br = NULL;
		return STS_ERR_NO_MEMORY;
	}

	*br = brd;
	return STS_OK;
}


