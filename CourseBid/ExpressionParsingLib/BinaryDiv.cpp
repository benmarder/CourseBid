

#include "BinaryDiv.h"

double BinaryDiv::evaluate(int i) {
	return right->evaluate(i) / left->evaluate(i);

}
