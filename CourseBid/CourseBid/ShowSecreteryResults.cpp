#include "ShowSecreteryResults.h"

/*
controller of all the courses allocations for the secretery to view
*/
ShowSecreteryResults::ShowSecreteryResults() {
	fileStorage = FileStorage::getInstance();
	map<string, Student*> allStudents = fileStorage->getStudentsMap();
	vector<string> data;
	string answer;
	while (true) {
		for (map<string, Student*>::iterator iter = allStudents.begin(); iter != allStudents.end(); ++iter) {
			data.push_back(iter->first);
			data.push_back(iter->second->getName());
			data.push_back("\n");
		}
		answer = ui.listOfStudentSecretaryPostBidding(data);
		data.clear();
		if (answer[0] == 'x' || answer[0] == 'X') {
			return;
		}
		else { //makes the first letter in lower case
			char c = answer[0];
			answer[0] = tolower(c);
		}
		if (!allStudents.count(answer)) {
			ui.errorSyntax("Student doesn't exists");
		}
		else {
			vector<string> currentCourses = allStudents[answer]->getCurrentCourses();
			vector<string> coursesInfo;
			while (true) {
				for (unsigned i = 0; i < currentCourses.size(); i++) {
					Course* c = fileStorage->getCourse(currentCourses[i]);
					if (c != NULL) {
						coursesInfo.push_back(c->getId());
						coursesInfo.push_back(c->getName());
						coursesInfo.push_back("\n");
					}
				}
				string insideAnswer = ui.listOfCoursesOfStudentPostBidding(coursesInfo);
				coursesInfo.clear();
				if (insideAnswer[0] != 'x' && insideAnswer[0] != 'X') {
					ui.errorSyntax("");
				}
				else {
					break;
				}
			}
		}

	}
}


ShowSecreteryResults::~ShowSecreteryResults()
{
}
