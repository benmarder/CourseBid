#include "Student.h"

Student::Student(){}
Student::~Student(){}


Student::Student(string idVal, int pointsVal, string nameVal, vector<string> courses, map<string, int> pointsPerCourseVal) :id(idVal), points(pointsVal),
name(nameVal), completedCourses(courses), pointsPerCourse(pointsPerCourseVal) {}


string Student::getId() {
	return id;
}
void Student::setId(string val) {
	id = val;
}
string Student::getName() {
	return name;
}
void Student::setName(string val) {
	name = val;
}
int Student::getPoints() {
	return points;
}
void Student::setPoints(int val) {
	points = val;
}
vector<string>& Student::getCompletedCourses() {
	return completedCourses;
}
void Student::setCompletedCourses(string val) {
	completedCourses.push_back(val);
}

map<string, int> Student::getPointsPerCourse() {
	return pointsPerCourse;
}

void Student::setPointsPerCourse(string key, int value) {
	pointsPerCourse[key] = value;
}

vector<string>& Student::getCurrentCourses() {
	return currentCourses;
}

void Student::setCurrentCourses(string courseId) {
	currentCourses.push_back(courseId);
}


