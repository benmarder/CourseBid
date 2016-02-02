#ifndef BINARY_DIVISION
#define BINARY_DIVISION
#include "BinaryOperator.h"
class BinaryDivision : public BinaryOperator
{
public:
	BinaryDivision();
	~BinaryDivision();
	int evaluate(int i);
};

#endif
