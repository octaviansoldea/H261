#ifndef VLC_TREE
#define VLC_TREE

#include <vector>
#include <string>

#include "vlc_table.h"
#include "vlc_tree_node.h"
#include "bitstream_reader.h"

struct VLC_Tree{
	enum STATUS {
		STS_OK = 0,
		STS_EOF,
		STS_ERR_NOT_IN_TREE,
		STS_ERR
	};

	VLC_Tree(){m_pTreeRoot = new VLC_TreeNode;};
	~VLC_Tree();

	//void setCodes(const std::vector<std::string> & aarrstrCodes);

	STATUS getKey(int * apnIndex, BitstreamReader * apBR) const;
	
	void printTree(const VLC_Table & aVLC_Table) const;

	
	void addCode(const std::string & astrCode, const int anIndex);

	STATUS peekMaxBits(u32 * apBits, int * apnBitsPeekable, BitstreamReader * apBR) const;

private:
	VLC_TreeNode * m_pTreeRoot;
};

#endif //VLC_TREE