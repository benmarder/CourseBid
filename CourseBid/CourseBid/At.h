

#ifndef MATHPARSER_AT_H
#define MATHPARSER_AT_H

#include "Expression.h"
class At : public Expression {

public:
	virtual double evaluate(int i);
};


#endif //MATHPARSER_AT_H
