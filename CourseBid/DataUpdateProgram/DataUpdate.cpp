#include "DataUpdate.h"

DataUpdate::DataUpdate()
{
	const int numOfOptions = 8;
	fileStorage = FileStorage::getInstance();
	deployTermianls();
	createCircularCoursesFile();
	while (true) {
		string answer = ui.secretaryOptions();
		if (answer[0] == 'x' || answer[0] == 'X') {
			return;
		}
		int selection;
		try {
			selection = stoi(answer);
			switch (selection)
			{
			case 0: {
				string formula = ui.addFormula();
				Lexer* lexer = new Lexer(formula);
				Expression* ex = lexer->getExpression();
				if (ex != NULL) {
					setFormula(formula);
				}
				else {
					ui.errorSyntax("Invalid formula");
				}
				break;
			}
			case 1: { //show all courses
				while (true) {
					string innerAnswer = ui.listOfCoursesSecretary(getCoursesDataInVector());
					if (innerAnswer[0] == 'x' || innerAnswer[0] == 'X') {
						break;
					}
					else {
						ui.errorSyntax("Enter course id or 'x' to exit");
						continue;
					}
				}
			}
					break;
			case 2: { //show all students
				while (true) {
					string innerAnswer = ui.listOfStudentSecretary(getStudentsDataInVector());
					if (innerAnswer[0] == 'x' || innerAnswer[0] == 'X') {
						break;
					}
					else {
						ui.errorSyntax("Enter student id or 'x' to exit");
						continue;
					}
				}
			}
					break;
			case 3: { //add new course
				vector<string> courseData = ui.addNewCourseScreen();
				bool succeed = saveCourse(courseData, 3, "");
				if (!succeed) {
					ui.errorSyntax("Failed adding course");
				}
				else {
					ui.addedSuccessfully();
				}
				createCircularCoursesFile();
			}
					break;
			case 4: { //add new student
				if (getFormula().empty()){ //checks if the formula is already been entered
					ui.errorFormula();//if not - can't add new student
					break;
				}
				vector<string> studentData = ui.addNewStudentScreen();
				bool succeed = saveStudent(studentData, 4, "");
				if (!succeed) {
					ui.errorSyntax("Failed adding student");
				}
				else {
					ui.addedSuccessfully();
				}
			}
					break;
			case 5: //delete course
				while (true) {
					string courseIdToDelete = ui.deleteCourseScreen(getCoursesDataInVector());
					if (courseIdToDelete[0] == 'x' || courseIdToDelete[0] == 'X') {
						break;
					}
					else if (fileStorage->getCourse(courseIdToDelete) == NULL) {
						ui.errorSyntax("Course doesn't exists");
						continue;
					}
					else {
						bool canDelete = true;
						//check if the course is in another course's required courses list 
						map<string, Course*> allCourses = fileStorage->getCoursesMap();
						for (map<string, Course*>::iterator iter = allCourses.begin(); iter != allCourses.end(); ++iter) {
							for (unsigned i = 0; i < iter->second->getRequiredCourses().size(); i++) {
								if (courseIdToDelete == iter->second->getRequiredCourses()[i]) {
									canDelete = false;
								}
							}
						}

						// check if the course is in student's completed courses
						map<string, Student*> allStudents = fileStorage->getStudentsMap();
						for (map<string, Student*>::iterator iter = allStudents.begin(); iter != allStudents.end(); ++iter) {
							for (unsigned i = 0; i < iter->second->getCompletedCourses().size(); i++) {
								if (courseIdToDelete == iter->second->getCompletedCourses()[i]) {
									canDelete = false;
								}
							}
						}
						if (canDelete) {
							fileStorage->remove(courseIdToDelete); //delete the course from the file storage
						}
						else {
							ui.errorSyntax("Cannot delete this course.\n Course is in required courses list or in student completed courses");
						}
					}
				}
				break;
			case 6: { //delete student
				while (true) {
					string studentIdToDelete = ui.deleteStudentScreen(getStudentsDataInVector());
					if (studentIdToDelete[0] == 'x' || studentIdToDelete[0] == 'X') {
						break;
					}
					else if (fileStorage->getStudent(studentIdToDelete, false, "") == NULL) {
						ui.errorSyntax("Student doesn't exists");
						continue;
					}
					else {
						fileStorage->remove(studentIdToDelete); //delete the student from the file storage
						map<string, Course*> allCourses = fileStorage->getCoursesMap();
						for (map<string, Course*>::iterator iter = allCourses.begin(); iter != allCourses.end(); ++iter) {
							//delete the student from the courses he participents as well
							vector<string> particpentStudents = iter->second->getStudentsList();
							for (unsigned i = 0; i < particpentStudents.size(); i++) {
								bool courseChanged = false;
								if (studentIdToDelete == particpentStudents[i]) {
									Course* c = fileStorage->getCourse(iter->first);
									if (c != NULL) {
										c->getStudentsList().erase(c->getStudentsList().begin() + i);
									}
									courseChanged = true;
								}
								if (courseChanged) {
									fileStorage->setCourse(iter->second);
								}
							}
						}
					}
				}
			}
					break;
			case 7: { //edit course
				while (true) {
					string idToEdit = ui.editCourseChooseScreen(getCoursesDataInVector());
					if (idToEdit[0] == 'x' || idToEdit[0] == 'X') {
						break;
					}
					else {
						vector<string> courseData = ui.editCourseScreen();
						bool succeed = saveCourse(courseData, 7, idToEdit);
						if (!succeed) {
							ui.errorSyntax("Failed editing course");
						}
						else {
							ui.errorSyntax("Course was successfully updated");
						}
					}
				}
				createCircularCoursesFile();
			}
					break;
			case 8: { //edit student
				while (true) {
					if (getFormula().empty()){
						ui.errorFormula();
						break;
					}
					string idToEdit = ui.editStudentChooseScreen(getStudentsDataInVector());
					if (idToEdit[0] == 'x' || idToEdit[0] == 'X') {
						break;
					}
					if (fileStorage->getStudent(idToEdit, false, "") == NULL) {
						ui.errorSyntax("Student doesn't exists\n");
						break;
					}
					else {
						vector<string> studentData = ui.editStudentScreen();
						bool succeed = saveStudent(studentData, 8, idToEdit);
						if (!succeed) {
							ui.errorSyntax("Failed editing student");
						}
						else {
							ui.errorSyntax("Student was successfully updated");
						}
					}
				}

			}
					break;
			default:
				ui.errorSyntax("Not an option");
				break;
			}
		}
		catch (invalid_argument e) {
			ui.errorSyntax("Not a number");
		}
	}
}

