#ifndef VLC_TREE
#define VLC_TREE

#include <vector>


#include "vlc_tree_node.h"
/*#include "vlc_targets.h"*/



class VLC_Tree{
private:
	VLC_TreeNode * m_pTreeRoot;

	void addCode(const std::vector<int> & aarrnCode, int anIndex);

public:
	VLC_Tree(){m_pTreeRoot = new VLC_TreeNode;};
	void setCodes(const std::vector< std::vector<int> > & aarrarrnCodes);

	int getKey(const std::vector<int> ** aarrnppKey, const std::vector<int> & aarrnCode, const VLC_Table & aVLC_Table, int anStateSpecific) const;
	//int getCode(const vector<int> ** aarrnppCode, const vector<int> & aarrnKey) const;

	void printTree(const VLC_Table & aVLC_Table) const;
};

#endif //VLC_TREE