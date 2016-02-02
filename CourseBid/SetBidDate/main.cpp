#include <iostream>
#include <string>
#include <Date.h>
#include <fstream>
using namespace std;

int main() {
	string date;
	ofstream file;
	bool succeed = true;
	while (succeed) {
		cout << "Please enter a date for the bidding. e.g dd/mm/yyyy" << endl;
		cin >> date;
		try {
			Date d(date);
			succeed = false;
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	file.open("../date.txt");
	file << date;
	file.close();

	return 0;
}