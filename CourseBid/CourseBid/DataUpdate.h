#ifndef DATAUPDATE
#define DATAUPDATE
#include "FileStorage.h"
#include "UILibraryState.h"
#include "Lexer.h"
#include "Expression.h"
#include <lemon\list_graph.h>
#include <lemon\maps.h>
#include <lemon\bfs.h>
#include <lemon\connectivity.h>

using namespace lemon;


class DataUpdate
{
private:
	UILibraryState ui;
	FileStorage* fileStorage;
	string formula;
public:
	DataUpdate();
	~DataUpdate();
	vector<string> getStudentsDataInVector();
	vector<string> getCoursesDataInVector();
	void goToEditStudent();
	bool saveStudent(vector<string>,int,string);
	bool saveCourse(vector<string>,int,string);
	string getFormula();
	void setFormula(string f);
	void createCircularCoursesFile();
	string checkCircularity(string, vector<string>);
};
#endif
