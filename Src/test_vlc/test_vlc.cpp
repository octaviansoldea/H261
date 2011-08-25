#include <vector>

#include "BasicDefinitions.h"
#include "Singleton.h"
#include "Trace.h"
#include "FileOperations.h"


#include "bitstream_reader.h"

#include "vlc_MBA.h"
#include "vlc_MTYPE.h"
#include "vlc_MVD.h"
#include "vlc_CBP.h"
#include "vlc_TCOEFF.h"

using namespace std;

void write2File(const char * apchFileName, const unsigned char * apuchInfo, int anLen) {
	FILE * fp;
	CheckedFileOpen(&fp, apchFileName, "wb");
	int nI;
	for(nI = 0; nI < anLen; nI++) {
		fprintf(fp, "%c", apuchInfo[nI]);
	}
	fclose(fp);
}

void testMBA() {
	const char * pchFileName = "TestFileName.bin";
	
	unsigned char arruchInfo[MAX_STR_LEN + 1];
	//Introduced string: 22; 34; 2; 16
	arruchInfo[0] = 0x04;
	arruchInfo[1] = 0x60;
	arruchInfo[2] = 0x3D;
	arruchInfo[3] = 0x82;
	arruchInfo[4] = 0xE0;
	write2File(pchFileName, arruchInfo, 5);

	BitstreamReader *pBR;
	BitstreamReader::STATUS sts;
				
	unsigned __int64 file_size = GetFileSizeFromName(pchFileName);
 
	sts = BitstreamReader::create(pchFileName,&pBR);
	if (sts != BitstreamReader::STS_OK) {
		fprintf(stderr,"Error: Cannot create bitstream reader\n");
		exit(1);
	}

	VLC_MBA vlc_MBA;
	int nMBA;
	vlc_MBA.getNextMBA(&nMBA, pBR);
	vlc_MBA.getNextMBA(&nMBA, pBR);
	vlc_MBA.getNextMBA(&nMBA, pBR);
	vlc_MBA.getNextMBA(&nMBA, pBR);

	pBR->destroy();
}

void testMTYPE() {
	const char * pchFileName = "TestFileName.bin";
	
	unsigned char arruchInfo[MAX_STR_LEN + 1];
	//Introduced string: all the values in the table in sequential order
	arruchInfo[0] = 0x10;
	arruchInfo[1] = 0x30;
	arruchInfo[2] = 0x80;
	arruchInfo[3] = 0x40;
	arruchInfo[4] = 0x40;
	arruchInfo[5] = 0x12;
	arruchInfo[6] = 0x82;
	write2File(pchFileName, arruchInfo, 7);

	BitstreamReader *pBR;
	BitstreamReader::STATUS sts;
				
	unsigned __int64 file_size = GetFileSizeFromName(pchFileName);
 
	sts = BitstreamReader::create(pchFileName,&pBR);
	if (sts != BitstreamReader::STS_OK) {
		fprintf(stderr,"Error: Cannot create bitstream reader\n");
		exit(1);
	}
	int arrnMTYPEVals[VLC_MTYPE::MTYPE_MAX] = {
							   VLC_MTYPE::MTYPE_INTRA_TCOEFF,
		                       VLC_MTYPE::MTYPE_INTRA_MQUANT_TCOEFF,
							   VLC_MTYPE::MTYPE_INTER_CBP_TCOEFF,
							   VLC_MTYPE::MTYPE_INTER_MQUANT_CBP_TCOEFF,
							   VLC_MTYPE::MTYPE_INTERMC_MVD,
							   VLC_MTYPE::MTYPE_INTERMC_MVD_CBP_TCOEFF,
							   VLC_MTYPE::MTYPE_INTERMC_MQUANT_MVD_CBP_TCOEFF,
							   VLC_MTYPE::MTYPE_INTERMCFIL_MVD,
							   VLC_MTYPE::MTYPE_INTERMCFIL_MVD_CBP_TCOEFF,
							   VLC_MTYPE::MTYPE_INTERMCFIL_MQUANT_MVD_CBP_TCOEFF
	};

	VLC_MTYPE vlc_MTYPE;
	u32 unMTYPE;
	int nI;
	for(nI = 0; nI < VLC_MTYPE::MTYPE_MAX; nI++) {
		vlc_MTYPE.getNextMTYPE(&unMTYPE, pBR);
		printf("Read %d expected %d\n", unMTYPE, arrnMTYPEVals[nI]);
	}
	

	pBR->destroy();
}

