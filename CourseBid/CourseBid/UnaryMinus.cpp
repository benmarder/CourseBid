//
// Created by dudi on 08/08/2015.
//

#include "UnaryMinus.h"

double UnaryMinus::evaluate(int i) {
	return -(expr->evaluate(i));
}
