#ifndef STUDENT_LIST_DISPLAY_STATE
#define STUDENT_LIST_DISPLAY_STATE
#include"ListDisplayState.h"
#include "SeasonConfiguration.h"
class StudentListDisplayState:public ListDisplayState
{
private:
	SeasonConfiguration sc;
public:
	StudentListDisplayState();
	~StudentListDisplayState();
	void get(int);
	void select(int);
	void del(int);
	void add();

};
#endif

