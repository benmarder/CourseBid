#pragma once
#ifndef NONREFFIELD
#define NONREFFIELD
#include "IdObj.h"

template <typename T, int i>
class NonRefField
{
private:
	IdObj obj;
public:
	NonRefField() {}
	~NonRefField() {}
	T get() {}
	void set(T value) {}
};

#endif