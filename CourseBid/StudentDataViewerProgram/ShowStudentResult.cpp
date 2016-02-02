#include "ShowStudentResult.h"

/*
controller of the courses allocations for the student to view
*/
ShowStudentResult::ShowStudentResult() {
	fileStorage = FileStorage::getInstance();
	Student* student = authenticate.checkPassword();
	if (student != NULL) {
		string answer;
		map<string, int> coursesAplliedTo = student->getPointsPerCourse();
		vector<string> data;
		while (true) {
			for (map<string, int>::iterator iter = coursesAplliedTo.begin(); iter != coursesAplliedTo.end(); ++iter) {
				data.push_back(iter->first);
				Course* c = fileStorage->getCourse(iter->first);
				if (c != NULL) {
					data.push_back(c->getName());
					data.push_back("minimum points: ");
					data.push_back(to_string(c->getLowPoints()));
					data.push_back(to_string(iter->second));
					vector<string> currentCourses = student->getCurrentCourses();
					unsigned i;
					for (i = 0; i < currentCourses.size(); i++) {
						if (currentCourses[i] == c->getId()) {
							data.push_back("Applied");
							break;
						}
					}
					if (i == currentCourses.size()){ //we reached the end of the loop without matching course => Not applied
						data.push_back("Not applied");
					}
					data.push_back("\n");
				}
			}
			answer = ui.studentPostBiddingScreen(data);
			data.clear();
			if (answer[0] == 'x' || answer[0] == 'X') {
				return;
			}
		}
	}
	else {
		return;
	}
}



ShowStudentResult::~ShowStudentResult()
{
}
