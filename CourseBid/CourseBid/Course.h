#pragma once

#include <string> 
#include <vector>
using namespace std;
class Course
{
public:
	Course();
	~Course();
	Course(string, string, string, int, vector<string>, int,vector<string>);
	string getId();
	void setId(string id);
	string getName();
	void setName(string name);
	string getDescription();
	void setDescription(string description);
	int getHours();
	void setHoures(int hours);
	int getMaxStudent();
	void setMaxStudents(int maxStudents);
	vector<string>& getRequiredCourses();
	void setRequiredCoures(vector<string> &requiredCoures);
	vector<string>& getStudentsList();
	void setStudentsList(string);
private:
	string id;
	string name;
	string description;
	int hours;
	vector<string> requiredCourses;
	int maxStudents;
	vector<string> studentsList;
};