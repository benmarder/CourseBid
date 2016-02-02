#ifndef SHOWSTUDENTRESULT
#define SHOWSTUDENTRESULT
#include "FileStorage.h"
#include "Authenticate.h"
#include "UILibraryState.h"
class ShowStudentResult
{
private:
	Authenticate authenticate;
	FileStorage* fileStorage;
	UILibraryState ui;
public:
	ShowStudentResult();
	~ShowStudentResult();
};
#endif
