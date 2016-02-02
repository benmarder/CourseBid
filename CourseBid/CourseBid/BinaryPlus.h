

#ifndef MATHPARSER_BINARYPLUS_H
#define MATHPARSER_BINARYPLUS_H

#include "BinaryOperator.h"
class BinaryPlus : public BinaryOperator {

public:

	BinaryPlus(Expression * left, Expression * right) : BinaryOperator(left, right){ }
	virtual double evaluate(int i);
};


#endif //MATHPARSER_BINARYPLUS_H
