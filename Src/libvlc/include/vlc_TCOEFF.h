#ifndef VLC_TCOEFF_H
#define VLC_TCOEFF_H

#include <vector>
#include <string>

#include "vlc_tree.h"
#include "vlc_abstract_model.h"
#include "vlc_table.h"

typedef struct TCoeffStruct {
	bool m_bIsEOB;
	bool m_bEscapeDetected;
	int m_nRun;
	int m_nLevel;
	int m_RecLevel;

	TCoeffStruct() : m_bIsEOB(false), m_bEscapeDetected(false) {}
} TCoeff;

class VLC_TCOEFF : public VLC_AbstractModel {
	enum KEY {
        TCOEFF_EOB_OR_0_1_FIRSTCOEFF = 1,
        //TCOEFF_0_1_FIRSTCOEFF = 1,
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

	STATUS getNextRunLevel(TCoeff * apTCoeff,
						   BitstreamReader * apBR,
						   bool abIsFirstCoeff = false) const;

public:

	VLC_TCOEFF();

	virtual void initCodes();

	STATUS getNextTCOEFF(TCoeff * apTCoeff,
		                 BitstreamReader * apBR,
						 int anQuant = 0,
		                 bool abIsFirstCoeff = false,
						 bool abIsIntraDC = false) const;
private:
	void introduceRunLevelSign(std::vector<std::vector<int> > & aarrarrn_Keys, int anRun, int anLevel, int anSign);
};
#endif //VLC_TCOEFF_H