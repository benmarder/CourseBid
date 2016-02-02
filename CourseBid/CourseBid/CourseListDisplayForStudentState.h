#ifndef COURSE_LIST_DISPLAY_FOR_STUDENT_STATE		
#define COURSE_LIST_DISPLAY_FOR_STUDENT_STATE
#include"student.h"
#include"UiLibraryState.h"
class CourseListDisplayForStudentState:public UiLibraryState
{
	Student student;
public:
	CourseListDisplayForStudentState();
	~CourseListDisplayForStudentState();
	void handleInput(char);
	void display();
};

#endif