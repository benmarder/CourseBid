

#ifndef MATHPARSER_CONSTEXPR_H
#define MATHPARSER_CONSTEXPR_H

#include "Expression.h"

class ConstExpr : public Expression {

public:
	ConstExpr(int value) : value(value) { }
	virtual double evaluate(int i);
private:
	int value;
};


#endif //MATHPARSER_CONSTEXPR_H
