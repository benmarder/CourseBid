#include "DataUpdate.h"
#include <Date.h>
#include <DateComparison.h>

int main() {
	try {
		Date bidDate = DateComparison::getBidDate();
		Date currDate = DateComparison::getCurrentDate();
		if (Date::isBigger(bidDate, currDate)) {
			DataUpdate c;
		}
		else {
			cout << "You can't change data after the bid " << endl;
			exit(EXIT_FAILURE);
		}
	}
	catch (invalid_argument e) {
		cout << "Please enter the bid date first" << endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}