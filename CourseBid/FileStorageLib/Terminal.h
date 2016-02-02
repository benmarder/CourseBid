#ifndef TERMINAL
#define TERMINAL
#include <iostream>
using namespace std;
class Terminal {
private:
	string id;
	bool locked;
public:
	Terminal();
	~Terminal();
	Terminal(string, bool);
	string getId();
	bool isLocked();
	void setId(string);
	void setLocked(bool);
};

#endif