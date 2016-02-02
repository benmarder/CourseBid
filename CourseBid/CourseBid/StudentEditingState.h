#ifndef STUDENT_EDITING_STATE
#define STUDENT_EDITING_STATE
#include"Student.h"
#include "EntryDisplayState.h"

class StudentEditingState: public EntryDisplayState
{
private:
	Student student;
public:
	StudentEditingState();
	~StudentEditingState();
	int  getFieldCount(int);
	string  getCaption(int);
	bool getValue(int);
	void edit(int);
};
#endif

