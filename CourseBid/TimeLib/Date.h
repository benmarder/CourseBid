#pragma once
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <exception>
#include <stdexcept>
using namespace std;
class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int, int, int);
	Date(SYSTEMTIME);
	Date(string);
	~Date();
	int getYear();
	int getMonth();
	int getDay();
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	static bool isEqual(Date, Date);
	static bool isBigger(Date, Date);
	string toString();
};

