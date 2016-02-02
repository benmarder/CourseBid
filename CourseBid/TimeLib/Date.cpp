#include "Date.h"


Date::Date()
{
}

Date::Date(int y, int m, int d) {
	setYear(y);
	setMonth(m);
	setDay(d);
}

Date::Date(SYSTEMTIME time) {
	int day = time.wDay;
	int month = time.wMonth;
	int year = time.wYear;
	setDay(day);
	setMonth(month);
	setYear(year);
}

Date::Date(string date) {
	if (date.size() != 10) {
		throw invalid_argument("Wrond date format");
	}
	if (date[2] != '/' || date[5] != '/') {
		throw invalid_argument("Wrond date format");
	}
	istringstream iss(date);
	string token;
	getline(iss, token, '/');
	setDay(stoi(token));
	getline(iss, token, '/');
	setMonth(stoi(token));
	getline(iss, token, '/');
	setYear(stoi(token));
}

Date::~Date()
{
}

int Date::getYear() {
	return year;
}

int Date::getMonth() {
	return month;
}

int Date::getDay() {
	return day;
}

void Date::setYear(int y) {
	if (y > 0) {
		year = y;
	}
	else {
		throw invalid_argument("Invalid year");
	}
}

void Date::setMonth(int m) {
	if (m > 0 && m <= 12) {
		month = m;
	}
	else {
		throw invalid_argument("Invalid month");
	}
}

void Date::setDay(int d) {
	if (d > 0 && d <= 31) {
		day = d;
	}
	else {
		throw invalid_argument("Invalid day");

	}
}

bool Date::isEqual(Date d1, Date d2) {
	if (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() == d2.getDay()) {
		return true;
	}
	else
		return false;
}

bool Date::isBigger(Date d1, Date d2) {
	if (d1.getYear() > d2.getYear()) {
		return true;
	}
	else if (d2.getYear() > d1.getYear()) {
		return false;
	}
	//the years are equal
	else if (d1.getMonth() > d2.getMonth()) { 
		return true;
	}
	else if (d2.getMonth() > d1.getMonth()) {
		return false;
	}
	//the months are equal
	else if (d1.getDay() > d2.getDay()) { 
		return true;
	}
	else {
		return false;
	}
}

string Date::toString() {
	return to_string(day) + '/' + to_string(month) + '/' + to_string(year);
}