DataUpdate::~DataUpdate()
{
}

/*this function reutrns all students objects in string vector
for the ui component that needs to dispaly them*/
vector<string> DataUpdate::getStudentsDataInVector() {
	map<string, Student*> allStudents = fileStorage->getStudentsMap();
	vector<string> data;
	for (map<string, Student*>::iterator iter = allStudents.begin(); iter != allStudents.end(); ++iter) {
		data.push_back(iter->second->getId());
		data.push_back(iter->second->getName());
		data.push_back(to_string(iter->second->getPoints()));
		vector<string> completedCourses = iter->second->getCompletedCourses();
		data.push_back("\nCompleted courses:");
		if (completedCourses.size() == 0) {
			data.push_back("none");
		}
		else {
			for (unsigned i = 0; i < completedCourses.size(); i++) {
				data.push_back(completedCourses[i]);
			}
		}
		data.push_back("\n");
	}
	return data;

}

/*this function reutrns all students objects in string vector
for the ui component that needs to dispaly them*/
vector<string> DataUpdate::getCoursesDataInVector() {
	map<string, Course*> allCourses = fileStorage->getCoursesMap();
	vector<string> data;
	for (map<string, Course*>::iterator iter = allCourses.begin(); iter != allCourses.end(); ++iter) {
		data.push_back(iter->second->getId());
		data.push_back(iter->second->getName());
		data.push_back(iter->second->getDescription());
		data.push_back(to_string(iter->second->getHours()));
		data.push_back(to_string(iter->second->getMaxStudent()));
		vector<string> requiredCourses = iter->second->getRequiredCourses();
		data.push_back("\nRequired courses:");
		if (requiredCourses.size() == 0) {
			data.push_back("none");
		}
		else {
			for (unsigned i = 0; i < requiredCourses.size(); i++) {
				data.push_back(requiredCourses[i]);
			}
		}
		vector<string> studentsList = iter->second->getStudentsList();
		data.push_back("\nStudents list:");
		if (studentsList.size() == 0) {
			data.push_back("There are no registered students to this course");
		}
		else {
			for (unsigned i = 0; i < studentsList.size(); i++) {
				data.push_back(studentsList[i]);
			}
		}
		data.push_back("\n");
	}
	return data;
}

