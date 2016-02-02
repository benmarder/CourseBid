#ifndef LIST_DISPAY_STATE
#define LIST_DISPAY_STATE
#include "UiLibraryState.h"
class ListDisplayState: public UiLibraryState
{
private:

public:
	ListDisplayState();
	~ListDisplayState();
	void handleInput(char c);
	void display();
	virtual void get(int);
	virtual void select(int);
	virtual void del(int);
	virtual void add();
};
#endif

