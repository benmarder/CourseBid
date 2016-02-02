#ifndef AUTHENTICATE
#define AUTHENTICATE
#include <FileStorage.h>
#include <UILibrary.h>
class Authenticate
{
private:
	Terminal* terminal;
	FileStorage* fileStorage;
	UILibrary ui;
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