/* this function is been called when add student or update student
first checks if student is already exists */
bool DataUpdate::saveStudent(vector<string> data, int from, string idToEdit) {
	if (&data != NULL || data.size() > 0)  {
		Student* student = NULL;
		if (from == 8) { //from update student
			student = fileStorage->getStudent(idToEdit, false, "");
			char c;
			student->setId(data[0]);
			student->setName(data[1]);
			int completedCourses = data.size() - 2; // -2 is the name and id in data vector
			Lexer* lexer = new Lexer(getFormula());
			Expression* ex = lexer->getExpression();
			student->setPoints((int)ex->evaluate(completedCourses));
			for (unsigned i = 2; i < data.size(); i++) {
				c = data[i][0];
				if (c == 'c' || c == 'C') {
					map<string, Course*>allCourse = fileStorage->getCoursesMap();
					if (allCourse.count(data[i])) {
						student->setCompletedCourses(data[i]);
					}
					else {
						ui.errorSyntax("The course don't exists, consider add the course first(option 3)");
						return false;
					}
				}
				else {
					ui.errorSyntax("Course id must start with 'c'");
					return false;
				}
			}
			fileStorage->setStudent(student);
			return true;
		}
		else {
			char c = data[0][0];
			if (c == 's' || c == 'S') {
				student = fileStorage->getStudent(data[0], false, "");
				if (student != NULL) {
					ui.errorSyntax("Student is already exists. Update it.");
					return false;
				}
				else {
					student = new Student();
					student->setId(data[0]);
					student->setName(data[1]);
					int completedCourses = data.size() - 2; // -2 is the name and id in data vector
					Lexer* lexer = new Lexer(getFormula());
					Expression* ex = lexer->getExpression();
					student->setPoints((int)ex->evaluate(completedCourses));
					for (unsigned i = 2; i < data.size(); i++) {
						c = data[i][0];
						if (c == 'c' || c == 'C') {
							map<string, Course*>allCourse = fileStorage->getCoursesMap();
							if (allCourse.count(data[i])) {
								student->setCompletedCourses(data[i]);
							}
							else {
								ui.errorSyntax("The course don't exists, consider add the course first(option 3)");
								return false;
							}
						}
						else {
							ui.errorSyntax("Course id must start with 'c'");
							return false;
						}
					}
				}
			}
			else {
				ui.errorSyntax("Student id must start with 's'");
				return false;
			}
			fileStorage->setStudent(student);
			return true;
		}

	}
	return false;
}

/* this function is been called when add course or update course
first checks if course is already exists */
bool DataUpdate::saveCourse(vector<string> data, int from, string idToEdit) {
	if (&data != NULL || data.size() > 0)  {
		Course* course = NULL;
		if (from == 7) { //from update course
			course = fileStorage->getCourse(idToEdit);
			if (course == NULL) {
				ui.errorSyntax("Course doesn't exists\n"); //need another screen 
				return false;
			}
			else {
				course->setId(data[0]);
				course->setName(data[1]);
				course->setDescription(data[2]);
				course->setHoures(stoi(data[3]));
				unsigned i = 4;
				vector<string> requiredCourses;
				while (i < data.size()) {
					if (data[i][0] == 'c' || data[i][0] == 'C') {
						requiredCourses.push_back(data[i]);
						i++;
					}
					else {
						break;
					}
				}
				if (requiredCourses.size() > 0) {
					string isCircle = checkCircularity(data[0], requiredCourses);
					if (!isCircle.empty()) {
						ui.errorSyntax("Cannot add course - check requried courses circularity. Problem at "
							+ isCircle);
						return false;;
					}
					else {
						course->setRequiredCoures(requiredCourses);
					}
				}
				course->setMaxStudents(stoi(data[i]));
				course->setLowPoints(0);
				fileStorage->setCourse(course);
				return true;
			}
		}
		else {
			char c = data[0][0];
			if (c == 'c' || c == 'C') {
				course = fileStorage->getCourse(data[0]);
				if (course != NULL) {
					ui.errorSyntax("course is already exists. Update it.");
					return false;
				}
				else {
					try {
						course = new Course();
						course->setId(data[0]);
						course->setName(data[1]);
						course->setDescription(data[2]);
						course->setHoures(stoi(data[3]));
						unsigned i = 4;
						vector<string> requiredCourses;
						while (i < data.size()) {
							if (data[i][0] == 'c' || data[i][0] == 'C') {
								requiredCourses.push_back(data[i]);
								i++;
							}
							else {
								break;
							}
						}
						if (requiredCourses.size() > 0) {
							map<string, Course*> allCourses = fileStorage->getCoursesMap();
							for (unsigned i = 0; i < requiredCourses.size(); i++) { //check if the required courses are exists
								if (allCourses.count(requiredCourses[i])) {
									continue;
								}
								else {
									ui.errorSyntax("Course " + requiredCourses[i] + " in the required courses "
										+ "list is not exists. consider adding it first.");
									return false;

								}
							}
							string isCircle = checkCircularity(data[0], requiredCourses); //check circularity
							if (!isCircle.empty()) {
								ui.errorSyntax("Cannot add course - check requried courses circularity. Problem at "
									+ isCircle);
								return false;
							}
							else {
								course->setRequiredCoures(requiredCourses);
							}
						}
						course->setMaxStudents(stoi(data[i]));
						course->setLowPoints(0);
						fileStorage->setCourse(course);
						return true;
					}
					catch (invalid_argument e) {
						//points must be a number
						ui.errorSyntax("Points must be a number");
						return false;
					}
				}
			}
			else {
				ui.errorSyntax("Course id must start with 'c'");
				return false;
			}
			fileStorage->setCourse(course);
			return true;
		}
	}
	return false;
}

