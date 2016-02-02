#pragma once
#include "Date.h"
#include <fstream>

class DateComparison
{
public:
	DateComparison();
	~DateComparison();
	static Date getCurrentDate();
	static Date getBidDate();
};

