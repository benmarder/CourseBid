#include "UILibraryState.h"

UILibraryState::UILibraryState(){}

UILibraryState::~UILibraryState(){}

/*
* GUI for terminal list return empty string
*/
string UILibraryState::terminalListDisplayState(vector<string> data){
	cout << "Hello these are the terminals :\n";
	for (unsigned int i = 0; i < data.size(); ++i){
		cout << data[i] << "  ";
		if (i % 2 != 0)cout << endl; //end line after each terminal;
	}
	cout << "\nPlease enter the terminal you want to unlock , or x to exit :\n";
	string answer;
	cin >> answer;
	return answer;

}

/*
* GUI for authentication return a map with the parameter for
* the controler to handle
*/
map<string, string> UILibraryState::authenticateScreen(){
	string id;
	string name;
	map<string, string> authenticateMap;
	cout << "Hello please enter your id:\n";
	cin >> id;
	cout << "Hello please enter your name:\n";
	getline(cin, name);
	getline(cin, name);
	authenticateMap["id"] = id;
	authenticateMap["name"] = name;
	return authenticateMap;
}

/*
* GUI for the option of the secratery before bidding
* return a number for the option
*/
string UILibraryState::secretaryOptions() {
	string result;
	cout << "**************************************\n"
		<< "welcome to the secretary terminal\n"
		<< "0 - add formula\n"
		<< "1 - list of all courses\n"
		<< "2 - list of all student\n"
		<< "3 - add new course\n"
		<< "4 - add new student\n"
		<< "5 - delete a course\n"
		<< "6 - delete a student\n"
		<< "7 - edit a course\n"
		<< "8 - edit a student\n"
		<< "**************************************\n";
	cin >> result;
	return result;
}

/*
* GUI for secratery to see all courses return string for her to go back
* recives a map with all the courses to present to the secretary
* if she pressed x it will return (logic in the controller)
*/
string UILibraryState::listOfCoursesSecretary(vector<string> data){
	string result;
	cout << "******list of all courses**********\n"
		<< "x - go back\n";
	for (unsigned i = 0; i < data.size(); i++) {
		cout << "  " << data[i];
		if (1+i % 2 == 0)cout << endl;
	}
	cout << "**************************************\n";
	cin >> result;
	return result;
}

/*
* GUI for secratery to see all students return string for her to go back
* recives a map with all the student to present to the secretary
* if she pressed x it will return (logic in the controller)
*/
string UILibraryState::listOfStudentSecretary(vector<string> data){
	string result;
	cout << "******list of all student**********\n"
		<< "x - go back\n";
	for (unsigned i = 0; i < data.size(); i++) {
		cout << "  " << data[i];
		if (1 + i % 2 == 0)cout << endl;
	}
	cout << "**************************************\n";
	cin >> result;
	return result;
}

/*
* GUI for secratery to add new course to the database
* a map is sent to the controller that communicates with the file storage
*/
vector<string> UILibraryState::addNewCourseScreen() {
	vector<string> courseInfo;
	string result;
	cout << "******add new course**********\n";
	cout << "enter course id (example: C01)\n";
	cin >> result;
	courseInfo.push_back(result);
	cout << "enter course name\n";
	getline(cin, result);
	getline(cin, result);
	courseInfo.push_back(result);
	cout << "enter course description\n";
	getline(cin, result);
	courseInfo.push_back(result);
	cout << "enter course hours\n";
	cin >> result;
	courseInfo.push_back(result);
	while (true) {
		cout << "enter course required courses (example: C02,C05,C12)\n";
		cout << "to finish entering required courses press X\n";
		cin >> result;
		if (result[0] != 'x' && result[0] != 'X') {
			courseInfo.push_back(result);
		}
		else {
			break;
		}
	}
	cout << "enter course max students\n";
	cin >> result;
	courseInfo.push_back(result);
	return courseInfo;

}

