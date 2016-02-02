#ifndef DATAUPDATE
#define DATAUPDATE
#include <FileStorage.h>
#include <UILibrary.h>
#include <Lexer.h>
#include <Expression.h>
#include <lemon\list_graph.h>
#include <lemon\maps.h>
#include <lemon\bfs.h>
#include <lemon\connectivity.h>

using namespace lemon;


class DataUpdate
{
private:
	UILibrary ui;
	FileStorage* fileStorage;
	string formula;
public:
	DataUpdate();
	~DataUpdate();
	vector<string> getStudentsDataInVector();
	vector<string> getCoursesDataInVector();
	bool saveStudent(vector<string>, int, string);
	bool saveCourse(vector<string>, int, string);
	string getFormula();
	void setFormula(string f);
	void createCircularCoursesFile();
	string checkCircularity(string, vector<string>);
	void deployTermianls();
};
#endif
