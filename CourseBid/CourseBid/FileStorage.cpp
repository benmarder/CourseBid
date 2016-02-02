#include "FileStorage.h"

FileStorage* FileStorage::fs = NULL;
bool FileStorage::instanceFlag = false;

FileStorage::FileStorage() {
	storageFile = "io.txt";
	iFileStream.open(storageFile);
	string line;
	getline(iFileStream, line);
	iFileStream.close();
	if (line == "") { //check if the file was first created or it is empty
		oFileStream.open(storageFile); //the storage starts with '#'
		oFileStream << "#" << endl;
		oFileStream.close();
	}
	else {
		readFromFile();
	}
}

/*singelton design pattern*/
FileStorage* FileStorage::getInstance() {
	if (!instanceFlag) {
		fs = new FileStorage();
		instanceFlag = true;
	}
	return fs;
}

FileStorage::~FileStorage() {
	instanceFlag = false;
	delete fs;
}

/*this function reads from the fileStorage and creates a maps of all objects 
Courses, Students and Terminals*/
void FileStorage::readFromFile(){
	iFileStream.open(storageFile);
	string line;
	while (getline(iFileStream, line)){
		if (line[0] == '#'){
			getline(iFileStream, line);
			switch (line[0]) {
			case STUDENT_LOW:
			case STUDENT_UPP:{
				Student* student = new Student();
				student->setId(line);
				getline(iFileStream, line);
				student->setName(line);
				getline(iFileStream, line);
				student->setPoints(stoi(line));
				getline(iFileStream, line);
				istringstream iss(line);
				for (string token; getline(iss, token, ',');) {
					student->setCompletedCourses(token);
				}
				getline(iFileStream, line);
				istringstream iss2(line);
				for (string token; getline(iss2, token, ' ');) {
					string course = token;
					getline(iss2, token, ',');
					student->setPointsPerCourse(course, stoi(token));
				}
				studentsMap[student->getId()] = student;
				getline(iFileStream, line);
				istringstream iss3(line);
				for (string token; getline(iss3, token, ',');) {
					student->setCurrentCourses(token);
				}
			}
				break;
			case TERMINAL_LOW:
			case TERMINAL_UPP: {
				Terminal* terminal = new Terminal();
				terminal->setId(line);
				getline(iFileStream, line);
				if (line == "0") {
					terminal->setLocked(false);
				}
				else {
					terminal->setLocked(true);
				}
				terminalsMap[terminal->getId()] = terminal;
			}
				break;
			case COURSE_LOW:
			case COURSE_UPP: {
				Course* course = new Course();
				course->setId(line);
				getline(iFileStream, line);
				course->setName(line);
				getline(iFileStream, line);
				course->setDescription(line);
				getline(iFileStream, line);
				course->setHoures(stoi(line));
				getline(iFileStream, line);
				istringstream iss(line);
				vector<string> result;
				for (string token; getline(iss, token, ',');) {
					result.push_back(token);
				}
				course->setRequiredCoures(result);
				getline(iFileStream, line);
				course->setMaxStudents(stoi(line));
				coursesMap[course->getId()] = course;
				getline(iFileStream, line);
				istringstream iss2(line);
				for (string token; getline(iss2, token, ',');) {
					course->setStudentsList(token);
				}
			}
				break;
			default:
				cout << "default "<<line << endl;
				break;
			}
		}
	}
}