void testMVD() {
	const char * pchFileName = "TestFileName.bin";

	unsigned char arruchInfo[MAX_STR_LEN + 1];
	//Introduced string: -15&17; -1; 4&-28;14&-18
	arruchInfo[0] = 0x03;
	arruchInfo[1] = 0x6C;
	arruchInfo[2] = 0x30;
	arruchInfo[3] = 0x1c;
	arruchInfo[4] = 0x00;
	write2File(pchFileName, arruchInfo, 5);

	BitstreamReader *pBR;
	BitstreamReader::STATUS sts;
				
	unsigned __int64 file_size = GetFileSizeFromName(pchFileName);
 
	sts = BitstreamReader::create(pchFileName,&pBR);
	if (sts != BitstreamReader::STS_OK) {
		fprintf(stderr,"Error: Cannot create bitstream reader\n");
		exit(1);
	}


	VLC_MVD vlc_MVD;
	int nMVDx, nMVDy;
	vlc_MVD.getNextMVD(&nMVDx, &nMVDy, pBR);
	vlc_MVD.getNextMVD(&nMVDx, &nMVDy, pBR);
	vlc_MVD.getNextMVD(&nMVDx, &nMVDy, pBR);
	vlc_MVD.getNextMVD(&nMVDx, &nMVDy, pBR);

	pBR->destroy();
}

void testCBP() {
	const char * pchFileName = "TestFileName.bin";

	unsigned char arruchInfo[MAX_STR_LEN + 1];
	//Introduced string: 20; 63; 41; 59
	arruchInfo[0] = 0x89;
	arruchInfo[1] = 0x83;
	arruchInfo[2] = 0x00;
	arruchInfo[3] = 0x40;
	arruchInfo[4] = 0x00;
	write2File(pchFileName, arruchInfo, 5);

	BitstreamReader *pBR;
	BitstreamReader::STATUS sts;
				
	unsigned __int64 file_size = GetFileSizeFromName(pchFileName);
 
	sts = BitstreamReader::create(pchFileName,&pBR);
	if (sts != BitstreamReader::STS_OK) {
		fprintf(stderr,"Error: Cannot create bitstream reader\n");
		exit(1);
	}


	VLC_CBP vlc_CBP;
	int nCBP;
	vlc_CBP.getNextCBP(&nCBP, pBR);
	vlc_CBP.getNextCBP(&nCBP, pBR);
	vlc_CBP.getNextCBP(&nCBP, pBR);
	vlc_CBP.getNextCBP(&nCBP, pBR);

	pBR->destroy();
}

void testTCOEFF() {
	const char * pchFileName = "TestFileName.bin";

	unsigned char arruchInfo[MAX_STR_LEN + 1];
	//Introduced string: EOB - not first coeff <10>; Run = 0 Level = 1 - first coeff <10>; 
	//                   Run = 0 Level = 3 <001010>; Escape Run = 2 Level = -127 <000001 000010 10000001>;
	//                   Escape Run = 2 Level = 2 <000001 000010 00000010>;
	//                   Intra DC coefficient 16 <00000010>
	arruchInfo[0] = 0xA2;
	arruchInfo[1] = 0x81;
	arruchInfo[2] = 0x0A;
	arruchInfo[3] = 0x04;
	arruchInfo[4] = 0x10;
	arruchInfo[5] = 0x80;
	arruchInfo[6] = 0x80;
	arruchInfo[7] = 0x80;
	write2File(pchFileName, arruchInfo, 8);

	BitstreamReader *pBR;
	BitstreamReader::STATUS sts;
				
	unsigned __int64 file_size = GetFileSizeFromName(pchFileName);
 
	sts = BitstreamReader::create(pchFileName,&pBR);
	if (sts != BitstreamReader::STS_OK) {
		fprintf(stderr,"Error: Cannot create bitstream reader\n");
		exit(1);
	}


	VLC_TCOEFF vlc_TCOEFF;
	TCoeff tCoeff;
	tCoeff.m_bIsEOB = false;
	vlc_TCOEFF.getNextTCOEFF(&tCoeff, pBR, 1);
	vlc_TCOEFF.getNextTCOEFF(&tCoeff, pBR, 1, true);//first coefficient
	vlc_TCOEFF.getNextTCOEFF(&tCoeff, pBR, 1);
	vlc_TCOEFF.getNextTCOEFF(&tCoeff, pBR, 1);
	vlc_TCOEFF.getNextTCOEFF(&tCoeff, pBR, 5);
	vlc_TCOEFF.getNextTCOEFF(&tCoeff, pBR, 0, true, true);//Intra dc coefficient

	pBR->destroy();
}



