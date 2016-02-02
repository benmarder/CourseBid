#include "ShowStudentResult.h"
#include <Windows.h>
#include <Date.h>
#include <DateComparison.h>
#include <fstream>
int main() {
	try {
		Date bidDate = DateComparison::getBidDate();
		Date currDate = DateComparison::getCurrentDate();
		if (Date::isBigger(currDate, bidDate)) {
			ShowStudentResult showStudent;
		}
		else {
			cout << "The bid date is " + bidDate.toString() << endl
				<< "Wait for it..." << endl;
			exit(EXIT_FAILURE);
		}

	}
	catch (invalid_argument e) {
		cout << "Please enter the bid date first" << endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}