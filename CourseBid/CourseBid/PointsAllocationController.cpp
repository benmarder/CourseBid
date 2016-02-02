#include "PointsAllocationController.h"


/*
controls the points allocation screen
*/
PointsAllocationController::PointsAllocationController(){

	//check student authentication
	Authenticate authenticate;
	Student* student = authenticate.checkPassword();
	vector<string> result;
	int remainingPoints;

	//if student is logged in
	if (student != NULL){
		remainingPoints = student->getPoints();
		result.push_back(to_string(remainingPoints));

		//get the data
		FileStorage* fs = FileStorage::getInstance();
		for (map<string, Course*>::iterator it = fs->getCoursesMap().begin(); it != fs->getCoursesMap().end(); ++it){
			string courseId = it->first;
			vector<string> completedCourses = student->getCompletedCourses();
			if (std::find(completedCourses.begin(), completedCourses.end(), courseId) == completedCourses.end()){ //if course doesnt exist in completed Courses
				vector<string> requiredCourses = it->second->getRequiredCourses();
				unsigned int i;
				for (i = 0; i < requiredCourses.size(); ++i)//if the student has all the required courses;
					if (std::find(completedCourses.begin(), completedCourses.end(), requiredCourses[i]) == completedCourses.end())
						break;
				if (i == requiredCourses.size()){
					result.push_back(courseId);					//push id and name to result vector
					result.push_back(it->second->getName());	//
				}
			}
		}
		UILibraryState ui;
		//handle student input
		while (true){
			char answer = ui.studentListOfCoursesToBid(result)[0];
			switch (answer){
			case 's':
			case 'S':{int points; bool continueFlag;
				for (int i = 1; i < result.size() - 1; i += 2){
					continueFlag = true;
					while (continueFlag){
						try{
							points = stoi(ui.studentBiddingScreen(result[0], result[i], result[i + 1]));
						}
						catch (invalid_argument e){
							ui.errorSyntax("");
							continue;
						}
						if (points > remainingPoints || points < 0){
							ui.tooManyPointsAllocated();
						}

						else{
							remainingPoints -= points;
							result[0] = to_string(remainingPoints);
							student->setPointsPerCourse(result[i], points);
							student->setPoints(remainingPoints);
							continueFlag = false;
						}
					}
				}
				fs->setStudent(student);
			}
					 return;
			case'x':
			case'X':return;
			default:ui.errorSyntax("");
			}
		}
	}
}


PointsAllocationController::~PointsAllocationController()
{
}