/*this function write the maps to the file after a change has been made
an object has been modifed, added or deleted*/
void FileStorage::writeToFile() {
	oFileStream.open(storageFile);
	if (oFileStream.is_open()) {
		oFileStream << "#" << endl;
		for (map<string, Student*>::iterator it = studentsMap.begin(); it != studentsMap.end(); ++it) {
			oFileStream << it->second->getId() << endl;
			oFileStream << it->second->getName() << endl;
			oFileStream << to_string(it->second->getPoints()) << endl;
			vector<string> completedCourses = it->second->getCompletedCourses();
			for (unsigned i = 0; i < completedCourses.size(); i++) {
				oFileStream << completedCourses[i] << ",";
			}
			oFileStream << endl;
			map<string, int> pointsPerCourse = it->second->getPointsPerCourse();
			for (map<string, int>::iterator iter = pointsPerCourse.begin(); iter != pointsPerCourse.end(); ++iter) {
				oFileStream << iter->first << " " << iter->second << ",";
			}
			oFileStream << endl;
			vector<string> currentCourses = it->second->getCurrentCourses();
			for (unsigned i = 0; i < currentCourses.size(); i++) {
				oFileStream << currentCourses[i] << ",";
			}
			oFileStream << endl << "#" << endl;
		}
		for (map<string, Course*>::iterator it = coursesMap.begin(); it != coursesMap.end(); ++it) {
			oFileStream << it->second->getId() << endl;
			oFileStream << it->second->getName() << endl;
			oFileStream << it->second->getDescription() << endl;
			oFileStream << to_string(it->second->getHours()) << endl;
			vector<string> requiredCourses = it->second->getRequiredCourses();
			for (unsigned i = 0; i < requiredCourses.size(); i++) {
				oFileStream << requiredCourses[i] << ",";
 			}
			oFileStream << endl;
			oFileStream << to_string(it->second->getMaxStudent()) << endl;
			vector<string> studentsList = it->second->getStudentsList();
			for (unsigned i = 0; i<studentsList.size(); i++) {
				oFileStream << studentsList[i] << ",";
			}
			oFileStream << endl << "#" << endl;
		}
		for (map<string, Terminal*>::iterator it = terminalsMap.begin(); it != terminalsMap.end(); ++it) {
			oFileStream << it->second->getId() << endl;
			oFileStream << it->second->isLocked() ? "1" : "0";
			oFileStream << endl << "#" << endl;
		}
		oFileStream.close();
	}
}

/*returns the student with specific id
this function is used when authentication as well - the student needs to give his id and name*/
Student* FileStorage::getStudent(string id,bool needAutenticate,string name) {
	if (studentsMap.count(id)) {
		if (needAutenticate) {
			if (studentsMap[id]->getName() == name) {
				return studentsMap[id];
			}
		}
		else {
			return studentsMap[id];
		}
	}
	return NULL;	
}

/*returns the course with specific id*/
Course* FileStorage::getCourse(string id) {
	if (coursesMap.count(id)) {
		return coursesMap[id];
	}
	else {
		return NULL;
	}
}

/*returns the terminal with specific id*/
Terminal* FileStorage::getTerminal(string id) {
	if (terminalsMap.count(id)) {
		return terminalsMap[id];
	}
	else {
		return NULL;
	}
}

/*add or modify student - write it to the students map and then to file storage*/
void FileStorage::setStudent(Student* student) {
	studentsMap[student->getId()] = student;
	writeToFile();
}

/*add or modify course - write it to the courses map and then to file storage*/
void FileStorage::setCourse(Course* course) {
	coursesMap[course->getId()] = course;
	writeToFile();
}

/*add or modify terminal - write it to the terminals map and then to file storage*/
void FileStorage::setTerminal(Terminal* terminal) {
	terminalsMap[terminal->getId()] = terminal;
	writeToFile();
}

/*this function remove objects from file storage*/
void FileStorage::remove(string id) {
	char type = id[0];
	switch (type) {
	case STUDENT_LOW:
	case STUDENT_UPP:
		if (studentsMap.count(id)) {
			studentsMap.erase(id);
		}
		else {
			return;
		}
		break;
	case TERMINAL_LOW:
	case TERMINAL_UPP:
		if (terminalsMap.count(id)) {
			terminalsMap.erase(id);
		}
		else {
			return;
		}
		break;
	case COURSE_LOW:
	case COURSE_UPP:
		if (coursesMap.count(id)) {
			coursesMap.erase(id);
		}
		else {
			return;
		}
	}
	writeToFile();
}

map<string, Student*>& FileStorage::getStudentsMap() {
	return studentsMap;
}

map<string, Course*>& FileStorage::getCoursesMap() {
	return coursesMap;
}

map<string, Terminal*>& FileStorage::getTerminalsMap() {
	return terminalsMap;
}