/*
* GUI for secratery to add new student to the database
* a map is sent to the controller that communicates with the file storage
*/
vector<string> UILibraryState::addNewStudentScreen(){ //changed
	vector<string> studentInfo;
	string result;
	cout << "******add new student**********\n";
	cout << "enter student id (example: S01)\n";
	cin >> result;
	studentInfo.push_back(result);
	cout << "enter student first name\n";
	cin >> result;
	string temp = result;
	cout << "enter student last name\n";
	cin >> result;
	studentInfo.push_back(temp+' '+result);
	while (true) {
		cout << "enter student course completed\n";
		cout << "to finish entering completed courses press X\n";
		cin >> result;
		if (result[0] != 'x' && result[0] != 'X') {
			studentInfo.push_back(result);
		}
		else {
			break;
		}
	}
	return studentInfo;
}

/*
* GUI for secratery to delete course from the database
* recives a map with all the courses to present to the secretary
* a string is sent back to the controller that communicates with the file storage
*/
string UILibraryState::deleteCourseScreen(vector<string> data) {
	string result;
	cout << "********delete course**********\n";
	cout << "x - go back\n";
	for (unsigned i = 0; i < data.size(); i++) {
		cout << " " << data[i];
		if (1 + i % 2 == 0) cout << endl;
	}
	cout << "**************************************\n";
	cin >> result;
	return result;
}

/*
* GUI for secratery to delete student from the database
* recives a map with all the student to present to the secretary
* a string is sent to the controller that communicates with the file storage
*/
string UILibraryState::deleteStudentScreen(vector<string> data){ //changed
	string result;
	cout << "********delete student**********\n";
	cout << "x - go back\n";
	for (unsigned i = 0; i < data.size(); i++) {
		cout <<" "<< data[i];
		if (1 + i % 2 == 0) cout << endl;
	}
	cout << "**************************************\n";
	cin >> result;
	return result;
}

/*
* GUI for secratery to choose which course from the database enter editing mode
* recives a map with all the courses to present to the secretary
* a string is sent to the controller to know what course to edit
*/
string UILibraryState::editCourseChooseScreen(vector<string> data) {
	string result;
	cout << "********choose a course to edit**********\n";
	cout << "x - go back\n";
	for (unsigned i = 0; i < data.size(); i++) {
		cout << " " << data[i];
		if (1 + i % 2 == 0) cout << endl;
	}
	cout << "**************************************\n";
	cin >> result;
	return result;
}

/*
* GUI for secratery to choose which student from the database enter editing mode
* recives a map with all the students to present to the secretary
* a string is sent to the controller to know what student to edit
*/
string UILibraryState::editStudentChooseScreen(vector<string> data){
	string result;
	cout << "********choose a student to edit**********\n";
	cout << "x - go back\n";
	for (unsigned i = 0; i < data.size(); i++) {
		cout << " " << data[i];
		if (1 + i % 2 == 0) cout << endl;
	}
	cout << "**************************************\n";
	cin >> result;
	return result;
}

/*
* GUI for secratery  editing mode
* a map is sent to the controller to know what course to change from the database
* with new data
*/
vector<string> UILibraryState::editCourseScreen(){
	vector<string> courseInfo;
	string result;
	cout << "********edit course**********\n";
	cout << "enter edited course id (example: C01)\n";
	cin >> result;
	courseInfo.push_back(result);
	cout << "enter edited course name\n";
	cin >> result;
	courseInfo.push_back(result);
	cout << "enter course description\n";
	cin >> result;
	courseInfo.push_back(result);
	cout << "enter edited course hours\n";
	cin >> result;
	courseInfo.push_back(result);
	while (true) {
		cout << "enter edited course require courses (example: C02,C05,C12)\n";
		cout << "to finish entering completed courses press X\n";
		cin >> result;
		if (result[0] != 'x' && result[0] != 'X') {
			courseInfo.push_back(result);
		}
		else {
			break;
		}
	}
	cout << "enter edited course max students\n";
	cin >> result;
	courseInfo.push_back(result);
	return courseInfo;
}

