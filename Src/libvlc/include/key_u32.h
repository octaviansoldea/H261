#ifndef KEY_U32_H
#define KEY_U32_H

#include "h261_common.h"
#include "key.h"

class Key_U32 : public Key {
	u32 m_unVal;
public:
	Key_U32(u32 aunVal) : m_unVal(aunVal) {}
};

#endif //KEY_U32_H