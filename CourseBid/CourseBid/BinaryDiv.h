

#ifndef MATHPARSER_BINARYDIV_H
#define MATHPARSER_BINARYDIV_H
#include "BinaryOperator.h"


class BinaryDiv : public BinaryOperator {

public:
	BinaryDiv(Expression *left, Expression *right) : BinaryOperator(left, right) { }

	virtual double evaluate(int i);
};


#endif //MATHPARSER_BINARYDIV_H
