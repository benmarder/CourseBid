#include "BinaryDivision.h"


BinaryDivision::BinaryDivision()
{
}


BinaryDivision::~BinaryDivision()
{
}

int BinaryDivision::evaluate(int i) {
	return (leftExpression->evaluate(i) / rightExpression->evaluate(i));
}