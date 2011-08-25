#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

#include "Singleton.h"
#include "Trace.h"

#include "vlc_tree_node.h"
#include "vlc_table.h"
#include "vlc_tree.h"

#include "bitstream_reader.h"

VLC_Tree::~VLC_Tree() {
	stack<VLC_TreeNode *> stackTreeNodes;
	stackTreeNodes.push(m_pTreeRoot);
	VLC_TreeNode * pNode;
	while(stackTreeNodes.empty() == false) {
		pNode = stackTreeNodes.top();
		if((pNode->getLeft() == NULL) && (pNode->getRight() == NULL)) {
			stackTreeNodes.pop();
			delete pNode;
		} else {
			VLC_TreeNode * pLocalNode;
			if(pNode->getLeft() != NULL) {
				pLocalNode = pNode->getLeft();
				pNode->setLeft(NULL);
			} else {
				pLocalNode = pNode->getRight();
				pNode->setRight(NULL);
			}
			stackTreeNodes.push(pLocalNode);
		}
	}
}

void VLC_Tree::addCode(const string & astrCode, const int anIndex){

	VLC_TreeNode * pCurrNode = m_pTreeRoot;
	if(pCurrNode == NULL){
		m_pTreeRoot = pCurrNode = new VLC_TreeNode;		
		if(m_pTreeRoot == NULL)
			Singleton<Trace>::instance()->printErrorMessage("VLC_Tree::addCode - Could not allocate node for the root of the VLC");
	}
	int nI;
	int nLen = (int)astrCode.size();
	for(nI = 0; nI < nLen; nI++){
		char chCurrCh = astrCode[nI];
		
		if((chCurrCh != '0') && (chCurrCh != '1')) {
			Singleton<Trace>::instance()->printErrorMessage("VLC_Tree::addCode a code with different than 0 and 1 characters was detected\n");
		}
		//Just becouse I like more integers - Tavi
		int nVal = (chCurrCh == '0' ? 0 : 1);
		VLC_TreeNode * pChild;
		if(nVal == 0) {
			if(pCurrNode->getLeft() == NULL){
				pChild = new VLC_TreeNode;
				if(pChild == NULL)
					Singleton<Trace>::instance()->printErrorMessage("VLC_Tree::addCode - Could not allocate node in the VLC");
				pCurrNode->setLeft(pChild);
			}
			pCurrNode = pCurrNode->getLeft();
		}
		else {//nVal == 1
			if(pCurrNode->getRight() == NULL){
				pChild = new VLC_TreeNode;
				if(pChild == NULL)
					Singleton<Trace>::instance()->printErrorMessage("VLC_Tree::addCode - Could not allocate node in the VLC");
				pCurrNode->setRight(pChild);
			}
			pCurrNode = pCurrNode->getRight();
		}
	}
	pCurrNode->setIndex(anIndex);

}

/*
void VLC_Tree::setCodes(const vector<string> & aarrstrCodes) {

	vector<string>::const_iterator citCode;
	int nIndex;
	for(citCode = aarrstrCodes.begin(), nIndex = 0; 
		citCode != aarrstrCodes.end(); 
		citCode++, nIndex++){

		addCode(*citCode, nIndex);

	}

}
*/

VLC_Tree::STATUS VLC_Tree::peekMaxBits(u32 * apBits, int * apnBitsPeekable, BitstreamReader * apBR) const {
	*apnBitsPeekable = 32;
	while((*apnBitsPeekable) > 0) {
		BitstreamReader::STATUS stsBR;
		stsBR = apBR->peekBits(apBits, *apnBitsPeekable);
		switch(stsBR) {
			case BitstreamReader::STS_OK :
				return(STS_OK);
			case BitstreamReader::STS_EOF :
				break;
			default:
				return(STS_ERR);
		};
		(*apnBitsPeekable)--;
	}
	return(STS_EOF);
}

VLC_Tree::STATUS VLC_Tree::getKey(int * apnIndex, BitstreamReader * apBR) const
{
	vector<int>::const_iterator citCode;
	VLC_TreeNode * pNode = m_pTreeRoot;
	if(pNode == NULL)	
		return(STS_ERR);

	u32 bits;
	int nBitsPeekable = 32;
	STATUS sts_VLC_Tree = peekMaxBits(&bits, &nBitsPeekable, apBR);
	switch(sts_VLC_Tree) {
		case STS_OK :
			break;
		case STS_EOF :
			return(STS_EOF);
		default:
			return(STS_ERR);
	};

	if(nBitsPeekable == 0)
		return(STS_ERR);

	int nBits2Read = 0;
	while(nBits2Read < 32) {
		if(pNode == NULL)	
			return(STS_ERR_NOT_IN_TREE);
		if(pNode->hasInfo() == 1) {
			(*apnIndex) = pNode->getIndex();
			if(apBR->readBits(&bits, nBits2Read) == BitstreamReader::STS_OK)
				return(STS_OK);
			else
				return(STS_ERR);
		}
		int nDigit = !!(bits & (0x01 << (nBitsPeekable - nBits2Read - 1)));
		if(nDigit == 0)
			pNode = pNode->getLeft();
		else
			pNode = pNode->getRight();
		nBits2Read++;
	}
	return(STS_ERR_NOT_IN_TREE);
}

void VLC_Tree::printTree(const VLC_Table & aVLC_Table) const{
	
	ofstream vlc_file_stream;
	vlc_file_stream.open("vlc_tree.txt");
	
	stack<VLC_TreeNode *> stack;
	stack.push(m_pTreeRoot);
	while(stack.empty() == 0){
		VLC_TreeNode * pNode = stack.top();
		int nLevel = (int)stack.size();

		for(int nI = 0; nI < nLevel; nI++)
			vlc_file_stream << "-";
		if(pNode->hasInfo()){
			int nIndex = pNode->getIndex();
			vlc_file_stream << nIndex;
			vlc_file_stream << " ";

			const VLC_CodeRightAligned * pCodeRightAligned;

			aVLC_Table.getCode(&pCodeRightAligned, nIndex);

			vlc_file_stream << *pCodeRightAligned;
		}
		vlc_file_stream << endl;
		
		if(pNode->getLeft() != NULL)
			stack.push(pNode->getLeft());
		else
			if(pNode->getRight() != NULL)
				stack.push(pNode->getRight());
			else{
				stack.pop();
				VLC_TreeNode * pNodeUp = stack.top();
				while((stack.size() != 0) && ((pNodeUp->getRight() == pNode) || (pNodeUp->getRight() == NULL))){
					pNode = pNodeUp;
					stack.pop();
					if(stack.size() != 0)
						pNodeUp = stack.top();
				}
				if(stack.size() != 0){
					stack.push(pNodeUp->getRight());
				}
			}
	}
	
	vlc_file_stream.close();
	
}