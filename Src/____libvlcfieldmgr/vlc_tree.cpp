#include <iostream>
#include <fstream>


#include <string>
#include <stack>

using namespace std;



#include "vlc_tree_node.h"
#include "vlc_table.h"
//#include "vlc_targets.h"
#include "vlc_tree.h"





void VLC_Tree::addCode(const vector<int> & aarrnCode, const int anIndex){

	VLC_TreeNode * pCurrNode = m_pTreeRoot;
	if(pCurrNode == NULL){
		m_pTreeRoot = pCurrNode = new VLC_TreeNode;		
		if(m_pTreeRoot == NULL){
			printf("Could not allocate node for the root of the VLC");
			exit(-1);
		}
	}
	
	vector<int> arrnPartCode;
	arrnPartCode.resize(0);
	
	vector<int>::const_iterator citCode;
	for(citCode = aarrnCode.begin(); citCode != aarrnCode.end(); citCode++){
		arrnPartCode.push_back(*citCode);
		VLC_TreeNode * pChild;
		if(*citCode == 0) {
			if(pCurrNode->getLeft() == NULL){
				pChild = new VLC_TreeNode;
				if(pChild == NULL){
					printf("Could not allocate node in the VLC");
					exit(-1);
				}
				pCurrNode->setLeft(pChild);
			}
			pCurrNode = pCurrNode->getLeft();
		}
		else if(*citCode == 1) {
			if(pCurrNode->getRight() == NULL){
				pChild = new VLC_TreeNode;
				if(pChild == NULL){
					printf("Could not allocate node in the VLC");
					exit(-1);
				}
				pCurrNode->setRight(pChild);
			}
			pCurrNode = pCurrNode->getRight();
		}
	}
	pCurrNode->setIndex(anIndex);

}




void VLC_Tree::setCodes(const vector< vector<int> > & aarrarrnCodes) {

	vector< vector<int> >::const_iterator citCode;
	int nIndex;
	for(citCode = aarrarrnCodes.begin(), nIndex = 0; 
		citCode != aarrarrnCodes.end(); 
		citCode++, nIndex++){

		addCode(*citCode, nIndex);
	}

}



int VLC_Tree::getKey(const vector<int> ** aarrnppKey, const vector<int> & aarrnCode, const VLC_Table & aVLC_Table, int anStateSpecific) const
{

	int nIndex;
	if(anStateSpecific < 0){
		vector<int>::const_iterator citCode;
		VLC_TreeNode * pNode = m_pTreeRoot;
			if(pNode == NULL)	
				return(0);

		for(citCode = aarrnCode.begin(); citCode != aarrnCode.end(); citCode++){
			if(pNode == NULL)	
				return(0);
			if(pNode->hasInfo() == 1){
				nIndex = pNode->getIndex();
	       		aVLC_Table.getKey(aarrnppKey, nIndex);
				return(1);
			}
			int nDigit = *citCode;
			if(nDigit == 0)
				pNode = pNode->getLeft();
			else
				pNode = pNode->getRight();
		}
		if(pNode == NULL)
			return(0);
		
		nIndex = pNode->getIndex();
	}else{
		nIndex = aVLC_Table.getIndexStateSpecific(aarrnCode, anStateSpecific);
	}
	aVLC_Table.getKey(aarrnppKey, nIndex);
	return(1);

}


void VLC_Tree::printTree(const VLC_Table & aVLC_Table) const{
	
	ofstream vlc_file_stream;
	vlc_file_stream.open("vlc_tree.txt");
	
	stack<VLC_TreeNode *> stack;
	stack.push(m_pTreeRoot);
	while(stack.empty() == 0){
		VLC_TreeNode * pNode = stack.top();
		int nLevel = stack.size();
		
		for(int nI = 0; nI < nLevel; nI++)
			vlc_file_stream << "-";
		if(pNode->hasInfo()){
			int nIndex = pNode->getIndex();
			vlc_file_stream << nIndex;
			vlc_file_stream << " ";

			const vector<int> *arrnpCode;
			aVLC_Table.getCode(&arrnpCode, nIndex);

			vector<int>::const_iterator citVals;
			for(citVals = arrnpCode->begin(); citVals != arrnpCode->end(); citVals++)
				vlc_file_stream << *citVals;
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