#ifndef VLC_MVD_H
#define VLC_MVD_H

#include "vlc_tree.h"
#include "vlc_abstract_model.h"
#include "vlc_table.h"

class VLC_MVD : public VLC_AbstractModel {	
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

public:
	VLC_MVD();

	virtual void initCodes();

	STATUS getNextMVD(int * apnMVDx, int * apnMVDy, BitstreamReader * apBR) const;
};
#endif //VLC_MVD_H