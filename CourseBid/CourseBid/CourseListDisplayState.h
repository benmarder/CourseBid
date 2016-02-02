
#ifndef __courseBid__CourseListDisplayState__
#define __courseBid__CourseListDisplayState__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CourseListDisplayState{
private:
	SeasonConfiguration seasonConfiguration;
public:
	CourseListDisplayState();
	void selectCourse(int courseNum);
	void deleteCourse(int courseNum);
	void addCourse();
	~CourseListDisplayState();
};

#endif /* defined(__courseBid__CourseListDisplayState__) */
