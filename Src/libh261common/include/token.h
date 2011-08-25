#ifndef TOKEN_H
#define TOKEN_H

#include "h261_common.h"

struct Token {
	enum TYPE {
		TOK_PSC,			//Picture Start Code
		TOK_TR,				//Temporal Reference
		TOK_PTYPE,			//Picture Type
		TOK_PEI,			//Picture Extra Insertion Information
		TOK_PSPARE,			//Picture Spare Information
		TOK_GBSC,			//GOB Start Code,
		TOK_GN,				//GOB Number
		TOK_GQUANT,			//GOB Quantizer Information
		TOK_GEI,			//GOB Extra Insertion Information
		TOK_GSPARE,			//GOB Spare Information
		TOK_MBA_STUFFING,	//MBA Stuffing
		TOK_MBA,			//Macroblock Address
		TOK_MTYPE,			//Macroblock Type
		TOK_MQUANT,			//Macroblock Quantizer
		TOK_MVD,			//Motion Vector Data
		TOK_CBP,				//Coded Bit Pattern
		TOK_TCOEFF			//Transform Coefficient
	};

	TYPE tok_type;
	union {
		u32 u32_value;
		struct {
			s16 s16_first;
			s16 s16_second;
		};
		struct {
			u16 u16_run;
			s16 s16_level;
			bool b_eob;
		};
	};

	Token(void) {}
	Token(TYPE type, u32 value = 0) { tok_type = type; u32_value = value; }
	Token(TYPE type, s16 first, s16 second) { tok_type = type; s16_first = first; s16_second = second; }
	Token(TYPE type, u16 run, s16 level, bool eob) { tok_type = type; u16_run = run; s16_level = level; b_eob = eob; }
};

#endif /* TOKEN_H */