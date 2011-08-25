#ifndef VLC_TARGETS
#define VLC_TARGETS

#include <vector>


#include "vlc_table.h"


class VLC_MBA : public VLC_Table{
	virtual void initCodes(std::vector<std::string> & aarrstrVLC_init) const;
public:
	enum KEY {
		MBA_1 = 0,
		MBA_2 = 1,
		MBA_3 = 2,
		MBA_4 = 3,
		MBA_5 = 4,
		MBA_6 = 5,
		MBA_7 = 6,
		MBA_8 = 7,
		MBA_9 = 8,
		MBA_10 = 9,
		MBA_11 = 10,
		MBA_12 = 11,
		MBA_13 = 12,
		MBA_14 = 13,
		MBA_15 = 14,
		MBA_16 = 15,
		MBA_17 = 16,
		MBA_18 = 17,
		MBA_19 = 18,
		MBA_20 = 19,
		MBA_21 = 20,
		MBA_22 = 21,
		MBA_23 = 22,
		MBA_24 = 23,
		MBA_25 = 24,
		MBA_26 = 25,
		MBA_27 = 26,
		MBA_28 = 27,
		MBA_29 = 28,
		MBA_30 = 29,
		MBA_31 = 30,
		MBA_32 = 31,
		MBA_33 = 32,
		MBA_stuffing = 33, 
		MBA_Start_code = 34,
		MBA_MAX = 35
	};


	VLC_MBA();
};

class VLC_MTYPE : public VLC_Table{
	virtual void initCodes(std::vector<std::string> & aarrstrVLC_init) const;
public:
	enum KEY {
		MTYPE_INTRA_TCOEFF = 0,
		MTYPE_INTRA_MQUANT_TCOEFF = 1,
		MTYPE_INTER_CBP_TCOEFF = 2,
		MTYPE_INTER_MQUANT_CBP_TCOEFF = 3,
		MTYPE_INTERMC_MVD = 4,
		MTYPE_INTERMC_MVD_CBP_TCOEFF = 5,
		MTYPE_INTERMC_MQUANT_MVD_CBP_TCOEFF = 6,
		MTYPE_INTERMCFIL_MVD = 7,
		MTYPE_INTERMCFIL_MVD_CBP_TCOEFF = 8,
		MTYPE_INTERMCFIL_MQUANT_MVD_CBP_TCOEFF = 9,
		MTYPE_MAX = 10
	};


	VLC_MTYPE();
};

class VLC_MVD : public VLC_Table{
	virtual void initCodes(std::vector<std::string> & aarrstrVLC_init) const;
public:
	enum KEY {
		MVD_M16_16 = 0,
		MVD_M15_17 = 1,
		MVD_M14_18 = 2,
		MVD_M13_19 = 3,
		MVD_M12_20 = 4,
		MVD_M11_21 = 5,
		MVD_M10_22 = 6,
		MVD_M9_23 = 7,
		MVD_M8_24 = 8,
		MVD_M7_25 = 9,
		MVD_M6_26 = 10,
		MVD_M5_27 = 11,
		MVD_M4_28 = 12,
		MVD_M3_29 = 13,
		MVD_M2_30 = 14,
		MVD_M1 = 15,
		MVD_0 = 16,
		MVD_1 = 17,
		MVD_2_M30 = 18,
		MVD_3_M29 = 19,
		MVD_4_M28 = 20,
		MVD_5_M27 = 21,
		MVD_6_M26 = 22,
		MVD_7_M25 = 23,
		MVD_8_M24 = 24,
		MVD_9_M23 = 25,
		MVD_10_M22 = 26,
		MVD_11_M21 = 27,
		MVD_12_M20 = 28,
		MVD_13_M19 = 29,
		MVD_14_M18 = 30,
		MVD_15_M17 = 31,
		MVD_MAX = 32
	};


	VLC_MVD();
};


