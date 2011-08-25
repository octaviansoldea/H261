#ifndef VLC_MTYPE_H
#define VLC_MTYPE_H

#include "vlc_tree.h"
#include "vlc_abstract_model.h"
#include "vlc_table.h"

struct VLC_MTYPE : public VLC_AbstractModel {
	enum FIELD_MASK {
		FIELD_INTRA   = 0x80,
		FIELD_INTER   = 0x40,
		FIELD_MC      = 0x20,
		FIELD_FIL     = 0x10,
		FIELD_MQUANT  = 0x08,
		FIELD_MVD     = 0x04,
		FIELD_CBP     = 0x02,
		FIELD_TCOEFF  = 0x01
	};

	enum KEY {
		MTYPE_INTRA_TCOEFF                     = FIELD_INTRA                                                               | FIELD_TCOEFF, 
		MTYPE_INTRA_MQUANT_TCOEFF              = FIELD_INTRA                        | FIELD_MQUANT                         | FIELD_TCOEFF,
		MTYPE_INTER_CBP_TCOEFF                 = FIELD_INTER                                                   | FIELD_CBP | FIELD_TCOEFF,
		MTYPE_INTER_MQUANT_CBP_TCOEFF          = FIELD_INTER                        | FIELD_MQUANT             | FIELD_CBP | FIELD_TCOEFF,
		MTYPE_INTERMC_MVD                      = FIELD_INTER | FIELD_MC                            | FIELD_MVD                           ,
		MTYPE_INTERMC_MVD_CBP_TCOEFF           = FIELD_INTER | FIELD_MC                            | FIELD_MVD | FIELD_CBP | FIELD_TCOEFF,
		MTYPE_INTERMC_MQUANT_MVD_CBP_TCOEFF    = FIELD_INTER | FIELD_MC             | FIELD_MQUANT | FIELD_MVD | FIELD_CBP | FIELD_TCOEFF,
		MTYPE_INTERMCFIL_MVD                   = FIELD_INTER | FIELD_MC | FIELD_FIL                | FIELD_MVD                           ,
		MTYPE_INTERMCFIL_MVD_CBP_TCOEFF        = FIELD_INTER | FIELD_MC | FIELD_FIL                | FIELD_MVD | FIELD_CBP | FIELD_TCOEFF,
		MTYPE_INTERMCFIL_MQUANT_MVD_CBP_TCOEFF = FIELD_INTER | FIELD_MC | FIELD_FIL | FIELD_MQUANT | FIELD_MVD | FIELD_CBP | FIELD_TCOEFF,
		MTYPE_MAX = 10
	};

public:

	VLC_MTYPE();

	virtual void initCodes();

	STATUS getNextMTYPE(u32 * aunpMask, BitstreamReader * apBR) const;
};
#endif //VLC_MTYPE_H