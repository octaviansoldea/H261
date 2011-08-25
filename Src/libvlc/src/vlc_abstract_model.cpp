#include <vector>
#include <string>

#include "vlc_abstract_model.h"

using namespace std;

void VLC_AbstractModel::setCodes(const vector<vector<int> > & aarrarrn_Keys,
								 const vector<string> & aarrstr_VLC_Init) {
	int nI;
	int nSize = (int)aarrstr_VLC_Init.size();
	for(nI = 0; nI < nSize; nI++){
		const vector<int> & arrnKeys = aarrarrn_Keys[nI];
		m_Table.addKeyCode(arrnKeys, aarrstr_VLC_Init[nI], nI);
		m_Tree.addCode(aarrstr_VLC_Init[nI], nI);
	}
}