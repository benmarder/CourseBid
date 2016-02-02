#ifndef COURSE_FINAL_RESULT_STATE
#define COURSE_FINAL_RESULT_STATE
#include "ListDisplayState.h"
#include"Student.h"
class CourseFinalResultState : public ListDisplayState
{
private:
	Student student;
public:
	CourseFinalResultState();
	~CourseFinalResultState();
};
#endif
