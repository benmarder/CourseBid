#ifndef TERMINAL_EDITING_STATE
#define TERMINAL_EDITING_STATE
#include "Terminal.h"
#include"EntryDisplayState.h"
#include<iostream>
using namespace std;
class TerminalEditingState: public EntryDisplayState
{
public:
	Terminal terminal;
public:
	TerminalEditingState();
	~TerminalEditingState();
	int  getFieldCount(int);
	string  getCaption(int);
	bool  getValue(int);
	void  edit(int);
};

#endif