#ifndef VLC_FIELD_MGR_H
#define VLC_FIELD_MGR_H

#include <vector>

#include "vlc_table.h"

template <class T>
class VLC_FieldMgr{
	T m_vlcTable;
	VLC_Tree m_tree;
//	VLC_FieldSearch m_field_search;
public:

	VLC_FieldMgr();

	int enum2Field(const std::vector<int> ** aarrnppField, int anIndex) const;
	int code2Field(const std::vector<int> ** aarrnppField, const std::vector<int> & aarrnCode, int anStateSpecific = -1) const;

	int enum2Code(const std::vector<int> ** aarrnppCode, int anIndex) const;
	int field2Code(const std::vector<int> ** aarrnppCode, const std::vector<int> & aarrnField, int anStateSpecific = -1) const;

	void print() const {m_tree.printTree(m_vlcTable);}
};

template<class T>
VLC_FieldMgr<T>::VLC_FieldMgr() {
	std::vector< std::vector<int> > arrarrnCodes;
	m_vlcTable.getCodes(arrarrnCodes);
	m_tree.setCodes(arrarrnCodes);
}

template<class T>
int VLC_FieldMgr<T>::enum2Field(const std::vector<int> ** aarrnppField, int anIndex) const{
	return(m_vlcTable.getCode(aarrnppField, anIndex));
}

template<class T>
int VLC_FieldMgr<T>::code2Field(const std::vector<int> ** aarrnppField, const std::vector<int> & aarrnCode, int anStateSpecific) const{
	return(m_tree.getKey(aarrnppField, aarrnCode, m_vlcTable, anStateSpecific));
}

template<class T>
int VLC_FieldMgr<T>::enum2Code(const std::vector<int> ** aarrnppCode, int anIndex) const{
	return(m_vlcTable.getCode(aarrnppCode, anIndex));
}

template<class T>
int VLC_FieldMgr<T>::field2Code(const std::vector<int> ** aarrnppCode, const std::vector<int> & aarrnField, int anStateSpecific) const{
	return(1);
}


#endif //VLC_FIELD_MGR_H