class VLC_CBP : public VLC_Table{
	virtual void initCodes(std::vector<std::string> & aarrstrVLC_init) const;
public:
	enum KEY {
		CBP_60 = 0,
		CBP_4 = 1,
		CBP_8 = 2,
		CBP_16 = 3,
		CBP_32 = 4,
		CBP_12 = 5,
		CBP_48 = 6,
		CBP_20 = 7,
		CBP_40 = 8,
		CBP_28 = 9,
		CBP_44 = 10,
		CBP_52 = 11,
		CBP_56 = 12,
		CBP_1 = 13,
		CBP_61 = 14,
		CBP_2 = 15,
		CBP_62 = 16,
		CBP_24 = 17,
		CBP_36 = 18,
		CBP_3 = 19,
		CBP_63 = 20,
		CBP_5 = 21,
		CBP_9 = 22,
		CBP_17 = 23,
		CBP_33 = 24,
		CBP_6 = 25,
		CBP_10 = 26,
		CBP_18 = 27,
		CBP_34 = 28,
		CBP_7 = 29,
		CBP_11 = 30,
		CBP_19 = 31,
		CBP_35 = 32,
		CBP_13 = 33,
		CBP_49 = 34,
		CBP_21 = 35,
		CBP_41 = 36,
		CBP_14 = 37,
		CBP_50 = 38,
		CBP_22 = 39,
		CBP_42 = 40,
		CBP_15 = 41,
		CBP_51 = 42,
		CBP_23 = 43,
		CBP_43 = 44,
		CBP_25 = 45,
		CBP_37 = 46,
		CBP_26 = 47,
		CBP_38 = 48,
		CBP_29 = 49,
		CBP_45 = 50,
		CBP_53 = 51,
		CBP_57 = 52,
		CBP_30 = 53,
		CBP_46 = 54,
		CBP_54 = 55,
		CBP_58 = 56,
		CBP_31 = 57,
		CBP_47 = 58,
		CBP_55 = 59,
		CBP_59 = 60,
		CBP_27 = 61,
		CBP_39 = 62,
		CBP_MAX = 63
	};


	VLC_CBP();
};

