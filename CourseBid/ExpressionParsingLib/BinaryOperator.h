
#ifndef MATHPARSER_BINARYOPERATOR_H
#define MATHPARSER_BINARYOPERATOR_H
#include "Expression.h"

class BinaryOperator : public Expression {
protected:
	Expression* left;
	Expression* right;
public:
	BinaryOperator(Expression *left, Expression *right) : left(left), right(right) { }
	virtual double evaluate(int) = 0;
};


#endif //MATHPARSER_BINARYOPERATOR_H
