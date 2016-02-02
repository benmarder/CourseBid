#ifndef TERMINALS_CONTROL
#define TERMINALS_CONTROL
#include "Terminal.h"
#include "vector"
class TerminalsControl
{
private:
	vector<Terminal> terminals;

public:
	TerminalsControl();
	~TerminalsControl();
	void openTerminal(Terminal);
	vector<Terminal> getTerminals();
};
#endif