class VLC_TCOEFF : public VLC_Table{
	virtual void initCodes(std::vector<std::string> & aarrstrVLC_init) const;
	void introduceRunLevelSign(int anRun, int anLevel, int anSign, const std::string & astrCode);
public:
	enum KEY {
        TCOEFF_EOB = 0,
        TCOEFF_0_1_FIRSTCOEFF = 1,
        TCOEFF_0_1_FIRSTCOEFF_M = 2,
        TCOEFF_0_1_NOTFIRSTCOEFF = 3,
        TCOEFF_0_1_NOTFIRSTCOEFF_M = 4,
        TCOEFF_0_2 = 5,
        TCOEFF_0_2_M = 6,
        TCOEFF_0_3 = 7,
        TCOEFF_0_3_M = 8,
        TCOEFF_0_4 = 9,
        TCOEFF_0_4_M = 10,
        TCOEFF_0_5 = 11,
        TCOEFF_0_5_M = 12,
        TCOEFF_0_6 = 13,
        TCOEFF_0_6_M = 14,
        TCOEFF_0_7 = 15,
        TCOEFF_0_7_M = 16,
        TCOEFF_0_8 = 17,
        TCOEFF_0_8_M = 18,
        TCOEFF_0_9 = 19,
        TCOEFF_0_9_M = 20,
        TCOEFF_0_10 = 21,
        TCOEFF_0_10_M = 22,
        TCOEFF_0_11 = 23,
        TCOEFF_0_11_M = 24,
        TCOEFF_0_12 = 25,
        TCOEFF_0_12_M = 26,
        TCOEFF_0_13 = 27,
        TCOEFF_0_13_M = 28,
        TCOEFF_0_14 = 29,
        TCOEFF_0_14_M = 30,
        TCOEFF_0_15 = 31,
        TCOEFF_0_15_M = 32,
        TCOEFF_1_1 = 33,
        TCOEFF_1_1_M = 34,
        TCOEFF_1_2 = 35,
        TCOEFF_1_2_M = 36,
        TCOEFF_1_3 = 37,
        TCOEFF_1_3_M = 38,
        TCOEFF_1_4 = 39,
        TCOEFF_1_4_M = 40,
        TCOEFF_1_5 = 41,
        TCOEFF_1_5_M = 42,
        TCOEFF_1_6 = 43,
        TCOEFF_1_6_M = 44,
        TCOEFF_1_7 = 45,
        TCOEFF_1_7_M = 46,
        TCOEFF_2_1 = 47,
        TCOEFF_2_1_M = 48,
        TCOEFF_2_2 = 49,
        TCOEFF_2_2_M = 50,
        TCOEFF_2_3 = 51,
        TCOEFF_2_3_M = 52,
        TCOEFF_2_4 = 53,
        TCOEFF_2_4_M = 54,
        TCOEFF_2_5 = 55,
        TCOEFF_2_5_M = 56,
        TCOEFF_3_1 = 57,
        TCOEFF_3_1_M = 58,
        TCOEFF_3_2 = 59,
        TCOEFF_3_2_M = 60,
        TCOEFF_3_3 = 61,
        TCOEFF_3_3_M = 62,
        TCOEFF_3_4 = 63,
        TCOEFF_3_4_M = 64,
        TCOEFF_4_1 = 65,
        TCOEFF_4_1_M = 66,
        TCOEFF_4_2 = 67,
        TCOEFF_4_2_M = 68,
        TCOEFF_4_3 = 69,
        TCOEFF_4_3_M = 70,
        TCOEFF_5_1 = 71,
        TCOEFF_5_1_M = 72,
        TCOEFF_5_2 = 73,
        TCOEFF_5_2_M = 74,
        TCOEFF_5_3 = 75,
        TCOEFF_5_3_M = 76,
        TCOEFF_6_1 = 77,
        TCOEFF_6_1_M = 78,
        TCOEFF_6_2 = 79,
        TCOEFF_6_2_M = 80,
        TCOEFF_7_1 = 81,
        TCOEFF_7_1_M = 82,
        TCOEFF_7_2 = 83,
        TCOEFF_7_2_M = 84,
        TCOEFF_8_1 = 85,
        TCOEFF_8_1_M = 86,
        TCOEFF_8_2 = 87,
        TCOEFF_8_2_M = 88,
        TCOEFF_9_1 = 89,
        TCOEFF_9_1_M = 90,
        TCOEFF_9_2 = 91,
        TCOEFF_9_2_M = 92,
        TCOEFF_10_1 = 93,
        TCOEFF_10_1_M = 94,
        TCOEFF_10_2 = 95,
        TCOEFF_10_2_M = 96,
        TCOEFF_11_1 = 97,
        TCOEFF_11_1_M = 98,
        TCOEFF_12_1 = 99,
        TCOEFF_12_1_M = 100,
        TCOEFF_13_1 = 101,
        TCOEFF_13_1_M = 102,
        TCOEFF_14_1 = 103,
        TCOEFF_14_1_M = 104,
        TCOEFF_15_1 = 105,
        TCOEFF_15_1_M = 106,
        TCOEFF_16_1 = 107,
        TCOEFF_16_1_M = 108,
        TCOEFF_17_1 = 109,
        TCOEFF_17_1_M = 110,
        TCOEFF_18_1 = 111,
        TCOEFF_18_1_M = 112,
        TCOEFF_19_1 = 113,
        TCOEFF_19_1_M = 114,
        TCOEFF_20_1 = 115,
        TCOEFF_20_1_M = 116,
        TCOEFF_21_1 = 117,
        TCOEFF_21_1_M = 118,
        TCOEFF_22_1 = 119,
        TCOEFF_22_1_M = 120,
        TCOEFF_23_1 = 121,
        TCOEFF_23_1_M = 122,
        TCOEFF_24_1 = 123,
        TCOEFF_24_1_M = 124,
        TCOEFF_25_1 = 125,
        TCOEFF_25_1_M = 126,
        TCOEFF_26_1 = 127,
        TCOEFF_26_1_M = 128,
        TCOEFF_ESCAPE = 129,
        TCOEFF_MAX = 130
	};


	VLC_TCOEFF();

    virtual int getIndexStateSpecific(const std::vector<int> & aarrnCode, int anSpecificState) const;
};

#endif //VLC_TARGETS