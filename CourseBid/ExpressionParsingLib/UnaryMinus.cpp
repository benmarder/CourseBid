

#include "UnaryMinus.h"

double UnaryMinus::evaluate(int i) {
	return -(expr->evaluate(i));
}
