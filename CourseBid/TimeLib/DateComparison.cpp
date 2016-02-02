#include "DateComparison.h"


DateComparison::DateComparison()
{
}


DateComparison::~DateComparison()
{
}

Date DateComparison::getCurrentDate() {
	SYSTEMTIME currDate;
	GetLocalTime(&currDate);
	Date currentDate(currDate);
	return currentDate;
}

Date DateComparison::getBidDate() {
	ifstream iFileStream;
	iFileStream.open("../date.txt");
	string line;
	getline(iFileStream, line);
	Date bidDate(line);
	return bidDate;
}


