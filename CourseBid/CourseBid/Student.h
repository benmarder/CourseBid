
#ifndef __courseBid__Student__
#define __courseBid__Student__

#include <stdio.h>
#include <string>
#include "Course.h"
#include <vector>
#include <map>

using namespace std;

class Student {
private:
	string id;
	string name;
	int points;
	vector<string> completedCourses;
	map<string, int> pointsPerCourse;
	vector<string> currentCourses;

public:
	string getId();
	void setId(string);
	int getPoints();
	void setPoints(int);
	string getName();
	void setName(string);
	vector<string>& getCompletedCourses();
	void setCompletedCourses(string);
	map<string, int> getPointsPerCourse();
	void setPointsPerCourse(string, int);
	vector<string>& getCurrentCourses();
	void setCurrentCourses(string);
	Student();
	Student(string, int, string, vector<string>, map<string, int>);
	~Student();
};

#endif /* defined(__courseBid__Student__) */
