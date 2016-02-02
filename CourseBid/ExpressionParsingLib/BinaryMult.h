

#ifndef MATHPARSER_BINARYMULT_H
#define MATHPARSER_BINARYMULT_H
#include "BinaryOperator.h"


class BinaryMult : public BinaryOperator {

public:
	BinaryMult(Expression *left, Expression *right) : BinaryOperator(left, right) { }
	virtual double evaluate(int i);
};


#endif //MATHPARSER_BINARYMULT_H
