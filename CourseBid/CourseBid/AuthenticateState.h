#ifndef AUTHENTICATE_STATE
#define AUTHENTICATE_STATE
#include"Authenticate.h"
#include "UiLibraryState.h"
class AuthenticateState :public UiLibraryState
{
private:
	Authenticate authenticate;
public:
	AuthenticateState();
	~AuthenticateState();
	void handleInput(char);
	void display();
};
#endif

