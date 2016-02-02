

#include "BinaryPlus.h"

double BinaryPlus::evaluate(int i) {
	return right->evaluate(i) + left->evaluate(i);
}
