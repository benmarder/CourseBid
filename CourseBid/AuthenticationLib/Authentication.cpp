#include "Authentication.h"


/*every terminal has a file that indicates the terminal id*/
Authenticate::Authenticate()
{
	fileStorage = FileStorage::getInstance();
	string terminalIdFile = "terminalId.txt";
	ifstream fstream;
	fstream.open(terminalIdFile);
	string line;
	if (fstream.is_open()) {
		getline(fstream, line);
		fstream.close();
	}
	if (line[0] == 't' || line[0] == 'T') {
		terminal = fileStorage->getTerminal(line);
		if (terminal == NULL) {
			ui.errorSyntax("This terminal is not exists in the file storage.");
			exit(EXIT_FAILURE);
		}
		if (terminal->isLocked()) {
			ui.errorSyntax("This terminal is locked.\nFor more information go to the secretary");
			exit(EXIT_FAILURE);
		}
	}
	else {
		ui.errorSyntax("This terminal has no id\nEvery terminal should have a text file that indicates it's id.");
		exit(EXIT_FAILURE);
	}
}


Authenticate::~Authenticate()
{

}

void Authenticate::lockTerminal() {
	terminal->setLocked(true);
	fileStorage->setTerminal(terminal);
}

//checks authentication - student has 3 shots.
Student* Authenticate::checkPassword() {
	int counter = 1;
	while (counter < 4) {
		map<string, string> authenticationMap = ui.authenticateScreen();
		string id = authenticationMap["id"];
		string name = authenticationMap["name"];
		Student* student = fileStorage->getStudent(id, true, name);
		if (student != NULL) {
			return student;
		}
		else {
			ui.errorAuthentication(counter);
			counter++;
		}
	}
	lockTerminal();
	ui.terminalIsLocked();
	return NULL;
}