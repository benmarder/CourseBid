#ifndef COURSE_EDITING_STATE
#define COURSE_EDITING_STATE
#include"EntryDisplayState.h"
#include"Course.h"
class CourseEditingState:public EntryDisplayState
{
private:
	Course course;
public:
	CourseEditingState();
	~CourseEditingState();
	int  getFieldCount(int);
	string  getCaption(int);
	bool  getValue(int);
	void  edit(int);
};

#endif

