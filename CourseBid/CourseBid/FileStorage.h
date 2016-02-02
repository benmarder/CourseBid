#ifndef FILE_STORAGE
#define FILE_STORAGE
#include "IStorage.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Student.h"
#include "Terminal.h"
#include <map>
#include <vector>

using namespace std;

typedef enum t { 
	STUDENT_UPP = 'S',STUDENT_LOW = 's', TERMINAL_UPP = 'T', TERMINAL_LOW = 't', COURSE_UPP = 'C',COURSE_LOW = 'c'
} objectType;

class FileStorage 
{
private:
	map<string,Student*> studentsMap;
	map<string, Course*> coursesMap;
	map<string, Terminal*> terminalsMap;
	static bool instanceFlag;
	static FileStorage* fs;
	string storageFile;
	ofstream oFileStream;
	ifstream iFileStream;
	FileStorage();
public:
	static FileStorage* getInstance();
	~FileStorage();
	void readFromFile();
	void writeToFile();
	Student* getStudent(string,bool,string);
	void setStudent(Student*);
	void remove(string);
	Course* getCourse(string);
	void setCourse(Course*);
	Terminal* getTerminal(string);
	void setTerminal(Terminal*);
	map<string, Student*>& getStudentsMap();
	map<string, Course*>& getCoursesMap();
	map<string, Terminal*>& getTerminalsMap();
};


#endif

