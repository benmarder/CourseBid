#include "RemoveLock.h"


/* remove lock from a chosen id of a terminal.
how? get the terminals gui , then the user choose the terminal he wants to release.
the, change the terminals state from the file storage.
*/
RemoveLock::RemoveLock()
{
	string answer;
	while (answer[0] != 'x') {
		fs = FileStorage::getInstance();
		vector<string>result;
		for (map<string, Terminal*>::iterator it = fs->getTerminalsMap().begin(); it != fs->getTerminalsMap().end(); ++it) {
			result.push_back(it->second->getId());
			if (it->second->isLocked()){
				result.push_back("locked");
			}
			else result.push_back("open");
		}
		answer = ui.terminalListDisplayState(result);
		if (answer[0] == 'x' || answer[0] == 'X')
			return;
		Terminal* t = fs->getTerminal(answer);
		if (t == NULL){
			ui.errorSyntax("Terminal doesn't exists");
		}
		else{
			t->setLocked(false);
			fs->setTerminal(t);
		}
	}
}


RemoveLock::~RemoveLock()
{
}