int main() {
	
	Singleton<Trace>::instance()->init("Trace.log");

	testMBA();

	testMTYPE();

	testMVD();

	testCBP();

	testTCOEFF();

	return(0);
}

#if 0

#include "vlc_targets.h"
#include "vlc_tree.h"
#include "vlc_field_mgr.h"


template <class T>
void printCodeFromTable(VLC_FieldMgr<T> & avlc_table, int anIndex){
	const vector<int> * arrnpCode;
	int nRes = avlc_table.enum2Code(&arrnpCode, anIndex);
	printf("Index = %d ==>> nRes = %d and arrnpCode = ", anIndex, nRes);
	for(int nI = 0; nI < (int)arrnpCode->size(); nI++)
		printf("%d ", (*arrnpCode)[nI]);
	printf("\n");
}

void printArray(const vector<int> & aarrnVals){

	for(int nI = 0; nI < (int)aarrnVals.size(); nI++){
		printf("%d ", aarrnVals[nI]);
	}
	printf("\n");

}


int main(){

	//VLC_Tree vlc_tree_int;
	//vlc_tree_int.printTree();

	VLC_FieldMgr<VLC_MBA> vlc_MBA;
	VLC_FieldMgr<VLC_MTYPE> vlc_MTYPE;
	VLC_FieldMgr<VLC_MVD> vlc_MVD;
	VLC_FieldMgr<VLC_CBP> vlc_CBP;
	VLC_FieldMgr<VLC_TCOEFF> vlc_TCOEFF;
	
	printCodeFromTable(vlc_MBA, 0);
	printCodeFromTable(vlc_MBA, 1);
	
	const std::vector<int> * aarrnpField = NULL;
	
	vector<int> arrnCode;

#if 0
	arrnCode.push_back(0);
	//arrnCode.push_back(0);
	//arrnCode.push_back(0);
	//arrnCode.push_back(1);
	//arrnCode.push_back(1);//00011
    if(vlc_MBA.code2Field(&aarrnpField, arrnCode) == 0){
		printf("Warning: no key recovered");
	}else{
		printArray(*aarrnpField);
	}

	//0001 1
	aarrnpField	= NULL;
	if(vlc_MTYPE.code2Field(&aarrnpField, arrnCode) == 0){
		printf("Warning: no key recovered");
	}else{
		printArray(*aarrnpField);
	}

	arrnCode[4] = 0;//00010
	if(vlc_MVD.code2Field(&aarrnpField, arrnCode) == 0){
		printf("Warning: no key recovered");
	}else{
		printArray(*aarrnpField);
	}
	
	arrnCode.push_back(1);
	arrnCode.push_back(1);
	arrnCode.push_back(1);//00010111
	if(vlc_CBP.code2Field(&aarrnpField, arrnCode) == 0){
		printf("Warning: no key recovered");
	}else{
		printArray(*aarrnpField);
	}

#endif
	static const int tcoeff[] = {
		//0, 0, 0, 0,		0, 1
		1, 0
	};
	arrnCode = vector<int>(&tcoeff[0],&tcoeff[sizeof(tcoeff)/sizeof(tcoeff[0])]);
	//arrnCode.push_back(1);
	//arrnCode.push_back(1);
	//arrnCode.push_back(1);//0001011 1
	if(vlc_TCOEFF.code2Field(&aarrnpField, arrnCode) == 0){
		printf("Warning: no key recovered");
	}else{
		printArray(*aarrnpField);
	}

	return(0);

}

#endif

