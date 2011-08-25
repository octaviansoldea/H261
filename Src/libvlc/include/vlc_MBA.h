#ifndef VLC_MBA_H
#define VLC_MBA_H

#include "vlc_tree.h"
#include "vlc_abstract_model.h"
#include "vlc_table.h"

class VLC_MBA : public VLC_AbstractModel {
public:
	enum KEY {
		MBA_1 = 1,
		MBA_2 = 2,
		MBA_3 = 3,
		MBA_4 = 4,
		MBA_5 = 5,
		MBA_6 = 6,
		MBA_7 = 7,
		MBA_8 = 8,
		MBA_9 = 9,
		MBA_10 = 10,
		MBA_11 = 11,
		MBA_12 = 12,
		MBA_13 = 13,
		MBA_14 = 14,
		MBA_15 = 15,
		MBA_16 = 16,
		MBA_17 = 17,
		MBA_18 = 18,
		MBA_19 = 19,
		MBA_20 = 20,
		MBA_21 = 21,
		MBA_22 = 22,
		MBA_23 = 23,
		MBA_24 = 24,
		MBA_25 = 25,
		MBA_26 = 26,
		MBA_27 = 27,
		MBA_28 = 28,
		MBA_29 = 29,
		MBA_30 = 30,
		MBA_31 = 31,
		MBA_32 = 32,
		MBA_33 = 33,
		MBA_stuffing = 34, 
		MBA_Start_code = 35,
		MBA_MAX = 36
	};


	VLC_MBA();

	virtual void initCodes();

	STATUS getNextMBA(int * apnMBA, BitstreamReader * apBR) const;
};
#endif //VLC_MBA_H