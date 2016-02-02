#ifndef AUTHENTICATE
#define AUTHENTICATE
#include "Student.h"
#include "Terminal.h"
#include "FileStorage.h"
#include "UILibraryState.h"
class Authenticate
{
private:
	Terminal* terminal;
	FileStorage* fileStorage;
	UILibraryState ui;
	int counter;
	
public:
	static int getCounter();
	Authenticate();
	~Authenticate();
	void lockTerminal();
	Student* checkPassword();
	void showAut();

};

#endif
