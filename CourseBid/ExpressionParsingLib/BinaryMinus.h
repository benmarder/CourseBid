

#ifndef MATHPARSER_BINARYMINUS_H
#define MATHPARSER_BINARYMINUS_H

#include "BinaryOperator.h"
class BinaryMinus : public BinaryOperator {

public:
	BinaryMinus(Expression *left, Expression *right) : BinaryOperator(left, right) { }

private:
	virtual double evaluate(int i);
};


#endif //MATHPARSER_BINARYMINUS_H
