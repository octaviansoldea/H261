#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "bitstream_reader.h"

int main(int argc, char *argv[])
{
	BitstreamReader *br;
	BitstreamReader::STATUS sts;
	struct _stati64 st;
	unsigned __int64 file_size;
	const char *in_file;
	const char *out_file;
	int bit_count = 0;
	int bit_count_mod_8 = 0;
	unsigned __int64 byte_count = 0;
	srand(0);
	FILE *out_fp;
	int i;
	u32 bits;


	if (argc != 3) {
		fprintf(stderr,"Usage: %s <in_file> <out_file>\n",argv[0]);
		exit(1);
	}

	in_file = argv[1];
	out_file = argv[2];

	if (_stati64(in_file,&st) < 0) {
		perror("Error: Cannot stat input file");
		exit(1);
	}
	
	file_size = st.st_size;
 
	printf("Size of file '%s' is: %I64u bytes\n",in_file,(__int64)file_size);

	sts = BitstreamReader::create(in_file,&br);
	if (sts != BitstreamReader::STS_OK) {
		fprintf(stderr,"Error: Cannot create bitstream reader\n");
		exit(1);
	}

	out_fp = fopen(out_file,"w");
	if (out_fp == NULL) {
		perror("Error: Cannot open output file");
		br->destroy();
		exit(1);
	}


	while (file_size - byte_count >= 4) {
		int num_bits = (int)((double)rand()/RAND_MAX*32);

	//	printf("Attempting to read %d bytes\n",num_bits);

		sts = br->readBits(&bits,num_bits);

		if (sts != BitstreamReader::STS_OK) {
			fprintf(stderr,"Error reading %d bits from the input file\n",num_bits);
			br->destroy();
			exit(1);
		}

		for (i = num_bits-1; i>=0; i--) {
			if (bits & (u32(1) << i)) {
				putc('1',out_fp);
			} else {
				putc('0',out_fp);
			}
		}
	
//		bit_count += num_bits;
//		byte_count = bit_count/8;
		bit_count = (bit_count_mod_8 + num_bits);
		byte_count += (bit_count)/8;
		bit_count_mod_8 = bit_count % 8;
	}

	bit_count = (32 - (bit_count%32));
	sts = br->readBits(&bits,bit_count);
	
	if (sts != BitstreamReader::STS_OK) {
		fprintf(stderr,"Error reading %d bits from the input file\n",32-bit_count);
		br->destroy();
		exit(1);
	}

	for (i = bit_count -1; i>=0; i--) {

		if (bits & (u32(1) << i)) {
			putc('1',out_fp);
		} else {
			putc('0',out_fp);
		}
	}	

	fclose(out_fp);

	br->destroy();

	return 0;
} 