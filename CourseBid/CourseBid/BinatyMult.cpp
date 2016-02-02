

#include "BinatyMult.h"

double BinaryMult::evaluate(int i) {
	return left->evaluate(i) * right->evaluate(i);

}
