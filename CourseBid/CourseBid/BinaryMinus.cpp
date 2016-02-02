

#include "BinaryMinus.h"

double BinaryMinus::evaluate(int i) {
	return right->evaluate(i) - left->evaluate(i);
}
