#ifndef VLC_TREE_NODE
#define VLC_TREE_NODE

class VLC_TreeNode{
	int m_nIndex;
	VLC_TreeNode * m_pLeft, * m_pRight;
public:

	VLC_TreeNode(int anIndex = -1) : m_nIndex(anIndex), m_pLeft(NULL), m_pRight(NULL) {}

	int getIndex() const {return(m_nIndex);}
	void setIndex(int anIndex) {m_nIndex = anIndex;}
	
	VLC_TreeNode * getRight() {return(m_pRight);}
	void setRight(VLC_TreeNode * apVLC_TreeNode){m_pRight = apVLC_TreeNode;}
	VLC_TreeNode * getLeft() {return(m_pLeft);}
	void setLeft(VLC_TreeNode * apVLC_TreeNode){m_pLeft = apVLC_TreeNode;}

	bool hasInfo() const {return(m_nIndex >= 0);}

};

#endif //VLC_TREE_NODE