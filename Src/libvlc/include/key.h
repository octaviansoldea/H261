#ifndef KEY_H
#define KEY_H

#include <vector>

#include "h261_common.h"

class Key {
protected:
	void * m_pKey;
public:
	Key(u32 aunVal);
	Key(const std::vector<int> & aarrnVals);
	~Key() = 0 { delete(m_pKey); }
};

#endif //KEY_H