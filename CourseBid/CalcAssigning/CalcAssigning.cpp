#include "CalcAssigning.h"


CalcAssigning::CalcAssigning()
{
	FileStorage* fs = FileStorage::getInstance();
	map<string, Course*>coursesMap = fs->getCoursesMap();
	map<string, Student*>studentsMap = fs->getStudentsMap();
	ofstream oFileStream;
	oFileStream.open("input.txt");	//create a text file that will be the input file for the alogithm implemented in ex3 this semester 
	if (oFileStream.fail()){
		cerr << "Error: " << strerror(errno);
	}
	oFileStream << to_string(studentsMap.size()) << " " << to_string(coursesMap.size()) << endl;
	for (map<string, Course*>::iterator it = coursesMap.begin(); it != coursesMap.end(); ++it) {
		oFileStream << it->second->getMaxStudent() << " ";
	}
	oFileStream << endl;
	for (map<string, Student*>::iterator it = studentsMap.begin(); it != studentsMap.end(); ++it) {
		for (map<string, Course*>::iterator it2 = coursesMap.begin(); it2 != coursesMap.end(); ++it2) {
			if (it->second->getPointsPerCourse().count(it2->first) == 0) // if a student did not bid for the course, then it means he cant bid for it so the points set for 0
				oFileStream << "0 ";
			else
				oFileStream << to_string(it->second->getPointsPerCourse()[it2->first]) << " ";
		}
		oFileStream << endl;
	}

	/*this is the algorithm implemented in ex3  */
	ifstream iFileStream;
	iFileStream.open("input.txt");
	if (iFileStream.fail()){
		cerr << "Error: " << strerror(errno);
	}
	int m, n;
	iFileStream >> m >> n;

	Lp lp;
	vector<Lp::Col> cols(m * n);

	for (auto &c : cols)
	{
		c = lp.addCol();
		lp.colLowerBound(c, 0);
		lp.colUpperBound(c, 1);
	}

	for (int j = 0; j < n; ++j)
	{
		int limit;
		iFileStream >> limit;
		Lp::Expr sum;
		for (int i = 0; i < m; ++i)
			sum += cols[i * n + j];
		lp.addRow(sum <= limit);
	}

	Lp::Expr objective;
	for (auto &col : cols)
	{
		int c;
		iFileStream >> c;
		objective += col * c;
	}
	lp.obj(objective);
	lp.max();
	lp.solve();

	/*after solving, update all students for their current courses ,and all the courses for their students.*/
	int j, i = 0;
	for (map<string, Student*>::iterator it = studentsMap.begin(); it != studentsMap.end(); ++it) {
		j = 0;
		for (map<string, Course*>::iterator it2 = coursesMap.begin(); it2 != coursesMap.end(); ++it2) {
			if (lp.primal(cols[i * n + j])){	//if he got accepted to the course
				it->second->setCurrentCourses(it2->first);	//update the course in the student
				fs->setStudent(it->second);					//update in file storage
				it2->second->setStudentsList(it->first);	//update the student in the course
				fs->setCourse(it2->second);					//update in file storage
			}
			++j;
		}
		++i;
	}
	addMinPoints();
}
CalcAssigning::~CalcAssigning()
{
}

void CalcAssigning::addMinPoints() {
	FileStorage*fileStorage = FileStorage::getInstance();
	int minPts = 0;
	map <string, Student*> allStudents = fileStorage->getStudentsMap();
	map <string, Course*> allCourses = fileStorage->getCoursesMap();
	for (map<string, Course*>::iterator iter = allCourses.begin(); iter != allCourses.end(); ++iter) {
		vector<string> studentsList = iter->second->getStudentsList();
		for (unsigned i = 0; i < studentsList.size(); i++) {
			Student* student = allStudents[studentsList[i]];
			map<string, int> currCourses = student->getPointsPerCourse();
			if (i == 0) {
				minPts = currCourses[iter->first];
			}
			else {
				if (minPts > currCourses[iter->first]) {
					minPts = currCourses[iter->first];
				}
			}
		}
		iter->second->setLowPoints(minPts);
		fileStorage->setCourse(iter->second);
	}
}
