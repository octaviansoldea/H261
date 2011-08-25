#ifndef VLC_ABSTRACT_MODEL_H
#define VLC_ABSTRACT_MODEL_H

#include <vector>
#include <string>

#include "vlc_tree.h"

struct VLC_AbstractModel {
	enum STATUS {
		STS_OK = 0,
		STS_EOF,
		STS_ERR_NOT_IN_TREE,
		STS_ERR_INDEX_EXCEED_BOUNDS,
		STS_ERR_PURE_VIRTUAL_CALL,
		STS_ERR_INVALID_KEY,
		STS_ERR
	};
	
	virtual void initCodes() = 0;
protected:
	VLC_Table m_Table;
	VLC_Tree m_Tree;

	void setCodes(const std::vector<std::vector<int> > & aarrarrn_Keys,
				  const std::vector<std::string> & aarrstr_VLC_Init);
};

#endif //VLC_ABSTRACT_MODEL_H