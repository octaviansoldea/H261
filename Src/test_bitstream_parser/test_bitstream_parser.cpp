//#define MEMORY_MAPPED_BITSTREAM_READER

#ifdef MEMORY_MAPPED_BITSTREAM_READER
#include <windows.h>
#endif

#include <iostream>
#include "xml_dump_event_handler.h"
#include "bitstream_parser.h"
#include "bitstream_reader.h"

using namespace std;

int main(int argc, char *argv[])
{

	if (argc != 2) {
		cerr << "Usage: test_bitstream_parser <h261 bitstream file>" << endl;
		exit (1);
	}

	char *in_file = argv[1];

	BitstreamReader *bsr;
	BitstreamReader::STATUS bsr_sts;
	BitstreamParser *psr;
	BitstreamParser::STATUS psr_sts;
	XMLDumpEventHandler xml_dump_ev_hdlr(cout);

#ifdef MEMORY_MAPPED_BITSTREAM_READER
	HANDLE hFile;
	HANDLE hFileMapping;
	u8 *ptr;
	DWORD fileSize;
	DWORD fileSizeHigh;

	hFile = CreateFile(in_file,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		cerr << "Error: Cannot open file: " << in_file << endl;
		exit(1);
	}

	fileSize = GetFileSize(hFile,&fileSizeHigh);
	if (fileSizeHigh != 0) {
		cerr << "Error: File size is too large" << endl;
		CloseHandle(hFile);
		exit(1);
	}

	hFileMapping = CreateFileMapping(hFile,NULL,PAGE_READONLY|SEC_COMMIT,0,0,NULL);
	CloseHandle(hFile);

	if (hFileMapping == NULL) {
		cerr << "Error: Cannot create mapping for file: " << in_file << endl;
		exit(1);
	}

	ptr = (u8*)MapViewOfFile(hFileMapping,FILE_MAP_READ,0,0,0);
	CloseHandle(hFileMapping);
	if (ptr == NULL) {
		cerr << "Error: Cannot map file to memory" << endl;
		exit(1);
	}

	bsr_sts = BitstreamReader::create(ptr,fileSize,&bsr);
#else
	bsr_sts = BitstreamReader::create(in_file, &bsr);
#endif
	if (bsr_sts != BitstreamReader::STS_OK) {
		cerr << "Error: Cannot create BitstreamReader from file: " << in_file << endl;
		exit(1);
	}

	psr_sts = BitstreamParser::create(&psr);
	if (psr_sts != BitstreamParser::STS_OK) {
		cerr << "Error: Cannot create BitstreamParser" << endl;
		bsr->destroy();
#ifdef MEMORY_MAPPED_BITSTREAM_READER
		UnmapViewOfFile(ptr);
#endif
		exit(1);
	}

	xml_dump_ev_hdlr.handleEvent(EventHandler::EV_BITSTREAM_BEGIN,NULL);

	u32 dummy;
	while (bsr->peekBits(&dummy,1) == BitstreamReader::STS_OK) {

		psr_sts = psr->parse(bsr,&xml_dump_ev_hdlr);

		if (psr_sts != BitstreamParser::STS_OK) {
			cerr << "Error: Bitstream parse error" << endl;
			psr->destroy();
			bsr->destroy();
#ifdef MEMORY_MAPPED_BITSTREAM_READER
			UnmapViewOfFile(ptr);
#endif
			exit(1);
		}
	}
	xml_dump_ev_hdlr.handleEvent(EventHandler::EV_BITSTREAM_END,NULL);

	psr->destroy();
	bsr->destroy();

#ifdef MEMORY_MAPPED_BITSTREAM_READER
	UnmapViewOfFile(ptr);
#endif
	return 0;
}
