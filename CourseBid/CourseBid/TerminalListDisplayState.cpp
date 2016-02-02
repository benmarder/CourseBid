#include "TerminalListDisplayState.h"

TerminalListDisplayState::TerminalListDisplayState(){
	cout << "********************************" << endl
		<< "Welcome to the terminal list";
	vector<Terminal> terminalVector = terminalControl.getTerminals(); /* not implemented yet */
	for (auto i = terminalVector.begin(); i != terminalVector.end(); ++i)
		cout << *i << endl;
	cout << "********************************" << endl;

}

void TerminalListDisplayState::selectTerminal(int terminalNum){
	vector<Terminal> terminalVector = getTerminalControl().getTerminals();
	terminalVector[terminalNum];
}


TerminalsControl& TerminalListDisplayState::getTerminalControl(){
	return terminalControl;
}
