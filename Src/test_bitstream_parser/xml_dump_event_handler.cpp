#include "token.h"
#include "blockCoeffsMgr.h"
#include "xml_dump_event_handler.h"

using namespace std;

inline void XMLDumpEventHandler::indent(void)
{
	int i;

	for (i=0; i<m_indent; i++)
		m_os << "\t";

}


void XMLDumpEventHandler::
printToken(const Token& token)
{
	const char *tag = "INVALID_TOKEN";

	switch (token.tok_type) {
	case Token::TOK_PSC:
		tag = "PSC";
		break;

	case Token::TOK_TR:
		tag = "TR";
		break;

	case Token::TOK_PTYPE:
		tag = "PTYPE";
		break;

	case Token::TOK_PEI:
		tag = "PEI";
		break;

	case Token::TOK_PSPARE:
		tag = "PSPARE";
		break;

	case Token::TOK_GBSC:
		tag = "GBSC";
		break;

	case Token::TOK_GN:
		tag = "GN";
		break;

	case Token::TOK_GQUANT:
		tag = "GQUANT";
		break;

	case Token::TOK_GEI:
		tag = "GEI";
		break;

	case Token::TOK_GSPARE:
		tag = "GSPARE";
		break;

	case Token::TOK_MBA_STUFFING:
		tag = "MBA_STUFFING";
		break;

	case Token::TOK_MBA:
		tag = "MBA";
		break;

	case Token::TOK_MTYPE:
		tag = "MTYPE";
		break;

	case Token::TOK_MQUANT:
		tag = "MQUANT";
		break;

	case Token::TOK_MVD:
		tag = "MVD";
		break;

	case Token::TOK_CBP:
		tag = "CBP";
		break;

	case Token::TOK_TCOEFF:
		tag = "TCOEFF";
		break;
	}


	indent();
	m_os << "<" << tag << ">";

	switch (token.tok_type) {
		case Token::TOK_MBA_STUFFING:
			break;

		case Token::TOK_MVD:
			m_os << endl;
			indent();
			m_os << "<x>" << token.s16_first << "</x>" << endl;
			indent();
			m_os << "<y>" << token.s16_second << "</y>" << endl;
			indent();
			break;

		case Token::TOK_TCOEFF:
			m_os << endl;
			if (!token.b_eob) {
				indent();
				m_os << "<run>" << token.u16_run << "</run>" << endl;
				indent();
				m_os << "<level>" << token.s16_level << "</level>" << endl;
			} else {
				indent();
				m_os << "<eob>" << token.b_eob << "</eob>" << endl;
			}
			indent();
			break;

		default:
			m_os << token.u32_value;
	}
	m_os << "</" << tag << ">" << endl;
}	

void XMLDumpEventHandler::printCoeffs(const BlockCoeffsMgr & aCoeffsTable) {
	int nCount = 0;
	int nElemsNr = aCoeffsTable.getElemsNr();
	int nCol, nLine;
	for(nCol = 0; nCol < 8; nCol++) {
		for(nLine = 0; nLine < 8; nLine++) {
			if(nCount < nElemsNr) {
				Token token = aCoeffsTable.getCoeff(nCol, nLine);
				printToken(token);
			}
			nCount++;
		}
	}
}

EventHandler::STATUS XMLDumpEventHandler::
handleEvent(EventHandler::EVENT_TYPE ev_type, const void *pTokenOrCoeffsTable)
{
	if(pTokenOrCoeffsTable == NULL) {
		switch (ev_type) {
			case EV_BITSTREAM_BEGIN:
				indent();
				m_os << "<bitstream>" << endl;
				m_indent++;
				break;

			case EV_BITSTREAM_END:
				m_indent--;
				indent();
				m_os << "</bitstream>" << endl;
				break;

			case EV_PICTURE_BEGIN:
				indent();
				m_os << "<picture>" << endl;
				m_indent++;
				break;

			case EV_PICTURE_END:
				m_indent--;
				indent();
				m_os << "</picture>" << endl;
				break;

			case EV_GOB_BEGIN:
				indent();
				m_os << "<gob>" << endl;
				m_indent++;
				break;

			case EV_GOB_END:
				m_indent--;
				indent();
				m_os << "</gob>" << endl;
				break;

			case EV_MB_BEGIN:
				indent();
				m_os << "<mb>" << endl;
				m_indent++;
				break;

			case EV_MB_END:
				m_indent--;
				indent();
				m_os << "</mb>" << endl;
				break;

			case EV_BLOCK_BEGIN:
				indent();
				m_os << "<block>" << endl;
				m_indent++;
				break;

			case EV_BLOCK_END:
				m_indent--;
				indent();
				m_os << "</block>" << endl;
				break;
			default:
				return STS_ERROR;
		}
	} else {
		switch(ev_type) {
			case EV_TOKEN: {
				const Token * pToken = (const Token *)(pTokenOrCoeffsTable);
				printToken(*pToken);
				}
				break;
			case EV_BLOCK_COEFFS: {
				const BlockCoeffsMgr * pCoeffsTable = (const BlockCoeffsMgr *)(pTokenOrCoeffsTable);
				printCoeffs(*pCoeffsTable);
				}
				break;
			default:
				return STS_ERROR;
		}
	}

	return STS_OK;
}