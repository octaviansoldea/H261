#ifndef VLC_CBP_H
#define VLC_CBP_H

#include "vlc_tree.h"
#include "vlc_abstract_model.h"
#include "vlc_table.h"

class VLC_CBP : public VLC_AbstractModel {
	enum KEY {
		CBP_60 = 60,
		CBP_4 = 4,
		CBP_8 = 8,
		CBP_16 = 16,
		CBP_32 = 32,
		CBP_12 = 12,
		CBP_48 = 48,
		CBP_20 = 20,
		CBP_40 = 40,
		CBP_28 = 28,
		CBP_44 = 44,
		CBP_52 = 52,
		CBP_56 = 56,
		CBP_1 = 1,
		CBP_61 = 61,
		CBP_2 = 2,
		CBP_62 = 62,
		CBP_24 = 24,
		CBP_36 = 36,
		CBP_3 = 3,
		CBP_63 = 63,
		CBP_5 = 5,
		CBP_9 = 9,
		CBP_17 = 17,
		CBP_33 = 33,
		CBP_6 = 6,
		CBP_10 = 10,
		CBP_18 = 18,
		CBP_34 = 34,
		CBP_7 = 7,
		CBP_11 = 11,
		CBP_19 = 19,
		CBP_35 = 35,
		CBP_13 = 13,
		CBP_49 = 49,
		CBP_21 = 21,
		CBP_41 = 41,
		CBP_14 = 14,
		CBP_50 = 50,
		CBP_22 = 22,
		CBP_42 = 42,
		CBP_15 = 15,
		CBP_51 = 51,
		CBP_23 = 23,
		CBP_43 = 43,
		CBP_25 = 25,
		CBP_37 = 37,
		CBP_26 = 26,
		CBP_38 = 38,
		CBP_29 = 29,
		CBP_45 = 45,
		CBP_53 = 53,
		CBP_57 = 57,
		CBP_30 = 30,
		CBP_46 = 46,
		CBP_54 = 54,
		CBP_58 = 58,
		CBP_31 = 31,
		CBP_47 = 47,
		CBP_55 = 55,
		CBP_59 = 59,
		CBP_27 = 27,
		CBP_39 = 39,
		CBP_MAX = 64
	};

public:
	VLC_CBP();

	virtual void initCodes();

	STATUS getNextCBP(int * apnCBP, BitstreamReader * apBR) const;
};
#endif //VLC_CBP_H