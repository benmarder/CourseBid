#include "Course.h"

Course::Course() {}
Course::~Course() {}

Course::Course(string idVal, string nameVal, string descVal, int hoursVal, vector<string> vecVal, int maxVal,vector<string> studentsVal) : id(idVal), name(nameVal),
	description(descVal), hours(hoursVal), requiredCourses(vecVal), maxStudents(maxVal), studentsList(studentsVal){}

string Course::getId() {
	return id;
}

void Course::setId(string id)
{
	this->id = id;
}

string Course::getName() {
	return name;
}

void Course::setName(string name)
{
	this->name = name;
}

string Course::getDescription() {
	return description;
}

void Course::setDescription(string description)
{
	this->description = description;
}

int Course::getHours() {
	return hours;
}

void Course::setHoures(int hours)
{
	this->hours = hours;
}

int Course::getMaxStudent() {
	return maxStudents;
}

void Course::setMaxStudents(int maxStudents)
{
	this->maxStudents = maxStudents;
}

vector<string>& Course::getRequiredCourses() {
	return requiredCourses;
}

void Course::setRequiredCoures(vector<string>& requiredCoures)
{
	this->requiredCourses = requiredCoures;
}

vector<string>& Course::getStudentsList() {
	return studentsList;
}

void Course::setStudentsList(string studentId) {
	studentsList.push_back(studentId);
}