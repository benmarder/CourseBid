#ifndef MATHPARSER_EXPRESSION_H
#define MATHPARSER_EXPRESSION_H


class Expression {
public:

	virtual double evaluate(int) = 0;
};

#endif