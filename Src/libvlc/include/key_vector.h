#ifndef KEY_VECTOR_H
#define KEY_VECTOR_H

#include <vector>

#include "key.h"

class Key_Vector : public Key {
	std::vector<int> m_arrnVals;
public:
	Key_Vector(const std::vector<int> & aarrnVals) : m_arrnVals(aarrnVals) {}
};

#endif //KEY_VECTOR_H