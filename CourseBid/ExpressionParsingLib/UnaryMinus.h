

#ifndef MATHPARSER_UNARYMINUS_H
#define MATHPARSER_UNARYMINUS_H


#include "Expression.h"

class UnaryMinus : public Expression {
private:
	Expression* expr;
public:
	virtual double evaluate(int i);
	UnaryMinus(Expression *pExpression) : expr(pExpression) {};
};


#endif //MATHPARSER_UNARYMINUS_H
