#ifndef __courseBid__TerminalListDisplayState__
#define __courseBid__TerminalListDisplayState__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include"Terminal.h"
#include "TerminalsControl.h"
using namespace std;

class TerminalListDisplayState{
private:
	TerminalsControl terminalControl;
public:
	TerminalListDisplayState();
	void selectTerminal(int);
	~TerminalListDisplayState();
	TerminalsControl& getTerminalControl();

};

#endif 