/* this function checks circularity in the required courses dependencied
the algorithm has been taken from ex 1
returns the cycle as a string if found. if not - returns empty string*/
string DataUpdate::checkCircularity(string courseId, vector<string> requiredCourses) {
	string file = "circularCourses.txt";
	ofstream oFileStream;
	oFileStream.open(file, ofstream::app);
	if (oFileStream.is_open()) { // first write the dependecy in the dependecies file and then checks
		for (unsigned i = 0; i < requiredCourses.size(); i++) {
			oFileStream << requiredCourses[i] << ' ' << courseId << endl;
		}
		oFileStream.close();
	}
	int found = 0;
	ListDigraph g;
	CrossRefMap<ListDigraph, ListDigraph::Node, string> names(g);
	ListDigraph::Node n;
	string line;
	ifstream myfile(file);
	string circularPath;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{

			vector<ListDigraph::Node> vec;
			istringstream iss(line);
			//splits the line to words
			while (iss) {
				string sub;
				iss >> sub;

				//if the word is not white space
				if (sub.compare("") != 0) {

					//check if the word is already have a node 
					auto node = names(sub);
					if (node != INVALID) {
						found = 1;
					}

					//if no we create a new node for it
					if (found == 0) {
						auto node = g.addNode();
						names.set(node, sub);
					}

					//put the node in a temp vector
					vec.push_back(names(sub));
					found = 0;
				}
			}

			//create the arc between the two nodes
			ListDigraph::Arc  a = g.addArc(vec.at(0), vec.at(1));

			//check if the arc creates a cycle
			//if so print all the nodes in the cycle
			Bfs<ListDigraph> bfs(g);
			bfs.run(vec.at(1));
			if (bfs.reached(vec.at(0))) {
				circularPath = names[vec.at(0)];
			}
			vec.clear();
		}
		myfile.close();
		return circularPath;
	}

	else ui.errorSyntax("Unable to open file");
	return circularPath;
}

void DataUpdate::setFormula(string f) {
	formula = f;
}

string DataUpdate::getFormula(){
	if (this->formula.empty())
		return "";
	return this->formula;
}

/*this function creates and ovverides the circularity file
envokes when the program starts and when creating and updating course
simply writes the dependencies to the file as we do at ex 1*/
void DataUpdate::createCircularCoursesFile() {
	string file = "circularCourses.txt";
	ofstream oFileStream;
	oFileStream.open(file);
	if (oFileStream.is_open()) {
		map<string, Course*> allCourses = fileStorage->getCoursesMap();
		for (map<string, Course*>::iterator iter = allCourses.begin(); iter != allCourses.end(); ++iter) {
			vector<string> requiredCourses = iter->second->getRequiredCourses();
			for (unsigned i = 0; i < requiredCourses.size(); i++) {
				oFileStream << requiredCourses[i] << ' ' << iter->second->getId() << endl;
			}
		}
		oFileStream.close();
	}
}

/*The technicians deploys 5 student's terminal across the university*/
void DataUpdate::deployTermianls() {
	map<string, Terminal*> allTerminals = fileStorage->getTerminalsMap();
	if (allTerminals.size() > 0) {
		return;
	}
	Terminal* t1 = new Terminal("t1",0);
	Terminal* t2 = new Terminal("t2",0);
	Terminal* t3 = new Terminal("t3",0);
	Terminal* t4 = new Terminal("t4",0);
	Terminal* t5 = new Terminal("t5",0);
	fileStorage->setTerminal(t1);
	fileStorage->setTerminal(t2);
	fileStorage->setTerminal(t3);
	fileStorage->setTerminal(t4);
	fileStorage->setTerminal(t5);
}