/*
* GUI for secratery  editing mode
* a map is sent to the controller to know what student to change from the database
* with new data
*/
vector<string> UILibraryState::editStudentScreen() { 
	vector<string> studentInfo;
	string result;
	cout << "*********edit student**********\n";
	cout << "enter student id (example: S01)\n";
	cin >> result;
	studentInfo.push_back(result);
	cout << "enter student first name\n";
	cin >> result;
	string temp = result;
	cout << "enter student last name\n";
	cin >> result;
	studentInfo.push_back(temp+' '+result);
	while (true) {
		cout << "enter student course completed\n";
		cout << "to finish entering completed courses press X\n";
		cin >> result;
		if (result[0] != 'x' && result[0] != 'X') {
			studentInfo.push_back(result);
		}
		else {
			break;
		}
	}
	return studentInfo;
}

/*
* GUI for secratery  list of all student after bidding
* a map of all student is received from the controller to show all student
* a string with the student id is sent back to the controller to show
* every course the student is in
*/
string UILibraryState::listOfStudentSecretaryPostBidding(vector<string> data){
	string result;
	cout << "******list of all student**********\n"
		<< "Type Student ID or press x to go back\n";
	for (unsigned i = 0; i < data.size(); i++) {
		cout << '\t' << data[i];
	}
	cout << "**************************************\n";
	cin >> result;
	return result;
}

/*
* GUI for secratery  list of all courses that student is in after bidding
* a map of all courses is received from the controller to show all courses
* a string is returned to the controller only to go back
*/
string UILibraryState::listOfCoursesOfStudentPostBidding(vector<string> data){
	string result;
	cout << "******all courses that student is in*******\n"
		<< "x - go back" << endl;
	for (unsigned i = 0; i < data.size(); i++) {
		cout << '\t' << data[i];
	}
	cout << "**************************************\n";
	cin >> result;
	return result;
}

/*
* GUI for student  list of all courses that student can bid on
* a map of all courses is received from the controller to show all courses student can bid on
* a string is returned to the controller only to go forward
*/
string UILibraryState::studentListOfCoursesToBid(vector<string> data){
	cout << "Your total Points: " << data[0] << endl;
	string result;
	cout << "********courses you can bid on********\n";
	for (unsigned int i = 1; i < data.size(); ++i){
		cout << data[i] << "  ";
		if (i % 2 == 0){
			cout << endl;
		}
	}
	cout << "press s to start bidding or x  to exit\n";
	cin >> result;
	return result;
}

/*
* GUI for student for bidding, course will be presented, the student will input
* how many points and the number of point will return to the controller that will calculate
*/

string UILibraryState::studentBiddingScreen(string points, string courseId, string courseName){
	string result;
	cout << "******** Bidding Screen ********\n";
	cout << "Point Remaining: " << points << endl; /* enter point here */
	cout << "please type number of point for course: " << courseId << "  " << courseName << endl;
	cin >> result;
	return result;
}

/*
* GUI for student after bidding present courses i applied and courses he didnt
*/
string UILibraryState::studentPostBiddingScreen(vector<string> data){ 
	cout << "***student info****\n"
		<< "courses i applied\n";
	for (unsigned i = 0; i < data.size(); i++) {
		cout << '\t' << data[i];
	}
	cout << "***************************\n";
	string answer;
	cout << "Exit - X \n";
	cin >> answer;
	return answer;
}

/*
* GUI for student error too
*/
void UILibraryState::tooManyPointsAllocated(){
	cout << "To many points allocated";
}

/*
* GUI that handle authentication error
*/
void UILibraryState::errorAuthentication(int counter){
	cout << "you entered a wrong ID or Name\n";
	cout << "failed " << counter << " times\n";
}

/*
* GUI that handle syntax error
*/
void UILibraryState::errorSyntax(string cause){
	cout << "Syntax Error\n";
	cout << cause << endl;
}

void UILibraryState::terminalIsLocked(){
	cout << "terminal is locked\n";
}

string UILibraryState::addFormula() {
	string result;
	cout << "please enter the formula for the students points\n";
	cin >> result;
	return result;
}

void UILibraryState::errorFormula(){
	cout << "the formula was not inserted,please insert a formula\n";
}

void UILibraryState::addedSuccessfully() {
	cout << "Added successfully\n";
} 

