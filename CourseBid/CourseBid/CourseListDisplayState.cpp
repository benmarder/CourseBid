#include "CourseListDisplayState.h"
#include "Course.h"

CourseListDisplayState::CourseListDisplayState(){
	cout << "********************************" << endl
		<< "Welcome to the Course list";
	vector<Course> courseVector = seasonConfiguration.getCourses(); /* not implemented yet */
	for (auto i = courseVector.begin(); i != courseVector.end(); ++i)
		cout << *i << endl;
	cout << "********************************" << endl;
	int courseNum;
	int selection;
	cout << "select course by typing course num ";
	cin >> courseNum;
	cout << "1 - select" << endl << "2 - delete" << endl << "3 - add" << endl;
	cin >> selection;
	switch (selection) {
	case 1:
		selectCourse(courseNum);
		break;
	case 2:
		deleteCourse(courseNum);
		break;
	case 3:
		addCourse();
	default:
		break;
	}
}

void CourseListDisplayState::selectCourse(int courseNum){
	vector<Course> courseVector = seasonConfiguration.getCourses();
	courseVector[courseNum];
}

void CourseListDisplayState::deleteCourse(int courseNum){
	seasonConfiguration.deleteCourse(); /* not implemented */
}

void CourseListDisplayState::addCourse(){
	string courseID, courseName, courseDescription, courseRequireCoursesString;
	vector<string> courseRequireCourses;
	int  courseHours, courseMaxStudent;
	cout << "enter course id (example: C01)" << endl;
	cin >> courseID;
	cout << "enter course name" << endl;
	cin >> courseName;
	cout << "enter course description" << endl;
	cin >> courseDescription;
	cout << "enter course hours" << endl;
	cin >> courseHours;
	cout << "enter course max student" << endl;
	cin >> courseMaxStudent;
	cout << " enter course require courses (example: C02,C05,C12)" << endl;
	cin >> courseRequireCoursesString;
    
}