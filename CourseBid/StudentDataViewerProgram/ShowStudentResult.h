#ifndef SHOWSTUDENTRESULT
#define SHOWSTUDENTRESULT
#include <FileStorage.h>
#include <Authentication.h>
#include <UILibrary.h>

class ShowStudentResult
{
private:
	Authenticate authenticate;
	FileStorage* fileStorage;
	UILibrary ui;
public:
	ShowStudentResult();
	~ShowStudentResult();
};
#endif